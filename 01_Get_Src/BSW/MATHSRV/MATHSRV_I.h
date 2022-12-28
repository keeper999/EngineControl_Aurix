/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_I.h                                             */
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
 * %PID: LIBEMB:MATHSRV I H-99055192X4420X338.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MATHSRV_I_H
#define MATHSRV_I_H

#include "Std_Types.h"

/******************************************************************************/
/* !FuncName    : MATHSRV_udtUX_DIV_UX_RND                                    */
/* !Description : Calculate the Rounded Off result of Dividing 2 udtNumbers   */
/*                where these Numbers are Unsigned. Rounded Result            */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
#define MATHSRV_udtUX_DIV_UX_RND(\
\
   udtNumerator,          /* !Comment : Numerator            */\
   udtDenominator           /* !Comment : Denomenator        */\
\
)\
(\
    ((((udtNumerator) % (udtDenominator)) > ((udtDenominator) / 2))\
     || ((((udtDenominator) % 2) == 0) &&\
        (((udtNumerator) % (udtDenominator)) == ((udtDenominator) / 2))))\
   ?\
      (((udtNumerator) / (udtDenominator)) + 1)\
     :\
     ((udtNumerator) / (udtDenominator))\
)

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

#define MATHSRV_START_SEC_CODE
#include "MemMap.h"

/* !Comment : General Math*/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Add_u32_u32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u32_div_u32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue, uint32 u32Denominator);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Add_s32_s32
                            (sint32 s32FirstValue,
                            sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Add_u32_s32
                            (uint32 u32FirstValue,
                            sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Add_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Add_u32_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Sub_u32_u32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue);

FUNC(uint32, MATHSRV_CODE)   MATHSRV_u32Sub_u32_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)   MATHSRV_u32Sub_s32_u32
                            (sint32 s32FirstValue,
                             uint32 u32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Sub_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_u32_u32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_u32_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_s32_u32
                            (sint32 s32FirstValue,
                             uint32 u32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_u32_u32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_u32_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_s32_u32
                            (sint32 s32FirstValue,
                             uint32 u32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Div_u32_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Div_s32_u32
                            (sint32 s32FirstValue,
                             uint32 u32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Div_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Div_s32_u32
                            (sint32 s32FirstValue,
                             uint32 u32SecondValue);

FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Div_s32_s16
                            (sint32 s32FirstValue,
                             sint16 s16SecondValue);

FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Div_s32_u16
                            (sint32 s32FirstValue,
                             uint16 u16SecondValue);

FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Div_u32_u16
                            (uint32 u32FirstValue,
                             uint16 u16SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_u32_u16
                            (uint32 u32FirstValue,
                             uint16 u16SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_u32_s32
                            (uint32 u32FirstValue,
                            sint32 s32SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u16
                            (uint32 u32FirstValue,
                             uint16 u16SecondValue);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_u16
                            (sint32 s32FirstValue,
                             uint16 u16SecondValue);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u32_div_s32
                            (uint32 u32FirstValue,
                             uint32 u32SecondValue,
                             sint32 s32Denominator);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_s32_div_u32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue,
                             uint32 u32Denominator);

FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_s32_div_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue,
                             sint32 s32Denominator);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_u32_s32_div_u32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue,
                             uint32 u32Denominator);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_u32_s32_div_s32
                            (uint32 u32FirstValue,
                             sint32 s32SecondValue,
                             sint32 s32Denominator);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_s32_div_u32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue,
                             uint32 u32Denominator);

FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_s32_div_s32
                            (sint32 s32FirstValue,
                             sint32 s32SecondValue,
                             sint32 s32Denominator);

FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_u16_u16_div_u16
                            (uint16 u16FirstValue,
                             uint16 u16SecondValue,
                             uint16 u16Denominator);

FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_u16_u16_div_u32
                            (uint16 u16FirstValue,
                             uint16 u16SecondValue,
                             uint32 u32Denominator);

FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_s16_u16_div_u16
                            (sint16 s16FirstValue,
                             uint16 u16SecondValue,
                             uint16 u16Denominator);

FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_s16_u16_div_s16
                            (sint16 s16FirstValue,
                             uint16 u16SecondValue,
                             sint16 s16Denominator);

FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_u16_s16_div_u16
                            (uint16 u16FirstValue,
                             sint16 s16SecondValue,
                             uint16 u16Denominator);

FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_s16_u16_div_s16
                            (sint16 s16FirstValue,
                             uint16 u16SecondValue,
                             sint16 s16Denominator);

FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_s16_s16_div_u16
                            (sint16 s16FirstValue,
                             sint16 s16SecondValue,
                             uint16 u16Denominator);

FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_s16_s16_div_s16
                            (sint16 s16FirstValue,
                             sint16 s16SecondValue,
                             sint16 s16Denominator);


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"




#endif   /* MATHSRV_I_H */


/*------------------------------ fin de fichier ------------------------------*/
