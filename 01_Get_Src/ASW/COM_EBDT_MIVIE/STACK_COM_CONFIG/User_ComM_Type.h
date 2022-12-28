/* PRQA S 8014, 8114, 8314, 8414, 8614 ++*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
    because file names are imposed by AutOSAR requirements */
/* !Deviation: [3453] Violates MISRA rule 93: "A function should be used in
    preference to a function-like macro." but these function-like macros are
    only to abbreviate long function calls to make the code more readable and to
    avoid breaking the 80 characters mark.
*/
/* PRQA S 3453 ++ */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : ComM                                                    */
/* !Description     : Communication Manager Module                            */
/*                                                                            */
/* !Module          : ComM                                                    */
/*                                                                            */
/* !File            : User_ComM_Type.h                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/


#ifndef  USER_COMM_TYPE_H
#define  USER_COMM_TYPE_H

#include "Std_Types.h"


#define USER_MODE_ComMMode_COMM_NO_COMMUNICATION       0
#define USER_MODE_ComMMode_COMM_SILENT_COMMUNICATION   1
#define USER_MODE_ComMMode_COMM_FULL_COMMUNICATION     2

typedef uint8 User_ModeType_ComMMode;

/* PRQA S 3453 -- */
#endif /* USER_COMM_TYPE_H */

