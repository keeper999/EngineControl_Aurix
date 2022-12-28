/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COMSTMNG                                                */
/* !Description     : COMSTMNG component                                      */
/*                                                                            */
/* !Module          : COMSTMNG                                                */
/* !Description     : GESTION DES PHASES DE VIE DE LA COMMUNICATION           */
/*                                                                            */
/* !File            : COMSTMNG_FCT2.C                                         */
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
/*   1 / COMSTMNG_vidLinLifeCyclePhases                                       */
/*   2 / COMSTMNG_vidLinStatusInit                                            */
/*   3 / COMSTMNG_vidLinStatusWakeUp                                          */
/*   4 / COMSTMNG_vidLinStatusNormal                                          */
/*   5 / COMSTMNG_vidLinStatusShut                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6832731 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/COMSTMNG/COMSTMNG_FCT2.C_v        $*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   06 Oct 2014 $*/
/* $Author::   hmelloul                               $$Date::   06 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "COMSTMNG.h"
#include "COMSTMNG_L.h"
#include "COMSTMNG_im.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidLinLifeCyclePhases                             */
/* !Description :   L’automate détermine dans quel état se trouve le réseau   */
/*                 LIN. Au réveil RCD et afin de réveiller le réseau LIN, il  */
/*                 est nécessaire d’envoyer une trame de réveil. De même à la */
/*                 coupure du contact clef, il est nécessaire d’envoyer une   */
/*                 trame de mise en veille.                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COMSTMNG_vidLinStatusInit();                             */
/*  extf argret void COMSTMNG_vidLinStatusWakeUp();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void LinSM_ScheduleRequest(uint8 u8ComMChannel, boolean bEna);*/
/*  extf argret void COMSTMNG_vidLinStatusNormal();                           */
/*  extf argret void COMSTMNG_vidLinStatusShut();                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Clef_de_contact;                                            */
/*  input st111 IsLin_stLin;                                                  */
/*  input boolean COMSTMNG_bClefDeContactPrev;                                */
/*  output boolean Clef_de_contact_FallEdge;                                  */
/*  output boolean COMSTMNG_bClefDeContactPrev;                               */
/*  output st111 IsLin_stLin;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidLinLifeCyclePhases(void)
{
   boolean  bLocalClef_de_contact;
   uint8    u8LocalIsLin_stLin;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);

   if ((COMSTMNG_bClefDeContactPrev != 0) && (bLocalClef_de_contact == 0))
   {
      Clef_de_contact_FallEdge = 1;
   }
   else
   {
      Clef_de_contact_FallEdge = 0;
   }
   COMSTMNG_bClefDeContactPrev = bLocalClef_de_contact;

   switch(u8LocalIsLin_stLin)
   {
      case ISLIN_INIT:
         COMSTMNG_vidLinStatusInit();
         break;
      case ISLIN_WAKEUP:
         COMSTMNG_vidLinStatusWakeUp();
         break;
      case ISLIN_WAKEUPDONE:
         VEMS_vidSET(IsLin_stLin, ISLIN_NORMAL);
         LinSM_ScheduleRequest(ComM_u8ComMChannel_Lin_1, 1);
         break;
      case ISLIN_NORMAL:
         COMSTMNG_vidLinStatusNormal();
         break;
      case ISLIN_SHUTDOWNRQ:
         VEMS_vidSET(IsLin_stLin, ISLIN_SHUTDOWN);
         break;
      case ISLIN_SHUTDOWN:
         COMSTMNG_vidLinStatusShut();
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(IsLin_stLin, ISLIN_INIT);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidLinStatusInit                                  */
/* !Description :  Transition de l'état ISLIN_INIT.                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact;                                            */
/*  output st111 IsLin_stLin;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidLinStatusInit(void)
{
   boolean  bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (bLocalClef_de_contact != 0)
   {
      VEMS_vidSET(IsLin_stLin, ISLIN_WAKEUP);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidLinStatusWakeUp                                */
/* !Description :  transition de l'état ISLIN_WAKEUP.                         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ComM_GetCurrentComMode(uint8 u8ComMUser, uint8 *ComMode);*/
/*  input boolean Clef_de_contact_FallEdge;                                   */
/*  output st111 IsLin_stLin;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidLinStatusWakeUp(void)
{

   if (Clef_de_contact_FallEdge != 0)
   {
      VEMS_vidSET(IsLin_stLin, ISLIN_SHUTDOWN);
   }
   else
   {
      if (COMSTMNG_LinCurrentMode == COMM_FULL_COMMUNICATION)
      {
         VEMS_vidSET(IsLin_stLin, ISLIN_WAKEUPDONE);
      }
      else
      {
         ComM_GetCurrentComMode(ComM_u8ComMUser_Lin, &COMSTMNG_LinCurrentMode);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidLinStatusNormal                                */
/* !Description :  Transition de l'état ISLIN_NORMAL.                         */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact_FallEdge;                                   */
/*  output st111 IsLin_stLin;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidLinStatusNormal(void)
{
   if (Clef_de_contact_FallEdge != 0)
   {
      VEMS_vidSET(IsLin_stLin, ISLIN_SHUTDOWNRQ);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidLinStatusShut                                  */
/* !Description :  Transition de l'état ISLIN_SHUTDOWN.                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ComM_GetCurrentComMode(uint8 u8ComMUser, uint8 *ComMode);*/
/*  input boolean Clef_de_contact;                                            */
/*  output st111 IsLin_stLin;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidLinStatusShut(void)
{
   boolean  bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (bLocalClef_de_contact != 0)
   {
      VEMS_vidSET(IsLin_stLin, ISLIN_WAKEUP);
   }
   else
   {
      if (COMSTMNG_LinCurrentMode == COMM_NO_COMMUNICATION)
      {
         VEMS_vidSET(IsLin_stLin, ISLIN_INIT);
      }
      else
      {
         ComM_GetCurrentComMode(ComM_u8ComMUser_Lin, &COMSTMNG_LinCurrentMode);
      }
   }
}
/*------------------------------- end of file --------------------------------*/