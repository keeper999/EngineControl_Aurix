/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ISLIN                                                   */
/* !Description     : ISLIN component                                         */
/*                                                                            */
/* !Module          : ISLIN                                                   */
/* !Description     : INTER SYSTEM LIN                                        */
/*                                                                            */
/* !File            : ISLIN_FCT1.C                                            */
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
/*   1 / ISLIN_vidInitProd                                                    */
/*   2 / ISLIN_vidInitCons                                                    */
/*   3 / ISLIN_vidFreeze                                                      */
/*   4 / ISLIN_vidEtatAlt1                                                    */
/*   5 / ISLIN_vidEtatAlt2                                                    */
/*   6 / ISLIN_vidDiagEna                                                     */
/*   7 / ISLIN_vidWakeUp                                                      */
/*   8 / ISLIN_vidShutDown                                                    */
/*   9 / ISLIN_vidLinStatus                                                   */
/*   10 / vidSendTrame                                                        */
/*   11 / vidCmdeAltScale                                                     */
/*   12 / vidLinStatusInit                                                    */
/*   13 / vidLinStatusWakeUp                                                  */
/*   14 / vidLinStatusNormal                                                  */
/*   15 / vidLinStatusShut                                                    */
/*                                                                            */
/* !Reference   : V02 NT 09 03043 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ISLIN/ISLIN_FCT1.C_v              $*/
/* $Revision::   1.16     $$Author::   cbanchie       $$Date::   26 Dec 2011 $*/
/* $Author::   cbanchie                               $$Date::   26 Dec 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "Std_Types.h"
#include "ISLIN_im.h"
#include "islin.h"
#include "islin_l.h"
#include "MATHSRV.H"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion */
#include "GDGAR.h"
#include "VEMS.h"

#define ISLIN_START_SEC_CODE
#include "Memmap.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidInitProd                                          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 V_Reg;                                                       */
/*  output uint8 T_Lrc;                                                       */
/*  output uint8 Lrc_Off_On;                                                  */
/*  output uint8 I_Lim;                                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidInitProd(void)
{
   V_Reg = 0;
   T_Lrc = 5;
   Lrc_Off_On = 8;
   I_Lim = 0x00;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidInitCons                                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Clef_de_contact_prev;                                       */
/*  output boolean AltCtl_dftHiTAlt;                                          */
/*  output boolean AltCtl_dftMecAlt;                                          */
/*  output boolean AltCtl_dftElecAlt;                                         */
/*  output uint8 AltCtl_rAltCycOpRate;                                        */
/*  output uint8 AltCtl_iAlt;                                                 */
/*  output boolean AltCtl_dftComAlt;                                          */
/*  output boolean AltCtl_bFctlDft;                                           */
/*  output st111 IsLin_stLin;                                                 */
/*  output boolean Clef_de_contact_prev;                                      */
/*  output uint8 IsLin_nbWUFrameSent;                                         */
/*  output uint8 IsLin_nbSDFrameSent;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidInitCons(void)
{
   VEMS_vidSET(AltCtl_dftHiTAlt,0);
   VEMS_vidSET(AltCtl_dftMecAlt,0);
   VEMS_vidSET(AltCtl_dftElecAlt,0);
   VEMS_vidSET(AltCtl_rAltCycOpRate,0);
   VEMS_vidSET(AltCtl_iAlt,0);
   VEMS_vidSET(AltCtl_dftComAlt,0);
   VEMS_vidSET(AltCtl_bFctlDft,0);
   VEMS_vidSET(IsLin_stLin,ISLIN_INIT);
   VEMS_vidGET(Clef_de_contact,Clef_de_contact_prev);
   IsLin_nbWUFrameSent = 0;
   IsLin_nbSDFrameSent = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidFreeze                                            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ISLIN_Freeze;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidFreeze(void)
{
   GDFRM_tenuGDUState LocalstDgoAltAbsentECU;
   GDFRM_tenuGDUState LocalstDgoLINBlockedBus;


   LocalstDgoAltAbsentECU = GDGAR_tenuGetStDgo(GD_DFT_ALTABSENTECU);
   LocalstDgoLINBlockedBus = GDGAR_tenuGetStDgo(GD_DFT_LINBLOCKEDBUS);

   if ((LocalstDgoAltAbsentECU == GDU_ETAT_PCTL_PRESENT) ||
       (LocalstDgoLINBlockedBus == GDU_ETAT_PCTL_PRESENT))
   {
      ISLIN_Freeze = 1;
   }
   else
   {
      ISLIN_Freeze = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidEtatAlt1                                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ReceiveMessage(argin uint16 Id_msg, argout uint8         */
/* *Ptr_msg);                                                                 */
/*  input st111 IsLin_stLin;                                                  */
/*  input boolean ISLIN_Freeze;                                               */
/*  input boolean Defaut_Ht_Alt;                                              */
/*  input boolean Defaut_Meca_Alt;                                            */
/*  input boolean Defaut_Elec_Alt;                                            */
/*  input boolean Defaut_Com_Alt;                                             */
/*  input boolean Tof;                                                        */
/*  input uint8 Rco;                                                          */
/*  input uint8 I_Rot;                                                        */
/*  input uint8 AltCtl_iAlt;                                                  */
/*  input uint8 AltCtl_rAltCycOpRate;                                         */
/*  output uint8 AltCtl_rAltCycOpRate;                                        */
/*  output uint8 AltCtl_iAlt;                                                 */
/*  output boolean AltCtl_bFctlDft;                                           */
/*  output boolean Defaut_Ht_Alt;                                             */
/*  output boolean Defaut_Meca_Alt;                                           */
/*  output boolean Defaut_Elec_Alt;                                           */
/*  output boolean Defaut_Com_Alt;                                            */
/*  output boolean Tof;                                                       */
/*  output boolean AltCtl_dftHiTAlt;                                          */
/*  output boolean AltCtl_dftMecAlt;                                          */
/*  output boolean AltCtl_dftElecAlt;                                         */
/*  output boolean AltCtl_dftComAlt;                                          */
/*  output uint8 Rco;                                                         */
/*  output uint8 I_Rot;                                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidEtatAlt1(void)
{
   boolean  bLocalFRM_bInhEtat_Alt1;
   uint8    u8LocalBuffer[ISLIN_u8RX_BUFFER_LENGTH];
   uint8    LocalOutputCalc;
   uint8    u8LocalIsLin_stLin;
   uint8    u8LocalAltCtl_rAltCycOpRate;
   uint8    u8LocalAltCtl_iAlt;


   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);

   bLocalFRM_bInhEtat_Alt1 = GDGAR_bGetFRM(FRM_FRM_INHETAT_ALT1);
   if (bLocalFRM_bInhEtat_Alt1 != 0)
   {
      VEMS_vidSET(AltCtl_rAltCycOpRate,0);
      VEMS_vidSET(AltCtl_iAlt,0);
      VEMS_vidSET(AltCtl_bFctlDft,1);
   }
   else
   {
      ReceiveMessage(SN_ETAT_ALT1_RESPONSE, u8LocalBuffer);

      if ((ISLIN_Freeze == 0) && (u8LocalIsLin_stLin == ISLIN_NORMAL))
      {
         if (((u8LocalBuffer[0]) & 0x01) != 0)
         {
            Defaut_Ht_Alt = 1;
         }
         else
         {
            Defaut_Ht_Alt = 0;
         }
         if (((u8LocalBuffer[0]) & 0x02) != 0)
         {
            Defaut_Meca_Alt = 1;
         }
         else
         {
            Defaut_Meca_Alt = 0;
         }
         if (((u8LocalBuffer[0]) & 0x04) != 0)
         {
            Defaut_Elec_Alt = 1;
         }
         else
         {
            Defaut_Elec_Alt = 0;
         }
         if (((u8LocalBuffer[1]) & 0x40) != 0)
         {
            Defaut_Com_Alt = 1;
         }
         else
         {
            Defaut_Com_Alt = 0;
         }
         if (((u8LocalBuffer[1]) & 0x80) != 0)
         {
            Tof = 1;
         }
         else
         {
            Tof = 0;
         }

         VEMS_vidSET(AltCtl_dftHiTAlt,Defaut_Ht_Alt);
         VEMS_vidSET(AltCtl_dftMecAlt,Defaut_Meca_Alt);
         VEMS_vidSET(AltCtl_dftElecAlt,Defaut_Elec_Alt);
         VEMS_vidSET(AltCtl_dftComAlt,Defaut_Com_Alt);
         VEMS_vidSET(AltCtl_bFctlDft,Tof);

         Rco = (uint8)(((u8LocalBuffer[0]) & 0xF8) >> 3) ;
         LocalOutputCalc = (uint8)((Rco*100)/31);
         VEMS_vidSET(AltCtl_rAltCycOpRate,LocalOutputCalc);


         I_Rot = (uint8)((u8LocalBuffer[1]) & 0x3F);
         LocalOutputCalc = (uint8)(I_Rot << 1);
         VEMS_vidSET(AltCtl_iAlt,LocalOutputCalc);
      }
      else
      {
         VEMS_vidGET(AltCtl_iAlt, u8LocalAltCtl_iAlt);
         VEMS_vidGET(AltCtl_rAltCycOpRate,u8LocalAltCtl_rAltCycOpRate);

         u8LocalAltCtl_iAlt = (uint8)MATHSRV_udtMIN(u8LocalAltCtl_iAlt, 160);
         u8LocalAltCtl_rAltCycOpRate = (uint8)MATHSRV_udtMIN
                                    (u8LocalAltCtl_rAltCycOpRate, 100);
         VEMS_vidSET(AltCtl_iAlt, u8LocalAltCtl_iAlt);
         VEMS_vidSET(AltCtl_rAltCycOpRate,u8LocalAltCtl_rAltCycOpRate);
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidEtatAlt2                                          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ReceiveMessage(argin uint16 Id_msg, argout uint8         */
/* *Ptr_msg);                                                                 */
/*  input st111 IsLin_stLin;                                                  */
/*  input boolean ISLIN_Freeze;                                               */
/*  input uint8 AltCtl_idxAltProv;                                            */
/*  input uint8 IsLin_idxAltClas;                                             */
/*  input uint8 Fnr;                                                          */
/*  input st112 Class;                                                        */
/*  output uint8 AltCtl_idxAltProv;                                           */
/*  output uint8 IsLin_idxAltClas;                                            */
/*  output uint8 Fnr;                                                         */
/*  output st112 Class;                                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidEtatAlt2(void)
{
   boolean  bLocalFRM_bInhEtat_Alt2;
   uint8    u8LocalBuffer[ISLIN_u8RX_BUFFER_LENGTH];
   uint8    u8LocalIsLin_stLin;
   uint8    u8LocalFnr;
   uint8    u8LocalClass;
   uint8    u8LocalAltCtl_idxAltProv;
   uint8    u8LocalIsLin_idxAltClas;


   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);
   bLocalFRM_bInhEtat_Alt2 = GDGAR_bGetFRM(FRM_FRM_INHETAT_ALT2);
   if (bLocalFRM_bInhEtat_Alt2 != 0)
   {
      VEMS_vidSET(AltCtl_idxAltProv,0);
      VEMS_vidSET(IsLin_idxAltClas,0);

   }
   else
   {
      ReceiveMessage(SN_ETAT_ALT2_RESPONSE, u8LocalBuffer);

      if ((ISLIN_Freeze != 0) || (u8LocalIsLin_stLin != ISLIN_NORMAL))
      {
         VEMS_vidGET(AltCtl_idxAltProv,u8LocalAltCtl_idxAltProv);
         VEMS_vidGET(IsLin_idxAltClas,u8LocalIsLin_idxAltClas);

         u8LocalFnr = (uint8)MATHSRV_udtMIN(u8LocalAltCtl_idxAltProv, 10);
         u8LocalClass = (uint8)MATHSRV_udtMIN(u8LocalIsLin_idxAltClas, 100);

         VEMS_vidSET(AltCtl_idxAltProv,u8LocalFnr);
         VEMS_vidSET(IsLin_idxAltClas,u8LocalClass);
      }
      else
      {
         Fnr = (uint8)((u8LocalBuffer[0]) & 0x07);
         Class = (uint8)(((u8LocalBuffer[0]) & 0xF8) >> 3);

         VEMS_vidSET(AltCtl_idxAltProv,Fnr);
         VEMS_vidSET(IsLin_idxAltClas,Class);
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidDiagEna                                           */
/* !Description :  This functions checks conditions to enable the diag and    */
/*                 calls GDGAR functions                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean AltCtl_dftHiTAlt;                                           */
/*  input boolean AltCtl_dftMecAlt;                                           */
/*  input boolean AltCtl_dftElecAlt;                                          */
/*  input st08 Power_conditions_state;                                        */
/*  input boolean AltCtl_dftComAlt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidDiagEna(void)
{
   boolean  bLocalDiagEna;
   boolean  Local_bDefault;
   uint8    u8LocalVehicle_active_state;
   uint8    u8LocalPower_conditions_state;


   VEMS_vidGET(Vehicle_active_state,u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      bLocalDiagEna = 1;
   }
   else
   {
      bLocalDiagEna = 0;
   }

   VEMS_vidGET(AltCtl_dftHiTAlt, Local_bDefault);
   GDGAR_vidGdu(GD_DFT_HITALT_ALTCTL,
                Local_bDefault,
                bLocalDiagEna,
                DIAG_DISPO);

   VEMS_vidGET(AltCtl_dftMecAlt, Local_bDefault);
   GDGAR_vidGdu(GD_DFT_MECAALT_ALTCTL,
                Local_bDefault,
                bLocalDiagEna,
                DIAG_DISPO);

   VEMS_vidGET(AltCtl_dftElecAlt, Local_bDefault);
   GDGAR_vidGdu(GD_DFT_ELECALT_ALTCTL,
                Local_bDefault,
                bLocalDiagEna,
                DIAG_DISPO);

   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   if (u8LocalPower_conditions_state == POWER_ON)
   {
      bLocalDiagEna = 1;
   }
   else
   {
      bLocalDiagEna = 0;
   }

   VEMS_vidGET(AltCtl_dftComAlt, Local_bDefault);
   GDGAR_vidGdu(GD_DFT_COMALT_ALTCTL,
                Local_bDefault,
                bLocalDiagEna,
                DIAG_DISPO);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidWakeUp                                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GoToMode(argin uint8 NetId, argin uint8 NewMode);        */
/*  input st111 IsLin_stLin;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidWakeUp(void)
{
   uint8  u8LocalIsLin_stLin;


   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);
   if (u8LocalIsLin_stLin == ISLIN_WAKEUP)
   {
      GoToMode(N_LIN_E, Awake);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidShutDown                                          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GoToMode(argin uint8 NetId, argin uint8 NewMode);        */
/*  input st111 IsLin_stLin;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidShutDown(void)
{
   uint8  u8LocalIsLin_stLin;


   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);
   if (u8LocalIsLin_stLin == ISLIN_SHUTDOWN)
   {
      GoToMode(N_LIN_E, BusSleep);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ISLIN_vidLinStatus                                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_001.01                                     */
/*                 VEMS_R_09_03043_002.01                                     */
/*                 VEMS_R_09_03043_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void vidLinStatusInit();                                      */
/*  extf argret void vidLinStatusWakeUp();                                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void vidLinStatusNormal();                                    */
/*  extf argret void vidLinStatusShut();                                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Clef_de_contact;                                            */
/*  input st111 IsLin_stLin;                                                  */
/*  input boolean Clef_de_contact_prev;                                       */
/*  output boolean Clef_de_contact_FallEdge;                                  */
/*  output boolean Clef_de_contact_prev;                                      */
/*  output st111 IsLin_stLin;                                                 */
/*  output uint8 IsLin_nbSDFrameSent;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ISLIN_vidLinStatus(void)
{
   boolean  bLocalClef_de_contact;
   uint8    u8LocalIsLin_stLin;


   VEMS_vidGET(Clef_de_contact,bLocalClef_de_contact);
   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);

   if ((Clef_de_contact_prev != 0) && (bLocalClef_de_contact == 0))
   {
      Clef_de_contact_FallEdge = 1;
   }
   else
   {
      Clef_de_contact_FallEdge = 0;
   }
   Clef_de_contact_prev = 	bLocalClef_de_contact;

   switch(u8LocalIsLin_stLin)
   {
   case ISLIN_INIT:
      vidLinStatusInit();
      break;
   case ISLIN_WAKEUP:
      vidLinStatusWakeUp();
      break;
   case ISLIN_WAKEUPDONE:
      VEMS_vidSET(IsLin_stLin,ISLIN_NORMAL);
      break;
   case ISLIN_NORMAL:
      vidLinStatusNormal();
      break;
   case ISLIN_SHUTDOWNRQ:
      VEMS_vidSET(IsLin_stLin,ISLIN_SHUTDOWN);
      IsLin_nbSDFrameSent = 1;
      break;
   case ISLIN_SHUTDOWN:
      vidLinStatusShut();
      break;
   default:
      SWFAIL_vidSoftwareErrorHook();
      VEMS_vidSET(IsLin_stLin,ISLIN_INIT);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  vidSendTrame                                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_09_03043_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void vidCmdeAltScale();                                       */
/*  extf argret void SendMessage(argin uint16 Id_msg, argio uint8 *Ptr_msg);  */
/*  input uint16 VoltCtl_uReqProdElec;                                        */
/*  input uint16 VoltCtl_IexctMax;                                            */
/*  input uint8 VoltCtl_AltPrgChDi_nEng;                                      */
/*  input boolean ISLIN_Freeze;                                               */
/*  input uint8 V_Reg;                                                        */
/*  input uint8 VoltCtl_tiAltPrgCh_Rescaled;                                  */
/*  input uint8 T_Lrc;                                                        */
/*  input uint8 Lrc_Off_On;                                                   */
/*  input uint8 I_Lim;                                                        */
/*  output uint8 V_Reg;                                                       */
/*  output uint8 T_Lrc;                                                       */
/*  output uint8 Lrc_Off_On;                                                  */
/*  output uint8 I_Lim;                                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void vidSendTrame(void)
{
   boolean  bLocalFRM_bInhuReqProdElec;
   boolean  bLocalFRM_bInhtiAltPrgCh;
   boolean  bLocalFRM_bInhAltPrgChDi_nEng;
   boolean  bLocalFRM_bInhIexctMax;
   uint8    u8LocalBuffer[ISLIN_u8TX_BUFFER_LENGTH];
   sint16   s16Temp;
   sint16   s16LocalTemp;
   uint16   u16Local_uReqProdElec;
   uint16   u16Local_IexctMax;
   uint8    u8Local_AltPrgChDi_nEng;


   VEMS_vidGET(VoltCtl_uReqProdElec, u16Local_uReqProdElec);
   VEMS_vidGET(VoltCtl_IexctMax, u16Local_IexctMax);
   VEMS_vidGET(VoltCtl_AltPrgChDi_nEng, u8Local_AltPrgChDi_nEng);

   u8LocalBuffer[3] = 0;

   bLocalFRM_bInhuReqProdElec = GDGAR_bGetFRM(FRM_FRM_INHUREQPRODELEC);
   if ((bLocalFRM_bInhuReqProdElec != 0) || (ISLIN_Freeze != 0))
   {
      u8LocalBuffer[0] = V_Reg;
   }
   else
   {
      s16LocalTemp = (sint16)((u16Local_uReqProdElec/10) - 106);
      V_Reg = (uint8)MATHSRV_udtCLAMP(s16LocalTemp, 0, 54);
      u8LocalBuffer[0] = V_Reg;
   }

   vidCmdeAltScale ();
   bLocalFRM_bInhtiAltPrgCh = GDGAR_bGetFRM(FRM_FRM_INHTIALTPRGCH);
   if (bLocalFRM_bInhtiAltPrgCh != 0)
   {
      T_Lrc = 5 ;
   }
   else
   {
      if (ISLIN_Freeze != 0)
      {
         /* Do Nothing */
      }
      else
      {
         s16Temp = (sint16)((VoltCtl_tiAltPrgCh_Rescaled * 5) - 8);
         s16Temp = (sint16)MATHSRV_udtMAX(s16Temp,0);
         s16Temp = (sint16)((s16Temp *15) / 256);
         T_Lrc = (uint8)MATHSRV_udtMIN(s16Temp, 15);
      }
   }

   bLocalFRM_bInhAltPrgChDi_nEng = GDGAR_bGetFRM(FRM_FRM_INHALTPRGCHDI_NENG);
   if (bLocalFRM_bInhAltPrgChDi_nEng != 0)
   {
      Lrc_Off_On = 8;
   }
   else
   {
      if (ISLIN_Freeze != 0)
      {
      }
      else
      {
         Lrc_Off_On = (uint8)MATHSRV_udtMIN( u8Local_AltPrgChDi_nEng, 15);
      }
   }
   u8LocalBuffer[1] = (uint8)((T_Lrc & 0x0F) + ((Lrc_Off_On & 0x0F) << 4));


   bLocalFRM_bInhIexctMax = GDGAR_bGetFRM(FRM_FRM_INHIEXCTMAX);
   if (bLocalFRM_bInhIexctMax != 0)
   {
      u16Local_IexctMax = 0x00;
   }
   else if (ISLIN_Freeze != 0)
   {
      u16Local_IexctMax = I_Lim;
   }
   else
   {
      u16Local_IexctMax = (uint16)(u16Local_IexctMax >> 2) ;
   }

   if ((u16Local_IexctMax <= 0x08) && (u16Local_IexctMax >= 0x01))
   {
      u16Local_IexctMax = 0x08;
   }
   I_Lim = (uint8)MATHSRV_udtMIN(u16Local_IexctMax, 31);
   u8LocalBuffer[2] = (uint8)(I_Lim & 0x1F);

   SendMessage(SN_CDE_ALT, u8LocalBuffer);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  vidCmdeAltScale                                            */
/* !Number      :  FCT1.11                                                    */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 VoltCtl_tiAltPrgCh;                                           */
/*  output uint8 VoltCtl_tiAltPrgCh_Rescaled;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void vidCmdeAltScale(void)
{
   uint8 u8Local_tiAltPrgCh;


   VEMS_vidGET(VoltCtl_tiAltPrgCh, u8Local_tiAltPrgCh);

   switch(u8Local_tiAltPrgCh)
   {
   case 0:
      VoltCtl_tiAltPrgCh_Rescaled = 0;
      break;
   case 1:
      VoltCtl_tiAltPrgCh_Rescaled = 1;
      break;
   case 2:
      VoltCtl_tiAltPrgCh_Rescaled = 2;
      break;
   case 3:
      VoltCtl_tiAltPrgCh_Rescaled = 3;
      break;
   case 4:
      VoltCtl_tiAltPrgCh_Rescaled = 4;
      break;
   case 5:
      VoltCtl_tiAltPrgCh_Rescaled = 8;
      break;
   case 6:
      VoltCtl_tiAltPrgCh_Rescaled = 12;
      break;
   case 7:
      VoltCtl_tiAltPrgCh_Rescaled = 16;
      break;
   case 8:
      VoltCtl_tiAltPrgCh_Rescaled = 20;
      break;
   case 9:
      VoltCtl_tiAltPrgCh_Rescaled = 24;
      break;
   case 10:
      VoltCtl_tiAltPrgCh_Rescaled = 28;
      break;
   case 11:
      VoltCtl_tiAltPrgCh_Rescaled = 32;
      break;
   case 12:
      VoltCtl_tiAltPrgCh_Rescaled = 36;
      break;
   case 13:
      VoltCtl_tiAltPrgCh_Rescaled = 40;
      break;
   case 14:
      VoltCtl_tiAltPrgCh_Rescaled = 48;
      break;
   case 15:
      VoltCtl_tiAltPrgCh_Rescaled = 60;
      break;
   default:
      break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  vidLinStatusInit                                           */
/* !Number      :  FCT1.12                                                    */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact;                                            */
/*  output st111 IsLin_stLin;                                                 */
/*  output uint8 IsLin_nbWUFrameSent;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void vidLinStatusInit(void)
{
   boolean  bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (bLocalClef_de_contact != 0)
   {
      VEMS_vidSET(IsLin_stLin,ISLIN_WAKEUP);
      IsLin_nbWUFrameSent = 1;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  vidLinStatusWakeUp                                         */
/* !Number      :  FCT1.13                                                    */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact_FallEdge;                                   */
/*  input uint8 IsLin_nbWUFrameSent;                                          */
/*  input uint8 IsLin_WUConfFrameNb;                                          */
/*  output st111 IsLin_stLin;                                                 */
/*  output uint8 IsLin_nbSDFrameSent;                                         */
/*  output uint8 IsLin_nbWUFrameSent;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void vidLinStatusWakeUp(void)
{
   if (Clef_de_contact_FallEdge != 0)
   {
      VEMS_vidSET(IsLin_stLin,ISLIN_SHUTDOWN);
      IsLin_nbSDFrameSent = 1;
   }
   else
   {
      if (IsLin_nbWUFrameSent >= IsLin_WUConfFrameNb)
      {
         VEMS_vidSET(IsLin_stLin, ISLIN_WAKEUPDONE);
      }
      else
      {
         IsLin_nbWUFrameSent = (uint8)(IsLin_nbWUFrameSent + 1);
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  vidLinStatusNormal                                         */
/* !Number      :  FCT1.14                                                    */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact_FallEdge;                                   */
/*  output st111 IsLin_stLin;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void vidLinStatusNormal(void)
{
   if (Clef_de_contact_FallEdge != 0)
   {

      VEMS_vidSET(IsLin_stLin,ISLIN_SHUTDOWNRQ);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  vidLinStatusShut                                           */
/* !Number      :  FCT1.15                                                    */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 IsLin_nbSDFrameSent;                                          */
/*  input uint8 IsLin_SDConfFrameNb;                                          */
/*  output st111 IsLin_stLin;                                                 */
/*  output uint8 IsLin_nbWUFrameSent;                                         */
/*  output uint8 IsLin_nbSDFrameSent;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void vidLinStatusShut(void)
{
   boolean  bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (bLocalClef_de_contact != 0)
   {
      VEMS_vidSET(IsLin_stLin,ISLIN_WAKEUP);
      IsLin_nbWUFrameSent = 1;
   }
   else
   {
      if (IsLin_nbSDFrameSent >= IsLin_SDConfFrameNb)
      {
         VEMS_vidSET(IsLin_stLin,ISLIN_INIT);
      }
      else
      {
         IsLin_nbSDFrameSent = (uint8)(IsLin_nbSDFrameSent + 1);
      }
   }
}

#define ISLIN_STOP_SEC_CODE
#include "Memmap.h"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion of MemMap.h file  */
/*-------------------------------- end of file -------------------------------*/
/*QAC Warning Msg(2:0862): Due to Inclusion of MemMap.h                    */
