/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : FISA                                             */ 
/* !Description     : FISA Software Component                          */ 
/*                                                                            */ 
/* !Module          : FISA                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : FISA_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/FISA/5-SOFT-LIV/FIS$*/ 
/* $Revision::   1.0                                                         $*/ 
/* $Author::   adelvare                     $$Date::   16 Mar 2012 14:08:28  $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "FISA_Version.h" 
#define FISA_START_SEC_CONST_8BIT 
#include "FISA_MemMap.h" 
CONST(UInt8,FISA_CONST) FISA_ModuleVersion_Major_MP = (UInt8)FISA_MAJOR_VERSION; 
CONST(UInt8,FISA_CONST) FISA_ModuleVersion_Minor_MP = (UInt8)FISA_MINOR_VERSION; 
CONST(UInt8,FISA_CONST) FISA_ModuleVersion_Patch_MP = (UInt8)FISA_PATCH_VERSION; 
#define FISA_STOP_SEC_CONST_8BIT 
#include "FISA_MemMap.h" 
