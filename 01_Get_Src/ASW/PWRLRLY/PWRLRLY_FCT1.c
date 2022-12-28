/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRLRLY                                                 */
/* !Description     : PWRLRLY component.                                      */
/*                                                                            */
/* !Module          : PWRLRLY                                                 */
/* !Description     : COMMANDE ET DIAGNOSTIC DU RELAIS PRINCIPAL              */
/*                                                                            */
/* !File            : PWRLRLY_FCT1.C                                          */
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
/*   1 / PWRLRLY_vidCmd                                                       */
/*   2 / PWRLRLY_vidDiag                                                      */
/*   3 / PWRLRLY_vidGduCall                                                   */
/*   4 / PWRLRLY_vidInitialization                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6559340 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RLY/PWRLRLY/PWRLRLY_FCT1.c_v      $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PWRLRLY.h"
#include "PWRLRLY_L.h"
#include "PWRLRLY_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRLRLY_vidCmd                                             */
/* !Description :  Dès que la ligne RCD passe à l’état haut, le CMM commande  */
/*                 la fermeture du relais principal.                          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_08_05173_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st08 Power_conditions_state;                                        */
/*  output boolean Rly_bMainRlyCmd;                                           */
/*  output boolean Commande_relais_principal;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRLRLY_vidCmd(void)
{
   uint8 u8LocalPower_conditions_state;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   if (u8LocalPower_conditions_state != SLEEPING)
   {
      VEMS_vidSET(Rly_bMainRlyCmd, 1);
      VEMS_vidSET(Commande_relais_principal, 1);
   }
   else
   {
      VEMS_vidSET(Rly_bMainRlyCmd, 0);
      VEMS_vidSET(Commande_relais_principal, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRLRLY_vidDiag                                            */
/* !Description :  Le diagnostic du relais principal n’est possible que       */
/*                 lorsque celui-ci n’est pas commandé.                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_08_05173_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_cmd_relais_principal;                                */
/*  input boolean Dft_scg_cmd_relais_principal;                               */
/*  input boolean Dft_scp_cmd_relais_principal;                               */
/*  output boolean Rly_bMonRunStuck_MainRly;                                  */
/*  output boolean Rly_bDgoStuck_MainRly;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRLRLY_vidDiag(void)
{
   boolean          bLocalDftOcCmdRelaisPrincipal;
   boolean          bLocalDftScgCmdRelaisPrincipal;
   boolean          bLocalDftScpCmdRelaisPrincipal;


   VEMS_vidGET(Dft_oc_cmd_relais_principal, bLocalDftOcCmdRelaisPrincipal);
   VEMS_vidGET(Dft_scg_cmd_relais_principal, bLocalDftScgCmdRelaisPrincipal);
   VEMS_vidGET(Dft_scp_cmd_relais_principal, bLocalDftScpCmdRelaisPrincipal);
   Rly_bMonRunStuck_MainRly = 1;

   if (  (bLocalDftOcCmdRelaisPrincipal != 0)
      && (bLocalDftScgCmdRelaisPrincipal != 0)
      && (bLocalDftScpCmdRelaisPrincipal != 0))
   {
      Rly_bDgoStuck_MainRly = 1;
   }
   else
   {
      Rly_bDgoStuck_MainRly = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRLRLY_vidGduCall                                         */
/* !Description :  Appel au GDU réalisé qu’à la 1ère récurrence temporelle.   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/*  argin boolean bMonRun, argin boolean Ns_bMonWait);                        */
/*  input boolean PWRLRLY_bActiveGen;                                         */
/*  input boolean Rly_bDgoStuck_MainRly;                                      */
/*  input boolean Rly_bMonRunStuck_MainRly;                                   */
/*  output boolean PWRLRLY_bActiveGen;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRLRLY_vidGduCall(void)
{
   if (PWRLRLY_bActiveGen != 0)
   {
      GDGAR_vidGdu(GD_DFT_STUCK_MAINRLY,
                   Rly_bDgoStuck_MainRly,
                   Rly_bMonRunStuck_MainRly,
                   DIAG_DISPO);
      PWRLRLY_bActiveGen = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRLRLY_vidInitialization                                  */
/* !Description :  Initialisation de PWRLRLY_bActiveGen à 1                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean PWRLRLY_bActiveGen;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRLRLY_vidInitialization(void)
{
   PWRLRLY_bActiveGen = 1;
}
/*------------------------------- end of file --------------------------------*/