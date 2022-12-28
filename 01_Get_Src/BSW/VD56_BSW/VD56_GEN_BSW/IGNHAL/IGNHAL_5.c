/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_5.c                                              */
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
 * %PID: P2017_BSW:A30392.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "IGNHAL_gtm_Cfg.h"
#include "IGNHAL_I.h"
#include "SWFAIL.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : it_bobine_a                                                */
/* !Description : Call back function of Conduction for Coil A.               */
/*                                                                           */
/******************************************************************************/
void it_bobine_a(uint16 IrqNotifVal)
{
   if (IrqNotifVal == 0x00)
   {
      it_fin_de_conduction_bobine_a();
   }
   else
   {
      /* Start of conduction callback */
      if (IGNHAL_u8EVENT_T0_T1 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A])
      {
         it_ocr_bobine_a();
      }
      else
      {
         it_fin_de_conduction_bobine_a();
      }
   }
}
/******************************************************************************/
/* !FuncName    : it_bobine_b                                                */
/* !Description : Call back function of Conduction for Coil B.               */
/*                                                                           */
/******************************************************************************/
void it_bobine_b(uint16 IrqNotifVal)
{
   if (IrqNotifVal == 0x00)
   {
      it_fin_de_conduction_bobine_b();
   }
   else
   {
      /* Start of conduction callback */
      if (IGNHAL_u8EVENT_T0_T1 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B])
      {
         it_ocr_bobine_b();
      }
      else
      {
         it_fin_de_conduction_bobine_b();
      }
   }
}
/******************************************************************************/
/* !FuncName    : it_bobine_c                                                */
/* !Description : Call back function of Conduction for Coil C.               */
/*                                                                           */
/******************************************************************************/
void it_bobine_c(uint16 IrqNotifVal)
{
   if (IrqNotifVal == 0x00)
   {
      it_fin_de_conduction_bobine_c();
   }
   else
   {

      if (IGNHAL_u8EVENT_T0_T1 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C])
      {
         /* Start of conduction callback */
         it_ocr_bobine_c();
      }
      else
      {
         /* End of conduction callback */
         it_fin_de_conduction_bobine_c();
      }
   }
}
/******************************************************************************/
/* !FuncName    : it_ocr_bobine_a                                            */
/* !Description : Call back function of Start Conduction for Coil A.         */
/*                                                                           */
/******************************************************************************/
void it_ocr_bobine_a(void)
{
   switch (IGNHAL_ku8CoilPhysicMode)
   {
      case IGNHAL_u8JUMOPHYS_MODE:
         /* IGNHAL_vidOCR_IT_PROCESSING(COIL_A_C);*/
         break;

      case IGNHAL_u8MONOPHYS_MODE:
         IGNHAL_vidOCR_IT_PROCESSING(COIL_A);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/******************************************************************************/
/* !FuncName    : it_ocr_bobine_b                                            */
/* !Description : Call back function of Start Conduction for Coil B.         */
/*                                                                           */
/******************************************************************************/
void it_ocr_bobine_b(void)
{
   IGNHAL_vidOCR_IT_PROCESSING(COIL_B);
}
/******************************************************************************/
/* !FuncName    : it_ocr_bobine_c                                            */
/* !Description : Call back function of Start Conduction for Coil C.         */
/*                                                                           */
/******************************************************************************/
void it_ocr_bobine_c(void)
{
   IGNHAL_vidOCR_IT_PROCESSING(COIL_C);
}
/******************************************************************************/
/* !FuncName    : it_fin_de_conduction_bobine_a                              */
/* !Description : Call back function of End Conduction for Coil A.           */
/*                                                                           */
/******************************************************************************/
void it_fin_de_conduction_bobine_a(void)
{
   switch (IGNHAL_ku8CoilPhysicMode)
   {
      case IGNHAL_u8JUMOPHYS_MODE:
         /*  IGNHAL_vidEND_OF_CONDUCTION(COIL_A_C);*/
         break;

      case IGNHAL_u8MONOPHYS_MODE:
         IGNHAL_vidEND_OF_CONDUCTION(COIL_A);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/******************************************************************************/
/* !FuncName    : it_fin_de_conduction_bobine_b                              */
/* !Description : Call back function of End Conduction for Coil B.           */
/*                                                                           */
/******************************************************************************/
void it_fin_de_conduction_bobine_b(void)
{
   IGNHAL_vidEND_OF_CONDUCTION(COIL_B);
}
/******************************************************************************/
/* !FuncName    : it_fin_de_conduction_bobine_c                              */
/* !Description : Call back function of End Conduction for Coil C.           */
/*                                                                           */
/******************************************************************************/
void it_fin_de_conduction_bobine_c(void)
{
   IGNHAL_vidEND_OF_CONDUCTION(COIL_C);
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConduction_start_a                               */
/* !Description : API handles the Start Conduction for Coil A.               */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConduction_start_a(void)
{
   /* Set the angle and Time condition and set the output to low
    * on a angle or time match on the channel connected to coil.
    * Diagnostics channel :
    */
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_A, (uint8)IfxGtm_Compare_Unit_0);

   /* Serve First and the Output set to 0 on compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_A,
                         (uint32)IGNHAL_au16EndAngle[IGNHAL_u8COIL_A],
                         (IGNHAL_au32WdgDelay[IGNHAL_u8COIL_A]
                          + IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_A]) & (0x00FFFFFFU),
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_INACT
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConduction_start_b                               */
/* !Description : API handles the Start Conduction for Coil B.               */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConduction_start_b(void)
{
   /* Set the angle and Time condition and set the output to low
    * on a angle or time match on the channel connected to coil.
    * Diagnostics channel :
    */
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_B, (uint8)IfxGtm_Compare_Unit_0);

   /* Serve First and the Output set to 0 on compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_B,
                         (uint32)IGNHAL_au16EndAngle[IGNHAL_u8COIL_B],
                         (IGNHAL_au32WdgDelay[IGNHAL_u8COIL_B]
                          + IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_B]) & (0x00FFFFFFU),
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_INACT
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConduction_start_c                               */
/* !Description : API handles the Start Conduction for Coil C.               */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConduction_start_c(void)
{
   /* Set the angle and Time condition and set the output to low
    * on a angle or time match on the channel connected to coil.
    * Diagnostics channel :
    */
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_C, (uint8)IfxGtm_Compare_Unit_0);

   /* Serve First and the Output set to 0 on compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_C,
                         (uint32)(IGNHAL_au16EndAngle[IGNHAL_u8COIL_C]),
                         (IGNHAL_au32WdgDelay[IGNHAL_u8COIL_C]
                          + IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_C]) & (0x00FFFFFFU),
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_INACT
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidDisableWtdgNotif                          */
/* !Description : API disables the notification on the Coils.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidDisableWtdgNotif(uint8 u8Coil)
{
   switch (u8Coil)
   {
      case IGNHAL_u8COIL_A:
         IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_A, \
                                           (uint8)IfxGtm_Compare_Unit_0);
         break;

      case IGNHAL_u8COIL_B:
         IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_B, \
                                           (uint8)IfxGtm_Compare_Unit_0);
         break;

      case IGNHAL_u8COIL_C:
         IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_C, \
                                           (uint8)IfxGtm_Compare_Unit_0);
         break;

      case IGNHAL_u8COIL_D:
         /* IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_D,(uint8)IfxGtm_Compare_Unit_0); */
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidDisableCmd                                        */
/*                                                                            */
/* !Description : Disables ATOM channels.                                     */
/******************************************************************************/
void IGNHAL_vidDisableCmd(uint8 u8Coil)
{
   switch (u8Coil)
   {
      case IGNHAL_u8COIL_A:
         IfxGtm_vidAtomDisableChannel
         (
            IGNHAL_pstrCOIL_A,
            IGNHAL_pstrAgcCOIL_A,
            IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A),
            IfxGtm_Atom_Level_High
         );
         IfxGtm_vidAtomToPinDisconnect( IGNHAL_COIL_A_TOUT_REG,
                                        IGNHAL_COIL_A_TOUT_SEL,
                                        (Ifx_P *)IGNHAL_COIL_A_PORT,
                                        IGNHAL_COIL_A_PIN,
                                        0U);
         break;

      case IGNHAL_u8COIL_B:
         IfxGtm_vidAtomDisableChannel
         (
            IGNHAL_pstrCOIL_B,
            IGNHAL_pstrAgcCOIL_B,
            IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B),
            IfxGtm_Atom_Level_High
         );
         IfxGtm_vidAtomToPinDisconnect( IGNHAL_COIL_B_TOUT_REG,
                                        IGNHAL_COIL_B_TOUT_SEL,
                                        (Ifx_P *)IGNHAL_COIL_B_PORT,
                                        IGNHAL_COIL_B_PIN,
                                        0U);
         break;

      case IGNHAL_u8COIL_C:
         IfxGtm_vidAtomDisableChannel
         (
            IGNHAL_pstrCOIL_C,
            IGNHAL_pstrAgcCOIL_C,
            IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C),
            IfxGtm_Atom_Level_High
         );
         IfxGtm_vidAtomToPinDisconnect( IGNHAL_COIL_C_TOUT_REG,
                                        IGNHAL_COIL_C_TOUT_SEL,
                                        (Ifx_P *)IGNHAL_COIL_C_PORT,
                                        IGNHAL_COIL_C_PIN,
                                        0U);
         break;

      case IGNHAL_u8COIL_D:
         /* IfxGtm_vidAtomDisableChannel(IGNHAL_pstrCOIL_D,IGNHAL_pstrAgcCOIL_D);*/
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
