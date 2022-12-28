/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_Runnables                                        */
/* !Description :															  */
/*                                                                            */
/* !File :              FISA_Runnables.h                                      */
/*                                                                            */
/* !Scope :             Public                                                */
/*                                                                            */
/* !Target :            All                                                   */
/*                                                                            */
/* !Vendor :            Valeo                                                 */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/FISA/5-SOFT-LIV/FIS$*/
/* $Revision::   1.0       $$Author::   adelvare$$Date::   16 Mar 2012 14:$   */
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef _FISA_RUNNABLES_H_
#define _FISA_RUNNABLES_H_


/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/

#include "Rte_FISA.h"


/******************************************************************************/
/* DEFINITION OF STRUCTURE                                                    */
/******************************************************************************/

typedef struct
{
  UInt16 u16Ext_ctInj;					/* [0 ; 65535]	  	echelle 1		*/	  /* 1  */
  UInt16 u16Ext_nEng ;					/* [0 ; 7500]	  	echelle 1		*/	  /* 2  */
  UInt16 u16Ext_pAirExtMes;				/* [500 ; 1500]		echelle 1		*/	  /* 3  */
  SInt16 s16Ext_tCoMes;					/* [-40 ; 214]		echelle 1		*/	  /* 4  */
  SInt16 s16uBattMes;					/* [0 ; 3200]		echelle 1/100 */	  /* 5  */
  UInt16 u16Veh_spdVeh;					/* [0 ; 64000]		echelle 1/128	*/	  /* 6  */
  Boolean bExt_bEngReStrt;				/* {0 , 1}							*/	  /* 7 */
  Boolean bExt_bSync;					/* {0 , 1}							*/	  /* 8  */
  Boolean bExt_bStrtEnd;				/* {0 , 1}							*/	  /* 9  */
  Boolean bExt_bIdlAcv;					/* {0 , 1}							*/	  /* 10 */
  UInt8   u8CoPt_noEgdGearCord;			/* {0 , 7}							*/	  /* 11 */
  UInt16 u16Eng_rAirLd;					/* [0 ; 4800]						*/	  /* 12 */
  Boolean bAFReg_bAFRegAcv;				/* {0 , 1}							*/	  /* 13 */
  UInt16 u16AccP_rAccP;					/* {0 , 1}							*/	  /* 14 */
  Boolean bExt_bFirstStrt;				/* {0 , 1}							*/	  /* 15 */
  UInt16 u16TqSys_nTarIdl;				/* [0 ; 32000]		echelle 1/4		*/	  /* 16 */
  Boolean bExt_bCluPedPrss;				/* {0 , 1}							*/	  /* 17 */
  Boolean bFISA_bPoor;					/* {0 , 1}							*/	  /* 18 */
  Boolean bFISA_bRich;					/* {0 , 1}							*/	  /* 19 */
  Boolean bFISA_bInhFISA;				/* {0 , 1}							*/	  /* 20 */
  Boolean bFISA_bInhInst;				/* {0 , 1}							*/	  /* 21 */
  Boolean bRFuDet_bRstAdp;				/* {0 , 1}							*/	  /* 22 */
  UInt8 u8Ext_tiTDC;					/* [0 ; 100]		echelle 1/1000	*/	  /* 23 */
  UInt16 u16AFReg_facCorRich;			/* [0 ; 1280]		echelle 1/128 en entree mais echelle 1/100 dans le code */	  /* 24 */
  UInt8  u8FISA_facRst;				/* [0 ; 128]		echelle 1/128	 en entree mais echelle 1/100 dans le code */	  /* 25 */
  UInt8 u8Ext_stGBxCf; 					/* {0 , 2}							*/	  /* 26 */
  UInt8 CoPTSt_stEng;					/* [1 ; 8]							*/	  /* 27 */
}tstrInputFisa;

/* ============================================== */
/* Structure des données du vecteur Sortie FISA   */
/* ============================================== */

typedef struct
{
  Boolean bFISA_bAuthSave;				 /* {0 , 1}								*/
  Boolean bFISA_bGrdWin;				 /* {0 , 1}								*/
  Boolean bFISA_bInstWin;				 /* {0 , 1}								*/
  Boolean bFISA_bAFRegWin;				 /* {0 , 1}								*/
  Boolean bFISA_bRstAdpDone;			 /* {0 , 1}								*/
}tstrOutputFisa;

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/

#define FISA_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FISA_MemMap.h"

extern VAR(Boolean,FISA_VAR) FISA_firstTime;

#define FISA_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FISA_MemMap.h"

/* ce visualisable est utilisé par DetermVal et SupervFctAdaptInj (où il est défini) , il faut donc le déclarer en tant qu'extern pour DetermVal */
/* Altis 1613245 */
#define FISA_START_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

extern VAR(UInt8,FISA_VAR) FISA_idxTypIni;

#define FISA_STOP_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/

/******************************************************************************/
/* DECLARATION OF FUNCTIONS                                                   */
/******************************************************************************/
#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"


/*==============================================================================
** Name: FISA_GetExt_ctInj
** Description:
** Lecture entree FISA
**============================================================================*/

FUNC(void,FISA_CODE) FISA_GetExt_ctInj(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_nEng
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_nEng(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_pAirExtMes
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_pAirExtMes(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_tCoMes
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_tCoMes(P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_ctInj
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetuBattMes(P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetVeh_spdVeh
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetVeh_spdVeh(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_bEngReStrt
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_bEngReStrt(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_Ext_bSync
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_Ext_bSync(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_bStrtEnd
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_bStrtEnd(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_bIdlAcv
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_bIdlAcv(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetCoPt_noEgdGearCord
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetCoPt_noEgdGearCord(P2VAR(UInt8, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetEng_rAirLd
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetEng_rAirLd(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetAFReg_bAFRegAcv
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetAFReg_bAFRegAcv(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetAccP_rAccP
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetAccP_rAccP(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_bFirstStrt
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_bFirstStrt(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetTqSys_nTarIdl
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetTqSys_nTarIdl(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_bCluPedPrss
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_bCluPedPrss(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetPoor
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetPoor(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetRich
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetRich(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetInhFISA
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetInhFISA(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetInhInst
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetInhInst(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetRFuDet_bRstAdp
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetRFuDet_bRstAdp(P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_tiTDC
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_tiTDC(P2VAR(UInt8, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetAFReg_facCorRich
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetAFReg_facCorRich(P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetfacRst
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetfacRst(P2VAR(UInt8, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetfacOld
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetfacOld(P2VAR(UInt8, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetExt_stGBxCf
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetExt_stGBxCf(P2VAR(UInt8, FISA_APPL_DATA, AUTOMATIC) value);

/*==============================================================================
** Name: FISA_GetCoPTSt_stEng
** Description:
** Lecture entree FISA
**============================================================================*/
FUNC(void,FISA_CODE) FISA_GetCoPTSt_stEng(P2VAR(UInt8, FISA_APPL_DATA, AUTOMATIC) value);


/*==============================================================================
** Name:  FISA_Update_facAdp
** Description: cette fonction est appele pour tamponner les sorties
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_Update_facAdp(UInt8 value);

/*==============================================================================
** Name:  FISA_Update_bAuthSave
** Description: cette fonction est appele pour tamponner les sorties
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_Update_bAuthSave(Boolean value);

/*==============================================================================
** Name:  FISA_Update_bGrdWin
** Description: cette fonction est appele pour tamponner les sorties
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_Update_bGrdWin(Boolean value);

/*==============================================================================
** Name:  FISA_Update_bInstWin
** Description: cette fonction est appele pour tamponner les sorties
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_Update_bInstWin(Boolean value);

/*==============================================================================
** Name:  FISA_Update_bAFRegWin
** Description: cette fonction est appele pour tamponner les sorties
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_Update_bAFRegWin(Boolean value);

/*==============================================================================
** Name:  FISA_Update_bRstAdpDone
** Description: cette fonction est appele pour tamponner les sorties
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_Update_bRstAdpDone(Boolean value);


#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

#endif
