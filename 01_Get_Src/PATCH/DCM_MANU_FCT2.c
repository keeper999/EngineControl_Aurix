/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DCM_MANU_FCT2.C                                         */
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
/*   1 / DCM_MANU_CheckChangeSessionSWCcondition                              */
/*   2 / DCM_MANU_CALL_RcAcv_RstAFAMgtT                                       */
/*   3 / DCM_MANU_CALL_CheckRcCdn_RstAFAMgtT                                  */
/*   4 / DCM_MANU_CALL_RcAcv_RstCylHdDmgCnt                                   */
/*   5 / DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCnt                              */
/*   6 / DCM_MANU_CALL_RcAcv_RstMnfDmgCnt                                     */
/*   7 / DCM_MANU_CALL_CheckRcCdn_RstMnfDmgCnt                                */
/*   8 / DCM_MANU_CALL_RcAcv_RstTrbDmgCnt                                     */
/*   9 / DCM_MANU_CALL_CheckRcCdn_RstTrbDmgCnt                                */
/*   10 / DCM_MANU_CALL_RcAcv_RstCylHdDmgCplmCnt                              */
/*   11 / DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCplmCnt                         */
/*   12 / DCM_MANU_CALL_RcAcv_RstTrbActSys                                    */
/*   13 / DCM_MANU_CALL_CheckRcCdn_RstTrbActSys                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/DCM_MANU_FCT2.c_v           $*/
/* $Revision::   1.2      $$Author::   croche2        $$Date::   02 Jul 2014 $*/
/* $Author::   croche2                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"
#include "DCM_MANU_Fix.h"
//#include "Rte_DCM_MANU.h"
#include "Rte_VirtualComponent.h"

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckChangeSessionSWCcondition                    */
/* !Description :  Fonction testant les conditions de changement de session   */
/*                 relatives aux SWC PSA                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  Rte_Call_R_MPM_SessionControl_OP_GetSesChgPermission(argin Dcm_SesCtrlType*/
/*  SesCtrlTypeActive, argin Dcm_SesCtrlType SesCtrlTypeNew);                 */
/*  extf argret Std_ReturnType                                                */
/* Rte_Call_R_AFAMgtT_SessionControl_OP_GetSesChgPermission(argin             */
/* Dcm_SesCtrlType SesCtrlTypeActive, argin Dcm_SesCtrlType SesCtrlTypeNew);  */
/*  extf argret Std_ReturnType                                                */
/* Rte_Call_R_TrbActSys_SessionControl_OP_GetSesChgPermission(argin           */
/* Dcm_SesCtrlType SesCtrlTypeActive, argin Dcm_SesCtrlType SesCtrlTypeNew);  */
/*  extf argret Std_ReturnType                                                */
/* Rte_Call_R_MPM_SessionControl_OP_ChangeIndication(argin Dcm_SesCtrlType    */
/* SesCtrlTypeOld, argin Dcm_SesCtrlType SesCtrlTypeNew);                     */
/*  extf argret Std_ReturnType                                                */
/* Rte_Call_R_AFAMgtT_SessionControl_OP_ChangeIndication(argin Dcm_SesCtrlType*/
/* SesCtrlTypeOld, argin Dcm_SesCtrlType SesCtrlTypeNew);                     */
/*  extf argret Std_ReturnType                                                */
/* Rte_Call_R_TrbActSys_SessionControl_OP_ChangeIndication(argin              */
/* Dcm_SesCtrlType SesCtrlTypeOld, argin Dcm_SesCtrlType SesCtrlTypeNew);     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CheckChangeSessionSWCcondition
(
   uint8 SesCtrlType,
   uint8 RequestedMode,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType                u8localreturn;
   Dcm_NegativeResponseCodeType  u8LocalError;
   Std_ReturnType                status1;
   Std_ReturnType                status2;
   //Std_ReturnType                status3;


   // status1 = Rte_Call_R_MPM_SessionControl_GetSesChgPermission(
                     // SesCtrlType, RequestedMode);

    // status2 = Rte_Call_R_AFAMgtT_SessionControl_GetSesChgPermission(
                     // SesCtrlType, RequestedMode);

    //status3 = Rte_Call_R_TrbActSys_SessionControl_GetSesChgPermission(
                                 //SesCtrlType, RequestedMode);

    if((status1 == E_OK) && (status2 == E_OK))
    {
      // status1 = Rte_Call_R_MPM_SessionControl_ChangeIndication(
                     // SesCtrlType, RequestedMode);

        // status2 = Rte_Call_R_AFAMgtT_SessionControl_ChangeIndication(
                     // SesCtrlType, RequestedMode);

        //status3 = Rte_Call_R_TrbActSys_SessionControl_ChangeIndication(
                                   // SesCtrlType, RequestedMode);

        u8localreturn = E_OK;
        u8LocalError = 0x00;
    }
    else if((status1 == E_PENDING) || (status2 == E_PENDING))
    {
        u8localreturn = E_PENDING;
        u8LocalError = 0x00;
    }
    else
    {
        u8localreturn = E_NOT_OK;
        u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
    }

   *ErrorCode = u8LocalError;
   return u8localreturn;
}
/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_RcAcv_RstAFAMgtT                             */
/* !Description :  Fonction exécutant le fonctionnel de la routine reset      */
/*                 AFAMgtT data service THR/INJ/VVT                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_RcAcv_RstAFAMgtT
(
   uint8* InBuffer,
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status = Rte_Call_R_RoutineServices_AFMgtT_NVMID03_Start(
                        // (UInt8 *)InBuffer,(UInt8 *)OutBuffer, ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_CheckRcCdn_RstAFAMgtT                        */
/* !Description :  Fonction testant les conditions de terminaison de la       */
/*                 routine reset AFAMgtT data service THR/INJ/VVT             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstAFAMgtT
(
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status =
      // Rte_Call_R_RoutineServices_AFMgtT_NVMID03_RequestResults(
                                                // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_RcAcv_RstCylHdDmgCnt                         */
/* !Description :  Fonction exécutant le fonctionnel de la routine reset the  */
/*                 damage counter of the cylinder head                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_RcAcv_RstCylHdDmgCnt
(
   uint8* InBuffer,
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status = Rte_Call_R_RoutineServices_MPM_NVMID03_Start((UInt8 *)InBuffer,
               // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCnt                    */
/* !Description :  Fonction testant les conditions de terminaison de la       */
/*                 routine reset the damage counter of the cylinder head      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCnt
(
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

// status = Rte_Call_R_RoutineServices_MPM_NVMID03_RequestResults(
                                                // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_RcAcv_RstMnfDmgCnt                           */
/* !Description :  Fonction exécutant le fonctionnel de la routine reset the  */
/*                 damage counter of the exhaust manifold                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_RcAcv_RstMnfDmgCnt
(
   uint8* InBuffer,
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status = Rte_Call_R_RoutineServices_MPM_NVMID08_Start((UInt8 *)InBuffer,
               // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_CheckRcCdn_RstMnfDmgCnt                      */
/* !Description :  Fonction testant les conditions de terminaison de la       */
/*                 routine reset the damage counter of the exhaust manifold   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstMnfDmgCnt
(
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType status;

   // status =
      // Rte_Call_R_RoutineServices_MPM_NVMID08_RequestResults(
                                                // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_RcAcv_RstTrbDmgCnt                           */
/* !Description :  Fonction exécutant le fonctionnel de la routine reset the  */
/*                 damage counter of the turbo housing                        */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_RcAcv_RstTrbDmgCnt
(
   uint8* InBuffer,
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status = Rte_Call_R_RoutineServices_MPM_NVMID07_Start((UInt8 *)InBuffer,
               // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_CheckRcCdn_RstTrbDmgCnt                      */
/* !Description :  Fonction testant les conditions de terminaison de la       */
/*                 routine reset the damage counter of the turbo housing      */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstTrbDmgCnt
(
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status =
      // Rte_Call_R_RoutineServices_MPM_NVMID07_RequestResults(
                                                // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_RcAcv_RstCylHdDmgCplmCnt                     */
/* !Description :  Fonction exécutant le fonctionnel de la routine reset the  */
/*                 damage counter of the cylinder head complementary          */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_RcAcv_RstCylHdDmgCplmCnt
(
   uint8* InBuffer,
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

// status = Rte_Call_R_RoutineServices_MPM_NVMID04_Start((UInt8 *)InBuffer,
               // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCplmCnt                */
/* !Description :  Fonction testant les conditions de terminaison de la rouine*/
/*                 reset the damage counter of the cylinder head complementary*/
/* !Number      :  FCT2.11                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCplmCnt
(
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   // status =
      // Rte_Call_R_RoutineServices_MPM_NVMID04_RequestResults(
                                                // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_RcAcv_RstTrbActSys                           */
/* !Description :  Fonction exécutant le fonctionnel de la routine reset      */
/*                 TrbActSys data service Waste Gate                          */
/* !Number      :  FCT2.12                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_RcAcv_RstTrbActSys
(
   uint8* InBuffer,
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   //status =
     // Rte_Call_R_RoutineServices_TAS_NVMID03_Start((UInt8 *)InBuffer,
             //  (UInt8 *)OutBuffer,ErrorCode);

   return status;
}

/******************************************************************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CALL_CheckRcCdn_RstTrbActSys                      */
/* !Description :  Fonction testant les conditions de terminaison de la       */
/*                 routine reset TrbActSys data service Waste Gate            */
/* !Number      :  FCT2.13                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstTrbActSys
(
   uint8* OutBuffer,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType status;

   //status =
     // Rte_Call_R_RoutineServices_TAS_NVMID03_RequestResults(
                                               // (UInt8 *)OutBuffer,ErrorCode);

   return status;
}