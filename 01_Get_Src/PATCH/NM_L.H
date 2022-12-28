/***************************************************************************
;**
;** FILE NAME      : NM_L.H
;**
;** FILE AUTHOR    : ftremel (VEES)
;**
;**************************************************************************/

#ifndef NM_L_H
#define NM_L_H

// #include "MATHSRV_Portability.h"
#include "STD_Types.h"
#include "NM_TYP.h"
#include "STD_Types.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define NM_ABBUSERRORALARMRUNNING_COLS         ( 2 )/* NM_u8NETWORKS_NB */
#define NM_ABDIAGON_COLS                       ( 2 )/* NM_u8NETWORKS_NB */
#define NM_ABFNODEDIAGONCONFIG_COLS            ( 2 )/* 2 */
#define NM_ABFNODESSTATUS_LNS                 ( 2 )/* NM_u8NETWORKS_NB */
#define NM_ABFNODESSTATUS_COLS                 ( 2 )/* 2 */
#define NM_ABNMLIMPHOME_COLS                   ( 2 )/* NM_u8NETWORKS_NB */
#define NM_ABRECEIVEOK_COLS                    ( 2 )/* NM_u8NETWORKS_NB */
#define NM_ABTRANSMITOK_COLS                   ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKBFALLMODULESABSENT_COLS           ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKU8BUSOFFDELTADEC_COLS             ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKU8BUSOFFDELTAINC_COLS             ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKU8BUSOFFDLLRESTARTTHRNB_COLS      ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKU8NODESNUMBER_COLS                ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKUDTBUSOFFINCALARMID_COLS          ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKUDTBUSOFFINCSTATUSALARM_COLS      ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKUDTBUSRESTARTALARMID_COLS         ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKUDTBUSSLEEPALARM_COLS             ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKUDTBUSWAITSLEEPTIMEOUT_COLS       ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AKUDTNETID_COLS                     ( 2 )/* NM_u8NETWORKS_NB */
#define NM_ASTRNETWORKPARAMETERS_COLS          ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AU8ABSENTCNT_COLS                   ( 32 )/* 32 */
#define NM_AU8ABSENTCNT0_COLS                  ( 26 )/* 26 */
#define NM_AU8ABSENTCNT1_COLS                  ( 3 )/* 3 */
#define NM_AU8BUSOFFCNT_COLS                   ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AU8BUSOFFNUMBER_COLS                ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AU8BUSSLEEPMODESTATE_COLS           ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AU8BUSSTATUS_COLS                   ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AU8MESSAGENOTRECEIVENUMBER_COLS     ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AU8ONOFFSTATUS_COLS                 ( 2 )/* NM_u8NETWORKS_NB */
#define NM_AUDTNODEMONITORINGTIMEOUT0_COLS     ( 26 )/* 26 */
#define NM_AUDTNODEMONITORINGTIMEOUT1_COLS     ( 3 )/* 3 */
#define NM_KABSLEEPMODEMANAGEMENT_COLS         ( 2 )/* NM_u8NETWORKS_NB */
#define NM_MODULE_ABSENT                  1    /* 0x01 */
#define NM_MODULE_ABSENT_CONF             1    /* 0x01 */
#define NM_MODULE_MUET_CONF               1    /* 0x01 */
#define NM_MODULE_MUET_PRES               1    /* 0x01 */
#define NM_MODULE_NON_MUET                0    /* 0x00 */
#define NM_MODULE_PRESENT                 0    /* 0x00 */
#define NM_u8NETWORKS_NB                  2    /* 2 */

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

// void I_MessageTimeOut(SymbolicName udtMessageId);
// void NM_vidDecConfigCount(uint8_least u8NetworkIndex,uint8 u8Index);
// void NM_vidDecStatusCount(uint8_least u8NetworkIndex);
// void NM_vidDiagInit(uint8_least  u8NetworkIndex);
// void NM_vidIncConfigCount(uint8_least u8NetworkIndex,uint8 Index);
// void NM_vidIncStatusCount(uint8_least u8NetworkIndex);
// void NM_vidInitNetworkStatus(uint8_least  u8NetworkIndex);
// boolean NM_vidExtractNWIndex(NetIdType NetId, uint8_least *pu8NWIndex);
// boolean NM_vidExtractSource(uint8_least u8NetworkIndex, SymbolicName udtMessageId, uint8 *pu8Index);


#endif /* NM_L_H */

/*-------------------------------- end of file -------------------------------*/
