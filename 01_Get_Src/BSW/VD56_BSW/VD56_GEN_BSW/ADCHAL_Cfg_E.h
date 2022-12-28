/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : ADCHAL                                                  */
/* !Description     : Analog to digital conversion on HAL                     */
/*                                                                            */
/* !File            : ADCHAL_Cfg_E.h                                          */
/* !Description     : ADCHAL configuration                                    */
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
 * %PID: P2017_BSW:0A192553.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef ADCHAL_CFG_E_H
#define ADCHAL_CFG_E_H

#include "Std_Types.h"
#include "ADCHAL_Cfg.h"
/*#include "APLS.h"*/
#include "MATHSRV.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define ADCHAL_u16OFFSET_ASIC 10u /*APLS_u16OFFSET_ASIC*/
#define ADCHAL_u8HEAT_O2_GAIN_UP \
           10u /*APLS_u8HeatO2FactorTable[Apls_gain_chauff_sonde_amont&3]*/
#define ADCHAL_u8HEAT_O2_GAIN_DOWN \
           10u /*APLS_u8HeatO2FactorTable[Apls_gain_chauff_sonde_aval&3]*/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* Private services                                                           */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : ADCHAL_vidAPPLY_TRIMS_ON_VBRF                               */
/* !Description : Returns battery voltage after applying trims                */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
#define ADCHAL_vidAPPLY_TRIMS_ON_VBRF( \
\
   u16AdcbslConvResult,  /* !Comment: ADCBSL conversion result              */ \
   u16Result             /* !Comment: Result including trims                */ \
) \
do \
{ \
   uint32 u32Temp; \
   sint32 s32Temp; \
   sint16 s16Temp; \
\
   s16Temp = (sint16)(ADCHAL_s8BatTrimOffset * 128u); \
   s32Temp = (((sint32)ADCHAL_s8BatTrimGain) + 1024u) \
           * ((sint32)(u16AdcbslConvResult)); \
   s32Temp = ((sint32)s16Temp) + s32Temp; \
   s32Temp = MATHSRV_udtMAX((4u + s32Temp) / 8u, 0u); \
   u32Temp = ((uint32)s32Temp) * 2473UL; \
   (u16Result) = (uint16)((32768u  + u32Temp) >> 16u); \
} \
while (0u)

/******************************************************************************/
/* !FuncName    : ADCHAL_vidCALCULATE_VECU                                    */
/* !Description : Compute Vecu voltage                                        */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
#define ADCHAL_vidCALCULATE_VECU( \
\
   u16Vmicro, \
   u8GAsic, \
   u16Vcmd, \
   u16OffsetAsic, \
   u16Vecu \
\
) \
do \
{ \
   uint32 u32LocalNumer; \
   if ((u16Vmicro) <= (u16OffsetAsic)) \
   { \
      (u16Vecu) = (u16Vcmd); \
   } \
   else \
   { \
      u32LocalNumer = (uint32)((u16Vmicro) - (u16OffsetAsic)); \
      (u16Vecu) = MATHSRV_u16Div_u32_u16(u32LocalNumer, (uint16)(u8GAsic)); \
      (u16Vecu) = (u16Vecu) + (u16Vcmd); \
   } \
} \
while (0u)

/******************************************************************************/
/* !FuncName    : ADCHAL_vidCALCULATE_IO2                                     */
/* !Description : Compute IO2 current                                         */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
#define ADCHAL_vidCALCULATE_IO2( \
\
   u16Vmicro, \
   u8GAsic, \
   u16OffsetAsic, \
   u16Rs, \
   u16IO2 \
\
) \
do \
{ \
   uint32 u32LocalNumer; \
   uint32 u32LocalDenom; \
   uint32 u32LocalDivResult; \
   if ((u16Vmicro) <= (u16OffsetAsic)) \
   { \
      (u16IO2)  = UINT16_MIN; \
   } \
   else \
   { \
      u32LocalNumer = ((uint32)((u16Vmicro)  - (u16OffsetAsic)))<<17; \
/* Shift used to optimize code with all compilator versions.                */ \
/* Shift value for resolution purpose :                                     */ \
/* u16IO2 has a resolution of 8/65536 A                                     */ \
/* u32LocalNumer has a resolution of 5/4096 V                               */ \
/* u32LocalDenom has a resolution of 5/65536 Ohm                            */ \
/* so the resolution adaptation coefficient is 131072 = 2^17                */ \
      u32LocalDenom = ((uint32)(u16Rs)) * (u8GAsic); \
      u32LocalDivResult = MATHSRV_u32Div_u32_u32(u32LocalNumer, \
                                    u32LocalDenom); \
      u32LocalDivResult = MATHSRV_udtMIN(u32LocalDivResult, UINT16_MAX); \
      (u16IO2) = (uint16)u32LocalDivResult; \
   } \
} \
while (0u)


/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/*#define ADCHAL_START_SEC_CALIB_16BIT
#include "ADCHAL_MemMap.h"

extern const uint16 ADCHAL_ku16HeatingMosOffsDWN;
extern const uint16 ADCHAL_ku16HeatingMosOffsUPS;
extern const uint16 ADCHAL_ku16ShuntResistorDWN;
extern const uint16 ADCHAL_ku16ShuntResistorUPS;

#define ADCHAL_STOP_SEC_CALIB_16BIT
#include "ADCHAL_MemMap.h"*/


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define ADCHAL_START_SEC_CODE
#include "MemMap.h"

extern uint32 ADCHAL_u32MultiplyByTwo(ADCHAL_tudtMcalAcquisition udtRawResult);
extern uint16 ADCHAL_u16ApplyTrimsOnVbrf(ADCHAL_tudtMcalAcquisition udtRawResult);
extern uint16 ADCHAL_u16CalculateVecuDwn(ADCHAL_tudtMcalAcquisition udtRawResult);
extern uint16 ADCHAL_u16CalculateIO2Dwn(ADCHAL_tudtMcalAcquisition udtRawResult);
extern uint16 ADCHAL_u16CalculateVecuUps(ADCHAL_tudtMcalAcquisition udtRawResult);
extern uint16 ADCHAL_u16CalculateIO2Ups(ADCHAL_tudtMcalAcquisition udtRawResult);

#define ADCHAL_STOP_SEC_CODE
#include "MemMap.h"


#endif /* ADCHAL_CFG_E_H */

/*------------------------------ end of file ---------------------------------*/