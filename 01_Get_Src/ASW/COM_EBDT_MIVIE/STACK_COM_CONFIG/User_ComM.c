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
/* !File            : User_ComM.c                                             */
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


#include "User_ComM.h"


#define COMM_START_SEC_CODE
#include "MemMap.h"

 
Std_ReturnType User_Switch_UM000_currentMode(
                                                 User_ModeType_ComMMode ComMode){
return E_OK; 
}
 
Std_ReturnType User_Switch_UM001_currentMode(
                                                 User_ModeType_ComMMode ComMode){
return E_OK; 
}


/*****************************************************************************/



#define COMM_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA S 3453 -- */

