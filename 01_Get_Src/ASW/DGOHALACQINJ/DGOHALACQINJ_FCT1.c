/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DGOHALACQINJ                                            */
/* !Description     : DGOHALACQINJ component.                                 */
/*                                                                            */
/* !Module          : DGOHALACQINJ                                            */
/* !Description     : Acquisition of Diagnoses States and results for         */
/*                    injectors                                               */
/*                                                                            */
/* !File            : DGOHALACQINJ_FCT1.C                                     */
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
/*   1 / DGOHALACQINJ_vidInjectorsDiag                                        */
/*   2 / DGOHALACQINJ_vidInjector1Diag                                        */
/*   3 / DGOHALACQINJ_vidInjector2Diag                                        */
/*   4 / DGOHALACQINJ_vidInjector3Diag                                        */
/*   5 / DGOHALACQINJ_vidInjector4Diag                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6913684 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "DGOHALACQINJ.h"
#include "DGOHALACQINJ_L.h"
#include "DGOHALACQINJ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DGOHALACQINJ_vidInjectorsDiag                              */
/* !Description :  Le diagnostic fournit une information de panne présente,   */
/*                 utilisée par la gestion des défauts unitaire pour générer  */
/*                 les éventuelles  demande de reconfiguration et définir les */
/*                 modes dégradés associés.                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DGOHALACQINJ_vidInjector1Diag();                         */
/*  extf argret void DGOHALACQINJ_vidInjector3Diag();                         */
/*  extf argret void DGOHALACQINJ_vidInjector2Diag();                         */
/*  extf argret void DGOHALACQINJ_vidInjector4Diag();                         */
/*  input uint8 Ext_noCylEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DGOHALACQINJ_vidInjectorsDiag(void)
{
   uint8 u8LocalExt_noCylEng;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   DGOHALACQINJ_vidInjector1Diag();
   DGOHALACQINJ_vidInjector3Diag();
   DGOHALACQINJ_vidInjector2Diag();
   if (u8LocalExt_noCylEng == 4)
   {
      DGOHALACQINJ_vidInjector4Diag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DGOHALACQINJ_vidInjector1Diag                              */
/* !Description :  Le driver Injection est capable de différencier un court   */
/*                 circuit à la masse d’un circuit ouvert. Il permet aussi de */
/*                 détecter un Overload sur l’injecteur.  Le LDB remontera 4  */
/*                 flags de défaut (Scg, Scp, Oc, Ovld)                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_Inj1Cmd;                                             */
/*  input boolean Dft_scg_Inj1Cmd;                                            */
/*  input boolean Dft_scw_Inj1Cmd;                                            */
/*  input boolean Dft_ovld_Inj1Cmd;                                           */
/*  input boolean Dena_oc_Inj1Cmd;                                            */
/*  input boolean Dena_scg_Inj1Cmd;                                           */
/*  input boolean Dena_scw_Inj1Cmd;                                           */
/*  input boolean Dena_ovld_Inj1Cmd;                                          */
/*  output boolean Ext_bDgoOc_Inj1Cmd;                                        */
/*  output boolean Ext_bDgoScg_Inj1Cmd;                                       */
/*  output boolean Ext_bDgoScp_Inj1Cmd;                                       */
/*  output boolean Ext_bDgoOvld_Inj1Cmd;                                      */
/*  output boolean Ext_bMonRunOc_Inj1Cmd;                                     */
/*  output boolean Ext_bMonRunScg_Inj1Cmd;                                    */
/*  output boolean Ext_bMonRunScp_Inj1Cmd;                                    */
/*  output boolean Ext_bMonRunOvld_Inj1Cmd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DGOHALACQINJ_vidInjector1Diag(void)
{
   boolean bLocalDena_oc_Inj1Cmd;
   boolean bLocalDena_ovld_Inj1Cmd;
   boolean bLocalDena_scg_Inj1Cmd;
   boolean bLocalDena_scw_Inj1Cmd;
   boolean bLocalDft_oc_Inj1Cmd;
   boolean bLocalDft_ovld_Inj1Cmd;
   boolean bLocalDft_scg_Inj1Cmd;
   boolean bLocalDft_scw_Inj1Cmd;
   boolean bLocalInhInjCmdDiagEl;


   bLocalInhInjCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHINJCMDDIAGEL);

   VEMS_vidGET(Dft_oc_Inj1Cmd, bLocalDft_oc_Inj1Cmd);
   VEMS_vidGET(Dft_scg_Inj1Cmd, bLocalDft_scg_Inj1Cmd);
   VEMS_vidGET(Dft_scw_Inj1Cmd, bLocalDft_scw_Inj1Cmd);
   VEMS_vidGET(Dft_ovld_Inj1Cmd, bLocalDft_ovld_Inj1Cmd);
   VEMS_vidGET(Dena_oc_Inj1Cmd, bLocalDena_oc_Inj1Cmd);
   VEMS_vidGET(Dena_scg_Inj1Cmd, bLocalDena_scg_Inj1Cmd);
   VEMS_vidGET(Dena_scw_Inj1Cmd, bLocalDena_scw_Inj1Cmd);
   VEMS_vidGET(Dena_ovld_Inj1Cmd, bLocalDena_ovld_Inj1Cmd);

   Ext_bDgoOc_Inj1Cmd = bLocalDft_oc_Inj1Cmd;
   Ext_bDgoScg_Inj1Cmd = bLocalDft_scg_Inj1Cmd;
   Ext_bDgoScp_Inj1Cmd = bLocalDft_scw_Inj1Cmd;
   Ext_bDgoOvld_Inj1Cmd = bLocalDft_ovld_Inj1Cmd;

   if (  (bLocalDena_oc_Inj1Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOc_Inj1Cmd = 1;
   }
   else
   {
      Ext_bMonRunOc_Inj1Cmd = 0;
   }

   if (  (bLocalDena_scg_Inj1Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScg_Inj1Cmd = 1;
   }
   else
   {
      Ext_bMonRunScg_Inj1Cmd = 0;
   }

   if (  (bLocalDena_scw_Inj1Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScp_Inj1Cmd = 1;
   }
   else
   {
      Ext_bMonRunScp_Inj1Cmd = 0;
   }

   if (  (bLocalDena_ovld_Inj1Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOvld_Inj1Cmd = 1;
   }
   else
   {
      Ext_bMonRunOvld_Inj1Cmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DGOHALACQINJ_vidInjector2Diag                              */
/* !Description :  Le driver Injection est capable de différencier un court   */
/*                 circuit à la masse d’un circuit ouvert. Il permet aussi de */
/*                 détecter un Overload sur l’injecteur.  Le LDB remontera 4  */
/*                 flags de défaut (Scg, Scp, Oc, Ovld)                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_Inj2Cmd;                                             */
/*  input boolean Dft_scg_Inj2Cmd;                                            */
/*  input boolean Dft_scw_Inj2Cmd;                                            */
/*  input boolean Dft_ovld_Inj2Cmd;                                           */
/*  input boolean Dena_oc_Inj2Cmd;                                            */
/*  input boolean Dena_scg_Inj2Cmd;                                           */
/*  input boolean Dena_scw_Inj2Cmd;                                           */
/*  input boolean Dena_ovld_Inj2Cmd;                                          */
/*  output boolean Ext_bDgoOc_Inj2Cmd;                                        */
/*  output boolean Ext_bDgoScg_Inj2Cmd;                                       */
/*  output boolean Ext_bDgoScp_Inj2Cmd;                                       */
/*  output boolean Ext_bDgoOvld_Inj2Cmd;                                      */
/*  output boolean Ext_bMonRunOc_Inj2Cmd;                                     */
/*  output boolean Ext_bMonRunScg_Inj2Cmd;                                    */
/*  output boolean Ext_bMonRunScp_Inj2Cmd;                                    */
/*  output boolean Ext_bMonRunOvld_Inj2Cmd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DGOHALACQINJ_vidInjector2Diag(void)
{
   boolean bLocalDena_oc_Inj2Cmd;
   boolean bLocalDena_ovld_Inj2Cmd;
   boolean bLocalDena_scg_Inj2Cmd;
   boolean bLocalDena_scw_Inj2Cmd;
   boolean bLocalDft_oc_Inj2Cmd;
   boolean bLocalDft_ovld_Inj2Cmd;
   boolean bLocalDft_scg_Inj2Cmd;
   boolean bLocalDft_scw_Inj2Cmd;
   boolean bLocalInhInjCmdDiagEl;


   bLocalInhInjCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHINJCMDDIAGEL);

   VEMS_vidGET(Dft_oc_Inj2Cmd, bLocalDft_oc_Inj2Cmd);
   VEMS_vidGET(Dft_scg_Inj2Cmd, bLocalDft_scg_Inj2Cmd);
   VEMS_vidGET(Dft_scw_Inj2Cmd, bLocalDft_scw_Inj2Cmd);
   VEMS_vidGET(Dft_ovld_Inj2Cmd, bLocalDft_ovld_Inj2Cmd);
   VEMS_vidGET(Dena_oc_Inj2Cmd, bLocalDena_oc_Inj2Cmd);
   VEMS_vidGET(Dena_scg_Inj2Cmd, bLocalDena_scg_Inj2Cmd);
   VEMS_vidGET(Dena_scw_Inj2Cmd, bLocalDena_scw_Inj2Cmd);
   VEMS_vidGET(Dena_ovld_Inj2Cmd, bLocalDena_ovld_Inj2Cmd);

   Ext_bDgoOc_Inj2Cmd = bLocalDft_oc_Inj2Cmd;
   Ext_bDgoScg_Inj2Cmd = bLocalDft_scg_Inj2Cmd;
   Ext_bDgoScp_Inj2Cmd = bLocalDft_scw_Inj2Cmd;
   Ext_bDgoOvld_Inj2Cmd = bLocalDft_ovld_Inj2Cmd;

   if (  (bLocalDena_oc_Inj2Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOc_Inj2Cmd = 1;
   }
   else
   {
      Ext_bMonRunOc_Inj2Cmd = 0;
   }

   if (  (bLocalDena_scg_Inj2Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScg_Inj2Cmd = 1;
   }
   else
   {
      Ext_bMonRunScg_Inj2Cmd = 0;
   }

   if (  (bLocalDena_scw_Inj2Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScp_Inj2Cmd = 1;
   }
   else
   {
      Ext_bMonRunScp_Inj2Cmd = 0;
   }

   if (  (bLocalDena_ovld_Inj2Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOvld_Inj2Cmd = 1;
   }
   else
   {
      Ext_bMonRunOvld_Inj2Cmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DGOHALACQINJ_vidInjector3Diag                              */
/* !Description :  Le driver Injection est capable de différencier un court   */
/*                 circuit à la masse d’un circuit ouvert. Il permet aussi de */
/*                 détecter un Overload sur l’injecteur.  Le LDB remontera 4  */
/*                 flags de défaut (Scg, Scp, Oc, Ovld)                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_Inj3Cmd;                                             */
/*  input boolean Dft_scg_Inj3Cmd;                                            */
/*  input boolean Dft_scw_Inj3Cmd;                                            */
/*  input boolean Dft_ovld_Inj3Cmd;                                           */
/*  input boolean Dena_oc_Inj3Cmd;                                            */
/*  input boolean Dena_scg_Inj3Cmd;                                           */
/*  input boolean Dena_scw_Inj3Cmd;                                           */
/*  input boolean Dena_ovld_Inj3Cmd;                                          */
/*  output boolean Ext_bDgoOc_Inj3Cmd;                                        */
/*  output boolean Ext_bDgoScg_Inj3Cmd;                                       */
/*  output boolean Ext_bDgoScp_Inj3Cmd;                                       */
/*  output boolean Ext_bDgoOvld_Inj3Cmd;                                      */
/*  output boolean Ext_bMonRunOc_Inj3Cmd;                                     */
/*  output boolean Ext_bMonRunScg_Inj3Cmd;                                    */
/*  output boolean Ext_bMonRunScp_Inj3Cmd;                                    */
/*  output boolean Ext_bMonRunOvld_Inj3Cmd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DGOHALACQINJ_vidInjector3Diag(void)
{
   boolean bLocalDena_oc_Inj3Cmd;
   boolean bLocalDena_ovld_Inj3Cmd;
   boolean bLocalDena_scg_Inj3Cmd;
   boolean bLocalDena_scw_Inj3Cmd;
   boolean bLocalDft_oc_Inj3Cmd;
   boolean bLocalDft_ovld_Inj3Cmd;
   boolean bLocalDft_scg_Inj3Cmd;
   boolean bLocalDft_scw_Inj3Cmd;
   boolean bLocalInhInjCmdDiagEl;


   bLocalInhInjCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHINJCMDDIAGEL);

   VEMS_vidGET(Dft_oc_Inj3Cmd, bLocalDft_oc_Inj3Cmd);
   VEMS_vidGET(Dft_scg_Inj3Cmd, bLocalDft_scg_Inj3Cmd);
   VEMS_vidGET(Dft_scw_Inj3Cmd, bLocalDft_scw_Inj3Cmd);
   VEMS_vidGET(Dft_ovld_Inj3Cmd, bLocalDft_ovld_Inj3Cmd);
   VEMS_vidGET(Dena_oc_Inj3Cmd, bLocalDena_oc_Inj3Cmd);
   VEMS_vidGET(Dena_scg_Inj3Cmd, bLocalDena_scg_Inj3Cmd);
   VEMS_vidGET(Dena_scw_Inj3Cmd, bLocalDena_scw_Inj3Cmd);
   VEMS_vidGET(Dena_ovld_Inj3Cmd, bLocalDena_ovld_Inj3Cmd);

   Ext_bDgoOc_Inj3Cmd = bLocalDft_oc_Inj3Cmd;
   Ext_bDgoScg_Inj3Cmd = bLocalDft_scg_Inj3Cmd;
   Ext_bDgoScp_Inj3Cmd = bLocalDft_scw_Inj3Cmd;
   Ext_bDgoOvld_Inj3Cmd = bLocalDft_ovld_Inj3Cmd;

   if (  (bLocalDena_oc_Inj3Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOc_Inj3Cmd = 1;
   }
   else
   {
      Ext_bMonRunOc_Inj3Cmd = 0;
   }

   if (  (bLocalDena_scg_Inj3Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScg_Inj3Cmd = 1;
   }
   else
   {
      Ext_bMonRunScg_Inj3Cmd = 0;
   }

   if (  (bLocalDena_scw_Inj3Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScp_Inj3Cmd = 1;
   }
   else
   {
      Ext_bMonRunScp_Inj3Cmd = 0;
   }

   if (  (bLocalDena_ovld_Inj3Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOvld_Inj3Cmd = 1;
   }
   else
   {
      Ext_bMonRunOvld_Inj3Cmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DGOHALACQINJ_vidInjector4Diag                              */
/* !Description :  La spécification est compatible pour des moteurs 3 ou 4    */
/*                 cylindres. Pour un moteur 3 cylindres, le bloc             */
/*                 Diagnostic_injecteur_4 n’est jamais appelé                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Dft_oc_Inj4Cmd;                                             */
/*  input boolean Dft_scg_Inj4Cmd;                                            */
/*  input boolean Dft_scw_Inj4Cmd;                                            */
/*  input boolean Dft_ovld_Inj4Cmd;                                           */
/*  input boolean Dena_oc_Inj4Cmd;                                            */
/*  input boolean Dena_scg_Inj4Cmd;                                           */
/*  input boolean Dena_scw_Inj4Cmd;                                           */
/*  input boolean Dena_ovld_Inj4Cmd;                                          */
/*  input boolean Ext_bDgoScp_Inj4Cmd;                                        */
/*  input boolean Ext_bMonRunScp_Inj4Cmd;                                     */
/*  input boolean Ext_bDgoOc_Inj4Cmd;                                         */
/*  input boolean Ext_bMonRunOc_Inj4Cmd;                                      */
/*  input boolean Ext_bDgoScg_Inj4Cmd;                                        */
/*  input boolean Ext_bMonRunScg_Inj4Cmd;                                     */
/*  input boolean Ext_bDgoOvld_Inj4Cmd;                                       */
/*  input boolean Ext_bMonRunOvld_Inj4Cmd;                                    */
/*  output boolean Ext_bDgoOc_Inj4Cmd;                                        */
/*  output boolean Ext_bDgoScg_Inj4Cmd;                                       */
/*  output boolean Ext_bDgoScp_Inj4Cmd;                                       */
/*  output boolean Ext_bDgoOvld_Inj4Cmd;                                      */
/*  output boolean Ext_bMonRunOc_Inj4Cmd;                                     */
/*  output boolean Ext_bMonRunScg_Inj4Cmd;                                    */
/*  output boolean Ext_bMonRunScp_Inj4Cmd;                                    */
/*  output boolean Ext_bMonRunOvld_Inj4Cmd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DGOHALACQINJ_vidInjector4Diag(void)
{
   boolean bLocalDena_oc_Inj4Cmd;
   boolean bLocalDena_ovld_Inj4Cmd;
   boolean bLocalDena_scg_Inj4Cmd;
   boolean bLocalDena_scw_Inj4Cmd;
   boolean bLocalDft_oc_Inj4Cmd;
   boolean bLocalDft_ovld_Inj4Cmd;
   boolean bLocalDft_scg_Inj4Cmd;
   boolean bLocalDft_scw_Inj4Cmd;
   boolean bLocalInhInjCmdDiagEl;


   bLocalInhInjCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHINJCMDDIAGEL);

   VEMS_vidGET(Dft_oc_Inj4Cmd, bLocalDft_oc_Inj4Cmd);
   VEMS_vidGET(Dft_scg_Inj4Cmd, bLocalDft_scg_Inj4Cmd);
   VEMS_vidGET(Dft_scw_Inj4Cmd, bLocalDft_scw_Inj4Cmd);
   VEMS_vidGET(Dft_ovld_Inj4Cmd, bLocalDft_ovld_Inj4Cmd);
   VEMS_vidGET(Dena_oc_Inj4Cmd, bLocalDena_oc_Inj4Cmd);
   VEMS_vidGET(Dena_scg_Inj4Cmd, bLocalDena_scg_Inj4Cmd);
   VEMS_vidGET(Dena_scw_Inj4Cmd, bLocalDena_scw_Inj4Cmd);
   VEMS_vidGET(Dena_ovld_Inj4Cmd, bLocalDena_ovld_Inj4Cmd);

   Ext_bDgoOc_Inj4Cmd = bLocalDft_oc_Inj4Cmd;
   Ext_bDgoScg_Inj4Cmd = bLocalDft_scg_Inj4Cmd;
   Ext_bDgoScp_Inj4Cmd = bLocalDft_scw_Inj4Cmd;
   Ext_bDgoOvld_Inj4Cmd = bLocalDft_ovld_Inj4Cmd;

   if (  (bLocalDena_oc_Inj4Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOc_Inj4Cmd = 1;
   }
   else
   {
      Ext_bMonRunOc_Inj4Cmd = 0;
   }

   if (  (bLocalDena_scg_Inj4Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScg_Inj4Cmd = 1;
   }
   else
   {
      Ext_bMonRunScg_Inj4Cmd = 0;
   }

   if (  (bLocalDena_scw_Inj4Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunScp_Inj4Cmd = 1;
   }
   else
   {
      Ext_bMonRunScp_Inj4Cmd = 0;
   }

   if (  (bLocalDena_ovld_Inj4Cmd != 0)
      && (bLocalInhInjCmdDiagEl == 0))
   {
      Ext_bMonRunOvld_Inj4Cmd = 1;
   }
   else
   {
      Ext_bMonRunOvld_Inj4Cmd = 0;
   }

   GDGAR_vidGdu(GD_DFT_SCP_INJ4CMD,
                Ext_bDgoScp_Inj4Cmd,
                Ext_bMonRunScp_Inj4Cmd,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_OC_INJ4CMD,
                Ext_bDgoOc_Inj4Cmd,
                Ext_bMonRunOc_Inj4Cmd,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_SCG_INJ4CMD,
                Ext_bDgoScg_Inj4Cmd,
                Ext_bMonRunScg_Inj4Cmd,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_OVLD_INJ4CMD,
                Ext_bDgoOvld_Inj4Cmd,
                Ext_bMonRunOvld_Inj4Cmd ,
                DIAG_DISPO);
}

/*------------------------------- end of file --------------------------------*/