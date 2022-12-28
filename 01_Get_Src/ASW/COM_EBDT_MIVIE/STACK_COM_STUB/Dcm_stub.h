/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       : TST_CAN                                                 */
/* !Description     : Test of CAN component                                   */
/*                                                                            */
/* !File            : TST_CAN.h                                               */
/* !Description     : Test of CAN component APIs                              */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111901.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef DCM_STUB_H
#define DCM_STUB_H

#include "Std_Types.h"
#include "Can.h"
#include "CanIf.h"

/******************************************************************************/
/* DEFINE DECLARATIONS                                                        */
/******************************************************************************/

#define CDD_CanTpTxNPdu_688 0
#define CDD_RXCanTpRxNPdu_6A8 0

/******************************************************************************/
/* FUNCTION DECLARATIONS                                                      */
/******************************************************************************/

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"

void TST_CAN_vidInit(void);
void TST_COM_RxInd_DoC(PduIdType udtPduId, PduInfoType *pstrPduInfo);
void TST_COM_TxConf_DoC(PduIdType udtPduId);

#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"

#endif /* DCM_STUB_H */

/*------------------------------- end of file --------------------------------*/
