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
/* !File            : IFAIRSYSIGSYS_SCH4.C                                    */
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
/*   1 / Eng_EveIni_tOilEstimIf                                               */
/*   2 / Inj_EveRst_InjTiCorIf                                                */
/*   3 / InjrM_EveRst_InjrMdlIf                                               */
/*   4 / Can_EveRxn34D_FHCanF34DIf2                                           */
/*   5 / Pwr_EveRst_BattVoltAcqIf                                             */
/*   6 / RE_AdvMaxT_001_MSEIf                                                 */
/*   7 / RE_AirSysAir_001_MSEIf                                               */
/*   8 / Sync_EveRst_CkMngIfIf                                                */
/*   9 / Sync_EveRst_FuSysCkMngIf                                             */
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
/* !Function    :  Eng_EveIni_tOilEstimIf                                     */
/* !Description :  Evenement reset du calculateur.                            */
/* !Number      :  SCH4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_tOilMes();                       */
/*  extf argret void IFAIRSYSIGSYS_vidInit_tOil();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Eng_EveIni_tOilEstimIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Eng_EveIni_tOilEstimIf(void)
{
   IFAIRSYSIGSYS_vidOutput_tOilMes();
   IFAIRSYSIGSYS_vidInit_tOil();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveRst_InjTiCorIf                                      */
/* !Description :  Evenement reset du calculateur.                            */
/* !Number      :  SCH4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidDiag_Trim();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveRst_InjTiCorIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveRst_InjTiCorIf(void)
{
   IFAIRSYSIGSYS_vidDiag_Trim();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjrM_EveRst_InjrMdlIf                                     */
/* !Description :  Evènement Reset pour InjrMdlFct.                           */
/* !Number      :  SCH4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInjrMSys1();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjrM_EveRst_InjrMdlIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjrM_EveRst_InjrMdlIf(void)
{
   IFAIRSYSIGSYS_vidInjrMSys1();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn34D_FHCanF34DIf2                                 */
/* !Description :  Evénement de réception de trame 34Dh                       */
/* !Number      :  SCH4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_bTqReq();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn34D_FHCanF34DIf2                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn34D_FHCanF34DIf2(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutput_bTqReq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveRst_BattVoltAcqIf                                   */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidBattVolt();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_EveRst_BattVoltAcqIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveRst_BattVoltAcqIf(void)
{
   IFAIRSYSIGSYS_vidBattVolt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_AdvMaxT_001_MSEIf                                       */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH4.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutMaxPrevAdpCy();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_AdvMaxT_001_MSEIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_AdvMaxT_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutMaxPrevAdpCy();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_AirSysAir_001_MSEIf                                     */
/* !Description :  Evénement reset de la fonction AirSysAir.                  */
/* !Number      :  SCH4.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutputInMnfReq();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_AirSysAir_001_MSEIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_AirSysAir_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutputInMnfReq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_CkMngIfIf                                      */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH4.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidCtTDC();                                */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_nEng();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_CkMngIfIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_CkMngIfIf(void)
{
   IFAIRSYSIGSYS_vidCtTDC();
   IFAIRSYSIGSYS_vidOutput_nEng();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_FuSysCkMngIf                                   */
/* !Description :  Evénement reset de module d'interface.                     */
/* !Number      :  SCH4.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidCkMngIf();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_FuSysCkMngIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_FuSysCkMngIf(void)
{
   IFAIRSYSIGSYS_vidCkMngIf();
}

/*-------------------------------- end of file -------------------------------*/