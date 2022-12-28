/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYS                                                */
/* !Description     : IFAIRSYS Component                                      */
/*                                                                            */
/* !Module          : IFAIRSYS                                                */
/* !Description     : INTERFACE DE LA CHAINE D AIR                            */
/*                                                                            */
/* !File            : IFAIRSYS_FCT2.C                                         */
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
/*   1 / IFAIRSYS_vidNEngGrd                                                  */
/*   2 / IFAIRSYS_vidEngSt                                                    */
/*   3 / IFAIRSYS_vidInitCrkMgt                                               */
/*   4 / IFAIRSYS_vidCrkMgt2                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5199971 / 07                                        */
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
#include "IFAIRSYS.h"
#include "IFAIRSYS_L.h"
#include "IFAIRSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidNEngGrd                                        */
/* !Description :  cette fonction calcule le gradiant du régime moteur à      */
/*                 partir de sa dérivée.                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 Engine_speed_derivate;                                        */
/*  input uint8 Ext_nEngGrdGain_C;                                            */
/*  input sint32 IFAIRSYS_s32OutputMem;                                       */
/*  output sint32 IFAIRSYS_s32OutputMem;                                      */
/*  output sint8 Ext_nEngGrd;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidNEngGrd(void)
{
   uint8  u8LocalGain;
   sint16 s16LocalExt_nEngGrd;
   sint16 s16LocalEngine_speed_derivate;


   VEMS_vidGET(Engine_speed_derivate, s16LocalEngine_speed_derivate);
   if (Ext_nEngGrdGain_C > 254)
   {
      s16LocalExt_nEngGrd = s16LocalEngine_speed_derivate;
      IFAIRSYS_s32OutputMem =(sint32)(s16LocalExt_nEngGrd * 256);
   }
   else
   {
      u8LocalGain = (uint8)((Ext_nEngGrdGain_C * 256) / 255);
      s16LocalExt_nEngGrd =
         MATHSRV_s16FirstOrderFilterGu8(u8LocalGain,
                                        &IFAIRSYS_s32OutputMem,
                                        s16LocalEngine_speed_derivate);
   }
   VEMS_vidSET(Ext_nEngGrd, (sint8)s16LocalExt_nEngGrd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidEngSt                                          */
/* !Description :  cette fonction détermine l'état de fonctionnement du       */
/*                 moteur.                                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st07 Engine_running_state;                                          */
/*  output uint8 Eng_stRun;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidEngSt(void)
{
   uint8 u8LocalEngine_running_state;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   u8LocalEngine_running_state =
      (uint8)MATHSRV_udtCLAMP(u8LocalEngine_running_state, 1, 128);
   VEMS_vidSET(Eng_stRun, u8LocalEngine_running_state);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidInitCrkMgt                                     */
/* !Description :  cette fonction détermine l'état du gestionnaire de la      */
/*                 section efficace du papillon en démarrage.                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 CrkMgt_stThr_arThrEff;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidInitCrkMgt(void)
{
   VEMS_vidSET(CrkMgt_stThr_arThrEff, CrkMgt_stStrtArIni_SC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidCrkMgt2                                        */
/* !Description :  cette fonction détermine l'état du gestionnaire de la      */
/*                 section efficace du papillon.                              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st12 Dtc_etat_structure;                                            */
/*  output uint8 CrkMgt_stThr_arThrEff;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidCrkMgt2(void)
{
   uint8 u8LocalDtc_etat_structure;


   VEMS_vidGET(Dtc_etat_structure, u8LocalDtc_etat_structure);
   if (u8LocalDtc_etat_structure == DTC_VERS_ET_STRUCTURE_COUPLE)
   {
      VEMS_vidSET(CrkMgt_stThr_arThrEff, CrkMgt_stCllTq_SC);
   }
   else
   {
      if (u8LocalDtc_etat_structure == DTC_VERS_ET_DEBOUCLEE)
      {
         VEMS_vidSET(CrkMgt_stThr_arThrEff, CrkMgt_stOplTq_SC);
      }
      else
      {
         VEMS_vidSET(CrkMgt_stThr_arThrEff, CrkMgt_stStrtArIni_SC);
      }
   }
}

/*-------------------------------- end of file -------------------------------*/