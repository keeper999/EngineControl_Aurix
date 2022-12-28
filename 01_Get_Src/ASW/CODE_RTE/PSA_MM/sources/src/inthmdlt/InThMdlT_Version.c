/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : InThMdlT                                             */ 
/* !Description     : InThMdlT Software Component                          */ 
/*                                                                            */ 
/* !Module          : InThMdlT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : InThMdlT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M03-InThMdlT/5-S$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   ADELVARE                      $$Date::   06 Jan 2011 17:19:18 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "InThMdlT_Version.h" 
#define InThMdlT_START_SEC_CONST_8BIT 
#include "InThMdlT_MemMap.h" 
CONST(UInt8,INTHMDLT_CONST) InThMdlT_ModuleVersion_Major_MP = (UInt8)INTHMDLT_MAJOR_VERSION; 
CONST(UInt8,INTHMDLT_CONST) InThMdlT_ModuleVersion_Minor_MP = (UInt8)INTHMDLT_MINOR_VERSION; 
CONST(UInt8,INTHMDLT_CONST) InThMdlT_ModuleVersion_Patch_MP = (UInt8)INTHMDLT_PATCH_VERSION; 
#define InThMdlT_STOP_SEC_CONST_8BIT 
#include "InThMdlT_MemMap.h" 
