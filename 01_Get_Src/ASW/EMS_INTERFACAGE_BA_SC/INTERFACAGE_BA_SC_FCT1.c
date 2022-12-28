/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INTERFACAGE_BA_SC                                       */
/* !Description     : INTERFACAGE_BA_SC Component                             */
/*                                                                            */
/* !Module          : INTERFACAGE_BA_SC                                       */
/* !Description     : Interfaçage Boucle Air / Structure Couple               */
/*                                                                            */
/* !File            : INTERFACAGE_BA_SC_FCT1.C                                */
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
/*   1 / INTERFACAGE_BA_SC_vidInitOutput                                      */
/*   2 / INTERFACAGE_BA_SC_vidIntEngMSC                                       */
/*   3 / INTERFACAGE_BA_SC_vidInterfExMSC                                     */
/*   4 / INTERFACAGE_BA_SC_vidIntAirSysSC                                     */
/*   5 / INTERFACAGE_BA_SC_vidIntrfUsThrM                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 07792 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_2661_2 / 1.2                                    */
/* !OtherRefs   : VEMS V02 ECU#058226                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/Air/INTERFACAGE_BA_SC/INTE$*/
/* $Revision::   1.5.1.1  $$Author::   etsasson       $$Date::   04 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   04 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INTERFACAGE_BA_SC.h"
#include "INTERFACAGE_BA_SC_L.h"
#include "INTERFACAGE_BA_SC_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTERFACAGE_BA_SC_vidInitOutput                            */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 AirSys_mfAirMesThrEstim;                                    */
/*  output uint16 Eng_rAirLd;                                                 */
/*  output uint16 ExM_pUsTrbEstimTqSys;                                       */
/*  output boolean Eng_bAcvCllEngReq;                                         */
/*  output uint16 UsThrM_pAirExtEstim;                                        */
/*  output uint16 UsThrM_tDsThrCorMes;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTERFACAGE_BA_SC_vidInitOutput(void)
{
   VEMS_vidSET(AirSys_mfAirMesThrEstim, 0);
   VEMS_vidSET(Eng_rAirLd, 0);
   VEMS_vidSET(ExM_pUsTrbEstimTqSys, 0);
   VEMS_vidSET(Eng_bAcvCllEngReq, 0);
   VEMS_vidSET(UsThrM_pAirExtEstim, 0);
   VEMS_vidSET(UsThrM_tDsThrCorMes, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTERFACAGE_BA_SC_vidIntEngMSC                             */
/* !Description :  Interfaçage de la charge moteur en air corrigée            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  output uint16 Eng_rAirLd;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTERFACAGE_BA_SC_vidIntEngMSC(void)
{
   uint16 u16LocalAirLdCor;
   uint16 u16LocalEng_rAirLd;
   uint16 u16LocalEngM_rAirLdCor;


   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   u16LocalAirLdCor = (uint16)( (uint32)((25 * u16LocalEngM_rAirLdCor) + 128)
                              / 256);
   u16LocalEng_rAirLd = (uint16)MATHSRV_udtMIN(u16LocalAirLdCor, 4800);
   VEMS_vidSET(Eng_rAirLd, u16LocalEng_rAirLd);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTERFACAGE_BA_SC_vidInterfExMSC                           */
/* !Description :  Interfaçage du débit de gaz échappement sans EGR, de la    */
/*                 température et de la pression d'échappement du  collecteur */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ExM_pExMnfEstim;                                             */
/*  output uint16 ExM_pUsTrbEstimTqSys;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTERFACAGE_BA_SC_vidInterfExMSC(void)
{
   uint16 u16LocalTqSys;
   uint16 u16LocalExM_pExMnfEstim;

   VEMS_vidGET(ExM_pExMnfEstim, u16LocalExM_pExMnfEstim);
   u16LocalTqSys = (uint16)((uint32)(2 * u16LocalExM_pExMnfEstim) / 25);
   VEMS_vidSET(ExM_pUsTrbEstimTqSys, u16LocalTqSys);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTERFACAGE_BA_SC_vidIntAirSysSC                           */
/* !Description :  Interfaçage de la masse d’air pompée maximale et de        */
/*                 l’objectif de débit d’air papillon                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirSys_mfAirThrReqFil;                                       */
/*  input boolean InjSys_bAcvCllRailDcha;                                     */
/*  input boolean AirSys_bActStraLimSurge;                                    */
/*  output uint16 AirSys_mfAirMesThrEstim;                                    */
/*  output boolean Eng_bAcvCllEngReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTERFACAGE_BA_SC_vidIntAirSysSC(void)
{
   boolean bLocalInjSysRailDcha;
   boolean bLocalAirSysLimSurge;
   boolean bLocalEngCllEngReq;
   uint16  u16LocalAirSys_mfAirMesThrEstim;
   uint16  u16LocalAirSys_mfAirThrReq;
   uint32  u32LocalAirThr;


   VEMS_vidGET(AirSys_mfAirThrReqFil, u16LocalAirSys_mfAirThrReq);
   u32LocalAirThr = (uint32)((250 * u16LocalAirSys_mfAirThrReq) + 64) / 128;
   u16LocalAirSys_mfAirMesThrEstim = (uint16)MATHSRV_udtMIN(u32LocalAirThr,
                                                            38400);
   VEMS_vidSET(AirSys_mfAirMesThrEstim, u16LocalAirSys_mfAirMesThrEstim);
   VEMS_vidGET(InjSys_bAcvCllRailDcha, bLocalInjSysRailDcha);
   VEMS_vidGET(AirSys_bActStraLimSurge, bLocalAirSysLimSurge);
   if (  (bLocalInjSysRailDcha != 0)
      || (bLocalAirSysLimSurge != 0))
   {
      bLocalEngCllEngReq = 1;
   }
   else
   {
      bLocalEngCllEngReq = 0;
   }
   VEMS_vidSET(Eng_bAcvCllEngReq, bLocalEngCllEngReq);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTERFACAGE_BA_SC_vidIntrfUsThrM                           */
/* !Description :  Interfaçage de la pression atmosphérique                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_07792_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 UsThrM_pAirExt;                                              */
/*  input uint16 UsThrM_tThrMes;                                              */
/*  output uint16 UsThrM_pAirExtEstim;                                        */
/*  output uint16 UsThrM_tDsThrCorMes;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTERFACAGE_BA_SC_vidIntrfUsThrM(void)
{
   uint16 u16LocalUsThrM_pAirExt;
   uint16 u16LocalUsThrM_tThrMes;
   uint16 u16LocalUsThrM_tDsThrCorMes;


   VEMS_vidGET(UsThrM_pAirExt, u16LocalUsThrM_pAirExt);
   VEMS_vidGET(UsThrM_tThrMes, u16LocalUsThrM_tThrMes);

   VEMS_vidSET(UsThrM_pAirExtEstim, u16LocalUsThrM_pAirExt);
   u16LocalUsThrM_tDsThrCorMes =
      (uint16)MATHSRV_udtMIN(u16LocalUsThrM_tThrMes, 65408);
   VEMS_vidSET(UsThrM_tDsThrCorMes, u16LocalUsThrM_tDsThrCorMes);
}
/*-------------------------------- end of file -------------------------------*/