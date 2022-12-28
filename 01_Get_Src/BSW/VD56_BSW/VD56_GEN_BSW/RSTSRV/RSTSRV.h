/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RSTSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : RSTSRV.h                                                */
/* !Description     : Public declaration of RSTSRV Component                  */
/*                                                                            */
/* !Reference       : V03 NT 07 02929                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A167417.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RSTSRV_H
#define RSTSRV_H

#include "Std_Types.h"
#include "RSTSRV_Typ.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define RSTSRV_udtNORMAL_STARTUP_RESET    1
#define RSTSRV_udtSOFTWARE_RESET          2
#define RSTSRV_udtHARDWARE_RESET          4


/******************************************************************************/
/* DATA DECLARATIONS                                                          */
/******************************************************************************/

#define RSTSRV_START_SEC_VAR_CLEARED_16BIT
#include "RSTSRV_MemMap.h"

extern uint16 RSTSRV_u16HotResetCtr;

#define RSTSRV_STOP_SEC_VAR_CLEARED_16BIT
#include "RSTSRV_MemMap.h"


/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

#define RSTSRV_START_SEC_CONST_16BIT
#include "RSTSRV_MemMap.h"

extern const uint16 RSTSRV_ku16HotResetCtr;

#define RSTSRV_STOP_SEC_CONST_16BIT
#include "RSTSRV_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define RSTSRV_START_SEC_CODE
#include "RSTSRV_MemMap.h"

extern void RSTSRV_vidInitEntry(void);
extern void RSTSRV_vidPerformReset(RSTSRV_tudtResetType udtRequestedResetType);
extern void RSTSRV_vidPowerDownEntry(void);
extern void RSTSRV_vidPowerOnResetEntry(RSTSRV_tudtResetType udtResetType);
extern RSTSRV_tudtResetType RSTSRV_udtReadResetState(void);

#define RSTSRV_STOP_SEC_CODE
#include "RSTSRV_MemMap.h"

#endif /* RSTSRV_H */

/*-------------------------------- end of file -------------------------------*/
