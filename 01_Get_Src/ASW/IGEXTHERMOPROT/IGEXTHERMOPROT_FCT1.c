/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGEXTHERMOPROT                                          */
/* !Description     : IGEXTHERMOPROT component.                               */
/*                                                                            */
/* !Module          : IGEXTHERMOPROT                                          */
/* !Description     : PROTECTION THERMIQUE DE LA LIGNE D’ECHAPPEMENT.         */
/*                                                                            */
/* !File            : IGEXTHERMOPROT_FCT1.C                                   */
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
/*   1 / IGEXTHERMOPROT_vidInitOutput                                         */
/*   2 / IGEXTHERMOPROT_vidResetProtTherm                                     */
/*   3 / IGEXTHERMOPROT_vidProtAdvCalc                                        */
/*   4 / IGEXTHERMOPROT_vidYieldAdvCalc                                       */
/*   5 / IGEXTHERMOPROT_vidThermProt                                          */
/*   6 / IGEXTHERMOPROT_vidInit                                               */
/*   7 / IGEXTHERMOPROT_vidIntegration                                        */
/*   8 / IGEXTHERMOPROT_vidCut                                                */
/*   9 / IGEXTHERMOPROT_vidProtection                                         */
/*   10 / IGEXTHERMOPROT_vidCutProt                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 06151 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGEXTHERMOPROT/IGEXTHERMOPROT_FCT1$*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   13 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   13 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGEXTHERMOPROT.h"
#include "IGEXTHERMOPROT_l.h"
#include "IGEXTHERMOPROT_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidInitOutput                               */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Eng_bExThermoProt;                                         */
/*  output uint8 IgSys_agIgMinThermo2;                                        */
/*  output boolean IGEXTHERMOPROT_bTimerOut1;                                 */
/*  output boolean IGEXTHERMOPROT_bTimerOut2;                                 */
/*  output boolean IGEXTHERMOPROT_bTimerOut3;                                 */
/*  output boolean IGEXTHERMOPROT_bTimerOut4;                                 */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay1;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay2;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay3;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay4;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay5;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay6;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay7;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay8;                                */
/*  output boolean Inhibition_appli_avance_min_spc[4];                        */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev1;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev2;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev3;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev4;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev5;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev6;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev7;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev8;                              */
/*  output boolean IGEXTHERMOPROT_bTimer1Init;                                */
/*  output boolean IGEXTHERMOPROT_bTimer1InitPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidInitOutput(void)
{
   uint8 u8LocalIndex;


   VEMS_vidSET(Eng_bExThermoProt, 0);
   VEMS_vidSET(IgSys_agIgMinThermo2, 96);

   IGEXTHERMOPROT_bTimerOut1 = 1;
   IGEXTHERMOPROT_bTimerOut2 = 1;
   IGEXTHERMOPROT_bTimerOut3 = 1;
   IGEXTHERMOPROT_bTimerOut4 = 1;
   IGEXTHERMOPROT_u16TmrDelay1 = 0;
   IGEXTHERMOPROT_u16TmrDelay2 = 0;
   IGEXTHERMOPROT_u16TmrDelay3 = 0;
   IGEXTHERMOPROT_u16TmrDelay4 = 0;
   IGEXTHERMOPROT_u16TmrDelay5 = 0;
   IGEXTHERMOPROT_u16TmrDelay6 = 0;
   IGEXTHERMOPROT_u16TmrDelay7 = 0;
   IGEXTHERMOPROT_u16TmrDelay8 = 0;
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Inhibition_appli_avance_min_spc[u8LocalIndex] = 1;
   }
   IGEXTHERMOPROT_bInitTmrPrev1 = 0;
   IGEXTHERMOPROT_bInitTmrPrev2 = 0;
   IGEXTHERMOPROT_bInitTmrPrev3 = 0;
   IGEXTHERMOPROT_bInitTmrPrev4 = 0;
   IGEXTHERMOPROT_bInitTmrPrev5 = 0;
   IGEXTHERMOPROT_bInitTmrPrev6 = 0;
   IGEXTHERMOPROT_bInitTmrPrev7 = 0;
   IGEXTHERMOPROT_bInitTmrPrev8 = 0;
   IGEXTHERMOPROT_bTimer1Init = 0;
   IGEXTHERMOPROT_bTimer1InitPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidResetProtTherm                           */
/* !Description :  Fonction d'initialisation des outputs                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st74 IgSys_stThermoProt;                                           */
/*  output uint16 IgSys_mAirInt_thermoProt;                                   */
/*  output boolean Eng_bExThermoProtNotInh;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidResetProtTherm(void)
{
   IgSys_stThermoProt = THERMOPROT_INIT;
   IgSys_mAirInt_thermoProt = 32768;
   VEMS_vidSET(Eng_bExThermoProtNotInh, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidProtAdvCalc                              */
/* !Description :  Fonction permettant de déterminer une nouvelle avance min  */
/*                 de protection thermique échappement                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Eng_bExThermoProtNotInh;                                    */
/*  input uint8 IgSys_agIgLimMinRef2;                                         */
/*  input uint8 IgSys_agIgLimKnkMv;                                           */
/*  input uint8 IgSys_agIgTarWiCllTar;                                        */
/*  input uint8 IgSys_agIgLimMinKnk;                                          */
/*  output uint8 IgSys_agIgMinThermo2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidProtAdvCalc(void)
{
   boolean bLocalExThrmProtNotInh;
   uint8   u8LocalIgSys_agIgLimMinRef2;
   uint8   u8LocalIgSys_agIgLimKnkMv;
   uint8   u8LocalIgSys_agIgTarWiCllTar;
   uint8   u8LocalIgSys_agIgLimMinKnk;
   uint8   u8LocalIgSys_agIgMinThermo2;
   uint8   u8LocalMin1;
   uint8   u8LocalMin2;


   VEMS_vidGET(Eng_bExThermoProtNotInh, bLocalExThrmProtNotInh);
   VEMS_vidGET(IgSys_agIgLimMinRef2, u8LocalIgSys_agIgLimMinRef2);
   VEMS_vidGET(IgSys_agIgLimKnkMv, u8LocalIgSys_agIgLimKnkMv);
   VEMS_vidGET(IgSys_agIgTarWiCllTar, u8LocalIgSys_agIgTarWiCllTar);
   VEMS_vidGET(IgSys_agIgLimMinKnk, u8LocalIgSys_agIgLimMinKnk);

   u8LocalMin1 = (uint8)MATHSRV_udtMIN(u8LocalIgSys_agIgLimMinRef2,
                                      u8LocalIgSys_agIgLimKnkMv);
   u8LocalMin2 = (uint8)MATHSRV_udtMIN(u8LocalIgSys_agIgTarWiCllTar,
                                      u8LocalMin1);

   if (bLocalExThrmProtNotInh != 0)
   {
      u8LocalIgSys_agIgMinThermo2 = (uint8)MATHSRV_udtMAX(u8LocalMin2,
                                    u8LocalIgSys_agIgLimMinKnk);
   }
   else
   {
      u8LocalIgSys_agIgMinThermo2 = (uint8)MATHSRV_udtMAX(u8LocalMin1,
                                    u8LocalIgSys_agIgLimMinKnk);
   }

   VEMS_vidSET(IgSys_agIgMinThermo2, u8LocalIgSys_agIgMinThermo2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidYieldAdvCalc                             */
/* !Description :  Fonction permettant de faire le calcul destiné à utiliser  */
/*                 les rendements fournis par le module d’avance.             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean IgSys_bSel_effClc_C;                                        */
/*  input uint16 IgSys_rMinThermoIgEfc;                                       */
/*  input uint16 IgSys_rDynIgSpEfc;                                           */
/*  input uint8 IgSys_agIgOptm;                                               */
/*  input uint8 IgSys_agIgMinThermo2;                                         */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  input uint8 IgSys_rIgEfc_thermoProt_T[6];                                 */
/*  input uint8 IgSys_agIgDifOptmThermo;                                      */
/*  input uint8 IgSys_agIgDifOptmSp;                                          */
/*  input uint16 IgSys_rIgEfc_Thermo_thermoProt_M[6];                         */
/*  input uint16 IgSys_rIgEfc_Sp_thermoProt_M[6];                             */
/*  output uint16 IgSys_rMinThermoIgEfc_ThP;                                  */
/*  output uint16 IgSys_rDynIgSpEfc_ThP;                                      */
/*  output uint8 IgSys_agIgDifOptmThermo;                                     */
/*  output uint8 IgSys_agIgDifOptmSp;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidYieldAdvCalc(void)
{
   uint8  u8LocalMinThermo2;
   uint8  u8LocalIgSp;
   uint8  u8LocalIgOptm;
   uint16 u16LocalMinThermoIgEfc;
   uint16 u16LocalDynIgSpEfc;
   uint16 u16LocalOptmThermoPara;
   uint16 u16LocalOptmSpPara;
   sint16 s16LocalDifOptmThermo;
   sint16 s16LocalDifOptmSp;


   if (IgSys_bSel_effClc_C != 0)
   {
      VEMS_vidGET(IgSys_rMinThermoIgEfc, u16LocalMinThermoIgEfc);
      VEMS_vidGET(IgSys_rDynIgSpEfc, u16LocalDynIgSpEfc);
      IgSys_rMinThermoIgEfc_ThP =
         (uint16)MATHSRV_udtMIN(u16LocalMinThermoIgEfc, 1023);
      IgSys_rDynIgSpEfc_ThP =
         (uint16)MATHSRV_udtMIN(u16LocalDynIgSpEfc, 1023);
   }
   else
   {
      VEMS_vidGET(IgSys_agIgOptm, u8LocalIgOptm);
      VEMS_vidGET(IgSys_agIgMinThermo2, u8LocalMinThermo2);
      VEMS_vidGET(IgSys_agIgSp, u8LocalIgSp);
      s16LocalDifOptmThermo = (sint16)( (u8LocalIgOptm - u8LocalMinThermo2)
                                      + 96);
      s16LocalDifOptmSp = (sint16)( (u8LocalIgOptm - u8LocalIgSp)
                                  + 96);
      IgSys_agIgDifOptmThermo = (uint8)MATHSRV_udtCLAMP(s16LocalDifOptmThermo,
                                                        0,
                                                        255);
      IgSys_agIgDifOptmSp = (uint8)MATHSRV_udtCLAMP(s16LocalDifOptmSp, 0, 255);
      u16LocalOptmThermoPara =
         MATHSRV_u16CalcParaIncAryU8(IgSys_rIgEfc_thermoProt_T,
                                     IgSys_agIgDifOptmThermo,
                                     6);
      u16LocalOptmSpPara =
         MATHSRV_u16CalcParaIncAryU8(IgSys_rIgEfc_thermoProt_T,
                                     IgSys_agIgDifOptmSp,
                                     6);
      IgSys_rMinThermoIgEfc_ThP =
         MATHSRV_u16Interp1d(&IgSys_rIgEfc_Thermo_thermoProt_M[0],
                             u16LocalOptmThermoPara);
      IgSys_rDynIgSpEfc_ThP =
         MATHSRV_u16Interp1d(&IgSys_rIgEfc_Sp_thermoProt_M[0],
                             u16LocalOptmSpPara);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidThermProt                                */
/* !Description :  Gestion de l'automate permettant la proctection de la ligne*/
/*                 d'échappement                                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGEXTHERMOPROT_vidThermProtCalc();                       */
/*  extf argret void IGEXTHERMOPROT_vidInit();                                */
/*  extf argret void IGEXTHERMOPROT_vidIntegration();                         */
/*  extf argret void IGEXTHERMOPROT_vidCut();                                 */
/*  extf argret void IGEXTHERMOPROT_vidProtection();                          */
/*  extf argret void IGEXTHERMOPROT_vidCutProt();                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st74 IgSys_stThermoProt;                                            */
/*  output uint8 IgSys_SampleTiMid_PhysVal;                                   */
/*  output st74 IgSys_stThermoProt;                                           */
/*  output uint16 IgSys_mAirInt_thermoProt;                                   */
/*  output boolean Eng_bExThermoProtNotInh;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidThermProt(void)
{
   IGEXTHERMOPROT_vidThermProtCalc();
   IgSys_SampleTiMid_PhysVal = IgSys_SampleTiMid_SC;
   switch(IgSys_stThermoProt)
   {
      case THERMOPROT_INIT:
         IGEXTHERMOPROT_vidInit();
         break;
      case THERMOPROT_INTEGRATION:
         IGEXTHERMOPROT_vidIntegration();
         break;
      case THERMOPROT_COUPURE:
         IGEXTHERMOPROT_vidCut();
         break;
      case THERMOPROT_PROTECTION:
         IGEXTHERMOPROT_vidProtection();
         break;
      case THERMOPROT_COUP_PROT:
         IGEXTHERMOPROT_vidCutProt();
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         IgSys_stThermoProt = THERMOPROT_INIT;
         IgSys_mAirInt_thermoProt = 32768;
         VEMS_vidSET(Eng_bExThermoProtNotInh, 0);
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidInit                                     */
/* !Description :  Fonction de transition de l'état THERMOPROT_INIT           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  input uint8 IgSys_agIgMinThermo2;                                         */
/*  output st74 IgSys_stThermoProt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidInit(void)
{
   uint8 u8LocalVehicle;
   uint8 u8LocalAgIgSp;
   uint8 u8LocalMinThermo2;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle);
   VEMS_vidGET(IgSys_agIgSp, u8LocalAgIgSp);
   VEMS_vidGET(IgSys_agIgMinThermo2, u8LocalMinThermo2);
   if (  (u8LocalVehicle == VS_RUNNING)
      && (u8LocalAgIgSp < u8LocalMinThermo2))
   {
      IgSys_stThermoProt = THERMOPROT_INTEGRATION;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidIntegration                              */
/* !Description :  Fonction de transition de l'état THERMOPROT_INTEGRATION    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGEXTHERMOPROT_vidResetProtTherm();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGEXTHERMOPROT_vidCalOnIntOrProt();                      */
/*  input uint16 IgSys_mAirInt_thermoProt;                                    */
/*  input uint16 IgSys_mAirMax_ThermoProt;                                    */
/*  input boolean Auto_injection;                                             */
/*  input st23 Vehicle_active_state;                                          */
/*  output st74 IgSys_stThermoProt;                                           */
/*  output boolean Eng_bExThermoProtNotInh;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidIntegration(void)
{
   boolean bLocalAutoInj;
   uint8   u8LocalVehicle;
   uint32  u32LocalMaxThermoProt;


   if (IgSys_mAirInt_thermoProt < 32768)
   {
      IGEXTHERMOPROT_vidResetProtTherm();
   }
   else
   {
      u32LocalMaxThermoProt = (uint32)(IgSys_mAirMax_ThermoProt + 32768);
      if (IgSys_mAirInt_thermoProt > u32LocalMaxThermoProt)
      {
         IgSys_stThermoProt = THERMOPROT_PROTECTION;
         VEMS_vidSET(Eng_bExThermoProtNotInh, 1);
      }
      else
      {
         VEMS_vidGET(Auto_injection, bLocalAutoInj);
         if (bLocalAutoInj == 0)
         {
            IgSys_stThermoProt = THERMOPROT_COUPURE;
         }
         else
         {
            VEMS_vidGET(Vehicle_active_state, u8LocalVehicle);
            if (u8LocalVehicle != VS_RUNNING)
            {
               IGEXTHERMOPROT_vidResetProtTherm();
            }
            else
            {
               IGEXTHERMOPROT_vidCalOnIntOrProt();
            }
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidCut                                      */
/* !Description :  Fonction de transition de l'état THERMOPROT_COUPURE        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGEXTHERMOPROT_vidResetProtTherm();                      */
/*  extf argret void IGEXTHERMOPROT_vidCalOnCutOrCutP();                      */
/*  input boolean Auto_injection;                                             */
/*  input st23 Vehicle_active_state;                                          */
/*  output st74 IgSys_stThermoProt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidCut(void)
{
   boolean bLocalAutoInj;
   uint8   u8LocalVehicle;


   VEMS_vidGET(Auto_injection, bLocalAutoInj);
   if (bLocalAutoInj != 0)
   {
      IgSys_stThermoProt = THERMOPROT_INTEGRATION;
   }
   else
   {
      VEMS_vidGET(Vehicle_active_state, u8LocalVehicle);
      if (u8LocalVehicle != VS_RUNNING)
      {
         IGEXTHERMOPROT_vidResetProtTherm();
      }
      else
      {
         IGEXTHERMOPROT_vidCalOnCutOrCutP();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidProtection                               */
/* !Description :  Fonction de transition de l'état THERMOPROT_PROTECTION     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGEXTHERMOPROT_vidResetProtTherm();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGEXTHERMOPROT_vidCalOnIntOrProt();                      */
/*  input uint16 IgSys_mAirInt_thermoProt;                                    */
/*  input uint16 IgSys_mAirMin_ThermoProt;                                    */
/*  input boolean Auto_injection;                                             */
/*  input st23 Vehicle_active_state;                                          */
/*  output st74 IgSys_stThermoProt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidProtection(void)
{
   boolean bLocalAutoInj;
   uint8   u8LocalVehicle;


   if (IgSys_mAirInt_thermoProt < IgSys_mAirMin_ThermoProt)
   {
      IGEXTHERMOPROT_vidResetProtTherm();
   }
   else
   {
      VEMS_vidGET(Auto_injection, bLocalAutoInj);
      if (bLocalAutoInj == 0)
      {
         IgSys_stThermoProt = THERMOPROT_COUP_PROT;
      }
      else
      {
         VEMS_vidGET(Vehicle_active_state, u8LocalVehicle);
         if (u8LocalVehicle != VS_RUNNING)
         {
            IGEXTHERMOPROT_vidResetProtTherm();
         }
         else
         {
            IGEXTHERMOPROT_vidCalOnIntOrProt();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidCutProt                                  */
/* !Description :  Fonction de transition de l'état THERMOPROT_COUP_PROT      */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void IGEXTHERMOPROT_vidResetProtTherm();                      */
/*  extf argret void IGEXTHERMOPROT_vidCalOnCutOrCutP();                      */
/*  input boolean Auto_injection;                                             */
/*  input st23 Vehicle_active_state;                                          */
/*  output st74 IgSys_stThermoProt;                                           */
/*  output boolean Eng_bExThermoProtNotInh;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidCutProt(void)
{
   boolean bLocalAutoInj;
   uint8   u8LocalVehicle;


   VEMS_vidGET(Auto_injection, bLocalAutoInj);
   if (bLocalAutoInj != 0)
   {
      IgSys_stThermoProt = THERMOPROT_PROTECTION;
      VEMS_vidSET(Eng_bExThermoProtNotInh, 1);
   }
   else
   {
      VEMS_vidGET(Vehicle_active_state, u8LocalVehicle);
      if (u8LocalVehicle != VS_RUNNING)
      {
         IGEXTHERMOPROT_vidResetProtTherm();
      }
      else
      {
         IGEXTHERMOPROT_vidCalOnCutOrCutP();
      }
   }
}
/*------------------------------- end of file --------------------------------*/