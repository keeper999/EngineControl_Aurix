/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PTMHAL                                                  */
/* !Description     : PTMHAL Component                                        */
/*                                                                            */
/* !File            : PTMHAL_E.h                                              */
/* !Description     : Backward compatibility layer.                           */
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
 * %PID: P2017_BSW:0A149681.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PTMHAL_E_H
#define PTMHAL_E_H

#include "Std_Types.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define PTMHAL_u8PTMHAL_EVT_CALL          0    /* 0x00 */
#define PTMHAL_u8TDC_CALL                 1    /* 0x01 */


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PTMHAL_START_SEC_CODE
#include "PTMHAL_MemMap.h"

void PTMHAL_vidInit(void);
Std_ReturnType PTMHAL_udtEnable(void);
Std_ReturnType PTMHAL_udtDisable(void);
uint8 PTMHAL_u8GetAllPacksDuration(uint8 u8MaxTableSize, uint32 *pau32PacksDurationTable);
Std_ReturnType PTMHAL_udtGetFirstPackDuration(uint32 *pu32FirstPackDuration);

void PTMHAL_vidPacksDurationCalc(uint8 u8CallingConditions);
void PTMHAL_vidAlarmManagement(void);

#define PTMHAL_STOP_SEC_CODE
#include "PTMHAL_MemMap.h"


#endif /* PTMHAL_E_H */

/*-------------------------------- end of file -------------------------------*/
