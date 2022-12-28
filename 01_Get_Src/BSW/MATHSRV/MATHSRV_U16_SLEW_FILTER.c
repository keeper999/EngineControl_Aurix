/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_U16_SLEW_FILTER.c                               */
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
 * %PID: LIBEMB:MATHSRV U16 SLEW FILTER C-99055196X4420X392.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_u16SlewFilter                                       */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_043.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16SlewFilter
(
   uint16 u16FilteredValue,
   uint16 u16MeasuredValue,
   uint16 u16MaxIncrementValue,
   uint16 u16MaxDecrementValue
)
{
   sint32 s32LocalLimitOutputValue;


   if (u16FilteredValue <= u16MeasuredValue)
   {
      s32LocalLimitOutputValue = u16FilteredValue + u16MaxIncrementValue;
      if (s32LocalLimitOutputValue <= u16MeasuredValue)
      {
         u16MeasuredValue = (uint16)s32LocalLimitOutputValue;
      }
   }
   else
   {
      s32LocalLimitOutputValue = u16FilteredValue - u16MaxDecrementValue;
      if (s32LocalLimitOutputValue >= u16MeasuredValue)
      {
         u16MeasuredValue = (uint16)s32LocalLimitOutputValue;
      }
   }
   return(u16MeasuredValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
