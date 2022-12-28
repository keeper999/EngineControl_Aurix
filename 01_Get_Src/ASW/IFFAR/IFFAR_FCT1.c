/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFFAR                                                   */
/* !Description     : IFFAR component.                                        */
/*                                                                            */
/* !Module          : IFFAR                                                   */
/* !Description     : INTERFACAGE DE LA FONCTION FAR .                        */
/*                                                                            */
/* !File            : IFFAR_FCT1.C                                            */
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
/*   1 / IFFAR_vidInitFar                                                     */
/*   2 / IFFAR_vidObjRich                                                     */
/*   3 / IFFAR_vidAcvReqMonItrsv                                              */
/*   4 / IFFAR_vidMixtReqMonItrsv                                             */
/*                                                                            */
/* !Reference   : V02 NT 12 01358 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065272                                         */
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
#include "IFFAR.h"
#include "IFFAR_L.h"
#include "IFFAR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFFAR_vidInitFar                                           */
/* !Description :  fonction d'initialisation du module                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Obj_rich_decrease_enable;                                  */
/*  output boolean OxC_bAcvReqMonItrsv;                                       */
/*  output boolean LsMon_bAcvReqMonItrsv;                                     */
/*  output uint16 Obj_rich_min_limit;                                         */
/*  output uint16 Obj_rich_mise_en_action;                                    */
/*  output uint16 Obj_rich_coef_base_total;                                   */
/*  output uint16 Obj_rich_charge_partielle;                                  */
/*  output uint16 Obj_rich_pleine_charge;                                     */
/*  output uint16 Obj_rich_temperature_air;                                   */
/*  output uint16 Objectif_richesse_anti_k;                                   */
/*  output uint16 Hsfr_target;                                                */
/*  output uint16 Eng_rlamRstrtSTT;                                           */
/*  output uint16 LsMon_rMixtReqMonItrsv;                                     */
/*  output sint16 Afr_target_reinst_corr;                                     */
/*  output sint16 Afr_target_reinst_aps_corr;                                 */
/*  output sint16 Eng_FacCorIntrSttHiEngSpd;                                  */
/*  output uint32 Obj_rich_apres_depart;                                      */
/*  output uint32 OxC_rlamOxCHeatPhaReq;                                      */
/*  output uint16 OxC_rMixtReqMonItrsv;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFFAR_vidInitFar(void)
{
   VEMS_vidSET(Obj_rich_decrease_enable, 0);
   VEMS_vidSET(OxC_bAcvReqMonItrsv, 0);
   VEMS_vidSET(LsMon_bAcvReqMonItrsv, 0);
   VEMS_vidSET(Obj_rich_min_limit, 8917);
   VEMS_vidSET(Obj_rich_mise_en_action, 8917);
   VEMS_vidSET(Obj_rich_coef_base_total, 16384);
   VEMS_vidSET(Obj_rich_charge_partielle, 8917);
   VEMS_vidSET(Obj_rich_pleine_charge, 8917);
   VEMS_vidSET(Obj_rich_temperature_air, 8917);
   VEMS_vidSET(Objectif_richesse_anti_k, 8917);
   VEMS_vidSET(Hsfr_target, 0);
   VEMS_vidSET(Eng_rlamRstrtSTT, 8917);
   VEMS_vidSET(LsMon_rMixtReqMonItrsv, 4096);
   VEMS_vidSET(Afr_target_reinst_corr, 0);
   VEMS_vidSET(Afr_target_reinst_aps_corr, 0);
   VEMS_vidSET(Eng_FacCorIntrSttHiEngSpd, 0);
   VEMS_vidSET(Obj_rich_apres_depart, 8917);
   VEMS_vidSET(OxC_rlamOxCHeatPhaReq, 8917);
   VEMS_vidSET(OxC_rMixtReqMonItrsv, 4096);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFFAR_vidObjRich                                           */
/* !Description :  fonction d'interfacage de l'objectif de richesse après     */
/*                 départ.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FARSp_rMixtCylSp;                                            */
/*  output uint32 Obj_rich_apres_depart;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFFAR_vidObjRich(void)
{
   uint16 u16LocalFARSp_rMixtCylSp;
   uint32 u32LocalObj_rich_apres_depart;


   VEMS_vidGET(FARSp_rMixtCylSp, u16LocalFARSp_rMixtCylSp);
   u32LocalObj_rich_apres_depart = (uint32)( ( ( u16LocalFARSp_rMixtCylSp
                                               * 320)
                                             + 73)
                                           / 147);
   u32LocalObj_rich_apres_depart =
      MATHSRV_udtMIN(u32LocalObj_rich_apres_depart, 131071);
   VEMS_vidSET(Obj_rich_apres_depart, u32LocalObj_rich_apres_depart);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFFAR_vidAcvReqMonItrsv                                    */
/* !Description :  Fonction d'interfacage de la demande de diagnostic intrusif*/
/*                 pour la sonde aval                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsMon_bAcvItrsvSenO2DsDiag;                                 */
/*  output boolean LsMon_bAcvReqMonItrsv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFFAR_vidAcvReqMonItrsv(void)
{
   boolean  bLocalLsMon_bAcvItrsvSenO2DsDiag;


   VEMS_vidGET(LsMon_bAcvItrsvSenO2DsDiag, bLocalLsMon_bAcvItrsvSenO2DsDiag);
   VEMS_vidSET(LsMon_bAcvReqMonItrsv, bLocalLsMon_bAcvItrsvSenO2DsDiag);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFFAR_vidMixtReqMonItrsv                                   */
/* !Description :  fonction d'interfacage de la consigne de créneau de        */
/*                 richesse.                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 OxC_rMixtReqMonIntr;                                         */
/*  input boolean LsMon_bAcvItrsvSenO2DsDiag;                                 */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  output boolean OxC_bAcvReqMonItrsv;                                       */
/*  output uint16 OxC_rMixtReqMonItrsv;                                       */
/*  output uint16 LsMon_rMixtReqMonItrsv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFFAR_vidMixtReqMonItrsv(void)
{
   boolean bLocalLsMon_bAcvItrsvSenO2DsDiag;
   boolean bLocalOxC_bMonRunORngIntr;
   uint16  u16LocalOxC_rMixtReqMonIntr;
   uint16  u16LocalLsMon_rMixtReqMonItrsv;
   uint16  u16LocalOxC_rMixtReqMonItrsv;


   VEMS_vidGET(OxC_rMixtReqMonIntr, u16LocalOxC_rMixtReqMonIntr);
   VEMS_vidGET(LsMon_bAcvItrsvSenO2DsDiag, bLocalLsMon_bAcvItrsvSenO2DsDiag);
   VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);

   u16LocalOxC_rMixtReqMonItrsv = (uint16)( ( ( u16LocalOxC_rMixtReqMonIntr
                                              * 147)
                                            + 160)
                                          / 320);
   if (bLocalLsMon_bAcvItrsvSenO2DsDiag != 0)
   {
      u16LocalLsMon_rMixtReqMonItrsv = (uint16)( ( ( u16LocalOxC_rMixtReqMonIntr
                                                   * 147)
                                                 + 160)
                                               / 320);
   }
   else
   {
      u16LocalLsMon_rMixtReqMonItrsv = 4096;
   }
   VEMS_vidSET(OxC_bAcvReqMonItrsv, bLocalOxC_bMonRunORngIntr);
   VEMS_vidSET(OxC_rMixtReqMonItrsv, u16LocalOxC_rMixtReqMonItrsv);
   VEMS_vidSET(LsMon_rMixtReqMonItrsv, u16LocalLsMon_rMixtReqMonItrsv);
}
/*-------------------------------- end of file -------------------------------*/
