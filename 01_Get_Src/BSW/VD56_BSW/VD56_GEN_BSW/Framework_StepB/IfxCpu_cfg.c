/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXCPU_CFG.c                                            */
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
 * %PID: P2017_BSW:0A111512.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "IfxCpu_cfg.h"
#include "Ifx_Types.h"

#define IFXCPU_START_SEC_CONST_UNSPECIFIED
#include "IFXCPU_MemMap.h"

const IfxModule_IndexMap IfxCpu_cfg_indexMap[IFXCPU_COUNT] = {
    {&MODULE_CPU0, (uint32) IfxCpu_ResourceCpu_0},
    {&MODULE_CPU1, (uint32) IfxCpu_ResourceCpu_1},
    {&MODULE_CPU2, (uint32) IfxCpu_ResourceCpu_2},
};

#define IFXCPU_STOP_SEC_CONST_UNSPECIFIED
#include "IFXCPU_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
