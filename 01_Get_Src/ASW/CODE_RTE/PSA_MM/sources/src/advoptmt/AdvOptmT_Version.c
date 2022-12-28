/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AdvOptmT                                             */ 
/* !Description     : AdvOptmT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AdvOptmT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AdvOptmT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M03-AdvOptmT/5-$*/ 
/* $Revision::   1.4                                                         $*/ 
/* $Author::   adelvare                      $$Date::   21 Nov 2012 10:09:06 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AdvOptmT_Version.h" 
#define AdvOptmT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvOptmT_MemMap.h" 
CONST(UInt8,ADVOPTMT_CONST) AdvOptmT_ModuleVersion_Major_MP = (UInt8)ADVOPTMT_MAJOR_VERSION; 
CONST(UInt8,ADVOPTMT_CONST) AdvOptmT_ModuleVersion_Minor_MP = (UInt8)ADVOPTMT_MINOR_VERSION; 
CONST(UInt8,ADVOPTMT_CONST) AdvOptmT_ModuleVersion_Patch_MP = (UInt8)ADVOPTMT_PATCH_VERSION; 
#define AdvOptmT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvOptmT_MemMap.h" 
