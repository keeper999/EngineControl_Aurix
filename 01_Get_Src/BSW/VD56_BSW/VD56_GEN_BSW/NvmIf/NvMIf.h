/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : NvMIf                                                   */
/* !Description     : NVM interface between ASW and NvM stack                 */
/*                                                                            */
/* !File            : NvMIf.h                                                 */
/* !Description     : Contains internal macro functions and defines of the    */
/*                    NvMIf component                                         */
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
 * %PID: P2017_BSW:0A167736.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef NVMIF_H
#define NVMIF_H

#include "Std_Types.h"
#include "NvM.h"

/* These following API will exist with AUTOSAR 4.1.2, but present NvM is AUTOSAR 4.0.2 */
#define NvM_WritePRAMBlock(BlockId) NvM_WriteBlock(BlockId, (const void *)NULL_PTR)
#define NvM_ReadPRAMBlock(BlockId)  NvM_ReadBlock(BlockId, (void *)NULL_PTR)
#define NvM_RestorePRAMBlockDefaults(BlockId)  NvM_RestoreBlockDefaults(BlockId, (void *)NULL_PTR)

/******************************************************************************/
/* CONSTANTS                                                                  */
/******************************************************************************/
#define NVMIF_START_SEC_CONST_32BIT
#include "NVMIF_MemMap.h"
extern const uint32 NvmIf_ku32NvMInitDuration_us; /* EEPROM Block  */
#define NVMIF_STOP_SEC_CONST_32BIT
#include "NVMIF_MemMap.h"

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/
#define NVMIF_START_SEC_VAR_32BIT
#include "NVMIF_MemMap.h"
extern uint32 NvmIf_u32NvMInitDuration_us; /* EEPROM Block  */
#define NVMIF_STOP_SEC_VAR_32BIT
#include "NVMIF_MemMap.h"

#define NVMIF_START_SEC_VAR_16BIT
#include "NVMIF_MemMap.h"
extern uint16 NVM_u16ConfigIdBlock; /* used by internal NvM plugin */
#define NVMIF_STOP_SEC_VAR_16BIT
#include "NVMIF_MemMap.h"


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define NVMIF_START_SEC_CODE
#include "NVMIF_MemMap.h"
extern void NvMIf_vidInit(void);
extern void NvMIf_vidWriteAll(void);
#define NVMIF_STOP_SEC_CODE
#include "NVMIF_MemMap.h"

#endif /* NVMIF_H */

/*------------------------------ end of file ---------------------------------*/
