/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKDIAG                                              */
/* !Description     : SYNCCKDIAG Component                                    */
/*                                                                            */
/* !Module          : SYNCCKDIAG                                              */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL VILEBREQUIN              */
/*                                                                            */
/* !File            : SYNCCKDIAG_FCT2.C                                       */
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
/*   1 / SYNCCKDIAG_vidBackUpMode                                             */
/*   2 / SYNCCKDIAG_vidSetEdgePos                                             */
/*   3 / SYNCCKDIAG_vidInCamSig                                               */
/*   4 / SYNCCKDIAG_vidExCamSig                                               */
/*   5 / SYNCCKDIAG_vidReadCkMode                                             */
/*   6 / SYNCCKDIAG_vidAcvDwgMode                                             */
/*   7 / SYNCCKDIAG_vidInitSelectCkMode                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6886036 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKDIAG/SYNCCKDIAG_FCT2.C_$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   29 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   29 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCCKDIAG.h"
#include "SYNCCKDIAG_L.h"
#include "SYNCCKDIAG_IM.h"
#include "CRKHAL.h"
#include "CAMHAL.h"
#include "SYNCCKDIAG_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidBackUpMode                                   */
/* !Description :  En cas de demande d’activation du back-up mode vilebrequin,*/
/*                 on effectue une  préparation pour le passage en mode       */
/*                 dégradé, puis on vient lire le mode de fonctionnement en   */
/*                 cours et on active enfin le mode de back-up.               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCCKDIAG_vidSetEdgePos();                              */
/*  extf argret void SYNCCKDIAG_vidReadCkMode();                              */
/*  extf argret void SYNCCKDIAG_vidAcvDwgMode();                              */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean SYNCCKDIAG_bDgoCkSigPrev;                                   */
/*  input boolean Sync_bForcDwgMode;                                          */
/*  output boolean SYNCCKDIAG_bDgoCkSigPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidBackUpMode(void)
{
   boolean bLocalSync_bDgoCkSig;


   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);

   if (  (bLocalSync_bDgoCkSig !=0)
      && (SYNCCKDIAG_bDgoCkSigPrev == 0))
   {
      SYNCCKDIAG_vidSetEdgePos();
   }

   SYNCCKDIAG_bDgoCkSigPrev = bLocalSync_bDgoCkSig;
   SYNCCKDIAG_vidReadCkMode();

   if (Sync_bForcDwgMode != 0)
   {
      SYNCCKDIAG_vidAcvDwgMode();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidSetEdgePos                                   */
/* !Description :  Lorsqu’une demande de passage en mode de back-up           */
/*                 vilebrequin est activée on envoie au LDB la position       */
/*                 apprise des fronts arbre à cames.                          */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03088_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCCKDIAG_vidInCamSig();                                */
/*  extf argret void SYNCCKDIAG_vidExCamSig();                                */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input uint8 CoSync_stSigCm2Sync;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidSetEdgePos(void)
{
   boolean bLocalSync_bDgoCkSig;
   uint8   u8LocalCoSync_stSigCm2Sync;


   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(CoSync_stSigCm2Sync,u8LocalCoSync_stSigCm2Sync);

   if (  (u8LocalCoSync_stSigCm2Sync == 1)
      && (bLocalSync_bDgoCkSig !=0))
   {
      SYNCCKDIAG_vidInCamSig();
   }
   if (  (u8LocalCoSync_stSigCm2Sync == 2)
      && (bLocalSync_bDgoCkSig !=0))
   {
      SYNCCKDIAG_vidExCamSig();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidInCamSig                                     */
/* !Description :  utiliser le signal admission  qui définit le signal arbre à*/
/*                 cames                                                      */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void CAMHAL_vidSetTrueEdgePos(argin CAMHAL_tudtChannel        */
/* udtChannelName, argio uint16 *pau16CamEdgePositionTable);                  */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidInCamSig(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalVcpi_cam_offsets[VCPI_CAM_OFFSETS_COLS];
   uint32 u32LocalResult;


   VEMS_vidGET1DArray(Vcpi_cam_offsets,
                      VCPI_CAM_OFFSETS_COLS,
                      u16LocalVcpi_cam_offsets);
   for (u8LocalIndex = 0; u8LocalIndex < VCPI_CAM_OFFSETS_COLS; u8LocalIndex++)
   {
      u32LocalResult = (uint32)(6 * u16LocalVcpi_cam_offsets[u8LocalIndex]);
      u16LocalVcpi_cam_offsets[u8LocalIndex] =
           (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   }
   /*Resolution of the 2nd parameter of CAMHAL_vidSetTrueEdgePos: 1/64 °CK*/
   CAMHAL_vidSetTrueEdgePos(CAMHAL_udtCH_INTAKE_CAMSHAFT,
                            &u16LocalVcpi_cam_offsets[0]);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidExCamSig                                     */
/* !Description :  utiliser le signal échappement qui définit le signal arbre */
/*                 à cames.                                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void CAMHAL_vidSetTrueEdgePos(argin CAMHAL_tudtChannel        */
/* udtChannelName, argio uint16 *pau16CamEdgePositionTable);                  */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidExCamSig(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalVcpe_cam_offsets[VCPE_CAM_OFFSETS_COLS];
   uint32 u32LocalResult;

   VEMS_vidGET1DArray(Vcpe_cam_offsets,
                      VCPE_CAM_OFFSETS_COLS,
                      u16LocalVcpe_cam_offsets);
   for (u8LocalIndex = 0; u8LocalIndex < VCPE_CAM_OFFSETS_COLS; u8LocalIndex++)
   {
      u32LocalResult = (uint32)(6 * u16LocalVcpe_cam_offsets[u8LocalIndex]);
      u16LocalVcpe_cam_offsets[u8LocalIndex] =
           (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   }
   /*Resolution of the 2nd parameter of CAMHAL_vidSetTrueEdgePos: 1/64 °CK*/
   CAMHAL_vidSetTrueEdgePos(CAMHAL_udtCH_EXHAUST_CAMSHAFT,
                            &u16LocalVcpe_cam_offsets[0]);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidReadCkMode                                   */
/* !Description :  lire le mode vilebrequin qui est actif                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03088_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  CRKHAL_udtReadMode(argout CRKHAL_tenuMode     */
/* *penuMode);                                                                */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bAcvBchModCk_C;                                        */
/*  input boolean Sync_bAcvBackUpCk_C;                                        */
/*  input boolean SYNCCKDIAG_bSelectCkMode;                                   */
/*  input uint8 Sync_stCkModeRead;                                            */
/*  input uint8 Sync_stCkMode;                                                */
/*  output uint8 Sync_stCkModeRead;                                           */
/*  output boolean SYNCCKDIAG_bSelectCkMode;                                  */
/*  output uint8 Sync_stCkMode;                                               */
/*  output boolean Sync_bForcDwgMode;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidReadCkMode(void)
{
   boolean         bLocalSync_bDgoCkSig;
   Std_ReturnType  StdLocalValidCall;
   CRKHAL_tenuMode enuLocalCrkMode;
   uint8           u8LocalSync_stCkModeRead;


   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   StdLocalValidCall = CRKHAL_udtReadMode(&enuLocalCrkMode);

   if (StdLocalValidCall != E_OK)
   {
      u8LocalSync_stCkModeRead = CRKHAL_udtNOT_SET;
   }
   else
   {
      u8LocalSync_stCkModeRead = enuLocalCrkMode;
   }
   Sync_stCkModeRead = (uint8)MATHSRV_udtMIN(u8LocalSync_stCkModeRead, 15);

   /*Updating SYNCCKDIAG_bSelectCkMode*/
   if (bLocalSync_bDgoCkSig != 0)
   {
      SYNCCKDIAG_bSelectCkMode = 1;
   }

   if (Sync_bAcvBchModCk_C != 0)
   {
      if (Sync_bAcvBackUpCk_C != 0)
      {
         Sync_stCkMode = CRKHAL_udtDOWNGRADED_MODE;
      }
      else
      {
         Sync_stCkMode = CRKHAL_udtNORMAL_MODE;
      }
   }
   else
   {
      if (SYNCCKDIAG_bSelectCkMode != 0)
      {
         Sync_stCkMode = CRKHAL_udtDOWNGRADED_MODE;
      }
      else
      {
         Sync_stCkMode = CRKHAL_udtNORMAL_MODE;
      }
   }

   if (Sync_stCkModeRead != Sync_stCkMode)
   {
      Sync_bForcDwgMode = 1;
   }
   else
   {
      Sync_bForcDwgMode = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidAcvDwgMode                                   */
/* !Description :  Appel de l’API permettant le changement de mode            */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03088_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_vidSetMode(argin CRKHAL_tenuMode enuMode);        */
/*  input uint8 Sync_stCkMode;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidAcvDwgMode(void)
{
   CRKHAL_vidSetMode(Sync_stCkMode);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKDIAG_vidInitSelectCkMode                             */
/* !Description :  Initialisation du mode de selection                        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SYNCCKDIAG_bSelectCkMode;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKDIAG_vidInitSelectCkMode(void)
{
   SYNCCKDIAG_bSelectCkMode = 0;
}
/*------------------------------- end of file --------------------------------*/