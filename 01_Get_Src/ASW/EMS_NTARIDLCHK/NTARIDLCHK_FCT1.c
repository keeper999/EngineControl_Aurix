/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NTARIDLCHK                                              */
/* !Description     : NTARIDLCHK component.                                   */
/*                                                                            */
/* !Module          : NTARIDLCHK                                              */
/* !Description     : Safety TMS : Valider consigne de Ralenti.               */
/*                                                                            */
/* !File            : NTARIDLCHK_FCT1.C                                       */
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
/*   1 / NTARIDLCHK_vidInitOutput                                             */
/*   2 / NTARIDLCHK_vidValConsigneRalenti                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5049983 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_1792 / 1.6Br1                                   */
/* !OtherRefs   : VEMS V02 ECU#065161                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/NTARIDLCHK/NTARIDLCHK_$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "NTARIDLCHK.h"
#include "NTARIDLCHK_L.h"
#include "NTARIDLCHK_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NTARIDLCHK_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_nTarIdlIni_C;                                        */
/*  output boolean SftyMgt_bDgoNIdl;                                          */
/*  output boolean NTARIDLCHK_bTqSysAcvTqSysPrev;                             */
/*  output uint16 NTARIDLCHK_u16CounterTMS1;                                  */
/*  output uint16 NTARIDLCHK_u16CounterTMS2;                                  */
/*  output uint16 NTARIDLCHK_u16TarIdlDynIdSysPrev;                           */
/*  output uint16 SftyMgt_nTarIdlTqSysDly_MP;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NTARIDLCHK_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDgoNIdl, 0);
   NTARIDLCHK_bTqSysAcvTqSysPrev = 0;
   NTARIDLCHK_u16CounterTMS1 = 0;
   NTARIDLCHK_u16CounterTMS2 = 0;
   NTARIDLCHK_u16TarIdlDynIdSysPrev = 0;
   SftyMgt_nTarIdlTqSysDly_MP = (uint16)MATHSRV_udtMIN(SftyMgt_nTarIdlIni_C,
                                                       32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NTARIDLCHK_vidValConsigneRalenti                           */
/* !Description :  Fonction qui permet de valider que la consigne de ralenti  */
/*                 statique ne dépasse pas le gradient max d’évolution toléré.*/
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01232_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_nTarIdlStrtTqSys;                                    */
/*  input boolean SftyMgt_bTqSysAcvTqSys;                                     */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint16 SftyMgt_nTarIdlATTqSys;                                      */
/*  input uint16 SftyMgt_nTarIdlSftyTqSys;                                    */
/*  input uint16 SftyMgt_nTarIdlUnChkBuf;                                     */
/*  input boolean SftyMgt_bInhIniNTarIdlStrt_C;                               */
/*  input uint16 SftyMgt_nMinEngSetTqSysAcv_C;                                */
/*  input boolean NTARIDLCHK_bTqSysAcvTqSysPrev;                              */
/*  input uint16 SftyMgt_nTarIdlStrt_MP;                                      */
/*  input uint16 SftyMgt_nTarIdlTqSysDly_MP;                                  */
/*  input uint16 SftyMgt_facIncMaxTarIdl_C;                                   */
/*  input uint8 SftyMgt_stGBxAT_C;                                            */
/*  input uint16 SftyMgt_nTarIdlMax_C;                                        */
/*  input uint16 SftyMgt_nOfsErrTarIdl_C;                                     */
/*  input uint16 SftyMgt_tiDlyNTarIdlDftOn_C;                                 */
/*  input uint16 NTARIDLCHK_u16CounterTMS1;                                   */
/*  input uint16 SftyMgt_nTarIdlTqSysTol_MP;                                  */
/*  input uint16 SftyMgt_nTarIdlDynIdlSys;                                    */
/*  input uint16 SftyMgt_nOfsIdlTakeOff;                                      */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input boolean SftyMgt_bIniIdlCtlIdlSys;                                   */
/*  input uint16 NTARIDLCHK_u16TarIdlDynIdSysPrev;                            */
/*  input uint16 SftyMgt_nOfsNTarIdlDyn_C;                                    */
/*  input uint16 SftyMgt_nTarIdlDynThd_C;                                     */
/*  input boolean SftyMgt_bInhIniIdlDyn_C;                                    */
/*  input boolean SftyMgt_bAcvIdlDynMon_MP;                                   */
/*  input sint16 SftyMgt_nGrdNTarIdlDyn_C;                                    */
/*  input uint8 SftyMgt_tiDlyNTarIdlDynDft_C;                                 */
/*  input uint16 NTARIDLCHK_u16CounterTMS2;                                   */
/*  input boolean NTARIDLCHK_bTurnOnDlyTMS1;                                  */
/*  input boolean NTARIDLCHK_bTurnOnDlyTMS2;                                  */
/*  output uint16 SftyMgt_nTarIdlStrt_MP;                                     */
/*  output uint16 SftyMgt_nTarIdlTqSysDly_MP;                                 */
/*  output uint16 SftyMgt_nTarIdlTqSysTol_MP;                                 */
/*  output uint16 NTARIDLCHK_u16CounterTMS1;                                  */
/*  output boolean NTARIDLCHK_bTurnOnDlyTMS1;                                 */
/*  output boolean SftyMgt_bAcvIdlDynMon_MP;                                  */
/*  output uint16 NTARIDLCHK_u16CounterTMS2;                                  */
/*  output boolean NTARIDLCHK_bTurnOnDlyTMS2;                                 */
/*  output boolean SftyMgt_bDgoNIdl;                                          */
/*  output boolean NTARIDLCHK_bTqSysAcvTqSysPrev;                             */
/*  output uint16 NTARIDLCHK_u16TarIdlDynIdSysPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NTARIDLCHK_vidValConsigneRalenti(void)
{
   boolean  bLocalSftyMgt_bTqSysAcvTqSys;
   boolean  bLocalSftyMgt_bIniIdlCtlIdlSys;
   boolean  bLocalInTurnOnDly2;
   uint8    u8LocalExt_stGBxCf;
   uint16   u16LocalSftyMgt_nTarIdlStrtTqSys;
   uint16   u16LocalSftyMgt_nTarIdl;
   uint16   u16LocalOutMin_1;
   uint16   u16LocalSftyMgt_nTarIdlATTqSys;
   uint16   u16LocalSftyMgt_nTarIdlSftyTqSys;
   uint16   u16LocalOutSwitch;
   uint16   u16LocalOutMax;
   uint16   u16LocalOutMin_2;
   uint16   u16LocalMinTdlyCounter;
   uint16   u16LocalSftyMgt_tiDlyNTarDftOn;
   uint16   u16LocalSftyMgt_nTarIdlDynIdlSys;
   uint16   u16LocalSftyMgt_nTarIdlUnChkBuf;
   uint16   u16LocalSftyMgt_tiDlyNTarIdlDft;
   uint16   u16LocalSftyMgt_nOfsIdlTakeOff;
   uint16   u16LocalSftyMgt_nEng;
   uint16   u16LocalMinTdlyCounter2;
   uint32   u32LocalSftyMgt_nTarIdl;
   uint32   u32LocalSftyMgt_nTarIdlTqSysTol;
   uint32   u32LocalSftyMgt_nOfsNTarIdlDyn;
   uint32   u32LocalSftyMgt_nEng;
   sint32   s32LocalSftyMgt_nTarIdlDynIdlSys;


   VEMS_vidGET(SftyMgt_nTarIdlStrtTqSys, u16LocalSftyMgt_nTarIdlStrtTqSys);
   VEMS_vidGET(SftyMgt_bTqSysAcvTqSys, bLocalSftyMgt_bTqSysAcvTqSys);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(SftyMgt_nTarIdlATTqSys, u16LocalSftyMgt_nTarIdlATTqSys);
   VEMS_vidGET(SftyMgt_nTarIdlSftyTqSys, u16LocalSftyMgt_nTarIdlSftyTqSys);
   VEMS_vidGET(SftyMgt_nTarIdlUnChkBuf, u16LocalSftyMgt_nTarIdlUnChkBuf);
   if (SftyMgt_bInhIniNTarIdlStrt_C != 0)
   {
      SftyMgt_nTarIdlStrt_MP =
         (uint16)MATHSRV_udtMIN(SftyMgt_nMinEngSetTqSysAcv_C, 32000);
   }
   else
   {
      SftyMgt_nTarIdlStrt_MP =
         (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_nTarIdlStrtTqSys, 32000);
   }
   if (  (bLocalSftyMgt_bTqSysAcvTqSys != 0)
      && (NTARIDLCHK_bTqSysAcvTqSysPrev == 0))
   {
      u16LocalSftyMgt_nTarIdl = SftyMgt_nTarIdlStrt_MP;
   }
   else
   {
      u16LocalSftyMgt_nTarIdl = SftyMgt_nTarIdlTqSysDly_MP;
   }
   u32LocalSftyMgt_nTarIdl = (uint32)( SftyMgt_facIncMaxTarIdl_C
                                     + u16LocalSftyMgt_nTarIdl);
   u16LocalOutMin_1 = (uint16)MATHSRV_udtMIN(u32LocalSftyMgt_nTarIdl,
                                             u16LocalSftyMgt_nTarIdlSftyTqSys);
   SftyMgt_nTarIdlTqSysDly_MP = (uint16)MATHSRV_udtMIN(u16LocalOutMin_1, 32000);
   if (u8LocalExt_stGBxCf == SftyMgt_stGBxAT_C)
   {
      u16LocalOutSwitch = u16LocalSftyMgt_nTarIdlATTqSys;
   }
   else
   {
      u16LocalOutSwitch = 0;
   }
   u16LocalOutMax = (uint16)MATHSRV_udtMAX(u16LocalOutSwitch, u16LocalOutMin_1);
   u16LocalOutMin_2 = (uint16)MATHSRV_udtMIN(u16LocalOutMax,
                                             SftyMgt_nTarIdlMax_C);
   u32LocalSftyMgt_nTarIdlTqSysTol = (uint32)( u16LocalOutMin_2
                                             + SftyMgt_nOfsErrTarIdl_C);
   SftyMgt_nTarIdlTqSysTol_MP =
      (uint16)MATHSRV_udtMIN(u32LocalSftyMgt_nTarIdlTqSysTol, 32000);
   /*Turn_On_Delay_Simple1*/
   u16LocalSftyMgt_tiDlyNTarDftOn = (uint16)( ( SftyMgt_tiDlyNTarIdlDftOn_C + 6)
                                            / 4);
   u16LocalMinTdlyCounter =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tiDlyNTarDftOn,
                             NTARIDLCHK_u16CounterTMS1);
   if (u16LocalSftyMgt_nTarIdlUnChkBuf <= SftyMgt_nTarIdlTqSysTol_MP)
   {
      NTARIDLCHK_u16CounterTMS1 = 0;
   }
   else
   {
      NTARIDLCHK_u16CounterTMS1 = (uint16)(u16LocalMinTdlyCounter + 1);
   }
   if (NTARIDLCHK_u16CounterTMS1 >= u16LocalSftyMgt_tiDlyNTarDftOn)
   {
      NTARIDLCHK_bTurnOnDlyTMS1 = 1;
   }
   else
   {
      NTARIDLCHK_bTurnOnDlyTMS1 = 0;
   }

   VEMS_vidGET(SftyMgt_nTarIdlDynIdlSys, u16LocalSftyMgt_nTarIdlDynIdlSys);
   VEMS_vidGET(SftyMgt_nOfsIdlTakeOff, u16LocalSftyMgt_nOfsIdlTakeOff);
   VEMS_vidGET(SftyMgt_nEng, u16LocalSftyMgt_nEng);
   VEMS_vidGET(SftyMgt_bIniIdlCtlIdlSys, bLocalSftyMgt_bIniIdlCtlIdlSys);
   s32LocalSftyMgt_nTarIdlDynIdlSys =
   (sint32)( u16LocalSftyMgt_nTarIdlDynIdlSys
           - NTARIDLCHK_u16TarIdlDynIdSysPrev);
   u32LocalSftyMgt_nOfsNTarIdlDyn = (uint32)( SftyMgt_nOfsNTarIdlDyn_C
                                            + u16LocalSftyMgt_nTarIdlUnChkBuf
                                            + u16LocalSftyMgt_nOfsIdlTakeOff);
   u32LocalSftyMgt_nEng = (uint32)(4 * u16LocalSftyMgt_nEng);
   if (  (u16LocalSftyMgt_nTarIdlDynIdlSys > u32LocalSftyMgt_nOfsNTarIdlDyn)
      && (u32LocalSftyMgt_nEng > SftyMgt_nTarIdlDynThd_C)
      && (  (SftyMgt_bInhIniIdlDyn_C != 0)
         || (bLocalSftyMgt_bIniIdlCtlIdlSys == 0)))
   {
      SftyMgt_bAcvIdlDynMon_MP = 1;
   }
   else
   {
      SftyMgt_bAcvIdlDynMon_MP = 0;
   }
   if (  (SftyMgt_bAcvIdlDynMon_MP != 0)
      && (s32LocalSftyMgt_nTarIdlDynIdlSys > SftyMgt_nGrdNTarIdlDyn_C))
   {
      bLocalInTurnOnDly2 = 1;
   }
   else
   {
      bLocalInTurnOnDly2 = 0;
   }
   u16LocalSftyMgt_tiDlyNTarIdlDft = (uint16)( SftyMgt_tiDlyNTarIdlDynDft_C
                                             + 1);
   u16LocalMinTdlyCounter2 =
      (uint16)MATHSRV_udtMIN(NTARIDLCHK_u16CounterTMS2,
                             u16LocalSftyMgt_tiDlyNTarIdlDft);
   if (bLocalInTurnOnDly2 == 0)
   {
      NTARIDLCHK_u16CounterTMS2 = 0;
   }
   else
   {
      NTARIDLCHK_u16CounterTMS2 = (uint16)(u16LocalMinTdlyCounter2 + 1);
   }
   if (NTARIDLCHK_u16CounterTMS2 >= u16LocalSftyMgt_tiDlyNTarIdlDft)
   {
      NTARIDLCHK_bTurnOnDlyTMS2 = 1;
   }
   else
   {
      NTARIDLCHK_bTurnOnDlyTMS2 = 0;
   }
   if (  (NTARIDLCHK_bTurnOnDlyTMS1 != 0)
      || (NTARIDLCHK_bTurnOnDlyTMS2 != 0))
   {
      VEMS_vidSET(SftyMgt_bDgoNIdl, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoNIdl, 0);
   }
   NTARIDLCHK_bTqSysAcvTqSysPrev = bLocalSftyMgt_bTqSysAcvTqSys;
   NTARIDLCHK_u16TarIdlDynIdSysPrev =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_nTarIdlDynIdlSys, 32000);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/