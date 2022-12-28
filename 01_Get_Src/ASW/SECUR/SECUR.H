/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SECUR                                                   */
/* !Description     : Customer security algorithms,Random Seed generation and */
/*                    Key calculation algorithms for Security Access.         */
/*                                                                            */
/* !Module          : SECUR                                                   */
/* !Description     : Public Header file for the component.                   */
/*                                                                            */
/* !File            : SECUR.H                                                 */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SECUR/SECUR.H_v                   $*/
/* $Revision::   1.0      $$Author::   pcabariq       $$Date::   20 Oct 2009 $*/
/******************************************************************************/

#ifndef SECUR_H
#define SECUR_H

#include "Type.H"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* !Description : Initializes SECUR component.                                */
/******************************************************************************/
extern void SECUR_vidInit(const uint16 ku16AppliKey,
                          const uint32 ku32bEepromSeedRead,
                          const uint32 ku32pfbEepromSeedWrite);

/******************************************************************************/
/* !Description : Calculates the key corresponding to the seed then compare   */
/*                the recieved key with the calculated one; Returns true if   */
/*                they are equal, false if they are not.                      */
/******************************************************************************/
extern boolean SECUR_bKeyCalcCompare(uint32 u32Seed, uint32 u32Key);

/******************************************************************************/
/* !Description : Generates a random 4 bytes seed.                            */
/******************************************************************************/
extern uint32 SECUR_u32GenerateRandomSeed(uint16 u16RandomValue);


#endif /* SECUR_H */

/*-------------------------------- end of file -------------------------------*/