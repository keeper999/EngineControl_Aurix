/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : MCAL                                                    */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : MCAL.h                                                  */
/* !Description     : MCAL APIs                                               */
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
 * %PID: P2017_BSW:0A192486.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MCAL_H 
#define MCAL_H 

/******************************************************************************/
/*                      Includes                                              */
/******************************************************************************/

/* Inclusion of Mcal Library  Files */
#include "Mcal_TcLib.h"
#include "Mcal_WdgLib.h"

/******************************************************************************/
/*                      External Data                                         */
/******************************************************************************/
#define MCAL_START_SEC_VAR_8BIT
#include "MCAL_MemMap.h"

extern volatile uint8  Mcal_u8CpuInitCompletedSem[3];

#define MCAL_STOP_SEC_VAR_8BIT
#include "MCAL_MemMap.h"

/******************************************************************************/
/*                      Global Macro Definitions                              */
/******************************************************************************/

#define MCAL_AURIX_TARGET       (TC29x)
#define MCAL_AURIX_SPEC         (AS40)

typedef unsigned int uint32_t; 


/******************************************************************************/
/*                      APIs used by external components                      */
/******************************************************************************/
#define MCAL_START_SEC_CODE
#include "MCAL_MemMap.h"

void Mcal_EcuMInit(void);
void Mcal_Gnu_CopyTable(uint32 ClearTable, uint32 CopyTable);

#define MCAL_STOP_SEC_CODE
#include "MCAL_MemMap.h"

#endif /* MCAL_H  */

/*-------------------------------- end of file -------------------------------*/
