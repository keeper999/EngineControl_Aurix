/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TBU_DPLL                                                */
/* !Description     : TBU & DPLL Component                                    */
/*                                                                            */
/* !File            : IfxGtm_Tbu_Dpll.c                                       */
/* !Description     : Definition of data of Tbu & Dpll Component              */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/******************************************************************************/
/* VERSION   : v.0.1          DATE : Oct 18 2013                         */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A18536.A-SRC;6 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"

#include "IfxGtm_Def.h"
#include "CRKHAL_L.h"
#include "IfxGtm_Tbu_dpll.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
/** \addtogroup CRAKHAL
 * \{ */

/******************************************************************************/
/*                          Typedefs                                          */
/******************************************************************************/


/******************************************************************************/
/*                          Enums                                             */
/******************************************************************************/


/******************************************************************************/
/*                           Struct                                           */
/******************************************************************************/


/******************************************************************************/
/*                           Variables                                        */
/******************************************************************************/


/******************************************************************************/
/*                           Function prototypes                              */
/******************************************************************************/

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTbusDisable                                       */
/* !Description :                                                             */
/*                                                                            */
/******************************************************************************/
/* void IfxGtm_vidTbusDisable(void)
{
   if ((3U) == GTM_TBU_CHEN.B.ENDIS_CH0)
   {
      GTM_TBU_CHEN.B.ENDIS_CH0 = (1U);
   }

   if ((3U) == GTM_TBU_CHEN.B.ENDIS_CH1)
   {
      GTM_TBU_CHEN.B.ENDIS_CH1 = (1U);
      IFX_GTM_SET_BITFIELD(GTM_TBU_CHEN.U, IFX_GTM_TBU_CHEN_ENDIS_CH1_OFF, 0x1U);
   }
} */

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTbuReEnable                                       */
/* !Description : TBU Re Enable if it is disabled. This function enables both */
/*                Timer & Angular counters                                    */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTbuReEnable(void)
{
   if ((0U) == GTM_TBU_CHEN.B.ENDIS_CH0)
   {
      vidENABLE_TBU_TMR_CNTR();
   }

   if ((0U) == GTM_TBU_CHEN.B.ENDIS_CH1)
   {
      vidENABLE_TBU_ANG_CNTR();
   }
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTbuEnable                                         */
/* !Description :                                                             */
/*                                                                            */
/******************************************************************************/
/* void IfxGtm_vidTbuEnable(void)
{
   GTM_TBU_CHEN.U = (uint32)(0x00000005U);

    GTM_TBU_CH1_CTRL.U  = (0x00000001U);

    GTM_TBU_CHEN.U = (uint32)(0x0000000AU);
} */

/******************************************************************************/
/* !FuncName    : IfxGtm_vidDpllConfig                                        */
/* !Description : Configures DPLL - This function is used for Crank & Cam     */
/*                                                                            */
/******************************************************************************/

void IfxGtm_vidDpllConfig(uint8  u8TriggerN,
                          uint8  u8StateN,
                          uint16 u16MicrotickMlt,
                          uint8  u8GapHalfScale)
{

   unsigned int ram_ini_v = UINT32_MIN;
   /* initialise RAM; */
   /* make sure that no RAM initialisation takes place in parallel */
   ram_ini_v = IFX_GTM_READ_REG_BITFIELD(GTM_DPLL_RAM_INI.U,
                  IFX_GTM_DPLL_RAM_INI_INIT_RAM_RD_MSK_BIT);
   while (ram_ini_v != (boolean)FALSE)
   { /* we have to wait until RAM initialisation ends */
      ram_ini_v = IFX_GTM_READ_REG_BITFIELD(GTM_DPLL_RAM_INI.U,
                     IFX_GTM_DPLL_RAM_INI_INIT_RAM_RD_MSK_BIT);
   }

    /* DPLL CTRL_0 Register configurations */
    /* TEN = 1 | SEN = 1 | IFP=0 | TNU = triggerN | SNU = PHS_DPLL_SNU | MLT = EP_DPLL_MLT  */

   GTM_DPLL_CTRL_0.U = (uint32) (DPLL_CTRL_0_SET
                              | (  (u8TriggerN & IFX_GTM_DPLL_CTRL_0_TNU_MSK)
                                << IFX_GTM_DPLL_CTRL_0_TNU_OFF)
                              | (  (u8StateN & IFX_GTM_DPLL_CTRL_0_SNU_MSK)
                                << IFX_GTM_DPLL_CTRL_0_SNU_OFF)
                              | (  ( (u16MicrotickMlt - 1U)
                                   & IFX_GTM_DPLL_CTRL_0_MLT_MSK)
                                << IFX_GTM_DPLL_CTRL_0_MLT_OFF));

   /*     DPLL CTRL_1 Register configurations*/
   GTM_SET_DPLL_CTRL_1(u8GapHalfScale);

    /* todo - CAMHAL implementation need to change this variable       */
    /* CRKHAL_udtFALLING_EDGE to change constant calibration variable. */

   GTM_DPLL_MLS1.U = (uint32) (0x0U); /* number of pulses between two state events */
   /* Update RAM size,256 entries */
   /* GTM_DPLL_OSW.B.OSS = DPLL_RAM_OFFSET; */
   IFX_GTM_WRITE_REG(GTM_DPLL_OSW.U,
                     IFX_GTM_DPLL_OSW_OSS_WR_MSK_BIT,
                     IFX_GTM_DPLL_OSW_OSS_OFF, DPLL_RAM_OFFSET);

   GTM_DPLL_NTI_CNT.U  = (uint32)(0x0U);
   GTM_DPLL_MPVAL1.U   = (uint32)(0x0U);
   GTM_DPLL_PVT.U      = (uint32) CRKHAL_PVT_VAL;  /* Plausability_val      */
   /* TS_T_Check TOV value  */
   CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);

   CRKHAL_vidSET_TRIGGER_HOLD_TIME(0);

   GTM_DPLL_THMA.U     = (uint32) CRKHAL_THMA_VAL; /* Trigger Hold Time max */
   GTM_DPLL_TLR.U      = (uint32) (0x0U);          /* Disable TLR Check     */

   /* GTM_DPLL_IRQ_MODE.B.IRQ_MODE = IfxGtm_IrqMode_PulseNotifyMode; */
   GTM_DPLL_IRQ_MODE.U = IfxGtm_IrqMode_PulseNotifyMode;
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidCrankProfileInit                                  */
/* !Description : Configures Crank Profile as per configuration               */
/*                                                                            */
/******************************************************************************/

void IfxGtm_vidCrankProfileInit(void)
{
   uint8 LocalCount          = (uint8)UINT8_MIN;
   uint8 LocalNoCycle        = (uint8)UINT8_MIN;
   uint8 LocalRelTeethOffset = (uint8)UINT8_MIN;

   /* Configuration for - Rotation */
   for (LocalNoCycle = (uint8)UINT8_MIN;
        LocalNoCycle < CRKHAL_udtNUM_CYCLE;
        LocalNoCycle ++)
   {
      /* NormalTeeth (NT = 1) value from 0 - 54th Teeth */
      /* Load Normal teeth value from teeth 58 to 112 */
      for (LocalCount = LocalRelTeethOffset;
           LocalCount < ( (CRKHAL_ku16NbPhysTeeth - 3U)
                        + LocalRelTeethOffset);
           LocalCount ++)
      {
         CRKHAL_ADT_Tx[LocalCount] = CRKHAL_NORMAL_TOOTH_LEN;
      }
      /* NormalTeeth + TE0I set = for 55, 113 Teeth */
      CRKHAL_ADT_Tx[(CRKHAL_ku16NbPhysTeeth - 3U) + LocalRelTeethOffset] =
         (CRKHAL_NORMAL_TOOTH_LEN | CRKHAL_TE0I_ENABLE); /* TE0_IRQ */
      /* NormalTeeth + TE1I set = check value for 56, 114 Teeth */
      CRKHAL_ADT_Tx[(CRKHAL_ku16NbPhysTeeth - 2U) + LocalRelTeethOffset] =
         (CRKHAL_NORMAL_TOOTH_LEN);
      /* 3Teeth + TE2I set = check value for 57, 115 Teeth */
      CRKHAL_ADT_Tx[(CRKHAL_ku16NbPhysTeeth - 1U) + LocalRelTeethOffset] =
         (CRKHAL_GAP_TOOTH_LEN);
      /* for 2nd Rotation */
      LocalRelTeethOffset = CRKHAL_ku16NbPhysTeeth;
   }
   /* TE2_IRQ=> update offset */
   CRKHAL_ADT_Tx[CRKHAL_TE2] = (CRKHAL_NORMAL_TOOTH_LEN | CRKHAL_TE2I_ENABLE);
   /* Synchro Check - FIRST */
   CRKHAL_ADT_Tx[CRKHAL_TE1_FIRST] = ( CRKHAL_NORMAL_TOOTH_LEN
                                     | CRKHAL_TE1I_ENABLE);
   /* Synchro Check - LAST */
   CRKHAL_ADT_Tx[(CRKHAL_ku16NbPhysTeeth + 2U)] = ( CRKHAL_NORMAL_TOOTH_LEN
                                                  | CRKHAL_TE1I_ENABLE);
}
/******************************************************************************/
/* !FuncName    : IfxGtm_u32TbuConvAbsToRelAng                                */
/* !Description : This function convert absolute to relative angle            */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32TbuConvAbsToRelAng(uint32 u32absAngle)
{
   /*Current Angle Value [0..0x00FFFFFF] */
   uint32 u32LocalCurrentAngRel;
   uint32 u32RelAngOffset;
   uint32 u32LocalAngle;
   uint32 u32MatchAngRel;
   uint32 u32RotCorrectionFactor;

   u32LocalCurrentAngRel = (uint32)GTM_TBU_ANGLE;

   /* get the rotation offset store @ every 720 degrees */
   u32RelAngOffset = CRKHAL_u32GlobalTeethOffset;

   /*Convert from [0..720] to [0..0xFFFFFF] */
   u32LocalAngle = (uint32)(u32absAngle + CRKHAL_u32NumberOfMlt_Tdc);
   if (u32LocalAngle >= CRKHAL_u16EngineCycleAngle)
   {
      u32LocalAngle -= CRKHAL_u16EngineCycleAngle;
   }
   u32MatchAngRel = (uint32)((u32RelAngOffset + u32LocalAngle) & 0x00FFFFFFu);
   u32RotCorrectionFactor = (uint32)IfxGtm_u16TbuCompRelAngles(
                                       u32MatchAngRel,
                                       u32LocalCurrentAngRel,
                                       CRKHAL_u16ENGINE_CYCLE);

   /* Check if the relAngOffset is correct */
   u32MatchAngRel = (u32MatchAngRel + u32RotCorrectionFactor) & 0x00FFFFFFu;

   return (u32MatchAngRel);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u16TbuCompRelAngles                                  */
/* !Description : This function compares the relative angles                  */
/*                                                                            */
/******************************************************************************/
uint16 IfxGtm_u16TbuCompRelAngles(uint32 u32AlarmStartRel,
                                  uint32 u32CurrAngle,
                                  uint32 u32TotalTicksRotation)
{
   uint32 u32LocalDiff = (uint32)UINT32_MIN;
   if (u32AlarmStartRel > u32CurrAngle)
   {
      u32LocalDiff = u32AlarmStartRel - u32CurrAngle;
      if (u32LocalDiff <= 0x7FFFFFu)
      {
         return ((uint16)UINT16_MIN);
      }
      else
      {
         /*Number of ticks generated in 720 degrees (i.e. 384*120=30720)*/
         return ((uint16)u32TotalTicksRotation);
      }
   }
   else
   {
      u32LocalDiff = (u32CurrAngle - u32AlarmStartRel);
      if (u32LocalDiff > 0x7FFFFFu)
      {
         return ((uint16)UINT16_MIN);
      }
      else
      {
         return ((uint16)u32TotalTicksRotation);
      }
   }
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u32TbuRelToAbsCorrectionFactor                       */
/* !Description : This function update correction factor for Relative to      */
/*				  Absolute angle value 										  */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32TbuRelToAbsCorrectionFactor(void)
{
   uint32 u32LocalCorrectionfactor;
   uint32 u32LocalValue;

    u32LocalValue = GTM_TBU_Angle.U - CRKHAL_u32GlobalTeethOffset;

   if (u32LocalValue < CRKHAL_u32NumberOfMlt_Tdc)
   {
      u32LocalCorrectionfactor = CRKHAL_u32NumberOfMlt_Full;
   }
   else
   {
      u32LocalCorrectionfactor = (uint32)UINT32_MIN;
   }
   return (u32LocalCorrectionfactor);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u32TbuRelToAbsCorrectionFactor                       */
/* !Description : This function convert relative to absolute angle            */
/*                                                                            */
/******************************************************************************/
/* u32relAngle --> TBU angle or TBU Data
 * angleOffet  --> To take care of TDC offset in micro ticks
 * u32CurrRotationOffset --> global teeth offset
 */
uint16 IfxGtm_u16TbuConvRelToAbsAng(uint32 u32relAngle)
{
   uint32 u32LocalTempAbs;
   sint32 s32LocalDiff;

   if(CRKHAL_bRotationDirection == CRKHAL_bFWD_ROTATION)
   {
	   u32LocalTempAbs = (uint32)(((u32relAngle
                      - CRKHAL_u32GlobalTeethOffset) & GTM_TBU_TIMER_MAX_LIMIT));
	   s32LocalDiff = (sint32) (u32relAngle - CRKHAL_u32GlobalTeethOffset);

	   if (s32LocalDiff < (sint32)UINT32_MIN)
	   {
	      u32LocalTempAbs = (u32LocalTempAbs + CRKHAL_u32NumberOfMlt_Full)
	                      & GTM_TBU_TIMER_MAX_LIMIT;
	   }

	   /* Remove the offset from the Abs Angle */
	   if (u32LocalTempAbs < CRKHAL_u32NumberOfMlt_Tdc)
	   {
	      u32LocalTempAbs = (u32LocalTempAbs + CRKHAL_u32NumberOfMlt_Full)
	                      - CRKHAL_u32NumberOfMlt_Tdc;
	   }
	   else
	   {
	      u32LocalTempAbs -= CRKHAL_u32NumberOfMlt_Tdc;
	   }

	   while (u32LocalTempAbs >= CRKHAL_u32NumberOfMlt_Full)
	   {
	      u32LocalTempAbs -= CRKHAL_u32NumberOfMlt_Full;
	   }
   }
   else
   {
	   sint32 s32_diff = (CRKHAL_u32GlobalTeethOffset - u32relAngle);
	   sint32 s32Tempvalue;

	   if(s32_diff > 0)
	   {
		   if(s32_diff > (CRKHAL_u32NumberOfMlt_Full - CRKHAL_u32NumberOfMlt_Tdc))
		   {

			   s32Tempvalue = ((CRKHAL_u32GlobalTeethOffset - u32relAngle) + CRKHAL_u32NumberOfMlt_Tdc);
			   s32Tempvalue %= CRKHAL_u32NumberOfMlt_Full;

			   if(s32Tempvalue > CRKHAL_u32NumberOfMlt_Full)
			   {
				   s32Tempvalue = s32Tempvalue - CRKHAL_u32NumberOfMlt_Full;
			   }
			   else
			   {
				   s32Tempvalue = CRKHAL_u32NumberOfMlt_Full - s32Tempvalue;
			   }

		   }
		   else
		   {

			   if((((sint32)((CRKHAL_u32GlobalTeethOffset - u32relAngle)
					   - CRKHAL_u32NumberOfMlt_Full + CRKHAL_u32NumberOfMlt_Tdc)) > 0))
			   {
				   s32Tempvalue = ((CRKHAL_u32GlobalTeethOffset - u32relAngle) -
						   CRKHAL_u32NumberOfMlt_Full + CRKHAL_u32NumberOfMlt_Tdc) & GTM_TBU_TIMER_MAX_LIMIT;
			   }
			   else
			   {
				   s32Tempvalue = ((u32relAngle - CRKHAL_u32GlobalTeethOffset) +
						   CRKHAL_u32NumberOfMlt_Full - CRKHAL_u32NumberOfMlt_Tdc) & GTM_TBU_TIMER_MAX_LIMIT;
			   }
		   }
	   }
	   else
	   {

		   s32Tempvalue = ((u32relAngle - CRKHAL_u32GlobalTeethOffset) +
				   CRKHAL_u32NumberOfMlt_Full - CRKHAL_u32NumberOfMlt_Tdc);

		   if(s32Tempvalue > GTM_TBU_TIMER_MAX_LIMIT)
		   {
			   s32Tempvalue = s32Tempvalue & GTM_TBU_TIMER_MAX_LIMIT;
			   s32Tempvalue %= CRKHAL_u32NumberOfMlt_Full;
		   }
		   else
		   {
			   s32Tempvalue = ((s32Tempvalue + CRKHAL_u32NumberOfMlt_Full) & GTM_TBU_TIMER_MAX_LIMIT);
			   s32Tempvalue %= CRKHAL_u32NumberOfMlt_Full;
		   }
	   }
	   u32LocalTempAbs = (uint32)s32Tempvalue;
   }

   return ((uint16) u32LocalTempAbs);
   /* return (uint16) (u32LocalTempAbs % CRKHAL_u32NumberOfMlt_Full); */
}

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
