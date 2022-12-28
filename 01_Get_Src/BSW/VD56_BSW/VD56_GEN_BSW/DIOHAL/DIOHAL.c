/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : DIOHAL                                                                                          */
/* !Description     : Allows access to the logical input/output of the ECU.                                           */
/*                                                                                                                    */
/* !Module          : DIOHAL                                                                                          */
/* !Description     : Digital i/o hardware abstraction layer module.                                                  */
/*                                                                                                                    */
/* !File            : DIOHAL.c                                                                                        */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : ALL                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* 1 / DIOHAL_vidInit                                                                                                 */
/* 2 / DIOHAL_vidWrite                                                                                                */
/* 3 / DIOHAL_bRead                                                                                                   */
/* 4 / DIOHAL_bReadRaw                                                                                                */
/* 5 / DIOHAL_vidMainFunction                                                                                         */
/* 6 / DIOHAL_vidUpdateHighFreqTable                                                                                  */
/* 7 / DIOHAL_vidUpdateLowFreqTable                                                                                   */
/* 8 / DIOHAL_vidFilterInit                                                                                           */
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A734.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/

#include "DIOHAL_Def.h"
#include "DIOHAL.h"
#include "SWFAIL.h"

/**********************************************************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                                                         */
/**********************************************************************************************************************/


#define DIOHAL_START_SEC_CODE
#include "DIOHAL_MemMap.h"

STATIC INLINE void DIOHAL_vidUpdateLowFreqTable(void);
STATIC INLINE void DIOHAL_vidUpdateHighFreqTable(void);
STATIC INLINE void DIOHAL_vidFilterInit(void);

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_vidInit                                                                                      */
/*                                                                                                                    */
/* !Description : Initializes all internal DIOHAL variables.                                                          */
/* !Number      : 0                                                                                                   */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/01.01                                                        */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/01.02                                                        */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/01.03                                                        */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
void DIOHAL_vidInit(void)
{
   DIOHAL_vidFilterInit();
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_vidWrite                                                                                     */
/*                                                                                                                    */
/* !Description :                                                                                                     */
/* !Number      : 1                                                                                                   */
/* !Reference   : 	PTS_DOC_5206415 /                                                                                  */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
void DIOHAL_vidWrite
(
   uint8 u8Channel,
   boolean bVal
)
{
   if(u8Channel < DIOHAL_u8WRITE_TABLE_SIZE)
   {
      DIOHAL_akpfvidWrite[u8Channel] (bVal);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_bRead                                                                                        */
/*                                                                                                                    */
/* !Description : Returns the input after a s/w low pass filter; but if the  uChannel is o/p, it returns the raw value*/
/*                (no filter).  State of the ECU input/output; or STD_OFF in case of invalid ch.                      */
/* !Number      : 2                                                                                                   */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/03.01                                                        */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/03.02                                                        */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
boolean DIOHAL_bRead
(
   uint8 u8Channel
)
{
   /* !Comment: return value */
   boolean bLocalRetVal;

   /* !Pseudo: The action (reading from the filter table or from the raw value
               is configured by the equivalent pointer on DIOHAL_akpfbRead    */
   if(u8Channel < DIOHAL_u8READ_TABLE_SIZE)
   {
      bLocalRetVal = DIOHAL_akpfbRead[u8Channel] ();
      /* !Pseudo: This may be Read(input channel) or ReadRaw(o/p channel).    */
   }
   else
   {
      bLocalRetVal = STD_OFF;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (bLocalRetVal);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_bReadRaw                                                                                     */
/*                                                                                                                    */
/* !Description : Returns the actual state without filtering. State of the ECU input/output; or STD_OFF in case of    */
/*                invalid ch.                                                                                         */
/* !Number      : 3                                                                                                   */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/04.01                                                        */
/* !Trace_To    : V01 NT 06 03391 01: DEV REQ: DIOHAL/EA/04.02                                                        */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
boolean DIOHAL_bReadRaw
(
   uint8 u8Channel
)
{
   /* !Comment: return value */
   boolean bLocalRetVal;

   /* !Pseudo: If there is a defined function pointer for the channel in the
               table call it, else call the error hook function.              */
   if(u8Channel < DIOHAL_u8READ_TABLE_SIZE)
   {
      bLocalRetVal = DIOHAL_akpfbReadRaw[u8Channel] ();
   }
   else
   {
      bLocalRetVal = STD_OFF;
      SWFAIL_vidSoftwareErrorHook();
   }

   return (bLocalRetVal);
}


/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_vidMainFunction                                                                              */
/*                                                                                                                    */
/* !Description : Updates both low and high frequency filter tables.                                                  */
/* !Number      : 1.4                                                                                                 */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
void DIOHAL_vidMainFunction(void)
{
   DIOHAL_vidUpdateHighFreqTable();
   DIOHAL_vidUpdateLowFreqTable();
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_vidUpdateHighFreqTable                                                                       */
/*                                                                                                                    */
/* !Description : Updates high frequency filter's table                                                               */
/* !Number      : 1.1                                                                                                 */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
STATIC INLINE void DIOHAL_vidUpdateHighFreqTable(void)
{
   uint8  u8LocalNewSampleIndex;
   uint8  u8LocalOldSampleIndex;

   uint8  u8LocalPortIndex;
   uint8  u8LocalHFSampleNBIndex;
   uint16 au16LocalPortStatus[DIOHAL_u8FILTERED_PORTS_NBR];
   uint16 au16LocalPortValue[DIOHAL_u8FILTERED_PORTS_NBR];
   uint16 au16LocalRawValues[DIOHAL_u8FILTERED_PORTS_NBR];

   /* !Pseudo: Circulate the sampling index.                                  */
   u8LocalOldSampleIndex = DIOHAL_u8LowFreqSampleIndex;
   if (u8LocalOldSampleIndex < (uint8) (DIOHAL_u8LOW_FREQ_SAMPLE_NBR - 1))
   {
      u8LocalNewSampleIndex = (uint8)(u8LocalOldSampleIndex + 1);
   }
   else
   {
      u8LocalNewSampleIndex = 0;
   }
   DIOHAL_u8LowFreqSampleIndex = u8LocalNewSampleIndex;


   /* !Pseudo:
   for each port do
   {
      Anding and oring all samples
      Detect error
      Take the good values
   }
   */

   for (u8LocalHFSampleNBIndex = 0;
        u8LocalHFSampleNBIndex < DIOHAL_u8HIGH_FREQ_SAMPLE_NBR;
        u8LocalHFSampleNBIndex++)
   {
      DIOHAL_vidGET_SAMPLE(au16LocalRawValues);
      for (u8LocalPortIndex = 0;
           u8LocalPortIndex < DIOHAL_u8FILTERED_PORTS_NBR;
           u8LocalPortIndex++)
      {
         if(u8LocalHFSampleNBIndex > 0)
         {
            au16LocalPortValue[u8LocalPortIndex]
            &= au16LocalRawValues[u8LocalPortIndex];

            au16LocalPortStatus[u8LocalPortIndex]
            |= au16LocalRawValues[u8LocalPortIndex];
         }

         else /* equal zero (first element of the array) */
         {
            au16LocalPortValue[u8LocalPortIndex]
            = au16LocalRawValues[u8LocalPortIndex];

            au16LocalPortStatus[u8LocalPortIndex]
            = au16LocalRawValues[u8LocalPortIndex];
         }
      }
   }


   for (u8LocalPortIndex = 0;
        u8LocalPortIndex < DIOHAL_u8FILTERED_PORTS_NBR;
        u8LocalPortIndex++)
   {
      /* !Pseudo: Status(Error) = XOR(anding, oring of all raw samples).      */
      au16LocalPortStatus[u8LocalPortIndex]
      ^= au16LocalPortValue[u8LocalPortIndex];

      /* !Pseudo: Take the good sampled bits from the new sample, but for bad
                  sampled bits (with error) take the values from the older
                  sample (inverted, to propagate the error to the LF Filter). */
      DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex][u8LocalNewSampleIndex]
      = (uint16) ( ( ((uint16) ~au16LocalPortStatus[u8LocalPortIndex])
                   & au16LocalPortValue[u8LocalPortIndex])
                 | ( au16LocalPortStatus[u8LocalPortIndex]
                   & ((uint16) ~DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex]
                                                     [u8LocalOldSampleIndex])));
   }
}


/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_vidUpdateLowFreqTable                                                                        */
/*                                                                                                                    */
/* !Description : Updates low frequency filter's table.                                                               */
/* !Number      : 1.2                                                                                                 */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
STATIC INLINE void DIOHAL_vidUpdateLowFreqTable(void)
{
   uint8  u8LocalPortIndex;
   uint8  u8LocalSampleIndex;
   uint16 au16LocalPortStatus[DIOHAL_u8FILTERED_PORTS_NBR];
   uint16 au16LocalPortValue[DIOHAL_u8FILTERED_PORTS_NBR];

   for (u8LocalPortIndex = 0;
        u8LocalPortIndex < DIOHAL_u8FILTERED_PORTS_NBR;
        u8LocalPortIndex++)
   {
      /* !Pseudo: Adding and oring all samples */
      for(u8LocalSampleIndex = 0;
          u8LocalSampleIndex < DIOHAL_u8LOW_FREQ_SAMPLE_NBR;
          u8LocalSampleIndex++)
      {
         if (u8LocalSampleIndex > 0)
         {
            au16LocalPortValue[u8LocalPortIndex]
            &= DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex]
                                             [u8LocalSampleIndex];

            au16LocalPortStatus[u8LocalPortIndex]
            |= DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex]
                                             [u8LocalSampleIndex];
         }
         else
         {
            au16LocalPortValue[u8LocalPortIndex]
            = DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex]
                                            [u8LocalSampleIndex];

            au16LocalPortStatus[u8LocalPortIndex]
            = DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex]
                                            [u8LocalSampleIndex];
         }
      }

      /* !Pseudo: status(Error) = XOR(anding, oring of all high frequency
                  filtered samples).                                          */
      au16LocalPortStatus[u8LocalPortIndex]
      ^= au16LocalPortValue[u8LocalPortIndex];

      /* !Pseudo: Take the good sampled bits from the new sample, but for bad
                  sampled bits (Equivalent bit in status = 1) take the values
                  from the older sample.                                      */

      DIOHAL_au16LowFreqFilterTable[u8LocalPortIndex]
      = (uint16) ( ( ((uint16) ~au16LocalPortStatus[u8LocalPortIndex])
                   & au16LocalPortValue[u8LocalPortIndex])
                 | ( au16LocalPortStatus[u8LocalPortIndex]
                   & DIOHAL_au16LowFreqFilterTable[u8LocalPortIndex]));
   }
}


/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : DIOHAL_vidFilterInit                                                                                */
/*                                                                                                                    */
/* !Description : Initializes the Filter module.                                                                      */
/* !Number      : 1.3                                                                                                 */
/* !Reference   : PTS_DOC_5206415 / 1                                                                                 */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  A.Nagy                                                                                             */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
STATIC INLINE void DIOHAL_vidFilterInit(void)
{
   uint8  u8LocalPortIndex;
   uint8  u8LocalHFSampleNBIndex;

   /* !Comment: Temporatory storage of raw values of all filtered ports.      */
   uint16 au16LocalPortRawValue[DIOHAL_u8FILTERED_PORTS_NBR];

   /* !Pseudo: Set the sampling index to zero                                 */
   DIOHAL_u8LowFreqSampleIndex = 0;

   /* !Pseudo: Fill both the high and low frequency filter tables by the
               current raw values.                                            */

   DIOHAL_vidGET_SAMPLE(au16LocalPortRawValue);

   for (u8LocalPortIndex = 0;
        u8LocalPortIndex < DIOHAL_u8FILTERED_PORTS_NBR;
        u8LocalPortIndex++)
   {
      DIOHAL_au16LowFreqFilterTable[u8LocalPortIndex]
      = au16LocalPortRawValue[u8LocalPortIndex];

      for (u8LocalHFSampleNBIndex = 0;
           u8LocalHFSampleNBIndex < DIOHAL_u8HIGH_FREQ_SAMPLE_NBR;
           u8LocalHFSampleNBIndex++)
      {
         DIOHAL_au16HighFreqFilterTable[u8LocalPortIndex]
                                       [u8LocalHFSampleNBIndex]
         = au16LocalPortRawValue[u8LocalPortIndex];
      }
   }
}

#define DIOHAL_STOP_SEC_CODE
#include "DIOHAL_MemMap.h"


/*-------------------------------------------------- end of file -----------------------------------------------------*/
