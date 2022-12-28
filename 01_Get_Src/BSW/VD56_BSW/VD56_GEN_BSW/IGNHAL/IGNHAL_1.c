/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_1.c                                              */
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
 * %PID: P2017_BSW:A30393.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "ADCHAL.h"
#include "CRKHAL.h"
#include "IGNHAL.h"
#include "IGNHAL_E.h"
#include "IGNHAL_I.h"
#include "IGNHAL_L.h"
#include "SchM_IGNHAL.h"
#include "SWFAIL.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"


/*****************************************************************************/
/* !FuncName    : IGNHAL_vidCalcNextTeethRef                                 */
/* !Description : API to set the Alarm on the reference Teeth Angle.         */
/*                                                                           */
/*****************************************************************************/
void IGNHAL_vidCalcNextTeethRef(void)
{
   /* Setup an angular alarm on a next reference tooth detection for a next coil
    * in conduction order based on a value of IgnHALCoilToCommand variable.
    */
   switch (IgnHALCoilToCommand)
   {
      case IGNHAL_u8COIL_A:
         CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_IGN_REF_TEETH,
                               IGNHAL_u16COIL_B_REF_TOOTH_ANGLE);
         break;

      case IGNHAL_u8COIL_B:
         CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_IGN_REF_TEETH,
                               IGNHAL_u16COIL_C_REF_TOOTH_ANGLE);
         break;

      case IGNHAL_u8COIL_C:
         CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_IGN_REF_TEETH,
                               IGNHAL_u16COIL_A_REF_TOOTH_ANGLE);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*****************************************************************************/
/* !FuncName    : it_dent_ref                                                */
/* !Description : notification function of refence teeth .                   */
/*                                                                           */
/*****************************************************************************/
void it_dent_ref(void)
{
   /* to update IgnHALCoilToCommand variable */
   IGNHAL_vidRefreshCoilToCommand();
   switch (IGNHAL_ku8CoilPhysicMode)
   {
      case IGNHAL_u8JUMOPHYS_MODE:
         /*
            IGNHAL_vidCalcNextTeethRef();
            if (Interdit_trig_it_dent_ref == (boolean)TRUE)
            {
            Interdit_trig_it_dent_ref = (boolean)FALSE;
            }
            else
            {
            if (Trait_pmh_avance_glisse == (boolean)FALSE)
            {
               if (Avance_disponible != (boolean)FALSE)
               {
                  IGNHAL_u16AppliedAdvance = IgnHALAdvanceToApplicate;
                  IGNHAL_vidCurrentJumoCoilManager();
                  IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
                  IGNHAL_vidNextJumoCoilManager();
                  IGNHAL_vidALLOW_COIL_MNG();
                  Avance_disponible = (boolean)FALSE;
               }
               else
               {
                  IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
                  IGNHAL_vidCurrentJumoCoilManager();
                  Avance_disponible = (boolean)TRUE;
                  Trait_pmh_avance_glisse = (boolean)TRUE;
               }
            }
            else
            {
               IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
               IGNHAL_vidNextJumoCoilManager();
               IGNHAL_vidALLOW_COIL_MNG();
               Trait_pmh_avance_glisse = (boolean)FALSE;
            }
            }
          */
         break;

      case IGNHAL_u8MONOPHYS_MODE:
         /* set the alarm for the coil at the reference teeth */
         IGNHAL_vidCalcNextTeethRef();

         if (Interdit_trig_it_dent_ref == (boolean)TRUE)
         {
            /* Special case No 1: executed on reference tooth detection before the
             * notification of advance availability
             * On current cylinder we are commanding next coil in ignition order
             * On IGN_HAL_CYLINDER_A => IgnHALCoilToCommand == IGNHAL_u8COIL_C
             */
            Interdit_trig_it_dent_ref = (boolean)FALSE;
         }
         else
         {
            if (Trait_pmh_avance_glisse == (boolean)FALSE)
            {
               if (Avance_disponible != (boolean)FALSE)
               {
                  /* Normal case: executed on reference tooth detection with
                   * calculation of ignition advances already available
                   * Avance_disponible == TRUE
                   * Special case No 1: executed on notification of advance
                   * availability calling it_dent_ref from
                   * IGNHAL_vidCoilTdcAdvAvail Avance_disponible == TRUE
                   */
                  IGNHAL_u16AppliedAdvance = IgnHALAdvanceToApplicate;
                  IGNHAL_vidCurrentMonoCoilManager();
                  IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
                  IGNHAL_vidNextMonoCoilManager();
                  IGNHAL_vidALLOW_COIL_MNG();
                  Avance_disponible = (boolean)FALSE;
               }
               else
               {
                  /* Special case No 2: executed on reference tooth detection
                   * before the calculation of ignition advances
                   * Avance_disponible == FALSE
                   * Also before ASW call to IgnHALWriteAngle function
                   * Interdit_trig_it_dent_ref = FALSE
                   */
                  IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
                  IGNHAL_vidCurrentMonoCoilManager();
                  Avance_disponible       = (boolean)TRUE;
                  Trait_pmh_avance_glisse = (boolean)TRUE;
               }
            }
            else
            {
               /* Special case No 2: executed on notification of advance
                * availability calling it_dent_ref from IGNHAL_vidCoilTdcAdvAvail
                * Trait_pmh_avance_glisse == TRUE
                */
               IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
               IGNHAL_vidNextMonoCoilManager();
               IGNHAL_vidALLOW_COIL_MNG();
               Trait_pmh_avance_glisse = (boolean)FALSE;
            }
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_u8CoilToCommand / E                                  */
/*                                                                            */
/* !Description :  Get the coil to command depending on the                   */
/*                 engine position.                                           */
/******************************************************************************/
uint8 IGNHAL_u8CoilToCommand(void)
{
   uint8  u8CoilToCommand;
   uint16 u16AnglePosition;


   /* IGNHAL_u16TDC_OFFSET = 240° (angle between 2 TDCs) for 3 cylinder */
   u16AnglePosition = CRKHAL_u16ReadCounter(CRKHAL_u8ALARM_IGN_REF_TEETH);
   if ( ( (sint32)u16AnglePosition) < (sint32)IGNHAL_u16TDC_OFFSET)
   {
      u8CoilToCommand = IGNHAL_u8COIL_B;
   }
   else
   {
      if ( ( (sint32)u16AnglePosition) \
           < (sint32)( (2 * (sint32)IGNHAL_u16TDC_OFFSET) ) )
      {
         u8CoilToCommand = IGNHAL_u8COIL_C;
      }
      else
      {
         u8CoilToCommand = IGNHAL_u8COIL_A;
      }
   }
   return(u8CoilToCommand);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidCoilTdcAdvAvail / D                               */
/*                                                                            */
/* !Description :  Get the coil to command depending on the                   */
/*                 engine position.                                           */
/******************************************************************************/
void IGNHAL_vidCoilTdcAdvAvail(void)
{
   if (  (IgnHALMode != IGN_HAL_MODE_TEST)
      && (IGNHAL_bEnabled != (boolean)FALSE) )
   {
      if (Avance_disponible == (boolean)FALSE)
      {
         /* In normal case Avance_disponible == FALSE
          * set in it_dent_ref notification
          */
         Avance_disponible = (boolean)TRUE;
      }
      else
      {
         Avance_disponible = (boolean)FALSE;
      }
      SchM_Enter_IGNHAL_ACCESS_001();
      if (  (Avance_disponible != (boolean)FALSE) \
         && (Interdit_trig_it_dent_ref != (boolean)FALSE) )
      {
         /* In normal case: on availability of a current advance and before
          * reference tooth detection (it_dent_ref) we should enter this path.
          * After second call of ASW to IgnHALWriteAngle function to update
          * IgnHALNextAdvanceToApplicate for a next coil variable
          * Interdit_trig_it_dent_ref is set to TRUE!
          */
         Interdit_trig_it_dent_ref = (boolean)FALSE;
         SchM_Exit_IGNHAL_ACCESS_001();
      }
      else
      {
         Interdit_trig_it_dent_ref = (boolean)FALSE;
         CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_IGN_REF_TEETH);
         SchM_Exit_IGNHAL_ACCESS_001();
         it_dent_ref();
         CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_IGN_REF_TEETH);
      }
   }
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidCurrentMonoCoilManager / D                        */
/*                                                                            */
/* !Description :  Get the coil to command depending on the                   */
/*                 engine position.                                           */
/******************************************************************************/
void IGNHAL_vidCurrentMonoCoilManager(void)
{
   boolean bLocalCut;


   bLocalCut = IGNHAL_bCutManager(IgnHALCoilToCommand);
   if (bLocalCut == (boolean)FALSE)
   {
      IGNHAL_vidMONO_COIL_MANAGER(IgnHALCoilToCommand);
   }
   else
   {
      switch (IgnHALCoilToCommand)
      {
         case IGNHAL_u8COIL_A:
            IGNHAL_vidCOIL_CUT_OFF(COIL_A);
            break;

         case IGNHAL_u8COIL_B:
            IGNHAL_vidCOIL_CUT_OFF(COIL_B);
            break;

         case IGNHAL_u8COIL_C:
            IGNHAL_vidCOIL_CUT_OFF(COIL_C);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidNextMonoCoilManager / E                           */
/*                                                                            */
/* !Description :  Get the coil to command depending on the                   */
/*                 engine position.                                           */
/******************************************************************************/
void IGNHAL_vidNextMonoCoilManager(void)
{
   uint8   NextCoilToCommand;
   boolean bLocalCut;


   NextCoilToCommand = 1U + IgnHALCoilToCommand;
   if ( ( (sint32)NextCoilToCommand) >= ( (sint32)IGNHAL_ku8NumberOfCylinders) )
   {
      NextCoilToCommand = (uint8)UINT8_MIN;
   }
   bLocalCut = IGNHAL_bCutManager(NextCoilToCommand);
   if (bLocalCut == (boolean)FALSE)
   {
      IGNHAL_vidMONO_COIL_MANAGER(NextCoilToCommand);
   }
   else
   {
      switch (NextCoilToCommand)
      {
         case IGNHAL_u8COIL_A:
            IGNHAL_vidCOIL_CUT_OFF(COIL_A);
            break;

         case IGNHAL_u8COIL_B:
            IGNHAL_vidCOIL_CUT_OFF(COIL_B);
            break;

         case IGNHAL_u8COIL_C:
            IGNHAL_vidCOIL_CUT_OFF(COIL_C);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidCurrentJumoCoilManager / D                        */
/* !Description :  Get the coil to command depending on the                   */
/*                 engine position.                                           */
/******************************************************************************/
/*void IGNHAL_vidCurrentJumoCoilManager(void)
   {
   boolean bLocalCut;

   bLocalCut = IGNHAL_bCutManager(IgnHALCoilToCommand);
   if (bLocalCut == (boolean)FALSE)
   {
    IGNHAL_vidJUMO_COIL_MANAGER(IgnHALCoilToCommand);
   }
   else
   {
    switch (IgnHALCoilToCommand)
    {
      case IGNHAL_u8COIL_A:
      case IGNHAL_u8COIL_C:
        IGNHAL_vidCOIL_CUT_OFF(COIL_A_C);
        break;

      case IGNHAL_u8COIL_B:
      case IGNHAL_u8COIL_D:
        break;

      default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
   }
   }*/

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidNextJumoCoilManager / E                           */
/*                                                                            */
/* !Description :  Get the coil to command depending on the                   */
/*                 engine position.                                           */
/******************************************************************************/
/*void IGNHAL_vidNextJumoCoilManager(void)
   {
   uint8 NextCoilToCommand;
   boolean bLocalCut;

   NextCoilToCommand = 1U + IgnHALCoilToCommand;
   if (((sint32)NextCoilToCommand) >= ((sint32)IGNHAL_ku8NumberOfCylinders))
   {
    NextCoilToCommand = (uint8)UINT8_MIN;
   }
   bLocalCut = IGNHAL_bCutManager(NextCoilToCommand);
   if (bLocalCut == (boolean)FALSE)
   {
    IGNHAL_vidJUMO_COIL_MANAGER(NextCoilToCommand);
   }
   else
   {
    switch (NextCoilToCommand)
    {
      case IGNHAL_u8COIL_A:
      case IGNHAL_u8COIL_C:
        IGNHAL_vidCOIL_CUT_OFF(COIL_A_C);
        break;

      case IGNHAL_u8COIL_B:
      case IGNHAL_u8COIL_D:
        break;

      default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
   }
   }*/

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_bCutManager / C                                      */
/*                                                                            */
/* !Description :  Reads the Coil Cut Off status                              */
/******************************************************************************/
boolean IGNHAL_bCutManager
(
   uint8 u8Coil
)
{
   boolean bLocalCut;


   switch (u8Coil)
   {
      case IGNHAL_u8COIL_A:
         bLocalCut = IGNHAL_bCutCylinderA;
         break;

      case IGNHAL_u8COIL_B:
         bLocalCut = IGNHAL_bCutCylinderB;
         break;

      case IGNHAL_u8COIL_C:
         bLocalCut = IGNHAL_bCutCylinderC;
         break;

      /*    case IGNHAL_u8COIL_D:
            bLocalCut = IGNHAL_bCutCylinderD;
            break;*/

      default:
         bLocalCut = (boolean)FALSE;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   return(bLocalCut);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidPeriodicIgnVbrf / C                               */
/*                                                                            */
/* !Description :  Reads the Battery Volatge                                  */
/******************************************************************************/
void IGNHAL_vidPeriodicIgnVbrf(void)
{
   if (IGNHAL_bPeriodicIgnVbrfEna == (boolean)TRUE)
   {
      ADCHAL_vidEntry_IGN_EVENT();
   }
}


#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
