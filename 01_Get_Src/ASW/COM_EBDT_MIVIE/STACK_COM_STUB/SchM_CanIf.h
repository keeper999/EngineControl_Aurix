#if !defined(SCHM_CANIF_H)
#define SCHM_CANIF_H

#include "Os.h"

#define SchM_Enter_CanIf_Generic() SuspendAllInterrupts()
#define SchM_Exit_CanIf_Generic()  ResumeAllInterrupts()


#define SchM_Enter_CanIf_CurrConMode_03            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_03             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_04            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_04             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_17            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_17             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_16            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_16             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_11            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_11             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_14            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_14             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_05            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_05             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_13            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_13             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CurrConMode_15            SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CurrConMode_15             SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_PduChnlMod_15             SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_PduChnlMod_15              SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_PduChnlMod_09             SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_PduChnlMod_09              SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_PduChnlMod_0a             SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_PduChnlMod_0a              SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_PduChnlMod_14             SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_PduChnlMod_14              SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_PduChnlMod_05             SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_PduChnlMod_05              SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_PduChnlMod_13             SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_PduChnlMod_13              SchM_Exit_CanIf_Generic

#define SchM_Enter_CanIf_CS0011                    SchM_Enter_CanIf_Generic
#define SchM_Exit_CanIf_CS0011                     SchM_Exit_CanIf_Generic


/* make SchM empty for unused section in out configuration */
/* then if configuration change and request a new critical section, that will not compile */
#if (0==1)
#define SchM_Enter_CanIf_TxNotifStat_07()
#define SchM_Exit_CanIf_TxNotifStat_07()

#define SchM_Enter_CanIf_TxNotifStat_13()
#define SchM_Exit_CanIf_TxNotifStat_13()

#define SchM_Enter_CanIf_CS004()
#define SchM_Exit_CanIf_CS004()

#define SchM_Enter_CanIf_DynTxPduCanId_0c()
#define SchM_Exit_CanIf_DynTxPduCanId_0c()

#define SchM_Enter_CanIf_DynTxPduCanId_05()
#define SchM_Exit_CanIf_DynTxPduCanId_05()

#define SchM_Enter_CanIf_TxConfStat_17()
#define SchM_Exit_CanIf_TxConfStat_17()

#define SchM_Enter_CanIf_TxConfStat_16()
#define SchM_Exit_CanIf_TxConfStat_16()

#define SchM_Enter_CanIf_TxConfStat_19()
#define SchM_Exit_CanIf_TxConfStat_19()

#define SchM_Enter_CanIf_TxConfStat_13()
#define SchM_Exit_CanIf_TxConfStat_13()

#define SchM_Enter_CanIf_RxNotifStat_08()
#define SchM_Exit_CanIf_RxNotifStat_08()

#define SchM_Enter_CanIf_RxNotifStat_14()
#define SchM_Exit_CanIf_RxNotifStat_14()

#define SchM_Enter_CanIf_CtrlWakeup_16()
#define SchM_Exit_CanIf_CtrlWakeup_16()

#define SchM_Enter_CanIf_CtrlWakeup_11()
#define SchM_Exit_CanIf_CtrlWakeup_11()

#define SchM_Enter_CanIf_CtrlWakeup_12()
#define SchM_Exit_CanIf_CtrlWakeup_12()

#define SchM_Enter_CanIf_CtrlWakeup_14()
#define SchM_Exit_CanIf_CtrlWakeup_14()

#define SchM_Enter_CanIf_CurrConMode_06()
#define SchM_Exit_CanIf_CurrConMode_06()

#define SchM_Enter_CanIf_PduChnlMod_06()
#define SchM_Exit_CanIf_PduChnlMod_06()

#define SchM_Enter_CanIf_CS0010()
#define SchM_Exit_CanIf_CS0010()


#endif /* (0==1) */

#endif /* !defined(SCHM_CANIF_H) */
/*==================[end of file]============================================*/

