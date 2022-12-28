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
* %name: PSA_TL_LibC.h %
*
* %version: 1.5 %
*
* %date_modified: Wed Dec 19 14:14:21 2012 %
*
*
* %derived_by: u261238 %
* %release: Pack_Integrateur/5.0 %
* %full_filespec: PSA_TL_LibC.h-1.5:incl:9 %
*
*******************************************************************************/

#ifndef _PSA_TL_LIBC_H_
#define _PSA_TL_LIBC_H_

#include "tl_basetypes.h"

/* macro pour assurer la compatibilite ascendante */
#define PSALib_TurnOnDelay(bCmdIn, uiDelayIn, puiTimeInOut, pbCmdOut) {*(pbCmdOut) = PSALib_bTurnOnDelay32(bCmdIn, uiDelayIn, puiTimeInOut);}
#define PSALib_TurnOffDelay(bCmdIn, uiDelayIn, puiTimeInOut, pbCmdOut) {*(pbCmdOut) = PSALib_bTurnOffDelay32(bCmdIn, uiDelayIn, puiTimeInOut);}
#define PSALib_BaryCentre(iCmd1In, iCmd2In, uiCoefIn, piCmdOut) {*(piCmdOut) = PSALib_iBaryCentre32(iCmd1In, iCmd2In, uiCoefIn);}
#define PSALib_HysPos(iCmdIn, iLimLoIn, iLimHiIn, pbCmdOut, pbFirstInOut, pbSaveInOut) {*(pbCmdOut) = PSALib_bHysPos32(iCmdIn, iLimLoIn, iLimHiIn, pbFirstInOut, pbSaveInOut);}
#define PSALib_HysNeg(iCmdIn, iLimLoIn, iLimHiIn, pbCmdOut, pbFirstInOut, pbSaveInOut) {*(pbCmdOut) = PSALib_bHysNeg32(iCmdIn, iLimLoIn, iLimHiIn, pbFirstInOut, pbSaveInOut);}
#define PSALib_Counter(bEnaIn, bRstIn, uiIncIn, puiCntOut, puiSavInOut, pbPrevRstInOut) {*(puiCntOut) = PSALib_uiCounter32(bEnaIn, bRstIn, uiIncIn, puiSavInOut, pbPrevRstInOut);}
#define PSALib_TimrRst(bStrtIn, uiInitIn, bRstIn, pbCmdOut, puiValOut, puiSaveInOut, pbPrevStrtInOut) {*(puiValOut) = PSALib_uiTimerRst32(bStrtIn, uiInitIn, bRstIn, pbCmdOut, puiSaveInOut, pbPrevStrtInOut);}
#define PSALib_FiltreT(iCmdIn, iInitIn, uiDelayIn, bRstIn, piCmdOut, pbFirstInOut, piSaveInOut) {*(piCmdOut) = PSALib_iFiltreT32(iCmdIn, iInitIn, uiDelayIn, bRstIn, pbFirstInOut, piSaveInOut);}
#define PSALib_FiltreK(iCmdIn, iInitIn, uiCoefIn, bRstIn, piCmdOut, pbFirstInOut, piSaveInOut) {*(piCmdOut) = PSALib_iFiltreK32(iCmdIn, iInitIn, uiCoefIn, bRstIn, pbFirstInOut, piSaveInOut);}
#define PSALib_RateLimiter(iCmdIn, iInitIn, iIncrIn, iDecrIn, bEnableIn, piCmdOut, piSavInOut, pbFirstInOut) {*(piCmdOut) = PSALib_iRateLimiter32(iCmdIn, iInitIn, iIncrIn, iDecrIn, bEnableIn, piSavInOut, pbFirstInOut);}

/* fonctions de librairie pour les runnables periodiques */
extern Boolean PSALib_bBasculeRS(Boolean bSetIn, Boolean bRstIn, UInt8 *puiMemInOut);
extern Boolean PSALib_bTurnOnDelay16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 *puiTimeInOut);
extern Boolean PSALib_bTurnOnDelay32(Boolean bCmdIn, UInt32 uiDelayIn, UInt32 *puiTimeInOut);
extern Boolean PSALib_bTurnOffDelay16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 *puiTimeInOut);
extern Boolean PSALib_bTurnOffDelay32(Boolean bCmdIn, UInt32 uiDelayIn, UInt32 *puiTimeInOut);
extern SInt32 PSALib_iFiltreT32(SInt32 iCmdIn, SInt32 iInitIn, UInt32 uiDelayIn, Boolean bRstIn, Boolean *pbFirstInOut, SInt32 *piSaveInOut);
extern SInt32 PSALib_iFiltreK32(SInt32 iCmdIn, SInt32 iInitIn, UInt16 uiCoefIn, Boolean bRstIn, Boolean *pbFirstInOut, SInt32 *piSaveInOut);
extern SInt32 PSALib_iRateLimiter32(SInt32 iCmdIn, SInt32 iInitIn, SInt32 iIncrIn, SInt32 iDecrIn, Boolean bEnableIn, SInt32 *piSavInOut, Boolean *pbFirstInOut);
extern UInt32 PSALib_uiTimerRst32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt16 PSALib_uiTimerRst16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt32 PSALib_uiTimerReset32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt16 PSALib_uiTimerReset16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt32 PSALib_uiCounter32(Boolean bEnaIn, Boolean bRstIn, UInt32 uiIncIn, UInt32 *puiSavInOut, Boolean *pbPrevRstInOut);
extern UInt16 PSALib_uiCounter16(Boolean bEnaIn, Boolean bRstIn, UInt16 uiIncIn, UInt16 *puiSavInOut, Boolean *pbPrevRstInOut);
extern UInt32 PSALib_uiIncCounter32(Boolean bEnaIn, Boolean bRstIn, UInt32 uiIncIn, UInt32 *puiSavInOut, UInt8 *puiPrevInInOut);
extern UInt16 PSALib_uiIncCounter16(Boolean bEnaIn, Boolean bRstIn, UInt16 uiIncIn, UInt16 *puiSavInOut, UInt8 *puiPrevInInOut);
extern Boolean PSALib_bHysPos32(SInt32 iCmdIn, SInt32 iLimLoIn, SInt32 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut);
extern Boolean PSALib_bHysNeg32(SInt32 iCmdIn, SInt32 iLimLoIn, SInt32 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut);
extern Boolean PSALib_bHysPos16(SInt16 iCmdIn, SInt16 iLimLoIn, SInt16 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut);
extern Boolean PSALib_bHysNeg16(SInt16 iCmdIn, SInt16 iLimLoIn, SInt16 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut);
extern SInt32 PSALib_iBaryCentre32(SInt32 iCmd1In, SInt32 iCmd2In, UInt16 uiCoefIn);
extern SInt16 PSALib_iBaryCentre16(SInt16 iCmd1In, SInt16 iCmd2In, UInt16 uiCoefIn);
/* PSALib_BasculeRS ajoutée pour assurer la compatibilite ascendante */
extern void PSALib_BasculeRS(Boolean bSetIn, Boolean bRstIn, Boolean *pbQOut, Boolean *pbFirstInOut, Boolean *pbPrevQInOut);

/* fonctions de librairie pour les runnables evenementiels */
extern Boolean PSALib_bTurnOnDelayASY16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 uiSampleIn, UInt16 *puiTimeInOut);
extern Boolean PSALib_bTurnOnDelayASY32(Boolean bCmdIn, UInt32 uiDelayIn, UInt16 uiSampleIn, UInt32 *puiTimeInOut);
extern Boolean PSALib_bTurnOffDelayASY16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 uiSampleIn, UInt16 *puiTimeInOut);
extern Boolean PSALib_bTurnOffDelayASY32(Boolean bCmdIn, UInt32 uiDelayIn, UInt16 uiSampleIn, UInt32 *puiTimeInOut);
extern UInt32 PSALib_uiTimerRstASY32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt16 PSALib_uiTimerRstASY16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt32 PSALib_uiTimerResetASY32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern UInt16 PSALib_uiTimerResetASY16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut);
extern SInt32 PSALib_iFiltreTASY32(SInt32 iCmdIn, SInt32 iInitIn, UInt32 uiDelayIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbFirstInOut, SInt32 *piSaveInOut);

#endif /*_PSA_TL_LIBC_H_*/
