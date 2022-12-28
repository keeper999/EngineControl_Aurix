/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_Def.h                                            */
/* !Description     : DEVHAL data declaration                                 */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef DEVHAL_DEF_H
#define DEVHAL_DEF_H

#include "Std_Types.h"
#include "IfxOvc_regdef.h"

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define DEVHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "DEVHAL_MemMap.h"

extern boolean DEVHAL_bIsFlsLoaderInitialized;
extern boolean DEVHAL_bIsFlsLoaderErasing;
extern boolean DEVHAL_bIsFlsLoaderErased;
extern boolean DEVHAL_bIsFlsLoaderCopied;
extern boolean DEVHAL_bIsInitialized;

#define DEVHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "DEVHAL_MemMap.h"

#define DEVHAL_START_SEC_VAR_CLEARED_8BIT
#include "DEVHAL_MemMap.h"

extern uint8 DEVHAL_u8CheckEngineState;

#define DEVHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "DEVHAL_MemMap.h"

#define DEVHAL_START_SEC_VAR_INIT_UNSPECIFIED
#include "DEVHAL_MemMap.h"

extern volatile Ifx_OVC_BLK_RABR  *OVMrabrXC0[32];
extern volatile Ifx_OVC_BLK_OTAR  *OVMotarXC0[32];
extern volatile Ifx_OVC_BLK_OMASK *OVMomaskXC0[32];
extern volatile Ifx_OVC_BLK_RABR  *OVMrabrXC1[32];
extern volatile Ifx_OVC_BLK_OTAR  *OVMotarXC1[32];
extern volatile Ifx_OVC_BLK_OMASK *OVMomaskXC1[32];
extern volatile Ifx_OVC_BLK_RABR  *OVMrabrXC2[32];
extern volatile Ifx_OVC_BLK_OTAR  *OVMotarXC2[32];
extern volatile Ifx_OVC_BLK_OMASK *OVMomaskXC2[32];

#define DEVHAL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "DEVHAL_MemMap.h"

#endif /* DEVHAL_DEF_H */

/*-------------------------------- end of file -------------------------------*/
