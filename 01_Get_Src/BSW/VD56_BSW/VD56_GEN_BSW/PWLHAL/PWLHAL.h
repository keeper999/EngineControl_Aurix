/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL.h                                                */
/* !Description     : APIs declaration of PWLHAL Component                    */
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
 * %PID: P2017_BSW:A11983.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PWLHAL_H
#define PWLHAL_H

#include "Std_Types.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PWLHAL_START_SEC_CODE
#include "PWLHAL_MemMap.h"

extern void    PWLHAL_vidInit(void);
extern void    PWLHAL_vidWriteMainRlyState(boolean bValue);
extern boolean PWLHAL_bReadRawMainRlyState(void);
extern void    PWLHAL_vidReadKeyDiagMainRly(void);
extern void    PWLHAL_vidDiagMainRly(void);

#define PWLHAL_STOP_SEC_CODE
#include "PWLHAL_MemMap.h"


#endif /* PWLHAL_H */

/*------------------------------- end of file --------------------------------*/
