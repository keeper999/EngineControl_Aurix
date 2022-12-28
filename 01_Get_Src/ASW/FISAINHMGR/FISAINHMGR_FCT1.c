/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FISAINHMGR                                              */
/* !Description     : FISAINHMGR component                                    */
/*                                                                            */
/* !Module          : FISAINHMGR                                              */
/* !Description     : INHIBITIONS ET RECONFIGURATIONS RELATIVES À LA FONCTION */
/*                    D’ADAPTATION DE L’INJECTION AU DÉMARRAGE (FISA)         */
/*                                                                            */
/* !File            : FISAINHMGR_FCT1.C                                       */
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
/*   1 / FISAINHMGR_vidInitOutput                                             */
/*   2 / FISAINHMGR_vidFisaCaseDetermin                                       */
/*   3 / FISAINHMGR_vidCrankingState                                          */
/*   4 / FISAINHMGR_vidReconfigManagement                                     */
/*   5 / FISAINHMGR_vidFisaLearningInhib                                      */
/*   6 / FISAINHMGR_vidMoveModeRefugeLean                                     */
/*   7 / FISAINHMGR_vidMoveModeRefugeRich                                     */
/*   8 / FISAINHMGR_vidInhibObservInst                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/FISAINHMGR/FISAINHMGR_FCT1.C_v    $*/
/* $Revision::   1.1      $$Author::   fgravez        $$Date::   26 Oct 2009 $*/
/* $Author::   fgravez                                $$Date::   26 Oct 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FISAINHMGR.h"
#include "FISAINHMGR_L.h"
#include "FISAINHMGR_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Fonction d'initialisation des sorties.                      */
/* !Number      : FCT1.1                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*                                                                            */
/*   output boolean FISA_bInhFISA;                                            */
/*   output boolean FISA_bPoor;                                               */
/*   output boolean FISA_bRich;                                               */
/*   output boolean FISA_bInhInst;                                            */
/*   output sint16 TqRes_tqMaxRes_prev;                                       */
/*   output sint16 Ext_uBattMes_prev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidInitOutput(void)
{
   VEMS_vidSET(FISA_bInhFISA,0);
   VEMS_vidSET(FISA_bPoor,0);
   VEMS_vidSET(FISA_bRich,0);
   VEMS_vidSET(FISA_bInhInst,0);
   TqRes_tqMaxRes_prev = 0;
   Ext_uBattMes_prev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Ce bloc permet de déterminer des cas de vie spécifique aux  */
/*                besoins de reconfiguration pour la fonction FISA .          */
/* !Number      : FCT1.2                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void FISAINHMGR_vidCrankingState();                          */
/*                                                                            */
/*   input st23 Vehicle_active_state;                                         */
/*   input bool VS_CRANKING;                                                  */
/*   input boolean Demarrage_poussette;                                       */
/*   input sint16 TqRes_tqMaxRes;                                             */
/*   input sint16 TqRes_tqMaxRes_prev;                                        */
/*   input sint16 tqMaxResInhFisa_C;                                          */
/*                                                                            */
/*   output boolean Detection_demarrage_poussette;                            */
/*   output boolean Detection_consommateurs_actifs;                           */
/*   output sint16 TqRes_tqMaxRes_prev;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidFisaCaseDetermin(void)
{
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalTemp;
   sint16  s16LocalTqRes_tqMaxRes;
   sint32  s32LocalTemp;


   VEMS_vidGET(Vehicle_active_state,u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_CRANKING)
   {
      FISAINHMGR_vidCrankingState();
      Detection_demarrage_poussette = Demarrage_poussette;
   }
   else
   {
      Detection_demarrage_poussette = 0;
   }
   VEMS_vidGET(TqRes_tqMaxRes,s16LocalTqRes_tqMaxRes);
   s32LocalTemp = (sint32)(s16LocalTqRes_tqMaxRes - TqRes_tqMaxRes_prev);
   u16LocalTemp = (uint16)MATHSRV_udtABS(s32LocalTemp);
   if (u16LocalTemp > tqMaxResInhFisa_C)
   {
      Detection_consommateurs_actifs = 1;
   }
   else
   {
      Detection_consommateurs_actifs = 0;
   }
   TqRes_tqMaxRes_prev = (sint16)MATHSRV_udtCLAMP(s16LocalTqRes_tqMaxRes,
                                                  -32000,
                                                  32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Au démarrage , si le regime moteur est inférieure au seuil  */
/*                d'inhibition FISA ou  si le seuil maximal pour le gradient  */
/*                de tension batterie est dépassé ou bien le demarrage à la   */
/*                poussette est  détecté .Il y'aura détection d'un état       */
/*                cranking.                                                   */
/* !Number      : FCT1.3                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*                                                                            */
/*   input uint16 Ext_nEng;                                                   */
/*   input uint16 Ext_nEngCrkInhFisa_C;                                       */
/*   input sint16 Ext_uBattMes;                                               */
/*   input sint16 Ext_uBattMes_prev;                                          */
/*   input uint16 Ext_uBattMesDelta;                                          */
/*   input uint16 Ext_uBattMesInhFisa_C;                                      */
/*   input boolean Dml_cmd_cranking;                                          */
/*                                                                            */
/*   output boolean Ext_nEngCrkInf;                                           */
/*   output uint16 Ext_uBattMesDelta;                                         */
/*   output boolean Ext_uBattMesDeltaSup;                                     */
/*   output sint16 Ext_uBattMes_prev;                                         */
/*   output boolean Demarrage_poussette;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : H.BCHINI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidCrankingState(void)
{
   boolean bLocalDml_cmd_cranking;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalExt_uBattMesDelta;
   sint16  s16LocalExt_uBattMes;
   sint32  s32LocalTemp;


   VEMS_vidGET(Ext_nEng,u16LocalExt_nEng);
   if (u16LocalExt_nEng < Ext_nEngCrkInhFisa_C)
   {
      Ext_nEngCrkInf = 1;
   }
   else
   {
      Ext_nEngCrkInf = 0;
   }
   VEMS_vidGET(Ext_uBattMes,s16LocalExt_uBattMes);
   s32LocalTemp = (sint32)(s16LocalExt_uBattMes - Ext_uBattMes_prev);
   u16LocalExt_uBattMesDelta = (uint16)MATHSRV_udtABS(s32LocalTemp);
   Ext_uBattMesDelta = (uint16)MATHSRV_udtMIN(u16LocalExt_uBattMesDelta, 3200);

   if (Ext_uBattMesDelta > Ext_uBattMesInhFisa_C)
   {
      Ext_uBattMesDeltaSup = 1;
   }
   else
   {
      Ext_uBattMesDeltaSup = 0;
   }
   Ext_uBattMes_prev = (sint16) MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   VEMS_vidGET(Dml_cmd_cranking,bLocalDml_cmd_cranking);
   if (bLocalDml_cmd_cranking == 0)
   {
      Demarrage_poussette = 1;
   }
   else
   {
      Demarrage_poussette = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Cette fonction permet de considérer tous les modes de       */
/*                défaillances et cas de vie particuliers impactant la        */
/*                stratégie d’adaptation de l’injection au démarrage.         */
/* !Number      : FCT1.4                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/* !Requirement : VEMS_R_08_07067_001.01                                      */
/*                VEMS_R_08_07067_002.01                                      */
/*                VEMS_R_08_07067_003.01                                      */
/*                VEMS_R_08_07067_004.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void FISAINHMGR_vidFisaLearningInhib();                      */
/*   extf argret void FISAINHMGR_vidMoveModeRefugeLean();                     */
/*   extf argret void FISAINHMGR_vidMoveModeRefugeRich();                     */
/*   extf argret void FISAINHMGR_vidInhibObservInst();                        */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidReconfigManagement(void)
{
   FISAINHMGR_vidFisaLearningInhib();
   FISAINHMGR_vidMoveModeRefugeLean();
   FISAINHMGR_vidMoveModeRefugeRich();
   FISAINHMGR_vidInhibObservInst();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : cette fonction permet de déterminer la démande d'inhibition */
/*                du FISA via le booléen FISA_bInhFISA.                       */
/* !Number      : FCT1.5                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*   input uint16 Ext_pAirExtMes;                                             */
/*   input uint16 Ext_pAirExtMesMaxInhFisa_C;                                 */
/*   input uint16 Ext_pAirExtMesMinInhFisa_C;                                 */
/*   input sint16 Ext_tCoMes;                                                 */
/*   input uint8 Ext_stGBxCf;                                                 */
/*   input boolean Ext_bCluPedPrss;                                           */
/*   input sint16 Ext_tCoMesMinInhFisa_C;                                     */
/*   input sint16 Eng_tOilEstim;                                              */
/*   input sint16 DiftCotOilFisaTrsh_C;                                       */
/*   input boolean Flev_low_fuel_level;                                       */
/*   input boolean Ext_nEngCrkInf;                                            */
/*   input boolean Ext_uBattMesDeltaSup;                                      */
/*   input boolean Detection_demarrage_poussette;                             */
/*   input boolean Detection_consommateurs_actifs;                            */
/*                                                                            */
/*   output boolean FISA_bInhFISA;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidFisaLearningInhib(void)
{
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalExt_bCluPedPrss;
   boolean bLocalFISA1;
   boolean bLocalFISA2;
   boolean bLocalFISA3;
   boolean bLocalInhFISA;
   uint8   u8LocalExt_stGBxCf;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16Localtemp;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalEng_tOilEstim;
   sint32  s32LocalTemp;


   VEMS_vidGET(Ext_pAirExtMes,u16LocalExt_pAirExtMes);
   if (  (Ext_pAirExtMesMaxInhFisa_C < u16LocalExt_pAirExtMes)
      || (u16LocalExt_pAirExtMes < Ext_pAirExtMesMinInhFisa_C))
   {
      bLocalFISA1 = 1;
   }
   else
   {
      bLocalFISA1 = 0;
   }
   VEMS_vidGET(Ext_tCoMes,s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_stGBxCf,u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_bCluPedPrss,bLocalExt_bCluPedPrss);
   if (  (s16LocalExt_tCoMes < Ext_tCoMesMinInhFisa_C)
      && (u8LocalExt_stGBxCf == BVM)
      && (bLocalExt_bCluPedPrss == 0))
   {
      bLocalFISA2 = 1;
   }
   else
   {
      bLocalFISA2 = 0;
   }
   VEMS_vidGET(Eng_tOilEstim,s16LocalEng_tOilEstim);
   s32LocalTemp = (sint32)( (4 * s16LocalExt_tCoMes) - s16LocalEng_tOilEstim);
   u16Localtemp = (uint16)MATHSRV_udtABS(s32LocalTemp);
   if ( u16Localtemp > DiftCotOilFisaTrsh_C)
   {
      bLocalFISA3 = 1;
   }
   else
   {
      bLocalFISA3 = 0;
   }
   bLocalInhFISA = GDGAR_bGetFRM(FRM_FRM_INHFISA);
   VEMS_vidGET(Flev_low_fuel_level,bLocalFlev_low_fuel_level);
   if (  (bLocalInhFISA != 0)
      || (bLocalFISA1 != 0)
      || (bLocalFlev_low_fuel_level != 0)
      || (bLocalFISA2 != 0)
      || (Ext_nEngCrkInf != 0)
      || (Ext_uBattMesDeltaSup != 0)
      || (Detection_demarrage_poussette != 0)
      || (Detection_consommateurs_actifs != 0)
      || (bLocalFISA3 != 0)
      )
   {
      VEMS_vidSET(FISA_bInhFISA,1);
   }
   else
   {
      VEMS_vidSET(FISA_bInhFISA,0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : La demande de passage en mode FISA pauvre via le booléen    */
/*                FISA_bPoor a lieu dans les cas suivants : FRM_bAcvFISAPoor à*/
/*                1                                                           */
/* !Number      : FCT1.6                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*                                                                            */
/*   output boolean FISA_bPoor;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidMoveModeRefugeLean(void)
{
   boolean bLocalAcvFISAPoor;


   bLocalAcvFISAPoor = GDGAR_bGetFRM(FRM_FRM_ACVFISAPOOR);
   VEMS_vidSET(FISA_bPoor,bLocalAcvFISAPoor);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : La demande de passage en mode FISA riche via le booléen     */
/*                FISA_bRich a lieu dans les cas suivants : FRM_bAcvFISARich à*/
/*                1                                                           */
/* !Number      : FCT1.7                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*                                                                            */
/*   output boolean FISA_bRich;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidMoveModeRefugeRich(void)
{
   boolean bLocalAcvFISARich;


   bLocalAcvFISARich = GDGAR_bGetFRM(FRM_FRM_ACVFISARICH);
   VEMS_vidSET(FISA_bRich,bLocalAcvFISARich);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : cette fonction permet de déterminer la demande d’inhibition */
/*                de l’observation des instabilités.                          */
/* !Number      : FCT1.8                                                      */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*                                                                            */
/*   output boolean FISA_bInhInst;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidInhibObservInst(void)
{

   VEMS_vidSET(FISA_bInhInst,0);
}
/*------------------------------- end of file --------------------------------*/