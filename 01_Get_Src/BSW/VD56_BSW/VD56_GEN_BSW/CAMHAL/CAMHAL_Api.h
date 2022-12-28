/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_Api.h                                            */
/* !Description     : APIs declaration of CAMHAL Component                    */
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
 * %PID: P2017_BSW:A81074.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CAMHAL_API_H
#define CAMHAL_API_H

#include "Std_Types.h"
#include "CAMHAL_E.h"
#include "CAMHAL_Typ.h"
#include "IfxGtm_Typ.h"

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define CAMHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CAMHAL_MemMap.h"

extern volatile Ifx_GTM_TIM_CH*  CAMHAL_IntakeTim;
extern volatile Ifx_GTM_TIM_CH*  CAMHAL_ExhaustTim;

#define CAMHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CAMHAL_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

void CAMHAL_vidInit(void);
void CAMHAL_vidSetMode(CAMHAL_tudtChannel udtChannelName, CAMHAL_tenuMode enuMode);
Std_ReturnType CAMHAL_udtReadMode(CAMHAL_tudtChannel udtChannelName, CAMHAL_tenuMode *penuMode);
Std_ReturnType CAMHAL_udtReadStatus(CAMHAL_tudtChannel udtChannelName, uint8 u8ChannelStatus, boolean *pbStatus);
Std_ReturnType CAMHAL_udtEnableDetection(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtDisableDetection(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtEnableSynchronisation(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtDisableSynchronisation(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtForceDesynchronisation(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtReadCylinderNumber(CAMHAL_tudtChannel udtChannelName, CAMHAL_tenuCylinderNumber *penuCylinderNumber);
Std_ReturnType CAMHAL_udtReadToothPeriod(CAMHAL_tudtChannel udtChannelName, uint32 *pu32Period);
Std_ReturnType CAMHAL_udtReadSignalLevel(CAMHAL_tudtChannel udtChannelName, boolean *pbLevel);
Std_ReturnType CAMHAL_udtReadEventPosition(CAMHAL_tudtChannel udtChannelName, uint16 *pu16Position);
Std_ReturnType CAMHAL_udtEnableEvtActivation(CAMHAL_tudtChannel udtChannelName);
Std_ReturnType CAMHAL_udtDisableEvtActivation(void);
void CAMHAL_vidSetTrueEdgePos(CAMHAL_tudtChannel udtChannelName, uint16 *pau16CamEdgePositionTable);
Std_ReturnType CAMHAL_udtGetEdgeCounter(CAMHAL_tudtChannel udtChannelName, boolean bEdgeType, uint16 *pu16EdgeCount);
void CAMHAL_vidTimeoutDetection(void);

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"

#endif /* CAMHAL_API_H */

/*------------------------------ end of file ---------------------------------*/
