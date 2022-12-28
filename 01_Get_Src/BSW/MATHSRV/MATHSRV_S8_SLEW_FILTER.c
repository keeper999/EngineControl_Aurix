/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_S8_SLEW_FILTER.c                                */
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
 * %PID: LIBEMB:MATHSRV S8 SLEW FILTER C-99055195X4420X376.A-SRC;1.2 %
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
/* !FuncName    : MATHSRV_s8SlewFilter                                        */
/* !Description :                                                             */
/*                                                                            */
/* !Trace_To    :  VEMS_R_08_02127_110                                        */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint8, MATHSRV_CODE) MATHSRV_s8SlewFilter
(
   sint8 s8FilteredValue,
   sint8 s8MeasuredValue,
   uint8 u8MaxIncrementValue,
   uint8 u8MaxDecrementValue
)
{
   sint16_least s16LocalLimitOutputValue;


   if (s8FilteredValue <= s8MeasuredValue)
   {
      s16LocalLimitOutputValue = (sint16)(s8FilteredValue
                                          + u8MaxIncrementValue);
      if (s16LocalLimitOutputValue <= s8MeasuredValue)
      {
         s8MeasuredValue = (sint8)s16LocalLimitOutputValue;
      }
   }
   else
   {
      s16LocalLimitOutputValue = (sint16)(s8FilteredValue
                                          - u8MaxDecrementValue);
      if (s16LocalLimitOutputValue >= s8MeasuredValue)
      {
         s8MeasuredValue = (sint8)s16LocalLimitOutputValue;
      }
   }
   return(s8MeasuredValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
