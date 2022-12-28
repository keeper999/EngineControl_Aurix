/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_I.h                                              */
/* !Description     : DEVHAL Internal                                         */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef DEVHAL_I_H
#define DEVHAL_I_H

#include "Std_Types.h"
#include "DEVHAL_Cfg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define DEVHAL_u32SIZE_OF_CALIB        (DEVHAL_u32CALIB_END_ADDRESS - DEVHAL_u32CALIB_START_ADDRESS)

#define DEVHAL_u32REDIRECT_TO_LMU       0x6u   /* For LMU   */
#define DEVHAL_u32REDIRECT_TO_ED_MEM    0x7u   /* For EDMEM */

/* !Comment: Mask of Available size of blocks managed by the Aurix            */
#define DEVHAL_u32BLOCK_SIZE_MASK_32B   0x00000FFFUL
#define DEVHAL_u32BLOCK_SIZE_MASK_64B   0x00000FFEUL
#define DEVHAL_u32BLOCK_SIZE_MASK_128B  0x00000FFCUL
#define DEVHAL_u32BLOCK_SIZE_MASK_256B  0x00000FF8UL
#define DEVHAL_u32BLOCK_SIZE_MASK_512B  0x00000FF0UL
#define DEVHAL_u32BLOCK_SIZE_MASK_1KB   0x00000FE0UL
#define DEVHAL_u32BLOCK_SIZE_MASK_2KB   0x00000FC0UL
#define DEVHAL_u32BLOCK_SIZE_MASK_4KB   0x00000F80UL
#define DEVHAL_u32BLOCK_SIZE_MASK_8KB   0x00000F00UL
#define DEVHAL_u32BLOCK_SIZE_MASK_16KB  0x00000E00UL
#define DEVHAL_u32BLOCK_SIZE_MASK_32KB  0x00000C00UL
#define DEVHAL_u32BLOCK_SIZE_MASK_64KB  0x00000800UL
#define DEVHAL_u32BLOCK_SIZE_MASK_128KB 0x00000000UL

/* !Comment: Available size of blocks managed by the Aurix                   */
#define DEVHAL_u32BLOCK_SIZE_32B        0x00000020UL
#define DEVHAL_u32BLOCK_SIZE_64B        0x00000040UL
#define DEVHAL_u32BLOCK_SIZE_128B       0x00000080UL
#define DEVHAL_u32BLOCK_SIZE_256B       0x00000100UL
#define DEVHAL_u32BLOCK_SIZE_512B       0x00000200UL
#define DEVHAL_u32BLOCK_SIZE_1KB        0x00000400UL
#define DEVHAL_u32BLOCK_SIZE_2KB        0x00000800UL
#define DEVHAL_u32BLOCK_SIZE_4KB        0x00001000UL
#define DEVHAL_u32BLOCK_SIZE_8KB        0x00002000UL
#define DEVHAL_u32BLOCK_SIZE_16KB       0x00004000UL
#define DEVHAL_u32BLOCK_SIZE_32KB       0x00008000UL
#define DEVHAL_u32BLOCK_SIZE_64KB       0x00010000UL
#define DEVHAL_u32BLOCK_SIZE_128KB      0x00020000UL

/******************************************************************************/
/* !Comment: Maximal Number of Blocks Used                                    */
/*                                                                            */
/******************************************************************************/
#define DEVHAL_u16NB_BLOCKS \
   ( (DEVHAL_u32CALIB_END_ADDRESS - DEVHAL_u32CALIB_START_ADDRESS) \
   / DEVHAL_u32GET_BLOCK_SIZE(DEVHAL_snDESIRED_BLOCK_SIZE))

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : DEVHAL_u32GET_BLOCK_SIZE_MASK                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define DEVHAL_u32GET_BLOCK_SIZE_MASK(snSize) \
   M1_DEVHAL_u32GET_BLOCK_SIZE_MASK(snSize)

   #define M1_DEVHAL_u32GET_BLOCK_SIZE_MASK(snSize) \
      DEVHAL_u32BLOCK_SIZE_MASK_##snSize

/******************************************************************************/
/* !FuncName    : DEVHAL_u32GET_BLOCK_SIZE                                    */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define DEVHAL_u32GET_BLOCK_SIZE(snSize) \
   M1_DEVHAL_u32GET_BLOCK_SIZE(snSize)

   #define M1_DEVHAL_u32GET_BLOCK_SIZE(snSize) \
      DEVHAL_u32BLOCK_SIZE_##snSize

/******************************************************************************/
/* !FuncName    : DEVHAL_u32GET_REDIRECT_MEMORY                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define DEVHAL_u32GET_REDIRECT_MEMORY(snMemory) \
   M1_DEVHAL_u32GET_REDIRECT_MEMORY(snMemory)

   #define M1_DEVHAL_u32GET_REDIRECT_MEMORY(snMemory) \
      DEVHAL_u32REDIRECT_TO_##snMemory


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define DEVHAL_START_SEC_CODE
#include "DEVHAL_MemMap.h"

void DEVHAL_vidCopyCalibToERAM(void);
void DEVHAL_vidInitEmuCalib(void);
void DEVHAL_vidTrapDevaidPowerDown(uint8 u8Arg);
void DEVHAL_vidUnlockEMEM(void);

#define DEVHAL_STOP_SEC_CODE
#include "DEVHAL_MemMap.h"


#endif /* DEVHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
