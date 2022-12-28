/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_INTERP_U16.c                                    */
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
 * %PID: LIBEMB:MATHSRV INTERP U16 C-99055193X4420X340.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_u16Interp1d                                         */
/* !Description : Calculate the uint16 interpolation value on                 */
/*                u16SiteInterpolation parameter.                             */
/*                                                                            */
/* !Trace_To    : VEMS_R_08_02127_025.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d
(
   CONST(uint16, MATHSRV_CONST) kau16Cartography[],
   uint16 u16SiteInterpolation
)
{
   sint32 s32LocalInterpolation;
   uint32 u32LocalSite;
   uint32 u32LocalFirstValue;
   uint32 u32LocalResultValue;


   P2CONST(uint16, AUTOMATIC, MATHSRV_CONST) pku16LocalCartography;

   /* !Comment : MSB of u16InterpolationSite is the index of the first point     */
   /*            in the map                                                      */
   u32LocalSite = u16SiteInterpolation;
   u32LocalSite = u32LocalSite >> 8;

   /* !Comment : use a local pointer for code optimisation                       */
   pku16LocalCartography = &kau16Cartography[u32LocalSite];

   /* !Comment : u32LocalParam store the value of the first point in the map     */
   u32LocalFirstValue = *pku16LocalCartography;

   /* !Comment : compute the delta between the two consecutive point in the map  */
   s32LocalInterpolation = (sint32)pku16LocalCartography[1]
                           - (sint32)u32LocalFirstValue;

   /* !Comment : multiply this delta with the percent of Site position LSB/256   */
   s32LocalInterpolation = s32LocalInterpolation
                           * (u16SiteInterpolation & 0x00FF);
   s32LocalInterpolation += 0x80;

   /* !Comment : scale the first point value to the result of the delta          */
   u32LocalFirstValue = u32LocalFirstValue << 8;

   /* !Comment : add the delta value to the first point value                    */
   /*            the result is always a value between the two point of the MAP:  */
   /*            so, it is always a positive value and fit in an uint24          */
   u32LocalResultValue = (uint32)( (sint32)u32LocalFirstValue
                                   + s32LocalInterpolation);

   /* !Comment : rescale the result wich is 256 time greater for the compute     */
   /*            accuracy                                                        */
   u32LocalResultValue = u32LocalResultValue >> 8;
   return( (uint16)u32LocalResultValue);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Interp1d09Pts                                    */
/* !Description : Calculate the uint16 interpolation of u8Value parameter on  */
/*                9 points cartography only                                   */
/*                                                                            */
/* !Trace_To    : VEMS_R_08_02127_025.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d09Pts
(
   CONST(uint16, MATHSRV_CONST) kau16Cartography[9],
   uint8 u8Value
)
{
   uint16 u16LocalValue;


   u16LocalValue = (uint16)( (uint32)u8Value << 3);
   return(MATHSRV_u16Interp1d(kau16Cartography, u16LocalValue) );
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Interp1d11Pts                                    */
/* !Description : Calculate the uint16 interpolation of u8Value parameter on  */
/*                11 points cartography only                                  */
/*                                                                            */
/* !Trace_To    : VEMS_R_08_02127_025.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d11Pts
(
   CONST(uint16, MATHSRV_CONST) kau16Cartography[11],
   uint8 u8Value
)
{
   uint16 u16LocalValue;


   if (u8Value > 0x40)
   {
      u16LocalValue = (uint16)( (uint32)u8Value << 3);
      u16LocalValue = (uint16)( (uint32)u16LocalValue + 0x200);
   }
   else
   {
      u16LocalValue = (uint16)( (uint32)u8Value << 4);
   }
   return(MATHSRV_u16Interp1d(kau16Cartography, u16LocalValue) );
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Interp1d17Pts                                    */
/* !Description : Calculate the uint16 interpolation of u8Value parameter on  */
/*                17 points cartography only                                  */
/*                                                                            */
/* !Trace_To    : VEMS_R_08_02127_025.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp1d17Pts
(
   CONST(uint16, MATHSRV_CONST) kau16Cartography[17],
   uint8 u8Value
)
{
   uint16 u16LocalValue;


   u16LocalValue = (uint16)( (uint32)u8Value << 4);
   return(MATHSRV_u16Interp1d(kau16Cartography, u16LocalValue) );
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u16Interp2d                                         */
/* !Description : Calculate the uint16 interpolation value on a 2 dimension   */
/*                point parameter.                                            */
/*                                                                            */
/* !Trace_To    : VEMS_R_08_02127_033.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16Interp2d
(
   P2CONST(uint16, AUTOMATIC, MATHSRV_CONST) pkau16Cartography,
   uint16 u16SiteInterpolationXLine,
   uint16 u16SiteInterpolationYColumn,
   uint8 u8BreakpointNumberYColumn
)
{
   sint32 s32LocalLineIndex;
   sint32 s32LocalInterpolation;
   sint32 s32LocalSecondValue;
   uint32 u32LocalResultValue;
   uint16 u16LocalFirstValue;
   uint8  u8LocalInterpolationXLine;


   /* !Comment: Extract the line of the map pointed by u16SiteInterpolationXLine */
   s32LocalLineIndex = (sint32)(u16SiteInterpolationXLine >> 8);
   s32LocalLineIndex = s32LocalLineIndex * u8BreakpointNumberYColumn;
   pkau16Cartography = &pkau16Cartography[s32LocalLineIndex];

   /* !Comment: do the interpolaiton in the first line                           */
   u16LocalFirstValue = MATHSRV_u16Interp1d(pkau16Cartography,
                                            u16SiteInterpolationYColumn);

   /* !Deviation: Violation of MISRA Rule 17.4. Reason : Length of lines is not  */
   /*             fixed so we cannot acces to the next line of the table by      */
   /*             indexation                                                     */
   pkau16Cartography = pkau16Cartography + u8BreakpointNumberYColumn;

   s32LocalSecondValue = (sint32)MATHSRV_u16Interp1d(pkau16Cartography,
                                                     u16SiteInterpolationYColumn);

   u8LocalInterpolationXLine = (uint8)(u16SiteInterpolationXLine & 0x00FF);
   s32LocalInterpolation     = s32LocalSecondValue - u16LocalFirstValue;
   s32LocalInterpolation     = s32LocalInterpolation * u8LocalInterpolationXLine;
   s32LocalInterpolation     = s32LocalInterpolation + 0x80;

   u32LocalResultValue = (uint32)u16LocalFirstValue << 8;
   u32LocalResultValue = (uint32)( (sint32)u32LocalResultValue
                                   + s32LocalInterpolation);
   u32LocalResultValue = u32LocalResultValue >> 8;
   return( (uint16)u32LocalResultValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
