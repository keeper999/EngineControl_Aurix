/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : DIV64s05.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/******************************************************************************
*                                                                              
* FILE:                                                                        
*   DIV64s05.c         2000/03/22                                              
*                                                                              
*  Copyright (c) 2000 dSPACE GmbH, GERMANY                                     
*                                                                              
*  $Workfile: DIV64s05.c $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:56GMT+01:00 $ $Author: FrankL $                           
******************************************************************************/


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */

	#if ALIGN==2		/* The code must be compiled with an alignment
	                       of 2 or the 32-bit pointer arithmetic
	                       will not work properly. */

	/* divide unsigned UInt64s by UInt32 */
	UInt64s F__U64sDIVU64sU32(const UInt64s *U, UInt32 v)
	{
		Int8 i = 0;
		Int8 j;
	
		/* structure to hold dividend */
		union
		{
			UInt16 d[5];
			struct
			{
				UInt64s d0d3;
				UInt16 d4;	/* (number matches index) */
			} s;
		} dividend;

		/* Structure to hold quotient */
		union
		{
			UInt64s Q;
			UInt16 q[4];
		} quotient;

		/* pointers to the structures */
		UInt16 *up = &dividend.d[2];
		UInt16 *qp = &quotient.q[3];
	
		/* first, make sure v is not a short */
		if(v <= 0xFFFF) 
			return(F__U64sDIVU64sU16(U, (UInt16)v));

		/* normalize the divisor */
        if (!(v & 0x80000000))
        {
    		for(i=0; (Int32)v > 0; i++) 
	    		v <<= 1;
        }

		/* and the dividend */
        dividend.s.d4 = 0;              /* initialization necessary if i=0 */
		if(i) /* avoid shift by 32 bits */
		{
		    dividend.s.d4 = (UInt16)(U->hi >> (32 - i));
		}
		dividend.s.d0d3.hi = U->hi << i;
		if(i) /* avoid shift by 32 bits */
		{
    		dividend.s.d0d3.hi += (U->lo >> (32 - i));
    	}
		dividend.s.d0d3.lo = U->lo << i;

		/* start the division loop */
		*qp-- = 0;
		for(j=0; j<3; j++) 
			*qp-- = div3by2(up--, *(UInt32s *)&v);
		return(quotient.Q);
	}

	#else		 	/* If the code is not compiled with an alignment
	                   of 2 the 32-bit pointers to the nominator
	                   array must be replaced with 32-bit 
	                   variables. */

	/* divide unsigned UInt64s by UInt32 */
	UInt64s F__U64sDIVU64sU32(const UInt64s *U, UInt32 v)
	{
		Int8 i = 0;
		Int8 j;
	
		/* structure to hold dividend */
		union
		{
			UInt16 d[6];
			struct
			{
				UInt64s d0d3;
				UInt32 d4;	/* (number matches index) */
			} s;
		} dividend;

		/* Structure to hold quotient */
		union
		{
			UInt64s Q;
			UInt16 q[4];
		} quotient;

		/* pointers to the structures */
		UInt16 *up = &dividend.d[2];
		UInt16 *qp = &quotient.q[3];
	
		/* first, make sure v is not a short */
		if(v <= 0xFFFF) 
			return(F__U64sDIVU64sU16(U, (UInt16)v));

		/* normalize the divisor */
        if (!(v & 0x80000000))
        {
    		for(i=0; (Int32)v > 0; i++) 
	    		v <<= 1;
        }

		/* and the dividend */
        dividend.s.d4 = 0;              /* initialization necessary if i=0 */
		if(i) /* avoid shift by 32 bits */
		{
		    dividend.s.d4 = U->hi >> (32 - i);
		}
		dividend.s.d0d3.hi = U->hi << i;
		if(i) /* avoid shift by 32 bits */
		{
    		dividend.s.d0d3.hi += (U->lo >> (32 - i));
    	}
		dividend.s.d0d3.lo = U->lo << i;

		/* start the division loop */
		*qp-- = 0;
		for(j=0; j<3; j++) 
			*qp-- = div3by2(up--, *(UInt32s *)&v);
		return(quotient.Q);
	}

	#endif

#else					/* Target with big-endian architecture */

	#if ALIGN==2		/* The code must be compiled with an alignment
	                       of 2 or the 32-bit pointer arithmetic
	                       will not work properly. */

	/* divide unsigned UInt64s by UInt32 */
	UInt64s F__U64sDIVU64sU32(const UInt64s *U, UInt32 v)
	{
		Int8 i = 0;
		Int8 j;
	
		/* structure to hold dividend */
		union
		{
			UInt16 d[5];
			struct
			{
				UInt16 d4;	/* (number matches index) */
				UInt64s d0d3;
			} s;
		} dividend;
	
		/* Structure to hold quotient */
		union
		{
			UInt64s Q;
			UInt16 q[4];
		} quotient;
	
		/* pointers to the structures */
		UInt16 *up = &dividend.d[0];
		UInt16 *qp = &quotient.q[0];
	
		/* first, make sure v is not a short */
		if(v <= 0xFFFF) 
			return(F__U64sDIVU64sU16(U, (UInt16)v));

		/* normalize the divisor */
        if (!(v & 0x80000000))
        {
    		for(i=0; (Int32)v > 0; i++) 
	    		v <<= 1;
        }

		/* and the dividend */
        dividend.s.d4 = 0;              /* initialization necessary if i=0 */
	    if(i) /* avoid shift by 32 bits */
		{
            dividend.s.d4 = (UInt16)(U->hi >> (32 - i));
        }
		dividend.s.d0d3.hi = U->hi << i;
	    if(i) /* avoid shift by 32 bits */
		{
    		dividend.s.d0d3.hi += (U->lo >> (32 - i));
    	}
		dividend.s.d0d3.lo = U->lo << i;
	
		/* start the division loop */
		*qp++ = 0;
		for(j=0; j<3; j++) 
			*qp++ = div3by2(up++, *(UInt32s *)&v);
		return(quotient.Q);
	}
	
	#else		 	/* If the code is not compiled with an alignment
	                   of 2 the 32-bit pointers to the nominator
	                   array must be replaced with 32-bit 
	                   variables. */

	/* divide unsigned UInt64s by UInt32 */
	UInt64s F__U64sDIVU64sU32(const UInt64s *U, UInt32 v)
	{
		Int8 i = 0;
		Int8 j;
	
		/* structure to hold dividend */
		union
		{
			UInt16 d[6];
			struct
			{
				UInt32 d4;	/* (number matches index) */
				UInt64s d0d3;
			} s;
		} dividend;
	
		/* Structure to hold quotient */
		union
		{
			UInt64s Q;
			UInt16 q[4];
		} quotient;
	
		/* pointers to the structures */
		UInt16 *up = &dividend.d[1];
		UInt16 *qp = &quotient.q[0];
	
		/* first, make sure v is not a short */
		if(v <= 0xFFFF) 
			return(F__U64sDIVU64sU16(U, (UInt16)v));

		/* normalize the divisor */
        if (!(v & 0x80000000))
        {
    		for(i=0; (Int32)v > 0; i++) 
	    		v <<= 1;
        }

		/* and the dividend */
        dividend.s.d4 = 0;              /* initialization necessary if i=0 */
	    if(i) /* avoid shift by 32 bits */
		{
    		dividend.s.d4 = U->hi >> (32 - i);
    	}
		dividend.s.d0d3.hi = U->hi << i;
	    if(i) /* avoid shift by 32 bits */
		{
    		dividend.s.d0d3.hi += (U->lo >> (32 - i));
    	}
		dividend.s.d0d3.lo = U->lo << i;

		/* start the division loop */
		*qp++ = 0;
		for(j=0; j<3; j++) 
			*qp++ = div3by2(up++, *(UInt32s *)&v);
		return(quotient.Q);
	}

	#endif

#endif

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
