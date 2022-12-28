/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GMIL                                                    */
/* !Description     : GMIL Component                                          */
/*                                                                            */
/* !Module          : GMIL                                                    */
/* !Description     : GESTIONNAIRE DE LA LAMPE DEFAUT                         */
/*                                                                            */
/* !File            : GMIL_FCT1.C                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / GMIL_vidInitOutput                                                   */
/*   2 / GMIL_Init                                                            */
/*   3 / GMIL_StrtCntIni                                                      */
/*   4 / GMIL_StrtMng                                                         */
/*   5 / GMIL_DftAndWarnSt                                                    */
/*   6 / GMIL_Req                                                             */
/*   7 / GMIL_MilReqCanConf                                                   */
/*   8 / GMIL_DftSt                                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 04661 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GMIL/GMIL_FCT1.c_v           $*/
/* $Revision::   1.6      $$Author::   alaouni        $$Date::   22 Dec 2011 $*/
/* $Author::   alaouni                                $$Date::   22 Dec 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "GMIL.h"
#include "GMIL_L.h"
#include "GMIL_im.h"
#include "VEMS.h"
#include "NVMSRV.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_vidInitOutput                                         */
/* !Description :  Initializing outputs of GMIL module.                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean GMIL_bMilDftPres;                                          */
/*  output boolean GMIL_bWarnSt;                                              */
/*  output boolean GMIL_bDftMilBlink;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_vidInitOutput(void)
{
   VEMS_vidSET(GMIL_bMilDftPres, 0);
   VEMS_vidSET(GMIL_bWarnSt, 0);
   VEMS_vidSET(GMIL_bDftMilBlink, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_Init                                                  */
/* !Description :  Initialisation des variables et récupération des données   */
/*                 mémorisées en EEPROM au Power Latch précédent.             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean GMIL_bInhMilRst_C;                                          */
/*  input uint8 GMIL_tiMilOnMin_C;                                            */
/*  output uint8 GMIL_tiStrtMng;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_Init(void)
{
   if(GMIL_bInhMilRst_C == TRUE)
   {
      GMIL_tiStrtMng = 0;
   }
   else
   {
      GMIL_tiStrtMng = GMIL_tiMilOnMin_C;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_StrtCntIni                                            */
/* !Description :  Cette fonction permet d'initialiser les variables sur      */
/*                 l'événement GD_EveKeyOBD                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GMIL_tiMilOnMin_C;                                            */
/*  output uint8 GMIL_tiStrtMng;                                              */
/*  output boolean GMIL_bStrtMilOn;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_StrtCntIni(void)
{
   GMIL_tiStrtMng = GMIL_tiMilOnMin_C;

   if(GMIL_tiMilOnMin_C != 0)
   {
      GMIL_bStrtMilOn = 1;
   }
   else
   {
      GMIL_bStrtMilOn = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_StrtMng                                               */
/* !Description :  Cette fonction exécutée à la récurrence GD_SdlSlow_GMIL    */
/*                 gère l'allumage de la MIL avant démarrage.                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Clef_off_on_sans_dem;                                       */
/*  input uint8 GMIL_tiStrtMng;                                               */
/*  input uint8 GMIL_tiMilOnMin_C;                                            */
/*  output boolean GMIL_bStrtMilOn;                                           */
/*  output uint8 GMIL_tiStrtMng;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_StrtMng(void)
{
   boolean bLocalClef_off_on_sans_dem;

   VEMS_vidGET(Clef_off_on_sans_dem, bLocalClef_off_on_sans_dem);

   if(GMIL_tiStrtMng > 0)
   {
      GMIL_bStrtMilOn = TRUE;

      GMIL_tiStrtMng = (uint8)(GMIL_tiStrtMng - 1);
   }
   else
   {
      if((bLocalClef_off_on_sans_dem == TRUE)
         &&(GMIL_tiMilOnMin_C != 0))
      {
         GMIL_bStrtMilOn = TRUE;
      }
      else
      {
         GMIL_bStrtMilOn = FALSE;
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_DftAndWarnSt                                          */
/* !Description :  Cette fonction produit 2 requêtes d'allumage voyant:       */
/*                 clignotement et fixe ainsi que l'état voyant MIL pour le   */
/*                 Scan Tool.                                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGOBDState  GOBD_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 GD_au8IdxClasObd[7];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input boolean Tra_bLiMILReq;                                              */
/*  input boolean CoHVB_bMILReq;                                              */
/*  input boolean Ext_bLiMILReqSCT;                                           */
/*  input boolean Ext_bLiMILReqHCU2;                                          */
/*  input boolean Fco_for_mf_cat_dam_actif;                                   */
/*  output boolean GMIL_bDftMilOn;                                            */
/*  output boolean GMIL_bDftMilBlink;                                         */
/*  output boolean GMIL_bWarnSt;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_DftAndWarnSt(void)
{
   boolean             bLocalEnaMil;
   boolean             bLocalTra_bLiMILReq;
   boolean             bLocalCoHVB_bMILReq;
   boolean             bLocalExt_bLiMILReqSCT;
   boolean             bLocalExt_bLiMILReqHCU2;
   boolean             bLocalFco_for_mf;
   boolean             bLocalWarnSt_cpy;
   boolean             bLocalGMIL_bDftMilOn;
   uint8               u8LocalExit;       /* info de sortie de boucle         */
   uint8               u8LocalIdxClasObd; /* OBD class index                  */
   GDFRM_tenuGOBDState enuLocalGobd;      /* etat de l'automate OBD d'1 dft   */
   sint32              s32LocalIdx;       /* idx local pour parcours defauts  */


   bLocalGMIL_bDftMilOn = FALSE;
   bLocalWarnSt_cpy = FALSE;
   u8LocalExit = FALSE;

   for (s32LocalIdx = 0;
      (  (s32LocalIdx < GD_DFT_NB)
         && (u8LocalExit == FALSE));
      s32LocalIdx++)
   {
      u8LocalIdxClasObd = GD_au8IdxClasObd[s32LocalIdx];
      bLocalEnaMil = GD_astrClasObd[u8LocalIdxClasObd].bEnaMIL;

      if (bLocalEnaMil == TRUE)
      {
         enuLocalGobd = GOBD_tenuGetStDgo(s32LocalIdx);

         if (  (enuLocalGobd == GOBD_ETAT_ENREGISTRE)
            || (enuLocalGobd == GOBD_ETAT_HISTORIQUE_ON))
         {
            bLocalGMIL_bDftMilOn = TRUE;
            bLocalWarnSt_cpy = TRUE;
            u8LocalExit = TRUE;
         }
      }
   }

   VEMS_vidGET(Tra_bLiMILReq, bLocalTra_bLiMILReq);
   VEMS_vidGET(CoHVB_bMILReq, bLocalCoHVB_bMILReq);
   VEMS_vidGET(Ext_bLiMILReqSCT, bLocalExt_bLiMILReqSCT);
   VEMS_vidGET(Ext_bLiMILReqHCU2, bLocalExt_bLiMILReqHCU2);

   if (  (bLocalTra_bLiMILReq == TRUE)
      || (bLocalCoHVB_bMILReq == TRUE)
      || (bLocalExt_bLiMILReqSCT == TRUE)
      || (bLocalExt_bLiMILReqHCU2 == TRUE))
   {
      bLocalGMIL_bDftMilOn = TRUE;
   }
   VEMS_vidSET(GMIL_bDftMilOn, bLocalGMIL_bDftMilOn);

   VEMS_vidGET(Fco_for_mf_cat_dam_actif, bLocalFco_for_mf);
   if (bLocalFco_for_mf == TRUE)
   {
      bLocalWarnSt_cpy = TRUE;
   }

   VEMS_vidSET(GMIL_bDftMilBlink, bLocalFco_for_mf);
   VEMS_vidSET(GMIL_bWarnSt, bLocalWarnSt_cpy);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_Req                                                   */
/* !Description :  Cet automate synthétise via la variable GMIL_stMilReq les  */
/*                 demandes d'allumage issues des fonctions                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st81 GMIL_stMILReq;                                                 */
/*  input boolean GMIL_bInhMilRst_C;                                          */
/*  input boolean GMIL_bDftMilBlink;                                          */
/*  input boolean GMIL_bStrtMilOn;                                            */
/*  input boolean GMIL_bDftMilOn;                                             */
/*  output st81 GMIL_stMILReq;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_Req
(
   uint8 u8Event
)
{
   uint8   u8LocalstMILReq_cpy;
   boolean bLocalAcvMilReq;

   VEMS_vidGET(GMIL_stMILReq, u8LocalstMILReq_cpy);

   switch(u8Event)
   {

/* -- Event Reset ----------------------------------------------------------- */
      case GMIL_EVE_RST:

      if(GMIL_bInhMilRst_C == FALSE)
      {
         u8LocalstMILReq_cpy = MIL_ON;
      }
      else
      {
         u8LocalstMILReq_cpy = MIL_OFF;
      }

      break;

/* -- Event Slow ------------------------------------------------------------ */
      case GMIL_EVE_SLOW:
      bLocalAcvMilReq = GDGAR_bGetFRM(FRM_FRM_ACVMILREQ);
      /* opt modification */
      if((bLocalAcvMilReq == FALSE) && (GMIL_bDftMilBlink == FALSE))
      {
         if((GMIL_bStrtMilOn == TRUE) || (GMIL_bDftMilOn == TRUE))
         {
            u8LocalstMILReq_cpy = MIL_ON;
         }
         else
         {
            u8LocalstMILReq_cpy = MIL_OFF;
         }
      }
      else
      {
         u8LocalstMILReq_cpy = MIL_BLINK;
      }

      break;

/* -- Others Events --------------------------------------------------------- */
      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   VEMS_vidSET(GMIL_stMILReq, u8LocalstMILReq_cpy);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_MilReqCanConf                                         */
/* !Description :  Ce bloc permet de créer 2 booléens GMIL_bMilOn et          */
/*                 GMIL_bMilBlink à partir de l'état d'automate GMIL_stMILReq */
/*                 qui seront envoyés sur le Can via la trame 348.            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st81 GMIL_stMILReq;                                                 */
/*  output boolean GMIL_bMilOn;                                               */
/*  output boolean GMIL_bMilBlink;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_MilReqCanConf(void)
{
   boolean bLocalMilBlink_cpy;
   boolean bLocalMilOn_cpy;
   uint8   u8LocalstMILReq_cpy;

   VEMS_vidGET(GMIL_stMILReq, u8LocalstMILReq_cpy);

   if(u8LocalstMILReq_cpy == MIL_ON)
   {
      bLocalMilOn_cpy = TRUE;
   }
   else
   {
      bLocalMilOn_cpy = FALSE;
   }

   if(u8LocalstMILReq_cpy == MIL_BLINK)
   {
      bLocalMilBlink_cpy = TRUE;
   }
   else
   {
      bLocalMilBlink_cpy = FALSE;
   }

   VEMS_vidSET(GMIL_bMilOn, bLocalMilOn_cpy);
   VEMS_vidSET(GMIL_bMilBlink, bLocalMilBlink_cpy);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_DftSt                                                 */
/* !Description :  Cette fonction permet, à partir des différentes requêtes   */
/*                 issues des fonctions précédentes de créer le booléen       */
/*                 GMIL_bMilDftPres. Il informe si l'allumage de la MIL est   */
/*                 lié ou non à une défaillance.                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean GMIL_bDftMilBlink;                                          */
/*  input boolean GMIL_bDftMilOn;                                             */
/*  output boolean GMIL_bMilDftPres;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_DftSt(void)
{
   boolean bLocalGMIL_bDftMilBlink;
   boolean bLocalGMIL_bDftMilOn;


   VEMS_vidGET(GMIL_bDftMilBlink, bLocalGMIL_bDftMilBlink);
   VEMS_vidGET(GMIL_bDftMilOn, bLocalGMIL_bDftMilOn);
   if (  (bLocalGMIL_bDftMilBlink == TRUE)
      || (bLocalGMIL_bDftMilOn == TRUE))
   {
      VEMS_vidSET(GMIL_bMilDftPres, TRUE);
   }
}

/*------------------------------- end of file --------------------------------*/