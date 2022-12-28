/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RTMCKS                                                  */
/* !Description     : Real Time Monitoring: Memory Checksum Control           */
/*                                                                            */
/* !File            : RTMCKS_I.h                                              */
/* !Description     : RTMCKS Internal types and datas                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:RTMCKS I H-99057336X5000X1106.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RTMCKS_I_H
#define RTMCKS_I_H

#include "Std_Types.h"
#include "RTMCKS_Types.h"
#include "RTMCKS.h"
#include "RTMCKS_Cfg.h"


/******************************************************************************/
/* TYPES DEFINITION                                                           */
/******************************************************************************/

typedef void (*RTMCKS_tpfvidCalcFuncCallback)(int,
                                              RTMCKS_tCksDataRef,
                                              RTMCKS_tCksDataRef,
                                              RTMCKS_tResultRef);
typedef void (*RTMCKS_tpfvidCheckFuncCallback)(RTMCKS_tResult);

typedef struct
{
   RTMCKS_tZoneIndexType          udtLastZoneIdx;
   RTMCKS_tpfvidCalcFuncCallback  pfvidCalcFunc;
   RTMCKS_tpfvidCheckFuncCallback pfvidCheckFunc;
} RTMCKS_tstrZoneConfig;

typedef RTMCKS_tstrZoneConfig * RTMCKS_tpstrZoneConfigRef;

typedef struct
{
   RTMCKS_tCksDataRef          pudtCksAlignRef;
   RTMCKS_tCksDataRef          pudtAlignEndRef;
   RTMCKS_tpstrZoneConfigRef   pstrZoneConfig;
   RTMCKS_tResult              udtResultValue;
   uint8                       u8StartZone;
   RTMCKS_tZoneIndexType       udtZoneIdx;
   RTMCKS_tIndexType           udtIndex;
   RTMCKS_tbfSelectType        bfSelect;
   RTMCKS_tbfSelectType        bfSelectMask;
} RTMCKS_tstrMainObject;

typedef struct
{
   RTMCKS_tCksDataRef pudtStartAddress;
   RTMCKS_tCksDataRef pudtEndAddress;
} RTMCKS_tstrAddress;

typedef RTMCKS_tstrAddress * RTMCKS_tpstrAddressRef;

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/\

#define RTMCKS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "RTMCKS_MemMap.h"

extern RTMCKS_tstrMainObject RTMCKS_astrValues[RTMCKS_udtCHANNELS_NUMBER];

#define RTMCKS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "RTMCKS_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

#define RTMCKS_START_SEC_CONST_UNSPECIFIED
#include "RTMCKS_MemMap.h"

extern const RTMCKS_tpstrZoneConfigRef RTMCKS_apstrZoneConfig[RTMCKS_udtCHANNELS_NUMBER];
extern const RTMCKS_tpstrAddressRef RTMCKS_apstrAddress[RTMCKS_udtCHANNELS_NUMBER];

#define RTMCKS_STOP_SEC_CONST_UNSPECIFIED
#include "RTMCKS_MemMap.h"

#define RTMCKS_START_SEC_CONST_16BIT
#include "RTMCKS_MemMap.h"

extern const uint16 RTMCKS_kau16BlockSize[RTMCKS_udtCHANNELS_NUMBER];

#define RTMCKS_STOP_SEC_CONST_16BIT
#include "RTMCKS_MemMap.h"

#define RTMCKS_START_SEC_CONST_8BIT
#include "RTMCKS_MemMap.h"

extern const uint8 RTMCKS_kau8NbOfArea[RTMCKS_udtCHANNELS_NUMBER];
extern const uint8 RTMCKS_kau8NbOfZone[RTMCKS_udtCHANNELS_NUMBER];

#define RTMCKS_STOP_SEC_CONST_8BIT
#include "RTMCKS_MemMap.h"

#endif   /* RTMCKS_I_H */

/*-------------------------------- end of file -------------------------------*/
