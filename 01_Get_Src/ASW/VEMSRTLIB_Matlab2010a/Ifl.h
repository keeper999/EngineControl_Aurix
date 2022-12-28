/******************************************************************************/
/*                                                                            */
/* !Layer          : AUTOSAR                                                  */
/*                                                                            */
/* !Component      : IFL                                                      */
/*                                                                            */
/* !Module         : IFL                                                      */
/* !Description    : Source of IFL component                                  */
/*                                                                            */
/* !File           : Ifl.h                                                    */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Ifl.h_v    $*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   19 Feb 2013$*/
/******************************************************************************/

#ifndef _IFL_H_
#define _IFL_H_

#include "Std_Types.h"

typedef struct {
   uint32  Index;
   float32 Ratio;
} Ifl_DPResultF32_Type;

#endif /* _IFL_H_ */
