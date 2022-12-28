/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR_LocalTypes.h                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.6      $$Author::   aalaa          $$Date::   Oct 02 2013 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_LOCALTYPES_H
#define PDUR_LOCALTYPES_H

#include "Std_Types.h"
#include "ComStack_Cfg.h"

#include "PduR_Types.h"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/*!   \Description      Identifies the routing type (minimum/normal routing)
                        and accordingly grab the needed information \n
      \Range            PduR_u8MINIMUM_ROUTING, PduR_u8NORMAL_ROUTING, 
                        PduR_u8INVALID_ROUTING \n
*******************************************************************************/
typedef uint8   PduR_tu8RoutingType;

#define PduR_u8MINIMUM_ROUTING          0x00
#define PduR_u8NORMAL_ROUTING           0x01
#define PduR_u8INVALID_ROUTING          0x02 

/******************************************************************************/
/*!   \Description      Identifies the state of the IPDU in the PduR context.
                        Refer to B791130I0-222-0201-CDD.doc for details \n
      \Range            PduR_u8IDLE, PduR_u8TOBEHANDLED, PduR_u8INPROGRESS \n
*******************************************************************************/
typedef uint8   PduR_tu8PduStateType;

#define PduR_u8IDLE                     0x00
#define PduR_u8TOBEHANDLED              0x01
#define PduR_u8INPROGRESS               0x02


/******************************************************************************/
/* Enumerations                                                               */
/******************************************************************************/


/******************************************************************************/
/* Structures                                                                 */
/******************************************************************************/

/*---------------------------------TP Buffers---------------------------------*/
typedef struct {
    VAR(boolean, AUTOMATIC)                                     bIsFree;
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RPathGrpId;
    #endif
    VAR(PduLengthType, AUTOMATIC)                               udtMsgLen;
    VAR(PduLengthType, AUTOMATIC)                               udtTxIdx;
    VAR(PduLengthType, AUTOMATIC)                               udtRxIdx;
    VAR(PduLengthType, AUTOMATIC)                               udtTxAvBytes;
    VAR(PduLengthType, AUTOMATIC)                               udtRxAvBytes;
} PduR_tstrTpBuffCntrlType;


/*----------------------------API References Array----------------------------*/
typedef struct {
    P2CONST(PduR_tstrLoIfRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrMinRRxTRf;
    P2CONST(PduR_tstrLoIfRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrNrmRRxTRf;
    P2CONST(PduR_tstrIf2UpRxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrMinRxFnTblRf;
    P2CONST(PduR_tstrIf2UpRxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrNrmRxFnTblRf;
    VAR(uint16, AUTOMATIC)                                              u16MinRxTSize;
    VAR(uint16, AUTOMATIC)                                              u16NrmRxTSize;
    VAR(uint8, AUTOMATIC)                                               u8APIId;
} PduR_tstrIfRxRefType;

typedef struct {
    P2CONST(PduR_tstrLoIfTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrMinRTxTRf;
    P2CONST(PduR_tstrLoIfTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrNrmRTxTRf;
    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrMinTxFnTblRf;
    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrNrmTxFnTblRf;
    VAR(uint16, AUTOMATIC)                                              u16MinTxTSize;
    VAR(uint16, AUTOMATIC)                                              u16NrmTxTSize;
    VAR(uint8, AUTOMATIC)                                               u8APIId;
} PduR_tstrIfTxRefType;


typedef struct {
    P2CONST(PduR_tstrLoTpRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrMinRRxTRf;
    P2CONST(PduR_tstrLoTpRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrNrmRRxTRf;
    P2CONST(PduR_tstrTp2UpRxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrMinRxFnTblRf;
    P2CONST(PduR_tstrTp2UpRxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrNrmRxFnTblRf;
    VAR(uint16, AUTOMATIC)                                              u16MinRxTSize;
    VAR(uint16, AUTOMATIC)                                              u16NrmRxTSize;
    VAR(uint8, AUTOMATIC)                                               u8APIId;
} PduR_tstrTpRxRefType;

typedef struct {
    P2CONST(PduR_tstrLoTpTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrMinRTxTRf;
    P2CONST(PduR_tstrLoTpTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrNrmRTxTRf;
    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrMinTxFnTblRf;
    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)   pkstrNrmTxFnTblRf;
    VAR(uint16, AUTOMATIC)                                              u16MinTxTSize;
    VAR(uint16, AUTOMATIC)                                              u16NrmTxTSize;
    VAR(uint8, AUTOMATIC)                                               u8APIId;
} PduR_tstrTpTxRefType;

typedef struct {
    P2CONST(PduR_tstrUpTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)       pkstrMinRTxTRf;
    P2CONST(PduR_tstrUpTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)       pkstrNrmRTxTRf;
    VAR(uint16, AUTOMATIC)                                              u16MinTxTSize;
    VAR(uint16, AUTOMATIC)                                              u16NrmTxTSize;
    P2CONST(PduR_tstrUpTpRevTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrMinRevRTxTRf;
    P2CONST(PduR_tstrUpTpRevTableType, AUTOMATIC, PDUR_CALIB_CONST)     pkstrNrmRevRTxTRf;
    VAR(uint16, AUTOMATIC)                                              u16MinRevTxTSize;
    VAR(uint16, AUTOMATIC)                                              u16NrmRevTxTSize;
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)      pkstrMinTpTxFnTblRf;
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)      pkstrNrmTpTxFnTblRf;
    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)      pkstrMinIfTxFnTblRf;
    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)      pkstrNrmIfTxFnTblRf;
    VAR(uint8, AUTOMATIC)                                               u8APIId;
} PduR_tstrUpRefType;



#endif /* PDUR_LOCALTYPES_H */

/*------------------------------- end of file --------------------------------*/