/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCRK                                                   */
/* !Description     : IGCRK component.                                        */
/*                                                                            */
/* !Module          : IGCRK                                                   */
/* !Description     : CALCUL DE L’AVANCE A L’ALLUMAGE SOUS DEMARREUR.         */
/*                                                                            */
/* !File            : IGCRK_FCT1.C                                            */
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
/*   1 / IGCRK_vidInitOutput                                                  */
/*   2 / IGCRK_vidCalcAdvanceCranking                                         */
/*                                                                            */
/* !Reference   : V02 NT 09 04922 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGCRK/IGCRK_FCT1.C_v              $*/
/* $Revision::   1.4      $$Author::   achebino       $$Date::   22 Nov 2012 $*/
/* $Author::   achebino                               $$Date::   22 Nov 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCRK.h"
#include "IGCRK_L.h"
#include "IGCRK_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCRK_vidInitOutput                                        */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean IGCRK_bIntrSTTEsHiEngSpd_Prev;                             */
/*  output boolean IGCRK_bIntrSTTEsLoEngSpd_Prev;                             */
/*  output boolean IGCRK_bAcvStructAdv_Prev;                                  */
/*  output boolean IGCRK_bRSAltCtlOut;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCRK_vidInitOutput(void)
{
   /* Initialization of previous values */
   IGCRK_bIntrSTTEsHiEngSpd_Prev = 0;
   IGCRK_bIntrSTTEsLoEngSpd_Prev = 0;
   IGCRK_bAcvStructAdv_Prev = 0;
   /* Various initializations*/
   IGCRK_bRSAltCtlOut = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCRK_vidCalcAdvanceCranking                               */
/* !Description :  L’avance sous démarreur est calculée en fonction de la     */
/*                 température d’eau et du régime moteur.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input boolean IgSys_bAcvStructAdv;                                        */
/*  input uint8 Regime_moteur_9_bkpt_map[9];                                  */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input boolean IGCRK_bAcvStructAdv_Prev;                                   */
/*  input uint16 IgCrk_seuil_regime_C;                                        */
/*  input boolean IGCRK_bIntrSTTEsHiEngSpd_Prev;                              */
/*  input boolean IGCRK_bIntrSTTEsLoEngSpd_Prev;                              */
/*  input boolean IGCRK_bRSAltCtlOut;                                         */
/*  input uint8 Crank_ign_adv_STT_Intr_map[9][16];                            */
/*  input uint8 Crank_ign_adv_STT_map[9][16];                                 */
/*  input uint8 Crank_ign_adv_map[9][16];                                     */
/*  output boolean IGCRK_bRSAltCtlOut;                                        */
/*  output uint8 IgSys_agIgStrtSp;                                            */
/*  output uint8 IgSys_agIgStrtSpNxt;                                         */
/*  output boolean IGCRK_bIntrSTTEsHiEngSpd_Prev;                             */
/*  output boolean IGCRK_bIntrSTTEsLoEngSpd_Prev;                             */
/*  output boolean IGCRK_bAcvStructAdv_Prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCRK_vidCalcAdvanceCranking(void)
{
   boolean bLocalCoEs_bIntrSTTEsHiEngSpd;
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   boolean bLocalIgSys_bAcvStructAdv;
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalRegimeMoteur32;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalIgSysAgIgStrtSp;
   uint16  u16LocalCrankIgnAdvMap1;
   uint16  u16LocalCrankIgnAdvMap2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegimeMoteur32);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, bLocalCoEs_bIntrSTTEsHiEngSpd);
   VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, bLocalCoEs_bIntrSTTEsLoEngSpd);
   VEMS_vidGET(IgSys_bAcvStructAdv, bLocalIgSys_bAcvStructAdv);

   u16LocalCrankIgnAdvMap1 =
      MATHSRV_u16CalcParaIncAryU8(Regime_moteur_9_bkpt_map,
                                  u8LocalRegimeMoteur32,
                                  9);
   u16LocalCrankIgnAdvMap2 =
      MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                  u8LocalTemperature_eau,
                                  16);
   /* bascule RS (R Prioritaire)*/
   if (  (bLocalIgSys_bAcvStructAdv != 0)
      && (IGCRK_bAcvStructAdv_Prev == 0))
   {
      IGCRK_bRSAltCtlOut = 0;
   }
   else
   {
      if (  (u8LocalRegimeMoteur32 >= IgCrk_seuil_regime_C)
         && (  (  (bLocalCoEs_bIntrSTTEsHiEngSpd != 0)
               && (IGCRK_bIntrSTTEsHiEngSpd_Prev == 0))
            || (  (bLocalCoEs_bIntrSTTEsLoEngSpd != 0)
               && (IGCRK_bIntrSTTEsLoEngSpd_Prev == 0))))
      {
         IGCRK_bRSAltCtlOut = 1;
      }
   }
   if (IGCRK_bRSAltCtlOut != 0)
   {
      u8LocalIgSysAgIgStrtSp =
                     MATHSRV_u8Interp2d(&Crank_ign_adv_STT_Intr_map[0][0],
                                         u16LocalCrankIgnAdvMap1,
                                         u16LocalCrankIgnAdvMap2,
                                         16);
   }
   else
   {
      if ( bLocalCoPTSt_bRStrtSTT != 0)
      {
         u8LocalIgSysAgIgStrtSp =
                        MATHSRV_u8Interp2d(&Crank_ign_adv_STT_map[0][0],
                                           u16LocalCrankIgnAdvMap1,
                                           u16LocalCrankIgnAdvMap2,
                                           16);
      }
      else
      {
         u8LocalIgSysAgIgStrtSp = MATHSRV_u8Interp2d(&Crank_ign_adv_map[0][0],
                                                   u16LocalCrankIgnAdvMap1,
                                                   u16LocalCrankIgnAdvMap2,
                                                   16);
      }
   }

   VEMS_vidSET(IgSys_agIgStrtSp, u8LocalIgSysAgIgStrtSp);
   VEMS_vidSET(IgSys_agIgStrtSpNxt,u8LocalIgSysAgIgStrtSp);
   IGCRK_bIntrSTTEsHiEngSpd_Prev = bLocalCoEs_bIntrSTTEsHiEngSpd;
   IGCRK_bIntrSTTEsLoEngSpd_Prev = bLocalCoEs_bIntrSTTEsLoEngSpd;
   IGCRK_bAcvStructAdv_Prev = bLocalIgSys_bAcvStructAdv;
}
/*------------------------------- end of file --------------------------------*/