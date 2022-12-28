/******************************************************************************/
/*                                                                            */
/* !Layer          : ELECITGRMOD                                              */
/*                                                                            */
/* !Component      : ELECITGRMOD                                              */
/*                                                                            */
/* !Module         : ELECITGRMOD                                              */
/* !Description    : Contains internal defines of the DIAGCANcomponent        */
/*                                                                            */
/* !File           : ELECITGRMOD_I.H                                          */
/*                                                                            */
/* !Scope          : PrivateComponent                                         */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ELECITGRMOD/ELECITGRMOD_I.h_v     $*/
/* $Revision::   1.0          $$Author::   hmelloul    $$Date::   19 Aug 2014$*/
/******************************************************************************/
#ifndef ELECITGRMOD_I_H
#define ELECITGRMOD_I_H
#include "STD_TYPES.H"

#define ELECITGRMOD_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
extern uint16  DIAGCAN_u16Etat_IntElec_nrazram;
#define ELECITGRMOD_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

#endif /* ELECITGRMOD_I_H */

/*------------------------------- end of file --------------------------------*/
