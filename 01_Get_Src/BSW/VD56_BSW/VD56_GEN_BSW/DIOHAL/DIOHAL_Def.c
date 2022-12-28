/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : DIOHAL                                                                                          */
/* !Description     : Allows access to the logical input/output of the ECU.                                           */
/*                                                                                                                    */
/* !Module          : DIOHAL_DEF                                                                                      */
/* !Description     : DIOHAL definition code                                                                          */
/*                                                                                                                    */
/* !File            : DIOHAL_Def.c                                                                                    */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : ALL                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:DIOHAL DEF C-99052999X4420X100.A-SRC;1.7 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/
#include "DIOHAL_Def.h"

/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* PrivateComponent variables                                                                                         */
/**********************************************************************************************************************/

#define DIOHAL_START_SEC_VAR_16BIT
#include "DIOHAL_MemMap.h"

/* !Comment: Array of the high frequency filter samples.                      */
uint16 DIOHAL_au16HighFreqFilterTable[DIOHAL_u8FILTERED_PORTS_NBR]
                                     [DIOHAL_u8LOW_FREQ_SAMPLE_NBR];

/* !Comment: Array of the low frequency filter samples.                       */
uint16 DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTERED_PORTS_NBR];

#define DIOHAL_STOP_SEC_VAR_16BIT
#include "DIOHAL_MemMap.h"

#define DIOHAL_START_SEC_VAR_8BIT
#include "DIOHAL_MemMap.h"

/* !Comment: The index of the next low frequency sample                       */
uint8  DIOHAL_u8LowFreqSampleIndex;

#define DIOHAL_STOP_SEC_VAR_8BIT
#include "DIOHAL_MemMap.h"


/*-------------------------------------------------- end of file -----------------------------------------------------*/
