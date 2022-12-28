/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_MULDIV_32.c                                     */
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
 * %PID: LIBEMB:MATHSRV MULDIV 32 C-99055194X4420X358.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "MATHSRV.h"
#include "STD_Types.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"


STATIC FUNC(void, MATHSRV_CODE) MATHSRV_vidMul_u32_u32_Res_u64
(
   uint32 u32Factor1,
   uint32 u32Factor2,
   uint32 * pu32ResultLow32,
   uint32 * pu32ResultHigh32
);


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_u32_div_u32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C.Geamblu                                                   */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u32_div_u32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue,
   uint32 u32Denominator
)
{
   boolean      bLocalR3OverflowFlag;
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalResult;
   uint32_least u32LocalRemainder;


   if (u32Denominator != 0)
   {
      if (  (u32FirstValue != 0)
         && (u32SecondValue != 0) )
      {
         MATHSRV_vidMul_u32_u32_Res_u64(u32FirstValue, u32SecondValue,
                                        &u32LocalProductLow, &u32LocalProductHigh);
         if (u32LocalProductHigh < u32Denominator)
         {
            /*If the Multiplication will not make an Overflow*/
            if (u32LocalProductHigh == 0)
            {
               u32LocalResult    = (u32LocalProductLow / u32Denominator);
               u32LocalRemainder = (u32LocalProductLow % u32Denominator);
               if (  (u32LocalRemainder > (u32Denominator / 2) )
                  || (  ( (u32Denominator % 2) == 0)
                     && (u32LocalRemainder == (u32Denominator / 2) ) ) )
               {
                  u32LocalResult += 1;
               }
            }
            else
            {
               u32LocalResult       = 0;
               bLocalR3OverflowFlag = 0;
               u32LocalTemp2        = 2147483648UL;
               /*Check if the Last Bit in u32LocalProductHigh is 1*/
               if (u32LocalProductHigh >= 2147483648UL)
               {
                  bLocalR3OverflowFlag = 1;
               }
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by the
                  previous if check by setting the overflow flag */

               /*Check if the Last Bit in u32LocalProductLow is 1*/
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by the
                  previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 32; u8LocalLoopIndex++)
               {
                  if (bLocalR3OverflowFlag == 1)
                  {
                     u32LocalProductHigh += ( (UINT32_MAX - u32Denominator) + 1);
                     u32LocalTemp         = u32LocalTemp2;
                  }
                  else if (u32LocalProductHigh >= u32Denominator)
                  {
                     u32LocalProductHigh = u32LocalProductHigh - u32Denominator;
                     u32LocalTemp        = u32LocalTemp2;
                  }
                  else
                  {
                     u32LocalTemp = 0;
                  }
                  if (u32LocalProductHigh >= 2147483648UL)
                  {
                     bLocalR3OverflowFlag = 1;
                  }
                  else
                  {
                     bLocalR3OverflowFlag = 0;
                  }
                  u32LocalProductHigh = (u32LocalProductHigh * 2);
                  /*QAC Warning(3:3382): wraparound past zero is considered by
                     the previous if(u32LocalProductHigh >= 2147483648UL) check
                     by setting the overflow flag */
                  if (u32LocalProductLow >= 2147483648UL)
                  {
                     u32LocalProductHigh = u32LocalProductHigh + 1;
                  }
                  u32LocalProductLow = (u32LocalProductLow * 2);
                  /*QAC Warning(3:3382): wraparound past zero is considered by
                     the previous if(u32LocalProductLow >= 2147483648UL) check by
                     incrementing u32LocalProductHigh */

                  u32LocalResult += u32LocalTemp;
                  u32LocalTemp2   = u32LocalTemp2 / 2;
               }
               if (  (  (bLocalR3OverflowFlag == 1)
                     || (u32LocalProductHigh >= u32Denominator) )
                  && (u32LocalResult < UINT32_MAX) )
               {
                  u32LocalResult += 1;
               }
            }
         }
         else
         {
            u32LocalResult = UINT32_MAX;
         }
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      u32LocalResult = UINT32_MAX;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_u32_div_s32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C.Geamblu                                                   */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u32_div_s32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue,
   sint32 s32Denominator
)

{
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalResult;
   uint32_least u32LocalRemainder;


   if (s32Denominator != 0)
   {
      if (  (s32Denominator > 0)
         && (u32FirstValue != 0)
         && (u32SecondValue != 0) )
      {
         MATHSRV_vidMul_u32_u32_Res_u64(u32FirstValue, u32SecondValue,
                                        &u32LocalProductLow, &u32LocalProductHigh);
         if (u32LocalProductHigh < (uint32)s32Denominator)
         {
            if (u32LocalProductHigh == 0)
            {
               u32LocalResult    = (u32LocalProductLow / (uint32)s32Denominator);
               u32LocalRemainder =
                  (u32LocalProductLow % (uint32)s32Denominator);
               if (  (u32LocalRemainder > ( (uint32)s32Denominator / 2) )
                  || (  ( ( ( (uint32)s32Denominator) % 2) == 0)
                     && (u32LocalRemainder == ( ( (uint32)s32Denominator) / 2) ) ) )
               {
                  u32LocalResult += 1;
               }
            }
            else
            {
               u32LocalResult      = 0;
               u32LocalTemp2       = 2147483648UL;
               u32LocalProductHigh = u32LocalProductHigh % 2147483648UL;
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by the
                  previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 32; u8LocalLoopIndex++)
               {
                  if (u32LocalProductHigh >= (uint32)s32Denominator)
                  {
                     u32LocalProductHigh -= (uint32)s32Denominator;
                     u32LocalTemp         = u32LocalTemp2;
                  }
                  else
                  {
                     u32LocalTemp = 0;
                  }
                  u32LocalProductHigh = (u32LocalProductHigh * 2);
                  if (u32LocalProductLow >= 2147483648UL)
                  {
                     u32LocalProductHigh = u32LocalProductHigh + 1;
                  }
                  u32LocalProductLow = (u32LocalProductLow * 2);
                  /*QAC Warning(3:3382): wraparound past zero is considered by
                     the previous if(u32LocalProductLow >= 2147483648UL) check by
                     incrementing u32LocalProductHigh */
                  u32LocalResult += u32LocalTemp;
                  u32LocalTemp2   = u32LocalTemp2 / 2;
               }
               if (  (u32LocalProductHigh >= ( (uint32)s32Denominator) )
                  && (u32LocalResult < UINT32_MAX) )
               {
                  u32LocalResult += 1;
               }
            }
         }
         else
         {
            u32LocalResult = UINT32_MAX;
         }
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      u32LocalResult = UINT32_MAX;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_s32_div_u32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M. Mohi                                                     */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_s32_div_u32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue,
   uint32 u32Denominator
)

{
   boolean      bLocalR3OverflowFlag;
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalResult;


   if (u32Denominator != 0)
   {
      if (  (s32SecondValue > 0)
         && (u32FirstValue != 0) )
      {
         MATHSRV_vidMul_u32_u32_Res_u64(u32FirstValue, (uint32)s32SecondValue,
                                        &u32LocalProductLow, &u32LocalProductHigh);
         if (u32LocalProductHigh < u32Denominator)
         {
            if (u32LocalProductHigh == 0)
            {
               u32LocalResult = MATHSRV_udtUX_DIV_UX_RND(u32LocalProductLow,
                                                         u32Denominator);
            }
            else
            {
               u32LocalResult       = 0;
               bLocalR3OverflowFlag = 0;
               u32LocalTemp2        = 2147483648UL;
               u32LocalProductHigh  = (u32LocalProductHigh * 2);
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 32; u8LocalLoopIndex++)
               {
                  if (bLocalR3OverflowFlag == 1)
                  {
                     u32LocalProductHigh += ( (UINT32_MAX - u32Denominator) + 1);
                     u32LocalTemp         = u32LocalTemp2;
                  }
                  else if (u32LocalProductHigh >= u32Denominator)
                  {
                     u32LocalProductHigh = u32LocalProductHigh - u32Denominator;
                     u32LocalTemp        = u32LocalTemp2;
                  }
                  else
                  {
                     u32LocalTemp = 0;
                  }
                  if (u32LocalProductHigh >= 2147483648UL)
                  {
                     bLocalR3OverflowFlag = 1;
                  }
                  else
                  {
                     bLocalR3OverflowFlag = 0;
                  }
                  u32LocalProductHigh = (u32LocalProductHigh * 2);
                  /*QAC Warning(3:3382): wraparound past zero is considered by
                     the previous if(u32LocalProductHigh >= 2147483648UL) check
                     by setting the overflow flag */
                  if (u32LocalProductLow >= 2147483648UL)
                  {
                     u32LocalProductHigh = u32LocalProductHigh + 1;
                  }
                  u32LocalProductLow = (u32LocalProductLow * 2);
                  /*QAC Warning(3:3382): wraparound past zero is considered by
                     the previous if(u32LocalProductLow >= 2147483648UL) check by
                     incrementing u32LocalProductHigh */
                  u32LocalResult += u32LocalTemp;
                  u32LocalTemp2   = u32LocalTemp2 / 2;
               }
               if (  (bLocalR3OverflowFlag == 1)
                  || (u32LocalProductHigh >= u32Denominator) )
               {
                  u32LocalProductHigh = (u32LocalProductHigh / 2);
                  if (  (bLocalR3OverflowFlag == 1)
                     || ( (u32LocalProductHigh) >= (u32Denominator / 2) ) )
                  {
                     u32LocalResult += 1;
                  }
               }
            }
         }
         else
         {
            u32LocalResult = UINT32_MAX;
         }
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      if (  (s32SecondValue >= 0)
         || (u32FirstValue == 0) )
      {
         u32LocalResult = UINT32_MAX;
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_s32_div_s32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M. Mohi                                                     */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_s32_div_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue,
   sint32 s32Denominator
)

{
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalFactor2;
   uint32_least u32LocalDenominator;
   uint32_least u32LocalResult;


   if (s32Denominator != 0)
   {
      if (  (  (  (s32SecondValue > 0)
               && (s32Denominator > 0) )
            || (  (s32SecondValue < 0)
               && (s32Denominator < 0) ) )
         && (u32FirstValue != 0) )
      {
         u32LocalFactor2     = (uint32)MATHSRV_udtABS(s32SecondValue);
         u32LocalDenominator = (uint32)MATHSRV_udtABS(s32Denominator);
         MATHSRV_vidMul_u32_u32_Res_u64(u32FirstValue, u32LocalFactor2,
                                        &u32LocalProductLow, &u32LocalProductHigh);
         if (u32LocalProductHigh < u32LocalDenominator)
         {
            if (u32LocalProductHigh == 0)
            {
               u32LocalResult = MATHSRV_udtUX_DIV_UX_RND(u32LocalProductLow,
                                                         u32LocalDenominator);
               /*QAC Warning 0584:Accepted,Code revised
                * to avoid Division by Zero*/
            }
            else
            {
               u32LocalResult      = 0;
               u32LocalTemp2       = 2147483648UL;
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 32; u8LocalLoopIndex++)
               {
                  if (u32LocalProductHigh >= u32LocalDenominator)
                  {
                     u32LocalProductHigh -= u32LocalDenominator;
                     u32LocalTemp         = u32LocalTemp2;
                  }
                  else
                  {
                     u32LocalTemp = 0;
                  }
                  u32LocalProductHigh = (u32LocalProductHigh * 2);
                  if (u32LocalProductLow >= 2147483648UL)
                  {
                     u32LocalProductHigh = u32LocalProductHigh + 1;
                  }
                  u32LocalProductLow = (u32LocalProductLow * 2);
                  /*QAC Warning(3:3382): wraparound past zero is considered by
                     the previous if(u32LocalProductLow >= 2147483648UL) check by
                     incrementing u32LocalProductHigh */
                  u32LocalResult += u32LocalTemp;
                  u32LocalTemp2   = u32LocalTemp2 / 2;
               }
               if ( (u32LocalProductHigh) >= u32LocalDenominator)
               {
                  u32LocalResult += 1;
               }
            }
         }
         else
         {
            u32LocalResult = UINT32_MAX;
         }
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      if (  (s32SecondValue >= 0)
         || (u32FirstValue == 0) )
      {
         u32LocalResult = UINT32_MAX;
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_s32_s32_div_s32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C. Geamblu                                                  */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_s32_div_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue,
   sint32 s32Denominator
)

{
   boolean      bLocalPositiveResult;
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalFactor1;
   uint32_least u32LocalFactor2;
   uint32_least u32LocalDenominator;
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   if (s32Denominator != 0)
   {
      u32LocalFactor1     = (uint32)MATHSRV_udtABS(s32FirstValue);
      u32LocalFactor2     = (uint32)MATHSRV_udtABS(s32SecondValue);
      u32LocalDenominator = (uint32)MATHSRV_udtABS(s32Denominator);
      MATHSRV_vidMul_u32_u32_Res_u64(u32LocalFactor1, u32LocalFactor2,
                                     &u32LocalProductLow, &u32LocalProductHigh);

      if (  (  (  (  (s32FirstValue > 0)
                  && (s32SecondValue > 0) )
               || (  (s32FirstValue < 0)
                  && (s32SecondValue < 0) ) )
            && (s32Denominator > 0) )
         || (  (  (  (s32FirstValue > 0)
                  && (s32SecondValue < 0) )
               || (  (s32FirstValue < 0)
                  && (s32SecondValue > 0) ) )
            && (s32Denominator < 0) ) )
      {
         bLocalPositiveResult = TRUE;
      }
      else
      {
         bLocalPositiveResult = FALSE;
      }
      /*u32LocalProductHigh is Adjusted by Shifting the Highest Bit in
       * u32LocalProductLow and to check that the Calculation at the End
       * Doesn't make an overflow in the S32 */
      u32LocalProductHigh = (u32LocalProductHigh * 2);
      /*Check if the Last Bit in u32LocalProductLow is 1*/
      if (u32LocalProductLow >= 2147483648UL)
      {
         u32LocalProductHigh = u32LocalProductHigh + 1;
      }
      /*Check for Overflow*/
      if (u32LocalProductHigh < u32LocalDenominator)
      {
         /*If the Multiplication will not Make an overflow
          * => Perform the Calculation Directly */
         if (u32LocalProductHigh <= 1)
         {
            u32LocalResult = MATHSRV_udtUX_DIV_UX_RND(u32LocalProductLow,
                                                      u32LocalDenominator);
            /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/

         }
         else
         {
            u32LocalResult     = 0;
            u32LocalTemp2      = 1073741824UL;
            u32LocalProductLow = u32LocalProductLow * 2;
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            u32LocalProductHigh = u32LocalProductHigh * 2;

            /*Check if the Last Bit in u32LocalProductLow is 1*/
            if (u32LocalProductLow >= 2147483648UL)
            {
               u32LocalProductHigh = u32LocalProductHigh + 1;
            }
            u32LocalProductLow = (u32LocalProductLow * 2);
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 31; u8LocalLoopIndex++)
            {
               if (u32LocalProductHigh >= u32LocalDenominator)
               {
                  u32LocalProductHigh -= u32LocalDenominator;
                  u32LocalTemp         = u32LocalTemp2;
               }
               else
               {
                  u32LocalTemp = 0;
               }
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               u32LocalResult += u32LocalTemp;
               u32LocalTemp2   = u32LocalTemp2 / 2;
            }
            if (u32LocalProductHigh >= u32LocalDenominator)
            {
               u32LocalResult += 1;
            }
         }
         /*If Positive*/
         if (bLocalPositiveResult == TRUE)
         {
            s32LocalResult = (sint32)MATHSRV_udtMIN(u32LocalResult,
                                                    (uint32)SINT32_MAX);
            /* QAC Warning(2:1258): Due to Explicit cast of SINT32_MAX */
         }
         else
         {
            if (u32LocalResult < ( ( (uint32)SINT32_MAX) + 1) )
            {
               /* QAC waring(1258): Due to Explicit cast of SINT32_MAX */
               s32LocalResult = -( (sint32)u32LocalResult);
            }
            else
            {
               s32LocalResult = SINT32_MIN;
            }
         }
      }
      else
      {
         /*If Positive*/
         if (bLocalPositiveResult == TRUE)
         {
            s32LocalResult = SINT32_MAX;
         }
         else
         {
            s32LocalResult = SINT32_MIN;
         }
      }
   }
   else
   {
      /*If Positive*/
      if (  (  (s32FirstValue >= 0)
            && (s32SecondValue >= 0) )
         || (  (s32FirstValue <= 0)
            && (s32SecondValue <= 0) ) )
      {
         s32LocalResult = SINT32_MAX;
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }

   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_s32_s32_div_u32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C. Geamblu                                                  */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_s32_div_u32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue,
   uint32 u32Denominator
)

{
   boolean      bLocalPositiveResult;
   boolean      bLocalR3OverflowFlag;
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalFactor1;
   uint32_least u32LocalFactor2;
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   if (  (  (s32FirstValue >= 0)
         && (s32SecondValue >= 0) )
      || (  (s32FirstValue <= 0)
         && (s32SecondValue <= 0) ) )
   {
      bLocalPositiveResult = TRUE;
   }
   else
   {
      bLocalPositiveResult = FALSE;
   }
   if (u32Denominator != 0)
   {
      u32LocalFactor1 = (uint32)MATHSRV_udtABS(s32FirstValue);
      u32LocalFactor2 = (uint32)MATHSRV_udtABS(s32SecondValue);
      MATHSRV_vidMul_u32_u32_Res_u64(u32LocalFactor1, u32LocalFactor2,
                                     &u32LocalProductLow, &u32LocalProductHigh);

      /*u32LocalProductHigh is Adjusted by Shifting the Highest Bit in
       *  u32LocalProductLow and to check that the Calculation at the End
       *  Doesn't make an overflow in the S32 */
      u32LocalProductHigh = (u32LocalProductHigh * 2);
      if (u32LocalProductLow >= 2147483648UL)
      {
         u32LocalProductHigh = u32LocalProductHigh + 1;
      }
      /*Check for Overflow*/
      if (u32LocalProductHigh < u32Denominator)
      {
         /*If the Multiplication will not Make an overflow
          * => Perform the Calculation Directly */
         if (u32LocalProductHigh <= 1)
         {
            u32LocalResult = MATHSRV_udtUX_DIV_UX_RND(u32LocalProductLow,
                                                      u32Denominator);
         }
         else
         {
            u32LocalResult = 0;
            /*Flag to Detect that the Highest Bit in ..
             * ..u32LocalProductHigh is '1' Before Shifting */
            bLocalR3OverflowFlag = 0;
            u32LocalTemp2        = 1073741824UL;
            u32LocalProductLow   = u32LocalProductLow * 2;
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            if (u32LocalProductHigh >= 2147483648UL)
            {
               bLocalR3OverflowFlag = 1;
            }
            u32LocalProductHigh = u32LocalProductHigh * 2;

            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductHigh >= 2147483648UL) check
               by setting the overflow flag */

            /*Check if the Last Bit in u32LocalProductLow is 1*/
            if (u32LocalProductLow >= 2147483648UL)
            {
               u32LocalProductHigh = u32LocalProductHigh + 1;
            }
            u32LocalProductLow = (u32LocalProductLow * 2);
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 31; u8LocalLoopIndex++)
            {
               if (bLocalR3OverflowFlag == 1)
               {
                  u32LocalProductHigh += ( (UINT32_MAX - u32Denominator) + 1);
                  u32LocalTemp         = u32LocalTemp2;
               }
               else if (u32LocalProductHigh >= u32Denominator)
               {
                  u32LocalProductHigh = u32LocalProductHigh - u32Denominator;
                  u32LocalTemp        = u32LocalTemp2;
               }
               else
               {
                  u32LocalTemp = 0;
               }
               /*Check if the Last Bit in u32LocalProductHigh is 1*/
               if (u32LocalProductHigh >= 2147483648UL)
               {
                  bLocalR3OverflowFlag = 1;
               }
               else
               {
                  bLocalR3OverflowFlag = 0;
               }
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductHigh >= 2147483648UL) check
                  by setting the overflow flag */

               /*Check if the Last Bit in u32LocalProductLow is 1*/
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               u32LocalResult += u32LocalTemp;
               u32LocalTemp2   = u32LocalTemp2 / 2;
            }
            if (  (  (bLocalR3OverflowFlag == 1)
                  || (u32LocalProductHigh >= u32Denominator) )
               && (u32LocalResult < UINT32_MAX) )
            {
               u32LocalResult += 1;
            }
         }
         if (bLocalPositiveResult == TRUE)
         {
            s32LocalResult = (sint32)MATHSRV_udtMIN(u32LocalResult,
                                                    (uint32)SINT32_MAX);
            /* QAC Warning(2:1258): Due to Explicit cast of SINT32_MAX */
         }
         else
         {
            if (u32LocalResult < ( ( (uint32)SINT32_MAX) + 1) )
            {
               /* QAC waring(1258): Due to Explicit cast of SINT32_MAX */
               s32LocalResult = -( (sint32)u32LocalResult);
            }
            else
            {
               s32LocalResult = SINT32_MIN;
            }
         }
      }
      else
      {
         if (bLocalPositiveResult == TRUE)
         {
            s32LocalResult = SINT32_MAX;
         }
         else
         {
            s32LocalResult = SINT32_MIN;
         }
      }
   }
   else
   {
      if (bLocalPositiveResult == TRUE)
      {

         s32LocalResult = SINT32_MAX;
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_u32_s32_div_s32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M. Mohi                                                     */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_u32_s32_div_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue,
   sint32 s32Denominator
)

{
   boolean      bLocalPositiveResult;
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalFactor2;
   uint32_least u32LocalDenominator;
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   if (s32Denominator != 0)
   {
      u32LocalFactor2     = (uint32)MATHSRV_udtABS(s32SecondValue);
      u32LocalDenominator = (uint32)MATHSRV_udtABS(s32Denominator);
      MATHSRV_vidMul_u32_u32_Res_u64(u32FirstValue, u32LocalFactor2,
                                     &u32LocalProductLow, &u32LocalProductHigh);

      if (  (  (s32SecondValue > 0)
            && (s32Denominator > 0) )
         || (  (s32SecondValue < 0)
            && (s32Denominator < 0) ) )
      {
         bLocalPositiveResult = TRUE;
      }
      else
      {
         bLocalPositiveResult = FALSE;
      }
      /* u32LocalProductHigh is Adjusted by Shifting the Highest Bit in
       * u32LocalProductLow and to check that
       * the Calculation at the End Doesn't make an overflow in the S32 */
      u32LocalProductHigh = (u32LocalProductHigh * 2);
      if (u32LocalProductLow >= 2147483648UL)
      {
         u32LocalProductHigh = u32LocalProductHigh + 1;
      }
      /*Check for Overflow*/
      if (u32LocalProductHigh < u32LocalDenominator)
      {
         /*If the Multiplication will not Make an overflow
          * => Perform the Calculation Directly */
         if (u32LocalProductHigh <= 1)
         {
            u32LocalResult = MATHSRV_udtUX_DIV_UX_RND(u32LocalProductLow,
                                                      u32LocalDenominator);
            /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         }
         else
         {
            u32LocalResult     = 0;
            u32LocalTemp2      = 1073741824UL;
            u32LocalProductLow = u32LocalProductLow * 2;
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            u32LocalProductHigh = u32LocalProductHigh * 2;

            if (u32LocalProductLow >= 2147483648UL)
            {
               u32LocalProductHigh = u32LocalProductHigh + 1;
            }
            u32LocalProductLow = (u32LocalProductLow * 2);
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 31; u8LocalLoopIndex++)
            {
               if (u32LocalProductHigh >= u32LocalDenominator)
               {
                  u32LocalProductHigh -= u32LocalDenominator;
                  u32LocalTemp         = u32LocalTemp2;
               }
               else
               {
                  u32LocalTemp = 0;
               }
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               u32LocalResult += u32LocalTemp;
               u32LocalTemp2   = u32LocalTemp2 / 2;
            }
            if (u32LocalProductHigh >= u32LocalDenominator)
            {
               u32LocalResult += 1;
            }
         }
         if (bLocalPositiveResult == TRUE)
         {
            s32LocalResult = (sint32)MATHSRV_udtMIN(u32LocalResult,
                                                    (uint32)SINT32_MAX);
            /* QAC waring(1258): Due to Explicit cast of SINT32_MAX */
         }
         else
         {
            s32LocalResult = -( (sint32)u32LocalResult);
         }
      }
      else
      {
         if (bLocalPositiveResult == TRUE)
         {
            s32LocalResult = SINT32_MAX;
         }
         else
         {
            s32LocalResult = SINT32_MIN;
         }
      }
   }
   else
   {
      /*If Positive*/
      if (  (s32SecondValue >= 0)
         || (u32FirstValue == 0) )
      {
         s32LocalResult = SINT32_MAX;
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_u32_s32_div_u32                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C.Geamblu                                                   */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_u32_s32_div_u32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue,
   uint32 u32Denominator
)

{
   boolean      bLocalR3OverflowFlag;
   uint8_least  u8LocalLoopIndex;
   uint32_least u32LocalProductLow;
   uint32_least u32LocalProductHigh;
   uint32_least u32LocalTemp;
   uint32_least u32LocalTemp2;
   uint32_least u32LocalFactor2;
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   if (u32Denominator != 0)
   {
      u32LocalFactor2 = (uint32)MATHSRV_udtABS(s32SecondValue);
      MATHSRV_vidMul_u32_u32_Res_u64(u32FirstValue, u32LocalFactor2,
                                     &u32LocalProductLow, &u32LocalProductHigh);

      /*u32LocalProductHigh is Adjusted by Shifting the Highest Bit in
       * u32LocalProductLow and to check that the Calculation at the End
       *  Doesn't make an overflow in the S32 */
      u32LocalProductHigh = (u32LocalProductHigh * 2);
      if (u32LocalProductLow >= 2147483648UL)
      {
         u32LocalProductHigh = u32LocalProductHigh + 1;
      }
      /*Check for Overflow*/
      if (u32LocalProductHigh < u32Denominator)
      {
         /*If the Multiplication will not Make an overflow
          * => Perform the Calculation Directly */
         if (u32LocalProductHigh <= 1)
         {
            u32LocalResult = MATHSRV_udtUX_DIV_UX_RND(u32LocalProductLow,
                                                      u32Denominator);
         }
         else
         {
            u32LocalResult = 0;
            /*Flag to Detect that the Highest Bit in u32LocalProductHigh
             * ..is '1' Before Shifting */
            bLocalR3OverflowFlag = 0;
            u32LocalTemp2        = 1073741824UL;
            u32LocalProductLow   = u32LocalProductLow * 2;
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            if (u32LocalProductHigh >= 2147483648UL)
            {
               bLocalR3OverflowFlag = 1;
            }
            u32LocalProductHigh = u32LocalProductHigh * 2;

            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductHigh >= 2147483648UL) check
               by setting the overflow flag */
            if (u32LocalProductLow >= 2147483648UL)
            {
               u32LocalProductHigh = u32LocalProductHigh + 1;
            }
            u32LocalProductLow = (u32LocalProductLow * 2);
            /*QAC Warning(3:3382): wraparound past zero is considered by
               the previous if(u32LocalProductLow >= 2147483648UL) check by
               incrementing u32LocalProductHigh */
            for (u8LocalLoopIndex = 0; u8LocalLoopIndex < 31; u8LocalLoopIndex++)
            {
               if (bLocalR3OverflowFlag == 1)
               {
                  u32LocalProductHigh += ( (UINT32_MAX - u32Denominator) + 1);
                  u32LocalTemp         = u32LocalTemp2;
               }
               else if (u32LocalProductHigh >= u32Denominator)
               {
                  u32LocalProductHigh = u32LocalProductHigh - u32Denominator;
                  u32LocalTemp        = u32LocalTemp2;
               }
               else
               {
                  u32LocalTemp = 0;
               }
               if (u32LocalProductHigh >= 2147483648UL)
               {
                  bLocalR3OverflowFlag = 1;
               }
               else
               {
                  bLocalR3OverflowFlag = 0;
               }
               u32LocalProductHigh = (u32LocalProductHigh * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductHigh >= 2147483648UL) check
                  by setting the overflow flag */

               if (u32LocalProductLow >= 2147483648UL)
               {
                  u32LocalProductHigh = u32LocalProductHigh + 1;
               }
               u32LocalProductLow = (u32LocalProductLow * 2);
               /*QAC Warning(3:3382): wraparound past zero is considered by
                  the previous if(u32LocalProductLow >= 2147483648UL) check by
                  incrementing u32LocalProductHigh */
               u32LocalResult += u32LocalTemp;
               u32LocalTemp2   = u32LocalTemp2 / 2;
            }
            if (  (  (bLocalR3OverflowFlag == 1)
                  || (u32LocalProductHigh >= u32Denominator) )
               && (u32LocalResult < UINT32_MAX) )
            {
               u32LocalResult += 1;
            }
         }
         /*If Positive*/
         if (s32SecondValue >= 0)
         {
            s32LocalResult = (sint32)MATHSRV_udtMIN(u32LocalResult,
                                                    (uint32)SINT32_MAX);
            /* QAC waring(1258): Due to Explicit cast of SINT32_MAX */
         }
         else
         {
            if (u32LocalResult < ( ( (uint32)SINT32_MAX) + 1) )
            {
               /* QAC waring(1258): Due to Explicit cast of SINT32_MAX */
               s32LocalResult = -( (sint32)u32LocalResult);
            }
            else
            {
               s32LocalResult = SINT32_MIN;
            }
         }
      }
      else
      {
         /*If Positive*/
         if (s32SecondValue >= 0)
         {
            s32LocalResult = SINT32_MAX;
         }
         else
         {
            s32LocalResult = SINT32_MIN;
         }
      }
   }
   else
   {
      /*If Positive*/
      if (  (s32SecondValue >= 0)
         || (u32FirstValue == 0) )
      {
         s32LocalResult = SINT32_MAX;
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   return(s32LocalResult);
}
/*QAC Warning 4700, Accepted Complexity*/


/******************************************************************************/
/* !FuncName    : MATHSRV_vidMul_u32_u32_Res_u64                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
STATIC FUNC(void,
            MATHSRV_CODE) MATHSRV_vidMul_u32_u32_Res_u64
(
   uint32 u32Factor1,        /* !Comment : Input Parameter                    */
                             /* !Range   : 0....4294967295                       */
   uint32 u32Factor2,        /* !Comment : Input Parameter                    */
                             /* !Range   : 0....4294967295                       */
   uint32 * pu32ResultLow32, /* !Comment : Output Parameter                   */
                             /* !Range   : 0....4294967295                       */
   uint32 * pu32ResultHigh32 /* !Comment : Output Parameter                   */
                             /* !Range   : 0....4294967295                       */
)

{
   uint32_least u32LocalR1;
   uint32_least u32LocalR3;
   uint32_least u32LocalR21;
   uint32_least u32LocalR22;
   uint32_least u32LocalXL;
   uint32_least u32LocalXM;
   uint32_least u32LocalYL;
   uint32_least u32LocalYM;
   uint32_least u32LocalTemp;


   u32LocalXL  = (u32Factor1 % 65536);
   u32LocalXM  = (u32Factor1 / 65536);
   u32LocalYL  = (u32Factor2 % 65536);
   u32LocalYM  = (u32Factor2 / 65536);
   u32LocalR1  = (u32LocalXL * u32LocalYL);
   u32LocalR21 = (u32LocalXL * u32LocalYM);
   u32LocalR22 = (u32LocalXM * u32LocalYL);
   u32LocalR3  = (u32LocalXM * u32LocalYM);
   /* Putting the Result in 2 U32 */
   u32LocalTemp     = (u32LocalR1 / 65536);
   u32LocalTemp    += (u32LocalR21 % 65536);
   u32LocalTemp    += (u32LocalR22 % 65536);
   *pu32ResultLow32 = (u32LocalR1 % 65536) + (u32LocalTemp * 65536);

   u32LocalTemp      = (u32LocalTemp / 65536);
   u32LocalTemp     += (u32LocalR21 / 65536);
   u32LocalTemp     += (u32LocalR22 / 65536);
   *pu32ResultHigh32 = u32LocalR3 + u32LocalTemp;
}

#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/***************************** End of File ***********************************/
