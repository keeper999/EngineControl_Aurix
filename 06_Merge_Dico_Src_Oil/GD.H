/***************************************************************************
;**
;** FILE NAME      : GD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GD_H
#define GD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GD_ASTRCLASDET_LNS                    ( 32 )
#define GD_ASTRCLASDID_LNS                    ( 60 )
#define GD_ASTRCLASFRF_LNS                    ( 60 )
#define GD_ASTRCLASOBD_LNS                    ( 20 )
#define GD_AU8IDXCLASFRF_LNS                  ( 972 )
#define GD_AU8IDXCLASOBD_LNS                  ( 972 )
#define GD_AU8IDXCLASSDET_LNS                 ( 972 )
#define GD_CLAS_DET                       32
#define GD_CLAS_DID                       60
#define GD_CLAS_FRF                       60
#define GD_CLAS_OBD                       20
#define GD_u16MAX_CTDIAG                  65534
#define GD_u16MAX_DEC_VALUE               32768
#define GD_u16MAX_INC_VALUE               32768
#define GD_u16MAX_NOTHD_VALUE             32768

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const  GD_strClasDet  GD_astrClasDet[GD_ASTRCLASDET_LNS];
extern const  GD_strClasDID  GD_astrClasDID[GD_ASTRCLASDID_LNS];
extern const  GD_strClasObd  GD_astrClasObd[GD_ASTRCLASOBD_LNS];
extern const  GD_tstrClasFrf  GD_astrClasFrf[GD_ASTRCLASFRF_LNS];
extern const uint8  GD_au8IdxClasFrf[GD_AU8IDXCLASFRF_LNS];
extern const uint8  GD_au8IdxClasObd[GD_AU8IDXCLASOBD_LNS];
extern const uint8  GD_au8IdxClassDet[GD_AU8IDXCLASSDET_LNS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GD_bMemRstDftCal;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveCrTR(void);
void GD_EveCrTSt(void);
void GD_EveKOf(void);
void GD_EveKOn(void);
void GD_EveRst(void);
void GD_EveRstDft(void);
void GD_EveRstDftObd(void);
void GD_EveRxn55F(void);
void GD_EveRxn772(void);
void GD_SdlFast(void);
void GD_SdlSlow(void);
void GDEXTINT_EveRstDft(void);
void GDEXTINT_EveRstDftObd(void);


#endif /* GD_H */

/*-------------------------------- end of file -------------------------------*/
