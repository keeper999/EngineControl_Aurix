/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COMSTMNG                                                */
/* !Description     : COMSTMNG component                                      */
/*                                                                            */
/* !Module          : COMSTMNG                                                */
/* !Description     : GESTION DES PHASES DE VIE DE LA COMMUNICATION           */
/*                                                                            */
/* !File            : COMSTMNG_FCT1.C                                         */
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
/*   1 / COMSTMNG_vidReset                                                    */
/*   2 / COMSTMNG_vidIntegraElectronique                                      */
/*   3 / COMSTMNG_vidPowerlatch                                               */
/*   4 / COMSTMNG_vidCanIsLifeCyclePhases                                     */
/*   5 / COMSTMNG_vidWakeUp                                                   */
/*   6 / COMSTMNG_vidShutDown                                                 */
/*   7 / VidMainFunction_StackCom_2_5MS                                       */
/*   8 / VidMainFunction_StackCom_10MS                                        */
/*   9 / VidMainFunction_StackCom_20MS                                        */
/*   10 / COMSTMNG_vidInitOutput                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6832731 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/COMSTMNG/COMSTMNG_FCT1.c_v        $*/
/* $Revision::   1.5          $$Author::   croche2     $$Date::   14 Oct 2014$*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "COMSTMNG.h"
#include "COMSTMNG_L.h"
#include "COMSTMNG_im.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidReset                                          */
/* !Description :  Fonction d'initialisation des différentes couches de la COM*/
/*                 stack pour l’activation de la  communication via le réseau */
/*                 CAN IS                                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Can_Init(argin const Lin_ConfigType * Config);           */
/*  extf argret void Can_DisableControllerInterrupts(argin uint8 CAN_Channel);*/
/*  extf argret void Lin_Init(uint16 *Config);                                */
/*  extf argret void ComM_Init();                                             */
/*  extf argret void CanIf_Init(uint16 *pu16Aks);                             */
/*  extf argret void LinIf_Init(uint16 *pu16Lin);                             */
/*  extf argret void LinSM_Init();                                            */
/*  extf argret void Com_Init(uint16 *pu16Com);                               */
/*  extf argret void PduR_Init(uint16 *pu16Pdu);                              */
/*  extf argret void CanSM_Init(uint16 *pu16Can);                             */
/*  extf argret void CanTp_Init(argin const CanTp_ConfigType *CfgPtr);        */
/*  extf argret void ComM_CommunicationAllowed(uint8 u8ComMChannel, boolean   */
/* bEna);                                                                     */
/*  extf argret void ComM_RequestComMode(uint8 u8ComMUser, uint8 u8FullCom);  */
/*  extf argret void Com_ClearIpduGroupVector(uint16 u16PduGroup);            */
/*  extf argret void Com_SetIpduGroup(uint16 u16PduGroup, uint8 u8ComIP,      */
/* boolean bEnable);                                                          */
/*  extf argret void Com_ReceptionDMControl(uint16 u16PduGroup);              */
/*  extf argret void Com_IpduGroupControl(uint16 u16PduGroupVector, boolean   */
/* bTest);                                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Com_IpduGroupVector au8eIPduGroupVector;

void COMSTMNG_vidReset(void)
{
   /* Call of init module of stack comm */
   Can_Init(&Can_17_MCanP_ConfigRoot[0]);
   /*Can_DisableControllerInterrupts(2);  CAN_DEVAID Mode Interrupt*/
   Can_DisableControllerInterrupts(0); /* CAN_2: LAS */
   Can_DisableControllerInterrupts(1); /* CAN_1: I/S */
   Can_DisableControllerInterrupts(3); /* CAN_3: Hybrid */
   Lin_Init(&Lin_ConfigRoot[0]);
   ComM_Init();
   CanIf_Init(&CanIfInitCfg);
   LinIf_Init(&LinIf_kstrePBConfig);
   LinSM_Init();

   Com_Init(&Com_kstrePBConfig0);
   PduR_Init(&PduRRoutingTables);

   CanSM_Init(&CanSMConfiguration);
   CanTp_Init(CanTp_akpkstreCanTpConfig[0]);
 
   
   /* Sets all bits of the  au8eIPduGroupVector to 0*/
   Com_ClearIpduGroupVector(au8eIPduGroupVector);

   /* Indicate to ComM that communication is allowed */
   /* in Cannel CanIS, Ccp Devaid and Lin_1          */
   ComM_CommunicationAllowed(ComM_u8ComMChannel_CanIS, TRUE);
   ComM_CommunicationAllowed(ComM_u8ComMChannel_Cpp_Devaid, TRUE);
   ComM_CommunicationAllowed(ComM_u8ComMChannel_Lin_1, TRUE);

   /* Requesting Full Communication mode by Can User  */
   ComM_RequestComMode(ComM_u8ComMUser_Can, COMM_FULL_COMMUNICATION);

   /* Set the bit of the au8eIPduGroupVector that corresponds to I-PDU group*/
    Com_SetIpduGroup(au8eIPduGroupVector,Com_CMM_EB_atmo_Euro_6_2_redundant_sig_RxPduGroup,1);
    Com_SetIpduGroup(au8eIPduGroupVector,Com_TempPduGroupFor_Diag,1);
    Com_SetIpduGroup(au8eIPduGroupVector,Com_TxPduGroup_Electronic_Integration,1);
    Com_SetIpduGroup(au8eIPduGroupVector,Com_TxPduGroup_Normal_Mode,1);
    Com_SetIpduGroup(au8eIPduGroupVector,Com_TxPduGroup_Power_Latch,1);

   /* Enables I-PDU group Deadline Monitoring.  */
   Com_ReceptionDMControl(au8eIPduGroupVector);

   /* Starts  I-PDU group */
   Com_IpduGroupControl(au8eIPduGroupVector, TRUE);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidIntegraElectronique                            */
/* !Description :  Fontion permettant la circulation d'un ensemble de trames  */
/*                 prédéfini sur le bus pendant la phase d’intégration        */
/*                 électronique.                                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Com_SetIpduGroup(uint16 u16PduGroup, uint8 u8ComIP,      */
/* boolean bEnable);                                                          */
/*  extf argret void Com_IpduGroupControl(uint16 u16PduGroupVector, boolean   */
/* bTest);                                                                    */
/*  input boolean Ext_bElecItgrReq;                                           */
/*  input boolean Ext_bElecItgrReq_prev;                                      */
/*  output boolean Ext_bElecItgrReq_prev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidIntegraElectronique(void)
{
   boolean bLocalExt_bElecItgrReq;


   VEMS_vidGET(Ext_bElecItgrReq, bLocalExt_bElecItgrReq);
   if (Ext_bElecItgrReq_prev != bLocalExt_bElecItgrReq)
   {
      if (bLocalExt_bElecItgrReq != 0)
      {
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Power_Latch, 0);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Normal_Mode, 0);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TempPduGroupFor_Diag, 0);
      }
      else
      {
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Power_Latch, 1);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Normal_Mode, 1);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TempPduGroupFor_Diag, 1);
      }
      Com_IpduGroupControl(au8eIPduGroupVector,TRUE);
   }
   Ext_bElecItgrReq_prev = bLocalExt_bElecItgrReq ;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidPowerlatch                                     */
/* !Description :  Fontion permettant la circulation d'un ensemble de trames  */
/*                 prédéfini sur le bus pendant la phase de Power-latch.      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Com_SetIpduGroup(uint16 u16PduGroup, uint8 u8ComIP,      */
/* boolean bEnable);                                                          */
/*  extf argret void Com_IpduGroupControl(uint16 u16PduGroupVector, boolean   */
/* bTest);                                                                    */
/*  input st09 Rcd_power_state;                                               */
/*  input uint8 Rcd_power_state_prev;                                         */
/*  output uint8 Rcd_power_state_prev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidPowerlatch(void)
{
   uint8 u8LocalRcd_power_state;


   VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
   if (Rcd_power_state_prev != u8LocalRcd_power_state)
   {
      if (u8LocalRcd_power_state == RCD_POWER_LATCH)
      {
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Electronic_Integration, 0);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Normal_Mode, 0);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TempPduGroupFor_Diag, 0);
      }
      else
      {
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Electronic_Integration, 1);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TxPduGroup_Normal_Mode, 1);
         Com_SetIpduGroup(au8eIPduGroupVector, Com_TempPduGroupFor_Diag, 1);
      }
      Com_IpduGroupControl(au8eIPduGroupVector,TRUE);
   }
   Rcd_power_state_prev = u8LocalRcd_power_state;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidCanIsLifeCyclePhases                           */
/* !Description :  Afin de gérer la communication CAN pendant la phase        */
/*                 d’intégration électronique et de power-latch, il suffit de */
/*                 positionner les PduGroup des trames qui ne doivent plus    */
/*                 être émises à 0.                                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMSTMNG_vidIntegraElectronique();                       */
/*  extf argret void COMSTMNG_vidPowerlatch();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidCanIsLifeCyclePhases(void)
{
   COMSTMNG_vidIntegraElectronique();
   COMSTMNG_vidPowerlatch();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidWakeUp                                         */
/* !Description :  Quand l’automate est à l’état WAKEUP, on demande le passage*/
/*                 du réseau LIN en mode FULL_COM.                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ComM_RequestComMode(uint8 u8ComMUser, uint8 u8FullCom);  */
/*  input st111 IsLin_stLin;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidWakeUp(void)
{
   uint8  u8LocalIsLin_stLin;


   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);
   if (u8LocalIsLin_stLin == ISLIN_WAKEUP)
   {
      ComM_RequestComMode(ComM_u8ComMUser_Lin, COMM_FULL_COMMUNICATION);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidShutDown                                       */
/* !Description :  Quand l’automate est à l’état SHUTDOWN, on demande le      */
/*                 passage du réseau LIN en mode NO_COM.                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ComM_RequestComMode(uint8 u8ComMUser, uint8 u8FullCom);  */
/*  input st111 IsLin_stLin;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidShutDown(void)
{
   uint8  u8LocalIsLin_stLin;


   VEMS_vidGET(IsLin_stLin, u8LocalIsLin_stLin);
   if (u8LocalIsLin_stLin == ISLIN_SHUTDOWN)
   {
      ComM_RequestComMode(ComM_u8ComMUser_Lin, COMM_NO_COMMUNICATION);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VidMainFunction_StackCom_2_5MS                             */
/* !Description :  Call Main function: task OSTSK_C_2_5MS_1                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Can_MainFunction_Write();                                */
/*  extf argret void Can_MainFunction_Read();                                 */
/*  extf argret void Can_MainFunction_BusOff();                               */
/*  extf argret void Com_MainFunctionRouteSignals();                          */
/*  extf argret void Com_MainFunctionRx();                                    */
/*  extf argret void Com_MainFunctionTx();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VidMainFunction_StackCom_2_5MS(void)
{
   /* Call Main function: task OSTSK_C_2_5MS_1 */
   Can_MainFunction_Write();
   Can_MainFunction_Read();
   Can_MainFunction_BusOff();
   Com_MainFunctionRouteSignals();
   Com_MainFunctionRx();
   Com_MainFunctionTx();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VidMainFunction_StackCom_5MS                               */
/* !Description :  Call Main function: task OSTSK_C_5MS_4                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LinIf_MainFunction();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VidMainFunction_StackCom_5MS(void)
{
   /* Call Main function: task OSTSK_C_5MS_4 */
   LinIf_MainFunction();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VidMainFunction_StackCom_10MS                              */
/* !Description :  Call Main function: task OSTSK_C_10MS_7                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CanSM_MainFunction();                                    */
/*  extf argret void CanTp_MainFunction();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VidMainFunction_StackCom_10MS(void)
{
   /* Call Main function: task OSTSK_C_10MS_7 */
   CanSM_MainFunction();
   CanTp_MainFunction();
   LinSM_MainFunction();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VidMainFunction_StackCom_20MS                              */
/* !Description :  Call Main function: task OSTSK_C_20MS_5                    */
/* !Number      :  FCT1.10                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ComM_MainFunction_000();                                 */
/*  extf argret void ComM_MainFunction_001();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VidMainFunction_StackCom_20MS(void)
{
   /* Call Main function: task OSTSK_C_20MS_5 */
   ComM_MainFunction_000();
   ComM_MainFunction_001();
   ComM_MainFunction_002();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COMSTMNG_vidInitOutput                                     */
/* !Description :  Initialisation des internes et des sorties                 */
/* !Number      :  FCT1.11                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st09 Rcd_power_state;                                               */
/*  input boolean Ext_bElecItgrReq;                                           */
/*  input boolean Clef_de_contact;                                            */
/*  output st111 IsLin_stLin;                                                 */
/*  output uint8 Rcd_power_state_prev;                                        */
/*  output boolean Ext_bElecItgrReq_prev;                                     */
/*  output boolean COMSTMNG_bClefDeContactPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COMSTMNG_vidInitOutput(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalExt_bElecItgrReq;
   uint8   u8LocalRcd_power_state;


   VEMS_vidSET(IsLin_stLin, ISLIN_INIT);
   COMSTMNG_LinCurrentMode = COMM_NO_COMMUNICATION;

   VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
   Rcd_power_state_prev = u8LocalRcd_power_state;

   VEMS_vidGET(Ext_bElecItgrReq, bLocalExt_bElecItgrReq);
   Ext_bElecItgrReq_prev = bLocalExt_bElecItgrReq;

   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   COMSTMNG_bClefDeContactPrev = bLocalClef_de_contact;
}

/*------------------------------- end of file --------------------------------*/