/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRTHERMOPROT                                           */
/* !Description     : THRTHERMOPROT component                                 */
/*                                                                            */
/* !Module          : THRTHERMOPROT                                           */
/* !Description     : DIAGNOSTIC DE L’ECHAUFFEMENT THERMIQUE DU BOITIER       */
/*                    PAPILLON                                                */
/*                                                                            */
/* !File            : THRTHERMOPROT_FCT1.C                                    */
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
/*   1 / THRTHERMOPROT_vidInitOutput                                          */
/*   2 / THRTHERMOPROT_vidInit                                                */
/*   3 / THRTHERMOPROT_vidFilThrVolt                                          */
/*   4 / THRTHERMOPROT_vidDiagCdn                                             */
/*   5 / THRTHERMOPROT_vidEngTEstim                                           */
/*   6 / THRTHERMOPROT_vidDiag                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 00381 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRTHERMOPROT/THRTHERMOPROT_FC$*/
/* $Revision::   1.3      $$Author::   acabresp       $$Date::   27 May 2010 $*/
/* $Author::   acabresp                               $$Date::   27 May 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRTHERMOPROT.h"
#include "THRTHERMOPROT_L.h"
#include "THRTHERMOPROT_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRTHERMOPROT_vidInitOutput                                */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  N.ABID                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Thr_uCmd;                                                    */
/*  output sint16 Thr_uCmdFil;                                                */
/*  output sint32 THRTHERMOPROT_s32ThruCmdFilMem;                             */
/*  output boolean THRTHERMOPROT_bTpacOpenLpCtrPrev;                          */
/*  output uint16 THRTHERMOPROT_u16ThrthermoProt;                             */
/*  output boolean THRTHERMOPROT_bDlyCfmOvldThrPrev;                          */
/*  output uint8 THRTHERMOPROT_u8ThrDlCfmOvldThr;                             */
/*  output boolean THRTHERMOPROT_bThermoThrTimeOut;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRTHERMOPROT_vidInitOutput(void)
{
   sint16 s16LocalThr_uCmd;


   VEMS_vidGET(Thr_uCmd, s16LocalThr_uCmd);
   VEMS_vidSET(Thr_uCmdFil, s16LocalThr_uCmd);
   THRTHERMOPROT_s32ThruCmdFilMem = (sint32)(s16LocalThr_uCmd * 65536);
   THRTHERMOPROT_bTpacOpenLpCtrPrev = 0;
   THRTHERMOPROT_u16ThrthermoProt = 0;
   THRTHERMOPROT_bDlyCfmOvldThrPrev = 0;
   THRTHERMOPROT_u8ThrDlCfmOvldThr = 0;
   THRTHERMOPROT_bThermoThrTimeOut = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRTHERMOPROT_vidInit                                      */
/* !Description :  Initialisation de la sortie "Thr_tEngEstim".               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  N.ABID                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_eau;                                              */
/*  output uint32 Thr_tEngEstim;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRTHERMOPROT_vidInit(void)
{
   uint8  u8LocalTemperature_eau;
   uint32 u32LocalThr_tEngEstim;


   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   u32LocalThr_tEngEstim = (uint32)(u8LocalTemperature_eau * 16384);
   VEMS_vidSET(Thr_tEngEstim, u32LocalThr_tEngEstim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRTHERMOPROT_vidFilThrVolt                                */
/* !Description :  Filtrage de la tension de commande du papillon avec        */
/*                 réinitialisation du filtre à la tension courante.          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  N.ABID                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Thr_uCmd;                                                    */
/*  input uint16 Thr_facFilUCmd_C;                                            */
/*  input sint32 THRTHERMOPROT_s32ThruCmdFilMem;                              */
/*  output sint16 Thr_uCmdFil;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRTHERMOPROT_vidFilThrVolt(void)
{
   sint16 s16LocalThr_uCmd;
   sint16 s16LocalThr_uCmdFil;


   VEMS_vidGET(Thr_uCmd, s16LocalThr_uCmd);
   s16LocalThr_uCmdFil =
      MATHSRV_s16FirstOrderFilterGu16(Thr_facFilUCmd_C,
                                      &THRTHERMOPROT_s32ThruCmdFilMem,
                                      s16LocalThr_uCmd);
   VEMS_vidSET(Thr_uCmdFil, s16LocalThr_uCmdFil);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRTHERMOPROT_vidDiagCdn                                   */
/* !Description :  C'est la  fonction de diagnostic sur la commande filtrée du*/
/*                 BPM qui  doit permettre de  protéger de l’échauffement     */
/*                 thermique le moteur électrique dans toutes les  situations */
/*                 de vie.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  N.ABID                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Tpac_open_loop_control;                                     */
/*  input boolean THRTHERMOPROT_bTpacOpenLpCtrPrev;                           */
/*  input uint16 Thr_dlyAcvCll_thermoProt_C;                                  */
/*  input uint16 THRTHERMOPROT_u16ThrthermoProt;                              */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint16 Dtc_throttle_position_reference;                             */
/*  input uint16 Thr_acvSpThd_ThermoProt_C;                                   */
/*  input boolean Thr_bAcvCdnCll_thermoProt_C;                                */
/*  input boolean Thr_bCdnCll_thermoProt;                                     */
/*  input boolean Thr_bAcvCdnLrn_thermoProt_C;                                */
/*  input boolean Thr_bCdnStopLrn_thermoProt;                                 */
/*  input boolean Thr_bAcvCdnSp_thermoProt_C;                                 */
/*  input boolean Thr_bCdnSpThd_thermoProt;                                   */
/*  input boolean Thr_bAcvCdnLih_thermoProt_C;                                */
/*  input boolean Thr_bCdnLih_thermoProt;                                     */
/*  output uint16 THRTHERMOPROT_u16ThrthermoProt;                             */
/*  output boolean Thr_bCdnCll_thermoProt;                                    */
/*  output boolean THRTHERMOPROT_bTpacOpenLpCtrPrev;                          */
/*  output boolean Thr_bCdnLih_thermoProt;                                    */
/*  output boolean Thr_bCdnSpThd_thermoProt;                                  */
/*  output boolean Thr_bCdnStopLrn_thermoProt;                                */
/*  output boolean Thr_bMonRunOvldThermoThr;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRTHERMOPROT_vidDiagCdn(void)
{
   boolean bLocalTpac_open_loop_control;
   boolean bLocalThermoProt1;
   boolean bLocalThermoProt2;
   boolean bLocalThermoProt3;
   boolean bLocalThermoProt4;
   uint8   u8LocalTpac_thr_control_state;
   uint16  u16LocalDtc_throttle_pos_ref;


   VEMS_vidGET(Tpac_open_loop_control, bLocalTpac_open_loop_control);

   if (  (bLocalTpac_open_loop_control == 0)
      && (THRTHERMOPROT_bTpacOpenLpCtrPrev != 0))
   {
      THRTHERMOPROT_u16ThrthermoProt =
         (uint16)MATHSRV_udtMIN(Thr_dlyAcvCll_thermoProt_C, 1000);
      if (THRTHERMOPROT_u16ThrthermoProt == 0)
      {
         Thr_bCdnCll_thermoProt = 1;
      }
      else
      {
         Thr_bCdnCll_thermoProt = 0;
      }
   }
   else
   {
      if (THRTHERMOPROT_u16ThrthermoProt > 0)
      {
         THRTHERMOPROT_u16ThrthermoProt =
            (uint16)(THRTHERMOPROT_u16ThrthermoProt - 1);
         if (THRTHERMOPROT_u16ThrthermoProt == 0)
         {
            Thr_bCdnCll_thermoProt = 1;
         }
         else
         {
            Thr_bCdnCll_thermoProt = 0;
         }
      }
   }
   THRTHERMOPROT_bTpacOpenLpCtrPrev = bLocalTpac_open_loop_control;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   if (u8LocalTpac_thr_control_state != TPAC_LIMP_HOME)
   {
      Thr_bCdnLih_thermoProt = 1;
   }
   else
   {
      Thr_bCdnLih_thermoProt = 0;
   }


   VEMS_vidGET(Dtc_throttle_position_reference, u16LocalDtc_throttle_pos_ref);
   if (u16LocalDtc_throttle_pos_ref <= Thr_acvSpThd_ThermoProt_C)
   {
      Thr_bCdnSpThd_thermoProt = 1;
   }
   else
   {
      Thr_bCdnSpThd_thermoProt = 0;
   }


   if (  (u8LocalTpac_thr_control_state != TPAC_CLOSING_RAMP)
      && (u8LocalTpac_thr_control_state != TPAC_HIGH_THRUST_SEARCH)
      && (u8LocalTpac_thr_control_state != TPAC_EXIT_LOW_THRUST))
   {
      Thr_bCdnStopLrn_thermoProt = 1;
   }
   else
   {
      Thr_bCdnStopLrn_thermoProt = 0;
   }


   if (Thr_bAcvCdnCll_thermoProt_C != 0)
   {
      bLocalThermoProt1 = Thr_bCdnCll_thermoProt;
   }
   else
   {
      bLocalThermoProt1 = 1;
   }

   if (Thr_bAcvCdnLrn_thermoProt_C != 0)
   {
      bLocalThermoProt2 = Thr_bCdnStopLrn_thermoProt;
   }
   else
   {
      bLocalThermoProt2 = 1;
   }

   if (Thr_bAcvCdnSp_thermoProt_C != 0)
   {
      bLocalThermoProt3 = Thr_bCdnSpThd_thermoProt;
   }
   else
   {
      bLocalThermoProt3 = 1;
   }

   if (Thr_bAcvCdnLih_thermoProt_C != 0)
   {
      bLocalThermoProt4 = Thr_bCdnLih_thermoProt;
   }
   else
   {
      bLocalThermoProt4 = 1;
   }

   if (  (bLocalThermoProt1 != 0)
      && (bLocalThermoProt2 != 0)
      && (bLocalThermoProt3 != 0)
      && (bLocalThermoProt4 != 0))
   {
      Thr_bMonRunOvldThermoThr = 1;
   }
   else
   {
      Thr_bMonRunOvldThermoThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRTHERMOPROT_vidEngTEstim                                 */
/* !Description :  Cette fonction permet de calculer L’estimation de la       */
/*                 température du moteur réalisée en utilisant le principe    */
/*                 suivant lequel le gradient de température vaut la          */
/*                 différence entre la chaleur apportée et la chaleur évacuée.*/
/* !Number      :  FCT1.5                                                     */
/* !Author      :  N.ABID                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Thr_uCmdFil;                                                 */
/*  input uint8 Temperature_eau;                                              */
/*  input uint32 Thr_tEngEstim;                                               */
/*  input uint16 Thr_facPwr_C;                                                */
/*  input uint16 Thr_facGrd_C;                                                */
/*  output sint16 Thr_tEngGrd;                                                */
/*  output uint32 Thr_tEngEstim;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRTHERMOPROT_vidEngTEstim(void)
{
   uint8  u8LocalTemperature_eau;
   sint16 s16LocalThr_uCmdFil;
   sint32 s32LocalThr_tEngGrd;
   uint32 u32LocalThr_uCmdFil2;
   uint32 u32LocalThr_tEngEstim;
   uint32 u32LocalOutputMul_x3;
   uint32 u32LocalAddThr_tEngEstim;
   uint32 u32LocalTemp1;
   uint32 u32LocalTemp2;
   uint32 u32LocalTemp3;
   sint32 s32LocalTemp;


   VEMS_vidGET(Thr_uCmdFil, s16LocalThr_uCmdFil);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Thr_tEngEstim, u32LocalThr_tEngEstim);

   u32LocalThr_uCmdFil2 = (uint32)(s16LocalThr_uCmdFil * s16LocalThr_uCmdFil);
   u32LocalOutputMul_x3 = Mfx_RMulDiv_u32u32u32_u32(u32LocalThr_uCmdFil2,
                                                    (uint32)Thr_facPwr_C,
                                                    64000);
   u32LocalTemp1 = Mfx_RMulDiv_u32u32u32_u32(u32LocalOutputMul_x3,
                                             (uint32)Thr_facGrd_C,
                                             6553600);

   u32LocalTemp2 = Mfx_RMulDiv_u32u32u32_u32(u32LocalThr_tEngEstim,
                                             (uint32)Thr_facGrd_C,
                                             6553600);

   u32LocalTemp3 =
      (uint32)(((u8LocalTemperature_eau * Thr_facGrd_C) + 200) / 400);

   s32LocalTemp = Mfx_Sub_u32u32_s32(u32LocalTemp1, u32LocalTemp2);
   s32LocalThr_tEngGrd = Mfx_Add_u32s32_s32(u32LocalTemp3, s32LocalTemp);

   Thr_tEngGrd = (sint16)MATHSRV_udtCLAMP(s32LocalThr_tEngGrd,
                                                  -32768,
                                                  32767);
   u32LocalAddThr_tEngEstim = Mfx_Add_u32s32_u32(u32LocalThr_tEngEstim,
                                                 s32LocalThr_tEngGrd);
   u32LocalAddThr_tEngEstim = MATHSRV_udtMIN(u32LocalAddThr_tEngEstim,
                                             16777215);
   VEMS_vidSET(Thr_tEngEstim, u32LocalAddThr_tEngEstim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRTHERMOPROT_vidDiag                                      */
/* !Description :  La calibration permet de choisir d’effectuer le diagnostic */
/*                 sur la valeur de la tension de commande ou sur la valeur   */
/*                 estimée de la température du moteur.                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  N.ABID                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Thr_uCmdFil;                                                 */
/*  input sint32 Thr_uCmdThd_C;                                               */
/*  input boolean THRTHERMOPROT_bDlyCfmOvldThrPrev;                           */
/*  input uint8 Thr_tiDlyCfmOvldThermoThr_C;                                  */
/*  input uint8 THRTHERMOPROT_u8ThrDlCfmOvldThr;                              */
/*  input boolean Thr_bTypDiagThermoProt_C;                                   */
/*  input boolean THRTHERMOPROT_bThermoThrTimeOut;                            */
/*  input uint32 Thr_tEngEstim;                                               */
/*  input uint16 Thr_tEngThd_C;                                               */
/*  output uint8 THRTHERMOPROT_u8ThrDlCfmOvldThr;                             */
/*  output boolean THRTHERMOPROT_bThermoThrTimeOut;                           */
/*  output boolean THRTHERMOPROT_bDlyCfmOvldThrPrev;                          */
/*  output boolean Thr_bDgoOvldThermoThr;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRTHERMOPROT_vidDiag(void)
{
   boolean bLocalThr_tiDlyCfmOvldThermoThr;
   uint16  u16LocalThr_uCmdFil;
   sint16  s16LocalThr_uCmdFil;
   uint32  u32LocalThr_tEngEstim;
   uint32  u32LocalThrTEngThd;


   VEMS_vidGET(Thr_uCmdFil, s16LocalThr_uCmdFil);
   u16LocalThr_uCmdFil = (uint16)(MATHSRV_udtABS(s16LocalThr_uCmdFil));
   if (u16LocalThr_uCmdFil >= Thr_uCmdThd_C)
   {
      bLocalThr_tiDlyCfmOvldThermoThr = 1;
   }
   else
   {
      bLocalThr_tiDlyCfmOvldThermoThr = 0;
   }

   if (  (bLocalThr_tiDlyCfmOvldThermoThr != 0)
      && (THRTHERMOPROT_bDlyCfmOvldThrPrev == 0))
   {
      THRTHERMOPROT_u8ThrDlCfmOvldThr = Thr_tiDlyCfmOvldThermoThr_C;
      if (THRTHERMOPROT_u8ThrDlCfmOvldThr == 0)
      {
         THRTHERMOPROT_bThermoThrTimeOut = 1;
      }
      else
      {
         THRTHERMOPROT_bThermoThrTimeOut = 0;
      }
   }
   else
   {
      if (THRTHERMOPROT_u8ThrDlCfmOvldThr > 0)
      {
         THRTHERMOPROT_u8ThrDlCfmOvldThr =
            (uint8)(THRTHERMOPROT_u8ThrDlCfmOvldThr - 1);
         if (THRTHERMOPROT_u8ThrDlCfmOvldThr == 0)
         {
            THRTHERMOPROT_bThermoThrTimeOut = 1;
         }
         else
         {
            THRTHERMOPROT_bThermoThrTimeOut = 0;
         }
      }
   }
   THRTHERMOPROT_bDlyCfmOvldThrPrev = bLocalThr_tiDlyCfmOvldThermoThr;
   if (Thr_bTypDiagThermoProt_C != 0)
   {
      if (bLocalThr_tiDlyCfmOvldThermoThr != 0)
      {
         Thr_bDgoOvldThermoThr = THRTHERMOPROT_bThermoThrTimeOut;
      }
      else
      {
         Thr_bDgoOvldThermoThr = 0;
      }
   }
   else
   {
      VEMS_vidGET(Thr_tEngEstim, u32LocalThr_tEngEstim);
      u32LocalThrTEngThd = (uint32)(Thr_tEngThd_C * 256);
      if (u32LocalThr_tEngEstim >= u32LocalThrTEngThd)
      {
         Thr_bDgoOvldThermoThr = 1;
      }
      else
      {
         Thr_bDgoOvldThermoThr = 0;
      }
   }
}

/*------------------------------- end of file --------------------------------*/