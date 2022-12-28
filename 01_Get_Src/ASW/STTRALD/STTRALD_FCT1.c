/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STTRALD                                                 */
/* !Description     : STTRALD component.                                      */
/*                                                                            */
/* !Module          : STTRALD                                                 */
/* !Description     : Automate de detection des transitoires de charge        */
/*                                                                            */
/* !File            : STTRALD_FCT1.C                                          */
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
/*   1 / STTRALD_vidInitOutputs                                               */
/*   2 / STTRALD_vidLoadTransDetectStMach                                     */
/*   3 / STTRALD_vidResetManifoldState                                        */
/*   4 / STTRALD_vidTransientState                                            */
/*   5 / STTRALD_vidStateMachine                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 04622 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#043770                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/STTRALD/STTRALD_FCT1.C_v          $*/
/* $Revision::   1.1      $$Author::   pcabariq       $$Date::   14 Dec 2009 $*/
/* $Author::   pcabariq                               $$Date::   14 Dec 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "STTRALD.h"
#include "STTRALD_L.h"
#include "STTRALD_IM.h"
#include "VEMS.h"
#include "SWFAIL.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTRALD_vidInitOutputs                                     */
/* !Description :  Fonctin qui initialise les sorties                         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Eng_bAccEng;                                               */
/*  output sint16 InM_mfDif_stTraLd;                                          */
/*  output uint8 InM_stTraLd;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTRALD_vidInitOutputs(void)
{
   VEMS_vidSET(Eng_bAccEng, 0);
   VEMS_vidSET(InM_mfDif_stTraLd, 0);
   VEMS_vidSET(InM_stTraLd, Ext_stStab_SC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTRALD_vidLoadTransDetectStMach                           */
/* !Description :  Fonction principale qui fait appel au fonctions associées  */
/*                 au sous blocs                                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTRALD_vidResetManifoldState();                         */
/*  extf argret void STTRALD_vidTransientState();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTRALD_vidLoadTransDetectStMach(void)
{
   STTRALD_vidResetManifoldState();
   STTRALD_vidTransientState();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTRALD_vidResetManifoldState                              */
/* !Description :  Initialisation des variables de l'automate de transitoire  */
/*                 lorsque l'on n'est pas dans l'état RUNNING                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st34 Eng_stEru;                                                     */
/*  output uint8 InM_stTraLd;                                                 */
/*  output boolean Eng_bAccEng;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTRALD_vidResetManifoldState(void)
{
   uint8 u8LocalEng_stEru;


   VEMS_vidGET(Eng_stEru, u8LocalEng_stEru);
   if (u8LocalEng_stEru != Ext_stRun_SC)
   {
      VEMS_vidSET(InM_stTraLd, Ext_stStab_SC);
      VEMS_vidSET(Eng_bAccEng, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTRALD_vidTransientState                                  */
/* !Description :  Cette fonction permet de détecter les transitoires de      */
/*                 l'état collecteur. La détection se fait par un indicateur  */
/*                 de transitoire basé sur la comparaison entre le débit d'air*/
/*                 entrant dans le collecteur et le débit d'air pompé par le  */
/*                 moteur.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void STTRALD_vidStateMachine();                               */
/*  input st34 Eng_stEru;                                                     */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input uint16 InM_mfTotCanPurgEstim;                                       */
/*  input uint16 CanPurg_mfFuStmEstim;                                        */
/*  input uint16 InM_mfAirEstim;                                              */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input uint16 InM_mfTotExCor_A[9];                                         */
/*  input uint8 InM_TranToStabThd_T[9];                                       */
/*  input uint8 InM_StabToTranThd_T[9];                                       */
/*  output sint16 InM_mfDif_stTraLd;                                          */
/*  output uint8 InM_TranToStabThd_stTraLd;                                   */
/*  output uint8 InM_StabToTranThd_stTraLd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTRALD_vidTransientState(void)
{
   uint8  u8LocalEng_stEru;
   uint16 u16LocalmfAirThrEstim;
   uint16 u16LocalmfTotCanPurgEstim;
   uint16 u16LocalmfFuStmEstim;
   uint16 u16LocalmfAirEstim;
   uint16 u16LocalEngMmfTotExCor;
   uint16 u16LocalSttraldPara;
   sint16 s16LocalmfDif_stTraLd;
   sint32 s32LocalmfDif_stTraLd;


   VEMS_vidGET(Eng_stEru, u8LocalEng_stEru);

   if (u8LocalEng_stEru == Ext_stRun_SC)
   {
      VEMS_vidGET(InM_mfAirThrEstim, u16LocalmfAirThrEstim);
      VEMS_vidGET(InM_mfTotCanPurgEstim, u16LocalmfTotCanPurgEstim);
      VEMS_vidGET(CanPurg_mfFuStmEstim, u16LocalmfFuStmEstim);
      VEMS_vidGET(InM_mfAirEstim, u16LocalmfAirEstim);

      s32LocalmfDif_stTraLd =
         (sint32)(  ((u16LocalmfAirThrEstim - u16LocalmfAirEstim) / 2)
                  + ((u16LocalmfTotCanPurgEstim - u16LocalmfFuStmEstim)
                      / 32));

      s16LocalmfDif_stTraLd = (sint16)MATHSRV_udtCLAMP(s32LocalmfDif_stTraLd,
                                                       -32768,
                                                       32767);

      VEMS_vidSET(InM_mfDif_stTraLd, s16LocalmfDif_stTraLd);

      VEMS_vidGET(EngM_mfTotExCor, u16LocalEngMmfTotExCor);

      u16LocalSttraldPara = MATHSRV_u16CalcParaIncAryU16(InM_mfTotExCor_A,
                                                         u16LocalEngMmfTotExCor,
                                                         9);

      InM_TranToStabThd_stTraLd = MATHSRV_u8Interp1d(InM_TranToStabThd_T,
                                                      u16LocalSttraldPara);

      InM_StabToTranThd_stTraLd = MATHSRV_u8Interp1d(InM_StabToTranThd_T,
                                                      u16LocalSttraldPara);
      STTRALD_vidStateMachine();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTRALD_vidStateMachine                                    */
/* !Description :  Fonction qui représente l'automate de transitoire de       */
/*                 charges                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 InM_stTraLd;                                                  */
/*  input sint16 InM_mfDif_stTraLd;                                           */
/*  input uint8 InM_StabToTranThd_stTraLd;                                    */
/*  input uint8 InM_TranToStabThd_stTraLd;                                    */
/*  output uint8 InM_stTraLd;                                                 */
/*  output boolean Eng_bAccEng;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTRALD_vidStateMachine(void)
{
   uint8  u8LocalInM_stTraLd;
   sint16 s16LocalmfDif_stTraLd;


   VEMS_vidGET(InM_stTraLd, u8LocalInM_stTraLd);
   VEMS_vidGET(InM_mfDif_stTraLd, s16LocalmfDif_stTraLd);

   switch (u8LocalInM_stTraLd)
   {
      case Ext_stStab_SC:
         if (s16LocalmfDif_stTraLd > InM_StabToTranThd_stTraLd)
         {
            VEMS_vidSET(InM_stTraLd, Ext_stAcce_SC);
            VEMS_vidSET(Eng_bAccEng, 1);
         }
         else
         {
            if(s16LocalmfDif_stTraLd < (-1 * InM_StabToTranThd_stTraLd))
            {
               VEMS_vidSET(InM_stTraLd, Ext_stDece_SC);
               VEMS_vidSET(Eng_bAccEng, 0);
            }
         }
         break;

      case Ext_stAcce_SC:
         if (   (s16LocalmfDif_stTraLd < InM_TranToStabThd_stTraLd)
             && (s16LocalmfDif_stTraLd > (-1 * InM_StabToTranThd_stTraLd)))
         {
            VEMS_vidSET(InM_stTraLd, Ext_stStab_SC);
            VEMS_vidSET(Eng_bAccEng, 1);
         }
         else
         {
            if (s16LocalmfDif_stTraLd < (-1 * InM_StabToTranThd_stTraLd))
            {
               VEMS_vidSET(InM_stTraLd, Ext_stDece_SC);
               VEMS_vidSET(Eng_bAccEng, 0);
            }
         }
         break;

      case Ext_stDece_SC:
         if (   (s16LocalmfDif_stTraLd > (-1 * InM_TranToStabThd_stTraLd))
             && (s16LocalmfDif_stTraLd < InM_StabToTranThd_stTraLd))
         {
            VEMS_vidSET(InM_stTraLd, Ext_stStab_SC);
            VEMS_vidSET(Eng_bAccEng, 1);
         }
         else
         {
            if (s16LocalmfDif_stTraLd > InM_StabToTranThd_stTraLd)
            {
               VEMS_vidSET(InM_stTraLd, Ext_stAcce_SC);
               VEMS_vidSET(Eng_bAccEng, 1);
            }
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(InM_stTraLd, Ext_stStab_SC);
         VEMS_vidSET(Eng_bAccEng, 1);
         break;
   }
}

/*----------------------------- end of file ----------------------------------*/