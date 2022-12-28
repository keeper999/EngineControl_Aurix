/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IFXGTM                                                  */
/* !Description     : GTM Driver                                              */
/*                                                                            */
/* !File            : IfxGtm_Typ.h                                            */
/* !Description     : Definition of data of GTM type Component                */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A18532.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXGTM_TYP_H_
#define IFXGTM_TYP_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "IfxGtm_Def.h"

/******************************************************************************/
/*                           Enums                                            */
/******************************************************************************/
/*! IfxGtm_IrqTrigger
 */
typedef enum
{
   IfxGtm_IrqTrigger_CCU0,
   IfxGtm_IrqTrigger_CCU1
}IfxGtm_IrqTrigger;

/*! Ifx_Status
 */
enum Ifx_Status
{
   Ifx_ok    = 0,
   Ifx_notOk = 1
};

/*! IfxGtm_Tim
 */
typedef enum
{
   IfxGtm_Tim_0 = 0,
   /* Only TIM0 is possible for Crank/Cam */
/*
   IfxGtm_Tim_1 = 1,
   IfxGtm_Tim_2 = 2,
   IfxGtm_Tim_3 = 3,
*/
}IfxGtm_Tim;

/*! IfxGtm_TimCh
 */
typedef enum
{
   IfxGtm_TimCh_0 = 0,
   IfxGtm_TimCh_1 = 1,
   IfxGtm_TimCh_2 = 2,
   IfxGtm_TimCh_3 = 3,
   IfxGtm_TimCh_4 = 4,
   IfxGtm_TimCh_5 = 5,
   IfxGtm_TimCh_6 = 6,
   IfxGtm_TimCh_7 = 7
}IfxGtm_TimCh;

/*! IfxGtm_Atom
 */
typedef enum
{
   IfxGtm_Atom_0 = 0,
   IfxGtm_Atom_1 = 1,
   IfxGtm_Atom_2 = 2,
   IfxGtm_Atom_3 = 3,
   IfxGtm_Atom_4 = 4,
   IfxGtm_Atom_5 = 5,
   IfxGtm_Atom_6 = 6,
   IfxGtm_Atom_7 = 7,
   IfxGtm_Atom_8 = 8
}IfxGtm_Atom;

/*! IfxGtm_AtomCh
 */
typedef enum
{
   IfxGtm_AtomCh_0 = 0,
   IfxGtm_AtomCh_1 = 1,
   IfxGtm_AtomCh_2 = 2,
   IfxGtm_AtomCh_3 = 3,
   IfxGtm_AtomCh_4 = 4,
   IfxGtm_AtomCh_5 = 5,
   IfxGtm_AtomCh_6 = 6,
   IfxGtm_AtomCh_7 = 7
}IfxGtm_AtomCh;


/*! IfxGtm_Tom
 */
typedef enum
{
   IfxGtm_Tom_0 = 0,
   IfxGtm_Tom_1 = 1,
   IfxGtm_Tom_2 = 2,
   IfxGtm_Tom_3 = 3,
   IfxGtm_Tom_4 = 4,
   IfxGtm_Tom_5 = 5,
   IfxGtm_Tom_6 = 6,
   IfxGtm_Tom_7 = 7,
   IfxGtm_Tom_8 = 8
}IfxGtm_Tom;

/*! IfxGtm_TomCh
 */
typedef enum
{
   IfxGtm_TomCh_0 = 0,
   IfxGtm_TomCh_1 = 1,
   IfxGtm_TomCh_2 = 2,
   IfxGtm_TomCh_3 = 3,
   IfxGtm_TomCh_4 = 4,
   IfxGtm_TomCh_5 = 5,
   IfxGtm_TomCh_6 = 6,
   IfxGtm_TomCh_7 = 7
}IfxGtm_TomCh;

typedef enum
{
   IfxGtm_Atom_Level_Low  = 0,
   IfxGtm_Atom_Level_High = 1
}IfxGtm_Atom_Level;

/*! IRQ mode selection  */
typedef enum
{
   IfxGtm_IrqMode_LevelMode       = (0U),     /*!< Level mode         */
   IfxGtm_IrqMode_PulseMode       = (1U),     /*!< Pulse mode         */
   IfxGtm_IrqMode_PulseNotifyMode = (2U),     /*!< Pulse-Notify mode  */
   IfxGtm_IrqMode_SinglePulseMode = (3U)      /*!< Single-Pulse mode  */
}IfxGtm_IrqModeSelect;

typedef enum
{
   IfxGtm_Atom_Mode_SOMI = 0,
   IfxGtm_Atom_Mode_SOMC = 1,
   IfxGtm_Atom_Mode_SOMP = 2,
   IfxGtm_Atom_Mode_SOMS = 3
}IfxGtm_Atom_Mode;

typedef enum
{
   IfxGtm_Atom_Cmp_Ctrl_TbuGe = 0,  /** <! Greater or equal> */
   IfxGtm_Atom_Cmp_Ctrl_TbuLe = 1   /** <! Less or equal> */
}IfxGtm_Atom_Cmp_Ctrl;

typedef enum
{
   IfxGtm_AtomCtrl_Disable = 1,
   IfxGtm_AtomCtrl_Enable  = 2
}IfxGtm_AtomCtrl;

typedef enum
{
   IfxGtm_AtomCcu1_Disable = 0,
   IfxGtm_AtomCcu1_Enable  = 1
}IfxGtm_AtomCcu1;

typedef enum
{
   IfxGtm_Crank = 0,
   IfxGtm_Cam   = 2
}IfxGtm_InSignalType;

typedef enum
{
   IfxGtm_TimTDUDisable     = 0,
   IfxGtm_TimTDURisingEdge  = 1,
   IfxGtm_TimTDUFallingEdge = 2,
   IfxGtm_TimTDUBothEdge    = 3
}IfxGtm_TimTimeOutControl;


typedef enum
{
   IfxGtm_Compare_Unit_0 = 0,
   IfxGtm_Compare_Unit_1 = 1
}IfxGtm_Compare_Unit;

typedef enum
{
   IfxGtmToutSel_TimerA = 0,
   IfxGtmToutSel_TimerB = 1,
   IfxGtmToutSel_TimerC = 2,
   IfxGtmToutSel_TimerD = 3

}IfxGtmToutSel;

/******************************************************************************/
/*                           Struct                                           */
/******************************************************************************/

typedef struct
{
   volatile Ifx_GTM_ATOM_CH* GTM_ATOM_CH;
   volatile Ifx_GTM_ATOM_AGC* GTM_ATOM_AGC;
}Ifx_GTM_ATOM_STRUCT;
#endif /* IFXGTM_TYP_H_ */

/*------------------------------ end of file ---------------------------------*/
