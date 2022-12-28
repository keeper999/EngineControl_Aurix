/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_SpiM.c                                                                                    */
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
 * %PID: LIBEMB:A6080.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Spi.h"
#include "L9960.h"
#include "L9960_Private.h"
#include "L9960_Spi.h"
#include "L9960_SpiM.h"
#include "L9960_Types.h"
#include "SchM_L9960.h"



/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/
#define L9960_START_SEC_CONST_UNSPECIFIED
#include "L9960_MemMap.h"

/* the both below table order is same as L9960_tenuSpiMSequences enums */
/* SpiM: sequence start function */
STATIC L9960_tkpfvidSpiM_StartSeqFct L9960_pfvidSpiM_StartSeqFct[L9960_SPIM_SEQ_NB_OF_CMD] =
{
   &L9960_vidSpiM_HwscStart,      /* L9960_SPIM_SEQ_HWSC_LAUNCH        */
   &L9960_vidSpiM_RegInitStart,        /* L9960_SPIM_SEQ_INIT_ALL_REGISTER  */
   &L9960_vidSpiM_RegCheckStart,       /* L9960_SPIM_SEQ_CHECK_ALL_REGISTER */
   &L9960_vidSpiM_DiagOnSeq1Start,      /* L9960_SPIM_SEQ_ON_DIAGNOSTIC_1    */
   &L9960_vidSpiM_DiagOnSeq2Start,      /* L9960_SPIM_SEQ_ON_DIAGNOSTIC_2    */
   &L9960_vidSpiM_DiagOffSeqStart,      /* L9960_SPIM_SEQ_OFF_DIAGNOSTIC    */
};
/* SpiM: function to call on SPI TxConfirmation */
L9960_tkpfvidSpiM_TxConf L9960_pfvidSpiM_TxConfFct[L9960_SPIM_SEQ_NB_OF_CMD] =
{
   &L9960_vidSpiM_HwscTxConf,    /* L9960_SPIM_SEQ_HWSC_LAUNCH        */
   &L9960_vidSpiM_RegInitTxConf,      /* L9960_SPIM_SEQ_INIT_ALL_REGISTER  */
   &L9960_vidSpiM_RegCheckTxConf,     /* L9960_SPIM_SEQ_CHECK_ALL_REGISTER */
   &L9960_vidSpiM_DiagOnSeq1TxConf,    /* L9960_SPIM_SEQ_ON_DIAGNOSTIC_1    */
   &L9960_vidSpiM_DiagOnSeq2TxConf,    /* L9960_SPIM_SEQ_ON_DIAGNOSTIC_2    */
   &L9960_vidSpiM_DiagOffSeqTxConf,    /* L9960_SPIM_SEQ_OFF_DIAGNOSTIC    */
};


/* SpiM: sequence start function */
/* BE CAREFULL: these functions must not call L9960_vidSpiTransmit if a Tx confirmation could occurs */  
STATIC L9960_tkpfvidSpiM_StartSeqFct L9960_pfvidSpiM_MainFctSeqFct[L9960_SPIM_SEQ_NB_OF_CMD] =
{
   &L9960_vidSpiM_HwscMainFct,      /* L9960_SPIM_SEQ_HWSC_LAUNCH        */
   NULL_PTR,        /* L9960_SPIM_SEQ_INIT_ALL_REGISTER  */
   NULL_PTR,       /* L9960_SPIM_SEQ_CHECK_ALL_REGISTER */
   NULL_PTR,      /* L9960_SPIM_SEQ_ON_DIAGNOSTIC_1    */
   NULL_PTR,      /* L9960_SPIM_SEQ_ON_DIAGNOSTIC_2    */
   NULL_PTR,      /* L9960_SPIM_SEQ_OFF_DIAGNOSTIC    */
};

#define L9960_STOP_SEC_CONST_UNSPECIFIED
#include "L9960_MemMap.h"


#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"

LOCAL_INLINE boolean L9960_bSpiM_LaunchDiagnsoticAllowed(const L9960_tstrConfig *pkstrConfig,
                                                         L9960_strData          *pstrData);

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_Init                                                                                  */
/* !Description : Init of the SpiM layer                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_Init(const L9960_tstrConfig *pkstrConfig,
                        L9960_strData          *pstrData)
{
   uint8_least u8LocSequence;
   
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   /* All state machine are idle */
   pstrData->udtSpiM_StateMachine.All   = L9960_SPI_SEQ_IDLE;
   pstrData->enuSpiM_SeqRunning         = L9960_SPIM_SEQ_WAITING_STATE;
   pstrData->enuSpiMRegisterInitialized = L9960_REGISTER_INIT_NOT_DONE;
   pstrData->enuSpiMRegisterRead        = L9960_REGISTER_READ_NOT_DONE;

   /* No sequence to run */
   for (u8LocSequence = 0; u8LocSequence < L9960_SPIM_SEQ_NB_OF_CMD; u8LocSequence++)
   {
      pstrData->abSpiM_SeqRequest[u8LocSequence] = FALSE;
   }

   /* Init expected L9960 register value to their Power On reset values */
   pstrData->u16SpiMChipRegConfiguration1 = L9960_u16SPI_POR_VALUE_CONFIG_1;
   pstrData->u16SpiMChipRegConfiguration2 = L9960_u16SPI_POR_VALUE_CONFIG_2;
   pstrData->u16SpiMChipRegConfiguration3 = L9960_u16SPI_POR_VALUE_CONFIG_3;
   pstrData->u16SpiMChipRegConfiguration4 = L9960_u16SPI_POR_VALUE_CONFIG_4;

   /* Last registers value read from L9960: clear to unpossible value to ensure a first read before to use it */
   pstrData->u16SpiMChipRegOverCurrent = 0xFFFFu; /* 4 bits are always = 0 */
   pstrData->u16SpiMChipRegState1      = 0xFFFFu; /* if DIS = 1 then BRIDGE_EN = 0, so FFFF is an imposible value */
   pstrData->u16SpiMChipRegState2      = 0xFFFFu; /* We can't have OTSDcnt = 11111 (i.e. 32 OT fault) and NOTSD_REG = 1 (no OT fault) */
   pstrData->u16SpiMChipRegOffDiag     = 0xFFFFu; /* 9 bits are always = 0 */
   pstrData->u16SpiMChipRegConfig1     = 0xFFFFu; /* 1 bits are always = 0 */
   pstrData->u16SpiMChipRegConfig2     = 0xFFFFu; /* 1 bits are always = 0 */
   pstrData->u16SpiMChipRegConfig3     = 0xFFFFu; /* 6 bits are always = 0 */
   pstrData->u16SpiMChipRegConfig4     = 0xFFFFu; /* 11 bits are always = 0 */
   pstrData->u16SpiMChipRegConfig5     = 0xFFFFu; /* 9 bits are always = 0 */
   
   /* Both belowe initialization : Don't care as they are reloaded before use */
   pstrData->u8SpiM_HWSCTimeout      = 0; 
   pstrData->u8SpiM_HWSCCheckCounter = 0;

   /* By default, no register has been read */
   pstrData->bSpiMNewRegOverCurrent = FALSE;
   pstrData->bSpiMNewRegState2      = FALSE;
   pstrData->bSpiMNewRegState5      = FALSE;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_Manager                                                                               */
/* !Description : This function is the entry point of the Sequence manager                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_Manager(const L9960_tstrConfig *pkstrConfig,
                           L9960_strData          *pstrData)
{
   uint8_least u8LocSeqIdx;
   boolean     bLocSeqFound = FALSE;


   /* if a sequence is already running, we do nothing, otherwise we start the most prior sequence awaiting to run  */

   /* enuSpiM_SeqRunning is a shared data, we consider that its access is atomic */
   if (pstrData->enuSpiM_SeqRunning == L9960_SPIM_SEQ_WAITING_STATE)
   {
      /* If enuSpiM_SeqRunning == L9960_SPIM_SEQ_WAITING_STATE, then no SPI communcation is in progress            */
      /* And so, no SPI interrupt could occurs, and so no concurrent acess to protect.                             */

      for (  u8LocSeqIdx = 0; (u8LocSeqIdx < L9960_SPIM_SEQ_NB_OF_CMD)
          && (bLocSeqFound == FALSE); u8LocSeqIdx++)
      {
         /* We check, in priority order, which sequence to start */
         if (pstrData->abSpiM_SeqRequest[u8LocSeqIdx] != FALSE)
         {
            /* Stop the loop on first found sequence to run */
            bLocSeqFound = TRUE;
            /* Set to the value of sequence which becomes running */
            pstrData->enuSpiM_SeqRunning = (L9960_tenuSpiMSequences)u8LocSeqIdx;
            /* Clear the request */
            pstrData->abSpiM_SeqRequest[u8LocSeqIdx] = FALSE;
            /* launch the found sequence */
            L9960_pfvidSpiM_StartSeqFct[u8LocSeqIdx](pkstrConfig, pstrData);
         }
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_MainFunction                                                                          */
/* !Description : This function is the periodic function for SpiM sequences states machines                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_MainFunction(const L9960_tstrConfig *pkstrConfig,
                                L9960_strData          *pstrData)
{
   L9960_tenuSpiMSequences enuLocSpiSeq;

   /* enuSpiM_SeqRunning is a shared data, we consider that its access is atomic */
   enuLocSpiSeq = pstrData->enuSpiM_SeqRunning;
   if (enuLocSpiSeq != L9960_SPIM_SEQ_WAITING_STATE)
   {
      if(L9960_pfvidSpiM_MainFctSeqFct[enuLocSpiSeq] != NULL_PTR)
      {
         L9960_pfvidSpiM_MainFctSeqFct[enuLocSpiSeq](pkstrConfig, pstrData);
      }
   }
}


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_Task                                                                                  */
/* !Description : this function check if a sequence has to be launched and launches it.                               */
/*                This function must be "trig" by SchM_Trigger_L9960_SpiM                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_Task(void)
{
   uint8_least u8LocChannel;


   for (u8LocChannel = 0; u8LocChannel < L9960_u8NB_OF_DEVICE; u8LocChannel++)
   {
      /* Call the Manager to start next pending sequence */
      L9960_vidSpiM_Manager(&L9960_akstrConfig[u8LocChannel], &L9960_astrData[u8LocChannel]);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_StartOnDiagnosticSeq1                                                                 */
/* !Description : This function launch the On State Diagnostic sequence 1                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_StartOnDiagnosticSeq1(const L9960_tstrConfig *pkstrConfig,
                                         L9960_strData          *pstrData)
{
   boolean bLocDiagnosticAllowed;
   
   /* this test is needing to prevent against shared data issue                                                   */
   /* Diagnsotic is not allowed if a diagnsotic is still running i.e take more than one slot to                   */
   /* perform the diagnostic (which should never occurs). If occurs, the diag request will be done on next period */
   /* of course if diagnostic is finish                                                                           */
   bLocDiagnosticAllowed = L9960_bSpiM_LaunchDiagnsoticAllowed(pkstrConfig, pstrData);
   if(bLocDiagnosticAllowed == TRUE)
   {
      pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_ON_DIAGNOSTIC_1] = TRUE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_StartOnDiagnosticSeq2                                                                 */
/* !Description : This function launch the On State Diagnostic sequence 2                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_StartOnDiagnosticSeq2(const L9960_tstrConfig *pkstrConfig,
                                         L9960_strData          *pstrData)
{
   boolean bLocDiagnosticAllowed;
   
   /* this test is needing to prevent against shared data issue                                                   */
   /* Diagnsotic is not allowed if a diagnsotic is still running i.e take more than one slot to                   */
   /* perform the diagnostic (which should never occurs). If occurs, the diag request will be done on next period */
   /* of course if diagnostic is finish                                                                           */
   bLocDiagnosticAllowed = L9960_bSpiM_LaunchDiagnsoticAllowed(pkstrConfig, pstrData);
   if(bLocDiagnosticAllowed == TRUE)
   {
      pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_ON_DIAGNOSTIC_2] = TRUE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_StartOffStateDiagnostic                                                               */
/* !Description : This function launch the On State Diagnostic sequence 2                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_StartOffStateDiagnostic(const L9960_tstrConfig *pkstrConfig,
                                           L9960_strData          *pstrData)
{
   boolean bLocDiagnosticAllowed;
   
   /* this test is needing to prevent against shared data issue                                                   */
   /* Diagnsotic is not allowed if a diagnsotic is still running i.e take more than one slot to                   */
   /* perform the diagnostic (which should never occurs). If occurs, the diag request will be done on next period */
   /* of course if diagnostic is finish                                                                           */
   bLocDiagnosticAllowed = L9960_bSpiM_LaunchDiagnsoticAllowed(pkstrConfig, pstrData);
   if(bLocDiagnosticAllowed == TRUE)
   {
      pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_OFF_DIAGNOSTIC] = TRUE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_bSpiM_LaunchDiagnsoticAllowed                                                                 */
/* !Description : This function check if diagnostic is allowed                                                        */
/*                It is allowed if last diagnostic was treated by MainFunction                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE boolean L9960_bSpiM_LaunchDiagnsoticAllowed(const L9960_tstrConfig *pkstrConfig,
                                                         L9960_strData          *pstrData)
{
   boolean bReturnDiagnosticAllowed = TRUE;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   
   /* this test is needing to prevent against shared data issue                                                   */
   /* Diagnsotic is not allowed if a diagnsotic is still running i.e take more than one slot to                   */
   /* perform the diagnostic (which should never occurs). If occurs, the diag request will be done on next period */
   /* of course if diagnostic is finish                                                                           */
   if( (pstrData->bOnDiagnosticIsAvailable == TRUE)
       || (pstrData->bOffDiagnosticIsAvailable == TRUE) )
   {
      bReturnDiagnosticAllowed = FALSE;
   }
   
   return(bReturnDiagnosticAllowed);
}

#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
