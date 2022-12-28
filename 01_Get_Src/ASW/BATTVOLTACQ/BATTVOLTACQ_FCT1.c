/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BATTVOLTACQ                                             */
/* !Description     : BATTVOLTACQ Component                                   */
/*                                                                            */
/* !Module          : BATTVOLTACQ                                             */
/* !Description     : ACQUISITION DE LA TENSION BATTERIE                      */
/*                                                                            */
/* !File            : BATTVOLTACQ_FCT1.C                                      */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / BATTVOLTACQ_vidInitOutput                                            */
/*   2 / BATTVOLTACQ_vidBattAcqReset                                          */
/*   3 / BATTVOLTACQ_vidBattDiag                                              */
/*   4 / BATTVOLTACQ_vidBattIni                                               */
/*   5 / BATTVOLTACQ_vidFilClcnAcv                                            */
/*   6 / BATTVOLTACQ_vidFilClcnVal                                            */
/*   7 / BATTVOLTACQ_vidBattFil                                               */
/*   8 / BATTVOLTACQ_vidBattFilt                                              */
/*   9 / BATTVOLTACQ_vidBattAcqOnEveInj                                       */
/*   10 / BATTVOLTACQ_vidBattAcqOn2ms                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6547150 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068642                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BATTVOLTACQ/BATTVOLTACQ_FCT1.C_v  $*/
/* $Revision::   1.5      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BATTVOLTACQ_IM.h"
#include "BATTVOLTACQ.h"
#include "BATTVOLTACQ_L.h"
#include "MATHSRV.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint32 BATTVOLTACQ_u32FiltPosErrorMem;                             */
/*  output boolean Ext_bDgoLo_uBattSpc;                                       */
/*  output uint16 Pwr_uBattRaw1;                                              */
/*  output uint16 Pwr_uBattRaw2;                                              */
/*  output uint16 Pwr_uBattRaw3;                                              */
/*  output uint16 Pwr_uBattRaw4;                                              */
/*  output uint16 Pwr_uBattRaw5;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidInitOutput(void)
{
   BATTVOLTACQ_u32FiltPosErrorMem = 0;
   Ext_bDgoLo_uBattSpc = 0;
   Pwr_uBattRaw1 = 0;
   Pwr_uBattRaw2 = 0;
   Pwr_uBattRaw3 = 0;
   Pwr_uBattRaw4 = 0;
   Pwr_uBattRaw5 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattAcqReset                                */
/* !Description :  Acquisition de la tension batterie au Reset.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acquisition_tension_batterie;                                */
/*  output uint16 Tension_batterie_brute;                                     */
/*  output uint16 Pwr_uBattDiagAcq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattAcqReset(void)
{
   uint16 u16LocalTension_batterie_brute;
   uint16 u16LocalAcquis_tension_batterie;
   uint32 u32LocalAdcVoltage;


   VEMS_vidGET(Acquisition_tension_batterie, u16LocalAcquis_tension_batterie);
   u32LocalAdcVoltage = ((u16LocalAcquis_tension_batterie * 25) + 241) / 483;
   u16LocalTension_batterie_brute = (uint16)MATHSRV_udtMIN(u32LocalAdcVoltage,
                                                           1024);
   VEMS_vidSET(Tension_batterie_brute, u16LocalTension_batterie_brute);
   Pwr_uBattDiagAcq = u16LocalTension_batterie_brute;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattDiag                                    */
/* !Description :  Diagnostic défaut haut et bas de la tension batterie       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Pwr_uBattMinSpc_C;                                           */
/*  input uint16 Pwr_uBattOfsSpc_C;                                           */
/*  input uint16 Pwr_uBattDiagAcq;                                            */
/*  input boolean Ext_bDgoLo_uBattSpc;                                        */
/*  input uint16 Tension_batterie_brute_max;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Seuil_regime_batterie_batt_basse;                             */
/*  input uint16 Tension_batterie_brute_min;                                  */
/*  output boolean Ext_bMonRunLo_uBattSpc;                                    */
/*  output boolean Ext_bMonRunHi_uBattMes;                                    */
/*  output boolean Ext_bDgoHi_uBattMes;                                       */
/*  output boolean Ext_bDgoLo_uBattMes;                                       */
/*  output boolean Ext_bMonRunLo_uBattMes;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattDiag(void)
{
   boolean bLocalTemp1;
   boolean bLocalTemp2;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalHystHighTresh;
   uint32  u32LocalThreshold;
   uint32  u32LocalHystHighTresh;


   Ext_bMonRunLo_uBattSpc = 1;
   Ext_bMonRunHi_uBattMes = 1;

   u32LocalHystHighTresh = (uint32)(Pwr_uBattMinSpc_C + Pwr_uBattOfsSpc_C);
   u16LocalHystHighTresh = (uint16)MATHSRV_udtMIN(u32LocalHystHighTresh, 65535);
   MATHSRV_vidSchmittTriggerU16(Pwr_uBattDiagAcq,
                                Pwr_uBattMinSpc_C,
                                u16LocalHystHighTresh,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &Ext_bDgoLo_uBattSpc);

   if (Pwr_uBattDiagAcq >= Tension_batterie_brute_max)
   {
      Ext_bDgoHi_uBattMes = 1;
   }
   else
   {
      Ext_bDgoHi_uBattMes = 0;
   }

   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u32LocalThreshold = (uint32)(Seuil_regime_batterie_batt_basse * 32);

   if (u16LocalRegime_moteur > u32LocalThreshold)
   {
      bLocalTemp1 = 1;
   }
   else
   {
      bLocalTemp1 = 0;
   }

   if (Tension_batterie_brute_min > Pwr_uBattDiagAcq)
   {
      bLocalTemp2 = 1;
   }
   else
   {
      bLocalTemp2 = 0;
   }

   if ((bLocalTemp1 != 0) && (bLocalTemp2 != 0))
   {
      Ext_bDgoLo_uBattMes = 1;
   }
   else
   {
      Ext_bDgoLo_uBattMes = 0;
   }

   if ((bLocalTemp1 != 0) || (bLocalTemp2 == 0))
   {
      Ext_bMonRunLo_uBattMes = 1;
   }
   else
   {
      Ext_bMonRunLo_uBattMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattIni                                     */
/* !Description :  Initialisation de la tension batterie.                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoHi_uBattMes;                                        */
/*  input boolean Ext_bDgoLo_uBattMes;                                        */
/*  input uint16 Tension_batterie_par_defaut;                                 */
/*  input uint16 Tension_batterie_brute;                                      */
/*  output uint16 Tension_batterie_acq_prec;                                  */
/*  output sint16 Ext_uBattMes;                                               */
/*  output uint16 Tension_batterie;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattIni(void)
{
   boolean bLocalAcvBattVoltDftMod1;
   boolean bLocalAcvBattVoltDftMod2;
   uint32  u32LocalExtBattMes;
   sint16  s16LocalExt_uBattMes;
   uint16  u16LocalTension_batterie;
   uint16  u16LocalTension_batterie_brute;


   bLocalAcvBattVoltDftMod1 = GDGAR_bGetFRM(FRM_FRM_ACVBATTVOLTDFTMOD1);
   bLocalAcvBattVoltDftMod2 = GDGAR_bGetFRM(FRM_FRM_ACVBATTVOLTDFTMOD2);

   if (  (Ext_bDgoHi_uBattMes != 0)
      || (Ext_bDgoLo_uBattMes != 0)
      || (bLocalAcvBattVoltDftMod1 != 0)
      || (bLocalAcvBattVoltDftMod2 != 0))
   {
      Tension_batterie_acq_prec = Tension_batterie_par_defaut;
      u16LocalTension_batterie = Tension_batterie_par_defaut;
      u32LocalExtBattMes = ((uint32)(Tension_batterie_par_defaut * 59) / 25);
      s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u32LocalExtBattMes, 3200));
   }
   else
   {
      VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
      Tension_batterie_acq_prec =
         (uint16)( (uint32)( ( u16LocalTension_batterie_brute
                             * 60375)
                           + 30208)
                 / 60416);
      u16LocalTension_batterie =
         (uint16)( (uint32)( ( u16LocalTension_batterie_brute
                             * 60375)
                           + 30208)
                 / 60416);
      u32LocalExtBattMes = ( (uint32)( u16LocalTension_batterie_brute
                                     * 2415)
                           / 1024);
      s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u32LocalExtBattMes, 3200));

   }
   VEMS_vidSET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidSET(Tension_batterie, u16LocalTension_batterie);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidFilClcnAcv                                  */
/* !Description :  Fonction du filtre anti-progression                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_batterie;                                            */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input uint16 Tension_batterie_acq_prec;                                   */
/*  input uint16 B_v_slew_variation;                                          */
/*  output uint16 Tension_batterie_filtree;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidFilClcnAcv(void)
{
   uint16 u16LocalTension_batterie;
   uint16 u16LocalTension_batterie_brute;
   uint32 u32LocalTensionBatterie;
   uint32 u32LocalTensionBatAcqPrec;
   uint32 u32LocalTensionBatterieFiltree;
   sint32 s32LocalDeltaCurFilt;
   sint32 s32LocalDeltaPrevFilt;


   VEMS_vidGET(Tension_batterie, u16LocalTension_batterie);
   VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
   u32LocalTensionBatterie = ( (uint32)( ( u16LocalTension_batterie
                                         * 60416)
                                       + 30187)
                             / 60375);
   s32LocalDeltaCurFilt = (sint32)( u16LocalTension_batterie_brute
                                  - u32LocalTensionBatterie);
   u32LocalTensionBatAcqPrec = ( (uint32)( ( Tension_batterie_acq_prec
                                           * 60416)
                                         + 30187)
                               / 60375);
   s32LocalDeltaPrevFilt = (sint32)( u32LocalTensionBatAcqPrec
                                   - u32LocalTensionBatterie);
   if (s32LocalDeltaCurFilt > B_v_slew_variation)
   {
      if (s32LocalDeltaPrevFilt > B_v_slew_variation)
      {
         u32LocalTensionBatterieFiltree = u32LocalTensionBatterie
                                        + B_v_slew_variation;
      }
      else
      {
         u32LocalTensionBatterieFiltree = u32LocalTensionBatterie;
      }
   }
   else
   {
      /* !QAC Deviation : logical operation is NOT always 'false'.*/
      if (s32LocalDeltaCurFilt < (-1 * B_v_slew_variation))
      {
         if (s32LocalDeltaPrevFilt < (-1 * B_v_slew_variation))
         {
            u32LocalTensionBatterieFiltree = u32LocalTensionBatterie
                                           - B_v_slew_variation;
         }
         else
         {
            u32LocalTensionBatterieFiltree = u32LocalTensionBatterie;
         }
      }
      else
      {
         u32LocalTensionBatterieFiltree = u32LocalTensionBatterie;
      }
   }
   Tension_batterie_filtree =
      (uint16)MATHSRV_udtMIN(u32LocalTensionBatterieFiltree, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidFilClcnVal                                  */
/* !Description :  Calcul de la tension batterie filtrée                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BATTVOLTACQ_vidFilClcnAcv();                             */
/*  input uint16 Tension_batterie;                                            */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input uint8 Seuil_filtre_anti_progression;                                */
/*  input uint16 Tension_batterie_acq_prec;                                   */
/*  output uint16 Tension_batterie_filtree;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidFilClcnVal(void)
{
   boolean bLocalCompBrute;
   boolean bLocalCompPrec;
   uint16  u16LocalTension_batterie;
   uint16  u16LocalTension_batterie_brute;
   uint16  u16LocalProdBrute;
   sint32  s32LocalDiffBrute;
   sint32  s32LocalDiffPrec;
   uint32  u32LocalAbs;
   uint32  u32LocalAbs1;


   VEMS_vidGET(Tension_batterie, u16LocalTension_batterie);
   VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
   u16LocalProdBrute =
      (uint16)( (uint32)( ( u16LocalTension_batterie_brute
                          * 60375)
                        + 30208)
               / 60416);
   s32LocalDiffBrute = (sint32)(u16LocalProdBrute - u16LocalTension_batterie);
   u32LocalAbs = (uint32)(MATHSRV_udtABS(s32LocalDiffBrute));

   /* !QAC Deviation : logical operation is NOT always 'false'.*/
   if (u32LocalAbs < Seuil_filtre_anti_progression)
   {
      bLocalCompBrute = 1;
   }
   else
   {
      bLocalCompBrute = 0;
   }

   s32LocalDiffPrec = (Tension_batterie_acq_prec - u16LocalTension_batterie);
   u32LocalAbs1 = (uint32)(MATHSRV_udtABS(s32LocalDiffPrec));

   if (u32LocalAbs1 < Seuil_filtre_anti_progression)
   {
      bLocalCompPrec = 1;
   }
   else
   {
      bLocalCompPrec = 0;
   }

   if ((bLocalCompBrute != 0) || (bLocalCompPrec != 0))
   {
      BATTVOLTACQ_vidFilClcnAcv();
   }
   else
   {
      Tension_batterie_filtree =
         (uint16)MATHSRV_udtMIN(u16LocalTension_batterie_brute, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattFil                                     */
/* !Description :  Calcul de la tension batterie précédente                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BATTVOLTACQ_vidFilClcnVal();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_batterie_brute;                                      */
/*  input boolean Ext_bDgoHi_uBattMes;                                        */
/*  input boolean Ext_bDgoLo_uBattMes;                                        */
/*  input uint16 Tension_batterie_acq_prec;                                   */
/*  input uint16 Tension_batterie_filtree;                                    */
/*  input uint16 Tension_batterie_par_defaut;                                 */
/*  input st23 Vehicle_active_state;                                          */
/*  output uint16 Tension_batterie_acq_prec;                                  */
/*  output sint16 Ext_uBattMes;                                               */
/*  output uint16 Tension_batterie;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattFil(void)
{
   boolean bLocalAcvBattVoltDftMod1;
   boolean bLocalAcvBattVoltDftMod2;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalBattMes;
   sint16  s16LocalExt_uBattMes;
   uint16  u16LocalTension_batterie;
   uint16  u16LocalTension_batterie_brute;
   uint32  u32LocalExtBattMes;


   bLocalAcvBattVoltDftMod1 = GDGAR_bGetFRM(FRM_FRM_ACVBATTVOLTDFTMOD1);
   bLocalAcvBattVoltDftMod2 = GDGAR_bGetFRM(FRM_FRM_ACVBATTVOLTDFTMOD2);
   VEMS_vidGET(Tension_batterie_brute, u16LocalTension_batterie_brute);
   BATTVOLTACQ_vidFilClcnVal();

   if (  (Ext_bDgoHi_uBattMes != 0)
      || (Ext_bDgoLo_uBattMes != 0)
      || (bLocalAcvBattVoltDftMod1 != 0)
      || (bLocalAcvBattVoltDftMod2 != 0))
   {
      if (bLocalAcvBattVoltDftMod1 == 0)
      {
         if (bLocalAcvBattVoltDftMod2 == 0)
         {
            u32LocalExtBattMes =
               ((uint32)(Tension_batterie_acq_prec * 59) / 25);
            s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u32LocalExtBattMes,
                                                           3200));
            u16LocalTension_batterie = Tension_batterie_acq_prec;
         }
         else
         {
            u16LocalBattMes = (uint16)( (uint32)( ( Tension_batterie_filtree
                                                  * 2415)
                                                + 512)
                                      / 1024);
            s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u16LocalBattMes,
                                                           3200));
            u16LocalTension_batterie =
               (uint16)( (uint32)( ( Tension_batterie_filtree
                                   * 60375)
                                 + 30208)
                       / 60416);
            Tension_batterie_acq_prec =
               (uint16)( (uint32)( ( u16LocalTension_batterie_brute
                                   * 60375)
                                 + 30208)
                       / 60416);
         }
      }
      else
      {
         u32LocalExtBattMes = ((uint32)(Tension_batterie_par_defaut * 59) / 25);
         s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u32LocalExtBattMes,
                                                        3200));
         u16LocalTension_batterie = Tension_batterie_par_defaut;
         Tension_batterie_acq_prec = Tension_batterie_par_defaut;
      }
   }
   else
   {
      VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
      if (u8LocalVehicle_active_state != VS_RUNNING)
      {
         u32LocalExtBattMes =
            ((uint32)((u16LocalTension_batterie_brute * 2415) + 512) / 1024);
         s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u32LocalExtBattMes,
                                                        3200));
         u16LocalTension_batterie =
            (uint16)( (uint32)( ( u16LocalTension_batterie_brute
                                * 60375)
                              + 30208)
                    / 60416);
         Tension_batterie_acq_prec = u16LocalTension_batterie;
      }
      else
      {
         u16LocalBattMes =
            (uint16)((uint32)((Tension_batterie_filtree * 2415) + 512) / 1024);
         s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMIN(u16LocalBattMes, 3200));
         u16LocalTension_batterie =
            (uint16)( (uint32)( ( Tension_batterie_filtree
                                * 60375)
                              + 30208)
                    / 60416);
         Tension_batterie_acq_prec =
            (uint16)( (uint32)( ( u16LocalTension_batterie_brute
                                * 60375)
                              + 30208)
                    / 60416);
      }
   }
   VEMS_vidSET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidSET(Tension_batterie, u16LocalTension_batterie);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattFilt                                    */
/* !Description :  Tension_batterie_filt est créé à partir d’un filtrage du   */
/*                 premier ordre sur Tension_batterie.                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_batterie;                                            */
/*  input uint8 Gain_tension_batterie_filt;                                   */
/*  input uint32 BATTVOLTACQ_u32FiltPosErrorMem;                              */
/*  output uint16 Tension_batterie_filt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattFilt(void)
{
   uint16 u16LocalTension_batterie_filt;
   uint16 u16LocalTension_batterie;

   VEMS_vidGET(Tension_batterie, u16LocalTension_batterie);

   u16LocalTension_batterie_filt =
      MATHSRV_u16FirstOrderFilterGu8(Gain_tension_batterie_filt,
                                     &BATTVOLTACQ_u32FiltPosErrorMem,
                                     u16LocalTension_batterie);

   VEMS_vidSET(Tension_batterie_filt, u16LocalTension_batterie_filt);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattAcqOnEveInj                             */
/* !Description :  Acquisition de la tension batterie sur événement           */
/*                 d’injection, sous condition d’activation de la stratégie : */
/*                 Pwr_bEnaEveInj_C = 1.                                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acquisition_tension_batterie;                                */
/*  output uint16 Pwr_uBattEveInjAcq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattAcqOnEveInj(void)
{
   uint16 u16LocalAcquis_tension_batterie;
   uint32 u32LocalAdcVoltage;


   VEMS_vidGET(Acquisition_tension_batterie, u16LocalAcquis_tension_batterie);
   u32LocalAdcVoltage = ((u16LocalAcquis_tension_batterie * 25) + 241) / 483;
   Pwr_uBattEveInjAcq = (uint16)MATHSRV_udtMIN(u32LocalAdcVoltage, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidBattAcqOn2ms                                */
/* !Description :  Acquisition de la tension batterie toute les 2ms, sous     */
/*                 condition d’activation de la stratégie : Pwr_bEnaEve2ms_C =*/
/*                 1. En sortie, on retrouve les 5 derniers échantillons.     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Pwr_uBattRaw2;                                               */
/*  input uint16 Pwr_uBattRaw3;                                               */
/*  input uint16 Pwr_uBattRaw4;                                               */
/*  input uint16 Pwr_uBattRaw5;                                               */
/*  input uint16 Acquisition_tension_batterie;                                */
/*  output uint16 Pwr_uBattRaw1;                                              */
/*  output uint16 Pwr_uBattRaw2;                                              */
/*  output uint16 Pwr_uBattRaw3;                                              */
/*  output uint16 Pwr_uBattRaw4;                                              */
/*  output uint16 Pwr_uBattRaw5;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidBattAcqOn2ms(void)
{
   uint16 u16LocalAcquis_tension_batterie;
   uint32 u32LocalAdcVoltage;


   Pwr_uBattRaw1 = (uint16)MATHSRV_udtMIN(Pwr_uBattRaw2, 1024);
   Pwr_uBattRaw2 = (uint16)MATHSRV_udtMIN(Pwr_uBattRaw3, 1024);
   Pwr_uBattRaw3 = (uint16)MATHSRV_udtMIN(Pwr_uBattRaw4, 1024);
   Pwr_uBattRaw4 = (uint16)MATHSRV_udtMIN(Pwr_uBattRaw5, 1024);

   VEMS_vidGET(Acquisition_tension_batterie, u16LocalAcquis_tension_batterie);
   u32LocalAdcVoltage = ((u16LocalAcquis_tension_batterie * 25) + 241) / 483;
   Pwr_uBattRaw5 = (uint16)MATHSRV_udtMIN(u32LocalAdcVoltage, 1024);
}
/*------------------------------- end of file --------------------------------*/