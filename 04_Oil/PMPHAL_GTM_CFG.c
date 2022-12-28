/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_GTM_CFG.c                                                                                */
/* !Description     : Configuration of the PMPHAL Component                                                           */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/

#include "IfxGtm_Ccu.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "PMPHAL_GTM_CFG.h"
#include "PMPHAL_I.h"

/**********************************************************************************************************************/
/* VARIABLES                                                                                                          */
/**********************************************************************************************************************/
#define PMPHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "PMPHAL_MemMap.h"

volatile Ifx_GTM_ATOM_CH*   PMPHAL_pstrSPILL_CMD_CH;
volatile Ifx_GTM_ATOM_AGC*  PMPHAL_pstrAgcSPILL_CMD_CH;

#define PMPHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "PMPHAL_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

static void PMPHAL_vidCoilToPin(void);

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidGtmInit                                                                                   */
/* !Description : API initialises the global variables used for GTM for the PMPHAL component.                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidGtmInit(void)
{
   PMPHAL_pstrSPILL_CMD_CH = (volatile Ifx_GTM_ATOM_CH *)
                             (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                             (ATOM_OFFSET * PMPHAL_snSPILL_CMD_ATOM)+
                             (ATOM_CH_OFFSET * PMPHAL_snSPILL_CMD_ATOM_CH));
   PMPHAL_pstrAgcSPILL_CMD_CH = (volatile Ifx_GTM_ATOM_AGC*)
                                (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                                (ATOM_OFFSET * PMPHAL_snSPILL_CMD_ATOM)+
                                (ATOM_AGC_OFFSET));

   /* Disable of angular alarms */
   PMPHAL_vidDisableSpillCmdInt();

   /* TOUTSEL and IOCR configurations for injections */
   /*PMPHAL_vidCoilToPin();*/
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCoilToPin                                                                                 */
/* !Description : API Connects ATOM output to IO pin                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
static void PMPHAL_vidCoilToPin(void)
{
   IfxGtm_vidAtomToPin(PMPHAL_SPILL_CMD_TOUT_REG,
                       PMPHAL_SPILL_CMD_TOUT_SEL,
                       (Ifx_P *)PMPHAL_SPILL_CMD_PORT,
                       PMPHAL_SPILL_CMD_PIN,
                       PMPHAL_SPILL_CMD_GTM_TIMER);

}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCoilToPinDisconnect                                                                       */
/* !Description : API Connects ATOM output to IO pin                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidCoilToPinDisconnect(void)
{
   IfxGtm_vidAtomToPinDisconnect(PMPHAL_SPILL_CMD_TOUT_REG,
                                 PMPHAL_SPILL_CMD_TOUT_SEL,
                                 (Ifx_P *)PMPHAL_SPILL_CMD_PORT,
                                 PMPHAL_SPILL_CMD_PIN,
                                 0U);

}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidGtmEnable                                                                                 */
/* !Description : API initialises the ATOM channel for the PMPHAL component.                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidGtmEnable(void)
{
   /* Enable the ATOM associated to pump */
   IfxGtm_vidAtomEnableChannel(PMPHAL_pstrSPILL_CMD_CH,
                               PMPHAL_pstrAgcSPILL_CMD_CH,
                               PMPHAL_snSPILL_CMD_ATOM_CH,
                               IfxGtm_Atom_Level_Low);
   PMPHAL_vidCoilToPin();
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidGtmDisable                                                                                */
/* !Description : API disables the ATOM channel for the PMPHAL component.                                             */
/*                the PMPHAL component.                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidGtmDisable(void)
{
   /* Disable the ATOM associated to pump */
   IfxGtm_vidAtomDisableChannel(PMPHAL_pstrSPILL_CMD_CH,
                                PMPHAL_pstrAgcSPILL_CMD_CH,
                                PMPHAL_snSPILL_CMD_ATOM_CH,
                                IfxGtm_Atom_Level_High);
   PMPHAL_vidCoilToPinDisconnect();
}

#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
