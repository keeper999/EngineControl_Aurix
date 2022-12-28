/******************************************************************************/
/*                                                                            */
/* !File           : LibCore_Ifxl_IpoCur.h                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifx$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   24 Jun 2014$*/
/******************************************************************************/

#ifndef __LIBCORE_IFXL_IPOCUR_H__
#define __LIBCORE_IFXL_IPOCUR_H__

#include "LibCore_Ifl.h"
#include "Std_Types.h"

/*
Curve interpolation
*/

extern float32 LibCore_Ifxl_IpoCur_u8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IpoCur_s8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IpoCur_u16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IpoCur_s16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IpoCur_u32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IpoCur_s32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IpoCur_f32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const float32 * Val_array);

#endif /* __LIBCORE_IFXL_IPOCUR_H__ */

