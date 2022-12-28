/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : DmpVlvH                                             */ 
/* !Description     : DmpVlvH Software Component                          */ 
/*                                                                            */ 
/* !Module          : DmpVlvH                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : DmpVlvH_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M12-DmpVlvH/5-SO$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   04 Jun 2013 10:29:58 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "DmpVlv_H_Version.h" 
#define DmpVlv_H_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "DmpVlv_H_MemMap.h" 
CONST(UInt8,DMPVLV_H_CONST) DmpVlv_H_ModuleVersion_Major_MP = (UInt8)DMPVLV_H_MAJOR_VERSION; 
CONST(UInt8,DMPVLV_H_CONST) DmpVlv_H_ModuleVersion_Minor_MP = (UInt8)DMPVLV_H_MINOR_VERSION; 
CONST(UInt8,DMPVLV_H_CONST) DmpVlv_H_ModuleVersion_Patch_MP = (UInt8)DMPVLV_H_PATCH_VERSION; 
#define DmpVlv_H_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "DmpVlv_H_MemMap.h" 
