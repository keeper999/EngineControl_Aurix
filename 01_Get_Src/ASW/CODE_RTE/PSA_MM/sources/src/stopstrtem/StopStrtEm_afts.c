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
* %name:  StopStrtEm_afts.c %
*
* %version:  4.5 %
*
* %date_modified:  Thu Dec 22 14:09:18 2011 %
*
*
* %derived_by:  e375697 %
* %release:StopStrtEm/4.0 %
* %full_filespec:  StopStrtEm_afts.c-4.5:csrc:1 %
*
*******************************************************************************/

#ifndef _STOPSTRTEM_AFTS_C_
#define _STOPSTRTEM_AFTS_C_

#include "Rte_Type.h"
#include "PSA_afts.h"
#include "StopStrtEm_nvm.h"
#include "Rte_StopStrtEm.h"
#include "StopStrtEm_004_TEV_fct.h"

#define STOPSTRTEM_START_SEC_CODE
#include "StopStrtEm_MemMap.h"

void RE_StopStrtEm_AftsNvramRead_1(UInt8 *StopStrtEm_tabNvram_1)
{

    UInt16 position = 0;
    UInt32 *Ptr32;

    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaAcv_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;
    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaRstrtAcv_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;
    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaStrtAcv_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;
    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_dstStaSubMes_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;
    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaSubTi_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;
    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_2.StaStrtMgt_ctLastConnTi_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;
    Ptr32 = &StopStrtEm_sNV_Z1_CST_32BIT_2.StaStrtMgt_ctTotTi_NV;
    PSA_UInt32ToTabUInt8(*Ptr32, &StopStrtEm_tabNvram_1[position]);
    position+= 4;

}

void RE_StopStrtEm_AftsNvramWrite_1(UInt8 *StopStrtEm_tabNvram_1)
{
    UInt16 position = 0;

    StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaAcv_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;
    StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaRstrtAcv_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;
    StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaStrtAcv_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;
    StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_dstStaSubMes_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;
    StopStrtEm_sNV_Z1_CST_32BIT_1.StaStrtMgt_ctStaSubTi_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;
    StopStrtEm_sNV_Z1_CST_32BIT_2.StaStrtMgt_ctLastConnTi_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;
    StopStrtEm_sNV_Z1_CST_32BIT_2.StaStrtMgt_ctTotTi_NV = PSA_TabUInt8ToUInt32(&StopStrtEm_tabNvram_1[position]);
    position+= 4;

    /* Variables réinitialisées pour empècher le récrassement des valeurs mise en NVM */
	StaStrtMgt_ctLastConnTi_NV_reset = 0;
	StaStrtMgt_ctTotTi_NV_reset = 0;

}

void RE_StopStrtEm_AftsNvramReset_1()
{
    StopStrtEm_sNV_Z1_CST_32BIT_1 = StopStrtEm_sNV_Z1_CST_32BIT_1_r;

	/* Variables réinitialisées pour empècher le récrassement des valeurs mise en NVM */
	StaStrtMgt_ctLastConnTi_NV_reset = 0;
	StaStrtMgt_ctTotTi_NV_reset = 0;
}

#define STOPSTRTEM_STOP_SEC_CODE
#include "StopStrtEm_MemMap.h"


#endif
