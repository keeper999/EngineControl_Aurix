/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COPTST                                                  */
/* !Description     : COPTST Component.                                       */
/*                                                                            */
/* !Module          : COPTST                                                  */
/* !Description     : Définition des variables STT                            */
/*                                                                            */
/* !File            : COPTST_FCT1.C                                           */
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
/*   1 / COPTST_vidInitOutput                                                 */
/*   2 / COPTST_vidDefinitionVariables                                        */
/*   3 / COPTST_vidBoolEtatRedemarrageSTT                                     */
/*   4 / COPTST_vidTempEauRedemarrageSTT                                      */
/*   5 / COPTST_vidCalcTempEauRedemarrage                                     */
/*   6 / COPTST_vidTempEauDemarrage                                           */
/*   7 / COPTST_vidCalcTempEauDemarrage                                       */
/*                                                                            */
/* !Reference   : V02 NT 09 05959 / 04                                        */
/* !OtherRefs   : CSMT_CGMT08_3115 / 1.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COPTST/COPTST_FCT1.C_v$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "COPTST.h"
#include "COPTST_L.h"
#include "COPTST_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidInitOutput                                       */
/* !Description :  initialisation des sorties du module                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean CoPTSt_bRStrtSTT;                                          */
/*  output uint8 CoPTSt_tCoMesRStrtSTT;                                       */
/*  output sint16 CoPTSt_tCoMesStrt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidInitOutput(void)
{
   VEMS_vidSET(CoPTSt_bRStrtSTT, 0);
   VEMS_vidSET(CoPTSt_tCoMesRStrtSTT, 40);
   VEMS_vidSET(CoPTSt_tCoMesStrt, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidDefinitionVariables                              */
/* !Description :  Cette fonction détermine les variables spécifiques au      */
/*                 redémarrage Stop&Start : le booléen d’état de redémarrage  */
/*                 STT et la température d’eau moteur lors des redémarrages   */
/*                 STT                                                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COPTST_vidBoolEtatRedemarrageSTT();                      */
/*  extf argret void COPTST_vidTempEauRedemarrageSTT();                       */
/*  extf argret void COPTST_vidTempEauDemarrage();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidDefinitionVariables(void)
{
   COPTST_vidBoolEtatRedemarrageSTT();
   COPTST_vidTempEauRedemarrageSTT();
   COPTST_vidTempEauDemarrage();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidBoolEtatRedemarrageSTT                           */
/* !Description :  Ce booléen détermine l’état du redémarrage STT. Il doit    */
/*                 être stocké en mémoire protégée.                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  output boolean CoPTSt_bRStrtSTT;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidBoolEtatRedemarrageSTT(void)
{
   uint8 u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if ( u8LocalCoPTSt_stEng == 1)
   {
      VEMS_vidSET(CoPTSt_bRStrtSTT, 0);
   }
   else
   {
      if ( u8LocalCoPTSt_stEng == 6)
      {
         VEMS_vidSET(CoPTSt_bRStrtSTT, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidTempEauRedemarrageSTT                            */
/* !Description :  On  actualise  la  mémorisation  de  la  température  d’eau*/
/*                  moteur  au  redémarrage  Stop&Start  lors  des phases de  */
/*                 redémarrages STT.                                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COPTST_vidCalcTempEauRedemarrage();                      */
/*  input uint8 CoPTSt_stEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidTempEauRedemarrageSTT(void)
{
   uint8 u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   if (u8LocalCoPTSt_stEng == 7)
   {
      COPTST_vidCalcTempEauRedemarrage();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidCalcTempEauRedemarrage                           */
/* !Description :  On  stocke  la  valeur  de  température  d’eau  courante   */
/*                 dans  la  variable  de  température  d’eau  au redémarrage */
/*                 STT.                                                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  output uint8 CoPTSt_tCoMesRStrtSTT;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidCalcTempEauRedemarrage(void)
{
   uint8  u8LocalCoPTSt_tCoMesRStrtSTT;
   sint16 s16LocalExt_tCoMes;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   s16LocalExt_tCoMes = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes, -40, 214);
   u8LocalCoPTSt_tCoMesRStrtSTT = (uint8)(s16LocalExt_tCoMes + 40);
   VEMS_vidSET(CoPTSt_tCoMesRStrtSTT, u8LocalCoPTSt_tCoMesRStrtSTT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidTempEauDemarrage                                 */
/* !Description :  On actualise la mémorisation de la température d’eau moteur*/
/*                 au démarrage lors des phases de démarrages ou redémarrage  */
/*                 uniquement.                                                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COPTST_vidCalcTempEauDemarrage();                        */
/*  input uint8 CoPTSt_stEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidTempEauDemarrage(void)
{
   uint8 u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (u8LocalCoPTSt_stEng == 3)
   {
      COPTST_vidCalcTempEauDemarrage();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COPTST_vidCalcTempEauDemarrage                             */
/* !Description :  On stocke la valeur de température d’eau courante dans la  */
/*                 variable de température d’eau au démarrage ou redémarrage. */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_05959_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  output sint16 CoPTSt_tCoMesStrt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COPTST_vidCalcTempEauDemarrage(void)
{
   sint16 s16LocalExt_tCoMes;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   s16LocalExt_tCoMes = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes, -40, 214);
   VEMS_vidSET(CoPTSt_tCoMesStrt, s16LocalExt_tCoMes);
}
/*------------------------------- end of file --------------------------------*/