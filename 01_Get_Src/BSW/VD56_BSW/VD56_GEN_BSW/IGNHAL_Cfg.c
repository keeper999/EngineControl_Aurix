/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_Cfg.c                                            */
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
 * %PID: P2017_BSW:0A192581.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "CRKHAL.h"
#include "IGNHAL.h"
#include "IGNHAL_I.h"
#include "IGNHAL_L.h"
#include "IGNHAL_Cfg.h"
#include "IGNHAL_gtm_Cfg.h"


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define IGNHAL_START_SEC_CONST_UNSPECIFIED
#include "IGNHAL_MemMap.h"

/* IGNHALCoilConductProg */
IGNHAL_takpfCoilConductProg IGNHAL_akpfCoilConductProg[
                          IGNHAL_FCT_COIL_CONDUCT_PROG_TABLE_LENGTH] = 
{ 
   IGNHAL_vidCoilProg_COIL_A,
   IGNHAL_vidCoilProg_COIL_B,
   IGNHAL_vidCoilProg_COIL_C
};

/* IGNHALReadStartCounter */
IGNHAL_takpfReadStartCounter IGNHAL_akpfReadStartCounter[
                          IGNHAL_FCT_READ_COUNTER_TABLE_LENGTH] = 
{ 
   IGNHAL_u16ReadStartCntr_COIL_A,
   IGNHAL_u16ReadStartCntr_COIL_B,
   IGNHAL_u16ReadStartCntr_COIL_C
};

/* IGNHALCoilConductProgImmediate */
IGNHAL_takpfCoilImmediateTrig IGNHAL_akpfCoilImmediateTrig[
                          IGNHAL_FCT_READ_COUNTER_TABLE_LENGTH] = 
{ 
   IGNHAL_vidImmediateTrig_COIL_A,
   IGNHAL_vidImmediateTrig_COIL_B,
   IGNHAL_vidImmediateTrig_COIL_C
};

#define IGNHAL_STOP_SEC_CONST_UNSPECIFIED
#include "IGNHAL_MemMap.h"


#define IGNHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "IGNHAL_MemMap.h"

volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_A;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_A;
volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_A_DIAG;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_A_DIAG;

volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_B;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_B;
volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_B_DIAG;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_B_DIAG;

volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_C;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_C;
volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_C_DIAG;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_C_DIAG;

volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrREF_TEETH;
volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcREF_TEETH;

#define IGNHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "IGNHAL_MemMap.h"


/******************************************************************************/
/* PRIVATE FUNCTION DEFINITIONS                                               */
/******************************************************************************/

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidCoilProg_COIL_A                                  */
/* !Description : API start the conduction of Coil A.                        */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidCoilProg_COIL_A(uint16 u16Start)
{
   uint32 u32LocalChannel ;
   uint32 u32LocalValue ;

   /* Check if the channel is enabled or disabled */
   u32LocalChannel = IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A) ;
   u32LocalValue = IGNHAL_pstrAgcCOIL_A->ENDIS_STAT.U ;
   u32LocalChannel = 2U * u32LocalChannel ;
   u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;

   if(u32LocalValue == 0U)
   {
      IfxGtm_vidAtomEnableChannel( IGNHAL_pstrCOIL_A,
                                   IGNHAL_pstrAgcCOIL_A,
                                   IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A),
                                   IfxGtm_Atom_Level_Low
                                 );

      IfxGtm_vidAtomToPin( IGNHAL_COIL_A_TOUT_REG,
                           IGNHAL_COIL_A_TOUT_SEL,
                           (Ifx_P *)IGNHAL_COIL_A_PORT,
                           IGNHAL_COIL_A_PIN,
                           IGNHAL_COIL_A_GTM_TIMER
                         );

   }

   /* Set the ATOM channel to low and enable the channel */
   /* Enable the Notification function for start Angle */
   CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_COIL_A_CMD);
   /* At the compare match the Signal is output as High */
   CRKHAL_vidActivateAlarmMode(CRKHAL_u8ALARM_COIL_A_CMD, MODE_OUTPUT_1);
   /* Set the alarm to the required Start Angle */
   CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_COIL_A_CMD, u16Start);
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidCoilProg_COIL_B                                  */
/* !Description : API start the conduction of Coil B.                        */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidCoilProg_COIL_B(uint16 u16Start)
{
   uint32 u32LocalChannel ;
   uint32 u32LocalValue ;

   /* Check if the channel is enabled or disabled */
   u32LocalChannel = IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B) ;
   u32LocalValue = IGNHAL_pstrAgcCOIL_B->ENDIS_STAT.U ;
   u32LocalChannel = 2U * u32LocalChannel ;
   u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;

   if(u32LocalValue == 0U)
   {
      IfxGtm_vidAtomEnableChannel( IGNHAL_pstrCOIL_B,
                                   IGNHAL_pstrAgcCOIL_B,
                                   IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B),
                                   IfxGtm_Atom_Level_Low
                                 );

      IfxGtm_vidAtomToPin( IGNHAL_COIL_B_TOUT_REG,
                           IGNHAL_COIL_B_TOUT_SEL,
                           (Ifx_P *)IGNHAL_COIL_B_PORT,
                           IGNHAL_COIL_B_PIN,
                           IGNHAL_COIL_B_GTM_TIMER
                         );

  }

   /* Set the ATOM channel to low and enable the channel */
   /* Enable the Notification function for start Angle */
   CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_COIL_B_CMD);
   /* At the compare match the Signal is output as High */
   CRKHAL_vidActivateAlarmMode(CRKHAL_u8ALARM_COIL_B_CMD, MODE_OUTPUT_1);
   /* Set the alarm to the required Start Angle */
   CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_COIL_B_CMD, u16Start);
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidCoilProg_COIL_C                                  */
/* !Description : API start the conduction of Coil C.                        */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidCoilProg_COIL_C(uint16 u16Start)
{
   uint32 u32LocalChannel ;
   uint32 u32LocalValue ;

   /* Check if the channel is enabled or disabled */
   u32LocalChannel = IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C) ;
   u32LocalValue = IGNHAL_pstrAgcCOIL_C->ENDIS_STAT.U ;
   u32LocalChannel = 2U * u32LocalChannel ;
   u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;

   if(u32LocalValue == 0U)
   {
      IfxGtm_vidAtomEnableChannel( IGNHAL_pstrCOIL_C,
                                   IGNHAL_pstrAgcCOIL_C,
                                   IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C),
                                   IfxGtm_Atom_Level_Low
                                 );

      IfxGtm_vidAtomToPin( IGNHAL_COIL_C_TOUT_REG,
                           IGNHAL_COIL_C_TOUT_SEL,
                           (Ifx_P *)IGNHAL_COIL_C_PORT,
                           IGNHAL_COIL_C_PIN,
                           IGNHAL_COIL_C_GTM_TIMER
                         );

   }

   /* Enable the Notification function for start Angle */
   CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_COIL_C_CMD);
   /* At the compare match the Signal is output as High */
   CRKHAL_vidActivateAlarmMode(CRKHAL_u8ALARM_COIL_C_CMD, MODE_OUTPUT_1);
   /* Set the alarm to the required Start Angle */
   CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_COIL_C_CMD, u16Start);
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidImmediateTrig_COIL_A                             */
/* !Description : API to start immediately conduction on a coil.             */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidImmediateTrig_COIL_A(void)
{
   uint32 u32LocalChannel ;
   uint32 u32LocalValue ;

   /* Check if the channel is enabled or disabled */
   u32LocalChannel = IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A) ;
   u32LocalValue = IGNHAL_pstrAgcCOIL_A->ENDIS_STAT.U ;
   u32LocalChannel = 2U * u32LocalChannel ;
   u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;
   if(u32LocalValue == 0U)
   {
      IfxGtm_vidAtomEnableChannel(  IGNHAL_pstrCOIL_A,
                                    IGNHAL_pstrAgcCOIL_A,
                                    IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A),
                                    IfxGtm_Atom_Level_Low
                                 );

      IfxGtm_vidAtomToPin( IGNHAL_COIL_A_TOUT_REG,
                           IGNHAL_COIL_A_TOUT_SEL,
                           (Ifx_P *)IGNHAL_COIL_A_PORT,
                           IGNHAL_COIL_A_PIN,
                           IGNHAL_COIL_A_GTM_TIMER
                         );

   }
   IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_A,(uint8)IfxGtm_Compare_Unit_1);
   IfxGtm_vidAtomSetCond_Immediate  (  IGNHAL_pstrCOIL_A,
                                       GTM_TBU_ANGLE,
                                       INACTIVE_CCU0,
                                       (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                                       CCU1_ONLY_OUT_ACTIVE
                                    );
   it_bobine_a(1);
   /* clear the interrupt notify in the register */
   IfxGtm_vidAtomClearInterrupt(IGNHAL_pstrCOIL_A,(uint8)IfxGtm_Compare_Unit_1);
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_A, (uint8)IfxGtm_Compare_Unit_1);
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidImmediateTrig_COIL_B                             */
/* !Description : API to start immediately conduction on a coil.             */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidImmediateTrig_COIL_B(void)
{
   uint32 u32LocalChannel ;
   uint32 u32LocalValue ;

   /* Check if the channel is enabled or disabled */
   u32LocalChannel = IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B) ;
   u32LocalValue = IGNHAL_pstrAgcCOIL_B->ENDIS_STAT.U ;
   u32LocalChannel = 2U * u32LocalChannel ;
   u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;
   if(u32LocalValue == 0U)
   {
      IfxGtm_vidAtomEnableChannel(  IGNHAL_pstrCOIL_B,
                                    IGNHAL_pstrAgcCOIL_B,
                                    IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B),
                                    IfxGtm_Atom_Level_Low
                                 );

      IfxGtm_vidAtomToPin( IGNHAL_COIL_B_TOUT_REG,
                           IGNHAL_COIL_B_TOUT_SEL,
                           (Ifx_P *)IGNHAL_COIL_B_PORT,
                           IGNHAL_COIL_B_PIN,
                           IGNHAL_COIL_B_GTM_TIMER
                         );

   }
   IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_B,(uint8)IfxGtm_Compare_Unit_1);
   IfxGtm_vidAtomSetCond_Immediate  (  IGNHAL_pstrCOIL_B,
                                       GTM_TBU_ANGLE,
                                       INACTIVE_CCU0,
                                       (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                                       CCU1_ONLY_OUT_ACTIVE
                                    );
   it_bobine_b(1);
   /* clear the interrupt notify in the register */
   IfxGtm_vidAtomClearInterrupt(IGNHAL_pstrCOIL_B,(uint8)IfxGtm_Compare_Unit_1);
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_B, (uint8)IfxGtm_Compare_Unit_1);
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidImmediateTrig_COIL_C                             */
/* !Description : API to start immediately conduction on a coil.             */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidImmediateTrig_COIL_C(void)
{
   uint32 u32LocalChannel ;
   uint32 u32LocalValue ;

   /* Check if the channel is enabled or disabled */
   u32LocalChannel = IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C) ;
   u32LocalValue = IGNHAL_pstrAgcCOIL_C->ENDIS_STAT.U ;
   u32LocalChannel = 2U * u32LocalChannel ;
   u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;
   if(u32LocalValue == 0U)
   {
      IfxGtm_vidAtomEnableChannel(  IGNHAL_pstrCOIL_C,
                                    IGNHAL_pstrAgcCOIL_C,
                                    IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C),
                                    IfxGtm_Atom_Level_Low
                                 );

      IfxGtm_vidAtomToPin( IGNHAL_COIL_C_TOUT_REG,
                           IGNHAL_COIL_C_TOUT_SEL,
                           (Ifx_P *)IGNHAL_COIL_C_PORT,
                           IGNHAL_COIL_C_PIN,
                           IGNHAL_COIL_C_GTM_TIMER
                         );

   }
   IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_C,(uint8)IfxGtm_Compare_Unit_1);
   IfxGtm_vidAtomSetCond_Immediate  (  IGNHAL_pstrCOIL_C,
                                       GTM_TBU_ANGLE,
                                       INACTIVE_CCU0,
                                       (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                                       CCU1_ONLY_OUT_ACTIVE
                                    );
   it_bobine_c(1);
   /* clear the interrupt notify in the register */
   IfxGtm_vidAtomClearInterrupt(IGNHAL_pstrCOIL_C,(uint8)IfxGtm_Compare_Unit_1);
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_C, (uint8)IfxGtm_Compare_Unit_1);
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_u16ReadStartCntr_COIL_A                             */
/* !Description : API to read the current counter value of Coil A.           */
/*                                                                           */
/*****************************************************************************/
uint16 IGNHAL_u16ReadStartCntr_COIL_A(void)
{
   return(CRKHAL_u16ReadCounter(CRKHAL_u8ALARM_COIL_A_CMD));
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_u16ReadStartCntr_COIL_B                             */
/* !Description : API to read the current counter value of Coil B.           */
/*                                                                           */
/*****************************************************************************/
uint16 IGNHAL_u16ReadStartCntr_COIL_B(void)
{
   return(CRKHAL_u16ReadCounter(CRKHAL_u8ALARM_COIL_B_CMD));
}
/*****************************************************************************/
/* !FuncName    : IGNHAL_u16ReadStartCntr_COIL_C                             */
/* !Description : API to read the current counter value of Coil C.           */
/*                                                                           */
/*****************************************************************************/
uint16 IGNHAL_u16ReadStartCntr_COIL_C(void)
{
   return(CRKHAL_u16ReadCounter(CRKHAL_u8ALARM_COIL_C_CMD));
}

/*****************************************************************************/
/* !FuncName    : IGNHAL_vidDiagIsr_COIL_A                                   */
/* !Description : ISR function for diagnostics on  Coil A                    */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidDiagIsr_COIL_A(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal)
{
   COMPILER_UNUSED_PARAMETER(ModuleType);
   COMPILER_UNUSED_PARAMETER(ModuleNo);
   COMPILER_UNUSED_PARAMETER(ChannelNo);
   it_diag_ccbat_bobine_a(IrqNotifVal);
}
/*****************************************************************************/
/* !FuncName    : IGNHAL_vidDiagIsr_COIL_B                                   */
/* !Description : ISR function for diagnostics on  Coil B                    */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidDiagIsr_COIL_B(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal)
{
   COMPILER_UNUSED_PARAMETER(ModuleType);
   COMPILER_UNUSED_PARAMETER(ModuleNo);
   COMPILER_UNUSED_PARAMETER(ChannelNo);
   it_diag_ccbat_bobine_b(IrqNotifVal);
}
/*****************************************************************************/
/* !FuncName    : IGNHAL_vidDiagIsr_COIL_C                                   */
/* !Description : ISR function for diagnostics on  Coil C                    */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidDiagIsr_COIL_C(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal)
{
   COMPILER_UNUSED_PARAMETER(ModuleType);
   COMPILER_UNUSED_PARAMETER(ModuleNo);
   COMPILER_UNUSED_PARAMETER(ChannelNo);
   it_diag_ccbat_bobine_c(IrqNotifVal);
}
/*****************************************************************************/
/* !FuncName    : IGNHAL_vidDiagIsr_COIL_D                                   */
/* !Description : ISR function for diagnostics on  Coil D                    */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidDiagIsr_COIL_D(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal)
{
   COMPILER_UNUSED_PARAMETER(ModuleType);
   COMPILER_UNUSED_PARAMETER(ModuleNo);
   COMPILER_UNUSED_PARAMETER(ChannelNo);
   COMPILER_UNUSED_PARAMETER(IrqNotifVal);
}

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


/*------------------------------ end of file ---------------------------------*/
