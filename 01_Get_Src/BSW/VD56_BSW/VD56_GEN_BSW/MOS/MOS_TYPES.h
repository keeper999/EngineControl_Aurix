/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS_Types.h                                                                                     */
/* !Description     : Configurations of the HOD component.                                                            */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5012137 01                                                                              */
/* !Reference       : PTS_DOC_5199248 01                                                                              */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MOS TYPES H-99055677X1544X71.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef MOS_TYPES_H
#define MOS_TYPES_H

#include "Std_Types.h"
#include "HOD_TYPES.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !MComment: defines of the mode type                                        */
#define MOS_bfMODE_DIO     0x01
#define MOS_bfMODE_PWM     0x02
#define MOS_bfMODE_CDD     0x04

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* !MComment: Typedef of the functionnal mode of the MOS component. This      */
/* is linked to the above #define                                             */
typedef uint8    MOS_tbfMode;


#endif  /* MOS_TYPES_H */

/*-------------------------------- end of file -------------------------------*/
