/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MEMSRV                                                  */
/* !Description     : Memory management services                              */
/*                                                                            */
/* !File            : MEMSRV.c                                                */
/* !Description     : API of the MEMSRV component                             */
/*                                                                            */
/* !Reference       : PON EEM NT 05 1920 01                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MEMSRV API C-99055480X4420X504.A-SRC;1.1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "MEMSRV.h"

/******************************************************************************/
/* GLOBAL FUNCTIONS DEFINITION                                                */
/******************************************************************************/

#define MEMSRV_START_SEC_CODE
#include "MEMSRV_MemMap.h"

/******************************************************************************/
/* !Description : Copy a 8 bits buffer of u16ElementNumber.                   */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
void MEMSRV_vidCopyU8
(
   uint8       * pu8Dest,           /* !Comment: Destination buffer address   */
   const uint8 * pu8Src,            /* !Comment: Source buffer address        */
   uint16        u16ElementNumber   /* !Comment: length in bytes of buffer    */
)
{
/* !Comment: using microcontroller register length optimize the indice        */
/*           loop treatment                                                   */
   uint16_least u16LoopIndice;

   u16LoopIndice = (uint16_least)u16ElementNumber;
/* !Comment : "if-do-while" is less %CPU than a while loop for Keil           */
/*            compilateur this structure uses one register less on Hitachi    */
   if (u16LoopIndice > 0)
   {
      do
      {
         /* !Comment: the post-increment only on pu8Src optimizes Keil        */
         /*           Compilateur no impact for Hitachi                       */
         *pu8Dest = *pu8Src++;
         pu8Dest++;

         u16LoopIndice--;
      }
      while (u16LoopIndice > 0);
   }
}

/******************************************************************************/
/* !Description : Copy a 16 bits buffer of u16ElementNumber.                  */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
void MEMSRV_vidCopyU16
(
   uint16       * pu16Dest,         /* !Comment: Destination buffer address   */
   const uint16 * pu16Src,          /* !Comment: Source buffer address        */
   uint16         u16ElementNumber  /* !Comment: length in words of buffer    */
)
{
   uint16_least u16LoopIndice;

   u16LoopIndice = (uint16_least)u16ElementNumber;
   if (u16LoopIndice > 0)
   {
      do
      {
         *pu16Dest = *pu16Src++;
         pu16Dest++;

         u16LoopIndice--;
      }
      while (u16LoopIndice > 0);
   }
}

/******************************************************************************/
/* !Description : Copy a 32 bits buffer of u16ElementNumber.                  */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
void MEMSRV_vidCopyU32
(
   uint32       * pu32Dest,         /* !Comment: Destination buffer address   */
   const uint32 * pu32Src,          /* !Comment: Source buffer address        */
   uint16         u16ElementNumber  /* !Comment: length in double-words       */
)
{
   uint16_least u16LoopIndice;

   u16LoopIndice = (uint16_least)u16ElementNumber;
   if (u16LoopIndice > 0)
   {
      do
      {
         /* !Comment: no post-increment during the copy is optimized for u32  */
         /*           on ST10 no impact for Hitachi                           */
         *pu32Dest = *pu32Src;
         pu32Dest++;
         pu32Src++;

         u16LoopIndice--;
      }
      while (u16LoopIndice > 0);
   }
}

/******************************************************************************/
/* !Description : Set a 8 bits buffer of u16ElementNumber to u8Value value    */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
void MEMSRV_vidSetU8
(
   uint8 * pu8Dest,           /* !Comment: Buffer address                     */
   uint8   u8Value,           /* !Comment: Expected fill value of the buffer  */
   uint16  u16ElementNumber   /* !Comment: length in bytes of buffer          */
)
{
   uint16_least u16LoopIndice;

   u16LoopIndice = (uint16_least)u16ElementNumber;
   if (u16LoopIndice > 0)
   {
      do
      {
         *pu8Dest = u8Value;
         pu8Dest++;

         u16LoopIndice--;
      }
      while (u16LoopIndice > 0);
   }
}

/******************************************************************************/
/* !Description : Set a 16 bits buffer of u16ElementNumber to u8Value value   */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
void MEMSRV_vidSetU16
(
   uint16 * pu16Dest,         /* !Comment: Buffer address                     */
   uint16   u16Value,         /* !Comment: Expected fill value of the buffer  */
   uint16   u16ElementNumber  /* !Comment: length in words of buffer          */
)
{
   uint16_least u16LoopIndice;

   u16LoopIndice = (uint16_least)u16ElementNumber;
   if (u16LoopIndice > 0)
   {
      do
      {
         *pu16Dest = u16Value;
         pu16Dest++;

         u16LoopIndice--;
      }
      while (u16LoopIndice > 0);
   }
}

/******************************************************************************/
/* !Description : Set a 32 bits buffer of u16ElementNumber to u8Value value   */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
void MEMSRV_vidSetU32
(
   uint32 * pu32Dest,         /* !Comment: Buffer address                     */
   uint32   u32Value,         /* !Comment: Expected fill value of the buffer  */
   uint16   u16ElementNumber  /* !Comment: length in double-words of buffer   */
)
{
   uint16_least u16LoopIndice;

   u16LoopIndice = (uint16_least)u16ElementNumber;
   if (u16LoopIndice > 0)
   {
      do
      {
         *pu32Dest = u32Value;
         pu32Dest++;

         u16LoopIndice--;
      }
      while (u16LoopIndice > 0);
   }
}

#define MEMSRV_STOP_SEC_CODE
#include "MEMSRV_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
