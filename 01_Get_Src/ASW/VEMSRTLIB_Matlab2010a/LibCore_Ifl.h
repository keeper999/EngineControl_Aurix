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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifl$*/
/* $Revision::   1.1          $$Author::   adelvare    $$Date::   30 Jun 2014$*/
/******************************************************************************/

#ifndef _LIBCORE_IFL_H_
#define _LIBCORE_IFL_H_

#include "Std_Types.h"

typedef struct {
   uint32  Index;
   float32 Ratio;
} LibCore_Ifl_DPResultF32_Type;

#endif /* _LIBCORE_IFL_H_ */
