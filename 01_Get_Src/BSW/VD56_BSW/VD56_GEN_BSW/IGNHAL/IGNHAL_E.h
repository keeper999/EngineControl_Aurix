/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_E.h                                              */
/* !Description     :                                                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:A30384.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IGNHAL_E_H
#define IGNHAL_E_H

#include "IGNHAL.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/



/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/* !Comment: API function declaration                                         */
void IgnHALInit(void);
void IgnHALEnable(void);
void IgnHALDisable(void);
void IgnHALWriteAngle(uint8 u8Channel, uint16 u16Advance);
void IGNHAL_vidWriteEnergy(uint16 u16DesiredCurrent);
void IgnHALWriteDwellTime(uint16 u16DwellTime);
uint16 IgnHALReadDwellTime(uint8 u8Channel);
uint8 IgnHALWriteMode(uint8 u8Mode);
void IgnHALWriteTestTime(uint8 u8Channel, uint32 u32TestTime);
void IgnHALGetAdapValues(uint8 u8Channel, uint16 *pu16Factor, uint16 *pu16Offset);
void IgnHALResetAdapValues(void);
void IGNHAL_vidInhibCoil(uint8 u8Channel);

/* !Comment: External function declaration                                    */
void diagnostic_bobine_a(void);
void diagnostic_bobine_a_c(void);
void diagnostic_bobine_b(void);
void diagnostic_bobine_b_d(void);
void diagnostic_bobine_c(void);
void diagnostic_bobine_d(void);
void IGNHAL_vidAdaptCoilCalc(uint8 u8Coil);
void IGNHAL_vidCoilsDisable(void);
void IGNHAL_vidCoilTdcAdvAvail(void);
void IGNHAL_vidPeriodicIgnVbrf(void);
void it_diag_ccbat_bobine_a(uint16 IrqNotifVal);
void it_diag_ccbat_bobine_b(uint16 IrqNotifVal);
void it_diag_ccbat_bobine_c(uint16 IrqNotifVal);
void it_diag_ccbat_bobine_d(uint16 IrqNotifVal);
void it_bobine_a(uint16 IrqNotifVal);
void it_bobine_b(uint16 IrqNotifVal);
void it_bobine_c(uint16 IrqNotifVal);
void it_dent_ref(void);

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


#endif /* IGNHAL_E_H */

/*-------------------------------- end of file -------------------------------*/
