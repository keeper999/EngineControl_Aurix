/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCEXCMDIAG                                            */
/* !Description     : SYNCEXCMDIAG component                                  */
/*                                                                            */
/* !Module          : SYNCEXCMDIAG                                            */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL ARBRE A CAMES ECHAPPEMENT*/
/*                                                                            */
/* !File            : SYNCEXCMDIAG_FCT1.C                                     */
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
/*   1 / SYNCEXCMDIAG_vidInitOutput                                           */
/*   2 / SYNCEXCMDIAG_vidIniDiag                                              */
/*   3 / SYNCEXCMDIAG_vidDiag                                                 */
/*   4 / SYNCEXCMDIAG_vidDiagExCmAcq                                          */
/*   5 / SYNCEXCMDIAG_vidExCmAcqVld                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6884540 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCEXCMDIAG/SYNCEXCMDIAG_FCT$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCEXCMDIAG.h"
#include "SYNCEXCMDIAG_L.h"
#include "SYNCEXCMDIAG_IM.h"
#include "CAMHAL.h"
#include "DGOHAL.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCEXCMDIAG_vidInitOutput                                 */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sync_bExCmAcqVld;                                          */
/*  output boolean SYNCEXCMDIAG_bHysOutput;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCEXCMDIAG_vidInitOutput(void)
{
   VEMS_vidSET(Sync_bExCmAcqVld, 0);
   SYNCEXCMDIAG_bHysOutput = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCEXCMDIAG_vidIniDiag                                    */
/* !Description :  Au réveil ECU et à chaque KEY OFF-ON, la panne élémentaire */
/*                 et les conditions de diagnostics sont remises à zéro       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bDgoCoh_ExCm;                                         */
/*  output boolean Sync_bMonRunCoh_ExCm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCEXCMDIAG_vidIniDiag(void)
{
   Sync_bDgoCoh_ExCm = 0;
   Sync_bMonRunCoh_ExCm = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCEXCMDIAG_vidDiag                                       */
/* !Description :  En cas de perte des conditions de diagnostic, le flag de   */
/*                 détection de la panne élémentaire est figé à sa dernière   */
/*                 valeur valide.                                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCEXCMDIAG_vidDiagExCmAcq();                           */
/*  input boolean Ext_bPresExCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCEXCMDIAG_vidDiag(void)
{
   boolean bLocalExt_bPresExCmSen;


   VEMS_vidGET(Ext_bPresExCmSen,bLocalExt_bPresExCmSen);
   if (bLocalExt_bPresExCmSen != 0)
   {
      SYNCEXCMDIAG_vidDiagExCmAcq();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCEXCMDIAG_vidDiagExCmAcq                                */
/* !Description :  Fonction responsable du diagnostic.                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Dena_chr_excamdiag;                                         */
/*  input boolean Dft_chr_excamdiag;                                          */
/*  input boolean Acq_excam_chr_diag_ena_upcb0;                               */
/*  input uint16 Sync_nEngInhMonCohExCm_C;                                    */
/*  input uint16 Sync_nEngInhMonCohExCm_Hys_C;                                */
/*  input boolean SYNCEXCMDIAG_bHysOutput;                                    */
/*  input boolean Sync_bMonRunCoh_ExCm;                                       */
/*  output boolean Sync_bMonRunCoh_ExCm;                                      */
/*  output boolean Sync_bDgoCoh_ExCm;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCEXCMDIAG_vidDiagExCmAcq(void)
{
   boolean bLocalInhCohExCmDiag;
   boolean bLocalDenaChrExcamdiag;
   boolean bLocalDftChrExcamdiag;
   uint16  u16LocalExt_nEng;
   uint16  u16localSum;
   uint32  u32localSum;


   bLocalInhCohExCmDiag = GDGAR_bGetFRM(FRM_FRM_INHCOHEXCMDIAG);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Dena_chr_excamdiag, bLocalDenaChrExcamdiag);
   VEMS_vidGET(Dft_chr_excamdiag, bLocalDftChrExcamdiag);

   if (  (Acq_excam_chr_diag_ena_upcb0 != 0)
      && (bLocalDenaChrExcamdiag != 0)
      && (bLocalInhCohExCmDiag == 0))
   {
      Sync_bMonRunCoh_ExCm = 1;
   }
   else
   {
      Sync_bMonRunCoh_ExCm = 0;
   }

   u32localSum = (uint32)( Sync_nEngInhMonCohExCm_C
                         + Sync_nEngInhMonCohExCm_Hys_C);
   u16localSum = (uint16)MATHSRV_udtMIN(u32localSum, 65535);
   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                Sync_nEngInhMonCohExCm_C,
                                u16localSum,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &SYNCEXCMDIAG_bHysOutput);

   if (  (bLocalDftChrExcamdiag != 0)
      && (Sync_bMonRunCoh_ExCm != 0)
      && (SYNCEXCMDIAG_bHysOutput != 0 ))
   {
      Sync_bDgoCoh_ExCm = 1;
   }
   else
   {
      Sync_bDgoCoh_ExCm = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCEXCMDIAG_vidExCmAcqVld                                 */
/* !Description :  L’acquisition du signal arbre à cames échappement est      */
/*                 considérée comme valide si aucune panne élémentaire  sur le*/
/*                 profil du signal arbre à cames échappement n’est détectée  */
/*                 et si les conditions de diagnostics sont remplies.         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Sync_bDgoCoh_ExCm;                                          */
/*  input boolean Sync_bMonRunCoh_ExCm;                                       */
/*  output boolean Sync_bExCmAcqVld;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCEXCMDIAG_vidExCmAcqVld(void)
{
   boolean bLocalSync_bExCmAcqVld;


   if (  (Sync_bDgoCoh_ExCm ==0 )
      && (Sync_bMonRunCoh_ExCm != 0))
   {
      bLocalSync_bExCmAcqVld = 1;
   }
   else
   {
      bLocalSync_bExCmAcqVld = 0;
   }
   VEMS_vidSET(Sync_bExCmAcqVld, bLocalSync_bExCmAcqVld);
}
/*---------------------------- end of file ----------------------------------*/