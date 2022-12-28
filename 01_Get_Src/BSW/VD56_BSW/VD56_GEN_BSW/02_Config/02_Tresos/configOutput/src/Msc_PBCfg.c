/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Msc_PBCfg.c                                                  **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-29, 11:35:18                                         **
**                                                                           **
**  GENERATOR : Build b131017-0205                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : MSC configuration generated out of ECU configuration      **
**                 file (Msc.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY : [cover parentID = DS_NAS_PR69_PR469_PR122_PR123,DS_NAS_PR647,
                  SAS_NAS_MSC_PR1071,DS_NAS_PR446,DS_NAS_PR699,DS_NAS_PR709] 
                  [/cover]                                                    **
*******************************************************************************/
/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Msc.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                    Call Back Function Prototype                            **
*******************************************************************************/
/* MSC0 Command Frame Call Back function for configuration set 0 */
extern void TLE8718_vidMc0TxCmdFrameNotif(void);

/* MSC0 Rx Frame Call Back function for configuration set 0 */
extern void Msc_Interrupt_HandlerMSC0RxFrame(void);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Memory Mapping the configuration constant */
#define MSC_START_SEC_POSTBUILDCFG
#include "MemMap.h"


/*
        Container: MscConfigSet
        Multilplicity : 1 - *
*/
static const Msc_ModuleConfigType Msc_kModuleConfiguration0[] = 
{
  /***** Configuration Set 0 for MSC *****/
  /***** Configuration for MSC0 *****/
{
  0x02102081U, /* Configuration for MSC0 register DSC */
  0x00000000U, /* Configuration for MSC0 register DSTE */
  0x00000000U, /* Configuration for MSC0 register DSDSL */
  0x00000000U, /* Configuration for MSC0 register DSDSLE */
  0x00000000U, /* Configuration for MSC0 register DSDSH */
  0x00000000U, /* Configuration for MSC0 register DSDSHE */
  0x0000ffffU, /* Mask for bits selected Downstream Data Register as source */
  0x00000000U, /* Extension Mask for bits selected Downstream Data Register as source */
  0x00000000U, /* Configuration for MSC0 register ESR */
  0x00000000U, /* Configuration for MSC0 register ESRE */
  0x00000000U, /* Configuration for MSC0 register DD.DDL */
  0x00000000U, /* Configuration for MSC0 register DDE.DDLE */
  0x00000000U, /* Configuration for MSC0 register DD.DDH */
  0x00000000U, /* Configuration for MSC0 register DDE.DDHE */
  0x00000000U, /* Configuration for MSC0 register DSCE */
  0x000043fdU, /* Configuration for MSC0 register FDR */
  0x0000002aU, /* Configuration for MSC0 register USR */
  0x00000104U, /* Configuration for MSC0 register OCR */
  0x00000074U, /* Configuration for MSC0 register USCE */
  0x00U, /* Configuration for MSC0 register DSS */
  0x08U, /* Configuration for MSC0 register CLC */
  0x00U, /* Configuration for MSC0 register DSCE Extension Enable Value */
  /* Interrupt configration for MSC0 Module */
  {
    0x00001000U, /* Configuration for MSC0 register ICR */ /* VALEO_PATCH_DISABLE_MSC_INTERRUPT: disable of all MSC interrupts */
    /* Application Notifier Function for Time Frame Interrupt */
    NULL_PTR,
    /* Application Notifier Function for Command Frame Interrupt */
    TLE8718_vidMc0TxCmdFrameNotif,
    /* Application Notifier Function for Data Frame Interrupt */
    NULL_PTR,
    /* Application Notifier Function for Rx Frame Interrupt */
    Msc_Interrupt_HandlerMSC0RxFrame,
    /* Configuration for Service Requests SR0, SR1, SR2 and SR3*/
    0x03U
  }
}
};

/*     MSC Config Root    */
const Msc_ConfigType Msc_ConfigRoot[]=
{
{
  /* Configuration Set 0 for MSC */
  {
    &Msc_kModuleConfiguration0[0],
    NULL_PTR,
    NULL_PTR

  }
}
};

#define MSC_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"



