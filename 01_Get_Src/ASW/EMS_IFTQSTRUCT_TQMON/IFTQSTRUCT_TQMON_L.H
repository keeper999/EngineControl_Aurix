/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : IFTQSTRUCT_TQMON                                         */
/*                                                                            */
/* !Module         : IFTQSTRUCT_TQMON                                         */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : IFTQSTRUCT_TQMON_L.H                                     */
/*                                                                            */
/* !Scope          : Private                                                  */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFTQSTRUCT_TQMON/IFTQS$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   15 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef IFTQSTRUCT_TQMON_L_H
#define IFTQSTRUCT_TQMON_L_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_PRM_BDECEACVRAW_COLS           (5)
#define SFTYMGT_PRM_BNREGREQRAW_COLS           (5)
#define SFTYMGT_PRM_NCKFILRAW_COLS             (5)
#define SFTYMGT_PRM_NOGEARDRIVFILRAW_COLS      (5)
#define SFTYMGT_PRM_NOTARGEARTRARAW_COLS       (5)
#define SFTYMGT_PRM_TQLIMEMRAW_COLS            (5)

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  IFTQSTRUCT_TQMON_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean IFTQSTRUCT_TQMON_bAcvNRegReOut;
extern boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev;
extern boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev1;
extern boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev2;
extern boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev3;
extern boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev4;
extern boolean IFTQSTRUCT_TQMON_bDeceAcvOut;
extern boolean IFTQSTRUCT_TQMON_bDeceAcvPrev;
extern boolean IFTQSTRUCT_TQMON_bDeceAcvPrev1;
extern boolean IFTQSTRUCT_TQMON_bDeceAcvPrev2;
extern boolean IFTQSTRUCT_TQMON_bDeceAcvPrev3;
extern boolean IFTQSTRUCT_TQMON_bDeceAcvPrev4;
extern boolean SftyMgt_prm_bDeceAcvRaw[SFTYMGT_PRM_BDECEACVRAW_COLS];
extern boolean SftyMgt_prm_bNRegReqRaw[SFTYMGT_PRM_BNREGREQRAW_COLS];
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern sint8 IFTQSTRUCT_TQMON_s8TarGearOut;
extern sint8 IFTQSTRUCT_TQMON_s8TarGearPrev;
extern sint8 IFTQSTRUCT_TQMON_s8TarGearPrev1;
extern sint8 IFTQSTRUCT_TQMON_s8TarGearPrev2;
extern sint8 IFTQSTRUCT_TQMON_s8TarGearPrev3;
extern sint8 IFTQSTRUCT_TQMON_s8TarGearPrev4;
extern sint8 SftyMgt_prm_noTarGearTraRaw[SFTYMGT_PRM_NOTARGEARTRARAW_COLS];
extern uint8 IFTQSTRUCT_TQMON_u8CorDrFilOut;
extern uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev1;
extern uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev2;
extern uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev3;
extern uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev4;
extern uint8 IFTQSTRUCT_TQMON_u8CorDriFilPrev;
extern uint8 IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr;
extern uint8 IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr;
extern uint8 SftyMgt_prm_noGearDrivFilRaw[SFTYMGT_PRM_NOGEARDRIVFILRAW_COLS];
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 IFTQSTRUCT_TQMON_s16TqLimEMOut;
extern sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev;
extern sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev1;
extern sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev2;
extern sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev3;
extern sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev4;
extern sint16 SftyMgt_prm_tqLimEMRaw[SFTYMGT_PRM_TQLIMEMRAW_COLS];
extern uint16 IFTQSTRUCT_TQMON_u16CkFilOut;
extern uint16 IFTQSTRUCT_TQMON_u16CkFilPrev;
extern uint16 IFTQSTRUCT_TQMON_u16CkFilPrev1;
extern uint16 IFTQSTRUCT_TQMON_u16CkFilPrev2;
extern uint16 IFTQSTRUCT_TQMON_u16CkFilPrev3;
extern uint16 IFTQSTRUCT_TQMON_u16CkFilPrev4;
extern uint16 IFTQSTRUCT_TQMON_u16FilterOut;
extern uint16 IFTQSTRUCT_TQMON_u16SpdVeh;
extern uint16 SftyMgt_agCkClsExCal_MP;
extern uint16 SftyMgt_agCkClsExCal2_MP;
extern uint16 SftyMgt_agCkOpInCal_MP;
extern uint16 SftyMgt_agCkOpInCal2_MP;
extern uint16 SftyMgt_prm_nCkFilRaw[SFTYMGT_PRM_NCKFILRAW_COLS];
extern uint16 SftyMgt_spd1000RatCf_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 IFTQSTRUCT_TQMON_u32nEngFiltMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void IFTQSTRUCT_TQMON_vidFluxInternes(void);
void IFTQSTRUCT_TQMON_vidGeInf40m2Bis(void);
void IFTQSTRUCT_TQMON_vidGeInf40m3Bis(void);
void IFTQSTRUCT_TQMON_vidGeInf40m4Bis(void);
void IFTQSTRUCT_TQMON_vidGeInf40msBis(void);
void IFTQSTRUCT_TQMON_vidGenerInf10ms(void);
void IFTQSTRUCT_TQMON_vidGenerInf40ms(void);
void IFTQSTRUCT_TQMON_vidGenerInfTole(void);
void IFTQSTRUCT_TQMON_vidGenerInfTran(void);
void IFTQSTRUCT_TQMON_vidGerCprInject(void);
void IFTQSTRUCT_TQMON_vidInitOutput(void);
void IFTQSTRUCT_TQMON_vidInitOutputBis(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* IFTQSTRUCT_TQMON_L_H */

/*-------------------------------- end of file -------------------------------*/
