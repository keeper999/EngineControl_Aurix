/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_Cfg.h                                            */
/* !Description     : DEVHAL configuration                                    */
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

#ifndef DEVHAL_CFG_H
#define DEVHAL_CFG_H

#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* !Comment: Calibration Area Addresses                                       */
/*           DEVHAL_u32CALIB_START_ADDRESS < DEVHAL_u32CALIB_END_ADDRESS      */
/******************************************************************************/
#define DEVHAL_u32CALIB_START_ADDRESS    0xA0040000UL
#define DEVHAL_u32CALIB_END_ADDRESS      0xA00C0000UL

/******************************************************************************/
/* !Comment: Desired Size of Each Calibration Block                           */
/* !Range  : 32B, 64B, 128B, 256B, 512B, 1KB, 2KB, 4KB, 8KB, 16KB, 32KB,      */
/*           64KB, 128KB                                                      */
/******************************************************************************/
#define DEVHAL_snDESIRED_BLOCK_SIZE      128KB

/******************************************************************************/
/* !Comment: OVERLAY RAM Selection                                            */
/* !Range  : ED_MEM, LMU                                                      */
/******************************************************************************/
#define DEVHAL_snREDIRECTION_AREA        ED_MEM
                                                                      
/******************************************************************************/
/* !Comment: OVERLAY RAM Start/End Addresses                                  */
/*           DEVHAL_OVERLAY_RAM_START_ADDRESS < DEVHAL_OVERLAY_RAM_END_ADDRESS*/
/******************************************************************************/
#define DEVHAL_OVERLAY_RAM_START_ADDRESS 0xBF000000UL
#define DEVHAL_OVERLAY_RAM_END_ADDRESS   0xBF100000UL


/* Start adress of EMEM */
#define DEVHAL_u32EMEM_START_ADDR         DEVHAL_OVERLAY_RAM_START_ADDRESS

/* Start Address of first logical sector inside same physical sub-sector PSx  */
#define DEVHAL_u32CALIB_START_ADDR_PS0    DEVHAL_u32CALIB_START_ADDRESS
#define DEVHAL_u32CALIB_START_ADDR_PS1    0xA0080000UL
#define DEVHAL_u32CALIB_START_ADDR_PS2    0xA0100000UL
#define DEVHAL_u32CALIB_START_ADDR_PS3    0xA0180000UL

/* Number of consecutive logical sectors inside same physical sub-sector PSx  */
#define DEVHAL_u32NUM_OF_LOGICAL_SECT_PS0 6U
#define DEVHAL_u32NUM_OF_LOGICAL_SECT_PS1 3U
#define DEVHAL_u32NUM_OF_LOGICAL_SECT_PS2 0U
#define DEVHAL_u32NUM_OF_LOGICAL_SECT_PS3 0U


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define DEVHAL_START_SEC_CODE
#include "DEVHAL_MemMap.h"

/* !Comment : This function returns ECU state for devaid reprog authorization */
extern boolean DEVHAL_bCheckReprogCond(void);

/* !Comment : This function returns the DEVAID protection state               */
extern boolean DEVHAL_bWaitProtectionCond(void);

#define DEVHAL_STOP_SEC_CODE
#include "DEVHAL_MemMap.h"

#endif /* DEVHAL_CFG_H   */

/*-------------------------------- end of file -------------------------------*/
