/***************************************************************************
;**
;** FILE NAME      : FCTDIAGTRBPRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FCTDIAGTRBPRES_L_H
#define FCTDIAGTRBPRES_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  FCTDIAGTRBPRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirPres_bAcvNegDifFctVlvPosn;
extern boolean AirPres_bDgoMaxAbs_pUsThr;
extern boolean AirPres_bDgoNegDif_pUsThrSen;
extern boolean AirPres_bDgoNegDif1_pUsThr;
extern boolean AirPres_bDgoNegDif2_pUsThr;
extern boolean AirPres_bDgoPlaus_pUsThrBoost;
extern boolean AirPres_bDgoPlaus_pUsThrIdl;
extern boolean AirPres_bDgoPosDif_pUsThrSen;
extern boolean AirPres_bDgoPosDif1_pUsThr;
extern boolean AirPres_bDgoPosDif2_pUsThr;
extern boolean AirPres_bMonRunMaxAbs_pUsThr;
extern boolean AirPres_bMonRunNegDif_pUsThrSen;
extern boolean AirPres_bMonRunNegDif1_pUsThr;
extern boolean AirPres_bMonRunNegDif2_pUsThr;
extern boolean AirPres_bMonRunPlaus_pUsThrBoost;
extern boolean AirPres_bMonRunPlaus_pUsThrIdl;
extern boolean AirPres_bMonRunPosDif_pUsThrSen;
extern boolean AirPres_bMonRunPosDif1_pUsThr;
extern boolean AirPres_bMonRunPosDif2_pUsThr;
extern boolean FCtDIAGTRBPRES_bAcvIdlCtlPrev;
extern boolean FCTDIAGTRBPRES_bBoostPresPrev;
extern boolean FCTDIAGTRBPRES_bOutTimer1;
extern boolean FCTDIAGTRBPRES_bOutTimer2;
extern boolean FCTDIAGTRBPRES_bOutTimer3;
extern boolean FCTDIAGTRBPRES_btiDifpUsThr;
extern boolean FCTDIAGTRBPRES_btiDifpUsThrPrev;
extern uint8 AirPres_ctTiBoostPresClCtlAcv;
extern uint8 AirPres_ctTiUsThrPlaus;
extern uint8 AirPres_tiDifpUsThr;
extern uint8 FCTDIAGTRBPRES_u8tiDifpUsThr;
extern uint16 AirPres_agAbsDeltaVlvExToMin;
extern uint16 AirPres_agAbsDeltaVlvInToMax;
extern uint16 AirPres_pAirExtMes1;
extern uint16 AirPres_pAirExtMes2;
extern uint16 AirPres_pUsThrMaxDiag;
extern uint16 AirPres_pUsThrNegDif;
extern uint16 AirPres_pUsThrNegDifSen;
extern uint16 AirPres_pUsThrPlaus1;
extern uint16 AirPres_pUsThrPlaus2;
extern uint16 AirPres_pUsThrPosDif;
extern uint16 AirPres_pUsThrPosDifSen;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FCTDIAGTRBPRES_vidCdEnaHiTrbPre(void);
void FCTDIAGTRBPRES_vidCdnCohTrbPrId(void);
void FCTDIAGTRBPRES_vidCdnEnaLoTrbPre(void);
void FCTDIAGTRBPRES_vidCdnNegTrbPres(void);
void FCTDIAGTRBPRES_vidCdnPosTrbPres(void);
void FCTDIAGTRBPRES_vidCohTrbPresBst(void);
void FCTDIAGTRBPRES_vidCohTrbPresIdl(void);
void FCTDIAGTRBPRES_vidDgCntTrbSenAcv(void);
void FCTDIAGTRBPRES_vidDiagCntTrbPres(void);
void FCTDIAGTRBPRES_vidDiagTrbPres(void);
void FCTDIAGTRBPRES_vidDiagTrbPrsinit(void);
void FCTDIAGTRBPRES_vidEnaCohTrbPsBst(void);
void FCTDIAGTRBPRES_vidHiTrbPres(void);
void FCTDIAGTRBPRES_vidInitOutput(void);
void FCTDIAGTRBPRES_vidLoTrbPres(void);
void FCTDIAGTRBPRES_vidNegTrbPres(void);
void FCTDIAGTRBPRES_vidPosTrbPres(void);


#endif /* FCTDIAGTRBPRES_L_H */

/*-------------------------------- end of file -------------------------------*/
