/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Crc.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\36 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-02 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of CRC driver.            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*  TRACEABILITY : [cover parentID=SAS_AS_CRC022,SAS_AS_CRC024,AUTOSAR:12911,
                    AUTOSAR:12913,AUTOSAR:12916,
                    ASW:1530,ASW:1499,ASW:1802,ASW:1442,ASW:1546]
                    [/cover]                                                 */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

  /* Inclusion of  Mcal header file */
  #include "Mcal.h"
  /* Inclusion of controller sfr file */
  #include "IfxFce_reg.h"
  /* Inclusion of Crc.h file*/
  #include "Crc_.h"
  /* Inclusion of Safety Error Report file */  
  #if (CRC_SAFETY_ENABLE == STD_ON)
  #include "SafetyReport.h"
  #endif

/* CRC Header File Version Check */

/* AUTOSAR Secification File Version Check */
  #ifndef CRC_AR_MAJOR_VERSION
    #error "CRC_AR_MAJOR_VERSION is not defined. "
  #endif /*#endif for #ifndef CRC_AR_MAJOR_VERSION */

  #ifndef CRC_AR_MINOR_VERSION
    #error "CRC_AR_MINOR_VERSION is not defined. "
  #endif /*#endif for #ifndef CRC_AR_MINOR_VERSION */

   #ifndef CRC_AR_PATCH_VERSION
    #error "CRC_AR_PATCH_VERSION is not defined. "
  #endif /*#endif for #ifndef CRC_AR_PATCH_VERSION */

  #ifndef CRC_SW_MAJOR_VERSION
    #error "CRC_SW_MAJOR_VERSION is not defined. "
  #endif /*#endif for #ifndef CRC_SW_MAJOR_VERSION */

  #ifndef CRC_SW_MINOR_VERSION
    #error "CRC_SW_MINOR_VERSION is not defined. "
  #endif /*#endif for #ifndef CRC_SW_MINOR_VERSION */

  #if ( CRC_AR_MAJOR_VERSION != 4U)
    #error "CRC_AR_MAJOR_VERSION does not match. "
  #endif

  #if ( CRC_AR_MINOR_VERSION != 0U )
    #error "CRC_AR_MINOR_VERSION does not match. "
  #endif

  #ifndef CRC_SW_PATCH_VERSION
    #error "CRC_SW_PATCH_VERSION is not defined. "
  #endif /*#endif for #ifndef CRC_SW_PATCH_VERSION */

  #if (CRC_SW_MAJOR_VERSION != 3U)
    #error "CRC_SW_MAJOR_VERSION does not match. "
  #endif /*#endif for  #if (CRC_SW_MAJOR_VERSION != 0U)*/

  #if (CRC_SW_MINOR_VERSION != 0U)
    #error "CRC_SW_MINOR_VERSION does not match. "
  #endif /*#endif for  #if (CRC_SW_MINOR_VERSION != 0U)*/



/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
 /*macros */
  #define CRC_ZERO_U (0U)
  #define CRC_ONE_U (1U)
  #define CRC_TWO_U (2U)
  #define CRC_THREE_U (3U)  
  #define CRC_FOUR_U (4U)
  #define CRC_EIGHT_U (8U)
  
 /*macros for shifting the data */ 
  #define CRC_SHIFT_ONE (1U)                   
  #define CRC_SHIFT_EIGHT (8U)                 
  #define CRC_SHIFT_SIXTEEN (16U)               
  #define CRC_SHIFT_TWENTYFOUR (24U) 
  #define CRC_TABLE_LENGTH 256



/*Macros for XOR values*/
  #define CRC_CRC8_XOR_VALUE  0xFFU
  #define CRC_CRC8H2F_XOR_VALUE 0xFFU
  #define CRC_CRC16_XOR_VALUE 0x0000U
  #define CRC_CRC32_XOR_VALUE 0xFFFFFFFFU

/*Macros for CRC sizes*/
  #define CRC_CRC8_SIZE (CRC_EIGHT_U *(sizeof(uint8)))
  #define CRC_CRC8_MSB ((uint8)((uint8)CRC_ONE_U << \
                            (uint8)(CRC_CRC8_SIZE - CRC_ONE_U)))

  #define CRC_CRC16_SIZE (CRC_EIGHT_U *(sizeof(uint16))) 
  #define CRC_CRC16_MSB ((uint16)((uint16)CRC_ONE_U << \
                            (uint16)(CRC_CRC16_SIZE - CRC_ONE_U)))

  #define CRC_CRC32_SIZE (CRC_EIGHT_U *(sizeof(uint32))) 
  #define CRC_CRC32_MSB ((uint32)((uint32)CRC_ONE_U << \
                             (uint32)(CRC_CRC32_SIZE - CRC_ONE_U)))

/*Crc polynomials*/
  #define CRC_CRC8_POLYNOMIAL (0x1DU)
  #define CRC_CRC16_POLYNOMIAL (0x1021U)
  #define CRC_CRC8H2F_POLYNOMIAL (0x2FU)
  #define CRC_CRC32_POLYNOMIAL (0x04C11DB7U)


  
   /*macros for initial  */
  #define CRC_INIT_VAL (0U)
  #define CRC_LOOPCNT_MSGBYTE_INIT_VAL (0U)
  #define CRC_LOOPCNT_MSGBIT_INIT_VAL (8U)
  
  #define CRC_BITCNT_EIGHT (8U)                  
  #define CRC_BITCNT_THIRTYTWO (32U) 
  
  #define CRC_ONEBYTEAND_VAL 0xFFU
  
                       
  
  
  #if (defined CRC_8_MODE)  && (CRC_8_MODE == CRC_RUNTIME_MODE)
    #define CRC_8_RUNTIME_MODE
  #endif
  
  #if (defined  CRC_8H2F_MODE)  && (CRC_8H2F_MODE == CRC_RUNTIME_MODE)
    #define CRC_8H2F_RUNTIME_MODE
  #endif
  
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
  #ifdef CRC_32_MODE
    #if  CRC_32_MODE == CRC_HARDWARE_MODE 
       static uint32 Crc_lCalculateCRC32Hardware( const uint8* Crc_DataPtr,
       uint32 Crc_Length, uint32 Crc_StartValue32,boolean Crc_IsFirstCall);
    #endif
 
    #if  CRC_32_MODE == CRC_TABLE_MODE 
      static uint32 Crc_lCalculateCRC32Table( const uint8* Crc_DataPtr, 
      uint32 Crc_Length,uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
    #endif
 
    #if  CRC_32_MODE == CRC_RUNTIME_MODE 
      static uint32 Crc_lCalculateCRC32Runtime( const uint8* Crc_DataPtr, 
      uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
    #endif
 
   
    static uint32 Crc_lReflectCRC32(uint32 CRCData_32bit, uint8 CRC_BitCount);
    
  #endif 

  #ifdef CRC_16_MODE
    #if  CRC_16_MODE == CRC_HARDWARE_MODE 
      static uint16 Crc_lCalculateCRC16Hardware( const uint8* Crc_DataPtr, 
      uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
    #endif
 
    #if  CRC_16_MODE == CRC_TABLE_MODE 
      static uint16 Crc_lCalculateCRC16Table( const uint8* Crc_DataPtr, 
      uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
    #endif
  
    #if  CRC_16_MODE == CRC_RUNTIME_MODE 
      static uint16 Crc_lCalculateCRC16Runtime(   const uint8* Crc_DataPtr,
      uint32 Crc_Length,  uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
    #endif
  #endif
  
  #ifdef CRC_8H2F_MODE
    #if  CRC_8H2F_MODE == CRC_TABLE_MODE 
      static uint8 Crc_lCalculateCRC8H2FTable( const uint8* Crc_DataPtr, 
      uint32 Crc_Length, uint8 Crc_StartValue8H2F,   boolean Crc_IsFirstCall);
    #endif
  
    #if  CRC_8H2F_MODE == CRC_RUNTIME_MODE 
      static uint8 Crc_lCalculateCRC8H2FRuntime( const uint8* Crc_DataPtr, 
      uint32 Crc_Length, uint8 Crc_StartValue8H2F,   boolean Crc_IsFirstCall);
    #endif
  #endif
  
  #ifdef CRC_8_MODE
    #if  CRC_8_MODE == CRC_HARDWARE_MODE 
      static uint8 Crc_lCalculateCRC8Hardware(const uint8* Crc_DataPtr, 
      uint32 Crc_Length,  uint8 Crc_StartValue8,   boolean Crc_IsFirstCall);
    #endif
    #if  CRC_8_MODE == CRC_TABLE_MODE 
      static uint8 Crc_lCalculateCRC8Table( const uint8* Crc_DataPtr, 
      uint32 Crc_Length,  uint8 Crc_StartValue8, boolean Crc_IsFirstCall);
    #endif
    #if  CRC_8_MODE == CRC_RUNTIME_MODE 
      static uint8 Crc_lCalculateCRC8Runtime(    const uint8* Crc_DataPtr, 
      uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall);
    #endif
    #if defined  (CRC_8_RUNTIME_MODE)  || defined (CRC_8H2F_RUNTIME_MODE)
     static uint8 Crc_lCommonCalculateCRCRuntime( const uint8* Crc_DataPtr,
     uint32 Crc_Length,   uint8 Crc_StartValue8, uint8 Polynomial_8bit);
    #endif
  #endif

 #if (CRC_SAFETY_ENABLE == STD_ON) 
/* Common service to check the Safety check for Crc_calculation API's */
static uint8 Crc_lCrcCalculationSafetyCheck
(
  const uint8* Crc_DataPtr,
  boolean Crc_IsFirstCall,
  uint32 Crc_Length,
  uint8 ServiceId 
);
#endif /*  #if (CRC_SAFETY_ENABLE == STD_ON) */


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*Crc 32bit polynomial=0x04C11DB7 table initialization*/
  #ifdef CRC_32_MODE 
    #if CRC_32_MODE == CRC_TABLE_MODE
    #define CRC_START_SEC_CONST_32BIT
    #include "MemMap.h"
    static const uint32 Crc_Table32[CRC_TABLE_LENGTH]=
    {
       0x00000000UL,   0x04c11db7UL,   0x09823b6eUL,   0x0d4326d9UL,
       0x130476dcUL,   0x17c56b6bUL,   0x1a864db2UL,   0x1e475005UL,
       0x2608edb8UL,   0x22c9f00fUL,   0x2f8ad6d6UL,   0x2b4bcb61UL,
       0x350c9b64UL,   0x31cd86d3UL,   0x3c8ea00aUL,   0x384fbdbdUL,
       0x4c11db70UL,   0x48d0c6c7UL,   0x4593e01eUL,   0x4152fda9UL,
       0x5f15adacUL,   0x5bd4b01bUL,   0x569796c2UL,   0x52568b75UL,
       0x6a1936c8UL,   0x6ed82b7fUL,   0x639b0da6UL,   0x675a1011UL,
       0x791d4014UL,   0x7ddc5da3UL,   0x709f7b7aUL,   0x745e66cdUL,
       0x9823b6e0UL,   0x9ce2ab57UL,   0x91a18d8eUL,   0x95609039UL,
       0x8b27c03cUL,   0x8fe6dd8bUL,   0x82a5fb52UL,   0x8664e6e5UL,
       0xbe2b5b58UL,   0xbaea46efUL,   0xb7a96036UL,   0xb3687d81UL,
       0xad2f2d84UL,   0xa9ee3033UL,   0xa4ad16eaUL,   0xa06c0b5dUL,
       0xd4326d90UL,   0xd0f37027UL,   0xddb056feUL,   0xd9714b49UL,
       0xc7361b4cUL,   0xc3f706fbUL,   0xceb42022UL,   0xca753d95UL,
       0xf23a8028UL,   0xf6fb9d9fUL,   0xfbb8bb46UL,   0xff79a6f1UL,
       0xe13ef6f4UL,   0xe5ffeb43UL,   0xe8bccd9aUL,   0xec7dd02dUL,
       0x34867077UL,   0x30476dc0UL,   0x3d044b19UL,   0x39c556aeUL,
       0x278206abUL,   0x23431b1cUL,   0x2e003dc5UL,   0x2ac12072UL,
       0x128e9dcfUL,   0x164f8078UL,   0x1b0ca6a1UL,   0x1fcdbb16UL,
       0x018aeb13UL,   0x054bf6a4UL,   0x0808d07dUL,   0x0cc9cdcaUL,
       0x7897ab07UL,   0x7c56b6b0UL,   0x71159069UL,   0x75d48ddeUL,
       0x6b93dddbUL,   0x6f52c06cUL,   0x6211e6b5UL,   0x66d0fb02UL,
       0x5e9f46bfUL,   0x5a5e5b08UL,   0x571d7dd1UL,   0x53dc6066UL,
       0x4d9b3063UL,   0x495a2dd4UL,   0x44190b0dUL,   0x40d816baUL,
       0xaca5c697UL,   0xa864db20UL,   0xa527fdf9UL,   0xa1e6e04eUL,
       0xbfa1b04bUL,   0xbb60adfcUL,   0xb6238b25UL,   0xb2e29692UL,
       0x8aad2b2fUL,   0x8e6c3698UL,   0x832f1041UL,   0x87ee0df6UL,
       0x99a95df3UL,   0x9d684044UL,   0x902b669dUL,   0x94ea7b2aUL,
       0xe0b41de7UL,   0xe4750050UL,   0xe9362689UL,   0xedf73b3eUL,
       0xf3b06b3bUL,   0xf771768cUL,   0xfa325055UL,   0xfef34de2UL,
       0xc6bcf05fUL,   0xc27dede8UL,   0xcf3ecb31UL,   0xcbffd686UL,
       0xd5b88683UL,   0xd1799b34UL,   0xdc3abdedUL,   0xd8fba05aUL,
       0x690ce0eeUL,   0x6dcdfd59UL,   0x608edb80UL,   0x644fc637UL,
       0x7a089632UL,   0x7ec98b85UL,   0x738aad5cUL,   0x774bb0ebUL,
       0x4f040d56UL,   0x4bc510e1UL,   0x46863638UL,   0x42472b8fUL,
       0x5c007b8aUL,   0x58c1663dUL,   0x558240e4UL,   0x51435d53UL,
       0x251d3b9eUL,   0x21dc2629UL,   0x2c9f00f0UL,   0x285e1d47UL,
       0x36194d42UL,   0x32d850f5UL,   0x3f9b762cUL,   0x3b5a6b9bUL,
       0x315d626UL,    0x07d4cb91UL,   0x0a97ed48UL,   0x0e56f0ffUL,
       0x1011a0faUL,   0x14d0bd4dUL,   0x19939b94UL,   0x1d528623UL,
       0xf12f560eUL,   0xf5ee4bb9UL,   0xf8ad6d60UL,   0xfc6c70d7UL,
       0xe22b20d2UL,   0xe6ea3d65UL,   0xeba91bbcUL,   0xef68060bUL,
       0xd727bbb6UL,   0xd3e6a601UL,   0xdea580d8UL,   0xda649d6fUL,
       0xc423cd6aUL,   0xc0e2d0ddUL,   0xcda1f604UL,   0xc960ebb3UL,
       0xbd3e8d7eUL,   0xb9ff90c9UL,   0xb4bcb610UL,   0xb07daba7UL,
       0xae3afba2UL,   0xaafbe615UL,   0xa7b8c0ccUL,   0xa379dd7bUL,
       0x9b3660c6UL,   0x9ff77d71UL,   0x92b45ba8UL,   0x9675461fUL,
       0x8832161aUL,   0x8cf30badUL,   0x81b02d74UL,   0x857130c3UL,
       0x5d8a9099UL,   0x594b8d2eUL,   0x5408abf7UL,   0x50c9b640UL,
       0x4e8ee645UL,   0x4a4ffbf2UL,   0x470cdd2bUL,   0x43cdc09cUL,
       0x7b827d21UL,   0x7f436096UL,   0x7200464fUL,   0x76c15bf8UL,
       0x68860bfdUL,   0x6c47164aUL,   0x61043093UL,   0x65c52d24UL,
       0x119b4be9UL,   0x155a565eUL,   0x18197087UL,   0x1cd86d30UL,
       0x029f3d35UL,   0x065e2082UL,   0x0b1d065bUL,   0x0fdc1becUL,
       0x3793a651UL,   0x3352bbe6UL,   0x3e119d3fUL,   0x3ad08088UL,
       0x2497d08dUL,   0x2056cd3aUL,   0x2d15ebe3UL,   0x29d4f654UL,
       0xc5a92679UL,   0xc1683bceUL,   0xcc2b1d17UL,   0xc8ea00a0UL,
       0xd6ad50a5UL,   0xd26c4d12UL,   0xdf2f6bcbUL,   0xdbee767cUL,
       0xe3a1cbc1UL,   0xe760d676UL,   0xea23f0afUL,   0xeee2ed18UL,
       0xf0a5bd1dUL,   0xf464a0aaUL,   0xf9278673UL,   0xfde69bc4UL,
       0x89b8fd09UL,   0x8d79e0beUL,   0x803ac667UL,   0x84fbdbd0UL,
       0x9abc8bd5UL,   0x9e7d9662UL,   0x933eb0bbUL,   0x97ffad0cUL,
       0xafb010b1UL,   0xab710d06UL,   0xa6322bdfUL,   0xa2f33668UL,
       0xbcb4666dUL,   0xb8757bdaUL,   0xb5365d03UL,   0xb1f740b4UL
    };
    #define CRC_STOP_SEC_CONST_32BIT
    #include "MemMap.h"
    #endif /* #endif for         #if CRC_32_MODE == CRC_TABLE_MODE*/
  #endif /* #endif for #ifdef CRC_32_MODE*/
    
    
    
    /*Crc 16bit polynomial=0x1021 table initialization*/
  #ifdef CRC_16_MODE 
    #if CRC_16_MODE == CRC_TABLE_MODE
    #define CRC_START_SEC_CONST_16BIT
    #include "MemMap.h"
    static const uint16 Crc_Table16[CRC_TABLE_LENGTH] = 
    {
      0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50A5U, 0x60C6U, 0x70E7U,
      0x8108U, 0x9129U, 0xA14AU, 0xB16BU, 0xC18CU, 0xD1ADU, 0xE1CEU, 0xF1EFU,
      0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52B5U, 0x4294U, 0x72F7U, 0x62D6U,
      0x9339U, 0x8318U, 0xB37BU, 0xA35AU, 0xD3BDU, 0xC39CU, 0xF3FFU, 0xE3DEU,
      0x2462U, 0x3443U, 0x0420U, 0x1401U, 0x64E6U, 0x74C7U, 0x44A4U, 0x5485U,
      0xA56AU, 0xB54BU, 0x8528U, 0x9509U, 0xE5EEU, 0xF5CFU, 0xC5ACU, 0xD58DU,
      0x3653U, 0x2672U, 0x1611U, 0x0630U, 0x76D7U, 0x66F6U, 0x5695U, 0x46B4U,
      0xB75BU, 0xA77AU, 0x9719U, 0x8738U, 0xF7DFU, 0xE7FEU, 0xD79DU, 0xC7BCU,
      0x48C4U, 0x58E5U, 0x6886U, 0x78A7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U,
      0xC9CCU, 0xD9EDU, 0xE98EU, 0xF9AFU, 0x8948U, 0x9969U, 0xA90AU, 0xB92BU,
      0x5AF5U, 0x4AD4U, 0x7AB7U, 0x6A96U, 0x1A71U, 0x0A50U, 0x3A33U, 0x2A12U,
      0xDBFDU, 0xCBDCU, 0xFBBFU, 0xEB9EU, 0x9B79U, 0x8B58U, 0xBB3BU, 0xAB1AU,
      0x6CA6U, 0x7C87U, 0x4CE4U, 0x5CC5U, 0x2C22U, 0x3C03U, 0x0C60U, 0x1C41U,
      0xEDAEU, 0xFD8FU, 0xCDECU, 0xDDCDU, 0xAD2AU, 0xBD0BU, 0x8D68U, 0x9D49U,
      0x7E97U, 0x6EB6U, 0x5ED5U, 0x4EF4U, 0x3E13U, 0x2E32U, 0x1E51U, 0x0E70U,
      0xFF9FU, 0xEFBEU, 0xDFDDU, 0xCFFCU, 0xBF1BU, 0xAF3AU, 0x9F59U, 0x8F78U,
      0x9188U, 0x81A9U, 0xB1CAU, 0xA1EBU, 0xD10CU, 0xC12DU, 0xF14EU, 0xE16FU,
      0x1080U, 0x00A1U, 0x30C2U, 0x20E3U, 0x5004U, 0x4025U, 0x7046U, 0x6067U,
      0x83B9U, 0x9398U, 0xA3FBU, 0xB3DAU, 0xC33DU, 0xD31CU, 0xE37FU, 0xF35EU,
      0x02B1U, 0x1290U, 0x22F3U, 0x32D2U, 0x4235U, 0x5214U, 0x6277U, 0x7256U,
      0xB5EAU, 0xA5CBU, 0x95A8U, 0x8589U, 0xF56EU, 0xE54FU, 0xD52CU, 0xC50DU,
      0x34E2U, 0x24C3U, 0x14A0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U,
      0xA7DBU, 0xB7FAU, 0x8799U, 0x97B8U, 0xE75FU, 0xF77EU, 0xC71DU, 0xD73CU,
      0x26D3U, 0x36F2U, 0x0691U, 0x16B0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U,
      0xD94CU, 0xC96DU, 0xF90EU, 0xE92FU, 0x99C8U, 0x89E9U, 0xB98AU, 0xA9ABU,
      0x5844U, 0x4865U, 0x7806U, 0x6827U, 0x18C0U, 0x08E1U, 0x3882U, 0x28A3U,
      0xCB7DU, 0xDB5CU, 0xEB3FU, 0xFB1EU, 0x8BF9U, 0x9BD8U, 0xABBBU, 0xBB9AU,
      0x4A75U, 0x5A54U, 0x6A37U, 0x7A16U, 0x0AF1U, 0x1AD0U, 0x2AB3U, 0x3A92U,
      0xFD2EU, 0xED0FU, 0xDD6CU, 0xCD4DU, 0xBDAAU, 0xAD8BU, 0x9DE8U, 0x8DC9U,
      0x7C26U, 0x6C07U, 0x5C64U, 0x4C45U, 0x3CA2U, 0x2C83U, 0x1CE0U, 0x0CC1U,
      0xEF1FU, 0xFF3EU, 0xCF5DU, 0xDF7CU, 0xAF9BU, 0xBFBAU, 0x8FD9U, 0x9FF8U,
      0x6E17U, 0x7E36U, 0x4E55U, 0x5E74U, 0x2E93U, 0x3EB2U, 0x0ED1U, 0x1EF0U
    };
    #define CRC_STOP_SEC_CONST_16BIT
    #include "MemMap.h"
  #endif /* #endif for         #if CRC_16_MODE == CRC_TABLE_MODE*/
  #endif /* #endif for #ifdef CRC_16_MODE*/



/*Crc 8bit polynomial=0x1D table initialization*/
  #ifdef CRC_8_MODE 
    #if CRC_8_MODE == CRC_TABLE_MODE
    #define CRC_START_SEC_CONST_8BIT
    #include "MemMap.h"

    static const uint8 Crc_Table8[CRC_TABLE_LENGTH]=
    {
      0x00U, 0x1dU, 0x3AU, 0x27U, 0x74U, 0x69U, 0x4eU, 0x53U,
      0xe8U, 0xf5U, 0xd2U, 0xcfU, 0x9cU, 0x81U, 0xa6U, 0xbbU,
      0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U, 0x83U, 0x9eU,
      0x25U, 0x38U, 0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U,
      0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U, 0xD4U,
      0x6FU, 0x72U, 0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU,
      0x4AU, 0x57U, 0x70U, 0x6DU, 0x3EU, 0x23U, 0x04U, 0x19U,
      0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU, 0xECU, 0xF1U,
      0x13U, 0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U,
      0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U, 0xB5U, 0xA8U,
      0xDEU, 0xC3U, 0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU,
      0x36U, 0x2BU, 0x0CU, 0x11U, 0x42U, 0x5FU, 0x78U, 0x65U,
      0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU, 0xDAU, 0xC7U,
      0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU,
      0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU, 0x30U, 0x17U, 0x0AU,
      0xB1U, 0xACU, 0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U,
      0x26U, 0x3BU, 0x1CU, 0x01U, 0x52U, 0x4FU, 0x68U, 0x75U,
      0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U, 0x80U, 0x9DU,
      0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U,
      0x03U, 0x1EU, 0x39U, 0x24U, 0x77U, 0x6AU, 0x4DU, 0x50U,
      0xA1U, 0xBCU, 0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U,
      0x49U, 0x54U, 0x73U, 0x6EU, 0x3DU, 0x20U, 0x07U, 0x1AU,
      0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U, 0x22U, 0x3FU,
      0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U,
      0x35U, 0x28U, 0x0FU, 0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U,
      0xDDU, 0xC0U, 0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU,
      0xF8U, 0xE5U, 0xC2U, 0xDFU, 0x8CU, 0x91U, 0xB6U, 0xABU,
      0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U, 0x79U, 0x5EU, 0x43U,
      0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U,
      0x5AU, 0x47U, 0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U,
      0x7FU, 0x62U, 0x45U, 0x58U, 0x0BU, 0x16U, 0x31U, 0x2CU,
      0x97U, 0x8AU, 0xADU, 0xB0U, 0xE3U, 0xFEU, 0xD9U, 0xC4U 
    };            
    #define CRC_STOP_SEC_CONST_8BIT
    #include "MemMap.h"

    #endif /* #endif for         #if CRC_8_MODE == CRC_TABLE_MODE*/
    #endif /* #endif for #ifdef CRC_8_MODE*/
/*Crc 8bit polynomial=0x1F table initialization*/
   #ifdef CRC_8H2F_MODE 
   #if CRC_8H2F_MODE == CRC_TABLE_MODE
   #define CRC_START_SEC_CONST_8BIT
   #include "MemMap.h"
    static const uint8 Crc_Table8H2F[CRC_TABLE_LENGTH]=
    {
     0x00U,   0x2fU,   0x5eU,   0x71U,   0xbcU,   0x93U,   0xe2U,   0xcdU, 
      0x57U,   0x78U,   0x09U,   0x26U,   0xEBU,   0xC4U,   0xB5U,   0x9AU, 
      0xAEU,   0x81U,   0xF0U,   0xDFU,   0x12U,   0x3DU,   0x4CU,   0x63U, 
      0xF9U,   0xD6U,   0xA7U,   0x88U,   0x45U,   0x6AU,   0x1BU,   0x34U, 
      0x73U,   0x5CU,   0x2DU,   0x02U,   0xCFU,   0xE0U,   0x91U,   0xBEU, 
      0x24U,   0x0BU,   0x7AU,   0x55U,   0x98U,   0xB7U,   0xC6U,   0xE9U, 
      0xDDU,   0xF2U,   0x83U,   0xACU,   0x61U,   0x4EU,   0x3FU,   0x10U, 
      0x8AU,   0xA5U,   0xD4U,   0xFBU,   0x36U,   0x19U,   0x68U,   0x47U, 
      0xE6U,   0xC9U,   0xB8U,   0x97U,   0x5AU,   0x75U,   0x04U,   0x2BU, 
      0xB1U,   0x9EU,   0xEFU,   0xC0U,   0x0DU,   0x22U,   0x53U,   0x7CU, 
      0x48U,   0x67U,   0x16U,   0x39U,   0xF4U,   0xDBU,   0xAAU,   0x85U, 
      0x1FU,   0x30U,   0x41U,   0x6EU,   0xA3U,   0x8CU,   0xFDU,   0xD2U, 
      0x95U,   0xBAU,   0xCBU,   0xE4U,   0x29U,   0x06U,   0x77U,   0x58U, 
      0xC2U,   0xEDU,   0x9CU,   0xB3U,   0x7EU,   0x51U,   0x20U,   0x0FU, 
      0x3BU,   0x14U,   0x65U,   0x4AU,   0x87U,   0xA8U,   0xD9U,   0xF6U, 
      0x6CU,   0x43U,   0x32U,   0x1DU,   0xD0U,   0xFFU,   0x8EU,   0xA1U, 
      0xE3U,   0xCCU,   0xBDU,   0x92U,   0x5FU,   0x70U,   0x01U,   0x2EU, 
      0xB4U,   0x9BU,   0xEAU,   0xC5U,   0x08U,   0x27U,   0x56U,   0x79U, 
      0x4DU,   0x62U,   0x13U,   0x3CU,   0xF1U,   0xDEU,   0xAFU,   0x80U, 
      0x1AU,   0x35U,   0x44U,   0x6BU,   0xA6U,   0x89U,   0xF8U,   0xD7U, 
      0x90U,   0xBFU,   0xCEU,   0xE1U,   0x2CU,   0x03U,   0x72U,   0x5DU, 
      0xC7U,   0xE8U,   0x99U,   0xB6U,   0x7BU,   0x54U,   0x25U,   0x0AU, 
      0x3EU,   0x11U,   0x60U,   0x4FU,   0x82U,   0xADU,   0xDCU,   0xF3U, 
      0x69U,   0x46U,   0x37U,   0x18U,   0xD5U,   0xFAU,   0x8BU,   0xA4U, 
      0x05U,   0x2AU,   0x5BU,   0x74U,   0xB9U,   0x96U,   0xE7U,   0xC8U, 
      0x52U,   0x7DU,   0x0CU,   0x23U,   0xEEU,   0xC1U,   0xB0U,   0x9FU, 
      0xABU,   0x84U,   0xF5U,   0xDAU,   0x17U,   0x38U,   0x49U,   0x66U, 
      0xFCU,   0xD3U,   0xA2U,   0x8DU,   0x40U,   0x6FU,   0x1EU,   0x31U, 
      0x76U,   0x59U,   0x28U,   0x07U,   0xCAU,   0xE5U,   0x94U,   0xBBU, 
      0x21U,   0x0EU,   0x7FU,   0x50U,   0x9DU,   0xB2U,   0xC3U,   0xECU, 
      0xD8U,   0xF7U,   0x86U,   0xA9U,   0x64U,   0x4BU,   0x3AU,   0x15U, 
      0x8FU,   0xA0U,   0xD1U,   0xFEU,   0x33U,   0x1CU,   0x6DU,   0x42U
     };
   #define CRC_STOP_SEC_CONST_8BIT
   #include "MemMap.h"

    #endif /* #endif for         #if CRC_8H2F_MODE == CRC_TABLE_MODE*/
    #endif /* #endif for #ifdef CRC_8H2F_MODE*/





/*******************************************************************************
**        Global Variable Definitions     **
*******************************************************************************/


  

/*******************************************************************************
**        Private Constant Definitions    **
*******************************************************************************/



/*******************************************************************************
**        Private Variable Definitions    **
*******************************************************************************/

/*******************************************************************************
**        Global Function Definitions     **
*******************************************************************************/


/* Memory Map of the CRC Code */
  #define CRC_START_SEC_CODE
  #include "MemMap.h"

  #ifdef CRC_8_MODE
/*******************************************************************************
** Traceability   :  [cover parentID=DS_AS403_CRC030,DS_AS403_CRC031,
        DS_AS403_CRC014,DS_AS403_CRC032,DS_AS403_CRC041
      ,DS_AS403_CRC033,DS_MCAL_SWSC_CRC_0447_1]                                 **
      [/cover]                                                                **
** Syntax     : uint8 Crc_CalculateCRC8                                       **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint8 Crc_StartValue8,                                               **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x01                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and  xor value  and returns the CRC xored with XOR value                **
*******************************************************************************/
  uint8 Crc_CalculateCRC8
  (
    const uint8* Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8,
    boolean Crc_IsFirstCall
  )
  {     
  uint8 Crc8Result=CRC_INIT_VAL;
  
    #if (CRC_SAFETY_ENABLE == STD_ON)      
    /* Verify any error is there for Safety check */    
    uint8 ErrorFlag; 
    ErrorFlag = Crc_lCrcCalculationSafetyCheck(
                 Crc_DataPtr,Crc_IsFirstCall,Crc_Length,CRC_SID_CALCULATECRC8);
    if (ErrorFlag != CRC_ERR_FOUND) 
    #endif
    {
      #if  CRC_8_MODE == CRC_RUNTIME_MODE
      Crc8Result= Crc_lCalculateCRC8Runtime( Crc_DataPtr, Crc_Length,
                  Crc_StartValue8, Crc_IsFirstCall);
      #elif CRC_8_MODE == CRC_TABLE_MODE
      Crc8Result= Crc_lCalculateCRC8Table( Crc_DataPtr, Crc_Length,
                  Crc_StartValue8, Crc_IsFirstCall);
      #elif CRC_8_MODE == CRC_HARDWARE_MODE
      Crc8Result= Crc_lCalculateCRC8Hardware( Crc_DataPtr, Crc_Length,
                  Crc_StartValue8, Crc_IsFirstCall);
      #endif
   }
    return Crc8Result;
  }
  #endif /* #endif for #ifdef CRC_8_MODE */

  #ifdef CRC_8H2F_MODE

/*******************************************************************************
** Traceability   : [cover parentID=DS_AS_CRC042,
DS_AS403_CRC041,DS_AS403_CRC043,DS_MCAL_SWSC_CRC_0447_2,DS_AS_CRC044]         
[/cover]
** Syntax     : uint8 Crc_CalculateCRC8H2F                                    **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint8 Crc_StartValue8H2F,                                            **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x05                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8H2F -Start value for CRC Calculation                 **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and  xor value  and returns the CRC xored with XOR value                **
*******************************************************************************/
  uint8 Crc_CalculateCRC8H2F
  (
    const uint8* Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8H2F, 
    boolean Crc_IsFirstCall
  )
  {     
    uint8 Crc8H2FResult=CRC_INIT_VAL;
    #if (CRC_SAFETY_ENABLE == STD_ON) 
    /* Verify any error is there for Safety check */    
    uint8 ErrorFlag;
    ErrorFlag = Crc_lCrcCalculationSafetyCheck(
               Crc_DataPtr,Crc_IsFirstCall,Crc_Length,CRC_SID_CALCULATECRC8H2F);
    if (ErrorFlag != CRC_ERR_FOUND)    
    #endif/* #if (CRC_SAFETY_ENABLE == STD_ON) */
    {
      #if  CRC_8H2F_MODE == CRC_RUNTIME_MODE
      Crc8H2FResult= Crc_lCalculateCRC8H2FRuntime( Crc_DataPtr, Crc_Length,
                     Crc_StartValue8H2F, Crc_IsFirstCall);
      #elif CRC_8H2F_MODE == CRC_TABLE_MODE
      Crc8H2FResult= Crc_lCalculateCRC8H2FTable( Crc_DataPtr, Crc_Length,
                     Crc_StartValue8H2F, Crc_IsFirstCall);
      #endif
  
    }
    return Crc8H2FResult;
  }
  #endif /* #endif for #ifdef CRC_8H2F_MODE */

  #ifdef CRC_16_MODE
/*******************************************************************************
** Traceability   : [cover parentID=DS_AS_CRC002,DS_AS_CRC015,DS_AS403_CRC019,
    DS_AS403_CRC041,DS_AS_CRC009,DS_AS_CRC002,
    DS_AS_CRC003,DS_AS_CRC015,DS_MCAL_SWSC_CRC_0447_3]
[/cover]
** Syntax     : uint8 Crc_CalculateCRC16                                      **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint8 Crc_StartValue16,                                              **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x05                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue16 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint16                                                    **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and  xor value  and returns the CRC xored with XOR value                **
*******************************************************************************/
  uint16 Crc_CalculateCRC16(
    const uint8* Crc_DataPtr, 
    uint32 Crc_Length, 
    uint16 Crc_StartValue16, 
    boolean Crc_IsFirstCall
  )
  {
    uint16 Crc16Result=CRC_INIT_VAL;  
    #if (CRC_SAFETY_ENABLE == STD_ON)       
    /* Verify any error is there for Safety check */    
    uint8 ErrorFlag;
    ErrorFlag = Crc_lCrcCalculationSafetyCheck(
                Crc_DataPtr,Crc_IsFirstCall,Crc_Length,CRC_SID_CALCULATECRC16);
    if (ErrorFlag != CRC_ERR_FOUND)    
    #endif /* #if (CRC_SAFETY_ENABLE == STD_ON)  */
    { 
      #if  CRC_16_MODE == CRC_RUNTIME_MODE
      Crc16Result = Crc_lCalculateCRC16Runtime( Crc_DataPtr, Crc_Length,
                    Crc_StartValue16, Crc_IsFirstCall);
      #elif CRC_16_MODE == CRC_TABLE_MODE
      Crc16Result = Crc_lCalculateCRC16Table( Crc_DataPtr, Crc_Length,
                    Crc_StartValue16, Crc_IsFirstCall);
      #elif CRC_16_MODE == CRC_HARDWARE_MODE    
      Crc16Result = Crc_lCalculateCRC16Hardware( Crc_DataPtr, Crc_Length,
                    Crc_StartValue16, Crc_IsFirstCall);
      #endif    
    }    
  return Crc16Result;
  }
#endif /* #endif for #ifdef CRC_16_MODE */

#ifdef CRC_32_MODE
/*******************************************************************************
** Traceability   : [cover parentID=DS_AS_CRC003,DS_AS_CRC016,DS_AS403_CRC041,
          DS_AS403_CRC020,DS_AS_CRC010,
          DS_AS_CRC016,DS_MCAL_SWSC_CRC_0447_4]                               **
[/cover]
** Syntax     : uint32 Crc_CalculateCRC32                                     **
**      (                                                                     **
**       const uint8* Crc_DataPtr,                                            **
**       uint32 Crc_Length,                                                   **
**       uint32 Crc_StartValue32,                                             **
**       boolean Crc_IsFirstCall                                              **
**      )                                                                     **
**                                                                            **
** Service ID     : 0x01                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters(in)   :  Crc_DataPtr  - Pointer to the start of the datablock   **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue32 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decIDe the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint32                                                    **
**                                                                            **
** Description    : This function:                                            **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and reversed xor value  and returns the CRC xored with XOR value        **
*******************************************************************************/
  uint32 Crc_CalculateCRC32(
    const uint8* Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32,
    boolean Crc_IsFirstCall
  )
  {
    uint32 Crc32Result=CRC_INIT_VAL;
    #if (CRC_SAFETY_ENABLE == STD_ON)          
    /* Verify any error is there for Safety check */    
    uint8 ErrorFlag;
    ErrorFlag = Crc_lCrcCalculationSafetyCheck(
                Crc_DataPtr,Crc_IsFirstCall,Crc_Length,CRC_SID_CALCULATECRC32);
    if (ErrorFlag != CRC_ERR_FOUND)    
    #endif/* #if (CRC_SAFETY_ENABLE == STD_ON) */
    {
      #if  CRC_32_MODE == CRC_RUNTIME_MODE
      Crc32Result = Crc_lCalculateCRC32Runtime( Crc_DataPtr, Crc_Length,
                    Crc_StartValue32, Crc_IsFirstCall);
      #elif CRC_32_MODE == CRC_TABLE_MODE
      Crc32Result = Crc_lCalculateCRC32Table( Crc_DataPtr, Crc_Length,
                    Crc_StartValue32, Crc_IsFirstCall);
      #elif CRC_32_MODE == CRC_HARDWARE_MODE
      Crc32Result = Crc_lCalculateCRC32Hardware( Crc_DataPtr, Crc_Length,
                    Crc_StartValue32, Crc_IsFirstCall);
      #endif
   }   
   return Crc32Result;
  }
  #endif /* #endif for #ifdef CRC_32_MODE */

#if defined (CRC_8_RUNTIME_MODE) || defined (CRC_8H2F_RUNTIME_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : static uint8 Crc_lCommonCalculateCRCRuntime                   **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 Crc_StartValue8,                                              **
**        boolean Crc_IsFirstCall,                                            **
**        uint8 Polynomial_8bit                                               **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**        Polynomial_8bit - 8bit polynomial to be used                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointerU, start value and    **
**   polynomialU, calculates the CRC value and returns the CRC                **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
*******************************************************************************/
  static uint8 Crc_lCommonCalculateCRCRuntime( const uint8* Crc_DataPtr, 
  uint32 Crc_Length,   uint8 Crc_StartValue8, uint8 Polynomial_8bit)
  {
    uint8 MessageBit;
    uint32 LoopCounter;
    /*process every byte of the message*/
    for (LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL; LoopCounter < Crc_Length; 
         LoopCounter++)
    {
      Crc_StartValue8 ^= Crc_DataPtr[LoopCounter];
      for(MessageBit = CRC_LOOPCNT_MSGBIT_INIT_VAL; MessageBit > CRC_ZERO_U;
          --MessageBit)
      {
        if((Crc_StartValue8 & CRC_CRC8_MSB )== CRC_CRC8_MSB)
        {
          /* If MSB is 1 then left shift and X-OR with polynomial*/
          Crc_StartValue8 = (uint8)((uint8)Crc_StartValue8 << CRC_SHIFT_ONE) 
                            ^ Polynomial_8bit;
        }
        else
        {
          /* If MSB is 0 then left shift and X-OR with polynomial*/
          Crc_StartValue8 = (uint8)((uint8)Crc_StartValue8 << CRC_SHIFT_ONE);
        }
     }
   }
   return Crc_StartValue8;
  }
  
  #endif 
  /*#endif for  #if ((CRC_8_MODE == CRC_RUNTIME_MODE) || 
  (CRC_8H2F_MODE == CRC_RUNTIME_MODE)) */
  
  
  #ifdef CRC_8_MODE
  #if  (CRC_8_MODE == CRC_RUNTIME_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint8 Crc_lCalculateCRC8Runtime                               **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 Crc_StartValue8,                                              **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the CRC value and returns the CRC xored with      **
**   XOR value                                                                **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
*******************************************************************************/
  static uint8 Crc_lCalculateCRC8Runtime( const uint8* Crc_DataPtr, 
  uint32 Crc_Length,uint8 Crc_StartValue8, boolean Crc_IsFirstCall)
  {
  /* code for crc 8 runtime calculaion for 0x1D polynomials */

    /* if it is first call assign initial value to the start value */
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
      Crc_StartValue8 = CRC_INITIAL_VALUE8;
    }
    else
    {
      Crc_StartValue8 = Crc_StartValue8 ^ CRC_CRC8_XOR_VALUE;
    }
    Crc_StartValue8 = Crc_lCommonCalculateCRCRuntime( Crc_DataPtr, 
    Crc_Length,Crc_StartValue8, CRC_CRC8_POLYNOMIAL);
    
    Crc_StartValue8 = Crc_StartValue8 ^ CRC_CRC8_XOR_VALUE;
    return Crc_StartValue8;
  }
  #elif (CRC_8_MODE == CRC_TABLE_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint8 Crc_lCalculateCRC8Table                                 **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 Crc_StartValue8,                                              **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**   xor value  and returns the CRC xored with XOR value                      **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint8 Crc_lCalculateCRC8Table( const uint8* Crc_DataPtr, 
  uint32 Crc_Length,  uint8 Crc_StartValue8, boolean Crc_IsFirstCall)
  {
  /* code for crc 8 Table based calculaion for 0x1D polynomials*/
    uint32 LoopCounter = CRC_INIT_VAL;
    uint8 CompareData = CRC_INIT_VAL;
    if (Crc_IsFirstCall==(boolean)TRUE)
    {
      Crc_StartValue8 = CRC_INITIAL_VALUE8;
    }
    else
    {
      Crc_StartValue8 = Crc_StartValue8 ^ CRC_CRC8_XOR_VALUE;
    }      
    /*Extract each byte from the message, fetch the value from lookup 
    table and XOR with the crc value*/
    for(LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL;LoopCounter < Crc_Length; 
        LoopCounter++)
    {
      CompareData = Crc_DataPtr[LoopCounter] ^ Crc_StartValue8;
      Crc_StartValue8 = Crc_Table8[CompareData] ^
                   (uint8)((uint16)((uint16)Crc_StartValue8<<CRC_SHIFT_EIGHT));
    }

    Crc_StartValue8 = CRC_CRC8_XOR_VALUE ^ Crc_StartValue8;
    return Crc_StartValue8;
  }
  #elif (CRC_8_MODE == CRC_HARDWARE_MODE)
/*******************************************************************************
** Traceability     : [cover parentID=DS_MCAL_SWSC_CRC_0443_1,
                       DS_MCAL_SWSC_CRC_0444_1]
[/cover]
**                                                                            **
** Syntax     : uint8 Crc_lCalculateCRC8Hardware                              **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 Crc_StartValue8,                                              **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc using the hardware and returns the CRC    **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint8 Crc_lCalculateCRC8Hardware(const uint8* Crc_DataPtr, 
  uint32 Crc_Length, uint8 Crc_StartValue8,   boolean Crc_IsFirstCall)
  {
    uint32 LoopCounter;
    uint8 CRC_RegBackup;
    uint8 Temp;
      
    CRC_RegBackup = (uint8) FCE0_IN3_CRC.B.CRC;
    /* code for crc 8 hardware calculaion for 0x1D polynomials*/
   
    /*Configure CRC register*/
    if (Crc_IsFirstCall == (boolean)TRUE)
    {
      FCE0_IN3_CRC.B.CRC = CRC_INITIAL_VALUE8;
    }
    else
    {
      Temp = (uint8)(Crc_StartValue8 ^ CRC_CRC8_XOR_VALUE);
      FCE0_IN3_CRC.B.CRC = Temp;
    }
    /* input in INIT register */
    for (LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL; LoopCounter < Crc_Length;
         ++LoopCounter)
    {
      FCE0_IN3_IR.U = (uint8)Crc_DataPtr[LoopCounter];      
    }
    Crc_StartValue8 = (uint8)FCE0_IN3_RES.B.RES;    
  
    FCE0_IN3_CRC.B.CRC = CRC_RegBackup ;

   
    return Crc_StartValue8;
  }
  #endif 
  /* #endif for (CRC_8_MODE == CRC_HARDWARE_MODE)*/
  #endif
  /*#endif for #ifdef CRC_8_MODE*/

  #ifdef CRC_8H2F_MODE
  #if (CRC_8H2F_MODE == CRC_RUNTIME_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint8 Crc_lCalculateCRC8H2FRuntime                            **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 Crc_StartValue8,                                              **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8 -Start value for CRC Calculation                    **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the CRC value and returns the CRC xored with      **
**   XOR value                                                                **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint8 Crc_lCalculateCRC8H2FRuntime( const uint8* Crc_DataPtr,
  uint32 Crc_Length,  uint8 Crc_StartValue8H2F,   boolean Crc_IsFirstCall)
  {
    /* code for crc 8 runtme calculaion with 0x2F polynomial*/
    /* if it is first call assign initial value to the start value */
    if(Crc_IsFirstCall ==(boolean)TRUE)
    {
      Crc_StartValue8H2F = CRC_INITIAL_VALUE8H2F;
    }
    else
    {
      Crc_StartValue8H2F = Crc_StartValue8H2F ^ CRC_CRC8H2F_XOR_VALUE;
    }    
    Crc_StartValue8H2F=Crc_lCommonCalculateCRCRuntime( Crc_DataPtr, 
    Crc_Length,    Crc_StartValue8H2F, CRC_CRC8H2F_POLYNOMIAL);
    Crc_StartValue8H2F = CRC_CRC8H2F_XOR_VALUE ^ Crc_StartValue8H2F;
    return Crc_StartValue8H2F;
  }
  #elif (CRC_8H2F_MODE == CRC_TABLE_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint8 Crc_lCalculateCRC8H2FTable                              **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 Crc_StartValue8H2F,                                           **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue8H2F -Start value for CRC Calculation                 **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint8                                                     **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**   xor value  and returns the CRC xored with XOR value                      **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint8 Crc_lCalculateCRC8H2FTable( const uint8* Crc_DataPtr,
  uint32 Crc_Length, uint8 Crc_StartValue8H2F,   boolean Crc_IsFirstCall) 
  {
     /*calculaion with 0x2F polynomial*/
    uint32 LoopCounter;
    uint8 CompareData = CRC_INIT_VAL;
    if (Crc_IsFirstCall==(boolean)TRUE)
    {
      Crc_StartValue8H2F = CRC_INITIAL_VALUE8H2F;
    }
    else
    {
      Crc_StartValue8H2F = Crc_StartValue8H2F ^ CRC_CRC8H2F_XOR_VALUE;
    }       
    /*Extract each byte from the message, fetch the value from
     lookup table and XOR with the crc value*/
    
    for(LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL;LoopCounter < Crc_Length; 
        LoopCounter++)
    {
      CompareData = Crc_DataPtr[LoopCounter] ^ Crc_StartValue8H2F ;
      Crc_StartValue8H2F = Crc_Table8H2F[CompareData] ^ 
             (uint8)((uint16)((uint16)Crc_StartValue8H2F<<CRC_SHIFT_EIGHT));
    }
    Crc_StartValue8H2F = CRC_CRC8H2F_XOR_VALUE ^ Crc_StartValue8H2F;
    return Crc_StartValue8H2F;
  }
  #endif 
  /* #endif for (CRC_8H2F_MODE == CRC_HARDWARE_MODE)*/
  #endif
  /*#endif for #ifdef CRC_8H2F_MODE*/

  #ifdef CRC_16_MODE
  #if (CRC_16_MODE == CRC_RUNTIME_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint16 Crc_lCalculateCRC16Runtime                             **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint16 Crc_StartValue16,                                            **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue16 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint16                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the CRC value and returns the CRC xored with      **
**   XOR value                                                                **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint16 Crc_lCalculateCRC16Runtime( const uint8* Crc_DataPtr, 
  uint32 Crc_Length, uint16 Crc_StartValue16,boolean Crc_IsFirstCall)
  {
    uint32 LoopCounter;
    uint32 MessageBit;
    /* code for crc 16 runtime calculaion with 0x1021 polynomial*/
  /* if it is first call assign initial value to the start value */
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
      Crc_StartValue16 = CRC_INITIAL_VALUE16;
    }
    else
    {
      Crc_StartValue16 = Crc_StartValue16 ^ CRC_CRC16_XOR_VALUE;
    }    
    /* process every byte of the message */
    for(LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL; LoopCounter < Crc_Length; 
        LoopCounter++)
    {
      Crc_StartValue16 ^= (uint16)((uint16)Crc_DataPtr[LoopCounter] << 
                          (CRC_CRC16_SIZE - CRC_EIGHT_U));
    for(MessageBit = CRC_LOOPCNT_MSGBIT_INIT_VAL; MessageBit > CRC_ZERO_U; 
        --MessageBit)
    {
      if((Crc_StartValue16 & CRC_CRC16_MSB)==CRC_CRC16_MSB)
      {
        /* If MSB is 1 then left shift and X-OR with polynomial*/ 
        Crc_StartValue16 = (uint16)((uint16)Crc_StartValue16 << CRC_SHIFT_ONE) 
                           ^ CRC_CRC16_POLYNOMIAL;
      
      }
      else
      {
        /* If MSB is 0 then left shift and X-OR with polynomial*/
        Crc_StartValue16 = (uint16)((uint16)Crc_StartValue16 << CRC_SHIFT_ONE);
      }
     }
    }
  Crc_StartValue16 = CRC_CRC16_XOR_VALUE ^ Crc_StartValue16;
  return Crc_StartValue16;
 }

  #elif (CRC_16_MODE == CRC_TABLE_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint16 Crc_lCalculateCRC16Table                               **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint16 Crc_StartValue16,                                            **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue16 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint16                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**   xor value  and returns the CRC xored with XOR value                      **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint16 Crc_lCalculateCRC16Table( const uint8* Crc_DataPtr, 
  uint32 Crc_Length,  uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
  {
  /* code for crc 16 Table based calculaion with 0x1021 polynomial*/
    uint32 LoopCounter;
    uint16 TempLocal;
    uint16 DataVal;
    /*Initialization of Table array*/
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
      Crc_StartValue16 = CRC_INITIAL_VALUE16;
    }
    else
    {
      Crc_StartValue16 = Crc_StartValue16 ^ CRC_CRC16_XOR_VALUE;
    }    
    for(LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL; LoopCounter < Crc_Length; 
        LoopCounter++)
    {      
      DataVal = (uint16)(Crc_DataPtr[LoopCounter]);
      TempLocal = (uint16)(( (uint16)(Crc_StartValue16 >> CRC_SHIFT_EIGHT) ^
                  DataVal) & (uint16)CRC_ONEBYTEAND_VAL);
                  
      Crc_StartValue16 = (uint16)((uint16)(Crc_StartValue16 & 
      (uint16)CRC_ONEBYTEAND_VAL) << CRC_SHIFT_EIGHT) ^ Crc_Table16[TempLocal];
      
    }    
    Crc_StartValue16 = CRC_CRC16_XOR_VALUE ^ Crc_StartValue16;
    return Crc_StartValue16;
  }
  #elif (CRC_16_MODE == CRC_HARDWARE_MODE)
/*******************************************************************************
** Traceability     : [cover parentID=DS_MCAL_SWSC_CRC_0443_2,
                       DS_MCAL_SWSC_CRC_0444_2]
[/cover]
**                                                                            **
** Syntax     : uint16 Crc_lCalculateCRC16Hardware                            **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint16 Crc_StartValue16,                                            **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue16 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint16                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc using the hardware and returns the CRC    **
**   xored with the XOR_VALUE                                                 **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint16 Crc_lCalculateCRC16Hardware( const uint8* Crc_DataPtr, 
  uint32 Crc_Length,  uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
  {
    /*Take the backup of CRC reg to ensure reentrancy*/
    uint32 LoopCounter;
    uint16 tempVal=CRC_INIT_VAL;
    uint16 CRC_RegBackup;
    

    CRC_RegBackup = (uint16)FCE0_IN2_CRC.B.CRC;

    /* code for crc 16 hardware calculaion with 0x1021 polynomial*/
    /* reset end init protection to enable FCE using CLC register*/  
    
    /*Configure CRC register*/
    if (Crc_IsFirstCall == (boolean)TRUE)
    {
      FCE0_IN2_CRC.B.CRC = CRC_INITIAL_VALUE16;
    }
    else
    {
      FCE0_IN2_CRC.B.CRC = Crc_StartValue16 ^ CRC_CRC16_XOR_VALUE;
    }
       
    /* input in INIT register */
    for (LoopCounter = CRC_ZERO_U; LoopCounter < Crc_Length; LoopCounter+=
         CRC_TWO_U)
    {
      if( (LoopCounter/CRC_TWO_U) == (Crc_Length/CRC_TWO_U) )
      {
        tempVal = (uint16)((uint16)Crc_DataPtr[LoopCounter] << 
                  CRC_SHIFT_EIGHT);
      }
      else
      {
        tempVal = Crc_DataPtr[LoopCounter];
        tempVal= tempVal << CRC_SHIFT_EIGHT;
        tempVal = tempVal ^ Crc_DataPtr[LoopCounter + CRC_ONE_U];
      }
      FCE0_IN2_IR.U = tempVal;
    }
    Crc_StartValue16 = (uint16)FCE0_IN2_RES.B.RES;
    

    FCE0_IN2_CRC.B.CRC = CRC_RegBackup ;    
    return Crc_StartValue16;
  }
  #endif
  /* #endif for (CRC_16_MODE == CRC_HARDWARE_MODE)*/
  #endif
  /*#endif for #ifdef CRC_16_MODE*/

  #ifdef CRC_32_MODE
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint32 Crc_lReflectCRC32                                      **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint8 CRC_BitCount                                                  **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_Length -Start value for CRC Calculation             **
**        CRC_BitCount -Boolean to decide the start value                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint16                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the 32bit crc data and length of the data, calculates**
**   reverses it and return back.                                             **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint32 Crc_lReflectCRC32(uint32 CRCData_32bit, uint8 CRC_BitCount)
  {
    uint32  ReversedData=CRC_INIT_VAL;
    uint8  MsgBit;

    for (MsgBit = CRC_ZERO_U; MsgBit < CRC_BitCount; ++MsgBit)
    {
      if (CRCData_32bit & CRC_ONE_U)
      {
        ReversedData |= (uint32)((uint32)CRC_ONE_U << 
                  ((CRC_BitCount - CRC_ONE_U) - MsgBit));
      }

     CRCData_32bit = (uint32)((uint32)CRCData_32bit >> (uint32)CRC_ONE_U);
    }
  
   return (ReversedData);
  }

  #if  CRC_32_MODE == CRC_RUNTIME_MODE
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint32 Crc_lCalculateCRC32Runtime                             **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint32 Crc_StartValue32,                                            **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue32 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**          *                                                                 **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint32                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the CRC value and returns the CRC xored with      **
**   XOR value                                                                **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint32 Crc_lCalculateCRC32Runtime( const uint8* Crc_DataPtr,
  uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
  {
  /* code for crc 32 runtime calculaion with 0x04C11DB7 polynomial*/
    uint32 LoopCounter;
    uint32 TempVal;
    uint8 MessageBit;
    
    
    /* if it is first call assign initial value to the start value */
    if(Crc_IsFirstCall ==(boolean)TRUE)
    {
      Crc_StartValue32 = CRC_INITIAL_VALUE32;
    }
    else
    {
      Crc_StartValue32 = Crc_StartValue32 ^ CRC_CRC32_XOR_VALUE;
      Crc_StartValue32 = Crc_lReflectCRC32(Crc_StartValue32,
                         CRC_BITCNT_THIRTYTWO);        
    }  
    /* code for reversing */
    for (LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL ; LoopCounter <  Crc_Length 
         ;LoopCounter++)
    {
      /*for each 32 bit block */
      TempVal = Crc_lReflectCRC32((uint32)Crc_DataPtr[LoopCounter],
                CRC_BITCNT_EIGHT);
      Crc_StartValue32 ^=  TempVal << (CRC_CRC32_SIZE - CRC_EIGHT_U);
      for( MessageBit = CRC_LOOPCNT_MSGBIT_INIT_VAL; MessageBit > CRC_ZERO_U; 
           --MessageBit)
      {
        if((Crc_StartValue32 & CRC_CRC32_MSB) == CRC_CRC32_MSB)
        {
          /* If MSB is 1 then left shift and X-OR with polynomial*/
          Crc_StartValue32 = (Crc_StartValue32 << CRC_SHIFT_ONE) ^ 
          CRC_CRC32_POLYNOMIAL;
        }
      else
      {
        /* If MSB is 0 then left shift and X-OR with polynomial*/
        Crc_StartValue32 = (Crc_StartValue32 << CRC_SHIFT_ONE);
      }
    }
   }
    Crc_StartValue32 = Crc_lReflectCRC32(Crc_StartValue32,
                       CRC_BITCNT_THIRTYTWO);
    Crc_StartValue32 = CRC_CRC32_XOR_VALUE ^ Crc_StartValue32;
    return Crc_StartValue32;
  }
  #elif  (CRC_32_MODE == CRC_TABLE_MODE)
/*******************************************************************************
** Traceability   :                                                           **
**                                                                            **
** Syntax     : uint32 Crc_lCalculateCRC32Table                               **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint32 Crc_StartValue32,                                            **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue32 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint32                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc taking the precomputed                    **
**    and reversed xor value  and returns the CRC xored with XOR value        **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint32 Crc_lCalculateCRC32Table( const uint8* Crc_DataPtr, 
  uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
  {
  /* code for crc 32 table based calculaion with 0x04C11DB7 polynomial*/
    uint32 LoopCounter = CRC_INIT_VAL;
    uint32 Temp32;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
      Crc_StartValue32 = CRC_INITIAL_VALUE32;
    }
    else
    {
      Crc_StartValue32 = Crc_StartValue32 ^ CRC_CRC32_XOR_VALUE;
      Crc_StartValue32 = Crc_lReflectCRC32(Crc_StartValue32,
      CRC_BITCNT_THIRTYTWO);  

    }    
    /*Extract each byte from the message, fetch the value from lookup 
    table and XOR with the crc value*/
    for(LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL;LoopCounter < Crc_Length; 
    LoopCounter++)
    {
      Temp32 = Crc_lReflectCRC32((uint32)Crc_DataPtr[LoopCounter],
               CRC_BITCNT_EIGHT);
    Temp32 = ((uint32) ((uint32)Crc_StartValue32 >> CRC_SHIFT_TWENTYFOUR) ^
             Temp32) & CRC_ONEBYTEAND_VAL;
    Crc_StartValue32 = (uint32)((uint32)Crc_StartValue32 << CRC_SHIFT_EIGHT) ^ 
                       Crc_Table32[Temp32];   
    }
    Crc_StartValue32 = Crc_lReflectCRC32(Crc_StartValue32,
                       CRC_BITCNT_THIRTYTWO);   
    Crc_StartValue32 = CRC_CRC32_XOR_VALUE ^ Crc_StartValue32;
    return Crc_StartValue32;  
  }
  #elif  (CRC_32_MODE == CRC_HARDWARE_MODE)
/*******************************************************************************
** Traceability     : [cover parentID=DS_MCAL_SWSC_CRC_0443_3,
                       DS_MCAL_SWSC_CRC_0444_3]
[/cover]
**                                                                            **
** Syntax     : uint32 Crc_lCalculateCRC32Hardware                            **
**      (                                                                     **
**        const uint8* Crc_DataPtr,                                           **
**        uint32 Crc_Length,                                                  **
**        uint32 Crc_StartValue32,                                            **
**        boolean Crc_IsFirstCall                                             **
**      )                                                                     **
**                                                                            **
**                                                                            **
** Service ID     : none                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : reentrant                                                 **
**                                                                            **
** Parameters (in)  : Crc_DataPtr  - Pointer to the start of the datablock    **
**        Crc_Length - Length of the input data to be fetched                 **
**        Crc_StartValue32 -Start value for CRC Calculation                   **
**        Crc_IsFirstCall -Boolean to decide the start value                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value   : uint32                                                    **
**                                                                            **
** Description    :                                                           **
** - This function takes the value of input data pointer, start value and     **
**   polynomial, calculates the crc using the hardware and returns the CRC    **
**   reversed and xored with the XOR_VALUE                                    **
** - This function is local to the library module and is not for the user of  **
**   CRC Library                                                              **
**                                                                            **
*******************************************************************************/
  static uint32 Crc_lCalculateCRC32Hardware( const uint8* Crc_DataPtr, 
  uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
  {
    /*Take the backup of CRC reg to ensure reentrancy*/
    uint32 CRC_RegBackup;
    uint32 LoopCounter;
    uint32 tempVal;   
    
    CRC_RegBackup = (uint32)FCE0_IN0_CRC.B.CRC;
    /* code for crc 32 hardware calculaion with 0x04C11DB7 polynomial*/    
    /*Configure CRC register*/
    if (Crc_IsFirstCall == (boolean)TRUE)
    {
      FCE0_IN0_CRC.B.CRC = CRC_INITIAL_VALUE32;
    }
    else
    {
      Crc_StartValue32 = Crc_StartValue32 ^ CRC_CRC32_XOR_VALUE;  
      FCE0_IN0_CRC.B.CRC = (uint32)(Crc_lReflectCRC32(Crc_StartValue32,
      CRC_BITCNT_THIRTYTWO));  
    }
        
     /* input in INIT register */          
    
    for (LoopCounter = CRC_LOOPCNT_MSGBYTE_INIT_VAL; LoopCounter < Crc_Length;
         LoopCounter += CRC_FOUR_U)
    {
    
      if((LoopCounter/CRC_FOUR_U)== (Crc_Length/CRC_FOUR_U))
       {
         tempVal=CRC_INIT_VAL;
         if((Crc_Length % CRC_FOUR_U) == CRC_ONE_U)
         {
           tempVal = (uint32)((uint32)Crc_DataPtr[LoopCounter] << 
           CRC_SHIFT_TWENTYFOUR);
         }
         if((Crc_Length % CRC_FOUR_U) == CRC_TWO_U)
         {
           tempVal = (uint32)((uint32)Crc_DataPtr[LoopCounter] <<
           CRC_SHIFT_TWENTYFOUR);         
           tempVal = (uint32)(tempVal | 
           (uint32)((uint32)Crc_DataPtr[LoopCounter+CRC_ONE_U] << 
           CRC_SHIFT_SIXTEEN));
         }
         if((Crc_Length % CRC_FOUR_U) == CRC_THREE_U)
         {
           tempVal = (uint32)((uint32)Crc_DataPtr[LoopCounter] << 
                     CRC_SHIFT_TWENTYFOUR);         
           tempVal = (uint32)(tempVal | 
                     (uint32)((uint32)Crc_DataPtr[LoopCounter+CRC_ONE_U] <<
                     CRC_SHIFT_SIXTEEN));
           tempVal = (uint32)(tempVal | 
                     (uint32)((uint32)Crc_DataPtr[LoopCounter+CRC_TWO_U] << 
                     CRC_SHIFT_EIGHT));
         }
     
       }
       else
       {   
         tempVal = (uint32)((uint32)Crc_DataPtr[LoopCounter + CRC_ZERO_U] << 
                   CRC_SHIFT_TWENTYFOUR) | 
                   (uint32)((uint32)Crc_DataPtr[LoopCounter + CRC_ONE_U] << 
                   CRC_SHIFT_SIXTEEN) | 
                   (uint32)((uint32)Crc_DataPtr[LoopCounter + CRC_TWO_U] << 
                   CRC_SHIFT_EIGHT) |
                   (Crc_DataPtr[LoopCounter + CRC_THREE_U]);
       }    
       FCE0_IN0_IR.U = tempVal;       
    }
    Crc_StartValue32 = FCE0_IN0_RES.U;
    /*restore CRC reg to ensure reentrancy*/   
    FCE0_IN0_CRC.U = CRC_RegBackup ; 
    
    /* set end init protection once FCE is disabled */    
    return Crc_StartValue32;
  }
   #endif
   #endif
 

 #if (CRC_SAFETY_ENABLE == STD_ON) 
/******************************************************************************
** Traceability     : [cover parentID=DS_MCAL_SWSC_CRC_0447_5]
[/cover]
** Syntax : static uint32 Crc_lCrcCalculationSafetyCheck                     **
**                                  (                                        **
**                                    const uint8* Crc_DataPtr               **
**                                    boolean Crc_IsFirstCall                **
**                                    uint32 Crc_Length                      **
**                                    uint8 ServiceId                        **
**                                  )                                        **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Crc_DataPtr : Crc Input Data pointer                   **
**                    Crc_IsFirstCall: TRUE/FALSE                            **
**                    Crc_Length: required number of bytes to be calculated  **
**                    ServiceId: Id of the API                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint8)                                      **
**                                                                           **
** Description :      Local function :Service for safety check in            **
**                                   Crc_CalculateCRC8()                     **
**                                   Crc_CalculateCRC16()                    **
**                                   Crc_CalculateCRC32()                    **
**                                   Crc_CalculateCRC8H2F                    **
**                                                                           **
*****************************************************************************/
static uint8 Crc_lCrcCalculationSafetyCheck
(
  const uint8* Crc_DataPtr,
  boolean Crc_IsFirstCall,
  uint32 Crc_Length,
  uint8 ServiceId 
)
{
  /* Verify any error is there for safety report */  
  uint8 ErrorFlag;      
  /*Initialize Error Flag with No Error*/
  ErrorFlag = CRC_ERR_NOT_FOUND;
  if((Crc_DataPtr == NULL_PTR) || \
                     (Crc_DataPtr[Crc_Length] !=CRC_DATAPTR_MARKER_VALUE))
  {
    /*Error flag is set*/
    ErrorFlag = CRC_ERR_FOUND; 
    /* Report an error */
    SafeMcal_ReportError ((uint16)CRC_MODULE_ID,CRC_INSTANCE_ID,
                          ServiceId,CRC_E_PARAM_DATAPTR); 
                      
  }   
  if (ErrorFlag != CRC_ERR_FOUND)
  { 
    if((Crc_IsFirstCall != (boolean)TRUE) && \
                            (Crc_IsFirstCall != (boolean)FALSE))
    {
      /*Error flag is set*/
      ErrorFlag = CRC_ERR_FOUND;
      /* Report an error */
      SafeMcal_ReportError ((uint16)CRC_MODULE_ID,CRC_INSTANCE_ID,
                            ServiceId,CRC_E_PARAM_FIRSTCALL);
    }
  }   
  return (ErrorFlag);
} 

#endif /* #if (CRC_SAFETY_ENABLE == STD_ON) */

 
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
