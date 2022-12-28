/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RTMCKS                                                  */
/* !Description     : Real Time Monitoring: Memory Checksum Control           */
/*                                                                            */
/* !File            : RTMCKS_.c                                               */
/* !Description     : RTMCKS component External APIs                          */
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
 * %PID: LIBEMB:RTMCKS  C-99057334X5000X1084.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "RTMCKS.h"
#include "SWFAIL.h"

#define RTMCKS_START_SEC_CODE
#include "RTMCKS_MemMap.h"

/******************************************************************************/
/* !FuncName    : RTMCKS_vidInit                                              */
/* !Description : Init component function                                     */
/*                                                                            */
/* !LastAuthor  :  E. Riad                                                    */
/******************************************************************************/
void RTMCKS_vidInit(void)
{
   RTMCKS_tudtChannel udtLocalChannel;


   for(udtLocalChannel = 0; udtLocalChannel < RTMCKS_udtCHANNELS_NUMBER; udtLocalChannel++)
   {
      RTMCKS_astrValues[udtLocalChannel].udtIndex       = 0;
      RTMCKS_astrValues[udtLocalChannel].bfSelect       = ((1 << RTMCKS_kau8NbOfArea[udtLocalChannel]) - 1);
      RTMCKS_astrValues[udtLocalChannel].bfSelectMask   = 1;
      RTMCKS_astrValues[udtLocalChannel].udtResultValue = 0;
      RTMCKS_astrValues[udtLocalChannel].udtZoneIdx     = 0;
      RTMCKS_astrValues[udtLocalChannel].pstrZoneConfig = &(RTMCKS_apstrZoneConfig[udtLocalChannel][0]);
      RTMCKS_astrValues[udtLocalChannel].u8StartZone    = 1;
   }
}

/******************************************************************************/
/* !FuncName    : RTMCKS_vidMainFunction                                      */
/* !Description : Main Function                                               */
/*                                                                            */
/* !LastAuthor  :  E. Riad                                                    */
/******************************************************************************/
void RTMCKS_vidMainFunction(RTMCKS_tudtChannel udtChannelName)
{
   RTMCKS_tCksDataRef     localRef;
   RTMCKS_tCksDataRef     localEndRef;
   RTMCKS_tIndexType      localCksIdx;
   RTMCKS_tbfSelectType   localSelectMask;
   RTMCKS_tZoneIndexType  localZoneIdx;
   RTMCKS_tResultRef      localCksRef;
   boolean                localZoneCompleted;
   RTMCKS_tstrMainObject *pstrLocalValues;


   if (udtChannelName < RTMCKS_udtCHANNELS_NUMBER)
   {
      pstrLocalValues = &(RTMCKS_astrValues[udtChannelName]);

      /* checksum calculation requested                                          */
      if ((pstrLocalValues->bfSelect & pstrLocalValues->bfSelectMask) != 0)
      {
         localCksRef = &(pstrLocalValues->udtResultValue);
         if (pstrLocalValues->u8StartZone != 0)
         {
            pstrLocalValues->u8StartZone = 0;

            localZoneIdx = pstrLocalValues->udtZoneIdx;
            localRef = RTMCKS_apstrAddress[udtChannelName][localZoneIdx].pudtStartAddress;
            localEndRef = (RTMCKS_tCksDataRef)( (uint32)localRef
                                             & ~(sizeof(RTMCKS_udtDataType) - 1));
            localEndRef++;
            pstrLocalValues->pudtCksAlignRef = localEndRef;

            /* calculates checksum on unaligned data starting the current zone   */
            if (localRef != localEndRef)
            {
               (pstrLocalValues->pstrZoneConfig->pfvidCalcFunc)(RTMCKS_NOT_ALIGNED,
                                                    localRef, localEndRef,
                                                    localCksRef);
            }

            localEndRef =
               (RTMCKS_tCksDataRef)((uint32)RTMCKS_apstrAddress[udtChannelName][localZoneIdx].pudtEndAddress + 1);
            localRef = (RTMCKS_tCksDataRef)( (uint32)localEndRef
                                          & ~(sizeof(RTMCKS_udtDataType) - 1));
            pstrLocalValues->pudtAlignEndRef = localRef;

            /* calculates checksum on unaligned data ending the current zone     */
            if (localRef != localEndRef)
            {
               (pstrLocalValues->pstrZoneConfig->pfvidCalcFunc)(RTMCKS_NOT_ALIGNED,
                                                    localRef, localEndRef,
                                                    localCksRef);
            }
         }
         /* defines block size and calculates checksum on it                     */
         localRef = pstrLocalValues->pudtCksAlignRef;
         localEndRef = pstrLocalValues->pudtAlignEndRef;
         localZoneCompleted = 1;
         if (RTMCKS_kau16BlockSize[udtChannelName] != 0)
         {
            if ( (uint32)((uint32)localEndRef - (uint32)localRef)
               > (RTMCKS_kau16BlockSize[udtChannelName] * sizeof(RTMCKS_udtDataType)))
            {
               localEndRef = (RTMCKS_tCksDataRef)( (uint32)localRef
                                             + ( RTMCKS_kau16BlockSize[udtChannelName]
                                               * sizeof(RTMCKS_udtDataType)));
               localZoneCompleted = 0;
            }
         }
         pstrLocalValues->pudtCksAlignRef = localEndRef;
         (pstrLocalValues->pstrZoneConfig->pfvidCalcFunc)(RTMCKS_ALIGNED,
                                              localRef, localEndRef,
                                              localCksRef);
         if (localZoneCompleted == 0)
         {
            return;
         }

         /* next zone																			   */
         pstrLocalValues->u8StartZone = 1;
         localZoneIdx = pstrLocalValues->udtZoneIdx;
         localZoneIdx++;
         pstrLocalValues->udtZoneIdx = localZoneIdx;
         if (localZoneIdx <= pstrLocalValues->pstrZoneConfig->udtLastZoneIdx)
         {
            return;
         }

         /* no more zone for the current checksum                                */
         /* checks checksum value																*/
         (pstrLocalValues->pstrZoneConfig->pfvidCheckFunc)(pstrLocalValues->udtResultValue);
      }

      /* next checksum                                                           */
      localCksIdx = pstrLocalValues->udtIndex;
      localCksIdx++;
      localSelectMask = pstrLocalValues->bfSelectMask << 1;
      localZoneIdx = pstrLocalValues->pstrZoneConfig->udtLastZoneIdx + 1;
      if (localCksIdx >= RTMCKS_kau8NbOfArea[udtChannelName])
      {
         localCksIdx = 0;
         localSelectMask = 1;
         localZoneIdx = 0;
      }
      pstrLocalValues->udtResultValue = 0;
      pstrLocalValues->bfSelectMask   = localSelectMask;
      pstrLocalValues->udtIndex       = localCksIdx;
      pstrLocalValues->pstrZoneConfig = &(RTMCKS_apstrZoneConfig[udtChannelName][localCksIdx]);
      pstrLocalValues->udtZoneIdx     = localZoneIdx;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   return;
}

/******************************************************************************/
/* !FuncName    : RTMCKS_vidAreaCheckDisable                                  */
/* !Description : Disable the check of one area                               */
/*                                                                            */
/* !LastAuthor  :  E. Riad                                                    */
/******************************************************************************/
void RTMCKS_vidAreaCheckDisable(RTMCKS_tudtChannel udtChannelName, uint8 u8AreaNumber)
{
   if (udtChannelName < RTMCKS_udtCHANNELS_NUMBER)
   {
      RTMCKS_astrValues[udtChannelName].bfSelect &= (RTMCKS_tbfSelectType)~(1 << u8AreaNumber);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define RTMCKS_STOP_SEC_CODE
#include "RTMCKS_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
