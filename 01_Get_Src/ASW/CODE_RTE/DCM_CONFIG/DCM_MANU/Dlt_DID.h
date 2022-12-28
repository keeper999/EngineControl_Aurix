/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : Dlt_DID.h                                               */
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
/* !File            : Dlt_DID.h                                               */
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
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.2      $$Author::   pbakabad        $$Date::   22 May 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef DLT_DID_H_
#define DLT_DID_H_

#include "STD_TYPES.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION CODE MANUEL                                          */
/******************************************************************************/

extern Std_ReturnType DLT_ReadDataLength_2101( uint16* DataLength );

extern Std_ReturnType DLT_ConditionCheckRead_2101
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_2101( Dcm_OpStatusType OpStatus,
                                         uint8* Data );

extern Std_ReturnType DLT_ReadDataLength_2100( uint16* DataLength );

extern Std_ReturnType DLT_ConditionCheckRead_2100
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_2100( Dcm_OpStatusType OpStatus,
                                         uint8* Data );

extern Std_ReturnType DLT_ReadDataLength_F080
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_F080
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_F080( Dcm_OpStatusType OpStatus,
                                         uint8* Data );

extern Std_ReturnType DLT_ReadDataLength_F0FE
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_F0FE
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_F0FE( Dcm_OpStatusType OpStatus,
                                         uint8* Data );

extern Std_ReturnType DLT_WriteData_2101
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_F18B
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_F18B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_F18B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_C001
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_C001
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ReadDataLength_D500
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_D500
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D500
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_D500
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_F196
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_F196
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_F196
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_F196
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_D49C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D49C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D71F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D71F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D604
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D604
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D605
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D605
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D606
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D606
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

/******************************************************************************/
/* FUNCTIONS DECLARATION CODE AUTO                                            */
/******************************************************************************/
extern Std_ReturnType DLT_ConditionCheckRead_D621
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D621
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4C5
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4C5
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D623
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D623
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4C3
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4C3
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D625
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D625
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D624
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D624
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D421
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D421
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D41B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D41B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D41A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D41A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D41D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D41D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D41C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D41C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4CB
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4CB
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D41E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D41E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4CA
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4CA
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4CC
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4CC
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D61A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D61A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4CD
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4CD
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D61B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D61B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D61C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D61C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_F196
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_F196
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D61D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D61D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D61F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D61F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D422
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D422
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D423
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D423
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D424
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D424
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D425
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D425
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D426
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D426
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4D2
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4D2
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4D3
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4D3
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D428
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D428
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D429
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D429
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D612
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D612
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4D5
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4D5
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D611
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D611
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D49D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D49D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D49E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D49E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4D9
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4D9
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D615
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D615
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D49F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D49F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4D8
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4D8
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D614
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D614
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D613
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D613
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D40C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D40C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D499
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D499
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D619
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D619
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D618
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D618
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D40A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D40A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4DA
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4DA
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D40E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D40E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D492
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D492
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D60A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D60A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D491
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D491
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D496
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D496
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D60B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D60B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D498
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D498
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D60C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D60C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D497
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D497
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D414
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D414
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D412
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D412
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4A6
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4A6
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4A5
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4A5
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4A3
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4A3
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4A2
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4A2
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4A1
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4A1
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D43D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D43D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D43C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D43C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_C001
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_C001
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D43E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D43E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4AF
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4AF
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4AB
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4AB
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D445
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D445
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D446
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D446
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_0100
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_0100
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4B9
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4B9
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4B8
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4B8
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D633
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D633
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D632
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D632
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D631
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D631
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4BA
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4BA
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D42F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D42F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D42E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D42E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D42D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D42D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D43A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D43A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D62D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D62D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D62E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D62E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D62B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D62B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4BB
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4BB
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D62C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D62C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D62A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D62A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D630
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D630
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D438
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D438
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D469
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D469
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D468
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D468
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D467
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D467
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D466
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D466
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D70B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D70B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D70A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D70A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D70D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D70D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D70C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D70C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D70F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D70F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D710
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D710
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D460
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D460
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D464
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D464
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D465
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D465
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D462
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D462
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D463
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D463
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D71E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D71E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D725
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D725
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D726
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D726
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_0E00
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_0E00
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D723
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D723
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D724
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D724
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D727
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D727
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D728
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D728
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D489
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D489
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D48E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D48E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D48D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D48D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_DADD
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_DADD
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_DADC
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_DADC
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D405
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D405
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D404
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D404
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D407
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D407
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D406
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D406
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D400
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D400
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D403
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D403
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D402
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D402
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D500
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D500
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D484
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D484
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D485
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D485
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D409
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D409
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D482
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D482
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D408
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D408
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D483
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D483
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D481
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D481
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D478
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D478
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D477
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D477
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D47F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D47F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D47E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D47E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D703
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D703
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D704
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D704
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D701
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D701
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D702
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D702
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_F18B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_F18B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D700
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D700
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D600
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D600
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D474
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D474
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D475
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D475
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D476
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D476
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D708
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D708
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D470
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D470
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D705
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D705
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D602
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D602
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D471
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D471
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D706
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D706
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D603
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D603
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D472
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D472
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E019
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E019
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E019
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E019
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E018
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E018
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E018
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E018
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E017
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E017
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E017
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E017
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_D626
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D626
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D665
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D665
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D666
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D666
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D667
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D667
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D669
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D669
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D48A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D48A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D661
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D661
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D63A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D63A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D663
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D663
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D63C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D63C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D662
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D662
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E014
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E014
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E014
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E014
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_D4B0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4B0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E013
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E013
(
   uint16* DataLength
);

extern Std_ReturnType DLT_WriteData_E013
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_D4E6
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4E6
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D638
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D638
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D637
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D637
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D636
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D636
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D635
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D635
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D459
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D459
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D639
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D639
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4FF
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4FF
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4DE
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4DE
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4FE
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4FE
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4DF
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4DF
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4A0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4A0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D72A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D72A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D729
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D729
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4C0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4C0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D709
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D709
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D411
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D411
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4E0
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4E0
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4E2
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4E2
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4E3
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4E3
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4DC
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4DC
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E013
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_E013
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E013
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E03D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_E03D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E03D
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_D40F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D40F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D410
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D410
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D486
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D486
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D63D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D63D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D63E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D63E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D63F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D63F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D641
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D641
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D642
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D642
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4E4
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4E4
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D4E5
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4E5
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

/** Ajout DIDs lot SC 3 */
extern Std_ReturnType DLT_ConditionCheckRead_E00D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E00D
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E00D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E00D
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E050
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E050
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E050
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E050
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E051
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E051
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E051
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E051
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E052
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E052
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E052
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E052
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E053
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E053
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E053
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_E053
(
   uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E01B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E01B
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E01B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E043
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E043
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E043
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E044
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E044
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E044
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E045
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E045
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E045
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_F18C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_F18C
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_F18C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D420
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D420
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_D420
(
   uint8* Data,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

/* DIDs pour SC4 */
extern Std_ReturnType DLT_ConditionCheckRead_E038
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E038
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E038
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E035
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E035
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E035
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E034
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E034
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E034
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E037
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E037
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E037
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_2102
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_2102
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_2102
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_WriteData_2102
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_E036
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E036
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E036
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E031
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E031
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E031
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E03A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E03A
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E03A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E033
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E033
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E033
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E032
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E032
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E032
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E039
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadDataLength_E039
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ReadData_E039
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);
extern Std_ReturnType DLT_ConditionCheckRead_E03C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_E03C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ReadDataLength_E03C
(
   uint16* DataLength
);

extern Std_ReturnType DLT_WriteData_E03C
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_ConditionCheckRead_0D01
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_0D01
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ReadDataLength_0D01
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_D40D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D40D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D736
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D736
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D737
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D737
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D73D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D73D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D73E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D73E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D73F
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D73F
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D740
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D740
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D741
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D741
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D742
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D742
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D743
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D743
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D744
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D744
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D745
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D745
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D74A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D74A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D74B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D74B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D74C
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D74C
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D74D
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D74D
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D74E
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D74E
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D750
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D750
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D751
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D751
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D752
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D752
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D753
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D753
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D754
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D754
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D757
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D757
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D760
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D760
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D761
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D761
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D762
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D762
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D763
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D763
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D764
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D764
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D765
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D765
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D766
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D766
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D767
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D767
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D780
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D780
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D782
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D782
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D783
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D783
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D784
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D784
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D785
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D785
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D786
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D786
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_D78A
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D78A
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ConditionCheckRead_E040
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_E040
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ReadDataLength_E040
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_E041
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_E041
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ReadDataLength_E041
(
   uint16* DataLength
);

extern Std_ReturnType DLT_ConditionCheckRead_E042
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_E042
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

extern Std_ReturnType DLT_ReadDataLength_E042
(
   uint16* DataLength
);
extern Std_ReturnType DLT_ConditionCheckRead_D435
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D435
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);
extern Std_ReturnType DLT_ConditionCheckRead_D4FD
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_ReadData_D4FD
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
);

#endif /* DLT_DID_H_ */