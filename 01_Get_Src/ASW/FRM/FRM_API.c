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
/* !File            : FRM_API.C                                               */
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
/*   1 / Fim_DemTriggerOnEventStatus                                          */
/*   2 / Fim_GetFunctionPermission                                            */
/*   3 / Fim_DemInit                                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5447829 / 01                                        */
/* !Reference   : PTS_DOC_5447824 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#066883                                         */
/* !OtherRefs   : VEMS V02 ECU#067073                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "FRM.h"
#include "FRM_L.h"
#include "FRM_IM.h"
#include "FRM_API.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fim_DemTriggerOnEventStatus                                */
/* !Description :  Update the GAR upon changes of the event status            */
/* !Number      :  API.3                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  PTS_R_5447824_001.01                                       */
/*                 PTS_R_5447824_002.01                                       */
/*                 PTS_R_5447824_003.01                                       */
/*                 PTS_R_5447824_004.01                                       */
/*                 PTS_R_5447829_001.01                                       */
/*                 PTS_R_5447829_002.01                                       */
/*                 PTS_R_5447829_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRM_vidF01_PrmDft_Init(argin uint16 u16Index, argin uint8*/
/*  u8StatusOld, argin uint8 u8Status);                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fim_DemTriggerOnEventStatus
(
   uint16 u16DftIdx,
   uint8 u8StatusOld,
   uint8 u8Status
)
{
   FRM_vidF01_PrmDft_Init(u16DftIdx, u8StatusOld, u8Status);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fim_GetFunctionPermission                                  */
/* !Description :  This function reports the permission state to the          */
/*                 functionality                                              */
/* !Number      :  API.4                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  PTS_R_5447824_001.01                                       */
/*                 PTS_R_5447824_002.01                                       */
/*                 PTS_R_5447824_003.01                                       */
/*                 PTS_R_5447824_004.01                                       */
/*                 PTS_R_5447829_001.01                                       */
/*                 PTS_R_5447829_002.01                                       */
/*                 PTS_R_5447829_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  FRM_vidF03_EnaFid_Idx_Switch(argin uint16     */
/*  u16FRMIndex, argin boolean *bPermission);                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Fim_GetFunctionPermission
(
   uint16 u16FRMIndex,
   boolean* bPermission
)
{
   uint8 u8LocalStatus;
   u8LocalStatus = FRM_vidF03_EnaFid_Idx_Switch(u16FRMIndex, bPermission);
   return(u8LocalStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fim_DemInit                                                */
/* !Description :  This service re-initializes the GAR.                       */
/* !Number      :  API.3                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  PTS_R_5447824_001.01                                       */
/*                 PTS_R_5447824_002.01                                       */
/*                 PTS_R_5447824_003.01                                       */
/*                 PTS_R_5447824_004.01                                       */
/*                 PTS_R_5447829_001.01                                       */
/*                 PTS_R_5447829_002.01                                       */
/*                 PTS_R_5447829_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRM_vidDemInit();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fim_DemInit(void)
{
   FRM_vidDemInit();
}

/*------------------------------- end of file --------------------------------*/