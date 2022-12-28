/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : TrbActSys                                             */ 
/* !Description     : TrbActSys Software Component                          */ 
/*                                                                            */ 
/* !Module          : TrbActSys                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : TrbActSys_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M14-TrbActSys/5-$*/ 
/* $Revision::   1.4                                                         $*/ 
/* $Author::   adelvare                      $$Date::   20 Jul 2012 11:53:58 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "TrbActSys_Version.h" 
#define TrbActSys_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "TrbActSys_MemMap.h" 
CONST(UInt8,TRBACTSYS_CONST) TrbActSys_ModuleVersion_Major_MP = (UInt8)TRBACTSYS_MAJOR_VERSION; 
CONST(UInt8,TRBACTSYS_CONST) TrbActSys_ModuleVersion_Minor_MP = (UInt8)TRBACTSYS_MINOR_VERSION; 
CONST(UInt8,TRBACTSYS_CONST) TrbActSys_ModuleVersion_Patch_MP = (UInt8)TRBACTSYS_PATCH_VERSION; 
#define TrbActSys_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "TrbActSys_MemMap.h" 
