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

#include "LibCore_Ifxl_DPSearch.h"

/*
Data Point Search
*/

void LibCore_Ifxl_DPSearch_u8(LibCore_Ifl_DPResultF32_Type * const dpResult, uint8 Xin, uint32 N, const uint8 * X_array)
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

void LibCore_Ifxl_DPSearch_s8(LibCore_Ifl_DPResultF32_Type * const dpResult, sint8 Xin, uint32 N, const sint8 * X_array)
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

void LibCore_Ifxl_DPSearch_u16(LibCore_Ifl_DPResultF32_Type * const dpResult, uint16 Xin, uint32 N, const uint16 * X_array)
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

void LibCore_Ifxl_DPSearch_s16(LibCore_Ifl_DPResultF32_Type * const dpResult, sint16 Xin, uint32 N, const sint16 * X_array)
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

void LibCore_Ifxl_DPSearch_u32(LibCore_Ifl_DPResultF32_Type * const dpResult, uint32 Xin, uint32 N, const uint32 * X_array)
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

void LibCore_Ifxl_DPSearch_s32(LibCore_Ifl_DPResultF32_Type * const dpResult, sint32 Xin, uint32 N, const sint32 * X_array)
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

void LibCore_Ifxl_DPSearch_f32(LibCore_Ifl_DPResultF32_Type * const dpResult, float32 Xin, uint32 N, const float32 * X_array)
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

