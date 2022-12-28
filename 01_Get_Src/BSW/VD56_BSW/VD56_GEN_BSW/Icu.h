/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ICU                                                     */
/* !Description     : ICU Component                                           */
/*                                                                            */
/* !File            : Icu.h                                                   */
/* !Description     : Upper Layer of ICU_17_GTMCCU6 components                */
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
 * %PID: P2017_BSW:0A192515.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef _ICU_H_
#define _ICU_H_

#include "Icu_17_GtmCcu6.h"

#define Icu_Ccu_Isr                  Icu_17_GtmCcu6_Ccu_Isr
#define Icu_CheckWakeup              Icu_17_GtmCcu6_CheckWakeup
#define Icu_DeInit                   Icu_17_GtmCcu6_DeInit
#define Icu_DisableEdgeCount         Icu_17_GtmCcu6_DisableEdgeCount
#define Icu_DisableEdgeDetection     Icu_17_GtmCcu6_DisableEdgeDetection
#define Icu_DisableNotification      Icu_17_GtmCcu6_DisableNotification
#define Icu_DisableWakeup            Icu_17_GtmCcu6_DisableWakeup
#define Icu_EnableEdgeCount          Icu_17_GtmCcu6_EnableEdgeCount
#define Icu_EnableEdgeDetection      Icu_17_GtmCcu6_EnableEdgeDetection
#define Icu_EnableNotification       Icu_17_GtmCcu6_EnableNotification
#define Icu_EnableWakeup             Icu_17_GtmCcu6_EnableWakeup
#define Icu_GetDutyCycleValues       Icu_17_GtmCcu6_GetDutyCycleValues
#define Icu_GetEdgeNumbers           Icu_17_GtmCcu6_GetEdgeNumbers
#define Icu_GetInputState            Icu_17_GtmCcu6_GetInputState
#define Icu_GetTimeElapsed           Icu_17_GtmCcu6_GetTimeElapsed
#define Icu_GetTimestampIndex        Icu_17_GtmCcu6_GetTimestampIndex
#define Icu_GetVersionInfo           Icu_17_GtmCcu6_GetVersionInfo
#define Icu_Init                     Icu_17_GtmCcu6_Init
#define Icu_Isr                      Icu_17_GtmCcu6_Isr
#define Icu_ResetEdgeCount           Icu_17_GtmCcu6_ResetEdgeCount
#define Icu_SetActivationCondition   Icu_17_GtmCcu6_SetActivationCondition
#define Icu_SetMode                  Icu_17_GtmCcu6_SetMode
#define Icu_StartSignalMeasurement   Icu_17_GtmCcu6_StartSignalMeasurement
#define Icu_StartTimestamp           Icu_17_GtmCcu6_StartTimestamp
#define Icu_StopSignalMeasurement    Icu_17_GtmCcu6_StopSignalMeasurement
#define Icu_StopTimestamp            Icu_17_GtmCcu6_StopTimestamp

/******************************************************************************/
/* TYPDEF                                                                     */
/******************************************************************************/
#define Icu_ActivationType           Icu_17_GtmCcu6_ActivationType
#define Icu_ChannelType              Icu_17_GtmCcu6_ChannelType
#define Icu_ConfigType               Icu_17_GtmCcu6_ConfigType
#define Icu_DutyCycleType            Icu_17_GtmCcu6_DutyCycleType
#define Icu_EdgeNumberType           Icu_17_GtmCcu6_EdgeNumberType
#define Icu_IndexType                Icu_17_GtmCcu6_IndexType
#define Icu_InputStateType           Icu_17_GtmCcu6_InputStateType
#define Icu_MeasurementModeType      Icu_17_GtmCcu6_MeasurementModeType
#define Icu_ModeType                 Icu_17_GtmCcu6_ModeType
#define Icu_SignalMeasurementPropertyType \
    Icu_17_GtmCcu6_SignalMeasurementPropertyType
#define Icu_TimestampBufferType      Icu_17_GtmCcu6_TimestampBufferType
#define Icu_ValueType                Icu_17_GtmCcu6_ValueType

#endif  /* _ICU_H_ */

/*------------------------------ end of file ---------------------------------*/
