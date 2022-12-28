/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGAIREXTPRES                                          */
/* !Description     : DIAGAIREXTPRES component.                               */
/*                                                                            */
/* !Module          : DIAGAIREXTPRES                                          */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA PRESSION DE ATMOSPHERIQUE  */
/*                                                                            */
/* !File            : DIAGAIREXTPRES_FCT1.C                                   */
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
/*   1 / DIAGAIREXTPRES_vidInitOutput                                         */
/*   2 / DIAGAIREXTPRES_vidDiaAirExtPrsIn                                     */
/*   3 / DIAGAIREXTPRES_vidMemAirExtPres                                      */
/*   4 / DIAGAIREXTPRES_vidDiagAirExtPres                                     */
/*   5 / DIAGAIREXTPRES_vidCdnCohAirPres                                      */
/*   6 / DIAGAIREXTPRES_vidCohAirExtPres                                      */
/*   7 / DIAGAIREXTPRES_vidCdnChgAirPres                                      */
/*   8 / DIAGAIREXTPRES_vidClcGrdAirPres                                      */
/*   9 / DIAGAIREXTPRES_vidChgCohAirPres                                      */
/*   10 / DIAGAIREXTPRES_vidCdnAirPresOld                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 03594 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRPRES/DIAGAIREXTPRES/DIAGAIREX$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   19 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "DIAGAIREXTPRES.h"
#include "DIAGAIREXTPRES_L.h"
#include "DIAGAIREXTPRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidInitOutput                               */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean AirPres_bPresAirExtKOnMem;                                 */
/*  output uint16 DIAGAIREXTPRES_u16OutPutSwitch2;                            */
/*  output boolean DIAGAIREXTPRES_bExtKOnMemPrev;                             */
/*  output uint16 AirPres_ctTiDlyGrd_pAirExt;                                 */
/*  output boolean DIAGAIREXTPRES_bTimeout;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidInitOutput(void)
{
   AirPres_bPresAirExtKOnMem = 0;
   DIAGAIREXTPRES_u16OutPutSwitch2 = 0;
   DIAGAIREXTPRES_bExtKOnMemPrev = 0;
   AirPres_ctTiDlyGrd_pAirExt = 0;
   DIAGAIREXTPRES_bTimeout = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidDiaAirExtPrsIn                           */
/* !Description :  Cette fonction gère l’initialisation des variables au reset*/
/*                 de l’ECU                                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 UsThrM_pAirExtEstimRefOld;                                   */
/*  output boolean AirPres_bMonRunMax_pAirExt;                                */
/*  output boolean AirPres_bDgoMax_pAirExt;                                   */
/*  output boolean AirPres_bMonRunMin_pAirExt;                                */
/*  output boolean AirPres_bDgoMin_pAirExt;                                   */
/*  output boolean AirPres_bMonRunGrd_pAirExt;                                */
/*  output boolean AirPres_bDgoGrd_pAirExt;                                   */
/*  output boolean AirPres_bMonRunGrd_pAirExtOld;                             */
/*  output boolean AirPres_bDgoGrd_pAirExtOld;                                */
/*  output uint16 AirPres_pAirExtStrtPresSens;                                */
/*  output uint16 AirPres_pAirExtRefOld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidDiaAirExtPrsIn(void)
{
   uint32 u32LocalAirPres_pAirExtRefOld;


   AirPres_bMonRunMax_pAirExt = 0;
   AirPres_bDgoMax_pAirExt = 0;
   AirPres_bMonRunMin_pAirExt = 0;
   AirPres_bDgoMin_pAirExt = 0;
   AirPres_bMonRunGrd_pAirExt = 0;
   AirPres_bDgoGrd_pAirExt = 0;
   AirPres_bMonRunGrd_pAirExtOld = 0;
   AirPres_bDgoGrd_pAirExtOld = 0;
   AirPres_pAirExtStrtPresSens = 500;
   u32LocalAirPres_pAirExtRefOld = (uint32)( ( UsThrM_pAirExtEstimRefOld * 2)
                                           / 25);
   AirPres_pAirExtRefOld =
      (uint16)MATHSRV_udtCLAMP(u32LocalAirPres_pAirExtRefOld, 500, 1500);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidMemAirExtPres                            */
/* !Description :  Cette fonction gère la mémorisation  de la pression        */
/*                 atmosphérique au Key-On, sous condition de présence du     */
/*                 capteur.                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  output uint16 AirPres_pAirExtStrtPresSens;                                */
/*  output boolean AirPres_bPresAirExtKOnMem;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidMemAirExtPres(void)
{
   uint16 u16LocalExt_pAirExtMes;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   AirPres_pAirExtStrtPresSens =
      (uint16)MATHSRV_udtCLAMP(u16LocalExt_pAirExtMes, 500, 1500);
   AirPres_bPresAirExtKOnMem = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidDiagAirExtPres                           */
/* !Description :  Cette fonction gère  l'appel des macros diagnostic         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGAIREXTPRES_vidCdnCohAirPres();                       */
/*  extf argret void DIAGAIREXTPRES_vidCohAirExtPres();                       */
/*  extf argret void DIAGAIREXTPRES_vidCdnChgAirPres();                       */
/*  extf argret void DIAGAIREXTPRES_vidClcGrdAirPres();                       */
/*  extf argret void DIAGAIREXTPRES_vidChgCohAirPres();                       */
/*  extf argret void DIAGAIREXTPRES_vidCdnAirPresOld();                       */
/*  extf argret void DIAGAIREXTPRES_vidCohAirPresOld();                       */
/*  input boolean AirPres_bMonRunMax_pAirExt;                                 */
/*  input boolean AirPres_bMonRunMin_pAirExt;                                 */
/*  input boolean AirPres_bMonRunGrd_pAirExt;                                 */
/*  input boolean AirPres_bMonRunGrd_pAirExtOld;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidDiagAirExtPres(void)
{
   DIAGAIREXTPRES_vidCdnCohAirPres();
   if (  (AirPres_bMonRunMax_pAirExt != 0)
      && (AirPres_bMonRunMin_pAirExt != 0))
   {
      DIAGAIREXTPRES_vidCohAirExtPres();
   }
   DIAGAIREXTPRES_vidCdnChgAirPres();
   DIAGAIREXTPRES_vidClcGrdAirPres();
   if (AirPres_bMonRunGrd_pAirExt != 0)
   {
      DIAGAIREXTPRES_vidChgCohAirPres();
   }
   DIAGAIREXTPRES_vidCdnAirPresOld();
   if (AirPres_bMonRunGrd_pAirExtOld != 0)
   {
      DIAGAIREXTPRES_vidCohAirPresOld();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidCdnCohAirPres                            */
/* !Description :  Cette fonction spécifie les conditions d’activation du     */
/*                 diagnostic de détection d'une pression atmosphérique       */
/*                 incohérente                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  output boolean AirPres_bMonRunMax_pAirExt;                                */
/*  output boolean AirPres_bMonRunMin_pAirExt;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidCdnCohAirPres(void)
{
   boolean bLocalInhDiagCohAirExtPres;


   bLocalInhDiagCohAirExtPres = GDGAR_bGetFRM(FRM_FRM_INHDIAGCOHAIREXTPRES);
   if (bLocalInhDiagCohAirExtPres != 0)
   {
      AirPres_bMonRunMax_pAirExt = 0;
      AirPres_bMonRunMin_pAirExt = 0;
   }
   else
   {
      AirPres_bMonRunMax_pAirExt = 1;
      AirPres_bMonRunMin_pAirExt = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidCohAirExtPres                            */
/* !Description :  Cette fonction permet la détection d'une pression          */
/*                 atmosphérique incohérente                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 AirPres_pAirExtThdMax_C;                                     */
/*  input uint8 AirPres_pAirExtThdMin_C;                                      */
/*  output boolean AirPres_bDgoMax_pAirExt;                                   */
/*  output boolean AirPres_bDgoMin_pAirExt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidCohAirExtPres(void)
{
   uint16 u16LocalAirPresThdMin;
   uint16 u16LocalExt_pAirExtMes;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   if (u16LocalExt_pAirExtMes > AirPres_pAirExtThdMax_C)
   {
      AirPres_bDgoMax_pAirExt = 1;
   }
   else
   {
      AirPres_bDgoMax_pAirExt = 0;
   }

   u16LocalAirPresThdMin = (uint16)(AirPres_pAirExtThdMin_C * 10);
   if (u16LocalExt_pAirExtMes < u16LocalAirPresThdMin)
   {
      AirPres_bDgoMin_pAirExt = 1;
   }
   else
   {
      AirPres_bDgoMin_pAirExt = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidCdnChgAirPres                            */
/* !Description :  Conditions d’activation du diagnostic de détection de la   */
/*                 variation de la pression  atmosphérique incohérente        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Moteur_tournant;                                            */
/*  output boolean AirPres_bMonRunGrd_pAirExt;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidCdnChgAirPres(void)
{
   boolean bLocalInhDiagChgCohAirExtPres;
   boolean bLocalMoteur_tournant;


   bLocalInhDiagChgCohAirExtPres =
      GDGAR_bGetFRM(FRM_FRM_INHDIAGCHGCOHAIREXTPRES);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);

   if (  (bLocalInhDiagChgCohAirExtPres == 0)
      && (bLocalMoteur_tournant != 0))
   {
      AirPres_bMonRunGrd_pAirExt = 1;
   }
   else
   {
      AirPres_bMonRunGrd_pAirExt = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidClcGrdAirPres                            */
/* !Description :  Détection de la variation de la pression atmosphérique     */
/*                 incohérente                                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean DIAGAIREXTPRES_bTimeout;                                    */
/*  input boolean DIAGAIREXTPRES_bExtKOnMemPrev;                              */
/*  input boolean AirPres_bPresAirExtKOnMem;                                  */
/*  input uint16 AirPres_tiDlyGrd_pAirExt_C;                                  */
/*  input uint16 AirPres_ctTiDlyGrd_pAirExt;                                  */
/*  output uint16 AirPres_ctTiDlyGrd_pAirExt;                                 */
/*  output boolean DIAGAIREXTPRES_bTimeout;                                   */
/*  output boolean AirPres_bEnaClcGrdExtAirPres;                              */
/*  output boolean DIAGAIREXTPRES_bExtKOnMemPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidClcGrdAirPres(void)
{
   boolean bLocalTimeout;
   uint16  u16LocalCtTiDlyGrd_pAirExt;


   bLocalTimeout = DIAGAIREXTPRES_bTimeout;
   if (  (DIAGAIREXTPRES_bExtKOnMemPrev == 0)
      && (AirPres_bPresAirExtKOnMem != 0))
   {
      AirPres_ctTiDlyGrd_pAirExt =
         (uint16)MATHSRV_udtMIN(AirPres_tiDlyGrd_pAirExt_C, 7650);
      if (AirPres_ctTiDlyGrd_pAirExt == 0)
      {
         DIAGAIREXTPRES_bTimeout = 1;
      }
      else
      {
         DIAGAIREXTPRES_bTimeout = 0;
      }
   }
   else
   {
      if (AirPres_ctTiDlyGrd_pAirExt > 0)
      {
         u16LocalCtTiDlyGrd_pAirExt = (uint16)(AirPres_ctTiDlyGrd_pAirExt - 1);
         AirPres_ctTiDlyGrd_pAirExt =
            (uint16)MATHSRV_udtMIN(u16LocalCtTiDlyGrd_pAirExt, 7650);
         if (AirPres_ctTiDlyGrd_pAirExt == 0)
         {
            DIAGAIREXTPRES_bTimeout = 1;
         }
         else
         {
            DIAGAIREXTPRES_bTimeout = 0;
         }
      }
   }

   if (  (bLocalTimeout == 0)
      && (DIAGAIREXTPRES_bTimeout != 0)
      && (AirPres_bPresAirExtKOnMem != 0))
   {
      AirPres_bEnaClcGrdExtAirPres = 1;
   }
   else
   {
      AirPres_bEnaClcGrdExtAirPres = 0;
   }

   DIAGAIREXTPRES_bExtKOnMemPrev = AirPres_bPresAirExtKOnMem;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidChgCohAirPres                            */
/* !Description :  Détection de la variation de la pression atmosphérique     */
/*                 incohérente                                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AirPres_bEnaClcGrdExtAirPres;                               */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 AirPres_pAirExtStrtPresSens;                                 */
/*  input boolean AirPres_bPresAirExtKOnMem;                                  */
/*  input uint16 DIAGAIREXTPRES_u16OutPutSwitch2;                             */
/*  input uint16 AirPres_pAirExtThdGrdMax_C;                                  */
/*  output uint16 DIAGAIREXTPRES_u16OutPutSwitch2;                            */
/*  output boolean AirPres_bDgoGrd_pAirExt;                                   */
/*  output uint16 AirPres_pAirExtGrd;                                         */
/*  output uint16 AirPres_pAirExtMemDly;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidChgCohAirPres(void)
{
   uint16 u16LocalOutPutSwitch1;
   uint16 u16LocalOutPutSwitch;
   uint16 u16LocalExt_pAirExtMes;
   sint32 s32LocalOutPutSwitch;


   if (AirPres_bEnaClcGrdExtAirPres != 0)
   {
      VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
      u16LocalOutPutSwitch1 = AirPres_pAirExtStrtPresSens;
      DIAGAIREXTPRES_u16OutPutSwitch2 = u16LocalExt_pAirExtMes;
   }
   else
   {
      if (AirPres_bPresAirExtKOnMem == 0)
      {
         DIAGAIREXTPRES_u16OutPutSwitch2 = 0;
      }
      u16LocalOutPutSwitch1 = 0;
   }
   s32LocalOutPutSwitch = (sint32)( u16LocalOutPutSwitch1
                                  - DIAGAIREXTPRES_u16OutPutSwitch2);
   u16LocalOutPutSwitch = (uint16)MATHSRV_udtABS(s32LocalOutPutSwitch);
   if (u16LocalOutPutSwitch > AirPres_pAirExtThdGrdMax_C)
   {
      AirPres_bDgoGrd_pAirExt = 1;
   }
   else
   {
      AirPres_bDgoGrd_pAirExt = 0;
   }

   AirPres_pAirExtGrd = (uint16)MATHSRV_udtMIN(u16LocalOutPutSwitch, 1000);
   AirPres_pAirExtMemDly =
      (uint16)MATHSRV_udtCLAMP(DIAGAIREXTPRES_u16OutPutSwitch2, 500, 1500);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidCdnAirPresOld                            */
/* !Description :  Conditions d’activation du diagnostic de détection d'une   */
/*                 pression  atmosphérique incohérente par rapport au roulage */
/*                 précédent                                                  */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Moteur_tournant;                                            */
/*  output boolean AirPres_bMonRunGrd_pAirExtOld;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidCdnAirPresOld(void)
{
   boolean bLocalInhCohAirExtPresOld;
   boolean bLocalMoteur_tournant;


   bLocalInhCohAirExtPresOld = GDGAR_bGetFRM(FRM_FRM_INHCOHAIREXTPRESOLD);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);

   if (  (bLocalInhCohAirExtPresOld == 0)
      && (bLocalMoteur_tournant != 0))
   {
      AirPres_bMonRunGrd_pAirExtOld = 1;
   }
   else
   {
      AirPres_bMonRunGrd_pAirExtOld = 0;
   }
}
/*---------------------------- end of file -----------------------------------*/