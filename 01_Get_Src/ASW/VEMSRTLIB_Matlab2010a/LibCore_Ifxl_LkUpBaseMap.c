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

#include "LibCore_Ifxl_LkUpBaseMap.h"

/*
Map look-up without rounding
num_value =
  Map Matlab : Dimension Axe 1
  Map C : Dimension Axe 2
*/

uint8 LibCore_Ifxl_LkUpBaseMap_u8(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint8 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

sint8 LibCore_Ifxl_LkUpBaseMap_s8(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint8 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

uint16 LibCore_Ifxl_LkUpBaseMap_u16(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint16 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

sint16 LibCore_Ifxl_LkUpBaseMap_s16(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint16 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

uint32 LibCore_Ifxl_LkUpBaseMap_u32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const uint32 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

sint32 LibCore_Ifxl_LkUpBaseMap_s32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const sint32 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

float32 LibCore_Ifxl_LkUpBaseMap_f32(const LibCore_Ifl_DPResultF32_Type * const dpResultX, const LibCore_Ifl_DPResultF32_Type * const dpResultY, uint32 num_value, const float32 * Val_array, boolean isMatlabMap)
{
   if (0 == isMatlabMap) {
      return Val_array[dpResultX->Index * num_value + dpResultY->Index];
   } else {
      return Val_array[dpResultY->Index * num_value + dpResultX->Index];
   }
}

