/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCINCMDIAG                                            */
/* !Description     : SYNCINCMDIAG component.                                 */
/*                                                                            */
/* !Module          : SYNCINCMDIAG                                            */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL ARBRE A CAMES ADMISSION. */
/*                                                                            */
/* !File            : SYNCINCMDIAG_FCT1.C                                     */
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
/*   1 / SYNCINCMDIAG_vidInitOutput                                           */
/*   2 / SYNCINCMDIAG_vidIniDiag                                              */
/*   3 / SYNCINCMDIAG_vidDiag                                                 */
/*   4 / SYNCINCMDIAG_vidDiagInCmAcq                                          */
/*   5 / SYNCINCMDIAG_vidInCmAcqVld                                           */
/*   6 / SYNCINCMDIAG_vidInCmCntFrnt                                          */
/*   7 / SYNCINCMDIAG_vidCntFrnt                                              */
/*   8 / SYNCINCMDIAG_vidStopEng                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6884534 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCINCMDIAG/SYNCINCMDIAG_FCT$*/
/* $Revision::   1.10     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCINCMDIAG.h"
#include "SYNCINCMDIAG_L.h"
#include "SYNCINCMDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidInitOutput                                 */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bInCmAcqVld;                                          */
/*  output boolean SYNCINCMDIAG_bHysteresisOutput;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidInitOutput(void)
{
   VEMS_vidSET(Sync_bInCmAcqVld, 0);
   SYNCINCMDIAG_bHysteresisOutput = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidIniDiag                                    */
/* !Description :  Au réveil ECU et à chaque KEY OFF - ON, la panne           */
/*                 élémentaire et les conditions de diagnostics sont remises à*/
/*                 zéro.                                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bDgoCoh_InCm;                                         */
/*  output boolean Sync_bMonRunCoh_InCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidIniDiag(void)
{
   Sync_bDgoCoh_InCm = 0;
   Sync_bMonRunCoh_InCm = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidDiag                                       */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCINCMDIAG_vidDiagInCmAcq();                           */
/*  input boolean Ext_bPresInCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidDiag(void)
{
   boolean bLocalExtbPresInCmSen;


   VEMS_vidGET(Ext_bPresInCmSen, bLocalExtbPresInCmSen);
   if (bLocalExtbPresInCmSen != 0)
   {
      SYNCINCMDIAG_vidDiagInCmAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidDiagInCmAcq                                */
/* !Description :  Fonction responsable du diagnostic.                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Dena_chr_incamdiag;                                         */
/*  input boolean Dft_chr_incamdiag;                                          */
/*  input boolean Acq_incam_chr_diag_ena_upcb0;                               */
/*  input uint16 Sync_nEngInhMonCohInCm_C;                                    */
/*  input uint16 Sync_nEngInhMonCohInCm_Hys_C;                                */
/*  input boolean SYNCINCMDIAG_bHysteresisOutput;                             */
/*  input boolean Sync_bMonRunCoh_InCm;                                       */
/*  output boolean Sync_bMonRunCoh_InCm;                                      */
/*  output boolean Sync_bDgoCoh_InCm;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidDiagInCmAcq(void)
{
   boolean bLocalInhChrInCmDiag;
   boolean bLocalDenaChrIncamdiag;
   boolean bLocalDftChrIncamdiag;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalSomme;
   uint32  u32LocalSomme;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Dena_chr_incamdiag, bLocalDenaChrIncamdiag);
   VEMS_vidGET(Dft_chr_incamdiag, bLocalDftChrIncamdiag);
   bLocalInhChrInCmDiag = GDGAR_bGetFRM(FRM_FRM_INHCHRINCMDIAG);

   if (  (Acq_incam_chr_diag_ena_upcb0 != 0)
      && (bLocalDenaChrIncamdiag != 0)
      && (bLocalInhChrInCmDiag == 0))
   {
      Sync_bMonRunCoh_InCm = 1;
   }
   else
   {
      Sync_bMonRunCoh_InCm = 0;
   }

   u32LocalSomme = (uint32)(Sync_nEngInhMonCohInCm_C
                           + Sync_nEngInhMonCohInCm_Hys_C);
   u16LocalSomme = (uint16)MATHSRV_udtMIN(u32LocalSomme, 65535);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                Sync_nEngInhMonCohInCm_C,
                                u16LocalSomme,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &SYNCINCMDIAG_bHysteresisOutput);

   if (  (bLocalDftChrIncamdiag != 0)
      && (Sync_bMonRunCoh_InCm != 0)
      && (SYNCINCMDIAG_bHysteresisOutput != 0))
   {
      Sync_bDgoCoh_InCm = 1;
   }
   else
   {
      Sync_bDgoCoh_InCm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidInCmAcqVld                                 */
/* !Description :  L’acquisition du signal arbre à cames admission est        */
/*                 considérée comme valide si aucune panne élémentaire sur le */
/*                 profil du signal arbre à cames admission n’est détectée et */
/*                 si les conditions de diagnostics sont remplies.            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bMonRunCoh_InCm;                                       */
/*  input boolean Sync_bDgoCoh_InCm;                                          */
/*  output boolean Sync_bInCmAcqVld;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidInCmAcqVld(void)
{
   boolean bLocalSyncbInCmAcqVld;


   if (  (Sync_bMonRunCoh_InCm != 0)
      && (Sync_bDgoCoh_InCm == 0))
   {
      bLocalSyncbInCmAcqVld = 1;
   }
   else
   {
      bLocalSyncbInCmAcqVld = 0;
   }
   VEMS_vidSET(Sync_bInCmAcqVld, bLocalSyncbInCmAcqVld);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidInCmCntFrnt                                */
/* !Description :  Cette fonction appelle la fonction qui autorisera          */
/*                 l’injection sous une condition.                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCINCMDIAG_vidCntFrnt();                               */
/*  input boolean Sync_bAcvInjIgDrv;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidInCmCntFrnt(void)
{
   boolean bLocalSyncbAcvInjIgDrv;


   VEMS_vidGET(Sync_bAcvInjIgDrv, bLocalSyncbAcvInjIgDrv);

   if ( bLocalSyncbAcvInjIgDrv != 1)
   {
      SYNCINCMDIAG_vidCntFrnt();
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidCntFrnt                                    */
/* !Description :  Cette fonction autorisera l’injection seulement si on      */
/*                 détecte un nombre suffisant et calibrable de fronts AAC.   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_cntFrntIncm;                                             */
/*  input uint8 Sync_cntFrntThd_C;                                            */
/*  output uint8 Sync_cntFrntIncm;                                            */
/*  output boolean Sync_bAcvInjIgDrv;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidCntFrnt(void)
{
   uint16 u16LocalSynccntFrntIncm;


   u16LocalSynccntFrntIncm = (uint16)(Sync_cntFrntIncm + 1);
   Sync_cntFrntIncm = (uint8)MATHSRV_udtMIN(u16LocalSynccntFrntIncm, 255);

   if ( Sync_cntFrntIncm >= Sync_cntFrntThd_C )
   {
      VEMS_vidSET(Sync_bAcvInjIgDrv, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCINCMDIAG_vidStopEng                                    */
/* !Description :  initialisation de la sortie Sync_bAcvInjIgDrv.             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input uint8 Sync_cntFrntThd_C;                                            */
/*  output uint8 Sync_cntFrntIncm;                                            */
/*  output boolean Sync_bAcvInjIgDrv;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCINCMDIAG_vidStopEng(void)
{
   boolean bLocalExtbPresInCmSen;


   VEMS_vidGET(Ext_bPresInCmSen, bLocalExtbPresInCmSen);
   Sync_cntFrntIncm = 0;
   if (  (bLocalExtbPresInCmSen == 0)
      || (Sync_cntFrntThd_C == 0))
   {
      VEMS_vidSET(Sync_bAcvInjIgDrv, 1);
   }
   else
   {
      VEMS_vidSET(Sync_bAcvInjIgDrv, 0);
   }
}
/*------------------------------- end of file --------------------------------*/