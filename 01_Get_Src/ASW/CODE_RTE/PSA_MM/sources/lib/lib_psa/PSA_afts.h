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
* %name: PSA_afts.h %
*
* %version: 4.2 %
*
* %date_modified: Fri Aug 12 13:32:07 2011 %
*
*
* %derived_by: u152920 %
* %release: Pack_Integrateur/4.0 %
* %full_filespec: PSA_afts.h-4.2:incl:1 %
*
*******************************************************************************/

/*******************************************************************************
* Description : Declaration des fonctions pour l'APV
* Auteur      : CLO
*******************************************************************************/
#ifndef _PSA_AFTS_H_
#define _PSA_AFTS_H_

#include "tl_basetypes.h"

extern void PSA_UInt32ToTabUInt8 (UInt32 Var32, UInt8 *Tab8);
extern void PSA_UInt16ToTabUInt8 (UInt16 Var16, UInt8 *Tab8);
extern UInt32 PSA_TabUInt8ToUInt32 (UInt8 *Tab8);
extern UInt16 PSA_TabUInt8ToUInt16 (UInt8 *Tab8);
extern SInt16 PSA_TabUInt8ToSInt16 (UInt8 *Tab8);
extern SInt32 PSA_TabUInt8ToSInt32 (UInt8 *Tab8);


#endif/*_PSA_AFTS_H_ */

