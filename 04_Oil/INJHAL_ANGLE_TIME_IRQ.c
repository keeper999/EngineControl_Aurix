/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : Injection Hardware Abstraction Layer                    */
/*                                                                            */
/* !File            : INJHAL_ANGLE_TIME_IRQ.c                                 */
/* !Description     : Configuration of the INJHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#include "Std_Types.h"

#include "INJHAL.h"
#include "INJHAL_I.h"

#define ATOM_CCU_1_IRQ  (1U)

#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"
/*lint -save -e934 */
/*****************************************************************************/
/* !FuncName    : INJHAL_vidAngleTimeNotif_CM_66*/
/* !Description : Angle notification function                                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidAngleTimeNotif_CM_66(uint16 IrqNotifVal)
{
   if (IrqNotifVal == ATOM_CCU_1_IRQ)
   {
      /* Angle(CCU1) Match */
      if (  ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_66_INSTANCE_ID]
            == (uint8)INJHAL_enuCOMP_SEQ_INJ )
         || (  ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_66_INSTANCE_ID]
               == (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ )
            && ( INJHAL_aenuInjectorMode[INJHAL_u8SN_CM_66_CHANNEL_ID]
               == (uint8)INJHAL_enuINJ_MODE_NORMAL) ) )
      {
         /** -------------------------------------------
         * (STEP5): Sequential Injection Angular Match 
         * --------------------------------------------
         *  This point (Angular Match) is reached when:
         *  1. The Injection "i" reached the start angle
         *  (INJHAL_au16InjectionAngle[i][SN_CM_66]).
         *  In this case the pulse Width needs to be setup and also the
         *  next injection starting angle  shall be taking into account
         *  to manage overlaps (SERVE FIRST)
         *
         *  2. There was an overlap between the pulse "i" and the "i+1".
         *  The Pulse "i" duration needs to be Extended
         *  (INJHAL_au32InjectionTime[i][SN_CM_66] + 
         *   INJHAL_au32InjectionTime[i+1][SN_CM_66]).
         */
         do
         {
           INJHAL_vidWRITE_ANGLE_NOTIF(SN_CM_66);
         }while(INJHAL_au8AngleMatch[INJHAL_u8SN_CM_66_CHANNEL_ID] == 1U) ;
      }
      else
      {
         if (INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_66_INSTANCE_ID] == 
              (uint8)INJHAL_enuCOMP_BEFORE_PRE_INJ)
         {
            /**---------------------------------------------------------------
            * * (STEP1) PRE-INJECTION FG MANAGEMENT
               * -------------------------------------------------------------
            * At this point, the FG pre-injection start Angle
            * (INJHAL_au16ProgAngleForPreInj[INJHAL_u8SN_CM_66_INSTANCE_ID])
            * has been reached and the Pre-injections signals,
            * for the "M" Injectors have been already started (enabled in the
            * INJHAL_vidEnable). The function INJHAL_vidFGPreinjManagement is
            * used to setup the closing condition for all the Injectors
            * (Pulse Width). Once that the time condition has been met,
            * the INJHAL_vidAngleTimeNotif_CM_66 is called again,
            * but this time there is not an Angular Match
            * (currCh->atomIrqNotify->B.CCU1TC), but a time match
            * (currCh->atomIrqNotify->B.CCU0TC, see STEP2).
            * The INJHAL_vidEND_OF_PULSE_NOTIF() macro is used to setup
            * the Sequential Pre-Injection Starting Angle for the current
            * Injector, or, if the Seq. Pre-Inj is not available the "normal"
            * Sequential Injector will start
            */
            INJHAL_vidFGPreinjManagement(INJHAL_u8SN_CM_66_INSTANCE_ID);
         }
         else
         {
            if (INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_66_INSTANCE_ID] == 
                (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ)
            {
               /**---------------------------------------------------------------------
                * * (STEP3) SEQUENTIAL PRE-INJECTION MANAGEMENT
                * ---------------------------------------------------------------------
                * At this point, the Angle INJHAL_u16SeqPreInjAngle[SN_CM_66] for 
                * the current injector, has been reached.
                * The INJHAL_vidSEQ_PREINJ_MANAGEMENT(SN_CM_66) shall be used to 
                * setup the closing condition (Time Condition) 
                * On the time match, the INJHAL_vidAngleTimeNotif_CM_66 
                * is called again (STEP4), and
                * the INJHAL_vidEND_OF_PULSE_NOTIF_Ifx macro is used to setup the SEQ. Injection */
               INJHAL_vidSEQ_PREINJ_MANAGEMENT(SN_CM_66);
            }
         }
      }
   }
   else
   {
      /* Time(CCU0) Match */
      /** -----------------------------------------------------------------------
       * STEP2 And STEP4
       * ------------------------------------------------------------------------
       * STEP2: The FG Pre-Injection is terminated (reached)
       * The Seq.Pre Injection shall be started (if enabled and if CRK synch)
       * If the CRK is not yet synchronized, the driver need to wait for
       * the INJHAL_vidCrkSyncFoundEntry event.
       * If the Seq. Pre-Inj is not enabled,........
       *-------------------------------------------------------------------------
       * STEP4: The Seq. Pre-Injection is terminated 
       *  The Seq. Injection can be started
       *  for each Injector, it is necessary to call only one time the 
       *  INJHAL_vidPROG_NEXT_INJ. To start a Train of Injections (Mode-N)
       *  The INJHAL_vidPROG_NEXT_INJ shall program the current injector 
       *  starting angle    
       *
       */
      /** (STEP6) The i-th Injection Pulse has reached its due time,
       * so the next Injection starting Angle needs to be set.
       * Set the INJHAL_au16NoOverLap[ ] flag to indicate no overlap
       * has happened , Force the output to inactive, using a
       * dummy comparison with a Time event in the past.
       * After that set the
       */
      INJHAL_vidEND_OF_PULSE_NOTIF(SN_CM_66);
   }
}

/*****************************************************************************/
/* !FuncName    : INJHAL_vidAngleTimeNotif_CM_45*/
/* !Description : Angle notification function                                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidAngleTimeNotif_CM_45(uint16 IrqNotifVal)
{
   if (IrqNotifVal == ATOM_CCU_1_IRQ)
   {
      /* Angle(CCU1) Match */
      if (  ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_45_INSTANCE_ID]
            == (uint8)INJHAL_enuCOMP_SEQ_INJ )
         || (  ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_45_INSTANCE_ID]
               == (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ )
            && ( INJHAL_aenuInjectorMode[INJHAL_u8SN_CM_45_CHANNEL_ID]
               == (uint8)INJHAL_enuINJ_MODE_NORMAL) ) )
      {
         /** -------------------------------------------
         * (STEP5): Sequential Injection Angular Match 
         * --------------------------------------------
         *  This point (Angular Match) is reached when:
         *  1. The Injection "i" reached the start angle
         *  (INJHAL_au16InjectionAngle[i][SN_CM_45]).
         *  In this case the pulse Width needs to be setup and also the
         *  next injection starting angle  shall be taking into account
         *  to manage overlaps (SERVE FIRST)
         *
         *  2. There was an overlap between the pulse "i" and the "i+1".
         *  The Pulse "i" duration needs to be Extended
         *  (INJHAL_au32InjectionTime[i][SN_CM_45] + 
         *   INJHAL_au32InjectionTime[i+1][SN_CM_45]).
         */
         do
         {
           INJHAL_vidWRITE_ANGLE_NOTIF(SN_CM_45);
         }while(INJHAL_au8AngleMatch[INJHAL_u8SN_CM_45_CHANNEL_ID] == 1U) ;
      }
      else
      {
         if ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_45_INSTANCE_ID] == 
               (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ)
         {
            /**---------------------------------------------------------------------
             * * (STEP3) SEQUENTIAL PRE-INJECTION MANAGEMENT
             * ---------------------------------------------------------------------
             * At this point, the Angle INJHAL_u16SeqPreInjAngle[SN_CM_45] for 
             * the current injector, has been reached.
             * The INJHAL_vidSEQ_PREINJ_MANAGEMENT(SN_CM_45) shall be used to 
             * setup the closing condition (Time Condition) 
             * On the time match, the INJHAL_vidAngleTimeNotif_CM_45 
             * is called again (STEP4), and
             * the INJHAL_vidEND_OF_PULSE_NOTIF_Ifx macro is used to setup the SEQ. Injection */
            INJHAL_vidSEQ_PREINJ_MANAGEMENT(SN_CM_45);
         }
      }
   }
   else
   {
      /* Time(CCU0) Match */
      /** -----------------------------------------------------------------------
       * STEP2 And STEP4
       * ------------------------------------------------------------------------
       * STEP2: The FG Pre-Injection is terminated (reached)
       * The Seq.Pre Injection shall be started (if enabled and if CRK synch)
       * If the CRK is not yet synchronized, the driver need to wait for
       * the INJHAL_vidCrkSyncFoundEntry event.
       * If the Seq. Pre-Inj is not enabled,........
       *-------------------------------------------------------------------------
       * STEP4: The Seq. Pre-Injection is terminated 
       *  The Seq. Injection can be started
       *  for each Injector, it is necessary to call only one time the 
       *  INJHAL_vidPROG_NEXT_INJ. To start a Train of Injections (Mode-N)
       *  The INJHAL_vidPROG_NEXT_INJ shall program the current injector 
       *  starting angle    
       *
       */
      /** (STEP6) The i-th Injection Pulse has reached its due time,
       * so the next Injection starting Angle needs to be set.
       * Set the INJHAL_au16NoOverLap[ ] flag to indicate no overlap
       * has happened , Force the output to inactive, using a
       * dummy comparison with a Time event in the past.
       * After that set the
       */
      INJHAL_vidEND_OF_PULSE_NOTIF(SN_CM_45);
   }
}

/*****************************************************************************/
/* !FuncName    : INJHAL_vidAngleTimeNotif_CM_24*/
/* !Description : Angle notification function                                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidAngleTimeNotif_CM_24(uint16 IrqNotifVal)
{
   if (IrqNotifVal == ATOM_CCU_1_IRQ)
   {
      /* Angle(CCU1) Match */
      if (  ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_24_INSTANCE_ID]
            == (uint8)INJHAL_enuCOMP_SEQ_INJ )
         || (  ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_24_INSTANCE_ID]
               == (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ )
            && ( INJHAL_aenuInjectorMode[INJHAL_u8SN_CM_24_CHANNEL_ID]
               == (uint8)INJHAL_enuINJ_MODE_NORMAL) ) )
      {
         /** -------------------------------------------
         * (STEP5): Sequential Injection Angular Match 
         * --------------------------------------------
         *  This point (Angular Match) is reached when:
         *  1. The Injection "i" reached the start angle
         *  (INJHAL_au16InjectionAngle[i][SN_CM_24]).
         *  In this case the pulse Width needs to be setup and also the
         *  next injection starting angle  shall be taking into account
         *  to manage overlaps (SERVE FIRST)
         *
         *  2. There was an overlap between the pulse "i" and the "i+1".
         *  The Pulse "i" duration needs to be Extended
         *  (INJHAL_au32InjectionTime[i][SN_CM_24] + 
         *   INJHAL_au32InjectionTime[i+1][SN_CM_24]).
         */
         do
         {
           INJHAL_vidWRITE_ANGLE_NOTIF(SN_CM_24);
         }while(INJHAL_au8AngleMatch[INJHAL_u8SN_CM_24_CHANNEL_ID] == 1U) ;
      }
      else
      {
         if ( INJHAL_aenuInjComponentStatus[INJHAL_u8SN_CM_24_INSTANCE_ID] == 
               (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ)
         {
            /**---------------------------------------------------------------------
             * * (STEP3) SEQUENTIAL PRE-INJECTION MANAGEMENT
             * ---------------------------------------------------------------------
             * At this point, the Angle INJHAL_u16SeqPreInjAngle[SN_CM_24] for 
             * the current injector, has been reached.
             * The INJHAL_vidSEQ_PREINJ_MANAGEMENT(SN_CM_24) shall be used to 
             * setup the closing condition (Time Condition) 
             * On the time match, the INJHAL_vidAngleTimeNotif_CM_24 
             * is called again (STEP4), and
             * the INJHAL_vidEND_OF_PULSE_NOTIF_Ifx macro is used to setup the SEQ. Injection */
            INJHAL_vidSEQ_PREINJ_MANAGEMENT(SN_CM_24);
         }
      }
   }
   else
   {
      /* Time(CCU0) Match */
      /** -----------------------------------------------------------------------
       * STEP2 And STEP4
       * ------------------------------------------------------------------------
       * STEP2: The FG Pre-Injection is terminated (reached)
       * The Seq.Pre Injection shall be started (if enabled and if CRK synch)
       * If the CRK is not yet synchronized, the driver need to wait for
       * the INJHAL_vidCrkSyncFoundEntry event.
       * If the Seq. Pre-Inj is not enabled,........
       *-------------------------------------------------------------------------
       * STEP4: The Seq. Pre-Injection is terminated 
       *  The Seq. Injection can be started
       *  for each Injector, it is necessary to call only one time the 
       *  INJHAL_vidPROG_NEXT_INJ. To start a Train of Injections (Mode-N)
       *  The INJHAL_vidPROG_NEXT_INJ shall program the current injector 
       *  starting angle    
       *
       */
      /** (STEP6) The i-th Injection Pulse has reached its due time,
       * so the next Injection starting Angle needs to be set.
       * Set the INJHAL_au16NoOverLap[ ] flag to indicate no overlap
       * has happened , Force the output to inactive, using a
       * dummy comparison with a Time event in the past.
       * After that set the
       */
      INJHAL_vidEND_OF_PULSE_NOTIF(SN_CM_24);
   }
}


/*lint -restore*/
#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
