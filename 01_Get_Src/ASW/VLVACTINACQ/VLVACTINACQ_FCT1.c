/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINACQ                                             */
/* !Description     : VLVACTINACQ component.                                  */
/*                                                                            */
/* !Module          : VLVACTINACQ                                             */
/* !Description     : ACQUISITION DU DECALAGE ET CALCUL DE LA VITESSE DE      */
/*                    DECALAGE DE LA VVT D'ADMISSION                          */
/*                                                                            */
/* !File            : VLVACTINACQ_FCT1.C                                      */
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
/*   1 / VLVACTINACQ_vidInitOutput                                            */
/*   2 / VLVACTINACQ_vidInitPannes                                            */
/*   3 / VLVACTINACQ_vidInit                                                  */
/*   4 / VLVACTINACQ_vidCurrentShift                                          */
/*   5 / VLVACTINACQ_vidCurrentVelocity                                       */
/*   6 / VLVACTINACQ_vidCamTargetState                                        */
/*   7 / VLVACTINACQ_vidIntakeResynchro                                       */
/*   8 / VLVACTINACQ_vidIntakePmhDiag                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6588653 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINACQ/VLVACT$*/
/* $Revision::   1.24     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINACQ.h"
#include "VLVACTINACQ_L.h"
#include "VLVACTINACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidInitOutput                                  */
/* !Description :  Initialisation des variables de sortie                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Vxx_rel_in_vvt_mes;                                         */
/*  output uint16 Vta_intake_tooth_time;                                      */
/*  output sint16 Vta_intake_filt_velocity;                                   */
/*  output uint8 Vta_intake_tooth_counter;                                    */
/*  output uint16 Ext_agCmInMes;                                              */
/*  output boolean Ext_bVoltSenCmIn;                                          */
/*  output uint8 Ext_ctEdgeCmIn;                                              */
/*  output uint16 Ext_nEngCmInMes;                                            */
/*  output uint16 Ext_tiPatCmIn;                                              */
/*  output uint16 VlvAct_nEngInCmFil;                                         */
/*  output uint16 VLVACTINACQ_u16EngInCmPrev1;                                */
/*  output uint16 VLVACTINACQ_u16EngInCmPrev2;                                */
/*  output uint16 VLVACTINACQ_u16EngInCmPrev3;                                */
/*  output uint8 VLVACTINACQ_u8VehActvStatePrev;                              */
/*  output uint16 Ext_agCmInMesTbl[4];                                        */
/*  output uint16 VlvAct_nEngInCm;                                            */
/*  output uint16 VLVACTINACQ_u16RelInVvtMesPrev;                             */
/*  output boolean Vta_intake_velocity_set;                                   */
/*  output sint16 Vta_intake_camshaft_velocity;                               */
/*  output sint16 Vta_intake_camshaft_velocity_1;                             */
/*  output sint32 VLVACTINACQ_s32FrstOrderFiltMem1;                           */
/*  output sint32 VLVACTINACQ_s32FrstOrderFiltMem2;                           */
/*  output boolean VLVACTINACQ_bnEngInTDCDiagThd;                             */
/*  output boolean VLVACTINACQ_bnEngInORngShiftThd;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidInitOutput(void)
{
   VEMS_vidSET(Vxx_rel_in_vvt_mes, 0);
   VEMS_vidSET(Vta_intake_tooth_time, 0);
   VEMS_vidSET(Vta_intake_filt_velocity, 0);
   VEMS_vidSET(Vta_intake_tooth_counter, 0);
   VEMS_vidSET(Ext_agCmInMes, 0);
   VEMS_vidSET(Ext_bVoltSenCmIn, 0);
   VEMS_vidSET(Ext_ctEdgeCmIn, 0);
   VEMS_vidSET(Ext_nEngCmInMes, 0);
   VEMS_vidSET(Ext_tiPatCmIn, 0);
   VEMS_vidSET(VlvAct_nEngInCmFil, 0);
   VLVACTINACQ_u16EngInCmPrev1 = 0;
   VLVACTINACQ_u16EngInCmPrev2 = 0;
   VLVACTINACQ_u16EngInCmPrev3 = 0;
   VLVACTINACQ_u8VehActvStatePrev = VS_STALL;
   Ext_agCmInMesTbl[0] = 0;
   Ext_agCmInMesTbl[1] = 0;
   Ext_agCmInMesTbl[2] = 0;
   Ext_agCmInMesTbl[3] = 0;
   VlvAct_nEngInCm = 0;
   VLVACTINACQ_u16RelInVvtMesPrev = 0;
   Vta_intake_velocity_set = 0;
   Vta_intake_camshaft_velocity = 0;
   Vta_intake_camshaft_velocity_1 = 0;
   VLVACTINACQ_s32FrstOrderFiltMem1 = 0;
   VLVACTINACQ_s32FrstOrderFiltMem2 = 0;
   VLVACTINACQ_bnEngInTDCDiagThd = 0;
   VLVACTINACQ_bnEngInORngShiftThd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidInitPannes                                  */
/* !Description :  Les pannes VVT présentes sont initialisées sur clé off/on  */
/*                 afin de ne pas rester figées entre le clé on et le         */
/*                 démarrage du moteur.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean VlvAct_bDgoMissToothVlvActIn;                              */
/*  output boolean VlvAct_bDgoORngShiftVlvActIn;                              */
/*  output boolean VlvAct_bDgoORngSpdVlvActIn;                                */
/*  output boolean VlvAct_bDgoTDCDiagVlvActIn;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidInitPannes(void)
{
   VlvAct_bDgoMissToothVlvActIn = 0;
   VlvAct_bDgoORngShiftVlvActIn = 0;
   VlvAct_bDgoORngSpdVlvActIn = 0;
   VlvAct_bDgoTDCDiagVlvActIn = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidInit                                        */
/* !Description :  Ce bloc initialise, sur front montant de                   */
/*                 Moteur_synchronisé, les variables suivantes : -            */
/*                 Vta_intake_camshaft_shift et Vta_intake_tooth_counter      */
/*                 (compteur de dents )                                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vta_intake_camshaft_shift_def;                               */
/*  input boolean VlvAct_bInSelTypIniCntCmTooth_C;                            */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input boolean Vta_intake_camshaft_level;                                  */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  output uint16 Vxx_rel_in_vvt_mes;                                         */
/*  output sint16 Vta_intake_camshaft_shift;                                  */
/*  output uint8 Vta_intake_tooth_counter;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidInit(void)
{
   uint8  u8LocalEng_noCmbCyl;
   uint8  u8LocalVtaIntToothCount;
   uint16 u16LocalVxx_rel_in_vvt_mes;
   sint16 s16LocalCalc;


   u16LocalVxx_rel_in_vvt_mes =
      (uint16)MATHSRV_udtMIN(Vta_intake_camshaft_shift_def, 1066);
   VEMS_vidSET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);

   Vta_intake_camshaft_shift =
      (sint16)MATHSRV_udtMIN(Vta_intake_camshaft_shift_def, 7679);

   if (VlvAct_bInSelTypIniCntCmTooth_C != 0)
   {
      VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
      s16LocalCalc = (sint16)(u8LocalEng_noCmbCyl - 1);
   }
   else
   {
      if (Vta_intake_camshaft_level != 0)
      {
         s16LocalCalc = 0;
      }
      else
      {
         s16LocalCalc = (sint16)(Vta_intake_tooth_nb - 1);
      }
   }
   u8LocalVtaIntToothCount = (uint8)MATHSRV_udtCLAMP(s16LocalCalc, 0, 3);
   VEMS_vidSET(Vta_intake_tooth_counter, u8LocalVtaIntToothCount);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidCurrentShift                                */
/* !Description :  Processus de mesure du décalage                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACQ_vidIntakeRisingCapt();                       */
/*  extf argret void VLVACTINACQ_vidIntakeCaptCalc();                         */
/*  extf argret void VLVACTINACQ_vidIntakeDiagnosis();                        */
/*  input boolean VlvAct_bMonRunORngShiftVlvActIn;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidCurrentShift(void)
{
   VLVACTINACQ_vidIntakeRisingCapt();
   VLVACTINACQ_vidIntakeCaptCalc();

   if(VlvAct_bMonRunORngShiftVlvActIn != 0)
   {
      VLVACTINACQ_vidIntakeDiagnosis();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidCurrentVelocity                             */
/* !Description :  Fonction de calcul de la valeur de la vitesse de décalage  */
/*                 de l’AAC d’admission                                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACQ_vidCurrentVelo();                            */
/*  input boolean VlvAct_bMonRunORngSpdVlvActIn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidCurrentVelocity(void)
{
   if(VlvAct_bMonRunORngSpdVlvActIn != 0)
   {
      VLVACTINACQ_vidCurrentVelo();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidCamTargetState                              */
/* !Description :  Fonction pour la la lecture de l’état de la cible de       */
/*                 l’arbre à cames admission à partir des basses couches      */
/*                 logicielles (LDB).                                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Acquisition_etat_aac_adm;                                   */
/*  input boolean Vta_intake_camshaft_level;                                  */
/*  output boolean Vta_intake_camshaft_level;                                 */
/*  output boolean Ext_bVoltSenCmIn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidCamTargetState(void)
{
   VEMS_vidGET(Acquisition_etat_aac_adm, Vta_intake_camshaft_level);
   VEMS_vidSET(Ext_bVoltSenCmIn, Vta_intake_camshaft_level);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakeResynchro                             */
/* !Description :  Fonction de resynchronisation du compteur dent AAC sur une */
/*                 panne présente pmh ou/et décalage                          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACQ_vidIntakeResyn();                            */
/*  input boolean Vta_intake_resynchro_manu_inh;                              */
/*  input boolean VlvAct_bDgoORngShiftVlvActIn;                               */
/*  input boolean VlvAct_bDgoTDCDiagVlvActIn;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakeResynchro(void)
{
   if (  (Vta_intake_resynchro_manu_inh == 0)
      && (  (VlvAct_bDgoORngShiftVlvActIn != 0)
         || (VlvAct_bDgoTDCDiagVlvActIn != 0)))
   {
      VLVACTINACQ_vidIntakeResyn();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakePmhDiag                               */
/* !Description :  Fonction pour éviter les problèmes de synchronisation lors */
/*                 des démarrages à froid .                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACQ_vidIntakePmhCounter();                       */
/*  input boolean VlvAct_bMonRunTDCDiagVlvActIn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakePmhDiag(void)
{
   if(VlvAct_bMonRunTDCDiagVlvActIn != 0)
   {
      VLVACTINACQ_vidIntakePmhCounter();
   }
}
/*------------------------------- end of file --------------------------------*/