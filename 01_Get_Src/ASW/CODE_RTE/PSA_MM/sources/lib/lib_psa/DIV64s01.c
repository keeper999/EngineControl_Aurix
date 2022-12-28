/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : DIV64s01.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   DIV64s01.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: DIV64s01.c $ $Revision: 1.3 $ $Date: 2005/07/11 12:48:23GMT+01:00 $ $Author: SebastianH $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */

/* divide a UInt64s by an UInt16                                     */
UInt64s F__U64sDIVU64sU16(const UInt64s *u, UInt16 a)
{
    UInt64s retval;
    UInt32s lo, v, q;
    
    /* test for divide by zero */
	if(a == 0)
    {
        retval.lo = 0xFFFFFFFFL;
        retval.hi = 0x7FFFFFFFL;
        if((Int32)u->hi < 0) retval.hi |= 0x80000000L;
        return(retval);
    }
    lo.lng = u->lo;
    v.lng  = u->hi;
	
	/* do division */

    retval.hi   = v.lng / a;
    v.lng -= retval.hi * a;

    v.pr[1] = v.pr[0];
    v.pr[0] = lo.pr[1];

    q.lng  = v.lng / a;
    v.lng -= q.lng * a;

    v.pr[1] = v.pr[0];
    v.pr[0] = lo.pr[0];

    lo.lng = v.lng / a;

    lo.pr[1] = q.pr[0];
    retval.lo =  lo.lng;
     
    return(retval);
}

#else

/* divide a UInt64s by an UInt16                                     */
UInt64s F__U64sDIVU64sU16(const UInt64s *u, UInt16 a)
{
    UInt64s retval;
    UInt32s lo, v, q;
    
    /* test for divide by zero */
	if(a == 0)
    {
        retval.lo = 0xFFFFFFFFL;
        retval.hi = 0x7FFFFFFFL;
        if((Int32)u->hi < 0) retval.hi |= 0x80000000L;
        return(retval);
    }
	lo.lng = u->lo;
    v.lng  = u->hi;

    /* do division */

    retval.hi   = v.lng / a;
    v.lng -= retval.hi * a;

    v.pr[0] = v.pr[1];
    v.pr[1] = lo.pr[0];

    q.lng  = v.lng / a;
    v.lng -= q.lng * a;

    v.pr[0] = v.pr[1];
    v.pr[1] = lo.pr[1];

    lo.lng = v.lng / a;

    lo.pr[0] = q.pr[1];
    retval.lo = lo.lng;
     
    return(retval);
}

#endif

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
