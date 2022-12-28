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

#include "LibCore_Ifxl_IntLkUpCur.h"
#include "LibCore_Ifxl_DPSearch.h"
#include "LibCore_Ifxl_LkUpCur.h"

/*
Integrated curve look-up
*/

uint8 LibCore_Ifxl_IntLkUpCur_u8_u8(uint8 Xin, uint32 N, const uint8 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_u8_s8(uint8 Xin, uint32 N, const uint8 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_u8_u16(uint8 Xin, uint32 N, const uint8 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_u8_s16(uint8 Xin, uint32 N, const uint8 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_u8_u32(uint8 Xin, uint32 N, const uint8 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_u8_s32(uint8 Xin, uint32 N, const uint8 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_u8_f32(uint8 Xin, uint32 N, const uint8 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

uint8 LibCore_Ifxl_IntLkUpCur_s8_u8(sint8 Xin, uint32 N, const sint8 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_s8_s8(sint8 Xin, uint32 N, const sint8 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_s8_u16(sint8 Xin, uint32 N, const sint8 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_s8_s16(sint8 Xin, uint32 N, const sint8 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_s8_u32(sint8 Xin, uint32 N, const sint8 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_s8_s32(sint8 Xin, uint32 N, const sint8 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_s8_f32(sint8 Xin, uint32 N, const sint8 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s8(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

uint8 LibCore_Ifxl_IntLkUpCur_u16_u8(uint16 Xin, uint32 N, const uint16 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_u16_s8(uint16 Xin, uint32 N, const uint16 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_u16_u16(uint16 Xin, uint32 N, const uint16 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_u16_s16(uint16 Xin, uint32 N, const uint16 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_u16_u32(uint16 Xin, uint32 N, const uint16 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_u16_s32(uint16 Xin, uint32 N, const uint16 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_u16_f32(uint16 Xin, uint32 N, const uint16 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

uint8 LibCore_Ifxl_IntLkUpCur_s16_u8(sint16 Xin, uint32 N, const sint16 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_s16_s8(sint16 Xin, uint32 N, const sint16 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_s16_u16(sint16 Xin, uint32 N, const sint16 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_s16_s16(sint16 Xin, uint32 N, const sint16 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_s16_u32(sint16 Xin, uint32 N, const sint16 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_s16_s32(sint16 Xin, uint32 N, const sint16 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_s16_f32(sint16 Xin, uint32 N, const sint16 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s16(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

uint8 LibCore_Ifxl_IntLkUpCur_u32_u8(uint32 Xin, uint32 N, const uint32 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_u32_s8(uint32 Xin, uint32 N, const uint32 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_u32_u16(uint32 Xin, uint32 N, const uint32 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_u32_s16(uint32 Xin, uint32 N, const uint32 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_u32_u32(uint32 Xin, uint32 N, const uint32 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_u32_s32(uint32 Xin, uint32 N, const uint32 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_u32_f32(uint32 Xin, uint32 N, const uint32 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_u32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

uint8 LibCore_Ifxl_IntLkUpCur_s32_u8(sint32 Xin, uint32 N, const sint32 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_s32_s8(sint32 Xin, uint32 N, const sint32 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_s32_u16(sint32 Xin, uint32 N, const sint32 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_s32_s16(sint32 Xin, uint32 N, const sint32 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_s32_u32(sint32 Xin, uint32 N, const sint32 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_s32_s32(sint32 Xin, uint32 N, const sint32 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_s32_f32(sint32 Xin, uint32 N, const sint32 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_s32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

uint8 LibCore_Ifxl_IntLkUpCur_f32_u8(float32 Xin, uint32 N, const float32 * X_array, const uint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u8(&dpResult, Val_array);
}

sint8 LibCore_Ifxl_IntLkUpCur_f32_s8(float32 Xin, uint32 N, const float32 * X_array, const sint8 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s8(&dpResult, Val_array);
}

uint16 LibCore_Ifxl_IntLkUpCur_f32_u16(float32 Xin, uint32 N, const float32 * X_array, const uint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u16(&dpResult, Val_array);
}

sint16 LibCore_Ifxl_IntLkUpCur_f32_s16(float32 Xin, uint32 N, const float32 * X_array, const sint16 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s16(&dpResult, Val_array);
}

uint32 LibCore_Ifxl_IntLkUpCur_f32_u32(float32 Xin, uint32 N, const float32 * X_array, const uint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_u32(&dpResult, Val_array);
}

sint32 LibCore_Ifxl_IntLkUpCur_f32_s32(float32 Xin, uint32 N, const float32 * X_array, const sint32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_s32(&dpResult, Val_array);
}

float32 LibCore_Ifxl_IntLkUpCur_f32_f32(float32 Xin, uint32 N, const float32 * X_array, const float32 * Val_array)
{
  LibCore_Ifl_DPResultF32_Type dpResult;
  LibCore_Ifxl_DPSearch_f32(&dpResult, Xin, N, X_array);
  return LibCore_Ifxl_LkUpCur_f32(&dpResult, Val_array);
}

