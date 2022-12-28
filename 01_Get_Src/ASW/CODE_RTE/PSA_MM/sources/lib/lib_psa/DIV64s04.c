/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : DIV64s04.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   DIV64s04.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: DIV64s04.c $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:56GMT+01:00 $ $Author: FrankL $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/* mixed division of UInt64s by Int32 */
UInt64s F__I64sDIVU64sI32(const UInt64s *u, Int32 a)
{
	UInt64s retval;
	UInt64s U;
	Int8 sign = 0;

	U = *u;	/* local copy to preserve u */

	/* check signs of arguments, force positive */
	if(a < 0)
	{
		a = -a;
		sign = !sign;
	}

	/* do unsigned divide */
	retval = F__U64sDIVU64sU32(&U, (UInt32)a);

	/* restore sign */
	if(sign) negate(&retval);
	return(retval);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
