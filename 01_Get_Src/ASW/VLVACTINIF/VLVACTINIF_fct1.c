/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINIF                                              */
/* !Description     : VLVACTINIF component                                    */
/*                                                                            */
/* !Module          : VLVACTINIF                                              */
/* !Description     : INTERFACE D’ADAPTATION DES CONSIGNE ET MESURE AAC POUR  */
/*                    LA FONCTION VVT ADMISSION                               */
/*                                                                            */
/* !File            : VLVACTINIF_FCT1.C                                       */
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
/*   1 / VLVACTINIF_vidInitOutput                                             */
/*   2 / VLVACTINIF_vidInitialisation                                         */
/*   3 / VLVACTINIF_vidVVTToothErrDet                                         */
/*   4 / VLVACTINIF_vidCmOfsCmp                                               */
/*   5 / VLVACTINIF_vidVlvActCmToothOfs                                       */
/*   6 / VLVACTINIF_vidVlvActOfsCmp                                           */
/*   7 / VLVACTINIF_vidVVTPosition                                            */
/*   8 / VLVACTINIF_vidVVTSetpoint                                            */
/*   9 / VLVACTINIF_vidCalcSatSetpoint                                        */
/*   10 / VLVACTINIF_vidVVTDiagInhFlagCal                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5320155 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINIF/VLVACTINIF_F$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   19 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINIF.h"
#include "VLVACTINIF_L.h"
#include "VLVACTINIF_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidInitOutput                                   */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint16 Vxx_vvtc_in_angl_sp;                                        */
/*  output boolean VlvAct_bInSpFuncIntlHiOutIdc;                              */
/*  output boolean VlvAct_bInSpFuncIntlLoOutIdc;                              */
/*  output boolean VlvAct_bInhDiagPresScav;                                   */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0;                                   */
/*  output boolean VlvAct_bCmdInServoLocLop;                                  */
/*  output uint16 VLVACTINIF_u16SlewRateOut;                                  */
/*  output boolean VLVACTINIF_bTimerInputPrev;                                */
/*  output uint8 VLVACTINIF_u8TimerCount;                                     */
/*  output boolean VlvAct_bInSpFuncIntlHiOutIdcInt;                           */
/*  output boolean VlvAct_bInSpFuncIntlLoOutIdcInt;                           */
/*  output uint16 VlvAct_prm_agCkOpInVlvMax[4];                               */
/*  output boolean VLVACTINIF_bSwitchOutPrev;                                 */
/*  output boolean VLVACTINIF_bTimerInitPrev;                                 */
/*  output boolean VLVACTINIF_bTimerOut;                                      */
/*  output boolean VLVACTINIF_bLihPosTimerOut;                                */
/*  output uint16 VlvAct_tiDlyInhDiagPresScavOff;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidInitOutput(void)
{
   uint8 u8LocalIdx;


   VEMS_vidSET(Vxx_vvtc_in_angl_sp, 0);
   VEMS_vidSET(VlvAct_bInSpFuncIntlHiOutIdc, 0);
   VEMS_vidSET(VlvAct_bInSpFuncIntlLoOutIdc, 0);
   VEMS_vidSET(VlvAct_bInhDiagPresScav, 0);
   VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0, 0);
   VEMS_vidSET(VlvAct_bCmdInServoLocLop, 0);
   VLVACTINIF_u16SlewRateOut = 0;
   VLVACTINIF_bTimerInputPrev = 0;
   VLVACTINIF_u8TimerCount = 0;
   VlvAct_bInSpFuncIntlHiOutIdcInt = 0;
   VlvAct_bInSpFuncIntlLoOutIdcInt = 0;
   for (u8LocalIdx = 0;
        u8LocalIdx < VLVACT_PRM_AGCKOPINVLVMAX_COLS;
        u8LocalIdx++)
   {
      VEMS_vidSET1DArrayElement(VlvAct_prm_agCkOpInVlvMax, u8LocalIdx, 0);
   }

   VLVACTINIF_bSwitchOutPrev = 0;
   VLVACTINIF_bTimerInitPrev = 0;
   VLVACTINIF_bTimerOut = 1;
   VLVACTINIF_bLihPosTimerOut = 0;
   VlvAct_tiDlyInhDiagPresScavOff = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidInitialisation                               */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input sint16 Ext_agCkOpInVlvEstimRef0Ini_C;                               */
/*  input sint8 VlvAct_agCkOpInVlvReqRef0Max_C;                               */
/*  input sint8 VlvAct_agCkOpInVlvReqRef0Min_C;                               */
/*  input uint16 Vta_intake_reference_angle[4];                               */
/*  output sint16 Ext_agCkOpInVlvEstimRef0;                                   */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0Max;                                */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0Max_C;                              */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0Min;                                */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0Min_C;                              */
/*  output uint16 VlvAct_prm_agCkOpInVlvBol[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidInitialisation(void)
{
   uint8    u8LocalCounter;
   uint16   u16LocalCkOpInVlvBol[VCPI_CAM_OFFSETS_COLS];
   sint16   s16LocalExt_agCkOpInVlvEstimRef0;
   uint32   u32LocalVta_intake[VCPI_CAM_OFFSETS_COLS];


   s16LocalExt_agCkOpInVlvEstimRef0 =
      (sint16)MATHSRV_udtCLAMP(Ext_agCkOpInVlvEstimRef0Ini_C, -1024, 1023);
   VEMS_vidSET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef0);
   VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Max, VlvAct_agCkOpInVlvReqRef0Max_C);
   VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Min, VlvAct_agCkOpInVlvReqRef0Min_C);

   for(u8LocalCounter = 0; u8LocalCounter < 4; u8LocalCounter++)
   {
      u32LocalVta_intake[u8LocalCounter] =
         (Vta_intake_reference_angle[u8LocalCounter] * 3) / 2;
      u16LocalCkOpInVlvBol[u8LocalCounter] =
         (uint16)MATHSRV_udtMIN(u32LocalVta_intake[u8LocalCounter], 11520);
   }
   VEMS_vidSET1DArray(VlvAct_prm_agCkOpInVlvBol, 4, u16LocalCkOpInVlvBol);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidVVTToothErrDet                               */
/* !Description :  Le calcul des erreurs de géométrie ainsi que des offsets de*/
/*                 décalage de montage de la cible et de l’actionneur VVT est */
/*                 effectué après chaque apprentissage des butées de repos.   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINIF_vidCmOfsCmp();                                */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  input boolean VLVACTINIF_bVcpiCamOffsetLndPrev;                           */
/*  output boolean VLVACTINIF_bVcpiCamOffsetLndPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidVVTToothErrDet(void)
{
   boolean bLocalVcpi_cam_offsets_are_learn;


   VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpi_cam_offsets_are_learn);
   if (  (bLocalVcpi_cam_offsets_are_learn != 0)
      && (VLVACTINIF_bVcpiCamOffsetLndPrev == 0))
   {
      VLVACTINIF_vidCmOfsCmp();
   }
   VLVACTINIF_bVcpiCamOffsetLndPrev = bLocalVcpi_cam_offsets_are_learn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidCmOfsCmp                                     */
/* !Description :  Le calcul du décalage de montage de l’ensemble cible AAC + */
/*                 actionneur VVT est déterminé lorsque l’ensemble des dents  */
/*                 de la cible AAC sont décalés dans le même sens par rapport */
/*                 à leur position théorique dans le référentiel moteur.      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void VLVACTINIF_vidVlvActCmToothOfs();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  input uint16 Vta_intake_reference_angle[4];                               */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  input sint16 VlvAct_agCkInCmVlvActOfs;                                    */
/*  input sint16 VlvAct_agCkInCmToothOfs;                                     */
/*  output sint16 VlvAct_agCkInCmOfs;                                         */
/*  output sint16 VlvAct_agCkInCmToothErr[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidCmOfsCmp(void)
{
   uint8  u8LocalCounter;
   uint16 u16LocalVcpi_cam_offsets[VCPI_CAM_OFFSETS_COLS];
   /*qac warning due to the use of VEMS_vidGET1DArray macro*/
   sint16 s16LocalVlvAct_agCkInCmVlvActOfs;
   sint32 s32LocalCamOffsetsDiff[VCPI_CAM_OFFSETS_COLS];
   sint32 s32LocalMin;
   sint32 s32LocalVlvActAgCkInCmToothErr;


   VEMS_vidGET1DArray(Vcpi_cam_offsets,
                      VCPI_CAM_OFFSETS_COLS,
                      u16LocalVcpi_cam_offsets);

   for (u8LocalCounter = 0;
        u8LocalCounter < VCPI_CAM_OFFSETS_COLS;
        u8LocalCounter++)
   {
      s32LocalCamOffsetsDiff[u8LocalCounter] =
         (sint32)( u16LocalVcpi_cam_offsets[u8LocalCounter]
                 - Vta_intake_reference_angle[u8LocalCounter]);
   }

   if (Vta_intake_tooth_nb == 2)
   {
      if (  (  (s32LocalCamOffsetsDiff[0] > 0)
            && (s32LocalCamOffsetsDiff[1] > 0)
            && (s32LocalCamOffsetsDiff[2] > 0)))
      {
         s32LocalMin = MATHSRV_udtMIN(s32LocalCamOffsetsDiff[0],
                                      s32LocalCamOffsetsDiff[1]);
         s32LocalMin = MATHSRV_udtMIN(s32LocalMin, s32LocalCamOffsetsDiff[2]);

         VlvAct_agCkInCmOfs = (sint16)MATHSRV_udtMIN(s32LocalMin, 1023);
      }
      else
      {
         if (  (s32LocalCamOffsetsDiff[0] <= 0)
            && (s32LocalCamOffsetsDiff[1] <= 0)
            && (s32LocalCamOffsetsDiff[2] <= 0))
         {
            s32LocalMin = MATHSRV_udtMAX(s32LocalCamOffsetsDiff[0],
                                         s32LocalCamOffsetsDiff[1]);
            s32LocalMin =
               MATHSRV_udtMAX(s32LocalMin, s32LocalCamOffsetsDiff[2]);

            VlvAct_agCkInCmOfs = (sint16)MATHSRV_udtMAX(s32LocalMin, -1024);
         }
         else
         {
            VlvAct_agCkInCmOfs = 0;
         }
      }
   }
   else
   {
      if (  (  (s32LocalCamOffsetsDiff[0] > 0)
            && (s32LocalCamOffsetsDiff[1] > 0)
            && (s32LocalCamOffsetsDiff[2] > 0)
            && (s32LocalCamOffsetsDiff[3] > 0)))
      {
         s32LocalMin = MATHSRV_udtMIN(s32LocalCamOffsetsDiff[0],
                                      s32LocalCamOffsetsDiff[1]);
         s32LocalMin = MATHSRV_udtMIN(s32LocalMin, s32LocalCamOffsetsDiff[2]);
         s32LocalMin = MATHSRV_udtMIN(s32LocalMin, s32LocalCamOffsetsDiff[3]);

         VlvAct_agCkInCmOfs = (sint16)MATHSRV_udtMIN(s32LocalMin, 1023);
      }
      else
      {
         if (  (s32LocalCamOffsetsDiff[0] <= 0)
            && (s32LocalCamOffsetsDiff[1] <= 0)
            && (s32LocalCamOffsetsDiff[2] <= 0)
            && (s32LocalCamOffsetsDiff[3] <= 0))
         {
            s32LocalMin = MATHSRV_udtMAX(s32LocalCamOffsetsDiff[0],
                                         s32LocalCamOffsetsDiff[1]);
            s32LocalMin =
               MATHSRV_udtMAX(s32LocalMin, s32LocalCamOffsetsDiff[2]);
            s32LocalMin =
               MATHSRV_udtMAX(s32LocalMin, s32LocalCamOffsetsDiff[3]);

            VlvAct_agCkInCmOfs = (sint16)MATHSRV_udtMAX(s32LocalMin, -1024);
         }
         else
         {
            VlvAct_agCkInCmOfs = 0;
         }
      }
   }

   VLVACTINIF_vidVlvActCmToothOfs();
   VEMS_vidGET(VlvAct_agCkInCmVlvActOfs, s16LocalVlvAct_agCkInCmVlvActOfs);
   for(u8LocalCounter = 0;
       u8LocalCounter < VCPI_CAM_OFFSETS_COLS;
       u8LocalCounter++)
   {
      s32LocalVlvActAgCkInCmToothErr = ( (s32LocalCamOffsetsDiff[u8LocalCounter]
                                         - s16LocalVlvAct_agCkInCmVlvActOfs)
                                       - (sint32)VlvAct_agCkInCmToothOfs);

      VlvAct_agCkInCmToothErr[u8LocalCounter] =
         (sint16)MATHSRV_udtCLAMP(s32LocalVlvActAgCkInCmToothErr,
                                  -1024,
                                  1023);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidVlvActCmToothOfs                             */
/* !Description :  Calcul du parametre VlvAct_agCkInCmToothOfs                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINIF_vidVlvActOfsCmp();                            */
/*  input boolean VlvAct_bInCmVlvActOfsEna_C;                                 */
/*  input sint16 VlvAct_agCkInCmOfs;                                          */
/*  output sint16 VlvAct_agCkInCmToothOfs;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidVlvActCmToothOfs(void)
{
   if (VlvAct_bInCmVlvActOfsEna_C != 0)
   {
      VLVACTINIF_vidVlvActOfsCmp();
   }
   else
   {
      VlvAct_agCkInCmToothOfs =
         (sint16)MATHSRV_udtCLAMP(VlvAct_agCkInCmOfs, -1024, 1023);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidVlvActOfsCmp                                 */
/* !Description :  Lorsqu’il est activé, ce bloc permet d’estimer le décalage */
/*                 de montage de l’actionneur VVT à partir de l’offset de     */
/*                 décalage constaté pour l’ensemble cible AAC + actionneur   */
/*                 VVT                                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_agCkInCmOfs;                                          */
/*  input sint16 VlvAct_agCkInCmToothOfsMax_C;                                */
/*  output sint16 VlvAct_agCkInCmVlvActOfs;                                   */
/*  output sint16 VlvAct_agCkInCmToothOfs;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidVlvActOfsCmp(void)
{
   uint16 u16LocalVlvAct_agCkInCmOfs;
   sint16 s16LocalVlvActAgCkInCmVlvActOfs;
   sint16 s16LocalVlvActAgCkInCmToothOfs;
   sint32 s32LocalVlvActAgCkInCmVlvActOfs;
   sint32 s32LocalVlvActAgCkInCmToothOfs;


   u16LocalVlvAct_agCkInCmOfs = (uint16)MATHSRV_udtABS(VlvAct_agCkInCmOfs);

   if (u16LocalVlvAct_agCkInCmOfs <= VlvAct_agCkInCmToothOfsMax_C)
   {
      s32LocalVlvActAgCkInCmVlvActOfs = 0;
   }
   else
   {
      if (VlvAct_agCkInCmOfs < 0)
      {
         s32LocalVlvActAgCkInCmVlvActOfs =
            (sint32)(VlvAct_agCkInCmOfs + VlvAct_agCkInCmToothOfsMax_C);
      }
      else
      {
         if (VlvAct_agCkInCmOfs > 0)
         {
            s32LocalVlvActAgCkInCmVlvActOfs =
               (sint32)( u16LocalVlvAct_agCkInCmOfs
                       - VlvAct_agCkInCmToothOfsMax_C);
         }
         else
         {
            s32LocalVlvActAgCkInCmVlvActOfs = 0;
         }
      }
   }

   s16LocalVlvActAgCkInCmVlvActOfs =
      (sint16)MATHSRV_udtCLAMP(s32LocalVlvActAgCkInCmVlvActOfs, -1024, 1023);

   s32LocalVlvActAgCkInCmToothOfs =
      (VlvAct_agCkInCmOfs - s16LocalVlvActAgCkInCmVlvActOfs);

   s16LocalVlvActAgCkInCmToothOfs =
      (sint16)MATHSRV_udtCLAMP(s32LocalVlvActAgCkInCmToothOfs, -1024, 1023);

   VEMS_vidSET(VlvAct_agCkInCmVlvActOfs, s16LocalVlvActAgCkInCmVlvActOfs);
   VlvAct_agCkInCmToothOfs = s16LocalVlvActAgCkInCmToothOfs;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidVVTPosition                                  */
/* !Description :  La position réelle d’ouverture des soupapes d’admission    */
/*                 dans le référentiel moteur est calculée à partir de la     */
/*                 valeur estimée du décalage d’AAC, issue de la loi de       */
/*                 commande VVT admission.                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_08_06183_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_agCkInCmVlvActOfs;                                    */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input sint16 VlvAct_agCkInCmRefOfs_C;                                     */
/*  input boolean VLVACTINIF_bTimerInputPrev;                                 */
/*  input uint8 VlvAct_tiInLihPosDly_C;                                       */
/*  input uint8 VLVACTINIF_u8TimerCount;                                      */
/*  input boolean VLVACTINIF_bLihPosTimerOut;                                 */
/*  input boolean VlvAct_bInSelDefPos_C;                                      */
/*  input uint16 VlvAct_agInLihPos_C;                                         */
/*  output uint8 VLVACTINIF_u8TimerCount;                                     */
/*  output boolean VLVACTINIF_bLihPosTimerOut;                                */
/*  output boolean VLVACTINIF_bTimerInputPrev;                                */
/*  output sint16 Ext_agCkOpInVlvEstimRef0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidVVTPosition(void)
{
   boolean bLocalAcvVlvActInInIfLihPosCalc;
   uint16  u16LocalVlvAct_agCmInPosnEstim;
   sint16  s16LocalVlvAct_agCkInCmVlvActOfs;
   sint16  s16LocalExtAgCkOpInVlvEstimRef0;
   sint32  s32LocalExtAgCkOpInVlvEstimRef0;


   VEMS_vidGET(VlvAct_agCkInCmVlvActOfs, s16LocalVlvAct_agCkInCmVlvActOfs);
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   s32LocalExtAgCkOpInVlvEstimRef0 = (sint32)( s16LocalVlvAct_agCkInCmVlvActOfs
                                             + VlvAct_agCkInCmRefOfs_C);
   bLocalAcvVlvActInInIfLihPosCalc =
      GDGAR_bGetFRM(FRM_FRM_ACVVLVACTININIFLIHPOSCALC);
   if (  (bLocalAcvVlvActInInIfLihPosCalc != 0)
      && (VLVACTINIF_bTimerInputPrev == 0) )
   {
      VLVACTINIF_u8TimerCount = VlvAct_tiInLihPosDly_C;
      if (VLVACTINIF_u8TimerCount == 0)
      {
         VLVACTINIF_bLihPosTimerOut = 1;
      }
      else
      {
         VLVACTINIF_bLihPosTimerOut = 0;
      }
   }
   else
   {
      if (VLVACTINIF_u8TimerCount > 0)
      {
         VLVACTINIF_u8TimerCount = (uint8)(VLVACTINIF_u8TimerCount - 1);

         if (VLVACTINIF_u8TimerCount == 0)
         {
            VLVACTINIF_bLihPosTimerOut = 1;
         }
         else
         {
            VLVACTINIF_bLihPosTimerOut = 0;
         }
      }
   }
   VLVACTINIF_bTimerInputPrev = bLocalAcvVlvActInInIfLihPosCalc;
   if (  (bLocalAcvVlvActInInIfLihPosCalc != 0)
      && (VLVACTINIF_bLihPosTimerOut != 0))
   {
      if (VlvAct_bInSelDefPos_C == 0)
      {
         s32LocalExtAgCkOpInVlvEstimRef0 = ( s32LocalExtAgCkOpInVlvEstimRef0
                                           - VlvAct_agInLihPos_C);
      }
   }
   else
   {
      s32LocalExtAgCkOpInVlvEstimRef0 = ( s32LocalExtAgCkOpInVlvEstimRef0
                                        - u16LocalVlvAct_agCmInPosnEstim);
   }
   s16LocalExtAgCkOpInVlvEstimRef0 =
      (sint16)MATHSRV_udtCLAMP(s32LocalExtAgCkOpInVlvEstimRef0, -1024, 1023);
   VEMS_vidSET(Ext_agCkOpInVlvEstimRef0, s16LocalExtAgCkOpInVlvEstimRef0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidVVTSetpoint                                  */
/* !Description :  La consigne de décalage AAC admission, utilisée par la loi */
/*                 de commande VVT admission est calculée à partir de la      */
/*                 consigne en position d’ouverture des soupapes à l’admission*/
/*                 dans le référentiel moteur.                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_08_06183_007.01                                     */
/*                 VEMS_E_08_06183_008.01                                     */
/*                 VEMS_E_08_06183_009.01                                     */
/*                 VEMS_E_08_06183_010.01                                     */
/*                 VEMS_R_08_06183_001.02                                     */
/*                 VEMS_R_08_06183_005.01                                     */
/*                 VEMS_R_08_06183_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINIF_vidCalcSatSetpoint();                         */
/*  input boolean VlvAct_bInVlvSpBenchModEna;                                 */
/*  input uint16 VlvAct_agCkInVlvSpBenchMod;                                  */
/*  input uint8 VlvSys_agCkOpInVlvCorRaw;                                     */
/*  input uint16 VlvAct_agInActrTestPosSp;                                    */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input sint16 VlvAct_agCkInCmVlvActOfs;                                    */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  input uint16 VlvAct_agCkInCmSpMax_C;                                      */
/*  input uint8 VlvAct_agInMaxSlopVlvSpPos_C;                                 */
/*  input uint8 VlvAct_agInMinSlopVlvSpPos_C;                                 */
/*  input uint16 VLVACTINIF_u16SlewRateOut;                                   */
/*  input uint16 Vxx_vvtc_in_angl_sp_cal;                                     */
/*  input boolean Vxx_vvtc_in_angl_test_bed;                                  */
/*  input sint16 VlvAct_agCkInCmRefOfs_C;                                     */
/*  input uint16 VlvAct_agInSpFuncIntlThd_C;                                  */
/*  input uint16 VlvAct_agInSpFuncIntlThdHysInf_C;                            */
/*  input uint16 VlvAct_agInSpFuncIntlThdHys_C;                               */
/*  input uint16 VlvAct_agInSpFuncIntlThdLo_C;                                */
/*  input uint16 VlvAct_agInSpFuncIntlThdLoHys_C;                             */
/*  input uint16 VlvAct_agInSpFuncIntlThdHi_C;                                */
/*  input uint16 VlvAct_agInSpFuncIntlThdHiHys_C;                             */
/*  input uint16 VlvAct_agInSpFuncIntlThdMax_C;                               */
/*  input uint16 VlvAct_agInSpFuncIntlThdMaxHys_C;                            */
/*  input uint16 VlvAct_agInSpFuncIntThdMaxHys1_C;                            */
/*  input boolean VlvAct_bInSpFuncIntlHiOutIdcInt;                            */
/*  input boolean VlvAct_bInSpFuncIntlHiOutIdc;                               */
/*  input boolean VlvAct_bInSpFuncIntlLoOutIdcInt;                            */
/*  input boolean VlvAct_bInSpFuncIntlLoOutIdc;                               */
/*  input uint16 VlvAct_agCkInCmSpMin_C;                                      */
/*  input uint16 Vxx_vvtc_in_angl_sp_Int;                                     */
/*  input uint16 VlvAct_agInSpFuncIntlThdHi;                                  */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  output uint16 VlvAct_prm_agCkOpInVlvBol[4];                               */
/*  output uint16 VlvAct_prm_agCkOpInVlvMax[4];                               */
/*  output uint16 VLVACTINIF_u16SlewRateOut;                                  */
/*  output uint16 Vxx_vvtc_in_angl_sp_Int;                                    */
/*  output boolean VlvAct_bInSpFuncIntlLoOutIdc;                              */
/*  output boolean VlvAct_bInSpFuncIntlLoOutIdcInt;                           */
/*  output boolean VlvAct_bInSpFuncIntlHiOutIdcInt;                           */
/*  output boolean VlvAct_bInSpFuncIntlHiOutIdc;                              */
/*  output uint16 Vxx_vvtc_in_angl_sp;                                        */
/*  output uint16 VlvAct_agInSpFuncIntlThdHi;                                 */
/*  output uint16 VlvAct_agInSpFuncIntlThdLo;                                 */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0;                                   */
/*  output boolean VlvAct_bCmdInServoLocLop;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidVVTSetpoint(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   boolean bLocalLVlvAct_bInSpFuncIntlLo;
   boolean bLocalLVlvAct_bInSpFuncIntlHi;
   boolean bLocalVlvAct_bInVlvSpBenchModEna;
   boolean bLocalVlvActbInSpFuncIntlHi;
   boolean bLocalVlvActbInSpFuncIntlLo;
   boolean bLocalVlvAct_bAcvInServo;
   uint8   u8LocalVlvSys_agCkOpInVlvCorRaw;
   uint8   u8LocalCounter;
   sint8   s8LocalVlvAct_agCkOpInVlvReqRef0;
   uint16  u16LocalMax;
   uint16  u16LocalMin;
   uint16  u16LocalVxx_vvtc_in_angl_sp;
   uint16  u16LocalVxx_vvtc_in_angl_sp1;
   uint16  u16LocalVlvAct_agInActrTestPosSp;
   uint16  u16LocalVcpi_cam_offsets[VCPI_CAM_OFFSETS_COLS];
   /* !QAC Warning, Msg(2:3204) due to the use of VEMS_vidGET1DArray macro*/
   uint16  u16LocalVlvActagCkOpInVlvBol[VLVACT_PRM_AGCKOPINVLVBOL_COLS];
   uint16  u16LocalVlvActAgCkInVlvSpBencMod;
   uint16  u16LocalVlvagInSpFuncIntlThdHi;
   uint16  u16LocalVlvActprmagCkOpInVlvMax[VLVACT_PRM_AGCKOPINVLVMAX_COLS];
   sint16  s16LocalVlvAct_agCkInCmVlvActOfs;
   uint32  u32LocalCamOffsets[VCPI_CAM_OFFSETS_COLS];
   sint32  s32LocalHyst1High;
   sint32  s32LocalCalc;
   sint32  s32LocalHyst1Low;
   sint32  s32LocalLocalVvtcInAnglSp;
   sint32  s32LocalCamOffsets[VCPI_CAM_OFFSETS_COLS];
   sint32  s32LocalCalc1;
   sint32  s32LocalVlvAct_agCkOpInVlvRqRf0;


   VEMS_vidGET(VlvAct_bInVlvSpBenchModEna, bLocalVlvAct_bInVlvSpBenchModEna);
   VEMS_vidGET(VlvAct_agCkInVlvSpBenchMod, u16LocalVlvActAgCkInVlvSpBencMod);
   VEMS_vidGET(VlvSys_agCkOpInVlvCorRaw, u8LocalVlvSys_agCkOpInVlvCorRaw);
   VEMS_vidGET(VlvAct_agInActrTestPosSp, u16LocalVlvAct_agInActrTestPosSp);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);
   VEMS_vidGET(VlvAct_agCkInCmVlvActOfs, s16LocalVlvAct_agCkInCmVlvActOfs);

   VEMS_vidGET1DArray(Vcpi_cam_offsets,
                      VCPI_CAM_OFFSETS_COLS,
                      u16LocalVcpi_cam_offsets);

   for (u8LocalCounter = 0;
        u8LocalCounter < VCPI_CAM_OFFSETS_COLS;
        u8LocalCounter++)
   {
      u32LocalCamOffsets[u8LocalCounter] =
         (u16LocalVcpi_cam_offsets[u8LocalCounter] * 3) / 2;
      u16LocalVlvActagCkOpInVlvBol[u8LocalCounter] =
         (uint16)MATHSRV_udtMIN(u32LocalCamOffsets[u8LocalCounter], 11520);

      s32LocalCamOffsets[u8LocalCounter] =
         (sint32)((( u16LocalVcpi_cam_offsets[u8LocalCounter]
                   - VlvAct_agCkInCmSpMax_C) * 3) / 2);
      s32LocalCamOffsets[u8LocalCounter] =
         MATHSRV_udtMAX(s32LocalCamOffsets[u8LocalCounter], -11520);
      u16LocalVlvActprmagCkOpInVlvMax[u8LocalCounter] =
         (uint16)((s32LocalCamOffsets[u8LocalCounter] + 11520) % 11520);
   }
   VEMS_vidSET1DArray(VlvAct_prm_agCkOpInVlvBol,
                      VLVACT_PRM_AGCKOPINVLVBOL_COLS,
                      u16LocalVlvActagCkOpInVlvBol);

   VEMS_vidSET1DArray(VlvAct_prm_agCkOpInVlvMax,
                      VLVACT_PRM_AGCKOPINVLVMAX_COLS,
                      u16LocalVlvActprmagCkOpInVlvMax);

   u16LocalMax = (uint16)(((VlvAct_agInMaxSlopVlvSpPos_C * 25) + 3) / 6);
   u16LocalMin = (uint16)(((VlvAct_agInMinSlopVlvSpPos_C * 25) + 3) / 6);
   VLVACTINIF_u16SlewRateOut = MATHSRV_u16SlewFilter(VLVACTINIF_u16SlewRateOut,
                                                     Vxx_vvtc_in_angl_sp_cal,
                                                     u16LocalMax,
                                                     u16LocalMin);
   VLVACTINIF_u16SlewRateOut = (uint16)MATHSRV_udtMIN(VLVACTINIF_u16SlewRateOut,
                                                      1066);
   if (bLocalVlvAct_bInVlvSpBenchModEna != 0)
   {
      s32LocalLocalVvtcInAnglSp = (sint32)u16LocalVlvActAgCkInVlvSpBencMod;
   }
   else
   {
      if (Vxx_vvtc_in_angl_test_bed != 0)
      {
         s32LocalLocalVvtcInAnglSp = (sint32)(VLVACTINIF_u16SlewRateOut);
      }
      else
      {
         if (bLocalSrv_bActrTstInVVTEna != 0)
         {
            s32LocalLocalVvtcInAnglSp =
               (sint32)(u16LocalVlvAct_agInActrTestPosSp);
         }
         else
         {
            s32LocalCalc = (sint32)( VlvAct_agCkInCmRefOfs_C
                                   + s16LocalVlvAct_agCkInCmVlvActOfs
                                   + 1024);
            s32LocalLocalVvtcInAnglSp = ( s32LocalCalc
                                        - ( u8LocalVlvSys_agCkOpInVlvCorRaw
                                          * 8));
         }
      }
   }
   Vxx_vvtc_in_angl_sp_Int =
      (uint16)MATHSRV_udtCLAMP(s32LocalLocalVvtcInAnglSp, 0, 1066);

   /*SCHMITT_TRIGGER_1*/
   s32LocalHyst1Low = (sint32)( VlvAct_agInSpFuncIntlThd_C
                              - VlvAct_agInSpFuncIntlThdHysInf_C);
   s32LocalHyst1High = (sint32)( VlvAct_agInSpFuncIntlThd_C
                               + VlvAct_agInSpFuncIntlThdHys_C);
   if (s32LocalLocalVvtcInAnglSp > s32LocalHyst1High)
   {
      VEMS_vidSET(VlvAct_bInSpFuncIntlLoOutIdc, 0);
   }
   else
   {
      if (s32LocalLocalVvtcInAnglSp <= s32LocalHyst1Low)
      {
         VEMS_vidSET(VlvAct_bInSpFuncIntlLoOutIdc, 1);
      }
   }
   /*SCHMITT_TRIGGER_2*/
   s32LocalHyst1High = (sint32)( VlvAct_agInSpFuncIntlThdLo_C
                               + VlvAct_agInSpFuncIntlThdLoHys_C);
   if (s32LocalLocalVvtcInAnglSp > s32LocalHyst1High)
   {
      VlvAct_bInSpFuncIntlLoOutIdcInt = 0;
   }
   else
   {
      if (s32LocalLocalVvtcInAnglSp <= VlvAct_agInSpFuncIntlThdLo_C)
      {
         VlvAct_bInSpFuncIntlLoOutIdcInt = 1;
      }
   }
   /*SCHMITT_TRIGGER_3*/
   s32LocalHyst1Low = (sint32)( VlvAct_agInSpFuncIntlThdHi_C
                              - VlvAct_agInSpFuncIntlThdHiHys_C);
   if (s32LocalLocalVvtcInAnglSp > VlvAct_agInSpFuncIntlThdHi_C)
   {
      VlvAct_bInSpFuncIntlHiOutIdcInt = 1;
   }
   else
   {
      if (s32LocalLocalVvtcInAnglSp <= s32LocalHyst1Low)
      {
         VlvAct_bInSpFuncIntlHiOutIdcInt = 0;
      }
   }
   /*SCHMITT_TRIGGER_4*/
   s32LocalHyst1Low = (sint32)( VlvAct_agInSpFuncIntlThdMax_C
                              - VlvAct_agInSpFuncIntlThdMaxHys_C);
   s32LocalHyst1High = (sint32)( VlvAct_agInSpFuncIntlThdMax_C
                               + VlvAct_agInSpFuncIntThdMaxHys1_C);
   if (s32LocalLocalVvtcInAnglSp > s32LocalHyst1High)
   {
      VEMS_vidSET(VlvAct_bInSpFuncIntlHiOutIdc, 1);
   }
   else
   {
      if (s32LocalLocalVvtcInAnglSp <= s32LocalHyst1Low)
      {
         VEMS_vidSET(VlvAct_bInSpFuncIntlHiOutIdc, 0);
      }
   }
   /*Production of Vxx_vvtc_in_angl_sp*/
   if (VlvAct_bInSpFuncIntlHiOutIdcInt != 0)
   {
      VEMS_vidGET(VlvAct_bInSpFuncIntlHiOutIdc, bLocalVlvActbInSpFuncIntlHi);
      if (bLocalVlvActbInSpFuncIntlHi != 0)
      {
         u16LocalVxx_vvtc_in_angl_sp = VlvAct_agCkInCmSpMax_C;
      }
      else
      {
         u16LocalVxx_vvtc_in_angl_sp = VlvAct_agInSpFuncIntlThdHi_C;
      }
   }
   else
   {
      if (VlvAct_bInSpFuncIntlLoOutIdcInt != 0)
      {
         VEMS_vidGET(VlvAct_bInSpFuncIntlLoOutIdc, bLocalVlvActbInSpFuncIntlLo);
         if (bLocalVlvActbInSpFuncIntlLo != 0)
         {
            u16LocalVxx_vvtc_in_angl_sp = VlvAct_agCkInCmSpMin_C;
         }
         else
         {
            u16LocalVxx_vvtc_in_angl_sp = VlvAct_agInSpFuncIntlThdLo_C;
         }
      }
      else
      {
         u16LocalVxx_vvtc_in_angl_sp = Vxx_vvtc_in_angl_sp_Int;
      }
   }
   u16LocalVxx_vvtc_in_angl_sp1 =
      (uint16)MATHSRV_udtMIN(u16LocalVxx_vvtc_in_angl_sp, 1066);
   VEMS_vidSET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp1);
   /*Production of VlvAct_agInSpFuncIntlThdHi*/
   VEMS_vidGET(VlvAct_bInSpFuncIntlHiOutIdc, bLocalLVlvAct_bInSpFuncIntlHi);
   if (bLocalLVlvAct_bInSpFuncIntlHi != 0)
   {
      u16LocalVlvagInSpFuncIntlThdHi = VlvAct_agCkInCmSpMax_C;
   }
   else
   {
      u16LocalVlvagInSpFuncIntlThdHi = VlvAct_agInSpFuncIntlThdHi_C;
   }
   VlvAct_agInSpFuncIntlThdHi =
      (uint16)MATHSRV_udtMIN(u16LocalVlvagInSpFuncIntlThdHi, 1066);
   /*Production of VlvAct_agInSpFuncIntlThdLo*/
   if (VlvAct_bInSpFuncIntlLoOutIdcInt != 0)
   {
      VEMS_vidGET(VlvAct_bInSpFuncIntlLoOutIdc, bLocalLVlvAct_bInSpFuncIntlLo);
      if (bLocalLVlvAct_bInSpFuncIntlLo != 0)
      {
         VlvAct_agInSpFuncIntlThdLo =
            (uint16)MATHSRV_udtMIN(VlvAct_agCkInCmSpMin_C, 1066);
      }
      else
      {
         VlvAct_agInSpFuncIntlThdLo =
            (uint16)MATHSRV_udtMIN(VlvAct_agInSpFuncIntlThdLo_C, 1066);
      }
   }
   else
   {
      if (VlvAct_bInSpFuncIntlHiOutIdcInt != 0)
      {
         VlvAct_agInSpFuncIntlThdLo = VlvAct_agInSpFuncIntlThdHi;
      }
      else
      {
         VlvAct_agInSpFuncIntlThdLo = Vxx_vvtc_in_angl_sp_Int;
      }
   }
   VLVACTINIF_vidCalcSatSetpoint();
   /*Production of VlvAct_agCkOpInVlvReqRef0*/
   s32LocalCalc1 = (sint32)( ( VlvAct_agCkInCmRefOfs_C
                             + s16LocalVlvAct_agCkInCmVlvActOfs)
                           - u16LocalVxx_vvtc_in_angl_sp);
   s32LocalVlvAct_agCkOpInVlvRqRf0 = (s32LocalCalc1 / 8);
   s8LocalVlvAct_agCkOpInVlvReqRef0 =
      (sint8)MATHSRV_udtCLAMP(s32LocalVlvAct_agCkOpInVlvRqRf0, -128, 127);
   VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0, s8LocalVlvAct_agCkOpInVlvReqRef0);
   /*Production of VlvAct_bCmdInServoLocLop*/
   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);
   if (  (VlvAct_bInSpFuncIntlHiOutIdcInt == 0)
      && (VlvAct_bInSpFuncIntlLoOutIdcInt == 0)
      && (bLocalVlvAct_bAcvInServo != 0))
   {
      VEMS_vidSET(VlvAct_bCmdInServoLocLop, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bCmdInServoLocLop, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidCalcSatSetpoint                              */
/* !Description :  En cas d’incursion en dehors de la plage fonctionnelle     */
/*                 définie par les calibrations, on renvoie à la boucle d’air */
/*                 les valeurs des consignes saturées qui sont mises  toutes  */
/*                 les deux à la même valeur de reconfiguration.              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_agCkInCmVlvActOfs;                                    */
/*  input sint16 VlvAct_agCkInCmRefOfs_C;                                     */
/*  input boolean VlvAct_bInSpFuncIntlLoOutIdcInt;                            */
/*  input boolean VlvAct_bInSpFuncIntlHiOutIdcInt;                            */
/*  input boolean VlvAct_bAcvVlvAgReqRef0Sat_C;                               */
/*  input uint16 VlvAct_agInSpFuncIntlThdLo;                                  */
/*  input uint16 VlvAct_agInSpFuncIntlThdHi;                                  */
/*  input uint16 VlvAct_agCkInCmSpMax_C;                                      */
/*  input uint16 VlvAct_agCkInCmSpMin_C;                                      */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0Min;                                */
/*  output sint8 VlvAct_agCkOpInVlvReqRef0Max;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidCalcSatSetpoint(void)
{
   sint8   s8LocalCalc;
   sint8   s8LocalCalcMin;
   sint8   s8LocalCalcMax;
   sint16  s16LocalVlvAct_agCkInCmVlvActOfs;
   sint32  s32LocalCalc;
   sint32  s32LocalCalcMin;
   sint32  s32LocalCalcMax;


   VEMS_vidGET(VlvAct_agCkInCmVlvActOfs, s16LocalVlvAct_agCkInCmVlvActOfs);
   s32LocalCalc = s16LocalVlvAct_agCkInCmVlvActOfs + VlvAct_agCkInCmRefOfs_C;

   if (  (  (VlvAct_bInSpFuncIntlLoOutIdcInt != 0)
         || (VlvAct_bInSpFuncIntlHiOutIdcInt != 0))
      && (VlvAct_bAcvVlvAgReqRef0Sat_C != 0))
   {
      if (VlvAct_bInSpFuncIntlLoOutIdcInt != 0)
      {
         s32LocalCalc = s32LocalCalc - VlvAct_agInSpFuncIntlThdLo;
         if (s32LocalCalc >= 0)
         {
            s32LocalCalc = (s32LocalCalc + 4) / 8;
         }
         else
         {
            s32LocalCalc = (s32LocalCalc - 4) / 8;
         }
         s8LocalCalc = (sint8)MATHSRV_udtCLAMP(s32LocalCalc, -128, 127);
         VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Min, s8LocalCalc);
         VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Max, s8LocalCalc);
      }
      else
      {
         s32LocalCalc = s32LocalCalc - VlvAct_agInSpFuncIntlThdHi;
         if (s32LocalCalc >= 0)
         {
            s32LocalCalc = (s32LocalCalc + 4) / 8;
         }
         else
         {
            s32LocalCalc = (s32LocalCalc - 4) / 8;
         }
         s8LocalCalc = (sint8)MATHSRV_udtCLAMP(s32LocalCalc, -128, 127);
         VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Min, s8LocalCalc);
         VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Max, s8LocalCalc);
      }
   }
   else
   {
      s32LocalCalcMin = s32LocalCalc - VlvAct_agCkInCmSpMax_C;
      if (s32LocalCalcMin >= 0)
      {
         s32LocalCalcMin = (s32LocalCalcMin + 4) / 8;
      }
      else
      {
         s32LocalCalcMin = (s32LocalCalcMin - 4) / 8;
      }
      s8LocalCalcMin = (sint8)MATHSRV_udtCLAMP(s32LocalCalcMin, -128, 127);
      VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Min, s8LocalCalcMin);

      s32LocalCalcMax = s32LocalCalc - VlvAct_agCkInCmSpMin_C;
      if (s32LocalCalcMax >= 0)
      {
         s32LocalCalcMax = (s32LocalCalcMax + 4) / 8;
      }
      else
      {
         s32LocalCalcMax = (s32LocalCalcMax - 4) / 8;
      }
      s8LocalCalcMax = (sint8)MATHSRV_udtCLAMP(s32LocalCalcMax, -128, 127);
      VEMS_vidSET(VlvAct_agCkOpInVlvReqRef0Max, s8LocalCalcMax);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINIF_vidVVTDiagInhFlagCal                            */
/* !Description :  On parle de croissement de soupape lorsque le RFE a lieu   */
/*                 avant l’ AOA et si la différence des pression admission et */
/*                 échappement est supérieure à un seuil auquel cas le booléen*/
/*                 indiquant un balayage des soupapes est positionné à 1.     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input boolean VlvAct_bInhDiagPresScavIdc_C;                               */
/*  input uint16 InM_pDsThr_facVlvOvlp;                                       */
/*  input uint16 ExM_pExMnfEstim_facVlvOvlp;                                  */
/*  input sint16 VlvAct_agCkInExVlvDif;                                       */
/*  input uint16 VlvAct_agCkInExVlvDif_T[10];                                 */
/*  input uint16 VlvAct_pInhDiagPresScavDif_M[10];                            */
/*  input boolean VLVACTINIF_bSwitchOutPrev;                                  */
/*  input boolean VLVACTINIF_bTimerInitPrev;                                  */
/*  input uint16 VlvAct_tiDlyInhDiagPresScavOff_C;                            */
/*  input uint16 VlvAct_tiDlyInhDiagPresScavOff;                              */
/*  input boolean VLVACTINIF_bTimerOut;                                       */
/*  output sint16 VlvAct_agCkInExVlvDif;                                      */
/*  output uint16 VlvAct_tiDlyInhDiagPresScavOff;                             */
/*  output boolean VLVACTINIF_bTimerOut;                                      */
/*  output boolean VlvAct_bInhDiagPresScav;                                   */
/*  output boolean VLVACTINIF_bSwitchOutPrev;                                 */
/*  output boolean VLVACTINIF_bTimerInitPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINIF_vidVVTDiagInhFlagCal(void)
{
   boolean bLocalSwitchOut;
   boolean bLocalTimerInit;
   uint16  u16LocalInMpDsThrfacVlvOvlp;
   uint16  u16LocalExMpExMnfEstimfacVlvlp;
   uint16  u16LocalScalX;
   uint16  u16LocalPara;
   uint16  u16LocalInterp1d;
   sint16  s16LocalExtagCkClExVlvEstimRef0;
   sint16  s16LocalExtagCkOpInVlvEstimRef0;
   sint32  s32LocalCalc;
   sint32  s32LocalScalX;
   sint32  s32LocalInterp;


   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExtagCkClExVlvEstimRef0);
   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExtagCkOpInVlvEstimRef0);
   s32LocalScalX = (sint32)( s16LocalExtagCkClExVlvEstimRef0
                           - s16LocalExtagCkOpInVlvEstimRef0);
   VlvAct_agCkInExVlvDif = (sint16)MATHSRV_udtCLAMP(s32LocalScalX,
                                                    -2048,
                                                    2048);

   if (VlvAct_bInhDiagPresScavIdc_C != 0)
   {
      bLocalSwitchOut = 0;
   }
   else
   {
      VEMS_vidGET(InM_pDsThr_facVlvOvlp, u16LocalInMpDsThrfacVlvOvlp);
      VEMS_vidGET(ExM_pExMnfEstim_facVlvOvlp, u16LocalExMpExMnfEstimfacVlvlp);

      u16LocalScalX = (uint16)(VlvAct_agCkInExVlvDif + 2048);

      u16LocalPara = MATHSRV_u16CalcParaIncAryU16(VlvAct_agCkInExVlvDif_T,
                                                  u16LocalScalX,
                                                  10);
      u16LocalInterp1d = MATHSRV_u16Interp1d(VlvAct_pInhDiagPresScavDif_M,
                                             u16LocalPara);

      s32LocalCalc = (sint32)( u16LocalInMpDsThrfacVlvOvlp
                             - u16LocalExMpExMnfEstimfacVlvlp);
      s32LocalInterp = (u16LocalInterp1d * 2) - 65536;

      if (  (s16LocalExtagCkClExVlvEstimRef0 > s16LocalExtagCkOpInVlvEstimRef0)
         && (s32LocalCalc > s32LocalInterp))
      {
         bLocalSwitchOut = 1;
      }
      else
      {
         bLocalSwitchOut = 0;
      }
   }

   if (  (VLVACTINIF_bSwitchOutPrev != 0)
      && (bLocalSwitchOut == 0))
   {
      bLocalTimerInit = 1;
   }
   else
   {
      bLocalTimerInit = 0;
   }

   if (  (VLVACTINIF_bTimerInitPrev == 0)
      && (bLocalTimerInit != 0))
   {
      VlvAct_tiDlyInhDiagPresScavOff = VlvAct_tiDlyInhDiagPresScavOff_C;
      if (VlvAct_tiDlyInhDiagPresScavOff == 0)
      {
         VLVACTINIF_bTimerOut = 1;
      }
      else
      {
         VLVACTINIF_bTimerOut = 0;
      }
   }
   else
   {
      if (VlvAct_tiDlyInhDiagPresScavOff > 0)
      {
         VlvAct_tiDlyInhDiagPresScavOff =
            (uint16)(VlvAct_tiDlyInhDiagPresScavOff - 1);

         if (VlvAct_tiDlyInhDiagPresScavOff == 0)
         {
            VLVACTINIF_bTimerOut = 1;
         }
         else
         {
            VLVACTINIF_bTimerOut = 0;
         }
      }
   }

   if (  (VLVACTINIF_bTimerOut != 0)
      && (bLocalSwitchOut == 0))
   {
      VEMS_vidSET(VlvAct_bInhDiagPresScav, 0);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInhDiagPresScav, 1);
   }

   VLVACTINIF_bSwitchOutPrev = bLocalSwitchOut;
   VLVACTINIF_bTimerInitPrev = bLocalTimerInit;
}
/*------------------------------- end of file --------------------------------*/