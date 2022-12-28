/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : MUL64s01.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   MUL64s01.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: MUL64s01.c $ $Revision: 1.1 $ $Date: 2004/04/28 11:45:25GMT+01:00 $ $Author: FrankL $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */
                                                     
/* Multiply two UInt32s to yield a UInt64s */
UInt64s F__U64sMULU32U32(const UInt32 x, const UInt32 y)
{
	UInt64s retval;
	UInt32s X, Y;
	UInt32s mid;		/* middle two words */
	UInt32 ad, bc;

	/* pointer to address individual words */
	UInt16 *p = (UInt16 *)(&retval);

	/* copy is as quick as pointer assignment */
	X.lng = x;
	Y.lng = y;

	/* generate partial products */
	retval.hi = (UInt32)X.pr[1] * Y.pr[1];	/* ac */
	ad    = (UInt32)X.pr[1] * Y.pr[0];
	bc    = (UInt32)X.pr[0] * Y.pr[1];
	retval.lo = (UInt32)X.pr[0] * Y.pr[0];	/* bd */

	mid.lng = ad + p[1];		/* ad, high half of bd */
	if(mid.lng < ad) ++p[3];    /* if carry, bump high word */		
	mid.lng += bc;       		/* all of bc */
	if(mid.lng < bc) ++p[3];    /* if carry,bump high word */

	/* results into place */
	retval.hi += mid.pr[1];		/* mid.hi to hi.lo */
	p[1] = mid.pr[0];			/* mid.lo to lo.hi */
	return(retval);
}

#else

/* Multiply two UInt32s to yield a UInt64s */
UInt64s F__U64sMULU32U32(const UInt32 x, const UInt32 y)
{
	UInt64s retval;
	UInt32s X, Y;
	UInt32s mid;		/* middle two words */
	UInt32 ad, bc;

	/* pointer to address individual words */
	UInt16 *p = (UInt16 *)(&retval);

	/* copy is as quick as pointer assignment */
	X.lng = x;
	Y.lng = y;

	/* generate partial products */
	retval.hi = (UInt32)X.pr[0] * Y.pr[0];	/* ac */
	ad    = (UInt32)X.pr[0] * Y.pr[1];
	bc    = (UInt32)X.pr[1] * Y.pr[0];
	retval.lo = (UInt32)X.pr[1] * Y.pr[1];	/* bd */

	mid.lng = ad + p[2];		/* ad, high half of bd */
	if(mid.lng < ad) ++p[0];    /* if carry, bump high word */		
	mid.lng += bc;       		/* all of bc */
	if(mid.lng < bc) ++p[0];    /* if carry,bump high word */

	/* results into place */
	retval.hi += mid.pr[0];		/* mid.hi to hi.lo */
	p[2] = mid.pr[1];			/* mid.lo to lo.hi */
	return(retval);
}

#endif

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
