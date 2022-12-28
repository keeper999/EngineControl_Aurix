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
/* !File            : FRM_3.C                                                 */
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
/*   1 / FRM_vidF03_EnaFid_Idx_Switch                                         */
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

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRM_vidF03_EnaFid_Idx_Switch                               */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean ActrTestMng_bInhFRM;                                        */
/*  input boolean FRM_bEnaFid_C;                                              */
/*  input uint8 FRM_au8EnaTypAcvOptRvCcDd_C[466];                             */
/*  input boolean FRM_abRawTypAcvOptRvCcDd[466];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRM_vidF03_EnaFid_Idx_Switch
(
   uint16 u16FRMIndex,
   boolean* bPermission
)
{
   Std_ReturnType udtLocalStatus;

   udtLocalStatus = E_OK;
   if (u16FRMIndex <= FRM_FRM_NB)
   {
      if(TRUE == ActrTestMng_bInhFRM)
      {
         *bPermission = TRUE;
      }
      else
      {
         if (TRUE == FRM_bEnaFid_C)
         {
            switch (FRM_au8EnaTypAcvOptRvCcDd_C[u16FRMIndex])
            {
            case FRM_u8ENA_TYP_ACV_LIBRE :
               *bPermission = !(FRM_abRawTypAcvOptRvCcDd[u16FRMIndex]);
               break;

            case FRM_u8ENA_TYP_ACV_FORCE_TRUE :
               *bPermission = FALSE;
               break;

            case FRM_u8ENA_TYP_ACV_FORCE_FALSE :
               *bPermission = TRUE;
               break;

            default :
               udtLocalStatus = E_NOT_OK;
               SWFAIL_vidSoftwareErrorHook();
               break;
            }
         }
         else
         {
            *bPermission = !(FRM_abRawTypAcvOptRvCcDd[u16FRMIndex]);
         }
      }
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalStatus);
}

/*------------------------------- end of file --------------------------------*/