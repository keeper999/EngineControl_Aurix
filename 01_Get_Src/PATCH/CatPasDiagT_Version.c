/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : CatPasDiagT                                             */ 
/* !Description     : CatPasDiagT Software Component                          */ 
/*                                                                            */ 
/* !Module          : CatPasDiagT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : CatPasDiagT_Version.c                                   */ 
/*                                                                            */ 
/* !Target          : All (optimized for "Generic->Custom")                   */ 
/*                                                                            */ 
/* !Vendor          : Valeo                                                   */ 
/*                                                                            */ 
/* Coding language  : C                                                       */ 
/*                                                                            */ 
/* COPYRIGHT 2008 VALEO                                                       */ 
/* all rights reserved                                                        */ 
/******************************************************************************/ 
/* PVCS Information                                                           */ 
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/CatPasDiagT_Version.c_v     $*/ 
/* $Revision::   1.0                                                         $*/ 
/* $Author::   croche2                       $$Date::   11 Mar 2014 10:43:00 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "CatPasDiagT_Version.h" 
#define CatPasDiagT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "CatPasDiagT_MemMap.h" 
CONST(UInt8,CATPASDIAGT_CONST) CatPasDiagT_ModuleVersion_Major_MP = (UInt8)CATPASDIAGT_MAJOR_VERSION; 
CONST(UInt8,CATPASDIAGT_CONST) CatPasDiagT_ModuleVersion_Minor_MP = (UInt8)CATPASDIAGT_MINOR_VERSION; 
CONST(UInt8,CATPASDIAGT_CONST) CatPasDiagT_ModuleVersion_Patch_MP = (UInt8)CATPASDIAGT_PATCH_VERSION; 
#define CatPasDiagT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "CatPasDiagT_MemMap.h" 
