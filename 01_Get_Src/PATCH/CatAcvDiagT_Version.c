/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : CatAcvDiagT                                             */ 
/* !Description     : CatAcvDiagT Software Component                          */ 
/*                                                                            */ 
/* !Module          : CatAcvDiagT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : CatAcvDiagT_Version.c                                   */ 
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
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/CatAcvDiagT_Version.c_v     $*/ 
/* $Revision::   1.0                                                         $*/ 
/* $Author::   croche2                       $$Date::   11 Mar 2014 10:42:58 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "CatAcvDiagT_Version.h" 
#define CatAcvDiagT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "CatAcvDiagT_MemMap.h" 
CONST(UInt8,CATACVDIAGT_CONST) CatAcvDiagT_ModuleVersion_Major_MP = (UInt8)CATACVDIAGT_MAJOR_VERSION; 
CONST(UInt8,CATACVDIAGT_CONST) CatAcvDiagT_ModuleVersion_Minor_MP = (UInt8)CATACVDIAGT_MINOR_VERSION; 
CONST(UInt8,CATACVDIAGT_CONST) CatAcvDiagT_ModuleVersion_Patch_MP = (UInt8)CATACVDIAGT_PATCH_VERSION; 
#define CatAcvDiagT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "CatAcvDiagT_MemMap.h" 
