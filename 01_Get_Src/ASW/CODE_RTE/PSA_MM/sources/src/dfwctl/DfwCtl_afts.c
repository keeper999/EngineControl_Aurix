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
* %name:  DfwCtl_afts.c %
*
* %version:  1.3.build4 %
*
* %date_modified:  Thu Nov 17 11:53:06 2011 %
*
*
* %derived_by:  e360487 %
* %release:DfwCtl/1.0 %
* %full_filespec:  DfwCtl_afts.c-1.3.build4:csrc:1 %
*
*******************************************************************************/

#ifndef _DFWCTL_AFTS_C_
#define _DFWCTL_AFTS_C_

#include "Rte_Type.h"
#include "PSA_afts.h"
#include "DfwCtl_nvm.h"
#include "Rte_DfwCtl.h"

#define DFWCTL_START_SEC_CODE
#include "DfwCtl_MemMap.h"

void DfwCtl_AftsNvramRead_1(UInt8 *DfwCtl_tabNVRAM_1)
{

    UInt16 i;
    UInt16 position = 0;
    UInt32 *Ptr32;
    UInt16 *Ptr16;
    UInt8 *Ptr8;

    for (i=0;i<2;i++)
    {
         Ptr16 = (UInt16*) &DfwCtl_sNV_Z1_CST_16BIT.DfwCtl_prm_noOscDetProtAcv_NV[i];
         PSA_UInt16ToTabUInt8(*Ptr16, &DfwCtl_tabNVRAM_1[position]);
         position+= 2;
    }

}

void DfwCtl_AftsNvramReset_1()
{
  DfwCtl_sNV_Z1_CST_16BIT = DfwCtl_sNV_Z1_CST_16BIT_r;
}

#define DFWCTL_STOP_SEC_CODE
#include "DfwCtl_MemMap.h"


#endif
