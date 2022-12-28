/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_Ident.c                                             */
/* !Description     : KRN Calibration definition                              */
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
 * %PID: P2017_BSW:0A189076.A-SRC;10 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "KRN_Private.h"

#define KRN_START_SEC_KRN_TAILLE_CAL
#include "KRN_MemMap.h"

const uint32 Taille_calib = 0x00CA0384UL;

#define KRN_STOP_SEC_KRN_TAILLE_CAL
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_VER_LDB
#include "KRN_MemMap.h"

/* !Comment: XX_XX_XX#XX                */
const uint32 Version_ldb = 0x9400000B;

#define KRN_STOP_SEC_KRN_VER_LDB
#include "KRN_MemMap.h"


#define KRN_START_SEC_CONST_32BIT
#include "KRN_MemMap.h"

/* !Comment: Start Address of all D sections                                  */
/* const uint32 D_ROM = (uint32)(__sectop("DINITIALIZED_RAM_BEG")); // dbg: to be implmented next */

/* !Comment: Start Address of all R sections                                  */
/* const uint32 D_BGN = (uint32)(__sectop("RINITIALIZED_RAM_BEG")); // dbg*/
/* !Comment: End Address of all R sections                                    */
/* const uint32 D_END = (uint32)(__secend("RINITIALIZED_RAM_END")); // dbg*/

/* !Comment: Start Address of RAM                                             */
/* const uint32 RAM_BGN = 0xFFF80000UL; // dbg*/
/* !Comment: End Address of RAM                                               */
/* const uint32 RAM_END = 0xFFFA0000UL; // dbg*/

/* !Comment: End Address of Stack                                             */
/* const uint32 STACK_BGN = (uint32)(__secend("BSTACK")); // dbg*/
/* !Comment: Start Address of Stack                                           */
/* const uint32 STACK_END = (uint32)(__sectop("BSTACK")); // dbg*/

/* !Comment: Start Address of all uncleared RAM sections                      */
/* const uint32 UNCLEARED_RAM_BGN = (uint32)(__sectop("BUNCLEARED_RAM_BEG")); // dbg*/
/* !Comment: End Address of all uncleared RAM sections                        */
/* const uint32 UNCLEARED_RAM_END = (uint32)(__secend("BUNCLEARED_RAM_END")); // dbg*/

#define KRN_STOP_SEC_CONST_32BIT
#include "KRN_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
