/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILMNG                                               */
/* !Description     : IGCOILMNG component.                                    */
/*                                                                            */
/* !Module          : IGCOILMNG                                               */
/* !Description     : COMMANDE ET DIAGNOSTIC DES BOBINES D’ALLUMAGE           */
/*                                                                            */
/* !File            : IGCOILMNG_FCT3.C                                        */
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
/*   1 / IGCOILMNG_vidCallDiagICD                                             */
/*   2 / IGCOILMNG_vidCallDiagSdlFast                                         */
/*   3 / IGCOILMNG_vidDisable                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6668934 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGCOILMNG/IGCOILMNG_FCT3.C_v      $*/
/* $Revision::   1.10     $$Author::   achebino       $$Date::   02 Jul 2014 $*/
/* $Author::   achebino                               $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "IGCOILMNG.h"
#include "IGCOILMNG_L.h"
#include "IGCOILMNG_IM.h"
#include "IGNHAL.h"
#include "IGCOILMNG_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidCallDiagICD                                   */
/* !Description :  Il est inutile de prendre en compte la condition sur       */
/*                 Code_test_action ni celle Srv_stActrTstStatus puisque les  */
/*                 tests actionneurs n’ont lieu que lorsque le moteur est     */
/*                 arrêté (pas de PMB).                                       */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidDiagnostic();                               */
/*  input boolean IgCmd_bCallDiagTyp_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidCallDiagICD(void)
{
   if (IgCmd_bCallDiagTyp_C == 0)
   {
      IGCOILMNG_vidDiagnostic();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidCallDiagSdlFast                               */
/* !Description :  call the diagnosis function depending on                   */
/*                 IgCmd_bCallDiagTyp_C, Srv_stActrTstStatus and              */
/*                 Code_test_action.                                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILMNG_vidDiagnostic();                               */
/*  input st92 Srv_stActrTstStatus;                                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean IgCmd_bCallDiagTyp_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidCallDiagSdlFast(void)
{
   uint8 u8LocalSrv_stActrTstStatus;
   uint8 u8LocalCode_test_action;

   VEMS_vidGET(Srv_stActrTstStatus, u8LocalSrv_stActrTstStatus);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if ( (IgCmd_bCallDiagTyp_C != 0)
      ||(  (u8LocalSrv_stActrTstStatus == ACTION_EN_COURS)
         &&(  (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
            ||(u8LocalCode_test_action == CODE_TEST_BOBINE_2)
            ||(u8LocalCode_test_action == CODE_TEST_BOBINE_3)
            ||(u8LocalCode_test_action == CODE_TEST_BOBINE_4)))
      )
   {
      IGCOILMNG_vidDiagnostic();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDisable                                       */
/* !Description :  Le driver est désactivé sur perte de synchronisation et sur*/
/*                 Key Off.                                                   */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgnHALDisable();                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDisable(void)
{
   IgnHALDisable();
}
/*QAC Warning(2:4700): complexity accepted                                    */
/*---------------------------------end of file--------------------------------*/