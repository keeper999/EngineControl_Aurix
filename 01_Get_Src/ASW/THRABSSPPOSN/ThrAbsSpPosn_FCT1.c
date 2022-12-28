/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRABSSPPOSN                                            */
/* !Description     : THRABSSPPOSN component                                  */
/*                                                                            */
/* !Module          : THRABSSPPOSN                                            */
/* !Description     : Calcul de la Consigne de Position Papillon Absolue      */
/*                                                                            */
/* !File            : THRABSSPPOSN_FCT1.C                                     */
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
/*   1 / THRABSSPPOSN_vidInitOutput                                           */
/*   2 / THRABSSPPOSN_vidInitThrotPosRef                                      */
/*   3 / THRABSSPPOSN_vidCompOpenThresh                                       */
/*   4 / THRABSSPPOSN_vidComputeAbsRef                                        */
/*   5 / THRABSSPPOSN_vidModifThrustPos                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 04493 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRABSSPPOSN/ThrAbsSpPosn_FCT1$*/
/* $Revision::   1.5      $$Author::   ACHEBINO       $$Date::   30 Jun 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRABSSPPOSN.h"
#include "THRABSSPPOSN_L.h"
#include "THRABSSPPOSN_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRABSSPPOSN_vidInitOutput                                 */
/* !Description :  Module initialization                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Tpac_ecu_temp_protected;                                   */
/*  output uint16 Tpac_throttle_open_thresh;                                  */
/*  output boolean Tpac_ecu_temp_protect_mode;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRABSSPPOSN_vidInitOutput(void)
{
   /* Output initialization */
   VEMS_vidSET(Tpac_ecu_temp_protected, 0);
   /* Internals initialization */
   Tpac_throttle_open_thresh = 0;
   Tpac_ecu_temp_protect_mode = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRABSSPPOSN_vidInitThrotPosRef                            */
/* !Description :  Sur Reset, on initialise la consigne absolue à la somme de */
/*                 la consigne relative et de la position de la butée basse.  */
/*                 La consigne relative étant initialisée à la position       */
/*                 corrigée, on démarre ainsi l’asservissement à partir de la */
/*                 position papillon.                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Dtc_throttle_position_reference;                             */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  output uint16 Tpac_throttle_position_reference;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRABSSPPOSN_vidInitThrotPosRef(void)
{
   uint16 u16LocalDtc_throttle_pos_ref;
   uint16 u16LocalSsm_closed_throttle_pos;
   uint16 u16LocalTpac_throttle_pos_ref;
   uint32 u32LocalInitPos;


   VEMS_vidGET(Dtc_throttle_position_reference, u16LocalDtc_throttle_pos_ref);
   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_closed_throttle_pos);

   u32LocalInitPos = u16LocalDtc_throttle_pos_ref
                   + u16LocalSsm_closed_throttle_pos;
   u16LocalTpac_throttle_pos_ref = (uint16)MATHSRV_udtMIN(u32LocalInitPos,
                                                          1024);
   VEMS_vidSET(Tpac_throttle_position_reference, u16LocalTpac_throttle_pos_ref);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRABSSPPOSN_vidCompOpenThresh                             */
/* !Description :  Le seuil maximal de position de consigne papillon est      */
/*                 soumis à deux contraintes : garde par rapport à la butée   */
/*                 haute et consommation de courant pour des températures ECU */
/*                 extrêmes.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ecut_ecu_temperature;                                         */
/*  input uint8 Tpac_ecu_temp_thresh_warm;                                    */
/*  input uint16 Tpac_throttle_open_thresh_warm;                              */
/*  input uint8 Tpac_ecu_temp_thresh_cold;                                    */
/*  input uint16 Tpac_throttle_open_thresh_cold;                              */
/*  input uint16 Tpac_throttle_open_thresh;                                   */
/*  output uint16 Tpac_throttle_open_thresh;                                  */
/*  output boolean Tpac_ecu_temp_protect_mode;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRABSSPPOSN_vidCompOpenThresh(void)
{
   uint8   u8LocalEcut_ecu_temperature;
   uint16  u16LocalTpac_throttl_open_thresh;


   VEMS_vidGET(Ecut_ecu_temperature, u8LocalEcut_ecu_temperature);
   if (u8LocalEcut_ecu_temperature > Tpac_ecu_temp_thresh_warm)
   {
      u16LocalTpac_throttl_open_thresh = Tpac_throttle_open_thresh_warm;
   }
   else
   {
      if (u8LocalEcut_ecu_temperature <= Tpac_ecu_temp_thresh_cold)
      {
         u16LocalTpac_throttl_open_thresh = Tpac_throttle_open_thresh_cold;
      }
      else
      {
         u16LocalTpac_throttl_open_thresh = Tpac_throttle_open_thresh;
      }
   }
   Tpac_throttle_open_thresh =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_throttl_open_thresh, 1024);
   if (Tpac_throttle_open_thresh == Tpac_throttle_open_thresh_warm)
   {
      Tpac_ecu_temp_protect_mode = 1;
   }
   else
   {
      Tpac_ecu_temp_protect_mode = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRABSSPPOSN_vidComputeAbsRef                              */
/* !Description :  Ce processus est calculé chaque 8ms ou sur front descendant*/
/*                 de  Tpac_open_loop_control et  fourni la consigne absolue  */
/*                 de position papillon en fonction de la garde à la butée    */
/*                 basse, de la garde à la butée haute et de l’état de        */
/*                 l’automate d'asservissement.                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint16 Ssm_limp_home_throttle_pos;                                  */
/*  input uint16 Dtc_throttle_position_reference;                             */
/*  input boolean Tpac_closed_throttle_manu_inh;                              */
/*  input uint16 Tpac_throttle_closed_thresh;                                 */
/*  input uint16 Ssm_closed_throttle_pos_tmp;                                 */
/*  input uint16 Ssm_open_throttle_pos_tmp;                                   */
/*  input uint16 Tpac_throttle_open_thresh;                                   */
/*  input boolean Tpac_ecu_temp_protect_mode;                                 */
/*  output uint16 Tpac_throttle_position_reference;                           */
/*  output boolean Tpac_ecu_temp_protected;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRABSSPPOSN_vidComputeAbsRef(void)
{
   boolean bLocalTpac_ecu_temp_protected;
   uint8   u8LocalTpac_throttle_control_st;
   uint16  u16LocalDtc_throttle_pos_ref;
   uint16  u16LocalSsm_limp_home_throttle_p;
   uint16  u16LocalThrPos;
   uint16  u16LocalOpenThPos;
   sint32  s32LocalOpenThPos;
   uint32  u32LocalThrPos;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_home_throttle_p);
   VEMS_vidGET(Dtc_throttle_position_reference, u16LocalDtc_throttle_pos_ref);
   if (u8LocalTpac_throttle_control_st == TPAC_LIMP_HOME)
   {
      u16LocalThrPos = u16LocalSsm_limp_home_throttle_p;
   }
   else
   {
      u16LocalThrPos = u16LocalDtc_throttle_pos_ref;
   }

   if (Tpac_closed_throttle_manu_inh == 0)
   {
      u16LocalThrPos = (uint16)MATHSRV_udtMAX(u16LocalThrPos,
                                              Tpac_throttle_closed_thresh);
   }
   u32LocalThrPos = u16LocalThrPos + Ssm_closed_throttle_pos_tmp;
   u16LocalThrPos = (uint16)MATHSRV_udtMIN(u32LocalThrPos, 1024 );
   s32LocalOpenThPos = (sint32)( Ssm_open_throttle_pos_tmp
                               - Tpac_throttle_open_thresh);
   u16LocalOpenThPos = (uint16)MATHSRV_udtCLAMP(s32LocalOpenThPos, 0, 1024);
   u16LocalThrPos = (uint16)MATHSRV_udtMIN(u16LocalThrPos, u16LocalOpenThPos);
   VEMS_vidSET(Tpac_throttle_position_reference, u16LocalThrPos);

   if (  (u16LocalThrPos == u16LocalOpenThPos)
      && (Tpac_ecu_temp_protect_mode != 0) )
   {
      bLocalTpac_ecu_temp_protected = 1;
   }
   else
   {
      bLocalTpac_ecu_temp_protected = 0;
   }
   VEMS_vidSET(Tpac_ecu_temp_protected, bLocalTpac_ecu_temp_protected);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRABSSPPOSN_vidModifThrustPos                             */
/* !Description :  Apprentissage en boucle fermée, les valeurs des butées     */
/*                 haute et basse sont modifiées afin de pouvoir générer une  */
/*                 consigne en dehors de la zone délimitée. Cela permet       */
/*                 d’assurer le contact et de contrôler le « couple appliqué »*/
/*                 sur la butée concernée.                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Thr_FLrnClCtl_bAcv;                                         */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  input uint16 Ssm_open_throttle_pos;                                       */
/*  input boolean Thr_bEnaClThrPosnByp_C;                                     */
/*  input uint16 Thr_ClThrPosnBypInLrn_C;                                     */
/*  input uint16 Thr_FLrnClCtl_posnLoThruLowr_C;                              */
/*  input uint16 Thr_FLrnClCtl_posnHiThruRise_C;                              */
/*  output uint16 Ssm_closed_throttle_pos_tmp;                                */
/*  output uint16 Ssm_open_throttle_pos_tmp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRABSSPPOSN_vidModifThrustPos(void)
{
   boolean bLocalThr_FLrnClCtl_bAcv;
   uint16  u16LocalSsm_closed_throttle_pos;
   uint16  u16LocalSsm_open_throttle_pos;
   uint32  u32LocalVar;
   sint32  s32LocalVar;

   VEMS_vidGET(Thr_FLrnClCtl_bAcv, bLocalThr_FLrnClCtl_bAcv);
   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_closed_throttle_pos);
   VEMS_vidGET(Ssm_open_throttle_pos, u16LocalSsm_open_throttle_pos);
   if (bLocalThr_FLrnClCtl_bAcv != 0)
   {
      if (Thr_bEnaClThrPosnByp_C != 0)
      {
         Ssm_closed_throttle_pos_tmp =
            (uint16)MATHSRV_udtMIN(Thr_ClThrPosnBypInLrn_C, 1024);
      }
      else
      {
         s32LocalVar = (sint32)(u16LocalSsm_closed_throttle_pos
                               - Thr_FLrnClCtl_posnLoThruLowr_C);
         Ssm_closed_throttle_pos_tmp = (uint16) MATHSRV_udtCLAMP(s32LocalVar,
                                                                 0, 1024);
      }

      u32LocalVar = (uint32)( u16LocalSsm_open_throttle_pos
                            + Thr_FLrnClCtl_posnHiThruRise_C);
      Ssm_open_throttle_pos_tmp = (uint16)MATHSRV_udtMIN(u32LocalVar,
                                                         1024);
   }
   else
   {
      Ssm_closed_throttle_pos_tmp =
         (uint16)MATHSRV_udtMIN(u16LocalSsm_closed_throttle_pos, 1024);
      Ssm_open_throttle_pos_tmp =
         (uint16)MATHSRV_udtMIN(u16LocalSsm_open_throttle_pos, 1024);
   }
}
/*------------------------------- end of file --------------------------------*/