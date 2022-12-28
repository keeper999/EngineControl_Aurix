/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RTMCKS                                                  */
/* !Description     : Real Time Monitoring: Memory Checksum Control           */
/*                                                                            */
/* !File            : RTMCKS_1.c                                              */
/* !Description     : RTMCKS Checksums procedures                             */
/*                                                                            */
/* !Reference       : PON EEM NT 05 2429#002                                  */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:RTMCKS 1 C-99057335X5000X1086.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "RTMCKS.h"
#include "RTMCKS_Cfg.h"


/******************************************************************************/
/* Check that Conditionnal Compilation define are defined                     */
/******************************************************************************/
#ifndef RTMCKS_coDATA_SIZE
   #error "Define RTMCKS_coDATA_SIZE is undefined"
#endif


#define RTMCKS_START_SEC_CODE
#include "RTMCKS_MemMap.h"

/******************************************************************************/
/* !FuncName    : RTMCKS_vidCalcChecksumOfU8                                  */
/* !Description : Compute checksum of bytes with a result on word             */
/*                                                                            */
/* !LastAuthor  :  E. Riad                                                    */
/******************************************************************************/

#ifdef RTMCKS_coU16_CHECKSUM_OF_U8

void RTMCKS_vidCalcChecksumOfU8
(
   int                enuMode,
   RTMCKS_tCksDataRef pudtStartAddress,
   RTMCKS_tCksDataRef pudtEndAddress,
   RTMCKS_tResultRef  pudtChecksumRef
)
{
   RTMCKS_udtDataType udtData;
   RTMCKS_tResult     udtChecksum;
   uint8              u8DataByte;
   uint8 *            pu8DataByteRef;
   uint8 *            pu8DataByteEndRef;

   udtChecksum = *pudtChecksumRef;
   if (enuMode == RTMCKS_ALIGNED)
   {
      while (pudtStartAddress < pudtEndAddress)
      {
         udtData = *pudtStartAddress;
         pudtStartAddress++;
         #if RTMCKS_coDATA_SIZE == 4
            udtChecksum += (RTMCKS_tResult)(udtData & 0x000000FF);
            udtData = udtData >> 8;
            udtChecksum += (RTMCKS_tResult)(udtData & 0x000000FF);
            udtData = udtData >> 8;
         #endif

         #if RTMCKS_coDATA_SIZE >= 2
            udtChecksum += (RTMCKS_tResult)(udtData & 0x000000FF);
            udtData = udtData >> 8;
         #endif

         udtChecksum += (RTMCKS_tResult)(udtData & 0x000000FF);
      }
   }
   else
   {
      pu8DataByteRef    = (uint8*)pudtStartAddress;
      pu8DataByteEndRef = (uint8*)pudtEndAddress;
      while (pu8DataByteRef < pu8DataByteEndRef)
      {
         u8DataByte = *pu8DataByteRef;
         pu8DataByteRef++;
         udtChecksum += (RTMCKS_tResult)u8DataByte;
      }
   }
   *pudtChecksumRef = udtChecksum;
}

#endif /* RTMCKS_coU16_CHECKSUM_OF_U8 */

#define RTMCKS_STOP_SEC_CODE
#include "RTMCKS_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
