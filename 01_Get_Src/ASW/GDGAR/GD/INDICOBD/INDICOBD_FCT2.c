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
/* !File            : INDICOBD_FCT2.C                                         */
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
/*   1 / INDICOBD_vidDftMILCntPrev                                            */
/*   2 / INDICOBD_vidMngDftMILCntInc                                          */
/*   3 / INDICOBD_vidDftMILCntInc                                             */
/*   4 / INDICOBD_vidMngDftMILCntDec                                          */
/*   5 / INDICOBD_vidDftMILCntDec                                             */
/*   6 / INDICOBD_vidDftMILRstCnt                                             */
/*   7 / INDICOBD_vidDstCntRstCdn                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5075367 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065277                                         */
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

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "INDICOBD.h"
#include "INDICOBD_L.h"
#include "INDICOBD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDftMILCntPrev                                  */
/* !Description :  This function recovers the previous value of the counter in*/
/*                 order to reinit it even for a failure clear event.         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IndicOBD_ctDftObdCf;                                          */
/*  output uint8 INDICOBD_u8ctDftObdCfPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDftMILCntPrev(void)
{
   INDICOBD_u8ctDftObdCfPrev = IndicOBD_ctDftObdCf;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidMngDftMILCntInc                                */
/* !Description :  This function check if there is a MIL relevant failure     */
/*                 enters the OBD confirmed state                             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidDftMILCntInc();                              */
/*  input GD_strClasObd GD_astrClasObd[20];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidMngDftMILCntInc
(
   uint16 u16IdxDft
)
{
   if (GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].bEnaMIL != 0)
   {
      INDICOBD_vidDftMILCntInc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDftMILCntInc                                   */
/* !Description :  This function check if ther is a MIL relevant failure is   */
/*                 cleared, the counter is decremented by one unit.           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 INDICOBD_u8ctDftObdCfPrev;                                    */
/*  output uint8 IndicOBD_ctDftObdCf;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDftMILCntInc(void)
{
   uint16 u16LocalctDftObdCf;


   u16LocalctDftObdCf = (uint16)(INDICOBD_u8ctDftObdCfPrev + 1);
   IndicOBD_ctDftObdCf = (uint8)MATHSRV_udtMIN(u16LocalctDftObdCf, 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidMngDftMILCntDec                                */
/* !Description :  Each time a MIL relevant failure enters the OBD confirmed  */
/*                 state, the counter is incremented by one unit.             */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidDftMILCntDec();                              */
/*  input GD_strClasObd GD_astrClasObd[20];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidMngDftMILCntDec
(
   uint16 u16IdxDft
)
{
   if (GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].bEnaMIL != 0)
   {
      INDICOBD_vidDftMILCntDec();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDftMILCntDec                                   */
/* !Description :  Each time a MIL relevant failure is cleared, the counter is*/
/*                 decremented by one unit.                                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 INDICOBD_u8ctDftObdCfPrev;                                    */
/*  output uint8 IndicOBD_ctDftObdCf;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDftMILCntDec(void)
{
   sint16 s16LocalctDftObdCf;


   s16LocalctDftObdCf = (sint16)(INDICOBD_u8ctDftObdCfPrev - 1);
   IndicOBD_ctDftObdCf = (uint8)MATHSRV_udtMAX(s16LocalctDftObdCf, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDftMILRstCnt                                   */
/* !Description :  The time and distance traveld counter with MIL illuminated */
/*                 are reinitialized when no more OBD relevant failure is     */
/*                 confirmed                                                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INDICOBD_vidDstCntRstCdn();                              */
/*  input boolean Tra_bCntMILRst;                                             */
/*  input boolean Ext_bMILReqCntRstTBMU;                                      */
/*  input boolean Ext_bMILReqCntRstAR2S;                                      */
/*  input boolean Ext_bMILReqCntRstHCU2;                                      */
/*  input boolean GMIL_bCfgExtDistMilOn_C;                                    */
/*  input uint8 IndicOBD_ctDftObdCf;                                          */
/*  input boolean INDICOBD_bDstCntRstCdnPrev;                                 */
/*  output boolean INDICOBD_bDstCntRstCdnPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDftMILRstCnt(void)
{
   boolean bLocalCntMILRst;
   boolean bLocalMILReqCntRstTBMU;
   boolean bLocalMILReqCntRstAR2S;
   boolean bLocalMILReqCntRstHCU2;
   boolean bLocalTrig;


   VEMS_vidGET(Tra_bCntMILRst, bLocalCntMILRst);
   VEMS_vidGET(Ext_bMILReqCntRstTBMU, bLocalMILReqCntRstTBMU);
   VEMS_vidGET(Ext_bMILReqCntRstAR2S, bLocalMILReqCntRstAR2S);
   VEMS_vidGET(Ext_bMILReqCntRstHCU2, bLocalMILReqCntRstHCU2);


   if (  (    (   (bLocalCntMILRst != 0)
              && (bLocalMILReqCntRstTBMU != 0)
              && (bLocalMILReqCntRstAR2S != 0)
              && (bLocalMILReqCntRstHCU2 != 0))
         || (GMIL_bCfgExtDistMilOn_C == 0))
      && (IndicOBD_ctDftObdCf == 0))
   {
      bLocalTrig = 1;
   }
   else
   {
      bLocalTrig = 0;
   }

   if (  (INDICOBD_bDstCntRstCdnPrev == 0)
      && (bLocalTrig != 0))
   {
      INDICOBD_vidDstCntRstCdn();
   }
   INDICOBD_bDstCntRstCdnPrev = bLocalTrig;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidDstCntRstCdn                                   */
/* !Description :  This function reinitializes the time and distance counters */
/*                 to 0                                                       */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 GMIL_tiMinsEngrunMilOn;                                     */
/*  output uint32 GMIL_tiEngrunMilOn;                                         */
/*  output uint16 GMIL_dstKmMilOn;                                            */
/*  output uint32 Dist_hecto_parcourue_depuis_mil;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidDstCntRstCdn(void)
{
   VEMS_vidSET(GMIL_tiMinsEngrunMilOn, 0);
   GMIL_tiEngrunMilOn = 0;
   VEMS_vidSET(GMIL_dstKmMilOn, 0);
   Dist_hecto_parcourue_depuis_mil = 0;
}
/*-------------------------------- end of file -------------------------------*/