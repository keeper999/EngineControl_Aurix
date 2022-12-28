/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_U8_SLEW_FILTER.c                                */
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
 * %PID: LIBEMB:MATHSRV U8 SLEW FILTER C-99055196X4420X394.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_u8SlewFilter                                        */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_044.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint8, MATHSRV_CODE) MATHSRV_u8SlewFilter
(
   uint8 u8FilteredValue,
   uint8 u8MeasuredValue,
   uint8 u8MaxIncrementValue,
   uint8 u8MaxDecrementValue
)
{
   sint32 s32LocalLimitOutputValue;


   if (u8FilteredValue <= u8MeasuredValue)
   {
      s32LocalLimitOutputValue = u8FilteredValue + u8MaxIncrementValue;
      if (s32LocalLimitOutputValue <= u8MeasuredValue)
      {
         u8MeasuredValue = (uint8)s32LocalLimitOutputValue;
      }
   }
   else
   {
      s32LocalLimitOutputValue = u8FilteredValue - u8MaxDecrementValue;
      if (s32LocalLimitOutputValue >= u8MeasuredValue)
      {
         u8MeasuredValue = (uint8)s32LocalLimitOutputValue;
      }
   }
   return(u8MeasuredValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
