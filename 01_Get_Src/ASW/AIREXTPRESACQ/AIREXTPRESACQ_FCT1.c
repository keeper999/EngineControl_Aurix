/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIREXTPRESACQ                                           */
/* !Description     : AIREXTPRESACQ Component.                                */
/*                                                                            */
/* !Module          : AIREXTPRESACQ                                           */
/* !Description     : Atmospheric Pressure Acquisition.                       */
/*                                                                            */
/* !File            : AIREXTPRESACQ_FCT1.C                                    */
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
/*   1 / AIREXTPRESACQ_vidInit                                                */
/*   2 / AIREXTPRESACQ_vidCalc                                                */
/*   3 / AIREXTPRESACQ_vidAcquisition                                         */
/*   4 / AIREXTPRESACQ_vidAtmPresDiag                                         */
/*   5 / AIREXTPRESACQ_vidElectDiag                                           */
/*   6 / AIREXTPRESACQ_vidAtmPreTreat                                         */
/*   7 / AIREXTPRESACQ_vidInterfacage                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6525166 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065883                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/AIREXTPRESACQ/AIREXTPRESACQ_FCT1.C$*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AIREXTPRESACQ.h"
#include "AIREXTPRESACQ_L.h"
#include "AIREXTPRESACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidInit                                      */
/* !Description :  Initilyze the value of atmospheric pressure.               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pAirExtIni_C;                                            */
/*  output uint16 Ext_pAirExtMesSI;                                           */
/*  output uint16 Ext_pAirExtMesSIIf;                                         */
/*  output uint16 AirExtPresAcq_upAirMes;                                     */
/*  output uint16 Ext_pAirExtAcq;                                             */
/*  output uint16 Ext_pAirExtMes;                                             */
/*  output uint16 Ext_pAirExtMesPrev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidInit(void)
{
   uint16 u16LocalExt_pAirExtMesSI;
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalpAirExtMes;


   u16LocalExt_pAirExtMesSI = Ext_pAirExtIni_C;
   VEMS_vidSET(Ext_pAirExtMesSI, u16LocalExt_pAirExtMesSI);
   VEMS_vidSET(Ext_pAirExtMesSIIf, u16LocalExt_pAirExtMesSI);
   VEMS_vidSET(AirExtPresAcq_upAirMes, 0);
   VEMS_vidSET(Ext_pAirExtAcq, 0);

   u16LocalpAirExtMes = (uint16)((u16LocalExt_pAirExtMesSI * 2) / 25);
   u16LocalExt_pAirExtMes = (uint16)MATHSRV_udtCLAMP(u16LocalpAirExtMes,
                                                     500,
                                                     1500);
   VEMS_vidSET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   Ext_pAirExtMesPrev = u16LocalExt_pAirExtMes;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidCalc                                      */
/* !Description :  lunch the 3 steps of the atmospheric pressure calculation. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIREXTPRESACQ_vidAcquisition();                          */
/*  extf argret void AIREXTPRESACQ_vidAtmPresDiag();                          */
/*  extf argret void AIREXTPRESACQ_vidAtmPreTreat();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidCalc(void)
{
   AIREXTPRESACQ_vidAcquisition();
   AIREXTPRESACQ_vidAtmPresDiag();
   AIREXTPRESACQ_vidAtmPreTreat();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidAcquisition                               */
/* !Description :  The function deals with the pressure sensor voltage        */
/*                 acquisition and the voltage-                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acquisition_press_airext;                                    */
/*  input uint16 AirExtPresAcq_upAirMes_A[2];                                 */
/*  input uint16 AirExtPresAcq_upPairAcq_T[2];                                */
/*  output uint16 AirExtPresAcq_upAirMes;                                     */
/*  output uint16 Ext_pAirExtAcq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidAcquisition(void)
{
   uint16 u16LocalBKPTSup;
   uint16 u16LocalBKPTInf;
   uint16 u16LocalMapSup;
   uint16 u16LocalMapInf;
   uint16 u16LocalSiteInterpolation;
   uint16 u16LocalInterpolation;
   uint16 u16LocalAcquisition_press_airext;
   uint16 u16LocalAirExtPresAcq_upAirMes;
   uint16 u16LocalExt_pAirExtAcq;
   uint16 u16LocalABS;
   uint32 u32LocalDeltaValue;
   uint32 u32LocalResultValue;
   uint32 u32LocalInterpolation;
   sint32 s32LocalInterpolation;


   VEMS_vidGET(Acquisition_press_airext, u16LocalAcquisition_press_airext);
   u16LocalAirExtPresAcq_upAirMes =
      (uint16)MATHSRV_udtMIN(u16LocalAcquisition_press_airext, 4095);
   VEMS_vidSET(AirExtPresAcq_upAirMes, u16LocalAirExtPresAcq_upAirMes);
   if (AirExtPresAcq_upAirMes_A[1] >= AirExtPresAcq_upAirMes_A[0])
   {
      u16LocalBKPTSup = AirExtPresAcq_upAirMes_A[1];
      u16LocalBKPTInf = AirExtPresAcq_upAirMes_A[0];
      u16LocalMapSup = AirExtPresAcq_upPairAcq_T[1];
      u16LocalMapInf = AirExtPresAcq_upPairAcq_T[0];
   }
   else
   {
      u16LocalBKPTSup = AirExtPresAcq_upAirMes_A[0];
      u16LocalBKPTInf = AirExtPresAcq_upAirMes_A[1];
      u16LocalMapSup = AirExtPresAcq_upPairAcq_T[0];
      u16LocalMapInf = AirExtPresAcq_upPairAcq_T[1];
   }
   u16LocalExt_pAirExtAcq = 0;
   /*added to avoid compilation and QAC Warning*/
   if (AirExtPresAcq_upAirMes_A[1] != AirExtPresAcq_upAirMes_A[0])
   {
      if (u16LocalAirExtPresAcq_upAirMes >= u16LocalBKPTSup)
      {
         u16LocalExt_pAirExtAcq = u16LocalMapSup;
      }
      if (u16LocalAirExtPresAcq_upAirMes < u16LocalBKPTInf)
      {
         u16LocalExt_pAirExtAcq = u16LocalMapInf;
      }
      if (  (u16LocalAirExtPresAcq_upAirMes < u16LocalBKPTSup)
         && (u16LocalAirExtPresAcq_upAirMes >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of AirExtPresAcq_upAirMes with
            AirExtPresAcq_upAirMes_A */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS( u16LocalAirExtPresAcq_upAirMes
                                  - AirExtPresAcq_upAirMes_A[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation =(uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation = (uint16)( u32LocalDeltaValue
                                             / u16LocalInterpolation);
         /* Calculate the interpolation value on AirExtPresAcq_upPairAcq_T */

         s32LocalInterpolation = ( (sint32)AirExtPresAcq_upPairAcq_T[1]
                                 - (sint32)AirExtPresAcq_upPairAcq_T[0]);
         u16LocalABS = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16LocalABS * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
         }
         else
         {
            u32LocalInterpolation = u16LocalABS * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue = (uint32)( (sint32)AirExtPresAcq_upPairAcq_T[0]
                                       + s32LocalInterpolation);
         u16LocalExt_pAirExtAcq = (uint16)u32LocalResultValue;
      }
   }
   else
   {
      u16LocalExt_pAirExtAcq = AirExtPresAcq_upPairAcq_T[0];
   }
   VEMS_vidSET(Ext_pAirExtAcq, u16LocalExt_pAirExtAcq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidAtmPresDiag                               */
/* !Description :  Generate the dgo internal values and lunch the elictricals */
/*                 diagnostic                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void AIREXTPRESACQ_vidElectDiag();                            */
/*  output boolean Ext_bMonRunScp_AirExtPresAcq;                              */
/*  output boolean Ext_bMonRunScg_AirExtPresAcq;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidAtmPresDiag(void)
{
   boolean bLocalFRM_bInhDiag_pAirMes;


   bLocalFRM_bInhDiag_pAirMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PAIRMES);
   if ( bLocalFRM_bInhDiag_pAirMes != 0)
   {
      Ext_bMonRunScp_AirExtPresAcq = 0;
      Ext_bMonRunScg_AirExtPresAcq = 0;
   }
   else
   {
      Ext_bMonRunScp_AirExtPresAcq = 1;
      Ext_bMonRunScg_AirExtPresAcq = 1;
      AIREXTPRESACQ_vidElectDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidElectDiag                                 */
/* !Description :  The electrical diagnosis is managed in this sub-system.    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AirExtPresAcq_upAirMes;                                      */
/*  input uint16 Ext_uDgoScp_pAirExtMes_C;                                    */
/*  input uint16 Ext_uDgoScg_pAirExtMes_C;                                    */
/*  output boolean Ext_bDgoScp_AirExtPresAcq;                                 */
/*  output boolean Ext_bDgoScg_AirExtPresAcq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidElectDiag(void)
{
   uint16 u16LocalAirExtPresAcq_upAirMes;


   VEMS_vidGET(AirExtPresAcq_upAirMes, u16LocalAirExtPresAcq_upAirMes);
   if (u16LocalAirExtPresAcq_upAirMes > Ext_uDgoScp_pAirExtMes_C)
   {
      Ext_bDgoScp_AirExtPresAcq = 1;
   }
   else
   {
      Ext_bDgoScp_AirExtPresAcq = 0;
   }
   if (u16LocalAirExtPresAcq_upAirMes < Ext_uDgoScg_pAirExtMes_C)
   {
      Ext_bDgoScg_AirExtPresAcq = 1;
   }
   else
   {
      Ext_bDgoScg_AirExtPresAcq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidAtmPreTreat                               */
/* !Description :  In the nominal functioning case, the specification sends   */
/*                 the measured value.                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_03695_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 UsThrM_pAirExt;                                              */
/*  input boolean Ext_bDgoScg_AirExtPresAcq;                                  */
/*  input boolean Ext_bDgoScp_AirExtPresAcq;                                  */
/*  input uint16 Ext_pAirExtMesPrev;                                          */
/*  input uint16 Ext_pAirExtAcq;                                              */
/*  output uint16 Ext_pAirExtMesSIIf;                                         */
/*  output uint16 Ext_pAirExtMes;                                             */
/*  output uint16 Ext_pAirExtMesPrev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidAtmPreTreat(void)
{
   boolean bLocalFRM_bAcvDftMod_pAirMes;
   uint16  u16LocalExt_pAirExtMesSIIf;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalExt_pAirExtAcq;
   uint16  u16LocalUsThrM_pAirExt;
   uint32  u32LocalExt_pAirExt;
   uint32  u32LocalExt_pAirExtMes;


   bLocalFRM_bAcvDftMod_pAirMes = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PAIRMES);
   if (bLocalFRM_bAcvDftMod_pAirMes != 0)
   {
      VEMS_vidGET(UsThrM_pAirExt, u16LocalUsThrM_pAirExt);
      u32LocalExt_pAirExt = u16LocalUsThrM_pAirExt;
   }
   else
   {
      if (  (Ext_bDgoScg_AirExtPresAcq != 0)
         || (Ext_bDgoScp_AirExtPresAcq != 0))
      {
         u32LocalExt_pAirExt = (uint32)(((Ext_pAirExtMesPrev * 25) + 1) / 2);
      }
      else
      {
         VEMS_vidGET(Ext_pAirExtAcq, u16LocalExt_pAirExtAcq);
         u32LocalExt_pAirExt = u16LocalExt_pAirExtAcq;
      }
   }
   u16LocalExt_pAirExtMesSIIf = (uint16)MATHSRV_udtMIN(u32LocalExt_pAirExt,
                                                     65535);
   VEMS_vidSET(Ext_pAirExtMesSIIf, u16LocalExt_pAirExtMesSIIf);
   u32LocalExt_pAirExtMes = (u32LocalExt_pAirExt * 2) / 25;
   u16LocalExt_pAirExtMes = (uint16)MATHSRV_udtCLAMP(u32LocalExt_pAirExtMes,
                                                     500,
                                                     1500);
   VEMS_vidSET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   Ext_pAirExtMesPrev = u16LocalExt_pAirExtMes;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIREXTPRESACQ_vidInterfacage                               */
/* !Description :  Mesurement of atmospheric pressure interfacing             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pAirExtMesSIIf;                                          */
/*  output uint16 Ext_pAirExtMesSI;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIREXTPRESACQ_vidInterfacage(void)
{
   uint16 u16LocalExt_pAirExtMesSIIf;


   VEMS_vidGET(Ext_pAirExtMesSIIf, u16LocalExt_pAirExtMesSIIf);
   VEMS_vidSET(Ext_pAirExtMesSI, u16LocalExt_pAirExtMesSIIf);
}

/*------------------------------- end of file --------------------------------*/