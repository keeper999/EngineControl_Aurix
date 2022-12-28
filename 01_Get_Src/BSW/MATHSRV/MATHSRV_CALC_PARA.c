/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_CALC_PARA.c                                     */
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
 * %PID: LIBEMB:MATHSRV CALC PARA C-99055191X4420X328.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "MATHSRV.h"


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define MATHSRV_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* !FuncName    : MATHSRV_u16CalcParaIncAryU8Loc                              */
/* !Description : Calculate the "Para" value of u8Value with a breakpoint     */
/*                array of 255 points max and a maximum value of 255.         */
/*                                                                            */
/* !TraceTo   : VEMS_R_08_02127_001.01                                        */
/*                                                                            */
/* !LastAuthor : J. Perochon                                                  */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16CalcParaIncAryU8Loc
(
   CONST(uint8, MATHSRV_CONST) kau8BreakpointMap[],
   uint8 u8Value,
   uint8 u8BreakpointNumberMinusOne
)
{
   uint32 u32LocalPivot;
   uint32 u32LocalSiteIndex;
   uint32 u32LocalSiteValue;
   uint32 u32LocalInterpolation;
   uint32 u32LocalDeltaValueFromSite;
   uint32 u32LocalSiteInterpolation;


   if (u8Value >= kau8BreakpointMap[u8BreakpointNumberMinusOne])
   {
      /* !TraceTo : VEMS_R_08_02127_003.01                                          */
      /* !Comment : Value is greater than the last point, then return the last      */
      /*            point index                                                     */
      return( (uint16)( (uint32)u8BreakpointNumberMinusOne << 8) );
   }

   if (u8Value < kau8BreakpointMap[0])
   {
      /* !TraceTo : VEMS_R_08_02127_002.01                                          */
      /* !Comment : Value is lesser than the first point, then return the first     */
      /*            point index                                                     */
      return(0);
   }

   /* !Comment : Perform a binary-search (Dichotomie)                            */
   u32LocalSiteIndex = 0;

   while (u8BreakpointNumberMinusOne > 2)
   {
      u32LocalPivot = u32LocalSiteIndex + (u8BreakpointNumberMinusOne >> 1);
      if (u8Value < kau8BreakpointMap[u32LocalPivot])
      {
         u8BreakpointNumberMinusOne = (uint8)(u32LocalPivot
                                              - u32LocalSiteIndex);
      }
      else
      {
         u8BreakpointNumberMinusOne = (uint8)( (u32LocalSiteIndex
                                                + u8BreakpointNumberMinusOne)
                                               - u32LocalPivot);
         u32LocalSiteIndex = u32LocalPivot;
      }
   }

   if (u8Value >= kau8BreakpointMap[u32LocalSiteIndex + 1])
   {
      u32LocalSiteIndex++;
   }

   u32LocalSiteValue = kau8BreakpointMap[u32LocalSiteIndex];

   u32LocalDeltaValueFromSite = u8Value - u32LocalSiteValue;
   u32LocalDeltaValueFromSite = u32LocalDeltaValueFromSite << 8;

   u32LocalInterpolation = kau8BreakpointMap[u32LocalSiteIndex + 1]
                           - u32LocalSiteValue;
   u32LocalInterpolation = u32LocalDeltaValueFromSite / u32LocalInterpolation;

   u32LocalSiteIndex         = u32LocalSiteIndex << 8;
   u32LocalSiteInterpolation = u32LocalSiteIndex + u32LocalInterpolation;

   return( (uint16)u32LocalSiteInterpolation);
   /* !Deviation: Violation of MISRA Rule 14.7. Reason : Optimisation, this      */
   /*             function is used a lot of time                                 */
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16CalcParaIncAryU16Loc                             */
/* !Description : Calculate the "Para" value of u8Value with a breakpoint     */
/*                array of 255 points max and a maximum value of 65535.       */
/*                                                                            */
/* !TraceTo   : VEMS_R_08_02127_005.01                                        */
/*                                                                            */
/* !LastAuthor : J. Perochon                                                  */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16CalcParaIncAryU16Loc
(
   CONST(uint16, MATHSRV_CONST) kau16BreakpointMap[],
   uint16 u16Value,
   uint8 u8BreakpointNumberMinusOne
)
{
   uint32 u32LocalPivot;
   uint32 u32LocalSiteIndex;
   uint32 u32LocalSiteValue;
   uint32 u32LocalInterpolation;
   uint32 u32LocalDeltaValueFromSite;
   uint32 u32LocalSiteInterpolation;


   if (u16Value >= kau16BreakpointMap[u8BreakpointNumberMinusOne])
   {
      /* !TraceTo : VEMS_R_08_02127_007.01                                          */
      /* !Comment : Value is greater than the last point, then return the last      */
      /*            point index                                                     */
      return( (uint16)( (uint32)u8BreakpointNumberMinusOne << 8) );
   }

   if (u16Value < kau16BreakpointMap[0])
   {
      /* !TraceTo : VEMS_R_08_02127_006.01                                          */
      /* !Comment : Value is lesser than the first point, then return the first     */
      /*            point index                                                     */
      return(0);
   }

   /* !Comment : Perform a binary-search (Dichotomie)                            */
   u32LocalSiteIndex = 0;

   while (u8BreakpointNumberMinusOne > 2)
   {
      u32LocalPivot = u32LocalSiteIndex + (u8BreakpointNumberMinusOne >> 1);
      if (u16Value < kau16BreakpointMap[u32LocalPivot])
      {
         u8BreakpointNumberMinusOne = (uint8)(u32LocalPivot
                                              - u32LocalSiteIndex);
      }
      else
      {
         u8BreakpointNumberMinusOne = (uint8)( (u32LocalSiteIndex
                                                + u8BreakpointNumberMinusOne)
                                               - u32LocalPivot);
         u32LocalSiteIndex = u32LocalPivot;
      }
   }

   if (u16Value >= kau16BreakpointMap[u32LocalSiteIndex + 1])
   {
      u32LocalSiteIndex++;
   }

   u32LocalSiteValue = kau16BreakpointMap[u32LocalSiteIndex];

   u32LocalDeltaValueFromSite = u16Value - u32LocalSiteValue;
   u32LocalDeltaValueFromSite = u32LocalDeltaValueFromSite << 8;

   u32LocalInterpolation = kau16BreakpointMap[u32LocalSiteIndex + 1]
                           - u32LocalSiteValue;
   u32LocalInterpolation = u32LocalDeltaValueFromSite / u32LocalInterpolation;

   u32LocalSiteIndex         = u32LocalSiteIndex << 8;
   u32LocalSiteInterpolation = u32LocalSiteIndex + u32LocalInterpolation;

   return( (uint16)u32LocalSiteInterpolation);
   /* !Deviation: Violation of MISRA Rule 14.7. Reason : Optimisation, this      */
   /*             function is used a lot of time                                 */
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/
