/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_Typ.h                                            */
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
 * %PID: P2017_BSW:A30381.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IGNHAL_TYP_H
#define IGNHAL_TYP_H

#include "Std_Types.h"

/******************************************************************************/
/* TYPE DECLARATION                                                           */
/******************************************************************************/

typedef void (* const IGNHAL_takpfCoilConductProg) (uint16 u16Start);
typedef uint16 (* const IGNHAL_takpfReadStartCounter) (void);
typedef void (* const IGNHAL_takpfCoilImmediateTrig) (void);

#endif /* IGNHAL_TYP_H */


/*-------------------------------- end of file -------------------------------*/
