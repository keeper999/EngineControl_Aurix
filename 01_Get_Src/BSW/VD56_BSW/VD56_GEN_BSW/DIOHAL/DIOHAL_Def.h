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
/* !File            : DIOHAL_Def.h                                                                                    */
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
 * %PID: LIBEMB:A737.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/

#ifndef DIOHAL_Def_H
#define DIOHAL_Def_H

#include "DIOHAL.h"
#include "Std_Types.h"
#include "DIOHAL_CFG.h"

/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/

#define DIOHAL_START_SEC_CONST_UNSPECIFIED
#include "DIOHAL_MemMap.h"

/* !Comment: Array of pointer to functions of all defined ReadRaw for ECU pins*/
extern boolean (* const DIOHAL_akpfbReadRaw[DIOHAL_u8READ_TABLE_SIZE])(void);

/* !Comment: Array of pointer to functions of all defined Read for ECU pins   */
extern boolean (* const DIOHAL_akpfbRead[DIOHAL_u8READ_TABLE_SIZE])(void);

/* !Comment: Array of pointer to functions of all defined Write for ECU pins  */
extern void (* const DIOHAL_akpfvidWrite[DIOHAL_u8WRITE_TABLE_SIZE])(boolean);

#define DIOHAL_STOP_SEC_CONST_UNSPECIFIED
#include "DIOHAL_MemMap.h"

#define DIOHAL_START_SEC_VAR_16BIT
#include "DIOHAL_MemMap.h"

/* !Comment: Array of the high frequency filter samples.                      */
extern uint16 DIOHAL_au16HighFreqFilterTable[DIOHAL_u8FILTERED_PORTS_NBR]
                                            [DIOHAL_u8LOW_FREQ_SAMPLE_NBR];

/* !Comment: Array of the low frequency filter samples.                       */
extern uint16 DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTERED_PORTS_NBR];


#define DIOHAL_STOP_SEC_VAR_16BIT
#include "DIOHAL_MemMap.h"

#define DIOHAL_START_SEC_VAR_8BIT
#include "DIOHAL_MemMap.h"

/* !Comment: The index of the next low frequency sample                       */
extern uint8  DIOHAL_u8LowFreqSampleIndex;

#define DIOHAL_STOP_SEC_VAR_8BIT
#include "DIOHAL_MemMap.h"

#endif /* DIOHAL_Def_H */

/*-------------------------------------------------- end of file -----------------------------------------------------*/
