/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : DIV64_01.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   DIV64_01.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: DIV64_01.c $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:54GMT+01:00 $ $Author: FrankL $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

/******************************************************************************
*
* FUNCTION:
*   F__I64DIVI64I32(n_h, n_l, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 64bit result. 
*
* PARAMETERS:
*   type    name    meaning    
*   Int32    n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   Int32      d    denominator 
*   Int32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively 
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
*
* HISTORY:
*
******************************************************************************/
void F__I64DIVI64I32(Int32 n_h, UInt32 n_l, Int32 d, Int32 *r_h, UInt32 *r_l)
{														                        
	UInt64s tmp;										                        

	tmp.lo = n_l;										                        
	tmp.hi = (UInt32)n_h;										                        
	tmp = F__I64sDIVI64sI32(&tmp, d);					                        
	*r_h = (Int32)tmp.hi;										                        
	*r_l = tmp.lo;										                        
}/* END F__I64DIVI64I32() */


#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
