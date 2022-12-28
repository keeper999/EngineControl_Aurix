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
* %name:  ThMgt_afts.c %
*
* %version:  15.2.build1 %
*
* %date_modified:  Thu Nov 14 17:48:33 2013 %
*
*
* %derived_by:  u299919 %
* %release:ThMgt/14.2 %
* %full_filespec:  ThMgt_afts.c-15.2.build1:csrc:1 %
*
*******************************************************************************/

#ifndef _THMGT_AFTS_C_
#define _THMGT_AFTS_C_

#include "Rte_Type.h"
#include "PSA_afts.h"
#include "ThMgt_nvm.h"
#include "Rte_ThMgt.h"
#include "ThMgt_002_TEV_fct.h"


#define THMGT_START_SEC_CODE
#include "ThMgt_MemMap.h"

void RE_ThMgt_AftsNvramRead_1(UInt8 *ThMgt_tabNVRAM_1)
{

    UInt16 position = 0;
    UInt8 *Ptr8;

    Ptr8 = (UInt8*) &ThMgt_sNV_Z1_CST_8BIT.ThMgt_stDiagFctFSF_NV;
    ThMgt_tabNVRAM_1[position] = *Ptr8;
    position++;
    Ptr8 = (UInt8*) &ThMgt_sNV_Z1_CST_BOOLEAN.ThMgt_bRefFSFReq_NV;
    ThMgt_tabNVRAM_1[position] = *Ptr8;
    position++;

}

void RE_ThMgt_AftsNvramWrite_1(UInt8 *ThMgt_tabNVRAM_1)
{
    UInt16 position = 0;

    ThMgt_sNV_Z1_CST_8BIT.ThMgt_stDiagFctFSF_NV = ThMgt_tabNVRAM_1[position];
    position++;
    ThMgt_sNV_Z1_CST_BOOLEAN.ThMgt_bRefFSFReq_NV = ThMgt_tabNVRAM_1[position];
    position++;
	ThMgt_stDiagFctFSF_NV_init=0;
	ThMgt_bRefFSFReq_NV_init=0;

}

#define THMGT_STOP_SEC_CODE
#include "ThMgt_MemMap.h"


#endif
