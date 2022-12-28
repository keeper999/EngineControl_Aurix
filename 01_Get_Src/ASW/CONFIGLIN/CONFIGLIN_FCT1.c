/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CONFIGLIN                                               */
/* !Description     : CONFIGLIN component                                     */
/*                                                                            */
/* !Module          : CONFIGLIN                                               */
/* !Description     : Configuration du reseau LIN                             */
/*                                                                            */
/* !File            : CONFIGLIN_FCT1.c                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CONFIGLIN_vidInit                                                    */
/*   2 / CONFIGLIN_vidReInitCondCheck                                         */
/*   3 / CONFIGLIN_vidLinScheduler                                            */
/*   4 / CONFIGLIN_vidDiagLinBlocked                                          */
/*   5 / CONFIGLIN_vidDiagAltAbsent                                           */
/*   6 / CONFIGLIN_vidDiagFrame                                               */
/*                                                                            */
/* !Reference   : V02 NT 09 04644 / 2                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "STD_TYPES.h"

#include "OSEK_NM.h"
#include "CONFIGLIN_im.h"
#include "CONFIGLIN_L.h"
#include "CONFIGLIN.h"
#include "GDGAR.h"
#include "VEMS.h"

#define CONFIGLIN_START_SEC_CODE
#include "Memmap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CONFIGLIN_vidInit                                          */
/* !Description :  This function initializes internal variables, outputs and  */
/*                 the NM for the LIN                                         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void StartNM(argin uint8 NetId);                              */
/*  extf argret void InitExtNodeMonitoring(argin uint8 NetId, argin uint8     */
/* NodeId, argin uint8 DeltaInc, argin uint8 DeltaDec);                       */
/*  extf argret void NM_vidSetNodesConfig(argin uint8 NetId, argout           */
/* tenuNMDiagConfig *aenuDiagConfig);                                         */
/*  input uint8 CONFIGLIN_u8IncEcmMute;                                       */
/*  input uint8 CONFIGLIN_u8DecEcmMute;                                       */
/*  input uint8 CONFIGLIN_u8IncAlt1Absent;                                    */
/*  input uint8 CONFIGLIN_u8DecAlt1Absent;                                    */
/*  input uint8 CONFIGLIN_u8IncAlt2Absent;                                    */
/*  input uint8 CONFIGLIN_u8DecAlt2Absent;                                    */
/*  output uint8 CONFIGLIN_u8Compteur;                                        */
/*  output boolean CONFIGLIN_bDgoLinBlocked;                                  */
/*  output boolean CONFIGLIN_bDgoAltAbsent;                                   */
/*  output boolean CONFIGLIN_bDiag_on_pred;                                   */
/*  output boolean CONFIGLIN_bMonRun;                                         */
/*  output uint8 CONFIGLIN_u8AltEcuCnt_prev;                                  */
/*  output uint8 CONFIGLIN_u8Cnt_prev[3];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidInit                                              */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidInit(void)
{
   tenuNMDiagConfig  aenuDiagConfig[NM_u8NB_NODES_N_LIN_E];
   uint8             u8LocalIndex;

   StartNM(N_LIN_E);

   /* Initialisation des variables internes */
   CONFIGLIN_u8Compteur = 0;
   CONFIGLIN_bDgoLinBlocked = FALSE;
   CONFIGLIN_bDgoAltAbsent = FALSE;
   CONFIGLIN_bDiag_on_pred = FALSE;
   CONFIGLIN_bMonRun = FALSE;
   CONFIGLIN_u8AltEcuCnt_prev = 0;

   InitExtNodeMonitoring(N_LIN_E, ECM_LIN, CONFIGLIN_u8IncEcmMute,
                         CONFIGLIN_u8DecEcmMute);
   InitExtNodeMonitoring(N_LIN_E, ETAT_ALT1_LIN, CONFIGLIN_u8IncAlt1Absent,
                         CONFIGLIN_u8DecAlt1Absent);
   InitExtNodeMonitoring(N_LIN_E, ETAT_ALT2_LIN, CONFIGLIN_u8IncAlt2Absent,
                         CONFIGLIN_u8DecAlt2Absent);

   for (u8LocalIndex = 0; u8LocalIndex < NM_u8NB_NODES_N_LIN_E; u8LocalIndex++)
   {
      aenuDiagConfig[u8LocalIndex] = E_HAL_NM_STOP;
      CONFIGLIN_u8Cnt_prev[u8LocalIndex] = 0;
   }

   NM_vidSetNodesConfig(N_LIN_E, aenuDiagConfig);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CONFIGLIN_vidReInitCondCheck                               */
/* !Description :  his function checks the variable Diag_on to enable or      */
/*                 disable the LIN NM.                                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void NM_vidSetNodesConfig(argin uint8 NetId, argout           */
/* tenuNMDiagConfig *aenuDiagConfig);                                         */
/*  input boolean Diag_on;                                                    */
/*  input boolean CONFIGLIN_bDiag_on_pred;                                    */
/*  output boolean CONFIGLIN_bMonRun;                                         */
/*  output boolean CONFIGLIN_bDiag_on_pred;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidReInitCondCheck                                   */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidReInitCondCheck(void)
{
   tenuNMDiagConfig  aenuDiagConfig[NM_u8NB_NODES_N_LIN_E];

   tenuNMDiagConfig  enuLocalDiagConfig;
   uint8             u8LocalIndex;
   boolean           bLocalDiagOn;

   VEMS_vidGET(Diag_on, bLocalDiagOn);

   if (bLocalDiagOn != CONFIGLIN_bDiag_on_pred)
   {
      if (bLocalDiagOn == FALSE)
      {
         enuLocalDiagConfig = E_HAL_NM_STOP;
         CONFIGLIN_bMonRun = FALSE;
      }
      else /*Diag_on = TRUE && DIAGCAN_bDiag_on_pred = FALSE */
      {
         enuLocalDiagConfig = E_HAL_NM_START_RESUME;
         CONFIGLIN_bMonRun = TRUE;
      }

      for (u8LocalIndex = 0;u8LocalIndex< NM_u8NB_NODES_N_LIN_E;u8LocalIndex++)
      {
         aenuDiagConfig[u8LocalIndex] = enuLocalDiagConfig;
      }

      NM_vidSetNodesConfig(N_LIN_E, aenuDiagConfig);
   }
   else
   {
      /* Do Nothing */
   }

   CONFIGLIN_bDiag_on_pred = bLocalDiagOn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CONFIGLIN_vidLinScheduler                                  */
/* !Description :  This function manages the NM of the LIN and schedules the  */
/*                 transmission and the reception of messages.                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void NM_vidSetNodesConfig(argin uint8 NetId, argout           */
/* tenuNMDiagConfig *aenuDiagConfig);                                         */
/*  extf argret void ISLIN_vidCmdeAlt();                                      */
/*  extf argret void SendMessage(argin uint16 Id_msg, argio uint8 *Ptr_msg);  */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Diag_on;                                                    */
/*  input st111 IsLin_stLin;                                                  */
/*  input uint8 CONFIGLIN_u8Compteur;                                         */
/*  output uint8 CONFIGLIN_u8Compteur;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidLinScheduler                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidLinScheduler(void)
{
   tenuNMDiagConfig  aenuDiagConfig[NM_u8NB_NODES_N_LIN_E];
   uint8             u8LocalBuffer[CONFIGLIN_u8RX_BUFFER_LENGTH];
   uint8             u8LocalIndex;
   uint8             u8LocalIsLinStLin;
   boolean           bLocalDiagOn;

   VEMS_vidGET(Diag_on, bLocalDiagOn);

   for (u8LocalIndex = 0;u8LocalIndex < CONFIGLIN_u8RX_BUFFER_LENGTH;
                                                                 u8LocalIndex++)
   {
      u8LocalBuffer[u8LocalIndex] = 0;
   }

   VEMS_vidGET(IsLin_stLin, u8LocalIsLinStLin);

   switch (u8LocalIsLinStLin)
   {
      case ISLIN_WAKEUPDONE:
         /*QAC Warning Msg(2:2215): Accepted  */
         if (bLocalDiagOn != FALSE)
         {
            for (u8LocalIndex =0;u8LocalIndex<NM_u8NB_NODES_N_LIN_E;
                                                                 u8LocalIndex++)
            {
               aenuDiagConfig[u8LocalIndex] = E_HAL_NM_START_RESUME;
            }
            NM_vidSetNodesConfig(N_LIN_E, aenuDiagConfig);
         }
         CONFIGLIN_u8Compteur = 0;
         break;

      case ISLIN_NORMAL:
         if ((CONFIGLIN_u8Compteur % 10) == 0)
         {
            ISLIN_vidCmdeAlt();
         }
         else if ((CONFIGLIN_u8Compteur % 10) == 5)
         {
            SendMessage(SN_ETAT_ALT1_HEADER, u8LocalBuffer);
         }
         else if (CONFIGLIN_u8Compteur == 6)
         {
            SendMessage(SN_ETAT_ALT2_HEADER, u8LocalBuffer);
         }
         else
         {
            /* Do Nothing */
         }

         CONFIGLIN_u8Compteur = (uint8)(CONFIGLIN_u8Compteur + 1);
         if (CONFIGLIN_u8Compteur >= 100)
         {
            CONFIGLIN_u8Compteur = 0;
         }
         break;

      case ISLIN_SHUTDOWNRQ:
         for (u8LocalIndex =0;u8LocalIndex<NM_u8NB_NODES_N_LIN_E;u8LocalIndex++)
         {
            aenuDiagConfig[u8LocalIndex] = E_HAL_NM_STOP;
         }
         NM_vidSetNodesConfig(N_LIN_E, aenuDiagConfig);
         break;

      case ISLIN_INIT:
      case ISLIN_WAKEUP:
      case ISLIN_SHUTDOWN:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CONFIGLIN_vidDiagLinBlocked                                */
/* !Description :  This function does the diagnostic of the default BUS LIN   */
/*                 BLOCKED.                                                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NM_vidGetCounters(argin uint8 NetId, argout uint8        */
/*  *au8AbsentCounter);                                                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CONFIGLIN_u8Cnt_prev[3];                                      */
/*  input boolean CONFIGLIN_bDgoLinBlocked;                                   */
/*  input boolean CONFIGLIN_bMonRun;                                          */
/*  output boolean CONFIGLIN_bDgoLinBlocked;                                  */
/*  output st114 CONFIGLIN_stBusBlockedStatus;                                */
/*  output uint8 CONFIGLIN_u8Cnt_prev[3];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidDiagLinBlocked                                    */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidDiagLinBlocked(void)
{
   uint8 au8LocalAbsentCounter[NM_u8NB_NODES_N_LIN_E + 1];

   NM_vidGetCounters(N_LIN_E, au8LocalAbsentCounter);

   if ((CONFIGLIN_u8Cnt_prev[ECM_LIN] > au8LocalAbsentCounter[ECM_LIN]) ||
       (au8LocalAbsentCounter[ECM_LIN] == 0))
   {
      CONFIGLIN_bDgoLinBlocked = FALSE;
      VEMS_vidSET(CONFIGLIN_stBusBlockedStatus, LIN_NO_BLOCKED);
      GDGAR_vidGdu(GD_DFT_LINBLOCKEDBUS,
                   CONFIGLIN_bDgoLinBlocked,
                   CONFIGLIN_bMonRun,
                   FALSE);
   }
   else if ((CONFIGLIN_u8Cnt_prev[ECM_LIN] < au8LocalAbsentCounter[ECM_LIN]) ||
            (au8LocalAbsentCounter[ECM_LIN] >= CONFIGLIN_u8C_MAX))
   {
      CONFIGLIN_bDgoLinBlocked = TRUE;
      GDGAR_vidGdu(GD_DFT_LINBLOCKEDBUS,
                   CONFIGLIN_bDgoLinBlocked,
                   CONFIGLIN_bMonRun,
                   FALSE);

      if (au8LocalAbsentCounter[ECM_LIN] < CONFIGLIN_u8C_MAX)
      {
         VEMS_vidSET(CONFIGLIN_stBusBlockedStatus, LIN_BLOCKED);
      }
      else
      {
         VEMS_vidSET(CONFIGLIN_stBusBlockedStatus, LIN_CONFIRMED_BLOCKED);
      }
   }
   else
   {
      /* Do Nothing */
   }

   CONFIGLIN_u8Cnt_prev[ECM_LIN] = au8LocalAbsentCounter[ECM_LIN];
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CONFIGLIN_vidDiagAltAbsent                                 */
/* !Description :  This function does the diagnostic of the default ECU ALT   */
/*                 Absent.                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NM_vidGetCounters(argin uint8 NetId, argout uint8        */
/*  *au8AbsentCounter);                                                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CONFIGLIN_u8AltEcuCnt_prev;                                   */
/*  input boolean CONFIGLIN_bDgoAltAbsent;                                    */
/*  input boolean CONFIGLIN_bMonRun;                                          */
/*  output boolean CONFIGLIN_bDgoAltAbsent;                                   */
/*  output st113 CONFIGLIN_stAltStatus;                                       */
/*  output uint8 CONFIGLIN_u8AltEcuCnt_prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidDiagAltAbsent                                     */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidDiagAltAbsent(void)
{
   uint8 au8LocalAbsentCounter[NM_u8NB_NODES_N_LIN_E + 1];

   NM_vidGetCounters(N_LIN_E, au8LocalAbsentCounter);

   if ((CONFIGLIN_u8AltEcuCnt_prev > au8LocalAbsentCounter[ALT_LIN]) ||
       (au8LocalAbsentCounter[ALT_LIN] == 0))
   {
      CONFIGLIN_bDgoAltAbsent = FALSE;
      VEMS_vidSET(CONFIGLIN_stAltStatus, LIN_PRESENT);
      GDGAR_vidGdu(GD_DFT_ALTABSENTECU,
                   CONFIGLIN_bDgoAltAbsent,
                   CONFIGLIN_bMonRun,
                   FALSE);
   }
   else if ((CONFIGLIN_u8AltEcuCnt_prev < au8LocalAbsentCounter[ALT_LIN]) ||
            (au8LocalAbsentCounter[ALT_LIN] >= CONFIGLIN_u8C_MAX))
   {
      CONFIGLIN_bDgoAltAbsent = TRUE;
      GDGAR_vidGdu(GD_DFT_ALTABSENTECU,
                   CONFIGLIN_bDgoAltAbsent,
                   CONFIGLIN_bMonRun,
                   FALSE);

      if (au8LocalAbsentCounter[ALT_LIN] < CONFIGLIN_u8C_MAX)
      {
         VEMS_vidSET(CONFIGLIN_stAltStatus, LIN_ABSENT);
      }
      else
      {
         VEMS_vidSET(CONFIGLIN_stAltStatus, LIN_CONFIRMED_ABSENT);
      }
   }
   else
   {
      /* Do Nothing */
   }

   CONFIGLIN_u8AltEcuCnt_prev = au8LocalAbsentCounter[ALT_LIN];
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CONFIGLIN_vidDiagFrame                                     */
/* !Description :  Fonction gérant les défauts d'absences des trames de       */
/*                 réceptions                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NM_vidGetCounters(argin uint8 NetId, argout uint8        */
/*  *au8AbsentCounter);                                                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CONFIGLIN_u8Cnt_prev[3];                                      */
/*  input boolean CONFIGLIN_bMonRun;                                          */
/*  output uint8 CONFIGLIN_u8Cnt_prev[3];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidDiagFrame                                     */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidDiagFrame
(
   uint8 u8NodeIndex,
   uint16 u16DefaultIndex
)
{
   uint8 au8LocalAbsentCounter[NM_u8NB_NODES_N_LIN_E + 1];

   NM_vidGetCounters(N_LIN_E, au8LocalAbsentCounter);

   if ((CONFIGLIN_u8Cnt_prev[u8NodeIndex]>au8LocalAbsentCounter[u8NodeIndex]) ||
       (au8LocalAbsentCounter[u8NodeIndex] == 0))
   {
      GDGAR_vidGdu(u16DefaultIndex,
                   FALSE,
                   CONFIGLIN_bMonRun,
                   FALSE);
   }
   else if ((au8LocalAbsentCounter[u8NodeIndex] >= CONFIGLIN_u8C_MAX) ||
      (CONFIGLIN_u8Cnt_prev[u8NodeIndex] < au8LocalAbsentCounter[u8NodeIndex]))
   {
      GDGAR_vidGdu(u16DefaultIndex,
                   TRUE,
                   CONFIGLIN_bMonRun,
                   FALSE);
   }
   else
   {
      /* Do Nothing */
   }

   CONFIGLIN_u8Cnt_prev[u8NodeIndex] = au8LocalAbsentCounter[u8NodeIndex];
}
/*QAC Warning Msg(2:4700): Accepted  */

#define CONFIGLIN_STOP_SEC_CODE
#include "Memmap.h"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion of MemMap.h file  */
/*-------------------------------- end of file -------------------------------*/
/*QAC Warning Msg(2:0862): Due to Inclusion of MemMap.h                    */
