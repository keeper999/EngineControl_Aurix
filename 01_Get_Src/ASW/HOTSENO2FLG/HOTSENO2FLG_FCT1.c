/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HOTSENO2FLG                                             */
/* !Description     : HOTSENO2FLG Component                                   */
/*                                                                            */
/* !Module          : HOTSENO2FLG                                             */
/* !Description     : Determination des sondes lambda chaudes                 */
/*                                                                            */
/* !File            : HOTSENO2FLG_FCT1.C                                      */
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
/*   1 / HOTSENO2FLG_vidInitEveRst                                            */
/*   2 / HOTSENO2FLG_vidUsHotdiagFlgInit                                      */
/*   3 / HOTSENO2FLG_vidDsHotdiagFlgInit                                      */
/*   4 / HOTSENO2FLG_vidInitOutput                                            */
/*   5 / HOTSENO2FLG_vidInitCrTR                                              */
/*   6 / HOTSENO2FLG_vidInitHotSenO2UsFlg                                     */
/*   7 / HOTSENO2FLG_vidInitHotSenO2DsFlg                                     */
/*   8 / HOTSENO2FLG_vidHotSenO2Volt                                          */
/*   9 / HOTSENO2FLG_vidHotSenO2Fil                                           */
/*   10 / HOTSENO2FLG_vidDetSenO2Us                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 06204 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/HOTSENO2FLG/HOTSENO2FLG_$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   10 Aug 2011 $*/
/* $Author::   wbouach                                $$Date::   10 Aug 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "HOTSENO2FLG.H"
#include "HOTSENO2FLG_L.H"
#include "HOTSENO2FLG_IM.H"
#include "GDGAR.H"
#include "SWFAIL.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidInitEveRst                                  */
/* !Description :  Selon la stratégie de détection sonde lambda chaude basée  */
/*                 sur les états de chauffage, à l’initialisation du          */
/*                 calculateur,les sondes amont et aval sont déclarées        */
/*                 froides.                                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidUsHotdiagFlgInit();                       */
/*  extf argret void HOTSENO2FLG_vidDsHotdiagFlgInit();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidInitEveRst(void)
{
   HOTSENO2FLG_vidUsHotdiagFlgInit();
   HOTSENO2FLG_vidDsHotdiagFlgInit();

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidUsHotdiagFlgInit                            */
/* !Description :  .A l’initialisation du calculateur la sonde amont est      */
/*                 déclarée froide,: LsSys_bLsUsHeatOkDiag et                 */
/*                 LsSys_bLsUsHeatOk valent 0.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsSys_bLsUsMainOxCHeatOkdiag;                              */
/*  output boolean LsSys_bLsUsMainOxCHeatOk;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidUsHotdiagFlgInit(void)
{
   VEMS_vidSET(LsSys_bLsUsMainOxCHeatOkdiag, 0);
   VEMS_vidSET(LsSys_bLsUsMainOxCHeatOk, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDsHotdiagFlgInit                            */
/* !Description :  A l’initialisation du calculateur la sonde aval est        */
/*                 déclarée froide : LsSys_bLsDsHeatOkDiag et                 */
/*                 LsSys_bLsDsHeatOk valent 0.                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsSys_bLsDsMainOxCHeatOkdiag;                              */
/*  output boolean LsSys_bLsDsMainOxCHeatOk;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDsHotdiagFlgInit(void)
{
   VEMS_vidSET(LsSys_bLsDsMainOxCHeatOkdiag, 0);
   VEMS_vidSET(LsSys_bLsDsMainOxCHeatOk, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidInitOutput                                  */
/* !Description :  Initialisation des variables internes et des sorties du    */
/*                 module.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Lshd_up_stream_lbda_sensor_hot;                            */
/*  output boolean Lshd_down_stream_lbda_sensor_hot;                          */
/*  output uint16 Lshd_voltage_upstr_sens_filtered;                           */
/*  output uint16 Lshd_dwn_lbda_sens_heat_count;                              */
/*  output uint16 Lshd_voltage_dnstr_sens_filtered;                           */
/*  output uint16 Lshd_up_lbda_sens_heat_count;                               */
/*  output uint32 HOTSENO2FLG_u32VoltageUsFiltMem;                            */
/*  output uint32 HOTSENO2FLG_u32VoltageDsFiltMem;                            */
/*  output boolean LsSys_bLsUsHeatOk;                                         */
/*  output boolean LsSys_bLsDsHeatOk;                                         */
/*  output uint16 LsSys_tiLsDsDlyHeat;                                        */
/*  output uint16 LsSys_tiLsUsDlyHeat;                                        */
/*  output uint8 HOTSENO2FLG_u8UsMainOxCHeatPrev;                             */
/*  output uint8 HOTSENO2FLG_u8DsMainOxCHeatPrev;                             */
/*  output boolean HOTSENO2FLG_bInitTimer2Prev;                               */
/*  output boolean HOTSENO2FLG_bInitTimer3Prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidInitOutput(void)
{
   VEMS_vidSET(Lshd_up_stream_lbda_sensor_hot, 0);
   VEMS_vidSET(Lshd_down_stream_lbda_sensor_hot, 0);
   VEMS_vidSET(Lshd_voltage_upstr_sens_filtered, 0);
   VEMS_vidSET(Lshd_dwn_lbda_sens_heat_count, 0);
   VEMS_vidSET(Lshd_voltage_dnstr_sens_filtered, 0);
   VEMS_vidSET(Lshd_up_lbda_sens_heat_count, 0);
   HOTSENO2FLG_u32VoltageUsFiltMem = 0;
   HOTSENO2FLG_u32VoltageDsFiltMem = 0;
   LsSys_bLsUsHeatOk = 0;
   LsSys_bLsDsHeatOk = 0;
   LsSys_tiLsDsDlyHeat = 0;
   LsSys_tiLsUsDlyHeat = 0;
   HOTSENO2FLG_u8UsMainOxCHeatPrev = 0;
   HOTSENO2FLG_u8DsMainOxCHeatPrev = 0;
   HOTSENO2FLG_bInitTimer2Prev = 0;
   HOTSENO2FLG_bInitTimer3Prev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidInitCrTR                                    */
/* !Description :   Lorsque la stratégie de détection des sondes chaudes est  */
/*                 basée est la valeur des tensions sondes, les variables sont*/
/*                 initialisées au démarrage du moteur.Les sondes sont        */
/*                 déclarées froides.                                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidInitHotSenO2UsFlg();                      */
/*  extf argret void HOTSENO2FLG_vidInitHotSenO2DsFlg();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidInitCrTR(void)
{
   HOTSENO2FLG_vidInitHotSenO2UsFlg();
   HOTSENO2FLG_vidInitHotSenO2DsFlg();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidInitHotSenO2UsFlg                           */
/* !Description :  Lorsque la stratégie de détection de sonde amont chaude est*/
/*                 basée sur la tension sonde et lorsque le moteur démarre la */
/*                 sonde amont doit être déclarée froideet le compteur associé*/
/*                 à la détection de sonde chaude doit être                   */
/*                 Lshd_up_lbda_sens_heat_delay.                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lshd_up_lbda_sens_heat_delay;                                */
/*  output boolean Lshd_up_stream_lbda_sensor_hot;                            */
/*  output uint16 Lshd_up_lbda_sens_heat_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidInitHotSenO2UsFlg(void)
{
   uint16 u16Local_sens_heat_count;


   VEMS_vidSET(Lshd_up_stream_lbda_sensor_hot, 0);
   u16Local_sens_heat_count =
      (uint16)MATHSRV_udtMIN(Lshd_up_lbda_sens_heat_delay, 20470);
   VEMS_vidSET(Lshd_up_lbda_sens_heat_count, u16Local_sens_heat_count);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidInitHotSenO2DsFlg                           */
/* !Description :   Lorsque la stratégie de détection de sonde aval chaude est*/
/*                 basée sur la tension sonde et lorsque le moteur démarre,la */
/*                 sonde aval doit être déclarée froide et le compteur associé*/
/*                 à la détection de sonde chaude                             */
/*                 Lshd_dwn_lbda_sens_heat_delay.                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lshd_dwn_lbda_sens_heat_delay;                               */
/*  output boolean Lshd_down_stream_lbda_sensor_hot;                          */
/*  output uint16 Lshd_dwn_lbda_sens_heat_count;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidInitHotSenO2DsFlg(void)
{
   uint16 u16Local_sens_heat_count;


   VEMS_vidSET(Lshd_down_stream_lbda_sensor_hot, 0);
   u16Local_sens_heat_count =
      (uint16)MATHSRV_udtMIN(Lshd_dwn_lbda_sens_heat_delay, 20470);
   VEMS_vidSET(Lshd_dwn_lbda_sens_heat_count, u16Local_sens_heat_count);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidHotSenO2Volt                                */
/* !Description :  Fonction de calcul du filtrage de Tension_sonde_amont      */
/*                 (Tension_sonde_aval)                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HOTSENO2FLG_vidHotSenO2Fil();                            */
/*  extf argret void HOTSENO2FLG_vidDetSenO2Us();                             */
/*  extf argret void HOTSENO2FLG_vidDetSenO2Ds();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidHotSenO2Volt(void)
{
   HOTSENO2FLG_vidHotSenO2Fil();
   HOTSENO2FLG_vidDetSenO2Us();
   HOTSENO2FLG_vidDetSenO2Ds();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidHotSenO2Fil                                 */
/* !Description :  filtrage de Tension_sonde_amont  (Tension_sonde_aval) pour */
/*                 créer Lshd_voltage_upstr_sens_filtered                     */
/*                 (Lshd_voltage_dnstr_sens_filtered)                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Lshd_sensor_voltage_filter_gain;                              */
/*  input uint32 HOTSENO2FLG_u32VoltageDsFiltMem;                             */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint32 HOTSENO2FLG_u32VoltageUsFiltMem;                             */
/*  output uint16 Lshd_voltage_dnstr_sens_filtered;                           */
/*  output uint16 Lshd_voltage_upstr_sens_filtered;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidHotSenO2Fil(void)
{
   uint16  u16LocalLshdFiltAval;
   uint16  u16LocalLshdFiltAmont;
   uint16  u16LocalLshd_voltage_dnstr_sens;
   uint16  u16LocalTension_sonde_aval;
   uint16  u16LocalLshd_voltage_upstr_sens;
   uint16  u16LocalTension_sonde_amont;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   u16LocalLshdFiltAval =
      MATHSRV_u16FirstOrderFilterGu8(Lshd_sensor_voltage_filter_gain,
                                     &HOTSENO2FLG_u32VoltageDsFiltMem,
                                     u16LocalTension_sonde_aval);
   u16LocalLshd_voltage_dnstr_sens =
      (uint16)MATHSRV_udtMIN(u16LocalLshdFiltAval, 1023);
   VEMS_vidSET(Lshd_voltage_dnstr_sens_filtered,
               u16LocalLshd_voltage_dnstr_sens);

   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   u16LocalLshdFiltAmont =
      MATHSRV_u16FirstOrderFilterGu8(Lshd_sensor_voltage_filter_gain,
                                     &HOTSENO2FLG_u32VoltageUsFiltMem,
                                     u16LocalTension_sonde_amont);
   u16LocalLshd_voltage_upstr_sens =
      (uint16)MATHSRV_udtMIN(u16LocalLshdFiltAmont, 1023);
   VEMS_vidSET(Lshd_voltage_upstr_sens_filtered,
               u16LocalLshd_voltage_upstr_sens);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HOTSENO2FLG_vidDetSenO2Us                                  */
/* !Description :  vérification que  la  tension de  la sonde à oxygène se    */
/*                 trouve hors d’une plage de  tension.                       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HOTSENO2FLG_vidDetSenO2UsCold();                         */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void HOTSENO2FLG_vidDetSenO2UsHot();                          */
/*  input boolean Lshd_up_stream_lbda_sensor_hot;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HOTSENO2FLG_vidDetSenO2Us(void)
{
   boolean bLocalInhHotSenO2FlgUs;
   boolean bLocalLshd_up_stream_sensor_hot;


   VEMS_vidGET(Lshd_up_stream_lbda_sensor_hot, bLocalLshd_up_stream_sensor_hot);
   if (bLocalLshd_up_stream_sensor_hot != 0)
   {
      HOTSENO2FLG_vidDetSenO2UsCold();
   }
   else
   {
      bLocalInhHotSenO2FlgUs = GDGAR_bGetFRM(FRM_FRM_INHHOTSENO2FLGUS);
      if (bLocalInhHotSenO2FlgUs == 0)
      {
         HOTSENO2FLG_vidDetSenO2UsHot();
      }
   }
}
/*------------------------------- end of file --------------------------------*/