/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCMD                                                */
/* !Description     : INJCMD Component.                                     */
/*                                                                            */
/* !Module          : INJCMD                                                */
/* !Description     : interface du module  INJCMD                           */
/*                                                                            */
/* !File            : INJCMD_IM.H                                           */
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
/* $Archive::                           INJCMD_im.h_v                      $*/
/* $Revision::       $$Author::   dev            $$Date::21/10/2014 $  */
/* $Author::  dev                                $$Date::21/10/2014 $  */
/******************************************************************************/
#ifndef INJCMD_IM_H
#define INJCMD_IM_H

#include "InjCutOffMgr.h"
#include "InjSpMgt.h"
#include "INJ_GATEWAY.h"
#include "FRM.h"
#include "GDGAR.h"
#include "INJHAL.h"
#include "DGOHAL.h"
#include "SAIMMO.H"

#define MPI_1_TO_4         0    /*  Patch to be remove */
#define INJ_HAL_CYLINDER_4 0xFF /*  Patch to be remove */
#define INS_INJ_GDI        0    /*  Patch to be remove */

#define DGOHAL_udtINJ_1  DGOHAL_udtL9781_INJECTOR_1
#define DGOHAL_udtINJ_2  DGOHAL_udtL9781_INJECTOR_2
#define DGOHAL_udtINJ_3  DGOHAL_udtL9781_INJECTOR_3
#define DGOHAL_udtINJ_4  0xFF


#endif /* INJCMD_IM_H */
/*-------------------------------- end of file -------------------------------*/
