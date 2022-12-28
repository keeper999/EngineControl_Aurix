/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STATUSOFDTC                                             */
/* !Description     : STATUSOFDTC Component.                                  */
/*                                                                            */
/* !Module          : STATUSOFDTC                                             */
/* !Description     : interface du module  STATUSOFDTC                        */
/*                                                                            */
/* !File            : STATUSOFDTC_MACRO.H                                     */
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
/* PVCS Information                                                           */
/* $Archive::   $*/
/* $Revision::   1.2      $$Author::   alaouni       $$Date::   30 Nov 2011 1$*/
/******************************************************************************/
#ifndef STATUSOFDTC_MACRO_H
#define STATUSOFDTC_MACRO_H

#include "StatusOfDTC.h"
#include "StatusOfDTC_L.h"
#include "StatusOfDTC_IM.h"

/* Macro : GD_CDThd_opt */
/* 
   Description : replace the function GD_CDThd. It's an optimized version. It do 
   the same as GD_CDThd which is "the single failure detection counter has reached 
   one of its threshold".
 */
#define GD_CDThd_opt(u16DftIdx)\
{\
   if (StatusOfDTC_u8Inhib != 0x5A)\
   {\
      if (u16DftIdx < GD_DFT_NB)\
      {\
         SODTC_CDThd_opt(u16DftIdx);\
      }\
      else\
      {\
         SWFAIL_vidSoftwareErrorHook();\
      }\
   }\
}

/* Macro : StatusOfDtc_StGOBD_opt */
/* 
   Description : replace the function StatusOfDtc_StGOBD. It's an optimized version. 
   It do  the same as StatusOfDtc_StGOBD which is "Event indicating a changing OBD 
   state for the considered single failure.
 */
#define StatusOfDtc_StGOBD_opt(u16DftIDx)\
{\
   if (StatusOfDTC_u8Inhib != 0x5A)\
   {\
      if (u16DftIDx < GD_DFT_NB)\
      {\
         SODTC_StGOBD(u16DftIDx);\
      }\
      else\
      {\
         SWFAIL_vidSoftwareErrorHook();\
      }\
   }\
}

/* Macro : SODTC_CDThd_opt */
/* 
   Description : replace the function SODTC_CDThd. It's an optimized version. 
   It do  the same as SODTC_CDThd.
 */
#define SODTC_CDThd_opt(u16DftIdx)\
{\
   GDFRM_tenuGDUState   enuLocalGDUGetStDgo;\
\
   GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],4,0);\
   GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],6,0);\
\
   enuLocalGDUGetStDgo = GDU_tenuGetStDgo(u16DftIdx);\
   if (enuLocalGDUGetStDgo == GDU_ETAT_PRESENT)\
   {\
      GD_vidBitWrite(GD_prmDtcStatus[u16DftIdx],1,1);\
   }\
   GD_SetEventSt(u16DftIdx);\
}
#endif /* STATUSOFDTC_MACRO */