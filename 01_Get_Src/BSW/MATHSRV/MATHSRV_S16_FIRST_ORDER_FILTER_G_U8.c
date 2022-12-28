/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_S16_FIRST_ORDER_FILTER_G_U8.c                   */
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
 * %PID: LIBEMB:MATHSRV S16 FIRST ORDER FILTER G U8 C-99055195X4420X368.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "STD_Types.h"
#include "MATHSRV.h"
#include "Std_Limits.h"


#define MATHSRV_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* !FuncName    : MATHSRV_s16FirstOrderFilterGu8                              */
/* !Description : First Order filter for SINT16 signal, with gain of UINT8    */
/*                type.                                                       */
/*                                                                            */
/* !Trace_To    :  VEMS_R_08_02127_106                                        */
/*                                                                            */
/* !LastAuthor  : M.Mohi                                                      */
/******************************************************************************/
FUNC(sint16, MATHSRV_CODE) MATHSRV_s16FirstOrderFilterGu8
(
   uint8 u8FilterGain,
   P2VAR(sint32, AUTOMATIC, MATHSRV_VAR) ps32AccuracyFilterValue,
   sint16 s16MeasuredValue
)
{
   sint32 s32LocalAccuracyNewFilterValue;
   uint32 u32LocalPreviousFilterValue;
   uint32 u32LocalNewFilterValue;
   uint16 u16MeasuredValueScalled;
   uint32 u32LocalAccuracyFilterValue;


   /* For uint8 gain, the accuracy value is 256 time greater than the Measured*/
   /* Value                                                                   */
   u32LocalAccuracyFilterValue = (uint32)(*ps32AccuracyFilterValue
                                          + (-SINT16_MIN * 256) );
   u16MeasuredValueScalled = (uint16)( (sint32)s16MeasuredValue + (-SINT16_MIN) );

   u32LocalPreviousFilterValue = u32LocalAccuracyFilterValue + 127;
   u32LocalPreviousFilterValue = u32LocalPreviousFilterValue >> 8;

   s32LocalAccuracyNewFilterValue = (sint32)u16MeasuredValueScalled
                                    - (sint32)u32LocalPreviousFilterValue;
   s32LocalAccuracyNewFilterValue = u8FilterGain
                                    * s32LocalAccuracyNewFilterValue;
   s32LocalAccuracyNewFilterValue = (sint32)(u32LocalAccuracyFilterValue)
                                    + s32LocalAccuracyNewFilterValue;

   u32LocalAccuracyFilterValue =
      ( (s32LocalAccuracyNewFilterValue > 0)
        ? ( (uint32)(s32LocalAccuracyNewFilterValue) )
        : 0
      );
   u32LocalNewFilterValue = u32LocalAccuracyFilterValue + 127;
   u32LocalNewFilterValue = u32LocalNewFilterValue >> 8;

   *ps32AccuracyFilterValue = (sint32)(u32LocalAccuracyFilterValue
                                       + (SINT16_MIN * 256) );
   /*QAC(4:0273), The underflow is intended to convert the unsigned
      to signed values, and no overflow can occurs
      because the maximum value of u32LocalAccuracyFilterValue
      is (UINT16_MAX + .5) * 256), and the result will be
      ((SINT16_MAX + .5 ) * 256)  and it is much smaller than SINT32_MAX */

   return( (sint16)( ( (uint16)u32LocalNewFilterValue) + SINT16_MIN) );
   /*QAC(3892) : due to cast type is implicitly converted to another type,
                 and it is safe.                                          */
}

#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
