/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_U16_FIRST_ORDER_FILTER_G_U8.c                   */
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
 * %PID: LIBEMB:MATHSRV U16 FIRST ORDER FILTER G U8 C-99055196X4420X390.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_u16FirstOrderFilterGu8                              */
/* !Description : First order filter executed on a uint16 value with an       */
/*                uint8 gain.                                                 */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_040.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16FirstOrderFilterGu8
(
   uint8 u8FilterGain,
   P2VAR(uint32, AUTOMATIC, MATHSRV_VAR) pu32AccuracyFilterValue,
   uint16 u16MeasuredValue
)
{
   sint32 s32LocalAccuracyNewFilterValue;
   uint32 u32LocalPreviousFilterValue;
   uint32 u32LocalNewFilterValue;


   u32LocalPreviousFilterValue = *pu32AccuracyFilterValue + 127;
   u32LocalPreviousFilterValue = u32LocalPreviousFilterValue >> 8;

   s32LocalAccuracyNewFilterValue = (sint32)u16MeasuredValue
                                    - (sint32)u32LocalPreviousFilterValue;
   s32LocalAccuracyNewFilterValue = u8FilterGain
                                    * s32LocalAccuracyNewFilterValue;
   s32LocalAccuracyNewFilterValue = (sint32)(*pu32AccuracyFilterValue)
                                    + s32LocalAccuracyNewFilterValue;

   *pu32AccuracyFilterValue = ( (s32LocalAccuracyNewFilterValue > 0)
                                ? ( (uint32)(s32LocalAccuracyNewFilterValue) )
                                : 0
                              );
   u32LocalNewFilterValue = *pu32AccuracyFilterValue + 127;
   u32LocalNewFilterValue = u32LocalNewFilterValue >> 8;
   return( (uint16)u32LocalNewFilterValue);
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
