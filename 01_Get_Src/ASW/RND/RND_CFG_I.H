/******************************************************************************/
/*                                                                            */
/* !Layer :          MCAL                                                     */
/*                                                                            */
/* !Component :      RND                                                      */
/*                                                                            */
/* !Module :         RND                                                     */
/* !Description :    Configuration of the RND Component                       */
/*                                                                            */
/* !File :           RND_CFG_I.H                                              */
/*                                                                            */
/* !Target :         All                                                      */
/*                                                                            */
/* !Vendor :         Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RND/RND_CFG_I.H_v                 $*/
/* $Revision::   1.0      $$Author::   ftournai       $$Date::   10 Jul 2009 $*/
/******************************************************************************/


#ifndef RND_CFG_I_H
#define RND_CFG_I_H

#include "STD_TYPES.h"
#include "RND.h"
#include "RND_L.h"




#define RND_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern const uint8 RND_kuADCHAL[NB_MAX_ADC_CHANNEL];


#define RND_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#endif /* GPT_CFG_I_H */

/*-------------------------------- end of file -------------------------------*/
