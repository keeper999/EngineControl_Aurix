/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_TYP.h                                            */
/* !Description     : Types Definition of the INJHAL Component                */
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
 * %PID: P2017_BSW:A26580.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef INJHAL_TYP_H
#define INJHAL_TYP_H

#include "Std_Types.h"

/******************************************************************************/
/* Function Types                                                             */
/******************************************************************************/
typedef P2FUNC(void, INJHAL_CODE, INJHAL_tpfvidAngleNotifFunction)(uint16 IrqNotifVal);

/******************************************************************************/
/* 8 Bits Based Types                                                         */
/******************************************************************************/
typedef uint8 INJHAL_tenuFGPreInjStatus;
typedef uint8 INJHAL_tbfAngleUpdate;
typedef uint8 INJHAL_tbfTimeUpdate;
typedef uint8 INJHAL_tbfInhibitMask;
typedef uint8 INJHAL_tudtInjectorPhase;

/******************************************************************************/
/* 16 Bits Based Types                                                        */
/******************************************************************************/
typedef uint16 INJHAL_tbfUpdateStatus;
typedef uint16 INJHAL_tbfSeqPreInjStatus;


#endif /* INJHAL_TYP_H */

/*-------------------------------- end of file -------------------------------*/
