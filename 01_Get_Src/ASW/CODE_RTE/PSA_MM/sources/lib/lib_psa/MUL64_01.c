/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : mul64_01.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/**
 * @file       mul64_01.c
 * @brief      64-bit multiplication
 *
 * @since      1999-04-16
 * @author     D. Andoleit
 *
 * Copyright (c) 2003 by dSPACE GmbH, Paderborn, Germany
 * All Rights Reserved
 *
 */

/*
 * $Workfile: MUL64_01.c $
 * $Revision: 1.2 $
 * $Date: 2005/07/28 07:44:18GMT+01:00 $
 */


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/******************************************************************************
*
* FUNCTION:
*   void F__I64MULI64I32(Int32 f1_h, UInt32 f1_l, Int32 f2, Int32 *r_h, UInt32 *r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64-bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   Int32    f1_h    1. factor (high-part)
*   UInt32   f1_l    1. factor (low-part)
*   Int32    f2      2. factor
*   Int32    *r_h    64bit - result (high-part)
*   UInt32   *r_l    64bit - result (low-part)
*
* NOTE:
* f1                                                 * f2 =
* (f1_h*2^32                 + f1_l)                 * f2 =
* ((f1_hH*2^16 + f1_hL)*2^32 + f1_lH*2^16 + f1_lL)   * (f2H*2^16 + f2L) =
* (f1_hH*2^48 + f1_hL*2^32   + f1_lH*2^16 + f1_lL)   * (f2H*2^16 + f2L) =
*
* f1_hH*f2H*2^64 + f1_hL*f2H*2^48 + f1_lH*f2H*2^32 + f1_lL*f2H*2^16 +
* f1_hH*f2L*2^48 + f1_hL*f2L*2^32 + f1_lH*f2L*2^16 + f1_lL*f2L
*
* shifted by  64    48    32    16    0 Bits
* |-----|-----|-----|-----|-----|-----|
* |  f1_hH*f2H|     |     |     |     |
*       |  f1_hL*f2H|     |     |     |
*             |  f1_lH*f2H|     |     |
*                   |  f1_lL*f2H|     |
*       |  f1_hH*f2L|     |     |     |
*             |  f1_hL*f2L|     |     |
*                   |  f1_lH*f2L|     |
*                         |  f1_lL*f2L|
* |-----|-----|-----|-----|-----|-----|
*             |<   r_h   >|<   r_l   >|
*
*   Converts negative numbers with Booth-algorithm.
*
******************************************************************************/
void F__I64MULI64I32(Int32 f1_h, UInt32 f1_l, Int32 f2, Int32 *r_h, UInt32 *r_l)
{

    C__I64MULI64I32(f1_h, f1_l, f2, *r_h, *r_l)

}/*END F__I64MULI64I32()*/

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
