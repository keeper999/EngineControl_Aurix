/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_SUB.c                                           */
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
 * %PID: LIBEMB:MATHSRV SUB C-99055196X4420X384.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/


#include "MATHSRV.h"
#include "STD_Types.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Sub_u32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Sub_u32_u32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue
)
{
   uint32_least u32LocalResult;


   u32LocalResult = u32FirstValue - u32SecondValue;
   if (u32LocalResult > u32FirstValue)
   {
      u32LocalResult = UINT32_MIN;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Sub_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Sub_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;


   u32LocalResult = (u32FirstValue) - ( (uint32_least)(s32SecondValue) );
   if (s32SecondValue < 0)
   {
      if (u32LocalResult < u32FirstValue)
      {
         u32LocalResult = UINT32_MAX;
      }
   }
   else
   {
      if (u32LocalResult > u32FirstValue)
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Sub_s32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Sub_s32_u32
(
   sint32 s32FirstValue,
   uint32 u32SecondValue
)
{
   uint32_least u32LocalResult;


   u32LocalResult = ( (uint32_least)(s32FirstValue) ) - (u32SecondValue);
   if (s32FirstValue > 0)
   {
      if (u32LocalResult > (uint32_least)s32FirstValue)
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      u32LocalResult = UINT32_MIN;
   }
   return(u32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u32Sub_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Sub_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)
{
   sint32_least s32LocalResult;


   s32LocalResult = s32FirstValue - s32SecondValue;
   if (s32FirstValue >= 0)
   {
      if (  (s32SecondValue > 0)
         && (s32LocalResult < 0) )
      {
         s32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      if (  (s32SecondValue >= 0)
         || (s32LocalResult <= 0) )
      {
         s32LocalResult = UINT32_MIN;
      }
   }
   return( (uint32)s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Sub_u32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_u32_u32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue
)
{
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   u32LocalResult = u32FirstValue - u32SecondValue;
   s32LocalResult = (sint32)(u32LocalResult);
   /* Cast of u32FirstValue in type sint32 to optimize the test*/
   if (u32FirstValue < u32SecondValue)
   {
      if (s32LocalResult > 0)
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   else
   {
      if (s32LocalResult < 0)
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Sub_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   u32LocalResult = u32FirstValue - (uint32_least)s32SecondValue;
   s32LocalResult = (sint32_least)(u32LocalResult);
   if (s32SecondValue < 0)
   {
      if (  (u32LocalResult < u32FirstValue)
         || (s32LocalResult < 0) )
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else
   {
      if (  ( (sint32)u32FirstValue < 0)
         && (s32LocalResult < 0) )
      {
         /* Cast of u32FirstValue in type sint32 to optimize the test
          * this is  equivalent with : u32FirstValue > SINT32_MAX*/
         s32LocalResult = SINT32_MAX;
      }
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Sub_s32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_s32_u32
(
   sint32 s32FirstValue,
   uint32 u32SecondValue
)
{
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   u32LocalResult = (-SINT32_MIN) + (uint32_least)(s32FirstValue);
   if (u32LocalResult < u32SecondValue)
   {
      s32LocalResult = SINT32_MIN;
   }
   else
   {
      s32LocalResult = s32FirstValue - (sint32)(u32SecondValue);
   }
   return(s32LocalResult);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_s32Sub_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    : MFX010                                                      */
/* !Trace_To    : MFX011                                                      */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Sub_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)
{

   sint32_least s32LocalResult;


   s32LocalResult = s32FirstValue - s32SecondValue;
   if (s32FirstValue >= 0)
   {
      if (  (s32SecondValue < 0)
         && (s32LocalResult < 0) )
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else
   {
      if (  (s32SecondValue >= 0)
         && (s32LocalResult >= 0) )
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   return(s32LocalResult);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*-------------------------------- end of file -------------------------------*/
