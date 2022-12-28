/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_Typ.h                                            */
/* !Description     : Declaration of types used for CAMHAL Component          */
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
 * %PID: P2017_BSW:A81072.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CAMHAL_TYP_H
#define CAMHAL_TYP_H

#include "Std_Types.h"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* !Comment: Channel reference                                                */
typedef uint8 CAMHAL_tudtChannel;

/* typedef enum
{
   CAMHAL_udtNOT_SET,
   CAMHAL_udtNORMAL_MODE,
   CAMHAL_udtDOWNGRADED_MODE
}
CAMHAL_tenuMode; */

typedef uint8 CAMHAL_tenuMode;

/* typedef enum
{
   CAMHAL_udtUNKNOWN_CYLINDER,
   CAMHAL_udtFIRST_CYLINDER,
   CAMHAL_udtSECOND_CYLINDER,
   CAMHAL_udtTHIRD_CYLINDER,
   CAMHAL_udtFOURTH_CYLINDER
}
CAMHAL_tenuCylinderNumber; */

typedef uint8 CAMHAL_tenuCylinderNumber;

/* typedef enum
{
   CAMHAL_udtPATTERN_DIAG_DISABLED,
   CAMHAL_udtPATTERN_DIAG_NOT_READY,
   CAMHAL_udtPATTERN_DIAG_OK
}
CAMHAL_tenuPatternDiagStatus; */

typedef uint8 CAMHAL_tenuPatternDiagStatus;

/* typedef enum
{
   CAMHAL_udtPATTERN_DETECTED,
   CAMHAL_udtPATTERN_IN_1_PERIOD,
   CAMHAL_udtPATTERN_IN_2_PERIOD,
   CAMHAL_udtPATTERN_NOT_DETECTED
}
CAMHAL_tenuPatternStatus; */

typedef uint8 CAMHAL_tenuPatternStatus;

#endif /* CAMHAL_TYP_H */


/*-------------------------------- end of file -------------------------------*/
