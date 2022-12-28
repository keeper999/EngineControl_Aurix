/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_MEDIAN_FILTER.c                                 */
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
 * %PID: LIBEMB:MATHSRV MEDIAN FILTER C-99055193X4420X344.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_u16MedianFilter                                     */
/* !Description : Return the parameter whose value lies between the two other */
/*                                                                            */
/* !Trace_To    : VEMS_R_08_02127_036.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(uint16, MATHSRV_CODE) MATHSRV_u16MedianFilter
(
   uint16 u16Value1,
   uint16 u16Value2,
   uint16 u16Value3
)
{
   if (u16Value2 > u16Value1)
   {
      if (u16Value3 > u16Value2)
      {
         return(u16Value2);
      }
      if (u16Value3 > u16Value1)
      {
         return(u16Value3);
      }
      return(u16Value1);
   }
   if (u16Value3 > u16Value1)
   {
      return(u16Value1);
   }
   if (u16Value3 > u16Value2)
   {
      return(u16Value3);
   }
   return(u16Value2);
   /* !Deviation: Violation of MISRA Rule 14.7. Reason : Optimisation, this      */
   /*             function is used a lot of time                                 */
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
