/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_gtm_Cfg.c                                        */
/* !Description     : IGNHAL configuration                                    */
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
 * %PID: P2017_BSW:0A192573.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "IfxGtm_Ccu.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "IGNHAL_co_Cfg.h"
#include "IGNHAL.h"
#include "IGNHAL_gtm_Cfg.h"
#include "IGNHAL_I.h"
#include "IGNHAL_L.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

static void IGNHAL_vidCoilToPin(void);

/******************************************************************************/
/* !FuncName    : IGNHAL_GtmInit                                              */
/* !Description : initializes the ATOM register.                              */
/******************************************************************************/
void IGNHAL_GtmInit(void)
{
   /* Ignition Coil A ATOM mapping*/
  IGNHAL_pstrCOIL_A = (volatile Ifx_GTM_ATOM_CH *)
           (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
             (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_A))+ \
             (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A)));
                                       
  IGNHAL_pstrAgcCOIL_A = (volatile Ifx_GTM_ATOM_AGC*)
          (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
            (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_A))+ \
            (ATOM_AGC_OFFSET));
                                          
  IGNHAL_pstrCOIL_A_DIAG = (volatile Ifx_GTM_ATOM_CH *)
           (IFX_GTM_BASE + \
              ATOM_BASE_OFFSET + \
              (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_A_DIAG))+ \
              (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A_DIAG))); 
  
  IGNHAL_pstrAgcCOIL_A_DIAG =  (volatile Ifx_GTM_ATOM_AGC*)
        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_A_DIAG))+ \
          (ATOM_AGC_OFFSET));

  /* Ignition Coil B ATOM mapping*/
  IGNHAL_pstrCOIL_B = (volatile Ifx_GTM_ATOM_CH *)
            (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
              (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_B))+ \
              (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B)));
                                       
  IGNHAL_pstrAgcCOIL_B =  (volatile Ifx_GTM_ATOM_AGC*)(IFX_GTM_BASE + ATOM_BASE_OFFSET + \
          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_B))+ \
          (ATOM_AGC_OFFSET));
                                          
  IGNHAL_pstrCOIL_B_DIAG = (volatile Ifx_GTM_ATOM_CH *)
           (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
              (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_B_DIAG))+ \
              (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B_DIAG))); 
  
  IGNHAL_pstrAgcCOIL_B_DIAG =  (volatile Ifx_GTM_ATOM_AGC*)
        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_B_DIAG))+ \
          (ATOM_AGC_OFFSET));
  
  /* Ignition Coil C ATOM mapping*/
  IGNHAL_pstrCOIL_C = (volatile Ifx_GTM_ATOM_CH *)
                        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
                          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_C))+ \
                          (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C)));
                                       
  IGNHAL_pstrAgcCOIL_C = (volatile Ifx_GTM_ATOM_AGC*)
        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_C))+ \
          (ATOM_AGC_OFFSET));
                                          
  IGNHAL_pstrCOIL_C_DIAG = (volatile Ifx_GTM_ATOM_CH *)
           (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
              (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_C_DIAG))+ \
              (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C_DIAG))); 
  
  IGNHAL_pstrAgcCOIL_C_DIAG = (volatile Ifx_GTM_ATOM_AGC*)
        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(COIL_C_DIAG))+ \
          (ATOM_AGC_OFFSET));

  /* Ignition Reference Teeth ATOM mapping*/
  IGNHAL_pstrREF_TEETH = (volatile Ifx_GTM_ATOM_CH *)
                        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
                          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(REF_TEETH))+ \
                          (ATOM_CH_OFFSET * IGNHAL_snGET_ATOM_Channel_FROM_CFG(REF_TEETH)));
                                       
  IGNHAL_pstrAgcREF_TEETH = (volatile Ifx_GTM_ATOM_AGC*)
        (IFX_GTM_BASE + ATOM_BASE_OFFSET + \
          (ATOM_OFFSET * IGNHAL_snGET_ATOM_Subblock_FROM_CFG(REF_TEETH))+ \
          (ATOM_AGC_OFFSET));

}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidCoilToPin                                         */
/* !Description : Connects to ATOM outputs to pins.                           */
/******************************************************************************/
static void IGNHAL_vidCoilToPin(void)
{
   IfxGtm_vidAtomToPin( IGNHAL_COIL_A_TOUT_REG,
                        IGNHAL_COIL_A_TOUT_SEL,
                        (Ifx_P *)IGNHAL_COIL_A_PORT,
                        IGNHAL_COIL_A_PIN,
                        IGNHAL_COIL_A_GTM_TIMER
                      );

   IfxGtm_vidAtomToPin( IGNHAL_COIL_B_TOUT_REG,
                        IGNHAL_COIL_B_TOUT_SEL,
                        (Ifx_P *)IGNHAL_COIL_B_PORT,
                        IGNHAL_COIL_B_PIN,
                        IGNHAL_COIL_B_GTM_TIMER
                      );

   IfxGtm_vidAtomToPin( IGNHAL_COIL_C_TOUT_REG,
                        IGNHAL_COIL_C_TOUT_SEL,
                        (Ifx_P *)IGNHAL_COIL_C_PORT,
                        IGNHAL_COIL_C_PIN,
                        IGNHAL_COIL_C_GTM_TIMER
                      );
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidCoilToPinDisconnect                               */
/* !Description : Disconnects ATOM outputs from pins.                         */
/******************************************************************************/

void IGNHAL_vidCoilToPinDisconnect(void)
{
      IfxGtm_vidAtomToPinDisconnect( IGNHAL_COIL_A_TOUT_REG,
                                     IGNHAL_COIL_A_TOUT_SEL,
                                     (Ifx_P *)IGNHAL_COIL_A_PORT,
                                     IGNHAL_COIL_A_PIN,
                                     0U);

      IfxGtm_vidAtomToPinDisconnect( IGNHAL_COIL_B_TOUT_REG,
                                     IGNHAL_COIL_B_TOUT_SEL,
                                     (Ifx_P *)IGNHAL_COIL_B_PORT,
                                     IGNHAL_COIL_B_PIN,
                                     0U);

      IfxGtm_vidAtomToPinDisconnect( IGNHAL_COIL_C_TOUT_REG,
                                     IGNHAL_COIL_C_TOUT_SEL,
                                     (Ifx_P *)IGNHAL_COIL_C_PORT,
                                     IGNHAL_COIL_C_PIN,
                                     0U);

}
/******************************************************************************/
/* !FuncName    : IGNHAL_GtmEnable                                            */
/* !Description : Enables ATOM channels.                                      */
/******************************************************************************/
void IGNHAL_GtmEnable(void)
{
   /* Ref Teeth ATOM initialization */
   IfxGtm_vidAtomEnableChannel( IGNHAL_pstrREF_TEETH,
                                IGNHAL_pstrAgcREF_TEETH,
                                IGNHAL_snGET_ATOM_Channel_FROM_CFG(REF_TEETH),
                                IfxGtm_Atom_Level_Low
                              );
   IfxGtm_vidAtomEnableChannel( IGNHAL_pstrCOIL_A,
                                IGNHAL_pstrAgcCOIL_A,
                                IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A),
                                IfxGtm_Atom_Level_Low
                              );

   IfxGtm_vidAtomEnableChannel( IGNHAL_pstrCOIL_B,
                                IGNHAL_pstrAgcCOIL_B,
                                IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B),
                                IfxGtm_Atom_Level_Low
                              );

   IfxGtm_vidAtomEnableChannel( IGNHAL_pstrCOIL_C,
                                IGNHAL_pstrAgcCOIL_C,
                                IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C),
                                IfxGtm_Atom_Level_Low
                              );

  /* TOUTSEL and IOCR configurations for Coils */
  IGNHAL_vidCoilToPin();
}

/******************************************************************************/
/* !FuncName    : IGNHAL_GtmDisable                                           */
/* !Description : Disables ATOM channels.                                     */
/******************************************************************************/
void IGNHAL_GtmDisable(void)
{
     /* Ref Teeth ATOM initialization */
   IfxGtm_vidAtomDisableChannel( IGNHAL_pstrREF_TEETH ,
                                 IGNHAL_pstrAgcREF_TEETH ,
                                 IGNHAL_snGET_ATOM_Channel_FROM_CFG(REF_TEETH),
                                 IfxGtm_Atom_Level_High
                               );

   IfxGtm_vidAtomDisableChannel( IGNHAL_pstrCOIL_A,
                                 IGNHAL_pstrAgcCOIL_A ,
                                 IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A),
                                 IfxGtm_Atom_Level_High
                               );

   IfxGtm_vidAtomDisableChannel( IGNHAL_pstrCOIL_B,
                                 IGNHAL_pstrAgcCOIL_B,
                                 IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B),
                                 IfxGtm_Atom_Level_High
                               );

   IfxGtm_vidAtomDisableChannel( IGNHAL_pstrCOIL_C,
                                 IGNHAL_pstrAgcCOIL_C,
                                 IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C),
                                 IfxGtm_Atom_Level_High
                               );

   IGNHAL_vidCoilToPinDisconnect( );
}

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
