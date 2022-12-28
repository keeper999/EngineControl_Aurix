/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXCPU_CFG.h                                            */
/* !Description     : Confoguration of framework component managing CPU       */
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
 * %PID: P2017_BSW:0A111615.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXCPU_CFG_H
#define IFXCPU_CFG_H
/******************************************************************************/
#include "IfxCpu_reg.h"
#include "Ifx_Types.h"


/******************************************************************************/
/*                           Macro                                            */
/******************************************************************************/
#define IFXCPU_COUNT   (3)               /**< \brief CPU count */

/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/
/* List of the available CPU resources */
typedef enum
{
    IfxCpu_ResourceCpu_0 = 0,                               /**< CPU 0 */
    IfxCpu_ResourceCpu_1,                                   /**< CPU 1 */
    IfxCpu_ResourceCpu_2,                                   /**< CPU 2 */
    IfxCpu_ResourceCpu_none                                 /**< None of the CPU  */
} IfxCpu_ResourceCpu;


/** Halt status */
typedef enum
{
    IfxCpu_DBGST_HALT_run = 0,
    IfxCpu_DBGST_HALT_halt = 1
} IfxCpu_DBGST_HALT;

/** Power management status */
typedef enum
{
    IfxCpu_PMCSR_PMST_normalMode = 1,
    IfxCpu_PMCSR_PMST_idleModeRequest = 2,
    IfxCpu_PMCSR_PMST_idleMode = 3,
    IfxCpu_PMCSR_PMST_sleepModeRequest = 4,
    IfxCpu_PMCSR_PMST_standbyModeRequest = 6
} IfxCpu_PMCSR_PMST;


#define IFXCPU_START_SEC_CONST_UNSPECIFIED
#include "IFXCPU_MemMap.h"

extern const IfxModule_IndexMap IfxCpu_cfg_indexMap[IFXCPU_COUNT];

#define IFXCPU_STOP_SEC_CONST_UNSPECIFIED
#include "IFXCPU_MemMap.h"

#endif /* IFXCPU_CFG_H */

/*-------------------------------- end of file -------------------------------*/
