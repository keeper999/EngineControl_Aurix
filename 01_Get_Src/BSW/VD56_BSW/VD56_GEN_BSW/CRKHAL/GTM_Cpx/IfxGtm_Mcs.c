/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : GTM_MCS                                                 */
/* !Description     : GTM_MCS Component                                       */
/*                                                                            */
/* !File            : IfxGtm_Mcs.c                                            */
/* !Description     : Definition of data of GTM MCS Component                 */
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
 * %PID: P2017_BSW:A18527.A-SRC;6 %
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
#include "mcs0.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
/** \addtogroup CRAKHAL
 * \{ */

/******************************************************************************/
/*                           Typedefs                                         */
/******************************************************************************/


/******************************************************************************/
/*                           Enums                                            */
/******************************************************************************/


/******************************************************************************/
/*                           Struct                                           */
/******************************************************************************/


/******************************************************************************/
/*                           Variables                                        */
/******************************************************************************/
#define CRKHAL_START_SEC_CONST_UNSPECIFIED
#include "CRKHAL_MemMap.h"

extern const unsigned int MCS0_CH_INIT_RAM[];

#define CRKHAL_STOP_SEC_CONST_UNSPECIFIED
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/*                           Function prototypes                              */
/******************************************************************************/

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : IfxGtm_vidUpdateToothTskDurationThd                         */
/* !Description : This function updates the MCS pointer for Engine Speed      */
/*                Threshold passed by application 							  */
/*                                                                            */
/******************************************************************************/

void IfxGtm_vidUpdateToothTskDurationThd(uint32 CRKHAL_u32ToothTskDurationThd)
{
   *CRKHAL_pu32McsEngineSpeedThd = CRKHAL_u32ToothTskDurationThd;
}

/******************************************************************************/
/* !FuncName    : IfxGtm_loadCodeToMcs0                                       */
/* !Description : This function loads the MCS code to MCS                     */
/*                                                                            */
/******************************************************************************/
void IfxGtm_loadCodeToMcs0(void)
{
   uint16 u16LocalCount;
   uint32* u32LocalPmem = (uint32 *) &GTM_MCS_MEM;
   /*Write the assembler code to MCS0 RAM*/
   for (u16LocalCount = (uint16)UINT16_MIN;
        u16LocalCount < (MCS0_CH_INIT_RAM_LEN);
        u16LocalCount += 1)
   {
      u32LocalPmem[u16LocalCount] = MCS0_CH_INIT_RAM[u16LocalCount];
   }
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidMcs0Init                                          */
/* !Description : This function configures the MCS variables & initialisation */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidMcs0Init(void)
{
   uint32* u32LocalPmem = (uint32 *) &GTM_MCS_MEM;

   CRKHAL_pu32McsOnTime           = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsDuration         = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsEngineStatus     = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsTeeAfrLastSyLos  = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsEngineSpeedThd   = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsPrevToothDur     = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsT_2  			  = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsToothCnt         = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsTskIntrEn 		  = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsBiDirEn	 	  = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirDiaEn	 	  = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsBiDirFwdCnt      = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirBwdCnt      = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirChgMndEn    = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsDirCfgEn   	  = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBwdReliable	  = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirFwTotCfg    = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsRotDirMngMaxDur  = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsBiDirFwPlsDurMin = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirFwPlsDurMax = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirBwPlsDurMin = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsBiDirBwPlsDurMax = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsOorPulseCounter  = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsPulseDiagCounter = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsLtoo1event       = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsEngineRunThd     = (uint32*) &GTM_MCS_MEM;

   CRKHAL_pu32McsGlobalOffsetCnt   = (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsGlobalTeethOffset = (uint32*) &GTM_MCS_MEM;

/*   CRKHAL_pu32McsRotationDir	= (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsDirChange		= (uint32*) &GTM_MCS_MEM;
   CRKHAL_pu32McsDirConfirm		= (uint32*) &GTM_MCS_MEM;*/

   /* to be removed in case the compiler option is used */
   /* if COMPILER */
   IfxGtm_loadCodeToMcs0();
   /* end */

   CRKHAL_pu32McsOnTime           = &u32LocalPmem[MCS0_crankacttoinacttime / 4U];
   CRKHAL_pu32McsDuration         = &u32LocalPmem[MCS0_crankduration / 4U];
   CRKHAL_pu32McsEngineStatus     = &u32LocalPmem[MCS0_enginestatus / 4U];
   CRKHAL_pu32McsTeeAfrLastSyLos  = &u32LocalPmem[MCS0_teethaftrlastsyncloss / 4U];
   CRKHAL_pu32McsEngineSpeedThd   = &u32LocalPmem[MCS0_enginespeedthd / 4U];

   CRKHAL_pu32McsPrevToothDur     = &u32LocalPmem[MCS0_prevtoothdur / 4U];
   CRKHAL_pu32McsT_2  			  = &u32LocalPmem[MCS0_t_two / 4U];
   CRKHAL_pu32McsToothCnt         = &u32LocalPmem[MCS0_toothcnt / 4U];
   CRKHAL_pu32McsTskIntrEn 		  = &u32LocalPmem[MCS0_tskintren / 4U];

   CRKHAL_pu32McsBiDirEn 	      = &u32LocalPmem[MCS0_bidiren / 4U];
   CRKHAL_pu32McsBiDirDiaEn       = &u32LocalPmem[MCS0_bidirdiaen / 4U];

   CRKHAL_pu32McsBiDirFwdCnt      = &u32LocalPmem[MCS0_bidirfwdcnt / 4U];
   CRKHAL_pu32McsBiDirBwdCnt      = &u32LocalPmem[MCS0_bidirbwdcnt / 4U];
   CRKHAL_pu32McsBiDirChgMndEn    = &u32LocalPmem[MCS0_bidirchangminen / 4U];

   CRKHAL_pu32McsDirCfgEn   	  = &u32LocalPmem[MCS0_bidircfgen / 4U];
   CRKHAL_pu32McsBwdReliable	  = &u32LocalPmem[MCS0_bidirrelable / 4U];
   CRKHAL_pu32McsBiDirFwTotCfg    = &u32LocalPmem[MCS0_bidirfwmaxcnt / 4U];
   CRKHAL_pu32McsRotDirMngMaxDur  = &u32LocalPmem[MCS0_bidirmaxdur / 4U];

   CRKHAL_pu32McsBiDirFwPlsDurMin = &u32LocalPmem[MCS0_bidirfwdpulsedurmin / 4U];
   CRKHAL_pu32McsBiDirFwPlsDurMax = &u32LocalPmem[MCS0_bidirfwdpulsedurmax / 4U];
   CRKHAL_pu32McsBiDirBwPlsDurMin = &u32LocalPmem[MCS0_bidirbwdpulsedurmin / 4U];
   CRKHAL_pu32McsBiDirBwPlsDurMax = &u32LocalPmem[MCS0_bidirbwdpulsedurmax / 4U];

   CRKHAL_pu32McsOorPulseCounter  = &u32LocalPmem[MCS0_oorpulsecounter / 4U];
   CRKHAL_pu32McsPulseDiagCounter = &u32LocalPmem[MCS0_pulsediagcounter / 4U];

   CRKHAL_pu32McsLtoo1event       = &u32LocalPmem[MCS0_ltoo1event / 4U];
   CRKHAL_pu32McsEngineRunThd     = &u32LocalPmem[MCS0_enginerunthd / 4U];

   CRKHAL_pu32McsGlobalOffsetCnt   = &u32LocalPmem[MCS0_globaloffsetcnt / 4U];
   CRKHAL_pu32McsGlobalTeethOffset = &u32LocalPmem[MCS0_globalteethoffset / 4U];

/*   CRKHAL_pu32McsRotationDir	= &u32LocalPmem[MCS0_rotationdir / 4U];
   CRKHAL_pu32McsDirChange		= &u32LocalPmem[MCS0_dirchange / 4U];
   CRKHAL_pu32McsDirConfirm     = &u32LocalPmem[MCS0_dirchconf / 4U];*/

   *CRKHAL_pu32McsEngineStatus     = (uint32)UINT32_MIN;
   *CRKHAL_pu32McsEngineSpeedThd   = (uint32)CRKHAL_ku16EngSpeedThd;

   *CRKHAL_pu32McsBiDirChgMndEn    = (boolean)FALSE;

   /*  DirCfgEn = FALSE - generate tooth interrupt on below certain threshold
    *  DirCfgEn = TRUE - Direction Set & above threshold generate tooth interrupt */
   *CRKHAL_pu32McsDirCfgEn  	   = (boolean)FALSE;
   /*  BwdReliable = TRUE - generate tooth interrupt on below certain threshold
    *  BwdReliable = FALSE - Direction Set & above threshold generate tooth interrupt */
   *CRKHAL_pu32McsBwdReliable	   = (boolean)FALSE;

   *CRKHAL_pu32McsBiDirFwTotCfg    = (uint32)CRKHAL_u8MAX_CNT_TO_FWDDir;
   *CRKHAL_pu32McsRotDirMngMaxDur  = (uint32)CRKHAL_ku32BidirSensorValidThd;

   *CRKHAL_pu32McsBiDirFwPlsDurMin = (uint32)CRKHAL_ku16BiDirFwdPulseDurMin;
   *CRKHAL_pu32McsBiDirFwPlsDurMax = (uint32)CRKHAL_ku16BiDirFwdPulseDurMax;
   *CRKHAL_pu32McsBiDirBwPlsDurMin = (uint32)CRKHAL_ku16BiDirBwdPulseDurMin;
   *CRKHAL_pu32McsBiDirBwPlsDurMax = (uint32)CRKHAL_ku16BiDirBwdPulseDurMax;

   *CRKHAL_pu32McsOorPulseCounter  = (uint32)UINT32_MIN;
   *CRKHAL_pu32McsPulseDiagCounter = (uint32)UINT32_MIN;

   *CRKHAL_pu32McsBiDirEn 		   = (boolean) FALSE;

   *CRKHAL_pu32McsEngineRunThd     = CRKHAL_u32EngRunThDuration;

   *CRKHAL_pu32McsGlobalOffsetCnt  = (uint32)UINT32_MIN;
   *CRKHAL_pu32McsGlobalTeethOffset= (uint32)UINT32_MIN;

   *CRKHAL_pu32McsToothCnt       = (uint32)UINT32_MIN;
   *CRKHAL_pu32McsLtoo1event     = (uint32)UINT32_MIN;
   *CRKHAL_pu32McsTeeAfrLastSyLos = (uint32)UINT32_MIN;

   CRKHAL_vidMcsResetVars();

   /* GTM_MCS0_CH0_IRQ_EN.U   = (0x7U); */
   GTM_MCS0_CH0_IRQ_MODE.U = IfxGtm_IrqMode_PulseNotifyMode;
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidMcsResetVars                                      */
/* !Description : This function resets MCS variable during init & CRK_OFF     */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidMcsResetVars(void)
{
    *CRKHAL_pu32McsOnTime   	  = (uint32)UINT32_MIN;
    *CRKHAL_pu32McsDuration 	  = (uint32)UINT32_MIN;

    /**CRKHAL_pu32McsTeeAfrLastSyLos = (uint32)UINT32_MIN;*/

    *CRKHAL_pu32McsPrevToothDur   = (uint32)UINT32_MIN;
    *CRKHAL_pu32McsT_2  		  = (uint32)UINT32_MIN;

    *CRKHAL_pu32McsTskIntrEn      = (boolean)FALSE;

    *CRKHAL_pu32McsBiDirDiaEn 	  = (boolean)FALSE;

    *CRKHAL_pu32McsBiDirFwdCnt 	  = (uint32)UINT32_MIN;
    *CRKHAL_pu32McsBiDirBwdCnt 	  = (uint32)UINT32_MIN;

}

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
