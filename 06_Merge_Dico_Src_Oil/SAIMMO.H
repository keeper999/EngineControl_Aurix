/***************************************************************************
;**
;** FILE NAME      : SAIMMO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SAIMMO_H
#define SAIMMO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SAIMMO_I.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CHECK_ADC_ACK                     1
#define CHECK_ADC_IN_PROGRESS             2
#define CHECK_ADC_NOK                     4
#define CHECK_ADC_OK                      8
#define CHECK_ADC_TIMEOUT                 16
#define IMMO_ECU_DEVELOPMENT              3
#define IMMO_ECU_LIVRAISON                4
#define IMMO_ECU_LOCKED                   46021
#define IMMO_ECU_PAIRED                   2
#define IMMO_ECU_PROG_1                   5
#define IMMO_ECU_PROG_2                   6
#define IMMO_ECU_PROG_3                   7
#define IMMO_ECU_UNLOCKED                 43605
#define IMMO_ECU_VIRGIN                   1
#define MATCHING_ADC_ACK                  1
#define MATCHING_ADC_IMPOSSIBLE           2
#define MATCHING_ADC_IN_PROGRESS          4
#define MATCHING_ADC_NOK                  8
#define MATCHING_ADC_OK                   16
#define MATCHING_ADC_TIMEOUT              32
#define READ_ADC_IMPOSSIBLE               8
#define READ_ADC_IN_PROGRESS              4
#define READ_ADC_OK                       1
#define READ_ADC_TIMEOUT                  2
#define WRITE_ADC_ACK                     1
#define WRITE_ADC_IMPOSSIBLE              2
#define WRITE_ADC_IN_PROGRESS             4
#define WRITE_ADC_NOK                     8
#define WRITE_ADC_OK                      16
#define WRITE_ADC_OUT_OF_RANGE            32
#define WRITE_ADC_TIMEOUT                 64

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Immo_bEcuAwakeImmoNeed;
extern boolean Immo_bEngStopReq;
extern uint8 IMMO_stECUConf;
extern uint8 IMMO_stEcuPairOffStTyp;
extern uint8 SAIMMO_bfImmoReadStDft;
extern uint8 SAIMMO_IscanBufferPos1;
extern uint8 SAIMMO_IscanBufferPos2;
extern uint8 SAIMMO_IscanBufferPos3;
extern uint8 SAIMMO_IscanBufferPos4;
extern uint8 SAIMMO_IscanBufferPos5;
extern uint8 SAIMMO_stCANMatchOptReadSt;
extern uint8 SAIMMO_stLockECUReadSt;
extern uint8 SAIMMO_stProgImmoReadSt;
extern uint8 Srv_noADCCodChkOutpPrm;
extern uint8 Srv_noADCCodWrOutpPrm;
extern uint8 Srv_noADCMatchOutpPrm;
extern uint8 Srv_stADCCodChk;
extern uint8 Srv_stADCCodWr;
extern uint8 Srv_stADCMatch;
extern uint8 Srv_stADCRead;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Ext_getBInhCdtSpdVehImmo(boolean *Immo_bInhCdtSpdVehImmo);
void Ext_getBInhConf(boolean *Immo_bInhConf);
void Ext_getBUnlockAutho(boolean *Immo_bUnlockAutho);
void Ext_getBUnlockReq(boolean *Immo_bUnlockReq, boolean *Immo_bMainECUWakeUp);
void Ext_getImmoCodProg(uint32 *Ext_noImmoCod, uint8 *Ext_stCANMatchOpt, uint16 *Ext_stProgImmo, uint8 *Ext_stReadImmo);
void Ext_getNInputImmo(uint16 *Immo_nInput);
void Ext_getRandomUInt32(uint32 *Ext_noUInt32Random);
void Ext_getSpdVehImmo(uint8 *Immo_spdVeh);
void Ext_getStLockECU(uint8 *Ext_stLockECU);
void Ext_sendBLockECUCANImmo(boolean Immo_bLockECUCAN);
void Ext_sendNegAnswImmo(uint8 Immo_stNegAnswSrv, uint8 Immo_noNegAnswCod);
void Ext_sendNoSeedImmo(uint32 Immo_noSeed, uint8 Immo_stCANEmiTyp);
void Ext_sendPosAnswImmoReadSt(uint8 Immo_stLockECUReadSt, uint8 Immo_stProgImmoReadSt, uint8 Immo_bfImmoReadStDft, uint8 Immo_stCANMatchOptReadSt);
void Ext_sendPosAnswRCImmo(uint8 Immo_noRC, uint8 Immo_stRCSrv1, uint8 Immo_stRCSrv2);
void Ext_setBDgoImmoCodNotRead(boolean bLocalImmo_bDgoImmoCodNotRead, boolean Immo_bMonRunImmoCodNotRead);
void Ext_setBDgoNoAnswCtlUnit(boolean bLocalImmo_bDgoNoAnswCtlUnit, boolean Immo_bMonRunNoAnswCtlUnit);
void Ext_setBDgoWrgAnswCtlUnit(boolean bLocalImmo_bDgoWrgAnswCtlUnit, boolean Immo_bMonRunWrgAnswCtlUnit);
void Ext_setBECUAwakeImmoNeed(boolean bEcuAwakeImmoNeed);
void Ext_setImmoCod(uint32 Immo_noImmoCodWr, uint8 Immo_stCANMatchOptWr);
void Ext_setImmoProg(uint16 Immo_stProgImmoWr);
void Ext_setStCANOptImmoEve(uint8 Immo_stCANOptEve);
void Ext_setStLockECU(uint8 Immo_stLockECU);
void Ext_setStMatchProgImmoEve(void);
void SAIMMO_CODE__nvmini(void);
void SAIMMO_ETAT__nvmini(void);
void SAIMMO_EveRst(void);
void SAIMMO_EveRxn0A8(void);
void SAIMMO_EveRxn0E0(void);
void SAIMMO_init(void);
void SAIMMO_SdlMid(void);
void SAIMMO_vidSdlFast(void);
void Srv_EveRcChkCodProg(void);
void Srv_EveRcMatch(void);
void Srv_EveRcWrCodProg(void);
void Srv_EveRdByDidADC(void);


#endif /* SAIMMO_H */

/*-------------------------------- end of file -------------------------------*/
