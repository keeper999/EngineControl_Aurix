/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GD                                                      */
/* !Description     : GD Component                                            */
/*                                                                            */
/* !Module          : GD                                                      */
/* !Description     : GD ARCHITECTURE                                         */
/*                                                                            */
/* !File            : GD_SCH2.C                                               */
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
/*   1 / GD_SdlFast                                                           */
/*   2 / GD_EveRxn772                                                         */
/*   3 / GD_EveRxn55F                                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5447643 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#066729                                         */
/* !OtherRefs   : VEMS V02 ECU#068131                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GD_SCH2.c_v                  $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   10 Feb 2014 $*/
/* $Author::   mbenfrad                               $$Date::   10 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GD.h"
#include "GD_L.h"
#include "GDEXTINT.h"
#include "GDU.h"
#include "WUC.h"
#include "DC.h"
#include "GOBD.h"
#include "GMIL.h"
#include "RC01.h"
#include "INDICOBD.h"
#include "IUPRFRZ.h"
#include "IUPRSPCDEN.h"
#include "IUPRRATIO.h"
#include "MEM.h"
#include "JDDISCANIF.h"
#include "STATUSOFDTC.h"
#include "DIAGTAB.h"
#include "JDD.h"
#include "IUPRGENDEN.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlFast                                                 */
/* !Description :  Event receipt of frame 55F                                 */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_SdlFast_GJDD();                                       */
/*  extf argret void IUPRGENDEN_vidMngEveSdlFast();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_SdlFast                                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlFast(void)
{
   GD_SdlFast_GJDD();
   IUPRGENDEN_vidMngEveSdlFast();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRxn772                                               */
/* !Description :  Event receipt of frame 772                                 */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRxn772_GJDD();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRxn772                                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRxn772(void)
{
   GD_EveRxn772_GJDD();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRxn55F                                               */
/* !Description :  Event receipt of frame 772                                 */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRxn55F_GJDD();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRxn55F                                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRxn55F(void)
{
   GD_EveRxn55F_GJDD();
}
/*------------------------------end of file-----------------------------------*/
