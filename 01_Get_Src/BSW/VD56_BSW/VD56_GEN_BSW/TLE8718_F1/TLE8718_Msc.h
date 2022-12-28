/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver To Manage TLE8718 Device                                                                 */
/*                                                                                                                    */
/* !File            : TLE8718_Msc.h                                                                                   */
/* !Description     : Low Level MSC Protocol                                                                          */
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
 * %PID: P2017_BSW:0A133932.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef TLE8718_MSC_H
#define TLE8718_MSC_H

#include "Std_Types.h"
#include "HOD.h"
#include "TLE8718_co_Cfg.h"
#include "TLE8718_L.h"

#ifndef TLE8718_coDMA_USE_FOR_FRAME_RX
   #error The macro-constant TLE8718_coDMA_USE_FOR_FRAME_RX shall be defined
#endif
#ifndef TLE8718_coDISABLED
   #error The macro-constant TLE8718_coDISABLED shall be defined
#endif

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* !MComment: Maximal Number of Command Sending Without Receiving Any Valid Responses */
#define TLE8718_u8MSC_ERROR_FRAME_MAX         0x03u

/**********************************************************************************************************************/
/* DATA                                                                                                               */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

extern uint8 TLE8718_au8MscErrorFrameCnt[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscRxData[TLE8718_udtINSTANCE_NB][8u];
extern uint8 TLE8718_au8MscCmdData[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscCmdId[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscExpectedRxFrameNb[TLE8718_udtINSTANCE_NB];
#if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED)
extern uint8 TLE8718_au8MscRxFrameId[TLE8718_udtINSTANCE_NB];
#endif /* if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED) */

#define TLE8718_STOP_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_32BIT
#include "TLE8718_MemMap.h"

extern uint32 TLE8718_au32MscRxFrame[TLE8718_udtINSTANCE_NB][8u];

#define TLE8718_STOP_SEC_VAR_CLEARED_32BIT
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATIONS                                                                                             */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

extern void TLE8718_vidMscInit(void);
extern void TLE8718_vidMscStartCommand(HOD_tudtInstance udtInstance,
                                uint8 u8CmdIdentifier,
                                uint8 u8CmdData,
                                uint8 u8ExpectedRxFrameNb);
extern void TLE8718_vidMscRxFrameNotif(HOD_tudtInstance udtInstance);
extern void TLE8718_vidMscTxFrameNotif(HOD_tudtInstance udtInstance);
extern void TLE8718_vidMscTimeoutNotif(HOD_tudtInstance udtInstance);

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

#endif /* TLE8718_MSC_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
