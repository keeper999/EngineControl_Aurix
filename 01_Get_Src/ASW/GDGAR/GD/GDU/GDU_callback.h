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
/* !File            : GDU_callback.h                                          */
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
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_API.c_v              $*/
/* $Revision::   1.22     $$Author::   alaouni        $$Date::   05 Mar 2012 $*/
/* $Author::   alaouni                                $$Date::   05 Mar 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "GDU.h"
#include "GDU_L.h"
#include "GDU_im.h"

#ifndef GDU_CALLBACK_H
#define GDU_CALLBACK_H

/* Macro optimisation */
/* appel des fonctions en macros afin de gagner un appel */

/* -------------------------------------------------------------------------- */
#define GDU_vidExitEveFrfRec_opt( u16IdxDft)\
{\
   MEM_vidMngEveFrfRec_opt(u16IdxDft);\
}
/* -------------------------------------------------------------------------- */
#define GDU_vidF01_EndDiag_opt(u16DftIdx)\
{\
   GDU_astrDftUnit[u16DftIdx].bEndDiagStrt = 1;\
}
/* -------------------------------------------------------------------------- */
#define GDU_vidExitEveCDThd_opt(LocalDivision,LocalMask,u16DftIdx)\
{\
   DC_vidMngEveCDThd_opt(LocalDivision,LocalMask);\
   GD_CDThd_opt(u16DftIdx);\
   GDU_vidF01_EndDiag_opt(u16DftIdx);\
}
/* -------------------------------------------------------------------------- */
#define GDU_vidExitEveCDThdUp_opt(u16DftIdx)\
{\
   MEM_vidMngEveCDThUp_opt(u16DftIdx);\
   GOBD_vidMngEveCDThdUp_opt(u16DftIdx);\
}
/* -------------------------------------------------------------------------- */

#endif /* GDU_CALLBACK_H */