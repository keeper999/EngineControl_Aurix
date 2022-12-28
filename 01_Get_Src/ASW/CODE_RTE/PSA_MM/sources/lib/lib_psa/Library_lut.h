/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: Library_lut.h %
*
* %version: 5.7 %
*
* %date_modified: Tue Nov 12 11:26:21 2013 %
*
*
* %derived_by: u299919 %
* %release: Pack_Integrateur/5.0 %
* %full_filespec: Library_lut.h-5.7:incl:5 %
*
*******************************************************************************/

/*******************************************************************************
* Description : Code
* Auteur      : CLO
*******************************************************************************/

#ifndef _LIBRARY_LUT_H_
#define _LIBRARY_LUT_H_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_basetypes.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/

typedef struct MAP_Tab1DS2I2T524_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I2T524;
typedef struct MAP_Tab2DS34I2T1_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const UInt8 * y_table;
   const UInt8 * z_table;
} MAP_Tab2DS34I2T1;

typedef struct MAP_Tab2DS0I2T4168_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt8 * x_table;
   const UInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS0I2T4168;
typedef struct MAP_Tab1DS2I2T1_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS2I2T1;
typedef struct MAP_Tab1DS2I2T2081_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS2I2T2081;
typedef struct MAP_Tab1DS2I2T521_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I2T521;

typedef struct MAP_Tab1DS2I2T0_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS2I2T0;
typedef struct MAP_Tab2DS34I2T4172_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const UInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4172;
typedef struct MAP_Tab2DS34I2T12_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const UInt16 * y_table;
   const UInt8 * z_table;
} MAP_Tab2DS34I2T12;
typedef struct MAP_Tab1DS2I2T4_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS2I2T4;
typedef struct MAP_Tab1DS0I6T0_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I6T0;
typedef struct MAP_Tab1DS2I4T520_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I4T520;
typedef struct MAP_Tab1DS2I4T4_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS2I4T4;
typedef struct MAP_Tab1DS0I2T524_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS0I2T524;
typedef struct MAP_Tab1DS2I2T520_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I2T520;
typedef struct MAP_Tab1DS0I2T520_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS0I2T520;
typedef struct MAP_Tab1DS2I2T1560_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const SInt8 * z_table;
} MAP_Tab1DS2I2T1560;
typedef struct MAP_Tab1DS2I2T1044_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt32 * z_table;
} MAP_Tab1DS2I2T1044;
typedef struct MAP_Tab2DS34I2T33_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const SInt16 * y_table;
   const UInt8 * z_table;
} MAP_Tab2DS34I2T33;
typedef struct MAP_Tab1DS2I4T2084_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS2I4T2084;
typedef struct MAP_Tab1DS2I4T0_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS2I4T0;
typedef struct MAP_Tab1DS0I2T0_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I2T0;
typedef struct MAP_Tab1DS0I4T3_tag {
   UInt8 Nx;
   const SInt8 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I4T3;
typedef struct MAP_Tab1DS2I6T2_tag {
   UInt8 Nx;
   const UInt32 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS2I6T2;
typedef struct MAP_Tab2DS34I2T4192_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt8 * x_table;
   const SInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4192;
typedef struct MAP_Tab1DS2I2T1562_tag {
   UInt8 Nx;
   const UInt32 * x_table;
   const SInt8 * z_table;
} MAP_Tab1DS2I2T1562;
typedef struct MAP_Tab1DS2I2T2083_tag {
   UInt8 Nx;
   const SInt8 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS2I2T2083;
typedef struct MAP_Tab2DS34I2T4196_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const SInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4196;
typedef struct MAP_Tab1DS0I2T4_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I2T4;
typedef struct MAP_Tab1DS0I2T1_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I2T1;
typedef struct MAP_Tab1DS0I2T1042_tag {
   UInt8 Nx;
   const UInt32 * x_table;
   const UInt32 * z_table;
} MAP_Tab1DS0I2T1042;
typedef struct MAP_Tab1DS0I2T1045_tag {
   UInt8 Nx;
   const SInt32 * x_table;
   const UInt32 * z_table;
} MAP_Tab1DS0I2T1045;
typedef struct MAP_Tab1DS0I2T1043_tag {
   UInt8 Nx;
   const SInt8 * x_table;
   const UInt32 * z_table;
} MAP_Tab1DS0I2T1043;
typedef struct MAP_Tab2DS34I2T4193_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const SInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4193;
typedef struct MAP_Tab1DS0I2T2080_tag {
   UInt8 Nx;
   const UInt8 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS0I2T2080;
typedef struct MAP_Tab2DS0I2T16676_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const SInt16 * y_table;
   const SInt16 * z_table;
} MAP_Tab2DS0I2T16676;
typedef struct MAP_Tab2DS0I2T4193_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const SInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS0I2T4193;
typedef struct MAP_Tab1DS0I2T523_tag {
   UInt8 Nx;
   const SInt8 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS0I2T523;
typedef struct MAP_Tab1DS0I2T521_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS0I2T521;
typedef struct MAP_Tab1DS0I2T2084_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS0I2T2084;
typedef struct MAP_Tab1DS0I4T1_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I4T1;
typedef struct MAP_Tab1DS2I4T524_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I4T524;
typedef struct MAP_Tab1DS2I2T1041_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt32 * z_table;
} MAP_Tab1DS2I2T1041;
typedef struct MAP_Tab1DS2I2T1042_tag {
   UInt8 Nx;
   const UInt32 * x_table;
   const UInt32 * z_table;
} MAP_Tab1DS2I2T1042;
typedef struct MAP_Tab1DS2I4T521_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I4T521;
typedef struct MAP_Tab1DS2I4T522_tag {
   UInt8 Nx;
   const UInt32 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I4T522;
typedef struct MAP_Tab1DS2I2T522_tag {
   UInt8 Nx;
   const UInt32 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I2T522;
typedef struct MAP_Tab2DS0I2T4196_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const SInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS0I2T4196;
typedef struct MAP_Tab2DS0I2T16673_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const SInt16 * y_table;
   const SInt16 * z_table;
} MAP_Tab2DS0I2T16673;
typedef struct MAP_Tab1DS0I2T3_tag {
   UInt8 Nx;
   const SInt8 * x_table;
   const UInt8 * z_table;
} MAP_Tab1DS0I2T3;
typedef struct MAP_Tab1DS0I2T2604_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const SInt32 * z_table;
} MAP_Tab1DS0I2T2604;
typedef struct MAP_Tab1DS0I2T2081_tag {
   UInt8 Nx;
   const UInt16 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS0I2T2081;
typedef struct MAP_Tab1DS0I2T3081_tag {
   uint8 Nx;
   const UInt16 * x_table;
   const UInt16 * z_table;
   float32 xLSB;
   float32 xO;
   float32 zLSB;
   float32 zO;
} MAP_Tab1DS0I2T3081;
typedef struct MAP_Tab1DS0I2T3084_tag {
   uint8 Nx;
   const SInt16 * x_table;
   const UInt16 * z_table;
   float32 xLSB;
   float32 xO;
   float32 zLSB;
   float32 zO;
} MAP_Tab1DS0I2T3084;
typedef struct MAP_Tab1DS0I2T522_tag {
   uint8 Nx;
   const UInt32 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS0I2T522;
typedef struct MAP_Tab1DS2I2T3084_tag {
   uint8 Nx;
   const SInt16 * x_table;
   const UInt16 * z_table;
   float32 xLSB;
   float32 xO;
   float32 zLSB;
   float32 zO;
} MAP_Tab1DS2I2T3084;
typedef struct MAP_Tab1DS0I2T2083_tag {
   uint8 Nx;
   const SInt8 * x_table;
   const SInt16 * z_table;
} MAP_Tab1DS0I2T2083;
typedef struct MAP_Tab1DS0I2T3126_tag {
   uint8 Nx;
   const float32 * x_table;
   const float32 * z_table;
} MAP_Tab1DS0I2T3126;
typedef struct MAP_Tab2DS34I2T4164_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const UInt8 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4164;
typedef struct MAP_Tab2DS34I2T4168_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt8 * x_table;
   const UInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4168;
typedef struct MAP_Tab2DS34I2T4169_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const UInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4169;

typedef struct MAP_Tab2DS0I2T4161_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const UInt8 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS0I2T4161;
typedef struct MAP_Tab2DS0I2T4194_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt32 * x_table;
   const SInt16 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS0I2T4194;
typedef struct MAP_Tab1DS2I0T524_tag {
   UInt8 Nx;
   const SInt16 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS2I0T524;
typedef struct MAP_Tab1DS0I2T525_tag {
   UInt8 Nx;
   const SInt32 * x_table;
   const UInt16 * z_table;
} MAP_Tab1DS0I2T525;
typedef struct MAP_Tab2DS34I2T4161_tag {
   UInt8 Nx;
   UInt8 Ny;
   const UInt16 * x_table;
   const UInt8 * y_table;
   const UInt16 * z_table;
} MAP_Tab2DS34I2T4161;
typedef struct MAP_Tab2DS34I2T36_tag {
   UInt8 Nx;
   UInt8 Ny;
   const SInt16 * x_table;
   const SInt16 * y_table;
   const UInt8 * z_table;
} MAP_Tab2DS34I2T36;

/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

extern UInt8 Tab1DS2I2T0(const MAP_Tab1DS2I2T0 * map, UInt8 x, UInt8 * local_xLow);
extern UInt16 Tab1DS2I2T524(const MAP_Tab1DS2I2T524 * map, SInt16 x, UInt8 * local_xLow);
extern UInt8 Tab2DS34I2T1(const MAP_Tab2DS34I2T1 * map, UInt16 x, UInt8 y, UInt8 * local_xLow, UInt8 * local_yLow);
extern SInt16 Tab1DS2I2T2081(const MAP_Tab1DS2I2T2081 * map, UInt16 x, UInt8 * local_xLow);
extern UInt16 Tab1DIntp2I1T1(const UInt16 * z_table, UInt8 irx, UInt8 fractionX);
extern UInt16 Tab1DS2I2T521(const MAP_Tab1DS2I2T521 * map, UInt16 x, UInt8 * local_xLow);
extern UInt8 Tab1DIntp2I1T0(const UInt8 * z_table, UInt8 irx, UInt8 fractionX);
extern UInt8 Tab1DS2I2T1(const MAP_Tab1DS2I2T1 * map, UInt16 x, UInt8 * local_xLow);
extern Void TabIdxS50T1(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt8 * fraction);
extern SInt16 Tab1DIntp2I1T4(const SInt16 * z_table, UInt8 irx, UInt8 fractionX);
extern Void TabIdxS50T4(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 * irx, UInt8 * fraction);
extern UInt16 Tab2DS34I2T4172(const MAP_Tab2DS34I2T4172 * map, SInt16 x, UInt16 y, UInt8 * local_xLow, UInt8 * local_yLow);
extern UInt8 Tab2DS34I2T12(const MAP_Tab2DS34I2T12 * map, SInt16 x, UInt16 y, UInt8 * local_xLow, UInt8 * local_yLow);
extern UInt8 Tab1DS2I2T4(const MAP_Tab1DS2I2T4 * map, SInt16 x, UInt8 * local_xLow);
extern UInt8 Tab1DS0I6T0(const MAP_Tab1DS0I6T0 * map, UInt8 x);
extern UInt16 Tab1DS2I4T520(const MAP_Tab1DS2I4T520 * map, UInt8 x, UInt8 * local_xLow);
extern UInt8 Tab1DS2I4T4(const MAP_Tab1DS2I4T4 * map, SInt16 x, UInt8 * local_xLow);
extern UInt16 Tab1DS0I2T524(const MAP_Tab1DS0I2T524 * map, SInt16 x);
extern UInt16 Tab1DS2I2T520(const MAP_Tab1DS2I2T520 * map, UInt8 x, UInt8 * local_xLow);
extern UInt16 Tab1DS0I2T520(const MAP_Tab1DS0I2T520 * map, UInt8 x);
extern Void TabIdxS50T0(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt8 * fraction);
extern SInt8 Tab1DS2I2T1560(const MAP_Tab1DS2I2T1560 * map, UInt8 x, UInt8 * local_xLow);
extern Void TabIdxS50T513(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt16 * fraction);
extern Void TabIdxS50T516(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 * irx, UInt16 * fraction);
extern SInt16 Tab2DIntp2I1T33284(const SInt16 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry, UInt16 fractionY);
extern UInt16 Tab2DIntp2I1T33281(const UInt16 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry, UInt16 fractionY);
extern UInt32 Tab1DS2I2T1044(const MAP_Tab1DS2I2T1044 * map, SInt16 x, UInt8 * local_xLow);
extern UInt8 Tab2DS34I2T33(const MAP_Tab2DS34I2T33 * map, UInt16 x, SInt16 y, UInt8 * local_xLow, UInt8 * local_yLow);
extern SInt16 Tab1DS2I4T2084(const MAP_Tab1DS2I4T2084 * map, SInt16 x, UInt8 * local_xLow);
extern UInt8 Tab1DS2I4T0(const MAP_Tab1DS2I4T0 * map, UInt8 x, UInt8 * local_xLow);
extern UInt8 Tab1DS0I2T0(const MAP_Tab1DS0I2T0 * map, UInt8 x);
extern UInt8 Tab1DS0I4T3(const MAP_Tab1DS0I4T3 * map, SInt8 x);
extern UInt8 Tab1DS2I6T2(const MAP_Tab1DS2I6T2 * map, UInt32 x, UInt8 * local_xLow);
extern UInt16 Tab2DS34I2T4192(const MAP_Tab2DS34I2T4192 * map, UInt8 x, SInt16 y, UInt8 *local_xLow, UInt8 * local_yLow);
extern SInt8 Tab1DS2I2T1562(const MAP_Tab1DS2I2T1562 * map, UInt32 x, UInt8 * local_xLow);
extern SInt16 Tab1DS2I2T2083(const MAP_Tab1DS2I2T2083 * map, SInt8 x, UInt8 * local_xLow);
extern UInt16 Tab2DS34I2T4196(const MAP_Tab2DS34I2T4196 * map, SInt16 x, SInt16 y, UInt8 *local_xLow, UInt8 * local_yLow);
extern UInt8 Tab1DS0I2T4(const MAP_Tab1DS0I2T4 * map, SInt16 x);
extern Void TabIdxS50T3(const SInt8 * x_table, UInt8 N, SInt8 x, UInt8 * irx, UInt8 * fraction);
extern UInt8 Tab2DIntp2I1T0(const UInt8 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry,UInt8 fractionY);
extern SInt16 Tab2DIntp2I1T4(const SInt16 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry,UInt8 fractionY);
extern UInt8 Tab1DS0I2T1(const MAP_Tab1DS0I2T1 * map, UInt16 x);
extern UInt32 Tab2DIntp2I1T2(const UInt32 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry,UInt8 fractionY);
extern UInt32 Tab1DS0I2T1042(const MAP_Tab1DS0I2T1042 * map, UInt32 x);
extern UInt32 Tab1DS0I2T1045(const MAP_Tab1DS0I2T1045 * map, SInt32 x);
extern Void TabIdxS50T2(const UInt32 * x_table, UInt8 N, UInt32 x, UInt8 * irx, UInt8 * fraction);
extern UInt16 Tab2DIntp2I1T1(const UInt16 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry,UInt8 fractionY);
extern UInt32 Tab1DS0I2T1043(const MAP_Tab1DS0I2T1043 * map, SInt8 x);
extern UInt16 Tab2DS34I2T4193(const MAP_Tab2DS34I2T4193 * map, UInt16 x, SInt16 y, UInt8 *local_xLow, UInt8 * local_yLow);
extern SInt16 Tab1DS0I2T2080(const MAP_Tab1DS0I2T2080 * map, UInt8 x);
extern SInt16 Tab2DS0I2T16676(const MAP_Tab2DS0I2T16676 * map, SInt16 x, SInt16 y);
extern UInt16 Tab2DS0I2T4193(const MAP_Tab2DS0I2T4193 * map, UInt16 x, SInt16 y);
extern UInt16 Tab1DS0I2T523(const MAP_Tab1DS0I2T523 * map, SInt8 x);
extern UInt16 Tab1DS0I2T521(const MAP_Tab1DS0I2T521 * map, UInt16 x);
extern Void TabIdxS49T1(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt8 * fraction);
extern SInt16 Tab1DS0I2T2084(const MAP_Tab1DS0I2T2084 * map, SInt16 x);
extern UInt8 Tab1DS0I4T1(const MAP_Tab1DS0I4T1 * map, UInt16 x);
extern UInt16 Tab1DS2I4T524(const MAP_Tab1DS2I4T524 * map, SInt16 x, UInt8 * local_xLow);
extern UInt16 Tab2DS0I2T4168(const MAP_Tab2DS0I2T4168 * map, UInt8 x, UInt16 y);
extern UInt32 Tab1DS2I2T1041(const MAP_Tab1DS2I2T1041 * map, UInt16 x, UInt8 * local_xLow);
extern UInt32 Tab1DS2I2T1042(const MAP_Tab1DS2I2T1042 * map, UInt32 x, UInt8 * local_xLow);
extern UInt16 Tab1DS2I4T521(const MAP_Tab1DS2I4T521 * map, UInt16 x, UInt8 * local_xLow);
extern UInt16 Tab1DS2I4T522(const MAP_Tab1DS2I4T522 * map, UInt32 x, UInt8 * local_xLow);
extern UInt16 Tab1DS2I2T522(const MAP_Tab1DS2I2T522 * map, UInt32 x, UInt8 * local_xLow);
extern UInt16 Tab2DS0I2T4196(const MAP_Tab2DS0I2T4196 * map, SInt16 x, SInt16 y);
extern SInt16 Tab2DS0I2T16673(const MAP_Tab2DS0I2T16673 * map, UInt16 x, SInt16 y);
extern UInt8 Tab1DS0I2T3(const MAP_Tab1DS0I2T3 * map, SInt8 x);
extern SInt32 Tab1DS0I2T2604(const MAP_Tab1DS0I2T2604 * map, SInt16 x);
extern SInt16 Tab1DS0I2T2081(const MAP_Tab1DS0I2T2081 * map, UInt16 x);
extern float32 Tab1DIntp2I1T390(const float32 * z_table, uint8 irx, float32 fractionX);
extern float32 Tab1DS0I2T3081(const MAP_Tab1DS0I2T3081 * map, float32 x);
extern float32 Tab1DS0I2T3084(const MAP_Tab1DS0I2T3084 * map, float32 x);
extern float32 Tab1DS2I2T3084(const MAP_Tab1DS2I2T3084 * map, float32 x, uint8 * local_xLow);
extern UInt16 Tab1DS0I2T522(const MAP_Tab1DS0I2T522 * map, UInt32 x);


extern float32 Tab2DIntp2I1T33286(const float32 * z_table, uint8 N, uint8 irx, UInt16 fractionX,
   uint8 iry, UInt16 fractionY);

extern void TabIdxS50T3076(const SInt16 * x_table, uint8 N, SInt16 x, uint8 * irx, float32 *
   fraction);

extern void TabIdxS50T3073(const UInt16 * x_table, uint8 N, UInt16 x, uint8 * irx, float32 *
   fraction);

extern float32 Tab2DIntp2I1T199686(const float32 * z_table, uint8 N, uint8 irx, float32 fractionX,
   uint8 iry, float32 fractionY);

extern UInt16 Tab1DIntp2I1T385(const UInt16 * z_table, uint8 irx, float32 fractionX);

/******************************************************************************\
   UserGlobalLookup1D_LibraryLut: Derived TL_CG default function class.
\******************************************************************************/
extern UInt32 Tab1DIntp2I1T66(const UInt32 * z_table, UInt8 irx, UInt16 fractionX);
extern SInt32 Tab1DIntp2I1T69(const SInt32 * z_table, UInt8 irx, UInt16 fractionX);
extern UInt32 Tab2DIntp2I1T33282(const UInt32 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8
     iry, UInt16 fractionY);
extern SInt32 Tab2DIntp2I1T33285(const SInt32 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8
     iry, UInt16 fractionY);

/******************************************************************************\
   UserGlobalLookup1D_LibraryLut: Derived TL_CG default function class.
\******************************************************************************/
extern UInt16 Tab1DIntp2I1T65(const UInt16 * z_table, UInt8 irx, UInt16 fractionX);
extern SInt16 Tab1DIntp2I1T68(const SInt16 * z_table, UInt8 irx, UInt16 fractionX);

/******************************************************************************\
   UserGlobalLookup1D_LibraryLut: Derived TL_CG default function class.
\******************************************************************************/
extern UInt8 Tab1DIntp2I1T64(const UInt8 * z_table, UInt8 irx, UInt16 fractionX);
extern SInt8 Tab1DIntp2I1T67(const SInt8 * z_table, UInt8 irx, UInt16 fractionX);
extern UInt8 Tab2DIntp2I1T33280(const UInt8 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8
    iry, UInt16 fractionY);
extern SInt8 Tab2DIntp2I1T33283(const SInt8 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8
    iry, UInt16 fractionY);
extern UInt8 Tab1DIntp2I1T128(const UInt8 * z_table, UInt8 irx, UInt32 fractionX);

/******************************************************************************\
   UserGlobalLookup1D_LibraryLut: Derived TL_CG default function class.
\******************************************************************************/
extern Void TabIdxS50T512(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt16 * fraction);
extern Void TabIdxS50T514(const UInt32 * x_table, UInt8 N, UInt32 x, UInt8 * irx, UInt16 *
    fraction);
extern Void TabIdxS50T515(const SInt8 * x_table, UInt8 N, SInt8 x, UInt8 * irx, UInt16 * fraction);
extern Void TabIdxS50T517(const SInt32 * x_table, UInt8 N, SInt32 x, UInt8 * irx, UInt16 *
    fraction);
extern void TabIdxS50T1028(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 * irx, UInt32 *
   fraction);
extern void TabIdxS50T1024(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt32 * fraction);
extern void TabIdxS48T0(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt8 * fraction);
extern void TabIdxS50T3078(const float32 * x_table, uint8 N, float32 x, uint8 * irx, float32 *
   fraction);
extern SInt16 Tab1DS0I2T2083(const MAP_Tab1DS0I2T2083 * map, SInt8 x);
extern float32 Tab1DS0I2T3126(const MAP_Tab1DS0I2T3126 * map, float32 x);


extern UInt16 Tab2DS34I2T4164(const MAP_Tab2DS34I2T4164 * map, SInt16 x, UInt8 y, UInt8 *
    local_xLow, UInt8 * local_yLow);
extern UInt16 Tab2DS34I2T4168(const MAP_Tab2DS34I2T4168 * map, UInt8 x, UInt16 y, UInt8 *
    local_xLow, UInt8 * local_yLow);
extern UInt16 Tab2DS34I2T4169(const MAP_Tab2DS34I2T4169 * map, UInt16 x, UInt16 y, UInt8 *
    local_xLow, UInt8 * local_yLow);
/******************************************************************************\
   UserGlobalLookup1D_LibraryLut: Derived TL_CG default function class.
\******************************************************************************/
extern SInt16 Tab1DIntpI1T20(const SInt16 * z_table, UInt32 irx[2]);
extern UInt16 Tab2DIntpI1T1153(const UInt16 * z_table, UInt8 N, UInt32 irx[2], UInt32 iry[2]);
extern Void TabIdxS16T144(const UInt8 * x_table, UInt32 N, UInt8 x, UInt32 irx[2]);
extern SInt16 Tab2DIntpI1T1156(const SInt16 * z_table, UInt8 N, UInt32 irx[2], UInt32 iry[2]);
extern Void TabIdxS16T145(const UInt16 * x_table, UInt32 N, UInt16 x, UInt32 irx[2]);
extern Void TabIdxS16T72(const UInt8 * x_table, UInt16 N, UInt8 x, UInt16 irx[2]);
extern UInt8 Tab1DIntpI1T8(const UInt8 * z_table, UInt16 irx[2]);
extern UInt8 Tab1DIntpI1T0(const UInt8 * z_table, UInt8 irx[2]);
extern Void TabIdxS18T0(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 irx[2]);
extern Void TabIdxS50T1025(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt32 *
    fraction);
extern Void TabIdxS50T1169(const UInt16 * x_table, UInt32 N, UInt16 x, UInt32 * irx, UInt32 *
    fraction);
extern SInt16 Tab2DIntp2I1T66692(const SInt16 * z_table, UInt8 N, UInt32 irx, UInt32 fractionX,
    UInt8 iry, UInt32 fractionY);
extern SInt8 Tab2DIntp2I1T66691(const SInt8 * z_table, UInt8 N, UInt32 irx, UInt32 fractionX, UInt8
    iry, UInt32 fractionY);
extern SInt16 Tab2DIntp2I1T66564(const SInt16 * z_table, UInt8 N, UInt8 irx, UInt32 fractionX, UInt8
     iry, UInt32 fractionY);
extern Void TabIdxS48T1025(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt32 *
    fraction);
extern Void TabIdxS48T1024(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt32 * fraction);
extern Void TabIdxS50T1168(const UInt8 * x_table, UInt32 N, UInt8 x, UInt32 * irx, UInt32 *
    fraction);
extern UInt16 Tab2DIntp2I1T66561(const UInt16 * z_table, UInt8 N, UInt8 irx, UInt32 fractionX, UInt8
     iry, UInt32 fractionY);
extern UInt16 Tab1DIntp2I1T145(const UInt16 * z_table, UInt32 irx, UInt32 fractionX);
extern UInt16 Tab2DS0I2T4161(const MAP_Tab2DS0I2T4161 * map, UInt16 x, UInt8 y);
extern UInt16 Tab1DS2I0T524(const MAP_Tab1DS2I0T524 * map, SInt16 x, UInt8 * local_xLow);
extern UInt16 Tab2DS0I2T4194(const MAP_Tab2DS0I2T4194 * map, UInt32 x, SInt16 y);
extern Void TabIdxS18T73(const UInt16 * x_table, UInt16 N, UInt16 x, UInt16 irx[2]);
extern Void TabIdxS18T72(const UInt8 * x_table, UInt16 N, UInt8 x, UInt16 irx[2]);
extern Void TabIdxS18T76(const SInt16 * x_table, UInt16 N, SInt16 x, UInt16 irx[2]);
extern UInt16 Tab2DIntpI1T577(const UInt16 * z_table, UInt8 N, UInt16 irx[2], UInt16 iry[2]);
extern Void TabIdxS16T73(const UInt16 * x_table, UInt16 N, UInt16 x, UInt16 irx[2]);
extern Void TabIdxS16T76(const SInt16 * x_table, UInt16 N, SInt16 x, UInt16 irx[2]);
extern UInt16 Tab1DIntpI1T9(const UInt16 * z_table, UInt16 irx[2]);
extern Void TabIdxS16T4(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 irx[2]);
extern UInt16 Tab2DIntpI1T65(const UInt16 * z_table, UInt8 N, UInt16 irx[2], UInt8 iry[2]);
extern Void TabIdxS16T74(const UInt32 * x_table, UInt16 N, UInt32 x, UInt16 irx[2]);
extern UInt32 Tab2DIntpI1T578(const UInt32 * z_table, UInt8 N, UInt16 irx[2], UInt16 iry[2]);
extern UInt16 Tab1DS0I2T525(const MAP_Tab1DS0I2T525 * map, SInt32 x);
extern UInt16 Tab1DIntpI1T1(const UInt16 * z_table, UInt8 irx[2]);
extern UInt16 Tab1DIntp2I1T129(const UInt16 * z_table, UInt8 irx, UInt32 fractionX);
extern UInt16 Tab2DIntp2I1T199681(const UInt16 * z_table, UInt8 N, UInt8 irx, float32 fractionX,
    UInt8 iry, float32 fractionY);
extern UInt16 Tab2DS34I2T4161(const MAP_Tab2DS34I2T4161 * map, UInt16 x, UInt8 y, UInt8 *
    local_xLow, UInt8 * local_yLow);
extern UInt8 Tab2DS34I2T36(const MAP_Tab2DS34I2T36 * map, SInt16 x, SInt16 y, UInt8 * local_xLow,
    UInt8 * local_yLow);

#endif/*_LIBRARY_LUT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
