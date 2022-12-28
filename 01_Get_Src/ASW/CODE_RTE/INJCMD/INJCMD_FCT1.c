/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCMD                                                  */
/* !Description     : INJCMD Component                                        */
/*                                                                            */
/* !Module          : INJCMD                                                  */
/* !Description     : INTERFACE COMMANDE INJECTEURS ESSENCE                   */
/*                                                                            */
/* !File            : INJCMD_FCT1.C                                           */
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
/*   1 / INJCMD_vidInitOutput                                                 */
/*   2 / INJCMD_vidManInjTime                                                 */
/*   3 / INJCMD_vidFormatInjTime                                              */
/*   4 / INJCMD_vidUpdate                                                     */
/*   5 / INJCMD_vidInjHALUpdate                                               */
/*   6 / INJCMD_vidInjHALCmdProfile                                           */
/*   7 / INJCMD_vidModeInjectionSequentielleCyl1                              */
/*   8 / INJCMD_vidModeInjectionSequentielleCyl2                              */
/*   9 / INJCMD_vidModeInjectionSequentielleCyl3                              */
/*   10 / INJCMD_vidModeInjectionSequentielleCyl4                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6886136 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCMD/INJCMD_FCT1.C_v    $*/
/* $Revision::   1.15     $$Author::   mbenfrad       $$Date::   17 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
  temp.mde producing this kind of error                                      */
#include "INJCMD.h"
#include "INJCMD_L.h"
#include "INJCMD_IM.h"
#include "INJCMD_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInitOutput                                       */
/* !Description :  Initialisation des variables du module.                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Inj_bInhInjr1;                                             */
/*  output boolean Inj_bInhInjr2;                                             */
/*  output boolean Inj_bInhInjr3;                                             */
/*  output boolean Inj_bInhInjr4;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInitOutput(void)
{
   /*Outputs*/
   VEMS_vidSET(Inj_bInhInjr1, 0);
   VEMS_vidSET(Inj_bInhInjr2, 0);
   VEMS_vidSET(Inj_bInhInjr3, 0);
   VEMS_vidSET(Inj_bInhInjr4, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidManInjTime                                       */
/* !Description :  Les consignes phase et temps d'injection séquentielle      */
/*                 doivent être immédiatement prises en compte par le driver  */
/*                 injection si l'indicateur d'inhibition                     */
/*                 Inhibe_reactualisation_t_inj (calibration) n'est pas       */
/*                 positionné.                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret uint32  INJCMD_vidFormatInjTime(argin uint32                  */
/* uint32_tiInjReqCyl);                                                       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCMD_vidUpdate();                                      */
/*  extf argret void INJCMD_vidModeInjectionSequentielleCyl1();               */
/*  extf argret void INJCMD_vidModeInjectionSequentielleCyl2();               */
/*  extf argret void INJCMD_vidModeInjectionSequentielleCyl3();               */
/*  extf argret void INJCMD_vidModeInjectionSequentielleCyl4();               */
/*  input uint32 InjrSys_prm_tiInjH1ReqCyl[6];                                */
/*  input uint32 InjrSys_prm_tiInjS1ReqCyl[6];                                */
/*  input uint32 InjrSys_prm_tiInjH2ReqCyl[6];                                */
/*  input uint32 InjrSys_prm_tiInjS2ReqCyl[6];                                */
/*  input uint16 InjSys_nInjPhaOfs_C;                                         */
/*  input uint16 InjSys_prm_agBegInjH1ReqCyl[6];                              */
/*  input uint16 InjSys_prm_agBegInjS1ReqCyl[6];                              */
/*  input uint16 InjSys_prm_agBegInjH2ReqCyl[6];                              */
/*  input uint16 InjSys_prm_agBegInjS2ReqCyl[6];                              */
/*  input uint16 IMMO_stEcuLockStTyp;                                         */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output uint32 InjSys_tiInjH1LDBReqCyl1;                                   */
/*  output uint32 InjSys_tiInjH1LDBReqCyl2;                                   */
/*  output uint32 InjSys_tiInjH1LDBReqCyl3;                                   */
/*  output uint32 InjSys_tiInjH1LDBReqCyl4;                                   */
/*  output uint32 InjSys_tiInjS1LDBReqCyl1;                                   */
/*  output uint32 InjSys_tiInjS1LDBReqCyl2;                                   */
/*  output uint32 InjSys_tiInjS1LDBReqCyl3;                                   */
/*  output uint32 InjSys_tiInjS1LDBReqCyl4;                                   */
/*  output uint32 InjSys_tiInjH2LDBReqCyl1;                                   */
/*  output uint32 InjSys_tiInjH2LDBReqCyl2;                                   */
/*  output uint32 InjSys_tiInjH2LDBReqCyl3;                                   */
/*  output uint32 InjSys_tiInjH2LDBReqCyl4;                                   */
/*  output uint32 InjSys_tiInjS2LDBReqCyl1;                                   */
/*  output uint32 InjSys_tiInjS2LDBReqCyl2;                                   */
/*  output uint32 InjSys_tiInjS2LDBReqCyl3;                                   */
/*  output uint32 InjSys_tiInjS2LDBReqCyl4;                                   */
/*  output uint16 InjSys_prm_agBegH1LDBReqCyl1;                               */
/*  output uint16 InjSys_prm_agBegH1LDBReqCyl2;                               */
/*  output uint16 InjSys_prm_agBegH1LDBReqCyl3;                               */
/*  output uint16 InjSys_prm_agBegH1LDBReqCyl4;                               */
/*  output uint16 InjSys_prm_agBegS1LDBReqCyl1;                               */
/*  output uint16 InjSys_prm_agBegS1LDBReqCyl2;                               */
/*  output uint16 InjSys_prm_agBegS1LDBReqCyl3;                               */
/*  output uint16 InjSys_prm_agBegS1LDBReqCyl4;                               */
/*  output uint16 InjSys_prm_agBegH2LDBReqCyl1;                               */
/*  output uint16 InjSys_prm_agBegH2LDBReqCyl2;                               */
/*  output uint16 InjSys_prm_agBegH2LDBReqCyl3;                               */
/*  output uint16 InjSys_prm_agBegH2LDBReqCyl4;                               */
/*  output uint16 InjSys_prm_agBegS2LDBReqCyl1;                               */
/*  output uint16 InjSys_prm_agBegS2LDBReqCyl2;                               */
/*  output uint16 InjSys_prm_agBegS2LDBReqCyl3;                               */
/*  output uint16 InjSys_prm_agBegS2LDBReqCyl4;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidManInjTime(void)
{
   uint16 u16LocalIMMO_stEcuLockStTyp;
   uint16 u16LocalInjReqCyl;
   uint32 u32LocalInjReqCyl;
   uint32 u32LocalOfs;
   sint32 s32LocalDif;
   uint8  u8LocalExt_noCylEng;                         /* VEMS V02 ECU#060097 */

   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 0, u32LocalInjReqCyl);
   InjSys_tiInjH1LDBReqCyl1 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 1, u32LocalInjReqCyl);
   InjSys_tiInjH1LDBReqCyl2 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 2, u32LocalInjReqCyl);
   InjSys_tiInjH1LDBReqCyl3 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH1ReqCyl, 3, u32LocalInjReqCyl);
   InjSys_tiInjH1LDBReqCyl4 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);

   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS1ReqCyl, 0, u32LocalInjReqCyl);
   InjSys_tiInjS1LDBReqCyl1 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS1ReqCyl, 1, u32LocalInjReqCyl);
   InjSys_tiInjS1LDBReqCyl2 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS1ReqCyl, 2, u32LocalInjReqCyl);
   InjSys_tiInjS1LDBReqCyl3 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS1ReqCyl, 3, u32LocalInjReqCyl);
   InjSys_tiInjS1LDBReqCyl4 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);

   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH2ReqCyl, 0, u32LocalInjReqCyl);
   InjSys_tiInjH2LDBReqCyl1 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH2ReqCyl, 1, u32LocalInjReqCyl);
   InjSys_tiInjH2LDBReqCyl2 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH2ReqCyl, 2, u32LocalInjReqCyl);
   InjSys_tiInjH2LDBReqCyl3 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjH2ReqCyl, 3, u32LocalInjReqCyl);
   InjSys_tiInjH2LDBReqCyl4 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);

   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS2ReqCyl, 0, u32LocalInjReqCyl);
   InjSys_tiInjS2LDBReqCyl1 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS2ReqCyl, 1, u32LocalInjReqCyl);
   InjSys_tiInjS2LDBReqCyl2 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS2ReqCyl, 2, u32LocalInjReqCyl);
   InjSys_tiInjS2LDBReqCyl3 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);
   VEMS_vidGET1DArrayElement(InjrSys_prm_tiInjS2ReqCyl, 3, u32LocalInjReqCyl);
   InjSys_tiInjS2LDBReqCyl4 = INJCMD_vidFormatInjTime(u32LocalInjReqCyl);

   u32LocalOfs = (uint32)(InjSys_nInjPhaOfs_C * 64);
    /*H1*/
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH1ReqCyl, 0, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH1LDBReqCyl1 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   /*QAC Warning(3:3356): The case FALSE is covered in the unit test*/

   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH1ReqCyl, 1, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH1LDBReqCyl2 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH1ReqCyl, 2, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH1LDBReqCyl3 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH1ReqCyl, 3, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH1LDBReqCyl4 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);

   /*S1*/
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS1ReqCyl, 0, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS1LDBReqCyl1 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS1ReqCyl, 1, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS1LDBReqCyl2 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS1ReqCyl, 2, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS1LDBReqCyl3 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS1ReqCyl, 3, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS1LDBReqCyl4 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);

   /*H2*/
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH2ReqCyl, 0, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH2LDBReqCyl1 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH2ReqCyl, 1, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH2LDBReqCyl2 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH2ReqCyl, 2, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH2LDBReqCyl3 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjH2ReqCyl, 3, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 4));
   InjSys_prm_agBegH2LDBReqCyl4 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);

   /*S2*/
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS2ReqCyl, 0, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS2LDBReqCyl1 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS2ReqCyl, 1, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS2LDBReqCyl2 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS2ReqCyl, 2, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS2LDBReqCyl3 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);
   VEMS_vidGET1DArrayElement(InjSys_prm_agBegInjS2ReqCyl, 3, u16LocalInjReqCyl);
   s32LocalDif = (sint32)(u32LocalOfs - (u16LocalInjReqCyl * 6));
   InjSys_prm_agBegS2LDBReqCyl4 = (uint16)MATHSRV_udtCLAMP(s32LocalDif,0,46080);

   VEMS_vidGET(IMMO_stEcuLockStTyp, u16LocalIMMO_stEcuLockStTyp);
   if (u16LocalIMMO_stEcuLockStTyp == IMMO_ECU_UNLOCKED)
   {
      INJCMD_vidUpdate();
      INJCMD_vidModeInjectionSequentielleCyl1();
      INJCMD_vidModeInjectionSequentielleCyl2();
      INJCMD_vidModeInjectionSequentielleCyl3();

      /* Correction INJCMD - ESC VEMS V02 ECU#060097 */
      VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
      if (u8LocalExt_noCylEng == 4)
      {
         INJCMD_vidModeInjectionSequentielleCyl4();
      }
   }
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidFormatInjTime                                    */
/* !Description :  Scaling pour les temps d' injection                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
uint32 INJCMD_vidFormatInjTime
(
   uint32 uint32_tiInjReqCyl
)
{
   uint32 uint32_tiInjLDBReqCyl;

   if (uint32_tiInjReqCyl < 0x8000000)
   {
      uint32_tiInjLDBReqCyl = (32*uint32_tiInjReqCyl);
   }
   else
   {
      uint32_tiInjLDBReqCyl = UINT32_MAX;
   }
   return(uint32_tiInjLDBReqCyl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidUpdate                                           */
/* !Description :  Gestion de la mise a jour de la couche hard d'injection.   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCMD_vidInjHALUpdate();                                */
/*  extf argret void INJCMD_vidInjHALCmdProfile();                            */
/*  input boolean Inhibe_reactualisation_t_inj;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidUpdate(void)
{
   if (Inhibe_reactualisation_t_inj == 0)
   {
      INJCMD_vidInjHALUpdate();
   }
   INJCMD_vidInjHALCmdProfile();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInjHALUpdate                                     */
/* !Description :  Mise a jour de la couche hard d'injection                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret INJHAL_tbfUpdateStatus  INJHAL_bfUpdate(argin uint8           */
/*  u8InstanceId);                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInjHALUpdate(void)
{
   INJHAL_tbfUpdateStatus u16LocalINJHALUpdate;
   /*QAC Warning(3:3203): INJHAL_bfUpdate returns uint16 value*/
   u16LocalINJHALUpdate = INJHAL_bfUpdate(INS_INJ_GDI);
   /*QAC Warning(3:3199): INJHAL_bfUpdate returns uint16 value*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInjHALCmdProfile                                 */
/* !Description :  Fonction de changement de profil de commande.              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf INJHAL_udtSwitchGdiProfile();                                        */
/*  input uint8 InjSys_stTypElCmdInjrReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInjHALCmdProfile(void)
{
   Std_ReturnType u8LocalSwitchGdiProfile;
   /*QAC Warning(3:3203): INJHAL_udtSwitchGdiProfile returns uint8 value*/
   uint8          u8LocalInjSys_stTypElCmdInjRq;


   VEMS_vidGET(InjSys_stTypElCmdInjrReq, u8LocalInjSys_stTypElCmdInjRq);
   u8LocalSwitchGdiProfile =
      INJHAL_udtSwitchGdiProfile(INS_INJ_GDI, u8LocalInjSys_stTypElCmdInjRq);
   /*QAC Warning(3:3199): INJHAL_udtSwitchGdiProfile returns uint8 value*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidModeInjectionSequentielleCyl1                    */
/* !Description :  Mode d'injection sequentielle appliqué au cylindre 1       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidWriteTime(uint8 u8Channel, uint8 u8PulseNumber,*/
/*  uint32 u32InjectionTime);                                                 */
/*  extf argret void INJHAL_vidWriteAngle(uint8 u8Channel, uint8              */
/* u8PulseNumber, uint16 u16InjectionAngle);                                  */
/*  input uint32 InjSys_tiInjH1LDBReqCyl1;                                    */
/*  input uint16 InjSys_prm_agBegH1LDBReqCyl1;                                */
/*  input uint32 InjSys_tiInjH2LDBReqCyl1;                                    */
/*  input uint16 InjSys_prm_agBegH2LDBReqCyl1;                                */
/*  input uint32 InjSys_tiInjS1LDBReqCyl1;                                    */
/*  input uint16 InjSys_prm_agBegS1LDBReqCyl1;                                */
/*  input uint32 InjSys_tiInjS2LDBReqCyl1;                                    */
/*  input uint16 InjSys_prm_agBegS2LDBReqCyl1;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidModeInjectionSequentielleCyl1(void)
{
   /*QAC Warning(2:4152): Name imposed in specification*/

   INJHAL_vidWriteTime(CH_INJ_1_GDI, INJHAL_u8INJECTION_PULSE_1,
                       InjSys_tiInjH1LDBReqCyl1);
   INJHAL_vidWriteAngle(CH_INJ_1_GDI, INJHAL_u8INJECTION_PULSE_1,
                        InjSys_prm_agBegH1LDBReqCyl1);
   INJHAL_vidWriteTime(CH_INJ_1_GDI, INJHAL_u8INJECTION_PULSE_2,
                       InjSys_tiInjH2LDBReqCyl1);
   INJHAL_vidWriteAngle(CH_INJ_1_GDI,INJHAL_u8INJECTION_PULSE_2,
                        InjSys_prm_agBegH2LDBReqCyl1);
   INJHAL_vidWriteTime(CH_INJ_1_GDI, INJHAL_u8INJECTION_PULSE_3,
                       InjSys_tiInjS1LDBReqCyl1);
   INJHAL_vidWriteAngle(CH_INJ_1_GDI,INJHAL_u8INJECTION_PULSE_3,
                        InjSys_prm_agBegS1LDBReqCyl1);
   INJHAL_vidWriteTime(CH_INJ_1_GDI, INJHAL_u8INJECTION_PULSE_4,
                       InjSys_tiInjS2LDBReqCyl1);
   INJHAL_vidWriteAngle(CH_INJ_1_GDI,INJHAL_u8INJECTION_PULSE_4,
                        InjSys_prm_agBegS2LDBReqCyl1);
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidModeInjectionSequentielleCyl2                    */
/* !Description :  Mode d'injection sequentielle appliqué au cylindre 2       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidWriteTime(uint8 u8Channel, uint8 u8PulseNumber,*/
/*  uint32 u32InjectionTime);                                                 */
/*  extf argret void INJHAL_vidWriteAngle(uint8 u8Channel, uint8              */
/* u8PulseNumber, uint16 u16InjectionAngle);                                  */
/*  input uint32 InjSys_tiInjH1LDBReqCyl2;                                    */
/*  input uint16 InjSys_prm_agBegH1LDBReqCyl2;                                */
/*  input uint32 InjSys_tiInjH2LDBReqCyl2;                                    */
/*  input uint16 InjSys_prm_agBegH2LDBReqCyl2;                                */
/*  input uint32 InjSys_tiInjS1LDBReqCyl2;                                    */
/*  input uint16 InjSys_prm_agBegS1LDBReqCyl2;                                */
/*  input uint32 InjSys_tiInjS2LDBReqCyl2;                                    */
/*  input uint16 InjSys_prm_agBegS2LDBReqCyl2;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidModeInjectionSequentielleCyl2(void)
{

   INJHAL_vidWriteTime(CH_INJ_2_GDI, INJHAL_u8INJECTION_PULSE_1,
                       InjSys_tiInjH1LDBReqCyl2);
   INJHAL_vidWriteAngle(CH_INJ_2_GDI,INJHAL_u8INJECTION_PULSE_1,
                        InjSys_prm_agBegH1LDBReqCyl2);
   INJHAL_vidWriteTime(CH_INJ_2_GDI, INJHAL_u8INJECTION_PULSE_2,
                       InjSys_tiInjH2LDBReqCyl2);
   INJHAL_vidWriteAngle(CH_INJ_2_GDI,INJHAL_u8INJECTION_PULSE_2,
                        InjSys_prm_agBegH2LDBReqCyl2);
   INJHAL_vidWriteTime(CH_INJ_2_GDI, INJHAL_u8INJECTION_PULSE_3,
                       InjSys_tiInjS1LDBReqCyl2);
   INJHAL_vidWriteAngle(CH_INJ_2_GDI,INJHAL_u8INJECTION_PULSE_3,
                        InjSys_prm_agBegS1LDBReqCyl2);
   INJHAL_vidWriteTime(CH_INJ_2_GDI, INJHAL_u8INJECTION_PULSE_4,
                       InjSys_tiInjS2LDBReqCyl2);
   INJHAL_vidWriteAngle(CH_INJ_2_GDI,INJHAL_u8INJECTION_PULSE_4,
                        InjSys_prm_agBegS2LDBReqCyl2);
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidModeInjectionSequentielleCyl3                    */
/* !Description :  Mode d'injection sequentielle appliqué au cylindre 3       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidWriteTime(uint8 u8Channel, uint8 u8PulseNumber,*/
/*  uint32 u32InjectionTime);                                                 */
/*  extf argret void INJHAL_vidWriteAngle(uint8 u8Channel, uint8              */
/* u8PulseNumber, uint16 u16InjectionAngle);                                  */
/*  input uint32 InjSys_tiInjH1LDBReqCyl3;                                    */
/*  input uint16 InjSys_prm_agBegH1LDBReqCyl3;                                */
/*  input uint32 InjSys_tiInjH2LDBReqCyl3;                                    */
/*  input uint16 InjSys_prm_agBegH2LDBReqCyl3;                                */
/*  input uint32 InjSys_tiInjS1LDBReqCyl3;                                    */
/*  input uint16 InjSys_prm_agBegS1LDBReqCyl3;                                */
/*  input uint32 InjSys_tiInjS2LDBReqCyl3;                                    */
/*  input uint16 InjSys_prm_agBegS2LDBReqCyl3;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidModeInjectionSequentielleCyl3(void)
{

   INJHAL_vidWriteTime(CH_INJ_3_GDI, INJHAL_u8INJECTION_PULSE_1,
                       InjSys_tiInjH1LDBReqCyl3);
   INJHAL_vidWriteAngle(CH_INJ_3_GDI,INJHAL_u8INJECTION_PULSE_1,
                        InjSys_prm_agBegH1LDBReqCyl3);
   INJHAL_vidWriteTime(CH_INJ_3_GDI, INJHAL_u8INJECTION_PULSE_2,
                       InjSys_tiInjH2LDBReqCyl3);
   INJHAL_vidWriteAngle(CH_INJ_3_GDI,INJHAL_u8INJECTION_PULSE_2,
                        InjSys_prm_agBegH2LDBReqCyl3);
   INJHAL_vidWriteTime(CH_INJ_3_GDI, INJHAL_u8INJECTION_PULSE_3,
                       InjSys_tiInjS1LDBReqCyl3);
   INJHAL_vidWriteAngle(CH_INJ_3_GDI,INJHAL_u8INJECTION_PULSE_3,
                        InjSys_prm_agBegS1LDBReqCyl3);
   INJHAL_vidWriteTime(CH_INJ_3_GDI, INJHAL_u8INJECTION_PULSE_4,
                       InjSys_tiInjS2LDBReqCyl3);
   INJHAL_vidWriteAngle(CH_INJ_3_GDI,INJHAL_u8INJECTION_PULSE_4,
                        InjSys_prm_agBegS2LDBReqCyl3);
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidModeInjectionSequentielleCyl4                    */
/* !Description :  Mode d'injection sequentielle appliqué au cylindre 4       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidWriteTime(uint8 u8Channel, uint8 u8PulseNumber,*/
/*  uint32 u32InjectionTime);                                                 */
/*  extf argret void INJHAL_vidWriteAngle(uint8 u8Channel, uint8              */
/* u8PulseNumber, uint16 u16InjectionAngle);                                  */
/*  input uint32 InjSys_tiInjH1LDBReqCyl4;                                    */
/*  input uint16 InjSys_prm_agBegH1LDBReqCyl4;                                */
/*  input uint32 InjSys_tiInjH2LDBReqCyl4;                                    */
/*  input uint16 InjSys_prm_agBegH2LDBReqCyl4;                                */
/*  input uint32 InjSys_tiInjS1LDBReqCyl4;                                    */
/*  input uint16 InjSys_prm_agBegS1LDBReqCyl4;                                */
/*  input uint32 InjSys_tiInjS2LDBReqCyl4;                                    */
/*  input uint16 InjSys_prm_agBegS2LDBReqCyl4;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidModeInjectionSequentielleCyl4(void)
{

   INJHAL_vidWriteTime(CH_INJ_4_GDI,INJHAL_u8INJECTION_PULSE_1,
                       InjSys_tiInjH1LDBReqCyl4);
   INJHAL_vidWriteAngle(CH_INJ_4_GDI,INJHAL_u8INJECTION_PULSE_1,
                        InjSys_prm_agBegH1LDBReqCyl4);
   INJHAL_vidWriteTime(CH_INJ_4_GDI,INJHAL_u8INJECTION_PULSE_2,
                       InjSys_tiInjH2LDBReqCyl4);
   INJHAL_vidWriteAngle(CH_INJ_4_GDI,INJHAL_u8INJECTION_PULSE_2,
                        InjSys_prm_agBegH2LDBReqCyl4);
   INJHAL_vidWriteTime(CH_INJ_4_GDI, INJHAL_u8INJECTION_PULSE_3,
                       InjSys_tiInjS1LDBReqCyl4);
   INJHAL_vidWriteAngle(CH_INJ_4_GDI,INJHAL_u8INJECTION_PULSE_3,
                        InjSys_prm_agBegS1LDBReqCyl4);
   INJHAL_vidWriteTime(CH_INJ_4_GDI, INJHAL_u8INJECTION_PULSE_4,
                       InjSys_tiInjS2LDBReqCyl4);
   INJHAL_vidWriteAngle(CH_INJ_4_GDI,INJHAL_u8INJECTION_PULSE_4,
                        InjSys_prm_agBegS2LDBReqCyl4);
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*------------------------------- end of file --------------------------------*/
