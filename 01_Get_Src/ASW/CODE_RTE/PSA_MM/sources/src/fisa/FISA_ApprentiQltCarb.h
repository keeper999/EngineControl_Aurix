/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_ApprentiQltCarb                                  */
/* !Description :       Apprentissage qualite carburant                       */
/*                                                                            */
/* !File :              FISA_ApprentiQltCarb.h                                */
/*                                                                            */
/* !Scope :             Public                                                */
/*                                                                            */
/* !Target :            All                                                   */
/*                                                                            */
/* !Vendor :            Valeo                                                 */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_ApprentiQltCarb.h_v  $*/
/* $Revision::   1.8       $$Author::   flavergn   $$Date::   21 Jul 2010 16:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef __SOURCE_H__
#define __SOURCE_H__

#include "Rte_FISA.h"
#include "FISA_lib.h"
#include "FISA_calibration.h"
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/
#define FISA_NDIFENG_MP_EXP     1
#define FISA_NDIFBURNS_MP_EXP   1
#define FISA_FACNSTRT_MP_EXP   ((SInt16) (-2))
#define FISA_FACSTEPADP_MP_EXP -2
#define FISA_FACDIFSTRT_EXP    -2

#define MAX_SATURATION          4
#define MAX_SATURATION_EXP      0
#define MIN_SATURATION         -1
#define MIN_SATURATION_EXP      0

#define BVM                     0   /*boite vitesse manuelle*/
#define BVA                     1   /*boite vitesse automatique*/
#define BVMP                    2   /*boite vitesse type MP*/

/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/


#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

/******************************************************************************/
/* DECLARATION OF FUNCTIONS                                                   */
/******************************************************************************/

FUNC(void,FISA_CODE)   FISA_ApprentiQltCarb_Init(void);

FUNC(void,FISA_CODE)   FISA_ApprentiQltCarb_main (void);

FUNC(SInt16,FISA_CODE) FISA_ApprentiQltCarb_Reference_rpm_developpement (void);

FUNC(SInt16,FISA_CODE) FISA_ApprentiQltCarb_rpm_delta (void);

FUNC(SInt8,FISA_CODE)  FISA_ApprentiQltCarb_Adaptation_steps (void);

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

#endif /* __SOURCE_H__ */
