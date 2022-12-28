/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTAB                                                 */
/* !Description     : ENGSTAB component.                                      */
/*                                                                            */
/* !Module          : ENGSTAB                                                 */
/* !Description     : Engine Stabilised                                       */
/*                                                                            */
/* !File            : ENGSTAB_FCT2.C                                          */
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
/*   1 / ENGSTAB_vidEngineConditions                                          */
/*   2 / ENGSTAB_vidEngineCondNotStable                                       */
/*   3 / ENGSTAB_vidEngineCondStable                                          */
/*   4 / ENGSTAB_vidEngCondTimer                                              */
/*   5 / ENGSTAB_vidEngCondTimerOut                                           */
/*   6 / ENGSTAB_vidVehicleNotRunning                                         */
/*                                                                            */
/* !Reference   : V02 NT 09 03216 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ENGSTAB/ENGSTAB_FCT2.C_v          $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   02 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   02 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGSTAB.h"
#include "ENGSTAB_L.h"
#include "ENGSTAB_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngineConditions                                */
/* !Description :  Cette fonction détermine la stabitilité du moteur : Si une */
/*                 seule de ces conditions est validée alors cela signifie que*/
/*                 le moteur n’est pas stable.                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Dv_detection_pied_leve_final;                               */
/*  input st07 Engine_running_state;                                          */
/*  input boolean Engine_load_not_stable;                                     */
/*  input boolean Gear_engaged_not_stable;                                    */
/*  output boolean Engine_conditions;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngineConditions(void)
{
   boolean bLocalDv_detect_pied_lev_final;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalVehicle_active_state;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Dv_detection_pied_leve_final, bLocalDv_detect_pied_lev_final);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (  (u8LocalVehicle_active_state != VS_RUNNING)
      || (u8LocalEngine_running_state == ERUN_ENGINE_OVERRUN_FCO)
      || (u8LocalEngine_running_state == ERUN_ENGINE_OVERSPEED_FCO)
      || (Engine_load_not_stable != 0)
      || (Gear_engaged_not_stable != 0)
      || (  (u8LocalEngine_running_state != ERUN_ON_IDLE)
         && (bLocalDv_detect_pied_lev_final != 0)))
   {
      Engine_conditions = 1;
   }
   else
   {
      Engine_conditions = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngineCondNotStable                             */
/* !Description :  Fonction permettant la mise à 0 des conditions de stabilité*/
/*                 du moteur et le rebouclage pour un fonctionnement autonome */
/*                 du test des conditions de stabilité.                       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Engine_stable_delay_c;                                        */
/*  output boolean Engine_stabilised;                                         */
/*  output uint8 Engine_stable_t_d_c;                                         */
/*  output boolean Engine_stabilised_eng_running;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngineCondNotStable(void)
{
   VEMS_vidSET(Engine_stabilised, 0);
   Engine_stable_t_d_c = (uint8)MATHSRV_udtMIN(Engine_stable_delay_c, 100);
   Engine_stabilised_eng_running = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngineCondStable                                */
/* !Description :  Si au bout de la durée Engine_stable_delay_c les conditions*/
/*                 de stabilité sont toujours validées, le booléen            */
/*                 Engine_stabilised passe à 1.                               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidEngCondTimerOut();                            */
/*  extf argret void ENGSTAB_vidEngCondTimer();                               */
/*  input uint8 Engine_stable_t_d_c;                                          */
/*  output boolean Engine_stabilised_eng_running;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngineCondStable(void)
{
   Engine_stabilised_eng_running = 1;
   if (Engine_stable_t_d_c <= 0)
   {
      ENGSTAB_vidEngCondTimerOut();
   }
   else
   {
      ENGSTAB_vidEngCondTimer();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngCondTimer                                    */
/* !Description :  Fonction renfermant un compteur décroissant.               */
/*                 EngStab_SampleTiMid_SC représente la période d’appel de la */
/*                 tache.                                                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Engine_stable_t_d_c;                                          */
/*  output boolean Engine_stabilised;                                         */
/*  output uint8 Engine_stable_t_d_c;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngCondTimer(void)
{
   uint8 u8LocalEngineStableTDC;


   VEMS_vidSET(Engine_stabilised, 0);
   if (Engine_stable_t_d_c > 1)
   {
      u8LocalEngineStableTDC = (uint8)(Engine_stable_t_d_c - 1);
   }
   else
   {
      u8LocalEngineStableTDC = 0;
   }
   Engine_stable_t_d_c = (uint8)MATHSRV_udtMIN(u8LocalEngineStableTDC, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngCondTimerOut                                 */
/* !Description :  Fonction de mise à 1 du booléen Engine_stabilised, si le   */
/*                 délai Engine_stable_t_d_c est écoulé.                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Engine_stabilised;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngCondTimerOut(void)
{
   VEMS_vidSET(Engine_stabilised, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidVehicleNotRunning                               */
/* !Description :  Lorsque les conditions qui permettent de juger la stabilité*/
/*                 du moteur ne sont pas remplies, on recopie les variables   */
/*                 Engine_load et Gear_engaged dans des plages mémoire qui    */
/*                 permettront ensuite de suivre leur évolution.              */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Gear_engaged;                                                 */
/*  output uint8 Engine_load_last;                                            */
/*  output uint8 Gear_engaged_last;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidVehicleNotRunning(void)
{
   uint8  u8LocalEngineLoad;
   uint8  u8LocalGear_engaged;
   uint16 u16LocalEngine_load;


   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   u8LocalEngineLoad = (uint8)((u16LocalEngine_load * 200) / 65536);
   Engine_load_last = u8LocalEngineLoad;
   Gear_engaged_last = (uint8)MATHSRV_udtMIN(u8LocalGear_engaged, 5);
}

/*------------------------------- end of file --------------------------------*/