/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : div64s08.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/**
 * @file       div64s08.c
 * @brief      64-bit divisions
 *
 * @since      1999-04-16
 * @author     O. Grajetzky
 *
 * Copyright (c) 2003 by dSPACE GmbH, Paderborn, Germany
 * All Rights Reserved
 *
 */

/*
 * $Workfile: DIV64s08.c $
 * $Revision: 1.1 $
 * $Date: 2004/04/28 11:44:57GMT+01:00 $
 */


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/* mixed division of Int64s by UInt32 */
Int32 F__I32DIVI64sU32(const UInt64s *u, UInt32 a)
{
    Int32 retval;
    UInt64s U;
    Int8 sign = 0;

    U = *u;    /* local copy to preserve u */

    /* check signs of arguments, force positive */
    if((Int32)U.hi < 0)
    {
        negate(&U);
        sign = !sign;
    }

    /* do unsigned divide */
    retval = (Int32)F__U32DIVU64sU32(&U, (UInt32)a);

    /* restore sign */
    if(sign) return(-retval);
    return(retval);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
