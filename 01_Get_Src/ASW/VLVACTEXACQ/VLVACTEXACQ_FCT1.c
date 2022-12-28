/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXACQ                                             */
/* !Description     : VLVACTEXACQ Component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXACQ                                             */
/* !Description     : Acquisition du Décalage et Calcul de la Vitesse de      */
/*                    Décalage de la VVT d’échappement                        */
/*                                                                            */
/* !File            : VLVACTEXACQ_FCT1.C                                      */
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
/*   1 / VLVACTEXACQ_vidInitOutput                                            */
/*   2 / VLVACTEXACQ_vidInitPannes                                            */
/*   3 / VLVACTEXACQ_vidInit                                                  */
/*   4 / VLVACTEXACQ_vidCurrentShift                                          */
/*   5 / VLVACTEXACQ_vidCurrentVelocity                                       */
/*   6 / VLVACTEXACQ_vidCamTargetState                                        */
/*   7 / VLVACTEXACQ_vidExhaustResynchro                                      */
/*   8 / VLVACTEXACQ_vidExhaustPmhDiag                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6588648 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXACQ/VLVACT$*/
/* $Revision::   1.23     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXACQ.h"
#include "VLVACTEXACQ_L.h"
#include "VLVACTEXACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidInitOutput                                  */
/* !Description :  Initialisation des variables de sortie                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Vxx_rel_ex_vvt_mes;                                         */
/*  output uint16 Vta_exhaust_tooth_time;                                     */
/*  output sint16 Vta_exhaust_filt_velocity;                                  */
/*  output uint8 Vta_exhaust_tooth_counter;                                   */
/*  output uint16 Ext_agCmExMes;                                              */
/*  output boolean Ext_bVoltSenCmEx;                                          */
/*  output uint8 Ext_ctEdgeCmEx;                                              */
/*  output uint16 Ext_nEngCmExMes;                                            */
/*  output uint16 Ext_tiPatCmEx;                                              */
/*  output uint16 VlvAct_nEngExCmFil;                                         */
/*  output uint16 VLVACTEXACQ_u16EngInCmPrev1;                                */
/*  output uint16 VLVACTEXACQ_u16EngInCmPrev2;                                */
/*  output uint16 VLVACTEXACQ_u16EngInCmPrev3;                                */
/*  output uint8 VLVACTEXACQ_u8VehActivStatePrev;                             */
/*  output uint16 VlvAct_nEngExCm;                                            */
/*  output uint16 Ext_agCmExMesTbl[4];                                        */
/*  output uint16 VLVACTEXACQ_u16RelInVvtMesPrev;                             */
/*  output sint16 Vta_exhaust_camshaft_velocity;                              */
/*  output boolean Vta_exhaust_velocity_set;                                  */
/*  output sint16 Vta_exhaust_camshaft_velocity_1;                            */
/*  output sint32 VLVACTEXACQ_s32FrstOrderFiltMem1;                           */
/*  output sint32 VLVACTEXACQ_s32FrstOrderFiltMem2;                           */
/*  output boolean VLVACTEXACQ_bnEngExORngShiftThd;                           */
/*  output boolean VLVACTEXACQ_bnEngExTDCDiagThd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidInitOutput(void)
{
   VEMS_vidSET(Vxx_rel_ex_vvt_mes, 0);
   VEMS_vidSET(Vta_exhaust_tooth_time, 0);
   VEMS_vidSET(Vta_exhaust_filt_velocity, 0);
   VEMS_vidSET(Vta_exhaust_tooth_counter, 0);
   VEMS_vidSET(Ext_agCmExMes, 0);
   VEMS_vidSET(Ext_bVoltSenCmEx, 0);
   VEMS_vidSET(Ext_ctEdgeCmEx, 0);
   VEMS_vidSET(Ext_nEngCmExMes, 0);
   VEMS_vidSET(Ext_tiPatCmEx, 0);
   VEMS_vidSET(VlvAct_nEngExCmFil, 0);
   VLVACTEXACQ_u16EngInCmPrev1 = 0;
   VLVACTEXACQ_u16EngInCmPrev2 = 0;
   VLVACTEXACQ_u16EngInCmPrev3 = 0;
   VLVACTEXACQ_u8VehActivStatePrev = VS_STALL;
   VlvAct_nEngExCm = 0;
   Ext_agCmExMesTbl[0] = 0;
   Ext_agCmExMesTbl[1] = 0;
   Ext_agCmExMesTbl[2] = 0;
   Ext_agCmExMesTbl[3] = 0;
   VLVACTEXACQ_u16RelInVvtMesPrev = 0;
   Vta_exhaust_camshaft_velocity = 0;
   Vta_exhaust_velocity_set = 0;
   Vta_exhaust_camshaft_velocity_1 = 0;
   VLVACTEXACQ_s32FrstOrderFiltMem1 = 0;
   VLVACTEXACQ_s32FrstOrderFiltMem2 = 0;
   VLVACTEXACQ_bnEngExORngShiftThd = 0;
   VLVACTEXACQ_bnEngExTDCDiagThd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidInitPannes                                  */
/* !Description :  Les pannes VVT présentes sont initialisées sur clé off/on  */
/*                 afin de ne pas rester figées entre le clé on et le         */
/*                 démarrage du moteur.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean VlvAct_bDgoMissToothVlvActEx;                              */
/*  output boolean VlvAct_bDgoORngShiftVlvActEx;                              */
/*  output boolean VlvAct_bDgoORngSpdVlvActEx;                                */
/*  output boolean VlvAct_bDgoTDCDiagVlvActEx;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidInitPannes(void)
{
   VlvAct_bDgoMissToothVlvActEx = 0;
   VlvAct_bDgoORngShiftVlvActEx = 0;
   VlvAct_bDgoORngSpdVlvActEx = 0;
   VlvAct_bDgoTDCDiagVlvActEx = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidInit                                        */
/* !Description :  Ce bloc initialise, sur front montant de                   */
/*                 Moteur_synchronisé, les variables suivantes : -            */
/*                 Vta_exhaust_camshaft_shift et Vta_exhaust_tooth_counter    */
/*                 (compteur de dents )                                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vta_exhaust_camshaft_shift_def;                              */
/*  input boolean VlvAct_bExSelTypIniCntCmTooth_C;                            */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input boolean Vta_exhaust_camshaft_level;                                 */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  output uint16 Vxx_rel_ex_vvt_mes;                                         */
/*  output sint16 Vta_exhaust_camshaft_shift;                                 */
/*  output uint8 Vta_exhaust_tooth_counter;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidInit(void)
{
   uint8  u8LocalEng_noCmbCyl;
   uint8  u8LocalVtaExtToothCount;
   uint16 u16LocalVxx_rel_ex_vvt_mes;
   sint16 s16LocalCalc;


   u16LocalVxx_rel_ex_vvt_mes =
      (uint16)MATHSRV_udtMIN(Vta_exhaust_camshaft_shift_def, 1066);
   VEMS_vidSET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);

   Vta_exhaust_camshaft_shift =
      (sint16)MATHSRV_udtMIN(Vta_exhaust_camshaft_shift_def, 7679);

   if (VlvAct_bExSelTypIniCntCmTooth_C != 0)
   {
      VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
      s16LocalCalc = (sint16)(u8LocalEng_noCmbCyl - 1);
   }
   else
   {
      if (Vta_exhaust_camshaft_level != 0)
      {
         s16LocalCalc = 0;
      }
      else
      {
         s16LocalCalc = (sint16)(Vta_exhaust_tooth_nb - 1);
      }
   }
   u8LocalVtaExtToothCount = (uint8)MATHSRV_udtCLAMP(s16LocalCalc, 0, 3);
   VEMS_vidSET(Vta_exhaust_tooth_counter, u8LocalVtaExtToothCount);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidCurrentShift                                */
/* !Description :  Processus de mesure du décalage                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACQ_vidExhaustRisingCapt();                      */
/*  extf argret void VLVACTEXACQ_vidExhaustCaptCalc();                        */
/*  extf argret void VLVACTEXACQ_vidExhaustDiagnosis();                       */
/*  input boolean VlvAct_bMonRunORngShiftVlvActEx;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidCurrentShift(void)
{

   VLVACTEXACQ_vidExhaustRisingCapt();
   VLVACTEXACQ_vidExhaustCaptCalc();

   if (VlvAct_bMonRunORngShiftVlvActEx != 0)
   {
      VLVACTEXACQ_vidExhaustDiagnosis();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidCurrentVelocity                             */
/* !Description :  Fonction de calcul de la valeur de la vitesse de décalage  */
/*                 de l’AAC d'échappement                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACQ_vidCurrentVelo();                            */
/*  input boolean VlvAct_bMonRunORngSpdVlvActEx;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidCurrentVelocity(void)
{
   if (VlvAct_bMonRunORngSpdVlvActEx != 0)
   {
      VLVACTEXACQ_vidCurrentVelo();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidCamTargetState                              */
/* !Description :  Fonction pour la la lecture de l’état de la cible de       */
/*                 l’arbre à cames échappement à partir des basses couches    */
/*                 logicielles (LDB).                                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Acquisition_etat_aac_ech;                                   */
/*  input boolean Vta_exhaust_camshaft_level;                                 */
/*  output boolean Vta_exhaust_camshaft_level;                                */
/*  output boolean Ext_bVoltSenCmEx;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidCamTargetState(void)
{
   VEMS_vidGET(Acquisition_etat_aac_ech, Vta_exhaust_camshaft_level);
   VEMS_vidSET(Ext_bVoltSenCmEx, Vta_exhaust_camshaft_level);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustResynchro                            */
/* !Description :  Fonction de resynchronisation du compteur dent AAC sur une */
/*                 panne présente pmh ou/et décalage                          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACQ_vidExhaustResyn();                           */
/*  input boolean Vta_exhaust_resynchro_manu_inh;                             */
/*  input boolean VlvAct_bDgoORngShiftVlvActEx;                               */
/*  input boolean VlvAct_bDgoTDCDiagVlvActEx;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustResynchro(void)
{
   if (  (Vta_exhaust_resynchro_manu_inh == 0)
      && (  (VlvAct_bDgoORngShiftVlvActEx != 0)
         || (VlvAct_bDgoTDCDiagVlvActEx != 0)))
   {
      VLVACTEXACQ_vidExhaustResyn();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustPmhDiag                              */
/* !Description :  Fonction pour éviter les problèmes de synchronisation lors */
/*                 des démarrages à froid .                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACQ_vidExhaustPmhCounter();                      */
/*  input boolean VlvAct_bMonRunTDCDiagVlvActEx;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustPmhDiag(void)
{
   if (VlvAct_bMonRunTDCDiagVlvActEx != 0)
   {
      VLVACTEXACQ_vidExhaustPmhCounter();
   }
}
/*------------------------------- end of file --------------------------------*/