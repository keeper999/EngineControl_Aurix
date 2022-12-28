/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : DIV64s02.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   DIV64s02.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: DIV64s02.c $ $Revision: 1.2 $ $Date: 2005/07/05 13:38:54GMT+01:00 $ $Author: SebastianH $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */

/* divide a UInt64s by an UInt16                                     */
UInt32 F__U32DIVU64sU16(const UInt64s *u, UInt16 a)
{
    UInt32  temp;
    UInt32s lo, v, q;

    /* test for divide by zero */
    if(a == 0)
    {
        temp = 0x7FFFFFFFL;
        if((Int32)u->hi < 0) temp |= 0x80000000L;
        return temp;
    }
    lo.lng = u->lo;
    v.lng  = u->hi;

    /* do division */

    temp   = v.lng / a;
    v.lng -= temp * a;

    v.pr[1] = v.pr[0];
    v.pr[0] = lo.pr[1];

    q.lng  = v.lng / a;
    v.lng -= q.lng * a;

    v.pr[1] = v.pr[0];
    v.pr[0] = lo.pr[0];

    lo.lng = v.lng / a;

    lo.pr[1] = q.pr[0];
    
    return (lo.lng); 
}

#else

/* divide a UInt64s by an UInt16                                     */
UInt32 F__U32DIVU64sU16(const UInt64s *u, UInt16 a)
{
    UInt32  temp;
    UInt32s lo, v, q;

    /* test for divide by zero */
    if(a == 0)
    {
        temp = 0x7FFFFFFFL;
        if((Int32)u->hi < 0) temp |= 0x80000000L;
        return temp;
    }
    lo.lng = u->lo;
    v.lng  = u->hi;

    /* do division */

    temp   = v.lng / a;
    v.lng -= temp * a;

    v.pr[0] = v.pr[1];
    v.pr[1] = lo.pr[0];

    q.lng  = v.lng / a;
    v.lng -= q.lng * a;

    v.pr[0] = v.pr[1];
    v.pr[1] = lo.pr[1];

    lo.lng = v.lng / a;

    lo.pr[0] = q.pr[1];
    
    return (lo.lng); 
}

#endif

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
