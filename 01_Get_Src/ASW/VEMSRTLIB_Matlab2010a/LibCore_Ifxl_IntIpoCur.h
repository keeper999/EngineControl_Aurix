/******************************************************************************/
/*                                                                            */
/* !File           : $FileName                                                */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifx$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   24 Jun 2014$*/
/******************************************************************************/

#ifndef __LIBCORE_IFXL_INTIPOCUR_H__
#define __LIBCORE_IFXL_INTIPOCUR_H__

#include "Std_Types.h"

/*
Integrated curve interpolation
*/

extern float32 LibCore_Ifxl_IntIpoCur_u8_u8(uint8 Xin, uint32 N, const uint8 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u8_s8(uint8 Xin, uint32 N, const uint8 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u8_u16(uint8 Xin, uint32 N, const uint8 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u8_s16(uint8 Xin, uint32 N, const uint8 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u8_u32(uint8 Xin, uint32 N, const uint8 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u8_s32(uint8 Xin, uint32 N, const uint8 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u8_f32(uint8 Xin, uint32 N, const uint8 * X_array, const float32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_u8(sint8 Xin, uint32 N, const sint8 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_s8(sint8 Xin, uint32 N, const sint8 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_u16(sint8 Xin, uint32 N, const sint8 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_s16(sint8 Xin, uint32 N, const sint8 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_u32(sint8 Xin, uint32 N, const sint8 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_s32(sint8 Xin, uint32 N, const sint8 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s8_f32(sint8 Xin, uint32 N, const sint8 * X_array, const float32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_u8(uint16 Xin, uint32 N, const uint16 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_s8(uint16 Xin, uint32 N, const uint16 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_u16(uint16 Xin, uint32 N, const uint16 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_s16(uint16 Xin, uint32 N, const uint16 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_u32(uint16 Xin, uint32 N, const uint16 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_s32(uint16 Xin, uint32 N, const uint16 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u16_f32(uint16 Xin, uint32 N, const uint16 * X_array, const float32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_u8(sint16 Xin, uint32 N, const sint16 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_s8(sint16 Xin, uint32 N, const sint16 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_u16(sint16 Xin, uint32 N, const sint16 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_s16(sint16 Xin, uint32 N, const sint16 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_u32(sint16 Xin, uint32 N, const sint16 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_s32(sint16 Xin, uint32 N, const sint16 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s16_f32(sint16 Xin, uint32 N, const sint16 * X_array, const float32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_u8(uint32 Xin, uint32 N, const uint32 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_s8(uint32 Xin, uint32 N, const uint32 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_u16(uint32 Xin, uint32 N, const uint32 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_s16(uint32 Xin, uint32 N, const uint32 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_u32(uint32 Xin, uint32 N, const uint32 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_s32(uint32 Xin, uint32 N, const uint32 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_u32_f32(uint32 Xin, uint32 N, const uint32 * X_array, const float32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_u8(sint32 Xin, uint32 N, const sint32 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_s8(sint32 Xin, uint32 N, const sint32 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_u16(sint32 Xin, uint32 N, const sint32 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_s16(sint32 Xin, uint32 N, const sint32 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_u32(sint32 Xin, uint32 N, const sint32 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_s32(sint32 Xin, uint32 N, const sint32 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_s32_f32(sint32 Xin, uint32 N, const sint32 * X_array, const float32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_u8(float32 Xin, uint32 N, const float32 * X_array, const uint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_s8(float32 Xin, uint32 N, const float32 * X_array, const sint8 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_u16(float32 Xin, uint32 N, const float32 * X_array, const uint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_s16(float32 Xin, uint32 N, const float32 * X_array, const sint16 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_u32(float32 Xin, uint32 N, const float32 * X_array, const uint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_s32(float32 Xin, uint32 N, const float32 * X_array, const sint32 * Val_array);
extern float32 LibCore_Ifxl_IntIpoCur_f32_f32(float32 Xin, uint32 N, const float32 * X_array, const float32 * Val_array);

#endif /* __LIBCORE_IFXL_INTIPOCUR_H__ */

