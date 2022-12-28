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
/* !File            : FRM_22.c                                                */
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
/*   1 / FRM_vidF02_FidMng_F02_AcvTable                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5447829 / 01                                        */
/* !Reference   : PTS_DOC_5447824 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#066883                                         */
/* !OtherRefs   : VEMS V02 ECU#067073                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FRM/FRM_22.c_v                  $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   26 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "Std_Limits.h"
#include "FRM.h"
#include "FRM.h"
#include "FRM_L.h"
#include "MATHSRV.h"
#include "FRM_im.h"
#include "FRM_Calibration.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRM_vidF02_FidMng_F02_AcvTable                             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean FRM_abDftTypCc_NameVar[399];                                */
/*  input uint16 FRM_au16LD_To_FRM_NbFRM_C[399];                              */
/*  input uint16 FRM_au16LD_To_FRM_PosDeb_C[399];                             */
/*  input uint16 FRM_u16CrossNb;                                              */
/*  input uint16 FRM_au16LD_To_FRM_Tab_C[9320];                               */
/*  output boolean FRM_abRawTypAcvOptRvCcDd[466];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRM_vidF02_FidMng_F02_AcvTable
(
   uint16 u16LDIndex
)
{
   boolean bLocalRaisingEdge; /* Front montant */
   uint16  u16LocalIndex;
   uint16  u16LocalPosIndex;
   uint16  u16LocalFRMIndex;
   uint32  u32LocalCalc;


   if (TRUE == FRM_abDftTypCc_NameVar[u16LDIndex])
   {
      bLocalRaisingEdge = TRUE;
   }
   else
   {
      bLocalRaisingEdge = FALSE;
   }

   for (u16LocalIndex = 0;
        u16LocalIndex < FRM_au16LD_To_FRM_NbFRM_C[u16LDIndex];
        u16LocalIndex++)
   {
      u16LocalPosIndex
         = (uint16) (FRM_au16LD_To_FRM_PosDeb_C[u16LDIndex] + u16LocalIndex);

      if (u16LocalPosIndex < FRM_u16CrossNb)
      {
         u16LocalFRMIndex = FRM_au16LD_To_FRM_Tab_C[u16LocalPosIndex];

         if (u16LocalFRMIndex < FRM_FRM_NB)
         {
            if (TRUE == bLocalRaisingEdge)
            {
               FRM_abRawTypAcvOptRvCcDd[u16LocalFRMIndex] = TRUE;
               u32LocalCalc = FRM_abRawTypAcvOptRvCcDdCnt[u16LocalFRMIndex] + 1;
               FRM_abRawTypAcvOptRvCcDdCnt[u16LocalFRMIndex] =
                  (uint16)MATHSRV_udtMIN(u32LocalCalc, UINT16_MAX);
            }
            else
            {
               if (FRM_abRawTypAcvOptRvCcDdCnt[u16LocalFRMIndex] <= 1)
               {
                  FRM_abRawTypAcvOptRvCcDdCnt[u16LocalFRMIndex] = 0;
                  FRM_abRawTypAcvOptRvCcDd[u16LocalFRMIndex] = FALSE;
               }
               else
               {
                  FRM_abRawTypAcvOptRvCcDdCnt[u16LocalFRMIndex]
                        = (uint16)(FRM_abRawTypAcvOptRvCcDdCnt[u16LocalFRMIndex]
                                   - 1);
               }
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
}

/*------------------------------- end of file --------------------------------*/