/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFSUCDET                                              */
/* !Description     : MISFSUCDET Component                                    */
/*                                                                            */
/* !Module          : MISFSUCDET                                              */
/* !Description     : ALGORITHMES DE DÉTECTION DE 2 MISFIRES SUCCESSIFS       */
/*                                                                            */
/* !File            : MISFSUCDET_FCT1.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / MISFSUCDET_vidInitOutput                                             */
/*   2 / MISFSUCDET_vidSucMisfDetectMain                                      */
/*   3 / MISFSUCDET_vidSucMisfDetection                                       */
/*   4 / MISFSUCDET_vidSuccessiveMisfires                                     */
/*   5 / MISFSUCDET_vidAlgorithme                                             */
/*   6 / MISFSUCDET_vidDecision                                               */
/*   7 / MISFSUCDET_vidDetTwoMisfNotChckd                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5198660 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFSUCDET/MISFSUCDET_FCT1.C_$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFSUCDET.h"
#include "MISFSUCDET_L.h"
#include "MISFSUCDET_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidInitOutput                                   */
/* !Description :  Initialisation des variables de sorties                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_2_misfire_detected_uavb0;                               */
/*  output boolean MISFSUCDET_bEnablePrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidInitOutput(void)
{
   VEMS_vidSET(Mf_2_misfire_detected_uavb0, 0);
   MISFSUCDET_bEnablePrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSucMisfDetectMain                            */
/* !Description :  La stratégie de détection de 2 misfires successifs sera    */
/*                 calculée si le Booléen ,qui indique que les conditions     */
/*                 d'activation des algorithmes sont vérifiées, est mis à '1' */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFSUCDET_vidSucMisfDetection();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Mf_algo_cond_ok_uavb0;                                      */
/*  input boolean Mf_algo_idle_cond_ok;                                       */
/*  input boolean Mf_2_misfire_idle_detected_uavb0;                           */
/*  input boolean Mf_2_misfire_norm_detected_uavb0;                           */
/*  output boolean Mf_2_misfire_detected_uavb0;                               */
/*  output boolean Mf_2_misfire_norm_detected_uavb0;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSucMisfDetectMain(void)
{
   boolean bLocalMf_algo_cond_ok_uavb0;
   boolean bLocalMf_algo_idle_cond_ok;
   boolean bLocalMf_misfire_detected_uavb0;


   VEMS_vidGET(Mf_algo_cond_ok_uavb0, bLocalMf_algo_cond_ok_uavb0);
   VEMS_vidGET(Mf_algo_idle_cond_ok, bLocalMf_algo_idle_cond_ok);
   VEMS_vidGET( Mf_2_misfire_idle_detected_uavb0,
                bLocalMf_misfire_detected_uavb0);
   if (bLocalMf_algo_cond_ok_uavb0 != 0)
   {
      MISFSUCDET_vidSucMisfDetection();
   }
   if (bLocalMf_algo_idle_cond_ok != 0)
   {
      VEMS_vidSET(Mf_2_misfire_detected_uavb0, bLocalMf_misfire_detected_uavb0);
   }
   else
   {
      VEMS_vidSET( Mf_2_misfire_detected_uavb0,
                   Mf_2_misfire_norm_detected_uavb0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSucMisfDetection                             */
/* !Description :  Ce bloc est constitué de 3 modules dont les fonctions sont */
/*                 respectivement: L’activation de la stratégie de détection. */
/*                 Le calcul des nouveaux algorithmes. La décision permettant */
/*                 de dire si 2 misfires successifs se sont produits ou non.  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidSuccessiveMisfires();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSucMisfDetection(void)
{
   MISFSUCDET_vidSuccessiveMisfires();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidSuccessiveMisfires                           */
/* !Description :  Ce bloc permet d’activer la stratégie de détection de 2    */
/*                 misfires successifs dès lors que la sortie unique est      */
/*                 supérieure à un seuil calibrable.                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFSUCDET_vidAlgorithme();                              */
/*  extf argret void MISFSUCDET_vidDecision();                                */
/*  extf argret void MISFSUCDET_vidDetTwoMisfNotChckd();                      */
/*  input uint8 Mf_det_single_output_uavn0;                                   */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint8 Mf_2_misfire_det_map_uacn2[7][16];                            */
/*  input boolean MISFSUCDET_bEnablePrev;                                     */
/*  output boolean MISFSUCDET_bEnablePrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidSuccessiveMisfires(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMf_det_single_output_uavn;
   uint8   u8LocalInterp2d;
   uint16  u16LocalIndicatedTorque;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint32  s32LocalIndicatedTorque;


   VEMS_vidGET(Mf_det_single_output_uavn0, u8LocalMf_det_single_output_uavn);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   s32LocalIndicatedTorque = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalIndicatedTorque = (uint16)MATHSRV_udtMAX(s32LocalIndicatedTorque,
                                                    0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                u16LocalIndicatedTorque,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               16);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&Mf_2_misfire_det_map_uacn2[0][0],
                                        u16LocalParaX,
                                        u16LocalParaY,
                                        16);

   if (u8LocalMf_det_single_output_uavn > u8LocalInterp2d)
   {
      if (MISFSUCDET_bEnablePrev != 0)
      {
         MISFSUCDET_vidAlgorithme();
         MISFSUCDET_vidDecision();
      }
      else
      {
         MISFSUCDET_vidDetTwoMisfNotChckd();
      }
      MISFSUCDET_bEnablePrev = 1;
   }
   else
   {
      MISFSUCDET_bEnablePrev = 0;
      MISFSUCDET_vidDetTwoMisfNotChckd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidAlgorithme                                   */
/* !Description :  Ce bloc se décompose en 2 sous-blocs : Calcul de l’indice  */
/*                 de confiance appliqué au « 1er misfire » scruté. Calcul de */
/*                 l’indice de confiance appliqué au « 2ème misfire » scruté  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidFirstMisfDetection();                      */
/*  extf argret void MISFSUCDET_vidSndMisfDetection();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidAlgorithme(void)
{
   MISFSUCDET_vidFirstMisfDetection();
   MISFSUCDET_vidSndMisfDetection();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidDecision                                     */
/* !Description :  Ce bloc se divise en 2 sous blocs :Le 1er décide si le 1er */
/*                 misfire a effectivement eu lieu. Le 2ème décide si le 2ème */
/*                 misfire a effectivement eu lieu                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDET_vidFstMisfDecision();                         */
/*  extf argret void MISFSUCDET_vidSndMisfDecision();                         */
/*  input boolean Mf_misfire1_detected_uavb0;                                 */
/*  input boolean Mf_misfire2_detected_uavb0;                                 */
/*  output boolean Mf_2_misfire_norm_detected_uavb0;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidDecision(void)
{
   MISFSUCDET_vidFstMisfDecision();
   MISFSUCDET_vidSndMisfDecision();
   if (  (Mf_misfire1_detected_uavb0 != 0)
      && (Mf_misfire2_detected_uavb0 != 0))
   {
      Mf_2_misfire_norm_detected_uavb0 = 1;
   }
   else
   {
      Mf_2_misfire_norm_detected_uavb0 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDET_vidDetTwoMisfNotChckd                           */
/* !Description :  Ce bloc permet de remettre la variable                     */
/*                 Mf_2_misfire_detected_uavb0 à 0 dès lors que la détection  */
/*                 de 2 misfires successifs n’est pas vérifiée ( à savoir     */
/*                 Mf_2_mf_det_ena_uavb0 = 0 )                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Mf_2_misfire_norm_detected_uavb0;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDET_vidDetTwoMisfNotChckd(void)
{
   Mf_2_misfire_norm_detected_uavb0 = 0;
}
/*------------------------------- end of file --------------------------------*/