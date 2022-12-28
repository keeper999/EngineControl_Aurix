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
/* !File            : FRM_SCH.C                                               */
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
/*   1 / Fim_Init                                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5447829 / 01                                        */
/* !Reference   : PTS_DOC_5447824 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#066883                                         */
/* !OtherRefs   : VEMS V02 ECU#067073                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "FRM.h"
#include "FRM_L.h"
#include "FRM_21.h"
#include "GDFRMDef.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fim_Init                                                   */
/* !Number      :  SCH.1                                                      */
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
/*  extf argret void FRM_vidInit();                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fim_Init(void)
{
   FRM_vidInit();
}

/*------------------------------- end of file --------------------------------*/