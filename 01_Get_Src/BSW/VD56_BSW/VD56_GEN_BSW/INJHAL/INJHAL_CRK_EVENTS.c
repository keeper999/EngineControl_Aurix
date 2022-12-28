/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_CRK_EVENTS.c                                     */
/* !Description     : INJHAL Crank Call backs                                 */
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
 * %PID: P2017_BSW:A26590.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#include "CRKHAL.h"
#include "INJHAL.h"
#include "INJHAL_CFG_I.h"
#include "SchM_INJHAL.h"
#include "SWFAIL.h"

#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

/*lint -save -e934 */
/******************************************************************************/
/* !FuncName    : INJHAL_vidCrkSyncLostEntry                                  */
/* !Description : Call back function when the Crank has lost the synch        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidCrkSyncLostEntry
(
   uint8 u8InstanceId
)
{
   uint8 u8LocalChannelIndex;
   uint8 u8LocalChannelForLoopStart;
   uint8 u8LocalChannelForLoopEnd;
   uint8 u8LocalInjCompStatus;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      u8LocalInjCompStatus = INJHAL_aenuInjComponentStatus[u8InstanceId];

      INJHAL_vidGetForLoopConditions(u8InstanceId,
                                     &u8LocalChannelForLoopStart,
                                     &u8LocalChannelForLoopEnd);

      if (  (u8LocalInjCompStatus == INJHAL_enuCOMP_SEQ_INJ)
         || (u8LocalInjCompStatus == INJHAL_enuCOMP_SEQ_PRE_INJ))
      {
         INJHAL_vidCfgInitAllInjectors(u8InstanceId);

         for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/;
              u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
              u8LocalChannelIndex ++)
         {
            if (  INJHAL_aenuInjectorMode[u8LocalChannelIndex]
               != INJHAL_enuINJ_MODE_DISABLED)
            {
               INJHAL_aenuInjectorMode[u8LocalChannelIndex] =
                  INJHAL_enuINJ_MODE_NORMAL;
            }
         }
         INJHAL_aenuInjComponentStatus[u8InstanceId] =
            INJHAL_enuCOMP_WAITING_SYNCHRO;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidCrkSyncFoundEntry                                 */
/* !Description : Call back function when the Crank has found the synch       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidCrkSyncFoundEntry
(
   uint8 u8InstanceId
)
{
   uint8   u8LocalChannelIndex;
   uint8   u8LocalChannelForLoopStart;
   uint8   u8LocalChannelForLoopEnd;
   uint8   u8LocalInjCompStatus;
   uint16  u16LocalAbsoluteAngle;
   boolean bLocalEndAngTreated;
   boolean bLocalNormalInjectorMode;
   boolean bLocalEndAngReady;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      u8LocalInjCompStatus = INJHAL_aenuInjComponentStatus[u8InstanceId];

      INJHAL_vidGetForLoopConditions(u8InstanceId,
                                     &u8LocalChannelForLoopStart,
                                     &u8LocalChannelForLoopEnd);

      INJHAL_vidCfgInitWaitSynchro(u8InstanceId);
      INJHAL_abFGPreInjStartAngReady[u8InstanceId] = (boolean)TRUE;

      switch (u8LocalInjCompStatus)
      {
         /* FG pre injection is over and waiting to start sequential
          * pre injection. INJHAL_enuCOMP_WAITING_SYNCHRO.
          */
         case INJHAL_enuCOMP_WAITING_SYNCHRO:
            bLocalNormalInjectorMode = (boolean)FALSE;

            for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/;
                 u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
                 u8LocalChannelIndex ++)
            {
               if (  INJHAL_aenuInjectorMode[u8LocalChannelIndex]
                  == INJHAL_enuINJ_MODE_NORMAL)
               {
                  bLocalNormalInjectorMode = (boolean)TRUE;
               }
            }

            if (  (bLocalNormalInjectorMode == (boolean)FALSE)
               && (INJHAL_abEnableSeqPreInj[u8InstanceId] != (boolean)FALSE))
            {
            /* If sequential pre injection is enabled */
               INJHAL_aenuInjComponentStatus[u8InstanceId] =
                  INJHAL_enuCOMP_SEQ_PRE_INJ;

              INJHAL_vidCfgWritePreInjSeqNotif(u8InstanceId);
            }
            else
            {
               /* Normal Mode , no sequential pre injection is needed */
               INJHAL_aenuInjComponentStatus[u8InstanceId] =
                  INJHAL_enuCOMP_SEQ_INJ;
               for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/;
                    u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
                    u8LocalChannelIndex ++)
               {
                  if (  INJHAL_aenuInjectorMode[u8LocalChannelIndex]
                     != INJHAL_enuINJ_MODE_DISABLED)
                  {
                     INJHAL_aenuInjectorMode[u8LocalChannelIndex] =
                        INJHAL_enuINJ_MODE_NORMAL;
                  }
               }
               /* when status is INJHAL_enuCOMP_WAITING_SYNCHRO
                * All the next injections are started from here and not from
                * Angle_Time_Irq.c. Hence enable for all the injectors.
                */
               INJHAL_vidCfgProgNextInjections(u8InstanceId);
            }
            break;

         case INJHAL_enuCOMP_BEFORE_PRE_INJ: 
         case INJHAL_enuCOMP_FG_PRE_INJ:
         case INJHAL_enuCOMP_SEQ_PRE_INJ:
         case INJHAL_enuCOMP_SEQ_INJ:
            break;

         case INJHAL_enuCOMP_INIT:
            INJHAL_abFGPreInjStartAngReady[u8InstanceId] = (boolean)FALSE;
            break;

         default:
            INJHAL_abFGPreInjStartAngReady[u8InstanceId] = (boolean)FALSE;
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
      u16LocalAbsoluteAngle = INJHAL_au16ProgAngleForPreInj[u8InstanceId];

      /* update the Angle reference for the FG start Angle */
      INJHAL_vidUpdateAngleReference(&u16LocalAbsoluteAngle);
      INJHAL_au16ProgAngleForPreInj[u8InstanceId] = u16LocalAbsoluteAngle;

      SchM_Enter_INJHAL_ACCESS_006();
      bLocalEndAngTreated   = INJHAL_abEndOfPreInjTreated[u8InstanceId];
      bLocalEndAngReady     = INJHAL_abFGPreInjEndAngReady[u8InstanceId];
      u16LocalAbsoluteAngle = INJHAL_au16FGPreInjEndAngle[u8InstanceId];
      SchM_Exit_INJHAL_ACCESS_006();

      if (  (bLocalEndAngTreated != (boolean)FALSE)
         && (bLocalEndAngReady   == (boolean)FALSE))
      {
       /* update the end Angle for FG pre injection.
        * This is done only in case if the Synchronization
        * happens after the FG is complete.
        */
         INJHAL_vidUpdateAngleReference(&u16LocalAbsoluteAngle);
         INJHAL_au16FGPreInjEndAngle[u8InstanceId]  = u16LocalAbsoluteAngle;
         INJHAL_abFGPreInjEndAngReady[u8InstanceId] = (boolean)TRUE;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidUpdateAngleReference                              */
/* !Description : Update the reference of an angle from CRK detected to be    */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidUpdateAngleReference
(
   uint16* pu16Angle
)
{
   uint16         u16LocalDeltaAngleOnSynchro;
   uint32         u32LocalAbsoluteAngle;
   Std_ReturnType udtLocalStatus;


   udtLocalStatus = CRKHAL_udtGetDeltaAngleOnSync(&u16LocalDeltaAngleOnSynchro);
   if (udtLocalStatus != E_OK)
   {
      u16LocalDeltaAngleOnSynchro = (uint16)UINT16_MIN;
   }

   u32LocalAbsoluteAngle = (uint32)((uint32)*pu16Angle
                         + (uint32)(u16LocalDeltaAngleOnSynchro));
   if (u32LocalAbsoluteAngle >= INJHAL_u16ENGINE_CYCLE)
   {
      u32LocalAbsoluteAngle -= INJHAL_u16ENGINE_CYCLE;
   }
   *pu16Angle = (uint16)(u32LocalAbsoluteAngle);
}
/*lint -restore*/
#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
