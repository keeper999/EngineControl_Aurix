/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRFRZ                                                 */
/* !Description     : IUPRFRZ component.                                      */
/*                                                                            */
/* !Module          : IUPRFRZ                                                 */
/* !Description     : IUPR DEACTIVATION                                       */
/*                                                                            */
/* !File            : IUPRFRZ_FCT1.C                                          */
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
/*   1 / IUPRFRZ_vidDeactivation                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 03256 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRFRZ/IUPRFRZ_FCT1.c_v     $*/
/* $Revision::   1.4      $$Author::   alaouni        $$Date::   22 Dec 2011 $*/
/* $Author::   alaouni                                $$Date::   22 Dec 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IUPRFRZ.h"
#include "IUPRFRZ_L.h"
#include "IUPRFRZ_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRFRZ_vidDeactivation                                    */
/* !Description :  La gestion des ratios de désactivation de l'IUPR.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.Jlizi                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint16 Iupr_idxFrzGenDen_T[30];                                     */
/*  input GDFRM_tenuGOBDState GOBD_enustDgo[509];                             */
/*  input uint16 Iupr_idxFrzCntObdStrt_T[30];                                 */
/*  input uint16 Iupr_idxFrzRat_T[100][30];                                   */
/*  output boolean Iupr_bFrzGenDen;                                           */
/*  output boolean Iupr_bFrzCntObdStrt;                                       */
/*  output boolean Iupr_bFrzRat[100];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRFRZ_vidDeactivation(void)
{
   GDFRM_tenuGOBDState stLocalGOBDState1;
   GDFRM_tenuGOBDState stLocalGOBDState2;
   GDFRM_tenuGOBDState stLocalGOBDState3;
   sint32              s32LocalIdx1;
   sint32              s32LocalIdx2;
   sint32              s32LocalIdx3;
   uint16              u16LocalGD_DFT_NB;
   uint16              u16LocalInd_genden;
   uint16              u16LocalInd_strt;
   uint16              u16LocalInd_ratid;


   VEMS_vidSET(Iupr_bFrzGenDen, 0);
   VEMS_vidSET(Iupr_bFrzCntObdStrt, 0);

   for (s32LocalIdx1 = 0; s32LocalIdx1 < IUPR_NB_RAT; s32LocalIdx1++)
   {
      VEMS_vidSET1DArrayElement(Iupr_bFrzRat, s32LocalIdx1, 0);
   }

   u16LocalGD_DFT_NB = (uint16)(GD_DFT_NB - 1);
   for (s32LocalIdx2 = 0; s32LocalIdx2 < IUPR_FRZ_NB_DFT; s32LocalIdx2++)
   {
      u16LocalInd_genden = Iupr_idxFrzGenDen_T[s32LocalIdx2];
      u16LocalInd_genden = (uint16)MATHSRV_udtMIN(u16LocalInd_genden,
                                                  u16LocalGD_DFT_NB);
      VEMS_vidGET1DArrayElement(GOBD_enustDgo,
                                u16LocalInd_genden,
                                stLocalGOBDState1);
      if (  (stLocalGOBDState1 == GOBD_ETAT_PENDING1)
         || (stLocalGOBDState1 == GOBD_ETAT_ENREGISTRE))
      {
         VEMS_vidSET(Iupr_bFrzGenDen, 1);
      }

      u16LocalInd_strt = Iupr_idxFrzCntObdStrt_T[s32LocalIdx2];
      u16LocalInd_strt = (uint16)MATHSRV_udtMIN(u16LocalInd_strt,
                                                u16LocalGD_DFT_NB);
      VEMS_vidGET1DArrayElement(GOBD_enustDgo,
                                u16LocalInd_strt,
                                stLocalGOBDState2);
      if (  (stLocalGOBDState2 == GOBD_ETAT_PENDING1)
         || (stLocalGOBDState2 == GOBD_ETAT_ENREGISTRE))
      {
         VEMS_vidSET(Iupr_bFrzCntObdStrt, 1);
      }

      for (s32LocalIdx3 = 0; s32LocalIdx3 < IUPR_NB_RAT; s32LocalIdx3++)
      {
         u16LocalInd_ratid = Iupr_idxFrzRat_T[s32LocalIdx3]
                               [s32LocalIdx2];
         u16LocalInd_ratid = (uint16)MATHSRV_udtMIN(u16LocalInd_ratid,
                                                    u16LocalGD_DFT_NB);
         VEMS_vidGET1DArrayElement(GOBD_enustDgo,
                                   u16LocalInd_ratid,
                                   stLocalGOBDState3);
         if (  (stLocalGOBDState3 == GOBD_ETAT_PENDING1)
            || (stLocalGOBDState3 == GOBD_ETAT_ENREGISTRE))
         {
            VEMS_vidSET1DArrayElement(Iupr_bFrzRat, s32LocalIdx3, 1);
         }
      }
   }
}
/*------------------------------end-of-file-----------------------------------*/