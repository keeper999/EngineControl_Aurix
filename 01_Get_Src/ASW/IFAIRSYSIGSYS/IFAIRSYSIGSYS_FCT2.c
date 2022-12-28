/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_FCT2.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidTqRes                                               */
/*   2 / IFAIRSYSIGSYS_vidECU                                                 */
/*   3 / IFAIRSYSIGSYS_vidInterfacCstrIf                                      */
/*   4 / IFAIRSYSIGSYS_vidTqCurSfty                                           */
/*   5 / IFAIRSYSIGSYS_vidAFAInit                                             */
/*   6 / IFAIRSYSIGSYS_vidAFASyncIf                                           */
/*   7 / IFAIRSYSIGSYS_vidAFAThrIf                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidTqRes                                     */
/* !Description :  Fonction qui permet la production de la varible Ext_tqAlt. */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqRes_tqAltRes;                                              */
/*  output sint16 Ext_tqAlt;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidTqRes(void)
{
   /* F07_TqRes */
   uint16  u16LocalTqRes_tqAltRes;
   sint16  s16LocalExt_tqAlt;


   VEMS_vidGET(TqRes_tqAltRes, u16LocalTqRes_tqAltRes);
   s16LocalExt_tqAlt = (sint16)MATHSRV_udtMIN(u16LocalTqRes_tqAltRes, 32000);
   VEMS_vidSET(Ext_tqAlt, s16LocalExt_tqAlt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidECU                                       */
/* !Description :  Ce bloc contient les entrées de la chaine d’air issus des  */
/*                 modules projets Ebx.                                       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st08 Power_conditions_state;                                        */
/*  input bool WAITING_FOR_ANTICIPATION;                                      */
/*  input bool POWER_ON;                                                      */
/*  input bool WAITING_FOR_RESTART_DELAY;                                     */
/*  input bool WAITING_FOR_POWER_LATCH_DELAY;                                 */
/*  output uint8 ECU_stPwrECU;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidECU(void)
{
   /*f6_ECU*/
   uint8 u8LocalPower_conditions_state;
   uint8 u8LocalECU_stPwrECU;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   if (u8LocalPower_conditions_state ==  WAITING_FOR_ANTICIPATION)
   {
      u8LocalECU_stPwrECU = Ext_stWaitAnt_SC;
   }
   else
   {
      if (u8LocalPower_conditions_state == POWER_ON)
      {
         u8LocalECU_stPwrECU = Ext_stPwrOn_SC;
      }
      else
      {
         if (u8LocalPower_conditions_state == WAITING_FOR_RESTART_DELAY)
         {
            u8LocalECU_stPwrECU = Ext_stWaitRstrt_SC;
         }
         else
         {
            if (u8LocalPower_conditions_state == WAITING_FOR_POWER_LATCH_DELAY)
            {
               u8LocalECU_stPwrECU = Ext_stWaitPwrl_SC;
            }
            else
            {
               u8LocalECU_stPwrECU = Ext_stPwrOff_SC;
            }
         }
      }
   }
   VEMS_vidSET(ECU_stPwrECU, u8LocalECU_stPwrECU);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInterfacCstrIf                            */
/* !Description :  Permet de calculer le Signal d'autorisation de prélèvement */
/*                 de couple brute                                            */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoTqRStrt_bTraTqAuthRaw;                                    */
/*  output boolean CoTqRStrt_bTraCoplAuthRaw;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInterfacCstrIf(void)
{
   /* f2_interfacing_CstrIf */
   boolean bLocalCoTqRStrt_bTraTqAuthRaw;

   VEMS_vidGET(CoTqRStrt_bTraTqAuthRaw, bLocalCoTqRStrt_bTraTqAuthRaw);
   VEMS_vidSET(CoTqRStrt_bTraCoplAuthRaw, bLocalCoTqRStrt_bTraTqAuthRaw);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidTqCurSfty                                 */
/* !Description :  Mise à jour de la valeur du couple courant utilisé pour    */
/*                 initialiser la limitation de couple safety.                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  output sint16 EngLim_tqEngCur_Sfty;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidTqCurSfty(void)
{
   /*f1_tqCurSfty */
   sint16 s16LocalEngLim_tqIdcEngCur;
   sint16 s16LocalEngLim_tqEngCur_Sfty;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);

   s16LocalEngLim_tqEngCur_Sfty =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur, -32000, 32000);
   VEMS_vidSET(EngLim_tqEngCur_Sfty, s16LocalEngLim_tqEngCur_Sfty);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidAFAInit                                   */
/* !Description :  Fonction de remise à 0 du régime moteur en faible          */
/*                 résolution                                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_nEngLoResl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidAFAInit(void)
{
   /*F01_Init */

   VEMS_vidSET(Ext_nEngLoResl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidAFASyncIf                                 */
/* !Description :  Fonction de synchronisation entre régime moteur en         */
/*                 résolution 32 tr/mn et régime moteur en faible résolution  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  output uint16 Ext_nEngLoResl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidAFASyncIf(void)
{
   /*F02_SyncIf */
   uint8  u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidSET(Ext_nEngLoResl, (uint16)u8LocalRegime_moteur_32);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidAFAThrIf                                  */
/* !Description :  Fonction d'initialisation de la butée basse du papillon    */
/*                 motorisé                                                   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  output uint16 ThrLrn_rOpClsThrBol;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidAFAThrIf(void)
{
   /*F03_ThrIf */
   uint16 u16LocalSsm_closed_throttle_pos;
   uint16 u16LocalThrLrn_rOpClsThrBol;


   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_closed_throttle_pos);
   u16LocalThrLrn_rOpClsThrBol =
      (uint16)MATHSRV_udtMIN(u16LocalSsm_closed_throttle_pos, 1024);
   VEMS_vidSET(ThrLrn_rOpClsThrBol, u16LocalThrLrn_rOpClsThrBol);
}
/*-------------------------------- end of file -------------------------------*/