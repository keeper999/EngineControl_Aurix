/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AdvPrevKnkT                                             */ 
/* !Description     : AdvPrevKnkT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AdvPrevKnkT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AdvPrevKnkT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M05-AdvPrevKnkT$*/ 
/* $Revision::   1.7                                                         $*/ 
/* $Author::   adelvare                      $$Date::   27 Nov 2012 11:03:20 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AdvPrevKnkT_Version.h" 
#define AdvPrevKnkT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvPrevKnkT_MemMap.h" 
CONST(UInt8,ADVPREVKNKT_CONST) AdvPrevKnkT_ModuleVersion_Major_MP = (UInt8)ADVPREVKNKT_MAJOR_VERSION; 
CONST(UInt8,ADVPREVKNKT_CONST) AdvPrevKnkT_ModuleVersion_Minor_MP = (UInt8)ADVPREVKNKT_MINOR_VERSION; 
CONST(UInt8,ADVPREVKNKT_CONST) AdvPrevKnkT_ModuleVersion_Patch_MP = (UInt8)ADVPREVKNKT_PATCH_VERSION; 
#define AdvPrevKnkT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvPrevKnkT_MemMap.h" 
