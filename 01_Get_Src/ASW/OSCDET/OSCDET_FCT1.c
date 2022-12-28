/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OSCDET                                                  */
/* !Description     : OSCDET Component                                        */
/*                                                                            */
/* !Module          : OSCDET                                                  */
/* !Description     : VERIFICATION DES CONDITIONS DE STABILITE DU POINT DE    */
/*                    FONCTIONNEMENT DU MOTEUR AU RALENTI                     */
/*                                                                            */
/* !File            : OSCDET_FCT1.C                                           */
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
/*   1 / OSCDET_vidOscCheckFctCallInit                                        */
/*   2 / OSCDET_vidOscChekStabAirLd                                           */
/*   3 / OSCDET_vidOscCheckStabIdlSpd                                         */
/*   4 / OSCDET_vidOscCheckStabilityInit                                      */
/*   5 / OSCDET_vidInitOutput                                                 */
/*   6 / OSCDET_vidOscChekStabilityPeriod                                     */
/*   7 / OSCDET_vidOscEngAirLoadStabCompt                                     */
/*   8 / OSCDET_vidOscEngAirLoadExtrCmpt                                      */
/*   9 / OSCDET_vidOscEngSpeedStabCmpt                                        */
/*   10 / OSCDET_vidOscEngSpeedExtrCmpt                                       */
/*                                                                            */
/* !Reference   : V02 NT 12 00679 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/OSCDET/OSCDET_FCT1.C_v            $*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   06 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   06 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OSCDET.h"
#include "OSCDET_l.h"
#include "OSCDET_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscCheckFctCallInit                              */
/* !Description :  Ce bloc est appellé lors de la perte des conditions de     */
/*                 détection de stabilité                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void OSCDET_vidOscCheckStabilityInit();                       */
/*  input boolean EngSt_bEngNOnIdl;                                           */
/*  input boolean EngSt_bAcvOscDetStab;                                       */
/*  output boolean EngSt_bAcvOscDetStab;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscCheckFctCallInit(void)
{
   boolean bLocalEngSt_bEngNOnIdl;
   boolean bLocalInhOscDetCdn;
   boolean bLocalEngStbAcvOscDetStab;


   VEMS_vidGET(EngSt_bEngNOnIdl, bLocalEngSt_bEngNOnIdl);
   bLocalInhOscDetCdn = GDGAR_bGetFRM(FRM_FRM_INHOSCDETCDN);
   bLocalEngStbAcvOscDetStab = EngSt_bAcvOscDetStab;

   if (  (bLocalEngSt_bEngNOnIdl != 0)
      && (bLocalInhOscDetCdn == 0))
   {
      EngSt_bAcvOscDetStab = 1;
   }
   else
   {
      EngSt_bAcvOscDetStab = 0;
   }

   if (  (bLocalEngStbAcvOscDetStab != 0)
      && (EngSt_bAcvOscDetStab == 0))
   {
      OSCDET_vidOscCheckStabilityInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscChekStabAirLd                                 */
/* !Description :  Ce bloc vérifie la stabilité de la charge d'air.           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OSCDET_vidOscEngAirLoadStabCompt();                      */
/*  extf argret void OSCDET_vidOscEngAirLoadExtrCmpt();                       */
/*  input boolean EngSt_bEnaOscDet;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscChekStabAirLd(void)
{
   if (EngSt_bEnaOscDet != 0)
   {
      OSCDET_vidOscEngAirLoadStabCompt();
   }
   else
   {
      OSCDET_vidOscEngAirLoadExtrCmpt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscCheckStabIdlSpd                               */
/* !Description :  Ce bloc vérifie l'indicateur de la stabilité du régime     */
/*                 moteur au ralenti.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OSCDET_vidOscEngSpeedStabCmpt();                         */
/*  extf argret void OSCDET_vidOscEngSpeedExtrCmpt();                         */
/*  input boolean EngSt_bEnaOscDet;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscCheckStabIdlSpd(void)
{
   if (EngSt_bEnaOscDet != 0)
   {
      OSCDET_vidOscEngSpeedStabCmpt();
   }
   else
   {
      OSCDET_vidOscEngSpeedExtrCmpt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscCheckStabilityInit                            */
/* !Description :  Bloc d'initialisation.                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean EngSt_bAcvOscDetStab;                                      */
/*  output boolean EngSt_bOscDetStab;                                         */
/*  output uint16 EngSt_rAirLdOscMin;                                         */
/*  output uint16 EngSt_rAirLdOscMax;                                         */
/*  output uint16 EngSt_nIdlSpdOscMin;                                        */
/*  output uint16 EngSt_nIdlSpdOscMax;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscCheckStabilityInit(void)
{
   EngSt_bAcvOscDetStab = 0;
   VEMS_vidSET(EngSt_bOscDetStab, 1);
   EngSt_rAirLdOscMin = 0;
   EngSt_rAirLdOscMax = 0;
   EngSt_nIdlSpdOscMin = 0;
   EngSt_nIdlSpdOscMax = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidInitOutput                                       */
/* !Description :  Fonction d'initialisation des variable internes.           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EngSt_bEnaOscDet;                                          */
/*  output boolean OSCDET_bTimerInit;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidInitOutput(void)
{
   EngSt_bEnaOscDet = 0;
   OSCDET_bTimerInit = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscChekStabilityPeriod                           */
/* !Description :  Ce bloc verifie la période de stabilité du point de        */
/*                 fonctionnement moteur.                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean OSCDET_bTimerInit;                                          */
/*  input uint16 EngSt_tiDlyOscDet;                                           */
/*  input uint16 EngSt_tiDlyOscDet_C;                                         */
/*  output boolean OSCDET_bTimerInit;                                         */
/*  output uint16 EngSt_tiDlyOscDet;                                          */
/*  output boolean EngSt_bEnaOscDet;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscChekStabilityPeriod(void)
{
   boolean bLocalTimerInitPrev;
   uint16  u16LocalTransitCount;


   bLocalTimerInitPrev = OSCDET_bTimerInit;
   if (EngSt_tiDlyOscDet == 0)
   {
      OSCDET_bTimerInit = 1;
   }
   else
   {
      OSCDET_bTimerInit = 0;
   }

   if (  (bLocalTimerInitPrev == 0)
      && (OSCDET_bTimerInit != 0))
   {
      EngSt_tiDlyOscDet = (uint16)MATHSRV_udtMIN(EngSt_tiDlyOscDet_C, 6000);
      if (EngSt_tiDlyOscDet == 0)
      {
         EngSt_bEnaOscDet = 1;
      }
      else
      {
         EngSt_bEnaOscDet = 0;
      }
   }
   else
   {
      if (EngSt_tiDlyOscDet > 0)
      {
         u16LocalTransitCount = (uint16)(EngSt_tiDlyOscDet - 1);
         EngSt_tiDlyOscDet = (uint16)MATHSRV_udtMIN(u16LocalTransitCount, 6000);

         if (EngSt_tiDlyOscDet == 0)
         {
            EngSt_bEnaOscDet = 1;
         }
         else
         {
            EngSt_bEnaOscDet = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscEngAirLoadStabCompt                           */
/* !Description :  Ce bloc calcule la stabilité de la charge d'air.           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngSt_rAirLdOscMax;                                          */
/*  input uint16 EngSt_rAirLdOscMin;                                          */
/*  input uint16 EngSt_rAirLdDeltaMaxThd_C;                                   */
/*  input uint16 Ext_rAirLd;                                                  */
/*  output boolean EngSt_bOscDetAirLdCor;                                     */
/*  output uint16 EngSt_rAirLdOscMin;                                         */
/*  output uint16 EngSt_rAirLdOscMax;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscEngAirLoadStabCompt(void)
{
   uint16 u16Local_Ext_rAirLd;
   sint32 s32LocalDelta;


   s32LocalDelta = EngSt_rAirLdOscMax - EngSt_rAirLdOscMin;

   if (s32LocalDelta < (sint32)EngSt_rAirLdDeltaMaxThd_C)
   {
      EngSt_bOscDetAirLdCor = 1;
   }
   else
   {
      EngSt_bOscDetAirLdCor = 0;
   }

   VEMS_vidGET(Ext_rAirLd, u16Local_Ext_rAirLd);
   EngSt_rAirLdOscMin = u16Local_Ext_rAirLd;
   EngSt_rAirLdOscMax = u16Local_Ext_rAirLd;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscEngAirLoadExtrCmpt                            */
/* !Description :  Ce bloc calcule les valeurs maximale et minimale de la     */
/*                 charge d'air.                                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 EngSt_rAirLdOscMin;                                          */
/*  input uint16 EngSt_rAirLdOscMax;                                          */
/*  output uint16 EngSt_rAirLdOscMin;                                         */
/*  output uint16 EngSt_rAirLdOscMax;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscEngAirLoadExtrCmpt(void)
{
   uint16 u16Local_Ext_rAirLd;


   VEMS_vidGET(Ext_rAirLd, u16Local_Ext_rAirLd);
   EngSt_rAirLdOscMin =
      (uint16)MATHSRV_udtMIN(EngSt_rAirLdOscMin, u16Local_Ext_rAirLd);
   EngSt_rAirLdOscMax =
      (uint16)MATHSRV_udtMAX(EngSt_rAirLdOscMax, u16Local_Ext_rAirLd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscEngSpeedStabCmpt                              */
/* !Description :  Ce bloc calcule l'indicateur de stabilité du régime moteur */
/*                 au ralenti.                                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EngSt_nIdlSpdOscMax;                                         */
/*  input uint16 EngSt_nIdlSpdOscMin;                                         */
/*  input uint16 EngSt_nIdlSpdDeltaMaxThd_C;                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  output boolean EngSt_bOscDetIdlSpd;                                       */
/*  output uint16 EngSt_nIdlSpdOscMin;                                        */
/*  output uint16 EngSt_nIdlSpdOscMax;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscEngSpeedStabCmpt(void)
{
   uint16 u16Local_Ext_nEng;
   sint32 s32LocalDelta;


   s32LocalDelta = EngSt_nIdlSpdOscMax - EngSt_nIdlSpdOscMin;

   if (s32LocalDelta < (sint32)EngSt_nIdlSpdDeltaMaxThd_C)
   {
      EngSt_bOscDetIdlSpd = 1;
   }
   else
   {
      EngSt_bOscDetIdlSpd = 0;
   }

   VEMS_vidGET(Ext_nEng, u16Local_Ext_nEng);
   EngSt_nIdlSpdOscMin = (uint16)MATHSRV_udtMIN(u16Local_Ext_nEng, 7500);
   EngSt_nIdlSpdOscMax = (uint16)MATHSRV_udtMIN(u16Local_Ext_nEng, 7500);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscEngSpeedExtrCmpt                              */
/* !Description :  Ce bloc calcule les valeurs maximale et minimale du régime */
/*                 moteur observées pendant une période.                      */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngSt_nIdlSpdOscMin;                                         */
/*  input uint16 EngSt_nIdlSpdOscMax;                                         */
/*  output uint16 EngSt_nIdlSpdOscMin;                                        */
/*  output uint16 EngSt_nIdlSpdOscMax;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscEngSpeedExtrCmpt(void)
{
   uint16 u16Local_Ext_nEng;
   uint16 u16Local_EngSt_nIdlSpdOscMin;
   uint16 u16Local_EngSt_nIdlSpdOscMax;


   VEMS_vidGET(Ext_nEng, u16Local_Ext_nEng);

   u16Local_EngSt_nIdlSpdOscMin =
      (uint16)MATHSRV_udtMIN(EngSt_nIdlSpdOscMin, u16Local_Ext_nEng);

   EngSt_nIdlSpdOscMin =
      (uint16)MATHSRV_udtMIN(u16Local_EngSt_nIdlSpdOscMin, 7500);

   u16Local_EngSt_nIdlSpdOscMax =
      (uint16)MATHSRV_udtMAX(EngSt_nIdlSpdOscMax, u16Local_Ext_nEng);

   EngSt_nIdlSpdOscMax =
      (uint16)MATHSRV_udtMIN(u16Local_EngSt_nIdlSpdOscMax, 7500);
}
/************************************* end of file ****************************/