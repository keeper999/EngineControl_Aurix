/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : MUL64s02.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   MUL64s02.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: MUL64s02.c $ $Revision: 1.1 $ $Date: 2004/04/28 11:45:25GMT+01:00 $ $Author: FrankL $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/* Multiply two Int32 with UInt32 to yield a UInt64s using Booth's algorithm */
UInt64s F__I64sMULI32U32(const Int32 x, const UInt32 y)
{
	UInt64s retval;
	retval = F__U64sMULU32U32((UInt32)x, y);
	if(x < 0) retval.hi -= y;
	return(retval);
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
