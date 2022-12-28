/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RLYPWR                                                  */
/* !Description     : RLYPWR Component                                        */
/*                                                                            */
/* !Module          : RLYPWR                                                  */
/* !Description     : Gestionnaire du relais actionneurs                      */
/*                                                                            */
/* !File            : RLYPWR_FCT3.C                                           */
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
/*   1 / RLYPWR_vidRlyPwrDiagInh                                              */
/*   2 / RLYPWR_vidRlyPwrDiagNotInh                                           */
/*   3 / RLYPWR_vidRlyPwrMngDiagNotInh                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5137464 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "RLYPWR.h"
#include "RLYPWR_L.h"
#include "RLYPWR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrDiagInh                                    */
/* !Description :  Afin d’éviter une remontée de défauts circuit ouvert à     */
/*                 l'ouverture du relais actionneurs, le booléen              */
/*                 EcuSt_bInhDiagOcCmdActr désactive ces diag lorsqu’on ouvre */
/*                 le relais.                                                 */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 RlyPwr_ctInhDiagOcCmdActr_C;                                  */
/*  output uint8 RlyPwr_ctInhDiagOcCmdActr;                                   */
/*  output boolean EcuSt_bInhDiagOcCmdActr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrDiagInh(void)
{
   RlyPwr_ctInhDiagOcCmdActr =
      (uint8)MATHSRV_udtMIN(RlyPwr_ctInhDiagOcCmdActr_C, 100);
   VEMS_vidSET(EcuSt_bInhDiagOcCmdActr, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrDiagNotInh                                 */
/* !Description :  Afin d’éviter une remontée de défauts circuit ouvert à la  */
/*                 fermeture du relais actionneurs, le booléen                */
/*                 EcuSt_bInhDiagOcCmdActr maintien la désactivation pendant  */
/*                 une temporisation calibrable après sa fermeture.           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 RlyPwr_ctInhDiagOcCmdActr;                                    */
/*  output uint8 RlyPwr_ctInhDiagOcCmdActr;                                   */
/*  output boolean EcuSt_bInhDiagOcCmdActr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrDiagNotInh(void)
{
   sint16  s16LocalRlyPwr_ctInhDiag;


   s16LocalRlyPwr_ctInhDiag = (sint16)(RlyPwr_ctInhDiagOcCmdActr - 1);
   RlyPwr_ctInhDiagOcCmdActr =
      (uint8)MATHSRV_udtCLAMP(s16LocalRlyPwr_ctInhDiag, 0, 100);
   if (RlyPwr_ctInhDiagOcCmdActr != 0)
   {
      VEMS_vidSET(EcuSt_bInhDiagOcCmdActr, 1);
   }
   else
   {
      VEMS_vidSET(EcuSt_bInhDiagOcCmdActr, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrMngDiagNotInh                              */
/* !Description :  Permet d’éviter une remontée de défauts circuit ouvert à la*/
/*                 fermeture et ouverture du relais actionneurs               */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void RLYPWR_vidRlyPwrDiagNotInh();                            */
/*  extf argret void RLYPWR_vidRlyPwrDiagInh();                               */
/*  input boolean Actionneurs;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrMngDiagNotInh(void)
{
   boolean  bLocalActionneurs;


   VEMS_vidGET(Actionneurs, bLocalActionneurs);
   if (bLocalActionneurs != 0)
   {
      RLYPWR_vidRlyPwrDiagNotInh();
   }
   else
   {
      RLYPWR_vidRlyPwrDiagInh();
   }
}
/*------------------------------- end of file --------------------------------*/