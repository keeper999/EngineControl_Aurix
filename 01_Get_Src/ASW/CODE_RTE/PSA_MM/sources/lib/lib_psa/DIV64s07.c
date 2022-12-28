/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : DIV64s07.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   DIV64s07.c                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: DIV64s07.c $ $Revision: 1.2 $ $Date: 2005/07/29 12:06:57GMT+01:00 $ $Author: DagmarA $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */

/* divide unsigned UInt64s by UInt32 */
UInt32 F__U32DIVU64sU32(const UInt64s *U, UInt32 v)
{
	Int8 i = 0;
	Int8 j;

	/* structure to hold dividend */
	union
	{
		UInt16 d[4];
		struct
		{
			UInt64s d0d3;	/* (number matches index) */
		} s;
	} dividend;

	/* Structure to hold quotient */
	union
	{
		UInt32 Q;
		UInt16 q[2];
	} quotient;

	/* pointers to the structures */
	UInt16 *up = &dividend.d[1];
	UInt16 *qp = &quotient.q[1];

	/* first, make sure v is not a short */
	if(v <= 0xFFFF) return(F__U32DIVU64sU16(U, (UInt16)v));

	/* normalize the divisor */
    if (!(v & 0x80000000))
    {
	    for(i=0; (Int32)v > 0; i++) v <<= 1;
    }

	/* and the dividend */
	dividend.s.d0d3.hi = U->hi << i;
	if(i) /* avoid shift by 32 bits */
	{ 
	    dividend.s.d0d3.hi += (U->lo >> (32 - i));
	}
	/* check if denominator fits in numerator to avoid overflow in div3by2 */
	if ((UInt32)dividend.s.d0d3.hi >= (UInt32)v)
	{
		dividend.s.d0d3.hi -= v;
	}
	
	dividend.s.d0d3.lo = U->lo << i;

	/* start the division loop */
	for(j=0; j<2; j++) *qp-- = div3by2(up--, *(UInt32s *)&v);
	
	return(quotient.Q);
}

#else   /* Target with big-endian architecture */

/* divide unsigned UInt64s by UInt32 */
UInt32 F__U32DIVU64sU32(const UInt64s *U, UInt32 v)
{
	Int8 i = 0;
	Int8 j;

	/* structure to hold dividend */
	union
	{
		UInt16 d[4];
		struct
		{
			UInt64s d0d3;	/* (number matches index) */
		} s;
	} dividend;

	/* Structure to hold quotient */
	union
	{
		UInt32 Q;
		UInt16 q[2];
	} quotient;

	/* pointers to the structures */
	UInt16 *up = &dividend.d[0];
	UInt16 *qp = &quotient.q[0];

	/* first, make sure v is not a short */
	if(v <= 0xFFFF) return(F__U32DIVU64sU16(U, (UInt16)v));

	/* normalize the divisor */
    if (!(v & 0x80000000))
    {
    	for(i=0; (Int32)v > 0; i++) v <<= 1;
    }

	/* and the dividend */
	dividend.s.d0d3.hi = U->hi << i;
	if(i) /* avoid shift by 32 bits */
	{
	    dividend.s.d0d3.hi += (U->lo >> (32 - i));
	}
	/* check if denominator fits in numerator to avoid overflow in div3by2 */
	if ((UInt32)dividend.s.d0d3.hi >= (UInt32)v)
	{
		dividend.s.d0d3.hi -= v;
	}
	
	dividend.s.d0d3.lo = U->lo << i;

	/* start the division loop */
	for(j=0; j<2; j++) *qp++ = div3by2(up++, *(UInt32s *)&v);
	
	return(quotient.Q);
}

#endif

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
