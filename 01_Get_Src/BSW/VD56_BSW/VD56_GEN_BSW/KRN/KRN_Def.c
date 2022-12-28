/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_Def.c                                               */
/* !Description     : Data of KRN Component                                   */
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
 * %PID: P2017_BSW:0A192529.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "STD_TYPES.h"
#include "KRN.h"
#include "KRN_Private.h"
#include "KRN_Types.h"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define KRN_START_SEC_KRN_CKS_LOG
#include "KRN_MemMap.h"
const uint16 KRN_ku16SoftChecksum = 0;
#define KRN_STOP_SEC_KRN_CKS_LOG
#include "KRN_MemMap.h"

#define KRN_START_SEC_KRN_CKS_CAL
#include "KRN_MemMap.h"
const uint16 KRN_ku16CalibChecksum = 0;
#define KRN_STOP_SEC_KRN_CKS_CAL
#include "KRN_MemMap.h"

#define KRN_START_SEC_KRN_CKS_TMS_LOG
#include "KRN_MemMap.h"
const uint16 KRN_ku16TmsSoftChecksum = 0;
#define KRN_STOP_SEC_KRN_CKS_TMS_LOG
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_CKS_TMS_CAL
#include "KRN_MemMap.h"
const uint16 KRN_ku16TmsCalibChecksum = 0;
#define KRN_STOP_SEC_KRN_CKS_TMS_CAL
#include "KRN_MemMap.h"


#define KRN_START_SEC_TMS_CODE_BEG
#include "KRN_MemMap.h"
const uint32 KRN_ku32TmsCodeBeg = 0xAA55AA55;
#define KRN_STOP_SEC_TMS_CODE_BEG
#include "KRN_MemMap.h"


#define KRN_START_SEC_TMS_CODE_END
#include "KRN_MemMap.h"
const uint32 KRN_ku32TmsCodeEnd = 0x55AA55AA;
#define KRN_STOP_SEC_TMS_CODE_END
#include "KRN_MemMap.h"


#define KRN_START_SEC_TMS_CALIB_BEG
#include "KRN_MemMap.h"
const uint32 KRN_ku32TmsCalibBeg = 0xAA55AA55;
#define KRN_STOP_SEC_TMS_CALIB_BEG
#include "KRN_MemMap.h"


#define KRN_START_SEC_TMS_CALIB_END
#include "KRN_MemMap.h"
const uint32 KRN_ku32TmsCalibEnd = 0x55AA55AA;
#define KRN_STOP_SEC_TMS_CALIB_END
#include "KRN_MemMap.h"

#define RSTSRV_START_SEC_CONST_16BIT
#include "RSTSRV_MemMap.h"
const uint16 RSTSRV_ku16HotResetCtr = 0;
#define RSTSRV_STOP_SEC_CONST_16BIT
#include "RSTSRV_MemMap.h"


#define KRN_START_SEC_CONST_UNSPECIFIED
#include "KRN_MemMap.h"
const KRN_tstrExceptionRegs KRN_kstrExceptionRegs = {(void *)NULL_PTR,0,0,0};
#define KRN_STOP_SEC_CONST_UNSPECIFIED
#include "KRN_MemMap.h"

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/

#define KRN_START_SEC_VAR_CLEARED_BOOLEAN
#include "KRN_MemMap.h"
boolean KRN_bFirstCalibChecksumDone;
boolean KRN_bFirstSoftChecksumDone;
volatile boolean KRN_vbFirstTmsCalibChecksumDone;
volatile boolean KRN_vbFirstTmsSoftChecksumDone;
boolean KRN_bInitTmsChecksumOK;
volatile boolean KRN_bOsAccessAuthorized;
volatile boolean KRN_bPowerOnCopyPerformed;
#define KRN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_16BIT
#include "KRN_MemMap.h"
uint16 KRN_u16CalibChecksum;
uint16 KRN_u16InitTmsCalibChecksum;
uint16 KRN_u16InitTmsSoftChecksum;
uint16 KRN_u16SchedulerOverrunCnt;
uint16 KRN_u16SoftChecksum;
uint16 KRN_u16TmsCalibChecksum;
uint16 KRN_u16TmsSoftChecksum;
uint16 Type_de_defaut_eep;
uint16 Compteur_defaut_except_eep;
uint16 Compteur_defaut_pile_eep;
#define KRN_STOP_SEC_VAR_CLEARED_16BIT
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_32BIT
#include "KRN_MemMap.h"
uint32 KRN_u32CompareValue;
uint32 KRN_u32StackUsed;
uint32 ErrorAddress_eep;
#define KRN_STOP_SEC_VAR_CLEARED_32BIT
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_8BIT
#include "KRN_MemMap.h"
uint8 KRN_u8Modulo60000ms;
#define KRN_STOP_SEC_VAR_CLEARED_8BIT
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "KRN_MemMap.h"
KRN_tstrExceptionRegs KRN_strExceptionRegs;
#define KRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "KRN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

