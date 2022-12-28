/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDU                                                     */
/* !Description     : GDU Component.                                          */
/*                                                                            */
/* !Module          : GDU                                                     */
/* !Description     : SINGLE FAILURE MANAGER                                  */
/*                                                                            */
/* !File            : GDU_API.c                                               */
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
/*   1 / GDU_vidGdu                                                           */
/*   2 / GDU_tenuGetStDgo                                                     */
/*   3 / GDU_bGetEndDiagStrt                                                  */
/*   4 / GDU_vidGlbDCStrt                                                     */
/*   5 / GDU_vidExitEveCDThd                                                  */
/*   6 / GDU_vidExitEveCDThdUp                                                */
/*   7 / GDU_vidExitEveSt                                                     */
/*   8 / GDU_vidExitEveFrfRec                                                 */
/*   9 / GDU_vidExitEveRstDftCal                                              */
/*   10 / GDU_vidExitEveUnval                                                 */
/*   11 / GDU_vidExitEveDftClr                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_API.c_v              $*/
/* $Revision::   1.25     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDU.h"
#include "GDU_L.h"
#include "GDU_IM.h"
#include "GD_api.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidGdu                                                 */
/* !Description :  Main API to manage the GDU.                                */
/* !Number      :  API.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF01_CntDet(argin uint16 u16DftIdx);               */
/*  extf argret void GDU_vidF06_CntDetEvents(argin uint16 u16DftIdx);         */
/*  extf argret void GDU_vidAutomate(argin uint16 u16IdxDft);                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidGdu
(
   uint16 u16IdxDft
)
{
   GDU_vidF01_CntDet(u16IdxDft);
   GDU_vidF06_CntDetEvents(u16IdxDft);
   GDU_vidAutomate(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_tenuGetStDgo                                           */
/* !Description :  API which return the state of the single default. If the   */
/*                 index is wrong it's return the default state               */
/* !Number      :  API.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
GDFRM_tenuGDUState GDU_tenuGetStDgo
(
   uint16 u16IdxDft
)
{
   GDFRM_tenuGDUState enuLocalretState;

   if(u16IdxDft < GD_DFT_NB)
   {
      enuLocalretState = GD_astrDftEep[u16IdxDft].enuStDgo;
   }
   else
   {
      enuLocalretState = GDU_ETAT_ABSENT;
      SWFAIL_vidSoftwareErrorHook();
   }
   return enuLocalretState;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_bGetEndDiagStrt                                        */
/* !Description :  API which returns the value of the boolean EndDiaStrt      */
/* !Number      :  API.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input GDU_tstrDft GDU_astrDftUnit[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean GDU_bGetEndDiagStrt
(
   uint16 u16IdxDft
)
{
   boolean bLocalEndDiagStrt;

   if(u16IdxDft < GD_DFT_NB)
   {
      bLocalEndDiagStrt = GDU_astrDftUnit[u16IdxDft].bEndDiagStrt;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      bLocalEndDiagStrt = FALSE;
   }
   return bLocalEndDiagStrt;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidGlbDCStrt                                           */
/* !Description :  Start-up of a new Global Driving Cycle                     */
/* !Number      :  API.4                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF04_IniCntDetGlbDCStrt_opt(void);                 */
/*  extf argret void GDU_vidF06_ClearCntDetEvents(void);                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidGlbDCStrt(void)
{
   /*Optimisation GD */
   GDU_vidF04_IniCntDetGlbDCStrt_opt();
   GDU_vidF06_ClearCntDetEvents();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveCDThd                                        */
/* !Description :  function which manage the event CDth produce by the module */
/*                 and the scheduling of the call to the other module.        */
/* !Number      :  API.5                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidMngEveCDThd(argin uint16 u16IdxDft);               */
/*  extf argret void GD_CDThd(argin uint16 u16IdxDft);                        */
/*  extf argret void GDU_vidF01_EndDiag(argin uint16 u16DftIdx);              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveCDThd
(
   uint16 u16DftIdx
)
{
   DC_vidMngEveCDThd(u16DftIdx);
   GD_CDThd(u16DftIdx);
   GDU_vidF01_EndDiag(u16DftIdx);
}/* mettre a jour GDU_callback.h si cette fonction evolue */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveCDThdUp                                      */
/* !Description :  function which manage the event CDth produce by the module */
/*                 and the scheduling of the call to the other module.        */
/* !Number      :  API.6                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidMngEveCDThUp(argin uint16 u16IdxDft);             */
/*  extf argret void GOBD_vidMngEveCDThdUp(argin uint16 u16IdxDft);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveCDThdUp
(
   uint16 u16DftIdx
)
{
   MEM_vidMngEveCDThUp(u16DftIdx);
   GOBD_vidMngEveCDThdUp(u16DftIdx);
}/* mettre a jour GDU_callback.h si cette fonction evolue */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveSt                                           */
/* !Description :  function which manage the event St (change state) produce  */
/*                 by the module and the scheduling of the call to the others */
/*                 modules.                                                   */
/* !Number      :  API.7                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void StatusOfDtc_StGDU(argin uint16 u16IdxDft);               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveSt
(
   uint16 u16IdxDft
)
{
   StatusOfDtc_StGDU(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveFrfRec                                       */
/* !Description :  function which manage the event FrFRec produce by the      */
/*                 module and the scheduling of the call to the other module. */
/* !Number      :  API.8                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidMngEveFrfRec(argin uint16 u16IdxDft);             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveFrfRec
(
   uint16 u16IdxDft
)
{
   MEM_vidMngEveFrfRec (u16IdxDft);
}/* mettre a jour GDU_callback.h si cette fonction evolue */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveRstDftCal                                    */
/* !Description :  function which manage the event RstDftCal used in          */
/*                 validation                                                 */
/* !Number      :  API.9                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidMngEveRstDftCal();                                */
/*  extf argret void DC_RstDftCal();                                          */
/*  extf argret void GOBD_vidMngEveRstDftCal();                               */
/*  extf argret void OBD_vidMngEveRstDftCal();                                */
/*  extf argret void RC01_vidMngEveRstDft();                                  */
/*  extf argret void INDICOBD_RstDftCal();                                    */
/*  extf argret void JDD_RstDftCal();                                         */
/*  extf argret void GD_RstDftCal();                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveRstDftCal(void)
{
   MEM_vidMngEveRstDftCal();
   DC_RstDftCal();
   GOBD_vidMngEveRstDftCal();
   OBD_vidMngEveRstDftCal();
   RC01_vidMngEveRstDft();
   INDICOBD_RstDftCal();
   JDD_RstDftCal();
   GD_RstDftCal();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveUnval                                        */
/* !Description :  function which manage the event unval.                     */
/* !Number      :  API.10                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidMngEveDftUnval(argin uint16 u16IdxDft);          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveUnval
(
   uint16 u16IdxDft
)
{
   GOBD_vidMngEveDftUnval(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidExitEveDftClr                                       */
/* !Description :  Function which manage the event Default clear              */
/* !Number      :  API.11                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_DftClr(argin uint16 u16IdxDft);                       */
/*  extf argret void MEM_vidMngEveDftClr(argin uint16 u16IdxDft);             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidExitEveDftClr
(
   uint16 u16IdxDft
)
{
   GD_DftClr(u16IdxDft);
   MEM_vidMngEveDftClr(u16IdxDft);
}
/*------------------------------- end of file --------------------------------*/
