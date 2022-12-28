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
/* !File            : FRM_0.C                                                 */
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
/*   1 / FRM_vidInit                                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5447829 / 01                                        */
/* !Reference   : PTS_DOC_5447824 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#066883                                         */
/* !OtherRefs   : VEMS V02 ECU#067073                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FRM/FRM_0.c_v                   $*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   26 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "FRM.h"
#include "FRM_L.h"
#include "FRM_im.h"
#include "FRM_calibration.h"
#include "FRM_21.h"
#include "GDFRMDef.h"
#include "GD_API.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRM_vidInit                                                */
/* !Description :  Initialization of FRM module                               */
/* !Number      :  FCT0.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 EventId, argin*/
/*  uint8 *EventStatusExtended);                                              */
/*  extf argret void FRM_vidF02_FidMng_F02_AcvTable(argin uint16 u16LDIndex); */
/*  input boolean FRM_abAuthTypCc_NameVar_C[399];                             */
/*  input boolean FRM_abDftTypCc_NameVar[399];                                */
/*  output uint8 FRM_au8DU[400];                                              */
/*  output boolean FRM_abRawTypAcvOptRvCcDd[466];                             */
/*  output boolean FRM_abDftTypCc_NameVar[399];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRM_vidInit(void)
{
   sint32         s32LocalIndex;
   Std_ReturnType udtLocalStatus;
   uint8          u8LocalEventStatusExtended;
   boolean        bLocalESE;

   /* FRM_au8DU */
   for (s32LocalIndex = 0; s32LocalIndex < GD_DFT_NB; s32LocalIndex++)
   {
      udtLocalStatus = Dem_GetEventStatus((uint16)s32LocalIndex,
                                          &u8LocalEventStatusExtended);
      if (udtLocalStatus == E_OK)
      {
         bLocalESE = GD_bBitRead(u8LocalEventStatusExtended,0);
         if (bLocalESE == 1)
         {
            FRM_au8DU[s32LocalIndex] = (FRM_u8SNG_DFT_TRUE);
            bLocalESE = GD_bBitRead(u8LocalEventStatusExtended, 2);
            if (bLocalESE == 1)
            {
               FRM_au8DU[s32LocalIndex] = ((FRM_u8OBD_DFT_TRUE)
                                          |(FRM_u8SNG_DFT_TRUE));
            }
         }
         else
         {
            FRM_au8DU[s32LocalIndex] = (FRM_u8SNG_DFT_FALSE);
            bLocalESE = GD_bBitRead(u8LocalEventStatusExtended, 2);
            if (bLocalESE == 1)
            {
               FRM_au8DU[s32LocalIndex] =(FRM_u8OBD_DFT_TRUE);
            }
         }
      }
   }

   for (s32LocalIndex = 0; s32LocalIndex < FRM_FRM_NB; s32LocalIndex++)
   {
      FRM_abRawTypAcvOptRvCcDdCnt[s32LocalIndex] =0;
      FRM_abRawTypAcvOptRvCcDd[s32LocalIndex] = FALSE;
   }

   /* FRM_abDftTypCc_NameVar */
   for (s32LocalIndex = 0; s32LocalIndex < FRM_LD_NB; s32LocalIndex++)
   {
      if (TRUE == FRM_abAuthTypCc_NameVar_C[s32LocalIndex])
      {
         FRM_avidF02_FidMng_F01_FRM_RawDft[s32LocalIndex]();
         if (FRM_abDftTypCc_NameVar[s32LocalIndex] == TRUE)
         {
            FRM_vidF02_FidMng_F02_AcvTable((uint16)s32LocalIndex);
         }
      }
      else
      {
         FRM_abDftTypCc_NameVar[s32LocalIndex] = FALSE;
      }
   }

}

/*------------------------------- end of file --------------------------------*/