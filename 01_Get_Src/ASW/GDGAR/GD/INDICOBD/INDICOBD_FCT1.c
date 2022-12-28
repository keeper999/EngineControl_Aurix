/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INDICOBD                                                */
/* !Description     : INDICOBD Component                                      */
/*                                                                            */
/* !Module          : INDICOBD                                                */
/* !Description     : REGULATEUR DES INDICATEURS OBD                          */
/*                                                                            */
/* !File            : INDICOBD_FCT1.c                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / INDICOBD_vidInit                                                     */
/*   2 / INDICOBD_vidIndObdDstAndDurRstDf                                     */
/*   3 / INDICOBD_vidIndicOBDDstRstDft                                        */
/*   4 / INDICOBD_vidIndicOBDDurRstDft                                        */
/*   5 / INDICOBD_DstAndDurMIL                                                */
/*   6 / INDICOBD_vidDstAndDurnCnt                                            */
/*   7 / INDICOBD_vidF04_RstCnt                                               */
/*   8 / INDICOBD_vidEnableEngRun                                             */
/*   9 / INDICOBD_vidDisableEngRun                                            */
/*   10 / INDICOBD_vidDstPrevCalc                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5075367 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065277                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/INDICOBD/INDICOBD_FCT1.C_v   $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "INDICOBD.h"
#include "INDICOBD_L.h"
#include "INDICOBD_IM.h"
#include "NVMSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidInit                                           */
/* !Description :  This bloc is called at the ECU’s reset event. It           */
/*                 initialises and read the data written in EEPROM at the last*/
/*                 powerltach by the bloc F05_IndicOBD_StoreData              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 GMIL_tiMinsEngrunMilOn;                                      */
/*  input uint16 GMIL_tiMinsEngrunRstDft;                                     */
/*  input uint16 GMIL_dstKmMilOn;                                             */
/*  input uint16 GMIL_dstKmRstDft;                                            */
/*  input uint8 IndicOBD_ctDftObdCf;                                          */
/*  output uint32 GMIL_tiEngrunMilOn;                                         */
/*  output uint32 GMIL_tiEngrunRstDft;                                        */
/*  output uint32 Dist_hecto_parcourue_depuis_mil;                            */
/*  output uint32 Dist_hecto_depuis_RstDft;                                   */
/*  output boolean GMIL_bEngRun;                                              */
/*  output boolean INDICOBD_bDstCntRstCdnPrev;                                */
/*  output uint8 INDICOBD_u8ctDftObdCfPrev;                                   */
/*  output uint16 IndicOBD_DstHecto_prev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidInit(void)
{
   uint16  u16LocaltiMinsEngrunMilOn;
   uint16  u16LocaltiMinsEngrunRstDft;
   uint16  u16LocaldstKmMilOn;
   uint16  u16LocaldstKmRstDft;


   VEMS_vidGET(GMIL_tiMinsEngrunMilOn, u16LocaltiMinsEngrunMilOn);
   VEMS_vidGET(GMIL_tiMinsEngrunRstDft, u16LocaltiMinsEngrunRstDft);
   VEMS_vidGET(GMIL_dstKmMilOn, u16LocaldstKmMilOn);
   VEMS_vidGET(GMIL_dstKmRstDft, u16LocaldstKmRstDft);

   GMIL_tiEngrunMilOn = u16LocaltiMinsEngrunMilOn * (uint32)GMIL_MIN_SEC;
   GMIL_tiEngrunRstDft = u16LocaltiMinsEngrunRstDft * (uint32)GMIL_MIN_SEC;
   Dist_hecto_parcourue_depuis_mil = u16LocaldstKmMilOn * (uint32)GMIL_KM_HECT;
   Dist_hecto_depuis_RstDft = u16LocaldstKmRstDft * (uint32)GMIL_KM_HECT;

   GMIL_bEngRun = 0;
   INDICOBD_bDstCntRstCdnPrev = 0;
   INDICOBD_u8ctDftObdCfPrev = IndicOBD_ctDftObdCf;
   IndicOBD_DstHecto_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidIndObdDstAndDurRstDf                           */
/* !Description :  The calculation of  the time and distance since the last   */
/*                 clear failure is effective only during the ECU’s main wake */
/*                 up.                                                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INDICOBD_vidIndicOBDDstRstDft();                         */
/*  extf argret void INDICOBD_vidIndicOBDDurRstDft();                         */
/*  input boolean GOBD_bKeyOBD;                                               */
/*  input boolean GMIL_bEngRun;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidIndObdDstAndDurRstDf(void)
{
   boolean bLocalGOBD_bKeyOBD;


   VEMS_vidGET(GOBD_bKeyOBD, bLocalGOBD_bKeyOBD);
   if (bLocalGOBD_bKeyOBD != 0)
   {
      INDICOBD_vidIndicOBDDstRstDft();
      if (GMIL_bEngRun != 0)
      {
         INDICOBD_vidIndicOBDDurRstDft();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidIndicOBDDstRstDft                              */
/* !Description :  This function generates GMIL_dstKmRstDft : The covered     */
/*                 distance since the last clear failure in kilometres.       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Distance_parcourue_hectometre;                               */
/*  input uint16 IndicOBD_DstHecto_prev;                                      */
/*  input uint32 Dist_hecto_depuis_RstDft;                                    */
/*  output uint32 Dist_hecto_depuis_RstDft;                                   */
/*  output uint16 GMIL_dstKmRstDft;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidIndicOBDDstRstDft(void)
{
   uint16 u16LocalDistance_parcourue_hect;
   uint16 u16LocalGMIL_dstKmRstDft;
   uint32 u32LocalGMIL_dstKmRstDft;
   uint32 u32LocalDiff;
   sint32 s32LocalDiff1;


   VEMS_vidGET(Distance_parcourue_hectometre, u16LocalDistance_parcourue_hect);
   s32LocalDiff1 = (sint32)( u16LocalDistance_parcourue_hect
                           - IndicOBD_DstHecto_prev);
   if (s32LocalDiff1 >= 0)
   {
      u32LocalDiff = (429496729UL - (uint32)s32LocalDiff1);
      if (Dist_hecto_depuis_RstDft < u32LocalDiff)
      {
         Dist_hecto_depuis_RstDft = ( ( Dist_hecto_depuis_RstDft
                                      + u16LocalDistance_parcourue_hect)
                                    - IndicOBD_DstHecto_prev);
      }
      else
      {
         Dist_hecto_depuis_RstDft = 429496729UL;
      }
   }
   else
   {
      u32LocalDiff = (uint32)((-1) * s32LocalDiff1);
      if (Dist_hecto_depuis_RstDft <= u32LocalDiff)
      {
         Dist_hecto_depuis_RstDft = 0;
      }
      else
      {
         Dist_hecto_depuis_RstDft = ( ( Dist_hecto_depuis_RstDft
                                      + u16LocalDistance_parcourue_hect)
                                    - IndicOBD_DstHecto_prev);
         Dist_hecto_depuis_RstDft = MATHSRV_udtMIN(Dist_hecto_depuis_RstDft,
                                                   429496729UL);
      }
   }

   u32LocalGMIL_dstKmRstDft = Dist_hecto_depuis_RstDft / 10;
   u16LocalGMIL_dstKmRstDft = (uint16)MATHSRV_udtMIN(u32LocalGMIL_dstKmRstDft,
                                                     65535);
   VEMS_vidSET(GMIL_dstKmRstDft, u16LocalGMIL_dstKmRstDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidIndicOBDDurRstDft                              */
/* !Description :  This function generates The time spent since the last clear*/
/*                 failure in minutes.                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 GMIL_tiEngrunRstDft;                                         */
/*  output uint32 GMIL_tiEngrunRstDft;                                        */
/*  output uint16 GMIL_tiMinsEngrunRstDft;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidIndicOBDDurRstDft(void)
{
   uint16 u16LocalGMIL_tiMinsEngrunRstDft;
   uint32 u32LocalDiv;


   if (GMIL_tiEngrunRstDft < UINT32_MAX)
   {
      GMIL_tiEngrunRstDft = (GMIL_tiEngrunRstDft + 1);
   }
   u32LocalDiv = GMIL_tiEngrunRstDft / 60;
   u16LocalGMIL_tiMinsEngrunRstDft = (uint16)MATHSRV_udtMIN(u32LocalDiv, 65535);
   VEMS_vidSET(GMIL_tiMinsEngrunRstDft, u16LocalGMIL_tiMinsEngrunRstDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_DstAndDurMIL                                      */
/* !Description :  The strategy calculating the regulatory indicators         */
/*                 relatives to the MIL lights up is divided into 2 functions */
/*                 : - F01_IndicOBD_DstCntRstCdn and                          */
/*                 F02_IndicOBD_DstAndDurnCnt_MilOn                           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INDICOBD_vidDstAndDurnCnt(argin uint32* DistHecto, argin */
/* uint32* GMIL_tiEngRun,argin uint16* GMIL_DstKm,argin uint16*               */
/* GMIL_tiMinsEngRun);                                                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean GMIL_bDftMilBlink;                                          */
/*  input boolean GMIL_bDftMilOn;                                             */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input boolean GOBD_bKeyOBD;                                               */
/*  input uint32 Dist_hecto_parcourue_depuis_mil;                             */
/*  input uint32 GMIL_tiEngrunMilOn;                                          */
/*  output uint16 GMIL_dstKmMilOn;                                            */
/*  output uint16 GMIL_tiMinsEngrunMilOn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_DstAndDurMIL(void)
{
   boolean bLocalGMIL_bDftMilBlink;
   boolean bLocalGMIL_bDftMilOn;
   boolean bLocalGOBD_bKeyOBD;
   boolean bLocalDC_bSyncGlbDC;
   uint16  u16LocalGMIL_dstKmMilOn;
   uint16  u16LocalGMIL_tiMinsEngrunMilOn;


   VEMS_vidGET(GMIL_bDftMilBlink, bLocalGMIL_bDftMilBlink);
   VEMS_vidGET(GMIL_bDftMilOn, bLocalGMIL_bDftMilOn);
   VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
   VEMS_vidGET(GOBD_bKeyOBD, bLocalGOBD_bKeyOBD);


   if (  (  (bLocalGMIL_bDftMilBlink != 0)
         || (bLocalGMIL_bDftMilOn != 0))
      && (bLocalDC_bSyncGlbDC != 0)
      && (bLocalGOBD_bKeyOBD != 0))
   {
      u16LocalGMIL_dstKmMilOn = 0;
      u16LocalGMIL_tiMinsEngrunMilOn = 0;
      INDICOBD_vidDstAndDurnCnt(&Dist_hecto_parcourue_depuis_mil,
                                &GMIL_tiEngrunMilOn,
                                &u16LocalGMIL_dstKmMilOn,
                                &u16LocalGMIL_tiMinsEngrunMilOn);
      VEMS_vidSET(GMIL_dstKmMilOn, u16LocalGMIL_dstKmMilOn);
      VEMS_vidSET(GMIL_tiMinsEngrunMilOn, u16LocalGMIL_tiMinsEngrunMilOn);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDstAndDurnCnt                                  */
/* !Description :  Generic Function                                           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Distance_parcourue_hectometre;                               */
/*  input uint16 IndicOBD_DstHecto_prev;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDstAndDurnCnt
(
   uint32* DistHecto,
   uint32* GMIL_tiEngRun,
   uint16* GMIL_DstKm,
   uint16* GMIL_tiMinsEngRun
)
{
   uint16 u16LocalDistParcourue_hectometre;
   uint32 u32LocalDistParcourue;
   uint32 u32LocalEngrunMilOn;
   uint32 u32LocalDiff;
   sint32 s32LocalDiff1;


   VEMS_vidGET(Distance_parcourue_hectometre, u16LocalDistParcourue_hectometre);

   s32LocalDiff1 = (sint32)( u16LocalDistParcourue_hectometre
                           - IndicOBD_DstHecto_prev);
   if (s32LocalDiff1 >= 0)
   {
      u32LocalDiff = (429496729UL - (uint32)s32LocalDiff1);
      if (*DistHecto < u32LocalDiff)
      {
         *DistHecto = ( ( *DistHecto
                        + u16LocalDistParcourue_hectometre)
                      - IndicOBD_DstHecto_prev);
      }
      else
      {
         *DistHecto = 429496729UL;
      }
   }
   else
   {
      u32LocalDiff = (uint32)((-1) * s32LocalDiff1);
      if (*DistHecto <= u32LocalDiff)
      {
         *DistHecto = 0;
      }
      else
      {
         *DistHecto = ( ( *DistHecto
                        + u16LocalDistParcourue_hectometre)
                      - IndicOBD_DstHecto_prev);
         *DistHecto = MATHSRV_udtMIN(*DistHecto, 429496729UL);
      }
   }

   u32LocalDistParcourue = *DistHecto / (uint32)GMIL_KM_HECT;

   if(u32LocalDistParcourue < (uint32)UINT16_MAX_VALUE)
   {
      *GMIL_DstKm = (uint16)u32LocalDistParcourue;
   }
   else
   {
      *GMIL_DstKm = UINT16_MAX_VALUE;
   }

   if (*GMIL_tiEngRun < UINT32_MAX)
   {
      *GMIL_tiEngRun = *GMIL_tiEngRun + (uint32)1;
   }

   u32LocalEngrunMilOn = *GMIL_tiEngRun / (uint32)GMIL_MIN_SEC;

   if(u32LocalEngrunMilOn < (uint32)UINT16_MAX_VALUE)
   {
      *GMIL_tiMinsEngRun = (uint16)u32LocalEngrunMilOn;
   }
   else
   {
      *GMIL_tiMinsEngRun = UINT16_MAX_VALUE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidF04_RstCnt                                     */
/* !Description :  This function reinitializes the time and distance counters */
/*                 at each manual clear failure event generated by            */
/*                 calibration, the after sale tool or Scan-Tool              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 GMIL_tiMinsEngrunMilOn;                                     */
/*  output uint16 GMIL_tiMinsEngrunRstDft;                                    */
/*  output uint32 GMIL_tiEngrunMilOn;                                         */
/*  output uint32 GMIL_tiEngrunRstDft;                                        */
/*  output uint8 IndicOBD_ctDftObdCf;                                         */
/*  output uint16 GMIL_dstKmMilOn;                                            */
/*  output uint16 GMIL_dstKmRstDft;                                           */
/*  output uint32 Dist_hecto_parcourue_depuis_mil;                            */
/*  output uint32 Dist_hecto_depuis_RstDft;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidF04_RstCnt(void)
{
   VEMS_vidSET(GMIL_tiMinsEngrunMilOn, 0);
   VEMS_vidSET(GMIL_tiMinsEngrunRstDft, 0);
   GMIL_tiEngrunMilOn = 0;
   GMIL_tiEngrunRstDft = 0;
   VEMS_vidSET(IndicOBD_ctDftObdCf, 0);
   VEMS_vidSET(GMIL_dstKmMilOn, 0);
   VEMS_vidSET(GMIL_dstKmRstDft, 0);
   Dist_hecto_parcourue_depuis_mil = 0;
   Dist_hecto_depuis_RstDft = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidEnableEngRun                                   */
/* !Description :  The Boolean GMIL_bEngRun is set to 1 as soon as the engine */
/*                 starts.                                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean GMIL_bEngRun;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidEnableEngRun(void)
{
   GMIL_bEngRun = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDisableEngRun                                  */
/* !Description :  The Boolean GMIL_bEngRun is set to 0 as soon as the engine */
/*                 stops.                                                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean GMIL_bEngRun;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDisableEngRun(void)
{
   GMIL_bEngRun = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDstPrevCalc                                    */
/* !Description :  This function produces the previous value of               */
/*                 Distance_parcourue_hectometre.                             */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Distance_parcourue_hectometre;                               */
/*  output uint16 IndicOBD_DstHecto_prev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDstPrevCalc(void)
{
   uint16 u16LocalDis_parcourue_hectometre;


   VEMS_vidGET(Distance_parcourue_hectometre, u16LocalDis_parcourue_hectometre);
   IndicOBD_DstHecto_prev = u16LocalDis_parcourue_hectometre;
}
/*-------------------------------- end of file -------------------------------*/