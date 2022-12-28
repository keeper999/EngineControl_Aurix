/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAUTHDFTSTT                                            */
/* !Description     : IFAUTHDFTSTT Component                                  */
/*                                                                            */
/* !Module          : IFAUTHDFTSTT                                            */
/* !Description     : SAFETY TMS: INTERFACE AUTORISATION DEFAUT STT           */
/*                                                                            */
/* !File            : IFAUTHDFTSTT_FCT1.C                                     */
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
/*   1 / IFAUTHDFTSTT_vidInitOutput                                           */
/*   2 / IFAUTHDFTSTT_vidIrfAutrstDftSTT                                      */
/*   3 / IFAUTHDFTSTT_vidSTTConfig                                            */
/*   4 / IFAUTHDFTSTT_vidSansSTTCfg                                           */
/*   5 / IFAUTHDFTSTT_vidSTTPrstCfg                                           */
/*                                                                            */
/* !Reference   : V02 NT 11 01213 / 02                                        */
/* !OtherRefs   : 01460_09_01031 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFAUTHDFTSTT/IFAUTHDFT$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "IFAUTHDFTSTT.h"
#include "IFAUTHDFTSTT_L.h"
#include "IFAUTHDFTSTT_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAUTHDFTSTT_vidInitOutput                                 */
/* !Description :  Initialisation des output                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bInhSTTCord;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAUTHDFTSTT_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bInhSTTCord , 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAUTHDFTSTT_vidIrfAutrstDftSTT                            */
/* !Description :  Cette fonction permet de sécuriser les demandes Démarrage  */
/*                 redémarrage STTd.                                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_01213_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAUTHDFTSTT_vidSTTConfig();                             */
/*  extf argret void IFAUTHDFTSTT_vidSansSTTCfg();                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void IFAUTHDFTSTT_vidSTTPrstCfg();                            */
/*  input boolean SftyMgt_bEnaNotSTTCf;                                       */
/*  input boolean SftyMgt_bInhSTTCordNotSTTCf;                                */
/*  input boolean SftyMgt_bEnaSTTCf;                                          */
/*  input boolean SftyMgt_bInhSTTCordSTTCf;                                   */
/*  output boolean SftyMgt_bInhSTTCord;                                       */
/*  output boolean SftyMgt_bInhSTTCordNotSTTCf;                               */
/*  output boolean SftyMgt_bInhSTTCordSTTCf;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAUTHDFTSTT_vidIrfAutrstDftSTT(void)
{
   IFAUTHDFTSTT_vidSTTConfig();
   if (SftyMgt_bEnaNotSTTCf != 0)
   {
      IFAUTHDFTSTT_vidSansSTTCfg();
      VEMS_vidSET(SftyMgt_bInhSTTCord, SftyMgt_bInhSTTCordNotSTTCf);
   }
   if (SftyMgt_bEnaSTTCf != 0)
   {
      IFAUTHDFTSTT_vidSTTPrstCfg();
      VEMS_vidSET(SftyMgt_bInhSTTCord, SftyMgt_bInhSTTCordSTTCf);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAUTHDFTSTT_vidSTTConfig                                  */
/* !Description :  Test de la configuration définissant le code à compiler    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_01213_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bSTTCf;                                             */
/*  output boolean SftyMgt_bEnaSTTCf;                                         */
/*  output boolean SftyMgt_bEnaNotSTTCf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAUTHDFTSTT_vidSTTConfig(void)
{
   boolean bLocalSftyMgt_bSTTCf;


   VEMS_vidGET(SftyMgt_bSTTCf, bLocalSftyMgt_bSTTCf);
   if (bLocalSftyMgt_bSTTCf != 0)
   {
      SftyMgt_bEnaSTTCf = 1;
      SftyMgt_bEnaNotSTTCf = 0;
   }
   else
   {
      SftyMgt_bEnaSTTCf = 0;
      SftyMgt_bEnaNotSTTCf = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAUTHDFTSTT_vidSansSTTCfg                                 */
/* !Description :  Cette fonction permet de bypasser la sécurisation dans le  */
/*                 cas de la non présence d’un STT.                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_01213_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SftyMgt_bInhSTTCordNotSTTCf;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAUTHDFTSTT_vidSansSTTCfg(void)
{
   SftyMgt_bInhSTTCordNotSTTCf = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAUTHDFTSTT_vidSTTPrstCfg                                 */
/* !Description :  Cette fonction Coordonne le flux d’inhibition de Démarrage */
/*                 / redémarrage du niveau 1 avec les défauts détectés par le */
/*                 niveau 2 et vient contrôler le démarreur.                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_01213_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bInhSTT;                                            */
/*  input boolean SftyMgt_bInhCoStrtRStrt;                                    */
/*  output boolean SftyMgt_bInhSTTCordSTTCf;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAUTHDFTSTT_vidSTTPrstCfg(void)
{
   boolean bLocalSftyMgtSTT;
   boolean bLocalSftyMgtInhCoStrtRStrt;


   VEMS_vidGET(SftyMgt_bInhSTT, bLocalSftyMgtSTT);
   VEMS_vidGET(SftyMgt_bInhCoStrtRStrt, bLocalSftyMgtInhCoStrtRStrt);
   if (  (bLocalSftyMgtSTT != 0)
      || (bLocalSftyMgtInhCoStrtRStrt != 0))
   {
      SftyMgt_bInhSTTCordSTTCf = 1;
   }
   else
   {
      SftyMgt_bInhSTTCordSTTCf = 0;
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------ end of file ---------------------------------*/