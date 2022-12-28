/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STUB                                                    */
/* !Description     : ACQCMDDIO component.                                    */
/*                                                                            */
/* !Module          : ACQCMDDIO                                               */
/* !Description     : SPECIFICATION DES COMMANDES ET ACQUISITIONS LOGIQUES    */
/*                                                                            */
/* !File            : ACQCMDDIO_GATEWAY.h                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* !Reference   : PTS_DOC_6509298 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/PATCH/ACQCMDDIO_GATEWAY.h_v $*/
/* $Revision::   1.1      $$Author::   ynicaise       $$Date::   03 Nov 2014 $*/
/* $Author::   ynicaise                               $$Date::   03 Nov 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
#ifndef ACQCMDDIO_GATEWAY_H
#define ACQCMDDIO_GATEWAY_H

#include "DIOHAL.H"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CH_DIO_OUT_MAIN_RELAY_CMD      MAIN_RELAY
#define CH_DIO_OUT_BLOW_BY_2           DIOHAL_u8WRITE_TABLE_SIZE

#endif /* ACQCMDDIO_GATEWAY_H */

/*-------------------------------- end of file -------------------------------*/