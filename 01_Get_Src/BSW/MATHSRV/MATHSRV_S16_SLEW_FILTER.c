/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_S16_SLEW_FILTER.c                               */
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
 * %PID: LIBEMB:MATHSRV S16 SLEW FILTER C-99055195X4420X372.A-SRC;1.2 %
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
/* !FuncName    : MATHSRV_s16SlewFilter                                       */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    :  VEMS_R_08_02127_109                                        */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE) MATHSRV_s16SlewFilter
(
   sint16 s16FilteredValue,
   sint16 s16MeasuredValue,
   uint16 u16MaxIncrementValue,
   uint16 u16MaxDecrementValue
)
{
   sint32 s32LocalLimitOutputValue;


   if (s16FilteredValue <= s16MeasuredValue)
   {
      s32LocalLimitOutputValue = (sint32)s16FilteredValue
                                 + u16MaxIncrementValue;
      if (s32LocalLimitOutputValue <= s16MeasuredValue)
      {
         s16MeasuredValue = (sint16)s32LocalLimitOutputValue;
      }
   }
   else
   {
      s32LocalLimitOutputValue = (sint32)s16FilteredValue
                                 - u16MaxDecrementValue;
      if (s32LocalLimitOutputValue >= s16MeasuredValue)
      {
         s16MeasuredValue = (sint16)s32LocalLimitOutputValue;
      }
   }
   return(s16MeasuredValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
