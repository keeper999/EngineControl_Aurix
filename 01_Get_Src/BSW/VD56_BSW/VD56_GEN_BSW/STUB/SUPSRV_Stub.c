/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : STUB                                                    */
/* !Description     : Stub of SRV components                                  */
/*                                                                            */
/* !File            : SUPSRV_Stub.c                                           */
/* !Description     : Stub of SUPSRV component                                */
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
 * %PID: P2017_BSW:0A192531.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "SUPSRV.h"


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define SUPSRV_START_SEC_CODE
#include "SUPSRV_MemMap.h"

uint16 SUPSRV_u16ReadAppliKey
(
   uint8 *pau8Buffer,  /* !Comment : Buffer that contains request result      */
   uint16 u16MaxSize   /* !Comment : Maximum output buffer size               */
)
{
   COMPILER_UNUSED_PARAMETER(pau8Buffer);
   COMPILER_UNUSED_PARAMETER(u16MaxSize);
   return(UINT16_MIN);
}

uint16 SUPSRV_u16ReadHistoryArea
(
   uint8  u8LidId,     /* !Comment : History Area number to read              */
                       /* !Range   : 0xF0..0xFF                               */
   uint8 *pau8Buffer,  /* !Comment : Buffer that contains request result      */
   uint16 u16MaxSize   /* !Comment : Maximum output buffer size               */
)
{
   COMPILER_UNUSED_PARAMETER(u8LidId);
   COMPILER_UNUSED_PARAMETER(pau8Buffer);
   COMPILER_UNUSED_PARAMETER(u16MaxSize);
   return(UINT16_MIN);
}

Std_ReturnType SUPSRV_udtJumpToFinalTest
(
   uint8 u8TprodParameter    /* !Comment: Third Parameter, Specific for Test  */
)
{
   COMPILER_UNUSED_PARAMETER(u8TprodParameter);
   return(E_NOT_OK);
}

Std_ReturnType SUPSRV_udtJumpToReliabTest
(
   uint8 u8TprodParameter    /* !Comment: Third Parameter, Specific for Test  */
)
{
   COMPILER_UNUSED_PARAMETER(u8TprodParameter);
   return(E_NOT_OK);
}

uint16 SUPSRV_u16ReadFuncProdNr
(
   uint8 *pau8Buffer,  /* !Comment : Buffer that contains request result      */
   uint16 u16MaxSize   /* !Comment : Maximum output buffer size               */
)
{
   COMPILER_UNUSED_PARAMETER(pau8Buffer);
   COMPILER_UNUSED_PARAMETER(u16MaxSize);
   return(UINT16_MIN);
}

uint16 SUPSRV_u16ReadFuncSchemNr
(
   uint8 *pau8Buffer,  /* !Comment : Buffer that contains request result      */
   uint16 u16MaxSize   /* !Comment : Maximum output buffer size               */
)
{
   COMPILER_UNUSED_PARAMETER(pau8Buffer);
   COMPILER_UNUSED_PARAMETER(u16MaxSize);
   return(UINT16_MIN);
}

uint16 SUPSRV_u16ECUIdentification
(
   uint8 *pau8Buffer,  /* !Comment : Buffer that contains request result      */
   uint16 u16MaxSize   /* !Comment : Maximum output buffer size               */
)
{
   COMPILER_UNUSED_PARAMETER(pau8Buffer);
   COMPILER_UNUSED_PARAMETER(u16MaxSize);
   return(UINT16_MIN);
}

uint8* SUPSRV_pu8AftSaleReadBaseAddr(void)
{
   return( (uint8 *)SUPSRV_u32AFTER_SALE_AREA_ADDRESS_BEG);
}

uint16 SUPSRV_u16AftSaleReadBlockSize(void)
{
   return(SUPSRV_u16AFTER_SALE_AREA_GRANULATITY);
}

Std_ReturnType SUPSRV_udtAftSaleWriteFlash
(
   const uint8 *pku8SourceAddress,  /* !Comment: Source address of data to    */
                                    /*           write                        */
   uint8       *pu8TargetAddress,   /* !Comment: Target address in flash      */
   uint32       u32Length           /* !Comment: Length of data buffer to     */
                                    /*           write                        */
)
{
   COMPILER_UNUSED_PARAMETER(pku8SourceAddress);
   COMPILER_UNUSED_PARAMETER(pu8TargetAddress);
   COMPILER_UNUSED_PARAMETER(u32Length);
   return(E_NOT_OK);
}

uint8 SUPSRV_u8UnlockAlgorithm
(
   uint8 *pau8Seed,         /* !Comment: Seed Pointer                         */
   uint8  u8SeedSize,       /* !Comment: Seed Size                            */
   uint8 *pau8UnlockKey     /* !Comment: Unlocking Key Pointer                */
)
{
   COMPILER_UNUSED_PARAMETER(pau8Seed);
   COMPILER_UNUSED_PARAMETER(u8SeedSize);
   COMPILER_UNUSED_PARAMETER(pau8UnlockKey);
   return(UINT8_MIN);
}

#define SUPSRV_STOP_SEC_CODE
#include "SUPSRV_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
