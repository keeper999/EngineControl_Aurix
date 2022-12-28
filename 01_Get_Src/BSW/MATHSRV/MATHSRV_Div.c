/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_DIV.c                                           */
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
 * %PID: LIBEMB:MATHSRV DIV C-99055192X4420X330.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "MATHSRV.h"
#include "STD_Types.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* !FuncName    : MATHSRV_s16Div_s32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Div_s32_u32
(
   sint32 s32FirstValue,
   uint32 u32SecondValue
)

{
   sint32_least s32LocalResult;
   uint32_least u32LocalResult;
   uint32_least u32LocalRemainder;
   uint32_least u32LocalXAbsVal;
   sint16_least s16LocalResult;


   if (u32SecondValue != 0)
   {
      u32LocalXAbsVal   = (uint32)MATHSRV_udtABS(s32FirstValue);
      u32LocalResult    = (u32LocalXAbsVal / u32SecondValue);
      u32LocalRemainder = (u32LocalXAbsVal % u32SecondValue);
      if (  (u32LocalRemainder > (u32SecondValue / 2) )
         || (  ( (u32SecondValue % 2) == 0)
            && (u32LocalRemainder == (u32SecondValue / 2) ) ) )
      {
         u32LocalResult += 1;
      }
      if (s32FirstValue < 0)
      {
         s32LocalResult = -( (sint32)u32LocalResult);
      }
      else
      {
         s32LocalResult = (sint32)u32LocalResult;
      }
      s16LocalResult = MATHSRV_udtCLAMP(s32LocalResult, (sint32)SINT16_MIN,
                                        (sint32)SINT16_MAX);
   }
   else
   {
      if (s32FirstValue >= 0)
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
/* !FuncName    : MATHSRV_s16Div_s32_s16                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE)  MATHSRV_s16Div_s32_s16
(
   sint32 s32FirstValue,
   sint16 s16SecondValue
)

{
   sint16_least s16LocalResult;
   sint32_least s32LocalResult;
   uint32_least u32LocalXAbsVal;
   uint32_least u32LocalYAbsVal;
   sint32_least s32LocalTemp;


   s32LocalTemp = s32FirstValue;

   if (s16SecondValue != 0)
   {
      if (  (s32FirstValue != SINT32_MIN)
         || (s16SecondValue != -1) )
      {
         s32LocalResult = (s32FirstValue / (sint32)s16SecondValue);
         /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         u32LocalXAbsVal = (uint32)MATHSRV_udtABS(s32LocalTemp);
         u32LocalYAbsVal = (uint32)MATHSRV_udtABS(s16SecondValue);
         if ( ( ( (u32LocalXAbsVal) % u32LocalYAbsVal) * 2) >= u32LocalYAbsVal)
         {
            /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
            if (  (  (s32FirstValue > 0)
                  && (s16SecondValue > 0) )
               || (  (s32FirstValue < 0)
                  && (s16SecondValue < 0) ) )
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
         s16LocalResult = SINT16_MAX;
      }
   }
   else
   {
      if (s32FirstValue >= 0)
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
/* !FuncName    : MATHSRV_u16Div_s32_u16                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Div_s32_u16
(
   sint32 s32FirstValue,
   uint16 u16SecondValue
)

{
   uint16_least u16LocalResult;
   uint32_least u32LocalResult;


   if (u16SecondValue != 0)
   {
      if (s32FirstValue > 0)
      {
         u32LocalResult = (uint32)(s32FirstValue / (sint32)u16SecondValue);
         if ( ( (s32FirstValue % u16SecondValue) * 2) >= u16SecondValue)
         {
            u32LocalResult += 1;
         }
         u16LocalResult = MATHSRV_udtMIN(u32LocalResult, (uint32)UINT16_MAX);
         /* QAC Warning 1258 is due to the Explicit Casting for UINT16_MAX */
      }
      else
      {
         u16LocalResult = UINT16_MIN;
      }
   }
   else
   {
      if (s32FirstValue >= 0)
      {
         u16LocalResult = UINT16_MAX;
         /* QAC Warning 1258 is due to the Implicit Casting for UINT16_MAX */
      }
      else
      {
         u16LocalResult = UINT16_MIN;
      }
   }
   return( (uint16)u16LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_u16Div_u32_u16                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE)  MATHSRV_u16Div_u32_u16
(
   uint32 u32FirstValue,
   uint16 u16SecondValue
)

{
   uint16_least u16LocalResult;
   uint32_least u32LocalResult;


   if (u16SecondValue != 0)
   {
      u32LocalResult = (u16SecondValue) - (u16SecondValue / 2);
      if (u32LocalResult > u32FirstValue)
      {
         u16LocalResult = UINT16_MIN;
      }
      else
      {
         u32LocalResult = u32FirstValue - u32LocalResult;
         u32LocalResult = (u32LocalResult / u16SecondValue) + 1;
         u16LocalResult = MATHSRV_udtMIN(u32LocalResult, (uint32)UINT16_MAX);
         /* QAC Warning 1258 is due to the Explicit cast for UINT16_MAX */
      }
   }
   else
   {
      u16LocalResult = UINT16_MAX;
      /* QAC Warning 1256 is due to the Ixplicit Casting for UINT16_MAX */
   }
   return( (uint16)u16LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_u32Div_u32_u16                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_u32_u16
(
   uint32 u32FirstValue,
   uint16 u16SecondValue
)

{
   uint32_least u32LocalResult;


   if (u16SecondValue != 0)
   {
      u32LocalResult = (u16SecondValue) - (u16SecondValue / 2);
      if (u32LocalResult > u32FirstValue)
      {
         u32LocalResult = UINT32_MIN;
      }
      else
      {
         u32LocalResult = u32FirstValue - u32LocalResult;
         u32LocalResult = (u32LocalResult / u16SecondValue) + 1;
      }
   }
   else
   {
      u32LocalResult = UINT32_MAX;
   }
   return(u32LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_u32Div_u32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_u32_u32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue
)

{
   uint32_least u32LocalResult;


   if (u32SecondValue != 0)
   {
      u32LocalResult = (u32SecondValue) - (u32SecondValue / 2);
      if (u32LocalResult > u32FirstValue)
      {
         u32LocalResult = UINT32_MIN;
      }
      else
      {
         u32LocalResult = u32FirstValue - u32LocalResult;
         u32LocalResult = (u32LocalResult / u32SecondValue) + 1;
      }
   }
   else
   {
      u32LocalResult = UINT32_MAX;
   }
   return(u32LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_u32Div_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)

{
   uint32_least u32LocalResult;


   if (s32SecondValue != 0)
   {
      if (s32SecondValue > 0)
      {
         u32LocalResult = (uint32)( (s32SecondValue) - (s32SecondValue / 2) );
         if (u32LocalResult > u32FirstValue)
         {
            u32LocalResult = UINT32_MIN;
         }
         else
         {
            u32LocalResult = u32FirstValue - u32LocalResult;
            u32LocalResult = (u32LocalResult / (uint32)s32SecondValue) + 1;
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
/* !FuncName    : MATHSRV_u32Div_s32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_s32_u32
(
   sint32 s32FirstValue,
   uint32 u32SecondValue
)

{
   uint32_least u32LocalResult;
   uint32_least u32LocalRemainder;


   if (u32SecondValue != 0)
   {
      if (s32FirstValue > 0)
      {
         u32LocalResult    = ( ( (uint32)s32FirstValue) / u32SecondValue);
         u32LocalRemainder = ( ( (uint32)s32FirstValue) % u32SecondValue);
         if (  (u32LocalRemainder > (u32SecondValue / 2) )
            || (  ( (u32SecondValue % 2) == 0)
               && (u32LocalRemainder == (u32SecondValue / 2) ) ) )
         {
            u32LocalResult += 1;
         }
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      if (s32FirstValue >= 0)
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
/* !FuncName    : MATHSRV_u32Div_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Div_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)

{
   uint32_least u32LocalResult;
   uint32_least u32LocalXAbsVal;
   uint32_least u32LocalYAbsVal;
   uint32_least u32LocalRemainder;


   if (s32SecondValue != 0)
   {
      if (  (  (s32FirstValue >= 0)
            && (s32SecondValue > 0) )
         || (  (s32FirstValue <= 0)
            && (s32SecondValue < 0) ) )
      {
         if (  (s32SecondValue == (-1) )
            && (s32FirstValue == SINT32_MIN) )
         {
            u32LocalResult = 2147483648UL;
         }
         else
         {
            u32LocalResult    = (uint32)(s32FirstValue / s32SecondValue);
            u32LocalXAbsVal   = (uint32)MATHSRV_udtABS(s32FirstValue);
            u32LocalYAbsVal   = (uint32)MATHSRV_udtABS(s32SecondValue);
            u32LocalRemainder = (u32LocalXAbsVal % u32LocalYAbsVal);
            /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
            if (  (u32LocalRemainder > (u32LocalYAbsVal / 2) )
               || (  ( (u32LocalYAbsVal % 2) == 0)
                  && (u32LocalRemainder == (u32LocalYAbsVal / 2) ) ) )
            {
               u32LocalResult += 1;
            }
         }
      }
      else
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      if (s32FirstValue >= 0)
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
/* !FuncName    : MATHSRV_s32Div_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Div_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)

{
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;
   uint32_least u32LocalYAbsVal;
   uint32_least u32LocalRemainder;


   if (s32SecondValue != 0)
   {
      if (  (u32FirstValue <= (uint32)SINT32_MAX)
         || (s32SecondValue != -1) )
      {
         /* QAC Warning 1258 is due to the Explicit Casting for SINT32_MAX */
         u32LocalYAbsVal = (uint32)MATHSRV_udtABS(s32SecondValue);
         u32LocalResult  = (u32FirstValue / u32LocalYAbsVal);
         /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         u32LocalRemainder = (u32FirstValue % u32LocalYAbsVal);
         /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         if (  (u32LocalRemainder > (u32LocalYAbsVal / 2) )
            || (  ( (u32LocalYAbsVal % 2) == 0)
               && (u32LocalRemainder == (u32LocalYAbsVal / 2) ) ) )
         {
            u32LocalResult += 1;
         }
         if (s32SecondValue < 0)
         {
            s32LocalResult = -( (sint32)u32LocalResult);
         }
         else
         {
            s32LocalResult = (sint32)MATHSRV_udtMIN(u32LocalResult,
                                                    (uint32)SINT32_MAX);
            /* QAC Warning 1258 is due to the Explicit Casting for SINT32_MAX */
         }
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   else
   {
      s32LocalResult = SINT32_MAX;
   }
   return(s32LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_s32Div_s32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Div_s32_u32
(
   sint32 s32FirstValue,
   uint32 u32SecondValue
)

{
   sint32_least s32LocalResult;
   uint32_least u32LocalResult;
   uint32_least u32LocalXAbsVal;
   uint32_least u32LocalRemainder;


   if (u32SecondValue != 0)
   {
      u32LocalXAbsVal   = (uint32)MATHSRV_udtABS(s32FirstValue);
      u32LocalResult    = (u32LocalXAbsVal / u32SecondValue);
      u32LocalRemainder = (u32LocalXAbsVal % u32SecondValue);
      if (  (u32LocalRemainder > (u32SecondValue / 2) )
         || (  ( (u32SecondValue % 2) == 0)
            && (u32LocalRemainder == (u32SecondValue / 2) ) ) )
      {
         u32LocalResult += 1;
      }
      if (s32FirstValue < 0)
      {
         s32LocalResult = -( (sint32)u32LocalResult);
      }
      else
      {
         s32LocalResult = (sint32)u32LocalResult;
      }
   }
   else
   {
      if (s32FirstValue >= 0)
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
/* !FuncName    : MATHSRV_s32Div_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX033                                                      */
/* !Trace_To    : MFX034                                                      */
/* !Trace_To    : MFX035                                                      */
/* !Trace_To    : MFX037                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Div_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)

{
   sint32_least s32LocalResult;
   uint32_least u32LocalXAbsVal;
   uint32_least u32LocalYAbsVal;
   uint32_least u32LocalRemainder;
   sint32_least s32LocalTemp;


   s32LocalTemp = s32FirstValue;   /*To Avoid MISRA Violation*/

   if (s32SecondValue != 0)
   {
      if (  (s32FirstValue != SINT32_MIN)
         || (s32SecondValue != -1) )
      {
         u32LocalXAbsVal = (uint32)MATHSRV_udtABS(s32LocalTemp);
         u32LocalYAbsVal = (uint32)MATHSRV_udtABS(s32SecondValue);
         s32LocalResult  = (s32FirstValue / s32SecondValue);
         /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         u32LocalRemainder = (u32LocalXAbsVal % u32LocalYAbsVal);
         /*QAC Warning 0584:Accepted,Code revised to avoid Division by Zero*/
         if (  (u32LocalRemainder > (u32LocalYAbsVal / 2) )
            || (  ( (u32LocalYAbsVal % 2) == 0)
               && (u32LocalRemainder == (u32LocalYAbsVal / 2) ) ) )
         {
            if (  (  (s32FirstValue > 0)
                  && (s32SecondValue > 0) )
               || (  (s32FirstValue < 0)
                  && (s32SecondValue < 0) ) )
            {
               s32LocalResult += 1;
            }
            else
            {
               s32LocalResult -= 1;
            }
         }
      }
      else
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else
   {
      if (s32FirstValue >= 0)
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


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"

/******************************* End of File *********************************/
