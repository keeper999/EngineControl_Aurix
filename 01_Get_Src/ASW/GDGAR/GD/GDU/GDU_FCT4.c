/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDU                                                     */
/* !Description     : GDU Component.                                          */
/*                                                                            */
/* !Module          : GDU                                                     */
/* !Description     : SINGLE FAILURE MANAGER                                  */
/*                                                                            */
/* !File            : GDU_FCT4.c                                              */
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
/*   1 / GDU_vidTransAbs                                                      */
/*   2 / GDU_vidTransPctlPrst                                                 */
/*   3 / GDU_vidTransPctlAbs                                                  */
/*   4 / GDU_vidTransPrst                                                     */
/*   5 / GDU_vidTransDeval                                                    */
/*   6 / GDU_vidTransFugit                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_FCT4.c_v             $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDU.h"
#include "GDU_L.h"
#include "GDU_IM.h"
#include "GD_api.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidTransAbs                                            */
/* !Description :  Manage the transition in the state ABSENT.                 */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_CxtFrfRec(argin uint16 u16IdxDft);                   */
/*  extf argret void JDD_DftInPres(argin uint16 u16IdxDft);                   */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidTransAbs
(
   uint16 u16IdxDft
)
{
   if (  ((GDU_astrDftUnit[u16IdxDft].s16ctDet) > 0)
      && ((GDU_astrDftUnit[u16IdxDft].s16ctDet) < GDU_DFT_THD))
   {
      GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PCTL_PRESENT;
      JDD_CxtFrfRec(u16IdxDft);
   }
   else
   {
      if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == GDU_DFT_THD)
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PRESENT;
         JDD_CxtFrfRec(u16IdxDft);
         JDD_DftInPres(u16IdxDft);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidTransPctlPrst                                       */
/* !Description :  Manage the transition in the state PTCL PRESENT.           */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_DftInPres(argin uint16 u16IdxDft);                   */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidTransPctlPrst
(
   uint16 u16IdxDft
)
{
   boolean bLocalStPres;

   if (  ((GDU_astrDftUnit[u16IdxDft].s16ctDet) <= 0)
      && (GDU_astrDftUnit[u16IdxDft].s16ctDet > -(sint32)GDU_DFT_THD))
   {
      GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PCTL_ABSENT;
   }
   else
   {
      if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == -(sint32)(GDU_DFT_THD))
      {
         bLocalStPres =
            GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,BSTPRES);
         if (bLocalStPres == 0)
         {
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_ABSENT;
         }
         else
         {
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_FUGITIF;
         }
      }
      else
      {
         if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == GDU_DFT_THD)
         {
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PRESENT;
            JDD_DftInPres(u16IdxDft);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidTransPctlAbs                                        */
/* !Description :  Manage the transition in the state PTCL ABSENT.            */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_DftInPres(argin uint16 u16IdxDft);                   */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidTransPctlAbs
(
   uint16 u16IdxDft
)
{
   boolean bLocalStPres;

   if (  ((GDU_astrDftUnit[u16IdxDft].s16ctDet) > 0)
      && (GDU_astrDftUnit[u16IdxDft].s16ctDet < GDU_DFT_THD))
   {
      GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PCTL_PRESENT;
   }
   else
   {
      if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == -(sint32)GDU_DFT_THD)
      {
         bLocalStPres =
            GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,BSTPRES);
         if (bLocalStPres == 0)
         {
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_ABSENT;
         }
         else
         {
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_FUGITIF;
         }
      }
      else
      {
         if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == GDU_DFT_THD)
         {
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PRESENT;
            JDD_DftInPres(u16IdxDft);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidTransPrst                                           */
/* !Description :  Manage the transition in the state PRESENT.                */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_DftExitUnval(argin uint16 u16IdxDft);                */
/*  input uint8 GD_au8IdxClassDet[8];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidTransPrst
(
   uint16 u16IdxDft
)
{
   boolean bLocalStPres;
   boolean bLocalLockDft;
   uint8   u8LocalIdxClassDet;

   u8LocalIdxClassDet = GD_au8IdxClassDet[u16IdxDft];
   bLocalLockDft = GD_astrClasDet[u8LocalIdxClassDet].bLockDftClasDet;
   if (  ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == -(sint32)GDU_DFT_THD)
      && (bLocalLockDft == 0))
   {
      bLocalStPres =
         GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,BSTPRES);
      if (bLocalStPres == 0)
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_ABSENT;
      }
      else
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_FUGITIF;
      }

      JDD_DftExitUnval(u16IdxDft);
   }
   else
   {
      if (  (GDU_astrDftUnit[u16IdxDft].s16ctDet < GDU_DFT_THD)
         && (GDU_astrDftUnit[u16IdxDft].s16ctDet > -(sint32)GDU_DFT_THD))
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_DEVALIDATION;
      }
      else
      {
         /* No state change */
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidTransDeval                                          */
/* !Description :  Manage the transition in the state DEVALIDATION.           */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_DftExitUnval(argin uint16 u16IdxDft);                */
/*  input uint8 GD_au8IdxClassDet[8];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidTransDeval
(
   uint16 u16IdxDft
)
{
   boolean bLocalStPres;
   boolean bLocalLockDft;
   uint8   u8LocalIdxClassDet;

   u8LocalIdxClassDet = GD_au8IdxClassDet[u16IdxDft];
   bLocalLockDft = GD_astrClasDet[u8LocalIdxClassDet].bLockDftClasDet;
   if (  ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == -(sint32)GDU_DFT_THD)
      && (bLocalLockDft == 0))
   {
      bLocalStPres =
         GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement, BSTPRES);
      if (bLocalStPres == 0)
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_ABSENT;
      }
      else
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_FUGITIF;
      }

      JDD_DftExitUnval(u16IdxDft);
   }
   else
   {
      if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == GDU_DFT_THD)
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PRESENT;
      }
      else
      {
         /* No state change */
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidTransFugit                                          */
/* !Description :  Manage the transition in the state FUGITIF.                */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void JDD_CxtFrfRec(argin uint16 u16IdxDft);                   */
/*  extf argret void JDD_DftInPres(argin uint16 u16IdxDft);                   */
/*  extf argret void GDU_vidExitEveDftClr(argin uint16 u16IdxDft);            */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*  input uint8 GOBD_u8ctWUC[8];                                              */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidTransFugit
(
   uint16 u16IdxDft
)
{
   if (  ((GDU_astrDftUnit[u16IdxDft].s16ctDet) > 0)
      && ((GDU_astrDftUnit[u16IdxDft].s16ctDet) < GDU_DFT_THD))
   {
      GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PCTL_PRESENT;
      JDD_CxtFrfRec(u16IdxDft);
   }
   else
   {
      if ((GDU_astrDftUnit[u16IdxDft].s16ctDet) == GDU_DFT_THD)
      {
         GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PRESENT;
         JDD_CxtFrfRec(u16IdxDft);
         JDD_DftInPres(u16IdxDft);
      }
      else
      {
         if (GOBD_u8ctWUC[u16IdxDft] == 0)
         {
            GDU_vidExitEveDftClr(u16IdxDft);
            GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_ABSENT;
         }
      }
   }
}
/*------------------------------- end of file --------------------------------*/