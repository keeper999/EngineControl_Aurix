/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DFTMGT                                                  */
/* !Description     : DFTMGT Component.                                       */
/*                                                                            */
/* !Module          : DFTMGT                                                  */
/* !Description     : Safety TMS : INTERFACE DEFAUTS SFTYMGR.                 */
/*                                                                            */
/* !File            : DFTMGT_FCT1.C                                           */
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
/*   1 / DFTMGT_vidInitOutput                                                 */
/*   2 / DFTMGT_vidInterfaceDftSftyMgt                                        */
/*   3 / DFTMGT_vidIntrfDftSftyMgtDftECU                                      */
/*   4 / DFTMGT_vidIntrfDftSftyMgtPrmDft                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5402500 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2404 / 1.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/DFTMGT/DFTMGT_FCT1.C_v$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   19 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   19 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "DFTMGT.h"
#include "DFTMGT_L.h"
#include "DFTMGT_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTMGT_vidInitOutput                                       */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDftECU;                                           */
/*  output uint32 SftyMgt_prm_bDft;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTMGT_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDftECU, 0);
   VEMS_vidSET(SftyMgt_prm_bDft, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTMGT_vidInterfaceDftSftyMgt                              */
/* !Description :  Interface Defauts SafetyManager                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_10_01241_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DFTMGT_vidIntrfDftSftyMgtDftECU();                       */
/*  extf argret void DFTMGT_vidIntrfDftSftyMgtPrmDft();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTMGT_vidInterfaceDftSftyMgt(void)
{
   DFTMGT_vidIntrfDftSftyMgtDftECU();
   DFTMGT_vidIntrfDftSftyMgtPrmDft();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTMGT_vidIntrfDftSftyMgtDftECU                            */
/* !Description :  fonction de concaténation des défauts TMS pour safety      */
/*                 manager                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoTqDem;                                          */
/*  input boolean SftyMgt_bDgoCoCha;                                          */
/*  input boolean SftyMgt_bDgoTqSumLossCmp;                                   */
/*  input boolean SftyMgt_bDgoTqIdl;                                          */
/*  input boolean SftyMgt_bDgoTqCkEfcFil;                                     */
/*  input boolean SftyMgt_bDgoTqGBx;                                          */
/*  input boolean SftyMgt_bDgoDZone;                                          */
/*  input boolean SftyMgt_bDgoTakeOff;                                        */
/*  input boolean SftyMgt_bDgoSftyTqComp;                                     */
/*  input boolean SftyMgt_bDgoPresDsThr;                                      */
/*  input boolean SftyMgt_bInpChk;                                            */
/*  input boolean SftyMgt_bDgoLih;                                            */
/*  input boolean SftyMgt_bRcvMonRunLih;                                      */
/*  input boolean SftyMgt_bInhInpChk_C;                                       */
/*  output uint32 DFTMGT_u32SftyMgt_DftECU;                                   */
/*  output boolean SftyMgt_bDftECU;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTMGT_vidIntrfDftSftyMgtDftECU(void)
{
   boolean     bLocalSftyMgt_bDgoTqDem;
   boolean     bLocalSftyMgt_bDgoCoCha;
   boolean     bLocalSftyMgt_bDgoTqSumLossCmp;
   boolean     bLocalSftyMgt_bDgoSftyTqComp;
   boolean     bLocalSftyMgt_bDgoTqIdl;
   boolean     bLocalSftyMgt_bDgoTqCkEfcFil;
   boolean     bLocalSftyMgt_bDgoTqGBx;
   boolean     bLocalSftyMgt_bDgoDZone;
   boolean     bLocalSftyMgt_bDgoTakeOff;
   boolean     bLocalSftyMgtbInpChk;
   boolean     bLocalSftyMgt_bDgoLih;
   boolean     bLocalSftyMgt_bRcvMonRunLih;
   boolean     bLocalSftyMgt_bDgoPresDsThr;
   boolean     bLocalSftyMgt_bDftECU;
   boolean     bLlocalS1;
   boolean     bLlocalS2;
   uint32      u32LocalDFTMGT_SftyMgt_DftECU;


   VEMS_vidGET(SftyMgt_bDgoTqDem, bLocalSftyMgt_bDgoTqDem);
   VEMS_vidGET(SftyMgt_bDgoCoCha, bLocalSftyMgt_bDgoCoCha);
   VEMS_vidGET(SftyMgt_bDgoTqSumLossCmp, bLocalSftyMgt_bDgoTqSumLossCmp);
   VEMS_vidGET(SftyMgt_bDgoTqIdl, bLocalSftyMgt_bDgoTqIdl);
   VEMS_vidGET(SftyMgt_bDgoTqCkEfcFil, bLocalSftyMgt_bDgoTqCkEfcFil);
   VEMS_vidGET(SftyMgt_bDgoTqGBx, bLocalSftyMgt_bDgoTqGBx);
   VEMS_vidGET(SftyMgt_bDgoDZone, bLocalSftyMgt_bDgoDZone);
   VEMS_vidGET(SftyMgt_bDgoTakeOff, bLocalSftyMgt_bDgoTakeOff);
   VEMS_vidGET(SftyMgt_bDgoSftyTqComp, bLocalSftyMgt_bDgoSftyTqComp);
   VEMS_vidGET(SftyMgt_bDgoPresDsThr, bLocalSftyMgt_bDgoPresDsThr);
   VEMS_vidGET(SftyMgt_bInpChk, bLocalSftyMgtbInpChk);
   VEMS_vidGET(SftyMgt_bDgoLih, bLocalSftyMgt_bDgoLih);
   VEMS_vidGET(SftyMgt_bRcvMonRunLih, bLocalSftyMgt_bRcvMonRunLih);

   u32LocalDFTMGT_SftyMgt_DftECU = 0x00000000;
   if (bLocalSftyMgt_bDgoTqDem != 0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000010;
   }
   if (bLocalSftyMgt_bDgoCoCha != 0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000020;
   }
   if (bLocalSftyMgt_bDgoTqSumLossCmp != 0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000040;
   }
   if (bLocalSftyMgt_bDgoTqIdl != 0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000080;
   }
   if (bLocalSftyMgt_bDgoTqCkEfcFil !=0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000100;
   }
   if (bLocalSftyMgt_bDgoTqGBx !=0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000200;
   }
   if (bLocalSftyMgt_bDgoDZone !=0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000400;
   }
   if (bLocalSftyMgt_bDgoTakeOff !=0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00000800;
   }
   if (bLocalSftyMgt_bDgoSftyTqComp != 0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00001000;
   }
   if (bLocalSftyMgt_bDgoPresDsThr != 0)
   {
      u32LocalDFTMGT_SftyMgt_DftECU =
         u32LocalDFTMGT_SftyMgt_DftECU | 0x00002000;
   }
   DFTMGT_u32SftyMgt_DftECU = u32LocalDFTMGT_SftyMgt_DftECU;

   if (SftyMgt_bInhInpChk_C != 0)
   {
      bLlocalS1 = 0;
   }
   else
   {
      if (bLocalSftyMgtbInpChk != 0)
      {
         bLlocalS1 = 1;
      }
      else
      {
         bLlocalS1 = 0;
      }
   }
   if (bLocalSftyMgt_bRcvMonRunLih != 0)
   {
      if (bLocalSftyMgt_bDgoLih != 0)
      {
         bLlocalS2 = 1;
      }
      else
      {
         bLlocalS2 = 0;
      }
   }
   else
   {
      if(u32LocalDFTMGT_SftyMgt_DftECU != 0)
      {
         bLlocalS2 = 1;
      }
      else
      {
         bLlocalS2 = 0;
      }
   }
   if (  (bLlocalS1 != 0)
      || (bLlocalS2 != 0))
   {
      bLocalSftyMgt_bDftECU = 1;
   }
   else
   {
      bLocalSftyMgt_bDftECU = 0;
   }

   VEMS_vidSET(SftyMgt_bDftECU, bLocalSftyMgt_bDftECU);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTMGT_vidIntrfDftSftyMgtPrmDft                            */
/* !Description :  fonction de concaténation des défauts (25 bits)            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftAutChk;                                         */
/*  input boolean SftyMgt_bRcvMonRunLih;                                      */
/*  input boolean SftyMgt_bDgoLih;                                            */
/*  input boolean SftyMgt_bInpChk;                                            */
/*  input boolean SftyMgt_bDgoVSCtl;                                          */
/*  input boolean SftyMgt_bDftSTT;                                            */
/*  input boolean SftyMgt_bDftEM;                                             */
/*  input uint32 DFTMGT_u32SftyMgt_DftECU;                                    */
/*  output uint32 SftyMgt_prm_bDft;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTMGT_vidIntrfDftSftyMgtPrmDft(void)
{
   boolean     bLocalSftyMgt_bDftAutChk;
   boolean     bLocalSftyMgtbInpChk;
   boolean     bLocalSftyMgt_bDgoLih;
   boolean     bLocalSftyMgt_bRcvMonRunLih;
   boolean     bLocalSftyMgt_bDgoVSCtl;
   boolean     bLocalSftyMgt_bDftSTT;
   boolean     bLocalSftyMgt_bDftEM;
   uint32      u32LocalSftyMgt_prm_bDft;
   uint32      u32Local_9_bit;
   uint32      u32LocalSftyMgt_DftECU;


   VEMS_vidGET(SftyMgt_bDftAutChk,bLocalSftyMgt_bDftAutChk);
   VEMS_vidGET(SftyMgt_bRcvMonRunLih, bLocalSftyMgt_bRcvMonRunLih);
   VEMS_vidGET(SftyMgt_bDgoLih, bLocalSftyMgt_bDgoLih);
   VEMS_vidGET(SftyMgt_bInpChk, bLocalSftyMgtbInpChk);
   VEMS_vidGET(SftyMgt_bDgoVSCtl,bLocalSftyMgt_bDgoVSCtl);
   VEMS_vidGET(SftyMgt_bDftSTT,bLocalSftyMgt_bDftSTT);
   VEMS_vidGET(SftyMgt_bDftEM,bLocalSftyMgt_bDftEM);

   u32Local_9_bit = 0x00000000;
   u32LocalSftyMgt_prm_bDft = 0x00000000;

   if (bLocalSftyMgt_bRcvMonRunLih != 0)
   {
      u32LocalSftyMgt_prm_bDft =
         u32LocalSftyMgt_prm_bDft | 0x00000001;
   }
   if (bLocalSftyMgt_bDgoLih != 0)
   {
      u32LocalSftyMgt_prm_bDft =
         u32LocalSftyMgt_prm_bDft | 0x00000002;
   }
   if (bLocalSftyMgtbInpChk != 0)
   {
      u32LocalSftyMgt_prm_bDft =
         u32LocalSftyMgt_prm_bDft | 0x00000004;
   }

   u32LocalSftyMgt_DftECU = DFTMGT_u32SftyMgt_DftECU & 0x00003FF0;
   u32LocalSftyMgt_prm_bDft =
         u32LocalSftyMgt_prm_bDft | u32LocalSftyMgt_DftECU;

   if (bLocalSftyMgt_bDftAutChk !=0)
   {
      u32Local_9_bit = u32Local_9_bit | 0x00004000;
   }

   u32LocalSftyMgt_prm_bDft = u32LocalSftyMgt_prm_bDft | u32Local_9_bit;

   if (bLocalSftyMgt_bDgoVSCtl != 0)
   {
      u32LocalSftyMgt_prm_bDft = u32LocalSftyMgt_prm_bDft | 0x00400000;
   }
   if (bLocalSftyMgt_bDftSTT != 0)
   {
      u32LocalSftyMgt_prm_bDft = u32LocalSftyMgt_prm_bDft | 0x00800000;
   }
   if (bLocalSftyMgt_bDftEM != 0)
   {
      u32LocalSftyMgt_prm_bDft = u32LocalSftyMgt_prm_bDft | 0x01000000;
   }
   VEMS_vidSET(SftyMgt_prm_bDft,u32LocalSftyMgt_prm_bDft);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------ end of file ---------------------------------*/