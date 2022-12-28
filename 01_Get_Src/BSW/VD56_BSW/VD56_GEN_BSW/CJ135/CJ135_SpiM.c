/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM.c                                                                                    */
/* !Description     : handle the SPi protocol                                                                         */
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
 * %PID: P2017_BSW:0A188674.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Spi.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_Spi.h"
#include "CJ135_SpiM.h"
#include "CJ135_Types.h"
#include "SchM_CJ135.h"



/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CONST_UNSPECIFIED
#include "CJ135_MemMap.h"

/* the both below table order is same as CJ135_tenuSpiMSequences enums */
/* SpiM: sequence start function */
STATIC CJ135_tkpfvidSpiM_StartSeqFct CJ135_pfvidSpiM_StartSeqFct[CJ135_SPIM_SEQ_NB_OF_CMD] =
{
   &CJ135_vidSpiM_InitConfRegisterStart,   /* CJ135_SPIM_SEQ_INIT_CONF_REGISTER  */
   &CJ135_vidSpiM_ReadConfRegisterStart,   /* CJ135_SPIM_SEQ_READ_CONF_REGISTER  */
   &CJ135_vidSpiM_UpdateConfRegisterStart, /* CJ135_SPIM_SEQ_UPDATE_CONF_REGISTER  */
   &CJ135_vidSpiM_WriteModeStart,          /* CJ135_SPIM_SEQ_WRITE_MODE  */
   &CJ135_vidSpiM_ReadModesStart,          /* CJ135_SPIM_SEQ_READ_MODES  */
   &CJ135_vidSpiM_ReadRichnessTempStart,   /* CJ135_SPIM_SEQ_READ_RICHNESS_TEMP  */
   &CJ135_vidSpiM_ReadTempStart,           /* CJ135_SPIM_SEQ_READ_TEMP  */
   &CJ135_vidSpiM_ReadDiagnosticStart,     /* CJ135_SPIM_SEQ_READ_DIAGNOSTIC  */
   &CJ135_vidSpiM_ReadCompensationStart    /* CJ135_SPIM_SEQ_READ_COMPENSATION  */

};

/* SpiM: function to call on SPI TxConfirmation */
CJ135_tkpfvidSpiM_TxConf CJ135_pfvidSpiM_TxConfFct[CJ135_SPIM_SEQ_NB_OF_CMD] =
{
   &CJ135_vidSpiM_InitConfRegisterTxConf,   /* CJ135_SPIM_SEQ_INIT_CONF_REGISTER  */
   &CJ135_vidSpiM_ReadConfRegisterTxConf,   /* CJ135_SPIM_SEQ_READ_CONF_REGISTER  */
   &CJ135_vidSpiM_UpdateConfRegisterTxConf, /* CJ135_SPIM_SEQ_UPDATE_CONF_REGISTER  */
   &CJ135_vidSpiM_WriteModeTxConf,          /* CJ135_SPIM_SEQ_WRITE_MODE  */
   &CJ135_vidSpiM_ReadModesTxConf,          /* CJ135_SPIM_SEQ_READ_MODES  */
   &CJ135_vidSpiM_ReadRichnessTempTxConf,   /* CJ135_SPIM_SEQ_READ_RICHNESS_TEMP  */
   &CJ135_vidSpiM_ReadTempTxConf,           /* CJ135_SPIM_SEQ_READ_TEMP  */
   &CJ135_vidSpiM_ReadDiagnosticTxConf,     /* CJ135_SPIM_SEQ_READ_DIAGNOSTIC  */
   &CJ135_vidSpiM_ReadCompensationTxConf    /* CJ135_SPIM_SEQ_READ_COMPENSATION  */
};

#define CJ135_STOP_SEC_CONST_UNSPECIFIED
#include "CJ135_MemMap.h"


#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_Init                                                                                  */
/* !Description : Init of the SpiM layer                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_Init(const CJ135_tstrConfig *pkstrConfig,
                        CJ135_strData          *pstrData)
{
   uint8_least u8LocSequence;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   /* All state machine are idle */
   pstrData->udtSpiM_StateMachine.All   = CJ135_SPI_SEQ_IDLE;
   pstrData->enuSpiM_SeqRunning         = CJ135_SPIM_SEQ_WAITING_STATE;
   pstrData->enuSpiMRegisterInitialized = CJ135_REGISTER_INIT_NOT_DONE;

   /* No sequence to run */
   for (u8LocSequence = 0; u8LocSequence < CJ135_SPIM_SEQ_NB_OF_CMD; u8LocSequence++)
   {
      pstrData->abSpiM_SeqRequest[u8LocSequence] = FALSE;
   }

   /* Initialize all register expected values with calibrations  */
   pstrData->u16ExpectedRegConfigDsp = CJ135_ku16RegConfigDsp;
   pstrData->u16ExpectedRegIpOff = CJ135_ku16RegIpOff;
   pstrData->u16ExpectedRegMode = CJ135_ku16RegMode;
   pstrData->u16ExpectedRegRefpat = CJ135_ku16RegRefpat;
   pstrData->u16ExpectedRegSteerpat = CJ135_ku16RegSteerpat;
   pstrData->u16ExpectedRegTrim = CJ135_ku16RegTrim;
   pstrData->u16ExpectedRegUnset = CJ135_ku16RegUnset;
   pstrData->u16ExpectedRegUego0 = CJ135_ku16RegUego0;
   pstrData->u16ExpectedRegUego1 = CJ135_ku16RegUego1;
   pstrData->u16ExpectedRegUego2 = CJ135_ku16RegUego2;
   pstrData->u16ExpectedRegUego3 = CJ135_ku16RegUego3;
   pstrData->u16ExpectedRegUego4 = CJ135_ku16RegUego4;
   pstrData->u16ExpectedRegUego5 = CJ135_ku16RegUego5;
   pstrData->u16ExpectedRegUp0lean = CJ135_ku16RegUp0lean;
   pstrData->u16ExpectedRegUp0rich = CJ135_ku16RegUp0rich;
   pstrData->u16ExpectedRegFree = CJ135_ku16RegFree;
   pstrData->u16ExpectedRegActualMode = CJ135_u16SET_TAKEDATA(CJ135_ku16RegMode);
   /* actual mode register is read-only, is value shall be the same as mode register + bit takedata set to 1 */

   /* Last registers value read from CJ135: clear to unpossible value to ensure a first read before to use it */
   pstrData->u16SpiMChipRegConfigDsp  = 0xFFFFu; /* bit 15, 14, 12 and 11 are always zero  */
   pstrData->u16SpiMChipRegIpOff      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegMode       = 0x0008u; /* mode is NORMAL2 */
   pstrData->u16SpiMChipRegRefpat     = 0x8000u; /* possible but hightly unplausible value (no reference current)*/
   pstrData->u16SpiMChipRegSteerpat   = 0xFFFFu; /* possible but hightly unplausible value */
   pstrData->u16SpiMChipRegTrim       = 0xFFFFu; /* possible but unplausible value */
   pstrData->u16SpiMChipRegUnset      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUego0      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUego1      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUego2      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUego3      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUego4      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUego5      = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUp0lean    = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegUp0rich    = 0xFFFFu; /* out of range value */
   pstrData->u16SpiMChipRegFree       = 0xFFFFu; /* possible but unplausible value (free is not used) */
   pstrData->u16SpiMChipRegActualMode = 0x0008u; /* mode is NORMAL2 */

   /* Diag registers are initialized to zero (reset value is 0xFFFF)  */
   pstrData->u16SpiMChipRegDiag0      = 0x0000u;
   pstrData->u16SpiMChipRegDiag1      = 0x0000u;
   pstrData->u16SpiMChipRegChipStat   = 0x0000u;
   pstrData->u16SpiMChipRegDspStat    = 0x0000u;

   /* Initialize all values read in RAM with zero */
   pstrData->u16RamDataMode = 0;
   pstrData->s16RamIP1 = 0;
   pstrData->s16RamUrie = 0;
   pstrData->s16RamIP2 = 0;
   pstrData->s16RamUg0 = 0;
   pstrData->s16RamUn0 = 0;
   pstrData->s16RamIP3 = 0;
   pstrData->s16RamIP4 = 0;
   pstrData->s16RamUcal = 0;
   pstrData->s16RamIP5 = 0;

   /* Initialize all values used for richness or temperature calculation */
   pstrData->s16Mean5IP = 0;
   pstrData->s16Ipeff = 0;
   pstrData->u16Rie = 0;
   pstrData->u16RieWU = 0;

}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_Manager                                                                               */
/* !Description : This function is the entry point of the Sequence manager                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_Manager(const CJ135_tstrConfig *pkstrConfig,
                           CJ135_strData          *pstrData)
{
   uint8_least u8LocSeqIdx;
   boolean     bLocSeqFound = FALSE;


   /* if a sequence is already running, we do nothing, otherwise we start the most prior sequence awaiting to run  */

   /* enuSpiM_SeqRunning is a shared data, we consider that its access is atomic */
   if (pstrData->enuSpiM_SeqRunning == CJ135_SPIM_SEQ_WAITING_STATE)
   {
      /* If enuSpiM_SeqRunning == CJ135_SPIM_SEQ_WAITING_STATE, then no SPI communcation is in progress            */
      /* And so, no SPI interrupt could occurs, and so no concurrent acess to protect.                             */

      for (  u8LocSeqIdx = 0; (u8LocSeqIdx < CJ135_SPIM_SEQ_NB_OF_CMD)
          && (bLocSeqFound == FALSE); u8LocSeqIdx++)
      {
         /* We check, in priority order, which sequence to start */
         if (pstrData->abSpiM_SeqRequest[u8LocSeqIdx] != FALSE)
         {
            /* Stop the loop on first found sequence to run */
            bLocSeqFound = TRUE;
            /* Set to the value of sequence which becomes running */
            pstrData->enuSpiM_SeqRunning = (CJ135_tenuSpiMSequences)u8LocSeqIdx;
            /* Clear the request */
            pstrData->abSpiM_SeqRequest[u8LocSeqIdx] = FALSE;
            /* launch the found sequence */
            CJ135_pfvidSpiM_StartSeqFct[u8LocSeqIdx](pkstrConfig, pstrData);
         }
      }
      /* if there is no sequence to start, post-treatment can be made */
      if (bLocSeqFound == FALSE)
      {
         CJ135_vidStateMachinePost(pkstrConfig, pstrData);
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_Task                                                                                  */
/* !Description : this function check if a sequence has to be launched and launches it.                               */
/*                This function must be "trig" by SchM_Trigger_CJ135_SpiM                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_Task(uint8 u8Instance)
{
   CJ135_strData *pLocStrData;
   CJ135_tstrConfig const *pLockstrConfig;

   pLocStrData    = &CJ135_astrData[u8Instance];
   pLockstrConfig = &CJ135_akstrConfig[u8Instance];

   if (pLocStrData->bModeRead == FALSE)
   {
      pLocStrData->bModeRead = TRUE;

      /* Decode SPI received frames to determine the new internal sequencer state */
      if (pLocStrData->enuInternalSequencerState != CJ135_STATE_HW_FAILURE)
      {
         pLocStrData->enuInternalSequencerState = CJ135_u16EXTRACT_MODE(pLocStrData->u16SpiMChipRegActualMode);
         
         if ((pLocStrData->enuInternalSequencerState == CJ135_STATE_IDLEMODE1)
           ||(pLocStrData->enuInternalSequencerState == CJ135_STATE_FAILUREMODE1))
         {
            pLocStrData->enuInternalRamSequencerState = pLocStrData->enuInternalSequencerState;
         }
         else
         {
            pLocStrData->enuInternalRamSequencerState = CJ135_u16EXTRACT_MODE(pLocStrData->u16RamDataMode);
         }
      }

      /* Update the new sequences to launcha ccording to the new internal sequencer state */
      CJ135_vidStateMachineMain(pLockstrConfig, pLocStrData);
   }

   /* Call the Manager to start next pending sequence */
   CJ135_vidSpiM_Manager(pLockstrConfig, pLocStrData);
}


#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
