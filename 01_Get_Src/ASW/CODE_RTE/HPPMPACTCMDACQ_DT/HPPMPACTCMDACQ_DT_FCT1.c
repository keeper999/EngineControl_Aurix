/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HPPMPACTCMDACQ_DT                                       */
/* !Description     : HPPMPACTCMDACQ_DT Component                             */
/*                                                                            */
/* !Module          : HPPMPACTCMDACQ_DT                                       */
/* !Description     : PMPHAL acquisition                                      */
/*                                                                            */
/* !File            : HPPMPACTCMDACQ_DT_FCT1.c                                */
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
/*   1 / HPPMPACTCMDACQ_DT_vidHPPCmd_Init                                     */
/*   2 / HPPMPACTCMDACQ_DT_vidHPPCmd_Ena                                      */
/*   3 / HPPMPACTCMDACQ_DT_vidHPPApplCmd                                      */
/*   4 / HPPMPACTCMDACQ_DT_vidHPPProfSeln                                     */
/*   5 / HPPMPACTCMDACQ_DT_vidHPPCmdAppl                                      */
/*   6 / HPPMPACTCMDACQ_DT_vidHPPContnCmd                                     */
/*   7 / HPPMPACTCMDACQ_DT_vidbStopHPPCmd                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6882935 / 01                                        */
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

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HPPMPACTCMDACQ_DT.h"
#include "HPPMPACTCMDACQ_DT_L.h"
#include "HPPMPACTCMDACQ_DT_IM.h"
#include "PMPHAL.h"
#include "HPPMPACTCMDACQ_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidHPPCmd_Init                           */
/* !Description :  Fonction de désactivation de driver de la pompe HP au      */
/*                 calage du moteur.                                          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PMPHAL_vidDisable();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidHPPCmd_Init(void)
{
   PMPHAL_vidDisable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidHPPCmd_Ena                            */
/* !Description :  Fonction d'activation du Driver e la pompe HP.             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PMPHAL_vidEnable();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidHPPCmd_Ena(void)
{
   PMPHAL_vidEnable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidHPPApplCmd                            */
/* !Description :  Fonction qui gère la commande de la Pompe HP: sélectionne  */
/*                 le profil de commande  et applique l'angle et la mise sous */
/*                 tension pour les pulses de commande et de décélération.    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPProfSeln();                      */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPCmdAppl();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidHPPApplCmd(void)
{
   HPPMPACTCMDACQ_DT_vidHPPProfSeln();
   HPPMPACTCMDACQ_DT_vidHPPCmdAppl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidHPPProfSeln                           */
/* !Description :  Fonction qui  choisit le profil de commande à appliquer à  */
/*                 la spill valve de la pompe HP.                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret Std_ReturnType  PMPHAL_udtSwitchHppProfile(argin uint8        */
/* u8HppPulseId, argin uint8 u8HppProfileId);                                 */
/*  input uint8 PFuCtl_NrProfCmd;                                             */
/*  input uint8 PFuCtl_NrProfCmdAppl;                                         */
/*  output uint8 PFuCtl_NrProfCmdAppl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidHPPProfSeln(void)
{
   uint8          u8LocalPFuCtl_NrProfCmd;
   Std_ReturnType udtLocalStatus;
   /*Msg(3:3203) PMPHAL_udtSwitchHppProfile returns Std value*/


   VEMS_vidGET(PFuCtl_NrProfCmd, u8LocalPFuCtl_NrProfCmd);
   switch(u8LocalPFuCtl_NrProfCmd)
   {
      case 1:
         PFuCtl_NrProfCmdAppl = PMPHAL_NOM_PROFILE_1;
         break;

      case 2:
         PFuCtl_NrProfCmdAppl = PMPHAL_NOM_PROFILE_2;
         break;

      case 3:
         PFuCtl_NrProfCmdAppl = PMPHAL_NOM_PROFILE_3;
         break;

      case 4:
         PFuCtl_NrProfCmdAppl = PMPHAL_NOM_PROFILE_4;
         break;

      case 5:
         PFuCtl_NrProfCmdAppl = PMPHAL_NOM_PROFILE_5;
         break;

      case 6:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_6;
         break;

      case 7:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_7;
         break;

      case 8:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_8;
         break;

      case 9:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_9;
         break;

      case 10:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_10;
         break;

      case 11:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_11;
         break;

      case 12:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_12;
         break;

      case 13:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_13;
         break;

      case 14:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_14;
         break;

      case 15:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_15;
         break;

      case 16:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_16;
         break;

      case 17:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_17;
         break;

      case 18:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_18;
         break;

      case 19:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_19;
         break;

      case 20:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_20;
         break;

      case 21:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_21;
         break;

      case 22:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_22;
         break;

      case 23:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_23;
         break;

      case 24:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_24;
         break;

      case 25:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_25;
         break;

      default:
         PFuCtl_NrProfCmdAppl = PMPHAL_IDLE_PROFILE_25;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   udtLocalStatus = PMPHAL_udtSwitchHppProfile(PMPHAL_u8CMD_PULSE_ID,
                                               PFuCtl_NrProfCmdAppl);
   /*Msg(3:3198) PMPHAL_udtSwitchHppProfile returns Std value */
   udtLocalStatus = PMPHAL_udtSwitchHppProfile(PMPHAL_u8DECEL_PULSE_ID,
                                               PMPHAL_DECEL_PULSE_PROFILE);
   /*Msg(3:3199) PMPHAL_udtSwitchHppProfile returns Std value */

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidHPPCmdAppl                            */
/* !Description :  Fonction qui envoie la commande au LdB.                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PMPHAL_vidWriteSpillCmdAngle(argin uint16                */
/* u16SpillCmdAngle);                                                         */
/*  extf argret void PMPHAL_vidWriteSpillCmdTime(argin uint32 u32CommandTime);*/
/*  extf argret void PMPHAL_vidWriteSpillDecelDly(argin uint32                */
/* u32SpillDecelDelay);                                                       */
/*  extf argret void PMPHAL_vidWriteSpillDecelTime(argin uint32 u32DecelTime);*/
/*  extf argret void PMPHAL_vidWriteDecelHppProfilDly(argin uint32            */
/* u32ProfilSwitchDelay);                                                     */
/*  input uint16 PFuCtl_agPmpCmdReq;                                          */
/*  input uint16 PFuCtl_tiPmpCmdReq;                                          */
/*  input uint16 PFuCtl_tiPmpCmdDecelGap;                                     */
/*  input uint16 PFuCtl_tiPmpCmdDecelReq;                                     */
/*  input uint16 PFuCtl_tiPeakDurnCmd;                                        */
/*  input uint16 PFuCtl_agPmpCmdAppl;                                         */
/*  input uint32 PFuCtl_tiPmpCmdAppl;                                         */
/*  input uint32 PFuCtl_tiPmpCmdDecelAppl;                                    */
/*  output uint16 PFuCtl_agPmpCmdAppl;                                        */
/*  output uint32 PFuCtl_tiPmpCmdAppl;                                        */
/*  output uint32 PFuCtl_tiPmpCmdDecelAppl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidHPPCmdAppl(void)
{

   uint16         u16LocalPFuCtl_agPmpCmdReq;
   uint16         u16LocalPFuCtl_tiPmpCmdReq;
   uint16         u16LocalPFuCtl_tiPmpCmdDecelReq;
   uint16         u16LocalPFuCtl_tiPeakDurnCmd;
   uint16         u16LocalPFuCtl_tiPmpCmdDecelGap;
   uint32         u32LocalPFuCtl_agPmpCmdAppl;
   uint32         u32LocalPFuCtl_tiPeakDurnCmd;
   uint32         u32LocalPFuCtl_tiPmpCmdDecelGap;


   VEMS_vidGET(PFuCtl_agPmpCmdReq, u16LocalPFuCtl_agPmpCmdReq);
   VEMS_vidGET(PFuCtl_tiPmpCmdReq, u16LocalPFuCtl_tiPmpCmdReq);
   VEMS_vidGET(PFuCtl_tiPmpCmdDecelGap,u16LocalPFuCtl_tiPmpCmdDecelGap);
   VEMS_vidGET(PFuCtl_tiPmpCmdDecelReq,u16LocalPFuCtl_tiPmpCmdDecelReq);
   VEMS_vidGET(PFuCtl_tiPeakDurnCmd,u16LocalPFuCtl_tiPeakDurnCmd);

   u32LocalPFuCtl_agPmpCmdAppl = (uint32)(u16LocalPFuCtl_agPmpCmdReq * 6);
   PFuCtl_agPmpCmdAppl =
      (uint16)MATHSRV_udtMIN(u32LocalPFuCtl_agPmpCmdAppl, 46080);
   PFuCtl_tiPmpCmdAppl = (uint32)(u16LocalPFuCtl_tiPmpCmdReq * 64);

   PMPHAL_vidWriteSpillCmdAngle(PFuCtl_agPmpCmdAppl);
   PMPHAL_vidWriteSpillCmdTime(PFuCtl_tiPmpCmdAppl);

   u32LocalPFuCtl_tiPmpCmdDecelGap =
      (uint32)(u16LocalPFuCtl_tiPmpCmdDecelGap * 64);
   PMPHAL_vidWriteSpillDecelDly(u32LocalPFuCtl_tiPmpCmdDecelGap);

   PFuCtl_tiPmpCmdDecelAppl = (uint32)(u16LocalPFuCtl_tiPmpCmdDecelReq * 64);
   PMPHAL_vidWriteSpillDecelTime(PFuCtl_tiPmpCmdDecelAppl);

   u32LocalPFuCtl_tiPeakDurnCmd = (uint32)(u16LocalPFuCtl_tiPeakDurnCmd * 64);
   PMPHAL_vidWriteDecelHppProfilDly(u32LocalPFuCtl_tiPeakDurnCmd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidHPPContnCmd                           */
/* !Description :  Fonction qui assure la commande en continu de la pompe HP  */
/*                 au démarrage.                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  PMPHAL_udtWriteSpillCmdLevel(argin boolean    */
/* bSpillCmdLevel);                                                           */
/*  input boolean PFuCtl_bAcvCmdContnsReq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidHPPContnCmd(void)
{
   boolean        bLocalPFuCtl_bAcvCmdContnsReq;
   Std_ReturnType udtLocalStatus;
   /*Msg(3:3203): PMPHAL_udtWriteSpillCmdLevel returns Std value */
   VEMS_vidGET(PFuCtl_bAcvCmdContnsReq, bLocalPFuCtl_bAcvCmdContnsReq);
   udtLocalStatus = PMPHAL_udtWriteSpillCmdLevel(bLocalPFuCtl_bAcvCmdContnsReq);
   /*Msg(3:3199): PMPHAL_udtWriteSpillCmdLevel returns Std value */

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPMPACTCMDACQ_DT_vidbStopHPPCmd                           */
/* !Description :  Fonction qui retourne l’état du driver de la pompe.        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  PMPHAL_udtEnableSpillCommand();               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 AcquiState_stHPPmpActCmd;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPMPACTCMDACQ_DT_vidbStopHPPCmd(void)
{
   Std_ReturnType u8LocalAcquiState;


   u8LocalAcquiState = PMPHAL_udtEnableSpillCommand();
   VEMS_vidSET(AcquiState_stHPPmpActCmd, u8LocalAcquiState);
}

/*------------------------------end of file-----------------------------------*/