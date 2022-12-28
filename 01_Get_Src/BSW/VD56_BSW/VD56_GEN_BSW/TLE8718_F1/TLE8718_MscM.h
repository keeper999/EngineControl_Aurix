/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_MscM.h                                                                                  */
/* !Description     : To Handle the MSC Protocol                                                                      */
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
 * %PID: P2017_BSW:0A133938.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_MSCM_H
#define TLE8718_MSCM_H

#include "Std_Types.h"

#include "HOD.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* DEFINE                                                                                                             */
/**********************************************************************************************************************/

#define TLE8718_udtMSCM_SEQUENCE_NB         0x06u

#define TLE8718_u8MSCM_RD_DATA_ID           0x13u
#define TLE8718_u8MSCM_RD_CONFIG_ID         0x10u
#define TLE8718_u8MSCM_WR_RST_ID            0x08u
#define TLE8718_u8MSCM_WR_START_ID          0x0Bu
#define TLE8718_u8MSCM_WR_CONREG1_ID        0x01u
#define TLE8718_u8MSCM_WR_CONREG2_ID        0x02u
#define TLE8718_u8MSCM_WR_CONREG3_ID        0x04u
#define TLE8718_u8MSCM_WR_CONREG4_ID        0x0Du
#define TLE8718_u8MSCM_WR_OUT1516_ID        0x07u

#define TLE8718_u8MSCM_RD_ALL_DIAG_REG      0xFFu
#define TLE8718_u8MSCM_RD_DIAREG6           0x04u

#define TLE8718_u8MSCM_RD_ALL_CONFIG_REG    0xF8u /* Registers CONREGx + OUT1516 */
#define TLE8718_u8MSCM_RD_CFG_REG_1_TO_4    0xF0u
#define TLE8718_u8MSCM_RD_CFG_OUT1516REG    0x08u

#define TLE8718_u8MSCM_UNKNOWN_ID           0x00u

/**********************************************************************************************************************/
/* DATA                                                                                                               */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"
extern uint8 TLE8718_au8MscM_CmdData[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscM_CmdId[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscM_ExpectedRxFramNb[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscM_RdDiagReg6Cnt[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8MscM_ErrorStatus[TLE8718_udtINSTANCE_NB];
#define TLE8718_STOP_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "TLE8718_MemMap.h"
extern TLE8718_tenuMscMSequences TLE8718_aenuMscM_SeqRunning[TLE8718_udtINSTANCE_NB];
extern TLE8718_tenuReturnType    TLE8718_audtMscM_SeqStatus[TLE8718_udtINSTANCE_NB][TLE8718_udtMSCM_SEQUENCE_NB];
#define TLE8718_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_BOOLEAN
#include "TLE8718_MemMap.h"
extern boolean TLE8718_abMscM_SeqRequest[TLE8718_udtINSTANCE_NB][TLE8718_udtMSCM_SEQUENCE_NB];
#define TLE8718_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

void TLE8718_vidMscM_ConRegInitStart(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_ConRegInitTxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData,uint8 u8MscResult);
void TLE8718_vidMscM_DiagStart(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_DiagTxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData, uint8 u8MscResult);
void TLE8718_vidMscM_EnaDatFrOutStart(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_EnaDaFrOutTxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData, uint8 u8MscResult);
void TLE8718_vidMscM_Init(void);
void TLE8718_vidMscM_Manager(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_Out1516IniStart(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_Out1516IniTxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData, uint8 u8MscResult);
void TLE8718_vidMscM_SafetyStart(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_SafetyTxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData, uint8 u8MscResult);
void TLE8718_vidMscM_Task(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_WrOut1516Start(HOD_tudtInstance udtInstance);
void TLE8718_vidMscM_WrOut1516TxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData, uint8 u8MscResult);
void TLE8718_vidMscM_EndOfSequence(HOD_tudtInstance udtInstance, TLE8718_tenuReturnType udtReturnType);
void TLE8718_vidMscM_ManagerTxConf(HOD_tudtInstance udtInstance, uint8* pu8ReceiveData, uint8 u8MscResult);

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

#endif /* TLE8718_MSCM_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
