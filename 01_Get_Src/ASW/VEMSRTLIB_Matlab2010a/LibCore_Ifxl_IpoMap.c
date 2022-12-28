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

#include "LibCore_Ifxl_IpoMap.h"

/*
Map interpolation
num_value =
  Map Matlab : Dimension Axe 1
  Map C : Dimension Axe 2
*/

float32 LibCore_Ifxl_IpoMap_u8(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint8 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 LibCore_Ifxl_IpoMap_s8(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint8 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 LibCore_Ifxl_IpoMap_u16(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint16 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 LibCore_Ifxl_IpoMap_s16(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint16 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 LibCore_Ifxl_IpoMap_u32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint32 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 LibCore_Ifxl_IpoMap_s32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint32 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 LibCore_Ifxl_IpoMap_f32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const float32 * Val_array, boolean isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap) {
      BaseIndex = dpResultX->Index * num_value + dpResultY->Index;
      BaseIndexP1 = BaseIndex + 1;
      BaseIndexPNum = BaseIndex + num_value;
      BaseIndexPNumP1 = BaseIndexPNum + 1;
   } else {
      BaseIndex = dpResultY->Index * num_value + dpResultX->Index;
      BaseIndexP1 = BaseIndex + num_value;
      BaseIndexPNum = BaseIndex + 1;
      BaseIndexPNumP1 = BaseIndexP1 + 1;
   }

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio) {
      return (float32) (Val_array[BaseIndex]);
   } else if (0.0F == dpResultY->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   } else if (0.0F == dpResultX->Ratio) {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   } else {
      float32 VA_00 = (float32) (Val_array[BaseIndex]);
      float32 VA_01 = (float32) (Val_array[BaseIndexP1]);
      float32 VA_10 = (float32) (Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32) (Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

