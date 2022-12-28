/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM.h                                                                                    */
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
 * %PID: P2017_BSW:0A188671.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef CJ135_SPIM_H
#define CJ135_SPIM_H

#include "Std_Types.h"
#include "CJ135_Private.h"
#include "CJ135_Cfg.h"
#include "CJ135_Types.h"
#include "SchM_CJ135.h"
#include "SWFAIL.h"


/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CONST_UNSPECIFIED
#include "CJ135_MemMap.h"

extern CJ135_tkpfvidSpiM_TxConf CJ135_pfvidSpiM_TxConfFct[CJ135_SPIM_SEQ_NB_OF_CMD];

#define CJ135_STOP_SEC_CONST_UNSPECIFIED
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"

extern void CJ135_vidSpiM_Init(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_Manager(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);

extern void CJ135_vidSpiM_InitConfRegisterStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_InitConfRegisterTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_ReadConfRegisterStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_ReadConfRegisterTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_UpdateConfRegisterStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_UpdateConfRegisterTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_WriteModeStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_WriteModeTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_ReadModesStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_ReadModesTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_ReadRichnessTempStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_ReadRichnessTempTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_ReadTempStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_ReadTempTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_ReadDiagnosticStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_ReadDiagnosticTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);
extern void CJ135_vidSpiM_ReadCompensationStart(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidSpiM_ReadCompensationTxConf(const CJ135_tstrConfig *pkstrConfig,
                                           CJ135_strData          *pstrData,
                                           uint16                  u16ReceiveData,
                                           uint8                   u8SpiError);


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_EndOfSequence                                                                         */
/* !Description : Function to call to stop a sequence in progress                                                     */
/*                This function re-init the state machine and call the manager to start next pending sequence         */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiM_EndOfSequence(const CJ135_tstrConfig *pkstrConfig,
                                              CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   /* Reset the state machine */
   pstrData->udtSpiM_StateMachine.All = CJ135_SPI_SEQ_IDLE;
   pstrData->enuSpiM_SeqRunning       = CJ135_SPIM_SEQ_WAITING_STATE; /* All state machine are idle */

   /* This function allow to trig an event (like an ActivateTask) */
   SchM_Trigger_CJ135_SpiM(pstrData->u8InstanceNumber);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ManagerTxConf                                                                         */
/* !Description : This function is the SPI interrupt entry point (for the SPI manager i.e upper layer )               */
/*                It calls the right function according to the active state machine.                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiM_ManagerTxConf(const CJ135_tstrConfig *pkstrConfig,
                                              CJ135_strData          *pstrData,
                                              uint16                  u16ReceiveData,
                                              uint8                   u8SpiResult)
{
   CJ135_tenuSpiMSequences enuLocSeqRunning;


   if (u8SpiResult != CJ135_u8SPI_OK)
   {
      pstrData->u8SpiDiagnostic = u8SpiResult;
   }

   enuLocSeqRunning = pstrData->enuSpiM_SeqRunning;
   if (enuLocSeqRunning < CJ135_SPIM_SEQ_NB_OF_CMD)
   {
      /* launch the Tx Confirmation function of the active sequence */
      CJ135_pfvidSpiM_TxConfFct[enuLocSeqRunning](pkstrConfig, pstrData, u16ReceiveData, u8SpiResult);
   }
   else
   {
      /* we sent a SPI command, but no sequence is running */
      /* Stop all State Machine */
      pstrData->udtSpiM_StateMachine.All = CJ135_SPI_SEQ_IDLE;

      /* TODO: request flag to reset ?? or let it to true to restart ? */
      /* pstrData->abSpiM_SeqRequest[enuLocSeqRunning] = FALSE; */
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

#endif /* CJ135_SPIM_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
