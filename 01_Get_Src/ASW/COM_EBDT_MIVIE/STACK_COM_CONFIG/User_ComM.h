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
/* !File            : User_ComM.h                                             */
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


#ifndef  USER_COMM_H
#define  USER_COMM_H

#include "User_ComM_Type.h"
#include "ComM_Types.h"

/*------------------[declaration of runnable entities]-----------------------*/

#define COMM_START_SEC_CODE
#include "MemMap.h"

extern Std_ReturnType ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode);

extern Std_ReturnType ComM_GetMaxComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode);

extern Std_ReturnType ComM_GetRequestedComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode);

extern Std_ReturnType ComM_GetCurrentComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode);


/*****************************************************************************/

 
extern Std_ReturnType User_Switch_UM000_currentMode(
                                                 User_ModeType_ComMMode ComMode);
 
extern Std_ReturnType User_Switch_UM001_currentMode(
                                                 User_ModeType_ComMMode ComMode);


/*****************************************************************************/



#define COMM_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA S 3453 -- */
#endif /* USER_COMM_H */

