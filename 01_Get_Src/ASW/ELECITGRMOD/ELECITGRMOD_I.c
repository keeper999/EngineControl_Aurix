/******************************************************************************/
/*                                                                            */
/* !Layer          : ELECITGRMOD                                              */
/*                                                                            */
/* !Component      : ELECITGRMOD                                              */
/*                                                                            */
/* !Module         : ELECITGRMOD                                              */
/* !Description    : Contains internal defines of the DIAGCANcomponent        */
/*                                                                            */
/* !File           : ELECITGRMOD_I.C                                          */
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
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ELECITGRMOD/ELECITGRMOD_I.c_v     $*/
/* $Revision::   1.1          $$Author::   hmelloul    $$Date::   09 Sep 2014$*/
/******************************************************************************/
#include "STD_TYPES.H"
#include "ELECITGRMOD_I.H"

#define ELECITGRMOD_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
uint16  DIAGCAN_u16Etat_IntElec_nrazram;
#define ELECITGRMOD_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
