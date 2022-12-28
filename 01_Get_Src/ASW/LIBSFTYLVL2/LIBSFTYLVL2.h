/******************************************************************************/
/*                                                                            */
/* !Layer           : NONE                                                    */
/*                                                                            */
/* !Component       : LIBSFTYLVL2                                             */
/* !Description     : Diagnostic Level 2                                      */
/*                                                                            */
/* !Module          : LIBSFTYLVL2                                             */
/* !Description     : Diagnostic Level 2                                      */
/*                                                                            */
/* !File            : LIBSFTYLVL2.h                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::                */
/******************************************************************************/
/* !VnrOff :                                                                  */
/******************************************************************************/
#ifndef LIBSFTYLVL2_H
#define LIBSFTYLVL2_H
/******************************************************************************/
#include "Std_Types.h"
#include "MATHSRV.H"
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
void LIBSFTYLVL2_U8_Safety_Level2(boolean RawSig,
                                  uint8  UpTranThd_C,
                                  uint8  DownTranThd_C,
                                  uint8  InitCptConf_C,
                                  uint8  DecCpt_C,
                                  uint8  *Counter_Filter,
                                  boolean *FilSig,
                                  uint8  *CountNiv2,
                                  boolean *bDgoNiv2);                            
#endif /* LIBSFTYLVL2_H */

/*-------------------------------- end of file -------------------------------*/

