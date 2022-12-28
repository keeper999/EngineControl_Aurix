/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL_Typ.h                                            */
/* !Description     : Declaration of new types for CRKHAL Component           */
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
 * %PID: P2017_BSW:A18516.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CRKHAL_TYP_H
#define CRKHAL_TYP_H

#include "Std_Types.h"

/******************************************************************************/
/* DATA TYPES DEFINITIONS                                                     */
/******************************************************************************/

/* typedef enum
{
   CRKHAL_udtNOT_SET,
   CRKHAL_udtNORMAL_MODE,
   CRKHAL_udtDOWNGRADED_MODE
}
CRKHAL_tenuMode; */

typedef uint8 CRKHAL_tenuMode;

/* typedef enum
{
   CRKHAL_udtUNKNOWN_CYLINDER,
   CRKHAL_udtFIRST_CYLINDER,
   CRKHAL_udtSECOND_CYLINDER,
   CRKHAL_udtTHIRD_CYLINDER,
   CRKHAL_udtFOURTH_CYLINDER
}
CRKHAL_tenuCylinderNumber; */

typedef uint8 CRKHAL_tenuCylinderNumber;

/* typedef enum
{
   CRKHAL_udtNO_EDGE = 0,
   CRKHAL_udtFALLING_EDGE = 2,
   CRKHAL_udtRISING_EDGE = 1,
   CRKHAL_udtBOTH_EDGES = 3
}
CRKHAL_tenuEdgeTypeDetection; */

typedef uint8 CRKHAL_tenuEdgeTypeDetection;


#endif /* CRKHAL_TYP_H */

/*------------------------------ end of file ---------------------------------*/

