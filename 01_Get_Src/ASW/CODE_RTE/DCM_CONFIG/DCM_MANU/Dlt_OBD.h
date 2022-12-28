/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : Dlt_OBD.h                                               */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dlt                                                     */
/* !Description     : Dlt                                                     */
/*                                                                            */
/* !Module          : Dlt                                                     */
/* !Description     : Dlt                                                     */
/*                                                                            */
/* !File            : Dlt_OBD.h                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                          */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.2      $$Author::   pbakabad        $$Date::   22 May 2014 $*/
/* PRQA S 0288 --                          */
/******************************************************************************/

#ifndef DLT_OBD_H_
#define DLT_OBD_H_

#include "STD_TYPES.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/*                 APIs utilisées pour le Mode 01                             */
/******************************************************************************/

extern Std_ReturnType DLT_OBDMode01_PID01(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID03(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID04(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID05(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID06(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID07(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID0B(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID0C(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID0D(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID0E(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID0F(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID11(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID13(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID14(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID15(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID1C(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID1F(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID21(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID23(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID2E(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID30(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID31(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID33(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID3C(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID42(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID44(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID47(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID49(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID4A(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID4C(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID4D(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID4E(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID4F(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID50(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID72_Data1(uint8* Data);
extern Std_ReturnType DLT_OBDMode01_PID72_Data2(uint8* Data);

/******************************************************************************/
/*                 APIs utilisées pour le Mode 09                             */
/******************************************************************************/

extern Std_ReturnType DLT_GetInfotypeValueData_04
(
   Dcm_OpStatusType OpStatus,
   uint8 *DataValueBuffer
);

extern Std_ReturnType DLT_GetInfotypeValueData_08
(
   Dcm_OpStatusType OpStatus,
   uint8 *DataValueBuffer
);

extern Std_ReturnType DLT_GetInfotypeValueData_Stub
(
   Dcm_OpStatusType OpStatus,
   uint8* DataValueBuffer
);

extern Std_ReturnType DLT_GetInfotypeValueData_02
(
   Dcm_OpStatusType OpStatus,
   uint8 *DataValueBuffer
);

#endif /* DLT_OBD_H_ */