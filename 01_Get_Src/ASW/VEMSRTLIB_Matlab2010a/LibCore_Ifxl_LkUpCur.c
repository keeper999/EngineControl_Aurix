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

#include "LibCore_Ifxl_LkUpCur.h"

/*
Curve look-up
*/

uint8 LibCore_Ifxl_LkUpCur_u8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint8 * Val_array)
{
   return Val_array[dpResult->Index];
}

sint8 LibCore_Ifxl_LkUpCur_s8(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint8 * Val_array)
{
   return Val_array[dpResult->Index];
}

uint16 LibCore_Ifxl_LkUpCur_u16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint16 * Val_array)
{
   return Val_array[dpResult->Index];
}

sint16 LibCore_Ifxl_LkUpCur_s16(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint16 * Val_array)
{
   return Val_array[dpResult->Index];
}

uint32 LibCore_Ifxl_LkUpCur_u32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const uint32 * Val_array)
{
   return Val_array[dpResult->Index];
}

sint32 LibCore_Ifxl_LkUpCur_s32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const sint32 * Val_array)
{
   return Val_array[dpResult->Index];
}

float32 LibCore_Ifxl_LkUpCur_f32(const LibCore_Ifl_DPResultF32_Type * const dpResult, const float32 * Val_array)
{
   return Val_array[dpResult->Index];
}

