/***************************************************************************
;**
;** FILE NAME      : RICHBOOST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RICHBOOST_H
#define RICHBOOST_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQSYS_NENGPRFMOD_A_COLS                ( 6 )
#define TQSYS_RACCPTHDAUTHOVB_T_COLS           ( 6 )
#define TQSYS_RACCPTHDAUTHRICH_T_COLS          ( 6 )
#define TQSYS_TIDLYAUTHOVB_T_COLS              ( 6 )
#define TQSYS_TIDLYAUTHRICH_T_COLS             ( 6 )
#define TQSYS_TIDLYOVBRST_T_COLS               ( 6 )
#define TQSYS_TQEFCOFSOVBAUTH_T_COLS           ( 6 )
#define TQSYS_TQIDCOFSAUTHRICH_T_COLS          ( 6 )

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

extern const boolean  TqSys_bPrfInhRich_C;
extern const boolean  TqSys_bPrfOvbAuthSel_C;
extern const boolean  TqSys_bPrfRichAuthSel_C;
extern const sint16  TqSys_tCoMesAuthRich_C;
extern const sint16  TqSys_tqHysOvbAuth_C;
extern const sint16  TqSys_tqHysRichAuth_C;
extern const uint16  TqSys_nEngPrfMod_A[TQSYS_NENGPRFMOD_A_COLS];
extern const uint16  TqSys_nThdPrfAuthRich_C;
extern const uint16  TqSys_rAccPHysAuthRich_C;
extern const uint16  TqSys_rAccPHysOvbAuth_C;
extern const uint16  TqSys_rAccPThdAuthOvb_T[TQSYS_RACCPTHDAUTHOVB_T_COLS];
extern const uint16  TqSys_rAccPThdAuthRich_T[TQSYS_RACCPTHDAUTHRICH_T_COLS];
extern const uint16  TqSys_rAccPThdPrfAuthRich_C;
extern const uint16  TqSys_rAccPThdPrfInhRich_C;
extern const uint16  TqSys_tiDlyAuthOvb_T[TQSYS_TIDLYAUTHOVB_T_COLS];
extern const uint16  TqSys_tiDlyAuthRich_T[TQSYS_TIDLYAUTHRICH_T_COLS];
extern const uint16  TqSys_tiDlyOvbRst_T[TQSYS_TIDLYOVBRST_T_COLS];
extern const uint16  TqSys_tiDlyPrfAuthOvb_C;
extern const uint16  TqSys_tiPrfDlyAuthRich_C;
extern const uint16  TqSys_tiPrfRtAuthRich_C;
extern const uint16  TqSys_tiSpdLimDlyAuthOvb_C;
extern const uint16  TqSys_tiSpdLimDlyAuthRich_C;
extern const uint16  TqSys_tqEfcOfsOvbAuth_T[TQSYS_TQEFCOFSOVBAUTH_T_COLS];
extern const uint16  TqSys_tqIdcOfsAuthRich_T[TQSYS_TQIDCOFSAUTHRICH_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RICHBOOST_vidEntry_10ms(void);
void RICHBOOST_vidEntryInit(void);


#endif /* RICHBOOST_H */

/*-------------------------------- end of file -------------------------------*/
