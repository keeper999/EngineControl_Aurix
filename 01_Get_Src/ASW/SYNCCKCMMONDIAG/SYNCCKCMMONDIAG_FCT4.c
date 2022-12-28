/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKCMMONDIAG                                         */
/* !Description     : SYNCCKCMMONDIAG component.                              */
/*                                                                            */
/* !Module          : SYNCCKCMMONDIAG                                         */
/* !Description     : SURVEILLANCE DES SIGNAUX ARBRE A CAMES ET VILEBREQUIN   */
/*                                                                            */
/* !File            : SYNCCKCMMONDIAG_FCT4.C                                  */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SYNCCKCMMONDIAG_vidNoSigCkMonIni                                     */
/*   2 / SYNCCKCMMONDIAG_vidNoSgCkMonClcn                                     */
/*   3 / SYNCCKCMMONDIAG_vidNoSigCkMonRst                                     */
/*   4 / SYNCCKCMMONDIAG_vidClcDgoNoSigCk                                     */
/*   5 / SYNCCKCMMONDIAG_vidLossCkMonIni                                      */
/*   6 / SYNCCKCMMONDIAG_vidLossCkMonCl                                       */
/*   7 / SYNCCKCMMONDIAG_vidLossCkMonRst                                      */
/*   8 / SYNCCKCMMONDIAG_vidClDgoLossCk                                       */
/*                                                                            */
/* !Reference   : V02 NT 09 04208 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKCMMONDIAG/SYNCCKCMMONDI$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   20 Jan 2012 $*/
/* $Author::   wbouach                                $$Date::   20 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "SYNCCKCMMONDIAG_L.h"
#include "SYNCCKCMMONDIAG_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSigCkMonIni                           */
/* !Description :  Au réveil ECU et à chaque KEY OFF  ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises à*/
/*                 zéro.                                                      */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunNoSigCk;                                       */
/*  output boolean Sync_bDgoNoSigCk;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSigCkMonIni(void)
{
   Sync_bMonRunNoSigCk = 0;
   Sync_bDgoNoSigCk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSgCkMonClcn                           */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClcDgoNoSigCk();                      */
/*  input boolean Sync_bCmnCdnCkDiag;                                         */
/*  output boolean Sync_bMonRunNoSigCk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSgCkMonClcn(void)
{
   if (Sync_bCmnCdnCkDiag != 0)
   {
      Sync_bMonRunNoSigCk = 1;
      SYNCCKCMMONDIAG_vidClcDgoNoSigCk();
   }
   else
   {
      Sync_bMonRunNoSigCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidNoSigCkMonRst                           */
/* !Description :  Lorsqu’il n’y a plus d’évènement arbre à cames admission,  */
/*                 les conditions de diagnostics de l’absence et de perte du  */
/*                 signal vilebrequin doivent être remises à zéro. Cette      */
/*                 action est effectuée sur l’évènement CALL_MonRunCkRst      */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunNoSigCk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidNoSigCkMonRst(void)
{
   Sync_bMonRunNoSigCk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClcDgoNoSigCk                           */
/* !Description :  Une panne élémentaire est détectée si les conditions de    */
/*                 diagnostic sont remplies (Sync_bCmnCdnCkDiag = ON) et qu’il*/
/*                 n’ y a pas de mouvement détecté sur le vilebrequin         */
/*                 (Acq_crk_tooth_det_upvb0 = OFF).                           */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_crk_tooth_det_status_upvb0;                             */
/*  input boolean Acq_crk_tooth_det_upvb0;                                    */
/*  output boolean Sync_bDgoNoSigCk;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClcDgoNoSigCk(void)
{
   boolean bLocalAcq_crk_tooth_det_status;
   boolean bLocalAcq_crk_tooth_det_upvb0;


   VEMS_vidGET(Acq_crk_tooth_det_status_upvb0, bLocalAcq_crk_tooth_det_status);
   VEMS_vidGET(Acq_crk_tooth_det_upvb0, bLocalAcq_crk_tooth_det_upvb0);

   if (  (bLocalAcq_crk_tooth_det_upvb0 == 0)
      && (bLocalAcq_crk_tooth_det_status != 0))
   {
      Sync_bDgoNoSigCk = 1;
   }
   else
   {
      Sync_bDgoNoSigCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossCkMonIni                            */
/* !Description :  Au réveil ECU et à chaque KEY OFF  ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises à*/
/*                 zéro.                                                      */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunSigLossCk;                                     */
/*  output boolean Sync_bDgoSigLossCk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossCkMonIni(void)
{
   Sync_bMonRunSigLossCk = 0;
   Sync_bDgoSigLossCk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossCkMonCl                             */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide                                              */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClDgoLossCk();                        */
/*  input boolean Sync_bCmnCdnCkDiag;                                         */
/*  output boolean Sync_bMonRunSigLossCk;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossCkMonCl(void)
{
   if (Sync_bCmnCdnCkDiag != 0)
   {
      Sync_bMonRunSigLossCk = 1;
      SYNCCKCMMONDIAG_vidClDgoLossCk();
   }
   else
   {
      Sync_bMonRunSigLossCk = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidLossCkMonRst                            */
/* !Description :  Lorsqu’il n’y a plus d’évènement arbre à cames admission,  */
/*                 les conditions de diagnostics de l’absence et de perte du  */
/*                 signal vilebrequin doivent être remises à zéro. Cette      */
/*                 action est effectuée sur l’évènement CALL_MonRunCkRst.     */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bMonRunSigLossCk;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidLossCkMonRst(void)
{
   Sync_bMonRunSigLossCk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClDgoLossCk                             */
/* !Description :  Une panne élémentaire est détectée si les conditions de    */
/*                 diagnostic sont remplies (Sync_bCmnCdnCkDiag = ON) et qu’il*/
/*                 n’ y a pas de mouvement détecté sur le vilebrequin         */
/*                 (Acq_crk_tooth_det_upvb0 = OFF).                           */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_crk_tooth_det_status_upvb0;                             */
/*  input boolean Acq_crk_tooth_det_upvb0;                                    */
/*  output boolean Sync_bDgoSigLossCk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClDgoLossCk(void)
{
   boolean bLocalAcq_crk_tooth_det_status;
   boolean bLocalAcq_crk_tooth_det_upvb0;


   VEMS_vidGET(Acq_crk_tooth_det_status_upvb0, bLocalAcq_crk_tooth_det_status);
   VEMS_vidGET(Acq_crk_tooth_det_upvb0, bLocalAcq_crk_tooth_det_upvb0);

   if (  (bLocalAcq_crk_tooth_det_upvb0 == 0)
      && (bLocalAcq_crk_tooth_det_status != 0))
   {
      Sync_bDgoSigLossCk = 1;
   }
   else
   {
      Sync_bDgoSigLossCk = 0;
   }
}
/*------------------------------- end of file --------------------------------*/