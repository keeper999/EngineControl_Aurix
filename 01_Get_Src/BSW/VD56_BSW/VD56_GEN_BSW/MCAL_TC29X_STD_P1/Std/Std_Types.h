/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Std_Types.h                                                   **
**                                                                            **
**  VERSION   : 2.5.3                                                         **
**                                                                            **
**  DATE      : 07.06.2012                                                    **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : TASKING                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION: Provision of Standard Types                                  **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :  Standard Types SWS AS4.0                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** fer          Robert Feist               BMW Group                          **
** cma          Christoph Mueller-Albrecht BMW Group                          **
** Ravi         Ravikumar Shirakanahalli   Infineon                           **
** VS           Vinod Shankar              Infineon                           **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.5.3:  07.06.2012, VS    : UTP AI00064249 fixed. Instance Id removed
 * V2.5.2:  27.08.2010, Ravi  : Updated to conform with Misra2004, added suffix
 *                              U to the numbers defined
 * V2.5.1:  21.04.2006, cma  : bug in declaration of Std_VersionInfoType fixed
 *                             (bug taken over from SWS!
 *                              We tried to be as close to the spec as possible)
 * V2.5.0:  21.04.2006, cma  : type Std_VersionInfoType added
 * V2.4.0:  23.01.2006, cma  : symbols ON, OFF added according to AUTOSAR SWS
 * V2.3.1:  03.07.2005, cma  : comment in file header updated:
                               SWS Standard Types V1.0.0 (final)
 * V2.3.0:  04.05.2005, cma  : Defines STD_ACTIVE and STD_IDLE added
 * V2.2.0:  15.04.2005, fer  : Defines STD_HIGH and STD_LOW added;
                               Defines TRUE and FALSE moved to Platform_Types.h
 * V2.1.0:  16.03.2005, fer  : Defines TRUE and FALSE added;
 * V2.0.0:  09.03.2005, cma  : TRUE, FALSE, ON, OFF, NULL removed;
 * V1.0.0:  10.08.2004, fer  : initial version
 */

#ifndef STD_TYPES_H 
#define STD_TYPES_H 

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#define VALEO_PATCH_MCAL_STD_INCLUDE_ORDER_FOR_QAC

#ifdef VALEO_PATCH_MCAL_STD_INCLUDE_ORDER_FOR_QAC
#include "Platform_Types.h"             /* platform specific type definitions */
#include "Compiler.h"                   /* mapping compiler specific keywords */
#else
#include "Compiler.h"                   /* mapping compiler specific keywords */
#include "Platform_Types.h"             /* platform specific type definitions */
#endif /* VALEO_PATCH_MCAL_STD_INCLUDE_ORDER_FOR_QAC */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*
  File version information
*/
#define STD_MAJOR_VERSION  2U
#define STD_MINOR_VERSION  5U
#define STD_PATCH_VERSION  0U


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* for OSEK compliance this typedef has been added */
#ifndef STATUSTYPEDEFINED 
  #define STATUSTYPEDEFINED 

  typedef unsigned char StatusType; 
  #define E_OK      0U

#endif

/*
  The Std_ReturnType (STD005) may be used with the following values (STD011):
  E_OK:     0
  E_NOT_OK: 1
*/
typedef uint8 Std_ReturnType;
#define E_NOT_OK    1U

typedef struct
{
   uint16 vendorID;
   uint16  moduleID;
   uint8  sw_major_version;
   uint8  sw_minor_version;
   uint8  sw_patch_version;
} Std_VersionInfoType; /* STD015                                */


#define STD_HIGH    1U  /* Physical state 5V or 3.3V             */
#define STD_LOW     0U  /* Physical state 0V                     */

#define STD_ACTIVE  1U  /* Logical state active                  */
#define STD_IDLE    0U  /* Logical state idle                    */

#ifndef ON             /* avoid clash with existing definitions */
   #define ON       1U
#endif

#ifndef OFF            /* avoid clash with existing definitions */
   #define OFF      0U
#endif

#ifndef STD_ON             /* avoid clash with existing definitions */
   #define STD_ON       1U
#endif

#ifndef STD_OFF            /* avoid clash with existing definitions */
   #define STD_OFF      0U
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* nothing to fill in here */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/* nothing to fill in here */

#endif  /* STD_TYPES_H */
