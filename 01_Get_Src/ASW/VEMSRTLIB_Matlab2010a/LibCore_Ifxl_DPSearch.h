/******************************************************************************/
/*                                                                            */
/* !File           : LibCore_Ifxl_DPSearch.h                                  */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifx$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   24 Jun 2014$*/
/******************************************************************************/

#ifndef __LIBCORE_IFXL_DPSEARCH_H__
#define __LIBCORE_IFXL_DPSEARCH_H__

#include "LibCore_Ifl.h"
#include "Std_Types.h"

/*
Data Point Search
*/

extern void LibCore_Ifxl_DPSearch_u8(LibCore_Ifl_DPResultF32_Type * const dpResult, uint8 Xin, uint32 N, const uint8 * X_array);
extern void LibCore_Ifxl_DPSearch_s8(LibCore_Ifl_DPResultF32_Type * const dpResult, sint8 Xin, uint32 N, const sint8 * X_array);
extern void LibCore_Ifxl_DPSearch_u16(LibCore_Ifl_DPResultF32_Type * const dpResult, uint16 Xin, uint32 N, const uint16 * X_array);
extern void LibCore_Ifxl_DPSearch_s16(LibCore_Ifl_DPResultF32_Type * const dpResult, sint16 Xin, uint32 N, const sint16 * X_array);
extern void LibCore_Ifxl_DPSearch_u32(LibCore_Ifl_DPResultF32_Type * const dpResult, uint32 Xin, uint32 N, const uint32 * X_array);
extern void LibCore_Ifxl_DPSearch_s32(LibCore_Ifl_DPResultF32_Type * const dpResult, sint32 Xin, uint32 N, const sint32 * X_array);
extern void LibCore_Ifxl_DPSearch_f32(LibCore_Ifl_DPResultF32_Type * const dpResult, float32 Xin, uint32 N, const float32 * X_array);

#endif /* __LIBCORE_IFXL_DPSEARCH_H__ */

