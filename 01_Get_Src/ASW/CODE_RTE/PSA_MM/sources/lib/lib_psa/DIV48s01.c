/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE
* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE
********************************************************************************
* Fichier     : div48s01.c
* Version     : 1.1
* ID_synergy  : 
* Description : 
* Auteur      : CLO
* Creation    : 03-07-2008
*******************************************************************************/
/**
 * @file       div48s01.c
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
 * $Workfile: DIV48s01.c $
 * $Revision: 1.1 $
 * $Date: 2004/04/28 11:44:54GMT+01:00 $
 */


#include "dsfxp.h"


#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */

	#if ALIGN==2		/* The code must be compiled with an alignment
	                       of 2 or the 32-bit pointer arithmetic
	                       will not work properly. */
	
	/* divide three digits by two (used by multiword division) */
	UInt16 div3by2(UInt16 u[3], UInt32s v)
	{
		UInt32 q;
		UInt16 temp;
		UInt32s low;
		UInt32 *p1 = (UInt32 *)&u[1];
		UInt32 *p0 = (UInt32 *)&u[0];
	
		/* get initial guess of q using high digit of v */
		q = *p1 / v.pr[1];
		q = (q < 0xFFFF) ? q : 0xFFFF;  /* min(q, 0xFFFF) */
	
		/* compute first remainder */
		*p1 -= q * v.pr[1];
	
		/* then second remainder */
		low.lng = q * v.pr[0];
		temp = u[0];
		u[0] -= low.pr[0];
		if(u[0] > temp) 
			--(*p1);
		*p1 -= low.pr[1];
	
		/* refine as needed */
		while((Int32)*p1 < 0)
		{
			--q;
			*p0 += v.lng;
			if(*p0 < v.lng) 
				++u[2];
		}
		return((UInt16)q);
	}
	
	#else		 	/* If the code is not compiled with an alignment
	                   of 2 the 32-bit pointers to the nominator
	                   array must be replaced with 32-bit 
	                   variables. */

	/* divide three digits by two (used by multiword division) */
	UInt16 div3by2(UInt16 u[3], UInt32s v)
	{
		UInt32 q;
		UInt16 temp;
		UInt32s low;
		UInt16 *p1 = (UInt16 *)&u[1];
		UInt16 *p0 = (UInt16 *)&u[0];
		UInt16 *p2 = (UInt16 *)&u[2];
		UInt32 tp1 = (UInt32)*p1 + ((UInt32)*p2 << 16);
		UInt32 tp0 = (UInt32)*p0 + ((UInt32)*p1 << 16);

		/* get initial guess of q using high digit of v */
		q = tp1 / v.pr[1];
		q = (q < 0xFFFF) ? q : 0xFFFF;  /* min(q, 0xFFFF) */
	
		/* compute first remainder */
		tp1 -= q * v.pr[1];
	
		/* then second remainder */
		low.lng = q * v.pr[0];
		temp = u[0];
		u[0] -= low.pr[0];
		if(u[0] > temp) 
			--tp1;
		tp1 -= low.pr[1];

	    *p2 = (UInt16)(tp1 >> 16);
	    *p1 = (UInt16)tp1;    
	    tp0 = (UInt32)*p0 + ((UInt32)*p1 << 16);

		/* refine as needed */
		while((Int32)tp1 < 0)
		{
			--q;
			tp0 = (UInt32)*p0 + ((UInt32)*p1 << 16);
			tp0 += v.lng;
			*p1 = (UInt16)(tp0 >> 16);
			*p0 = (UInt16)tp0;
			if(tp0 < v.lng) 
				++u[2];
			tp1 = (UInt32)*p1 + ((UInt32)*p2 << 16);
		}
		*p1 = (UInt16)tp1;
		*p0 = (UInt16)tp0;
		
		return((UInt16)q);
	}

	#endif
		
#else					/* Target with big-endian architecture */

	#if ALIGN==2		/* The code must be compiled with an alignment
	                       of 2 or the 32-bit pointer arithmetic
	                       will not work properly. */
	
	/* divide three digits by two (used by multiword division) */
	UInt16 div3by2(UInt16 u[3], UInt32s v)
	{
		UInt32 q;
		UInt16 temp;
		UInt32s low;
		UInt32 *p1 = (UInt32 *)&u[0];
		UInt32 *p0 = (UInt32 *)&u[1];

		/* get initial guess of q using high digit of v */
		q = *p1 / v.pr[0];
		q = (q < 0xFFFF) ? q : 0xFFFF;  /* min(q, 0xFFFF) */
	
		/* compute first remainder */
		*p1 -= q * v.pr[0];
	
		/* then second remainder */
		low.lng = q * v.pr[1];
		temp = u[2];
		u[2] -= low.pr[1];
		if(u[2] > temp) 
			--(*p1);
		*p1 -= low.pr[0];
	
		/* refine as needed */
		while((Int32)*p1 < 0)
		{
			--q;
			*p0 += v.lng;
			if(*p0 < v.lng) 
				++u[0];
		}
		return((UInt16)q);
	}

	#else		 	/* If the code is not compiled with an alignment
	                   of 2 the 32-bit pointers to the nominator
	                   array must be replaced with 32-bit 
	                   variables. */

	/* divide three digits by two (used by multiword division) */
	UInt16 div3by2(UInt16 u[3], UInt32s v)
	{
		UInt32 q;
		UInt16 temp;
		UInt32s low;
		UInt16 *p1 = (UInt16 *)&u[0];
		UInt16 *p0 = (UInt16 *)&u[1];
		UInt16 *p2 = (UInt16 *)&u[2];
		UInt32 tp1 = (UInt32)*p0 + ((UInt32)*p1 << 16);
		UInt32 tp0 = (UInt32)*p2 + ((UInt32)*p0 << 16);
	
		/* get initial guess of q using high digit of v */
		q = tp1 / v.pr[0];
		q = (q < 0xFFFF) ? q : 0xFFFF;  /* min(q, 0xFFFF) */
	
		/* compute first remainder */
		tp1 -= q * v.pr[0];
	
		/* then second remainder */
		low.lng = q * v.pr[1];         
		temp = u[2];
		u[2] -= low.pr[1];
		if(u[2] > temp) 
			--tp1;
		tp1 -= low.pr[0];
		
        *p1 = (UInt16)(tp1 >> 16);
		*p0 = (UInt16)tp1;
		tp0 = (UInt32)*p2 + ((UInt32)*p0 << 16);

		/* refine as needed */
		while((Int32)tp1 < 0)
		{
			--q;
		   	tp0 = (UInt32)*p2 + ((UInt32)*p0 << 16);
			tp0 += v.lng;
			*p0 = (UInt16)(tp0 >> 16);
			*p2 = (UInt16)tp0;
			if(tp0 < v.lng) 
				++u[0];
			tp1 = (UInt32)*p0 + ((UInt32)*p1 << 16);	
		}
		*p0 = (UInt16)tp1;
		*p2 = (UInt16)tp0;
	
		return((UInt16)q);
	}
	
	#endif

#endif

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
