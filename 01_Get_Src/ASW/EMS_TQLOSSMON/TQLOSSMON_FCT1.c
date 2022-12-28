/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLOSSMON                                               */
/* !Description     : TQLOSSMON component.                                    */
/*                                                                            */
/* !Module          : TQLOSSMON                                               */
/* !Description     : Safety TMS : Valider Pertes Globales                    */
/*                                                                            */
/* !File            : TQLOSSMON_FCT1.C                                        */
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
/*   1 / TQLOSSMON_vidInitOutput                                              */
/*   2 / TQLOSSMON_vidDet_Pertes_Access                                       */
/*   3 / TQLOSSMON_vidDet_Pertes_Altern                                       */
/*   4 / TQLOSSMON_vidValider_Reserve_GMV                                     */
/*   5 / TQLOSSMON_vidDet_Demande_Altern                                      */
/*   6 / TQLOSSMON_vidVal_Demande_Altern                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 01233 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_1793 / 1.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON_FC$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQLOSSMON.h"
#include "TQLOSSMON_L.h"
#include "TQLOSSMON_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidInitOutput                                    */
/* !Description :  Initialisation des parametres                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoTqSumLossCmp;                                  */
/*  output uint16 SftyMgt_tqSumLossCmpChkBuf;                                 */
/*  output boolean SftyMgt_bDgoEngLossAdp;                                    */
/*  output boolean SftyMgt_bDgoEngLossAdpRaw_MP;                              */
/*  output boolean SftyMgt_bDgoEngLossBVA;                                    */
/*  output boolean SftyMgt_bDgoTqAC;                                          */
/*  output boolean SftyMgt_bDgoTqAltLoss;                                     */
/*  output boolean SftyMgt_bDgoTqCkEngLoss;                                   */
/*  output boolean SftyMgt_bDgoTqCkHiPLoss;                                   */
/*  output boolean SftyMgt_bDgoTqFanRes;                                      */
/*  output boolean SftyMgt_bDgoTqStg;                                         */
/*  output uint16 SftyMgt_facFilTqCnvLoss;                                    */
/*  output uint16 SftyMgt_pwrAC3Loss;                                         */
/*  output uint16 SftyMgt_pwrAC4Loss;                                         */
/*  output uint16 SftyMgt_pwrACLoss;                                          */
/*  output uint16 SftyMgt_pwrACLossFil;                                       */
/*  output uint16 SftyMgt_spdSel;                                             */
/*  output uint16 SftyMgt_spdVehSel;                                          */
/*  output uint16 SftyMgt_tqACLoss;                                           */
/*  output uint16 SftyMgt_tqACLossChkBuf;                                     */
/*  output uint16 SftyMgt_tqACLoss_MP;                                        */
/*  output uint16 SftyMgt_tqAltLoss;                                          */
/*  output uint16 SftyMgt_tqAltLossChkBuf;                                    */
/*  output uint16 SftyMgt_tqAltLoss_MP;                                       */
/*  output uint16 SftyMgt_tqAuxSumLossCmp;                                    */
/*  output uint16 SftyMgt_tqCkEngLossAdpChkBuf;                               */
/*  output uint16 SftyMgt_tqCkEngLossChkBuf;                                  */
/*  output uint16 SftyMgt_tqCkEngLoss_MP;                                     */
/*  output uint16 SftyMgt_tqCkFricLoss;                                       */
/*  output uint16 SftyMgt_tqCkFricLoss_MP;                                    */
/*  output uint16 SftyMgt_tqCkPmpHiPLoss;                                     */
/*  output uint16 SftyMgt_tqCkPmpLoss;                                        */
/*  output uint16 SftyMgt_tqCkPmpLoss_MP;                                     */
/*  output uint16 SftyMgt_tqCkStrtLoss;                                       */
/*  output uint16 SftyMgt_tqCkStrtLoss_MP;                                    */
/*  output uint16 SftyMgt_tqCnvLossChkBuf;                                    */
/*  output uint16 SftyMgt_tqCnvLossEstimMax;                                  */
/*  output uint16 SftyMgt_tqCnvLossNotFilNotSat;                              */
/*  output uint16 SftyMgt_tqCnvLossNotSat;                                    */
/*  output uint16 SftyMgt_tqCnvLoss_MP;                                       */
/*  output uint16 SftyMgt_tqFanStrtLoss;                                      */
/*  output uint16 SftyMgt_tqStgPmpLnrLoss;                                    */
/*  output uint16 SftyMgt_tqStgPmpLoss;                                       */
/*  output uint16 SftyMgt_tqStgPmpLossChkBuf;                                 */
/*  output uint16 SftyMgt_tqStgPmpLossNotFil;                                 */
/*  output uint16 SftyMgt_tqStgPmpLoss_MP;                                    */
/*  output uint16 SftyMgt_tqStgPmpThdLoss;                                    */
/*  output uint16 SftyMgt_tqSumLossCmpEstim;                                  */
/*  output boolean SftyMgt_bDgoTqAuxLoss;                                     */
/*  output boolean TQLOSSMON_bCnvLossSat;                                     */
/*  output boolean TQLOSSMON_bDgoEngLossAdpRawPrev;                           */
/*  output boolean TQLOSSMON_bDgoTqCkEngLossPrev;                             */
/*  output boolean TQLOSSMON_bForDebOutput;                                   */
/*  output boolean TQLOSSMON_bFstDebOutput;                                   */
/*  output boolean TQLOSSMON_bFstFunctDebTODInPrev;                           */
/*  output boolean TQLOSSMON_bSndDebOutput;                                   */
/*  output boolean TQLOSSMON_bSumLossCmpPrev;                                 */
/*  output boolean TQLOSSMON_bThdDebOutput;                                   */
/*  output uint16 TQLOSSMON_u16EngLossAdpCounter;                             */
/*  output uint16 TQLOSSMON_u16FirstDebFctCounter;                            */
/*  output uint16 TQLOSSMON_u16FourthDebFctCounter;                           */
/*  output uint16 TQLOSSMON_u16SecondDebFctCounter;                           */
/*  output uint16 TQLOSSMON_u16StrtLossCounter;                               */
/*  output uint16 TQLOSSMON_u16ThirdDebFctCounter;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidInitOutput(void)
{
   /* Outputs initialization */
   VEMS_vidSET(SftyMgt_bDgoTqSumLossCmp, 0);
   VEMS_vidSET(SftyMgt_tqSumLossCmpChkBuf, 0);
   /* Internal parameters initialization */
   SftyMgt_bDgoEngLossAdp = 0;
   SftyMgt_bDgoEngLossAdpRaw_MP = 0;
   SftyMgt_bDgoEngLossBVA = 0;
   SftyMgt_bDgoTqAC = 0;
   SftyMgt_bDgoTqAltLoss = 0;
   SftyMgt_bDgoTqCkEngLoss = 0;
   SftyMgt_bDgoTqCkHiPLoss = 0;
   SftyMgt_bDgoTqFanRes = 0;
   SftyMgt_bDgoTqStg = 0;
   SftyMgt_facFilTqCnvLoss = 0;
   SftyMgt_pwrAC3Loss = 0;
   SftyMgt_pwrAC4Loss = 0;
   SftyMgt_pwrACLoss = 0;
   SftyMgt_pwrACLossFil = 0;
   SftyMgt_spdSel = 0;
   SftyMgt_spdVehSel = 0;
   SftyMgt_tqACLoss = 0;
   SftyMgt_tqACLossChkBuf = 0;
   SftyMgt_tqACLoss_MP = 0;
   SftyMgt_tqAltLoss = 0;
   SftyMgt_tqAltLossChkBuf = 0;
   SftyMgt_tqAltLoss_MP = 0;
   SftyMgt_tqAuxSumLossCmp = 0;
   SftyMgt_tqCkEngLossAdpChkBuf = 0;
   SftyMgt_tqCkEngLossChkBuf = 0;
   SftyMgt_tqCkEngLoss_MP = 0;
   SftyMgt_tqCkFricLoss = 0;
   SftyMgt_tqCkFricLoss_MP = 0;
   SftyMgt_tqCkPmpHiPLoss = 0;
   SftyMgt_tqCkPmpLoss = 0;
   SftyMgt_tqCkPmpLoss_MP = 0;
   SftyMgt_tqCkStrtLoss = 0;
   SftyMgt_tqCkStrtLoss_MP = 0;
   SftyMgt_tqCnvLossChkBuf = 0;
   SftyMgt_tqCnvLossEstimMax = 0;
   SftyMgt_tqCnvLossNotFilNotSat = 0;
   SftyMgt_tqCnvLossNotSat = 0;
   SftyMgt_tqCnvLoss_MP = 0;
   SftyMgt_tqFanStrtLoss = 0;
   SftyMgt_tqStgPmpLnrLoss = 0;
   SftyMgt_tqStgPmpLoss = 0;
   SftyMgt_tqStgPmpLossChkBuf = 0;
   SftyMgt_tqStgPmpLossNotFil = 0;
   SftyMgt_tqStgPmpLoss_MP = 0;
   SftyMgt_tqStgPmpThdLoss = 0;
   SftyMgt_tqSumLossCmpEstim = 0;
   SftyMgt_bDgoTqAuxLoss = 0;
   /* Initialization of the created parameters */
   TQLOSSMON_bCnvLossSat = 0;
   TQLOSSMON_bDgoEngLossAdpRawPrev = 0;
   TQLOSSMON_bDgoTqCkEngLossPrev = 0;
   TQLOSSMON_bForDebOutput = 0;
   TQLOSSMON_bFstDebOutput = 0;
   TQLOSSMON_bFstFunctDebTODInPrev = 0;
   TQLOSSMON_bSndDebOutput = 0;
   TQLOSSMON_bSumLossCmpPrev = 0;
   TQLOSSMON_bThdDebOutput = 0;
   TQLOSSMON_u16EngLossAdpCounter = 0;
   TQLOSSMON_u16FirstDebFctCounter = 0;
   TQLOSSMON_u16FourthDebFctCounter = 0;
   TQLOSSMON_u16SecondDebFctCounter = 0;
   TQLOSSMON_u16StrtLossCounter = 0;
   TQLOSSMON_u16ThirdDebFctCounter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Access                             */
/* !Description :  Cette fonction détermine les prélèvements de couple des    */
/*                 accessoires. Elle est composée de 4 sous fonctions         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidDet_Pertes_Altern();                        */
/*  extf argret void TQLOSSMON_vidDet_Pertes_Clim();                          */
/*  extf argret void TQLOSSMON_vidDet_Pertes_DA();                            */
/*  extf argret void TQLOSSMON_vidDet_Pertes_BVM();                           */
/*  extf argret void TQLOSSMON_vidCoord_Pertes_Access();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Access(void)
{
   TQLOSSMON_vidDet_Pertes_Altern();
   TQLOSSMON_vidDet_Pertes_Clim();
   TQLOSSMON_vidDet_Pertes_DA();
   TQLOSSMON_vidDet_Pertes_BVM();
   TQLOSSMON_vidCoord_Pertes_Access();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Altern                             */
/* !Description :  Cette fonction permet de valider l’estimation du couple    */
/*                 prélevé par l’alternateur.                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidValider_Reserve_GMV();                      */
/*  extf argret void TQLOSSMON_vidDet_Demande_Altern();                       */
/*  extf argret void TQLOSSMON_vidVal_Demande_Altern();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Altern(void)
{
   TQLOSSMON_vidValider_Reserve_GMV();
   TQLOSSMON_vidDet_Demande_Altern();
   TQLOSSMON_vidVal_Demande_Altern();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidValider_Reserve_GMV                           */
/* !Description :  Cette fonction détermine la borne max du couple de réserves*/
/*                 GMV et valide que le couple de réserves calculé au niveau  */
/*                 ACS est inférieur à cette valeur.                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqFanStrtLossUnChkBuf;                               */
/*  input uint16 SftyMgt_tqErrThdSftyLossAux_C;                               */
/*  input uint16 SftyMgt_tqFanStrtLossMax_C;                                  */
/*  output uint16 SftyMgt_tqFanStrtLoss;                                      */
/*  output boolean SftyMgt_bDgoTqFanRes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidValider_Reserve_GMV(void)
{
   uint16 u16LocaltqFanStrtLossUnChkBuf;
   uint32 u32LocalSftyLossSum;


   VEMS_vidGET(SftyMgt_tqFanStrtLossUnChkBuf, u16LocaltqFanStrtLossUnChkBuf);

   SftyMgt_tqFanStrtLoss =
      (uint16)MATHSRV_udtMIN(u16LocaltqFanStrtLossUnChkBuf, 8000);

   u32LocalSftyLossSum = (uint32)( SftyMgt_tqErrThdSftyLossAux_C
                                 + SftyMgt_tqFanStrtLossMax_C);

   if (u32LocalSftyLossSum < u16LocaltqFanStrtLossUnChkBuf)
   {
      SftyMgt_bDgoTqFanRes = 1;
   }
   else
   {
      SftyMgt_bDgoTqFanRes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Demande_Altern                            */
/* !Description :  Cette fonction permet de déterminer le couple maximum que  */
/*                 l’alternateur peut demander. Ce couple maximum dépend du   */
/*                 type d’alternateur.                                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 SftyMgt_idxAltTyp_C;                                          */
/*  input uint16 SftyMgt_tqAltLossMaxMEL_C;                                   */
/*  input uint16 SftyMgt_tqAltLossMaxGAP_C;                                   */
/*  input uint16 SftyMgt_tqAltLossMaxICCP_C;                                  */
/*  input uint16 SftyMgt_tqFanStrtLoss;                                       */
/*  input sint16 SftyMgt_tqAltLossMin_C;                                      */
/*  input sint16 SftyMgt_tqAltLossMax_C;                                      */
/*  output uint16 SftyMgt_tqAltLoss;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Demande_Altern(void)
{
   uint16 u16LocalAltLossMax;
   sint32 s32LocalAltLossMaxSum;


   switch (SftyMgt_idxAltTyp_C)
   {
      case 0:
         u16LocalAltLossMax = SftyMgt_tqAltLossMaxMEL_C;
         break;
      case 1:
         u16LocalAltLossMax = SftyMgt_tqAltLossMaxGAP_C;
         break;
      case 2:
         u16LocalAltLossMax = SftyMgt_tqAltLossMaxICCP_C;
         break;
      default:
         u16LocalAltLossMax = SftyMgt_tqAltLossMaxICCP_C;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   s32LocalAltLossMaxSum = (sint32)(u16LocalAltLossMax + SftyMgt_tqFanStrtLoss);

   s32LocalAltLossMaxSum = MATHSRV_udtCLAMP(s32LocalAltLossMaxSum,
                                            SftyMgt_tqAltLossMin_C,
                                            SftyMgt_tqAltLossMax_C);

   SftyMgt_tqAltLoss = (uint16)MATHSRV_udtCLAMP(s32LocalAltLossMaxSum, 0, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidVal_Demande_Altern                            */
/* !Description :  Cette fonction permet de valider que le couple prélevé par */
/*                 l’alternateur est inférieur à son enveloppe maximale.      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_tqAltLossUnChkBuf;                                   */
/*  input uint16 SftyMgt_tqErrThdSftyLossAux_C;                               */
/*  input uint16 SftyMgt_tqAltLoss;                                           */
/*  input uint16 SftyMgt_tqAltLoss_MP;                                        */
/*  output uint16 SftyMgt_tqAltLossChkBuf;                                    */
/*  output uint16 SftyMgt_tqAltLoss_MP;                                       */
/*  output boolean SftyMgt_bDgoTqAltLoss;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidVal_Demande_Altern(void)
{
   sint16 s16LocalSftyMgt_tqAltLossUnChkBu;
   uint32 u32LocaltqAltLoss;


   VEMS_vidGET(SftyMgt_tqAltLossUnChkBuf, s16LocalSftyMgt_tqAltLossUnChkBu);
   SftyMgt_tqAltLossChkBuf =
      (uint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqAltLossUnChkBu, 0, 8000);

   u32LocaltqAltLoss = (uint32)( SftyMgt_tqErrThdSftyLossAux_C
                               + SftyMgt_tqAltLoss);
   SftyMgt_tqAltLoss_MP = (uint16)MATHSRV_udtMIN(u32LocaltqAltLoss, 8000);

   if (SftyMgt_tqAltLoss_MP < s16LocalSftyMgt_tqAltLossUnChkBu)
   {
      SftyMgt_bDgoTqAltLoss = 1;
   }
   else
   {
      SftyMgt_bDgoTqAltLoss = 0;
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*---------------------------- end of file -----------------------------------*/