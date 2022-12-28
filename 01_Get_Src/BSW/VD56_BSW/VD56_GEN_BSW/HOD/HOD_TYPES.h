/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : HOD                                                                                             */
/* !Description     : HOD Configuration                                                                               */
/*                                                                                                                    */
/* !File            : HOD_Types.h                                                                                     */
/* !Description     : Types used by HOD components                                                                    */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5199248                                                                                 */
/*                                                                                                                    */
/* Coding language  : c                                                                                             */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:HOD TYPES H-99053757X5000X848.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef HOD_TYPES_H
#define HOD_TYPES_H

#include "Std_Types.h"
#include "HOD_Cfg.h"


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* !Trace_To: VEMS_R_07_01216_038.01 */

typedef enum
{
   HOD_MODE_DIO,
   HOD_MODE_PWM,
   HOD_MODE_CDD
} HOD_tenuMode;

typedef enum
{
   HOD_CUT_OFF_WITHOUT_FAULT,
   HOD_CUT_OFF_WITH_DESTRUCTIVE_FAULT
} HOD_tenuCutMode;

#endif  /* HOD_TYPES_H */

/*------------------------------------------------ end of file -------------------------------------------------------*/
