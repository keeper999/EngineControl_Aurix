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
/* !File            : GDU_FCT2.c                                              */
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
/*   1 / GDU_vidMngEntryStAbsent                                              */
/*   2 / GDU_vidMngExitStAbsent                                               */
/*   3 / GDU_vidMngEntryStPresent                                             */
/*   4 / GDU_vidMngExitStPresent                                              */
/*   5 / GDU_vidMngEntryStPctlAbsent                                          */
/*   6 / GDU_vidMngExitStPctlAbsent                                           */
/*   7 / GDU_vidMngEntryStPctlPresent                                         */
/*   8 / GDU_vidMngExitStPctlPresent                                          */
/*   9 / GDU_vidMngEntryStDeval                                               */
/*   10 / GDU_vidMngExitStDeval                                               */
/*   11 / GDU_vidMngEntryStFugitif                                            */
/*   12 / GDU_vidMngExitStFugitif                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_FCT2.c_v             $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
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
/* !Function    :  GDU_vidMngEntryStAbsent                                    */
/* !Description :  Manage the action to do when you enter in the state ABSENT.*/
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngEntryStAbsent
(
   uint16 u16IdxDft
)
{
   boolean bLocalCond;


   bLocalCond = 0;
   GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_ABSENT;
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                  BSTPRES,
                  bLocalCond);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngExitStAbsent                                     */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 ABSENT.                                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveSt(argin uint16 u16IdxDft);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngExitStAbsent
(
   uint16 u16IdxDft
)
{
   GDU_vidExitEveSt(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngEntryStPresent                                   */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 PRESENT.                                                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngEntryStPresent
(
   uint16 u16IdxDft
)
{
   boolean bLocalCond;


   bLocalCond = 1;
   GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PRESENT;
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                  BSTPRES,
                  bLocalCond);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngExitStPresent                                    */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 PRESENT.                                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveSt(argin uint16 u16IdxDft);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngExitStPresent
(
   uint16 u16IdxDft
)
{
   GDU_vidExitEveSt(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngEntryStPctlAbsent                                */
/* !Description :  Manage the action to do when you enter in the state PCTL   */
/*                 ABSENT                                                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngEntryStPctlAbsent
(
   uint16 u16IdxDft
)
{
   GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PCTL_ABSENT;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngExitStPctlAbsent                                 */
/* !Description :  Manage the action to do when you exit from the state PTCL  */
/*                 ABSENT.                                                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveSt(argin uint16 u16IdxDft);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngExitStPctlAbsent
(
   uint16 u16IdxDft
)
{
   GDU_vidExitEveSt(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngEntryStPctlPresent                               */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 PCTPRESENT.                                                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngEntryStPctlPresent
(
   uint16 u16IdxDft
)
{
   GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_PCTL_PRESENT;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngExitStPctlPresent                                */
/* !Description :  Manage the action to do when you exit from the state PTCL  */
/*                 PRESENT.                                                   */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveSt(argin uint16 u16IdxDft);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngExitStPctlPresent
(
   uint16 u16IdxDft
)
{
   GDU_vidExitEveSt(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngEntryStDeval                                     */
/* !Description :  Manage the action to do when you enter in the state        */
/*                 DEVALIDATION                                               */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngEntryStDeval
(
   uint16 u16DftIdx
)
{
   GD_astrDftEep[u16DftIdx].enuStDgo = GDU_ETAT_DEVALIDATION;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngExitStDeval                                      */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 DEVALIDATION.                                              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveSt(argin uint16 u16IdxDft);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngExitStDeval
(
   uint16 u16IdxDft
)
{
   GDU_vidExitEveSt(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngEntryStFugitif                                   */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 FUGITIF.                                                   */
/* !Number      :  FCT2.11                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveUnval(argin uint16 u16IdxDft);             */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngEntryStFugitif
(
   uint16 u16IdxDft
)
{
   boolean bLocalCond;


   bLocalCond = 1;
   GD_astrDftEep[u16IdxDft].enuStDgo = GDU_ETAT_FUGITIF;
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                  BSTPRES,
                  bLocalCond);
   GDU_vidExitEveUnval(u16IdxDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngExitStFugitif                                    */
/* !Description :  Manage the action to do when you exit from the state       */
/*                 FUGITIF.                                                   */
/* !Number      :  FCT2.12                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidExitEveSt(argin uint16 u16IdxDft);                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngExitStFugitif
(
   uint16 u16IdxDft
)
{
   GDU_vidExitEveSt(u16IdxDft);
}
/*------------------------------- end of file --------------------------------*/