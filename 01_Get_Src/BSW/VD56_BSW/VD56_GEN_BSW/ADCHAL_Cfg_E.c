/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : ADCHAL                                                  */
/* !Description     : Analog to digital conversion on HAL                     */
/*                                                                            */
/* !File            : ADCHAL_Cfg_E.c                                          */
/* !Description     : ADCHAL configuration                                    */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192545.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "ADCHAL.h"
#include "ADCHAL_Cfg_E.h"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/

/*#define ADCHAL_START_SEC_CALIB_16BIT
#include "ADCHAL_MemMap.h"

const uint16 ADCHAL_ku16HeatingMosOffsDWN = 0;
const uint16 ADCHAL_ku16HeatingMosOffsUPS = 0;
const uint16 ADCHAL_ku16ShuntResistorDWN = 0;
const uint16 ADCHAL_ku16ShuntResistorUPS = 0;

#define ADCHAL_STOP_SEC_CALIB_16BIT
#include "ADCHAL_MemMap.h"*/


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/

#define ADCHAL_START_SEC_CODE
#include "ADCHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : ADCHAL_u32MultiplyByTwo                                     */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint32 ADCHAL_u32MultiplyByTwo(ADCHAL_tudtMcalAcquisition udtRawResult)
{
   return (udtRawResult << 1u);
}

/******************************************************************************/
/* !FuncName    : ADCHAL_u16ApplyTrimsOnVbrf                                  */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint16 ADCHAL_u16ApplyTrimsOnVbrf(ADCHAL_tudtMcalAcquisition udtRawResult)
{
   uint16 u16LocalAdcResult;

   ADCHAL_vidAPPLY_TRIMS_ON_VBRF((uint16)udtRawResult, u16LocalAdcResult);
   return (u16LocalAdcResult);
}

/******************************************************************************/
/* !FuncName    : ADCHAL_u16CalculateVecuDwn                                  */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint16 ADCHAL_u16CalculateVecuDwn(ADCHAL_tudtMcalAcquisition udtRawResult)
{
   uint16 u16LocalAdcResult;

   ADCHAL_vidCALCULATE_VECU((uint16)udtRawResult,
                            ADCHAL_u8HEAT_O2_GAIN_DOWN,
                            ADCHAL_ku16HeatingMosOffsDWN,
                            ADCHAL_u16OFFSET_ASIC,
                            u16LocalAdcResult);

   return (u16LocalAdcResult);
}

/******************************************************************************/
/* !FuncName    : ADCHAL_u16CalculateIO2Dwn                                   */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint16 ADCHAL_u16CalculateIO2Dwn(ADCHAL_tudtMcalAcquisition udtRawResult)
{
   uint16 u16LocalAdcResult;

   ADCHAL_vidCALCULATE_IO2((uint16)udtRawResult,
                           ADCHAL_u8HEAT_O2_GAIN_DOWN,
                           ADCHAL_u16OFFSET_ASIC,
                           ADCHAL_ku16ShuntResistorDWN,
                           u16LocalAdcResult);

   return (u16LocalAdcResult);
}

/******************************************************************************/
/* !FuncName    : ADCHAL_u16CalculateVecuUps                                  */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint16 ADCHAL_u16CalculateVecuUps(ADCHAL_tudtMcalAcquisition udtRawResult)
{
   uint16 u16LocalAdcResult;

   ADCHAL_vidCALCULATE_VECU((uint16)udtRawResult,
                            ADCHAL_u8HEAT_O2_GAIN_UP,
                            ADCHAL_ku16HeatingMosOffsUPS,
                            ADCHAL_u16OFFSET_ASIC,
                            u16LocalAdcResult);

   return (u16LocalAdcResult);
}

/******************************************************************************/
/* !FuncName    : ADCHAL_u16CalculateIO2Ups                                   */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint16 ADCHAL_u16CalculateIO2Ups(ADCHAL_tudtMcalAcquisition udtRawResult)
{
   uint16 u16LocalAdcResult;

   ADCHAL_vidCALCULATE_IO2((uint16)udtRawResult,
                           ADCHAL_u8HEAT_O2_GAIN_UP,
                           ADCHAL_u16OFFSET_ASIC,
                           ADCHAL_ku16ShuntResistorUPS,
                           u16LocalAdcResult);

   return (u16LocalAdcResult);
}

#define ADCHAL_STOP_SEC_CODE
#include "ADCHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
