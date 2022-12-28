/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMaxT                                                 */
/* !Description     : AdvMaxT Software Component                              */
/*                                                                            */
/* !Module          : AdvMaxT                                                 */
/*                                                                            */
/* !File            : AdvMaxT_Def.c                                           */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AdvMaxT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMaxT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M04-AdvMaxT/5-S$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   ADELVARE                               $$Date::   01 Jul 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvMaxT.h"
#include "AdvMaxT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CARTO_32BIT" */
#define AdvMaxT_START_SEC_CARTO_32BIT
#include "AdvMaxT_MemMap.h"

CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxExVlvMax_M[16][16] = { {3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F},
  {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F},
  {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F}, {3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F} } ;

CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxExVlvMin_M[16][16] = { {4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F},
  {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F},
  {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F}, {4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F,
  4.0F, 4.0F, 4.0F, 4.0F, 4.0F, 4.0F} } ;

CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxInVlvMax_M[16][16] = { {1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F},
  {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F},
  {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F}, {1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F} } ;

CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxInVlvMin_M[16][16] = { {2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F},
  {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F},
  {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F}, {2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F} } ;

CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxVlvRef_M[16][16] = { {5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F},
  {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F},
  {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F}, {5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F} } ;

CONST(Float32, ADVMAXT_CARTO) IgSys_rAdvMaxExVlv_M[17][17] = { {-1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F}, {-0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F,
  -0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F,
  -0.875F, -0.875F, -0.875F}, {-0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F,
  -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F,
  -0.75F}, {-0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F,
  -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F,
  -0.625F}, {-0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F,
  -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F}, {-0.375F, -0.375F, -0.375F,
  -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F,
  -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F}, {-0.25F, -0.25F, -0.25F,
  -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F,
  -0.25F, -0.25F, -0.25F, -0.25F}, {-0.125F, -0.125F, -0.125F, -0.125F, -0.125F,
  -0.125F, -0.125F, -0.125F, -0.125F, -0.125F, -0.125F, -0.125F, -0.125F,
  -0.125F, -0.125F, -0.125F, -0.125F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.125F}, {0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F}, {0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F,
  0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F}, {0.5F, 0.5F,
  0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F,
  0.5F, 0.5F}, {0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F,
  0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F}, {0.75F,
  0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F,
  0.75F, 0.75F, 0.75F, 0.75F, 0.75F}, {0.875F, 0.875F, 0.875F, 0.875F, 0.875F,
  0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F,
  0.875F, 0.875F}, {0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F,
  0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F,
  0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F} } ;

CONST(Float32, ADVMAXT_CARTO) IgSys_rAdvMaxInVlv_M[17][17] = { {-1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F}, {-0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F,
  -0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F, -0.875F,
  -0.875F, -0.875F, -0.875F}, {-0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F,
  -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F, -0.75F,
  -0.75F}, {-0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F,
  -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F, -0.625F,
  -0.625F}, {-0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F,
  -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F}, {-0.375F, -0.375F, -0.375F,
  -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F,
  -0.375F, -0.375F, -0.375F, -0.375F, -0.375F, -0.375F}, {-0.25F, -0.25F, -0.25F,
  -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F, -0.25F,
  -0.25F, -0.25F, -0.25F, -0.25F}, {-0.125F, -0.125F, -0.125F, -0.125F, -0.125F,
  -0.125F, -0.125F, -0.125F, -0.125F, -0.125F, -0.125F, -0.125F, -0.125F,
  -0.125F, -0.125F, -0.125F, -0.125F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.125F}, {0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F}, {0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F,
  0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F, 0.375F}, {0.5F, 0.5F,
  0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F,
  0.5F, 0.5F}, {0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F,
  0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F, 0.625F}, {0.75F,
  0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F, 0.75F,
  0.75F, 0.75F, 0.75F, 0.75F, 0.75F}, {0.875F, 0.875F, 0.875F, 0.875F, 0.875F,
  0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F, 0.875F,
  0.875F, 0.875F}, {0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F,
  0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F,
  0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F, 0.9921875F} } ;

CONST(Float32, ADVMAXT_CARTO) Vlv_agCkExVlvNorm_A[17] = { -1.0F, -0.875F,
  -0.75F, -0.625F, -0.5F, -0.375F, -0.25F, -0.125F, 0.0F, 0.125F, 0.25F, 0.375F,
  0.5F, 0.625F, 0.75F, 0.875F, 0.9921875F } ;

CONST(Float32, ADVMAXT_CARTO) Vlv_agCkInVlvNorm_A[17] = { -1.0F, -0.875F,
  -0.75F, -0.625F, -0.5F, -0.375F, -0.25F, -0.125F, 0.0F, 0.125F, 0.25F, 0.375F,
  0.5F, 0.625F, 0.75F, 0.875F, 0.9921875F } ;

#define AdvMaxT_STOP_SEC_CARTO_32BIT
#include "AdvMaxT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AdvMaxT_START_SEC_CALIB_BOOLEAN
#include "AdvMaxT_MemMap.h"

CONST(Boolean, ADVMAXT_CALIB) ADVMAXT_ACTIVE_BYP_C = 0;
CONST(Boolean, ADVMAXT_CALIB) IgSys_bFlexMaxOfs_C = 1;
CONST(Boolean, ADVMAXT_CALIB) IgSys_bGasMaxOfs_C = 1;

#define AdvMaxT_STOP_SEC_CALIB_BOOLEAN
#include "AdvMaxT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AdvMaxT_START_SEC_CALIB_8BIT
#include "AdvMaxT_MemMap.h"

CONST(UInt8, ADVMAXT_CALIB) IgSys_agIgKnkAdpOfsMv_B = 96U;
CONST(UInt8, ADVMAXT_CALIB) IgSys_agIgMaxWiPrevAdpMv_B = 96U;
CONST(UInt8, ADVMAXT_CALIB) IgSys_agIgMaxWiPrevMv_B = 96U;
CONST(UInt8, ADVMAXT_CALIB) IgSys_prm_agIgMaxWiPrevAdpCyl_B[6] = { 96U, 96U,
  96U, 96U, 96U, 96U } ;

#define AdvMaxT_STOP_SEC_CALIB_8BIT
#include "AdvMaxT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AdvMaxT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvMaxT_MemMap.h"

VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkClsExVlvWrmAdvMax_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkDeltaExVlv_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkDeltaInVlv_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkOpInVlvWrmAdvMax_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynExVlvMax_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynExVlvMin_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynInVlvMax_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynInVlvMin_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgKnkBasDyn = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgKnkBasStat = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynExVlvMax = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynExVlvMin = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynInVlvMax = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynInVlvMin = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatExVlvMax = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatExVlvMin = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatInVlvMax = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatInVlvMin = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxVlvDynRef = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxVlvStatRef = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxWiFlexCor_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxWiOfs = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxWoutPrevAdpMv = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatExVlvMax_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatExVlvMin_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatInVlvMax_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatInVlvMin_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_facAdvMaxExVlv = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_facAdvMaxInVlv = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rAdvMaxExVlv = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rAdvMaxInVlv = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rDeltaExVlv_MP = 0.0F;
VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rDeltaInVlv_MP = 0.0F;

#define AdvMaxT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvMaxT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvMaxT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMaxT_MemMap.h"

VAR(Boolean, ADVMAXT_INTERNAL_VAR) IgSys_bAcvAdvMax = FALSE;

#define AdvMaxT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMaxT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
