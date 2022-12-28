/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : TDCHAL Component                                        */
/*                                                                            */
/* !File            : TDCHAL_E.h                                              */
/* !Description     : Backward compatibility layer.                           */
/*                                                                            */
/* !Reference       : PTS DOC 5038320                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A272.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef TDCHAL_E_H
#define TDCHAL_E_H

#include "Std_Types.h"
#include "TDCHAL_Cfg.h"
#include "TDCHAL_l.h"
#include "TDCHAL.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !Description : Returns TDC offset for based on number of cylinders.        */
#define TDCHAL_u16TDC_OFFSET \
   ( (TDCHAL_ku8NumberOfCylinders != 0) \
   ? (uint16) (TDCHAL_u16ENGINE_CYCLE / TDCHAL_ku8NumberOfCylinders) \
   : (uint16) UINT16_MAX)


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : TDCHAL_udtReadCounter                                       */
/* !Description : Read TDC counter. (backward compatibility)                  */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_udtReadCounter(pu8Counter) \
   TDCHAL_udtGetCounter(pu8Counter)

/******************************************************************************/
/* !FuncName    : TDCHAL_udtReadPeriod                                        */
/* !Description : Read TDC Period. (backward compatibility)                   */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_udtReadPeriod(pu32Period) \
   TDCHAL_udtGetPeriod(pu32Period)

/******************************************************************************/
/* !FuncName    : TDCHAL_udtReadRawCounter                                    */
/* !Description : Read raw counter. (backward compatibility)                  */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_udtReadRawCounter(pu8Counter) \
   TDCHAL_udtGetCounter(pu8Counter)


#endif /* TDCHAL_E_H */

/*-------------------------------- end of file -------------------------------*/
