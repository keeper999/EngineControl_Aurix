/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MEM                                                     */
/* !Description     : MEM Component                                           */
/*                                                                            */
/* !Module          : MEM                                                     */
/* !Description     : MEMORISATION DES PARAMETRES DEFAUTS                     */
/*                                                                            */
/* !File            : MEM_macro.c                                             */
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
#ifndef MEM_MACRO_H
#define MEM_MACRO_H

#include "MEM_L.h"
#include "MEM.h"

/* Macro : MEM_vidMngEveFrfRec_opt                                            */
/* Description :                                                              */
/*    Optimized version of the function MEM_vidMngEveFrfRec. Do the same as   */
/*    the function "Evènement moment de mémorisation de la Freeze Frame".     */
#define MEM_vidMngEveFrfRec_opt(u16IdxDft)\
{\
   if(MEM_u8Inhib != 0x5A)\
   {\
      MEM_vidF01_FrzData(u16IdxDft);\
   }\
}

/* Macro : MEM_vidMngEveCDThUp_opt                                            */
/* Description :                                                              */
/*    Optimized version of the function MEM_vidMngEveCDThUp. Do the same as   */
/*    the function "Evènement moment de mémorisation de la Freeze Frame".     */
#define MEM_vidMngEveCDThUp_opt(u16IdxDft)\
{\
   if (MEM_u8Inhib != 0x5A)\
   {\
      MEM_vidF02_StoreDataFrf(u16IdxDft);\
   }\
}

#endif /* MEM_MACRO_H */