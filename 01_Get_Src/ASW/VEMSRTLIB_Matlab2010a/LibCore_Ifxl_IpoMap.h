/******************************************************************************/
/*                                                                            */
/* !File           : LibCore_Ifxl_IpoMap.h                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifx$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   24 Jun 2014$*/
/******************************************************************************/

#ifndef __LIBCORE_IFXL_IPOMAP_H__
#define __LIBCORE_IFXL_IPOMAP_H__

#include "LibCore_Ifl.h"
#include "Std_Types.h"

/*
Map interpolation
num_value =
  Map Matlab : Dimension Axe 1
  Map C : Dimension Axe 2
*/

extern float32 LibCore_Ifxl_IpoMap_u8(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint8 * Val_array, boolean isMatlabMap);
extern float32 LibCore_Ifxl_IpoMap_s8(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint8 * Val_array, boolean isMatlabMap);
extern float32 LibCore_Ifxl_IpoMap_u16(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint16 * Val_array, boolean isMatlabMap);
extern float32 LibCore_Ifxl_IpoMap_s16(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint16 * Val_array, boolean isMatlabMap);
extern float32 LibCore_Ifxl_IpoMap_u32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint32 * Val_array, boolean isMatlabMap);
extern float32 LibCore_Ifxl_IpoMap_s32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint32 * Val_array, boolean isMatlabMap);
extern float32 LibCore_Ifxl_IpoMap_f32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const float32 * Val_array, boolean isMatlabMap);

#endif /* __LIBCORE_IFXL_IPOMAP_H__ */

