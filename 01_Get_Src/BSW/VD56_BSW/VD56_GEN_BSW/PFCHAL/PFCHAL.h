/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PFCHAL                                                  */
/* !Description     : PFCHAL Component                                        */
/*                                                                            */
/* !File            : PFCHAL.h                                                */
/* !Description     : PFCHAL Component                                        */
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
 * %PID: P2017_BSW:0A111554.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PFCHAL_H
#define PFCHAL_H

#include "Std_Types.h"
#include "PFCHAL_Cfg_I.h"
#include "PFCHAL_Cfg_E.h"

/******************************************************************************/
/* GLOBAL FUNCTION DECLARATION                                                */
/******************************************************************************/

#define PFCHAL_START_SEC_CODE
#include "PFCHAL_MemMap.h"

void PFCHAL_vidInit(void);
void PFCHAL_vidEnable(void);
void PFCHAL_vidDioEnable(uint8 u8Channel);
void PFCHAL_vidPwmEnable(uint8 u8Channel);

#define PFCHAL_STOP_SEC_CODE
#include "PFCHAL_MemMap.h"


#endif /* PFCHAL_H */

/*-------------------------------- end of file -------------------------------*/
