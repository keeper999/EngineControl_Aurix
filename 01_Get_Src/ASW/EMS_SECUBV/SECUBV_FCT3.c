/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SECUBV                                                  */
/* !Description     : SECUBV Component                                        */
/*                                                                            */
/* !Module          : SECUBV                                                  */
/* !Description     : Sécuriser Boites                                        */
/*                                                                            */
/* !File            : SECUBV_FCT3.C                                           */
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
/*   1 / SECUBV_vidSecurisaMiseEnPlaceFRM                                     */
/*   2 / SECUBV_vidDetectionSIPInvalide                                       */
/*   3 / SECUBV_vidCalculSIPOutOfRange                                        */
/*   4 / SECUBV_vidCoordDebounceSIPErreur                                     */
/*   5 / SECUBV_vidCompteurSIP                                                */
/*   6 / SECUBV_vidComparaisonSeuilSIP                                        */
/*   7 / SECUBV_vidIFTHENCompteurSIP                                          */
/*   8 / SECUBV_vidRAZCompteurSIP                                             */
/*   9 / SECUBV_vidIncrementeCompteurSIP                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 01251 / 03                                        */
/* !OtherRefs   : 01460_09_01310 / 1.2                                        */
/* !OtherRefs   : VEMS V02 ECU#047007                                         */
/* !OtherRefs   : VEMS V02 ECU#050657                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_FCT3.C_v$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SECUBV.h"
#include "SECUBV_L.h"
#include "SECUBV_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidSecurisaMiseEnPlaceFRM                           */
/* !Description :  Ce bloc Coordonne sécurise la mise en place du FRM         */
/*                 d’inhibition de SIP                                        */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_018.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bSIPCoPt;                                           */
/*  input boolean SftyMgt_bDgoSIPORngCoPt;                                    */
/*  input boolean SftyMgt_bInhCoPtSIPFRM;                                     */
/*  input boolean SftyMgt_bInhSIPCord_MP;                                     */
/*  output boolean SftyMgt_bInhSIPCord_MP;                                    */
/*  output boolean SftyMgt_bDftSIPFRM;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidSecurisaMiseEnPlaceFRM(void)
{
   boolean bLocalSftyMgt_bSIPCoPt;
   boolean bLocalSftyMgt_bDgoSIPORngCoPt;
   boolean bLocalSftyMgt_bInhCoPtSIPFRM;


   /* F03_02_01_SecurisationMiseEnPlaceFRM */

   VEMS_vidGET(SftyMgt_bSIPCoPt, bLocalSftyMgt_bSIPCoPt);
   VEMS_vidGET(SftyMgt_bDgoSIPORngCoPt, bLocalSftyMgt_bDgoSIPORngCoPt);
   VEMS_vidGET(SftyMgt_bInhCoPtSIPFRM, bLocalSftyMgt_bInhCoPtSIPFRM);

   if (  (bLocalSftyMgt_bDgoSIPORngCoPt != 0)
      || (bLocalSftyMgt_bInhCoPtSIPFRM != 0))
   {
      SftyMgt_bInhSIPCord_MP = 1;
   }
   else
   {
      SftyMgt_bInhSIPCord_MP = 0;
   }

   if (  (bLocalSftyMgt_bSIPCoPt != 0)
      && (SftyMgt_bInhSIPCord_MP != 0))
   {
      SftyMgt_bDftSIPFRM = 1;
   }
   else
   {
      SftyMgt_bDftSIPFRM = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidDetectionSIPInvalide                             */
/* !Description :  Ce Bloc teste la cohérence de la demande de SIP CMM boite  */
/*                 (SftyMgt_bSIPCoPt) avec le flux provenant du parametre     */
/*                 sécurisé (SftyMgt_bSIPGBx).                                */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_007.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bSIPCoPt;                                           */
/*  input boolean SftyMgt_bSIPTra;                                            */
/*  output boolean SftyMgt_bDftSIPInvld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidDetectionSIPInvalide(void)
{
   boolean bLocalSftyMgt_bSIPCoPt;
   boolean bLocalSftyMgt_bSIPTra;

   /* F03_02_02_detectionSIPInvalide */

   VEMS_vidGET(SftyMgt_bSIPCoPt, bLocalSftyMgt_bSIPCoPt);
   VEMS_vidGET(SftyMgt_bSIPTra, bLocalSftyMgt_bSIPTra);

   if (   (bLocalSftyMgt_bSIPTra == 0)
       && (bLocalSftyMgt_bSIPCoPt != 0))
   {
      SftyMgt_bDftSIPInvld = 1;
   }
   else
   {
      SftyMgt_bDftSIPInvld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidCalculSIPOutOfRange                              */
/* !Description :  Ce Bloc Vérifie que la demande de SIP CMM boite est        */
/*                 inférieure à un seuil.                                     */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_008.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidCompteurSIP();                                 */
/*  extf argret void SECUBV_vidComparaisonSeuilSIP();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidCalculSIPOutOfRange(void)
{
   /* F03_02_03_calculSIPOutOfRange */

   SECUBV_vidCompteurSIP();
   SECUBV_vidComparaisonSeuilSIP();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidCoordDebounceSIPErreur                           */
/* !Description :  Ce bloc effectue la synthèse des défauts CMM boite         */
/*                 génériques.                                                */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_015.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDgoSIPInvld_C;                                  */
/*  input boolean SftyMgt_bDftSIPInvld;                                       */
/*  input uint8 SftyMgt_tiDlyOnDgoTqGBx_C;                                    */
/*  input uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt;                               */
/*  input boolean SftyMgt_bInhDgoSIPORng_C;                                   */
/*  input boolean SftyMgt_bDftSIPORng;                                        */
/*  input uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1;                             */
/*  input boolean SftyMgt_bInhDgoSIPFRM_C;                                    */
/*  input boolean SftyMgt_bDftSIPFRM;                                         */
/*  input uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2;                             */
/*  output uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt;                              */
/*  output uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1;                            */
/*  output uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2;                            */
/*  output boolean SftyMgt_bDgoSIPCord;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidCoordDebounceSIPErreur(void)
{
   boolean bLocalSftyMgt_bDftSIPInvld;
   boolean bLocalDgoSIPInvld;
   boolean bLocalSftyMgt_bDftSIPORng;
   boolean bLocalDgoSIPORng;
   boolean bLocalSftyMgt_bDftSIPFRM;
   boolean bLocalDgoSIPFRM;
   uint16  u16LocalMinTurnOnDelaySimple;
   uint16  u16LocalSumTurnOnDelaySimple;


   /* F03_02_04_CoordinationDebounceSIPErreur */

   if (SftyMgt_bInhDgoSIPInvld_C != 0)
   {
      bLocalSftyMgt_bDftSIPInvld = 0;
   }
   else
   {
      bLocalSftyMgt_bDftSIPInvld = SftyMgt_bDftSIPInvld;
   }
   /* Turn_On_Delay_Simple */

   u16LocalSumTurnOnDelaySimple = (uint16)(SftyMgt_tiDlyOnDgoTqGBx_C + 1);

   if (bLocalSftyMgt_bDftSIPInvld == 0)
   {
      SECUBV_u16tiDlyOnDgoTqGBx_Cnt = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(SECUBV_u16tiDlyOnDgoTqGBx_Cnt,
                                u16LocalSumTurnOnDelaySimple);
      SECUBV_u16tiDlyOnDgoTqGBx_Cnt =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (SECUBV_u16tiDlyOnDgoTqGBx_Cnt >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalDgoSIPInvld = 1;
   }
   else
   {
      bLocalDgoSIPInvld = 0;
   }

   /* Turn_On_Delay_Simple1 */

   if (SftyMgt_bInhDgoSIPORng_C != 0)
   {
      bLocalSftyMgt_bDftSIPORng = 0;
   }
   else
   {
      bLocalSftyMgt_bDftSIPORng = SftyMgt_bDftSIPORng;
   }

   if (bLocalSftyMgt_bDftSIPORng == 0)
   {
      SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1 = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1,
                                u16LocalSumTurnOnDelaySimple);
      SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1 =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1 >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalDgoSIPORng = 1;
   }
   else
   {
      bLocalDgoSIPORng = 0;
   }

   /* Turn_On_Delay_Simple2 */

   if (SftyMgt_bInhDgoSIPFRM_C != 0)
   {
      bLocalSftyMgt_bDftSIPFRM = 0;
   }
   else
   {
      bLocalSftyMgt_bDftSIPFRM = SftyMgt_bDftSIPFRM;
   }

   if (bLocalSftyMgt_bDftSIPFRM == 0)
   {
      SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2 = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2,
                                u16LocalSumTurnOnDelaySimple);
      SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2 =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2 >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalDgoSIPFRM = 1;
   }
   else
   {
      bLocalDgoSIPFRM = 0;
   }

   if (  (bLocalDgoSIPInvld !=0)
      || (bLocalDgoSIPORng != 0)
      || (bLocalDgoSIPFRM != 0))
   {
      SftyMgt_bDgoSIPCord = 1;
   }
   else
   {
      SftyMgt_bDgoSIPCord = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidCompteurSIP                                      */
/* !Description :  Ce Bloc effectue le calcul du compteur de temps passé pour */
/*                 la variable SIP égale à 1                                  */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidIFTHENCompteurSIP();                           */
/*  extf argret void SECUBV_vidRAZCompteurSIP();                              */
/*  extf argret void SECUBV_vidIncrementeCompteurSIP();                       */
/*  input boolean SftyMgt_bEnaSIPCntRst;                                      */
/*  input boolean SftyMgt_bEnaSIPCntRun;                                      */
/*  input boolean SECUBV_bEnaSIPCntRun_Prev;                                  */
/*  output uint16 SftyMgt_tiSIPCntRun;                                        */
/*  output uint16 SftyMgt_tiSIPCnt;                                           */
/*  output boolean SECUBV_bEnaSIPCntRun_Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidCompteurSIP(void)
{
   /* F03_02_03_01_CompteurSIP */
   SECUBV_vidIFTHENCompteurSIP();
   if (SftyMgt_bEnaSIPCntRst != 0)
   {
      SECUBV_vidRAZCompteurSIP();
   }

   if (SftyMgt_bEnaSIPCntRun != 0)
   {
      if (SECUBV_bEnaSIPCntRun_Prev == 0)
      {
         SftyMgt_tiSIPCntRun = 0;
         SftyMgt_tiSIPCnt = 0;
      }
      else
      {
         SECUBV_vidIncrementeCompteurSIP();
      }
   }
   SECUBV_bEnaSIPCntRun_Prev = SftyMgt_bEnaSIPCntRun;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidComparaisonSeuilSIP                              */
/* !Description :  cette fonction precise que Lorsque le compteur dépasse un  */
/*                 seuil. Un défaut est remonté.                              */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_014.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_tiSIPCnt;                                            */
/*  input uint16 SftyMgt_tiMaxGearBxIntv_C;                                   */
/*  output boolean SftyMgt_bDftSIPORng;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidComparaisonSeuilSIP(void)
{
   /* F03_02_03_02_comparaisonSeuilSIP */

   if (SftyMgt_tiSIPCnt > SftyMgt_tiMaxGearBxIntv_C)
   {
      SftyMgt_bDftSIPORng = 1;
   }
   else
   {
      SftyMgt_bDftSIPORng = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidIFTHENCompteurSIP                                */
/* !Description :  la fonction permet de définir la mise en marche  et l'arret*/
/*                 du compteur                                                */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bSIPCoPt;                                           */
/*  input boolean SftyMgt_bNbTarGearChgSIP;                                   */
/*  input boolean SftyMgt_bNRegReqChgSIP;                                     */
/*  output boolean SftyMgt_bEnaSIPCntRst;                                     */
/*  output boolean SftyMgt_bEnaSIPCntRun;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidIFTHENCompteurSIP(void)
{
   boolean bLocalSftyMgt_bSIPCoPt;


   /* F03_02_03_01_01_IFTHENCompteurSIP */

   VEMS_vidGET(SftyMgt_bSIPCoPt,bLocalSftyMgt_bSIPCoPt);

   if (  (bLocalSftyMgt_bSIPCoPt == 0)
      || (SftyMgt_bNbTarGearChgSIP != 0)
      || (SftyMgt_bNRegReqChgSIP != 0))
   {
      SftyMgt_bEnaSIPCntRst = 1;
      SftyMgt_bEnaSIPCntRun = 0;
   }
   else
   {
      SftyMgt_bEnaSIPCntRst = 0;
      SftyMgt_bEnaSIPCntRun = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidRAZCompteurSIP                                   */
/* !Description :  cette fonction permet de remmetre a 0 le compteur          */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_011.01                                     */
/*                 VEMS_R_10_01251_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_tiSIPCntRst;                                         */
/*  output uint16 SftyMgt_tiSIPCntRst;                                        */
/*  output uint16 SftyMgt_tiSIPCnt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidRAZCompteurSIP(void)
{
   /* F03_02_03_01_02_RAZCompteurSIP */

   SftyMgt_tiSIPCntRst = 0;
   SftyMgt_tiSIPCnt = SftyMgt_tiSIPCntRst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidIncrementeCompteurSIP                            */
/* !Description :  ce bloc permet l'Incrémentation du compteur.               */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_012.01                                     */
/*                 VEMS_R_10_01251_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_tiSIPCntRun;                                         */
/*  output uint16 SftyMgt_tiSIPCntRun;                                        */
/*  output uint16 SftyMgt_tiSIPCnt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidIncrementeCompteurSIP(void)
{
   uint32 u32LocalSftyMgt_tiSIPCntRun;


   /* F03_02_03_01_03_IncrementeCompteurSIP */

   u32LocalSftyMgt_tiSIPCntRun = (uint32)(SftyMgt_tiSIPCntRun + 1);
   SftyMgt_tiSIPCntRun = (uint16)MATHSRV_udtMIN
                              (u32LocalSftyMgt_tiSIPCntRun, 1500);
   SftyMgt_tiSIPCnt = SftyMgt_tiSIPCntRun;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/