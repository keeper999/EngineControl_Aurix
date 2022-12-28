/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCUTOFFBVMP                                           */
/* !Description     : INJCUTOFFBVMP Component                                 */
/*                                                                            */
/* !Module          : INJCUTOFFBVMP                                           */
/* !Description     : Gestion de la demande de coupure injection pour la BVMP */
/*                                                                            */
/* !File            : INJCUTOFFBVMP_FCT1.C                                    */
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
/*   1 / INJCUTOFFBVMP_vidInitBVMPFCO                                         */
/*   2 / INJCUTOFFBVMP_vidInitOutput                                          */
/*   3 / INJCUTOFFBVMP_vidCalcBVMPFCO                                         */
/*   4 / INJCUTOFFBVMP_vidAcvBvmpFco                                          */
/*   5 / INJCUTOFFBVMP_vidDisBvmpFco                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 07837 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJCUTOFFBVMP/INJCUTOFFBVMP_FCT1.C$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   12 Dec 2011 $*/
/* $Author::   wbouach                                $$Date::   12 Dec 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "INJCUTOFFBVMP.H"
#include "INJCUTOFFBVMP_L.H"
#include "INJCUTOFFBVMP_IM.H"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCUTOFFBVMP_vidInitBVMPFCO                               */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Bvmp_fco_request;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCUTOFFBVMP_vidInitBVMPFCO(void)
{
   /* output initialization */
   VEMS_vidSET(Bvmp_fco_request, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCUTOFFBVMP_vidInitOutput                                */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean INJCUTOFFBVMP_bHystOut;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCUTOFFBVMP_vidInitOutput(void)
{
   /* Hysteresis output initialization */
   INJCUTOFFBVMP_bHystOut = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCUTOFFBVMP_vidCalcBVMPFCO                               */
/* !Description :  Cette fonction décrit la gestion de la demande e coupure   */
/*                 injection pour la BVMP.                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCUTOFFBVMP_vidAcvBvmpFco();                           */
/*  extf argret void INJCUTOFFBVMP_vidDisBvmpFco();                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 CoPt_nTar;                                                   */
/*  input uint8 CoPt_stPhaGearShift;                                          */
/*  input st07 Engine_running_state;                                          */
/*  input boolean Presence_bvmp;                                              */
/*  input uint16 InjCutOff_nRegThdBvmpCutOff;                                 */
/*  input boolean INJCUTOFFBVMP_bHystOut;                                     */
/*  input boolean InjCutOff_bAcvBvmpFcoReq;                                   */
/*  output boolean INJCUTOFFBVMP_bHystOut;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCUTOFFBVMP_vidCalcBVMPFCO(void)
{
   boolean bLocalPresence_bvmp;
   uint8   u8LocalCoPt_stPhaGearShift;
   uint8   u8LocalEngine_running_state;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalCoPt_nTar;
   uint32  u32LocalHigh;
   sint32  s32LocalLow;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(CoPt_nTar, u16LocalCoPt_nTar);
   VEMS_vidGET(CoPt_stPhaGearShift, u8LocalCoPt_stPhaGearShift);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Presence_bvmp, bLocalPresence_bvmp);

   u16LocalCoPt_nTar = (uint16)(u16LocalCoPt_nTar / 4);
   s32LocalLow = (sint32)(u16LocalCoPt_nTar - InjCutOff_nRegThdBvmpCutOff);
   u32LocalHigh = (uint32)(u16LocalCoPt_nTar + InjCutOff_nRegThdBvmpCutOff);
   if (u16LocalRegime_moteur >= u32LocalHigh)
   {
      INJCUTOFFBVMP_bHystOut = 1;
   }
   else
   {
      if (u16LocalRegime_moteur <= s32LocalLow)
      {
         INJCUTOFFBVMP_bHystOut = 0;
      }
   }
   if (  (INJCUTOFFBVMP_bHystOut != 0)
      && (u8LocalCoPt_stPhaGearShift == 0)
      && (bLocalPresence_bvmp != 0)
      && (u8LocalEngine_running_state == ERUN_FULL_LOAD)
      && (InjCutOff_bAcvBvmpFcoReq != 0))
   {
      INJCUTOFFBVMP_vidAcvBvmpFco();
   }
   else
   {
      INJCUTOFFBVMP_vidDisBvmpFco();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCUTOFFBVMP_vidAcvBvmpFco                                */
/* !Description :  Cette fonction détermine la requète de coupure d'injection */
/*                 en passage de vitesse Bvmp.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean InjCutOff_bAcvIdlSysFco;                                    */
/*  input boolean IdlSys_bInjCutOff;                                          */
/*  output boolean Bvmp_fco_request;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCUTOFFBVMP_vidAcvBvmpFco(void)
{
   boolean bLocalIdlSys_bInjCutOff;


   if (InjCutOff_bAcvIdlSysFco != 0)
   {
      VEMS_vidGET(IdlSys_bInjCutOff, bLocalIdlSys_bInjCutOff);
      VEMS_vidSET(Bvmp_fco_request, bLocalIdlSys_bInjCutOff);
   }
   else
   {
      VEMS_vidSET(Bvmp_fco_request, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCUTOFFBVMP_vidDisBvmpFco                                */
/* !Description :  Cette fonction décrit la mise à zero de la requète de      */
/*                 coupure d'injection en passage de vitesse Bvmp.            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Bvmp_fco_request;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCUTOFFBVMP_vidDisBvmpFco(void)
{
   VEMS_vidSET(Bvmp_fco_request, 0);
}
/*------------------------------- end of file --------------------------------*/