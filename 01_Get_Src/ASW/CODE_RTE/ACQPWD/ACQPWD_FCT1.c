/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQPWD                                                  */
/* !Description     : ACQPWD Component                                        */
/*                                                                            */
/* !Module          : ACQPWD                                                  */
/* !Description     : Spécification des acquisitions rco (PwdHal)             */
/*                                                                            */
/* !File            : ACQPWD_FCT1.C                                           */
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
/*   1 / ACQPWD_vidInit                                                       */
/*   2 / ACQPWD_vidInitFlowMng                                                */
/*   3 / ACQPWD_vidCluPedAcq                                                  */
/*   4 / ACQPWD_vidInitNeutPosn                                               */
/*   5 / ACQPWD_vidNeutPosnAcq                                                */
/*   6 / ACQPWD_vidInitFuPmp                                                  */
/*   7 / ACQPWD_vidFuPmpDiagAcq                                               */
/*   8 / ACQPWD_vidInitCmdDiagCoFan                                           */
/*   9 / ACQPWD_vidCmdDiagCoFanAcq                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6717056 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQPWD/ACQPWD_FCT1.C_v            $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   05 Sep 2014 $*/
/* $Author::   achebino                               $$Date::   05 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACQPWD.h"
#include "ACQPWD_L.h"
#include "ACQPWD_IM.h"
#include "PWDHAL.h"
#include "ACQPWD_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidInit                                             */
/* !Description :  Ce bloc représente les valeurs des différents sorties au   */
/*                 réveil calculateur.                                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acqui_diag_pompe_ess_pwd_rco;                               */
/*  output uint32 Acqui_diag_pompe_ess_pwd_per;                               */
/*  output uint16 Acqui_pedale_embrayage_pwd_rco;                             */
/*  output uint32 Acqui_pedale_embrayage_pwd_per;                             */
/*  output uint16 Acquis_point_mort_rco;                                      */
/*  output uint16 Acquis_point_mort_periode;                                  */
/*  output uint16 Acquisition_etat_gmvC;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidInit(void)
{
   VEMS_vidSET(Acqui_diag_pompe_ess_pwd_rco, 0);
   VEMS_vidSET(Acqui_diag_pompe_ess_pwd_per, 0);
   VEMS_vidSET(Acqui_pedale_embrayage_pwd_rco, 0);
   VEMS_vidSET(Acqui_pedale_embrayage_pwd_per, 0);
   VEMS_vidSET(Acquis_point_mort_rco, 0);
   VEMS_vidSET(Acquis_point_mort_periode, 0);
   VEMS_vidSET(Acquisition_etat_gmvC, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidInitFlowMng                                      */
/* !Description :  Initialisation du FlowMng.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_udtWriteTimeoutValue(argin uint8 u8Channel, argin */
/*  PWDHAL_tudtTimeoutType udtTimeoutValue ) Std_ReturnType;                  */
/*  extf argret void PWDHAL_vidEnable(argin uint8 u8Channel);                 */
/*  input uint16 Ext_rCluPWDTimeOutVal_C;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidInitFlowMng(void)
{
   Std_ReturnType u8LocalStatus;
   uint32         u32LocalExt_rCluPWDTimeOutVal;

   /* Resolution of API = 10 ns */
   u32LocalExt_rCluPWDTimeOutVal = (uint32)(Ext_rCluPWDTimeOutVal_C * 1000);
   u8LocalStatus = PWDHAL_udtWriteTimeoutValue(CH_PWD_CLUTCH,
                                               u32LocalExt_rCluPWDTimeOutVal);
   /*QAC warning justification : Refer to VEMS V02 ECU#055994*/
   PWDHAL_vidEnable(CH_PWD_CLUTCH);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidCluPedAcq                                        */
/* !Description :  L’acquisition du  signal PWM issu du capteur de la pédale  */
/*                 d'embrayage est réalisée de façon temporelle et débutera   */
/*                 dès le réveil du calculateur.                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32          */
/*  *pu32Period, uint16 *pu16DutyCycle);                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Acqui_pedale_embrayage_pwd_per;                             */
/*  output uint16 Acqui_pedale_embrayage_pwd_rco;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidCluPedAcq(void)
{
   uint16 u16LocalDutyCycle;
   uint32 u32LocalAcqui_embrayage_per;
   uint32 u32LocalPeriod;


   PWDHAL_vidGetSignalInfo(CH_PWD_CLUTCH, &u32LocalPeriod, &u16LocalDutyCycle);
   /* u32LocalPeriod is returned with a resolution = 100ns */
   /* u16LocalDutyCycle is returned with a resolution = 100/32768 % */

   u32LocalAcqui_embrayage_per = MATHSRV_udtMIN(u32LocalPeriod, 2500001);
   VEMS_vidSET(Acqui_pedale_embrayage_pwd_per, u32LocalAcqui_embrayage_per);
   u16LocalDutyCycle = (uint16)MATHSRV_udtMIN(u16LocalDutyCycle, 32768);
   VEMS_vidSET(Acqui_pedale_embrayage_pwd_rco, u16LocalDutyCycle);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidInitNeutPosn                                     */
/* !Description :  Initialisation du NeutPosn.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_udtWriteTimeoutValue(argin uint8 u8Channel, argin */
/*  PWDHAL_tudtTimeoutType udtTimeoutValue ) Std_ReturnType;                  */
/*  extf argret void PWDHAL_vidEnable(argin uint8 u8Channel);                 */
/*  input uint32 Ext_PtNeutPWDTimeOutVal_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidInitNeutPosn(void)
{
   Std_ReturnType u8LocalStatus;

   /* Resolution of API = 10 ns */
   u8LocalStatus = PWDHAL_udtWriteTimeoutValue(CH_PWD_CAPTEUR_NEUTRE,
                                               Ext_PtNeutPWDTimeOutVal_C);
   /*QAC warning justification : Refer to VEMS V02 ECU#055994*/
   PWDHAL_vidEnable(CH_PWD_CAPTEUR_NEUTRE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidNeutPosnAcq                                      */
/* !Description :  Ce bloc met à la disposition du LDA le rapport cyclique du */
/*                 signal délivré par le capteur de position point mort. Le   */
/*                 calcul du rapport cyclique de ce signal est effectué par le*/
/*                 LDB.                                                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32          */
/*  *pu32Period, uint16 *pu16DutyCycle);                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquis_point_mort_rco;                                      */
/*  output uint16 Acquis_point_mort_periode;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidNeutPosnAcq(void)
{
   uint16  u16LocalAcquis_point_periode;
   uint16  u16LocalDutyCycle;
   uint32  u32LocalPeriod;


   PWDHAL_vidGetSignalInfo(CH_PWD_CAPTEUR_NEUTRE,
                           &u32LocalPeriod,
                           &u16LocalDutyCycle);
   /* u32LocalPeriod is returned with a resolution = 100ns */
   /* u16LocalDutyCycle is returned with a resolution = 100/32768 % */

   u16LocalDutyCycle = (uint16)MATHSRV_udtMIN(u16LocalDutyCycle, 32768);
   u32LocalPeriod = u32LocalPeriod / 1000;

   u16LocalAcquis_point_periode = (uint16)MATHSRV_udtMIN(u32LocalPeriod, 65535);

   VEMS_vidSET(Acquis_point_mort_rco, u16LocalDutyCycle);
   VEMS_vidSET(Acquis_point_mort_periode, u16LocalAcquis_point_periode);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidInitFuPmp                                        */
/* !Description :  Initialisation du FuPmp.                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_udtWriteTimeoutValue(argin uint8 u8Channel, argin */
/*  PWDHAL_tudtTimeoutType udtTimeoutValue ) Std_ReturnType;                  */
/*  extf argret void PWDHAL_vidEnable(argin uint8 u8Channel);                 */
/*  input uint16 FuPmp_tiFuPmpPWDTimeOutVal_C;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidInitFuPmp(void)
{
   Std_ReturnType u8LocalStatus;
   uint32         u32LocalFuPmp_tiFuPmpPWDTime;


   /* Resolution of API = 10 ns */
   u32LocalFuPmp_tiFuPmpPWDTime = (uint32)(FuPmp_tiFuPmpPWDTimeOutVal_C * 1000);
   u8LocalStatus = PWDHAL_udtWriteTimeoutValue(CH_PWD_DIAG_POMPE_CARB_VIT_VAR,
                                               u32LocalFuPmp_tiFuPmpPWDTime);
   /*QAC warning justification : Refer to VEMS V02 ECU#055994*/
   PWDHAL_vidEnable(CH_PWD_DIAG_POMPE_CARB_VIT_VAR);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidFuPmpDiagAcq                                     */
/* !Description :  L’acquisition du signal de diagnostic de la pompe de gavage*/
/*                 est réalisée de façon temporelle et débutera dès le réveil */
/*                 du calculateur.                                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32          */
/*  *pu32Period, uint16 *pu16DutyCycle);                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Acqui_diag_pompe_ess_pwd_per;                               */
/*  output uint16 Acqui_diag_pompe_ess_pwd_rco;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidFuPmpDiagAcq(void)
{
   uint16 u16LocalDutyCycle;
   uint32 u32LocalAcqui_diag_pompe_per;
   uint32 u32LocalPeriod;


   PWDHAL_vidGetSignalInfo(CH_PWD_DIAG_POMPE_CARB_VIT_VAR,
                           &u32LocalPeriod,
                           &u16LocalDutyCycle);
   /* u32LocalPeriod is returned with a resolution = 100ns */
   /* u16LocalDutyCycle is returned with a resolution = 100/32768 % */

   u32LocalAcqui_diag_pompe_per = MATHSRV_udtMIN(u32LocalPeriod, 2500001);
   VEMS_vidSET(Acqui_diag_pompe_ess_pwd_per, u32LocalAcqui_diag_pompe_per);
   u16LocalDutyCycle = (uint16)MATHSRV_udtMIN(u16LocalDutyCycle, 32768);
   VEMS_vidSET(Acqui_diag_pompe_ess_pwd_rco, u16LocalDutyCycle);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidInitCmdDiagCoFan                                 */
/* !Description :  Initialisation du CoFan.                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PFCHAL_vidPwmEnable(argin uint8 u8Channel);              */
/*  extf argret void PWDHAL_udtWriteTimeoutValue(argin uint8 u8Channel, argin */
/* PWDHAL_tudtTimeoutType udtTimeoutValue ) Std_ReturnType;                   */
/*  extf argret void PWDHAL_vidEnable(argin uint8 u8Channel);                 */
/*  input uint16 CoFan_StFanPWDTimeOutVal_C;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidInitCmdDiagCoFan(void)
{
   Std_ReturnType u8LocalStatus;
   uint32         u32LocalTimeoutValue;


   PFCHAL_vidPwmEnable(CH_PFC_GMV_1);

   /* Resolution of API = 10 ns */
   u32LocalTimeoutValue = (uint32)(CoFan_StFanPWDTimeOutVal_C * 1000);
   u8LocalStatus = PWDHAL_udtWriteTimeoutValue(CH_PWD_DIAG_GMV,
                                               u32LocalTimeoutValue);
   /*QAC warning justification : Refer to VEMS V02 ECU#055994*/

   PWDHAL_vidEnable(CH_PWD_DIAG_GMV);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQPWD_vidCmdDiagCoFanAcq                                  */
/* !Description :  Cette fonction réalise l’acquisition d’ETAT_GMV provenant  */
/*                 du LdB en équipement C.                                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32          */
/*  *pu32Period, uint16 *pu16DutyCycle);                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_etat_gmvC;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQPWD_vidCmdDiagCoFanAcq(void)
{
   uint16 u16LocalDutyCycle;
   uint32 u32LocalPeriod;


   PWDHAL_vidGetSignalInfo(CH_PWD_DIAG_GMV,
                           &u32LocalPeriod,
                           &u16LocalDutyCycle);
   /* u32LocalPeriod is returned with a resolution = 100ns */
   /* u16LocalDutyCycle is returned with a resolution = 100/32768 % */

   u16LocalDutyCycle = (uint16)MATHSRV_udtMIN(u16LocalDutyCycle, 32768);
   VEMS_vidSET(Acquisition_etat_gmvC, u16LocalDutyCycle);
}
/*--------------------------------- end of file ------------------------------*/