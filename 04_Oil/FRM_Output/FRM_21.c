/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* !Component       : GAR                                                     */
/* !Description     : Matrice GAR                                             */
/* !Module          : GDGAR                                                   */
/* !Vendor          : Valeo VEMS                                              */
/* !Reference       : PTS_DOC_5018281 / 15                                    */
/* !Release: 1                                                                */
/* !Integrity : Full                                                          */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/TOOL_CONFIG/GAR_TblDft.csv $*/
/* $Revision::   1.0   $$Author::   fsanch$$Date::   04 Mar 2014 11:19:38    $*/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

/* Code generate with GeneFRM  Vers 3.3  */

#include "FRM_21.h"
#include "FRM.h"
#include "GDFRMDef.h"

#define IS_SNG_DFT_ACTIVE(x) (0 != ((x) & FRM_u8SNG_DFT_TRUE))
#define IS_OBD_DFT_ACTIVE(x) (0 != ((x) & FRM_u8OBD_DFT_TRUE))

void FRM_vidF02_FidMng_F01_FRM_RawDft_AaStart_Bidon(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_AASTART_BIDON]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_AASTART_BIDON] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_AASTART_BIDON] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__iBattMaxCkg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__IBATTMAXCKG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__IBATTMAXCKG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__IBATTMAXCKG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__iBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__IBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__IBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__IBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__rBattSoC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__RBATTSOC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__RBATTSOC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__RBATTSOC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__resBattIt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__RESBATTIT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__RESBATTIT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__RESBATTIT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__tBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__TBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__TBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__TBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__UBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattMinCkg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__UBATTMINCKG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTMINCKG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTMINCKG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattOc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__UBATTOC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTOC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTOC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattRstrt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__UBATTRSTRT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTRSTRT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTRSTRT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattStrt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT__UBATTSTRT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTSTRT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD__UBATTSTRT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AbsEspMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ABSESPMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ABSESPMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ABSESPMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AccelCoh_BrkPed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ACCELCOH_BRKPED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ACCELCOH_BRKPED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ACCELCOH_BRKPED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AccelCoh_BrkPedBVH2p(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ACCELCOH_BRKPEDBVH2P]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ACCELCOH_BRKPEDBVH2P] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ACCELCOH_BRKPEDBVH2P] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AccP_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ACCP_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ACCP_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ACCP_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffEGRVlvLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPAREFFEGRVLVLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFEGRVLVLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFEGRVLVLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs1Lim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPAREFFTHROFS1LIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFS1LIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFS1LIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs2Lim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPAREFFTHROFS2LIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFS2LIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFS2LIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs3Lim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPAREFFTHROFS3LIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFS3LIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFS3LIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfsLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPAREFFTHROFSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPAREFFTHROFSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpClsExOfsLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPCLSEXOFSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPCLSEXOFSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPCLSEXOFSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpInjOfsLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPINJOFSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPINJOFSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPINJOFSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpIvsInjConLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPIVSINJCONLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPIVSINJCONLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPIVSINJCONLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpOpInOfsLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPOPINOFSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPOPINOFSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPOPINOFSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpSlopInjConLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ADPSLOPINJCONLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPSLOPINJCONLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ADPSLOPINJCONLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AirPrssExtSdwn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_AIRPRSSEXTSDWN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_AIRPRSSEXTSDWN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_AIRPRSSEXTSDWN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AirPrssExtSup(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_AIRPRSSEXTSUP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_AIRPRSSEXTSUP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_AIRPRSSEXTSUP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Algo_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ALGO_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ALGO_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ALGO_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Algo_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ALGO_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ALGO_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ALGO_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AltAbsentEcu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ALTABSENTECU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ALTABSENTECU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ALTABSENTECU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AntiBoil(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ANTIBOIL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ANTIBOIL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ANTIBOIL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ArDeltaCorLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ARDELTACORLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ARDELTACORLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ARDELTACORLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_AsicGdiFailure(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ASICGDIFAILURE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ASICGDIFAILURE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ASICGDIFAILURE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Block_Strtr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BLOCK_STRTR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BLOCK_STRTR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BLOCK_STRTR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Blt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BLT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BLT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BLT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost1_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BOOST1_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST1_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST1_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost2_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BOOST2_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST2_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST2_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost3_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BOOST3_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST3_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST3_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost4_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BOOST4_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST4_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BOOST4_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_BsiMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BSIMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BSIMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BSIMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_BusOff(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BUSOFF]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BUSOFF] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BUSOFF] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_BvaMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_BVAMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BVAMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_BVAMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CAVMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CAVMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CAVMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CAVMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_iBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CHKBATTSYS_IBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CHKBATTSYS_IBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CHKBATTSYS_IBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_tBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CHKBATTSYS_TBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CHKBATTSYS_TBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CHKBATTSYS_TBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_uBattClc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CHKBATTSYS_UBATTCLC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CHKBATTSYS_UBATTCLC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CHKBATTSYS_UBATTCLC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CksRom_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CKSROM_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CKSROM_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CKSROM_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Clk_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLK_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLK_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLK_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Clk_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLK_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLK_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLK_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ClnErrVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLNERRVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLNERRVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLNERRVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ClnErrVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLNERRVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLNERRVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLNERRVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ClsdRly_StFanC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLSDRLY_STFANC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLSDRLY_STFANC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLSDRLY_STFANC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ClsIdlCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLSIDLCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLSIDLCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLSIDLCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CluDmgAfts(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CLUDMGAFTS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLUDMGAFTS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CLUDMGAFTS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdCVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CMDCVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDCVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDCVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdCVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CMDCVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDCVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDCVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdHVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CMDHVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDHVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDHVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdHVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CMDHVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDHVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CMDHVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_bModSptReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_BMODSPTREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_BMODSPTREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_BMODSPTREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_CluSt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_CLUST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_CLUST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_CLUST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_EepPwrl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_EEPPWRL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_EEPPWRL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_EEPPWRL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_EepReinit(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_EEPREINIT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_EEPREINIT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_EEPREINIT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_ExCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_EXCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_EXCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_EXCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_HPSens(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_HPSENS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_HPSENS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_HPSENS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_InCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_INCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_INCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_INCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_pBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_PBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_PBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_PBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_Ped(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_PED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_PED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_PED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_PFuAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_PFUACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_PFUACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_PFUACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_rAccP(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_RACCP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_RACCP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_RACCP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_spdVeh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_SPDVEH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_SPDVEH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_SPDVEH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_stCluAC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STCLUAC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STCLUAC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STCLUAC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STFANB1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2HiSpd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STFANB2HISPD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB2HISPD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB2HISPD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2LoSpd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STFANB2LOSPD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB2LOSPD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB2LOSPD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2NoSpd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STFANB2NOSPD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB2NOSPD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STFANB2NOSPD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_stPwrAC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STPWRAC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STPWRAC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STPWRAC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StrtLock(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_STRTLOCK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STRTLOCK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_STRTLOCK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_tiEngStop(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COH_TIENGSTOP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_TIENGSTOP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COH_TIENGSTOP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CohAccPSwt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COHACCPSWT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHACCPSWT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHACCPSWT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit2_stDftOBD(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COHBIT2_STDFTOBD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT2_STDFTOBD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT2_STDFTOBD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit3_stDftOBD(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COHBIT3_STDFTOBD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT3_STDFTOBD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT3_STDFTOBD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit4_stDftOBD(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COHBIT4_STDFTOBD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT4_STDFTOBD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT4_STDFTOBD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit7_stDftOBD(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COHBIT7_STDFTOBD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT7_STDFTOBD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHBIT7_STDFTOBD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CohPosnSnsr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COHPOSNSNSR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHPOSNSNSR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COHPOSNSNSR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ComAlt_AltCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COMALT_ALTCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMALT_ALTCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMALT_ALTCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ComSpi_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COMSPI_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMSPI_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMSPI_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ComSpi_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COMSPI_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMSPI_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMSPI_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ComTout_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COMTOUT_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMTOUT_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMTOUT_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ComTout_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COMTOUT_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMTOUT_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COMTOUT_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CorLoss(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CORLOSS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CORLOSS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CORLOSS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CorSpCur(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CORSPCUR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CORSPCUR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CORSPCUR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CoSysDfct(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_COSYSDFCT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COSYSDFCT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_COSYSDFCT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Cpt_ThrCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CPT_THRCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CPT_THRCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CPT_THRCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CritSc_StFanC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CRITSC_STFANC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CRITSC_STFANC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CRITSC_STFANC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CrkCoh_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CRKCOH_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CRKCOH_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CRKCOH_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CrsCtlDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CRSCTLDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CRSCTLDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CRSCTLDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_CutReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_CUTREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CUTREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_CUTREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DecelCoh_BrkPed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DECELCOH_BRKPED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DECELCOH_BRKPED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DECELCOH_BRKPED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DecelCoh_BrkPedBVH2p(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DECELCOH_BRKPEDBVH2P]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DECELCOH_BRKPEDBVH2P] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DECELCOH_BRKPEDBVH2P] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DegMod_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DEGMOD_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DEGMOD_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DEGMOD_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Dft_Info_Crash(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFT_INFO_CRASH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFT_INFO_CRASH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFT_INFO_CRASH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftCVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTCVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTCVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTCVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftCVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTCVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTCVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTCVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftEeprom(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTEEPROM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTEEPROM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTEEPROM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFu_Afl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTFU_AFL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFU_AFL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFU_AFL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFu_Afr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTFU_AFR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFU_AFR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFU_AFR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFuGas_Afl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTFUGAS_AFL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFUGAS_AFL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFUGAS_AFL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFuGas_Afr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTFUGAS_AFR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFUGAS_AFR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTFUGAS_AFR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftHVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTHVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTHVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTHVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftHVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTHVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTHVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTHVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftObjEep(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTOBJEEP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTOBJEEP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTOBJEEP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftOnOffHi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTONOFFHI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTONOFFHI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTONOFFHI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftOnOffLo(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTONOFFLO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTONOFFLO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTONOFFLO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftOscCfm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTOSCCFM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTOSCCFM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTOSCCFM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegHi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTREGHI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGHI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGHI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegHiCfm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTREGHICFM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGHICFM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGHICFM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegLo(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTREGLO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGLO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGLO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegLoCfm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTREGLOCFM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGLOCFM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTREGLOCFM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2_Afl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTSENO2_AFL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2_AFL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2_AFL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2_Afr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTSENO2_AFR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2_AFR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2_AFR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2Gas_Afl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTSENO2GAS_AFL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2GAS_AFL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2GAS_AFL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2Gas_Afr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTSENO2GAS_AFR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2GAS_AFR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENO2GAS_AFR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenr_AccP(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTSENR_ACCP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENR_ACCP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENR_ACCP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenr_Thr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DFTSENR_THR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENR_THR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DFTSENR_THR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg1VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFNEG1VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG1VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG1VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg1VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFNEG1VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG1VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG1VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg2VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFNEG2VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG2VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG2VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg2VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFNEG2VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG2VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFNEG2VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos1VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFPOS1VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS1VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS1VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos1VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFPOS1VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS1VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS1VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos2VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFPOS2VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS2VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS2VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos2VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIFPOS2VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS2VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIFPOS2VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DiraMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DIRAMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIRAMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DIRAMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DistSig(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DISTSIG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DISTSIG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DISTSIG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DmtrMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DMTRMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DMTRMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DMTRMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_DrvTra(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_DRVTRA]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DRVTRA] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_DRVTRA] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ECI_StFanC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ECI_STFANC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ECI_STFANC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ECI_STFANC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EcmMute(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ECMMUTE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ECMMUTE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ECMMUTE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_El_StFanC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_EL_STFANC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_EL_STFANC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_EL_STFANC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElChkConsDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCHKCONSDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCHKCONSDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCHKCONSDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsCohVSMaxp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSCOHVSMAXP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSCOHVSMAXP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSCOHVSMAXP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSDEFDFTVSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSDEFDFTVSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSDEFDFTVSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSMaxp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSDEFDFTVSMAXP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSDEFDFTVSMAXP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSDEFDFTVSMAXP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSReg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSDEFDFTVSREG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSDEFDFTVSREG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSDEFDFTVSREG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsInitDftVSReg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSINITDFTVSREG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSINITDFTVSREG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSINITDFTVSREG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsVarDftVSLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSVARDFTVSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSVARDFTVSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSVARDFTVSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsVarDftVSReg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCONSVARDFTVSREG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSVARDFTVSREG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCONSVARDFTVSREG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElCptTraBsiDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELCPTTRABSIDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCPTTRABSIDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELCPTTRABSIDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElDftCrsCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELDFTCRSCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELDFTCRSCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELDFTCRSCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElDiagInhPin0_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELDIAGINHPIN0_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELDIAGINHPIN0_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELDIAGINHPIN0_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElDiagInhPin1_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELDIAGINHPIN1_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELDIAGINHPIN1_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELDIAGINHPIN1_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElecAlt_AltCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELECALT_ALTCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELECALT_ALTCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELECALT_ALTCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElFrameCntIncDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELFRAMECNTINCDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELFRAMECNTINCDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELFRAMECNTINCDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ElInfBsiDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ELINFBSIDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELINFBSIDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ELINFBSIDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopOldVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENDSTOPOLDVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPOLDVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPOLDVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopOldVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENDSTOPOLDVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPOLDVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPOLDVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopReq1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENDSTOPREQ1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPREQ1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPREQ1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopReq2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENDSTOPREQ2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPREQ2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENDSTOPREQ2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EngOilOverHeat(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENGOILOVERHEAT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGOILOVERHEAT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGOILOVERHEAT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohCk(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENGSPDCOHCK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGSPDCOHCK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGSPDCOHCK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohExCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENGSPDCOHEXCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGSPDCOHEXCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGSPDCOHEXCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohInCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ENGSPDCOHINCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGSPDCOHINCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ENGSPDCOHINCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Etat_Alt1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ETAT_ALT1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ETAT_ALT1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ETAT_ALT1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Etat_Alt2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ETAT_ALT2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ETAT_ALT2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ETAT_ALT2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_EvenFrameCntDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_EVENFRAMECNTDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_EVENFRAMECNTDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_EVENFRAMECNTDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ExtLeak_FuSys(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_EXTLEAK_FUSYS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_EXTLEAK_FUSYS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_EXTLEAK_FUSYS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F305Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F305COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F305Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F305LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F305Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F305LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F305P537Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F305P537INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305P537INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305P537INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F305P538Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F305P538INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305P538INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F305P538INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F30DLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F30DLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP263Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F30DP263INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP263INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP263INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP264Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F30DP264INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP264INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP264INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP265Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F30DP265INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP265INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP265INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP266Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F30DP266INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP266INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F30DP266INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F329Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F329COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F329Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F329LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F329Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F329LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F329P445Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F329P445INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329P445INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329P445INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F329ProcFailed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F329PROCFAILED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329PROCFAILED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F329PROCFAILED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349P007Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349P007INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349P007INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349P007INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349P055Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349P055INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349P055INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349P055INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349P440Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349P440INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349P440INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349P440INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F349ProcFailed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F349PROCFAILED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349PROCFAILED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F349PROCFAILED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DCoh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F34DCOH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DCOH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DCOH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F34DLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F34DLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DPM1413Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F34DPM1413INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DPM1413INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DPM1413INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DProcFailed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F34DPROCFAILED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DPROCFAILED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F34DPROCFAILED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DCoh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F38DCOH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DCOH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DCOH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F38DLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F38DLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DP010Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F38DP010INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DP010INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DP010INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DP052Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F38DP052INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DP052INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DP052INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DProcFailed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F38DPROCFAILED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DPROCFAILED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F38DPROCFAILED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADCoh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3ADCOH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3ADCOH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3ADCOH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3ADLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3ADLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3ADLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3ADLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3ADLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3ADLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P291Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9P291INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P291INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P291INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P363Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9P363INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P363INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P363INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P364Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9P364INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P364INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P364INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P482Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9P482INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P482INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P482INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P483Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9P483INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P483INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9P483INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9ProcFailed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3C9PROCFAILED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9PROCFAILED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3C9PROCFAILED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDCoh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3CDCOH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDCOH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDCOH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3CDLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3CDLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP225Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3CDP225INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDP225INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDP225INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP319Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3CDP319INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDP319INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDP319INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP515Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F3CDP515INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDP515INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F3CDP515INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F412Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F412LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F412LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F412LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F412Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F412LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F412LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F412LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F412P040Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F412P040INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F412P040INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F412P040INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F432COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F432INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F432LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F432LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F432LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DCoh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DCOH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DCOH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DCOH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DFP0535Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DFP0535INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DFP0535INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DFP0535INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP330Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DP330INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DP330INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DP330INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP331Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DP331INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DP331INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DP331INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP354Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F44DP354INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DP354INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F44DP354INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F489Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F489COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F489Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F489LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F489Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F489LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F489P102Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F489P102INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489P102INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489P102INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F489P218Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F489P218INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489P218INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489P218INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F489P254Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F489P254INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489P254INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F489P254INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F492Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F492LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F492LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F492LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F492Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F492LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F492LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F492LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F495Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F495LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F495LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F495LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F495Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F495LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F495LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F495LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4B2Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4B2LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4B2LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4B2LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4B2Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4B2LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4B2LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4B2LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4D2Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4D2LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4D2LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4D2LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4D2Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4D2LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4D2LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4D2LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P429Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P429INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P429INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P429INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P434Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P434INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P434INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P434INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P437Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P437INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P437INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P437INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P438Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P438INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P438INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P438INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P490Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P490INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P490INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P490INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P491Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P491INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P491INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P491INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P492Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F4F2P492INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P492INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F4F2P492INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50DLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50DLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50DLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50DLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50DLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50DLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50DLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50DLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50ECOH1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ECOH1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ECOH1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50ECOH2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ECOH2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ECOH2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50ECOH3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ECOH3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ECOH3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ELength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50ELENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ELENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ELENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ELost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50ELOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ELOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50ELOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50EP046Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50EP046INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50EP046INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50EP046INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50EP210Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50EP210INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50EP210INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50EP210INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F50EPM1386Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F50EPM1386INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50EPM1386INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F50EPM1386INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F532Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F532COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F532Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F532LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F532Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F532LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1414Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F532PM1414INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532PM1414INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532PM1414INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1415Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F532PM1415INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532PM1415INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532PM1415INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1416Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F532PM1416INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532PM1416INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F532PM1416INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP015Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552BISP015INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552BISP015INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552BISP015INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP325Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552BISP325INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552BISP325INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552BISP325INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP326Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552BISP326INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552BISP326INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552BISP326INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552P255Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552P255INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552P255INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552P255INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552P256Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552P256INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552P256INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552P256INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F552P257Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F552P257INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552P257INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F552P257INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F572Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F572COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F572Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F572LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F572Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F572LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F572PM1360Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F572PM1360INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572PM1360INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F572PM1360INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CCoh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F57CCOH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CCOH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CCOH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CLength(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F57CLENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CLENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CLENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CLost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F57CLOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CLOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CLOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CPM1418Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F57CPM1418INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CPM1418INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F57CPM1418INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P272Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P272INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P272INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P272INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P273Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P273INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P273INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P273INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P349Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P349INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P349INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P349INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P418Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P418INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P418INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P418INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P419Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P419INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P419INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P419INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P420Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P420INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P420INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P420INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P421Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F592P421INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P421INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F592P421INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F5B2COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F5B2LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F5B2LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2P146Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F5B2P146INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2P146INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F5B2P146INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F612Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F612COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F612Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F612LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F612Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F612LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F612P260Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F612P260INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612P260INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612P260INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F612P436Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F612P436INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612P436INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612P436INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F612P705Invld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F612P705INVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612P705INVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F612P705INVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Coh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F7F2COH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2COH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2COH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Length(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F7F2LENGTH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2LENGTH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2LENGTH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Lost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F7F2LOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2LOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2LOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2P015bisInvld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F7F2P015BISINVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2P015BISINVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2P015BISINVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2P146bisInvld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_F7F2P146BISINVLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2P146BISINVLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_F7F2P146BISINVLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_FctCluP(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_FCTCLUP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FCTCLUP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FCTCLUP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_FlashChk(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_FLASHCHK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FLASHCHK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FLASHCHK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_FldCoh_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_FLDCOH_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FLDCOH_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FLDCOH_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Frq_PropFuPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_FRQ_PROPFUPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FRQ_PROPFUPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FRQ_PROPFUPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_FSFBlockCls(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_FSFBLOCKCLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FSFBLOCKCLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FSFBLOCKCLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_FSFBlockOp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_FSFBLOCKOP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FSFBLOCKOP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_FSFBLOCKOP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_GravScp_PropFuPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRAVSCP_PROPFUPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRAVSCP_PROPFUPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRAVSCP_PROPFUPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_OilLvlAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_OILLVLACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_OILLVLACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_OILLVLACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pACMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_PACMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PACMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PACMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pAirExt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_PAIREXT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PAIREXT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PAIREXT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pAirExtOld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_PAIREXTOLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PAIREXTOLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PAIREXTOLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_PBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pRelBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_PRELBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PRELBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_PRELBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_rCluPedPrssMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_RCLUPEDPRSSMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_RCLUPEDPRSSMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_RCLUPEDPRSSMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_tCoMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_GRD_TCOMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_TCOMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_GRD_TCOMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HHit_NoiseAdp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HHIT_NOISEADP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HHIT_NOISEADP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HHIT_NOISEADP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_aEng(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_AENG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_AENG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_AENG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DmpVlvCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_DMPVLVCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DMPVLVCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DMPVLVCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrFan1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_DRVRFAN1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRFAN1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRFAN1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrFan2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_DRVRFAN2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRFAN2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRFAN2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrSenO2Ds(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_DRVRSENO2DS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRSENO2DS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRSENO2DS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrSenO2Us(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_DRVRSENO2US]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRSENO2US] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_DRVRSENO2US] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_nEng(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_NENG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_NENG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_NENG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_pACMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_PACMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_PACMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_PACMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_uBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_UBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_UBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_UBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_WgcCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HI_WGCCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_WGCCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HI_WGCCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HiCstrDrv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HICSTRDRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HICSTRDRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HICSTRDRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HiTAlt_AltCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HITALT_ALTCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HITALT_ALTCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HITALT_ALTCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HiToothCoh_CkSts(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HITOOTHCOH_CKSTS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HITOOTHCOH_CKSTS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HITOOTHCOH_CKSTS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HiVlvActExDrv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HIVLVACTEXDRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HIVLVACTEXDRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HIVLVACTEXDRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HiVlvActInDrv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HIVLVACTINDRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HIVLVACTINDRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HIVLVACTINDRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_HSld_NoiseAdp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_HSLD_NOISEADP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HSLD_NOISEADP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_HSLD_NOISEADP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IdcBlbyCnd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IDCBLBYCND]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IDCBLBYCND] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IDCBLBYCND] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IMaxVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IMAXVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IMAXVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IMAXVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IMaxVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IMAXVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IMAXVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IMAXVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ImmoCodNotRead(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IMMOCODNOTREAD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IMMOCODNOTREAD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IMMOCODNOTREAD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_InhChkInitSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INHCHKINITSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INHCHKINITSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INHCHKINITSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_InhEngStopSTT(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INHENGSTOPSTT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INHENGSTOPSTT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INHENGSTOPSTT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_InhThr_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INHTHR_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INHTHR_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INHTHR_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Inv_CalId(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INV_CALID]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INV_CALID] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INV_CALID] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Inv_VarCod(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INV_VARCOD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INV_VARCOD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INV_VARCOD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_InvCoh_BrkPed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INVCOH_BRKPED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INVCOH_BRKPED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INVCOH_BRKPED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Invld_uDftStaCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_INVLD_UDFTSTACMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INVLD_UDFTSTACMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_INVLD_UDFTSTACMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvECU(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IRVECU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVECU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVECU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvEM(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IRVEM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVEM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVEM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvSTT(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IRVSTT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVSTT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVSTT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvVSCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IRVVSCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVVSCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IRVVSCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IUPRSYNT1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IUPRSYNT1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IUPRSYNT1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IUPRSYNT2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IUPRSYNT2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IUPRSYNT2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_IUPRSYNT3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IUPRSYNT3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_IUPRSYNT3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LgEngRStrtInh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LGENGRSTRTINH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LGENGRSTRTINH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LGENGRSTRTINH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LHit_NoiseAdp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LHIT_NOISEADP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LHIT_NOISEADP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LHIT_NOISEADP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LihReq1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LIHREQ1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LIHREQ1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LIHREQ1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LihReq2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LIHREQ2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LIHREQ2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LIHREQ2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LinBlockedBus(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LINBLOCKEDBUS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LINBLOCKEDBUS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LINBLOCKEDBUS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DmpVlvCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_DMPVLVCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DMPVLVCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DMPVLVCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrFan1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_DRVRFAN1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRFAN1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRFAN1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrFan2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_DRVRFAN2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRFAN2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRFAN2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrSenO2Ds(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_DRVRSENO2DS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRSENO2DS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRSENO2DS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrSenO2Us(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_DRVRSENO2US]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRSENO2US] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_DRVRSENO2US] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_pACMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_PACMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_PACMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_PACMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_uBattMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_UBATTMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_UBATTMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_UBATTMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_uBattSpc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_UBATTSPC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_UBATTSPC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_UBATTSPC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_WgcCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LO_WGCCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_WGCCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LO_WGCCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LoCstrDrv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LOCSTRDRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOCSTRDRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOCSTRDRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LoFuLvl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LOFULVL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOFULVL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOFULVL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LostMisfRoughnsRoad(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LOSTMISFROUGHNSROAD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOSTMISFROUGHNSROAD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOSTMISFROUGHNSROAD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LoVlvActExDrv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LOVLVACTEXDRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOVLVACTEXDRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOVLVACTEXDRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LoVlvActInDrv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LOVLVACTINDRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOVLVACTINDRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LOVLVACTINDRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnEndStopVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LRNENDSTOPVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNENDSTOPVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNENDSTOPVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnEndStopVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LRNENDSTOPVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNENDSTOPVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNENDSTOPVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnFaiLimVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LRNFAILIMVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNFAILIMVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNFAILIMVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnFaiLimVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LRNFAILIMVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNFAILIMVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LRNFAILIMVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_LSld_NoiseAdp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_LSLD_NOISEADP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LSLD_NOISEADP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_LSLD_NOISEADP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_MainWkuDisrd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MAINWKUDISRD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAINWKUDISRD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAINWKUDISRD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_MainWkuIncst(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MAINWKUINCST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAINWKUINCST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAINWKUINCST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Map_PropFuPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MAP_PROPFUPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAP_PROPFUPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAP_PROPFUPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Max_pAirExt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MAX_PAIREXT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAX_PAIREXT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAX_PAIREXT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_MaxAbs_pUsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MAXABS_PUSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAXABS_PUSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MAXABS_PUSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_McpFlashCks_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MCPFLASHCKS_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCPFLASHCKS_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCPFLASHCKS_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_McpRAMTest_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MCPRAMTEST_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCPRAMTEST_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCPRAMTEST_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_McwCksCalc_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MCWCKSCALC_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCWCKSCALC_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCWCKSCALC_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_McwFctTest_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MCWFCTTEST_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCWFCTTEST_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCWFCTTEST_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_McwInitSftyRslt_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MCWINITSFTYRSLT_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCWINITSFTYRSLT_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MCWINITSFTYRSLT_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_MecaAlt_AltCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MECAALT_ALTCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MECAALT_ALTCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MECAALT_ALTCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Min_pAirExt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MIN_PAIREXT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MIN_PAIREXT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MIN_PAIREXT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_MissToothVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MISSTOOTHVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MISSTOOTHVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MISSTOOTHVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_MissToothVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_MISSTOOTHVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MISSTOOTHVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_MISSTOOTHVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif_pUsThrSen(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NEGDIF_PUSTHRSEN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGDIF_PUSTHRSEN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGDIF_PUSTHRSEN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif1_pUsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NEGDIF1_PUSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGDIF1_PUSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGDIF1_PUSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif2_pUsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NEGDIF2_PUSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGDIF2_PUSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGDIF2_PUSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NegOfs_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NEGOFS_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGOFS_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NEGOFS_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NoAnswCtlUnit(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NOANSWCTLUNIT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOANSWCTLUNIT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOANSWCTLUNIT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NoGap_CkSts(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NOGAP_CKSTS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOGAP_CKSTS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOGAP_CKSTS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigCk(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NOSIGCK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOSIGCK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOSIGCK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigExCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NOSIGEXCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOSIGEXCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOSIGEXCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigInCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_NOSIGINCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOSIGINCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_NOSIGINCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ObsAdp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OBSADP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OBSADP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OBSADP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_bInhCrkAltHw(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_BINHCRKALTHW]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_BINHCRKALTHW] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_BINHCRKALTHW] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_BlowBy1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_BLOWBY1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_BLOWBY1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_BLOWBY1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_BlowBy2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_BLOWBY2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_BLOWBY2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_BLOWBY2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CtlPmpReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_CTLPMPREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_CTLPMPREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_CTLPMPREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CTP1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_CTP1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_CTP1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_CTP1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CTP2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_CTP2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_CTP2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_CTP2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Dml(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_DML]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_DML] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_DML] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_DrvrFan1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_DRVRFAN1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_DRVRFAN1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_DRVRFAN1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_DrvrFan2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_DRVRFAN2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_DRVRFAN2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_DRVRFAN2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_ECTReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_ECTREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_ECTREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_ECTREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_EngStOutIdc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_ENGSTOUTIDC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_ENGSTOUTIDC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_ENGSTOUTIDC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_FuGauge(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_FUGAUGE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_FUGAUGE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_FUGAUGE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_HPPmpActCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_HPPMPACTCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_HPPMPACTCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_HPPMPACTCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil1Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_IGCOIL1CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL1CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL1CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil2Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_IGCOIL2CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL2CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL2CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil3Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_IGCOIL3CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL3CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL3CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil4Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_IGCOIL4CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL4CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_IGCOIL4CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj1Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_INJ1CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ1CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ1CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj2Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_INJ2CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ2CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ2CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj3Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_INJ3CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ3CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ3CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj4Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_INJ4CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ4CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_INJ4CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_PropFuPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_PROPFUPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_PROPFUPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_PROPFUPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_PwrRly(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_PWRRLY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_PWRRLY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_PWRRLY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_tCoMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_TCOMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_TCOMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_TCOMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_TrbWaPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_TRBWAPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_TRBWAPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_TRBWAPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_uDsLs(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_UDSLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_UDSLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_UDSLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_uUpLs(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OC_UUPLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_UUPLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OC_UUPLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_OilPrssSdwnORng(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OILPRSSSDWNORNG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OILPRSSSDWNORNG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OILPRSSSDWNORNG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_OilPrssSupORng(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OILPRSSSUPORNG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OILPRSSSUPORNG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OILPRSSSUPORNG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_OldLrnVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OLDLRNVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OLDLRNVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OLDLRNVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_OldLrnVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OLDLRNVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OLDLRNVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OLDLRNVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_bNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_BNEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_BNEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_BNEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_Cat(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_CAT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_CAT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_CAT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_CatApv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_CATAPV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_CATAPV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_CATAPV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsHeat(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_DSHEAT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_DSHEAT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_DSHEAT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsPlausFco(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_DSPLAUSFCO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_DSPLAUSFCO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_DSPLAUSFCO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsPlausFld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_DSPLAUSFLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_DSPLAUSFLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_DSPLAUSFLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_FuGauge(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_FUGAUGE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_FUGAUGE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_FUGAUGE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_FuGaugeLvl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_FUGAUGELVL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_FUGAUGELVL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_FUGAUGELVL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_KnkDiag(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_KNKDIAG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_KNKDIAG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_KNKDIAG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_LongWinLrn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_LONGWINLRN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_LONGWINLRN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_LONGWINLRN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_LongWinLrnMax(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_LONGWINLRNMAX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_LONGWINLRNMAX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_LONGWINLRNMAX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_OxyApvPerd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_OXYAPVPERD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_OXYAPVPERD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_OXYAPVPERD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_OxySensPerd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_OXYSENSPERD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_OXYSENSPERD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_OXYSENSPERD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblIrvLdLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_RBLIRVLDLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RBLIRVLDLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RBLIRVLDLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblTmpLdLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_RBLTMPLDLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RBLTMPLDLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RBLTMPLDLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblVlvPosn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_RBLVLVPOSN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RBLVLVPOSN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RBLVLVPOSN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_rCluPedPrssMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_RCLUPEDPRSSMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RCLUPEDPRSSMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_RCLUPEDPRSSMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_ShrtWinLrn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_SHRTWINLRN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SHRTWINLRN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SHRTWINLRN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_ShrtWinLrnMax(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_SHRTWINLRNMAX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SHRTWINLRNMAX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SHRTWINLRNMAX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_SigGrdDiag(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_SIGGRDDIAG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SIGGRDDIAG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SIGGRDDIAG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_spdVeh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_SPDVEH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SPDVEH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_SPDVEH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_tiEngStop(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_TIENGSTOP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_TIENGSTOP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_TIENGSTOP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsHeat(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_USHEAT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_USHEAT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_USHEAT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsPlausFco(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_USPLAUSFCO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_USPLAUSFCO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_USPLAUSFCO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsPlausFld(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_USPLAUSFLD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_USPLAUSFLD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_USPLAUSFLD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes1_Sfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES1_SFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES1_SFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES1_SFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes2_Sfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES2_SFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES2_SFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES2_SFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes3_Sfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES3_SFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES3_SFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES3_SFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes4_Sfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNG_VMES4_SFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES4_SFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNG_VMES4_SFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCutOffReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGCUTOFFREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGCUTOFFREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGCUTOFFREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGCVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGCVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGCVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGCVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGCVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGCVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTC1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTC2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTC3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTC4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTC4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCAll(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTCALL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCALL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCALL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTCGAZ1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTCGAZ2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTCGAZ3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTCGAZ4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZ4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGazAll(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATDTCGAZALL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZALL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATDTCGAZALL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMD1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMD2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMD3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMD4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMD4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDAll(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMDALL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDALL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDALL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMDGAZ1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMDGAZ2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMDGAZ3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMDGAZ4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZ4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGazAll(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGDMGCATMDGAZALL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZALL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGDMGCATMDGAZALL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcClu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGGCCLU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGCCLU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGCCLU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcMinClu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGGCMINCLU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGCMINCLU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGCMINCLU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGGCNEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGCNEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGCNEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearEnaClu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGGEARENACLU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGEARENACLU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGEARENACLU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearMinClu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGGEARMINCLU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGEARMINCLU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGEARMINCLU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGGEARNEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGEARNEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGGEARNEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiDragRed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGHIDRAGRED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHIDRAGRED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHIDRAGRED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGHINEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHINEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHINEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiTOilEstim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGHITOILESTIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHITOILESTIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHITOILESTIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGHVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGHVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGHVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngIFrz_PFuCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGIFRZ_PFUCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGIFRZ_PFUCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGIFRZ_PFUCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngIntr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGINTR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGINTR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGINTR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbk_Afl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGLFBK_AFL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBK_AFL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBK_AFL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbk_Afr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGLFBK_AFR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBK_AFR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBK_AFR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbkGas_Afl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGLFBKGAS_AFL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBKGAS_AFL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBKGAS_AFL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbkGas_Afr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGLFBKGAS_AFR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBKGAS_AFR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLFBKGAS_AFR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLoDragRed(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGLODRAGRED]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLODRAGRED] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLODRAGRED] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLoNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGLONEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLONEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGLONEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMax_PFuCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMAX_PFUCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMAX_PFUCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMAX_PFUCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMI1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMI2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMI3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMI4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMI4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiAll(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMIALL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIALL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIALL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMIGAZ1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMIGAZ2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMIGAZ3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMIGAZ4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZ4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGazAll(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMISFEMIGAZALL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZALL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMISFEMIGAZALL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMplReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGMPLREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMPLREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGMPLREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngNeg_PFuCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGNEG_PFUCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGNEG_PFUCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGNEG_PFUCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngNegDifI_PFuCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGNEGDIFI_PFUCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGNEGDIFI_PFUCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGNEGDIFI_PFUCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPFuEngSt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGPFUENGST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGPFUENGST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGPFUENGST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPos_PFuCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGPOS_PFUCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGPOS_PFUCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGPOS_PFUCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPosDifI_PFuCtl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGPOSDIFI_PFUCTL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGPOSDIFI_PFUCTL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGPOSDIFI_PFUCTL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServo(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSERVO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSERVO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSERVO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServoDifNeg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSERVODIFNEG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSERVODIFNEG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSERVODIFNEG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServoDifPos(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSERVODIFPOS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSERVODIFPOS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSERVODIFPOS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSftyDftLih(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSFTYDFTLIH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSFTYDFTLIH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSFTYDFTLIH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngShiftVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSHIFTVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSHIFTVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSHIFTVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngShiftVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSHIFTVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSHIFTVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSHIFTVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSpdVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSPDVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSPDVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSPDVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSpdVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSPDVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSPDVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSPDVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngStopReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSTOPREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSTOPREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSTOPREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngStrtEngSt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSTRTENGST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSTRTENGST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSTRTENGST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSyncEngSt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGSYNCENGST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSYNCENGST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGSYNCENGST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngUnlockEngSt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ORNGUNLOCKENGST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGUNLOCKENGST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ORNGUNLOCKENGST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_HPPmpActCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLD_HPPMPACTCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_HPPMPACTCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_HPPMPACTCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj1Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLD_INJ1CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ1CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ1CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj2Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLD_INJ2CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ2CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ2CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj3Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLD_INJ3CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ3CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ3CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj4Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLD_INJ4CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ4CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_INJ4CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_ThrCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLD_THRCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_THRCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLD_THRCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_OvldThermoThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_OVLDTHERMOTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLDTHERMOTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_OVLDTHERMOTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Plaus_pUsThrBoost(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PLAUS_PUSTHRBOOST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PLAUS_PUSTHRBOOST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PLAUS_PUSTHRBOOST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Plaus_pUsThrIdl(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PLAUS_PUSTHRIDL]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PLAUS_PUSTHRIDL] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PLAUS_PUSTHRIDL] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif_pUsThrSen(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_POSDIF_PUSTHRSEN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSDIF_PUSTHRSEN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSDIF_PUSTHRSEN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif1_pUsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_POSDIF1_PUSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSDIF1_PUSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSDIF1_PUSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif2_pUsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_POSDIF2_PUSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSDIF2_PUSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSDIF2_PUSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PosOfs_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_POSOFS_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSOFS_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_POSOFS_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PresMesFrz(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PRESMESFRZ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PRESMESFRZ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PRESMESFRZ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PresToHi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PRESTOHI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PRESTOHI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PRESTOHI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PresToLo(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PRESTOLO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PRESTOLO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PRESTOLO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ProtAdp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PROTADP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PROTADP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PROTADP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_PwrlMrk(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_PWRLMRK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PWRLMRK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_PWRLMRK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_RatConvTraClc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_RATCONVTRACLC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RATCONVTRACLC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RATCONVTRACLC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_RCDLineScg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_RCDLINESCG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RCDLINESCG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RCDLINESCG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ReadPinInhThr_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_READPININHTHR_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_READPININHTHR_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_READPININHTHR_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_RedESLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_REDESLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_REDESLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_REDESLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_RvLih(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_RVLIH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RVLIH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RVLIH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_RvsGear(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_RVSGEAR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RVSGEAR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_RVSGEAR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_AirExtPresAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_AIREXTPRESACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_AIREXTPRESACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_AIREXTPRESACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_bInhCrkAltHw(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_BINHCRKALTHW]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BINHCRKALTHW] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BINHCRKALTHW] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_BlowBy1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_BLOWBY1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BLOWBY1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BLOWBY1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_BlowBy2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_BLOWBY2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BLOWBY2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BLOWBY2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_bNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_BNEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BNEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_BNEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CtlPmpReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_CTLPMPREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_CTLPMPREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_CTLPMPREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CTP1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_CTP1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_CTP1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_CTP1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CTP2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_CTP2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_CTP2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_CTP2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Dml(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_DML]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_DML] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_DML] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_ECTReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_ECTREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_ECTREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_ECTREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_EngStOutIdc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_ENGSTOUTIDC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_ENGSTOUTIDC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_ENGSTOUTIDC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_FuGauge(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_FUGAUGE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_FUGAUGE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_FUGAUGE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj1Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_INJ1CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ1CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ1CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj2Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_INJ2CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ2CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ2CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj3Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_INJ3CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ3CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ3CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj4Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_INJ4CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ4CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_INJ4CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_OilLvlAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_OILLVLACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_OILLVLACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_OILLVLACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pDsThrMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PDSTHRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PDSTHRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PDSTHRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Ped1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PED1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PED1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PED1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Ped2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PED2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PED2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PED2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PFuAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PFUACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PFUACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PFUACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pOilMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_POILMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_POILMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_POILMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pRelBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PRELBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PRELBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PRELBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PropFuPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PROPFUPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PROPFUPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PROPFUPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pSpgPres(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PSPGPRES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PSPGPRES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PSPGPRES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PwrRly(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_PWRRLY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PWRRLY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_PWRRLY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_rCluPedPrssMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_RCLUPEDPRSSMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_RCLUPEDPRSSMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_RCLUPEDPRSSMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tCoMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_TCOMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TCOMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TCOMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tECUAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_TECUACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TECUACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TECUACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_TrbWaPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_TRBWAPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TRBWAPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_TRBWAPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uDftStaCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_UDFTSTACMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_UDFTSTACMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_UDFTSTACMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uDsLs(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_UDSLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_UDSLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_UDSLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uUpLs(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_UUPLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_UUPLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_UUPLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_VSSNwAcvReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCG_VSSNWACVREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_VSSNWACVREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCG_VSSNWACVREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScgAccPSwt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCGACCPSWT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCGACCPSWT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCGACCPSWT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScgPosnSnsr1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCGPOSNSNSR1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCGPOSNSNSR1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCGPOSNSNSR1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScgPosnSnsr2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCGPOSNSNSR2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCGPOSNSNSR2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCGPOSNSNSR2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_AirExtPresAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_AIREXTPRESACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_AIREXTPRESACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_AIREXTPRESACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_bInhCrkAltHw(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_BINHCRKALTHW]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BINHCRKALTHW] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BINHCRKALTHW] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_BlowBy1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_BLOWBY1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BLOWBY1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BLOWBY1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_BlowBy2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_BLOWBY2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BLOWBY2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BLOWBY2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_bNeut(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_BNEUT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BNEUT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_BNEUT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CtlPmpReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_CTLPMPREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_CTLPMPREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_CTLPMPREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CTP1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_CTP1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_CTP1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_CTP1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CTP2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_CTP2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_CTP2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_CTP2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Dml(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_DML]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_DML] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_DML] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_ECTReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_ECTREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_ECTREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_ECTREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_EngStOutIdc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_ENGSTOUTIDC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_ENGSTOUTIDC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_ENGSTOUTIDC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_HPPmpActCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_HPPMPACTCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_HPPMPACTCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_HPPMPACTCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil1Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_IGCOIL1CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL1CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL1CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil2Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_IGCOIL2CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL2CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL2CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil3Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_IGCOIL3CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL3CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL3CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil4Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_IGCOIL4CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL4CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_IGCOIL4CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj1Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_INJ1CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ1CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ1CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj2Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_INJ2CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ2CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ2CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj3Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_INJ3CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ3CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ3CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj4Cmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_INJ4CMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ4CMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_INJ4CMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_OilLvlAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_OILLVLACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_OILLVLACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_OILLVLACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pDsThrMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PDSTHRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PDSTHRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PDSTHRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PFuAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PFUACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PFUACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PFUACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pOilMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_POILMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_POILMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_POILMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pRelBrkAsi(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PRELBRKASI]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PRELBRKASI] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PRELBRKASI] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PropFuPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PROPFUPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PROPFUPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PROPFUPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pSpgPres(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PSPGPRES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PSPGPRES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PSPGPRES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PwrRly(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_PWRRLY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PWRRLY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_PWRRLY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_rCluPedPrssMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_RCLUPEDPRSSMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_RCLUPEDPRSSMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_RCLUPEDPRSSMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tCoMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_TCOMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TCOMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TCOMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tECUAcq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_TECUACQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TECUACQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TECUACQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_TrbWaPmp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_TRBWAPMP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TRBWAPMP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_TRBWAPMP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uDftStaCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_UDFTSTACMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_UDFTSTACMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_UDFTSTACMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uDsLs(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_UDSLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_UDSLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_UDSLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uUpLs(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_UUPLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_UUPLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_UUPLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_VSSNwAcvReq(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCP_VSSNWACVREQ]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_VSSNWACVREQ] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCP_VSSNWACVREQ] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpAccPSwt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCPACCPSWT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPACCPSWT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPACCPSWT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpOc_Ped1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCPOC_PED1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPOC_PED1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPOC_PED1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpOc_Ped2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCPOC_PED2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPOC_PED2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPOC_PED2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpPosnSnsr1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCPPOSNSNSR1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPPOSNSNSR1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPPOSNSNSR1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpPosnSnsr2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SCPPOSNSNSR2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPPOSNSNSR2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SCPPOSNSNSR2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ServoErrVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SERVOERRVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SERVOERRVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SERVOERRVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ServoErrVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SERVOERRVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SERVOERRVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SERVOERRVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SftyChkPt_PfcMng(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SFTYCHKPT_PFCMNG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SFTYCHKPT_PFCMNG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SFTYCHKPT_PFCMNG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SftyORngAMT(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SFTYORNGAMT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SFTYORNGAMT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SFTYORNGAMT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SftyORngAT(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SFTYORNGAT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SFTYORNGAT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SFTYORNGAT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossCk(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SIGLOSSCK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SIGLOSSCK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SIGLOSSCK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossExCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SIGLOSSEXCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SIGLOSSEXCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SIGLOSSEXCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossInCm(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SIGLOSSINCM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SIGLOSSINCM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SIGLOSSINCM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC1VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWC1VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC1VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC1VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC1VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWC1VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC1VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC1VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC2VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWC2VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC2VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC2VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC2VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWC2VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC2VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWC2VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH1VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWH1VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH1VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH1VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH1VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWH1VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH1VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH1VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH2VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWH2VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH2VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH2VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH2VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SLOWH2VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH2VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SLOWH2VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SpdVehClc(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SPDVEHCLC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SPDVEHCLC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SPDVEHCLC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StaAcvThd1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STAACVTHD1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STAACVTHD1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STAACVTHD1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StaAcvThd2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STAACVTHD2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STAACVTHD2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STAACVTHD2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StabCoh_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STABCOH_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STABCOH_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STABCOH_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StaCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STACMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STACMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STACMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StaCmdInfo(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STACMDINFO]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STACMDINFO] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STACMDINFO] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StaElCmd(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STAELCMD]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STAELCMD] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STAELCMD] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StallCoh_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STALLCOH_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STALLCOH_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STALLCOH_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StallCoh_tAirMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STALLCOH_TAIRMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STALLCOH_TAIRMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STALLCOH_TAIRMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StFuLvlDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STFULVLDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STFULVLDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STFULVLDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_CluSt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCK_CLUST]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_CLUST] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_CLUST] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_HPSens(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCK_HPSENS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_HPSENS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_HPSENS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_MainRly(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCK_MAINRLY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_MAINRLY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_MAINRLY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_PwrRly(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCK_PWRRLY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_PWRRLY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCK_PWRRLY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckAccP(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKACCP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKACCP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKACCP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckAccPSwt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKACCPSWT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKACCPSWT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKACCPSWT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckCls_DmpVlv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKCLS_DMPVLV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKCLS_DMPVLV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKCLS_DMPVLV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckCls_pTrbAct(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKCLS_PTRBACT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKCLS_PTRBACT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKCLS_PTRBACT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH1VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKH1VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH1VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH1VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH1VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKH1VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH1VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH1VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH2VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKH2VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH2VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH2VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH2VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKH2VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH2VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH2VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH3VlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKH3VLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH3VLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH3VLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH3VlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKH3VLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH3VLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKH3VLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckHVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKHVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKHVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKHVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckHVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKHVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKHVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKHVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckMec(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKMEC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKMEC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKMEC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_DmpVlv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKOP_DMPVLV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_DMPVLV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_DMPVLV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl1(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKOP_INJRCYL1]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL1] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL1] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl2(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKOP_INJRCYL2]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL2] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL2] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl3(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKOP_INJRCYL3]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL3] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL3] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl4(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKOP_INJRCYL4]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL4] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_INJRCYL4] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_pTrbAct(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_STUCKOP_PTRBACT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_PTRBACT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_STUCKOP_PTRBACT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SyncMon_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SYNCMON_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SYNCMON_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SYNCMON_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_SyncMon_CpuSfty(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_SYNCMON_CPUSFTY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SYNCMON_CPUSFTY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_SYNCMON_CPUSFTY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoBlock(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TCOBLOCK]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOBLOCK] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOBLOCK] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoOverEstim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TCOOVERESTIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOOVERESTIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOOVERESTIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoSlowRise(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TCOSLOWRISE]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOSLOWRISE] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOSLOWRISE] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoUndEstim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TCOUNDESTIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOUNDESTIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOUNDESTIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoWarn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TCOWARN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOWARN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TCOWARN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TDCDiagVlvActEx(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TDCDIAGVLVACTEX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TDCDIAGVLVACTEX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TDCDIAGVLVACTEX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TDCDiagVlvActIn(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TDCDIAGVLVACTIN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TDCDIAGVLVACTIN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TDCDIAGVLVACTIN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ThermoStuckCls(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_THERMOSTUCKCLS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THERMOSTUCKCLS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THERMOSTUCKCLS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ThermoStuckOp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_THERMOSTUCKOP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THERMOSTUCKOP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THERMOSTUCKOP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Thr_Cpu(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_THR_CPU]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THR_CPU] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THR_CPU] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ThrCoh_pDsThr(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_THRCOH_PDSTHR]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THRCOH_PDSTHR] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_THRCOH_PDSTHR] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ToothCoh_CkSts(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TOOTHCOH_CKSTS]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TOOTHCOH_CKSTS] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TOOTHCOH_CKSTS] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_TqAlt(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TQALT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TQALT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TQALT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_tqAltRv(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TQALTRV]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TQALTRV] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TQALTRV] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Trck_tCoMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_TRCK_TCOMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TRCK_TCOMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_TRCK_TCOMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_UnVld_StFanC(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_UNVLD_STFANC]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_UNVLD_STFANC] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_UNVLD_STFANC] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_UsThrPrssSdown(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_USTHRPRSSSDOWN]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_USTHRPRSSSDOWN] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_USTHRPRSSSDOWN] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_UsThrPrssSup(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_USTHRPRSSSUP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_USTHRPRSSSUP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_USTHRPRSSSUP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSLim(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSLIM]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSLIM] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSLIM] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSLimBody(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSLIMBODY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSLIMBODY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSLIMBODY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSMax(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSMAX]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSMAX] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSMAX] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSMaxp(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSMAXP]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSMAXP] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSMAXP] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSReg(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSREG]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSREG] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSREG] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSRegBody(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSREGBODY]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSREGBODY] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSREGBODY] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_VSRegVeh(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_VSREGVEH]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSREGVEH] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_VSREGVEH] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_WrgAnswCtlUnit(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_WRGANSWCTLUNIT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_WRGANSWCTLUNIT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_WRGANSWCTLUNIT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_Wup_tCoMes(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_WUP_TCOMES]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_WUP_TCOMES] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_WUP_TCOMES] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ZeroFrameCntDft(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ZEROFRAMECNTDFT]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ZEROFRAMECNTDFT] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ZEROFRAMECNTDFT] = FALSE;
   }
}

void FRM_vidF02_FidMng_F01_FRM_RawDft_ZzEnd_Bidon(void)
{
   if ( IS_SNG_DFT_ACTIVE(FRM_au8DU[GD_DFT_ZZEND_BIDON]) )
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ZZEND_BIDON] = TRUE;
   }
   else
   {
      FRM_abDftTypCc_NameVar[FRM_LD_ZZEND_BIDON] = FALSE;
   }
}


void (*const FRM_avidF02_FidMng_F01_FRM_RawDft[FRM_LD_NB])(void) =
{
   FRM_vidF02_FidMng_F01_FRM_RawDft_AaStart_Bidon,
   FRM_vidF02_FidMng_F01_FRM_RawDft__iBattMaxCkg,
   FRM_vidF02_FidMng_F01_FRM_RawDft__iBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft__rBattSoC,
   FRM_vidF02_FidMng_F01_FRM_RawDft__resBattIt,
   FRM_vidF02_FidMng_F01_FRM_RawDft__tBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft__uBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft__uBattMinCkg,
   FRM_vidF02_FidMng_F01_FRM_RawDft__uBattOc,
   FRM_vidF02_FidMng_F01_FRM_RawDft__uBattRstrt,
   FRM_vidF02_FidMng_F01_FRM_RawDft__uBattStrt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AbsEspMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AccelCoh_BrkPed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AccelCoh_BrkPedBVH2p,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AccP_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffEGRVlvLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs1Lim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs2Lim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs3Lim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfsLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpClsExOfsLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpInjOfsLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpIvsInjConLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpOpInOfsLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AdpSlopInjConLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AirPrssExtSdwn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AirPrssExtSup,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Algo_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Algo_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AltAbsentEcu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AntiBoil,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ArDeltaCorLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_AsicGdiFailure,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Block_Strtr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Blt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Boost1_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Boost2_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Boost3_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Boost4_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_BsiMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_BusOff,
   FRM_vidF02_FidMng_F01_FRM_RawDft_BvaMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CAVMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_iBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_tBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_uBattClc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CksRom_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Clk_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Clk_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ClnErrVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ClnErrVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ClsdRly_StFanC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ClsIdlCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CluDmgAfts,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CmdCVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CmdCVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CmdHVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CmdHVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_bModSptReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_CluSt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_EepPwrl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_EepReinit,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_ExCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_HPSens,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_InCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_pBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_Ped,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_PFuAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_rAccP,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_spdVeh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_stCluAC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2HiSpd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2LoSpd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2NoSpd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_stPwrAC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StrtLock,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_tiEngStop,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CohAccPSwt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit2_stDftOBD,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit3_stDftOBD,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit4_stDftOBD,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit7_stDftOBD,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CohPosnSnsr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ComAlt_AltCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ComSpi_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ComSpi_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ComTout_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ComTout_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CorLoss,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CorSpCur,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CoSysDfct,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Cpt_ThrCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CritSc_StFanC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CrkCoh_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CrsCtlDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_CutReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DecelCoh_BrkPed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DecelCoh_BrkPedBVH2p,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DegMod_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Dft_Info_Crash,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftCVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftCVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftEeprom,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftFu_Afl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftFu_Afr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftFuGas_Afl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftFuGas_Afr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftHVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftHVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftObjEep,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftOnOffHi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftOnOffLo,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftOscCfm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegHi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegHiCfm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegLo,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegLoCfm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2_Afl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2_Afr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2Gas_Afl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2Gas_Afr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenr_AccP,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenr_Thr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg1VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg1VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg2VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg2VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos1VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos1VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos2VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos2VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DiraMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DistSig,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DmtrMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_DrvTra,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ECI_StFanC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EcmMute,
   FRM_vidF02_FidMng_F01_FRM_RawDft_El_StFanC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElChkConsDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsCohVSMaxp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSMaxp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSReg,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsInitDftVSReg,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsVarDftVSLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsVarDftVSReg,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElCptTraBsiDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElDftCrsCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElDiagInhPin0_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElDiagInhPin1_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElecAlt_AltCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElFrameCntIncDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ElInfBsiDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopOldVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopOldVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopReq1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopReq2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EngOilOverHeat,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohCk,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohExCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohInCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Etat_Alt1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Etat_Alt2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_EvenFrameCntDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ExtLeak_FuSys,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F305Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F305Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F305Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F305P537Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F305P538Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F30DLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F30DLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP263Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP264Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP265Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP266Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F329Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F329Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F329Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F329P445Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F329ProcFailed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349P007Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349P055Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349P440Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F349ProcFailed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F34DCoh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F34DLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F34DLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F34DPM1413Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F34DProcFailed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F38DCoh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F38DLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F38DLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F38DP010Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F38DP052Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F38DProcFailed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADCoh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P291Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P363Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P364Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P482Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P483Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9ProcFailed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDCoh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP225Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP319Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP515Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F412Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F412Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F412P040Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F432Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F432Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F432Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F432Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DCoh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DFP0535Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP330Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP331Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP354Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F489Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F489Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F489Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F489P102Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F489P218Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F489P254Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F492Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F492Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F495Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F495Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4B2Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4B2Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4D2Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4D2Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P429Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P434Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P437Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P438Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P490Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P491Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P492Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50DLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50DLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50ELength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50ELost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50EP046Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50EP210Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F50EPM1386Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F532Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F532Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F532Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1414Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1415Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1416Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP015Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP325Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP326Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552P255Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552P256Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F552P257Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F572Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F572Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F572Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F572PM1360Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F57CCoh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F57CLength,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F57CLost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F57CPM1418Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P272Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P273Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P349Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P418Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P419Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P420Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F592P421Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2P146Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F612Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F612Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F612Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F612P260Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F612P436Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F612P705Invld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Coh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Length,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Lost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2P015bisInvld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2P146bisInvld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_FctCluP,
   FRM_vidF02_FidMng_F01_FRM_RawDft_FlashChk,
   FRM_vidF02_FidMng_F01_FRM_RawDft_FldCoh_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Frq_PropFuPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_FSFBlockCls,
   FRM_vidF02_FidMng_F01_FRM_RawDft_FSFBlockOp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_GravScp_PropFuPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_OilLvlAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pACMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pAirExt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pAirExtOld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pRelBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_rCluPedPrssMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_tCoMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HHit_NoiseAdp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_aEng,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DmpVlvCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrFan1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrFan2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrSenO2Ds,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrSenO2Us,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_nEng,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_pACMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_uBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_WgcCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HiCstrDrv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HiTAlt_AltCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HiToothCoh_CkSts,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HiVlvActExDrv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HiVlvActInDrv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_HSld_NoiseAdp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IdcBlbyCnd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IMaxVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IMaxVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ImmoCodNotRead,
   FRM_vidF02_FidMng_F01_FRM_RawDft_InhChkInitSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_InhEngStopSTT,
   FRM_vidF02_FidMng_F01_FRM_RawDft_InhThr_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Inv_CalId,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Inv_VarCod,
   FRM_vidF02_FidMng_F01_FRM_RawDft_InvCoh_BrkPed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Invld_uDftStaCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IrvECU,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IrvEM,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IrvSTT,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IrvVSCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LgEngRStrtInh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LHit_NoiseAdp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LihReq1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LihReq2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LinBlockedBus,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DmpVlvCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrFan1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrFan2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrSenO2Ds,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrSenO2Us,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_pACMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_uBattMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_uBattSpc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_WgcCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LoCstrDrv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LoFuLvl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LostMisfRoughnsRoad,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LoVlvActExDrv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LoVlvActInDrv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LrnEndStopVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LrnEndStopVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LrnFaiLimVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LrnFaiLimVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_LSld_NoiseAdp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_MainWkuDisrd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_MainWkuIncst,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Map_PropFuPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Max_pAirExt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_MaxAbs_pUsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_McpFlashCks_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_McpRAMTest_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_McwCksCalc_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_McwFctTest_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_McwInitSftyRslt_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_MecaAlt_AltCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Min_pAirExt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_MissToothVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_MissToothVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif_pUsThrSen,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif1_pUsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif2_pUsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NegOfs_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NoAnswCtlUnit,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NoGap_CkSts,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigCk,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigExCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigInCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ObsAdp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_bInhCrkAltHw,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_BlowBy1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_BlowBy2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CtlPmpReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CTP1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CTP2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Dml,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_DrvrFan1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_DrvrFan2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_ECTReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_EngStOutIdc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_FuGauge,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_HPPmpActCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil1Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil2Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil3Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil4Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj1Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj2Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj3Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj4Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_PropFuPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_PwrRly,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_tCoMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_TrbWaPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_uDsLs,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_uUpLs,
   FRM_vidF02_FidMng_F01_FRM_RawDft_OilPrssSdwnORng,
   FRM_vidF02_FidMng_F01_FRM_RawDft_OilPrssSupORng,
   FRM_vidF02_FidMng_F01_FRM_RawDft_OldLrnVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_OldLrnVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_bNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_Cat,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_CatApv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsHeat,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsPlausFco,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsPlausFld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_FuGauge,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_FuGaugeLvl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_KnkDiag,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_LongWinLrn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_LongWinLrnMax,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_OxyApvPerd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_OxySensPerd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblIrvLdLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblTmpLdLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblVlvPosn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_rCluPedPrssMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_ShrtWinLrn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_ShrtWinLrnMax,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_SigGrdDiag,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_spdVeh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_tiEngStop,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsHeat,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsPlausFco,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsPlausFld,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes1_Sfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes2_Sfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes3_Sfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes4_Sfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCutOffReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCAll,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGazAll,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDAll,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGazAll,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcClu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcMinClu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearEnaClu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearMinClu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiDragRed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiTOilEstim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngIFrz_PFuCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngIntr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbk_Afl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbk_Afr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbkGas_Afl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbkGas_Afr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLoDragRed,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLoNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMax_PFuCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiAll,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGazAll,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMplReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngNeg_PFuCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngNegDifI_PFuCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPFuEngSt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPos_PFuCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPosDifI_PFuCtl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServo,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServoDifNeg,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServoDifPos,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSftyDftLih,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngShiftVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngShiftVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSpdVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSpdVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngStopReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngStrtEngSt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSyncEngSt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ORngUnlockEngSt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_HPPmpActCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj1Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj2Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj3Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj4Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_ThrCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_OvldThermoThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Plaus_pUsThrBoost,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Plaus_pUsThrIdl,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif_pUsThrSen,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif1_pUsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif2_pUsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PosOfs_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PresMesFrz,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PresToHi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PresToLo,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ProtAdp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_PwrlMrk,
   FRM_vidF02_FidMng_F01_FRM_RawDft_RatConvTraClc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_RCDLineScg,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ReadPinInhThr_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_RedESLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_RvLih,
   FRM_vidF02_FidMng_F01_FRM_RawDft_RvsGear,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_AirExtPresAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_bInhCrkAltHw,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_BlowBy1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_BlowBy2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_bNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CtlPmpReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CTP1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CTP2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Dml,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_ECTReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_EngStOutIdc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_FuGauge,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj1Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj2Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj3Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj4Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_OilLvlAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pDsThrMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Ped1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Ped2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PFuAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pOilMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pRelBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PropFuPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pSpgPres,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PwrRly,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_rCluPedPrssMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tCoMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tECUAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_TrbWaPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uDftStaCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uDsLs,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uUpLs,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_VSSNwAcvReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScgAccPSwt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScgPosnSnsr1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScgPosnSnsr2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_AirExtPresAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_bInhCrkAltHw,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_BlowBy1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_BlowBy2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_bNeut,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CtlPmpReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CTP1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CTP2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Dml,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_ECTReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_EngStOutIdc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_HPPmpActCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil1Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil2Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil3Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil4Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj1Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj2Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj3Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj4Cmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_OilLvlAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pDsThrMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PFuAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pOilMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pRelBrkAsi,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PropFuPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pSpgPres,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PwrRly,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_rCluPedPrssMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tCoMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tECUAcq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_TrbWaPmp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uDftStaCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uDsLs,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uUpLs,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_VSSNwAcvReq,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScpAccPSwt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScpOc_Ped1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScpOc_Ped2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScpPosnSnsr1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ScpPosnSnsr2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ServoErrVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ServoErrVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SftyChkPt_PfcMng,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SftyORngAMT,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SftyORngAT,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossCk,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossExCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossInCm,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC1VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC1VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC2VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC2VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH1VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH1VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH2VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH2VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SpdVehClc,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StaAcvThd1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StaAcvThd2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StabCoh_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StaCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StaCmdInfo,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StaElCmd,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StallCoh_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StallCoh_tAirMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StFuLvlDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_CluSt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_HPSens,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_MainRly,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_PwrRly,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckAccP,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckAccPSwt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckCls_DmpVlv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckCls_pTrbAct,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH1VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH1VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH2VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH2VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH3VlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH3VlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckHVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckHVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckMec,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_DmpVlv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl1,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl2,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl3,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl4,
   FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_pTrbAct,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SyncMon_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_SyncMon_CpuSfty,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TCoBlock,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TCoOverEstim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TCoSlowRise,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TCoUndEstim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TCoWarn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TDCDiagVlvActEx,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TDCDiagVlvActIn,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ThermoStuckCls,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ThermoStuckOp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Thr_Cpu,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ThrCoh_pDsThr,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ToothCoh_CkSts,
   FRM_vidF02_FidMng_F01_FRM_RawDft_TqAlt,
   FRM_vidF02_FidMng_F01_FRM_RawDft_tqAltRv,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Trck_tCoMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_UnVld_StFanC,
   FRM_vidF02_FidMng_F01_FRM_RawDft_UsThrPrssSdown,
   FRM_vidF02_FidMng_F01_FRM_RawDft_UsThrPrssSup,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSLim,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSLimBody,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSMax,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSMaxp,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSReg,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSRegBody,
   FRM_vidF02_FidMng_F01_FRM_RawDft_VSRegVeh,
   FRM_vidF02_FidMng_F01_FRM_RawDft_WrgAnswCtlUnit,
   FRM_vidF02_FidMng_F01_FRM_RawDft_Wup_tCoMes,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ZeroFrameCntDft,
   FRM_vidF02_FidMng_F01_FRM_RawDft_ZzEnd_Bidon
};
const uint16 FRM_u16convDftIdtoLDId[GD_DFT_NB]={
   FRM_LD_AASTART_BIDON,
   FRM_LD_COH_PED,
   FRM_LD_SCPOC_PED2,
   FRM_LD_SCG_PED2,
   FRM_LD_SCPOC_PED1,
   FRM_LD_SCG_PED1,
   FRM_LD_COH_RACCP,
   FRM_LD_STUCKACCP,
   FRM_LD_SCPACCPSWT,
   FRM_LD_STUCKACCPSWT,
   FRM_LD_SCGACCPSWT,
   FRM_LD_COHACCPSWT,
   FRM_LD_GRD_PACMES,
   FRM_LD_HI_PACMES,
   FRM_LD_LO_PACMES,
   FRM_LD_OC_TAIRMES,
   FRM_LD_SCG_TAIRMES,
   FRM_LD_SCP_TAIRMES,
   FRM_LD_GRD_TAIRMES,
   FRM_LD_GRD_TCOMES,
   FRM_LD_OC_TCOMES,
   FRM_LD_SCG_TCOMES,
   FRM_LD_SCP_TCOMES,
   FRM_LD_SCG_CTP1,
   FRM_LD_SCP_CTP1,
   FRM_LD_OC_CTP1,
   FRM_LD_SCG_CTP2,
   FRM_LD_SCP_CTP2,
   FRM_LD_OC_CTP2,
   FRM_LD_SCG_AIREXTPRESACQ,
   FRM_LD_SCP_AIREXTPRESACQ,
   FRM_LD_NEGOFS_TAIRMES,
   FRM_LD_ORNG_TAIRMES,
   FRM_LD_POSOFS_TAIRMES,
   FRM_LD_STALLCOH_TAIRMES,
   FRM_LD_SCP_BINHCRKALTHW,
   FRM_LD_SCG_BINHCRKALTHW,
   FRM_LD_HI_UBATTMES,
   FRM_LD_LO_UBATTMES,
   FRM_LD_SCP_UDFTSTACMD,
   FRM_LD_SCG_UDFTSTACMD,
   FRM_LD_INVLD_UDFTSTACMD,
   FRM_LD_SCG_BLOWBY1,
   FRM_LD_SCG_BLOWBY2,
   FRM_LD_SCP_BLOWBY1,
   FRM_LD_SCP_BLOWBY2,
   FRM_LD_OC_BLOWBY1,
   FRM_LD_OC_BLOWBY2,
   FRM_LD_SCP_PBRKASI,
   FRM_LD_SCG_PBRKASI,
   FRM_LD_GRD_PBRKASI,
   FRM_LD_COH_PBRKASI,
   FRM_LD_DECELCOH_BRKPEDBVH2P,
   FRM_LD_ACCELCOH_BRKPEDBVH2P,
   FRM_LD_HI_AENG,
   FRM_LD_HI_NENG,
   FRM_LD_SCP_RCLUPEDPRSSMES,
   FRM_LD_SCG_RCLUPEDPRSSMES,
   FRM_LD_ORNG_RCLUPEDPRSSMES,
   FRM_LD_GRD_RCLUPEDPRSSMES,
   FRM_LD_FCTCLUP,
   FRM_LD_COH_CLUST,
   FRM_LD_STUCK_CLUST,
   FRM_LD_OC_DRVRFAN1,
   FRM_LD_LO_DRVRFAN1,
   FRM_LD_HI_DRVRFAN1,
   FRM_LD_OC_DRVRFAN2,
   FRM_LD_LO_DRVRFAN2,
   FRM_LD_HI_DRVRFAN2,
   FRM_LD_COH_STFANB1,
   FRM_LD_COH_STFANB2LOSPD,
   FRM_LD_COH_STFANB2HISPD,
   FRM_LD_COH_STFANB2NOSPD,
   FRM_LD_CLSDRLY_STFANC,
   FRM_LD_EL_STFANC,
   FRM_LD_UNVLD_STFANC,
   FRM_LD_CRITSC_STFANC,
   FRM_LD_ECI_STFANC,
   FRM_LD_COHBIT7_STDFTOBD,
   FRM_LD_COHBIT4_STDFTOBD,
   FRM_LD_COHBIT3_STDFTOBD,
   FRM_LD_COHBIT2_STDFTOBD,
   FRM_LD_CHKBATTSYS_IBATTMES,
   FRM_LD_CHKBATTSYS_TBATTMES,
   FRM_LD_CHKBATTSYS_UBATTCLC,
   FRM_LD_STFULVLDFT,
   FRM_LD_COH_BMODSPTREQ,
   FRM_LD_COH_STCLUAC,
   FRM_LD_COH_STPWRAC,
   FRM_LD_LINBLOCKEDBUS,
   FRM_LD_ALTABSENTECU,
   FRM_LD_ETAT_ALT1,
   FRM_LD_ETAT_ALT2,
   FRM_LD_TRCK_TCOMES,
   FRM_LD_WUP_TCOMES,
   FRM_LD_ELINFBSIDFT,
   FRM_LD_ELCPTTRABSIDFT,
   FRM_LD_ELCHKCONSDFT,
   FRM_LD_ELCONSDEFDFTVSLIM,
   FRM_LD_ELCONSVARDFTVSLIM,
   FRM_LD_ELCONSDEFDFTVSREG,
   FRM_LD_ELCONSVARDFTVSREG,
   FRM_LD_ELCONSINITDFTVSREG,
   FRM_LD_ELDFTCRSCTL,
   FRM_LD_ZEROFRAMECNTDFT,
   FRM_LD_EVENFRAMECNTDFT,
   FRM_LD_ELFRAMECNTINCDFT,
   FRM_LD_ELCONSCOHVSMAXP,
   FRM_LD_ELCONSDEFDFTVSMAXP,
   FRM_LD_CRSCTLDFT,
   FRM_LD_LOCSTRDRV,
   FRM_LD_HICSTRDRV,
   FRM_LD_OC_CTLPMPREQ,
   FRM_LD_SCG_CTLPMPREQ,
   FRM_LD_SCP_CTLPMPREQ,
   FRM_LD_SCG_INJ1CMD,
   FRM_LD_SCP_INJ1CMD,
   FRM_LD_OC_INJ1CMD,
   FRM_LD_OVLD_INJ1CMD,
   FRM_LD_SCG_INJ2CMD,
   FRM_LD_SCP_INJ2CMD,
   FRM_LD_OC_INJ2CMD,
   FRM_LD_OVLD_INJ2CMD,
   FRM_LD_SCG_INJ3CMD,
   FRM_LD_SCP_INJ3CMD,
   FRM_LD_OC_INJ3CMD,
   FRM_LD_OVLD_INJ3CMD,
   FRM_LD_SCG_INJ4CMD,
   FRM_LD_SCP_INJ4CMD,
   FRM_LD_OC_INJ4CMD,
   FRM_LD_OVLD_INJ4CMD,
   FRM_LD_MAX_PAIREXT,
   FRM_LD_MIN_PAIREXT,
   FRM_LD_GRD_PAIREXT,
   FRM_LD_GRD_PAIREXTOLD,
   FRM_LD_ASICGDIFAILURE,
   FRM_LD_DECELCOH_BRKPED,
   FRM_LD_ACCELCOH_BRKPED,
   FRM_LD_INVCOH_BRKPED,
   FRM_LD_DFTEEPROM,
   FRM_LD_FLASHCHK,
   FRM_LD_HI_DMPVLVCMD,
   FRM_LD_LO_DMPVLVCMD,
   FRM_LD_HI_DRVRSENO2DS,
   FRM_LD_LO_DRVRSENO2DS,
   FRM_LD_HI_DRVRSENO2US,
   FRM_LD_LO_DRVRSENO2US,
   FRM_LD_SCP_UDSLS,
   FRM_LD_OC_UDSLS,
   FRM_LD_SCG_UDSLS,
   FRM_LD_SCP_ECTREQ,
   FRM_LD_SCG_ECTREQ,
   FRM_LD_OC_ECTREQ,
   FRM_INVALID_LD_ID,
   FRM_LD_REDESLIM,
   FRM_LD_SCP_ENGSTOUTIDC,
   FRM_LD_SCG_ENGSTOUTIDC,
   FRM_LD_OC_ENGSTOUTIDC,
   FRM_LD_STUCKCLS_DMPVLV,
   FRM_LD_STUCKOP_DMPVLV,
   FRM_LD_POSDIF1_PUSTHR,
   FRM_LD_POSDIF2_PUSTHR,
   FRM_LD_NEGDIF1_PUSTHR,
   FRM_LD_NEGDIF2_PUSTHR,
   FRM_LD_PLAUS_PUSTHRIDL,
   FRM_LD_PLAUS_PUSTHRBOOST,
   FRM_LD_NEGDIF_PUSTHRSEN,
   FRM_LD_POSDIF_PUSTHRSEN,
   FRM_LD_MAXABS_PUSTHR,
   FRM_LD_STUCKCLS_PTRBACT,
   FRM_LD_STUCKOP_PTRBACT,
   FRM_LD_ORNG_FUGAUGELVL,
   FRM_LD_LOFULVL,
   FRM_LD_OC_FUGAUGE,
   FRM_LD_ORNG_FUGAUGE,
   FRM_LD_SCG_FUGAUGE,
   FRM_LD_EXTLEAK_FUSYS,
   FRM_LD_ORNG_SIGGRDDIAG,
   FRM_LD_ORNG_DSPLAUSFLD,
   FRM_LD_ORNG_DSPLAUSFCO,
   FRM_LD_ORNG_USHEAT,
   FRM_LD_ORNG_DSHEAT,
   FRM_LD_ORNG_USPLAUSFLD,
   FRM_LD_ORNG_USPLAUSFCO,
   FRM_LD_ORNG_OXYSENSPERD,
   FRM_LD_ORNG_OXYAPVPERD,
   FRM_LD_OC_HPPMPACTCMD,
   FRM_LD_SCP_HPPMPACTCMD,
   FRM_LD_OVLD_HPPMPACTCMD,
   FRM_LD_ORNGIFRZ_PFUCTL,
   FRM_LD_ORNGMAX_PFUCTL,
   FRM_LD_ORNGNEGDIFI_PFUCTL,
   FRM_LD_ORNGNEG_PFUCTL,
   FRM_LD_ORNGPOSDIFI_PFUCTL,
   FRM_LD_ORNGPOS_PFUCTL,
   FRM_LD_COH_HPSENS,
   FRM_LD_STUCK_HPSENS,
   FRM_LD_OC_IGCOIL1CMD,
   FRM_LD_SCP_IGCOIL1CMD,
   FRM_LD_OC_IGCOIL2CMD,
   FRM_LD_SCP_IGCOIL2CMD,
   FRM_LD_OC_IGCOIL3CMD,
   FRM_LD_SCP_IGCOIL3CMD,
   FRM_LD_OC_IGCOIL4CMD,
   FRM_LD_SCP_IGCOIL4CMD,
   FRM_LD_BOOST1_PDSTHR,
   FRM_LD_BOOST2_PDSTHR,
   FRM_LD_BOOST3_PDSTHR,
   FRM_LD_BOOST4_PDSTHR,
   FRM_LD_DFT_INFO_CRASH,
   FRM_LD_ORNGLFBK_AFL,
   FRM_LD_DFTFU_AFL,
   FRM_LD_DFTSENO2_AFL,
   FRM_LD_ORNGLFBKGAS_AFL,
   FRM_LD_DFTFUGAS_AFL,
   FRM_LD_DFTSENO2GAS_AFL,
   FRM_LD_ORNGLFBK_AFR,
   FRM_LD_DFTFU_AFR,
   FRM_LD_DFTSENO2_AFR,
   FRM_LD_ORNGLFBKGAS_AFR,
   FRM_LD_DFTFUGAS_AFR,
   FRM_LD_DFTSENO2GAS_AFR,
   FRM_LD_SCP_PDSTHRMES,
   FRM_LD_SCG_PDSTHRMES,
   FRM_LD_STALLCOH_PDSTHR,
   FRM_LD_CRKCOH_PDSTHR,
   FRM_LD_STABCOH_PDSTHR,
   FRM_LD_THRCOH_PDSTHR,
   FRM_LD_ORNG_PDSTHR,
   FRM_LD_FLDCOH_PDSTHR,
   FRM_LD_GRD_PDSTHR,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_LD_HITALT_ALTCTL,
   FRM_LD_MECAALT_ALTCTL,
   FRM_LD_ELECALT_ALTCTL,
   FRM_LD_COMALT_ALTCTL,
   FRM_LD_ORNG_KNKDIAG,
   FRM_LD_ORNG_RBLVLVPOSN,
   FRM_LD_ORNG_RBLTMPLDLIM,
   FRM_LD_ORNG_RBLIRVLDLIM,
   FRM_LD_HHIT_NOISEADP,
   FRM_LD_LHIT_NOISEADP,
   FRM_LD_HSLD_NOISEADP,
   FRM_LD_LSLD_NOISEADP,
   FRM_LD_ORNG_SHRTWINLRN,
   FRM_LD_ORNG_LONGWINLRN,
   FRM_LD_ORNG_SHRTWINLRNMAX,
   FRM_LD_ORNG_LONGWINLRNMAX,
   FRM_LD_ORNGDMGCATMD1,
   FRM_LD_ORNGDMGCATMD2,
   FRM_LD_ORNGDMGCATMD3,
   FRM_LD_ORNGDMGCATMD4,
   FRM_LD_ORNGDMGCATMDALL,
   FRM_LD_ORNGDMGCATDTC1,
   FRM_LD_ORNGDMGCATDTC2,
   FRM_LD_ORNGDMGCATDTC3,
   FRM_LD_ORNGDMGCATDTC4,
   FRM_LD_ORNGDMGCATDTCALL,
   FRM_LD_ORNGMISFEMI1,
   FRM_LD_ORNGMISFEMI2,
   FRM_LD_ORNGMISFEMI3,
   FRM_LD_ORNGMISFEMI4,
   FRM_LD_ORNGMISFEMIALL,
   FRM_LD_ORNGDMGCATMDGAZ1,
   FRM_LD_ORNGDMGCATMDGAZ2,
   FRM_LD_ORNGDMGCATMDGAZ3,
   FRM_LD_ORNGDMGCATMDGAZ4,
   FRM_LD_ORNGDMGCATMDGAZALL,
   FRM_LD_ORNGDMGCATDTCGAZ1,
   FRM_LD_ORNGDMGCATDTCGAZ2,
   FRM_LD_ORNGDMGCATDTCGAZ3,
   FRM_LD_ORNGDMGCATDTCGAZ4,
   FRM_LD_ORNGDMGCATDTCGAZALL,
   FRM_LD_ORNGMISFEMIGAZ1,
   FRM_LD_ORNGMISFEMIGAZ2,
   FRM_LD_ORNGMISFEMIGAZ3,
   FRM_LD_ORNGMISFEMIGAZ4,
   FRM_LD_ORNGMISFEMIGAZALL,
   FRM_LD_LOSTMISFROUGHNSROAD,
   FRM_LD_ORNGPFUENGST,
   FRM_LD_ORNGUNLOCKENGST,
   FRM_LD_ORNGSYNCENGST,
   FRM_LD_ORNGSTRTENGST,
   FRM_LD_SCP_BNEUT,
   FRM_LD_SCG_BNEUT,
   FRM_LD_ORNG_BNEUT,
   FRM_LD_ENGOILOVERHEAT,
   FRM_LD_DFTOBJEEP,
   FRM_LD_COH_EEPREINIT,
   FRM_LD_COH_EEPPWRL,
   FRM_LD_ADPAREFFEGRVLVLIM,
   FRM_LD_ADPAREFFTHROFS1LIM,
   FRM_LD_ADPAREFFTHROFS2LIM,
   FRM_LD_ADPAREFFTHROFS3LIM,
   FRM_LD_ADPAREFFTHROFSLIM,
   FRM_LD_ADPCLSEXOFSLIM,
   FRM_LD_ADPINJOFSLIM,
   FRM_LD_ADPIVSINJCONLIM,
   FRM_LD_ADPOPINOFSLIM,
   FRM_LD_ADPSLOPINJCONLIM,
   FRM_LD_ORNGINTR,
   FRM_LD_ORNG_CAT,
   FRM_LD_ORNG_CATAPV,
   FRM_LD__IBATTMAXCKG,
   FRM_LD__IBATTMES,
   FRM_LD__RBATTSOC,
   FRM_LD__RESBATTIT,
   FRM_LD__TBATTMES,
   FRM_LD__UBATTMES,
   FRM_LD__UBATTMINCKG,
   FRM_LD__UBATTOC,
   FRM_LD__UBATTRSTRT,
   FRM_LD__UBATTSTRT,
   FRM_LD_DFTSENR_ACCP,
   FRM_LD_OC_BINHCRKALTHW,
   FRM_LD_LO_UBATTSPC,
   FRM_LD_ORNG_VMES4,
   FRM_LD_ORNG_VMES4_SFTY,
   FRM_LD_ABSESPMUTE,
   FRM_LD_BSIMUTE,
   FRM_LD_BUSOFF,
   FRM_LD_BVAMUTE,
   FRM_LD_CAVMUTE,
   FRM_LD_DIRAMUTE,
   FRM_LD_DMTRMUTE,
   FRM_LD_ECMMUTE,
   FRM_LD_F305COH,
   FRM_LD_F305LENGTH,
   FRM_LD_F305LOST,
   FRM_LD_F305P537INVLD,
   FRM_LD_F305P538INVLD,
   FRM_LD_F30DLENGTH,
   FRM_LD_F30DLOST,
   FRM_LD_F30DP263INVLD,
   FRM_LD_F30DP264INVLD,
   FRM_LD_F30DP265INVLD,
   FRM_LD_F30DP266INVLD,
   FRM_LD_F329COH,
   FRM_LD_F329LENGTH,
   FRM_LD_F329LOST,
   FRM_LD_F329P445INVLD,
   FRM_LD_F329PROCFAILED,
   FRM_LD_F349COH,
   FRM_LD_F349INVLD,
   FRM_LD_F349LENGTH,
   FRM_LD_F349LOST,
   FRM_LD_F349P007INVLD,
   FRM_LD_F349P055INVLD,
   FRM_LD_F349P440INVLD,
   FRM_LD_F349PROCFAILED,
   FRM_LD_F34DCOH,
   FRM_LD_F34DLENGTH,
   FRM_LD_F34DLOST,
   FRM_LD_F34DPM1413INVLD,
   FRM_LD_F34DPROCFAILED,
   FRM_LD_F38DCOH,
   FRM_LD_F38DLENGTH,
   FRM_LD_F38DLOST,
   FRM_LD_F38DP010INVLD,
   FRM_LD_F38DP052INVLD,
   FRM_LD_F38DPROCFAILED,
   FRM_LD_F3ADCOH,
   FRM_LD_F3ADLENGTH,
   FRM_LD_F3ADLOST,
   FRM_LD_F3C9COH,
   FRM_LD_F3C9LENGTH,
   FRM_LD_F3C9LOST,
   FRM_LD_F3C9P291INVLD,
   FRM_LD_F3C9P363INVLD,
   FRM_LD_F3C9P364INVLD,
   FRM_LD_F3C9P482INVLD,
   FRM_LD_F3C9P483INVLD,
   FRM_LD_F3C9PROCFAILED,
   FRM_LD_F3CDCOH,
   FRM_LD_F3CDLENGTH,
   FRM_LD_F3CDLOST,
   FRM_LD_F3CDP225INVLD,
   FRM_LD_F3CDP319INVLD,
   FRM_LD_F3CDP515INVLD,
   FRM_LD_F412LENGTH,
   FRM_LD_F412LOST,
   FRM_LD_F412P040INVLD,
   FRM_LD_F432COH,
   FRM_LD_F432INVLD,
   FRM_LD_F432LENGTH,
   FRM_LD_F44DCOH,
   FRM_LD_F44DFP0535INVLD,
   FRM_LD_F44DLENGTH,
   FRM_LD_F44DLOST,
   FRM_LD_F44DP330INVLD,
   FRM_LD_F44DP331INVLD,
   FRM_LD_F44DP354INVLD,
   FRM_LD_F489COH,
   FRM_LD_F489LENGTH,
   FRM_LD_F489LOST,
   FRM_LD_F489P102INVLD,
   FRM_LD_F489P218INVLD,
   FRM_LD_F489P254INVLD,
   FRM_LD_F492LENGTH,
   FRM_LD_F492LOST,
   FRM_LD_F495LENGTH,
   FRM_LD_F495LOST,
   FRM_LD_F4B2LENGTH,
   FRM_LD_F4B2LOST,
   FRM_LD_F4D2LENGTH,
   FRM_LD_F4D2LOST,
   FRM_LD_F4F2COH,
   FRM_LD_F4F2LENGTH,
   FRM_LD_F4F2LOST,
   FRM_LD_F4F2P429INVLD,
   FRM_LD_F4F2P434INVLD,
   FRM_LD_F4F2P437INVLD,
   FRM_LD_F4F2P438INVLD,
   FRM_LD_F4F2P490INVLD,
   FRM_LD_F4F2P491INVLD,
   FRM_LD_F4F2P492INVLD,
   FRM_LD_F50DLENGTH,
   FRM_LD_F50DLOST,
   FRM_LD_F50ECOH1,
   FRM_LD_F50ECOH2,
   FRM_LD_F50ECOH3,
   FRM_LD_F50ELENGTH,
   FRM_LD_F50ELOST,
   FRM_LD_F50EP046INVLD,
   FRM_LD_F50EP210INVLD,
   FRM_LD_F50EPM1386INVLD,
   FRM_LD_F532COH,
   FRM_LD_F532LENGTH,
   FRM_LD_F532LOST,
   FRM_LD_F532PM1414INVLD,
   FRM_LD_F532PM1415INVLD,
   FRM_LD_F532PM1416INVLD,
   FRM_LD_F552BISP015INVLD,
   FRM_LD_F552BISP325INVLD,
   FRM_LD_F552BISP326INVLD,
   FRM_LD_F552COH,
   FRM_LD_F552LENGTH,
   FRM_LD_F552LOST,
   FRM_LD_F552P255INVLD,
   FRM_LD_F552P256INVLD,
   FRM_LD_F552P257INVLD,
   FRM_LD_F572COH,
   FRM_LD_F572LENGTH,
   FRM_LD_F572LOST,
   FRM_LD_F572PM1360INVLD,
   FRM_LD_F57CCOH,
   FRM_LD_F57CLENGTH,
   FRM_LD_F57CLOST,
   FRM_LD_F57CPM1418INVLD,
   FRM_LD_F592COH,
   FRM_LD_F592LENGTH,
   FRM_LD_F592LOST,
   FRM_LD_F592P272INVLD,
   FRM_LD_F592P273INVLD,
   FRM_LD_F592P349INVLD,
   FRM_LD_F592P418INVLD,
   FRM_LD_F592P419INVLD,
   FRM_LD_F592P420INVLD,
   FRM_LD_F592P421INVLD,
   FRM_LD_F5B2COH,
   FRM_LD_F5B2LENGTH,
   FRM_LD_F5B2LOST,
   FRM_LD_F5B2P146INVLD,
   FRM_LD_F612COH,
   FRM_LD_F612LENGTH,
   FRM_LD_F612LOST,
   FRM_LD_F612P260INVLD,
   FRM_LD_F612P436INVLD,
   FRM_LD_F612P705INVLD,
   FRM_LD_F7F2COH,
   FRM_LD_F7F2LENGTH,
   FRM_LD_F7F2LOST,
   FRM_LD_F7F2P015BISINVLD,
   FRM_LD_F7F2P146BISINVLD,
   FRM_INVALID_LD_ID,
   FRM_LD_IDCBLBYCND,
   FRM_LD_SCG_OILLVLACQ,
   FRM_LD_SCP_OILLVLACQ,
   FRM_LD_GRD_OILLVLACQ,
   FRM_LD_SCP_POILMES,
   FRM_LD_SCG_POILMES,
   FRM_LD_SFTYCHKPT_PFCMNG,
   FRM_LD_SCP_PFUACQ,
   FRM_LD_SCG_PFUACQ,
   FRM_LD_COH_PFUACQ,
   FRM_LD_OILPRSSSUPORNG,
   FRM_LD_OILPRSSSDWNORNG,
   FRM_LD_AIRPRSSEXTSUP,
   FRM_LD_AIRPRSSEXTSDWN,
   FRM_LD_USTHRPRSSSUP,
   FRM_LD_USTHRPRSSSDOWN,
   FRM_LD_SCG_PROPFUPMP,
   FRM_LD_SCP_PROPFUPMP,
   FRM_LD_OC_PROPFUPMP,
   FRM_LD_MAP_PROPFUPMP,
   FRM_LD_GRAVSCP_PROPFUPMP,
   FRM_LD_FRQ_PROPFUPMP,
   FRM_LD_CLUDMGAFTS,
   FRM_LD_PWRLMRK,
   FRM_LD_STUCK_MAINRLY,
   FRM_LD_STUCK_PWRRLY,
   FRM_LD_SCP_PWRRLY,
   FRM_LD_OC_PWRRLY,
   FRM_LD_SCG_PWRRLY,
   FRM_LD_ORNG_VMES1,
   FRM_LD_ORNG_VMES1_SFTY,
   FRM_LD_ORNG_VMES2,
   FRM_LD_ORNG_VMES2_SFTY,
   FRM_LD_ORNG_VMES3,
   FRM_LD_ORNG_VMES3_SFTY,
   FRM_LD_INV_CALID,
   FRM_LD_SCP_PRELBRKASI,
   FRM_LD_SCG_PRELBRKASI,
   FRM_LD_GRD_PRELBRKASI,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_LD_ANTIBOIL,
   FRM_LD_ARDELTACORLIM,
   FRM_LD_BLT,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_LD_COSYSDFCT,
   FRM_LD_CORLOSS,
   FRM_LD_CORSPCUR,
   FRM_LD_CUTREQ,
   FRM_LD_DFTONOFFHI,
   FRM_LD_DFTONOFFLO,
   FRM_LD_DFTOSCCFM,
   FRM_LD_DFTREGHI,
   FRM_LD_DFTREGHICFM,
   FRM_LD_DFTREGLO,
   FRM_LD_DFTREGLOCFM,
   FRM_LD_FSFBLOCKCLS,
   FRM_LD_FSFBLOCKOP,
   FRM_INVALID_LD_ID,
   FRM_LD_LGENGRSTRTINH,
   FRM_LD_MAINWKUDISRD,
   FRM_LD_MAINWKUINCST,
   FRM_LD_ORNGCUTOFFREQ,
   FRM_LD_ORNGGCCLU,
   FRM_LD_ORNGGCMINCLU,
   FRM_LD_ORNGGCNEUT,
   FRM_LD_ORNGGEARENACLU,
   FRM_LD_ORNGGEARMINCLU,
   FRM_LD_ORNGGEARNEUT,
   FRM_LD_ORNGHIDRAGRED,
   FRM_LD_ORNGHINEUT,
   FRM_LD_ORNGLODRAGRED,
   FRM_LD_ORNGLONEUT,
   FRM_LD_ORNGMPLREQ,
   FRM_LD_ORNGSTOPREQ,
   FRM_LD_OBSADP,
   FRM_LD_PRESMESFRZ,
   FRM_LD_PRESTOHI,
   FRM_LD_PRESTOLO,
   FRM_LD_PROTADP,
   FRM_LD_RCDLINESCG,
   FRM_LD_RATCONVTRACLC,
   FRM_LD_SFTYORNGAMT,
   FRM_LD_SFTYORNGAT,
   FRM_LD_SPDVEHCLC,
   FRM_LD_STAACVTHD1,
   FRM_LD_STAACVTHD2,
   FRM_LD_STACMD,
   FRM_LD_STACMDINFO,
   FRM_LD_STAELCMD,
   FRM_LD_STUCKMEC,
   FRM_LD_TCOBLOCK,
   FRM_LD_TCOOVERESTIM,
   FRM_LD_TCOSLOWRISE,
   FRM_LD_TCOUNDESTIM,
   FRM_LD_TCOWARN,
   FRM_LD_THERMOSTUCKCLS,
   FRM_LD_THERMOSTUCKOP,
   FRM_LD_TQALT,
   FRM_LD_VSLIM,
   FRM_LD_VSLIMBODY,
   FRM_LD_VSMAX,
   FRM_LD_VSMAXP,
   FRM_LD_VSREG,
   FRM_LD_VSREGBODY,
   FRM_LD_VSREGVEH,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_LD_TQALTRV,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_LD_RVSGEAR,
   FRM_LD_NOANSWCTLUNIT,
   FRM_LD_WRGANSWCTLUNIT,
   FRM_LD_IMMOCODNOTREAD,
   FRM_LD_COMSPI_CPU,
   FRM_LD_COMTOUT_CPU,
   FRM_LD_SYNCMON_CPU,
   FRM_LD_ACCP_CPU,
   FRM_LD_THR_CPU,
   FRM_LD_CLK_CPU,
   FRM_LD_ALGO_CPU,
   FRM_LD_COMSPI_CPUSFTY,
   FRM_LD_COMTOUT_CPUSFTY,
   FRM_LD_SYNCMON_CPUSFTY,
   FRM_LD_CLK_CPUSFTY,
   FRM_LD_ALGO_CPUSFTY,
   FRM_LD_CKSROM_CPUSFTY,
   FRM_LD_DEGMOD_CPUSFTY,
   FRM_LD_IRVSTT,
   FRM_LD_RVLIH,
   FRM_LD_IRVVSCTL,
   FRM_LD_INHCHKINITSFTY,
   FRM_LD_DRVTRA,
   FRM_LD_INHENGSTOPSTT,
   FRM_LD_IRVECU,
   FRM_LD_IRVEM,
   FRM_LD_SCP_PSPGPRES,
   FRM_LD_SCG_PSPGPRES,
   FRM_LD_COH_STRTLOCK,
   FRM_LD_SCP_DML,
   FRM_LD_OC_DML,
   FRM_LD_SCG_DML,
   FRM_LD_BLOCK_STRTR,
   FRM_LD_STUCKOP_INJRCYL1,
   FRM_LD_STUCKOP_INJRCYL2,
   FRM_LD_STUCKOP_INJRCYL3,
   FRM_LD_STUCKOP_INJRCYL4,
   FRM_LD_IUPRSYNT1,
   FRM_LD_IUPRSYNT2,
   FRM_LD_IUPRSYNT3,
   FRM_LD_ENGSPDCOHCK,
   FRM_LD_ENGSPDCOHINCM,
   FRM_LD_ENGSPDCOHEXCM,
   FRM_LD_NOSIGCK,
   FRM_LD_SIGLOSSCK,
   FRM_LD_NOSIGINCM,
   FRM_LD_SIGLOSSINCM,
   FRM_LD_NOSIGEXCM,
   FRM_LD_SIGLOSSEXCM,
   FRM_LD_NOGAP_CKSTS,
   FRM_LD_TOOTHCOH_CKSTS,
   FRM_LD_HITOOTHCOH_CKSTS,
   FRM_LD_COH_EXCM,
   FRM_LD_COH_INCM,
   FRM_LD_DISTSIG,
   FRM_LD_SCG_TECUACQ,
   FRM_LD_SCP_TECUACQ,
   FRM_LD_INV_VARCOD,
   FRM_LD_OVLD_THRCMD,
   FRM_LD_CPT_THRCMD,
   FRM_LD_COHPOSNSNSR,
   FRM_LD_SCPPOSNSNSR1,
   FRM_LD_SCGPOSNSNSR1,
   FRM_LD_SCPPOSNSNSR2,
   FRM_LD_SCGPOSNSNSR2,
   FRM_LD_DFTSENR_THR,
   FRM_LD_ORNGSERVO,
   FRM_LD_ORNGSERVODIFPOS,
   FRM_LD_ORNGSERVODIFNEG,
   FRM_LD_READPININHTHR_CPU,
   FRM_LD_INHTHR_CPUSFTY,
   FRM_LD_ORNGSFTYDFTLIH,
   FRM_LD_ELDIAGINHPIN0_CPU,
   FRM_LD_ELDIAGINHPIN1_CPU,
   FRM_LD_MCPRAMTEST_CPU,
   FRM_LD_MCPFLASHCKS_CPU,
   FRM_LD_MCWCKSCALC_CPU,
   FRM_LD_MCWINITSFTYRSLT_CPU,
   FRM_LD_MCWFCTTEST_CPU,
   FRM_LD_ENDSTOPREQ1,
   FRM_LD_ENDSTOPREQ2,
   FRM_LD_CLSIDLCTL,
   FRM_LD_LIHREQ1,
   FRM_LD_LIHREQ2,
   FRM_LD_OVLDTHERMOTHR,
   FRM_LD_ORNG_TIENGSTOP,
   FRM_LD_COH_TIENGSTOP,
   FRM_INVALID_LD_ID,
   FRM_INVALID_LD_ID,
   FRM_LD_ORNGHITOILESTIM,
   FRM_LD_SCP_TRBWAPMP,
   FRM_LD_SCG_TRBWAPMP,
   FRM_LD_OC_TRBWAPMP,
   FRM_LD_OC_UUPLS,
   FRM_LD_SCG_UUPLS,
   FRM_LD_SCP_UUPLS,
   FRM_LD_COH_SPDVEH,
   FRM_LD_ORNG_SPDVEH,
   FRM_LD_ORNGSPDVLVACTEX,
   FRM_LD_ORNGSHIFTVLVACTEX,
   FRM_LD_MISSTOOTHVLVACTEX,
   FRM_LD_TDCDIAGVLVACTEX,
   FRM_LD_CLNERRVLVACTEX,
   FRM_LD_LOVLVACTEXDRV,
   FRM_LD_HIVLVACTEXDRV,
   FRM_LD_LRNENDSTOPVLVACTEX,
   FRM_LD_ENDSTOPOLDVLVACTEX,
   FRM_LD_LRNFAILIMVLVACTEX,
   FRM_LD_OLDLRNVLVACTEX,
   FRM_LD_DFTCVLVACTEX,
   FRM_LD_ORNGCVLVACTEX,
   FRM_LD_CMDCVLVACTEX,
   FRM_LD_SLOWC1VLVACTEX,
   FRM_LD_SLOWC2VLVACTEX,
   FRM_LD_DFTHVLVACTEX,
   FRM_LD_ORNGHVLVACTEX,
   FRM_LD_CMDHVLVACTEX,
   FRM_LD_STUCKHVLVACTEX,
   FRM_LD_SLOWH1VLVACTEX,
   FRM_LD_STUCKH1VLVACTEX,
   FRM_LD_SLOWH2VLVACTEX,
   FRM_LD_STUCKH2VLVACTEX,
   FRM_LD_STUCKH3VLVACTEX,
   FRM_LD_DIFPOS1VLVACTEX,
   FRM_LD_DIFPOS2VLVACTEX,
   FRM_LD_DIFNEG1VLVACTEX,
   FRM_LD_DIFNEG2VLVACTEX,
   FRM_LD_SERVOERRVLVACTEX,
   FRM_LD_IMAXVLVACTEX,
   FRM_LD_ORNGSPDVLVACTIN,
   FRM_LD_ORNGSHIFTVLVACTIN,
   FRM_LD_MISSTOOTHVLVACTIN,
   FRM_LD_TDCDIAGVLVACTIN,
   FRM_LD_CLNERRVLVACTIN,
   FRM_LD_LOVLVACTINDRV,
   FRM_LD_HIVLVACTINDRV,
   FRM_LD_LRNENDSTOPVLVACTIN,
   FRM_LD_ENDSTOPOLDVLVACTIN,
   FRM_LD_LRNFAILIMVLVACTIN,
   FRM_LD_OLDLRNVLVACTIN,
   FRM_LD_DFTCVLVACTIN,
   FRM_LD_ORNGCVLVACTIN,
   FRM_LD_CMDCVLVACTIN,
   FRM_LD_SLOWC1VLVACTIN,
   FRM_LD_SLOWC2VLVACTIN,
   FRM_LD_DFTHVLVACTIN,
   FRM_LD_ORNGHVLVACTIN,
   FRM_LD_CMDHVLVACTIN,
   FRM_LD_STUCKHVLVACTIN,
   FRM_LD_SLOWH1VLVACTIN,
   FRM_LD_STUCKH1VLVACTIN,
   FRM_LD_SLOWH2VLVACTIN,
   FRM_LD_STUCKH2VLVACTIN,
   FRM_LD_STUCKH3VLVACTIN,
   FRM_LD_DIFPOS1VLVACTIN,
   FRM_LD_DIFPOS2VLVACTIN,
   FRM_LD_DIFNEG1VLVACTIN,
   FRM_LD_DIFNEG2VLVACTIN,
   FRM_LD_SERVOERRVLVACTIN,
   FRM_LD_IMAXVLVACTIN,
   FRM_LD_SCP_VSSNWACVREQ,
   FRM_LD_SCG_VSSNWACVREQ,
   FRM_LD_HI_WGCCMD,
   FRM_LD_LO_WGCCMD,
   FRM_LD_F432LOST,
   FRM_LD_ZZEND_BIDON
};


