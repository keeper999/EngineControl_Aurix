/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGLIMEFCCORD                                           */
/* !Description     : ENGLIMEFCCORD Component.                                */
/*                                                                            */
/* !Module          : ENGLIMEFCCORD                                           */
/* !Description     : Coordination des limitations CME.                       */
/*                                                                            */
/* !File            : ENGLIMEFCCORD_FCT2.C                                    */
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
/*   1 / ENGLIMEFCCORD_vidLimitCpleAirDsl                                     */
/*   2 / ENGLIMEFCCORD_vidLim_BVAuto_1_2                                      */
/*   3 / ENGLIMEFCCORD_vidLim_BVAuto_2_2                                      */
/*   4 / ENGLIMEFCCORD_vidLim_ESP1                                            */
/*   5 / ENGLIMEFCCORD_vidLim_ModSpt1                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 03267 / 03                                        */
/* !OtherRefs   : CSMT_CGMT08_0923 / 2.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/ENGLIMEFCCORD/ENG$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGLIMEFCCORD.h"
#include "ENGLIMEFCCORD_L.h"
#include "ENGLIMEFCCORD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLimitCpleAirDsl                           */
/* !Description :  Cette limitation est la limitation spécifique pour le      */
/*                 couple consigne air en diesel                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 CoPt_tqMaxGBxAir;                                            */
/*  input sint16 EngLim_tqCkEfcFLdLim;                                        */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input sint16 EngLim_tqEfcSyst;                                            */
/*  input sint16 EngLim_tqEfcRed;                                             */
/*  input sint16 EngLim_tqEfcSfty;                                            */
/*  output sint16 EngLim_tqCkEfcAirLim;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLimitCpleAirDsl(void)
{
   sint16  s16LocalCoPt_tqMaxGBxAir;
   sint16  s16LocalEngLim_tqCkEfcFLdLim;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqEfcSyst;
   sint16  s16LocalEngLim_tqEfcRed;
   sint16  s16LocalEngLim_tqEfcSfty;
   sint16  s16LocalEngLim_tqCkEfcAirLim;


   VEMS_vidGET(CoPt_tqMaxGBxAir, s16LocalCoPt_tqMaxGBxAir);
   VEMS_vidGET(EngLim_tqCkEfcFLdLim, s16LocalEngLim_tqCkEfcFLdLim);
   VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
   VEMS_vidGET(EngLim_tqEfcSyst, s16LocalEngLim_tqEfcSyst);
   VEMS_vidGET(EngLim_tqEfcRed, s16LocalEngLim_tqEfcRed);
   VEMS_vidGET(EngLim_tqEfcSfty, s16LocalEngLim_tqEfcSfty);

   s16LocalEngLim_tqCkEfcAirLim =
      (sint16)MATHSRV_udtMIN(s16LocalCoPt_tqMaxGBxAir,
                             s16LocalEngLim_tqCkEfcFLdLim);
   s16LocalEngLim_tqCkEfcAirLim =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcAirLim,
                             s16LocalEngLim_tqCkEfcStatLim);
   s16LocalEngLim_tqCkEfcAirLim =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcAirLim,
                             s16LocalEngLim_tqEfcSyst);
   s16LocalEngLim_tqCkEfcAirLim =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcAirLim,
                             s16LocalEngLim_tqEfcRed);
   s16LocalEngLim_tqCkEfcAirLim =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcAirLim,
                             s16LocalEngLim_tqEfcSfty);
   s16LocalEngLim_tqCkEfcAirLim =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqCkEfcAirLim, -32000, 32000);
   VEMS_vidSET(EngLim_tqCkEfcAirLim, s16LocalEngLim_tqCkEfcAirLim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_BVAuto_1_2                            */
/* !Description :  Réinitialisation du filtre de niveau 1 de la stratégie     */
/*                 d’agrément curatif.                                        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input uint8 EngLim_idxCoPtLim_C;                                          */
/*  input sint16 EngLim_tqEfcSyst;                                            */
/*  input sint16 EngLim_tqEfcRed;                                             */
/*  input sint16 EngLim_tqEfcSfty;                                            */
/*  output sint16 EngLim_tqCkEfcGBxLimCordEL2;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_BVAuto_1_2
(
   sint16 s16GbxBVAuto_1_2
)
{
   sint16  s16LocalGbx;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqEfcRed;
   sint16  s16LocalEngLim_tqEfcSfty;
   sint16  s16LocalEngLim_tqEfcSyst;


   s16LocalGbx = s16GbxBVAuto_1_2;
   VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
   if ((EngLim_idxCoPtLim_C & 0x10) != 0)
   {
      s16LocalGbx = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcStatLim,
                                           s16LocalGbx);
   }
   if ((EngLim_idxCoPtLim_C & 0x20) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSyst, s16LocalEngLim_tqEfcSyst);
      s16LocalGbx =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSyst, s16LocalGbx);
   }
   if ((EngLim_idxCoPtLim_C & 0x40) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcRed, s16LocalEngLim_tqEfcRed);
      s16LocalGbx =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcRed, s16LocalGbx);
   }
   if ((EngLim_idxCoPtLim_C & 0x80) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSfty, s16LocalEngLim_tqEfcSfty);
      s16LocalGbx =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSfty, s16LocalGbx);
   }
   s16LocalGbx = (sint16)MATHSRV_udtMAX(s16LocalGbx, -32000);
   VEMS_vidSET(EngLim_tqCkEfcGBxLimCordEL2, s16LocalGbx);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_BVAuto_2_2                            */
/* !Description :  La deuxième limitation pour la fonction BVA/BVMP est       */
/*                 configurée en fonction de la valeur de EngLim_CoPtLimTyp2_C*/
/*                 correspondant à la somme des valeurs couples de limitation */
/*                 à utiliser.                                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input uint8 EngLim_idxCoPtLimAT_C;                                        */
/*  input sint16 EngLim_tqEfcSyst;                                            */
/*  input sint16 EngLim_tqEfcRed;                                             */
/*  input sint16 EngLim_tqEfcSfty;                                            */
/*  output sint16 EngLim_tqCkEfcATLimCordEL2;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_BVAuto_2_2
(
   sint16 s16ATBVAuto_2_2
)
{
   sint16  s16LocalAT;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqEfcRed;
   sint16  s16LocalEngLim_tqEfcSfty;
   sint16  s16LocalEngLim_tqEfcSyst;


   s16LocalAT = s16ATBVAuto_2_2;
   VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
   if ((EngLim_idxCoPtLimAT_C & 0x10) != 0)
   {
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcStatLim,
                                          s16LocalAT);
   }
   if ((EngLim_idxCoPtLimAT_C & 0x20) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSyst, s16LocalEngLim_tqEfcSyst);
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSyst, s16LocalAT);
   }
   if ((EngLim_idxCoPtLimAT_C & 0x40) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcRed, s16LocalEngLim_tqEfcRed);
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcRed, s16LocalAT);
   }
   if ((EngLim_idxCoPtLimAT_C & 0x80) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSfty, s16LocalEngLim_tqEfcSfty);
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSfty, s16LocalAT);
   }
   s16LocalAT = (sint16)MATHSRV_udtMAX(s16LocalAT, -32000);
   VEMS_vidSET(EngLim_tqCkEfcATLimCordEL2, s16LocalAT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_ESP1                                  */
/* !Description :  La deuxième limitation pour la fonction ESP est configurée */
/*                 en fonction de la valeur de EngLim_ChaLim_C correspondant à*/
/*                 la somme des valeurs couples de limitation à utiliser.     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input uint8 EngLim_idxChaLim_C;                                           */
/*  input sint16 EngLim_tqEfcSyst;                                            */
/*  input sint16 EngLim_tqEfcRed;                                             */
/*  input sint16 EngLim_tqEfcSfty;                                            */
/*  output sint16 EngLim_tqCkEfcChaLim;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_ESP1
(
   sint16 s16tqEfcESP1
)
{
   sint16  s16LocalChaLim;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqEfcRed;
   sint16  s16LocalEngLim_tqEfcSfty;
   sint16  s16LocalEngLim_tqEfcSyst;


   s16LocalChaLim = s16tqEfcESP1;
   VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
   if ((EngLim_idxChaLim_C & 0x10) != 0)
   {
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcStatLim,
                                              s16LocalChaLim);
   }
   if ((EngLim_idxChaLim_C & 0x20) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSyst, s16LocalEngLim_tqEfcSyst);
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSyst,
                                              s16LocalChaLim);
   }
   if ((EngLim_idxChaLim_C & 0x40) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcRed, s16LocalEngLim_tqEfcRed);
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcRed,
                                              s16LocalChaLim);
   }
   if ((EngLim_idxChaLim_C & 0x80) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSfty, s16LocalEngLim_tqEfcSfty);
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSfty,
                                              s16LocalChaLim);
   }
   VEMS_vidSET(EngLim_tqCkEfcChaLim, s16LocalChaLim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_ModSpt1                               */
/* !Description :  La deuxième limitation pour la fonction superviseur du mode*/
/*                 sport est configurée en fonction de la valeur de           */
/*                 EngLim_idxModSptLim_C correspondant à la somme des valeurs */
/*                 couples de limitation à utiliser.                          */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 EngLim_idxModSptLim_C;                                        */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input sint16 EngLim_tqEfcSyst;                                            */
/*  input sint16 EngLim_tqEfcRed;                                             */
/*  input sint16 EngLim_tqEfcSfty;                                            */
/*  output sint16 EngLim_tqCkEfcModSptLim;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_ModSpt1
(
   sint16 s16tqEfcModSpt1
)
{
   sint16  s16LocalModSpt;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqEfcRed;
   sint16  s16LocalEngLim_tqEfcSfty;
   sint16  s16LocalEngLim_tqEfcSyst;


   s16LocalModSpt = s16tqEfcModSpt1;

   if ((EngLim_idxModSptLim_C & 0x10) != 0)
   {
      VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcStatLim,
                                              s16LocalModSpt);
   }
   if ((EngLim_idxModSptLim_C & 0x20) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSyst, s16LocalEngLim_tqEfcSyst);
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSyst,
                                              s16LocalModSpt);
   }
   if ((EngLim_idxModSptLim_C & 0x40) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcRed, s16LocalEngLim_tqEfcRed);
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcRed,
                                              s16LocalModSpt);
   }
   if ((EngLim_idxModSptLim_C & 0x80) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcSfty, s16LocalEngLim_tqEfcSfty);
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcSfty,
                                              s16LocalModSpt);
   }
   VEMS_vidSET(EngLim_tqCkEfcModSptLim, s16LocalModSpt);
}

/*------------------------------- end of file --------------------------------*/