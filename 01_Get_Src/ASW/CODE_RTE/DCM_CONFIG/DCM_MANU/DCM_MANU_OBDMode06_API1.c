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
/* !File            : DCM_MANU_OBDMode06_API1.c                               */
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
/*   1 / DCM_MANU_GetDTRValue_OBDMID01_TID01                                  */
/*   2 / DCM_MANU_GetDTRValue_OBDMID01_TID02                                  */
/*   3 / DCM_MANU_GetDTRValue_OBDMID01_TID03                                  */
/*   4 / DCM_MANU_GetDTRValue_OBDMID01_TID04                                  */
/*   5 / DCM_MANU_GetDTRValue_OBDMID01_TID07                                  */
/*   6 / DCM_MANU_GetDTRValue_OBDMID01_TID08                                  */
/*   7 / DCM_MANU_GetDTRValue_OBDMID01_TID0A                                  */
/*   8 / DCM_MANU_GetDTRValue_OBDMID01_TIDA0                                  */
/*   9 / DCM_MANU_GetDTRValue_OBDMID01_TIDA1                                  */
/*   10 / DCM_MANU_GetDTRValue_OBDMID02_TID01                                 */
/*   11 / DCM_MANU_GetDTRValue_OBDMID02_TID02                                 */
/*   12 / DCM_MANU_GetDTRValue_OBDMID02_TID03                                 */
/*   13 / DCM_MANU_GetDTRValue_OBDMID02_TID04                                 */
/*   14 / DCM_MANU_GetDTRValue_OBDMID02_TID07                                 */
/*   15 / DCM_MANU_GetDTRValue_OBDMID02_TID08                                 */
/*   16 / DCM_MANU_GetDTRValue_OBDMID02_TIDC0                                 */
/*   17 / DCM_MANU_GetDTRValue_OBDMID02_TIDC1                                 */
/*   18 / DCM_MANU_GetDTRValue_OBDMID02_TIDC2                                 */
/*   19 / DCM_MANU_GetDTRValue_OBDMID21_TID81                                 */
/*   20 / DCM_MANU_GetDTRValue_OBDMID42_TIDDA                                 */
/*   21 / DCM_MANU_GetDTRValue_OBDMIDA2_TID0B                                 */
/*   22 / DCM_MANU_GetDTRValue_OBDMIDA2_TID0C                                 */
/*   23 / DCM_MANU_GetDTRValue_OBDMIDA3_TID0B                                 */
/*   24 / DCM_MANU_GetDTRValue_OBDMIDA3_TID0C                                 */
/*   25 / DCM_MANU_GetDTRValue_OBDMIDA4_TID0B                                 */
/*   26 / DCM_MANU_GetDTRValue_OBDMIDA4_TID0C                                 */
/*   27 / DCM_MANU_GetDTRValue_OBDMIDA5_TID0B                                 */
/*   28 / DCM_MANU_GetDTRValue_OBDMIDA5_TID0C                                 */
/*   29 / DCM_MANU_GetDTRValue_OBDMID41_TIDD0                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID01                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.1                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID01(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID01
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID01( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID02                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID02(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID02
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID02( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID03                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.3                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID03(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID03
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID03( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID04                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.4                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID04(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID04
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID04( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID07                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.5                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID07(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID07
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID07( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID08                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.6                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID08(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID08
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID08( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TID0A                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.7                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TID0A(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID0A
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TID0A( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TIDA0                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.8                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TIDA0(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TIDA0
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TIDA0( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID01_TIDA1                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.9                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID01_TIDA1(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TIDA1
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID01_TIDA1( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TID01                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.10                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TID01(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID01
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TID01( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TID02                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.11                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TID02(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID02
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TID02( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TID03                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.12                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TID03(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID03
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TID03( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TID04                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.13                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TID04(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID04
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TID04( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TID07                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.14                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TID07(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID07
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TID07( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TID08                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.15                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TID08(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID08
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TID08( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TIDC0                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.16                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TIDC0(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TIDC0
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TIDC0( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TIDC1                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.17                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TIDC1(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TIDC1
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TIDC1( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID02_TIDC2                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.18                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID02_TIDC2(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TIDC2
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID02_TIDC2( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID21_TID81                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.19                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID21_TID81(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID21_TID81
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID21_TID81( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID42_TIDDA                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.20                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID42_TIDDA(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID42_TIDDA
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID42_TIDDA( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA2_TID0B                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.21                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA2_TID0B(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA2_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA2_TID0B( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA2_TID0C                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.22                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA2_TID0C(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA2_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA2_TID0C( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA3_TID0B                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.23                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA3_TID0B(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA3_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA3_TID0B( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA3_TID0C                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.24                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA3_TID0C(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA3_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA3_TID0C( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA4_TID0B                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.25                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA4_TID0B(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA4_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA4_TID0B( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA4_TID0C                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.26                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA4_TID0C(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA4_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA4_TID0C( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA5_TID0B                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.27                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA5_TID0B(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :                                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA5_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA5_TID0B( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMIDA5_TID0C                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.28                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMIDA5_TID0C(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA5_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMIDA5_TID0C( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_GetDTRValue_OBDMID41_TIDD0                        */
/* !Description :  Is called from Dcm when OBD MIDXX TIDYY is received.       */
/* !Number      :  OBDMode06_API1.29                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  GetDTRValue_OBDMID41_TIDD0(argin              */
/*  Dcm_OpStatusType OpStatus, argout uint16 *Testval, argout uint16          */
/*  *Minlimit, argout uint16 *Maxlimit, argout Dcm_DTRStatusType *Status);    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID41_TIDD0
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = GetDTRValue_OBDMID41_TIDD0( OpStatus,
                                               Testval,
                                               Minlimit,
                                               Maxlimit,
                                               Status );
   return u8LocalReturn;
}