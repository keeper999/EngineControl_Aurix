/******************************************************************************/
/*                                                                            */
/* !File           : LibCore_Ifxl_LkUpCur.h                                   */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifx$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   24 Jun 2014$*/
/******************************************************************************/

#ifndef __LIBCORE_IFXL_LKUPCUR_H__
#define __LIBCORE_IFXL_LKUPCUR_H__

#include "LibCore_Ifl.h"
#include "Std_Types.h"

/*
Curve look-up
*/

extern uint8 LibCore_Ifxl_LkUpCur_u8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint8 * Val_array);
extern sint8 LibCore_Ifxl_LkUpCur_s8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint8 * Val_array);
extern uint16 LibCore_Ifxl_LkUpCur_u16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint16 * Val_array);
extern sint16 LibCore_Ifxl_LkUpCur_s16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint16 * Val_array);
extern uint32 LibCore_Ifxl_LkUpCur_u32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint32 * Val_array);
extern sint32 LibCore_Ifxl_LkUpCur_s32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint32 * Val_array);
extern float32 LibCore_Ifxl_LkUpCur_f32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const float32 * Val_array);

#endif /* __LIBCORE_IFXL_LKUPCUR_H__ */

