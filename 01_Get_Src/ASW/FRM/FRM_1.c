/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FRM                                                     */
/* !Description     : Function Recovery Manager                               */
/*                                                                            */
/* !Module          : FRM                                                     */
/* !Description     : FRM module                                              */
/*                                                                            */
/* !File            : FRM_1.C                                                 */
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
/*   1 / FRM_vidF01_PrmDft_Init                                               */
/*   2 / FRM_vidDemInit                                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5447829 / 01                                        */
/* !Reference   : PTS_DOC_5447824 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#066883                                         */
/* !OtherRefs   : VEMS V02 ECU#067073                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "FRM.h"
#include "FRM_L.h"
#include "FRM_im.h"
#include "FRM_21.h"
#include "FRM_calibration.h"
#include "GDFRMDef.h"
#include "GD_API.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRM_vidF01_PrmDft_Init                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRM_u16convDftIdtoLDId();                                */
/*  extf argret void FRM_vidF02_FidMng_F02_AcvTable(argin uint16 u16LDIndex); */
/*  input boolean FRM_abDftTypCc_NameVar[399];                                */
/*  input boolean FRM_abAuthTypCc_NameVar_C[399];                             */
/*  output uint8 FRM_au8DU[400];                                              */
/*  output boolean FRM_abDftTypCc_NameVar[399];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRM_vidF01_PrmDft_Init
(
   uint16 u16Index,
   uint8 u8StatusOld,
   uint8 u8Status
)
{
   /* penser a mettre a jour FRM_macro.h quand cette fonction evolue*/

   boolean bLocalGDUDft;
   boolean bLocalGDUDftOld;
   boolean bLocalMajDft;
   boolean bLocalTemp_0;
   uint16  u16localLDIndex;


   bLocalGDUDft = GD_bBitRead(u8Status,0);
   bLocalGDUDftOld = GD_bBitRead(u8StatusOld,0);

   bLocalMajDft = 0;
   if  (  (bLocalGDUDft == TRUE)
       && (bLocalGDUDftOld == FALSE))
   {
      FRM_au8DU[u16Index] = FRM_u8SNG_DFT_TRUE;
      bLocalMajDft = 1;
   }
   else
   {
      if (  (bLocalGDUDft == FALSE)
         && (bLocalGDUDftOld == TRUE))
      {
         FRM_au8DU[u16Index] = FRM_u8SNG_DFT_FALSE;
         bLocalMajDft = 1;
      }
   }

   u16localLDIndex = FRM_u16convDftIdtoLDId(u16Index);
   if (  (bLocalMajDft == 1)
      && (u16localLDIndex != FRM_INVALID_LD_ID))
   {
      /* FRM_abDftTypCc_NameVar */
      bLocalTemp_0 = FRM_abDftTypCc_NameVar[u16localLDIndex];
      if (TRUE == FRM_abAuthTypCc_NameVar_C[u16localLDIndex])
      {
         FRM_avidF02_FidMng_F01_FRM_RawDft[u16localLDIndex]();
      }
      else
      {
         FRM_abDftTypCc_NameVar[u16localLDIndex] = FALSE;
      }

      if (bLocalTemp_0 != FRM_abDftTypCc_NameVar[u16localLDIndex])
      {
         FRM_vidF02_FidMng_F02_AcvTable(u16localLDIndex);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRM_vidDemInit                                             */
/* !Description :  Re_initialization of FRM module.                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 FRM_au8DU[400];                                              */
/*  output boolean FRM_abDftTypCc_NameVar[399];                               */
/*  output boolean FRM_abRawTypAcvOptRvCcDd[466];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRM_vidDemInit(void)
{
   sint32         s32LocalIndex;


   for (s32LocalIndex = 0; s32LocalIndex < GD_DFT_NB; s32LocalIndex++)
   {
      FRM_au8DU[s32LocalIndex] = FRM_u8SNG_DFT_FALSE;
   }

   /*CALL_FrmRstDft */
   for (s32LocalIndex = 0; s32LocalIndex < FRM_LD_NB; s32LocalIndex++)
   {
      /*FRM_bDft(u16LDIndex) = 0*/
      FRM_abDftTypCc_NameVar[s32LocalIndex] = FALSE;
   }
   for (s32LocalIndex = 0 ; s32LocalIndex < FRM_FRM_NB; s32LocalIndex++)
   {
      FRM_abRawTypAcvOptRvCcDdCnt[s32LocalIndex] = 0;
      FRM_abRawTypAcvOptRvCcDd[s32LocalIndex] = FALSE;
   }
}

/*------------------------------- end of file --------------------------------*/