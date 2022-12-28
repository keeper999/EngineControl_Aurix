/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Cfg_E.h                                                                                 */
/* !Description     : External Configuration of TLE8718 Component                                                     */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192535.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_CFG_E_H
#define TLE8718_CFG_E_H

#include "Std_Types.h"

/* Patch because the 2 following types are not yet defined in HOD component */
/* dbg */
typedef uint32   HOD_tudtPeriod;
typedef uint32   HOD_tudtDutyCycle;
/* dbg */

#include "Msc.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_Gateway.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* !MComment: Instance Numbers */
#define TLE8718_udtINSTANCE_1      0u

/**********************************************************************************************************************/
/* MACRO FUNCTIONS                                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEntry_10ms                                                                               */
/* !Description : Macro called in 10ms task                                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidEntry_10ms() \
do \
{ \
   TLE8718_abReactDelayMngEvent[TLE8718_udtINSTANCE_1] = TRUE; \
   TLE8718_abDiagReqStartEvent[TLE8718_udtINSTANCE_1] = TRUE; \
   TLE8718_vidMainFunction(TLE8718_udtINSTANCE_1); \
} \
while (0)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEntry_100ms                                                                              */
/* !Description : Macro called in 100ms task                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidEntry_100ms() \
do \
{ \
   TLE8718_abSafetyReqStartEvent[TLE8718_udtINSTANCE_1] = TRUE; \
} \
while (0)

/**********************************************************************************************************************/
/* FUNCTION DECLARATION                                                                                               */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

void Msc_Interrupt_HandlerMSC0RxFrame(void);
void TLE8718_vidMc0TxCmdFrameNotif(void);
void Msc_Interrupt_HandlerMSC0_SR4(void);

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

#endif /* TLE8718_CFG_E_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
