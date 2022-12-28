/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_Ifxl.c                                            */
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

#include "ACTEMS_Ifxl.h"

/* Data Point Search */

void ACTEMS_Ifx_DPSearch_u8 (      Ifl_DPResultF32_Type * const dpResult,
                                   uint8                        Xin,
                                   uint32                       N,
                             const uint8                *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = (float32)(X_array[uLeft]);
         dpResult->Index = uLeft;
         dpResult->Ratio = ((float32)(Xin) - fXLeft) / ((float32)(X_array[uRight]) - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

void ACTEMS_Ifx_DPSearch_s8 (      Ifl_DPResultF32_Type * const dpResult,
                                   sint8                        Xin,
                                   uint32                       N,
                             const sint8                *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = (float32)(X_array[uLeft]);
         dpResult->Index = uLeft;
         dpResult->Ratio = ((float32)(Xin) - fXLeft) / ((float32)(X_array[uRight]) - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

void ACTEMS_Ifx_DPSearch_u16(      Ifl_DPResultF32_Type * const dpResult,
                                   uint16                       Xin,
                                   uint32                       N,
                             const uint16               *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = (float32)(X_array[uLeft]);
         dpResult->Index = uLeft;
         dpResult->Ratio = ((float32)(Xin) - fXLeft) / ((float32)(X_array[uRight]) - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

void ACTEMS_Ifx_DPSearch_s16(      Ifl_DPResultF32_Type * const dpResult,
                                   sint16                       Xin,
                                   uint32                       N,
                             const sint16               *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = (float32)(X_array[uLeft]);
         dpResult->Index = uLeft;
         dpResult->Ratio = ((float32)(Xin) - fXLeft) / ((float32)(X_array[uRight]) - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

void ACTEMS_Ifx_DPSearch_u32(      Ifl_DPResultF32_Type * const dpResult,
                                   uint32                       Xin,
                                   uint32                       N,
                             const uint32               *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = (float32)(X_array[uLeft]);
         dpResult->Index = uLeft;
         dpResult->Ratio = ((float32)(Xin) - fXLeft) / ((float32)(X_array[uRight]) - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

void ACTEMS_Ifx_DPSearch_s32(      Ifl_DPResultF32_Type * const dpResult,
                                   sint32                       Xin,
                                   uint32                       N,
                             const sint32               *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = (float32)(X_array[uLeft]);
         dpResult->Index = uLeft;
         dpResult->Ratio = ((float32)(Xin) - fXLeft) / ((float32)(X_array[uRight]) - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

void ACTEMS_Ifl_DPSearch_f32(      Ifl_DPResultF32_Type * const dpResult,
                                   float32                      Xin,
                                   uint32                       N,
                             const float32              *       X_array)
{
   uint32 Nm1 = (uint32)(N - 1);

   if (Xin <= X_array[0])
   {
      dpResult->Index = 0U;
      dpResult->Ratio = 0.0F;
      return;
   }
   else if (Xin < X_array[Nm1])
   {
      uint32 uLeft = 0U;
      uint32 uRight = Nm1;
      uint32 uMidle;

      while ((uRight - uLeft) > 1U) {
         uMidle = (uRight + uLeft) >> 1U;
         if (Xin < X_array[uMidle]) {
            uRight = uMidle;
         } else {
            uLeft = uMidle;
         }
      }

      if (Xin == X_array[uLeft]) {
         dpResult->Index = uLeft;
         dpResult->Ratio = 0.0F;
         return;
      } else {
         float32 fXLeft = X_array[uLeft];
         dpResult->Index = uLeft;
         dpResult->Ratio = (Xin - fXLeft) / (X_array[uRight] - fXLeft);
         return;
      }
   }
   else
   {
      dpResult->Index = Nm1;
      dpResult->Ratio = 0.0F;
      return;
   }
}

/* Curve interpolation */

float32 ACTEMS_Ifl_IpoCur_f32_u8(const Ifl_DPResultF32_Type * const dpResult,
                                 const uint8                *       Val_array)
{
   float32 f32Local_0 = (float32)(Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_1   = (float32)(Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0 + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 ACTEMS_Ifl_IpoCur_f32_s8(const Ifl_DPResultF32_Type * const dpResult,
                                 const sint8                *       Val_array)
{
   float32 f32Local_0 = (float32)(Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_1   = (float32)(Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0 + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 ACTEMS_Ifl_IpoCur_f32_u16(const Ifl_DPResultF32_Type * const dpResult,
                                  const uint16               *       Val_array)
{
   float32 f32Local_0 = (float32)(Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_1   = (float32)(Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0 + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 ACTEMS_Ifl_IpoCur_f32_s16(const Ifl_DPResultF32_Type * const dpResult,
                                  const sint16               *       Val_array)
{
   float32 f32Local_0 = (float32)(Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_1   = (float32)(Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0 + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 ACTEMS_Ifl_IpoCur_f32_u32(const Ifl_DPResultF32_Type * const dpResult,
                                  const uint32               *       Val_array)
{
   float32 f32Local_0 = (float32)(Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_1   = (float32)(Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0 + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 ACTEMS_Ifl_IpoCur_f32_s32(const Ifl_DPResultF32_Type * const dpResult,
                                  const sint32               *       Val_array)
{
   float32 f32Local_0 = (float32)(Val_array[dpResult->Index]);
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_1   = (float32)(Val_array[dpResult->Index + 1]);
      float32 f32Local_Out = f32Local_0 + (f32Local_1 - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

float32 ACTEMS_Ifl_IpoCur_f32(const Ifl_DPResultF32_Type * const dpResult,
                              const float32              *       Val_array)
{
   float32 f32Local_0 = Val_array[dpResult->Index];
   if (0.0F == dpResult->Ratio)
   {
      return f32Local_0;
   }
   else
   {
      float32 f32Local_Out = f32Local_0 + (Val_array[dpResult->Index + 1] - f32Local_0) * dpResult->Ratio;
      return f32Local_Out;
   }
}

/* Map interpolation */

/*
num_value =
  Map Matlab  : Dimension Axe 1
  Map C       : Dimension Axe 2
*/

float32 ACTEMS_Ifl_IpoMap_f32_u8(const Ifl_DPResultF32_Type * const dpResultX,
                                 const Ifl_DPResultF32_Type * const dpResultY,
                                       uint32                       num_value,
                                 const uint8                *       Val_array,
                                       boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32)(Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 ACTEMS_Ifl_IpoMap_f32_s8(const Ifl_DPResultF32_Type * const dpResultX,
                                 const Ifl_DPResultF32_Type * const dpResultY,
                                       uint32                       num_value,
                                 const sint8                *       Val_array,
                                       boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32)(Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 ACTEMS_Ifl_IpoMap_f32_u16(const Ifl_DPResultF32_Type * const dpResultX,
                                  const Ifl_DPResultF32_Type * const dpResultY,
                                        uint32                       num_value,
                                  const uint16               *       Val_array,
                                        boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32)(Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 ACTEMS_Ifl_IpoMap_f32_s16(const Ifl_DPResultF32_Type * const dpResultX,
                                  const Ifl_DPResultF32_Type * const dpResultY,
                                        uint32                       num_value,
                                  const sint16               *       Val_array,
                                        boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32)(Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 ACTEMS_Ifl_IpoMap_f32_u32(const Ifl_DPResultF32_Type * const dpResultX,
                                  const Ifl_DPResultF32_Type * const dpResultY,
                                        uint32                       num_value,
                                  const uint32               *       Val_array,
                                        boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32)(Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 ACTEMS_Ifl_IpoMap_f32_s32(const Ifl_DPResultF32_Type * const dpResultX,
                                  const Ifl_DPResultF32_Type * const dpResultY,
                                        uint32                       num_value,
                                  const sint32               *       Val_array,
                                        boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = (float32)(Val_array[BaseIndex]);
      float32 VA_01 = (float32)(Val_array[BaseIndexP1]);
      float32 VA_10 = (float32)(Val_array[BaseIndexPNum]);
      float32 VA_11 = (float32)(Val_array[BaseIndexPNumP1]);

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}

float32 ACTEMS_Ifl_IpoMap_f32(const Ifl_DPResultF32_Type * const dpResultX,
                              const Ifl_DPResultF32_Type * const dpResultY,
                                    uint32                       num_value,
                              const float32              *       Val_array,
                                    boolean                      isMatlabMap)
{
   uint32 BaseIndex;
   uint32 BaseIndexP1;
   uint32 BaseIndexPNum;
   uint32 BaseIndexPNumP1;
   if (0 == isMatlabMap)
   {
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

   if (0.0F == dpResultY->Ratio && 0.0F == dpResultX->Ratio)
   {
      return (float32)(Val_array[BaseIndex]);
   }
   else if (0.0F == dpResultY->Ratio)
   {
      float32 VA_00 = Val_array[BaseIndex];
      float32 VA_10 = Val_array[BaseIndexPNum];

      return VA_00 + (VA_10 - VA_00) * dpResultX->Ratio;
   }
   else if (0.0F == dpResultX->Ratio)
   {
      float32 VA_00 = Val_array[BaseIndex];
      float32 VA_01 = Val_array[BaseIndexP1];

      return VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
   }
   else
   {
      float32 VA_00 = Val_array[BaseIndex];
      float32 VA_01 = Val_array[BaseIndexP1];
      float32 VA_10 = Val_array[BaseIndexPNum];
      float32 VA_11 = Val_array[BaseIndexPNumP1];

      float32 VA_00_01 = VA_00 + (VA_01 - VA_00) * dpResultY->Ratio;
      float32 VA_10_11 = VA_10 + (VA_11 - VA_10) * dpResultY->Ratio;

      return VA_00_01 + (VA_10_11 - VA_00_01) * dpResultX->Ratio;
   }
}
