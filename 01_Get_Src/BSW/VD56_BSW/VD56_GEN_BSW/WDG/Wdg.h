/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : WDG                                                     */
/* !Description     : WDG Component                                           */
/*                                                                            */
/* !File            : Wdg.h                                                   */
/* !Description     : Upper Layer of WDG_17_SCU components                    */
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
 * %PID: P2017_BSW:0A111576.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef WDG_H
#define WDG_H

#include "Wdg_17_Scu.h"
#include "Wdg_Add_On.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define Wdg_Init                  Wdg_17_Scu_Init
#define Wdg_SetMode               Wdg_17_Scu_SetMode
#define Wdg_SetTriggerCondition   Wdg_17_Scu_SetTriggerCondition
#define Wdg_GetVersionInfo        Wdg_17_Scu_GetVersionInfo

/******************************************************************************/
/* TYPDEF                                                                     */
/******************************************************************************/
#define Wdg_ConfigType            Wdg_17_Scu_ConfigType

#endif  /* WDG_H */

/*------------------------------ end of file ---------------------------------*/
