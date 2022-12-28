/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQIDCENGREAL                                             */
/*                                                                            */
/* !Module         : TQIDCENGREAL                                             */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQIDCENGREAL_L.H                                         */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDCENGREAL/TQIDCENGR$*/
/* $Revision::   1.4      $$Author::   MBENFRAD       $$Date::   02 May 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQIDCENGREAL_L_H
#define TQIDCENGREAL_L_H

#include "STD_TYPES.h"

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  TQIDCENGREAL_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_agIgAdvOptmEstim;
extern sint16 TQIDCENGREAL_s16agIgAdvDifOptCur;
extern uint16 SftyMgt_effAdvTqIdcEstim;
extern uint16 SftyMgt_rAcvCyl;
extern uint16 SftyMgt_rAirLdEstim;
extern uint16 SftyMgt_rAirLdEstimRaw_MP;
extern uint16 SftyMgt_tqIdcOptmEngCurEstim;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 TQIDCENGREAL_u32FilterMem;
extern sint32 SftyMgt_rAirLdEstimGrd_MP;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void TQIDCENGREAL_vidCalcRendmntAvanc(void);
void TQIDCENGREAL_vidEstimAvcOptimal(void);
void TQIDCENGREAL_vidEstimcpleminimum(void);
void TQIDCENGREAL_vidEstimCpleOptimum(void);
void TQIDCENGREAL_vidEstimCplIndiqRel(void);
void TQIDCENGREAL_vidEstimCplRelRdmnt(void);
void TQIDCENGREAL_vidEstimRendmAvance(void);
void TQIDCENGREAL_vidEstimRmplissgAir(void);
void TQIDCENGREAL_vidInitOutput(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* TQIDCENGREAL_L_H */

/*-------------------------------- end of file -------------------------------*/
