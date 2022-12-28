/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_SCH1.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidEntryInit                                           */
/*   2 / AirPres_EveRst_AirExtPresAcqIf                                       */
/*   3 / AirT_EveRst_AcqAirTIf                                                */
/*   4 / CatMon_EveRst_CatAcvDiagIf                                           */
/*   5 / EcuSt_EveRst_EcuMngIf                                                */
/*   6 / Can_EveRst_FHCanF50EIf2                                              */
/*   7 / RE_EngM_initIf                                                       */
/*   8 / Cf_EveRst_FlowMngIf                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidEntryInit                                 */
/* !Description :  Evénement reset ECU du module d'interface                  */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IFAIRSYSIGSYS_vidEntryInit                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidEntryInit(void)
{
   IFAIRSYSIGSYS_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_AirExtPresAcqIf                             */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutAtmphPress();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_AirExtPresAcqIf                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_AirExtPresAcqIf(void)
{
   IFAIRSYSIGSYS_vidOutAtmphPress();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_EveRst_AcqAirTIf                                      */
/* !Description :  Evénement reset ECU du module d'interface                  */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidTDsThr();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_EveRst_AcqAirTIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_EveRst_AcqAirTIf(void)
{
   IFAIRSYSIGSYS_vidTDsThr();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CatMon_EveRst_CatAcvDiagIf                                 */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_OxC();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CatMon_EveRst_CatAcvDiagIf                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CatMon_EveRst_CatAcvDiagIf(void)
{
   IFAIRSYSIGSYS_vidOutput_OxC();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveRst_EcuMngIf                                      */
/* !Description :  Evénement reset ECU du module d'interface                  */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidECU();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveRst_EcuMngIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveRst_EcuMngIf(void)
{
   IFAIRSYSIGSYS_vidECU();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF50EIf2                                    */
/* !Description :  Evènement reset de l'ECU                                   */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidIntfacIsCanIf16();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF50EIf2                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF50EIf2(void)
{
   IFAIRSYSIGSYS_vidIntfacIsCanIf16();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_EngM_initIf                                             */
/* !Description :  Evénement reset ECU du module d'interface                  */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutputLoad();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_EngM_initIf                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_EngM_initIf(void)
{
   IFAIRSYSIGSYS_vidOutputLoad();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngIf                                        */
/* !Description :  Evénement reset du calculateur .                           */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutBrakePedInp();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngIf(void)
{
   IFAIRSYSIGSYS_vidOutBrakePedInp();
}

/*-------------------------------- end of file -------------------------------*/