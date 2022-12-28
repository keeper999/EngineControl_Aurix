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
/* !File            : IFAIRSYSIGSYS_SCH5.C                                    */
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
/*   1 / Sync_EveRst_IfAirSysIgSys                                            */
/*   2 / FuSysM_EveRst_tFuMIf                                                 */
/*   3 / DIAGCAN_EveRxn092_If                                                 */
/*   4 / CoFan_EveRst_CmdDiagCoFanIf                                          */
/*   5 / RE_CoClLASl_001_MSEIf                                                */
/*   6 / RE_TraBVx_001_MSEIf                                                  */
/*   7 / RE_CoGBx_001_MSEIf                                                   */
/*   8 / RE_StopStrtEm_003_MSEIf                                              */
/*   9 / RE_TqTreat_003_MSEIf                                                 */
/*   10 / RE_ExMGslT2_001_MSEIf                                               */
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
/* !Function    :  Sync_EveRst_IfAirSysIgSys                                  */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH5.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidAFAInit();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_IfAirSysIgSys                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_IfAirSysIgSys(void)
{
   IFAIRSYSIGSYS_vidAFAInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuSysM_EveRst_tFuMIf                                       */
/* !Description :  Evènement d'initialisation pour le calcul des températures */
/*                 amont pompe et rail.                                       */
/* !Number      :  SCH5.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_tFuMes();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuSysM_EveRst_tFuMIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuSysM_EveRst_tFuMIf(void)
{
   IFAIRSYSIGSYS_vidOutput_tFuMes();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGCAN_EveRxn092_If                                       */
/* !Description :  Evènement de réception de la trame 092.                    */
/* !Number      :  SCH5.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutbElecltgr();                         */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DIAGCAN_EveRxn092_If                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGCAN_EveRxn092_If(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutbElecltgr();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_EveRst_CmdDiagCoFanIf                                */
/* !Description :  Evenement de reset de la fonction CoFan                    */
/* !Number      :  SCH5.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidCmdCoFan();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_EveRst_CmdDiagCoFanIf                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_EveRst_CmdDiagCoFanIf(void)
{
   IFAIRSYSIGSYS_vidCmdCoFan();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_CoClLASl_001_MSEIf                                      */
/* !Description :  Evènement init du module CoClLASl.                         */
/* !Number      :  SCH5.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_IdlLim();                        */
/*  extf argret void IFAIRSYSIGSYS_vidTqSys();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_CoClLASl_001_MSEIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_CoClLASl_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutput_IdlLim();
   IFAIRSYSIGSYS_vidTqSys();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_TraBVx_001_MSEIf                                        */
/* !Description :  Evènement init du module TraBVx.                           */
/* !Number      :  SCH5.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidrapEngaMeca349();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_TraBVx_001_MSEIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_TraBVx_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidrapEngaMeca349();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_CoGBx_001_MSEIf                                         */
/* !Description :  Evènement init du module CoGBx .                           */
/* !Number      :  SCH5.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutputGearRatio();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_CoGBx_001_MSEIf                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_CoGBx_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutputGearRatio();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_StopStrtEm_003_MSEIf                                    */
/* !Description :  Evènement init du module StopStrtEm .                      */
/* !Number      :  SCH5.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_bStaReq();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_StopStrtEm_003_MSEIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_StopStrtEm_003_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutput_bStaReq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_TqTreat_003_MSEIf                                       */
/* !Description :  Evènement init du module TqTreat.                          */
/* !Number      :  SCH5.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_tiAst();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_TqTreat_003_MSEIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_TqTreat_003_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutput_tiAst();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_ExMGslT2_001_MSEIf                                      */
/* !Description :  Evènement init du module ExMGslT2 .                        */
/* !Number      :  SCH5.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutMainOxCEstim();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_ExMGslT2_001_MSEIf                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_ExMGslT2_001_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutMainOxCEstim();
}

/*-------------------------------- end of file -------------------------------*/