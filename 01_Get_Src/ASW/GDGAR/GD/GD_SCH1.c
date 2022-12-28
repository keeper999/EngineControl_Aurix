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
/* !File            : GD_SCH1.C                                               */
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
/*   1 / GD_EveRst                                                            */
/*   2 / GD_EveKOn                                                            */
/*   3 / GD_EveCrTR                                                           */
/*   4 / GD_EveRstDft                                                         */
/*   5 / GD_EveKOf                                                            */
/*   6 / GD_EveRstDftObd                                                      */
/*   7 / GD_EveCrTSt                                                          */
/*   8 / GD_SdlSlow                                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5447643 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#066729                                         */
/* !OtherRefs   : VEMS V02 ECU#068131                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GD_SCH1.c_v                  $*/
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
/* !Function    :  GD_EveRst                                                  */
/* !Description :  ECU reset event                                            */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Dem_Init();                                              */
/*  extf argret void GD_EveRst_GDU();                                         */
/*  extf argret void WUC_vidMngEveRst();                                      */
/*  extf argret void DC_vidMngEveRst();                                       */
/*  extf argret void GOBD_vidMngEveRst();                                     */
/*  extf argret void GMIL_vidMngEveRst();                                     */
/*  extf argret void GD_EveRst_Rdy();                                         */
/*  extf argret void GD_EveRst_IndicOBD();                                    */
/*  extf argret void MEM_vidMngEveInit();                                     */
/*  extf argret void GD_EveRst_GJDD();                                        */
/*  extf argret void GD_EveRst_DftLogTx();                                    */
/*  extf argret void GD_EveRst_IuprFrz();                                     */
/*  extf argret void GD_EveRst_IuprGenDen();                                  */
/*  extf argret void IuprSpcDen_EveRst();                                     */
/*  extf argret void GD_EveRst_IuprRatio();                                   */
/*  extf argret void GD_EveRst_StatusOfDTC();                                 */
/*  extf argret void GD_EveRst_DiagTab();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst                                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst(void)
{
   Dem_Init();
   GD_EveRst_GDU();
   /* GD_EveRst_G_GOBD*/
   WUC_vidMngEveRst();
   DC_vidMngEveRst();
   GOBD_vidMngEveRst();
   GMIL_vidMngEveRst();
   GD_EveRst_Rdy();
   GD_EveRst_IndicOBD();
   /* GD_EveRst_G_GOBD*/
   MEM_vidMngEveInit();
   /*GD_EveRst_JDD*/
   GD_EveRst_GJDD();
   GD_EveRst_DftLogTx();
   /*GD_EveRst_JDD*/
   GD_EveRst_IuprFrz();
   GD_EveRst_IuprGenDen();
   IuprSpcDen_EveRst();
   GD_EveRst_IuprRatio();
   GD_EveRst_StatusOfDTC();
   GD_EveRst_DiagTab();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveKOn                                                  */
/* !Description :  Ignition key's transit from ON to OFF                      */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveKOn_GDU();                                         */
/*  extf argret void GOBD_vidMngEveKOn();                                     */
/*  extf argret void MEM_vidMngEveKeyOn();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveKOn                                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveKOn(void)
{
   GD_EveKOn_GDU();
   GOBD_vidMngEveKOn();
   MEM_vidMngEveKeyOn();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveCrTR                                                 */
/* !Description :  Crank To Run event                                         */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidMngEveCrTR();                                      */
/*  extf argret void GD_EveCrTR_IndicOBD();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveCrTR                                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveCrTR(void)
{
   DC_vidMngEveCrTR();
   GD_EveCrTR_IndicOBD();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft                                               */
/* !Description :  After-sale tool request for a clear failure                */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRstDft_GDU();                                      */
/*  extf argret void GD_EveRstDft_DC();                                       */
/*  extf argret void WUC_vidMngEvePrmClrAfts();                               */
/*  extf argret void GOBD_vidMngEveRstDft();                                  */
/*  extf argret void GD_EveRstDft_Rdy();                                      */
/*  extf argret void GD_EveRstDft_IndicOBD();                                 */
/*  extf argret void MEM_vidMngEveRstDft();                                   */
/*  extf argret void GD_EveRstDft_GJDD();                                     */
/*  extf argret void GD_EveRstDft_StatusOfDTC();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDft                                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft(void)
{
   GD_EveRstDft_GDU();
   /*GD_EveRstDft_G_GOBD*/
   GD_EveRstDft_DC();
   WUC_vidMngEvePrmClrAfts();
   GOBD_vidMngEveRstDft();
   GD_EveRstDft_Rdy();
   GD_EveRstDft_IndicOBD();
   /*GD_EveRstDft_G_GOBD*/
   MEM_vidMngEveRstDft();
   GD_EveRstDft_GJDD();
   GD_EveRstDft_StatusOfDTC();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveKOf                                                  */
/* !Description :  Key off event                                              */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveKOf_DC();                                          */
/*  extf argret void GOBD_vidMngEveKOf();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveKOf                                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveKOf(void)
{
   /*GD_EveKOf_G_GOBD*/
   GD_EveKOf_DC();
   GOBD_vidMngEveKOf();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDftObd                                            */
/* !Description :  After-sale tool request for an OBD clear failure           */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRstDftObd_GDU();                                   */
/*  extf argret void GD_EveRstDftObd_DC();                                    */
/*  extf argret void WUC_vidMngEvePrmClrAftsScanTool();                       */
/*  extf argret void GOBD_vidMngEveRstDftObd();                               */
/*  extf argret void GD_EveRstDftObd_Rdy();                                   */
/*  extf argret void GD_EveRstDftObd_IndicOBD();                              */
/*  extf argret void MEM_vidMngEveRstDftObd();                                */
/*  extf argret void GD_EveRstDftObd_StatusOfDTC();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDftObd                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDftObd(void)
{
   GD_EveRstDftObd_GDU();
   /*GD_EveRstDftObd_G_GOBD*/
   GD_EveRstDftObd_DC();
   WUC_vidMngEvePrmClrAftsScanTool();
   GOBD_vidMngEveRstDftObd();
   GD_EveRstDftObd_Rdy();
   GD_EveRstDftObd_IndicOBD();
   /*GD_EveRstDftObd_G_GOBD*/
   MEM_vidMngEveRstDftObd();
   GD_EveRstDftObd_StatusOfDTC();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveCrTSt                                                */
/* !Description :  Crank To Stall event                                       */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidMngEveCrTst();                                     */
/*  extf argret void GD_EveCrTSt_IndicOBD();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveCrTSt                                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveCrTSt(void)
{
   /*GD_EveCrTSt_G_GOBD*/
   DC_vidMngEveCrTst();
   GD_EveCrTSt_IndicOBD();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlSlow                                                 */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_02831_012.01                                     */
/*                 VEMS_R_10_05605_001.02                                     */
/*                 VEMS_R_10_05605_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidSdlSlow();                                        */
/*  extf argret void WUC_vidMngEveSldSlow();                                  */
/*  extf argret void GOBD_vidMngEveSldSlow();                                 */
/*  extf argret void GMIL_vidMngEveSldSlow();                                 */
/*  extf argret void GD_SdlSlow_IndicOBD();                                   */
/*  extf argret void GD_SdlSlow_IuprFrz();                                    */
/*  extf argret void IUPRGENDEN_vidMngEveSdlSlow();                           */
/*  extf argret void IuprSpcDen_SdlSlow();                                    */
/*  extf argret void IUPRRATIO_vidMngEveSdlSlow();                            */
/*  extf argret void GD_SdlSlow_DiagTab();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_SdlSlow                                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlSlow(void)
{
   GDU_vidSdlSlow();
   /*GD_SdlSlow_G_GOBD*/
   WUC_vidMngEveSldSlow();
   GOBD_vidMngEveSldSlow();
   GMIL_vidMngEveSldSlow();
   GD_SdlSlow_IndicOBD();
   /*GD_SdlSlow_IUPR*/
   GD_SdlSlow_IuprFrz();
   IUPRGENDEN_vidMngEveSdlSlow();
   IuprSpcDen_SdlSlow();
   IUPRRATIO_vidMngEveSdlSlow();
   /*GD_SdlSlow_IUPR*/
   GD_SdlSlow_DiagTab();
}

/* 1.7 */ /*sauvegarde en eeprom*/
/*void GD_EvePwrl (void)
{

}
*/
/*------------------------------end of file-----------------------------------*/