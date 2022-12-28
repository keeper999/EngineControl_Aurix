/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CATMONIF                                                */
/* !Description     : CATMONIF component.                                     */
/*                                                                            */
/* !Module          : CATMONIF                                                */
/* !Description     : SPÉCIFICATION D'INTERFACE POUR LE DIAGNOSTIC CATALYSEUR */
/*                                                                            */
/* !File            : CATMONIF_FCT1.C                                         */
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
/*   1 / CATMONIF_vidInit                                                     */
/*   2 / CATMONIF_vidCatMonIf                                                 */
/*                                                                            */
/* !Reference   : V02 NT 12 04035 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#064360                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CATMONIF/CATMONIF_FCT1.C_v        $*/
/* $Revision::   1.0      $$Author::   cbanchie       $$Date::   19 May 2011 $*/
/* $Author::   cbanchie                               $$Date::   19 May 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"MATHSRV.h"
#include"CATMONIF.h"
#include"CATMONIF_L.h"
#include"CATMONIF_IM.h"
#include"GDGAR.h"
#include"VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CATMONIF_vidInit                                           */
/* !Description :  Fonction initialise les sorties du module.                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean GDU_bEndDiagStORng_DsPlausFco;                             */
/*  output boolean GDU_bEndDiagStORng_OxyApvPerd;                             */
/*  output boolean GDU_bEndDiagStORng_OxySensPrd;                             */
/*  output boolean GDU_bEndDiagStORng_UsPlausFco;                             */
/*  output boolean GDU_bEndDiagStORngLf_Afl_swc;                              */
/*  output boolean GDU_bEndDiagStORngLf_Afr_swc;                              */
/*  output boolean GDU_bEndDiagStORng_DsHt_swc;                               */
/*  output boolean GDU_bEndDiagStORng_UsHt_swc;                               */
/*  output boolean Lshd_down_strm_lbda_sens_hot;                              */
/*  output boolean Lshd_up_strm_lbda_sens_hot;                                */
/*  output GDFRM_tenuGDUState GDU_stDgoORngLf_Afl_swc;                        */
/*  output GDFRM_tenuGDUState GDU_stDgoORngLf_Afr_swc;                        */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_DsHt_swc;                         */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_DsPlsFco_swc;                     */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_OxyApvPrd_swc;                    */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_OxySenPrd_swc;                    */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_UsHt_swc;                         */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_UsPlsFco_swc;                     */
/*  output uint8 Monitor_fdbk_cond_stat_swc;                                  */
/*  output uint16 AirSys_mfAirMesThrEstim_swc;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CATMONIF_vidInit(void)
{
   VEMS_vidSET(GDU_bEndDiagStORng_DsPlausFco, 0);
   VEMS_vidSET(GDU_bEndDiagStORng_OxyApvPerd, 0);
   VEMS_vidSET(GDU_bEndDiagStORng_OxySensPrd, 0);
   VEMS_vidSET(GDU_bEndDiagStORng_UsPlausFco, 0);
   VEMS_vidSET(GDU_bEndDiagStORngLf_Afl_swc, 0);
   VEMS_vidSET(GDU_bEndDiagStORngLf_Afr_swc, 0);
   VEMS_vidSET(GDU_bEndDiagStORng_DsHt_swc, 0);
   VEMS_vidSET(GDU_bEndDiagStORng_UsHt_swc, 0);
   VEMS_vidSET(Lshd_down_strm_lbda_sens_hot, 0);
   VEMS_vidSET(Lshd_up_strm_lbda_sens_hot, 0);
   VEMS_vidSET(GDU_stDgoORngLf_Afl_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORngLf_Afr_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORng_DsHt_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORng_DsPlsFco_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORng_OxyApvPrd_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORng_OxySenPrd_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORng_UsHt_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(GDU_stDgoORng_UsPlsFco_swc, GDU_ETAT_ABSENT);
   VEMS_vidSET(Monitor_fdbk_cond_stat_swc, WAITING_TO_START_FEEDBACK);
   VEMS_vidSET(AirSys_mfAirMesThrEstim_swc, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CATMONIF_vidCatMonIf                                       */
/* !Description :  cette fonction réaliser pour des variables d’entrée du     */
/*                 diagnostic catalyseur passif et actif                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Monitor_feedback_conds_state;                                 */
/*  input boolean LsSys_bLsDsMainOxCHeatOkdiag;                               */
/*  input boolean LsSys_bLsUsMainOxCHeatOkdiag;                               */
/*  input uint16 AirSys_mfAirMesThrEstim;                                     */
/*  output boolean GDU_bEndDiagStORng_DsPlausFco;                             */
/*  output boolean GDU_bEndDiagStORng_OxyApvPerd;                             */
/*  output boolean GDU_bEndDiagStORng_OxySensPrd;                             */
/*  output boolean GDU_bEndDiagStORng_UsPlausFco;                             */
/*  output boolean GDU_bEndDiagStORngLf_Afl_swc;                              */
/*  output boolean GDU_bEndDiagStORngLf_Afr_swc;                              */
/*  output boolean GDU_bEndDiagStORng_DsHt_swc;                               */
/*  output boolean GDU_bEndDiagStORng_UsHt_swc;                               */
/*  output boolean Lshd_down_strm_lbda_sens_hot;                              */
/*  output boolean Lshd_up_strm_lbda_sens_hot;                                */
/*  output GDFRM_tenuGDUState GDU_stDgoORngLf_Afl_swc;                        */
/*  output GDFRM_tenuGDUState GDU_stDgoORngLf_Afr_swc;                        */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_DsHt_swc;                         */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_DsPlsFco_swc;                     */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_OxyApvPrd_swc;                    */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_OxySenPrd_swc;                    */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_UsHt_swc;                         */
/*  output GDFRM_tenuGDUState GDU_stDgoORng_UsPlsFco_swc;                     */
/*  output uint8 Monitor_fdbk_cond_stat_swc;                                  */
/*  output uint16 AirSys_mfAirMesThrEstim_swc;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CATMONIF_vidCatMonIf(void)
{
   boolean              bLocalGDUbEndDgStrORngDsPlausFco;
   boolean              bLocalGDUbEndDgStrORngOxyApvPerd;
   boolean              bLocalGDUbEndDgStrORngOxySenPerd;
   boolean              bLocalGDUbEndDgStrORngUsPlausFco;
   boolean              bLocalGDUbEndDgStrtORngLfbk_Afl;
   boolean              bLocalGDUbEndDgStrtORngLfbk_Afr;
   boolean              bLocalGDUbEndDgStrtORng_DsHeat;
   boolean              bLocalGDUbEndDgStrtORng_UsHeat;
   boolean              bLocalLsSysLsDsMainOxCHeatOkdiag;
   boolean              bLocalLsSysLsUsMainOxCHeatOkdiag;
   uint8                u8LocalMonitor_feedback_conds_st;
   uint16               u16LocalAirSys_mfAirMesThrEstim;
   uint16               u16LocalAirSys_mfAirMsThrEstm_swc;
   GDFRM_tenuGDUState   stDgoORngLfbk_Afl;
   GDFRM_tenuGDUState   stDgoORngLfbk_Afr;
   GDFRM_tenuGDUState   stDgoORng_DsHeat;
   GDFRM_tenuGDUState   stDgoORng_DsPlausFco;
   GDFRM_tenuGDUState   stDgoORng_OxyApvPerd;
   GDFRM_tenuGDUState   stDgoORng_OxySensPerd;
   GDFRM_tenuGDUState   stDgoORng_UsHeat;
   GDFRM_tenuGDUState   stDgoORng_UsPlausFco;


   bLocalGDUbEndDgStrORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);
   bLocalGDUbEndDgStrORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalGDUbEndDgStrORngOxySenPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalGDUbEndDgStrORngUsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USPLAUSFCO);
   bLocalGDUbEndDgStrtORngLfbk_Afl =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNGLFBK_AFL);
   bLocalGDUbEndDgStrtORngLfbk_Afr =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNGLFBK_AFR);
   bLocalGDUbEndDgStrtORng_DsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalGDUbEndDgStrtORng_UsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);

   stDgoORngLfbk_Afl = GDGAR_tenuGetStDgo(GD_DFT_ORNGLFBK_AFL);
   stDgoORngLfbk_Afr = GDGAR_tenuGetStDgo(GD_DFT_ORNGLFBK_AFR);
   stDgoORng_DsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   stDgoORng_DsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);
   stDgoORng_OxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   stDgoORng_OxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   stDgoORng_UsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
   stDgoORng_UsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USPLAUSFCO);

   VEMS_vidGET(Monitor_feedback_conds_state, u8LocalMonitor_feedback_conds_st);
   VEMS_vidGET(LsSys_bLsDsMainOxCHeatOkdiag, bLocalLsSysLsDsMainOxCHeatOkdiag);
   VEMS_vidGET(LsSys_bLsUsMainOxCHeatOkdiag, bLocalLsSysLsUsMainOxCHeatOkdiag);
   VEMS_vidGET(AirSys_mfAirMesThrEstim, u16LocalAirSys_mfAirMesThrEstim);

   VEMS_vidSET(GDU_bEndDiagStORng_DsPlausFco, bLocalGDUbEndDgStrORngDsPlausFco);
   VEMS_vidSET(GDU_bEndDiagStORng_OxyApvPerd, bLocalGDUbEndDgStrORngOxyApvPerd);
   VEMS_vidSET(GDU_bEndDiagStORng_OxySensPrd, bLocalGDUbEndDgStrORngOxySenPerd);
   VEMS_vidSET(GDU_bEndDiagStORng_UsPlausFco, bLocalGDUbEndDgStrORngUsPlausFco);
   VEMS_vidSET(GDU_bEndDiagStORngLf_Afl_swc, bLocalGDUbEndDgStrtORngLfbk_Afl);
   VEMS_vidSET(GDU_bEndDiagStORngLf_Afr_swc, bLocalGDUbEndDgStrtORngLfbk_Afr);
   VEMS_vidSET(GDU_bEndDiagStORng_DsHt_swc, bLocalGDUbEndDgStrtORng_DsHeat);
   VEMS_vidSET(GDU_bEndDiagStORng_UsHt_swc, bLocalGDUbEndDgStrtORng_UsHeat);
   VEMS_vidSET(Lshd_down_strm_lbda_sens_hot, bLocalLsSysLsDsMainOxCHeatOkdiag);
   VEMS_vidSET(Lshd_up_strm_lbda_sens_hot, bLocalLsSysLsUsMainOxCHeatOkdiag);
   VEMS_vidSET(GDU_stDgoORngLf_Afl_swc, stDgoORngLfbk_Afl);
   VEMS_vidSET(GDU_stDgoORngLf_Afr_swc, stDgoORngLfbk_Afr);
   VEMS_vidSET(GDU_stDgoORng_DsHt_swc, stDgoORng_DsHeat);
   VEMS_vidSET(GDU_stDgoORng_DsPlsFco_swc, stDgoORng_DsPlausFco);
   VEMS_vidSET(GDU_stDgoORng_OxyApvPrd_swc, stDgoORng_OxyApvPerd);
   VEMS_vidSET(GDU_stDgoORng_OxySenPrd_swc, stDgoORng_OxySensPerd);
   VEMS_vidSET(GDU_stDgoORng_UsHt_swc, stDgoORng_UsHeat);
   VEMS_vidSET(GDU_stDgoORng_UsPlsFco_swc, stDgoORng_UsPlausFco);
   VEMS_vidSET(Monitor_fdbk_cond_stat_swc, u8LocalMonitor_feedback_conds_st);
   u16LocalAirSys_mfAirMsThrEstm_swc =
      (uint16)(((25 * u16LocalAirSys_mfAirMesThrEstim) + 16) / 32);
   u16LocalAirSys_mfAirMsThrEstm_swc =
      (uint16)MATHSRV_udtMIN(u16LocalAirSys_mfAirMsThrEstm_swc, 30000);
   VEMS_vidSET(AirSys_mfAirMesThrEstim_swc, u16LocalAirSys_mfAirMsThrEstm_swc);
}

/*------------------------------ end of file ---------------------------------*/