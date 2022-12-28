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
* %name: tl_defines.h %
*
* %version: 4.2 %
*
* %date_modified: Fri Aug 12 14:11:39 2011 %
*
*
* %derived_by: u152920 %
* %release: Pack_Integrateur/4.0 %
* %full_filespec: tl_defines.h-4.2:incl:55 %
*
*******************************************************************************/


#ifndef _TL_DEFINES_H_
#define _TL_DEFINES_H_

/******************************************************************************\
   TL_CG_MACROCL_GLOBAL: Default macro class for macros with module extent
\******************************************************************************/
#ifndef TL_FX_GROUND
#define TL_FX_GROUND 0
#endif /* TL_FX_GROUND */


/******************************************************************************\
   TL_CG_MACROCL_GLOBAL: Default macro class for macros with module extent
\******************************************************************************/
#define AR_IF_GLOBAL_16BIT
#define AR_IF_GLOBAL_32BIT
#define AR_IF_GLOBAL_8BIT
#define AR_IF_GLOBAL_BOOLEAN
#define AR_INTERNAL_VAR_DISP_32BIT
#define AR_INTERNAL_VAR_DISP_16BIT
#define AR_INTERNAL_VAR_DISP_8BIT
#define AR_INTERNAL_VAR_DISP_BOOLEAN
#define AR_MERGEABLE_CALIB_16BIT const volatile
#define AR_MERGEABLE_CALIB_32BIT const volatile
#define AR_MERGEABLE_CALIB_8BIT const volatile
#define AR_MERGEABLE_CALIB_BOOLEAN const volatile
#define AR_MERGEABLE_CARTO_32BIT const volatile
#define AR_MERGEABLE_CARTO_16BIT const volatile
#define AR_MERGEABLE_CARTO_8BIT const volatile
#define AR_MERGEABLE_CARTO_CONST_8BIT static const
#define AR_MERGEABLE_CARTO_CONST_16BIT static const
#define AR_MERGEABLE_CARTO_CONST_32BIT static const
#define AR_SEC_CONST_8BIT const
#define AR_SEC_CONST_BOOLEAN const
#define AR_SEC_CONST_16BIT const
#define AR_SEC_CONST_32BIT const
#define AR_SEC_CONST_UNSPECIFIED_STATIC static const
#define AR_SEC_VAR_BOOLEAN static
#define AR_SEC_VAR_8BIT static
#define AR_SEC_VAR_32BIT static
#define AR_SEC_VAR_16BIT static
#define AR_MERGEABLE_EXT_CALIB_BOOLEAN extern const volatile
#define AR_MERGEABLE_EXT_CALIB_8BIT extern const volatile
#define AR_MERGEABLE_EXT_CALIB_32BIT extern const volatile
#define AR_MERGEABLE_EXT_CALIB_16BIT extern const volatile
#define AR_SEC_NVM_INIT_BOOLEAN
#define AR_SEC_CONST_VERSION_MODULE_8BIT const

/* MACRO EURO5*/
#define AR_EXT_VAR_SAVED_ZONE2_8BIT extern
#define AR_EXT_VAR_SAVED_ZONE2_BOOLEAN extern
#define AR_EXT_VAR_SAVED_ZONE2_16BIT extern
#define AR_EXT_VAR_SAVED_ZONE2_32BIT extern

#define AR_EXT_VAR_SAVED_ZONE1_8BIT extern
#define AR_EXT_VAR_SAVED_ZONE1_BOOLEAN extern
#define AR_EXT_VAR_SAVED_ZONE1_16BIT extern
#define AR_EXT_VAR_SAVED_ZONE1_32BIT extern

/*MACRO EURO6*/

#define AR_EXT_VAR_SAVED_Z1CST_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z2CST_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z3CST_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z4CST_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z5CST_BOOLEAN extern
#define AR_EXT_VAR_SAVED_ZCSTCST_BOOLEAN extern

#define AR_EXT_VAR_SAVED_Z1CST_8BIT extern
#define AR_EXT_VAR_SAVED_Z2CST_8BIT extern
#define AR_EXT_VAR_SAVED_Z3CST_8BIT extern
#define AR_EXT_VAR_SAVED_Z4CST_8BIT extern
#define AR_EXT_VAR_SAVED_Z5CST_8BIT extern
#define AR_EXT_VAR_SAVED_ZCSTCST_8BIT extern

#define AR_EXT_VAR_SAVED_Z1CST_16BIT extern
#define AR_EXT_VAR_SAVED_Z2CST_16BIT extern
#define AR_EXT_VAR_SAVED_Z3CST_16BIT extern
#define AR_EXT_VAR_SAVED_Z4CST_16BIT extern
#define AR_EXT_VAR_SAVED_Z5CST_16BIT extern
#define AR_EXT_VAR_SAVED_ZCSTCST_16BIT extern

#define AR_EXT_VAR_SAVED_Z1CST_32BIT extern
#define AR_EXT_VAR_SAVED_Z2CST_32BIT extern
#define AR_EXT_VAR_SAVED_Z3CST_32BIT extern
#define AR_EXT_VAR_SAVED_Z4CST_32BIT extern
#define AR_EXT_VAR_SAVED_Z5CST_32BIT extern
#define AR_EXT_VAR_SAVED_ZCSTCST_32BIT extern

#define AR_EXT_VAR_SAVED_Z1CAL_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z2CAL_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z3CAL_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z4CAL_BOOLEAN extern
#define AR_EXT_VAR_SAVED_Z5CAL_BOOLEAN extern
#define AR_EXT_VAR_SAVED_ZCSTCAL_BOOLEAN extern

#define AR_EXT_VAR_SAVED_Z1CAL_8BIT extern
#define AR_EXT_VAR_SAVED_Z2CAL_8BIT extern
#define AR_EXT_VAR_SAVED_Z3CAL_8BIT extern
#define AR_EXT_VAR_SAVED_Z4CAL_8BIT extern
#define AR_EXT_VAR_SAVED_Z5CAL_8BIT extern
#define AR_EXT_VAR_SAVED_ZCSTCAL_8BIT extern

#define AR_EXT_VAR_SAVED_Z1CAL_16BIT extern
#define AR_EXT_VAR_SAVED_Z2CAL_16BIT extern
#define AR_EXT_VAR_SAVED_Z3CAL_16BIT extern
#define AR_EXT_VAR_SAVED_Z4CAL_16BIT extern
#define AR_EXT_VAR_SAVED_Z5CAL_16BIT extern
#define AR_EXT_VAR_SAVED_ZCSTCAL_16BIT extern

#define AR_EXT_VAR_SAVED_Z1CAL_32BIT extern
#define AR_EXT_VAR_SAVED_Z2CAL_32BIT extern
#define AR_EXT_VAR_SAVED_Z3CAL_32BIT extern
#define AR_EXT_VAR_SAVED_Z4CAL_32BIT extern
#define AR_EXT_VAR_SAVED_Z5CAL_32BIT extern
#define AR_EXT_VAR_SAVED_ZCSTCAL_32BIT extern

#endif/*_TL_DEFINES_H_ */
