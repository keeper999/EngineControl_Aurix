/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_E.h                                             */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !Reference       : PTS_DOC_5405229                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MATHSRV E H-99055192X4420X334.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/


#ifndef MATHSRV_E_H
   #define MATHSRV_E_H


   #include "Std_Types.h"


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* !Comment : Divers */
typedef enum
{
   MATHSRV_RISING_SCHMITT_TRIGGER = 0,
   MATHSRV_FALLING_SCHMITT_TRIGGER
} MATHSRV_tenuSchmittTriggerType;


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : MATHSRV_u16CalcParaIncAryU8                                 */
/* !Description : Macro-function which redirect MATHSRV_u16CalcParaIncAryU8 to*/
/*                MATHSRV_u16CalcParaIncAryU8Loc. It enables to call this     */
/*                function with the number of breakpoint instead of this      */
/*                number-1                                                    */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
   #define MATHSRV_u16CalcParaIncAryU8(kau8BreakpointMap, u8Value, \
                                       u8BreakpointNumber)         \
   MATHSRV_u16CalcParaIncAryU8Loc(kau8BreakpointMap, u8Value,      \
                                  (u8BreakpointNumber - 1) )

/******************************************************************************/
/* !FuncName    : MATHSRV_u16CalcParaIncAryU16                                */
/* !Description : Macro-function which redirect MATHSRV_u16CalcParaIncAryU8 to*/
/* !Description : Macro-function which redirect MATHSRV_u16CalcParaIncAryU16  */
/*                to MATHSRV_u16CalcParaIncAryU16Loc. It enables to call this */
/*                function with the number of breakpoint instead of this      */
/*                number-1                                                    */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
   #define MATHSRV_u16CalcParaIncAryU16(kau8BreakpointMap, u8Value, \
                                        u8BreakpointNumber)         \
   MATHSRV_u16CalcParaIncAryU16Loc(kau8BreakpointMap, u8Value,      \
                                   (u8BreakpointNumber - 1) )

/******************************************************************************/
/* !FuncName    : MATHSRV_udtABS                                              */
/* !Description : Macro-function which return the absolute value of a         */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_045.01                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
   #define  MATHSRV_udtABS(a) ( ( (a) < 0) ? (0 - (a) ) : (a) )

/******************************************************************************/
/* !FuncName    : MATHSRV_udtMIN                                              */
/* !Description : Macro-function which return the lesser value beetween a and */
/*                b                                                           */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_046.01                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
   #define  MATHSRV_udtMIN(a, b) ( ( (a) > (b) ) ? (b) : (a) )

/******************************************************************************/
/* !FuncName    : MATHSRV_udtMAX                                              */
/* !Description : Macro-function which return the greater value beetween a and*/
/*                b                                                           */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_048.01                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
   #define  MATHSRV_udtMAX(a, b) ( ( (a) > (b) ) ? (a) : (b) )

/******************************************************************************/
/* !FuncName    : MATHSRV_udtCLAMP                                            */
/* !Description : Macro-function which clamp the value a beetween b and c     */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_050.01                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
   #define  MATHSRV_udtCLAMP(a, b, c) ( ( (a) < (b) ) ? (b) : ( ( (a) > (c) ) \
                                                                ? (c) : (a) ) )


/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

   #define MATHSRV_START_SEC_CODE
   #include "MemMap.h"

/* !Comment : Interpolation on uint8 Map */
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d
   (CONST(uint8, MATHSRV_CONST) kau8Cartography[],
   uint16 u16SiteInterpolation);

FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d09Pts
   (CONST(uint8, MATHSRV_CONST) kau8Cartography[9],
   uint8 u8Value);

FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d11Pts
   (CONST(uint8, MATHSRV_CONST) kau8Cartography[11],
   uint8 u8Value);

FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d17Pts
   (CONST(uint8, MATHSRV_CONST) kau8Cartography[17],
   uint8 u8Value);

FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp2d
   (P2CONST(uint8, AUTOMATIC, MATHSRV_CONST) pkau8Cartography,
   uint16 u16SiteInterpolationXLine,
   uint16 u16SiteInterpolationYColumn,
   uint8 u8BreakpointNumberYColumn);


/* !Comment : Interpolation on uint16 Map */
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d
   (CONST(uint16, MATHSRV_CONST) kau16Cartography[],
   uint16 u16SiteInterpolation);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d09Pts
   (CONST(uint16, MATHSRV_CONST) kau16Cartography[9],
   uint8 u8Value);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d11Pts
   (CONST(uint16, MATHSRV_CONST) kau16Cartography[11],
   uint8 u8Value);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d17Pts
   (CONST(uint16, MATHSRV_CONST) kau16Cartography[17],
   uint8 u8Value);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp2d
   (P2CONST(uint16, AUTOMATIC, MATHSRV_CONST) pkau16Cartography,
   uint16 u16SiteInterpolationXLine,
   uint16 u16SiteInterpolationYColumn,
   uint8 u8BreakpointNumberYColumn);


/* !Comment : Computation of Site and interpolation-ratio parameters */
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16CalcParaIncAryU8Loc
   (CONST(uint8, MATHSRV_CONST) kau8BreakpointMap[],
   uint8 u8Value,
   uint8 u8BreakpointNumberMinusOne);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16CalcParaIncAryU16Loc
   (CONST(uint16, MATHSRV_CONST) kau16BreakpointMap[],
   uint16 u16Value,
   uint8 u8BreakpointNumberMinusOne);


/* !Comment : Filters */
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16FirstOrderFilterGu8
   (uint8 u8FilterGain,
   P2VAR(uint32, AUTOMATIC, MATHSRV_VAR) pu32AccuracyFilterValue,
   uint16 u16MeasuredValue);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16FirstOrderFilterGu16
   (uint16 u16FilterGain,
   P2VAR(uint32, AUTOMATIC, MATHSRV_VAR) pu32AccuracyFilterValue,
   uint16 u16MeasuredValue);

FUNC(sint16, MATHSRV_CODE) MATHSRV_s16FirstOrderFilterGu8
   (uint8 u8FilterGain,
   P2VAR(sint32, AUTOMATIC, MATHSRV_VAR) ps32AccuracyFilterValue,
   sint16 s16MeasuredValue);

FUNC(sint16, MATHSRV_CODE) MATHSRV_s16FirstOrderFilterGu16
   (uint16 u16FilterGain,
   P2VAR(sint32, AUTOMATIC, MATHSRV_VAR) ps32AccuracyFilterValue,
   sint16 s16MeasuredValue);

FUNC(uint8, MATHSRV_CODE) MATHSRV_u8SlewFilter
   (uint8 u8FilteredValue,
   uint8 u8MeasuredValue,
   uint8 u8MaxIncrementValue,
   uint8 u8MaxDecrementValue);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16SlewFilter
   (uint16 u16FilteredValue,
   uint16 u16MeasuredValue,
   uint16 u16MaxIncrementValue,
   uint16 u16MaxDecrementValue);


FUNC(sint8, MATHSRV_CODE) MATHSRV_s8SlewFilter
(
   sint8 s8FilteredValue,
   sint8 s8MeasuredValue,
   uint8 u8MaxIncrementValue,
   uint8 u8MaxDecrementValue);

FUNC(sint16, MATHSRV_CODE) MATHSRV_s16SlewFilter
(
   sint16 s16FilteredValue,
   sint16 s16MeasuredValue,
   uint16 u16MaxIncrementValue,
   uint16 u16MaxDecrementValue);

FUNC(uint16, MATHSRV_CODE) MATHSRV_u16MedianFilter
   (uint16 u16Value1,
   uint16 u16Value2,
   uint16 u16Value3);


/* !Comment : General Threshold */
FUNC(void, MATHSRV_CODE) MATHSRV_vidSchmittTriggerU16
   (uint16 u16InputValue,
   uint16 u16HysteresisLowThreshold,
   uint16 u16HysteresisHighTreshold,
   MATHSRV_tenuSchmittTriggerType tenuSchmittTriggerType,
   P2VAR(uint8, AUTOMATIC, MATHSRV_VAR)   u8OutputValue);


   #define MATHSRV_STOP_SEC_CODE
   #include "MemMap.h"


#endif

/*-------------------------------- end of file -------------------------------*/
