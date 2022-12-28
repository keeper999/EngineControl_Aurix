/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_S16_FIRST_ORDER_FILTER_G_U16.c                  */
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
 * %PID: LIBEMB:MATHSRV S16 FIRST ORDER FILTER G U16 C-99055194X4420X364.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "MATHSRV.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* !FuncName    : MATHSRV_s16FirstOrderFilterGu16                             */
/* !Description : First Order filter for SINT16 signal, with gain of UINT16   */
/*                type.                                                       */
/*                                                                            */
/* !Trace_To    :  VEMS_R_08_02127_103                                        */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE) MATHSRV_s16FirstOrderFilterGu16
(
   uint16 u16FilterGain,
   P2VAR(sint32, AUTOMATIC, MATHSRV_VAR) ps32AccuracyFilterValue,
   sint16 s16MeasuredValue
)
{
   uint32 u32LocalPreviousFilterValue;
   uint32 u32LocalNewFilterValue;
   uint32 u32LocalAccuracyNewFilterValue;
   uint16 u16LocalNewFilterValue;
   uint16 u16LocalMeasuredValueScalled;
   uint32 u32LocalAccuracyFilterValue;


   /*For uint16 gain, the accuracy value is 65536 time greater than the       */
   /*Measured Value ,    SINT32_MIN = (SINT16_MIN * 65536)                    */
   u32LocalAccuracyFilterValue = (uint32)(*ps32AccuracyFilterValue
                                          - SINT32_MIN);
   /* QAC warning 278: adding -SINT32_MIN to have all values in UINT32 range  */
   u16LocalMeasuredValueScalled = (uint16)( (sint32)s16MeasuredValue
                                            + (-SINT16_MIN) );

   u32LocalPreviousFilterValue = u32LocalAccuracyFilterValue + 32767;
   u32LocalPreviousFilterValue = u32LocalPreviousFilterValue >> 16;

   if (u16LocalMeasuredValueScalled >= u32LocalPreviousFilterValue)
   {
      u32LocalAccuracyNewFilterValue = u16LocalMeasuredValueScalled
                                       - u32LocalPreviousFilterValue;
      u32LocalAccuracyNewFilterValue = u16FilterGain
                                       * u32LocalAccuracyNewFilterValue;
      u32LocalAccuracyFilterValue = u32LocalAccuracyFilterValue
                                    + u32LocalAccuracyNewFilterValue;
   }
   else
   {
      u32LocalAccuracyNewFilterValue = u32LocalPreviousFilterValue
                                       - u16LocalMeasuredValueScalled;
      u32LocalAccuracyNewFilterValue = u16FilterGain
                                       * u32LocalAccuracyNewFilterValue;

      u32LocalAccuracyFilterValue =
         (
            (u32LocalAccuracyNewFilterValue < u32LocalAccuracyFilterValue)
            ? (u32LocalAccuracyFilterValue - u32LocalAccuracyNewFilterValue)
            : 0
         );
   }
   u32LocalNewFilterValue = u32LocalAccuracyFilterValue + 32767;
   u16LocalNewFilterValue = (uint16)(u32LocalNewFilterValue >> 16);

   *ps32AccuracyFilterValue = (sint32)(u32LocalAccuracyFilterValue
                                       + SINT32_MIN);
   /*QAC(4:0272),  The underflow is intended to convert the unsigned
      values < SINT32_MAX to signed values, and no overflow can occurs
      because UINT32_MAX will be   SINT32_MAX      */

   return( (sint16)(u16LocalNewFilterValue - (-SINT16_MIN) ) );

}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
