/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_SCHMITT_TRIGGER.c                               */
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
 * %PID: LIBEMB:MATHSRV SCHMITT TRIGGER C-99055195X4420X380.A-SRC;1.3 %
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
/* !FuncName    : MATHSRV_vidSchmittTriggerU16                                */
/* !Description : Compare u16InputValue to the correct threshold depending of */
/*                the type of trigger running (rising or falling trigger) and */
/*                saturate *u8OutputValue according to the result of the      */
/*                comparison.                                                 */
/*                                                                            */
/* !TraceTo     : VEMS_R_08_02127_011.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Perochon                                                 */
/******************************************************************************/
FUNC(void, MATHSRV_CODE) MATHSRV_vidSchmittTriggerU16
(
   uint16 u16InputValue,
   uint16 u16HysteresisLowThreshold,
   uint16 u16HysteresisHighTreshold,
   MATHSRV_tenuSchmittTriggerType tenuSchmittTriggerType,
   P2VAR(uint8, AUTOMATIC, MATHSRV_VAR)   u8OutputValue
)
{
   if (u16InputValue > u16HysteresisHighTreshold)
   {
      /* !TraceTo : VEMS_R_08_02127_010.01                                    */
      if (tenuSchmittTriggerType == MATHSRV_RISING_SCHMITT_TRIGGER)
      {
         *u8OutputValue = 1;
      }
      else
      {
         *u8OutputValue = 0;
      }
   }
   else
   {
      /* !TraceTo : VEMS_R_08_02127_009.01                                    */
      if (u16InputValue <= u16HysteresisLowThreshold)
      {
         if (tenuSchmittTriggerType == MATHSRV_RISING_SCHMITT_TRIGGER)
         {
            *u8OutputValue = 0;
         }
         else
         {
            *u8OutputValue = 1;
         }
      }
   }
}


#define MATHSRV_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
