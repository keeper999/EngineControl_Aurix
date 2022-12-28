/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_DIAG.c                                                                                    */
/* !Description     : Electrical diagnosis by SPI of the L9781 Component                                              */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A189047.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"

#include "L9781.h"
#include "L9781_CFG_I.h"
#include "L9781_I.h"
#include "L9781_L.h"

#include "ADCBSL.h"
#include "SchM_L9781.h"
#include "SWFAIL.h"

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : L9781_vidDiagManager                                                                                */
/* !Description : Manages the diagnosis of L9781 components and the unlock sequence.                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidDiagManager(void)
{
   uint8   u8LocalAsicIndex;
   uint8   u8LocalBankIndex;
   boolean blocalIrqDiag;

   blocalIrqDiag = FALSE;

   L9781_u16VboostVoltage = ADCBSL_u16Read(L9781_snVBOOST_VOLTAGE);

   if ((L9781_bStartupComplete != FALSE) && (L9781_bGdiAsicFullStopped == FALSE))
   {
      if (L9781_bfDiagComplete == L9781_bfIRQ_DIAG_INIT)
      {

         for (u8LocalAsicIndex = L9781_u8FIRST_CHANNEL; u8LocalAsicIndex < L9781_u8NB_ASIC; u8LocalAsicIndex ++)
         {
            for (u8LocalBankIndex = L9781_u8FIRST_BANK; u8LocalBankIndex < L9781_u8NB_BANK; u8LocalBankIndex ++)
            {
               if (L9781_au8UnlockTimeOut[u8LocalBankIndex][u8LocalAsicIndex] != 0u)
               {
                  L9781_au8UnlockTimeOut[u8LocalBankIndex][u8LocalAsicIndex]--;
                  if (L9781_au8UnlockTimeOut[u8LocalBankIndex][u8LocalAsicIndex] == 0u)
                  {
                     switch (u8LocalBankIndex)
                     {
                        case L9781_u8BANK_A:
                           L9781_au32BankToUnlock[u8LocalAsicIndex] |= L9781_u32MASK_BANK_A_UNLOCK;
                           break;

                        case L9781_u8BANK_B:
                           L9781_au32BankToUnlock[u8LocalAsicIndex] |= L9781_u32MASK_BANK_B_UNLOCK;
                           break;

                        case L9781_u8BANK_FP:
                           L9781_au32BankToUnlock[u8LocalAsicIndex] |= L9781_u32MASK_BANK_FP_UNLOCK;
                           break;

                        default:
                           SWFAIL_vidSoftwareErrorHook();
                           break;
                     }
                  }
               }
            }

            if (L9781_au32BankToUnlock[u8LocalAsicIndex] != L9781_u32NO_BANK_TO_UNLOCK)
            {
               L9781_vidUnlockSequence(u8LocalAsicIndex);
            }

            if (L9781_bEnabled != FALSE)
            {
               blocalIrqDiag = L9781_bReadIrqDiag(u8LocalAsicIndex);

               if (blocalIrqDiag != FALSE)
               {
                  if (L9781_abOnlyOvlSpiDiagMode[u8LocalAsicIndex] != FALSE)
                  {
                     /* ! Comment: Clear ALL faults except OVL  (SCG/SCW/OC) */
                     L9781_vidClearAllDiag(u8LocalAsicIndex);
                  }
                  else
                  {
                     if (L9781_abFirstDiagRead[u8LocalAsicIndex] == FALSE)
                     {
                        L9781_abOnlyOvlSpiDiagMode[u8LocalAsicIndex] = TRUE;
                        /* ! Comment: Clear ALL faults except OVL  (SCG/SCW/OC)  */
                        L9781_vidClearAllDiag(u8LocalAsicIndex);
                     }
                  }
               }
               else
               {
                  if (L9781_abOnlyOvlSpiDiagMode[u8LocalAsicIndex] != FALSE)
                  {
                    L9781_abOnlyOvlSpiDiagMode[u8LocalAsicIndex] = FALSE;
                    L9781_abFirstDiagRead[u8LocalAsicIndex]      = FALSE;
                  }
               }

               L9781_bfDiagComplete &= (uint16)(~(0x0001u << u8LocalAsicIndex) );

               if (L9781_abFirstDiagRead[u8LocalAsicIndex] == FALSE)
               {
                  L9781_au32IcStatusFrame[u8LocalAsicIndex]  = 0x00000000u;
                  L9781_au32DiagBankAFrame[u8LocalAsicIndex] = 0x00000000u;
                  L9781_au32DiagBankBFrame[u8LocalAsicIndex] = 0x00000000u;
                  L9781_au32DiagFpFrame[u8LocalAsicIndex]    = 0x00000000u;
               }

               SchM_Enter_L9781_vidDiagManager();
               if ((L9781_enuLoadingState == L9781_enuLOAD_IDLE) && (L9781_u8NbSpiRequest == 0u))
               {
                  L9781_enuLoadingState = L9781_enuLOAD_DIAG;
                  L9781_vidSpiStartInit(u8LocalAsicIndex);
               }
               else
               {
                  L9781_vidSET_SPI_REQUEST(u8LocalAsicIndex, LOAD_DIAG);
               }
               SchM_Exit_L9781_vidDiagManager();
            }
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }

      if (L9781_u8VboostAuthDiagDcntr != UINT8_MIN)
      {
         L9781_u8VboostAuthDiagDcntr--;
      }
      else
      {
         /* !Comment: VBOOST Diagnostic is performed only at the end of  */
         /*           authorisation delay and when full startup sequence */
         /*           is finished                                        */
         L9781_vidVBOOST_DIAGNOSIS(L9781_u16VboostVoltage,
                                   L9781_ku16VboostVoltLowLimit,
                                   L9781_ku16VboostVoltHighLimit);
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidLoadFrameDiag                                                                              */
/* !Description : Loads the SPI frame (for the diagnosis) in the SPI Tx Buffer.                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidLoadFrameDiag(void)
{
   switch (L9781_u8SpiFrameIndex)
   {
      case L9781_u8ID_IC_STATUS:
         L9781_u16SpiBufferTxLsw = (uint16)(L9781_u32FRAME_IC_STATUS);
         L9781_u16SpiBufferTxMsw = (uint16)(L9781_u32FRAME_IC_STATUS >> L9781_u8SHIFT_16_BITS);
         break;

      case L9781_u8ID_DIAG_BANK_A:
         L9781_u16SpiBufferTxLsw = (uint16)(L9781_u32FRAME_DIAG_BANK_A);
         L9781_u16SpiBufferTxMsw = (uint16)(L9781_u32FRAME_DIAG_BANK_A >> L9781_u8SHIFT_16_BITS);
         break;

      case L9781_u8ID_DIAG_BANK_B:
         L9781_u16SpiBufferTxLsw = (uint16)(L9781_u32FRAME_DIAG_BANK_B);
         L9781_u16SpiBufferTxMsw = (uint16)(L9781_u32FRAME_DIAG_BANK_B >> L9781_u8SHIFT_16_BITS);
         break;

      case L9781_u8ID_DIAG_FP:
         L9781_u16SpiBufferTxLsw = (uint16)(L9781_u32FRAME_DIAG_FP);
         L9781_u16SpiBufferTxMsw = (uint16)(L9781_u32FRAME_DIAG_FP >> L9781_u8SHIFT_16_BITS);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         L9781_u8SpiFrameIndex   = L9781_u8ID_UNDEFINED;
         L9781_u16SpiBufferTxLsw = L9781_u16BUFFER_UNDEFINED;
         L9781_u16SpiBufferTxMsw = L9781_u16BUFFER_UNDEFINED;
         L9781_bSpiTxRequest     = FALSE;
         L9781_bReadDiagValid    = FALSE;
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidReadFrameDiag                                                                              */
/* !Description : Reads the SPI frame for the diagnosis returned by the ASIC.                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidReadFrameDiag
(
   uint8 u8Channel
)
{
   switch (L9781_u8SpiFrameIndex)
   {
      case L9781_u8ID_IC_STATUS:
         L9781_au32IcStatusFrame[u8Channel] |= (uint32)( (  ((uint32)L9781_u16SpiBufferRxMsw)
                                                         << L9781_u8SHIFT_16_BITS)
                                                       | ((uint32)L9781_u16SpiBufferRxLsw));
         L9781_u8SpiFrameIndex++;
         break;

      case L9781_u8ID_DIAG_BANK_A:
         L9781_au32DiagBankAFrame[u8Channel] |= (uint32)( (  ((uint32)L9781_u16SpiBufferRxMsw)
                                                          << L9781_u8SHIFT_16_BITS)
                                                        | ((uint32)L9781_u16SpiBufferRxLsw));
         L9781_u8SpiFrameIndex++;
         break;

      case L9781_u8ID_DIAG_BANK_B:
         L9781_au32DiagBankBFrame[u8Channel] |= (uint32)( (  ((uint32)L9781_u16SpiBufferRxMsw)
                                                          << L9781_u8SHIFT_16_BITS)
                                                        | ((uint32)L9781_u16SpiBufferRxLsw));
         L9781_u8SpiFrameIndex++;
         break;

      case L9781_u8ID_DIAG_FP:
         L9781_au32DiagFpFrame[u8Channel] |= (uint32)( (  ((uint32)L9781_u16SpiBufferRxMsw)
                                                       << L9781_u8SHIFT_16_BITS)
                                                     | ((uint32)L9781_u16SpiBufferRxLsw));
         L9781_u8SpiFrameIndex++;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         L9781_u8SpiFrameIndex = L9781_u8ID_UNDEFINED;
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidAnalyzeDiag                                                                                */
/* !Description : Analyzes the diagnosis got from the related SPI frames and updates all the fault status.            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidAnalyzeDiag
(
   uint8 u8Channel
)
{
   uint8  u8LocalDelay;


   L9781_abBankLock[L9781_u8BANK_A] = ( (!(L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_BANK_A_LOCKED))
                                      ? FALSE
                                      : TRUE);

   L9781_abBankLock[L9781_u8BANK_B] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_BANK_B_LOCKED))
                                      ? FALSE
                                      : TRUE);

   L9781_abBankLock[L9781_u8BANK_FP] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_BANK_FP_LOCKED))
                                       ? FALSE
                                       : TRUE);

   L9781_abIrqActStatus[L9781_u8BANK_A] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_A_IRQ_ACT))
                                          ? FALSE
                                          : TRUE);

   L9781_abIrqActStatus[L9781_u8BANK_B] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_B_IRQ_ACT))
                                          ? FALSE
                                          : TRUE);

   L9781_abIrqActStatus[L9781_u8BANK_FP] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_FP_IRQ_ACT))
                                           ? FALSE
                                           : TRUE);

   L9781_abIrqIdleStatus[L9781_u8BANK_A] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_A_IRQ_IDLE))
                                           ? FALSE
                                           : TRUE);

   L9781_abIrqIdleStatus[L9781_u8BANK_B] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_B_IRQ_IDLE))
                                           ? FALSE
                                           : TRUE);

   L9781_abIrqIdleStatus[L9781_u8BANK_FP] = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_FP_IRQ_IDLE))
                                            ? FALSE
                                            : TRUE);

   L9781_abActStatus[L9781_u8BANK_A] = ( (!(L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_A_CMD_X_ACT) )
                                       ? FALSE
                                       : TRUE);

   L9781_abActStatus[L9781_u8BANK_B] = ( (!(L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_B_CMD_X_ACT) )
                                       ? FALSE
                                       : TRUE);

   L9781_abActStatus[L9781_u8BANK_FP] = ( (!(L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_DIAG_FP_CMD_ACT) )
                                        ? FALSE
                                        : TRUE);

   L9781_bDiagOvVbat = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_OV_LATCH))
                       ? FALSE
                       : TRUE);

   L9781_bDiagUvVbat = ( (!( L9781_au32IcStatusFrame[u8Channel] & L9781_u32MASK_UV_LATCH))
                       ? FALSE
                       : TRUE);

   L9781_bDiagScVbBankAx = ( (!( L9781_au32DiagBankAFrame[u8Channel] & L9781_u32MASK_CC_VB))
                           ? FALSE
                           : TRUE);

   L9781_bDiagScVbBankAy = L9781_bDiagScVbBankAx;

   L9781_bDiagScGndBankAx = ( (!( L9781_au32DiagBankAFrame[u8Channel] & L9781_u32MASK_CC_GND))
                            ? FALSE
                            : TRUE);

   L9781_bDiagScGndBankAy = L9781_bDiagScGndBankAx;

   L9781_bDiagScVhsVlsBankAx = ( (  (!( L9781_au32DiagBankAFrame[u8Channel] & ( L9781_u32MASK_CC_VB
                                                                              | L9781_u32MASK_CC_GND
                                                                              | L9781_u32MASK_OL_X
                                                                              | L9781_u32MASK_OL_Y)))
                                 && (L9781_abBankLock[L9781_u8BANK_A] != FALSE))
                               ? TRUE
                               : FALSE);

   L9781_bDiagScVhsVlsBankAy = L9781_bDiagScVhsVlsBankAx;

   L9781_bDiagOlBankAx = ( (!( L9781_au32DiagBankAFrame[u8Channel] & L9781_u32MASK_OL_X))
                         ? FALSE
                         : TRUE);

   L9781_bDiagOlBankAy = ( (!( L9781_au32DiagBankAFrame[u8Channel] & L9781_u32MASK_OL_Y))
                         ? FALSE
                         : TRUE);

   if ( L9781_au16FailureCounter[L9781_u8BANK_A][u8Channel] < L9781_ku16MaxBankFailure)
   {
      if ((L9781_abBankLock[L9781_u8BANK_A] != FALSE) && (L9781_au8UnlockTimeOut[L9781_u8BANK_A][u8Channel] == 0u))
      {
         if (L9781_abIrqActStatus[L9781_u8BANK_A] != FALSE)
         {
            u8LocalDelay = L9781_ku8DelayBeforeUnlock;
         }
         else
         {
            u8LocalDelay = L9781_u8UNLOCK_IDLE_DELAY;
         }

         L9781_au8UnlockTimeOut[L9781_u8BANK_A][u8Channel] = u8LocalDelay;
         L9781_au16FailureCounter[L9781_u8BANK_A][u8Channel]++;
      }
   }

   L9781_bDiagScVbBankBx = ( (!( L9781_au32DiagBankBFrame[u8Channel] & L9781_u32MASK_CC_VB))
                           ? FALSE
                           : TRUE);

   L9781_bDiagScVbBankBy = L9781_bDiagScVbBankBx;

   L9781_bDiagScGndBankBx = ( (!( L9781_au32DiagBankBFrame[u8Channel] & L9781_u32MASK_CC_GND))
                            ? FALSE
                            : TRUE);

   L9781_bDiagScGndBankBy = L9781_bDiagScGndBankBx;

   L9781_bDiagScVhsVlsBankBx = ( (  (!( L9781_au32DiagBankBFrame[u8Channel] & ( L9781_u32MASK_CC_VB
                                                                              | L9781_u32MASK_CC_GND
                                                                              | L9781_u32MASK_OL_X
                                                                              | L9781_u32MASK_OL_Y)))
                                 && (L9781_abBankLock[L9781_u8BANK_B] != FALSE))
                               ? TRUE
                               : FALSE);

   L9781_bDiagScVhsVlsBankBy = L9781_bDiagScVhsVlsBankBx;

   L9781_bDiagOlBankBx = ( (!( L9781_au32DiagBankBFrame[u8Channel] & L9781_u32MASK_OL_X))
                         ? FALSE
                         : TRUE);

   L9781_bDiagOlBankBy = ( (!( L9781_au32DiagBankBFrame[u8Channel] & L9781_u32MASK_OL_Y))
                         ? FALSE
                         : TRUE);

   if ( L9781_au16FailureCounter[L9781_u8BANK_B][u8Channel] < L9781_ku16MaxBankFailure)
   {
      if ((L9781_abBankLock[L9781_u8BANK_B] != FALSE) && (L9781_au8UnlockTimeOut[L9781_u8BANK_B][u8Channel] == 0u))
      {
         if (L9781_abIrqActStatus[L9781_u8BANK_B] != FALSE)
         {
            u8LocalDelay = L9781_ku8DelayBeforeUnlock;
         }
         else
         {
            u8LocalDelay = L9781_u8UNLOCK_IDLE_DELAY;
         }

         L9781_au8UnlockTimeOut[L9781_u8BANK_B][u8Channel] = u8LocalDelay;
         L9781_au16FailureCounter[L9781_u8BANK_B][u8Channel]++;
      }
   }

   L9781_bDiagScVbBankFp = ( (!( L9781_au32DiagFpFrame[u8Channel] & L9781_u32MASK_CC_VB))
                           ? FALSE
                           : TRUE);

   L9781_bDiagScGndBankFp = ( (!( L9781_au32DiagFpFrame[u8Channel] & L9781_u32MASK_CC_GND))
                            ? FALSE
                            : TRUE);

   L9781_bDiagScVhsVlsBankFp = ( (  (!( L9781_au32DiagFpFrame[u8Channel] & ( L9781_u32MASK_CC_VB
                                                                           | L9781_u32MASK_CC_GND
                                                                           | L9781_u32MASK_OL_P)))
                                 && (L9781_abBankLock[L9781_u8BANK_FP] != FALSE))
                               ? TRUE
                               : FALSE);

   L9781_bDiagOlBankFp = ( (!( L9781_au32DiagFpFrame[u8Channel] & L9781_u32MASK_OL_P))
                         ? FALSE
                         : TRUE);

   if ( L9781_au16FailureCounter[L9781_u8BANK_FP][u8Channel] < L9781_ku16MaxBankFailure)
   {
      if ((L9781_abBankLock[L9781_u8BANK_FP] != FALSE) && (L9781_au8UnlockTimeOut[L9781_u8BANK_FP][u8Channel] == 0u))
      {
         if (L9781_abIrqActStatus[L9781_u8BANK_FP] != FALSE)
         {
            u8LocalDelay = L9781_ku8DelayBeforeUnlock;
         }
         else
         {
            u8LocalDelay = L9781_u8UNLOCK_IDLE_DELAY;
         }

         L9781_au8UnlockTimeOut[L9781_u8BANK_FP][u8Channel] = u8LocalDelay;
         L9781_au16FailureCounter[L9781_u8BANK_FP][u8Channel]++;
      }
   }
}


#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
