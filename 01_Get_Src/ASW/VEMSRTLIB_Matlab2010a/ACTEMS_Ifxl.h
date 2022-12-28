/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_Ifxl.h                                            */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/ACTEMS_Ifxl$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   19 Feb 2013$*/
/******************************************************************************/

#ifndef _ACTEMS_IFXL_H_
#define _ACTEMS_IFXL_H_

#include "Ifl.h"

extern void ACTEMS_Ifx_DPSearch_u8 (Ifl_DPResultF32_Type* const dpResult, uint8   Xin, uint32 N, const uint8*   X_array);
extern void ACTEMS_Ifx_DPSearch_s8 (Ifl_DPResultF32_Type* const dpResult, sint8   Xin, uint32 N, const sint8*   X_array);
extern void ACTEMS_Ifx_DPSearch_u16(Ifl_DPResultF32_Type* const dpResult, uint16  Xin, uint32 N, const uint16*  X_array);
extern void ACTEMS_Ifx_DPSearch_s16(Ifl_DPResultF32_Type* const dpResult, sint16  Xin, uint32 N, const sint16*  X_array);
extern void ACTEMS_Ifx_DPSearch_u32(Ifl_DPResultF32_Type* const dpResult, uint32  Xin, uint32 N, const uint32*  X_array);
extern void ACTEMS_Ifx_DPSearch_s32(Ifl_DPResultF32_Type* const dpResult, sint32  Xin, uint32 N, const sint32*  X_array);

extern void ACTEMS_Ifl_DPSearch_f32(Ifl_DPResultF32_Type* const dpResult, float32 Xin, uint32 N, const float32* X_array);

/* Curve interpolation */
extern float32 ACTEMS_Ifl_IpoCur_f32_u8 (const Ifl_DPResultF32_Type* const dpResult, const uint8*   Val_array);
extern float32 ACTEMS_Ifl_IpoCur_f32_s8 (const Ifl_DPResultF32_Type* const dpResult, const sint8*   Val_array);
extern float32 ACTEMS_Ifl_IpoCur_f32_u16(const Ifl_DPResultF32_Type* const dpResult, const uint16*  Val_array);
extern float32 ACTEMS_Ifl_IpoCur_f32_s16(const Ifl_DPResultF32_Type* const dpResult, const sint16*  Val_array);
extern float32 ACTEMS_Ifl_IpoCur_f32_u32(const Ifl_DPResultF32_Type* const dpResult, const uint32*  Val_array);
extern float32 ACTEMS_Ifl_IpoCur_f32_s32(const Ifl_DPResultF32_Type* const dpResult, const sint32*  Val_array);

extern float32 ACTEMS_Ifl_IpoCur_f32    (const Ifl_DPResultF32_Type* const dpResult, const float32* Val_array);

/* Map interpolation */
extern float32 ACTEMS_Ifl_IpoMap_f32_u8 (const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const uint8*   Val_array, boolean isMatlabMap);
extern float32 ACTEMS_Ifl_IpoMap_f32_s8 (const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const sint8*   Val_array, boolean isMatlabMap);
extern float32 ACTEMS_Ifl_IpoMap_f32_u16(const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const uint16*  Val_array, boolean isMatlabMap);
extern float32 ACTEMS_Ifl_IpoMap_f32_s16(const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const sint16*  Val_array, boolean isMatlabMap);
extern float32 ACTEMS_Ifl_IpoMap_f32_u32(const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const uint32*  Val_array, boolean isMatlabMap);
extern float32 ACTEMS_Ifl_IpoMap_f32_s32(const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const sint32*  Val_array, boolean isMatlabMap);

extern float32 ACTEMS_Ifl_IpoMap_f32    (const Ifl_DPResultF32_Type* const dpResultX, const Ifl_DPResultF32_Type* const dpResultY, uint32 num_value, const float32* Val_array, boolean isMatlabMap);

#endif /* _ACTEMS_IFXL_H_ */
