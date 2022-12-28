/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_SpiM.h                                                                                    */
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
 * %PID: LIBEMB:A6046.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef L9960_SPIM_H
#define L9960_SPIM_H

#include "Std_Types.h"
#include "L9960_Private.h"
#include "L9960_Cfg.h"
#include "L9960_Types.h"
#include "SchM_L9960.h"
#include "SWFAIL.h"


/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/
#define L9960_START_SEC_CONST_UNSPECIFIED
#include "L9960_MemMap.h"

extern L9960_tkpfvidSpiM_TxConf L9960_pfvidSpiM_TxConfFct[L9960_SPIM_SEQ_NB_OF_CMD];

#define L9960_STOP_SEC_CONST_UNSPECIFIED
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"

extern void L9960_vidSpiM_Init(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_Manager(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_MainFunction(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_DiagOnSeq1Start(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_DiagOnSeq1TxConf(const L9960_tstrConfig *pkstrConfig,
                                           L9960_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void L9960_vidSpiM_DiagOnSeq2Start(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_DiagOnSeq2TxConf(const L9960_tstrConfig *pkstrConfig,
                                           L9960_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);

extern void L9960_vidSpiM_DiagOffSeqStart(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_DiagOffSeqTxConf(const L9960_tstrConfig *pkstrConfig,
                                           L9960_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);

                                           extern void L9960_vidSpiM_HwscStart(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_HwscMainFct(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_HwscTxConf(const L9960_tstrConfig *pkstrConfig,
                                           L9960_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);

extern void L9960_vidSpiM_RegInitStart(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_RegInitTxConf(const L9960_tstrConfig *pkstrConfig,
                                        L9960_strData          *pstrData,
                                        uint16                  u16ReceiveData,
                                        uint8                   u8SpiError);

extern void L9960_vidSpiM_RegCheckStart(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidSpiM_RegCheckTxConf(const L9960_tstrConfig *pkstrConfig,
                                         L9960_strData          *pstrData,
                                         uint16                 u16ReceiveData,
                                         uint8                  u8SpiError);

extern void L9960_vidSpiM_StartOnDiagnosticSeq1(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData);

extern void L9960_vidSpiM_StartOnDiagnosticSeq2(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData);

extern void L9960_vidSpiM_StartOffStateDiagnostic(const L9960_tstrConfig *pkstrConfig,
                                                  L9960_strData          *pstrData);


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_EndOfSequence                                                                         */
/* !Description : Function to call to stop a sequence in progress                                                     */
/*                This function re-init the state machine and call the manager to start next pending sequence         */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiM_EndOfSequence(const L9960_tstrConfig *pkstrConfig,
                                              L9960_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   /* Reset the state machine */
   pstrData->udtSpiM_StateMachine.All = L9960_SPI_SEQ_IDLE;
   pstrData->enuSpiM_SeqRunning       = L9960_SPIM_SEQ_WAITING_STATE; /* All state machine are idle */;

   /* This function allow to trig an event (like an ActivateTask) to laucnh the function L9960_vidSpiM_MainFunction  */
   SchM_Trigger_L9960_SpiM();
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_ManagerTxConf                                                                         */
/* !Description : This function is the SPI interrupt entry point (for the SPI manager i.e upper layer )               */
/*                It calls the right function according to the active state machine.                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiM_ManagerTxConf(const L9960_tstrConfig *pkstrConfig,
                                              L9960_strData          *pstrData,
                                              uint16                  u16ReceiveData,
                                              uint8                   u8SpiResult)
{
   L9960_tenuSpiMSequences enuLocSeqRunning;


   if (u8SpiResult != L9960_u8SPI_OK)
   {
      pstrData->u8SpiDiagnostic = u8SpiResult;
   }
   
   enuLocSeqRunning = pstrData->enuSpiM_SeqRunning;
   if (enuLocSeqRunning < L9960_SPIM_SEQ_NB_OF_CMD)
   {
      /* launch the Tx Confirmation function of the active sequence */
      L9960_pfvidSpiM_TxConfFct[enuLocSeqRunning](pkstrConfig, pstrData, u16ReceiveData, u8SpiResult);
   }
   else
   {
      /* we sent a SPI command, but no sequence is running */
      /* Stop all State Machine */
      pstrData->udtSpiM_StateMachine.All = L9960_SPI_SEQ_IDLE;

      /* TODO: request flag to reset ?? or let it to true to restart ? */
      /* pstrData->abSpiM_SeqRequest[enuLocSeqRunning] = FALSE; */
      SWFAIL_vidSoftwareErrorHook();
   }
}


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_UpdateRegState2                                                                       */
/* !Description : This function update the ram image of Register State 2                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiM_UpdateRegState2(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData,
                                                uint16                  u16ReceiveData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   pstrData->u16SpiMChipRegState2 = u16ReceiveData;
   pstrData->bSpiMNewRegState2 = TRUE;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_UpdateRegConfig5                                                                      */
/* !Description : This function update the ram image of Register State 5                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiM_UpdateRegConfig5(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData           *pstrData,
                                                uint16                  u16ReceiveData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   pstrData->u16SpiMChipRegConfig5 = u16ReceiveData;
   
   /* Each update of u16SpiMChipRegConfig5 must set the bSpiMNewRegState5 flag */
   /* Reason: to not loose the CC latch information                            */
   pstrData->bSpiMNewRegState5 = TRUE;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_UpdateOverCurrent                                                                     */
/* !Description : This function update the ram image of over Current                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiM_UpdateOverCurrent(const L9960_tstrConfig *pkstrConfig,
                                                  L9960_strData          *pstrData,
                                                  uint16                  u16ReceiveData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   pstrData->u16SpiMChipRegOverCurrent = u16ReceiveData;
   pstrData->bSpiMNewRegOverCurrent = TRUE;
}

#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

#endif /* L9960_SPIM_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
