/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRMCUT                                                 */
/* !Description     : THRMCUT Component                                       */
/*                                                                            */
/* !Module          : THRMCUT                                                 */
/* !Description     : DETECTION DE MICRO-COUPURES CMM/BPM ET MODE PALLIATIF   */
/*                                                                            */
/* !File            : THRMCUT_FCT2.C                                          */
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
/*   1 / THRMCUT_vidThrSpLrnDeac                                              */
/*   2 / THRMCUT_vidThrSpLrnDeacEna                                           */
/*                                                                            */
/* !Reference: V02 NT 08 04513 / 05                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRMCUT/THRMCUT_FCT2.C_v      $*/
/* $Revision::   1.3      $$Author::   acabresp       $$Date::   31 Mar 2010 $*/
/* $Author::   acabresp                               $$Date::   31 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRMCUT.h"
#include "THRMCUT_L.h"
#include "THRMCUT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidThrSpLrnDeac                                     */
/* !Description : Cette stratégie permet d’abandonner le process              */
/*                d’apprentissage en cas de détection de microcoupures.       */
/* !Number      : FCT2.1                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void THRMCUT_vidThrSpLrnDeacEna();                           */
/*   input boolean Tps_1_mcut_det_manu_inh;                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidThrSpLrnDeac(void)
{
   if (Tps_1_mcut_det_manu_inh == 0 )
   {
      THRMCUT_vidThrSpLrnDeacEna();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidThrSpLrnDeacEna                                  */
/* !Description : Process d’apprentissage, production de Thr_bDeacThrStopLrn. */
/* !Number      : FCT2.2                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input st01 Tpac_throttle_control_state;                                  */
/*   input bool TPAC_HIGH_THRUST_SEARCH;                                      */
/*   input bool TPAC_CLOSING_RAMP;                                            */
/*   input boolean Throttle_pos_ref_freeze_enab;                              */
/*   output boolean Thr_bDeacThrStopLrn;                                      */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidThrSpLrnDeacEna(void)
{
   boolean bLocalThrottle_pos_ref_frz_ena;
   uint8   u8LocalTpac_thr_control_state;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);

   if (  (u8LocalTpac_thr_control_state == TPAC_HIGH_THRUST_SEARCH)
      || (u8LocalTpac_thr_control_state == TPAC_CLOSING_RAMP))
   {
      VEMS_vidGET(Throttle_pos_ref_freeze_enab, bLocalThrottle_pos_ref_frz_ena);
      if (bLocalThrottle_pos_ref_frz_ena != 0)
      {
         VEMS_vidSET(Thr_bDeacThrStopLrn, 1);
      }
   }
   else
   {
      VEMS_vidSET(Thr_bDeacThrStopLrn, 0);
   }
}
/*------------------------------ End of file ---------------------------------*/