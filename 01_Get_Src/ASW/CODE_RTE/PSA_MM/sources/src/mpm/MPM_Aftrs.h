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
* %name: MPM_Aftrs.h %
*
* %version: 2.0_OBS %
*
* %date_modified: Fri Aug 10 10:45:33 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC3 %
* %full_filespec: MPM_Aftrs.h-2.0_OBS:incl:3 %
*
*******************************************************************************/


#ifndef MPMAFTRS_H
#define MPMAFTRS_H

#include "Rte_MPM.h"
#include "MPM.h"
#include "psa_lib_apv.h"
#include "Rte_Type.h"
#include "PSA_afts.h"
#include "MPM_nvm.h"
#include "SC.h"

#define MPM_NVMID01 1    
#define MPM_NVMID02 2    
#define MPM_NVMID03 3    
#define MPM_NVMID04 4    
#define MPM_NVMID05 5    
#define MPM_NVMID06 6    
#define MPM_NVMID07 7    
#define MPM_NVMID08 8    

#define MPM_NVMID_START 1
#define MPM_NVMID_END 8
#define MPM_NVMID_RESERVED    0
#define NULL 0
#define LITTLEENDIAN 1
#define MPM_RAMID_START 10000
#define MPM_RAMID_END 0

#define MPM_EOBDRAMID_START 10000
#define MPM_EOBDRAMID_END 0

extern FUNC(void,AUTOMATIC)MPM_Nvm_To_Cpy(void);extern FUNC(void,AUTOMATIC)
MPM_Cpy_To_Nvm_And_Reinit(UInt8 MPM_Nvmid);extern FUNC(void,AUTOMATIC)
MPM_Recovery_To_Nvm_And_Reinit(UInt8 MPM_Nvmid);extern FUNC(Std_ReturnType,
AUTOMATIC)MPM_Aftrs_Init(void);
#endif

