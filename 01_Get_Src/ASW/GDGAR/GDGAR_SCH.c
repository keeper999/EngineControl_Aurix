/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : GDGAR Component                                         */
/*                                                                            */
/* !Module          : GDGAR                                                   */
/* !Description     : GESTIONNAIRE DE DEFAUT                                  */
/*                                                                            */
/* !File            : GDGAR_SCH.C                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / GDGAR_EveRst                                                         */
/*   2 / GDGAR_SdlSlow                                                        */
/*   3 / GDGAR_SdlMid                                                         */
/*   4 / GDGAR_SdlFast                                                        */
/*   5 / GDGAR_EveKeyOn                                                       */
/*   6 / GDGAR_EveKeyOff                                                      */
/*   7 / GDGAR_EveCrkRun                                                      */
/*   8 / GDGAR_EveCrTst                                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5012623 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#048854                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GDGAR/GDGAR_SCH.c_v             $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   16 Jan 2013 $*/
/* $Author::   mbenfrad                               $$Date::   16 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDGAR.h"
#include "GDGAR_L.h"
#include "GDGAR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EveRst                                               */
/* !Description :  Evenement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRst();                                             */
/*  extf argret void Fim_Init();                                              */
/*  extf argret void GD_EveRst_HrdRcvMng();                                   */
/*  output boolean GDGAR_bInitInProgress;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_EveRst                                                   */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EveRst(void)
{
   GDGAR_bInitInProgress = TRUE;
   GD_EveRst();
   Fim_Init();
   GD_EveRst_HrdRcvMng();
   GDGAR_bInitInProgress = FALSE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_SdlSlow                                              */
/* !Description :  Moniteur 1024ms                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DGOTEST_vidSdlSlow();                                    */
/*  extf argret void GD_SdlSlow();                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_SdlSlow                                                  */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_SdlSlow(void)
{
   DGOTEST_vidSdlSlow();
   GD_SdlSlow();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_SdlMid                                               */
/* !Description :  Moniteur 40ms                                              */
/* !Number      :  SCH.3                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_SdlMid_HrdRcvMng();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_SdlMid                                                   */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_SdlMid(void)
{
   GD_SdlMid_HrdRcvMng();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_SdlFast                                              */
/* !Description :  Moniteur 10ms                                              */
/* !Number      :  SCH.4                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_SdlFast();                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_SdlFast                                                  */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_SdlFast(void)
{
   GD_SdlFast();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EveKeyOn                                             */
/* !Description :  Event Key On                                               */
/* !Number      :  SCH.5                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveKOn();                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_EveKeyOn                                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EveKeyOn(void)
{
   GD_EveKOn();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EveKeyOff                                            */
/* !Description :  Event Key Off                                              */
/* !Number      :  SCH.6                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveKOf();                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_EveKeyOff                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EveKeyOff(void)
{
   GD_EveKOf();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EveCrkRun                                            */
/* !Description :  Event CRANKING to RUN                                      */
/* !Number      :  SCH.7                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveCrTR();                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_EveCrkRun                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EveCrkRun(void)
{
   GD_EveCrTR();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EveCrTst                                             */
/* !Description :  Event CRANKING to STALL                                    */
/* !Number      :  SCH.8                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveCrTSt();                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDGAR_EveCrTst                                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EveCrTst(void)
{
   GD_EveCrTSt();
}
/*--------------------------------- end of file ------------------------------*/