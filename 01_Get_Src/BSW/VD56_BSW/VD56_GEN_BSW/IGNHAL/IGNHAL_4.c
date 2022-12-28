/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_4.c                                              */
/* !Description     :                                                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:A30389.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "IGNHAL_co_Cfg.h"
#include "IGNHAL.h"
#include "IGNHAL_Def.h"
#include "IGNHAL_L.h"
#include "MATHSRV.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

#ifndef IGNHAL_coEXTERNAL_POWER_COILS
   #error The macro-constant IGNHAL_coEXTERNAL_POWER_COILS shall be defined
#endif

/******************************************************************************/
/* !FuncName    : IGNHAL_vidAdaptCoilCalc                                    */
/* !Description : Function to calculate the adaptation parameters            */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidAdaptCoilCalc(uint8 u8Coil)
{
   uint16 u16LocalInstantFactor;
   sint16 s16LocalInstantOffset;
   sint32 Temp_s4;
   uint32 Local_uw_1;
   uint32 Local_uw_2;
   uint16 Local_uw_3;
   uint16 Local_uw_4;
   uint32 Local_uw_6;
   uint32 M2C_uint32_3;
   uint32 M2C_uint32_4;
   sint32 M2C_sint32_5;


   #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
   if (IGNHAL_kbEnableExtPowerCoils == FALSE)
   {
   #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
   if (IgnHALMode != IGN_HAL_MODE_TEST)
   {
      Local_uw_1 = IGNHAL_u32TimeSlope1[u8Coil];
      /* convert to 3.2us resolution from 100ns */
      Local_uw_1 = (Local_uw_1 * IGNHAL_DESIRED_RESOL_COEF) \
                   / IGNHAL_INTERP_RESOL_COEF;

      Local_uw_2 = IGNHAL_u32TimeSlope2[u8Coil];
      /* convert to 3.2us resolution from 100ns */
      Local_uw_2 = (Local_uw_2 * IGNHAL_DESIRED_RESOL_COEF) \
                   / IGNHAL_INTERP_RESOL_COEF;

      Local_uw_3 = IGNHAL_u16VoltageSlope1[u8Coil];
      Local_uw_4 = IGNHAL_u16VoltageSlope2[u8Coil];

      if (  (  ( (IGNHAL_bSlopeAcqValid[u8Coil]) != (boolean)FALSE)
            && ( (IGNHAL_bSCDefaultFlag[u8Coil]) == (boolean)FALSE) )
         && ( (IGNHAL_bOCDefaultFlag[u8Coil]) == (boolean)FALSE) )
      {
         Temp_s4 = ( (sint32)Local_uw_4) - ( (sint32)Local_uw_3);
         if (Temp_s4 < 0)
         {
            Temp_s4 = 0;
         }
         u16LocalInstantFactor = (uint16)Temp_s4;  /* V2 - V1 */

         Temp_s4 = ( (sint32)Local_uw_2) - ( (sint32)Local_uw_1);
         if (Temp_s4 < 0)
         {
            Temp_s4 = 0;
         }
         Local_uw_6 = (uint32)Temp_s4;          /* T2 - T1 */

         if (u16LocalInstantFactor != (uint16)UINT16_MIN)
         {
            M2C_uint32_3 = ( (uint32)u16LocalInstantFactor)
                           + ( ( (uint32)Local_uw_6) * 512u);
            M2C_uint32_4 = ( (uint32)u16LocalInstantFactor) * 2u;

            if ( (M2C_uint32_3 >> 16) >= M2C_uint32_4)
            {
               M2C_uint32_3 = 65535u;
            }
            else
            {
               M2C_uint32_3 = M2C_uint32_3 / M2C_uint32_4;
            }
            u16LocalInstantFactor = (uint16)MATHSRV_udtMIN(MATHSRV_udtMAX(
                                                              (sint32)( (uint16)M2C_uint32_3),
                                                              (sint32)Icd_adapt_factor_twin_phys_min),
                                                           (sint32)Icd_adapt_factor_twin_phys_max);
         }
         else
         {
            u16LocalInstantFactor = Icd_adapt_factor_twin_phys_max;
         }
         Temp_s4 = 8 * ( ( ( (sint32)Local_uw_3) * ( (sint32)Local_uw_2) )
                         - ( ( (sint32)Local_uw_4) * ( (sint32)Local_uw_1) ) );

         if (Local_uw_6 != (uint16)UINT16_MIN)
         {
            Temp_s4      = ( (sint32)(Local_uw_6 >> 1) + Temp_s4) / (sint16)Local_uw_6;
            M2C_sint32_5 = Temp_s4;
            if (M2C_sint32_5 < -32768)
            {
               M2C_sint32_5 = -32768;
            }
            else
            {
               if (M2C_sint32_5 > 32767)
               {
                  M2C_sint32_5 = 32767;
               }
            }
            s16LocalInstantOffset = (sint16)M2C_sint32_5;
         }
         else
         {
            if (Temp_s4 >= 0)
            {
               s16LocalInstantOffset = SINT16_MAX;
            }
            else
            {
               s16LocalInstantOffset = SINT16_MIN;
            }
         }
         IGNHAL_u16AdaptFactor[u8Coil] = MATHSRV_u16SlewFilter(
            IGNHAL_u16AdaptFactor[u8Coil], u16LocalInstantFactor,
            Icd_adapt_factor_twin_phys_step,
            Icd_adapt_factor_twin_phys_step);
         IGNHAL_s16AdaptOffset[u8Coil] = MATHSRV_s16SlewFilter(
            IGNHAL_s16AdaptOffset[u8Coil], s16LocalInstantOffset,
            Icd_adapt_offset_twin_phys_step,
            Icd_adapt_offset_twin_phys_step);

         if (  ( ( (IGNHAL_u16AdaptFactor[u8Coil]) - u16LocalInstantFactor) \
                 == (uint16)UINT16_MIN)
            && ( ( (uint16)( (IGNHAL_s16AdaptOffset[u8Coil]) \
                             - s16LocalInstantOffset) ) == (uint16)UINT16_MIN) )
         {
            IGNHAL_bAdaptCalcValid[u8Coil] = (boolean)TRUE;
         }
      }
   }
   #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
}
   #endif
}

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
