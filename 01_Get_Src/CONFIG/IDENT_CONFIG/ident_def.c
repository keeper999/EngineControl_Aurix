/******************************************************************************/
/*                                                                            */
/* !Layer          : MCAL                                                     */
/*                                                                            */
/* !Component      : IDENT                                                    */
/*                                                                            */
/* !Module         : IDENT_Def                                                */
/* !Description    : Data definition of the IDENT component                   */
/*                                                                            */
/* !File           : IDENT_Def.C                                              */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/IDENT_CONFIG/ident_def.c_v $*/
/* $Revision::   1.1      $$Author::   croche2        $$Date::   15 May 2014 $*/
/******************************************************************************/

#include "STD_TYPES.H"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define IDENT_START_SEC_APPMAIN_CALIB
#include "MemMap.h"

const uint8 Identification_psa[29] = {0};

#define IDENT_STOP_SEC_APPMAIN_CALIB
#include "MemMap.h"

#define IDENT_START_SEC_APPMAIN_CONST
#include "MemMap.h"

/* Software identification                                                 */
/* !Comment: 63_10_00                                                      */
const uint8 Identification[24]   =  {
                                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* unused */
                                       0x63, /* Software code number         */
                                       0x10, /* Customer requirements number */
                                       0x00, /* Software delivery number     */
                                       0x00,0x00,0x00,0x00 /* unused */
                                    };

#define IDENT_STOP_SEC_APPMAIN_CONST
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/

