/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GOBD                                                    */
/* !Description     : GOBD Component                                          */
/*                                                                            */
/* !Module          : GOBD                                                    */
/* !Description     : Gestionnaire OBD                                        */
/*                                                                            */
/* !File            : GOBD_FCT4.C                                             */
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
/*   1 / GOBD_vidTransOK                                                      */
/*   2 / GOBD_vidTransPending1                                                */
/*   3 / GOBD_vidTransPending2                                                */
/*   4 / GOBD_vidTransEnregistre                                              */
/*   5 / GOBD_vidTransHistoOn                                                 */
/*   6 / GOBD_vidTransHistoOff                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5075502 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GOBD/GOBD_FCT4.c_v           $*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   11 Feb 2014 $*/
/* $Author::   mbenfrad                               $$Date::   11 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GOBD.h"
#include "GOBD_L.h"
#include "GOBD_im.h"
#include "GD_api.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTransOK                                            */
/* !Description :  Manage the transitions from the state GOBD_ETAT_OK.        */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidExitEveStObdRec(argin uint16 u16IdxDft);         */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTransOK
(
   uint16 u16IdxDft
)
{
   boolean bLocalNcfDc;

   bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BNCFDC);

   if((GOBD_u8ctDC[u16IdxDft] > 0)
    &&(bLocalNcfDc == FALSE))
   {
      GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_PENDING1;
   }
   else
   {
      if(bLocalNcfDc == TRUE)
      {
         GOBD_vidExitEveStObdRec(u16IdxDft);
         GOBD_enustDgo[u16IdxDft] =  GOBD_ETAT_ENREGISTRE;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTransPending1                                      */
/* !Description :  Manage the transition from the state GOBD_ETAT_PENDING1.   */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidExitEveStObdRec(argin uint16 u16IdxDft);         */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTransPending1
(
   uint16 u16IdxDft
)
{
   boolean bLocalNcfDc;

   bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BNCFDC);

   if(GOBD_u8ctDC[u16IdxDft] == 0)
   {
      GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_OK;
   }
   else
   {
      if(bLocalNcfDc == TRUE)
      {
         GOBD_vidExitEveStObdRec(u16IdxDft);
         GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_ENREGISTRE;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTransPending2                                      */
/* !Description :  Manage the transistions from the state GOBD_ETAT_PENDING2. */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTransPending2
(
   uint16 u16IdxDft
)
{
   boolean bLocalNcfDc;

   bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BNCFDC);

   if(GOBD_u8ctDC[u16IdxDft] == 0)
   {
      GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_HISTORIQUE_OFF;
   }
   else
   {
      if(bLocalNcfDc == TRUE)
      {
         GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_ENREGISTRE;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTransEnregistre                                    */
/* !Description :  Manage the transitions from the state GOBD_ETAT_ENREGISTRE.*/
/* !Number      :  FCT4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GD_au8IdxClasObd[9];                                          */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTransEnregistre
(
   uint16 u16IdxDft
)
{
   uint8              u8LocalIdxClasObd;  /* index for OBD class              */

   u8LocalIdxClasObd = GD_au8IdxClasObd[u16IdxDft];

   if(GOBD_u8ctDC[u16IdxDft] == 0)
   {
      GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_HISTORIQUE_OFF;
   }
   else
   {
      if(GOBD_u8ctDC[u16IdxDft] < GD_astrClasObd[u8LocalIdxClasObd].u8NoHealDC)
      {
         GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_HISTORIQUE_ON;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTransHistoOn                                       */
/* !Description :  Manage the transitions from the state                      */
/*                 GOBD_ETAT_HIDTORIQUE_ON.                                   */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GD_au8IdxClasObd[9];                                          */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTransHistoOn
(
   uint16 u16IdxDft
)
{
   uint8              u8LocalIdxClasObd;  /* index for OBD class              */

   u8LocalIdxClasObd = GD_au8IdxClasObd[u16IdxDft];

   if(GOBD_u8ctDC[u16IdxDft] == 0)
   {
      GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_HISTORIQUE_OFF;
   }
   else
   {
      if(GOBD_u8ctDC[u16IdxDft] == GD_astrClasObd[u8LocalIdxClasObd].u8NoHealDC)
      {
         GOBD_enustDgo[u16IdxDft] = GOBD_ETAT_ENREGISTRE;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTransHistoOff                                      */
/* !Description :  Manage the transitions from the state GOBD_HISTORIQUE_OFF. */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidExitEveStObdClear(argin uint16 u16IdxDft);       */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  input uint8 GOBD_u8ctWUC[9];                                              */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTransHistoOff
(
   uint16 u16IdxDft
)
{
   boolean bLocalNcfDc;

   bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BNCFDC);

   if(GOBD_u8ctDC[u16IdxDft] > 0)
   {
      if(bLocalNcfDc == TRUE)
      {
         GOBD_enustDgo[u16IdxDft] =  GOBD_ETAT_ENREGISTRE;
      }
      else
      {
         GOBD_enustDgo[u16IdxDft] =  GOBD_ETAT_PENDING2;
      }
   }
   else
   {
      if(GOBD_u8ctWUC[u16IdxDft] == 0)
      {
         GOBD_vidExitEveStObdClear(u16IdxDft);
         GOBD_enustDgo[u16IdxDft] =  GOBD_ETAT_OK;
      }
   }
}
/*------------------------------- end of file --------------------------------*/