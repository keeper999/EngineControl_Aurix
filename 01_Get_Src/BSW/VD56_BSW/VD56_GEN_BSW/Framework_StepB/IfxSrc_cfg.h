/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSRC_CFG.h                                            */
/* !Description     : Configuration of framework component managing SRC       */
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
 * %PID: P2017_BSW:0A111585.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSRC_CFG_H
#define IFXSRC_CFG_H
/******************************************************************************/
#include "Ifx_Types.h"
#include "Ifx_Cfg.h"
#include "IfxSrc_reg.h"


/******************************************************************************/
/*                           Macro                                            */
/******************************************************************************/
/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/
/** Identifier of interrupt service provider, which handles the interrupt
 * service request. */
typedef enum
{
    IfxSrc_Tos_cpu0 = 0,
    IfxSrc_Tos_cpu1 = 1,
    IfxSrc_Tos_cpu2 = 2,
    IfxSrc_Tos_dma = 3,
} IfxSrc_Tos;
/******************************************************************************/

#endif /* IFXSRC_CFG_H */

/*-------------------------------- end of file -------------------------------*/
