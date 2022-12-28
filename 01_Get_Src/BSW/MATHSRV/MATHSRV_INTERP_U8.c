/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_INTERP_U8.c                                     */
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
 * %PID: LIBEMB:MATHSRV INTERP U8 C-99055193X4420X342.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_u8Interp1d                                          */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_014.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d
(
   CONST(uint8, MATHSRV_CONST) kau8Cartography[],
   uint16 u16SiteInterpolation
)
{
   sint32 s32LocalInterpolation;
   uint32 u32LocalSite;
   uint32 u32LocalFirstValue;
   uint32 u32LocalResultValue;


   P2CONST(uint8, AUTOMATIC, MATHSRV_CONST) pku8LocalCartography;

   /* !Comment: MSB of u16SiteInterpolation is the index of the first point in   */
   /*           the map                                                          */
   u32LocalSite = u16SiteInterpolation;
   u32LocalSite = u32LocalSite >> 8;

   /* !Comment: use a local pointer for code optimisation                        */
   pku8LocalCartography = &kau8Cartography[u32LocalSite];

   /* !Comment: u32LocalFirstValue store the value of the first point in the map */
   u32LocalFirstValue = *pku8LocalCartography;

   /* !Comment: compute the delta between the two consecutive point in the map   */
   s32LocalInterpolation = (sint32)pku8LocalCartography[1]
                           - (sint32)u32LocalFirstValue;

   /* !Comment: multiply this delta with the percent of Site position LSB/256    */
   s32LocalInterpolation = s32LocalInterpolation
                           * (u16SiteInterpolation & 0x00FF);
   s32LocalInterpolation += 0x80;

   /* !Comment: scale the first point value to the result of the delta           */
   u32LocalFirstValue = u32LocalFirstValue << 8;

   /* !Comment: add the delta value to the first point value                     */
   /*            the result is always a value between the two point of the MAP:  */
   /*            so, it is always a positive value and fit in an uint16          */
   u32LocalResultValue = (uint32)( (sint32)u32LocalFirstValue
                                   + s32LocalInterpolation);

   /* !Comment: rescale the result wich is 256 time greater for the compute      */
   /*           accuracy                                                         */
   u32LocalResultValue = u32LocalResultValue >> 8;
   return( (uint8)u32LocalResultValue);
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u8Interp1d09Pts                                     */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_014.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d09Pts
(
   CONST(uint8, MATHSRV_CONST) kau8Cartography[9],
   uint8 u8Value
)
{
   uint16 u16LocalValue;


   u16LocalValue = (uint16)( (uint32)u8Value << 3);
   return(MATHSRV_u8Interp1d(kau8Cartography, u16LocalValue) );
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u8Interp1d11Pts                                     */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_014.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d11Pts
(
   CONST(uint8, MATHSRV_CONST) kau8Cartography[11],
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
   return(MATHSRV_u8Interp1d(kau8Cartography, u16LocalValue) );
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u8Interp1d17Pts                                     */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_014.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp1d17Pts
(
   CONST(uint8, MATHSRV_CONST) kau8Cartography[17],
   uint8 u8Value
)
{
   uint16 u16LocalValue;


   u16LocalValue = (uint16)( (uint32)u8Value << 4);
   return(MATHSRV_u8Interp1d(kau8Cartography, u16LocalValue) );
}


/******************************************************************************/
/* !FuncName    : MATHSRV_u8Interp2d                                          */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_022.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8Interp2d
(
   P2CONST(uint8, AUTOMATIC, MATHSRV_CONST) pkau8Cartography,
   uint16 u16SiteInterpolationXLine,
   uint16 u16SiteInterpolationYColumn,
   uint8 u8BreakpointNumberYColumn
)
{
   sint32 s32LocalLineIndex;
   sint32 s32LocalInterpolation;
   sint32 s32LocalSecondValue;
   uint32 u32LocalResultValue;
   uint8  u8LocalInterpolationXLine;
   uint8  u8LocalFirstValue;


   /* !Comment: Extract the line of the map pointed by u16SiteInterpolationXLine */
   s32LocalLineIndex = (sint32)(u16SiteInterpolationXLine >> 8);
   s32LocalLineIndex = s32LocalLineIndex * u8BreakpointNumberYColumn;
   pkau8Cartography  = &pkau8Cartography[s32LocalLineIndex];

   /* !Comment: do the interpolaiton in the first line                           */
   u8LocalFirstValue = MATHSRV_u8Interp1d(pkau8Cartography,
                                          u16SiteInterpolationYColumn);

   /* !Deviation: Violation of MISRA Rule 17.4. Reason : Length of lines is not  */
   /*             fixed so we cannot acces to the next line of the table by      */
   /*             indexation                                                     */
   pkau8Cartography = pkau8Cartography + u8BreakpointNumberYColumn;

   s32LocalSecondValue = (sint32)MATHSRV_u8Interp1d(pkau8Cartography,
                                                    u16SiteInterpolationYColumn);

   u8LocalInterpolationXLine = (uint8)(u16SiteInterpolationXLine & 0x00FF);
   s32LocalInterpolation     = s32LocalSecondValue - u8LocalFirstValue;
   s32LocalInterpolation     = s32LocalInterpolation
                               * u8LocalInterpolationXLine;
   s32LocalInterpolation = s32LocalInterpolation + 0x80;

   u32LocalResultValue = (uint32)u8LocalFirstValue << 8;
   u32LocalResultValue = (uint32)( (sint32)u32LocalResultValue
                                   + s32LocalInterpolation);
   u32LocalResultValue = u32LocalResultValue >> 8;
   return( (uint8)u32LocalResultValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/
