
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !Module          : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !File            : Com_LCfg.h                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.3      $$Author::   ngalal         $$Date::   Dec 04 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/  

#ifndef COM_LCFG_H
#define COM_LCFG_H

#include "Com_CfgTypes.h"
#include "Com_Internal.h"



#define Com_u16NO_OF_FILTER            0U
#define Com_u16NO_OF_MASK_F_B          0U
#define Com_u16NO_OF_MASK_F_U8         0U
#define Com_u16NO_OF_MASK_F_S8         0U
#define Com_u16NO_OF_MASK_F_U16        0U
#define Com_u16NO_OF_MASK_F_S16        0U
#define Com_u16NO_OF_MASK_F_U32        0U
#define Com_u16NO_OF_MASK_F_S32        0U

#define Com_u16NO_OF_MASK_OLD_F_B      0U
#define Com_u16NO_OF_MASK_OLD_F_U8     0U
#define Com_u16NO_OF_MASK_OLD_F_S8     0U
#define Com_u16NO_OF_MASK_OLD_F_U16    0U
#define Com_u16NO_OF_MASK_OLD_F_S16    0U
#define Com_u16NO_OF_MASK_OLD_F_U32    0U
#define Com_u16NO_OF_MASK_OLD_F_S32    0U

#define Com_u16NO_OF_LIMITS_F_U8       0U
#define Com_u16NO_OF_LIMITS_F_S8       0U
#define Com_u16NO_OF_LIMITS_F_U16      0U
#define Com_u16NO_OF_LIMITS_F_S16      0U
#define Com_u16NO_OF_LIMITS_F_U32      0U
#define Com_u16NO_OF_LIMITS_F_S32      0U

#define Com_u16NO_OF_ONE_EVERY_N_F     0U

#define Com_u16NO_OF_TX_IPDU           26U

#define Com_u16NO_OF_SIGNAL            469U

#define Com_u16NO_OF_COUNTER_ERR       3U

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */


#define COM_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"
#if Com_u16NO_OF_COUNTER_ERR > 0u
extern CONST(Com_tpfvidCounterError, COM_CFG_CONST ) Com_akpfvideIPduCounterErrNotif[Com_u16NO_OF_COUNTER_ERR];
#endif

#if Com_u16NO_OF_SIGNAL > 0u
extern CONST(Com_tstrSignalLT, COM_CFG_CONST) Com_akstreSignalLT [Com_u16NO_OF_SIGNAL];
#endif

#if Com_u16NO_OF_FILTER > 0u
extern CONST(Com_tstrFilter, COM_CFG_CONST) Com_akstreFilter [Com_u16NO_OF_FILTER];
#endif

#if Com_u16NO_OF_MASK_F_B > 0u
extern CONST(Com_tstrMaskFilterB, COM_CFG_CONST)   Com_akstreMaskFilterB [Com_u16NO_OF_MASK_F_B];
#endif

#if Com_u16NO_OF_MASK_F_U8 > 0u
extern CONST(Com_tstrMaskFilterU8, COM_CFG_CONST) Com_akstreMaskFilterU8 [Com_u16NO_OF_MASK_F_U8];
#endif

#if Com_u16NO_OF_MASK_F_S8 > 0u
extern CONST(Com_tstrMaskFilterS8, COM_CFG_CONST) Com_akstreMaskFilterS8 [Com_u16NO_OF_MASK_F_S8];
#endif

#if Com_u16NO_OF_MASK_F_U16 > 0u
extern CONST(Com_tstrMaskFilterU16, COM_CFG_CONST) Com_akstreMaskFilterU16 [Com_u16NO_OF_MASK_F_U16];
#endif

#if Com_u16NO_OF_MASK_F_S16 > 0u
extern CONST(Com_tstrMaskFilterS16, COM_CFG_CONST) Com_akstreMaskFilterS16 [Com_u16NO_OF_MASK_F_S16];
#endif

#if Com_u16NO_OF_MASK_F_U32 > 0u
extern CONST(Com_tstrMaskFilterU32, COM_CFG_CONST) Com_akstreMaskFilterU32 [Com_u16NO_OF_MASK_F_U32];
#endif

#if Com_u16NO_OF_MASK_F_S32 > 0u
extern CONST(Com_tstrMaskFilterS32, COM_CFG_CONST) Com_akstreMaskFilterS32 [Com_u16NO_OF_MASK_F_S32];
#endif

#if Com_u16NO_OF_MASK_OLD_F_B > 0u
extern CONST(Com_tstrMaskOldFilterB, COM_CFG_CONST)  Com_akstreMaskOldFilterB [Com_u16NO_OF_MASK_OLD_F_B];
#endif

#if Com_u16NO_OF_MASK_OLD_F_U8 > 0u
extern CONST(Com_tstrMaskOldFilterU8, COM_CFG_CONST) Com_akstreMaskOldFilterU8 [Com_u16NO_OF_MASK_OLD_F_U8];
#endif

#if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
extern CONST(Com_tstrMaskOldFilterS8, COM_CFG_CONST) Com_akstreMaskOldFilterS8 [Com_u16NO_OF_MASK_OLD_F_S8];
#endif

#if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
extern CONST(Com_tstrMaskOldFilterU16, COM_CFG_CONST) Com_akstreMaskOldFilterU16 [Com_u16NO_OF_MASK_OLD_F_U16];
#endif

#if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
extern CONST(Com_tstrMaskOldFilterS16, COM_CFG_CONST) Com_akstreMaskOldFilterS16 [Com_u16NO_OF_MASK_OLD_F_S16];
#endif

#if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
extern CONST(Com_tstrMaskOldFilterU32, COM_CFG_CONST) Com_akstreMaskOldFilterU32 [Com_u16NO_OF_MASK_OLD_F_U32];
#endif

#if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
extern CONST(Com_tstrMaskOldFilterS32, COM_CFG_CONST) Com_akstreMaskOldFilterS32 [Com_u16NO_OF_MASK_OLD_F_S32];
#endif

#define COM_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

#define COM_START_SEC_VAR_8
#include "Memmap.h"

#if Com_u16NO_OF_MASK_OLD_F_B > 0u
extern VAR(boolean, COM_VAR_NOINIT)  Com_abeFilterOldValueB[Com_u16NO_OF_MASK_OLD_F_B];
#endif

#if Com_u16NO_OF_MASK_OLD_F_U8 > 0u
extern VAR(uint8, COM_VAR_NOINIT)    Com_au8eFilterOldValueU8[Com_u16NO_OF_MASK_OLD_F_U8];
#endif

#if Com_u16NO_OF_MASK_OLD_F_S8 > 0u
extern VAR(sint8, COM_VAR_NOINIT)    Com_as8eFilterOldValueS8[Com_u16NO_OF_MASK_OLD_F_S8];
#endif

#define COM_STOP_SEC_VAR_8
#include "Memmap.h"

#define COM_START_SEC_VAR_16
#include "Memmap.h"

#if Com_u16NO_OF_MASK_OLD_F_U16 > 0u
extern VAR(uint16, COM_VAR_NOINIT)   Com_au16eFilterOldValueU16[Com_u16NO_OF_MASK_OLD_F_U16];
#endif

#if Com_u16NO_OF_MASK_OLD_F_S16 > 0u
extern VAR(sint16, COM_VAR_NOINIT)   Com_as16eFilterOldValueS16[Com_u16NO_OF_MASK_OLD_F_S16];
#endif

#define COM_STOP_SEC_VAR_16
#include "Memmap.h"

#define COM_START_SEC_VAR_32
#include "Memmap.h"

#if Com_u16NO_OF_MASK_OLD_F_U32 > 0u
extern VAR(uint32, COM_VAR_NOINIT)   Com_au32eFilterOldValueU32[Com_u16NO_OF_MASK_OLD_F_U32];
#endif

#if Com_u16NO_OF_MASK_OLD_F_S32 > 0u
extern VAR(sint32, COM_VAR_NOINIT)   Com_as32eFilterOldValueS32[Com_u16NO_OF_MASK_OLD_F_S32];
#endif

#define COM_STOP_SEC_VAR_32
#include "Memmap.h"


#define COM_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

#if Com_u16NO_OF_LIMITS_F_U8 > 0u
extern CONST(Com_tstrLimitsFilterU8, COM_CFG_CONST) Com_akstreLimitsFilterU8 [Com_u16NO_OF_LIMITS_F_U8];
#endif

#if Com_u16NO_OF_LIMITS_F_S8 > 0u
extern CONST(Com_tstrLimitsFilterS8, COM_CFG_CONST) Com_akstreLimitsFilterS8 [Com_u16NO_OF_LIMITS_F_S8];
#endif

#if Com_u16NO_OF_LIMITS_F_U16 > 0u
extern CONST(Com_tstrLimitsFilterU16, COM_CFG_CONST) Com_akstreLimitsFilterU16 [Com_u16NO_OF_LIMITS_F_U16];
#endif

#if Com_u16NO_OF_LIMITS_F_S16 > 0u
extern CONST(Com_tstrLimitsFilterS16, COM_CFG_CONST) Com_akstreLimitsFilterS16 [Com_u16NO_OF_LIMITS_F_S16];
#endif

#if Com_u16NO_OF_LIMITS_F_U32 > 0u
extern CONST(Com_tstrLimitsFilterU32, COM_CFG_CONST) Com_akstreLimitsFilterU32 [Com_u16NO_OF_LIMITS_F_U32];
#endif

#if Com_u16NO_OF_LIMITS_F_S32 > 0u
extern CONST(Com_tstrLimitsFilterS32, COM_CFG_CONST) Com_akstreLimitsFilterS32 [Com_u16NO_OF_LIMITS_F_S32];
#endif

#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
extern CONST(Com_tstrOneEveryNFilter, COM_CFG_CONST) Com_akstreOneEveryNFilter [Com_u16NO_OF_ONE_EVERY_N_F];
#endif

#define COM_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"


#define COM_START_SEC_VAR_32
#include "Memmap.h"

#if Com_u16NO_OF_ONE_EVERY_N_F > 0u
extern VAR(uint32, COM_VAR_NOINIT) Com_au32eOneEveryNFilterCtr[Com_u16NO_OF_ONE_EVERY_N_F];
#endif

#define COM_STOP_SEC_VAR_32
#include "Memmap.h"


#define COM_START_SEC_VAR_8
#include "Memmap.h"
extern VAR(Com_IpduGroupVector, COM_VAR_NOINIT) Com_au8eIPduGroupVector;
extern VAR(Com_IpduGroupVector, COM_VAR_NOINIT) Com_au8eRxDMIPduGroupVector;
#define COM_STOP_SEC_VAR_8
#include "Memmap.h"

#define COM_START_CONFIG_DATA_8
#include "Memmap.h"

#if Com_u16NO_OF_TX_IPDU > 0u
extern CONST(Com_tu8TxUnusedAreasDefault,COM_CFG_CONST)
                        Com_aku8eTxUnusedAreaDefault [Com_u16NO_OF_TX_IPDU];
#endif

#define COM_STOP_CONFIG_DATA_8
#include "Memmap.h"


/******************************************************************************/
/*! \Description calculation method: \n
                     ((TotalNumberOfSignalsOfTypeBoolean-1)/8)+1 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_B_SIZE     0U

/******************************************************************************/
/*! \Description calculation method: \n
                     TotalNumberOfSignalsOfTypeU8 \n
                     + SumOfLengthsOfSignalsOfTypeU8N \n
                     + SumOfLengthsOfSignalsOfTypeU8DYN \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_U8U8N_SIZE 0U 

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeS8 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_S8_SIZE    0U

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeU16 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_U16_SIZE   0U

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeS16 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_S16_SIZE   0U

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeU32 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_U32_SIZE   0U

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeS32 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_S32_SIZE   0U

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeF32 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_F32_SIZE   0U

/******************************************************************************/
/*! \Description calculation method: TotalNumberOfSignalsOfTypeF64 \n */
/******************************************************************************/

#define Com_u16SIG_INV_V_F64_SIZE   0U

#define COM_START_CONFIG_DATA_8
#include "Memmap.h"

#if Com_u16SIG_INV_V_B_SIZE > 0u
extern CONST(boolean,COM_CFG_CONST) Com_akbeSigInvalidValB      [Com_u16SIG_INV_V_B_SIZE];
#endif

#if Com_u16SIG_INV_V_U8U8N_SIZE > 0u
extern CONST(uint8,COM_CFG_CONST) Com_aku8eSigInvalidValU8U8N  [Com_u16SIG_INV_V_U8U8N_SIZE];
#endif

#if Com_u16SIG_INV_V_S8_SIZE > 0u
extern CONST(sint8,COM_CFG_CONST) Com_aks8eSigInvalidValS8     [Com_u16SIG_INV_V_S8_SIZE];
#endif

#define COM_STOP_CONFIG_DATA_8
#include "Memmap.h"

#define COM_START_CONFIG_DATA_16
#include "Memmap.h"

#if Com_u16SIG_INV_V_U16_SIZE > 0u
extern CONST(uint16,COM_CFG_CONST) Com_aku16eSigInvalidValU16  [Com_u16SIG_INV_V_U16_SIZE];
#endif

#if Com_u16SIG_INV_V_S16_SIZE > 0u
extern CONST(sint16,COM_CFG_CONST) Com_aks16eSigInvalidValS16  [Com_u16SIG_INV_V_S16_SIZE];
#endif

#define COM_STOP_CONFIG_DATA_16
#include "Memmap.h"

#define COM_START_CONFIG_DATA_32
#include "Memmap.h"

#if Com_u16SIG_INV_V_U32_SIZE > 0u
extern CONST(uint32,COM_CFG_CONST) Com_aku32eSigInvalidValU32  [Com_u16SIG_INV_V_U32_SIZE];
#endif

#if Com_u16SIG_INV_V_S32_SIZE > 0u
extern CONST(sint32,COM_CFG_CONST) Com_aks32eSigInvalidValS32  [Com_u16SIG_INV_V_S32_SIZE];
#endif

#if Com_u16SIG_INV_V_F32_SIZE > 0u
extern CONST(float32,COM_CFG_CONST) Com_akf32eSigInvalidValF32 [Com_u16SIG_INV_V_F32_SIZE];
#endif

#define COM_STOP_CONFIG_DATA_32
#include "Memmap.h"

#define COM_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

#if Com_u16SIG_INV_V_F64_SIZE > 0u
extern CONST(float64,COM_CFG_CONST) Com_akf64eSigInvalidValF64 [Com_u16SIG_INV_V_F64_SIZE];
#endif

#define COM_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"


extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF495_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF532_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF532_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF532_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF7F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF495_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF57C_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF5B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF7F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF792_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHLIN_EveRxF11_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF5B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_AckClbk (void);

extern FUNC(void, COM_CODE) FHLIN_EveTxF29_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4D2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4D2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4D2_AckClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF495_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF532_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF532_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF532_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF572_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF552_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF7F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF495_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF57C_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3AD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF5B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF7F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF792_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF329_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3CD_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHLIN_EveRxF11_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF412_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF3C9_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF5B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF489_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF34D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF50E_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF349_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF592_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF612_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4F2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF492_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4B2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF305_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF30D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF38D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF44D_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveTxF208_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF432_TOutClbk (void);

extern FUNC(void, COM_CODE) FHLIN_EveTxF29_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4D2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4D2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveRxF4D2_TOutClbk (void);

extern FUNC(void, COM_CODE) FHCAN_EveCntF329_Clbk (VAR(PduIdType,AUTOMATIC) ComPduId, VAR(uint8,AUTOMATIC) ExpectedCounter, VAR(uint8,AUTOMATIC) ReceivedCounter);

extern FUNC(void, COM_CODE) FHCAN_EveCntF349_Clbk (VAR(PduIdType,AUTOMATIC) ComPduId, VAR(uint8,AUTOMATIC) ExpectedCounter, VAR(uint8,AUTOMATIC) ReceivedCounter);

extern FUNC(void, COM_CODE) FHCAN_EveCntF3C9_Clbk (VAR(PduIdType,AUTOMATIC) ComPduId, VAR(uint8,AUTOMATIC) ExpectedCounter, VAR(uint8,AUTOMATIC) ReceivedCounter);


/******************************************************************************/
/*! \Description Maximum indexes for LT arrays \n */
/******************************************************************************/


#define Com_u16RXIPDUIDMAX 66

#define Com_u16TXIPDUIDMAX 64

#define Com_u16IPDUIDMAX 66

#define Com_u16SIGNALIDMAX 468

#define Com_u16SIGNALGROUPIDMAX 0

#define Com_u16ONEEVERYNFCTRMAXIX 0

#define Com_u16IPDUGROUPVCTRMAXIX 0

#define Com_u16RXIPDUMAXIX 40

#define Com_u16TXIPDUMAXIX 25

/**************************************************************************/
/*! \Description  size of Com_aku16eGWSignalLength

                 calculation method: total number of GW signals of structure \n
                 type description and signal type UINT8_N or UINT8_DYN \n */
/**************************************************************************/

#define Com_u16GW_SIG_LENGTH_SIZE          0U

#define COM_START_CONFIG_DATA_16
#include "Memmap.h"

#if Com_u16GW_SIG_LENGTH_SIZE > 0u
extern CONST(Com_tu16GWSignalLength, AUTOMATIC) Com_aku16eGWSignalLength[Com_u16GW_SIG_LENGTH_SIZE];
#endif

#define COM_STOP_CONFIG_DATA_16
#include "Memmap.h"

#define Com_u16NO_OF_SIGNAL_GROUPSLT           0U

#define Com_u16NO_OF_GROUP_SIGSLT           0U

#define COM_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

#if Com_u16NO_OF_GROUP_SIGSLT > 0u
extern CONST(Com_tstrGroupSignalLT, COM_CFG_CONST) Com_akstreGroupSignalLT [Com_u16NO_OF_GROUP_SIGSLT];
#endif

#if Com_u16NO_OF_SIGNAL_GROUPSLT > 0u
extern CONST(Com_tstrSignalGroupLT, COM_CFG_CONST) Com_akstreSignalGroupLT [Com_u16NO_OF_SIGNAL_GROUPSLT];
#endif

#define COM_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"



#define u16NO_OF_IPDUS_STATUS     67U 

#define Com_u16NO_OF_SIGNAL_STATUS     469U

#define COM_START_SEC_VAR_8
#include "Memmap.h"


#if u16NO_OF_IPDUS_STATUS > 0u

extern VAR(Com_udtIPduStatus, COM_VAR_NOINIT)  Com_audteIPduStatus[u16NO_OF_IPDUS_STATUS];
#endif


/*Number of Signals And Signal Groups*/

#if Com_u16NO_OF_SIGNAL_STATUS > 0u
extern VAR(Com_udtSigStatus, COM_VAR_NOINIT) Com_audteSignalStatus[Com_u16NO_OF_SIGNAL_STATUS];
#endif

#define COM_STOP_SEC_VAR_8
#include "Memmap.h"

/* PRQA S 0850 --                                                             */
#endif /* COM_LCFG_H */

      
