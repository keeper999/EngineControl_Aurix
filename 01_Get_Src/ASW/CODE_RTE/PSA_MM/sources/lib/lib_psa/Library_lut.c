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
* %name: Library_lut.c %
*
* %version: 5.7 %
*
* %date_modified: Tue Nov 12 11:26:20 2013 %
*
*
* %derived_by: u299919 %
* %release: Pack_Integrateur/5.0 %
* %full_filespec: Library_lut.c-5.7:csrc:5 %
*
*******************************************************************************/

/*******************************************************************************
* Description : Code
* Auteur      : CLO
*******************************************************************************/

#ifndef _LIBRARY_LUT_C_
#define _LIBRARY_LUT_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "Library_lut.h"
#include "dsfxp.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/


/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T0
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T0 *map                 data structure
 ***      UInt8              x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS2I2T0(const MAP_Tab1DS2I2T0 * map, UInt8 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Interpolation. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   return ((UInt8) (((UInt16) (((UInt16) (((UInt16) Aux_U8) * ((UInt16) z_table[1]))) + ((UInt16)
    (((UInt16) Aux_U8_a) * ((UInt16) z_table[0]))))) / ((UInt8) (Aux_U8 + Aux_U8_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I2T524(const MAP_Tab1DS2I2T524 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U16 = *((z_table)++);
   Aux_U16_a = *(z_table);

   /* Interpolation. */
   Aux_U16_b = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_c = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16 <= Aux_U16_a) {
      /* Positive slope. */
      Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) Aux_U16_b)) /
       Aux_U16_c));
   }
   else {
      /* Negative slope. */
      Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) Aux_U16_b)) /
       Aux_U16_c));
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T1
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T1 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      UInt8              y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab2DS34I2T1(const MAP_Tab2DS34I2T1 * map, UInt16 x, UInt8 y, UInt8 * local_xLow, UInt8 *
  local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;
   UInt8 Aux_U8_d;
   UInt8 Aux_U8_e;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * y_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16) {
      x = Aux_U16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U8_a = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U8_a) {
      y = Aux_U8_a;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U8_a = (UInt8) (y - y_table[0]);
   Aux_U8_b = (UInt8) (y_table[1] - y);
   Aux_U8_c = (UInt8) (Aux_U8_a + Aux_U8_b);

   /* Interpolation. */
   if (Aux_U8_c == 0) {
      Aux_U8_d = z_table[0];
      Aux_U8_e = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U8_d = (UInt8) (((UInt16) (((UInt16) (((UInt16) Aux_U8_b) * ((UInt16) z_table[0]))) +
       ((UInt16) (((UInt16) Aux_U8_a) * ((UInt16) z_table[1]))))) / Aux_U8_c);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U8_e = (UInt8) (((UInt16) (((UInt16) (((UInt16) Aux_U8_b) * ((UInt16) z_table[0]))) +
       ((UInt16) (((UInt16) Aux_U8_a) * ((UInt16) z_table[1]))))) / Aux_U8_c);
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);
   if (Aux_U16_b != 0) {
      /* X-Interpolation. */
      Aux_U8_d = (UInt8) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) Aux_U8_d))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) Aux_U8_e)))) / Aux_U16_b);
   }
   return Aux_U8_d;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T1
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DIntp2I1T1(const UInt16 * z_table, UInt8 irx, UInt8 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   z_table += irx;
   Aux_U16 = *((z_table)++);
   if (fractionX != 0) {
      Aux_U16_a = *(z_table);
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) fractionX)) >>
           8));
      }
      else {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) fractionX)) >>
           8));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T2081
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T2081 *map                 data structure
 ***      UInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DS2I2T2081(const MAP_Tab1DS2I2T2081 * map, UInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_I16 = *((z_table)++);
   Aux_I16_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x_table[0]);
   if (Aux_I16 <= Aux_I16_a) {
      /* Positive slope. */
      Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
       Aux_I16))) * ((UInt32) Aux_U16)) / Aux_U16_a));
   }
   else {
      /* Negative slope. */
      Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
       Aux_I16_a))) * ((UInt32) Aux_U16)) / Aux_U16_a));
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T521
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T521 *map                 data structure
 ***      UInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I2T521(const MAP_Tab1DS2I2T521 * map, UInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   return ((UInt16) ((((UInt32) (((UInt32) Aux_U16) * ((UInt32) z_table[1]))) + ((UInt32) (((UInt32)
     Aux_U16_a) * ((UInt32) z_table[0])))) / ((UInt16) (Aux_U16 + Aux_U16_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T0
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DIntp2I1T0(const UInt8 * z_table, UInt8 irx, UInt8 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   z_table += irx;
   Aux_U8 = *((z_table)++);
   if (fractionX != 0) {
      Aux_U8_a = *(z_table);
      if (Aux_U8 <= Aux_U8_a) {
         Aux_U8 += ((UInt8) ((((UInt16) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt16) fractionX)) >> 8));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt16) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt16) fractionX)) >> 8));
      }
   }
   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T1
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T1 *map                 data structure
 ***      UInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS2I2T1(const MAP_Tab1DS2I2T1 * map, UInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   return ((UInt8) ((((UInt32) (((UInt32) Aux_U16) * ((UInt32) z_table[1]))) + ((UInt32) (((UInt32)
    Aux_U16_a) * ((UInt32) z_table[0])))) / ((UInt16) (Aux_U16 + Aux_U16_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T1
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T1(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt8 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt8) (((UInt32) (((UInt32) (UInt16) (x - x_table[0])) << 8)) / ((UInt16)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T4
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DIntp2I1T4(const SInt16 * z_table, UInt8 irx, UInt8 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;

   z_table += irx;
   Aux_I16 = *((z_table)++);
   if (fractionX != 0) {
      Aux_I16_a = *(z_table);
      if (Aux_I16 <= Aux_I16_a) {
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16))) * ((UInt32) fractionX)) >> 8));
      }
      else {
         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_a))) * ((UInt32) fractionX)) >> 8));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T4
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T4(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 * irx, UInt8 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt8) (((UInt32) (((UInt32) (UInt16) (((UInt16) x) - ((UInt16)
          x_table[0]))) << 8)) / ((UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DS34I2T4172(const MAP_Tab2DS34I2T4172 * map, SInt16 x, UInt16 y, UInt8 * local_xLow,
  UInt8 * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U16) {
      y = Aux_U16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (y - y_table[0]);
   Aux_U16_a = (UInt16) (y_table[1] - y);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);

   /* Interpolation. */
   if (Aux_U16_b == 0) {
      Aux_U16_c = z_table[0];
      Aux_U16_d = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_d = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_a != 0) {
      if (Aux_U16_c < Aux_U16_d) {
         /* Positive slope. */
         Aux_U16_c += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_c)) * ((UInt32) Aux_U16))
          / Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_U16_c -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_c - Aux_U16_d)) * ((UInt32) Aux_U16))
          / Aux_U16_a));
      }
   }
   return Aux_U16_c;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab2DS34I2T12(const MAP_Tab2DS34I2T12 * map, SInt16 x, UInt16 y, UInt8 * local_xLow, UInt8 *
  local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U16) {
      y = Aux_U16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (y - y_table[0]);
   Aux_U16_a = (UInt16) (y_table[1] - y);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);

   /* Interpolation. */
   if (Aux_U16_b == 0) {
      Aux_U8_a = z_table[0];
      Aux_U8_b = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U8_a = (UInt8) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U8_b = (UInt8) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_a != 0) {
      if (Aux_U8_a < Aux_U8_b) {
         /* Positive slope. */
         Aux_U8_a += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_b - Aux_U8_a)) * ((UInt32) Aux_U16)) /
          Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_U8_a -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8_b)) * ((UInt32) Aux_U16)) /
          Aux_U16_a));
      }
   }
   return Aux_U8_a;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS2I2T4(const MAP_Tab1DS2I2T4 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U8 = *((z_table)++);
   Aux_U8_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U8 <= Aux_U8_a) {
      /* Positive slope. */
      Aux_U8 += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt32) Aux_U16)) /
       Aux_U16_a));
   }
   else {
      /* Negative slope. */
      Aux_U8 -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt32) Aux_U16)) /
       Aux_U16_a));
   }
   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I6T0(const MAP_Tab1DS0I6T0 * map, UInt8 x)
{
   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;

   /* Look-up method: Use Input Below */
   return ((x == x_table[1]) ? z_table[1] : z_table[0]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I4T520(const MAP_Tab1DS2I4T520 * map, UInt8 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return ((((UInt8) (x - x_table[0])) < ((UInt8) (x_table[1] - x))) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS2I4T4(const MAP_Tab1DS2I4T4 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return ((((UInt16) (((UInt16) x) - ((UInt16) x_table[0]))) < ((UInt16) (((UInt16) x_table[1]) -
    ((UInt16) x)))) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS0I2T524(const MAP_Tab1DS0I2T524 * map, SInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_U16 = *((z_table)++);
   Aux_U16_a = *(z_table);

   /* Interpolation. */
   Aux_U16_b = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_c = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16 <= Aux_U16_a) {
      /* Positive slope. */
      Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) Aux_U16_b)) /
       Aux_U16_c));
   }
   else {
      /* Negative slope. */
      Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) Aux_U16_b)) /
       Aux_U16_c));
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I2T520(const MAP_Tab1DS2I2T520 * map, UInt8 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Interpolation. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   return ((UInt16) ((((UInt32) (((UInt32) Aux_U8) * ((UInt32) z_table[1]))) + ((UInt32) (((UInt32)
    Aux_U8_a) * ((UInt32) z_table[0])))) / ((UInt8) (Aux_U8 + Aux_U8_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS0I2T520(const MAP_Tab1DS0I2T520 * map, UInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;

   /* Interpolation. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   return ((UInt16) ((((UInt32) (((UInt32) Aux_U8) * ((UInt32) z_table[1]))) + ((UInt32) (((UInt32)
    Aux_U8_a) * ((UInt32) z_table[0])))) / ((UInt8) (Aux_U8 + Aux_U8_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T0
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T0(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt8 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt8) (((UInt16) (((UInt16) (UInt8) (x - x_table[0])) << 8)) / ((UInt8)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T1560
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T1560 *map                 data structure
 ***      UInt8              x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      SInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt8 Tab1DS2I2T1560(const MAP_Tab1DS2I2T1560 * map, UInt8 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   SInt8 Aux_I8;
   SInt8 Aux_I8_a;
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const SInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_I8 = *((z_table)++);
   Aux_I8_a = *(z_table);

   /* Interpolation. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x_table[0]);
   if (Aux_I8 <= Aux_I8_a) {
      /* Positive slope. */
      Aux_I8 += ((SInt8) (UInt8) ((((UInt16) (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8))) *
       ((UInt16) Aux_U8)) / Aux_U8_a));
   }
   else {
      /* Negative slope. */
      Aux_I8 -= ((SInt8) (UInt8) ((((UInt16) (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_a))) *
       ((UInt16) Aux_U8)) / Aux_U8_a));
   }
   return Aux_I8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T513
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt16 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T513(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt16 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt16) (((UInt32) (((UInt32) (UInt16) (x - x_table[0])) << 16)) / ((UInt16)
           (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T516
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt16 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T516(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 * irx, UInt16 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt16) (((UInt32) (((UInt32) (UInt16) (((UInt16) x) - ((UInt16)
          x_table[0]))) << 16)) / ((UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33284
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab2DIntp2I1T33284(const SInt16 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry,
  UInt16 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_I16 = z_table[0];
   if (fractionY == 0) {
      Aux_I16_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_I16_b = z_table[1];
      if (Aux_I16 <= Aux_I16_b) {
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_b) - ((UInt16)
          Aux_I16))) * ((UInt32) fractionY)) >> 16));
      }
      else {
         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_b))) * ((UInt32) fractionY)) >> 16));
      }
      if (fractionX == 0) {
         return Aux_I16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I16_b = z_table[0];
      if (Aux_I16_a <= Aux_I16_b) {
         Aux_I16_a += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_b) - ((UInt16)
          Aux_I16_a))) * ((UInt32) fractionY)) >> 16));
      }
      else {
         Aux_I16_a -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16_b))) * ((UInt32) fractionY)) >> 16));
      }
   }
   if (fractionX != 0) {
      if (Aux_I16 <= Aux_I16_a) {
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16))) * ((UInt32) fractionX)) >> 16));
      }
      else {
         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_a))) * ((UInt32) fractionX)) >> 16));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33281
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DIntp2I1T33281(const UInt16 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry,
  UInt16 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_U16 = z_table[0];
   if (fractionY == 0) {
      Aux_U16_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];
      if (Aux_U16 <= Aux_U16_b) {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16)) * ((UInt32) fractionY)) >>
           16));
      }
      else {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_b)) * ((UInt32) fractionY)) >>
           16));
      }
      if (fractionX == 0) {
         return Aux_U16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U16_b = z_table[0];
      if (Aux_U16_a <= Aux_U16_b) {
         Aux_U16_a += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16_a)) * ((UInt32)
          fractionY)) >> 16));
      }
      else {
         Aux_U16_a -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16_b)) * ((UInt32)
          fractionY)) >> 16));
      }
   }
   if (fractionX != 0) {
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) fractionX)) >>
           16));
      }
      else {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) fractionX)) >>
           16));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T1044
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T1044 *map                 data structure
 ***      SInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DS2I2T1044(const MAP_Tab1DS2I2T1044 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U32 = *((z_table)++);
   Aux_U32_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U32 <= Aux_U32_a) {
      /* Positive slope. */
      Aux_U32_b = Aux_U32_a - Aux_U32;

      /* CoEmSTT_002/F04_Superviser_la_charge_decharge_des_Ucaps/F04_02_Determiner_la_consigne_tensi
         on_Ucap/F04_02_06_Boost_Ucap/CoEmSTT_tiUndVolt_T: ANSI_F_64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32(Aux_U32_b, (UInt32) Aux_U16, &(Aux_U32_c), &(Aux_U32_d));
      C__U32DIVU64U32(Aux_U32_c, Aux_U32_d, (UInt32) Aux_U16_a, Aux_U32_b);
      Aux_U32 += Aux_U32_b;
   }
   else {
      /* Negative slope. */
      Aux_U32_b = Aux_U32 - Aux_U32_a;

      /* CoEmSTT_002/F04_Superviser_la_charge_decharge_des_Ucaps/F04_02_Determiner_la_consigne_tensi
         on_Ucap/F04_02_06_Boost_Ucap/CoEmSTT_tiUndVolt_T: ANSI_F_64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32(Aux_U32_b, (UInt32) Aux_U16, &(Aux_U32_a), &(Aux_U32_c));
      C__U32DIVU64U32(Aux_U32_a, Aux_U32_c, (UInt32) Aux_U16_a, Aux_U32_b);
      Aux_U32 -= Aux_U32_b;
   }
   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T33
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T33 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab2DS34I2T33(const MAP_Tab2DS34I2T33 * map, UInt16 x, SInt16 y, UInt8 * local_xLow, UInt8 *
  local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;
   UInt8 Aux_U8_d;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16) {
      x = Aux_U16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_U8_a = z_table[0];
      Aux_U8_b = z_table[Aux_U8];
   }
   else {
      Aux_U8_c = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U8_d = z_table[1];
      if (Aux_U8_c < Aux_U8_d) {
         /* Positive slope. */
         Aux_U8_a = (UInt8) (Aux_U8_c + ((UInt8) ((((UInt32) (UInt8) (Aux_U8_d - Aux_U8_c)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U8_a = (UInt8) (Aux_U8_c - ((UInt8) ((((UInt32) (UInt8) (Aux_U8_c - Aux_U8_d)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U8_c = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U8_d = z_table[1];
      if (Aux_U8_c < Aux_U8_d) {
         /* Positive slope. */
         Aux_U8_b = (UInt8) (Aux_U8_c + ((UInt8) ((((UInt32) (UInt8) (Aux_U8_d - Aux_U8_c)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U8_b = (UInt8) (Aux_U8_c - ((UInt8) ((((UInt32) (UInt8) (Aux_U8_c - Aux_U8_d)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);
   if (Aux_U16_b != 0) {
      /* X-Interpolation. */
      Aux_U8_a = (UInt8) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) Aux_U8_a))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) Aux_U8_b)))) / Aux_U16_b);
   }
   return Aux_U8_a;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I4T2084
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I4T2084 *map                 data structure
 ***      SInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Use input nearest
 ***      Distances fit into given bitlengths: - (no interpolation)
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DS2I4T2084(const MAP_Tab1DS2I4T2084 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return ((((UInt16) (((UInt16) x) - ((UInt16) x_table[0]))) < ((UInt16) (((UInt16) x_table[1]) -
    ((UInt16) x)))) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS2I4T0(const MAP_Tab1DS2I4T0 * map, UInt8 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return ((((UInt8) (x - x_table[0])) < ((UInt8) (x_table[1] - x))) ? z_table[0] : z_table[1]);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I2T0(const MAP_Tab1DS0I2T0 * map, UInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;

   /* Interpolation. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   return ((UInt8) (((UInt16) (((UInt16) (((UInt16) Aux_U8) * ((UInt16) z_table[1]))) + ((UInt16)
    (((UInt16) Aux_U8_a) * ((UInt16) z_table[0]))))) / ((UInt8) (Aux_U8 + Aux_U8_a))));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I4T3(const MAP_Tab1DS0I4T3 * map, SInt8 x)
{
   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;

   /* Look-up method: Use Input Nearest */
   return ((((UInt8) (((UInt8) x) - ((UInt8) x_table[0]))) < ((UInt8) (((UInt8) x_table[1]) -
    ((UInt8) x)))) ? z_table[0] : z_table[1]);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS2I6T2(const MAP_Tab1DS2I6T2 * map, UInt32 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Below */
   return ((x == x_table[1]) ? z_table[1] : z_table[0]);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4192
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4192 *map                 data structure
 ***      UInt8              x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DS34I2T4192(const MAP_Tab2DS34I2T4192 * map, UInt8 x, SInt16 y, UInt8 * local_xLow, UInt8
   * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;
   UInt16 Aux_U16_e;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U8_a = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U8_a) {
      x = Aux_U8_a;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_U16_b = z_table[0];
      Aux_U16_c = z_table[Aux_U8];
   }
   else {
      Aux_U16_d = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U16_d = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   Aux_U8_b = (UInt8) (Aux_U8 + Aux_U8_a);
   if (Aux_U8_b != 0) {
      /* X-Interpolation. */
      Aux_U16_b = (UInt16) ((((UInt32) (((UInt32) Aux_U8_a) * ((UInt32) Aux_U16_b))) + ((UInt32)
       (((UInt32) Aux_U8) * ((UInt32) Aux_U16_c)))) / Aux_U8_b);
   }
   return Aux_U16_b;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T1562
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T1562 *map                 data structure
 ***      UInt32             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      SInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt8 Tab1DS2I2T1562(const MAP_Tab1DS2I2T1562 * map, UInt32 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   SInt8 Aux_I8;
   SInt8 Aux_I8_a;
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const SInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_I8 = *((z_table)++);
   Aux_I8_a = *(z_table);

   /* Interpolation. */
   Aux_U32 = x - x_table[0];
   Aux_U32_a = x_table[1] - x_table[0];
   if (Aux_I8 <= Aux_I8_a) {
      /* Positive slope. */
      Aux_U8 = (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8));

      /* ProdElEm_002/F01_Calculer_la_consigne_de_SOC/F01_06_Correction_SOC_WarmUp/F01_06_01_Activat
         ion/CoOptmEl_rCorSoCWupInter_visu: ANSI_F_64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32((UInt32) Aux_U8, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));
      C__U8DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U8);
      Aux_I8 += ((SInt8) Aux_U8);
   }
   else {
      /* Negative slope. */
      Aux_U8 = (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_a));

      /* ProdElEm_002/F01_Calculer_la_consigne_de_SOC/F01_06_Correction_SOC_WarmUp/F01_06_01_Activat
         ion/CoOptmEl_rCorSoCWupInter_visu: ANSI_F_64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32((UInt32) Aux_U8, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));
      C__U8DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U8);
      Aux_I8 -= ((SInt8) Aux_U8);
   }
   return Aux_I8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T2083
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T2083 *map                 data structure
 ***      SInt8              x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DS2I2T2083(const MAP_Tab1DS2I2T2083 * map, SInt8 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt8 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_I16 = *((z_table)++);
   Aux_I16_a = *(z_table);

   /* Interpolation. */
   Aux_U8 = (UInt8) (((UInt8) x) - ((UInt8) x_table[0]));
   Aux_U8_a = (UInt8) (((UInt8) x_table[1]) - ((UInt8) x_table[0]));
   if (Aux_I16 <= Aux_I16_a) {
      /* Positive slope. */
      Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
       Aux_I16))) * ((UInt32) Aux_U8)) / Aux_U8_a));
   }
   else {
      /* Negative slope. */
      Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
       Aux_I16_a))) * ((UInt32) Aux_U8)) / Aux_U8_a));
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4196
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4196 *map                 data structure
 ***      SInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DS34I2T4196(const MAP_Tab2DS34I2T4196 * map, SInt16 x, SInt16 y, UInt8 * local_xLow,
  UInt8 * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;
   UInt16 Aux_U16_e;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_U16_b = z_table[0];
      Aux_U16_c = z_table[Aux_U8];
   }
   else {
      Aux_U16_d = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U16_d = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_a != 0) {
      if (Aux_U16_b < Aux_U16_c) {
         /* Positive slope. */
         Aux_U16_b += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_c - Aux_U16_b)) * ((UInt32) Aux_U16))
          / Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_U16_b -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16_c)) * ((UInt32) Aux_U16))
          / Aux_U16_a));
      }
   }
   return Aux_U16_b;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T4
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T4 *map                 data structure
 ***      SInt16             x                   table input
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I2T4(const MAP_Tab1DS0I2T4 * map, SInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;

   z_table = map->z_table;

   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }

   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }


   /* Linear search, start low. */
   (x_table)++;

   while (x > *((x_table)++))    {
      (z_table)++;
   }

   x_table -= 2 /* 2. */;

   Aux_U8 = *((z_table)++);

   Aux_U8_a = *(z_table);


   /* Interpolation. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));

   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));

   if (Aux_U8 <= Aux_U8_a) {
      /* Positive slope. */
      Aux_U8 += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt32) Aux_U16)) /
       Aux_U16_a));
   }
   else {
      /* Negative slope. */
      Aux_U8 -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt32) Aux_U16)) /
       Aux_U16_a));
   }

   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T16676
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T16676 *map                 data structure
 ***      SInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab2DS0I2T16676(const MAP_Tab2DS0I2T16676 * map, SInt16 x, SInt16 y)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;
   SInt16 Aux_I16_c;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))    {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))    {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_I16 = z_table[0];
      Aux_I16_a = z_table[Aux_U8];
   }
   else {
      Aux_I16_b = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_I16_c = z_table[1];
      if (Aux_I16_b < Aux_I16_c) {
         /* Positive slope. */
         Aux_I16 = (SInt16) (((UInt16) Aux_I16_b) + ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_c) - ((UInt16) Aux_I16_b))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_I16 = (SInt16) (((UInt16) Aux_I16_b) - ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_b) - ((UInt16) Aux_I16_c))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_I16_b = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_I16_c = z_table[1];
      if (Aux_I16_b < Aux_I16_c) {
         /* Positive slope. */
         Aux_I16_a = (SInt16) (((UInt16) Aux_I16_b) + ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_c) - ((UInt16) Aux_I16_b))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_I16_a = (SInt16) (((UInt16) Aux_I16_b) - ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_b) - ((UInt16) Aux_I16_c))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_a != 0) {
      if (Aux_I16 < Aux_I16_a) {
         /* Positive slope. */
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16))) * ((UInt32) Aux_U16)) / Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_a))) * ((UInt32) Aux_U16)) / Aux_U16_a));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T4193
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T4193 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DS0I2T4193(const MAP_Tab2DS0I2T4193 * map, UInt16 x, SInt16 y)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;
   UInt16 Aux_U16_e;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16) {
      x = Aux_U16;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))    {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))    {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_U16_b = z_table[0];
      Aux_U16_c = z_table[Aux_U8];
   }
   else {
      Aux_U16_d = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U16_d = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   Aux_U16_d = (UInt16) (Aux_U16 + Aux_U16_a);
   if (Aux_U16_d != 0) {
      /* X-Interpolation. */
      Aux_U16_b = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) Aux_U16_b))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) Aux_U16_c)))) / Aux_U16_d);
   }
   return Aux_U16_b;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T523
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T523 *map                 data structure
 ***      SInt8              x                   table input
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS0I2T523(const MAP_Tab1DS0I2T523 * map, SInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_U16 = *((z_table)++);
   Aux_U16_a = *(z_table);

   /* Interpolation. */
   Aux_U8 = (UInt8) (((UInt8) x) - ((UInt8) x_table[0]));
   Aux_U8_a = (UInt8) (((UInt8) x_table[1]) - ((UInt8) x_table[0]));
   if (Aux_U16 <= Aux_U16_a) {
      /* Positive slope. */
      Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) Aux_U8)) /
       Aux_U8_a));
   }
   else {
      /* Negative slope. */
      Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) Aux_U8)) /
       Aux_U8_a));
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T521
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T521 *map                 data structure
 ***      UInt16             x                   table input
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS0I2T521(const MAP_Tab1DS0I2T521 * map, UInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;

   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   return ((UInt16) ((((UInt32) (((UInt32) Aux_U16) * ((UInt32) z_table[1]))) + ((UInt32) (((UInt32)
     Aux_U16_a) * ((UInt32) z_table[0])))) / ((UInt16) (Aux_U16 + Aux_U16_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS49T1
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: descending linear search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS49T1(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt8 * fraction)
{
   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[--(N)]) {
         *(irx) = N;
         *(fraction) = 0;
      }
      else {
         x_table += N;

         /* Linear search, start high. */
         do          {
            --(N);
            --(x_table);
         }
         while (x < *(x_table));
         *(irx) = N;
         *(fraction) = (UInt8) (((UInt32) (((UInt32) (UInt16) (x - x_table[0])) << 8)) / ((UInt16)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I4T1
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I4T1 *map                 data structure
 ***      UInt16             x                   table input
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Use input nearest
 ***      Distances fit into given bitlengths: - (no interpolation)
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I4T1(const MAP_Tab1DS0I4T1 * map, UInt16 x)
{
   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;

   /* Look-up method: Use Input Nearest */
   return ((((UInt16) (x - x_table[0])) < ((UInt16) (x_table[1] - x))) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T3
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T3(const SInt8 * x_table, UInt8 N, SInt8 x, UInt8 * irx, UInt8 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;

      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;

         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);

         x_table += Aux_U8;

         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);

               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;

            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }

            x_table -= 2 /* 2. */;
         }

         *(irx) = Aux_U8;

         *(fraction) = (UInt8) (((UInt16) (((UInt16) (UInt8) (((UInt8) x) - ((UInt8) x_table[0])))
          << 8)) / ((UInt8) (((UInt8) x_table[1]) - ((UInt8) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T0
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt8              fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab2DIntp2I1T0(const UInt8 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry, UInt8
  fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));

   Aux_U8 = z_table[0];

   if (fractionY == 0) {
      Aux_U8_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U8_b = z_table[1];

      if (Aux_U8 <= Aux_U8_b) {
         Aux_U8 += ((UInt8) ((((UInt16) (UInt8) (Aux_U8_b - Aux_U8)) * ((UInt16) fractionY)) >> 8));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt16) (UInt8) (Aux_U8 - Aux_U8_b)) * ((UInt16) fractionY)) >> 8));
      }

      if (fractionX == 0) {
         return Aux_U8;
      }

      z_table += N;


      /* 2. Y-Interpolation. */
      Aux_U8_a = *((z_table)++);


      /* X-Interpolation. */
      Aux_U8_b = z_table[0];

      if (Aux_U8_a <= Aux_U8_b) {
         Aux_U8_a += ((UInt8) ((((UInt16) (UInt8) (Aux_U8_b - Aux_U8_a)) * ((UInt16) fractionY)) >>
          8));
      }
      else {
         Aux_U8_a -= ((UInt8) ((((UInt16) (UInt8) (Aux_U8_a - Aux_U8_b)) * ((UInt16) fractionY)) >>
          8));
      }
   }

   if (fractionX != 0) {
      if (Aux_U8 <= Aux_U8_a) {
         Aux_U8 += ((UInt8) ((((UInt16) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt16) fractionX)) >> 8));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt16) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt16) fractionX)) >> 8));
      }
   }

   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T4
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt8              fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab2DIntp2I1T4(const SInt16 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry, UInt8
  fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));

   Aux_I16 = z_table[0];

   if (fractionY == 0) {
      Aux_I16_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_I16_b = z_table[1];

      if (Aux_I16 <= Aux_I16_b) {
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_b) - ((UInt16)
          Aux_I16))) * ((UInt32) fractionY)) >> 8));
      }
      else {
                  Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_b))) * ((UInt32) fractionY)) >> 8));
      }

            if (fractionX == 0) {
                return Aux_I16;
      }

      z_table += N;


      /* 2. Y-Interpolation. */
      Aux_I16_a = *((z_table)++);


      /* X-Interpolation. */
      Aux_I16_b = z_table[0];

      if (Aux_I16_a <= Aux_I16_b) {
         Aux_I16_a += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_b) - ((UInt16)
          Aux_I16_a))) * ((UInt32) fractionY)) >> 8));
      }
      else {
         Aux_I16_a -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16_b))) * ((UInt32) fractionY)) >> 8));
      }
   }


   if (fractionX != 0) {

      if (Aux_I16 <= Aux_I16_a) {

         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16))) * ((UInt32) fractionX)) >> 8));
      }
      else {

         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_a))) * ((UInt32) fractionX)) >> 8));
      }
   }


   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T1
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T1 *map                 data structure
 ***      UInt16             x                   table input
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I2T1(const MAP_Tab1DS0I2T1 * map, UInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;


   x_table = map->x_table;


   z_table = map->z_table;


   if (x <= *(x_table)) {

      /* Saturation. */
      return z_table[0];
   }


   if (x >= x_table[(UInt8) (map->Nx - 1)]) {

      return z_table[(UInt8) (map->Nx - 1)];
   }



   /* Linear search, start low. */
   (x_table)++;


   while (x > *((x_table)++))    {

      (z_table)++;
   }


   x_table -= 2 /* 2. */;



   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);


   Aux_U16_a = (UInt16) (x_table[1] - x);


   return ((UInt8) ((((UInt32) (((UInt32) Aux_U16) * ((UInt32) z_table[1]))) + ((UInt32) (((UInt32)
    Aux_U16_a) * ((UInt32) z_table[0])))) / ((UInt16) (Aux_U16 + Aux_U16_a))));
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T2
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt8              fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab2DIntp2I1T2(const UInt32 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry, UInt8
  fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;
   UInt32 Aux_U32_e;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));


   Aux_U32 = z_table[0];


   if (fractionY == 0) {

      Aux_U32_a = z_table[N];
   }
   else {

      /* 1. Y-Interpolation. */
      Aux_U32_b = z_table[1];


      if (Aux_U32 <= Aux_U32_b) {

         Aux_U32_c = Aux_U32_b - Aux_U32;


         /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02
            _01_Jeux_donnees/F03_02_01_01_Jeux_gains/Interpolation Using Prelookup4: ANSI_F_64MUL_LE
            32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_d), &(Aux_U32_e));

         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 8, 24);
      }
      else {

         Aux_U32_c = Aux_U32 - Aux_U32_b;


         /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02
            _01_Jeux_donnees/F03_02_01_01_Jeux_gains/Interpolation Using Prelookup4: ANSI_F_64MUL_LE
            32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_d), &(Aux_U32_e));

         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 8, 24);
      }

      if (fractionX == 0) {

         return Aux_U32;
      }

      z_table += N;


      /* 2. Y-Interpolation. */
      Aux_U32_a = *((z_table)++);


      /* X-Interpolation. */
      Aux_U32_b = z_table[0];

      if (Aux_U32_a <= Aux_U32_b) {

         Aux_U32_c = Aux_U32_b - Aux_U32_a;

         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_d), &(Aux_U32_e));

         Aux_U32_a += C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 8, 24);
      }
      else {

         Aux_U32_c = Aux_U32_a - Aux_U32_b;


         /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02
            _01_Jeux_donnees/F03_02_01_01_Jeux_gains/Interpolation Using Prelookup4: ANSI_F_64MUL_LE
            32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_b), &(Aux_U32_d));

         Aux_U32_a -= C__U32SHRU64C6_LT32(Aux_U32_b, Aux_U32_d, 8, 24);
      }
   }

   if (fractionX != 0) {

      if (Aux_U32 <= Aux_U32_a) {

         Aux_U32_b = Aux_U32_a - Aux_U32;

         /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02
            _01_Jeux_donnees/F03_02_01_01_Jeux_gains/Interpolation Using Prelookup4: ANSI_F_64MUL_LE
            32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) fractionX, &(Aux_U32_c), &(Aux_U32_d));

         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_c, Aux_U32_d, 8, 24);
      }
      else {

         Aux_U32_b = Aux_U32 - Aux_U32_a;


         /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02
            _01_Jeux_donnees/F03_02_01_01_Jeux_gains/Interpolation Using Prelookup4: ANSI_F_64MUL_LE
            32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_c));

         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_c, 8, 24);
      }
   }

   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T1042
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T1042 *map                 data structure
 ***      UInt32             x                   table input
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DS0I2T1042(const MAP_Tab1DS0I2T1042 * map, UInt32 x)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;
   UInt32 Aux_U32_e;
   UInt32 Aux_U32_f;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;

   z_table = map->z_table;

   if (x <= *(x_table)) {

      return z_table[0];
   }

   if (x >= x_table[(UInt8) (map->Nx - 1)]) {

      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;

   while (x > *((x_table)++))    {

      (z_table)++;
   }

   x_table -= 2 /* 2. */;

   Aux_U32 = *((z_table)++);

   Aux_U32_a = *(z_table);


   /* Interpolation. */
   Aux_U32_b = x - x_table[0];

   Aux_U32_c = x_table[1] - x_table[0];

   if (Aux_U32 <= Aux_U32_a) {

      /* Positive slope. */
      Aux_U32_d = Aux_U32_a - Aux_U32;


      /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02_03
         _Prediction_Etat/F03_02_03_02_Calcul_deltaU_ch_Predit/Racine_m_exp: ANSI_F_64MUL_LE32LE32_W
         OPGT32 */
      F__U64MULU32U32(Aux_U32_d, Aux_U32_b, &(Aux_U32_e), &(Aux_U32_f));

      C__U32DIVU64U32(Aux_U32_e, Aux_U32_f, Aux_U32_c, Aux_U32_d);

      Aux_U32 += Aux_U32_d;
   }
   else {

      /* Negative slope. */
      Aux_U32_d = Aux_U32 - Aux_U32_a;


      /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02_03
         _Prediction_Etat/F03_02_03_02_Calcul_deltaU_ch_Predit/Racine_m_exp: ANSI_F_64MUL_LE32LE32_W
         OPGT32 */
      F__U64MULU32U32(Aux_U32_d, Aux_U32_b, &(Aux_U32_a), &(Aux_U32_e));

      C__U32DIVU64U32(Aux_U32_a, Aux_U32_e, Aux_U32_c, Aux_U32_b);

      Aux_U32 -= Aux_U32_b;
   }

   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T1045
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T1045 *map                 data structure
 ***      SInt32             x                   table input
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DS0I2T1045(const MAP_Tab1DS0I2T1045 * map, SInt32 x)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;
   UInt32 Aux_U32_e;
   UInt32 Aux_U32_f;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;

   z_table = map->z_table;

   if (x <= *(x_table)) {

      /* Saturation. */
      return z_table[0];
   }

   if (x >= x_table[(UInt8) (map->Nx - 1)]) {

      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;

   while (x > *((x_table)++))    {

      (z_table)++;
   }

   x_table -= 2 /* 2. */;

   Aux_U32 = *((z_table)++);

   Aux_U32_a = *(z_table);


   /* Interpolation. */
   Aux_U32_b = ((UInt32) x) - ((UInt32) x_table[0]);

   Aux_U32_c = ((UInt32) x_table[1]) - ((UInt32) x_table[0]);

   if (Aux_U32 <= Aux_U32_a) {

      /* Positive slope. */
      Aux_U32_d = Aux_U32_a - Aux_U32;


      /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02_03
         _Prediction_Etat/F03_02_03_03_Calcul_deltaU_dech_Predit/Racine_m_exp: ANSI_F_64MUL_LE32LE32
         _WOPGT32 */
      F__U64MULU32U32(Aux_U32_d, Aux_U32_b, &(Aux_U32_e), &(Aux_U32_f));

      C__U32DIVU64U32(Aux_U32_e, Aux_U32_f, Aux_U32_c, Aux_U32_d);

      Aux_U32 += Aux_U32_d;
   }
   else {

      /* Negative slope. */
      Aux_U32_d = Aux_U32 - Aux_U32_a;


      /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02_03
         _Prediction_Etat/F03_02_03_03_Calcul_deltaU_dech_Predit/Racine_m_exp: ANSI_F_64MUL_LE32LE32
         _WOPGT32 */
      F__U64MULU32U32(Aux_U32_d, Aux_U32_b, &(Aux_U32_a), &(Aux_U32_e));

      C__U32DIVU64U32(Aux_U32_a, Aux_U32_e, Aux_U32_c, Aux_U32_b);

      Aux_U32 -= Aux_U32_b;
   }

   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T2
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt32             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T2(const UInt32 * x_table, UInt8 N, UInt32 x, UInt8 * irx, UInt8 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-8 OFF:  0 MIN/MAX:  0 .. 16777215.9960938 */;
   UInt32 Aux_U32_a /* LSB: 2^-8 OFF:  0 MIN/MAX:  0 .. 16777215.9960938 */;
   UInt32 Aux_U32_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {

      *(irx) = 0;

      *(fraction) = 0;
   }
   else {

      if (x >= x_table[N - 1]) {

         *(irx) = N - 1;

         *(fraction) = 0;
      }
      else {

         Aux_U8 = *(irx);

         x_table += Aux_U8;

         if (x < *(x_table)) {

            /* Linear search, start high. */
            do             {

               --(Aux_U8);

               --(x_table);
            }
            while (x < *(x_table));
         }
         else {

            /* Linear search, start low. */
            (x_table)++;

            while (x >= *((x_table)++))             {

               (Aux_U8)++;
            }

            x_table -= 2 /* 2. */;
         }

         *(irx) = Aux_U8;

         C__U64SHLU32C6_LT32(x - x_table[0], 8, 24, Aux_U32, Aux_U32_a);

         Aux_U32_b = x_table[1] - x_table[0];

         C__U8DIVU64U32(Aux_U32, Aux_U32_a, Aux_U32_b, *(fraction));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T1
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt8              fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt8              fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DIntp2I1T1(const UInt16 * z_table, UInt8 N, UInt8 irx, UInt8 fractionX, UInt8 iry, UInt8
  fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));

   Aux_U16 = z_table[0];

   if (fractionY == 0) {

      Aux_U16_a = z_table[N];
   }
   else {

      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];

      if (Aux_U16 <= Aux_U16_b) {

         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16)) * ((UInt32) fractionY)) >>
           8));
      }
      else {

         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_b)) * ((UInt32) fractionY)) >>
           8));
      }

      if (fractionX == 0) {

         return Aux_U16;
      }

      z_table += N;


      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);


      /* X-Interpolation. */
      Aux_U16_b = z_table[0];

      if (Aux_U16_a <= Aux_U16_b) {

         Aux_U16_a += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16_a)) * ((UInt32)
          fractionY)) >> 8));
      }
      else {

         Aux_U16_a -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16_b)) * ((UInt32)
          fractionY)) >> 8));
      }
   }

   if (fractionX != 0) {

      if (Aux_U16 <= Aux_U16_a) {

         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) fractionX)) >>
           8));
      }
      else {

         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) fractionX)) >>
           8));
      }
   }

   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T1043
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T1043 *map                 data structure
 ***      SInt8              x                   table input
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DS0I2T1043(const MAP_Tab1DS0I2T1043 * map, SInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;

   z_table = map->z_table;

   if (x <= *(x_table)) {

      /* Saturation. */
      return z_table[0];
   }

   if (x >= x_table[(UInt8) (map->Nx - 1)]) {

      return z_table[(UInt8) (map->Nx - 1)];
   }


   /* Linear search, start low. */
   (x_table)++;

   while (x > *((x_table)++))    {

      (z_table)++;
   }

   x_table -= 2 /* 2. */;

   Aux_U32 = *((z_table)++);

   Aux_U32_a = *(z_table);


   /* Interpolation. */
   Aux_U8 = (UInt8) (((UInt8) x) - ((UInt8) x_table[0]));

   Aux_U8_a = (UInt8) (((UInt8) x_table[1]) - ((UInt8) x_table[0]));

   if (Aux_U32 <= Aux_U32_a) {

      /* Positive slope. */
      Aux_U32_b = Aux_U32_a - Aux_U32;


      /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02_01
         _Jeux_donnees/F03_02_01_01_Jeux_gains/BatMgt_facBattDchaSoCCor_T: ANSI_F_64MUL_LE32LE32_WOP
         GT32 */
      F__U64MULU32U32(Aux_U32_b, (UInt32) Aux_U8, &(Aux_U32_c), &(Aux_U32_d));

      C__U32DIVU64U32(Aux_U32_c, Aux_U32_d, (UInt32) Aux_U8_a, Aux_U32_b);

      Aux_U32 += Aux_U32_b;
   }
   else {

      /* Negative slope. */
      Aux_U32_b = Aux_U32 - Aux_U32_a;


      /* ProdElEm_004/F03_Fiabiliser_information_SOC_batterie_12V/F03_02_Estimateur_de_SOC/F03_02_01
         _Jeux_donnees/F03_02_01_01_Jeux_gains/BatMgt_facBattDchaSoCCor_T: ANSI_F_64MUL_LE32LE32_WOP
         GT32 */
      F__U64MULU32U32(Aux_U32_b, (UInt32) Aux_U8, &(Aux_U32_a), &(Aux_U32_c));

      C__U32DIVU64U32(Aux_U32_a, Aux_U32_c, (UInt32) Aux_U8_a, Aux_U32_b);

      Aux_U32 -= Aux_U32_b;
   }

   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4193
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4193 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DS34I2T4193(const MAP_Tab2DS34I2T4193 * map, UInt16 x, SInt16 y, UInt8 * local_xLow,
  UInt8 * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;
   UInt16 Aux_U16_e;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;

   y_table = map->y_table;

   z_table = map->z_table;

   Aux_U8 = map->Ny;


   /* Saturation. */
   if (x < *(x_table)) {

      x = x_table[0];
   }

   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];

   if (x > Aux_U16) {

      x = Aux_U16;
   }

   Aux_U8_a = *(local_xLow);

   x_table += Aux_U8_a;


   /* Local search. */
   if (x < *(x_table)) {

      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {

         --(Aux_U8_a);

         --(x_table);
      }
      while (x < *(x_table));
   }
   else {

      /* Search algorithm for row axis. */
      (x_table)++;


      /* Linear search, start low. */
      while (x > *((x_table)++))       {

         (Aux_U8_a)++;
      }

      x_table -= 2 /* 2. */;
   }

   *(local_xLow) = Aux_U8_a;

   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));


   /* Saturation. */
   if (y < *(y_table)) {

      y = y_table[0];
   }

   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];

   if (y > Aux_I16) {
      y = Aux_I16;
   }

   Aux_U8_a = *(local_yLow);

   y_table += Aux_U8_a;


   /* Local search. */
   if (y < *(y_table)) {

      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {

         --(Aux_U8_a);

         --(y_table);
      }
      while (y < *(y_table));
   }
   else {

      /* Search algorithm for column axis. */
      (y_table)++;


      /* Linear search, start low. */
      while (y > *((y_table)++))       {

         (Aux_U8_a)++;
      }

      y_table -= 2 /* 2. */;
   }

   *(local_yLow) = Aux_U8_a;

   z_table += Aux_U8_a;


   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));

   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));


   /* Interpolation. */
   if (Aux_U16 == 0) {

      Aux_U16_b = z_table[0];

      Aux_U16_c = z_table[Aux_U8];
   }
   else {

      Aux_U16_d = z_table[0];


      /* 1. Y-Interpolation. */
      Aux_U16_e = z_table[1];

      if (Aux_U16_d < Aux_U16_e) {

         /* Positive slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {

         /* Negative slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }

      z_table += Aux_U8;

      Aux_U16_d = z_table[0];


      /* 2. Y-Interpolation. */
      Aux_U16_e = z_table[1];

      if (Aux_U16_d < Aux_U16_e) {

         /* Positive slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {

         /* Negative slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }


   /* Differences in row axis. */
   Aux_U16 = (UInt16) (x - x_table[0]);

   Aux_U16_a = (UInt16) (x_table[1] - x);

   Aux_U16_d = (UInt16) (Aux_U16 + Aux_U16_a);

   if (Aux_U16_d != 0) {

      /* X-Interpolation. */
      Aux_U16_b = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) Aux_U16_b))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) Aux_U16_c)))) / Aux_U16_d);
   }

   return Aux_U16_b;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T2080
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T2080 *map                 data structure
 ***      UInt8              x                   table input
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DS0I2T2080(const MAP_Tab1DS0I2T2080 * map, UInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;

   z_table = map->z_table;

   if (x <= *(x_table)) {

      /* Saturation. */
      return z_table[0];
   }

   if (x >= x_table[(UInt8) (map->Nx - 1)]) {

      return z_table[(UInt8) (map->Nx - 1)];
   }


   /* Linear search, start low. */
   (x_table)++;

   while (x > *((x_table)++))    {

      (z_table)++;
   }

   x_table -= 2 /* 2. */;

   Aux_I16 = *((z_table)++);

   Aux_I16_a = *(z_table);


   /* Interpolation. */
   Aux_U8 = (UInt8) (x - x_table[0]);

   Aux_U8_a = (UInt8) (x_table[1] - x_table[0]);

   if (Aux_I16 <= Aux_I16_a) {

      /* Positive slope. */
      Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
       Aux_I16))) * ((UInt32) Aux_U8)) / Aux_U8_a));
   }
   else {

      /* Negative slope. */
      Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
       Aux_I16_a))) * ((UInt32) Aux_U8)) / Aux_U8_a));
   }

   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I4T524
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I4T524 *map                 data structure
 ***      SInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Use input nearest
 ***      Distances fit into given bitlengths: - (no interpolation)
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I4T524(const MAP_Tab1DS2I4T524 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return ((((UInt16) (((UInt16) x) - ((UInt16) x_table[0]))) < ((UInt16) (((UInt16) x_table[1]) -
    ((UInt16) x)))) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T1041
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T1041 *map                 data structure
 ***      UInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DS2I2T1041(const MAP_Tab1DS2I2T1041 * map, UInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U32 = *((z_table)++);
   Aux_U32_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x_table[0]);
   if (Aux_U32 <= Aux_U32_a) {
      /* Positive slope. */
      Aux_U32_b = Aux_U32_a - Aux_U32;

      /* StopStrtEm_004/F04_Diagnostiquer_demarrage/F04_02_Diagnostiquer_durabilite_demarreur/F04_02
         _02_Determiner_seuil_durabilite_demarreur/StaStrtMgt_noTiAcvLimThd_visu: ANSI_F_64MUL_LE32L
         E32_WOPGT32 */
      F__U64MULU32U32(Aux_U32_b, (UInt32) Aux_U16, &(Aux_U32_c), &(Aux_U32_d));
      C__U32DIVU64U32(Aux_U32_c, Aux_U32_d, (UInt32) Aux_U16_a, Aux_U32_b);
      Aux_U32 += Aux_U32_b;
   }
   else {
      /* Negative slope. */
      Aux_U32_b = Aux_U32 - Aux_U32_a;

      /* StopStrtEm_004/F04_Diagnostiquer_demarrage/F04_02_Diagnostiquer_durabilite_demarreur/F04_02
         _02_Determiner_seuil_durabilite_demarreur/StaStrtMgt_noTiAcvLimThd_visu: ANSI_F_64MUL_LE32L
         E32_WOPGT32 */
      F__U64MULU32U32(Aux_U32_b, (UInt32) Aux_U16, &(Aux_U32_a), &(Aux_U32_c));
      C__U32DIVU64U32(Aux_U32_a, Aux_U32_c, (UInt32) Aux_U16_a, Aux_U32_b);
      Aux_U32 -= Aux_U32_b;
   }
   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T1042
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T1042 *map                 data structure
 ***      UInt32             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DS2I2T1042(const MAP_Tab1DS2I2T1042 * map, UInt32 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;
   UInt32 Aux_U32_e;
   UInt32 Aux_U32_f;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U32 = *((z_table)++);
   Aux_U32_a = *(z_table);

   /* Interpolation. */
   Aux_U32_b = x - x_table[0];
   Aux_U32_c = x_table[1] - x_table[0];
   if (Aux_U32 <= Aux_U32_a) {
      /* Positive slope. */
      Aux_U32_d = Aux_U32_a - Aux_U32;

      /* StopStrtEm_004/F04_Diagnostiquer_demarrage/F04_02_Diagnostiquer_durabilite_demarreur/F04_02
         _02_Determiner_seuil_durabilite_demarreur/StaStrtMgt_noDstAcvLimThd_visu: ANSI_F_64MUL_LE32
         LE32_WOPGT32 */
      F__U64MULU32U32(Aux_U32_d, Aux_U32_b, &(Aux_U32_e), &(Aux_U32_f));
      C__U32DIVU64U32(Aux_U32_e, Aux_U32_f, Aux_U32_c, Aux_U32_d);
      Aux_U32 += Aux_U32_d;
   }
   else {
      /* Negative slope. */
      Aux_U32_d = Aux_U32 - Aux_U32_a;

      /* StopStrtEm_004/F04_Diagnostiquer_demarrage/F04_02_Diagnostiquer_durabilite_demarreur/F04_02
         _02_Determiner_seuil_durabilite_demarreur/StaStrtMgt_noDstAcvLimThd_visu: ANSI_F_64MUL_LE32
         LE32_WOPGT32 */
      F__U64MULU32U32(Aux_U32_d, Aux_U32_b, &(Aux_U32_a), &(Aux_U32_e));
      C__U32DIVU64U32(Aux_U32_a, Aux_U32_e, Aux_U32_c, Aux_U32_b);
      Aux_U32 -= Aux_U32_b;
   }
   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I4T521
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I4T521 *map                 data structure
 ***      UInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Use input nearest
 ***      Distances fit into given bitlengths: - (no interpolation)
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I4T521(const MAP_Tab1DS2I4T521 * map, UInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return ((((UInt16) (x - x_table[0])) < ((UInt16) (x_table[1] - x))) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I4T522
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I4T522 *map                 data structure
 ***      UInt32             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Use input nearest
 ***      Distances fit into given bitlengths: - (no interpolation)
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I4T522(const MAP_Tab1DS2I4T522 * map, UInt32 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;

   /* Look-up method: Use Input Nearest */
   return (((x - x_table[0]) < (x_table[1] - x)) ? z_table[0] : z_table[1]);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T66
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab1DIntp2I1T66(const UInt32 * z_table, UInt8 irx, UInt16 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;

   z_table += irx;
   Aux_U32 = *((z_table)++);
   if (fractionX != 0) {
      Aux_U32_a = *(z_table);
      if (Aux_U32 <= Aux_U32_a) {
         Aux_U32_b = Aux_U32_a - Aux_U32;

         /* Library/Library/Interpolation Using Prelookup20: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) fractionX, &(Aux_U32_c), &(Aux_U32_d));
         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_c, Aux_U32_d, 16, 16);
      }
      else {
         Aux_U32_b = Aux_U32 - Aux_U32_a;

         /* Library/Library/Interpolation Using Prelookup20: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_c));
         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_c, 16, 16);
      }
   }
   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T69
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt32 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      SInt32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 Tab1DIntp2I1T69(const SInt32 * z_table, UInt8 irx, UInt16 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   SInt32 Aux_I32;
   SInt32 Aux_I32_a;
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;

   z_table += irx;
   Aux_I32 = *((z_table)++);
   if (fractionX != 0) {
      Aux_I32_a = *(z_table);
      if (Aux_I32 <= Aux_I32_a) {
         Aux_U32 = ((UInt32) Aux_I32_a) - ((UInt32) Aux_I32);

         /* Library/Library/Interpolation Using Prelookup22: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32 += ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
      else {
         Aux_U32 = ((UInt32) Aux_I32) - ((UInt32) Aux_I32_a);

         /* Library/Library/Interpolation Using Prelookup22: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32 -= ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
   }
   return Aux_I32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33282
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 Tab2DIntp2I1T33282(const UInt32 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry,
  UInt16 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;
   UInt32 Aux_U32_e;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_U32 = z_table[0];
   if (fractionY == 0) {
      Aux_U32_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U32_b = z_table[1];
      if (Aux_U32 <= Aux_U32_b) {
         Aux_U32_c = Aux_U32_b - Aux_U32;

         /* Library/Library/Interpolation Using Prelookup21: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_d), &(Aux_U32_e));
         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 16, 16);
      }
      else {
         Aux_U32_c = Aux_U32 - Aux_U32_b;

         /* Library/Library/Interpolation Using Prelookup21: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_d), &(Aux_U32_e));
         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 16, 16);
      }
      if (fractionX == 0) {
         return Aux_U32;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U32_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U32_b = z_table[0];
      if (Aux_U32_a <= Aux_U32_b) {
         Aux_U32_c = Aux_U32_b - Aux_U32_a;

         /* Library/Library/Interpolation Using Prelookup21: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_d), &(Aux_U32_e));
         Aux_U32_a += C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 16, 16);
      }
      else {
         Aux_U32_c = Aux_U32_a - Aux_U32_b;

         /* Library/Library/Interpolation Using Prelookup21: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) fractionY, &(Aux_U32_b), &(Aux_U32_d));
         Aux_U32_a -= C__U32SHRU64C6_LT32(Aux_U32_b, Aux_U32_d, 16, 16);
      }
   }
   if (fractionX != 0) {
      if (Aux_U32 <= Aux_U32_a) {
         Aux_U32_b = Aux_U32_a - Aux_U32;

         /* Library/Library/Interpolation Using Prelookup21: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) fractionX, &(Aux_U32_c), &(Aux_U32_d));
         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_c, Aux_U32_d, 16, 16);
      }
      else {
         Aux_U32_b = Aux_U32 - Aux_U32_a;

         /* Library/Library/Interpolation Using Prelookup21: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_c));
         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_c, 16, 16);
      }
   }
   return Aux_U32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33285
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt32 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 Tab2DIntp2I1T33285(const SInt32 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry,
  UInt16 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   SInt32 Aux_I32;
   SInt32 Aux_I32_a;
   SInt32 Aux_I32_b;
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_I32 = z_table[0];
   if (fractionY == 0) {
      Aux_I32_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_I32_b = z_table[1];
      if (Aux_I32 <= Aux_I32_b) {
         Aux_U32 = ((UInt32) Aux_I32_b) - ((UInt32) Aux_I32);

         /* Library/Library/Interpolation Using Prelookup23: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionY, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32 += ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
      else {
         Aux_U32 = ((UInt32) Aux_I32) - ((UInt32) Aux_I32_b);

         /* Library/Library/Interpolation Using Prelookup23: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionY, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32 -= ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
      if (fractionX == 0) {
         return Aux_I32;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I32_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I32_b = z_table[0];
      if (Aux_I32_a <= Aux_I32_b) {
         Aux_U32 = ((UInt32) Aux_I32_b) - ((UInt32) Aux_I32_a);

         /* Library/Library/Interpolation Using Prelookup23: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionY, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32_a += ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
      else {
         Aux_U32 = ((UInt32) Aux_I32_a) - ((UInt32) Aux_I32_b);

         /* Library/Library/Interpolation Using Prelookup23: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionY, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32_a -= ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
   }
   if (fractionX != 0) {
      if (Aux_I32 <= Aux_I32_a) {
         Aux_U32 = ((UInt32) Aux_I32_a) - ((UInt32) Aux_I32);

         /* Library/Library/Interpolation Using Prelookup23: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32 += ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
      else {
         Aux_U32 = ((UInt32) Aux_I32) - ((UInt32) Aux_I32_a);

         /* Library/Library/Interpolation Using Prelookup23: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32, (UInt32) fractionX, &(Aux_U32_a), &(Aux_U32_b));
         Aux_I32 -= ((SInt32) C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_b, 16, 16));
      }
   }
   return Aux_I32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T65
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DIntp2I1T65(const UInt16 * z_table, UInt8 irx, UInt16 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   z_table += irx;
   Aux_U16 = *((z_table)++);
   if (fractionX != 0) {
      Aux_U16_a = *(z_table);
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) fractionX)) >>
           16));
      }
      else {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) fractionX)) >>
           16));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T68
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DIntp2I1T68(const SInt16 * z_table, UInt8 irx, UInt16 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;

   z_table += irx;
   Aux_I16 = *((z_table)++);
   if (fractionX != 0) {
      Aux_I16_a = *(z_table);
      if (Aux_I16 <= Aux_I16_a) {
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16))) * ((UInt32) fractionX)) >> 16));
      }
      else {
         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_a))) * ((UInt32) fractionX)) >> 16));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T64
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DIntp2I1T64(const UInt8 * z_table, UInt8 irx, UInt16 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   z_table += irx;
   Aux_U8 = *((z_table)++);
   if (fractionX != 0) {
      Aux_U8_a = *(z_table);
      if (Aux_U8 <= Aux_U8_a) {
         Aux_U8 += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt32) fractionX)) >>
          16));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt32) fractionX)) >>
          16));
      }
   }
   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T67
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt8 *      z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      SInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt8 Tab1DIntp2I1T67(const SInt8 * z_table, UInt8 irx, UInt16 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   SInt8 Aux_I8;
   SInt8 Aux_I8_a;

   z_table += irx;
   Aux_I8 = *((z_table)++);
   if (fractionX != 0) {
      Aux_I8_a = *(z_table);
      if (Aux_I8 <= Aux_I8_a) {
         Aux_I8 += ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8))) *
          ((UInt32) fractionX)) >> 16));
      }
      else {
         Aux_I8 -= ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_a))) *
          ((UInt32) fractionX)) >> 16));
      }
   }
   return Aux_I8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33280
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab2DIntp2I1T33280(const UInt8 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry,
  UInt16 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_U8 = z_table[0];
   if (fractionY == 0) {
      Aux_U8_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U8_b = z_table[1];
      if (Aux_U8 <= Aux_U8_b) {
         Aux_U8 += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_b - Aux_U8)) * ((UInt32) fractionY)) >>
          16));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8 - Aux_U8_b)) * ((UInt32) fractionY)) >>
          16));
      }
      if (fractionX == 0) {
         return Aux_U8;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U8_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U8_b = z_table[0];
      if (Aux_U8_a <= Aux_U8_b) {
         Aux_U8_a += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_b - Aux_U8_a)) * ((UInt32) fractionY)) >>
          16));
      }
      else {
         Aux_U8_a -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8_b)) * ((UInt32) fractionY)) >>
          16));
      }
   }
   if (fractionX != 0) {
      if (Aux_U8 <= Aux_U8_a) {
         Aux_U8 += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt32) fractionX)) >>
          16));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt32) fractionX)) >>
          16));
      }
   }
   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33283
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt8 *      z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt8 Tab2DIntp2I1T33283(const SInt8 * z_table, UInt8 N, UInt8 irx, UInt16 fractionX, UInt8 iry,
  UInt16 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   SInt8 Aux_I8;
   SInt8 Aux_I8_a;
   SInt8 Aux_I8_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_I8 = z_table[0];
   if (fractionY == 0) {
      Aux_I8_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_I8_b = z_table[1];
      if (Aux_I8 <= Aux_I8_b) {
         Aux_I8 += ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8_b) - ((UInt8) Aux_I8))) *
          ((UInt32) fractionY)) >> 16));
      }
      else {
         Aux_I8 -= ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_b))) *
          ((UInt32) fractionY)) >> 16));
      }
      if (fractionX == 0) {
         return Aux_I8;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I8_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I8_b = z_table[0];
      if (Aux_I8_a <= Aux_I8_b) {
         Aux_I8_a += ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8_b) - ((UInt8) Aux_I8_a)))
           * ((UInt32) fractionY)) >> 16));
      }
      else {
         Aux_I8_a -= ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8_b)))
           * ((UInt32) fractionY)) >> 16));
      }
   }
   if (fractionX != 0) {
      if (Aux_I8 <= Aux_I8_a) {
         Aux_I8 += ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8))) *
          ((UInt32) fractionX)) >> 16));
      }
      else {
         Aux_I8 -= ((SInt8) (UInt8) ((((UInt32) (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_a))) *
          ((UInt32) fractionX)) >> 16));
      }
   }
   return Aux_I8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T512
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt16 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T512(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt16 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt16) (((UInt32) (((UInt32) (UInt8) (x - x_table[0])) << 16)) / ((UInt8)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T514
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt32             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt16 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T514(const UInt32 * x_table, UInt8 N, UInt32 x, UInt8 * irx, UInt16 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-16 OFF:  0 MIN/MAX:  0 .. 65535.9999847412 */;
   UInt32 Aux_U32_a /* LSB: 2^-16 OFF:  0 MIN/MAX:  0 .. 65535.9999847412 */;
   UInt32 Aux_U32_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         C__U64SHLU32C6_LT32(x - x_table[0], 16, 16, Aux_U32, Aux_U32_a);
         Aux_U32_b = x_table[1] - x_table[0];
         C__U16DIVU64U32(Aux_U32, Aux_U32_a, Aux_U32_b, *(fraction));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T515
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt16 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T515(const SInt8 * x_table, UInt8 N, SInt8 x, UInt8 * irx, UInt16 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         *(fraction) = (UInt16) (((UInt32) (((UInt32) (UInt8) (((UInt8) x) - ((UInt8) x_table[0])))
          << 16)) / ((UInt8) (((UInt8) x_table[1]) - ((UInt8) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T517
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt32 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt32             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt16 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Void TabIdxS50T517(const SInt32 * x_table, UInt8 N, SInt32 x, UInt8 * irx, UInt16 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-16 OFF:  0 MIN/MAX:  0 .. 65535.9999847412 */;
   UInt32 Aux_U32_a /* LSB: 2^-16 OFF:  0 MIN/MAX:  0 .. 65535.9999847412 */;
   UInt32 Aux_U32_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table)) {
            /* Linear search, start high. */
            do             {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))             {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         C__U64SHLU32C6_LT32(((UInt32) x) - ((UInt32) x_table[0]), 16, 16, Aux_U32, Aux_U32_a);
         Aux_U32_b = ((UInt32) x_table[1]) - ((UInt32) x_table[0]);
         C__U16DIVU64U32(Aux_U32, Aux_U32_a, Aux_U32_b, *(fraction));
      }
   }
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T1028
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/
#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
void TabIdxS50T1028(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 * irx, UInt32 * fraction)
{
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   UInt16 Aux_U16;

   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *x_table) {
      *irx = 0;
      *fraction = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *irx = N - 1;
         *fraction = 0;
      }
      else {
         Aux_U8 = *irx;
         x_table += Aux_U8;
         if (x < *x_table) {
            /* Linear search, start high. */
            do {
               --Aux_U8;
               --x_table;
            }
            while (x < *x_table);
         }
         else {
            /* Linear search, start low. */
            x_table++;
            while (x >= *(x_table++)) {
               Aux_U8++;
            }
            x_table -= 2;
         }
         *irx = Aux_U8;
         C__U64SHLU16C6_EQ32((UInt16) (((UInt16) x) - ((UInt16) x_table[0])), Aux_U32, Aux_U32_a);
         Aux_U16 = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U16, *fraction);
      }
   }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T1024
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/
#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
void TabIdxS50T1024(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt32 * fraction)
{
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *x_table) {
      *irx = 0;
      *fraction = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *irx = N - 1;
         *fraction = 0;
      }
      else {
         Aux_U8 = *irx;
         x_table += Aux_U8;
         if (x < *x_table) {
            /* Linear search, start high. */
            do {
               --Aux_U8;
               --x_table;
            }
            while (x < *x_table);
         }
         else {
            /* Linear search, start low. */
            x_table++;
            while (x >= *(x_table++)) {
               Aux_U8++;
            }
            x_table -= 2;
         }
         *irx = Aux_U8;
         C__U64SHLU8C6_EQ32((UInt8) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U8 = (UInt8) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U8, *fraction);
      }
   }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T128
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/
#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DIntp2I1T128(const UInt8 * z_table, UInt8 irx, UInt32 fractionX)
{
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   z_table += irx;
   Aux_U8 = *(z_table++);
   if (fractionX != 0) {
      Aux_U8_a = *z_table;
      if (Aux_U8 <= Aux_U8_a) {
         Aux_U8_b = (UInt8) (Aux_U8_a - Aux_U8);
         F__U64MULU32U32((UInt32) Aux_U8_b, fractionX, &Aux_U32, &Aux_U32_a);
         Aux_U8 += C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else {
         Aux_U8_b = (UInt8) (Aux_U8 - Aux_U8_a);
         F__U64MULU32U32((UInt32) Aux_U8_b, fractionX, &Aux_U32, &Aux_U32_a);
         Aux_U8 -= C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   return Aux_U8;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T522
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T522 *map                 data structure
 ***      UInt32             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS2I2T522(const MAP_Tab1DS2I2T522 * map, UInt32 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      *(local_xLow) = 0;

      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      *(local_xLow) = (UInt8) (map->Nx - 2);
      return z_table[(UInt8) (map->Nx - 1)];
   }
   Aux_U8 = *(local_xLow);
   x_table += Aux_U8;

   /* Local search. */
   if (x < *(x_table)) {
      /* Linear search, start high. */
      do       {
         --(Aux_U8);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Linear search, start low. */
      (x_table)++;
      while (x > *((x_table)++))       {
         (Aux_U8)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U16 = *((z_table)++);
   Aux_U16_a = *(z_table);

   /* Interpolation. */
   Aux_U32 = x - x_table[0];
   Aux_U32_a = x_table[1] - x_table[0];
   if (Aux_U16 <= Aux_U16_a) {
      /* Positive slope. */
      Aux_U16_b = (UInt16) (Aux_U16_a - Aux_U16);

      /* StopStrtEm_006/F01_Proteger_demarreur_redemarrage/F01_03_Protection_3/1DInterp_LookUpTable1
         : ANSI_F_64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32((UInt32) Aux_U16_b, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));
      C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16_b);
      Aux_U16 += Aux_U16_b;
   }
   else {
      /* Negative slope. */
      Aux_U16_b = (UInt16) (Aux_U16 - Aux_U16_a);

      /* StopStrtEm_006/F01_Proteger_demarreur_redemarrage/F01_03_Protection_3/1DInterp_LookUpTable1
         : ANSI_F_64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32((UInt32) Aux_U16_b, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));
      C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16_a);
      Aux_U16 -= Aux_U16_a;
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

SInt16 Tab1DS0I2T2084(const MAP_Tab1DS0I2T2084 * map, SInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_I16 = *((z_table)++);
   Aux_I16_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_I16 <= Aux_I16_a) {
      /* Positive slope. */
      Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
       Aux_I16))) * ((UInt32) Aux_U16)) / Aux_U16_a));
   }
   else {
      /* Negative slope. */
      Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
       Aux_I16_a))) * ((UInt32) Aux_U16)) / Aux_U16_a));
   }
   return Aux_I16;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS48T0
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt8 *            fraction            table output
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/
#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

void TabIdxS48T0(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt8 * fraction)
{
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *x_table) {
      *irx = 0;
      *fraction = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         *irx = N - 1;
         *fraction = 0;
      }
      else {
         Aux_U8 = 0;

         /* Linear search, start low. */
         x_table++;
         while (x >= *(x_table++)) {
            Aux_U8++;
         }
         x_table -= 2;
         *irx = Aux_U8;
         *fraction = (UInt8) (((UInt16) (((UInt16) (UInt8) (x - x_table[0])) << 8)) / ((UInt8)
          (x_table[1] - x_table[0])));
      }
   }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T3
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T3 *map                 data structure
 ***      SInt8              x                   table input
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt8 Tab1DS0I2T3(const MAP_Tab1DS0I2T3 * map, SInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_U8 = *((z_table)++);
   Aux_U8_a = *(z_table);

   /* Interpolation. */
   Aux_U8_b = (UInt8) (((UInt8) x) - ((UInt8) x_table[0]));
   Aux_U8_c = (UInt8) (((UInt8) x_table[1]) - ((UInt8) x_table[0]));
   if (Aux_U8 <= Aux_U8_a) {
      /* Positive slope. */
      Aux_U8 += ((UInt8) ((((UInt16) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt16) Aux_U8_b)) /
       Aux_U8_c));
   }
   else {
      /* Negative slope. */
      Aux_U8 -= ((UInt8) ((((UInt16) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt16) Aux_U8_b)) /
       Aux_U8_c));
   }
   return Aux_U8;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T16673
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T16673 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab2DS0I2T16673(const MAP_Tab2DS0I2T16673 * map, UInt16 x, SInt16 y)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;
   SInt16 Aux_I16_c;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16) {
      x = Aux_U16;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))    {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))    {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_I16 = z_table[0];
      Aux_I16_a = z_table[Aux_U8];
   }
   else {
      Aux_I16_b = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_I16_c = z_table[1];
      if (Aux_I16_b < Aux_I16_c) {
         /* Positive slope. */
         Aux_I16 = (SInt16) (((UInt16) Aux_I16_b) + ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_c) - ((UInt16) Aux_I16_b))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_I16 = (SInt16) (((UInt16) Aux_I16_b) - ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_b) - ((UInt16) Aux_I16_c))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_I16_b = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_I16_c = z_table[1];
      if (Aux_I16_b < Aux_I16_c) {
         /* Positive slope. */
         Aux_I16_a = (SInt16) (((UInt16) Aux_I16_b) + ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_c) - ((UInt16) Aux_I16_b))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_I16_a = (SInt16) (((UInt16) Aux_I16_b) - ((UInt16) ((((UInt32) (UInt16) (((UInt16)
          Aux_I16_b) - ((UInt16) Aux_I16_c))) * ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x_table[0]);
   if (Aux_U16_a != 0) {
      if (Aux_I16 < Aux_I16_a) {
         /* Positive slope. */
         Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
          Aux_I16))) * ((UInt32) Aux_U16)) / Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
          Aux_I16_a))) * ((UInt32) Aux_U16)) / Aux_U16_a));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T4196
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T4196 *map                 data structure
 ***      SInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab2DS0I2T4196(const MAP_Tab2DS0I2T4196 * map, SInt16 x, SInt16 y)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;
   UInt16 Aux_U16_e;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))    {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))    {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_U16_b = z_table[0];
      Aux_U16_c = z_table[Aux_U8];
   }
   else {
      Aux_U16_d = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U16_d = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e) {
         /* Positive slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_a != 0) {
      if (Aux_U16_b < Aux_U16_c) {
         /* Positive slope. */
         Aux_U16_b += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_c - Aux_U16_b)) * ((UInt32) Aux_U16))
          / Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_U16_b -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16_c)) * ((UInt32) Aux_U16))
          / Aux_U16_a));
      }
   }
   return Aux_U16_b;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T2604
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T2604 *map                 data structure
 ***      SInt16             x                   table input
 ***
 ***  RETURNS:
 ***      SInt32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 Tab1DS0I2T2604(const MAP_Tab1DS0I2T2604 * map, SInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   SInt32 Aux_I32;
   SInt32 Aux_I32_a;
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_I32 = *((z_table)++);
   Aux_I32_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_I32 <= Aux_I32_a) {
      /* Positive slope. */
      Aux_U32 = ((UInt32) Aux_I32_a) - ((UInt32) Aux_I32);

      /* ACCmd/RE_ACCmd_003_DRE/F01/F03_04/F02_04_01/F02_04_01_02/ACCmd_nCkAntiStallDelta_T: ANSI_F_
         64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32(Aux_U32, (UInt32) Aux_U16, &(Aux_U32_a), &(Aux_U32_b));
      C__U32DIVU64U32(Aux_U32_a, Aux_U32_b, (UInt32) Aux_U16_a, Aux_U32);
      Aux_I32 += ((SInt32) Aux_U32);
   }
   else {
      /* Negative slope. */
      Aux_U32 = ((UInt32) Aux_I32) - ((UInt32) Aux_I32_a);

      /* ACCmd/RE_ACCmd_003_DRE/F01/F03_04/F02_04_01/F02_04_01_02/ACCmd_nCkAntiStallDelta_T: ANSI_F_
         64MUL_LE32LE32_WOPGT32 */
      F__U64MULU32U32(Aux_U32, (UInt32) Aux_U16, &(Aux_U32_a), &(Aux_U32_b));
      C__U32DIVU64U32(Aux_U32_a, Aux_U32_b, (UInt32) Aux_U16_a, Aux_U32);
      Aux_I32 -= ((SInt32) Aux_U32);
   }
   return Aux_I32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T2081
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T2081 *map                 data structure
 ***      UInt16             x                   table input
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 Tab1DS0I2T2081(const MAP_Tab1DS0I2T2081 * map, UInt16 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table)) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)]) {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))    {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_I16 = *((z_table)++);
   Aux_I16_a = *(z_table);

   /* Interpolation. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x_table[0]);
   if (Aux_I16 <= Aux_I16_a) {
      /* Positive slope. */
      Aux_I16 += ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16_a) - ((UInt16)
       Aux_I16))) * ((UInt32) Aux_U16)) / Aux_U16_a));
   }
   else {
      /* Negative slope. */
      Aux_I16 -= ((SInt16) (UInt16) ((((UInt32) (UInt16) (((UInt16) Aux_I16) - ((UInt16)
       Aux_I16_a))) * ((UInt32) Aux_U16)) / Aux_U16_a));
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T3081
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T3081 *map                 data structure
 ***      float32            x                   table input
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
float32 Tab1DS0I2T3081(const MAP_Tab1DS0I2T3081 * map, float32 x)
{
   float32 Aux_F32;
   float32 Aux_F32_a;

   uint16 Aux_U16;

   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   Aux_U16 = (uint16) ((x - map->xO) * map->xLSB);
   x_table = map->x_table;
   z_table = map->z_table;
   if (Aux_U16 <= *x_table) {
      /* Saturation. */
      return ((((float32) z_table[0]) * map->zLSB) + map->zO);
   }
   if (Aux_U16 >= x_table[(uint8) (map->Nx - 1)]) {
      return ((((float32) z_table[(uint8) (map->Nx - 1)]) * map->zLSB) + map->zO);
   }

   /* Linear search, start low. */
   x_table++;
   while (Aux_U16 > *(x_table++)) {
      z_table++;
   }
   x_table -= 2;
   Aux_F32 = (float32) *(z_table++);
   Aux_F32_a = (float32) *z_table;

   /* Interpolation. */
   return (((Aux_F32 + (((Aux_F32_a - Aux_F32) * ((float32) (uint16) (Aux_U16 - x_table[0]))) /
    ((float32) (uint16) (x_table[1] - x_table[0])))) * map->zLSB) + map->zO);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T3084
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T3084 *map                 data structure
 ***      float32            x                   table input
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
float32 Tab1DS0I2T3084(const MAP_Tab1DS0I2T3084 * map, float32 x)
{
   float32 Aux_F32;
   float32 Aux_F32_a;

   sint16 Aux_S16;

   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   Aux_S16 = (sint16) ((x - map->xO) * map->xLSB);
   x_table = map->x_table;
   z_table = map->z_table;
   if (Aux_S16 <= *x_table) {
      /* Saturation. */
      return ((((float32) z_table[0]) * map->zLSB) + map->zO);
   }
   if (Aux_S16 >= x_table[(uint8) (map->Nx - 1)]) {
      return ((((float32) z_table[(uint8) (map->Nx - 1)]) * map->zLSB) + map->zO);
   }

   /* Linear search, start low. */
   x_table++;
   while (Aux_S16 > *(x_table++)) {
      z_table++;
   }
   x_table -= 2;
   Aux_F32 = (float32) *(z_table++);
   Aux_F32_a = (float32) *z_table;

   /* Interpolation. */
   return (((Aux_F32 + (((Aux_F32_a - Aux_F32) * ((float32) (uint16) (((uint16) Aux_S16) - ((uint16)
     x_table[0])))) / ((float32) (uint16) (((uint16) x_table[1]) - ((uint16) x_table[0]))))) *
    map->zLSB) + map->zO);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I2T3084
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I2T3084 *map                 data structure
 ***      float32            x                   table input
 ***      uint8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
float32 Tab1DS2I2T3084(const MAP_Tab1DS2I2T3084 * map, float32 x, uint8 * local_xLow)
{
   float32 Aux_F32;
   float32 Aux_F32_a;

   sint16 Aux_S16;

   uint8 Aux_U8;

   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   Aux_S16 = (sint16) ((x - map->xO) * map->xLSB);
   x_table = map->x_table;
   z_table = map->z_table;
   if (Aux_S16 <= *x_table) {
      *local_xLow = 0;

      /* Saturation. */
      return ((((float32) z_table[0]) * map->zLSB) + map->zO);
   }
   if (Aux_S16 >= x_table[(uint8) (map->Nx - 1)]) {
      *local_xLow = (uint8) (map->Nx - 2);
      return ((((float32) z_table[(uint8) (map->Nx - 1)]) * map->zLSB) + map->zO);
   }
   Aux_U8 = *local_xLow;
   x_table += Aux_U8;

   /* Local search. */
   if (Aux_S16 < *x_table) {
      /* Linear search, start high. */
      do {
         --Aux_U8;
         --x_table;
      }
      while (Aux_S16 < *x_table);
   }
   else {
      /* Linear search, start low. */
      x_table++;
      while (Aux_S16 > *(x_table++)) {
         Aux_U8++;
      }
      x_table -= 2;
   }
   *local_xLow = Aux_U8;
   z_table += Aux_U8;
   Aux_F32 = (float32) *(z_table++);
   Aux_F32_a = (float32) *z_table;

   /* Interpolation. */
   return (((Aux_F32 + (((Aux_F32_a - Aux_F32) * ((float32) (uint16) (((uint16) Aux_S16) - ((uint16)
     x_table[0])))) / ((float32) (uint16) (((uint16) x_table[1]) - ((uint16) x_table[0]))))) *
    map->zLSB) + map->zO);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T522
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T522 *map                 data structure
 ***      UInt32             x                   table input
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 Tab1DS0I2T522(const MAP_Tab1DS0I2T522 * map, UInt32 x)
{
   uint32 Aux_U32;
   uint32 Aux_U32_a;
   uint32 Aux_U32_b;
   uint32 Aux_U32_c;

   uint16 Aux_U16;
   uint16 Aux_U16_a;
   uint16 Aux_U16_b;

   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *x_table) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(uint8) (map->Nx - 1)]) {
      return z_table[(uint8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   x_table++;
   while (x > *(x_table++)) {
      z_table++;
   }
   x_table -= 2;
   Aux_U16 = *(z_table++);
   Aux_U16_a = *z_table;

   /* Interpolation. */
   Aux_U32 = x - x_table[0];
   Aux_U32_a = x_table[1] - x_table[0];
   if (Aux_U16 <= Aux_U16_a) {
      /* Positive slope. */
      Aux_U16_b = (uint16) (Aux_U16_a - Aux_U16);
      F__U64MULU32U32((uint32) Aux_U16_b, Aux_U32, &Aux_U32_b, &Aux_U32_c);
      C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16_b);
      Aux_U16 += Aux_U16_b;
   }
   else {
      /* Negative slope. */
      Aux_U16_b = (uint16) (Aux_U16 - Aux_U16_a);
      F__U64MULU32U32((uint32) Aux_U16_b, Aux_U32, &Aux_U32_b, &Aux_U32_c);
      C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16_a);
      Aux_U16 -= Aux_U16_a;
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T390
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const float32 *    z_table             pointer to table vector
 ***      uint8              irx                 1. table input index
 ***      float32            fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/
float32 Tab1DIntp2I1T390(const float32 * z_table, uint8 irx, float32 fractionX)
{
   float32 Aux_F32;

   z_table += irx;
   Aux_F32 = *(z_table++);
   if (fractionX != 0.F) {
      Aux_F32 += ((*z_table - Aux_F32) * fractionX);
   }
   return Aux_F32;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T3078
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const float32 *    x_table             pointer to x-axis vector
 ***      uint8              N                   number of values in x-axis vector
 ***      float32            x                   table input
 ***      uint8 *            irx                 table output
 ***      float32 *          fraction            table output
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/
void TabIdxS50T3078(const float32 * x_table, uint8 N, float32 x, uint8 * irx, float32 * fraction)
{
   uint8 Aux_U8;

   /* Saturation. */
   if (x <= *x_table) {
      *irx = 0;
      *fraction = 0.F;
   }
   else {
      if (x >= x_table[N - 1]) {
         *irx = N - 1;
         *fraction = 0.F;
      }
      else {
         Aux_U8 = *irx;
         x_table += Aux_U8;
         if (x < *x_table) {
            /* Linear search, start high. */
            do {
               --Aux_U8;
               --x_table;
            }
            while (x < *x_table);
         }
         else {
            /* Linear search, start low. */
            x_table++;
            while (x >= *(x_table++)) {
               Aux_U8++;
            }
            x_table -= 2;
         }
         *irx = Aux_U8;
         *fraction = (x - x_table[0]) / (x_table[1] - x_table[0]);
      }
   }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T2083
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T2083 *map                 data structure
 ***      SInt8              x                   table input
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/
SInt16 Tab1DS0I2T2083(const MAP_Tab1DS0I2T2083 * map, SInt8 x)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   sint16 Aux_S16;
   sint16 Aux_S16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   uint8 Aux_U8;
   uint8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt8 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *x_table) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(uint8) (map->Nx - 1)]) {
      return z_table[(uint8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   x_table++;
   while (x > *(x_table++)) {
      z_table++;
   }
   x_table -= 2;
   Aux_S16 = *(z_table++);
   Aux_S16_a = *z_table;

   /* Interpolation. */
   Aux_U8 = (uint8) (((uint8) x) - ((uint8) x_table[0]));
   Aux_U8_a = (uint8) (((uint8) x_table[1]) - ((uint8) x_table[0]));
   if (Aux_S16 <= Aux_S16_a) {
      /* Positive slope. */
      Aux_S16 += ((sint16) (uint16) ((((uint32) (uint16) (((uint16) Aux_S16_a) - ((uint16)
       Aux_S16))) * ((uint32) Aux_U8)) / Aux_U8_a));
   }
   else {
      /* Negative slope. */
      Aux_S16 -= ((sint16) (uint16) ((((uint32) (uint16) (((uint16) Aux_S16) - ((uint16)
       Aux_S16_a))) * ((uint32) Aux_U8)) / Aux_U8_a));
   }
   return Aux_S16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T3126
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T3126 *map                 data structure
 ***      float32            x                   table input
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/
float32 Tab1DS0I2T3126(const MAP_Tab1DS0I2T3126 * map, float32 x)
{
   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const float32 * x_table /* Scaling may differ through function reuse. */;
   const float32 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *x_table) {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(uint8) (map->Nx - 1)]) {
      return z_table[(uint8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   x_table++;
   while (x > *(x_table++)) {
      z_table++;
   }
   x_table -= 2;

   /* Interpolation. */
   return (z_table[0] + (((z_table[1] - z_table[0]) * (x - x_table[0])) / (x_table[1] -
    x_table[0])));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T33286
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const float32 *    z_table             pointer to table vector
 ***      uint8              N                   number of values in y-axis vector
 ***      uint8              irx                 1. table input index
 ***      UInt16             fractionX           1. table input fraction
 ***      uint8              iry                 2. table input index
 ***      UInt16             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/
float32 Tab2DIntp2I1T33286(const float32 * z_table, uint8 N, uint8 irx, UInt16 fractionX, uint8 iry,
   UInt16 fractionY)
{
   float32 Aux_F32;
   float32 Aux_F32_a;
   float32 Aux_F32_b;

   z_table += ((uint16) (((uint16) (((uint16) irx) * ((uint16) N))) + ((uint16) iry)));
   Aux_F32 = z_table[0];
   if (fractionY == 0) {
      Aux_F32_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_F32_b = z_table[1];
      Aux_F32 += ((Aux_F32_b - Aux_F32) * ((float32) fractionY) * 1.525878906e-005F);
      if (fractionX == 0) {
         return Aux_F32;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_F32_a = *(z_table++);

      /* X-Interpolation. */
      Aux_F32_b = z_table[0];
      Aux_F32_a += ((Aux_F32_b - Aux_F32_a) * ((float32) fractionY) * 1.525878906e-005F);
   }
   if (fractionX != 0) {
      Aux_F32 += ((Aux_F32_a - Aux_F32) * ((float32) fractionX) * 1.525878906e-005F);
   }
   return Aux_F32;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T3076
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      uint8              N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      uint8 *            irx                 table output
 ***      float32 *          fraction            table output
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/
void TabIdxS50T3076(const SInt16 * x_table, uint8 N, SInt16 x, uint8 * irx, float32 * fraction)
{
   uint8 Aux_U8;

   /* Saturation. */
   if (x <= *x_table) {
      *irx = 0;
      *fraction = 0.F;
   }
   else {
      if (x >= x_table[N - 1]) {
         *irx = N - 1;
         *fraction = 0.F;
      }
      else {
         Aux_U8 = *irx;
         x_table += Aux_U8;
         if (x < *x_table) {
            /* Linear search, start high. */
            do {
               --Aux_U8;
               --x_table;
            }
            while (x < *x_table);
         }
         else {
            /* Linear search, start low. */
            x_table++;
            while (x >= *(x_table++)) {
               Aux_U8++;
            }
            x_table -= 2;
         }
         *irx = Aux_U8;
         *fraction = ((float32) (uint16) (((uint16) x) - ((uint16) x_table[0]))) / ((float32)
          (uint16) (((uint16) x_table[1]) - ((uint16) x_table[0])));
      }
   }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T3073
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      uint8              N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      uint8 *            irx                 table output
 ***      float32 *          fraction            table output
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/
void TabIdxS50T3073(const UInt16 * x_table, uint8 N, UInt16 x, uint8 * irx, float32 * fraction)
{
   uint8 Aux_U8;

   /* Saturation. */
   if (x <= *x_table) {
      *irx = 0;
      *fraction = 0.F;
   }
   else {
      if (x >= x_table[N - 1]) {
         *irx = N - 1;
         *fraction = 0.F;
      }
      else {
         Aux_U8 = *irx;
         x_table += Aux_U8;
         if (x < *x_table) {
            /* Linear search, start high. */
            do {
               --Aux_U8;
               --x_table;
            }
            while (x < *x_table);
         }
         else {
            /* Linear search, start low. */
            x_table++;
            while (x >= *(x_table++)) {
               Aux_U8++;
            }
            x_table -= 2;
         }
         *irx = Aux_U8;
         *fraction = ((float32) (uint16) (x - x_table[0])) / ((float32) (uint16) (x_table[1] -
          x_table[0]));
      }
   }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T199686
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const float32 *    z_table             pointer to table vector
 ***      uint8              N                   number of values in y-axis vector
 ***      uint8              irx                 1. table input index
 ***      float32            fractionX           1. table input fraction
 ***      uint8              iry                 2. table input index
 ***      float32            fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      float32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/
float32 Tab2DIntp2I1T199686(const float32 * z_table, uint8 N, uint8 irx, float32 fractionX, uint8
  iry, float32 fractionY)
{
   float32 Aux_F32;
   float32 Aux_F32_a;
   float32 Aux_F32_b;

   z_table += ((uint16) (((uint16) (((uint16) irx) * ((uint16) N))) + ((uint16) iry)));
   Aux_F32 = z_table[0];
   if (fractionY == 0.F) {
      Aux_F32_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_F32_b = z_table[1];
      Aux_F32 += ((Aux_F32_b - Aux_F32) * fractionY);
      if (fractionX == 0.F) {
         return Aux_F32;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_F32_a = *(z_table++);

      /* X-Interpolation. */
      Aux_F32_b = z_table[0];
      Aux_F32_a += ((Aux_F32_b - Aux_F32_a) * fractionY);
   }
   if (fractionX != 0.F) {
      Aux_F32 += ((Aux_F32_a - Aux_F32) * fractionX);
   }
   return Aux_F32;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T385
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      uint8              irx                 1. table input index
 ***      float32            fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/
UInt16 Tab1DIntp2I1T385(const UInt16 * z_table, uint8 irx, float32 fractionX)
{
   uint16 Aux_U16;
   uint16 Aux_U16_a;

   z_table += irx;
   Aux_U16 = *(z_table++);
   if (fractionX != 0.F) {
      Aux_U16_a = *z_table;
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16 += ((uint16) (((float32) (uint16) (Aux_U16_a - Aux_U16)) * fractionX));
      }
      else {
         Aux_U16 -= ((uint16) (((float32) (uint16) (Aux_U16 - Aux_U16_a)) * fractionX));
      }
   }
   return Aux_U16;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4164
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4164 *map                 data structure
 ***      SInt16             x                   searching for f(X,y)
 ***      UInt8              y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

UInt16 Tab2DS34I2T4164(const MAP_Tab2DS34I2T4164 * map, SInt16 x, UInt8 y, UInt8 * local_xLow, UInt8
   * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U8_a = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U8_a) {
      y = Aux_U8_a;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U8_a = (UInt8) (y - y_table[0]);
   Aux_U8_b = (UInt8) (y_table[1] - y);
   Aux_U8_c = (UInt8) (Aux_U8_a + Aux_U8_b);

   /* Interpolation. */
   if (Aux_U8_c == 0) {
      Aux_U16 = z_table[0];
      Aux_U16_a = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16 = (UInt16) ((((UInt32) (((UInt32) Aux_U8_b) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U8_a) * ((UInt32) z_table[1])))) / Aux_U8_c);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_a = (UInt16) ((((UInt32) (((UInt32) Aux_U8_b) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U8_a) * ((UInt32) z_table[1])))) / Aux_U8_c);
   }

   /* Differences in row axis. */
   Aux_U16_b = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_c = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_c != 0) {
      if (Aux_U16 < Aux_U16_a) {
         /* Positive slope. */
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) Aux_U16_b)) /
          Aux_U16_c));
      }
      else {
         /* Negative slope. */
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) Aux_U16_b)) /
          Aux_U16_c));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4168
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4168 *map                 data structure
 ***      UInt8              x                   searching for f(X,y)
 ***      UInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

UInt16 Tab2DS34I2T4168(const MAP_Tab2DS34I2T4168 * map, UInt8 x, UInt16 y, UInt8 * local_xLow, UInt8
   * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U8_a = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U8_a) {
      x = Aux_U8_a;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U16) {
      y = Aux_U16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (y - y_table[0]);
   Aux_U16_a = (UInt16) (y_table[1] - y);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);

   /* Interpolation. */
   if (Aux_U16_b == 0) {
      Aux_U16_c = z_table[0];
      Aux_U16_d = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_d = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
   }

   /* Differences in row axis. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   Aux_U8_b = (UInt8) (Aux_U8 + Aux_U8_a);
   if (Aux_U8_b != 0) {
      /* X-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U8_a) * ((UInt32) Aux_U16_c))) + ((UInt32)
       (((UInt32) Aux_U8) * ((UInt32) Aux_U16_d)))) / Aux_U8_b);
   }
   return Aux_U16_c;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4169
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4169 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      UInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

UInt16 Tab2DS34I2T4169(const MAP_Tab2DS34I2T4169 * map, UInt16 x, UInt16 y, UInt8 * local_xLow,
  UInt8 * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16) {
      x = Aux_U16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U16) {
      y = Aux_U16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (y - y_table[0]);
   Aux_U16_a = (UInt16) (y_table[1] - y);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);

   /* Interpolation. */
   if (Aux_U16_b == 0) {
      Aux_U16_c = z_table[0];
      Aux_U16_d = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_d = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (x - x_table[0]);
   Aux_U16_a = (UInt16) (x_table[1] - x);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);
   if (Aux_U16_b != 0) {
      /* X-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) Aux_U16_c))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) Aux_U16_d)))) / Aux_U16_b);
   }
   return Aux_U16_c;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntpI1T0
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt8              irx[2]              1. table input index
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt8 Tab1DIntpI1T0(const UInt8 * z_table, UInt8 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   z_table += irx[0];
   Aux_U8 = *((z_table)++);
   if (irx[1] != 0)
   {
      Aux_U8_a = *(z_table);
      if (Aux_U8 <= Aux_U8_a)
      {
         Aux_U8 += ((UInt8) ((((UInt16) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt16) irx[1])) >> 8));
      }
      else
      {
         Aux_U8 -= ((UInt8) ((((UInt16) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt16) irx[1])) >> 8));
      }
   }
   return Aux_U8;
}
#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS18T0
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt8              irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS18T0(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U8 = (UInt8) irx[0];
         x_table += Aux_U8;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         irx[0] = Aux_U8;
         irx[1] = (UInt8) (((UInt16) (((UInt16) (UInt8) (x - x_table[0])) << 8)) / ((UInt8)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T1025
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS50T1025(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt32 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table))
   {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else
      {
         Aux_U8 = *(irx);
         x_table += Aux_U8;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U8;
         C__U64SHLU16C6_EQ32((UInt16) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U16 = (UInt16) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U16, *(fraction));
      }
   }
}
#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T1169
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt32             N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt32 *           irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS50T1169(const UInt16 * x_table, UInt32 N, UInt16 x, UInt32 * irx, UInt32 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else
      {
         Aux_U32 = *(irx);
         x_table += Aux_U32;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U32);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U32)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U32;
         C__U64SHLU16C6_EQ32((UInt16) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U16 = (UInt16) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U16, *(fraction));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T66692
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt32             irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt32             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
SInt16 Tab2DIntp2I1T66692(const SInt16 * z_table, UInt8 N, UInt32 irx, UInt32 fractionX, UInt8 iry,
  UInt32 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;
   UInt16 Aux_U16;

   z_table += (((UInt32) (irx * ((UInt32) N))) + ((UInt32) iry));
   Aux_I16 = z_table[0];
   if (fractionY == 0)
   {
      Aux_I16_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_I16_b = z_table[1];
      if (Aux_I16 <= Aux_I16_b)
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_b) - ((UInt16) Aux_I16));

         /* AddonFlex/Subsystem1/F03_Mini_Spark_Advance/F01_Thermal_protection/IgSys_agIgMinKnkFlex_
            M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_b));

         /* AddonFlex/Subsystem1/F03_Mini_Spark_Advance/F01_Thermal_protection/IgSys_agIgMinKnkFlex_
            M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      if (fractionX == 0)
      {
         return Aux_I16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I16_b = z_table[0];
      if (Aux_I16_a <= Aux_I16_b)
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_b) - ((UInt16) Aux_I16_a));

         /* AddonFlex/Subsystem1/F03_Mini_Spark_Advance/F01_Thermal_protection/IgSys_agIgMinKnkFlex_
            M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16_a += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16_b));

         /* AddonFlex/Subsystem1/F03_Mini_Spark_Advance/F01_Thermal_protection/IgSys_agIgMinKnkFlex_
            M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16_a -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   if (fractionX != 0)
   {
      if (Aux_I16 <= Aux_I16_a)
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16));

         /* AddonFlex/Subsystem1/F03_Mini_Spark_Advance/F01_Thermal_protection/IgSys_agIgMinKnkFlex_
            M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_a));

         /* AddonFlex/Subsystem1/F03_Mini_Spark_Advance/F01_Thermal_protection/IgSys_agIgMinKnkFlex_
            M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T66691
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt8 *      z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt32             irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt32             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
SInt8 Tab2DIntp2I1T66691(const SInt8 * z_table, UInt8 N, UInt32 irx, UInt32 fractionX, UInt8 iry,
  UInt32 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   SInt8 Aux_I8;
   SInt8 Aux_I8_a;
   SInt8 Aux_I8_b;
   UInt8 Aux_U8;

   z_table += (((UInt32) (irx * ((UInt32) N))) + ((UInt32) iry));
   Aux_I8 = z_table[0];
   if (fractionY == 0)
   {
      Aux_I8_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_I8_b = z_table[1];
      if (Aux_I8 <= Aux_I8_b)
      {
         Aux_U8 = (UInt8) (((UInt8) Aux_I8_b) - ((UInt8) Aux_I8));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64MUL_LE32LE3
            2_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U8, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I8 += ((SInt8) C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U8 = (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_b));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64MUL_LE32LE3
            2_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U8, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I8 -= ((SInt8) C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      if (fractionX == 0)
      {
         return Aux_I8;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I8_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I8_b = z_table[0];
      if (Aux_I8_a <= Aux_I8_b)
      {
         Aux_U8 = (UInt8) (((UInt8) Aux_I8_b) - ((UInt8) Aux_I8_a));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64MUL_LE32LE3
            2_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U8, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I8_a += ((SInt8) C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U8 = (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8_b));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64MUL_LE32LE3
            2_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U8, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I8_a -= ((SInt8) C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   if (fractionX != 0)
   {
      if (Aux_I8 <= Aux_I8_a)
      {
         Aux_U8 = (UInt8) (((UInt8) Aux_I8_a) - ((UInt8) Aux_I8));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64MUL_LE32LE3
            2_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U8, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_I8 += ((SInt8) C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U8 = (UInt8) (((UInt8) Aux_I8) - ((UInt8) Aux_I8_a));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64MUL_LE32LE3
            2_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U8, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_I8 -= ((SInt8) C__U8SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   return Aux_I8;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T66564
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt32             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
SInt16 Tab2DIntp2I1T66564(const SInt16 * z_table, UInt8 N, UInt8 irx, UInt32 fractionX, UInt8 iry,
  UInt32 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;
   UInt16 Aux_U16;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_I16 = z_table[0];
   if (fractionY == 0)
   {
      Aux_I16_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_I16_b = z_table[1];
      if (Aux_I16 <= Aux_I16_b)
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_b) - ((UInt16) Aux_I16));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgCylPresMaxFlex_M/Interpolation Usi
            ng Prelookup: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_b));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgCylPresMaxFlex_M/Interpolation Usi
            ng Prelookup: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      if (fractionX == 0)
      {
         return Aux_I16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I16_b = z_table[0];
      if (Aux_I16_a <= Aux_I16_b)
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_b) - ((UInt16) Aux_I16_a));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgCylPresMaxFlex_M/Interpolation Usi
            ng Prelookup: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16_a += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16_b));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgCylPresMaxFlex_M/Interpolation Usi
            ng Prelookup: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_I16_a -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   if (fractionX != 0)
   {
      if (Aux_I16 <= Aux_I16_a)
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgCylPresMaxFlex_M/Interpolation Usi
            ng Prelookup: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else
      {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_a));

         /* AddonFlex/Subsystem1/F02_Maxi_Spark_Advance/IgSys_agIgCylPresMaxFlex_M/Interpolation Usi
            ng Prelookup: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   return Aux_I16;
}
#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS48T1025
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS48T1025(const UInt16 * x_table, UInt8 N, UInt16 x, UInt8 * irx, UInt32 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table))
   {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else
      {
         Aux_U8 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))
         {
            (Aux_U8)++;
         }
         x_table -= 2 /* 2. */;
         *(irx) = Aux_U8;
         C__U64SHLU16C6_EQ32((UInt16) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U16 = (UInt16) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U16, *(fraction));
      }
   }
}
#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS48T1024
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt8 *            irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS48T1024(const UInt8 * x_table, UInt8 N, UInt8 x, UInt8 * irx, UInt32 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table))
   {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else
      {
         Aux_U8 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))
         {
            (Aux_U8)++;
         }
         x_table -= 2 /* 2. */;
         *(irx) = Aux_U8;
         C__U64SHLU8C6_EQ32((UInt8) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U8 = (UInt8) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U8, *(fraction));
      }
   }
}
#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS50T1168
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt32             N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt32 *           irx                 table output
 ***      UInt32 *           fraction            table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction, two variables
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS50T1168(const UInt8 * x_table, UInt32 N, UInt8 x, UInt32 * irx, UInt32 * fraction)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table))
   {
      *(irx) = 0;
      *(fraction) = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         *(irx) = N - 1;
         *(fraction) = 0;
      }
      else
      {
         Aux_U32 = *(irx);
         x_table += Aux_U32;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U32);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U32)++;
            }
            x_table -= 2 /* 2. */;
         }
         *(irx) = Aux_U32;
         C__U64SHLU8C6_EQ32((UInt8) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U8 = (UInt8) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U8, *(fraction));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"



/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T66561
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      UInt32             fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DIntp2I1T66561(const UInt16 * z_table, UInt8 N, UInt8 irx, UInt32 fractionX, UInt8 iry,
  UInt32 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_U16 = z_table[0];
   if (fractionY == 0)
   {
      Aux_U16_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];
      if (Aux_U16 <= Aux_U16_b)
      {
         Aux_U16_c = (UInt16) (Aux_U16_b - Aux_U16);

         /* AddonFlex/Subsystem/InjSys_facAgInj3AdpEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else
      {
         Aux_U16_c = (UInt16) (Aux_U16 - Aux_U16_b);

         /* AddonFlex/Subsystem/InjSys_facAgInj3AdpEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      if (fractionX == 0)
      {
         return Aux_U16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U16_b = z_table[0];
      if (Aux_U16_a <= Aux_U16_b)
      {
         Aux_U16_c = (UInt16) (Aux_U16_b - Aux_U16_a);

         /* AddonFlex/Subsystem/InjSys_facAgInj3AdpEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_U16_a += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else
      {
         Aux_U16_c = (UInt16) (Aux_U16_a - Aux_U16_b);

         /* AddonFlex/Subsystem/InjSys_facAgInj3AdpEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, fractionY, &(Aux_U32), &(Aux_U32_a));
         Aux_U16_a -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   if (fractionX != 0)
   {
      if (Aux_U16 <= Aux_U16_a)
      {
         Aux_U16_b = (UInt16) (Aux_U16_a - Aux_U16);

         /* AddonFlex/Subsystem/InjSys_facAgInj3AdpEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else
      {
         Aux_U16_b = (UInt16) (Aux_U16 - Aux_U16_a);

         /* AddonFlex/Subsystem/InjSys_facAgInj3AdpEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T145
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt32             irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab1DIntp2I1T145(const UInt16 * z_table, UInt32 irx, UInt32 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += irx;
   Aux_U16 = *((z_table)++);
   if (fractionX != 0)
   {
      Aux_U16_a = *(z_table);
      if (Aux_U16 <= Aux_U16_a)
      {
         Aux_U16_b = (UInt16) (Aux_U16_a - Aux_U16);

         /* AddonFlex/Subsystem/InjSys_agInj3AdpEth_T: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else
      {
         Aux_U16_b = (UInt16) (Aux_U16 - Aux_U16_a);

         /* AddonFlex/Subsystem/InjSys_agInj3AdpEth_T: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T4161
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T4161 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      UInt8              y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DS0I2T4161(const MAP_Tab2DS0I2T4161 * map, UInt16 x, UInt8 y)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table))
   {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16)
   {
      x = Aux_U16;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))
   {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table))
   {
      y = y_table[0];
   }
   Aux_U8_a = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U8_a)
   {
      y = Aux_U8_a;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))
   {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U8_a = (UInt8) (y - y_table[0]);
   Aux_U8_b = (UInt8) (y_table[1] - y);
   Aux_U8_c = (UInt8) (Aux_U8_a + Aux_U8_b);

   /* Interpolation. */
   if (Aux_U8_c == 0)
   {
      Aux_U16 = z_table[0];
      Aux_U16_a = z_table[Aux_U8];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_U16 = (UInt16) ((((UInt32) (((UInt32) Aux_U8_b) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U8_a) * ((UInt32) z_table[1])))) / Aux_U8_c);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_a = (UInt16) ((((UInt32) (((UInt32) Aux_U8_b) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U8_a) * ((UInt32) z_table[1])))) / Aux_U8_c);
   }

   /* Differences in row axis. */
   Aux_U16_b = (UInt16) (x - x_table[0]);
   Aux_U16_c = (UInt16) (x_table[1] - x);
   Aux_U16_d = (UInt16) (Aux_U16_b + Aux_U16_c);
   if (Aux_U16_d != 0)
   {
      /* X-Interpolation. */
      Aux_U16 = (UInt16) ((((UInt32) (((UInt32) Aux_U16_c) * ((UInt32) Aux_U16))) + ((UInt32)
       (((UInt32) Aux_U16_b) * ((UInt32) Aux_U16_a)))) / Aux_U16_d);
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS2I0T524
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS2I0T524 *map                 data structure
 ***      SInt16             x                   table input
 ***      UInt8 *            local_xLow          table index found in previous search
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search
 ***      Look-up method.....................: Interpolation - Extrapolation
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab1DS2I0T524(const MAP_Tab1DS2I0T524 * map, SInt16 x, UInt8 * local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;

   /* Extrapolation. */
   if (x <= *(x_table))
   {
      Aux_U8 = 0;
   }
   else
   {
      if (x >= x_table[(UInt8) (map->Nx - 1)])
      {
         Aux_U8 = (UInt8) (map->Nx - 2);
         x_table += Aux_U8;
      }
      else
      {
         Aux_U8 = *(local_xLow);
         x_table += Aux_U8;

         /* Local search. */
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U8);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x > *((x_table)++))
            {
               (Aux_U8)++;
            }
            x_table -= 2 /* 2. */;
         }
      }
   }
   *(local_xLow) = Aux_U8;
   z_table += Aux_U8;
   Aux_U16 = *((z_table)++);
   Aux_U16_a = *(z_table);

   /* Interpolation. */
   Aux_U16_b = (x < x_table[0]) ? (UInt16) (((UInt16) x_table[0]) - ((UInt16) x)) : (UInt16)
    (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_c = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   Aux_U16_d = (Aux_U16_a < Aux_U16) ? (UInt16) (Aux_U16 - Aux_U16_a) : (UInt16) (Aux_U16_a -
    Aux_U16);
   if (Aux_U16_c == 0)
   {
      Aux_U32 = 0;
   }
   else
   {
      Aux_U32 = (((UInt32) Aux_U16_d) * ((UInt32) Aux_U16_b)) / ((UInt32) Aux_U16_c);
   }
   if ((Aux_U16 < Aux_U16_a) ^ (x < *(x_table)))
   {
      /* AddonFlex/Subsystem/F03_F01_Adapt_afterstart_Warmup_Compensations/If Action Subsystem1/F03_
         F01_F03_After_start2/InjSys_facHotStrtCorEth_T/Extrapol_EndValues: Omitted lower saturation
       */
      Aux_U32_a = ((UInt32) Aux_U16) + Aux_U32;
      Aux_U16 = C__U16FITU32_SATu(Aux_U32_a, 65535 /* 65535. */);
   }
   else
   {
      /* AddonFlex/Subsystem/F03_F01_Adapt_afterstart_Warmup_Compensations/If Action Subsystem1/F03_
         F01_F03_After_start2/InjSys_facHotStrtCorEth_T/Extrapol_EndValues: Omitted lower saturation
       */
      Aux_U32_a = ((UInt32) Aux_U16) - Aux_U32;
      Aux_U16 = C__U16FITU32_SATu(Aux_U32_a, 65535 /* 65535. */);
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T4194
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T4194 *map                 data structure
 ***      UInt32             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DS0I2T4194(const MAP_Tab2DS0I2T4194 * map, UInt32 x, SInt16 y)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;
   UInt16 Aux_U16_e;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt32 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table))
   {
      x = x_table[0];
   }
   Aux_U32 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U32)
   {
      x = Aux_U32;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))
   {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table))
   {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16)
   {
      y = Aux_I16;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))
   {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0)
   {
      Aux_U16_b = z_table[0];
      Aux_U16_c = z_table[Aux_U8];
   }
   else
   {
      Aux_U16_d = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e)
      {
         /* Positive slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else
      {
         /* Negative slope. */
         Aux_U16_b = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U16_d = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U16_e = z_table[1];
      if (Aux_U16_d < Aux_U16_e)
      {
         /* Positive slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d + ((UInt16) ((((UInt32) (UInt16) (Aux_U16_e - Aux_U16_d)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else
      {
         /* Negative slope. */
         Aux_U16_c = (UInt16) (Aux_U16_d - ((UInt16) ((((UInt32) (UInt16) (Aux_U16_d - Aux_U16_e)) *
           ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U32 = x - x_table[0];
   Aux_U32_a = x_table[1] - x_table[0];
   if (Aux_U32_a != 0)
   {
      if (Aux_U16_b < Aux_U16_c)
      {
         Aux_U16 = (UInt16) (Aux_U16_c - Aux_U16_b);

         /* AddonFlex/Subsystem/F03_F01_Adapt_afterstart_Warmup_Compensations/If Action Subsystem1/F
            03_F01_F03_After_start2/InjSys_facAstTiEngStopEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));

         /* Positive slope. */
         C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16);
         Aux_U16_b += Aux_U16;
      }
      else
      {
         Aux_U16 = (UInt16) (Aux_U16_b - Aux_U16_c);

         /* AddonFlex/Subsystem/F03_F01_Adapt_afterstart_Warmup_Compensations/If Action Subsystem1/F
            03_F01_F03_After_start2/InjSys_facAstTiEngStopEth_M: ANSI_F_64MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));

         /* Negative slope. */
         C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16);
         Aux_U16_b -= Aux_U16;
      }
   }
   return Aux_U16_b;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS18T73
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS18T73(const UInt16 * x_table, UInt16 N, UInt16 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U16 = (UInt16) irx[0];
         x_table += Aux_U16;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U16);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U16)++;
            }
            x_table -= 2 /* 2. */;
         }
         irx[0] = Aux_U16;
         irx[1] = (UInt16) (((UInt32) (((UInt32) (UInt16) (x - x_table[0])) << 16)) / ((UInt16)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS18T72
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS18T72(const UInt8 * x_table, UInt16 N, UInt8 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U16 = (UInt16) irx[0];
         x_table += Aux_U16;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U16);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U16)++;
            }
            x_table -= 2 /* 2. */;
         }
         irx[0] = Aux_U16;
         irx[1] = (UInt16) (((UInt32) (((UInt32) (UInt8) (x - x_table[0])) << 16)) / ((UInt8)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS18T76
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: local search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS18T76(const SInt16 * x_table, UInt16 N, SInt16 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U16 = (UInt16) irx[0];
         x_table += Aux_U16;
         if (x < *(x_table))
         {
            /* Linear search, start high. */
            do
            {
               --(Aux_U16);
               --(x_table);
            }
            while (x < *(x_table));
         }
         else
         {
            /* Linear search, start low. */
            (x_table)++;
            while (x >= *((x_table)++))
            {
               (Aux_U16)++;
            }
            x_table -= 2 /* 2. */;
         }
         irx[0] = Aux_U16;
         irx[1] = (UInt16) (((UInt32) (((UInt32) (UInt16) (((UInt16) x) - ((UInt16) x_table[0]))) <<
           16)) / ((UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntpI1T577
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt16             irx[2]              1. table input index
 ***      UInt16             iry[2]              2. table input index
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DIntpI1T577(const UInt16 * z_table, UInt8 N, UInt16 irx[2], UInt16 iry[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += (((UInt32) (((UInt32) irx[0]) * ((UInt32) N))) + ((UInt32) iry[0]));
   Aux_U16 = z_table[0];
   if (iry[1] == 0)
   {
      Aux_U16_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];
      if (Aux_U16 <= Aux_U16_b)
      {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16)) * ((UInt32) iry[1])) >>
          16));
      }
      else
      {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_b)) * ((UInt32) iry[1])) >>
          16));
      }
      if (irx[1] == 0)
      {
         return Aux_U16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U16_b = z_table[0];
      if (Aux_U16_a <= Aux_U16_b)
      {
         Aux_U16_a += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16_a)) * ((UInt32) iry[1]))
          >> 16));
      }
      else
      {
         Aux_U16_a -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16_b)) * ((UInt32) iry[1]))
          >> 16));
      }
   }
   if (irx[1] != 0)
   {
      if (Aux_U16 <= Aux_U16_a)
      {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) irx[1])) >>
          16));
      }
      else
      {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) irx[1])) >>
          16));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T73
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T73(const UInt16 * x_table, UInt16 N, UInt16 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U16 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))
         {
            (Aux_U16)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U16;
         irx[1] = (UInt16) (((UInt32) (((UInt32) (UInt16) (x - x_table[0])) << 16)) / ((UInt16)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T76
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T76(const SInt16 * x_table, UInt16 N, SInt16 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U16 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))
         {
            (Aux_U16)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U16;
         irx[1] = (UInt16) (((UInt32) (((UInt32) (UInt16) (((UInt16) x) - ((UInt16) x_table[0]))) <<
           16)) / ((UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntpI1T9
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt16             irx[2]              1. table input index
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab1DIntpI1T9(const UInt16 * z_table, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   z_table += irx[0];
   Aux_U16 = *((z_table)++);
   if (irx[1] != 0)
   {
      Aux_U16_a = *(z_table);
      if (Aux_U16 <= Aux_U16_a)
      {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) irx[1])) >>
          16));
      }
      else
      {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) irx[1])) >>
          16));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T4
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     x_table             pointer to x-axis vector
 ***      UInt8              N                   number of values in x-axis vector
 ***      SInt16             x                   table input
 ***      UInt8              irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T4(const SInt16 * x_table, UInt8 N, SInt16 x, UInt8 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U8 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))
         {
            (Aux_U8)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U8;
         irx[1] = (UInt8) (((UInt32) (((UInt32) (UInt16) (((UInt16) x) - ((UInt16) x_table[0]))) <<
          8)) / ((UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]))));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntpI1T65
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt16             irx[2]              1. table input index
 ***      UInt8              iry[2]              2. table input index
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DIntpI1T65(const UInt16 * z_table, UInt8 N, UInt16 irx[2], UInt8 iry[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += (((UInt32) (((UInt32) irx[0]) * ((UInt32) N))) + ((UInt32) iry[0]));
   Aux_U16 = z_table[0];
   if (iry[1] == 0)
   {
      Aux_U16_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];
      if (Aux_U16 <= Aux_U16_b)
      {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16)) * ((UInt32) iry[1])) >>
          8));
      }
      else
      {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_b)) * ((UInt32) iry[1])) >>
          8));
      }
      if (irx[1] == 0)
      {
         return Aux_U16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U16_b = z_table[0];
      if (Aux_U16_a <= Aux_U16_b)
      {
         Aux_U16_a += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_b - Aux_U16_a)) * ((UInt32) iry[1]))
          >> 8));
      }
      else
      {
         Aux_U16_a -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16_b)) * ((UInt32) iry[1]))
          >> 8));
      }
   }
   if (irx[1] != 0)
   {
      if (Aux_U16 <= Aux_U16_a)
      {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) irx[1])) >>
          16));
      }
      else
      {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) irx[1])) >>
          16));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T74
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      UInt32             x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T74(const UInt32 * x_table, UInt16 N, UInt32 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32 /* LSB: 2^-16 OFF:  0 MIN/MAX:  0 .. 65535.9999847412 */;
   UInt32 Aux_U32_a /* LSB: 2^-16 OFF:  0 MIN/MAX:  0 .. 65535.9999847412 */;
   UInt32 Aux_U32_b;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table))
   {
      irx[0] = 0;
      irx[1] = 0;
   }
   else
   {
      if (x >= x_table[N - 1])
      {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else
      {
         Aux_U16 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))
         {
            (Aux_U16)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U16;
         C__U64SHLU32C6_LT32(x - x_table[0], 16, 16, Aux_U32, Aux_U32_a);
         Aux_U32_b = x_table[1] - x_table[0];
         C__U16DIVU64U32(Aux_U32, Aux_U32_a, Aux_U32_b, irx[1]);
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntpI1T578
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt32 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt16             irx[2]              1. table input index
 ***      UInt16             iry[2]              2. table input index
 ***
 ***  RETURNS:
 ***      UInt32
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt32 Tab2DIntpI1T578(const UInt32 * z_table, UInt8 N, UInt16 irx[2], UInt16 iry[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;
   UInt32 Aux_U32_d;
   UInt32 Aux_U32_e;

   z_table += (((UInt32) (((UInt32) irx[0]) * ((UInt32) N))) + ((UInt32) iry[0]));
   Aux_U32 = z_table[0];
   if (iry[1] == 0)
   {
      Aux_U32_a = z_table[N];
   }
   else
   {
      /* 1. Y-Interpolation. */
      Aux_U32_b = z_table[1];
      if (Aux_U32 <= Aux_U32_b)
      {
         Aux_U32_c = Aux_U32_b - Aux_U32;

         /* AddonFlex/Subsystem/F04_Offset_calculation/Interpolation_n-D_using_PreLookup2: ANSI_F_64
            MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) iry[1], &(Aux_U32_d), &(Aux_U32_e));
         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 16, 16);
      }
      else
      {
         Aux_U32_c = Aux_U32 - Aux_U32_b;

         /* AddonFlex/Subsystem/F04_Offset_calculation/Interpolation_n-D_using_PreLookup2: ANSI_F_64
            MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) iry[1], &(Aux_U32_d), &(Aux_U32_e));
         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 16, 16);
      }
      if (irx[1] == 0)
      {
         return Aux_U32;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U32_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U32_b = z_table[0];
      if (Aux_U32_a <= Aux_U32_b)
      {
         Aux_U32_c = Aux_U32_b - Aux_U32_a;

         /* AddonFlex/Subsystem/F04_Offset_calculation/Interpolation_n-D_using_PreLookup2: ANSI_F_64
            MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) iry[1], &(Aux_U32_d), &(Aux_U32_e));
         Aux_U32_a += C__U32SHRU64C6_LT32(Aux_U32_d, Aux_U32_e, 16, 16);
      }
      else
      {
         Aux_U32_c = Aux_U32_a - Aux_U32_b;

         /* AddonFlex/Subsystem/F04_Offset_calculation/Interpolation_n-D_using_PreLookup2: ANSI_F_64
            MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_c, (UInt32) iry[1], &(Aux_U32_b), &(Aux_U32_d));
         Aux_U32_a -= C__U32SHRU64C6_LT32(Aux_U32_b, Aux_U32_d, 16, 16);
      }
   }
   if (irx[1] != 0)
   {
      if (Aux_U32 <= Aux_U32_a)
      {
         Aux_U32_b = Aux_U32_a - Aux_U32;

         /* AddonFlex/Subsystem/F04_Offset_calculation/Interpolation_n-D_using_PreLookup2: ANSI_F_64
            MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) irx[1], &(Aux_U32_c), &(Aux_U32_d));
         Aux_U32 += C__U32SHRU64C6_LT32(Aux_U32_c, Aux_U32_d, 16, 16);
      }
      else
      {
         Aux_U32_b = Aux_U32 - Aux_U32_a;

         /* AddonFlex/Subsystem/F04_Offset_calculation/Interpolation_n-D_using_PreLookup2: ANSI_F_64
            MUL_LE32LE32_WOPGT32 */
         F__U64MULU32U32(Aux_U32_b, (UInt32) irx[1], &(Aux_U32_a), &(Aux_U32_c));
         Aux_U32 -= C__U32SHRU64C6_LT32(Aux_U32_a, Aux_U32_c, 16, 16);
      }
   }
   return Aux_U32;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DS0I2T525
 ***
 ***  DESCRIPTION:
 ***      Generated function for look-up tables.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab1DS0I2T525 *map                 data structure
 ***      SInt32             x                   table input
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: linear search, start low
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***      Behavior at boundaries.............: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab1DS0I2T525(const MAP_Tab1DS0I2T525 * map, SInt32 x)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;
   UInt32 Aux_U32_b;
   UInt32 Aux_U32_c;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt32 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   z_table = map->z_table;
   if (x <= *(x_table))
   {
      /* Saturation. */
      return z_table[0];
   }
   if (x >= x_table[(UInt8) (map->Nx - 1)])
   {
      return z_table[(UInt8) (map->Nx - 1)];
   }

   /* Linear search, start low. */
   (x_table)++;
   while (x > *((x_table)++))
   {
      (z_table)++;
   }
   x_table -= 2 /* 2. */;
   Aux_U16 = *((z_table)++);
   Aux_U16_a = *(z_table);

   /* Interpolation. */
   Aux_U32 = ((UInt32) x) - ((UInt32) x_table[0]);
   Aux_U32_a = ((UInt32) x_table[1]) - ((UInt32) x_table[0]);
   if (Aux_U16 <= Aux_U16_a)
   {
      /* Positive slope. */
      Aux_U16_b = (UInt16) (Aux_U16_a - Aux_U16);

      /* AddonFlex/AddonFlex_RE006_Lib/F03_F02_Adapt_injection_resume_compensation/Subsystem/If Acti
         on Subsystem1/F03_F02_F05_Compensations/InjSys_facInjResuTCorEth_T: ANSI_F_64MUL_LE32LE32_W
         OPGT32 */
      F__U64MULU32U32((UInt32) Aux_U16_b, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));
      C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16_b);
      Aux_U16 += Aux_U16_b;
   }
   else
   {
      /* Negative slope. */
      Aux_U16_b = (UInt16) (Aux_U16 - Aux_U16_a);

      /* AddonFlex/AddonFlex_RE006_Lib/F03_F02_Adapt_injection_resume_compensation/Subsystem/If Acti
         on Subsystem1/F03_F02_F05_Compensations/InjSys_facInjResuTCorEth_T: ANSI_F_64MUL_LE32LE32_W
         OPGT32 */
      F__U64MULU32U32((UInt32) Aux_U16_b, Aux_U32, &(Aux_U32_b), &(Aux_U32_c));
      C__U16DIVU64U32(Aux_U32_b, Aux_U32_c, Aux_U32_a, Aux_U16_a);
      Aux_U16 -= Aux_U16_a;
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntpI1T1
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              irx[2]              1. table input index
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab1DIntpI1T1(const UInt16 * z_table, UInt8 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   z_table += irx[0];
   Aux_U16 = *((z_table)++);
   if (irx[1] != 0) {
      Aux_U16_a = *(z_table);
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16 += ((UInt16) ((((UInt32) (UInt16) (Aux_U16_a - Aux_U16)) * ((UInt32) irx[1])) >>
          8));
      }
      else {
         Aux_U16 -= ((UInt16) ((((UInt32) (UInt16) (Aux_U16 - Aux_U16_a)) * ((UInt32) irx[1])) >>
          8));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntp2I1T129
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              irx                 1. table input index
 ***      UInt32             fractionX           1. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab1DIntp2I1T129(const UInt16 * z_table, UInt8 irx, UInt32 fractionX)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += irx;
   Aux_U16 = *((z_table)++);
   if (fractionX != 0) {
      Aux_U16_a = *(z_table);
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16_b = (UInt16) (Aux_U16_a - Aux_U16);

         /* AddonFlex/AddonFlex_RE006_Lib/F03_F02_Adapt_injection_resume_compensation/F03_F02_F06_Ad
            aptation_Flex/InjSys_facInjResuAdpEth_T/Interpolation Using Prelookup: ANSI_F_64MUL_LE32
            LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else {
         Aux_U16_b = (UInt16) (Aux_U16 - Aux_U16_a);

         /* AddonFlex/AddonFlex_RE006_Lib/F03_F02_Adapt_injection_resume_compensation/F03_F02_F06_Ad
            aptation_Flex/InjSys_facInjResuAdpEth_T/Interpolation Using Prelookup: ANSI_F_64MUL_LE32
            LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, fractionX, &(Aux_U32), &(Aux_U32_a));
         Aux_U16 -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntpI1T8
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      z_table             pointer to table vector
 ***      UInt16             irx[2]              1. table input index
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt8 Tab1DIntpI1T8(const UInt8 * z_table, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;

   z_table += irx[0];
   Aux_U8 = *((z_table)++);
   if (irx[1] != 0) {
      Aux_U8_a = *(z_table);
      if (Aux_U8 <= Aux_U8_a) {
         Aux_U8 += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8)) * ((UInt32) irx[1])) >> 16));
      }
      else {
         Aux_U8 -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8 - Aux_U8_a)) * ((UInt32) irx[1])) >> 16));
      }
   }
   return Aux_U8;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T72
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt16             N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt16             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T72(const UInt8 * x_table, UInt16 N, UInt8 x, UInt16 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table)) {
      irx[0] = 0;
      irx[1] = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else {
         Aux_U16 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))          {
            (Aux_U16)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U16;
         irx[1] = (UInt16) (((UInt32) (((UInt32) (UInt8) (x - x_table[0])) << 16)) / ((UInt8)
          (x_table[1] - x_table[0])));
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T145
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     x_table             pointer to x-axis vector
 ***      UInt32             N                   number of values in x-axis vector
 ***      UInt16             x                   table input
 ***      UInt32             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T145(const UInt16 * x_table, UInt32 N, UInt16 x, UInt32 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;

   /* Saturation. */
   if (x <= *(x_table)) {
      irx[0] = 0;
      irx[1] = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else {
         Aux_U32 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))          {
            (Aux_U32)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U32;
         C__U64SHLU16C6_EQ32((UInt16) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U16 = (UInt16) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U16, irx[1]);
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntpI1T1156
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt32             irx[2]              1. table input index
 ***      UInt32             iry[2]              2. table input index
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
SInt16 Tab2DIntpI1T1156(const SInt16 * z_table, UInt8 N, UInt32 irx[2], UInt32 iry[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   SInt16 Aux_I16_b;
   UInt16 Aux_U16;

   z_table += (((UInt32) (irx[0] * ((UInt32) N))) + iry[0]);
   Aux_I16 = z_table[0];
   if (iry[1] == 0) {
      Aux_I16_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_I16_b = z_table[1];
      if (Aux_I16 <= Aux_I16_b) {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_b) - ((UInt16) Aux_I16));

         /* AddonFlex/AddonFlex_RE_003_Lib/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64M
            UL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_b));

         /* AddonFlex/AddonFlex_RE_003_Lib/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64M
            UL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      if (irx[1] == 0) {
         return Aux_I16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_I16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_I16_b = z_table[0];
      if (Aux_I16_a <= Aux_I16_b) {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_b) - ((UInt16) Aux_I16_a));

         /* AddonFlex/AddonFlex_RE_003_Lib/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64M
            UL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16_a += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16_b));

         /* AddonFlex/AddonFlex_RE_003_Lib/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64M
            UL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16_a -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   if (irx[1] != 0) {
      if (Aux_I16 <= Aux_I16_a) {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16));

         /* AddonFlex/AddonFlex_RE_003_Lib/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64M
            UL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, irx[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_a));

         /* AddonFlex/AddonFlex_RE_003_Lib/F02_Maxi_Spark_Advance/IgSys_agIgMaxFlexOfs_M: ANSI_F_64M
            UL_LE32LE32_WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, irx[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TabIdxS16T144
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for PreLook-Up Index Search blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt8 *      x_table             pointer to x-axis vector
 ***      UInt32             N                   number of values in x-axis vector
 ***      UInt8              x                   table input
 ***      UInt32             irx[2]              table output
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***      Search algorithm...................: ascending linear search.
 ***      Output configuration...............: output index and fraction
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
Void TabIdxS16T144(const UInt8 * x_table, UInt32 N, UInt8 x, UInt32 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a /* LSB: 2^-32 OFF:  0 MIN/MAX:  0 .. 0.9999999997672 */;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;

   /* Saturation. */
   if (x <= *(x_table)) {
      irx[0] = 0;
      irx[1] = 0;
   }
   else {
      if (x >= x_table[N - 1]) {
         irx[0] = N - 1;
         irx[1] = 0;
      }
      else {
         Aux_U32 = 0;

         /* Linear search, start low. */
         (x_table)++;
         while (x >= *((x_table)++))          {
            (Aux_U32)++;
         }
         x_table -= 2 /* 2. */;
         irx[0] = Aux_U32;
         C__U64SHLU8C6_EQ32((UInt8) (x - x_table[0]), Aux_U32, Aux_U32_a);
         Aux_U8 = (UInt8) (x_table[1] - x_table[0]);
         C__U32DIVU64U32(Aux_U32, Aux_U32_a, (UInt32) Aux_U8, irx[1]);
      }
   }
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab1DIntpI1T20
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const SInt16 *     z_table             pointer to table vector
 ***      UInt32             irx[2]              1. table input index
 ***
 ***  RETURNS:
 ***      SInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 1
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
SInt16 Tab1DIntpI1T20(const SInt16 * z_table, UInt32 irx[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   SInt16 Aux_I16_a;
   UInt16 Aux_U16;

   z_table += irx[0];
   Aux_I16 = *((z_table)++);
   if (irx[1] != 0) {
      Aux_I16_a = *(z_table);
      if (Aux_I16 <= Aux_I16_a) {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16_a) - ((UInt16) Aux_I16));

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup2: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, irx[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16 += ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
      else {
         Aux_U16 = (UInt16) (((UInt16) Aux_I16) - ((UInt16) Aux_I16_a));

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup2: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16, irx[1], &(Aux_U32), &(Aux_U32_a));
         Aux_I16 -= ((SInt16) C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a));
      }
   }
   return Aux_I16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntpI1T1153
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt32             irx[2]              1. table input index
 ***      UInt32             iry[2]              2. table input index
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DIntpI1T1153(const UInt16 * z_table, UInt8 N, UInt32 irx[2], UInt32 iry[2])
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   UInt32 Aux_U32;
   UInt32 Aux_U32_a;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;

   z_table += (((UInt32) (irx[0] * ((UInt32) N))) + iry[0]);
   Aux_U16 = z_table[0];
   if (iry[1] == 0) {
      Aux_U16_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];
      if (Aux_U16 <= Aux_U16_b) {
         Aux_U16_c = (UInt16) (Aux_U16_b - Aux_U16);

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup5: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_U16 += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else {
         Aux_U16_c = (UInt16) (Aux_U16 - Aux_U16_b);

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup5: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_U16 -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      if (irx[1] == 0) {
         return Aux_U16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U16_b = z_table[0];
      if (Aux_U16_a <= Aux_U16_b) {
         Aux_U16_c = (UInt16) (Aux_U16_b - Aux_U16_a);

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup5: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_U16_a += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else {
         Aux_U16_c = (UInt16) (Aux_U16_a - Aux_U16_b);

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup5: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_c, iry[1], &(Aux_U32), &(Aux_U32_a));
         Aux_U16_a -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   if (irx[1] != 0) {
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16_b = (UInt16) (Aux_U16_a - Aux_U16);

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup5: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, irx[1], &(Aux_U32), &(Aux_U32_a));
         Aux_U16 += C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
      else {
         Aux_U16_b = (UInt16) (Aux_U16 - Aux_U16_a);

         /* AddonFlex/AddonFlex_RE_004_Lib/Interpolation_n-D_using_PreLookup5: ANSI_F_64MUL_LE32LE32
            _WOPGT32 */
         F__U64MULU32U32((UInt32) Aux_U16_b, irx[1], &(Aux_U32), &(Aux_U32_a));
         Aux_U16 -= C__U16SHRU64C6_EQ32(Aux_U32, Aux_U32_a);
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"


/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DIntp2I1T199681
 ***
 ***  DESCRIPTION:
 ***      Automatic generated function for Interpolation using PreLook-Up blocks.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const UInt16 *     z_table             pointer to table vector
 ***      UInt8              N                   number of values in y-axis vector
 ***      UInt8              irx                 1. table input index
 ***      Float32            fractionX           1. table input fraction
 ***      UInt8              iry                 2. table input index
 ***      Float32            fractionY           2. table input fraction
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Number of table dimensions.........: 2
 ***      Interpolation......................: on
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DIntp2I1T199681(const UInt16 * z_table, UInt8 N, UInt8 irx, float32 fractionX, UInt8 iry,
   float32 fractionY)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;

   z_table += ((UInt16) (((UInt16) (((UInt16) irx) * ((UInt16) N))) + ((UInt16) iry)));
   Aux_U16 = z_table[0];
   if (fractionY == 0.F) {
      Aux_U16_a = z_table[N];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_b = z_table[1];
      if (Aux_U16 <= Aux_U16_b) {
         Aux_U16 += ((UInt16) (((float32) (UInt16) (Aux_U16_b - Aux_U16)) * fractionY));
      }
      else {
         Aux_U16 -= ((UInt16) (((float32) (UInt16) (Aux_U16 - Aux_U16_b)) * fractionY));
      }
      if (fractionX == 0.F) {
         return Aux_U16;
      }
      z_table += N;

      /* 2. Y-Interpolation. */
      Aux_U16_a = *((z_table)++);

      /* X-Interpolation. */
      Aux_U16_b = z_table[0];
      if (Aux_U16_a <= Aux_U16_b) {
         Aux_U16_a += ((UInt16) (((float32) (UInt16) (Aux_U16_b - Aux_U16_a)) * fractionY));
      }
      else {
         Aux_U16_a -= ((UInt16) (((float32) (UInt16) (Aux_U16_a - Aux_U16_b)) * fractionY));
      }
   }
   if (fractionX != 0.F) {
      if (Aux_U16 <= Aux_U16_a) {
         Aux_U16 += ((UInt16) (((float32) (UInt16) (Aux_U16_a - Aux_U16)) * fractionX));
      }
      else {
         Aux_U16 -= ((UInt16) (((float32) (UInt16) (Aux_U16 - Aux_U16_a)) * fractionX));
      }
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS0I2T4168
 ***
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 ***
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS0I2T4168 *map                 data structure
 ***      UInt8              x                   searching for f(X,y)
 ***      UInt16             y                   searching for f(x,Y
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: linear search, start low
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DS0I2T4168(const MAP_Tab2DS0I2T4168 * map, UInt8 x, UInt16 y)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt8 * x_table /* Scaling may differ through function reuse. */;
   const UInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U8_a = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U8_a) {
      x = Aux_U8_a;
   }

   /* Search algorithm for row axis. */
   (x_table)++;
   Aux_U8_a = 0;

   /* Linear search, start low. */
   while (x > *((x_table)++))    {
      (Aux_U8_a)++;
   }
   x_table -= 2 /* 2. */;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U16) {
      y = Aux_U16;
   }

   /* Search algorithm for column axis. */
   (y_table)++;

   /* Linear search, start low. */
   while (y > *((y_table)++))    {
      (z_table)++;
   }
   y_table -= 2 /* 2. */;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (y - y_table[0]);
   Aux_U16_a = (UInt16) (y_table[1] - y);
   Aux_U16_b = (UInt16) (Aux_U16 + Aux_U16_a);

   /* Interpolation. */
   if (Aux_U16_b == 0) {
      Aux_U16_c = z_table[0];
      Aux_U16_d = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_d = (UInt16) ((((UInt32) (((UInt32) Aux_U16_a) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U16) * ((UInt32) z_table[1])))) / Aux_U16_b);
   }

   /* Differences in row axis. */
   Aux_U8 = (UInt8) (x - x_table[0]);
   Aux_U8_a = (UInt8) (x_table[1] - x);
   Aux_U8_b = (UInt8) (Aux_U8 + Aux_U8_a);
   if (Aux_U8_b != 0) {
      /* X-Interpolation. */
      Aux_U16_c = (UInt16) ((((UInt32) (((UInt32) Aux_U8_a) * ((UInt32) Aux_U16_c))) + ((UInt32)
       (((UInt32) Aux_U8) * ((UInt32) Aux_U16_d)))) / Aux_U8_b);
   }
   return Aux_U16_c;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T4161
 *** 
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T4161 *map                 data structure
 ***      UInt16             x                   searching for f(X,y)
 ***      UInt8              y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt16
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt16 Tab2DS34I2T4161(const MAP_Tab2DS34I2T4161 * map, UInt16 x, UInt8 y, UInt8 * local_xLow, UInt8
   * local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;
   UInt16 Aux_U16_b;
   UInt16 Aux_U16_c;
   UInt16 Aux_U16_d;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const UInt16 * x_table /* Scaling may differ through function reuse. */;
   const UInt8 * y_table /* Scaling may differ through function reuse. */;
   const UInt16 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_U16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_U16) {
      x = Aux_U16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_U8_a = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_U8_a) {
      y = Aux_U8_a;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U8_a = (UInt8) (y - y_table[0]);
   Aux_U8_b = (UInt8) (y_table[1] - y);
   Aux_U8_c = (UInt8) (Aux_U8_a + Aux_U8_b);

   /* Interpolation. */
   if (Aux_U8_c == 0) {
      Aux_U16 = z_table[0];
      Aux_U16_a = z_table[Aux_U8];
   }
   else {
      /* 1. Y-Interpolation. */
      Aux_U16 = (UInt16) ((((UInt32) (((UInt32) Aux_U8_b) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U8_a) * ((UInt32) z_table[1])))) / Aux_U8_c);
      z_table += Aux_U8;

      /* 2. Y-Interpolation. */
      Aux_U16_a = (UInt16) ((((UInt32) (((UInt32) Aux_U8_b) * ((UInt32) z_table[0]))) + ((UInt32)
       (((UInt32) Aux_U8_a) * ((UInt32) z_table[1])))) / Aux_U8_c);
   }

   /* Differences in row axis. */
   Aux_U16_b = (UInt16) (x - x_table[0]);
   Aux_U16_c = (UInt16) (x_table[1] - x);
   Aux_U16_d = (UInt16) (Aux_U16_b + Aux_U16_c);
   if (Aux_U16_d != 0) {
      /* X-Interpolation. */
      Aux_U16 = (UInt16) ((((UInt32) (((UInt32) Aux_U16_c) * ((UInt32) Aux_U16))) + ((UInt32)
       (((UInt32) Aux_U16_b) * ((UInt32) Aux_U16_a)))) / Aux_U16_d);
   }
   return Aux_U16;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Tab2DS34I2T36
 *** 
 ***  DESCRIPTION:
 ***      Generated function for 2D look-up tables with common X- and Y-vectors.
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***      const MAP_Tab2DS34I2T36 *map                 data structure
 ***      SInt16             x                   searching for f(X,y)
 ***      SInt16             y                   searching for f(x,Y
 ***      UInt8 *            local_xLow          last index of x-vector
 ***      UInt8 *            local_yLow          last index of y-vector
 ***
 ***  RETURNS:
 ***      UInt8
 ***
 ***  SETTINGS:
 ***      Row axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Column axis
 ***      Search algorithm...................: local search
 ***      Boundary points....................: no
 ***      Starting point.....................: - (non-equidistant implementation)
 ***      Scaling unit.......................: - (non-equidistant implementation)
 ***      Interpolation
 ***      Look-up method.....................: Interpolation - Use end values
 ***      Distances fit into given bitlengths: no
 ***
\**************************************************************************************************/

#define PSA_START_SEC_CODE
#include "PSA_MemMap.h"
UInt8 Tab2DS34I2T36(const MAP_Tab2DS34I2T36 * map, SInt16 x, SInt16 y, UInt8 * local_xLow, UInt8 *
  local_yLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16;
   UInt16 Aux_U16;
   UInt16 Aux_U16_a;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   UInt8 Aux_U8;
   UInt8 Aux_U8_a;
   UInt8 Aux_U8_b;
   UInt8 Aux_U8_c;
   UInt8 Aux_U8_d;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   const SInt16 * x_table /* Scaling may differ through function reuse. */;
   const SInt16 * y_table /* Scaling may differ through function reuse. */;
   const UInt8 * z_table /* Scaling may differ through function reuse. */;

   x_table = map->x_table;
   y_table = map->y_table;
   z_table = map->z_table;
   Aux_U8 = map->Ny;

   /* Saturation. */
   if (x < *(x_table)) {
      x = x_table[0];
   }
   Aux_I16 = x_table[(UInt8) (map->Nx - 1)];
   if (x > Aux_I16) {
      x = Aux_I16;
   }
   Aux_U8_a = *(local_xLow);
   x_table += Aux_U8_a;

   /* Local search. */
   if (x < *(x_table)) {
      /* Search algorithm for row axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(x_table);
      }
      while (x < *(x_table));
   }
   else {
      /* Search algorithm for row axis. */
      (x_table)++;

      /* Linear search, start low. */
      while (x > *((x_table)++))       {
         (Aux_U8_a)++;
      }
      x_table -= 2 /* 2. */;
   }
   *(local_xLow) = Aux_U8_a;
   z_table += (((UInt16) Aux_U8) * ((UInt16) Aux_U8_a));

   /* Saturation. */
   if (y < *(y_table)) {
      y = y_table[0];
   }
   Aux_I16 = y_table[(UInt8) (Aux_U8 - 1)];
   if (y > Aux_I16) {
      y = Aux_I16;
   }
   Aux_U8_a = *(local_yLow);
   y_table += Aux_U8_a;

   /* Local search. */
   if (y < *(y_table)) {
      /* Search algorithm for column axis.
         Linear search, start high. */
      do       {
         --(Aux_U8_a);
         --(y_table);
      }
      while (y < *(y_table));
   }
   else {
      /* Search algorithm for column axis. */
      (y_table)++;

      /* Linear search, start low. */
      while (y > *((y_table)++))       {
         (Aux_U8_a)++;
      }
      y_table -= 2 /* 2. */;
   }
   *(local_yLow) = Aux_U8_a;
   z_table += Aux_U8_a;

   /* Differences in column axis. */
   Aux_U16 = (UInt16) (((UInt16) y) - ((UInt16) y_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) y_table[1]) - ((UInt16) y_table[0]));

   /* Interpolation. */
   if (Aux_U16 == 0) {
      Aux_U8_a = z_table[0];
      Aux_U8_b = z_table[Aux_U8];
   }
   else {
      Aux_U8_c = z_table[0];

      /* 1. Y-Interpolation. */
      Aux_U8_d = z_table[1];
      if (Aux_U8_c < Aux_U8_d) {
         /* Positive slope. */
         Aux_U8_a = (UInt8) (Aux_U8_c + ((UInt8) ((((UInt32) (UInt8) (Aux_U8_d - Aux_U8_c)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U8_a = (UInt8) (Aux_U8_c - ((UInt8) ((((UInt32) (UInt8) (Aux_U8_c - Aux_U8_d)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      z_table += Aux_U8;
      Aux_U8_c = z_table[0];

      /* 2. Y-Interpolation. */
      Aux_U8_d = z_table[1];
      if (Aux_U8_c < Aux_U8_d) {
         /* Positive slope. */
         Aux_U8_b = (UInt8) (Aux_U8_c + ((UInt8) ((((UInt32) (UInt8) (Aux_U8_d - Aux_U8_c)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
      else {
         /* Negative slope. */
         Aux_U8_b = (UInt8) (Aux_U8_c - ((UInt8) ((((UInt32) (UInt8) (Aux_U8_c - Aux_U8_d)) *
          ((UInt32) Aux_U16)) / Aux_U16_a)));
      }
   }

   /* Differences in row axis. */
   Aux_U16 = (UInt16) (((UInt16) x) - ((UInt16) x_table[0]));
   Aux_U16_a = (UInt16) (((UInt16) x_table[1]) - ((UInt16) x_table[0]));
   if (Aux_U16_a != 0) {
      if (Aux_U8_a < Aux_U8_b) {
         /* Positive slope. */
         Aux_U8_a += ((UInt8) ((((UInt32) (UInt8) (Aux_U8_b - Aux_U8_a)) * ((UInt32) Aux_U16)) / 
          Aux_U16_a));
      }
      else {
         /* Negative slope. */
         Aux_U8_a -= ((UInt8) ((((UInt32) (UInt8) (Aux_U8_a - Aux_U8_b)) * ((UInt32) Aux_U16)) / 
          Aux_U16_a));
      }
   }
   return Aux_U8_a;
}

#define PSA_STOP_SEC_CODE
#include "PSA_MemMap.h"

/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_LIBRARY_LUT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
