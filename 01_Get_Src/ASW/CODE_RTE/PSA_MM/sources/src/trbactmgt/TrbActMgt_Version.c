/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : TrbActMgt                                             */ 
/* !Description     : TrbActMgt Software Component                          */ 
/*                                                                            */ 
/* !Module          : TrbActMgt                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : TrbActMgt_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M13-TrbActMgt/5-$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   05 Oct 2012 10:31:58 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "TrbActMgt_Version.h" 
#define TrbActMgt_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "TrbActMgt_MemMap.h" 
CONST(UInt8,TRBACTMGT_CONST) TrbActMgt_ModuleVersion_Major_MP = (UInt8)TRBACTMGT_MAJOR_VERSION; 
CONST(UInt8,TRBACTMGT_CONST) TrbActMgt_ModuleVersion_Minor_MP = (UInt8)TRBACTMGT_MINOR_VERSION; 
CONST(UInt8,TRBACTMGT_CONST) TrbActMgt_ModuleVersion_Patch_MP = (UInt8)TRBACTMGT_PATCH_VERSION; 
#define TrbActMgt_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "TrbActMgt_MemMap.h" 
