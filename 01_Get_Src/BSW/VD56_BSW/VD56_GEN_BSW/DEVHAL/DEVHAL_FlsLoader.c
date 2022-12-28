/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : FLSLOADER                                               */
/* !Description     : FLSLOADER Component                                     */
/*                                                                            */
/* !File            : DEVHAL_FlsLoader.c                                      */
/* !Description     : APIs of FLSLOADER Component                             */
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

#include "Std_Types.h"
#include "FlsLoader.h"
#include "DEVHAL_I.h"
#include "DEVHAL_Def.h"

/*#define NB_BYTES     0x200*/

#define DEVHAL_START_SEC_CODE_COPY_CALIB
#include "DEVHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : DEVHAL_vidInitFlsLoader                                     */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidInitFlsLoader(void)
{
   FlsLoader_ReturnType retval;

   DEVHAL_bIsFlsLoaderInitialized = FALSE;
   DEVHAL_bIsFlsLoaderErased = FALSE;
   DEVHAL_bIsFlsLoaderCopied = FALSE;

   retval = FlsLoader_Init(NULL_PTR);
   if (retval == FLSLOADER_E_OK)
   {
      DEVHAL_bIsFlsLoaderInitialized = TRUE;
   }
   else
   {
      if (retval == FLSLOADER_E_NOT_OK)
      {
         /* !Comment: Calibration cannot be erased                            */
         DEVHAL_bIsFlsLoaderInitialized = FALSE;
      }
      else
      {
         if(retval == FLSLOADER_E_ROMVERSION)
         {
            /* !Comment: Calibration cannot be erased                         */
            DEVHAL_bIsFlsLoaderInitialized = FALSE;
         }
      }
   }
}
/******************************************************************************/
/* !FuncName    : DEVHAL_vidEraseCalib                                        */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidEraseCalib(uint32 u32StartAddress, uint32 u32NbSectors)
{
   FlsLoader_ReturnType retval;


   DEVHAL_bIsFlsLoaderErased = FALSE;

   if (DEVHAL_bIsFlsLoaderInitialized == TRUE)
   {
      retval =  FlsLoader_Erase((FlsLoader_AddressType)u32StartAddress, (FlsLoader_LengthType)u32NbSectors);

      if (retval == FLSLOADER_E_OK)
      {
         DEVHAL_bIsFlsLoaderErased = TRUE;
      }
      else
      {
         if (retval == FLSLOADER_E_NOT_OK)
         {
            DEVHAL_bIsFlsLoaderErased = FALSE;
         }
         else
         {
            if (retval == FLSLOADER_E_ROMVERSION)
            {
               DEVHAL_bIsFlsLoaderErased = FALSE;
            }
         }
      }
   }
}
/******************************************************************************/
/* !FuncName    : DEVHAL_vidCopyCalib                                         */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidCopyCalib(uint32 u32SrcStartAddress, uint32 u32DestStartAddress, uint32 u32NbOfBytes)
{
   FlsLoader_ReturnType retval;


   /*uint32 u32LocalIndex;
   uint8 * ui8calibBuffer = (uint8 *)ui32FromStartAddress;
   FlsLoader_AddressType FlsToAddress = (FlsLoader_AddressType)ui32ToStartAddress;
     */
   /*for ( u32LocalIndex = 0 ; u32LocalIndex <=  (ui32NbOfBytes - NB_BYTES) ; u32LocalIndex+= NB_BYTES)
   {
      retval = FlsLoader_Write(FlsToAddress, NB_BYTES, ui8calibBuffer);

      ui8calibBuffer += NB_BYTES;
      FlsToAddress   += NB_BYTES;
   }*/
   if (DEVHAL_bIsFlsLoaderInitialized == TRUE)
   {
      retval = FlsLoader_Write((FlsLoader_AddressType)u32DestStartAddress, (FlsLoader_LengthType)u32NbOfBytes, (uint8 *)u32SrcStartAddress);

      if (retval == FLSLOADER_E_OK)
      {
         DEVHAL_bIsFlsLoaderCopied = TRUE;
      }
      else
      {
         if (retval == FLSLOADER_E_NOT_OK)
         {
            DEVHAL_bIsFlsLoaderCopied = TRUE;
         }
         else
         {
            if (retval == FLSLOADER_E_ROMVERSION)
            {
               DEVHAL_bIsFlsLoaderCopied = TRUE;
            }
         }
      }
   }
}

#define DEVHAL_STOP_SEC_CODE_COPY_CALIB
#include "DEVHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
