/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RSTSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : RSTSRV_Def.c                                            */
/* !Description     : Data of RSTSRV Component                                */
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
 * %PID: P2017_BSW:0A167416.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "RSTSRV_Typ.h"
#include "RSTSRV.h"
#include "RSTSRV_Private.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define RSTSRV_START_SEC_VAR_CLEARED_16BIT
#include "RSTSRV_MemMap.h"

uint16 RSTSRV_u16HotResetCtr;

#define RSTSRV_STOP_SEC_VAR_CLEARED_16BIT
#include "RSTSRV_MemMap.h"

#define RSTSRV_START_SEC_VAR_CLEARED_BOOLEAN
#include "RSTSRV_MemMap.h"

boolean RSTSRV_bSWResetDetected;

#define RSTSRV_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "RSTSRV_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
