/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQIDLCHK                                                 */
/*                                                                            */
/* !Module         : TQIDLCHK                                                 */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQIDLCHK_L.H                                             */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDLCHK/TQIDLCHK_L.H_$*/
/* $Revision::   1.3      $$Author::   hmelloul       $$Date::   04 Jan 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQIDLCHK_L_H
#define TQIDLCHK_L_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void TQIDLCHK_vidInitOutput(void);
void TQIDLCHK_vidValidGlobaleRalenti(void);
void TQIDLCHK_vidValidRegulRalenti(void);
void TQIDLCHK_vidValRalentiDecollage(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/



/******************************************************************************/
/* TYPEDEF                                                                    */
/******************************************************************************/


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  TQIDLCHK_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"
/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bDgoIdlReg;
extern boolean SftyMgt_bDgoIdlTakeOff;
extern boolean SftyMgt_bDgoTqIdlRaw_MP;
extern boolean SftyMgt_bEngNOnIdl_MP;
extern boolean SftyMgt_bErrNIdl_MP;
extern boolean SftyMgt_bTqGrd_MP;
extern boolean SftyMgt_bTqIdcIdl_MP;
extern boolean SftyMgt_bTqIdlErr_MP;
extern boolean TQIDLCHK_bOfsIdlTakeOffPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SftyMgt_facTqIdcIdlFil_MP;
extern uint8 TQIDLCHK_u8DgoIdlRegTempo;
extern uint8 TQIDLCHK_u8ElValidateSlowTempo;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqIdcIdlComp_MP;
extern sint16 SftyMgt_tqIdcIdlFil_MP;
extern uint16 TQIDLCHK_u16nOfsIdlTakeOffPrev;
extern uint16 TQIDLCHK_u16tqIdcIdlCompMP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern sint32 TQIDLCHK_s32tqIdcIdlFilMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#endif /* TQIDLCHK_L_H */

/*-------------------------------- end of file -------------------------------*/
