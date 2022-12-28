#ifndef MUET_H
#define MUET_H
ADCHAL_tudtAdcResult ADCHAL_udtRead(uint8 u8Channel);
void DGOHAL_akpfvidCallback(void);
void DGOHAL_vidClearConfirmedFailure(DGOHAL_tudtChannel udtChannel,DGOHAL_tbfStatus bfFaultIds );
void DGOHAL_vidDisableNotification(DGOHAL_tudtChannel udtChannel);
void DGOHAL_vidEnableNotification(DGOHAL_tudtChannel udtChannel);
void DGOHAL_vidSetConfirmedFailure(DGOHAL_tudtChannel udtChannel, DGOHAL_tbfStatus bfFaultIds);
void vidFaultFilteringManagement(DGOHAL_tudtChannel udtChannel,DGOHAL_tbfStatus bfStatus );
void HBHAL_vidDisable(uint8 u8Channel);
void HBHAL_vidDisableNotification(uint8 u8Channel);
void HBHAL_vidEnable(uint8 u8Channel);
void HBHAL_vidEnableNotification(uint8 u8Channel);
void HBHAL_vidInit(void);
void HBHAL_vidWrite(uint8 u8Channel, HBHAL_tudtSetPoint udtSetPoint);
HBHAL_tenuStatus HBHAL_enuReadStatus(uint8 u8Channel);
void TDCHAL_vidFIND_LAST_SETPOINT(void);
void TDCHAL_vidGET_TDC_COUNTER(uint8 u8Counter);
void TDCHAL_vidNEXT_SETPOINT(void);
void TDCHAL_vidON_SETPOINT(void);
void TDCHAL_vidPROGRAM_SETPOINT(void);
Std_ReturnType TDCHAL_udtReadCounter(uint8  *pu8Counter);
Std_ReturnType TDCHAL_udtReadRawCounter(uint8  *pu8Counter);
Std_ReturnType TDCHAL_udtReadPeriod(uint32  *pu32Period);

#endif /* MUET_H */
