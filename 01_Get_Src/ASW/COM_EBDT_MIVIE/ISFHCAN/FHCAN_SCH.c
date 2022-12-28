/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCAN_SCH.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "Com.h"
#include "FHCANF092.h"
#include "FHCANF0A8.h"
#include "FHCANF0E0.h"
#include "FHCANF305.h"
#include "FHCANF30D.h"
#include "FHCANF329.h"
#include "FHCANF349.h"
#include "FHCANF34D.h"
#include "FHCANF38D.h"
#include "FHCANF3AD.h"
#include "FHCANF3C9.h"
#include "FHCANF3CD.h"
#include "FHCANF412.h"
#include "FHCANF432.h"
#include "FHCANF44D.h"
#include "FHCANF489.h"
#include "FHCANF492.h"
#include "FHCANF495.h"
#include "FHCANF4B2.h"
#include "FHCANF4C8.h"
#include "FHCANF4D2.h"
#include "FHCANF4F2.h"
#include "FHCANF50D.h"
#include "FHCANF50E.h"
#include "FHCANF532.h"
#include "FHCANF552.h"
#include "FHCANF55F.h"
#include "FHCANF572.h"
#include "FHCANF57C.h"
#include "FHCANF592.h"
#include "FHCANF5B2.h"
#include "FHCANF612.h"
#include "FHCANF772.h"
#include "FHCANF792.h"
#include "FHCANF7F2.h"
#include "ISCANF208.h"
#include "FHCANF208_PRIVATE.h"
#include "FHCAN_SCH.h"
#include "GDGAR.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_EveRxF092_AckClbk(void)
{
   FHCANF092_vidFrameReceived();
}

void FHCAN_EveRxF092_TOutClbk(void)
{
   FHCANF092_vidFrameNotReceived();
}

boolean FHCAN_EveRxF092_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   return TRUE;
}

void FHCAN_EveRxF0A8_AckClbk(void)
{
   FHCANF0A8_vidFrameReceived();
}

void FHCAN_EveRxF0A8_TOutClbk(void)
{
   FHCANF0A8_vidFrameNotReceived();
}

boolean FHCAN_EveRxF0A8_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   return TRUE;
}

void FHCAN_EveRxF0E0_AckClbk(void)
{
   FHCANF0E0_vidFrameReceived();
}

void FHCAN_EveRxF0E0_TOutClbk(void)
{
   FHCANF0E0_vidFrameNotReceived();
}

boolean FHCAN_EveRxF0E0_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   return TRUE;
}

void FHCAN_EveRxF305_AckClbk(void)
{
   FHCANF305_vidFrameReceived();
}

void FHCAN_EveRxF305_TOutClbk(void)
{
   FHCANF305_vidFrameNotReceived();
}

boolean FHCAN_EveRxF305_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN305_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks305IniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF305,
                  &ISCAN_bSecuChkOKF305);
   FHCAN305_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF305_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN305_vidMonCntUpdate();
}

void FHCAN_EveRxF30D_AckClbk(void)
{
   FHCANF30D_vidFrameReceived();
}

void FHCAN_EveRxF30D_TOutClbk(void)
{
   FHCANF30D_vidFrameNotReceived();
}

boolean FHCAN_EveRxF30D_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN30D_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF329_AckClbk(void)
{
   FHCANF329_vidFrameReceived();
}

void FHCAN_EveRxF329_TOutClbk(void)
{
   FHCANF329_vidFrameNotReceived();
}

boolean FHCAN_EveRxF329_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN329_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks329IniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF329,
                  &ISCAN_bSecuChkOKF329);
   FHCAN329_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF329_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN329_vidMonCntUpdate();
}

void FHCAN_EveRxF349_AckClbk(void)
{
   FHCANF349_vidFrameReceived();
}

void FHCAN_EveRxF349_TOutClbk(void)
{
   FHCANF349_vidFrameNotReceived();
}

boolean FHCAN_EveRxF349_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN349_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks349IniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF349,
                  &ISCAN_bSecuChkOKF349);
   FHCAN349_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF349_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN349_vidMonCntUpdate();
}

void FHCAN_EveRxF34D_AckClbk(void)
{
   FHCANF34D_vidFrameReceived();
}

void FHCAN_EveRxF34D_TOutClbk(void)
{
   FHCANF34D_vidFrameNotReceived();
}

boolean FHCAN_EveRxF34D_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN34D_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveCntF34D_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN34D_vidMonCntUpdate();
}

void FHCAN_EveRxF38D_AckClbk(void)
{
   FHCANF38D_vidFrameReceived();
}

void FHCAN_EveRxF38D_TOutClbk(void)
{
   FHCANF38D_vidFrameNotReceived();
}

boolean FHCAN_EveRxF38D_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN38D_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks38DIniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF38D,
                  &ISCAN_bSecuChkOKF38D);
   FHCAN38D_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF38D_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN38D_vidMonCntUpdate();
}

void FHCAN_EveRxF3AD_AckClbk(void)
{
   FHCANF3AD_vidFrameReceived();
}

void FHCAN_EveRxF3AD_TOutClbk(void)
{
   FHCANF3AD_vidFrameNotReceived();
}

boolean FHCAN_EveRxF3AD_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN3AD_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks3ADIniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF3AD,
                  &ISCAN_bSecuChkOKF3AD);
   FHCAN3AD_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF3AD_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN3AD_vidMonCntUpdate();
}

void FHCAN_EveRxF3C9_AckClbk(void)
{
   FHCANF3C9_vidFrameReceived();
}

void FHCAN_EveRxF3C9_TOutClbk(void)
{
   FHCANF3C9_vidFrameNotReceived();
}

boolean FHCAN_EveRxF3C9_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN3C9_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks3C9IniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF3C9,
                  &ISCAN_bSecuChkOKF3C9);
   FHCAN3C9_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF3C9_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN3C9_vidMonCntUpdate();
}

void FHCAN_EveRxF3CD_AckClbk(void)
{
   FHCANF3CD_vidFrameReceived();
}

void FHCAN_EveRxF3CD_TOutClbk(void)
{
   FHCANF3CD_vidFrameNotReceived();
}

boolean FHCAN_EveRxF3CD_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN3CD_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF412_AckClbk(void)
{
   FHCANF412_vidFrameReceived();
}

void FHCAN_EveRxF412_TOutClbk(void)
{
   FHCANF412_vidFrameNotReceived();
}

boolean FHCAN_EveRxF412_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN412_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF432_AckClbk(void)
{
   FHCANF432_vidFrameReceived();
}

void FHCAN_EveRxF432_TOutClbk(void)
{
   FHCANF432_vidFrameNotReceived();
}

boolean FHCAN_EveRxF432_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN432_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF44D_AckClbk(void)
{
   FHCANF44D_vidFrameReceived();
}

void FHCAN_EveRxF44D_TOutClbk(void)
{
   FHCANF44D_vidFrameNotReceived();
}

boolean FHCAN_EveRxF44D_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN44D_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF489_AckClbk(void)
{
   FHCANF489_vidFrameReceived();
}

void FHCAN_EveRxF489_TOutClbk(void)
{
   FHCANF489_vidFrameNotReceived();
}

boolean FHCAN_EveRxF489_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN489_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF492_AckClbk(void)
{
   FHCANF492_vidFrameReceived();
}

void FHCAN_EveRxF492_TOutClbk(void)
{
   FHCANF492_vidFrameNotReceived();
}

boolean FHCAN_EveRxF492_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN492_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF495_AckClbk(void)
{
   FHCANF495_vidFrameReceived();
}

void FHCAN_EveRxF495_TOutClbk(void)
{
   FHCANF495_vidFrameNotReceived();
}

boolean FHCAN_EveRxF495_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN495_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF4B2_AckClbk(void)
{
   FHCANF4B2_vidFrameReceived();
}

void FHCAN_EveRxF4B2_TOutClbk(void)
{
   FHCANF4B2_vidFrameNotReceived();
}

boolean FHCAN_EveRxF4B2_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN4B2_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF4C8_AckClbk(void)
{
   FHCANF4C8_vidFrameReceived();
}

void FHCAN_EveRxF4C8_TOutClbk(void)
{
   FHCANF4C8_vidFrameNotReceived();
}

boolean FHCAN_EveRxF4C8_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   return TRUE;
}

void FHCAN_EveRxF4D2_AckClbk(void)
{
   FHCANF4D2_vidFrameReceived();
}

void FHCAN_EveRxF4D2_TOutClbk(void)
{
   FHCANF4D2_vidFrameNotReceived();
}

boolean FHCAN_EveRxF4D2_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN4D2_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF4F2_AckClbk(void)
{
   FHCANF4F2_vidFrameReceived();
}

void FHCAN_EveRxF4F2_TOutClbk(void)
{
   FHCANF4F2_vidFrameNotReceived();
}

boolean FHCAN_EveRxF4F2_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN4F2_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF50D_AckClbk(void)
{
   FHCANF50D_vidFrameReceived();
}

void FHCAN_EveRxF50D_TOutClbk(void)
{
   FHCANF50D_vidFrameNotReceived();
}

boolean FHCAN_EveRxF50D_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN50D_vidMonShoUpdate(PduInfoPtr->SduLength);
   CanSecuChkData(Ext_noCks50DIniCks_C,
                  PduInfoPtr->SduDataPtr,
                  (uint8)PduInfoPtr->SduLength,
                  &ISCAN_u8SecuResultF50D,
                  &ISCAN_bSecuChkOKF50D);
   FHCAN50D_vidMonChkUpdate();
   return TRUE;
}

void FHCAN_EveCntF50D_Clbk
(
   PduIdType ComPduId,
   uint8 ExpectedCounter,
   uint8 ReceivedCounter
)
{
   FHCAN50D_vidMonCntUpdate();
}

void FHCAN_EveRxF50E_AckClbk(void)
{
   FHCANF50E_vidFrameReceived();
}

void FHCAN_EveRxF50E_TOutClbk(void)
{
   FHCANF50E_vidFrameNotReceived();
}

boolean FHCAN_EveRxF50E_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN50E_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF532_AckClbk(void)
{
   FHCANF532_vidFrameReceived();
}

void FHCAN_EveRxF532_TOutClbk(void)
{
   FHCANF532_vidFrameNotReceived();
}

boolean FHCAN_EveRxF532_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN532_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF552_AckClbk(void)
{
   FHCAN_BSI_552_vidFrameReceived();
   FHCAN_V2_BSI_552_vidFrameReceived();
}

void FHCAN_EveRxF552_TOutClbk(void)
{
   FHCAN_BSI_552_vidFrameNotReceived();
   FHCAN_V2_BSI_552_vidFrameNotReceived();
}

boolean FHCAN_EveRxF552_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCANBSI_552_vidMonShoUpdate(PduInfoPtr->SduLength);
   FHCANV2_BSI_552_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF55F_AckClbk(void)
{
   FHCANF55F_vidFrameReceived();
}

void FHCAN_EveRxF55F_TOutClbk(void)
{
   FHCANF55F_vidFrameNotReceived();
}

boolean FHCAN_EveRxF55F_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   return TRUE;
}

void FHCAN_EveRxF572_AckClbk(void)
{
   FHCANF572_vidFrameReceived();
}

void FHCAN_EveRxF572_TOutClbk(void)
{
   FHCANF572_vidFrameNotReceived();
}

boolean FHCAN_EveRxF572_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN572_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF57C_AckClbk(void)
{
   FHCANF57C_vidFrameReceived();
}

void FHCAN_EveRxF57C_TOutClbk(void)
{
   FHCANF57C_vidFrameNotReceived();
}

boolean FHCAN_EveRxF57C_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN57C_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF592_AckClbk(void)
{
   FHCANF592_vidFrameReceived();
}

void FHCAN_EveRxF592_TOutClbk(void)
{
   FHCANF592_vidFrameNotReceived();
}

boolean FHCAN_EveRxF592_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN592_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF5B2_AckClbk(void)
{
   FHCANF5B2_vidFrameReceived();
}

void FHCAN_EveRxF5B2_TOutClbk(void)
{
   FHCANF5B2_vidFrameNotReceived();
}

boolean FHCAN_EveRxF5B2_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN5B2_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF612_AckClbk(void)
{
   FHCANF612_vidFrameReceived();
}

void FHCAN_EveRxF612_TOutClbk(void)
{
   FHCANF612_vidFrameNotReceived();
}

boolean FHCAN_EveRxF612_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN612_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF772_AckClbk(void)
{
   FHCANF772_vidFrameReceived();
}

void FHCAN_EveRxF772_TOutClbk(void)
{
   FHCANF772_vidFrameNotReceived();
}

boolean FHCAN_EveRxF772_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   return TRUE;
}

void FHCAN_EveRxF792_AckClbk(void)
{
   FHCANF792_vidFrameReceived();
}

void FHCAN_EveRxF792_TOutClbk(void)
{
   FHCANF792_vidFrameNotReceived();
}

boolean FHCAN_EveRxF792_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN792_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRxF7F2_AckClbk(void)
{
   FHCANF7F2_vidFrameReceived();
}

void FHCAN_EveRxF7F2_TOutClbk(void)
{
   FHCANF7F2_vidFrameNotReceived();
}

boolean FHCAN_EveRxF7F2_Callout
(
   PduIdType PduId,
   const PduInfoType* PduInfoPtr
)
{
   FHCAN7F2_vidMonShoUpdate(PduInfoPtr->SduLength);
   return TRUE;
}

void FHCAN_EveRst_Init(void)
{
   FHCAN_vidInit_Rx_092();
   FHCAN_vidInit_Rx_0A8();
   FHCAN_vidInit_Rx_0E0();
   FHCAN_vidInit_Rx_305();
   FHCAN_vidInit_Rx_30D();
   FHCAN_vidInit_Rx_329();
   FHCAN_vidInit_Rx_349();
   FHCAN_vidInit_Rx_34D();
   FHCAN_vidInit_Rx_38D();
   FHCAN_vidInit_Rx_3AD();
   FHCAN_vidInit_Rx_3C9();
   FHCAN_vidInit_Rx_3CD();
   FHCAN_vidInit_Rx_412();
   FHCAN_vidInit_Rx_432();
   FHCAN_vidInit_Rx_44D();
   FHCAN_vidInit_Rx_489();
   FHCAN_vidInit_Rx_492();
   FHCAN_vidInit_Rx_495();
   FHCAN_vidInit_Rx_4B2();
   FHCAN_vidInit_Rx_4C8();
   FHCAN_vidInit_Rx_4D2();
   FHCAN_vidInit_Rx_4F2();
   FHCAN_vidInit_Rx_50D();
   FHCAN_vidInit_Rx_50E();
   FHCAN_vidInit_Rx_532();
   FHCAN_vidInit_Rx_552();
   FHCAN_vidInit_Rx_55F();
   FHCAN_vidInit_Rx_572();
   FHCAN_vidInit_Rx_57C();
   FHCAN_vidInit_Rx_592();
   FHCAN_vidInit_Rx_5B2();
   FHCAN_vidInit_Rx_612();
   FHCAN_vidInit_Rx_772();
   FHCAN_vidInit_Rx_792();
   FHCAN_vidInit_Rx_7F2();
}

void FHCAN_EveSdl100ms(void)
{
   FHCAN_vidCheckBSIWindow();
   FHCAN_vidCheckCAPT_VOLWindow();
   FHCAN_vidCheckUC_FREINWindow();
   FHCAN_vidCheckBVWindow();
   FHCAN_vidCheckUC_DIRAWindow();
   FHCAN_vidCheckDMTRWindow();
}

void FHCAN_EveTxF208_AckClbk (void)
{
   boolean Local_bCtrl_CMM_208;


   FHCAN208_vidCalcMonCMMWindow();
   VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
   if (ACTIVATED == Local_bCtrl_CMM_208)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCMMAbsent)
      {
         Ext_bDgoCMMAbsent = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CMMABSENT,
                      Ext_bDgoCMMAbsent,
                      Ext_bMonRunCMMAbsent,
                      DIAG_DISPO);
      }
   }
}

void FHCAN_EveTxF208_TOutClbk (void)
{
   boolean Local_bCtrl_CMM_208;


   FHCAN208_vidCalcMonCMMWindow();
   VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
   if (ACTIVATED == Local_bCtrl_CMM_208)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCMMAbsent)
      {
         Ext_bDgoCMMAbsent = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CMMABSENT,
                      Ext_bDgoCMMAbsent,
                      Ext_bMonRunCMMAbsent,
                      DIAG_DISPO);
      }
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
