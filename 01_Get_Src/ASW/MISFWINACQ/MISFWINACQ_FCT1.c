/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFWINACQ                                              */
/* !Description     : MISFWINACQ Component                                    */
/*                                                                            */
/* !Module          : MISFWINACQ                                              */
/* !Description     : ACQUISITION DES FENETRES MISFIRE                        */
/*                                                                            */
/* !File            : MISFWINACQ_FCT1.c                                       */
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
/*   1 / MISFWINACQ_vidInitOuput                                              */
/*   2 / MISFWINACQ_vidinitWintiDly                                           */
/*   3 / MISFWINACQ_vidMisfAcqSyncActive                                      */
/*   4 / MISFWINACQ_vidMisfAcqSdlActive                                       */
/*   5 / MISFWINACQ_vidMisfAcqActive                                          */
/*   6 / MISFWINACQ_vidMisfAcqDesactive                                       */
/*   7 / MISFWINACQ_MisfAcqDesactive                                          */
/*   8 / MISFWINACQ_vidReadWintiDly                                           */
/*   9 / MISFWINACQ_vidAcqLdbWinDuration                                      */
/*   10 / MISFWINACQ_vidWinDuration                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 05081 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFWINACQ/MISFWINACQ_FCT1.c_$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "MISFWINACQ.H"
#include "MISFWINACQ_l.h"
#include "MISFWINACQ_IM.h"
#include "PTMHAL.h"
#include "VEMS.h"

#define INDEX 4


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidInitOuput                                    */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Misf_bAcqWinOK;                                            */
/*  output boolean Misf_bAcqActive_prev;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidInitOuput(void)
{
   VEMS_vidSET(Misf_bAcqWinOK,0);
   Misf_bAcqActive_prev =0;
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidinitWintiDly                                 */
/* !Description :  ce bloc permet  d'intialiser les  durées des fenêtres.     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Misf_tiDlyTDCWin;                                           */
/*  output uint32 Misf_tiDlyExpWin;                                           */
/*  output uint32 Misf_tiDlyBdcWin;                                           */
/*  output uint32 Misf_tiDlyLongWin;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidinitWintiDly(void)
{
   VEMS_vidSET(Misf_tiDlyTDCWin,0);
   VEMS_vidSET(Misf_tiDlyExpWin,0);
   VEMS_vidSET(Misf_tiDlyBdcWin,0);
   VEMS_vidSET(Misf_tiDlyLongWin,0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidMisfAcqSyncActive                            */
/* !Description :  Au moment où le moteur se synchronise, on vérifie l’état de*/
/*                 l’API : si  E_OK, l’API est activé,  et si E_NOT_OK, l’API */
/*                 n’est pas activé.                                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PTMHAL_udtEnable()Std_ReturnType;                        */
/*  input boolean Misf_bAcqActive;                                            */
/*  output boolean Misf_bAcqActive;                                           */
/*  output boolean Misf_bAcqActive_prev;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidMisfAcqSyncActive(void)
{
   Std_ReturnType udtLocalStatus;


   udtLocalStatus = PTMHAL_udtEnable();
   if ( udtLocalStatus == E_OK)
   {
      Misf_bAcqActive = 1;
   }
   else
   {
      Misf_bAcqActive = 0;
   }
   Misf_bAcqActive_prev = Misf_bAcqActive;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidMisfAcqSdlActive                             */
/* !Description :  Dans le cas où l’API ne s’est pas activé lors de la        */
/*                 synchronisation du moteur, ce bloc permet de relancer, à   */
/*                 récurrence temporelle, l’activation de PTMHAL.             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidMisfAcqActive();                           */
/*  input boolean Misf_bAcqActive_prev;                                       */
/*  input boolean Misf_bAcqActive;                                            */
/*  output boolean Misf_bAcqActive_prev;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidMisfAcqSdlActive(void)
{
   if (Misf_bAcqActive_prev == 0)
   {
       /* 01_Misf_acq_active */
      MISFWINACQ_vidMisfAcqActive();
   }
   Misf_bAcqActive_prev = Misf_bAcqActive;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidMisfAcqActive                                */
/* !Description :  ce bloc permet  l’activation de PTMHAL.                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PTMHAL_udtEnable()Std_ReturnType;                        */
/*  output boolean Misf_bAcqActive;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidMisfAcqActive(void)
{
   Std_ReturnType udtLocalStatus;


   udtLocalStatus = PTMHAL_udtEnable();
   if ( udtLocalStatus == E_OK)
   {
      Misf_bAcqActive = 1;
   }
   else
   {
      Misf_bAcqActive = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidMisfAcqDesactive                             */
/* !Description :  Ce bloc désactive l’API PTMHAL si le moteur perd sa        */
/*                 synchronisation et que l’API était préalablement activé.   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_MisfAcqDesactive();                           */
/*  input boolean Misf_bAcqActive_prev;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidMisfAcqDesactive(void)
{
   if (Misf_bAcqActive_prev != 0)
   {
       /* 01_Misf_acq_desactive */
      MISFWINACQ_MisfAcqDesactive();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_MisfAcqDesactive                                */
/* !Description :  Ce bloc désactive l’API PTMHAL .                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PTMHAL_udtDisable()Std_ReturnType;                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_MisfAcqDesactive(void)
{
   Std_ReturnType udtLocalStatus;


   udtLocalStatus = PTMHAL_udtDisable();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidReadWintiDly                                 */
/* !Description :  L’acquisition des fenêtres par le LdB est autorisée si     */
/*                 PTMHAL est actif. Les valeurs acquises sont prises en      */
/*                 compte sous certaines conditions.                          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINACQ_vidAcqLdbWinDuration();                       */
/*  extf argret void MISFWINACQ_vidWinDuration();                             */
/*  input boolean Misf_bAcqActive;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidReadWintiDly(void)
{
   if (Misf_bAcqActive != 0)
   {
      /* 01_acq_ldb_win_duration */
      MISFWINACQ_vidAcqLdbWinDuration();
   }
      /* 02_win_duration */
   MISFWINACQ_vidWinDuration();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidAcqLdbWinDuration                            */
/* !Description :  Ce bloc récupère le nombre de durées acquises              */
/*                 Misf_cntWinAcq, ainsi que les durées de fenêtre mesurées   */
/*                 par le LdB, sous forme d’un tableau contenant, dans l’ordre*/
/*                 défini par le LdB :                                        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PTMHAL_u8GetAllPacksDuration(argin uint8                 */
/*  u8MaxTableSize,argio uint32 *pau32PacksDurationTable)uint8;               */
/*  input ???? INDEX;                                                         */
/*  output uint32 Misf_tiDlyTDCWinLdb;                                        */
/*  output uint32 Misf_tiDlyExpWinLdb;                                        */
/*  output uint32 Misf_tiDlyBdcWinLdb;                                        */
/*  output uint32 Misf_tiDlyLongWinLdb;                                       */
/*  output uint8 Misf_cntWinAcq;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidAcqLdbWinDuration(void)
{
   uint8  u8Localwindow_counter;
   uint32 u32LocalPacksDurationTable[INDEX];
   uint32 u32LocalMisf_tiDlyTDCWinLdb;
   uint32 u32LocalMisf_tiDlyExpWinLdb;
   uint32 u32LocalMisf_tiDlyBdcWinLdb;
   uint32 u32LocalMisf_tiDlyLongWinLdb;


   u8Localwindow_counter  =
      PTMHAL_u8GetAllPacksDuration( MISF_WIN_NBR,
                                    &u32LocalPacksDurationTable[0]);
   u32LocalMisf_tiDlyTDCWinLdb = (u32LocalPacksDurationTable[0]/2);
   Misf_tiDlyTDCWinLdb =
      MATHSRV_udtMIN(u32LocalMisf_tiDlyTDCWinLdb,99999);
   u32LocalMisf_tiDlyExpWinLdb = (u32LocalPacksDurationTable[1]/2);
   Misf_tiDlyExpWinLdb =
      MATHSRV_udtMIN(u32LocalMisf_tiDlyExpWinLdb,99999);
   u32LocalMisf_tiDlyBdcWinLdb = (u32LocalPacksDurationTable[2]/2);
   Misf_tiDlyBdcWinLdb =
      MATHSRV_udtMIN(u32LocalMisf_tiDlyBdcWinLdb,99999);
   u32LocalMisf_tiDlyLongWinLdb = (u32LocalPacksDurationTable[3]/2);
   Misf_tiDlyLongWinLdb =
      MATHSRV_udtMIN(u32LocalMisf_tiDlyLongWinLdb,199999);
   Misf_cntWinAcq = (uint8)MATHSRV_udtMIN(u8Localwindow_counter,4);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINACQ_vidWinDuration                                  */
/* !Description :  La prise en compte des mesures LdB est soumise à trois     */
/*                 conditions :le régime doit être supérieur à un seuil,le    */
/*                 statut d’activation renvoyé par le LdB doit être OK, le    */
/*                 moteur doit être synchronisé, le nombre de durées acquises */
/*                 doit être égal Misf_win_nbr_c                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint8 Misf_cntWinAcq;                                               */
/*  input uint8 Misf_win_nbr_c;                                               */
/*  input uint16 MF_N_MIN_ACQ;                                                */
/*  input boolean Misf_bAcqActive;                                            */
/*  input uint32 Misf_tiDlyTDCWinLdb;                                         */
/*  input uint32 Misf_tiDlyExpWinLdb;                                         */
/*  input uint32 Misf_tiDlyBdcWinLdb;                                         */
/*  input uint32 Misf_tiDlyLongWinLdb;                                        */
/*  output boolean Misf_bAcqWinOK;                                            */
/*  output uint32 Misf_tiDlyTDCWin;                                           */
/*  output uint32 Misf_tiDlyExpWin;                                           */
/*  output uint32 Misf_tiDlyBdcWin;                                           */
/*  output uint32 Misf_tiDlyLongWin;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : N.ABIDI                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINACQ_vidWinDuration(void)
{
   boolean bLocalMoteur_synchronise;
   uint16  u16LocalRegime_moteur;
   uint32  u32localMisf_tiDlyTDCWin;
   uint32  u32localMisf_tiDlyExpWin;
   uint32  u32localMisf_tiDlyBdcWin;
   uint32  u32localMisf_tiDlyLongWin;


   VEMS_vidGET(Regime_moteur,u16LocalRegime_moteur);
   VEMS_vidGET(Moteur_synchronise,bLocalMoteur_synchronise);
   if (  (Misf_cntWinAcq == Misf_win_nbr_c)
      && (u16LocalRegime_moteur > MF_N_MIN_ACQ)
      && (bLocalMoteur_synchronise != 0)
      && (Misf_bAcqActive != 0) )
   {
      VEMS_vidSET(Misf_bAcqWinOK,1);
      u32localMisf_tiDlyTDCWin =
         MATHSRV_udtMIN(Misf_tiDlyTDCWinLdb,99999);
      u32localMisf_tiDlyExpWin =
         MATHSRV_udtMIN(Misf_tiDlyExpWinLdb,99999);
      u32localMisf_tiDlyBdcWin =
         MATHSRV_udtMIN(Misf_tiDlyBdcWinLdb,99999);
      u32localMisf_tiDlyLongWin =
         MATHSRV_udtMIN(Misf_tiDlyLongWinLdb,199999);
   }
   else
   {
      VEMS_vidSET(Misf_bAcqWinOK,0);
      u32localMisf_tiDlyTDCWin = 0;
      u32localMisf_tiDlyExpWin = 0;
      u32localMisf_tiDlyBdcWin = 0;
      u32localMisf_tiDlyLongWin = 0;
   }

   VEMS_vidSET(Misf_tiDlyTDCWin,u32localMisf_tiDlyTDCWin);
   VEMS_vidSET(Misf_tiDlyExpWin,u32localMisf_tiDlyExpWin);
   VEMS_vidSET(Misf_tiDlyBdcWin,u32localMisf_tiDlyBdcWin);
   VEMS_vidSET(Misf_tiDlyLongWin,u32localMisf_tiDlyLongWin);
}

/*------------------------------- end of file --------------------------------*/