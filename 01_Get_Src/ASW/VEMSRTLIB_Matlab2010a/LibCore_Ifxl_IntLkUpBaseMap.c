/******************************************************************************/
/*                                                                            */
/* !File           : LibCore_Ifxl_IntLkUpBaseMap.c                            */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LibCore_Ifx$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   24 Jun 2014$*/
/******************************************************************************/

#include "LibCore_Ifxl_IntLkUpBaseMap.h"
#include "LibCore_Ifxl_DPSearch.h"
#include "LibCore_Ifxl_LkUpBaseMap.h"

/*
Integrated map look-up without rounding
*/

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8u8_u8(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8u8_s8(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8u8_u16(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8u8_s16(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8u8_u32(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8u8_s32(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8u8_f32(uint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8s8_u8(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8s8_s8(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8s8_u16(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8s8_s16(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8s8_u32(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8s8_s32(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8s8_f32(uint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8u16_u8(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8u16_s8(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8u16_u16(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8u16_s16(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8u16_u32(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8u16_s32(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8u16_f32(uint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8s16_u8(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8s16_s8(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8s16_u16(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8s16_s16(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8s16_u32(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8s16_s32(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8s16_f32(uint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8u32_u8(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8u32_s8(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8u32_u16(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8u32_s16(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8u32_u32(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8u32_s32(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8u32_f32(uint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8s32_u8(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8s32_s8(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8s32_u16(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8s32_s16(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8s32_u32(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8s32_s32(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8s32_f32(uint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u8f32_u8(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u8f32_s8(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u8f32_u16(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u8f32_s16(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u8f32_u32(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u8f32_s32(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u8f32_f32(uint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint8 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8u8_u8(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8u8_s8(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8u8_u16(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8u8_s16(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8u8_u32(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8u8_s32(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8u8_f32(sint8 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8s8_u8(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8s8_s8(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8s8_u16(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8s8_s16(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8s8_u32(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8s8_s32(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8s8_f32(sint8 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8u16_u8(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8u16_s8(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8u16_u16(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8u16_s16(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8u16_u32(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8u16_s32(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8u16_f32(sint8 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8s16_u8(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8s16_s8(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8s16_u16(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8s16_s16(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8s16_u32(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8s16_s32(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8s16_f32(sint8 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8u32_u8(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8u32_s8(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8u32_u16(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8u32_s16(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8u32_u32(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8u32_s32(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8u32_f32(sint8 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8s32_u8(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8s32_s8(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8s32_u16(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8s32_s16(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8s32_u32(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8s32_s32(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8s32_f32(sint8 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s8f32_u8(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s8f32_s8(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s8f32_u16(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s8f32_s16(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s8f32_u32(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s8f32_s32(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s8f32_f32(sint8 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint8 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s8(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16u8_u8(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16u8_s8(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16u8_u16(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16u8_s16(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16u8_u32(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16u8_s32(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16u8_f32(uint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16s8_u8(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16s8_s8(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16s8_u16(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16s8_s16(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16s8_u32(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16s8_s32(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16s8_f32(uint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16u16_u8(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16u16_s8(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16u16_u16(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16u16_s16(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16u16_u32(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16u16_s32(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16u16_f32(uint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16s16_u8(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16s16_s8(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16s16_u16(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16s16_s16(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16s16_u32(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16s16_s32(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16s16_f32(uint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16u32_u8(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16u32_s8(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16u32_u16(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16u32_s16(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16u32_u32(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16u32_s32(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16u32_f32(uint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16s32_u8(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16s32_s8(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16s32_u16(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16s32_s16(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16s32_u32(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16s32_s32(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16s32_f32(uint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u16f32_u8(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u16f32_s8(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u16f32_u16(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u16f32_s16(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u16f32_u32(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u16f32_s32(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u16f32_f32(uint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint16 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16u8_u8(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16u8_s8(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16u8_u16(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16u8_s16(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16u8_u32(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16u8_s32(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16u8_f32(sint16 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16s8_u8(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16s8_s8(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16s8_u16(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16s8_s16(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16s8_u32(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16s8_s32(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16s8_f32(sint16 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16u16_u8(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16u16_s8(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16u16_u16(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16u16_s16(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16u16_u32(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16u16_s32(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16u16_f32(sint16 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16s16_u8(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16s16_s8(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16s16_u16(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16s16_s16(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16s16_u32(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16s16_s32(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16s16_f32(sint16 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16u32_u8(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16u32_s8(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16u32_u16(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16u32_s16(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16u32_u32(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16u32_s32(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16u32_f32(sint16 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16s32_u8(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16s32_s8(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16s32_u16(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16s32_s16(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16s32_u32(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16s32_s32(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16s32_f32(sint16 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s16f32_u8(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s16f32_s8(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s16f32_u16(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s16f32_s16(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s16f32_u32(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s16f32_s32(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s16f32_f32(sint16 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint16 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s16(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32u8_u8(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32u8_s8(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32u8_u16(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32u8_s16(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32u8_u32(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32u8_s32(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32u8_f32(uint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32s8_u8(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32s8_s8(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32s8_u16(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32s8_s16(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32s8_u32(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32s8_s32(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32s8_f32(uint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32u16_u8(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32u16_s8(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32u16_u16(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32u16_s16(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32u16_u32(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32u16_s32(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32u16_f32(uint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32s16_u8(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32s16_s8(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32s16_u16(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32s16_s16(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32s16_u32(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32s16_s32(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32s16_f32(uint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32u32_u8(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32u32_s8(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32u32_u16(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32u32_s16(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32u32_u32(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32u32_s32(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32u32_f32(uint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32s32_u8(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32s32_s8(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32s32_u16(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32s32_s16(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32s32_u32(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32s32_s32(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32s32_f32(uint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_u32f32_u8(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_u32f32_s8(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_u32f32_u16(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_u32f32_s16(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_u32f32_u32(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_u32f32_s32(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_u32f32_f32(uint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const uint32 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_u32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32u8_u8(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32u8_s8(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32u8_u16(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32u8_s16(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32u8_u32(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32u8_s32(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32u8_f32(sint32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32s8_u8(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32s8_s8(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32s8_u16(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32s8_s16(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32s8_u32(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32s8_s32(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32s8_f32(sint32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32u16_u8(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32u16_s8(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32u16_u16(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32u16_s16(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32u16_u32(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32u16_s32(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32u16_f32(sint32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32s16_u8(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32s16_s8(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32s16_u16(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32s16_s16(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32s16_u32(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32s16_s32(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32s16_f32(sint32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32u32_u8(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32u32_s8(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32u32_u16(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32u32_s16(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32u32_u32(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32u32_s32(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32u32_f32(sint32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32s32_u8(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32s32_s8(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32s32_u16(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32s32_s16(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32s32_u32(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32s32_s32(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32s32_f32(sint32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_s32f32_u8(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_s32f32_s8(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_s32f32_u16(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_s32f32_s16(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_s32f32_u32(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_s32f32_s32(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_s32f32_f32(sint32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const sint32 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_s32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32u8_u8(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32u8_s8(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32u8_u16(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32u8_s16(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32u8_u32(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32u8_s32(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32u8_f32(float32 Xin,
    uint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32s8_u8(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32s8_s8(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32s8_u16(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32s8_s16(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32s8_u32(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32s8_s32(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32s8_f32(float32 Xin,
    sint8 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint8 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s8(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32u16_u8(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32u16_s8(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32u16_u16(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32u16_s16(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32u16_u32(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32u16_s32(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32u16_f32(float32 Xin,
    uint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32s16_u8(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32s16_s8(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32s16_u16(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32s16_s16(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32s16_u32(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32s16_s32(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32s16_f32(float32 Xin,
    sint16 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint16 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s16(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32u32_u8(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32u32_s8(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32u32_u16(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32u32_s16(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32u32_u32(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32u32_s32(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32u32_f32(float32 Xin,
    uint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const uint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_u32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32s32_u8(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32s32_s8(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32s32_u16(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32s32_s16(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32s32_u32(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32s32_s32(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32s32_f32(float32 Xin,
    sint32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const sint32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_s32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint8 LibCore_Ifxl_IntLkUpBaseMap_f32f32_u8(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const uint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint8 LibCore_Ifxl_IntLkUpBaseMap_f32f32_s8(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const sint8 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s8(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint16 LibCore_Ifxl_IntLkUpBaseMap_f32f32_u16(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const uint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint16 LibCore_Ifxl_IntLkUpBaseMap_f32f32_s16(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const sint16 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s16(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

uint32 LibCore_Ifxl_IntLkUpBaseMap_f32f32_u32(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const uint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_u32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

sint32 LibCore_Ifxl_IntLkUpBaseMap_f32f32_s32(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const sint32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_s32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

float32 LibCore_Ifxl_IntLkUpBaseMap_f32f32_f32(float32 Xin,
    float32 Yin,
    uint32 Nx,
    uint32 Ny,
    const float32 * X_array,
    const float32 * Y_array,
    const float32 * Val_array,
    boolean isMatlabMap)
{
  LibCore_Ifl_DPResultF32_Type dpResultX;
  LibCore_Ifl_DPResultF32_Type dpResultY;
  LibCore_Ifxl_DPSearch_f32(&dpResultX, Xin, Nx, X_array);
  LibCore_Ifxl_DPSearch_f32(&dpResultY, Yin, Ny, Y_array);
  return LibCore_Ifxl_LkUpBaseMap_f32(&dpResultX, &dpResultY, ((0 == isMatlabMap) ? Ny : Nx), Val_array, isMatlabMap);
}

