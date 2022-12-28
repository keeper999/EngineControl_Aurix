/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "CoOptmEl_custom.h"

#define PRODELEM_START_SEC_CODE
#include "ProdElEm_MemMap.h"

void bfAnd(bfConst bfC1, bfConst bfC2, bfConst bfCOut)
{
	UInt8 i;

	for (i = 0; i < 9; i++)
        bfCOut[i] = bfC1[i] & bfC2[i];
}

void bfOr(bfConst bfC1, bfConst bfC2, bfConst bfCOut)
{
	UInt8 i;

	for (i = 0; i < 9; i++)
        bfCOut[i] = bfC1[i] | bfC2[i];
}

void bfXor(bfConst bfC1, bfConst bfC2, bfConst bfCOut)
{
	UInt8 i;

	for (i = 0; i < 9; i++)
        bfCOut[i] = bfC1[i] ^ bfC2[i];
}

UInt8 bfIsZero(bfConst bfC)
{
    UInt8 i = 0;

	while (i < 9)
	{
        if (bfC[i] != 0)
            return 0;

        i++;
	}

    return 1;
}

UInt8 idContains(idVect idV, UInt8 id)
{
    UInt8 i = 0;

    while (i < 65 && idV[i] != CMAXUINT8)
    {
        if (idV[i] == id)
            return 1;

        i++;
    }

    return 0;
}

Boolean isDynConstId(UInt8 id)
{
    return (id == 25
            || id == 26
            || id == 40
            || id == 41
            || id == 42 // Traité comme dynamique en raison de l'exigence xxxxx_10_xxxxx-CoOptmEl-F015(1).
            || id == 43
            || id == 44
            || id == 51
            || id == 52
            || id == 53
            || id == 64);
}

void maxSta8(idVectSta idV, UInt8 *V, UInt8 *max, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 54 && idV[i] != CMAXUINT8)
    {
        if (V[idV[i]] > *max)
        {
            *max = V[idV[i]];
            *idConst = idV[i];
        }

        i++;
    }
}

void minSta8(idVectSta idV, UInt8* V, UInt8 *min, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 54 && idV[i] != CMAXUINT8)
    {
        if (V[idV[i]] < *min)
        {
            *min = V[idV[i]];
            *idConst = idV[i];
        }

        i++;
    }
}

void maxSta16(idVectSta idV, UInt16 *V, UInt16 *max, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 54 && idV[i] != CMAXUINT8)
    {
        if (V[idV[i]] > *max)
        {
            *max = V[idV[i]];
            *idConst = idV[i];
        }

        i++;
    }
}

void minSta16(idVectSta idV, UInt16* V, UInt16 *min, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 54 && idV[i] != CMAXUINT8)
    {
        if (V[idV[i]] < *min)
        {
            *min = V[idV[i]];
            *idConst = idV[i];
        }

        i++;
    }
}

void minDyn8(idVectDyn idV, UInt8* V, UInt8 *min, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 11 && idV[i] != CMAXUINT8)
    {
        if (V[i] < *min)
        {
            *min = V[i];
            *idConst = idV[i];
        }

        i++;
    }
}

void maxDyn16(idVectDyn idV, UInt16 *V, UInt16 *max, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 11 && idV[i] != CMAXUINT8)
    {
        if (V[i] > *max)
        {
            *max = V[i];
            *idConst = idV[i];
        }

        i++;
    }
}

void minDyn16(idVectDyn idV, UInt16* V, UInt16 *min, UInt8 *idConst)
{
    UInt8 i = 0;

    while (i < 11 && idV[i] != CMAXUINT8)
    {
        if (V[i] < *min)
        {
            *min = V[i];
            *idConst = idV[i];
        }

        i++;
    }
}

void maxStaPrio(idVectSta idV, UInt16 *V, UInt8* Vprio, UInt8 prio, UInt16 *max)
{
    UInt8 i = 0;

    while (i < 54 && idV[i] != CMAXUINT8)
    {
        if (Vprio[idV[i]] < prio && V[idV[i]] > *max)
            *max = V[idV[i]];

        i++;
    }
}

void minStaPrio(idVectSta idV, UInt16* V, UInt8* Vprio, UInt8 prio, UInt16 *min)
{
    UInt8 i = 0;

    while (i < 54 && idV[i] != CMAXUINT8)
    {
        if (Vprio[idV[i]] < prio && V[idV[i]] < *min)
            *min = V[idV[i]];

        i++;
    }
}

void maxDynPrio(idVectDyn idV, UInt16 *V, UInt8* Vprio, UInt8 prio64, UInt8 prio, UInt16 *max)
{
    UInt8 i = 0;

    while (i < 11 && idV[i] != CMAXUINT8)
    {
        if ((idV[i] != 64 && Vprio[idV[i]] < prio)
            || (idV[i] == 64 && prio64 < prio))
            {
                if (V[i] > *max)
                    *max = V[i];
            }

        i++;
    }
}

void minDynPrio(idVectDyn idV, UInt16* V, UInt8* Vprio, UInt8 prio64, UInt8 prio, UInt16 *min)
{
    UInt8 i = 0;

    while (i < 11 && idV[i] != CMAXUINT8)
    {
        if ((idV[i] != 64 && Vprio[idV[i]] < prio)
            || (idV[i] == 64 && prio64 < prio))
            {
                if (V[i] < *min)
                    *min = V[i];
            }

        i++;
    }
}

UInt8 sat8(UInt8 val, UInt8 inf, UInt8 sup)
{
    if (val < inf)
        return inf;
    else if (val > sup)
        return sup;
    else
        return val;
}

UInt16 sat16(UInt16 val, UInt16 inf, UInt16 sup)
{
    if (val < inf)
        return inf;
    else if (val > sup)
        return sup;
    else
        return val;
}

#define PRODELEM_STOP_SEC_CODE
#include "ProdElEm_MemMap.h"
