/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AdvMaxT                                             */ 
/* !Description     : AdvMaxT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AdvMaxT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AdvMaxT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M04-AdvMaxT/5-S$*/ 
/* $Revision::   1.4                                                         $*/ 
/* $Author::   adelvare                      $$Date::   27 Nov 2012 10:00:14 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AdvMaxT_Version.h" 
#define AdvMaxT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvMaxT_MemMap.h" 
CONST(UInt8,ADVMAXT_CONST) AdvMaxT_ModuleVersion_Major_MP = (UInt8)ADVMAXT_MAJOR_VERSION; 
CONST(UInt8,ADVMAXT_CONST) AdvMaxT_ModuleVersion_Minor_MP = (UInt8)ADVMAXT_MINOR_VERSION; 
CONST(UInt8,ADVMAXT_CONST) AdvMaxT_ModuleVersion_Patch_MP = (UInt8)ADVMAXT_PATCH_VERSION; 
#define AdvMaxT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvMaxT_MemMap.h" 
