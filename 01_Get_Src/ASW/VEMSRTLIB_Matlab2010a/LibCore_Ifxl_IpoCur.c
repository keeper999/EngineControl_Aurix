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

#include "LibCore_Ifxl_IpoCur.h"

/*
Curve interpolation
*/

float32 LibCore_Ifxl_IpoCur_u8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint8 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 LibCore_Ifxl_IpoCur_s8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint8 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 LibCore_Ifxl_IpoCur_u16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint16 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 LibCore_Ifxl_IpoCur_s16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint16 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 LibCore_Ifxl_IpoCur_u32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint32 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 LibCore_Ifxl_IpoCur_s32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint32 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 LibCore_Ifxl_IpoCur_f32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const float32 * Val_array)
{
   float32 f32Local_0 = (float32) (Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio) {
      return f32Local_0;
   } else {
      float32 f32Local_1 = (float32) (Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0
            + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

