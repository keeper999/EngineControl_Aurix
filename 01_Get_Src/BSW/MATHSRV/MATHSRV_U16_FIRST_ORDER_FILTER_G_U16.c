/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_U16_FIRST_ORDER_FILTER_G_U16.c                  */
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
 * %PID: LIBEMB:MATHSRV U16 FIRST ORDER FILTER G U16 C-99055196X4420X388.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "MATHSRV.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define MATHSRV_START_SEC_CODE
#include "MATHSRV_MemMap.h"

/******************************************************************************/
/* !FuncName    : MATHSRV_u16FirstOrderFilterGu16                             */
/* !Description : First order filter executed on a uint16 value with an       */
/*                uint16 gain.                                                */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_037.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16FirstOrderFilterGu16
(
   uint16 u16FilterGain,
   P2VAR(uint32, AUTOMATIC, MATHSRV_VAR) pu32AccuracyFilterValue,
   uint16 u16MeasuredValue
)
{
   uint32 u32LocalPreviousFilterValue;
   uint32 u32LocalNewFilterValue;
   uint32 u32LocalAccuracyNewFilterValue;
   uint16 u16LocalNewFilterValue;


   u32LocalPreviousFilterValue = *pu32AccuracyFilterValue + 32767;
   u32LocalPreviousFilterValue = u32LocalPreviousFilterValue >> 16;

   if (u16MeasuredValue >= u32LocalPreviousFilterValue)
   {
      u32LocalAccuracyNewFilterValue = u16MeasuredValue
                                       - u32LocalPreviousFilterValue;
      u32LocalAccuracyNewFilterValue = u16FilterGain
                                       * u32LocalAccuracyNewFilterValue;
      *pu32AccuracyFilterValue = *pu32AccuracyFilterValue
                                 + u32LocalAccuracyNewFilterValue;

      u32LocalNewFilterValue = *pu32AccuracyFilterValue + 32767;
      u16LocalNewFilterValue = (uint16)(u32LocalNewFilterValue >> 16);
   }
   else
   {
      u32LocalAccuracyNewFilterValue = u32LocalPreviousFilterValue
                                       - u16MeasuredValue;
      u32LocalAccuracyNewFilterValue = u16FilterGain
                                       * u32LocalAccuracyNewFilterValue;

      *pu32AccuracyFilterValue =
         (
            (u32LocalAccuracyNewFilterValue < *pu32AccuracyFilterValue)
            ? (*pu32AccuracyFilterValue - u32LocalAccuracyNewFilterValue)
            : 0
         );
      u32LocalNewFilterValue = *pu32AccuracyFilterValue + 32767;
      u16LocalNewFilterValue = (uint16)(u32LocalNewFilterValue >> 16);
   }

   return(u16LocalNewFilterValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MATHSRV_MemMap.h"


/*------------------------------- end of file --------------------------------*/
