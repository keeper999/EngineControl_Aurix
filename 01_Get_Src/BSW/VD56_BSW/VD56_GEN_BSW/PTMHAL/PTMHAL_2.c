/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PTMHAL                                                  */
/* !Description     : Precise Teeth Measurement HAL Service Layer             */
/*                                                                            */
/* !File            : PTMHAL_2.c                                              */
/* !Description     : General sub-functions of the PTMHAL Component           */
/*                                                                            */
/* !Reference       : V03 NT 11 07330 / 02                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A149690.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "PTMHAL_I.h"
#include "SWFAIL.h"
#include "PTMHAL.h"
#include "PTMHAL_l.h"
#include "CRKHAL.h"

#define PTMHAL_START_SEC_CODE
#include "PTMHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PTMHAL_vidPSA3CylCfgManager                                 */
/* !Description : Calculate the duration packs taking into account the        */
/*                acquisition method                                          */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/

#ifndef PTMHAL_bPSA_3CYL_CFG_EN
   #error PTMHAL_bPSA_3CYL_CFG_EN not defined
#elif (PTMHAL_bPSA_3CYL_CFG_EN)

/* Modified ToothInfo */
void PTMHAL_vidPSA3CylCfgManager(void)
{
   uint32 u32LocalPackEndTimeStamp;
   uint32 u32LocalPackStartTimeStamp;

   if (PTMHAL_bFirstCalculEvtOccured != FALSE)
   {
      switch(((sint32)PTMHAL_u8CycleIndex))
      {
         case 0:
            CRKHAL_udtGetSpecificToothInfo(21, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(31, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[0] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;
      
            CRKHAL_udtGetSpecificToothInfo(36, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(46, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[1] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;
   
            CRKHAL_udtGetSpecificToothInfo(51, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(59, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[2] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(31, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(51, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[3] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;
            break;

         case 1:
            CRKHAL_udtGetSpecificToothInfo(59, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(69, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[0] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(74, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(84, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[1] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(89, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(99, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[2] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(69, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(89, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[3] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;
            break;

         case 2:
            CRKHAL_udtGetSpecificToothInfo(99, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(109, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[0] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(114, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(6, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[1] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(11, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(21, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[2] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;

            CRKHAL_udtGetSpecificToothInfo(109, PTMHAL_u8TIME_STAMP, &u32LocalPackStartTimeStamp);
            CRKHAL_udtGetSpecificToothInfo(11, PTMHAL_u8TIME_STAMP, &u32LocalPackEndTimeStamp);
            PTMHAL_au32DurationPack[3] = (u32LocalPackEndTimeStamp - u32LocalPackStartTimeStamp) & PTMHAL_TIME_STAMP_TIMER_MASK;
            break;

         default:
            for (PTMHAL_u8CycleIndex = UINT8_MIN; PTMHAL_u8CycleIndex < PTMHAL_u8MAX_NB_PACKS; PTMHAL_u8CycleIndex++)
            {
               PTMHAL_au32DurationPack[PTMHAL_u8CycleIndex] = UINT32_MIN;
            }
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
      PTMHAL_u8NbDurationPacksValid = PTMHAL_u8PSA_3CYL_CFG_NB_PACK;
   }
   else
   {
      PTMHAL_bFirstCalculEvtOccured = TRUE;
      PTMHAL_u8NbDurationPacksValid = UINT8_MIN;
   }
}

#endif /* ifndef PTMHAL_bPSA_3CYL_CFG_EN */

/******************************************************************************/
/* !FuncName    : PTMHAL_vidPSA4CylCfg1Manager                                */
/* !Description : Calculate the duration packs taking into account the        */
/*                acquisition method                                          */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/

#ifndef PTMHAL_bPSA_4CYL_CFG1_EN
   #error PTMHAL_bPSA_4CYL_CFG1_EN not defined
#elif (PTMHAL_bPSA_4CYL_CFG1_EN)

void PTMHAL_vidPSA4CylCfg1Manager(void)
{

   if (PTMHAL_bFirstCalculEvtOccured != FALSE)
   {
      if ( ( (sint32)PTMHAL_u8CycleIndex) < 4)
      {
         PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[12] - PTMHAL_au32MeasuredTimeStamp[11]);
         PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[14] - PTMHAL_au32MeasuredTimeStamp[13]);
         PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0]  - PTMHAL_au32MeasuredTimeStamp[15]);
         PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0]  - PTMHAL_au32MeasuredTimeStamp[13]);
      }
      else
      {
         if ( ( (sint32)PTMHAL_u8CycleIndex) < 8)
         {
            PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0] - PTMHAL_au32MeasuredTimeStamp[15]);
            PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[2] - PTMHAL_au32MeasuredTimeStamp[1]);
            PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[4] - PTMHAL_au32MeasuredTimeStamp[3]);
            PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[4] - PTMHAL_au32MeasuredTimeStamp[1]);
         }
         else
         {
            if ( ( (sint32)PTMHAL_u8CycleIndex) < 12)
            {
               PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[4] - PTMHAL_au32MeasuredTimeStamp[3]);
               PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[6] - PTMHAL_au32MeasuredTimeStamp[5]);
               PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[8] - PTMHAL_au32MeasuredTimeStamp[7]);
               PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[8] - PTMHAL_au32MeasuredTimeStamp[5]);
            }
            else
            {
               PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[8]  - PTMHAL_au32MeasuredTimeStamp[7]);
               PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[10] - PTMHAL_au32MeasuredTimeStamp[9]);
               PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[12] - PTMHAL_au32MeasuredTimeStamp[11]);
               PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[12] - PTMHAL_au32MeasuredTimeStamp[9]);
            }
         }
      }
      PTMHAL_u8NbDurationPacksValid = PTMHAL_u8PSA_4CYL_CFG1_NB_PACK;
   }
   else
   {
      PTMHAL_bFirstCalculEvtOccured = TRUE;
      PTMHAL_u8NbDurationPacksValid = UINT8_MIN;
   }
}

#endif /* ifndef PTMHAL_bPSA_4CYL_CFG1_EN */

/******************************************************************************/
/* !FuncName    : PTMHAL_vidPSA4CylCfg2Manager                                */
/* !Description : Calculate the duration packs taking into account the        */
/*                acquisition method                                          */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/

#ifndef PTMHAL_bPSA_4CYL_CFG2_EN
   #error PTMHAL_bPSA_4CYL_CFG2_EN not defined
#elif (PTMHAL_bPSA_4CYL_CFG2_EN)

void PTMHAL_vidPSA4CylCfg2Manager(void)
{

   if (PTMHAL_bFirstCalculEvtOccured != FALSE)
   {
      if ( ( (sint32)PTMHAL_u8CycleIndex) < 5)
      {
         PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[15] - PTMHAL_au32MeasuredTimeStamp[14]);
         PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[18] - PTMHAL_au32MeasuredTimeStamp[16]);
         PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0]  - PTMHAL_au32MeasuredTimeStamp[19]);
         PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0]  - PTMHAL_au32MeasuredTimeStamp[17]);
      }
      else
      {
         if ( ( (sint32)PTMHAL_u8CycleIndex) < 10)
         {
            PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0] - PTMHAL_au32MeasuredTimeStamp[19]);
            PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[3] - PTMHAL_au32MeasuredTimeStamp[1]);
            PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[5] - PTMHAL_au32MeasuredTimeStamp[4]);
            PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[5] - PTMHAL_au32MeasuredTimeStamp[2]);
         }
         else
         {
            if ( ( (sint32)PTMHAL_u8CycleIndex) < 15)
            {
               PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[5]  - PTMHAL_au32MeasuredTimeStamp[4]);
               PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[8]  - PTMHAL_au32MeasuredTimeStamp[6]);
               PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[10] - PTMHAL_au32MeasuredTimeStamp[9]);
               PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[10] - PTMHAL_au32MeasuredTimeStamp[7]);
            }
            else
            {
               PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[10] - PTMHAL_au32MeasuredTimeStamp[9]);
               PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[13] - PTMHAL_au32MeasuredTimeStamp[11]);
               PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[15] - PTMHAL_au32MeasuredTimeStamp[14]);
               PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[15] - PTMHAL_au32MeasuredTimeStamp[12]);
            }
         }
      }
      PTMHAL_u8NbDurationPacksValid = PTMHAL_u8PSA_4CYL_CFG2_NB_PACK;
   }
   else
   {
      PTMHAL_bFirstCalculEvtOccured = TRUE;
      PTMHAL_u8NbDurationPacksValid = UINT8_MIN;
   }
}

#endif /* ifndef PTMHAL_bPSA_4CYL_CFG2_EN */

/******************************************************************************/
/* !FuncName    : PTMHAL_vidEvlvCfgManager                                    */
/* !Description : Calculate the duration packs taking into account the        */
/*                acquisition method                                          */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/

#ifndef PTMHAL_bEVLV_CFG_EN
   #error PTMHAL_bEVLV_CFG_EN not defined
#elif (PTMHAL_bEVLV_CFG_EN)

void PTMHAL_vidEvlvCfgManager(void)
{
   uint8 u8LocalFirstPtIndex;
   uint8 u8LocalSecondPtIndex;


   if (PTMHAL_bFirstCalculEvtOccured != FALSE)
   {
      if (PTMHAL_ku8AlarmNbPerCycle != UINT8_MIN)
      {
         u8LocalFirstPtIndex = PTMHAL_u8CycleIndex - 2;
         u8LocalFirstPtIndex = (uint8)(u8LocalFirstPtIndex % PTMHAL_ku8AlarmNbPerCycle);
         u8LocalSecondPtIndex = PTMHAL_u8CycleIndex - 1;
         u8LocalSecondPtIndex = (uint8)(u8LocalSecondPtIndex % PTMHAL_ku8AlarmNbPerCycle);
         PTMHAL_au32DurationPack[0] = (uint32)( PTMHAL_au32MeasuredTimeStamp[u8LocalSecondPtIndex]
                                              - PTMHAL_au32MeasuredTimeStamp[u8LocalFirstPtIndex]);
         PTMHAL_u8NbDurationPacksValid = PTMHAL_u8EVLV_CFG_NB_PACK;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
         PTMHAL_u8NbDurationPacksValid = UINT8_MIN;
      }
   }
   else
   {
      PTMHAL_bFirstCalculEvtOccured = TRUE;
      PTMHAL_u8NbDurationPacksValid = UINT8_MIN;
   }
}

#endif /* ifndef PTMHAL_bEVLV_CFG_EN */

/******************************************************************************/
/* !FuncName    : PTMHAL_vidRSA3CylCfgManager                                 */
/* !Description : Calculate the duration packs taking into account the        */
/*                acquisition method                                          */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/

#ifndef PTMHAL_bRSA_3CYL_CFG_EN
   #error PTMHAL_bRSA_3CYL_CFG_EN not defined
#elif (PTMHAL_bRSA_3CYL_CFG_EN)

void PTMHAL_vidRSA3CylCfgManager(uint8 u8PackDurationCalc)
{
   uint8 u8LocalCycleIndex = 0;


   if (PTMHAL_bFirstCalculEvtOccured != FALSE)
   {
      u8LocalCycleIndex = PTMHAL_u8CycleIndex;
      switch (u8PackDurationCalc)
      {
         case PTMHAL_u8PTMHAL_EVT_CALL:
            PTMHAL_au32DurationPack[0] = (uint32)( (PTMHAL_au32MeasuredTimeStamp[u8LocalCycleIndex - 1])
                                                 - (PTMHAL_au32MeasuredTimeStamp[u8LocalCycleIndex - 2]));
            break;

         case PTMHAL_u8TDC_CALL:
            if (  (u8LocalCycleIndex >= 1)
               && (u8LocalCycleIndex < 9) )
            {
               PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[17] - PTMHAL_au32MeasuredTimeStamp[16]);
               PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[18] - PTMHAL_au32MeasuredTimeStamp[17]);
               PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[19] - PTMHAL_au32MeasuredTimeStamp[18]);
               PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[20] - PTMHAL_au32MeasuredTimeStamp[19]);
               PTMHAL_au32DurationPack[4] = (uint32)(PTMHAL_au32MeasuredTimeStamp[21] - PTMHAL_au32MeasuredTimeStamp[20]);
               PTMHAL_au32DurationPack[5] = (uint32)(PTMHAL_au32MeasuredTimeStamp[22] - PTMHAL_au32MeasuredTimeStamp[21]);
               PTMHAL_au32DurationPack[6] = (uint32)(PTMHAL_au32MeasuredTimeStamp[23] - PTMHAL_au32MeasuredTimeStamp[22]);
               PTMHAL_au32DurationPack[7] = (uint32)(PTMHAL_au32MeasuredTimeStamp[0]  - PTMHAL_au32MeasuredTimeStamp[23]);
            }
            else
            {
               if (  (u8LocalCycleIndex >= 9)
                  && (u8LocalCycleIndex < 17) )
               {
                  PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[1] - PTMHAL_au32MeasuredTimeStamp[0]);
                  PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[2] - PTMHAL_au32MeasuredTimeStamp[1]);
                  PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[3] - PTMHAL_au32MeasuredTimeStamp[2]);
                  PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[4] - PTMHAL_au32MeasuredTimeStamp[3]);
                  PTMHAL_au32DurationPack[4] = (uint32)(PTMHAL_au32MeasuredTimeStamp[5] - PTMHAL_au32MeasuredTimeStamp[4]);
                  PTMHAL_au32DurationPack[5] = (uint32)(PTMHAL_au32MeasuredTimeStamp[6] - PTMHAL_au32MeasuredTimeStamp[5]);
                  PTMHAL_au32DurationPack[6] = (uint32)(PTMHAL_au32MeasuredTimeStamp[7] - PTMHAL_au32MeasuredTimeStamp[6]);
                  PTMHAL_au32DurationPack[7] = (uint32)(PTMHAL_au32MeasuredTimeStamp[8] - PTMHAL_au32MeasuredTimeStamp[7]);
               }
               else
               {
                  PTMHAL_au32DurationPack[0] = (uint32)(PTMHAL_au32MeasuredTimeStamp[9]  - PTMHAL_au32MeasuredTimeStamp[8]);
                  PTMHAL_au32DurationPack[1] = (uint32)(PTMHAL_au32MeasuredTimeStamp[10] - PTMHAL_au32MeasuredTimeStamp[9]);
                  PTMHAL_au32DurationPack[2] = (uint32)(PTMHAL_au32MeasuredTimeStamp[11] - PTMHAL_au32MeasuredTimeStamp[10]);
                  PTMHAL_au32DurationPack[3] = (uint32)(PTMHAL_au32MeasuredTimeStamp[12] - PTMHAL_au32MeasuredTimeStamp[11]);
                  PTMHAL_au32DurationPack[4] = (uint32)(PTMHAL_au32MeasuredTimeStamp[13] - PTMHAL_au32MeasuredTimeStamp[12]);
                  PTMHAL_au32DurationPack[5] = (uint32)(PTMHAL_au32MeasuredTimeStamp[14] - PTMHAL_au32MeasuredTimeStamp[13]);
                  PTMHAL_au32DurationPack[6] = (uint32)(PTMHAL_au32MeasuredTimeStamp[15] - PTMHAL_au32MeasuredTimeStamp[14]);
                  PTMHAL_au32DurationPack[7] = (uint32)(PTMHAL_au32MeasuredTimeStamp[16] - PTMHAL_au32MeasuredTimeStamp[15]);
               }
            }
            PTMHAL_u8NbDurationPacksValid = PTMHAL_u8RSA_3CYL_CFG_NB_PACK;
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      PTMHAL_bFirstCalculEvtOccured = TRUE;
      PTMHAL_u8NbDurationPacksValid = UINT8_MIN;
   }
}

#endif /* ifndef PTMHAL_bRSA_3CYL_CFG_EN */

#define PTMHAL_STOP_SEC_CODE
#include "PTMHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
