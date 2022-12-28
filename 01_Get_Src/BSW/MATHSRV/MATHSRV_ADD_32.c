/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_ADD_32.c                                        */
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
 * %PID: LIBEMB:MATHSRV ADD 32 C-99055191X4420X324.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "MATHSRV.h"
#include "STD_Types.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* !FuncName    : MATHSRV_u32Add_u32_u32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To :  MFX006                                                        */
/* !Trace_To :  MFX007                                                        */
/*                                                                            */
/* !LastAuthor  :  M.Mohi                                                     */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Add_u32_u32
(
   uint32 u32FirstValue,
   uint32 u32SecondValue
)
{
   uint32_least u32LocalResult;


   u32LocalResult = u32FirstValue + u32SecondValue;
   if (u32LocalResult < u32FirstValue)
   {
      u32LocalResult = UINT32_MAX;
   }

   return(u32LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_s32Add_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To :  MFX006                                                        */
/* !Trace_To :  MFX007                                                        */
/*                                                                            */
/* !LastAuthor  :  M.Mohi                                                     */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Add_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)
{
   sint32_least s32LocalResult;


   s32LocalResult = (s32FirstValue) + (s32SecondValue);
   if (s32FirstValue >= 0)
   {
      if (  (s32LocalResult < 0)
         && (s32SecondValue >= 0) )
      {
         s32LocalResult = SINT32_MAX;
      }
   }
   else
   {
      if (  (s32LocalResult >= 0)
         && (s32SecondValue < 0) )
      {
         s32LocalResult = SINT32_MIN;
      }
   }
   return(s32LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_u32Add_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To :  MFX006                                                        */
/* !Trace_To :  MFX007                                                        */
/*                                                                            */
/* !LastAuthor  :  M.Mohi                                                     */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Add_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;


   u32LocalResult = (u32FirstValue) + (uint32_least)(s32SecondValue);
   if (s32SecondValue >= 0)
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
/* !FuncName    : MATHSRV_u32Add_s32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To :  MFX006                                                        */
/* !Trace_To :  MFX007                                                        */
/*                                                                            */
/* !LastAuthor  :  M.Mohi                                                     */
/******************************************************************************/
FUNC(uint32, MATHSRV_CODE)  MATHSRV_u32Add_s32_s32
(
   sint32 s32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;


   u32LocalResult =
      (uint32_least)(s32FirstValue) + (uint32_least)(s32SecondValue);
   if (s32FirstValue < 0)
   {
      if (  (s32SecondValue <= 0)
         || (u32LocalResult > (uint32_least)s32SecondValue) )
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   else
   {
      if (  (s32SecondValue < 0)
         && (u32LocalResult > (uint32_least)s32FirstValue) )
      {
         u32LocalResult = UINT32_MIN;
      }
   }
   return(u32LocalResult);
}

/******************************************************************************/
/* !FuncName    : MATHSRV_s32Add_u32_s32                                      */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To :  MFX006                                                        */
/* !Trace_To :  MFX007                                                        */
/*                                                                            */
/* !LastAuthor  :  M.Mohi                                                     */
/******************************************************************************/
FUNC(sint32, MATHSRV_CODE)  MATHSRV_s32Add_u32_s32
(
   uint32 u32FirstValue,
   sint32 s32SecondValue
)
{
   uint32_least u32LocalResult;
   sint32_least s32LocalResult;


   u32LocalResult = (u32FirstValue) + (uint32_least)(s32SecondValue);
   s32LocalResult = (sint32_least)u32LocalResult;

   if (s32SecondValue >= 0)
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
         s32LocalResult = SINT32_MAX;
      }
   }
   return(s32LocalResult);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/
