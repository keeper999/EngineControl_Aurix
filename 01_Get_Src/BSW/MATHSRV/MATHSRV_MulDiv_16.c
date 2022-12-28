/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_MULDIV_16.c                                     */
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
 * %PID: LIBEMB:MATHSRV MULDIV 16 C-99055194X4420X354.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "MATHSRV.h"
#include "STD_Types.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Mul_u16_u16_div_u16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_u16_u16_div_u16
(
   uint16 u16FirstValue,
   uint16 u16SecondValue,
   uint16 u16Denominator
)

{
   uint32_least u32LocalResult;
   uint16_least u16LocalResult;
   uint32_least u32LocalProduct;


   if (u16Denominator != 0)
   {
      u32LocalProduct = ( (uint32)u16FirstValue * u16SecondValue);
      u32LocalResult  = (u32LocalProduct / u16Denominator);
      if ( ( (u32LocalProduct % u16Denominator) * 2) >= u16Denominator)
      {
         u32LocalResult += 1;
      }
      u16LocalResult = MATHSRV_udtMIN(u32LocalResult, (uint32)UINT16_MAX);
      /* QAC Warning 1258 is due to the Explicit Casting for UINT16_MAX */
   }
   else
   {
      u16LocalResult = UINT16_MAX;
      /* QAC Warning 1256 is due to the Explicit Casting for UINT16_MAX */
   }
   return( (uint16)u16LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s16Mul_s16_u16_div_s16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_s16_u16_div_s16
(
   sint16 s16FirstValue,
   uint16 u16SecondValue,
   sint16 s16Denominator
)

{
   sint32_least s32LocalResult;
   sint16_least s16LocalResult;
   sint32_least s32LocalProduct;
   uint32_least u32LocalProAbsVal;
   uint32_least u32LocalDenAbsVal;


   if (s16Denominator != 0)
   {
      s32LocalProduct   = ( (sint32)s16FirstValue * u16SecondValue);
      s32LocalResult    = (s32LocalProduct / (s16Denominator) );
      u32LocalProAbsVal = (uint32)MATHSRV_udtABS(s32LocalProduct);
      u32LocalDenAbsVal = (uint32)MATHSRV_udtABS(s16Denominator);
      if ( ( (u32LocalProAbsVal % u32LocalDenAbsVal) * 2) >= u32LocalDenAbsVal)
      {
         /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         if (  (  (s16FirstValue > 0)
               && (s16Denominator > 0) )
            || (  (s16FirstValue < 0)
               && (s16Denominator < 0) ) )
         {
            s32LocalResult += 1;
         }
         else
         {
            s32LocalResult -= 1;
         }
      }
      s16LocalResult = MATHSRV_udtCLAMP(s32LocalResult, SINT16_MIN, SINT16_MAX);
   }
   else
   {
      if (  (s16FirstValue >= 0)
         || (u16SecondValue == 0) )
      {
         s16LocalResult = SINT16_MAX;
      }
      else
      {
         s16LocalResult = SINT16_MIN;
      }
   }
   return( (sint16)s16LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s16Mul_u16_s16_div_u16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_u16_s16_div_u16
(
   uint16 u16FirstValue,
   sint16 s16SecondValue,
   uint16 u16Denominator
)

{
   sint32_least s32LocalResult;
   sint16_least s16LocalResult;
   sint32_least s32LocalProduct;
   uint32_least u32LocalProAbsVal;


   if (u16Denominator != 0)
   {
      s32LocalProduct   = (u16FirstValue * (sint32)s16SecondValue);
      s32LocalResult    = (s32LocalProduct / u16Denominator);
      u32LocalProAbsVal = (uint32)MATHSRV_udtABS(s32LocalProduct);
      if ( ( (u32LocalProAbsVal % u16Denominator) * 2) >= u16Denominator)
      {
         if (s16SecondValue > 0)
         {
            s32LocalResult += 1;
         }
         else
         {
            s32LocalResult -= 1;
         }
      }
      s16LocalResult = MATHSRV_udtCLAMP(s32LocalResult, SINT16_MIN, SINT16_MAX);
   }
   else
   {
      if (  (s16SecondValue >= 0)
         || (u16FirstValue == 0) )
      {
         s16LocalResult = SINT16_MAX;
      }
      else
      {
         s16LocalResult = SINT16_MIN;
      }
   }
   return( (sint16)s16LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Mul_s16_u16_div_s16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_s16_u16_div_s16
(
   sint16 s16FirstValue,
   uint16 u16SecondValue,
   sint16 s16Denominator
)

{
   sint32_least s32LocalResult;
   uint16_least u16LocalResult;
   sint32_least s32LocalProduct;
   uint32_least u32LocalProAbsVal;
   uint16_least u16LocalDenAbsVal;


   if (  (s16Denominator > 0)
      || (s16Denominator < 0) )
   {
      s32LocalProduct   = ( (sint32)s16FirstValue * u16SecondValue);
      s32LocalResult    = (s32LocalProduct / s16Denominator);
      u32LocalProAbsVal = (uint32)MATHSRV_udtABS(s32LocalProduct);
      u16LocalDenAbsVal = (uint16)MATHSRV_udtABS(s16Denominator);
      /*QAC (3892): No problem because ABS(sint16 type) can fit in uint16 */
      if ( ( (u32LocalProAbsVal % u16LocalDenAbsVal) * 2) >= u16LocalDenAbsVal)
      {
         if (  (  (s16FirstValue > 0)
               && (s16Denominator > 0) )
            || (  (s16FirstValue < 0)
               && (s16Denominator < 0) ) )
         {
            s32LocalResult += 1;
         }
         else
         {
            s32LocalResult -= 1;
         }
      }
      u16LocalResult = (uint16)MATHSRV_udtCLAMP(s32LocalResult,
                                                (sint32)(UINT16_MIN), (sint32)(UINT16_MAX) );
      /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/
      /* QAC Warning 1258 is due to the Explicit Casting for UINT16_MAX */
   }
   else
   {
      if (  (s16FirstValue >= 0)
         || (u16SecondValue == 0) )
      {
         u16LocalResult = UINT16_MAX;
         /* QAC (1256): No problem because UINT16_MAX can fit in uint16 */
      }
      else
      {
         u16LocalResult = UINT16_MIN;
      }
   }
   return( (uint16)u16LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Mul_s16_u16_div_u16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Mul_s16_u16_div_u16
(
   sint16 s16FirstValue,
   uint16 u16SecondValue,
   uint16 u16Denominator
)

{
   sint32_least s32LocalResult;
   uint16_least u16LocalResult;
   sint32_least s32LocalProduct;
   uint32_least u32LocalProAbsVal;


   if (u16Denominator != 0)
   {
      s32LocalProduct   = ( (sint32)s16FirstValue * u16SecondValue);
      s32LocalResult    = (s32LocalProduct / u16Denominator);
      u32LocalProAbsVal = (uint32)MATHSRV_udtABS(s32LocalProduct);
      if ( ( (u32LocalProAbsVal % u16Denominator) * 2) >= u16Denominator)
      {
         if (s16FirstValue > 0)
         {
            s32LocalResult += 1;
         }
         else
         {
            s32LocalResult -= 1;
         }
      }
      u16LocalResult = (uint16)MATHSRV_udtCLAMP(s32LocalResult,
                                                (sint32)UINT16_MIN, (sint32)UINT16_MAX);
      /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/
      /* QAC Warning 1258 is due to the Explicit Casting for UINT16_MAX */
   }
   else
   {
      if (  (s16FirstValue >= 0)
         || (u16SecondValue == 0) )
      {
         u16LocalResult = UINT16_MAX;
         /* QAC Warning 1256 is due to the Explicit Casting for UINT16_MAX */
      }
      else
      {
         u16LocalResult = UINT16_MIN;
      }
   }
   return( (uint16)u16LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s16Mul_s16_s16_div_u16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C.Geamblu                                                   */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_s16_s16_div_u16
(
   sint16 s16FirstValue,
   sint16 s16SecondValue,
   uint16 u16Denominator
)

{
   boolean      bLocalPositiveProduct;
   sint16_least s16LocalResult;
   uint16_least u16LocalAbsFirstVal;
   uint16_least u16LocalAbsSecondVal;
   uint32_least u32LocalProduct;
   uint32_least u32LocalResult;


   if (  (  (s16FirstValue >= 0)
         && (s16SecondValue >= 0) )
      || (  (s16FirstValue <= 0)
         && (s16SecondValue <= 0) ) )
   {
      bLocalPositiveProduct = TRUE;
   }
   else
   {
      bLocalPositiveProduct = FALSE;
   }

   if (u16Denominator != 0)
   {
      u16LocalAbsFirstVal  = (uint16)MATHSRV_udtABS(s16FirstValue);
      u16LocalAbsSecondVal = (uint16)MATHSRV_udtABS(s16SecondValue);
      /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/

      u32LocalProduct = (u16LocalAbsFirstVal) * (u16LocalAbsSecondVal);
      u32LocalResult  = (u32LocalProduct) / (u16Denominator);

      /* !Comment: Rounds to upper integer */
      if ( ( (u32LocalProduct % u16Denominator) * 2) >= u16Denominator)
      {
         u32LocalResult += 1;
      }

      /* !Comment: Inserts the sign to integer */
      if (bLocalPositiveProduct == TRUE)
      {
         s16LocalResult = (sint16)MATHSRV_udtMIN(u32LocalResult,
                                                 (uint32)SINT16_MAX);
         /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/
      }
      else
      {
         s16LocalResult = (sint16)MATHSRV_udtMAX(-( (sint32)u32LocalResult),
                                                 (sint32)SINT16_MIN);
         /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/
      }
   }
   else
   {
      if (bLocalPositiveProduct == TRUE)
      {
         s16LocalResult = SINT16_MAX;
      }
      else
      {
         s16LocalResult = SINT16_MIN;
      }
   }
   return( (sint16)s16LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s16Mul_s16_s16_div_s16                              */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX047                                                      */
/* !Trace_To    : MFX048                                                      */
/* !Trace_To    : MFX049                                                      */
/* !Trace_To    : MFX051                                                      */
/*                                                                            */
/* !LastAuthor  : C.Geamblu                                                   */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Mul_s16_s16_div_s16
(
   sint16 s16FirstValue,
   sint16 s16SecondValue,
   sint16 s16Denominator
)

{
   boolean      bLocalPositiveProduct;
   boolean      bLocalPositiveResult;
   uint16_least u16LocalAbsFirstVal;
   uint16_least u16LocalAbsSecondVal;
   uint16_least u16LocalAbsDenom;
   uint32_least u32LocalProduct;
   uint32_least u32LocalResult;
   sint16_least s16LocalResult;


   if (  (  (s16FirstValue >= 0)
         && (s16SecondValue >= 0) )
      || (  (s16FirstValue <= 0)
         && (s16SecondValue <= 0) ) )
   {
      bLocalPositiveProduct = TRUE;
   }
   else
   {
      bLocalPositiveProduct = FALSE;
   }

   if (  (s16Denominator > 0)
      || (s16Denominator < 0) )
   {
      if (  (  (bLocalPositiveProduct == TRUE)
            && (s16Denominator > 0) )
         || (  (bLocalPositiveProduct == FALSE)
            && (s16Denominator < 0) ) )
      {
         bLocalPositiveResult = TRUE;
      }
      else
      {
         bLocalPositiveResult = FALSE;
      }

      u16LocalAbsFirstVal  = (uint16)MATHSRV_udtABS(s16FirstValue);
      u16LocalAbsSecondVal = (uint16)MATHSRV_udtABS(s16SecondValue);
      u16LocalAbsDenom     = (uint16)MATHSRV_udtABS(s16Denominator);
      /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/

      u32LocalProduct = (u16LocalAbsFirstVal * u16LocalAbsSecondVal);
      u32LocalResult  = (u32LocalProduct) / (u16LocalAbsDenom);

      /* !Comment: Rounds to upper integer */
      if ( ( (u32LocalProduct % u16LocalAbsDenom) * 2) >= u16LocalAbsDenom)
      {
         u32LocalResult += 1;
      }

      /* !Comment: Inserts the sign to integer */
      if (bLocalPositiveResult == TRUE)
      {
         s16LocalResult = (sint16)MATHSRV_udtMIN(u32LocalResult,
                                                 (uint32)SINT16_MAX);
         /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/
      }
      else
      {
         s16LocalResult = (sint16)MATHSRV_udtMAX(-( (sint32)u32LocalResult),
                                                 (sint32)SINT16_MIN);
         /*QAC Warning 3892:Implicit Casting Accepted,to Cast with Original Type*/
      }
   }
   else
   {
      if (bLocalPositiveProduct == TRUE)
      {
         s16LocalResult = SINT16_MAX;
      }
      else
      {
         s16LocalResult = SINT16_MIN;
      }
   }
   return( (sint16)s16LocalResult);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/********************************** End of File ******************************/
