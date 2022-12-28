/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_Lib                                              */
/* !Description :       librairie math                                        */
/*                                                                            */
/* !File :              FISA_lib.h                                            */
/*                                                                            */
/* !Scope :             Public                                                */
/*                                                                            */
/* !Target :            All                                                   */
/*                                                                            */
/* !Vendor :            Valeo                                                 */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_lib.h_v          $   */
/* $Revision::   1.11      $$Author::   flavergn$$Date::   21 Jul 2010 15:$   */
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef __FISA_LIB_H__
#define __FISA_LIB_H__

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/

#include "Rte_FISA.h"
#include "FISA_fixed.h"
#include "FISA_Calibration.h"


/******************************************************************************/
/* DEFINITION OF STRUCTURE                                                    */
/******************************************************************************/


typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   VAR(UInt8,FISA_VAR)    Ny;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) y_table;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) z_table;
} MAP_Table_2D;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   VAR(UInt8,FISA_VAR)    Ny;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) y_table;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) z_table;
} MAP_Table_2D_yU16_S16;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   VAR(UInt8,FISA_VAR)    Ny;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) y_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) z_table;
} MAP_Table_2D_U16;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   VAR(UInt8,FISA_VAR)    Ny;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) y_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) z_table;
} MAP_Table_2D_xU16_U16;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   VAR(UInt8,FISA_VAR)    Ny;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) y_table;
   P2CONST(UInt8, FISA_APPL_CONST, FISA_CARTO)  z_table;
} MAP_Table_2D_U8;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   VAR(UInt8,FISA_VAR)    Ny;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) y_table;
   P2CONST(SInt8, FISA_APPL_CONST, FISA_CARTO)  z_table;
} MAP_Table_2D_S8;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) z_table;
} MAP_Table_1D;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) z_table;
} MAP_Table_1D_U16;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   P2CONST(SInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt8, FISA_APPL_CONST, FISA_CARTO)  z_table;
} MAP_Table_1D_U8;

typedef struct {
   VAR(UInt8,FISA_VAR)    Nx;
   P2CONST(UInt16, FISA_APPL_CONST, FISA_CARTO) x_table;
   P2CONST(UInt8, FISA_APPL_CONST, FISA_CARTO)  z_table;
} MAP_Table_1D_xU16_U8;

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/
#define FISE_ERREUR_NONE          0
#define FISA_ERREUR_DETERMVAL     1
#define FISA_ERREUR_READERROR     2
#define FISA_ERREUR_WRITEERROR    3
#define FISA_ERREUR_NULL_POINTER  4
#define FISA_ERREUR_SUPERVFCTADAP 5
#define FISA_ERREUR_APPRENTIQLT   6
#define FISA_ERREUR_CONFIRMATION  7
#define FISA_ERREUR_HORSPLAGE     8
#define FISA_ERREUR_FIXED         9
#define FISA_ERREUR_SUPERVFCTOPTI 10

#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

/******************************************************************************/
/* DECLARATION OF FUNCTIONS                                                   */
/******************************************************************************/
FUNC(Boolean,FISA_CODE) Delay1_Boolean ( P2CONST(Boolean, FISA_APPL_DATA, AUTOMATIC) current_value,
                P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) delay1);

FUNC(UInt16,FISA_CODE) Delay1_UINT16(  P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) current_value,
                  P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) delay1);
                  
FUNC(SInt16,FISA_CODE) Delay1_SINT16(  P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) current_value,
                  P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) delay1);

FUNC(SInt16,FISA_CODE) Accum_Sat_Analyse_SInt16 (  SInt16 Inc_man, SInt16 Inc_exp, Boolean On, SInt16 Min_man , SInt16 Min_exp, SInt16 Max_man, SInt16 Max_exp,
                      P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) Mem_man, SInt16 output_exp, Boolean firstTime);

FUNC(SInt16,FISA_CODE) Accum_Sat_Analisys_without_FIX ( SInt16 Inc, Boolean On, SInt16 Min, SInt16 Max, P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) Mem, Boolean firstTime);

FUNC(SInt32,FISA_CODE) Saturation_FIX (P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Value_f, SInt32 Max_man, SInt16 Max_exp, SInt32 Min_man , SInt16 Min_exp );

FUNC(SInt32,FISA_CODE) Saturation_tout_FIX (P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Value_f,
                                       P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Max_f,
                                       P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Min_f, SInt16 output_exp);

FUNC(SInt32,FISA_CODE) Saturation_INT (SInt32 Value, SInt32 Max, SInt32 Min);

FUNC(SInt8,FISA_CODE)  Saturation_INT_S8 (SInt16 Value, SInt16 Max, SInt16 Min);

FUNC(UInt8,FISA_CODE)  Saturation_INT_U8 (UInt8 Value, UInt8 Max, UInt8 Min);

FUNC(UInt16,FISA_CODE) Saturation_INT_U16 (UInt16 Value, UInt16 Max, UInt16 Min);

FUNC(SInt32,FISA_CODE) DivWithAntiDiVByZero(SInt32 dividend_man, SInt16 dividend_exp , SInt32 divisor_man, SInt16 divisor_exp , SInt16 output_exp);

FUNC(void,FISA_CODE)   DivWithAntiDiVByZeroFix(SInt32 dividend_man, SInt16 dividend_exp , SInt32 divisor_man, SInt16 divisor_exp , ts_fixed *result_f);

FUNC(SInt16,FISA_CODE) FISA_MIN16 (SInt16 Value1, SInt16 Value2);

FUNC(SInt32,FISA_CODE) FISA_MIN (SInt32 Value1, SInt32 Value2);

FUNC(SInt32,FISA_CODE) FISA_MAX (SInt32 Value1, SInt32 Value2);

FUNC(UInt16,FISA_CODE) FISA_U16MAX (UInt16 Value1, UInt16 Value2);

FUNC(UInt32,FISA_CODE) FISA_UMIN (UInt32 Value1, UInt32 Value2);

FUNC(UInt8,FISA_CODE)  FISA_U8MIN (UInt8 Value1, UInt8 Value2);

FUNC(UInt32,FISA_CODE) FISA_UMAX (UInt32 Value1, UInt32 Value2);

FUNC(UInt8,FISA_CODE)  FISA_U8MAX (UInt8 Value1, UInt8 Value2);

FUNC(SInt16,FISA_CODE) lookup2D(P2CONST(MAP_Table_2D, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, SInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                SInt16 fm);

FUNC(SInt16,FISA_CODE) lookup2D_yU16_S16(P2CONST(MAP_Table_2D_yU16_S16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                SInt16 fm);


FUNC(UInt16,FISA_CODE) lookup2D_yU16_U16(P2CONST(MAP_Table_2D_U16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                UInt16 fm);

FUNC(UInt16,FISA_CODE) lookup2D_xyU16_U16(P2CONST(MAP_Table_2D_xU16_U16, FISA_APPL_DATA, AUTOMATIC) map,
                UInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                UInt16 fm);

FUNC(SInt32,FISA_CODE) lookup2D_rS32_U8(P2CONST(MAP_Table_2D_U8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                SInt16 fm);

FUNC(SInt32,FISA_CODE) lookup2D_rS32_S8(P2CONST(MAP_Table_2D_S8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, SInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow);

FUNC(SInt16,FISA_CODE) lookup1D(P2CONST(MAP_Table_1D, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                SInt16 fm);

FUNC(UInt16,FISA_CODE) lookup1D_U16(P2CONST(MAP_Table_1D_U16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm);

FUNC(UInt32,FISA_CODE) lookup1D_rU32_U16(P2CONST(MAP_Table_1D_U16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow);

FUNC(UInt8,FISA_CODE) lookup1D_U8(P2CONST(MAP_Table_1D_U8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm,UInt16 fd);

FUNC(SInt16,FISA_CODE) lookup1D_rS16_U8(P2CONST(MAP_Table_1D_U8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm);

FUNC(SInt16,FISA_CODE) lookup1D_rS16_xU16_U8(P2CONST(MAP_Table_1D_xU16_U8, FISA_APPL_DATA, AUTOMATIC) map,
                UInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm);

FUNC(void,FISA_CODE)   FISA_erreur_(UInt8 type_erreur);
#define FISA_erreur(type_erreur) FISA_erreur_((UInt8)type_erreur)

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

#endif /* __FISA_LIB_H__ */
