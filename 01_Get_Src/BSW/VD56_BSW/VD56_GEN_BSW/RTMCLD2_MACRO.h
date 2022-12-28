/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : RTMCLD2                                                 */
/* !Description     : Real time measurement of CPU load                       */
/*                                                                            */
/* !File            : RTMCLD2_MACRO.h                                         */
/* !Description     : Configuration of the RTMCLD2 component                  */
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
 * %PID: P2017_BSW:0A192489.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RTMCLD2_MACRO_H
#define RTMCLD2_MACRO_H

#include "Std_Types.h"
#include "RTMCLD2_CFG.h"
#include "Gpt.h"
#include "Wdg.h"

/******************************************************************************/
/* !FuncName    : RTMCLD2_vidSTART_MEASUREMENT_TIMER                          */
/* !Description : The following macro shall:                                  */
/*                - Disable all interrupt                                     */
/*                - Reload the watchdog to have the maximum available time    */
/*                  before the next wdt reset(186 ms).                        */
/*                - Never reload the watchdog, we are waiting for the reset to*/
/*                  start measurement                                         */
/*                - Call the RTMCLD2_vidEndLoopDurationMeas function on reset */
/*                                                                            */
/*                The number of endless loop execution during this watchdog   */
/*                delay was viewable into the RTMCLD2_u32MeasuredValue data   */
/*                (not erased on reset)                                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/

#define RTMCLD2_vidSTART_MEASUREMENT_TIMER() \
   do \
   { \
        SuspendAllInterrupts(); \
        Wdg_SetMode(WDGIF_FAST_MODE); \
        Wdg_Trigger(); \
   } while(0)

#endif /* RTMCLD2_MACRO_H */

/*-------------------------------- end of file -------------------------------*/
