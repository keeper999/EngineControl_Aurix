/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : DIOHAL                                                                                          */
/* !Description     : Allows access to the logical input/output of the ECU.                                           */
/*                                                                                                                    */
/* !Module          : DIOHAL                                                                                          */
/* !Description     : Digital i/o hardware abstraction layer module.                                                  */
/*                                                                                                                    */
/* !File            : DIOHAL.h                                                                                        */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : ALL                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:DIOHAL H-99053000X4420X112.A-SRC;1.5 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/

#ifndef DIOHAL_H
#define DIOHAL_H

#include "Std_Types.h"
#include "DIOHAL_CFG.h"

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/

#define DIOHAL_START_SEC_CODE
#include "DIOHAL_MemMap.h"

extern void    DIOHAL_vidInit              (void);
extern void    DIOHAL_vidWrite             (uint8 u8Channel, boolean bVal);
extern boolean DIOHAL_bRead                (uint8 u8Channel);
extern boolean DIOHAL_bReadRaw             (uint8 u8Channel);
extern void    DIOHAL_vidMainFunction(void);

#define DIOHAL_STOP_SEC_CODE
#include "DIOHAL_MemMap.h"

#endif /* DIOHAL_H */

/*------------------------------------------------ end of file -------------------------------------------------------*/
