/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKFASTCOR                                              */
/* !Description     : KNKFASTCOR Component                                    */
/*                                                                            */
/* !Module          : KNKFASTCOR                                              */
/* !Description     : Correction rapide d’avance anti-cliquetis               */
/*                                                                            */
/* !File            : KNKFASTCOR_FCT2.C                                       */
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
/*   1 / KNKFASTCOR_vidFastCorrIncre                                          */
/*   2 / KNKFASTCOR_vidFastCorrDecre                                          */
/*   3 / KNKFASTCOR_vidDecrementation                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5059533 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKFASTCOR/KNKFASTCOR_FCT2.C$*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   25 Mar 2011 $*/
/* $Author::   wbouach                                $$Date::   25 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKFASTCOR.h"
#include "KNKFASTCOR_L.h"
#include "KNKFASTCOR_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidFastCorrIncre                                */
/* !Description :  On applique une correction rapide                          */
/*                 Cliq_pas_boucle_rapide_map que l’on maintient pendant un   */
/*                 délai Duree_maintien_boucle_rapide_map. Cette tempo est    */
/*                 calibrée en cycles moteur de façon à être générique N      */
/*                 cylindres.                                                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_08_07418_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 IgSys_prm_agIgMaxWiPrevAdpCyl[6];                             */
/*  input uint8 Correction_boucle_rapide[4];                                  */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  input boolean Cliquetis_cor_avance_type;                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 IgLim_rAirLd_A[8];                                           */
/*  input boolean KnkMgt_bSuperKnkCurCyl;                                     */
/*  input uint8 SuperCliq_pas_bouclRapide_map[16][8];                         */
/*  input uint8 Cliq_pas_boucle_rapide_map[16][8];                            */
/*  input uint8 Correction_max_rapide_map[16][8];                             */
/*  input uint8 Correction_max_rapide;                                        */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 FastCor_agFastCorLoopOfs_C;                                   */
/*  input uint8 Duree_correction_superCliq_map[16];                           */
/*  input uint8 Duree_maintien_boucle_rapide_map[16];                         */
/*  output uint8 Correction_max_rapide;                                       */
/*  output uint8 Correction_boucle_rapide[4];                                 */
/*  output uint8 Tempo_boucle_rapide[4];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidFastCorrIncre(void)
{
   boolean  bLocalrationaloperator;
   uint8    u8LocalCliqPasBclRapid;
   uint8    u8LocalGetCliqPasBclRapid;
   uint8    u8LocalGetCliqIgMaxWiPrevAdpCyl;
   uint8    u8LocalEng_noCmprCyl;
   uint8    u8LocalIgSys_agIgSp;
   uint8    u8LocalCorrBouRap [4];
   /*QAC Msg(2:3132) : No impact on the function*/
   uint8    u8LocalInd;
   uint8    u8LocalCorrecBclRapid;
   uint8    u8LocalExt_noCylEng;
   uint16   u16LocalParaRegMot;
   uint16   u16LocalRegime_moteur;
   uint16   u16LocalExt_rAirLd;
   uint16   u16LocalParaIgLimAir;
   uint16   u16LocalSomme;
   sint16   s16LocalAdd;
   sint16   s16LocalSwitch;
   sint16   s16LocalSumCliqPasBclRapid;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         VEMS_vidGET1DArrayElement(IgSys_prm_agIgMaxWiPrevAdpCyl,
                                   u8LocalEng_noCmprCyl,
                                   u8LocalGetCliqIgMaxWiPrevAdpCyl);
         VEMS_vidGET1DArrayElement(Correction_boucle_rapide,
                                   u8LocalEng_noCmprCyl,
                                   u8LocalGetCliqPasBclRapid);
         VEMS_vidGET(IgSys_agIgSp, u8LocalIgSys_agIgSp);
         s16LocalAdd = (sint16)( u8LocalGetCliqIgMaxWiPrevAdpCyl
                               - u8LocalGetCliqPasBclRapid);
         if (u8LocalIgSys_agIgSp <= s16LocalAdd)
         {
            bLocalrationaloperator = 1;
         }
         else
         {
            bLocalrationaloperator = 0;
         }
         if (  (bLocalrationaloperator != 0)
            && (Cliquetis_cor_avance_type != 0))
         {
            s16LocalSwitch = (sint16)( u8LocalGetCliqIgMaxWiPrevAdpCyl
                                     - u8LocalIgSys_agIgSp);
         }
         else
         {
            s16LocalSwitch = (sint16)(u8LocalGetCliqPasBclRapid);
         }

         VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
         VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
         u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u16LocalRegime_moteur,
                                                        8191);
         u16LocalRegime_moteur = (uint16)(u16LocalRegime_moteur * 8);

         u16LocalParaRegMot =
               MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                            u16LocalRegime_moteur,
                                            16);

         u16LocalParaIgLimAir =
               MATHSRV_u16CalcParaIncAryU16(IgLim_rAirLd_A,
                                            u16LocalExt_rAirLd,
                                            8);
         if (KnkMgt_bSuperKnkCurCyl != 0)
         {
            u8LocalCliqPasBclRapid =
               MATHSRV_u8Interp2d(&SuperCliq_pas_bouclRapide_map[0][0],
                                  u16LocalParaRegMot,
                                  u16LocalParaIgLimAir,
                                  8);
         }
         else
         {
            u8LocalCliqPasBclRapid =
               MATHSRV_u8Interp2d(&Cliq_pas_boucle_rapide_map[0][0],
                                  u16LocalParaRegMot,
                                  u16LocalParaIgLimAir,
                                  8);
         }
         Correction_max_rapide =
               MATHSRV_u8Interp2d(&Correction_max_rapide_map[0][0],
                                  u16LocalParaRegMot,
                                  u16LocalParaIgLimAir,
                                  8);
         s16LocalSumCliqPasBclRapid =(sint16)( u8LocalCliqPasBclRapid
                                             + s16LocalSwitch);
         u8LocalCliqPasBclRapid =
               (uint8)MATHSRV_udtMIN(s16LocalSumCliqPasBclRapid,
                                     Correction_max_rapide);
         VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
         VEMS_vidGET1DArray(Correction_boucle_rapide,
                            4,
                            u8LocalCorrBouRap);
         u16LocalSomme = 0;
         for (u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
         {
            if (u8LocalInd != u8LocalEng_noCmprCyl)
            {
               u16LocalSomme =
                  (uint16)(u16LocalSomme + u8LocalCorrBouRap[u8LocalInd]);
            }
         }
         if (u8LocalExt_noCylEng > 1)
         {
            u16LocalSomme = (uint16)( FastCor_agFastCorLoopOfs_C
                                    + ( u16LocalSomme
                                      / (u8LocalExt_noCylEng - 1)));
            u8LocalCorrecBclRapid =
               (uint8)MATHSRV_udtMIN(u8LocalCliqPasBclRapid, u16LocalSomme);
            VEMS_vidSET1DArrayElement(Correction_boucle_rapide,
                                      u8LocalEng_noCmprCyl,
                                      u8LocalCorrecBclRapid);
         }
         else
         {
            VEMS_vidSET1DArrayElement(Correction_boucle_rapide,
                                      u8LocalEng_noCmprCyl,
                                      u8LocalCliqPasBclRapid);
         }
         if (KnkMgt_bSuperKnkCurCyl != 0)
         {
            u8LocalCliqPasBclRapid =
               MATHSRV_u8Interp1d(Duree_correction_superCliq_map,
                                  u16LocalParaRegMot);
         }
         else
         {
            u8LocalCliqPasBclRapid =
               MATHSRV_u8Interp1d(Duree_maintien_boucle_rapide_map,
                                  u16LocalParaRegMot);
         }
         Tempo_boucle_rapide[u8LocalEng_noCmprCyl] = u8LocalCliqPasBclRapid;
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidFastCorrDecre                                */
/* !Description :  Une fois le délai de maintien écoulé, on décrémente la     */
/*                 correction d’avance d’une valeur interpolée dans la carto  */
/*                 Cliq_cor_boucle_rapide_dec_map(Régime_moteur) tous les X   */
/*                 PMH (où X est issu de la carto :                           */
/*                 Duree_decrem_boucle_rapide_map(Régime_moteur)).            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKFASTCOR_vidDecrementation();                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 Tempo_boucle_rapide[4];                                       */
/*  output uint8 Tempo_boucle_rapide[4];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidFastCorrDecre(void)
{
   uint8  u8LocalEng_noCmprCyl;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         if (Tempo_boucle_rapide[u8LocalEng_noCmprCyl] == 1)
         {
            Tempo_boucle_rapide[u8LocalEng_noCmprCyl] = 0;
            /* 0_decrementation */
            KNKFASTCOR_vidDecrementation();
         }
         else
         {
            if (Tempo_boucle_rapide[u8LocalEng_noCmprCyl] != 0)
            {
               Tempo_boucle_rapide[u8LocalEng_noCmprCyl] =
                     (uint8)(Tempo_boucle_rapide[u8LocalEng_noCmprCyl] - 1);
            }
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidDecrementation                               */
/* !Description :  La temporisation Tempo_boucle_rapide est décrémentée tous  */
/*                 les N PMH pour un cylindre donné (Ou N est le nombre de    */
/*                 cylindres du moteur).                                      */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint8 Correction_boucle_rapide[4];                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 IgLim_rAirLd_A[8];                                           */
/*  input uint8 Duree_decrem_boucle_rapide_map[16][8];                        */
/*  input uint8 Cliq_cor_boucle_rapide_dec_map[16];                           */
/*  output uint8 Tempo_boucle_rapide[4];                                      */
/*  output uint8 Correction_boucle_rapide[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidDecrementation(void)
{
   uint8  u8LocalDureeDecrBclRpd;
   uint8  u8LocalCliqCorrBclRpdDec;
   uint8  u8LocalSoustrCliqCorBclRpd;
   uint8  u8LocalGetCliqPasBclRapid;
   uint8  u8LocalEng_noCmprCyl;
   uint16 u16LocalParaRegMot;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalParaIgLimAir;
   uint16 u16LocalRegime_moteur;
   sint16 s16LocalSoustrCliqCorBclRpd;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
         VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
         u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u16LocalRegime_moteur,
                                                        8191);
         u16LocalRegime_moteur = (uint16)(u16LocalRegime_moteur * 8);
         VEMS_vidGET1DArrayElement(Correction_boucle_rapide,
                                   u8LocalEng_noCmprCyl,
                                   u8LocalGetCliqPasBclRapid);
         u16LocalParaRegMot =
               MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                            u16LocalRegime_moteur,
                                            16);

         u16LocalParaIgLimAir =
               MATHSRV_u16CalcParaIncAryU16(IgLim_rAirLd_A,
                                            u16LocalExt_rAirLd,
                                            8);
         u8LocalDureeDecrBclRpd =
            MATHSRV_u8Interp2d(&Duree_decrem_boucle_rapide_map[0][0],
                               u16LocalParaRegMot,
                               u16LocalParaIgLimAir,
                               8);
         Tempo_boucle_rapide[u8LocalEng_noCmprCyl] = u8LocalDureeDecrBclRpd;

         u8LocalCliqCorrBclRpdDec =
               MATHSRV_u8Interp1d(Cliq_cor_boucle_rapide_dec_map,
                                  u16LocalParaRegMot);

         s16LocalSoustrCliqCorBclRpd =
               (sint16)(u8LocalGetCliqPasBclRapid - u8LocalCliqCorrBclRpdDec);

         u8LocalSoustrCliqCorBclRpd =
               (uint8)MATHSRV_udtMAX(s16LocalSoustrCliqCorBclRpd, 0);

         VEMS_vidSET1DArrayElement(Correction_boucle_rapide,
                                   u8LocalEng_noCmprCyl,
                                   u8LocalSoustrCliqCorBclRpd);
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*--------------------------------- end of file ------------------------------*/