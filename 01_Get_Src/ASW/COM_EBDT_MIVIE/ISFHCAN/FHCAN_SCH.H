/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCAN_SCH.H */

#ifndef FHCAN_SCH_H
#define FHCAN_SCH_H

#include "STD_TYPES.H"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_EveRxF092_AckClbk(void);
extern void FHCAN_EveRxF092_TOutClbk(void);
extern boolean FHCAN_EveRxF092_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveRxF0A8_AckClbk(void);
extern void FHCAN_EveRxF0A8_TOutClbk(void);
extern boolean FHCAN_EveRxF0A8_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveRxF0E0_AckClbk(void);
extern void FHCAN_EveRxF0E0_TOutClbk(void);
extern boolean FHCAN_EveRxF0E0_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveRxF305_AckClbk(void);
extern void FHCAN_EveRxF305_TOutClbk(void);
extern boolean FHCAN_EveRxF305_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF305_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF30D_AckClbk(void);
extern void FHCAN_EveRxF30D_TOutClbk(void);
extern boolean FHCAN_EveRxF30D_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF30D_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF329_AckClbk(void);
extern void FHCAN_EveRxF329_TOutClbk(void);
extern boolean FHCAN_EveRxF329_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF329_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF349_AckClbk(void);
extern void FHCAN_EveRxF349_TOutClbk(void);
extern boolean FHCAN_EveRxF349_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF349_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF34D_AckClbk(void);
extern void FHCAN_EveRxF34D_TOutClbk(void);
extern boolean FHCAN_EveRxF34D_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF34D_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF38D_AckClbk(void);
extern void FHCAN_EveRxF38D_TOutClbk(void);
extern boolean FHCAN_EveRxF38D_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF38D_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF3AD_AckClbk(void);
extern void FHCAN_EveRxF3AD_TOutClbk(void);
extern boolean FHCAN_EveRxF3AD_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF3AD_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF3C9_AckClbk(void);
extern void FHCAN_EveRxF3C9_TOutClbk(void);
extern boolean FHCAN_EveRxF3C9_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF3C9_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF3CD_AckClbk(void);
extern void FHCAN_EveRxF3CD_TOutClbk(void);
extern boolean FHCAN_EveRxF3CD_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF3CD_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF412_AckClbk(void);
extern void FHCAN_EveRxF412_TOutClbk(void);
extern boolean FHCAN_EveRxF412_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF412_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF432_AckClbk(void);
extern void FHCAN_EveRxF432_TOutClbk(void);
extern boolean FHCAN_EveRxF432_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF432_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF44D_AckClbk(void);
extern void FHCAN_EveRxF44D_TOutClbk(void);
extern boolean FHCAN_EveRxF44D_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF44D_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF489_AckClbk(void);
extern void FHCAN_EveRxF489_TOutClbk(void);
extern boolean FHCAN_EveRxF489_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF489_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF492_AckClbk(void);
extern void FHCAN_EveRxF492_TOutClbk(void);
extern boolean FHCAN_EveRxF492_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF492_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF495_AckClbk(void);
extern void FHCAN_EveRxF495_TOutClbk(void);
extern boolean FHCAN_EveRxF495_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF495_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF4B2_AckClbk(void);
extern void FHCAN_EveRxF4B2_TOutClbk(void);
extern boolean FHCAN_EveRxF4B2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF4B2_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF4C8_AckClbk(void);
extern void FHCAN_EveRxF4C8_TOutClbk(void);
extern boolean FHCAN_EveRxF4C8_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveRxF4D2_AckClbk(void);
extern void FHCAN_EveRxF4D2_TOutClbk(void);
extern boolean FHCAN_EveRxF4D2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF4D2_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF4F2_AckClbk(void);
extern void FHCAN_EveRxF4F2_TOutClbk(void);
extern boolean FHCAN_EveRxF4F2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF4F2_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF50D_AckClbk(void);
extern void FHCAN_EveRxF50D_TOutClbk(void);
extern boolean FHCAN_EveRxF50D_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF50D_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF50E_AckClbk(void);
extern void FHCAN_EveRxF50E_TOutClbk(void);
extern boolean FHCAN_EveRxF50E_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF50E_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF532_AckClbk(void);
extern void FHCAN_EveRxF532_TOutClbk(void);
extern boolean FHCAN_EveRxF532_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF532_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF552_AckClbk(void);
extern void FHCAN_EveRxF552_TOutClbk(void);
extern boolean FHCAN_EveRxF552_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF552_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF55F_AckClbk(void);
extern void FHCAN_EveRxF55F_TOutClbk(void);
extern boolean FHCAN_EveRxF55F_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveRxF572_AckClbk(void);
extern void FHCAN_EveRxF572_TOutClbk(void);
extern boolean FHCAN_EveRxF572_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF572_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF57C_AckClbk(void);
extern void FHCAN_EveRxF57C_TOutClbk(void);
extern boolean FHCAN_EveRxF57C_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF57C_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF592_AckClbk(void);
extern void FHCAN_EveRxF592_TOutClbk(void);
extern boolean FHCAN_EveRxF592_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF592_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF5B2_AckClbk(void);
extern void FHCAN_EveRxF5B2_TOutClbk(void);
extern boolean FHCAN_EveRxF5B2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF5B2_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF612_AckClbk(void);
extern void FHCAN_EveRxF612_TOutClbk(void);
extern boolean FHCAN_EveRxF612_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF612_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF772_AckClbk(void);
extern void FHCAN_EveRxF772_TOutClbk(void);
extern boolean FHCAN_EveRxF772_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveRxF792_AckClbk(void);
extern void FHCAN_EveRxF792_TOutClbk(void);
extern boolean FHCAN_EveRxF792_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF792_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRxF7F2_AckClbk(void);
extern void FHCAN_EveRxF7F2_TOutClbk(void);
extern boolean FHCAN_EveRxF7F2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
extern void FHCAN_EveCntF7F2_Clbk(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
extern void FHCAN_EveRst_Init(void);
extern void FHCAN_EveTxF208_AckClbk(void);
extern void FHCAN_EveTxF208_TOutClbk(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
