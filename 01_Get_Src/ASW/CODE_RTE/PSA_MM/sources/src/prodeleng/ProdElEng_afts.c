/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name:  ProdElEng_afts.c %
*
* %version:  4.2 %
*
* %date_modified:  Thu Aug  4 11:07:24 2011 %
*
*
* %derived_by:  u349799 %
* %release:ProdElEng/4.0 %
* %full_filespec:  ProdElEng_afts.c-4.2:csrc:1 %
*
*******************************************************************************/

#ifndef _PRODELENG_AFTS_C_
#define _PRODELENG_AFTS_C_

#include "Rte_Type.h"
#include "PSA_afts.h"
#include "ProdElEng_nvm.h"
#include "Rte_ProdElEng.h"

#define PRODELENG_START_SEC_CODE
#include "ProdElEng_MemMap.h"

void RE_ProdElEng_AftsNvramRead_1(UInt8 *ProdElEng_tabNvram_1)
{

    UInt16 position = 0;
    UInt32 *Ptr32;
    UInt16 *Ptr16;
    UInt8 *Ptr8;

    Ptr32 = &ProdElEng_sNV_Z1_CST_32BIT_1.TqLimUH_dstTraAcvDrv_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &ProdElEng_tabNvram_1[position]);
    position+= 4;

}

void RE_ProdElEng_AftsNvramWrite_1(UInt8 *ProdElEng_tabNvram_1)
{
    UInt16 position = 0;

    ProdElEng_sNV_Z1_CST_32BIT_1.TqLimUH_dstTraAcvDrv_NV = PSA_TabUInt8ToUInt32(&ProdElEng_tabNvram_1[position]);
    position+= 4;
    TqLimUH_dstTraAcvDrv_NV_init = 0;
}

#define PRODELENG_STOP_SEC_CODE
#include "ProdElEng_MemMap.h"


#endif
