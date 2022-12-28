/***************************************************************************
;**
;** FILE NAME      : IUPRRATIO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "gd_api.h"
#include "IUPRRATIO.H"
#include "IUPRRATIO_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const uint8  Iupr_DenChoiceRat_C[IUPR_DENCHOICERAT_C_LNS] = {0};
const uint8  IUPR_idxGrpRat_C[IUPR_IDXGRPRAT_C_LNS] = {0};
const uint8  IUPRRATIO_u8Inhib = 0;
const uint16  IUPR_idxDftRat_C[IUPR_IDXDFTRAT_C_LNS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IUPRRATIO_abDcPrev[IUPRRATIO_ABDCPREV_LNS];
boolean IUPRRATIO_bFirstUse;
boolean IUPRRATIO_bRstPrm_prev;
boolean IUPRRATIO_DenChoicePrev[IUPRRATIO_DENCHOICEPREV_LNS];
uint16 IUPR_ctDenGrpRat[IUPR_CTDENGRPRAT_LNS];
uint16 IUPR_ctNumGrpRat[IUPR_CTNUMGRPRAT_LNS];
uint16 IUPR_noRatio[IUPR_NORATIO_LNS];
uint16 u16MinRatioIdx;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

