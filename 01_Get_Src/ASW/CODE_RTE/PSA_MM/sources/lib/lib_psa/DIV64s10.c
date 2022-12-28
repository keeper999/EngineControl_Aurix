/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : div64s10.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/**
 * @file       div64s10.c
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
 * $Workfile: DIV64s10.c $
 * $Revision: 1.1 $
 * $Date: 2004/04/28 11:44:58GMT+01:00 $
 */


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/* signed division of Int64s by Int32 */
Int32 F__I32DIVI64sI32(const UInt64s *u, Int32 a)
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
    if(a < 0)
    {
        a = -a;
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
