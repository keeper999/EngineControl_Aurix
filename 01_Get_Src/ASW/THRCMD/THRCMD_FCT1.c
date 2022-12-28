/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRCMD                                                  */
/* !Description     : THRCMD Component                                        */
/*                                                                            */
/* !Module          : THRCMD                                                  */
/* !Description     : Commande et diagnostics du driver du papillon motorisé  */
/*                                                                            */
/* !File            : THRCMD_FCT1.c                                           */
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
/*   1 / THRCMD_vidInitOutput                                                 */
/*   2 / THRCMD_vidDriverInh                                                  */
/*   3 / THRCMD_vidComptagePanne                                              */
/*   4 / THRCMD_vidCommandTpac                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6587801 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRCMD/THRCMD_FCT1.c_v        $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   02 Jun 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRCMD.h"
#include "THRCMD_L.h"
#include "THRCMD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCMD_vidInitOutput                                       */
/* !Description :  THRCMD Initialization function                             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 Commande_bpm_pwm_rco;                                       */
/*  output uint32 Delai_freewheeling_bpm;                                     */
/*  output boolean Demande_inhibition_hbridge;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCMD_vidInitOutput(void)
{
   /* Output initialization  */
   VEMS_vidSET(Commande_bpm_pwm_rco, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCMD_vidDriverInh                                        */
/* !Description :  Ce bloc décrit l’activation et la désactivation par le LDA */
/*                 du composant LDB qui pilote le Hbridge HBHAL.Par la même,  */
/*                 cela gère la pin d’inhibition du pont en H par le MCP( pin */
/*                 DIS).                                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Srv_bInhThr;                                                */
/*  input boolean Tpc_throt_on_off_request;                                   */
/*  input boolean Thr_bInhMngThrServo;                                        */
/*  input boolean ThrCmd_bForcFreeWheeling_C;                                 */
/*  input uint32 Tpc_free_wheeling_delay;                                     */
/*  input uint32 ThrCmd_tiFreeWheeling;                                       */
/*  output boolean Tpc_throt_on_off_request;                                  */
/*  output boolean Demande_inhibition_hbridge;                                */
/*  output uint32 ThrCmd_tiFreeWheeling;                                      */
/*  output uint32 Delai_freewheeling_bpm;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCMD_vidDriverInh(void)
{
   boolean bLocalThr_bInhMngThrServo;
   boolean bLocalSrv_bInhThr;
   uint8   u8LocalTpac_throttle_control_sta;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_sta);
   VEMS_vidGET(Srv_bInhThr, bLocalSrv_bInhThr);
   if (  (u8LocalTpac_throttle_control_sta == TPAC_LIMP_HOME)
      || (u8LocalTpac_throttle_control_sta == TPAC_WAIT_FOR_ADC)
      || (bLocalSrv_bInhThr != 0))
   {
      Tpc_throt_on_off_request = 1;
   }
   else
   {
      Tpc_throt_on_off_request = 0;
   }
   VEMS_vidSET(Demande_inhibition_hbridge, Tpc_throt_on_off_request);

   VEMS_vidGET(Thr_bInhMngThrServo, bLocalThr_bInhMngThrServo);
   if (  (ThrCmd_bForcFreeWheeling_C != 0)
      || (bLocalThr_bInhMngThrServo == 0))
   {
      ThrCmd_tiFreeWheeling = MATHSRV_udtMIN(Tpc_free_wheeling_delay,
                                             4290000000UL);
   }
   else
   {
      ThrCmd_tiFreeWheeling = 0;
   }
   VEMS_vidSET(Delai_freewheeling_bpm, ThrCmd_tiFreeWheeling);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCMD_vidComptagePanne                                    */
/* !Description :  function which manages the default of the throttle.        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_surcharge_bpm;                                          */
/*  input boolean Dena_surcharge_bpm;                                         */
/*  input boolean Dft_composant_bpm;                                          */
/*  input boolean Dena_composant_bpm;                                         */
/*  output boolean Thr_bDgoOvld_ThrCmd;                                       */
/*  output boolean Thr_bMonRunOvld_ThrCmd;                                    */
/*  output boolean Thr_bDgoCpt_ThrCmd;                                        */
/*  output boolean Thr_bMonRunCpt_ThrCmd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCMD_vidComptagePanne(void)
{
   boolean bLocalDft_surcharge_bpm;
   boolean bLocalDena_surcharge_bpm;
   boolean bLocalDft_composant_bpm;
   boolean bLocalDena_composant_bpm;


   VEMS_vidGET(Dft_surcharge_bpm, bLocalDft_surcharge_bpm);
   VEMS_vidGET(Dena_surcharge_bpm, bLocalDena_surcharge_bpm);
   VEMS_vidGET(Dft_composant_bpm, bLocalDft_composant_bpm);
   VEMS_vidGET(Dena_composant_bpm, bLocalDena_composant_bpm);

   Thr_bDgoOvld_ThrCmd = bLocalDft_surcharge_bpm;
   Thr_bMonRunOvld_ThrCmd = bLocalDena_surcharge_bpm;
   Thr_bDgoCpt_ThrCmd = bLocalDft_composant_bpm;
   Thr_bMonRunCpt_ThrCmd = bLocalDena_composant_bpm;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCMD_vidCommandTpac                                      */
/* !Description :  function which gives the command to the throttle.          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Tpac_request_thr_jc_duty_cycle;                              */
/*  input sint16 Tpac_request_throttle_duty_cycle;                            */
/*  input boolean Tpac_thr_servoing_typ_select;                               */
/*  input sint16 Tpac_throt_duty_cycle_to_apply;                              */
/*  output sint16 Tpac_throt_duty_cycle_to_apply;                             */
/*  output sint16 Commande_bpm_pwm_rco;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCMD_vidCommandTpac(void)
{
   sint16 s16LocalTpac_request_thr_jc;
   sint16 s16LocalTpac_request_throttle;


   VEMS_vidGET(Tpac_request_thr_jc_duty_cycle, s16LocalTpac_request_thr_jc);
   VEMS_vidGET(Tpac_request_throttle_duty_cycle, s16LocalTpac_request_throttle);
   if (Tpac_thr_servoing_typ_select == 0)
   {
      Tpac_throt_duty_cycle_to_apply =
         (sint16)MATHSRV_udtCLAMP(s16LocalTpac_request_throttle, -16384, 16384);
   }
   else
   {
      Tpac_throt_duty_cycle_to_apply =
         (sint16)MATHSRV_udtCLAMP(s16LocalTpac_request_thr_jc, -16384, 16384);
   }
   VEMS_vidSET(Commande_bpm_pwm_rco, Tpac_throt_duty_cycle_to_apply);
}
/*------------------------------ end of file ---------------------------------*/