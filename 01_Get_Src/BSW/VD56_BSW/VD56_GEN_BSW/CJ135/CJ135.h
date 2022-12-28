/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135.h                                                                                         */
/* !Description     : Public definitions                                                                              */
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
 * %PID: P2017_BSW:0A188658.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef CJ135_H
#define CJ135_H

#include "Std_Types.h"
#include "CJ135_Cfg.h"
#include "CJ135_Types.h"

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"

/*APIs*/
extern void CJ135_vidInit(void);
extern Std_ReturnType CJ135_udtWriteMode(CJ135_tenuChipState udtState);
extern Std_ReturnType CJ135_udtReadMode(CJ135_tenuChipState* pudtState);
extern Std_ReturnType CJ135_udtGetProbeTemp(uint16* pu16RieResistor);
extern Std_ReturnType CJ135_udtGetLambdaInformation(sint16* ps16IpPumpingCurrent);
extern Std_ReturnType CJ135_udtWriteReferenceCurrent(uint8 u8TRIMSQrValue, uint16 u16REFPATValue);
extern Std_ReturnType CJ135_udtWritePumpCurrent(uint8 u8TRIMSQValue);

extern void CJ135_vidMainFunction(void);
extern void CJ135_vidInstanceMainFunction(uint8 u8Instance);
extern void CJ135_vidSpiM_Task(uint8 u8Instance);

#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

#endif /* CJ135_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
