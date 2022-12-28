/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_MUL.c                                           */
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
 * %PID: LIBEMB:MATHSRV MUL C-99055193X4420X350.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "MATHSRV.h"
#include "STD_Types.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_u16                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u16
(
   uint32 u32FirstValue,
   uint16 u16SecondValue
)
{
   uint32_least u32LocalResult;


   if (u16SecondValue > 0)
   {
      u32LocalResult = UINT32_MAX / (uint32_least)u16SecondValue;
      if (u32LocalResult >= u32FirstValue)
      {
         u32LocalResult = (u32FirstValue) * (u16SecondValue);
      }
      else
      {
         u32LocalResult = UINT32_MAX;
      }
   }
   else
   {
      u32LocalResult = 0;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_s32_u16                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_u16
(
   sint32 s32FirstValue,
   uint16 u16SecondValue
)
{
   sint32_least s32LocalResult;
   uint32_least u32LocalTemp;


   if (s32FirstValue > 0)
   {
      s32LocalResult = SINT32_MAX / s32FirstValue;

      if (s32LocalResult >= u16SecondValue)
      {
         s32LocalResult = (s32FirstValue) * (u16SecondValue);
      }
      else
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else if (s32FirstValue < 0)
   {
      if (s32FirstValue == (-1) )
      {
         u32LocalTemp = 2147483648UL;
      }
      else
      {
         u32LocalTemp = (uint32_least)(SINT32_MIN / (s32FirstValue) );
      }
      if (u32LocalTemp >= u16SecondValue)
      {
         s32LocalResult = (s32FirstValue) * (u16SecondValue);
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   else
   {
      s32LocalResult = 0;
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_u32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue
)
{
   uint32_least u32LocalResult;


   if (u32FirstValue > 0)
   {
      u32LocalResult = UINT32_MAX / u32FirstValue;
      if (u32LocalResult >= u32SecondValue)
      {
         u32LocalResult = (u32FirstValue) * (u32SecondValue);
      }
      else
      {
         u32LocalResult = UINT32_MAX;
      }
   }
   else
   {
      u32LocalResult = 0;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;


   if (s32SecondValue > 0)
   {
      u32LocalResult = UINT32_MAX / (uint32_least)s32SecondValue;
      if (u32LocalResult >= u32FirstValue)
      {
         u32LocalResult = (u32FirstValue) * (uint32_least)(s32SecondValue);
      }
      else
      {
         u32LocalResult = UINT32_MAX;
      }
   }
   else if (s32SecondValue < 0)
   {
      u32LocalResult = UINT32_MIN;
   }
   else
   {
      u32LocalResult = 0;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Mul_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Mul_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;


   if (  (s32FirstValue > 0)
      && (s32SecondValue > 0) )
   {
      u32LocalResult = UINT32_MAX / (uint32_least)s32SecondValue;
      if (u32LocalResult >= (uint32_least)s32FirstValue)
      {
         u32LocalResult = (uint32_least)( (s32FirstValue) * (s32SecondValue) );
      }
      else
      {
         u32LocalResult = UINT32_MAX;
      }
   }
   else if (  (s32FirstValue < 0)
           && (s32SecondValue < 0) )
   {
      if (s32SecondValue < (SINT32_MIN + 1) )
      {
         u32LocalResult = 1;
      }
      else
      {
         u32LocalResult = UINT32_MAX / (uint32_least)(-s32SecondValue);
      }
      if (u32LocalResult >= (uint32_least)(-s32FirstValue) )
      {
         u32LocalResult = (uint32_least)( (-s32FirstValue) * (-s32SecondValue) );
         /*QAC Msg(3:0291): There is no problem both values are checked to be
            -ve before the execution of this line.*/
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
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)
{
   sint32_least s32LocalResult;
   uint32_least u32LocalTemp;


   if (s32SecondValue > 0)
   {
      if ( (uint32_least)(SINT32_MAX / s32SecondValue) >= u32FirstValue)
      {
         s32LocalResult = (s32SecondValue) * (sint32_least)(u32FirstValue);
      }
      else
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else if (s32SecondValue < 0)
   {
      if (s32SecondValue == (-1) )
      {
         u32LocalTemp = (2147483648UL);
      }
      else
      {
         u32LocalTemp = (uint32_least)(SINT32_MIN / (s32SecondValue) );
      }
      if ( (u32LocalTemp) >= u32FirstValue)
      {
         s32LocalResult = (s32SecondValue) * (sint32_least)(u32FirstValue);
      }
      else
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   else
   {
      s32LocalResult = 0;
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Mul_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX022                                                      */
/* !Trace_To    : MFX023                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Mul_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)
{
   sint32_least s32LocalResult;
   uint32_least u32LocalTemp;


   if (  (s32FirstValue > 0)
      && (s32SecondValue > 0) )
   {
      s32LocalResult = SINT32_MAX / s32SecondValue;
      if (s32LocalResult >= s32FirstValue)
      {
         s32LocalResult = (s32FirstValue) * (s32SecondValue);
      }
      else
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else if (  (s32FirstValue < 0)
           && (s32SecondValue < 0) )
   {
      if (s32SecondValue < (SINT32_MIN + 1) )
      {
         u32LocalTemp = 0;
      }
      else
      {
         u32LocalTemp = (uint32_least)(SINT32_MAX / (-s32SecondValue) );
      }
      if (u32LocalTemp >= (uint32_least)(-s32FirstValue) )
      {
         s32LocalResult = ( (-s32FirstValue) * (-s32SecondValue) );
      }
      else
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else
   {
      if (s32FirstValue > 0)
      {
         s32LocalResult = SINT32_MIN / s32FirstValue;
         if (s32LocalResult <= s32SecondValue)
         {
            s32LocalResult = (s32FirstValue * s32SecondValue);
         }
         else
         {
            s32LocalResult = SINT32_MIN;
         }
      }
      else if (s32FirstValue < 0)
      {
         if (s32FirstValue == (-1) )
         {
            u32LocalTemp = (2147483648UL);
         }
         else
         {
            u32LocalTemp = (uint32_least)(SINT32_MIN / (s32FirstValue) );
         }
         if (u32LocalTemp >= (uint32_least)s32SecondValue)
         {
            s32LocalResult = (s32FirstValue * s32SecondValue);
         }
         else
         {
            s32LocalResult = SINT32_MIN;
         }
      }
      else
      {
         s32LocalResult = 0;
      }
   }
   return(s32LocalResult);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/
