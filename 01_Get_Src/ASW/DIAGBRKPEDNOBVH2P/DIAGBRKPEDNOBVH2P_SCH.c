/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGBRKPEDNOBVH2P                                       */
/* !Description     : DIAGBRKPEDNOBVH2P component                             */
/*                                                                            */
/* !Module          : DIAGBRKPEDNOBVH2P                                       */
/* !Description     : DIAGNOSTIC DE LA PEDALE DE FREIN HORS BVH2PRIME         */
/*                                                                            */
/* !File            : DIAGBRKPEDNOBVH2P_SCH.C                                 */
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
/*   1 / Brk_EveRst_DiagBrkPedNoBVH2p                                         */
/*   2 / Brk_SdlMid_DiagBrkPedNoBVH2p                                         */
/*   3 / Brk_SdlSfty_BrkPed                                                   */
/*                                                                            */
/* !Reference   : V02 NT 10 02593 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#056351                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHIBRK/DIAGBRKPEDNOBVH2P/DIAGB$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   03 Jan 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   03 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "DIAGBRKPEDNOBVH2P.h"
#include "DIAGBRKPEDNOBVH2P_l.h"
#include "DIAGBRKPEDNOBVH2P_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_EveRst_DiagBrkPedNoBVH2p                               */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGBRKPEDNOBVH2P_vidInitOutput();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_EveRst_DiagBrkPedNoBVH2p                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_EveRst_DiagBrkPedNoBVH2p(void)
{
   DIAGBRKPEDNOBVH2P_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlMid_DiagBrkPedNoBVH2p                               */
/* !Description :  Moniteur du diagnostic acquisition frein                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGBRKPEDNOBVH2P_vidFnctionCall();                      */
/*  input uint8 DIAGBRKPEDNOBVH2P_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_SdlMid_DiagBrkPedNoBVH2p                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlMid_DiagBrkPedNoBVH2p(void)
{
   if (DIAGBRKPEDNOBVH2P_u8Inhib != 0x5A)
   {
      DIAGBRKPEDNOBVH2P_vidFnctionCall();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlSfty_BrkPed                                         */
/* !Description :  Evenement de lancement de diagnostic de défaut niveau 2.   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGBRKPEDNOBVH2P_vidSftyNiv2();                         */
/*  input uint8 DIAGBRKPEDNOBVH2P_u8Inhib;                                    */
/*  input boolean Ext_bAcv_BrkSftyLvl2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_SdlSfty_BrkPed                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlSfty_BrkPed(void)
{
   boolean bLocalExt_bAcv_BrkSftyLvl2;


   if (DIAGBRKPEDNOBVH2P_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bAcv_BrkSftyLvl2, bLocalExt_bAcv_BrkSftyLvl2);
      if (bLocalExt_bAcv_BrkSftyLvl2 != 0)
      {
         DIAGBRKPEDNOBVH2P_vidSftyNiv2();
      }
   }
}
/*------------------------------- end of file --------------------------------*/