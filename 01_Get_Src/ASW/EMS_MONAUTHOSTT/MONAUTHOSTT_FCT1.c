/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MONAUTHOSTT                                             */
/* !Description     : MONAUTHOSTT Component                                   */
/*                                                                            */
/* !Module          : MONAUTHOSTT                                             */
/* !Description     : SAFETY TMS : STT Chaine de Traction                     */
/*                                                                            */
/* !File            : MONAUTHOSTT_FCT1.C                                      */
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
/*   1 / MONAUTHOSTT_vidInitOutput                                            */
/*   2 / MONAUTHOSTT_vidConfigArchiEEBV                                       */
/*   3 / MONAUTHOSTT_vidSTTConfiguration                                      */
/*   4 / MONAUTHOSTT_vidSecurisationADML                                      */
/*   5 / MONAUTHOSTT_vidMiseEnPlaceFRMBVA                                     */
/*   6 / MONAUTHOSTT_vidArchi2010et_BVA                                       */
/*   7 / MONAUTHOSTT_vidArch2004_2010_BVA                                     */
/*   8 / MONAUTHOSTT_vidArchi2010_et_BVMP                                     */
/*   9 / MONAUTHOSTT_vidArch2004_2010BVMP                                     */
/*   10 / MONAUTHOSTT_vidCoordSecuriADML                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5199597 / 01                                        */
/* !OtherRefs   : 01460_10_03769 / 1.3                                        */
/* !OtherRefs   : VEMS V02 ECU#047008                                         */
/* !OtherRefs   : VEMS V02 ECU#060257                                         */
/* !OtherRefs   : VEMS V02 ECU#065855                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/MONAUTHOSTT/MONAUTHOST$*/
/* $Revision::   1.4.1.3  $$Author::   mbenfrad       $$Date::   23 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   23 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MONAUTHOSTT.h"
#include "MONAUTHOSTT_L.h"
#include "MONAUTHOSTT_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 MONAUTHOSTT_u16Counter;                                     */
/*  output uint16 MONAUTHOSTT_u16Counter1;                                    */
/*  output uint16 MONAUTHOSTT_u16Counter2;                                    */
/*  output uint16 MONAUTHOSTT_u16Counter3;                                    */
/*  output uint16 MONAUTHOSTT_u16Counter4;                                    */
/*  output boolean MONAUTHOSTT_bDftDrvTra2010AMTMrg;                          */
/*  output boolean MONAUTHOSTT_bDftStaAuthAMTMerge;                           */
/*  output boolean MONAUTHOSTT_bInhEngStopMTCfMerge;                          */
/*  output boolean MONAUTHOSTT_bRStrtAuthSTTMerge;                            */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev;                            */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev1;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev2;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev3;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev4;                           */
/*  output uint16 MONAUTHOSTT_u16spdVehSecuPrev;                              */
/*  output boolean SftyMgt_bInhEngStopMTCf;                                   */
/*  output boolean SftyMgt_bDftSTT;                                           */
/*  output boolean SftyMgt_bDgoDrvTra;                                        */
/*  output boolean SftyMgt_bDgoInhEngStopSTT;                                 */
/*  output boolean SftyMgt_bMonRunDrvTra;                                     */
/*  output boolean SftyMgt_bMonRunInhEngStopSTT;                              */
/*  output boolean Sfty_bInhDrvTraSfty;                                       */
/*  output boolean Sfty_bInhEngStopSTTReq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidInitOutput(void)
{
   MONAUTHOSTT_u16Counter = 0;
   MONAUTHOSTT_u16Counter1 = 0;
   MONAUTHOSTT_u16Counter2 = 0;
   MONAUTHOSTT_u16Counter3 = 0;
   MONAUTHOSTT_u16Counter4 = 0;
   MONAUTHOSTT_bDftDrvTra2010AMTMrg = 0;
   MONAUTHOSTT_bDftStaAuthAMTMerge = 0;
   MONAUTHOSTT_bInhEngStopMTCfMerge = 0;
   MONAUTHOSTT_bRStrtAuthSTTMerge = 0;
   MONAUTHOSTT_u16SftyMgt_nEngPrev = 0;
   MONAUTHOSTT_u16SftyMgt_nEngPrev1 = 0;
   MONAUTHOSTT_u16SftyMgt_nEngPrev2 = 0;
   MONAUTHOSTT_u16SftyMgt_nEngPrev3 = 0;
   MONAUTHOSTT_u16SftyMgt_nEngPrev4 = 0;
   MONAUTHOSTT_u16spdVehSecuPrev = 0;
   SftyMgt_bInhEngStopMTCf = 0;
   VEMS_vidSET(SftyMgt_bDftSTT, 0);
   VEMS_vidSET(SftyMgt_bDgoDrvTra, 0);
   VEMS_vidSET(SftyMgt_bDgoInhEngStopSTT, 0);
   VEMS_vidSET(SftyMgt_bMonRunDrvTra, 0);
   VEMS_vidSET(SftyMgt_bMonRunInhEngStopSTT, 0);
   VEMS_vidSET(Sfty_bInhDrvTraSfty, 0);
   VEMS_vidSET(Sfty_bInhEngStopSTTReq, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidConfigArchiEEBV                             */
/* !Description :  Detecte la configuration BV et Archi EE                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stStrtCf;                                                 */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 SftyMgt_stTypAM_C;                                            */
/*  input uint8 SftyMgt_st2004_C;                                             */
/*  input uint8 SftyMgt_stTypAMT_C;                                           */
/*  input uint8 SftyMgt_stTypMT_C;                                            */
/*  output boolean SftyMgt_bEna2010AMCf;                                      */
/*  output boolean SftyMgt_bEnaAMCf;                                          */
/*  output boolean SftyMgt_bEna2010AMTCf;                                     */
/*  output boolean SftyMgt_bEnaAMTCf;                                         */
/*  output boolean SftyMgt_bEnaMTSTTADCf;                                     */
/*  output boolean SftyMgt_bEnaNotMTSTTADCf;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidConfigArchiEEBV(void)
{
   uint8 u8LocalExt_stStrtCf;
   uint8 u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_stStrtCf, u8LocalExt_stStrtCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);

   SftyMgt_bEna2010AMCf = 0;
   SftyMgt_bEnaAMCf = 0;
   SftyMgt_bEna2010AMTCf = 0;
   SftyMgt_bEnaAMTCf = 0;
   SftyMgt_bEnaMTSTTADCf = 0;
   SftyMgt_bEnaNotMTSTTADCf = 0;

   if (u8LocalExt_stGBxCf == SftyMgt_stTypAM_C)
   {
      SftyMgt_bEnaAMCf = 1;
      if (u8LocalExt_stStrtCf != SftyMgt_st2004_C)
      {
         SftyMgt_bEna2010AMCf = 1;
      }
   }
   else
   {
      if (u8LocalExt_stGBxCf == SftyMgt_stTypAMT_C)
      {
         SftyMgt_bEnaAMTCf = 1;
         if (u8LocalExt_stStrtCf != SftyMgt_st2004_C)
         {
            SftyMgt_bEna2010AMTCf = 1;
         }
      }
   }
   if (u8LocalExt_stGBxCf == SftyMgt_stTypMT_C)
   {
      SftyMgt_bEnaMTSTTADCf = 1;
   }
   else
   {
      SftyMgt_bEnaNotMTSTTADCf = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidSTTConfiguration                            */
/* !Description :  Cette fonction permet de bypasser la sécurisation des      */
/*                 demandes Démarrage / redémarrage STTd                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bSTTCf;                                             */
/*  output boolean SftyMgt_bEnaSTTADCf;                                       */
/*  output boolean SftyMgt_bEnaNotSTTADCf;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidSTTConfiguration(void)
{
   boolean bLocalSftyMgt_bSTTCf;


   VEMS_vidGET(SftyMgt_bSTTCf, bLocalSftyMgt_bSTTCf);
   if (bLocalSftyMgt_bSTTCf != 0)
   {
      SftyMgt_bEnaSTTADCf = 1;
      SftyMgt_bEnaNotSTTADCf = 0;
   }
   else
   {
      SftyMgt_bEnaSTTADCf = 0;
      SftyMgt_bEnaNotSTTADCf = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidSecurisationADML                            */
/* !Description :  Sécurisation de l’ouverture de la chaine de traction en    */
/*                 ADML BVA en fonction de l’architecture EE.                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MONAUTHOSTT_vidMiseEnPlaceFRMBVA();                      */
/*  extf argret void MONAUTHOSTT_vidArchi2010et_BVA();                        */
/*  extf argret void MONAUTHOSTT_vidArch2004_2010_BVA();                      */
/*  extf argret void MONAUTHOSTT_vidArchi2010_et_BVMP();                      */
/*  extf argret void MONAUTHOSTT_vidArch2004_2010BVMP();                      */
/*  extf argret void MONAUTHOSTT_vidCoordSecuriADML();                        */
/*  input boolean SftyMgt_bEna2010AMCf;                                       */
/*  input boolean SftyMgt_bEnaAMCf;                                           */
/*  input boolean SftyMgt_bEna2010AMTCf;                                      */
/*  input boolean SftyMgt_bEnaAMTCf;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidSecurisationADML(void)
{
   MONAUTHOSTT_vidMiseEnPlaceFRMBVA();

   if (SftyMgt_bEna2010AMCf != 0)
   {
      MONAUTHOSTT_vidArchi2010et_BVA();
   }

   if (SftyMgt_bEnaAMCf != 0)
   {
      MONAUTHOSTT_vidArch2004_2010_BVA();
   }

   if (SftyMgt_bEna2010AMTCf != 0)
   {
      MONAUTHOSTT_vidArchi2010_et_BVMP();
   }

   if (SftyMgt_bEnaAMTCf != 0)
   {
      MONAUTHOSTT_vidArch2004_2010BVMP();
   }

   MONAUTHOSTT_vidCoordSecuriADML();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidMiseEnPlaceFRMBVA                           */
/* !Description :  Sécurisation de la mise en place du FRM sur le flux de     */
/*                 l’état de la chaine de traction                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bAcvDrvTraInvldFRM;                                 */
/*  input uint8 SftyMgt_stDrvTraCoPTSt;                                       */
/*  input uint8 SftyMgt_stDrvTraInvld_C;                                      */
/*  output boolean SftyMgt_bDftDrivTraFRM;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidMiseEnPlaceFRMBVA(void)
{
   boolean bLocalSftyMgt_bAcvDrvTraInvldFRM;
   uint8   u8LocalSftyMgt_stDrvTraCoPTSt;


   VEMS_vidGET(SftyMgt_bAcvDrvTraInvldFRM, bLocalSftyMgt_bAcvDrvTraInvldFRM);
   VEMS_vidGET(SftyMgt_stDrvTraCoPTSt, u8LocalSftyMgt_stDrvTraCoPTSt);

   if (  (u8LocalSftyMgt_stDrvTraCoPTSt != SftyMgt_stDrvTraInvld_C)
      && (bLocalSftyMgt_bAcvDrvTraInvldFRM !=0))
   {
      SftyMgt_bDftDrivTraFRM = 1;
   }
   else
   {
      SftyMgt_bDftDrivTraFRM = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidArchi2010et_BVA                             */
/* !Description :  Sécurisation du diagnostic Chaine de traction pour ADML    */
/*                 Archi 2010 et BVA                                          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bATParkNeutExt;                                     */
/*  input boolean SftyMgt_bDgoSenPN;                                          */
/*  input boolean SftyMgt_bDgoSftyORngATCoPTSt;                               */
/*  input boolean SftyMgt_bDftDrvTra2010AM;                                   */
/*  output boolean SftyMgt_bDftDrvTra2010AM;                                  */
/*  output boolean MONAUTHOSTT_bDftDrvTra2010AMTMrg;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidArchi2010et_BVA(void)
{
   boolean bLocalSftyMgt_bATParkNeutExt;
   boolean bLocalSftyMgt_bDgoSenPN;
   boolean bLocalSftyMgt_bDgoSftyORgATCPTSt;


   VEMS_vidGET(SftyMgt_bATParkNeutExt, bLocalSftyMgt_bATParkNeutExt);
   VEMS_vidGET(SftyMgt_bDgoSenPN, bLocalSftyMgt_bDgoSenPN);
   VEMS_vidGET(SftyMgt_bDgoSftyORngATCoPTSt,
               bLocalSftyMgt_bDgoSftyORgATCPTSt);

   if (  (bLocalSftyMgt_bATParkNeutExt == bLocalSftyMgt_bDgoSenPN)
      && (bLocalSftyMgt_bDgoSftyORgATCPTSt == 0))
   {
      SftyMgt_bDftDrvTra2010AM = 1;
   }
   else
   {
      SftyMgt_bDftDrvTra2010AM = 0;
   }
   MONAUTHOSTT_bDftDrvTra2010AMTMrg = SftyMgt_bDftDrvTra2010AM;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidArch2004_2010_BVA                           */
/* !Description :  Sécurisation de la demande de démarrage en BVA             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bStaAuthStaCtl;                                     */
/*  input boolean SftyMgt_bDgoSenPN;                                          */
/*  input boolean SftyMgt_bDftStaAuthAM;                                      */
/*  output boolean SftyMgt_bDftStaAuthAM;                                     */
/*  output boolean MONAUTHOSTT_bDftStaAuthAMTMerge;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidArch2004_2010_BVA(void)
{
   boolean bLocalSftyMgt_bStaAuthStaCtl;
   boolean bLocalSftyMgt_bDgoSenPN;


   VEMS_vidGET(SftyMgt_bStaAuthStaCtl, bLocalSftyMgt_bStaAuthStaCtl);
   VEMS_vidGET(SftyMgt_bDgoSenPN, bLocalSftyMgt_bDgoSenPN);

   if (  (bLocalSftyMgt_bStaAuthStaCtl != 0)
      && (bLocalSftyMgt_bDgoSenPN == 0))
   {
      SftyMgt_bDftStaAuthAM = 1;
   }
   else
   {
      SftyMgt_bDftStaAuthAM = 0;
   }
   MONAUTHOSTT_bDftStaAuthAMTMerge = SftyMgt_bDftStaAuthAM;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidArchi2010_et_BVMP                           */
/* !Description :  Sécurisation du diagnostic Chaine de traction pour ADML    */
/*                 Archi 2010 et BVMP                                         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_008.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDrvTraAMTExt;                                      */
/*  input boolean SftyMgt_bInhStrtAMT;                                        */
/*  input boolean SftyMgt_bDgoSftyORngAMCoPTSt;                               */
/*  input boolean SftyMgt_bDftDrvTra2010AMT;                                  */
/*  output boolean SftyMgt_bDftDrvTra2010AMT;                                 */
/*  output boolean MONAUTHOSTT_bDftDrvTra2010AMTMrg;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidArchi2010_et_BVMP(void)
{
   boolean bLocalSftyMgt_bDrvTraAMTExt;
   boolean bLocalSftyMgt_bInhStrtAMT;
   boolean bLocalSftyMgt_bDgoSftyORgAMCPTSt;


   VEMS_vidGET(SftyMgt_bDrvTraAMTExt, bLocalSftyMgt_bDrvTraAMTExt);
   VEMS_vidGET(SftyMgt_bInhStrtAMT, bLocalSftyMgt_bInhStrtAMT);
   VEMS_vidGET(SftyMgt_bDgoSftyORngAMCoPTSt,
               bLocalSftyMgt_bDgoSftyORgAMCPTSt);

   if (  (bLocalSftyMgt_bDrvTraAMTExt == bLocalSftyMgt_bInhStrtAMT)
      && (bLocalSftyMgt_bDgoSftyORgAMCPTSt == 0))
   {
      SftyMgt_bDftDrvTra2010AMT = 1;
   }
   else
   {
      SftyMgt_bDftDrvTra2010AMT = 0;
   }
   MONAUTHOSTT_bDftDrvTra2010AMTMrg = SftyMgt_bDftDrvTra2010AMT;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidArch2004_2010BVMP                           */
/* !Description :  Sécurisation de la demande de démarrage en BVMP            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bStaAuthStaCtl;                                     */
/*  input boolean SftyMgt_bInhStrtAMT;                                        */
/*  input boolean SftyMgt_bDftStaAuthAMT;                                     */
/*  output boolean SftyMgt_bDftStaAuthAMT;                                    */
/*  output boolean MONAUTHOSTT_bDftStaAuthAMTMerge;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidArch2004_2010BVMP(void)
{
   boolean bLocalSftyMgt_bStaAuthStaCtl;
   boolean bLocalSftyMgt_bInhStrtAMT;


   VEMS_vidGET(SftyMgt_bStaAuthStaCtl, bLocalSftyMgt_bStaAuthStaCtl);
   VEMS_vidGET(SftyMgt_bInhStrtAMT, bLocalSftyMgt_bInhStrtAMT);

   if (  (bLocalSftyMgt_bStaAuthStaCtl != 0)
      && (bLocalSftyMgt_bInhStrtAMT == 0))
   {
      SftyMgt_bDftStaAuthAMT = 1;
   }
   else
   {
      SftyMgt_bDftStaAuthAMT = 0;
   }
   MONAUTHOSTT_bDftStaAuthAMTMerge = SftyMgt_bDftStaAuthAMT;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCoordSecuriADML                             */
/* !Description :  Paramétrage de la prise en compte des défauts et filtrage  */
/*                 anti-rebond.                                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_tiDlyOnDftDrvTraFRM_C;                               */
/*  input boolean SftyMgt_bDftDrivTraFRM;                                     */
/*  input uint16 MONAUTHOSTT_u16Counter;                                      */
/*  input boolean SftyMgt_bInhDftDrvTraFRM_C;                                 */
/*  input boolean SftyMgt_bInhDftTra2010_C;                                   */
/*  input boolean MONAUTHOSTT_bDftDrvTra2010AMTMrg;                           */
/*  input boolean SftyMgt_bInhDftStaAuth_C;                                   */
/*  input boolean MONAUTHOSTT_bDftStaAuthAMTMerge;                            */
/*  input uint16 SftyMgt_tiDlyOnDftDrvTra_C;                                  */
/*  input boolean SftyMgt_bDftDrvTra_MP;                                      */
/*  input uint16 MONAUTHOSTT_u16Counter1;                                     */
/*  input boolean SftyMgt_bInhDgoDrvTraSfty_C;                                */
/*  input boolean SftyMgt_bDgoDrvTraSfty;                                     */
/*  output uint16 MONAUTHOSTT_u16Counter;                                     */
/*  output boolean SftyMgt_bDgoDrvTraFRM;                                     */
/*  output boolean SftyMgt_bDftDrvTra_MP;                                     */
/*  output uint16 MONAUTHOSTT_u16Counter1;                                    */
/*  output boolean SftyMgt_bDgoDrvTraSfty;                                    */
/*  output boolean SftyMgt_bDgoDrvTra;                                        */
/*  output boolean Sfty_bInhDrvTraSfty;                                       */
/*  output boolean SftyMgt_bMonRunDrvTra;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCoordSecuriADML(void)
{
   boolean bLocalTurnOnDLyOut1;
   boolean bLocalSwitch1;
   boolean bLocalSwitch2;
   boolean bLocalTurnOnDLyOut;
   uint16  u16LocalSumTurnOnDelaySimple;
   uint16  u16LocalMinTurnOnDelaySimple;


   /*Turn_On_Delay_Simple1*/
   u16LocalSumTurnOnDelaySimple = (uint16)( (SftyMgt_tiDlyOnDftDrvTraFRM_C + 6)
                                          / 4);
   if (SftyMgt_bDftDrivTraFRM == 0)
   {
      MONAUTHOSTT_u16Counter = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16Counter,
                                u16LocalSumTurnOnDelaySimple);
      MONAUTHOSTT_u16Counter = (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   if (MONAUTHOSTT_u16Counter >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalTurnOnDLyOut1 = 1;
   }
   else
   {
      bLocalTurnOnDLyOut1 = 0;
   }
   /*fin Turn_On_Delay_Simple1*/

   if (SftyMgt_bInhDftDrvTraFRM_C != 0)
   {
      SftyMgt_bDgoDrvTraFRM = 0;
   }
   else
   {
      SftyMgt_bDgoDrvTraFRM = bLocalTurnOnDLyOut1;
   }

   if (SftyMgt_bInhDftTra2010_C != 0)
   {
      bLocalSwitch1 = 0;
   }
   else
   {
      bLocalSwitch1 = MONAUTHOSTT_bDftDrvTra2010AMTMrg;
   }

   if (SftyMgt_bInhDftStaAuth_C != 0)
   {
      bLocalSwitch2 = 0;
   }
   else
   {
      bLocalSwitch2 = MONAUTHOSTT_bDftStaAuthAMTMerge;
   }

   if (  (bLocalSwitch1 != 0)
      || (bLocalSwitch2 != 0))
   {
      SftyMgt_bDftDrvTra_MP = 1;
   }
   else
   {
      SftyMgt_bDftDrvTra_MP = 0;
   }

   /*Turn_On_Delay_Simple*/
   u16LocalSumTurnOnDelaySimple = (uint16)( (SftyMgt_tiDlyOnDftDrvTra_C + 6)
                                          / 4);
   if (SftyMgt_bDftDrvTra_MP == 0)
   {
      MONAUTHOSTT_u16Counter1 = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16Counter1,
                                u16LocalSumTurnOnDelaySimple);
      MONAUTHOSTT_u16Counter1 = (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   if (MONAUTHOSTT_u16Counter1 >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalTurnOnDLyOut = 1;
   }
   else
   {
      bLocalTurnOnDLyOut = 0;
   }
   /*fin Turn_On_Delay_Simple*/

   if (SftyMgt_bInhDgoDrvTraSfty_C != 0)
   {
      SftyMgt_bDgoDrvTraSfty = 0;
   }
   else
   {
      SftyMgt_bDgoDrvTraSfty = bLocalTurnOnDLyOut;
   }
   VEMS_vidSET(SftyMgt_bDgoDrvTra, bLocalTurnOnDLyOut);
   VEMS_vidSET(Sfty_bInhDrvTraSfty, SftyMgt_bDgoDrvTraSfty);
   VEMS_vidSET(SftyMgt_bMonRunDrvTra, 1);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/