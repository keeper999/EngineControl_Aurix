/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : NvMIf                                                   */
/* !Description     : NVM interface between ASW and NvM stack                 */
/*                                                                            */
/* !File            : NvMIf_Def.c                                             */
/* !Description     : Data definitions                                        */
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
 * %PID: P2017_BSW:0A167735.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

/******************************************************************************/
/* CONSTANTS                                                                  */
/******************************************************************************/
#define NVMIF_START_SEC_CONST_32BIT
#include "NVMIF_MemMap.h"
const uint32 NvmIf_ku32NvMInitDuration_us = 0; /* EEPROM Block  */
#define NVMIF_STOP_SEC_CONST_32BIT
#include "NVMIF_MemMap.h"

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/
#define NVMIF_START_SEC_VAR_32BIT
#include "NVMIF_MemMap.h"
uint32 NvmIf_u32NvMInitDuration_us; /* EEPROM Block  */
#define NVMIF_STOP_SEC_VAR_32BIT
#include "NVMIF_MemMap.h"

#define NVMIF_START_SEC_VAR_16BIT
#include "NVMIF_MemMap.h"
uint16 NVM_u16ConfigIdBlock; /* used by internal NvM plugin */
#define NVMIF_STOP_SEC_VAR_16BIT
#include "NVMIF_MemMap.h"


/*------------------------------ end of file ---------------------------------*/
