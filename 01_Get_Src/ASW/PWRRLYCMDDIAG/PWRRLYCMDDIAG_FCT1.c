/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRRLYCMDDIAG                                           */
/* !Description     : PWRRLYCMDDIAG component.                                */
/*                                                                            */
/* !Module          : PWRRLYCMDDIAG                                           */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE ACTIONNEURS */
/*                                                                            */
/* !File            : PWRRLYCMDDIAG_FCT1.C                                    */
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
/*   1 / PWRRLYCMDDIAG_vidInitOutput                                          */
/*   2 / PWRRLYCMDDIAG_vidCmd                                                 */
/*   3 / PWRRLYCMDDIAG_vidDiagAct                                             */
/*   4 / PWRRLYCMDDIAG_vidElDiagAcv                                           */
/*   5 / PWRRLYCMDDIAG_vidElDiagInh                                           */
/*   6 / PWRRLYCMDDIAG_vidDiagExt                                             */
/*   7 / PWRRLYCMDDIAG_InitCountRelay                                         */
/*   8 / PWRRLYCMDDIAG_ActExternalDiag                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6561228 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RLY/PWRRLYCMDDIAG/PWRRLYCMDDIAG_FC$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PWRRLYCMDDIAG.h"
#include "PWRRLYCMDDIAG_l.h"
#include "PWRRLYCMDDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_vidInitOutput                                */
/* !Description :  Initialisation des output                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean PwrRlyHw_bDgoOc_PwrRly;                                    */
/*  output boolean PwrRlyHw_bDgoScg_PwrRly;                                   */
/*  output boolean PwrRlyHw_bDgoScp_PwrRly;                                   */
/*  output boolean PwrRlyHw_bDgoStuck_PwrRly;                                 */
/*  output boolean PwrRlyHw_bMonRunOc_PwrRly;                                 */
/*  output boolean PwrRlyHw_bMonRunScg_PwrRly;                                */
/*  output boolean PwrRlyHw_bMonRunScp_PwrRly;                                */
/*  output boolean PwrRlyHw_bMonRunStuck_PwrRly;                              */
/*  output boolean PwrRlyHw_bDgoDef;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_vidInitOutput(void)
{
   PwrRlyHw_bDgoOc_PwrRly = 0;
   PwrRlyHw_bDgoScg_PwrRly = 0;
   PwrRlyHw_bDgoScp_PwrRly = 0;
   PwrRlyHw_bDgoStuck_PwrRly = 0;
   PwrRlyHw_bMonRunOc_PwrRly = 0;
   PwrRlyHw_bMonRunScg_PwrRly = 0;
   PwrRlyHw_bMonRunScp_PwrRly = 0;
   PwrRlyHw_bMonRunStuck_PwrRly = 0;
   PwrRlyHw_bDgoDef = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_vidCmd                                       */
/* !Description :  Bloc d’interface entre le driver commande de l’actionneur  */
/*                 sous la responsabilité du LdB et la gestion de l’état de   */
/*                 l’actionneur sous la responsabilité du LdA                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Actionneurs;                                                */
/*  output boolean Commande_relais_puissance;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_vidCmd(void)
{
   boolean bLocalActionneurs;


   VEMS_vidGET(Actionneurs, bLocalActionneurs);

   if (bLocalActionneurs != 0)
   {
      VEMS_vidSET(Commande_relais_puissance, 1);
   }
   else
   {
      VEMS_vidSET(Commande_relais_puissance, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_vidDiagAct                                   */
/* !Description :  Fonction de gestion du diagnostic                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_08_05199_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void PWRRLYCMDDIAG_vidElDiagAcv();                            */
/*  extf argret void PWRRLYCMDDIAG_vidElDiagInh();                            */
/*  input boolean PwrRlyHw_bDgoOc_PwrRly;                                     */
/*  input boolean PwrRlyHw_bMonRunOc_PwrRly;                                  */
/*  input boolean PwrRlyHw_bDgoScg_PwrRly;                                    */
/*  input boolean PwrRlyHw_bMonRunScg_PwrRly;                                 */
/*  input boolean PwrRlyHw_bDgoScp_PwrRly;                                    */
/*  input boolean PwrRlyHw_bMonRunScp_PwrRly;                                 */
/*  output boolean PwrRlyHw_bDgoDef;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_vidDiagAct(void)
{
   boolean bLocalInhPwrRlyElDiag;


   bLocalInhPwrRlyElDiag = GDGAR_bGetFRM(FRM_FRM_INHPWRRLYELDIAG);

   if (bLocalInhPwrRlyElDiag == 0)
   {
      PWRRLYCMDDIAG_vidElDiagAcv();
   }
   else
   {
      PWRRLYCMDDIAG_vidElDiagInh();
   }

   if (  ( (PwrRlyHw_bDgoOc_PwrRly != 0)
         &&(PwrRlyHw_bMonRunOc_PwrRly != 0))
      || ( (PwrRlyHw_bDgoScg_PwrRly != 0)
         &&(PwrRlyHw_bMonRunScg_PwrRly != 0))
      || ( (PwrRlyHw_bDgoScp_PwrRly != 0)
         &&(PwrRlyHw_bMonRunScp_PwrRly != 0)))
   {
      PwrRlyHw_bDgoDef = 1;
   }
   else
   {
      PwrRlyHw_bDgoDef = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_vidElDiagAcv                                 */
/* !Description :  Fonction du diagnostic                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dena_oc_relais_puissance;                                   */
/*  input boolean Dena_scg_relais_puissance;                                  */
/*  input boolean Dena_scp_relais_puissance;                                  */
/*  input boolean Dft_oc_relais_puissance;                                    */
/*  input boolean Dft_scg_relais_puissance;                                   */
/*  input boolean Dft_scp_relais_puissance;                                   */
/*  output boolean PwrRlyHw_bDgoOc_PwrRly;                                    */
/*  output boolean PwrRlyHw_bMonRunOc_PwrRly;                                 */
/*  output boolean PwrRlyHw_bDgoScg_PwrRly;                                   */
/*  output boolean PwrRlyHw_bMonRunScg_PwrRly;                                */
/*  output boolean PwrRlyHw_bDgoScp_PwrRly;                                   */
/*  output boolean PwrRlyHw_bMonRunScp_PwrRly;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_vidElDiagAcv(void)
{
   boolean bLocalDena_oc_relais_puissance;
   boolean bLocalDena_scg_relais_puissance;
   boolean bLocalDena_scp_relais_puissance;
   boolean bLocalDft_oc_relais_puissance;
   boolean bLocalDft_scg_relais_puissance;
   boolean bLocalDft_scp_relais_puissance;


   VEMS_vidGET(Dena_oc_relais_puissance, bLocalDena_oc_relais_puissance);
   VEMS_vidGET(Dena_scg_relais_puissance, bLocalDena_scg_relais_puissance);
   VEMS_vidGET(Dena_scp_relais_puissance, bLocalDena_scp_relais_puissance);
   VEMS_vidGET(Dft_oc_relais_puissance, bLocalDft_oc_relais_puissance);
   VEMS_vidGET(Dft_scg_relais_puissance, bLocalDft_scg_relais_puissance);
   VEMS_vidGET(Dft_scp_relais_puissance, bLocalDft_scp_relais_puissance);

   PwrRlyHw_bDgoOc_PwrRly     = bLocalDft_oc_relais_puissance;
   PwrRlyHw_bMonRunOc_PwrRly  = bLocalDena_oc_relais_puissance;
   PwrRlyHw_bDgoScg_PwrRly    = bLocalDft_scg_relais_puissance;
   PwrRlyHw_bMonRunScg_PwrRly = bLocalDena_scg_relais_puissance;
   PwrRlyHw_bDgoScp_PwrRly    = bLocalDft_scp_relais_puissance;
   PwrRlyHw_bMonRunScp_PwrRly = bLocalDena_scp_relais_puissance;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_vidElDiagInh                                 */
/* !Description :  Lorsque le diagnostic est inhibé, les indicateurs de       */
/*                 défauts sont mis à 0.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean PwrRlyHw_bDgoScp_PwrRly;                                   */
/*  output boolean PwrRlyHw_bMonRunOc_PwrRly;                                 */
/*  output boolean PwrRlyHw_bDgoOc_PwrRly;                                    */
/*  output boolean PwrRlyHw_bMonRunScg_PwrRly;                                */
/*  output boolean PwrRlyHw_bDgoScg_PwrRly;                                   */
/*  output boolean PwrRlyHw_bMonRunScp_PwrRly;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_vidElDiagInh(void)
{
   PwrRlyHw_bDgoScp_PwrRly = 0;
   PwrRlyHw_bMonRunOc_PwrRly = 0;
   PwrRlyHw_bDgoOc_PwrRly = 0;
   PwrRlyHw_bMonRunScg_PwrRly = 0;
   PwrRlyHw_bDgoScg_PwrRly = 0;
   PwrRlyHw_bMonRunScp_PwrRly = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_vidDiagExt                                   */
/* !Description :  Diagnostic externe des actionneurs                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void PWRRLYCMDDIAG_InitCountRelay();                          */
/*  extf argret void PWRRLYCMDDIAG_ActExternalDiag();                         */
/*  input boolean Actionneurs;                                                */
/*  input boolean Chauffage_sonde_o2_amont;                                   */
/*  input boolean PwrRlyHw_bDgoDef;                                           */
/*  input boolean PwrRly_bInhFctDiag_Man;                                     */
/*  output boolean PwrRlyHw_bMonRunStuck_PwrRly;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_vidDiagExt(void)
{
   boolean bLocalActionneurs;
   boolean bLocalChauffage_sonde_o2_amont;
   boolean bLocalInhPwrRlyFctDiag;


   VEMS_vidGET(Actionneurs,bLocalActionneurs);
   VEMS_vidGET(Chauffage_sonde_o2_amont, bLocalChauffage_sonde_o2_amont);
   bLocalInhPwrRlyFctDiag = GDGAR_bGetFRM(FRM_FRM_INHPWRRLYFCTDIAG);

   if (  (PwrRlyHw_bDgoDef != 0)
      || (bLocalInhPwrRlyFctDiag != 0)
      || (bLocalActionneurs != 0)
      || (bLocalChauffage_sonde_o2_amont != 0)
      || (PwrRly_bInhFctDiag_Man != 0))
   {
      PWRRLYCMDDIAG_InitCountRelay();
   }
   else
   {
      PWRRLYCMDDIAG_ActExternalDiag();
   }
   PwrRlyHw_bMonRunStuck_PwrRly = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_InitCountRelay                               */
/* !Description :  Initialisation du compteur Diag_relais_bsm_wait_count avant*/
/*                 chaque diagnostic actionneurs externe.                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Diag_relais_bsm_wait_delay;                                  */
/*  output uint16 Diag_relais_bsm_wait_count;                                 */
/*  output boolean PwrRlyHw_bDgoStuck_PwrRly;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_InitCountRelay(void)
{
   Diag_relais_bsm_wait_count =
      (uint16)MATHSRV_udtMIN(Diag_relais_bsm_wait_delay, 327);
   PwrRlyHw_bDgoStuck_PwrRly = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRRLYCMDDIAG_ActExternalDiag                              */
/* !Description :  PWRRLYCMDDIAG_ActExternalDiag                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean M_diag_chauffage_amont;                                     */
/*  input uint16 Diag_relais_bsm_wait_count;                                  */
/*  output uint16 Diag_relais_bsm_wait_count;                                 */
/*  output boolean PwrRlyHw_bDgoStuck_PwrRly;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRRLYCMDDIAG_ActExternalDiag(void)
{
   boolean bLocalM_diag_chauffage_amont;


   VEMS_vidGET(M_diag_chauffage_amont, bLocalM_diag_chauffage_amont);

   Diag_relais_bsm_wait_count =
      (uint16)MATHSRV_udtCLAMP((Diag_relais_bsm_wait_count - 1), 0, 327);

   if (  (Diag_relais_bsm_wait_count == 0)
      && (bLocalM_diag_chauffage_amont == 0))
   {
      PwrRlyHw_bDgoStuck_PwrRly = 1;
   }
   else
   {
      PwrRlyHw_bDgoStuck_PwrRly = 0;
   }
}

/*------------------------------- end of file --------------------------------*/