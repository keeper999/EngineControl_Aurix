/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : MCAL                                                                                            */
/*                                                                                                                    */
/* !Component       : DRV_SH7254X                                                                                     */
/* !Description     : SH7254X microcontroller familly driver layer.                                                   */
/*                                                                                                                    */
/* !Module          : INTDRV                                                                                          */
/* !Description     : API of the INTDRV Component                                                                     */
/*                                                                                                                    */
/* !File            : INTDRV.H                                                                                        */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : SH7254X                                                                                         */
/*                                                                                                                    */
/* !Vendor          : Valeo VEES                                                                                      */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/INTDRV.H_v                                                          $*/
/* $Revision::   1.0                                                                                                 $*/
/* $Author::   croche2                                                                        $$Date::   11 Mar 2014 $*/
/**********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/


#ifndef INTDRV_H
#define INTDRV_H

#include "INTDRV_I.h"



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidSET_CONFIG set the configuration of all channels of the channel group identified by       */
/*                "snGroupChannel" with the desired configuration                                                     */
/* !Number      : 0x00                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/14.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.01                                                                                     */
/* !Trace_To    : INTDRV/EA/09.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.02                                                                                     */
/* !Trace_To    : INTDRV/EA/09.02                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSET_CONFIG( \
\
   snGroupChannel, \
   snConfSelect, \
   u16Config \
\
) \
   INTDRV_vidSET_CONFIG_I(snGroupChannel, snConfSelect, u16Config)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidSET_BANK_CONFIG set the "snBankConfSelect"configuration of all bank resources with the    */
/*                desired configuration "u16BankConfig"                                                               */
/* !Number      : 0x01                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/02.01                                                                                     */
/* !Trace_To    : INTDRV/EA/04.01                                                                                     */
/* !Trace_To    : INTDRV/EA/15.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSET_BANK_CONFIG( \
\
   snBankConfSelect, \
   u16BankConfig \
\
) \
   INTDRV_vidSET_BANK_CONFIG_I(snBankConfSelect, u16BankConfig)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_u16GET_PRIORITY_VALUE returns the mask to apply to the "u16Config" parameter of              */
/*                INTDRV_vidSET_CONFIG, to set the Subgroup "snSubGroupChannel" "u8ItLevel" priority.                 */
/* !Number      : 0x02                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/16.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.02                                                                                     */
/* !Trace_To    : INTDRV/EA/10.01                                                                                     */
/* !Trace_To    : INTDRV/EA/10.02                                                                                     */
/* !Trace_To    : INTDRV/EA/07.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_u16GET_PRIORITY_VALUE( \
\
   snSubGroupChannel, \
   u8ItLevel \
\
) \
   INTDRV_u16GET_PRIORITY_VALUE_I(snSubGroupChannel, u8ItLevel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_u16GET_EDGE_VALUE returns the mask to apply to "u16Config" parameter of                      */
/*                INTDRV_vidSET_CONFIG,to configure the IRQ "snIRQ" "snSensitivity" edge                              */
/* !Number      : 0x03                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/17.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.02                                                                                     */
/* !Trace_To    : INTDRV/EA/06.01                                                                                     */
/* !Trace_To    : INTDRV/EA/05.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_u16GET_EDGE_VALUE( \
\
   snIRQ, \
   snSensitivity \
\
) \
   INTDRV_u16GET_EDGE_VALUE_I(snIRQ, snSensitivity)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_u16GET_BANK_CONFIG_VALUE returns the mask to apply to "u16BankConfig" parameter of           */
/*                INTDRV_vidSET_BANK_CONFIG,to configure bank registers.                                              */
/* !Number      : 0x04                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/18.01                                                                                     */
/* !Trace_To    : INTDRV/EA/04.01                                                                                     */
/* !Trace_To    : INTDRV/EA/03.01                                                                                     */
/* !Trace_To    : INTDRV/EA/02.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_u16GET_BANK_CONFIG_VALUE( \
\
   snBankConfSelect, \
   snBankConfValue \
\
) \
   INTDRV_u16GET_BANK_CONFIG_VALUE_I(snBankConfSelect, snBankConfValue)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidENABLE enables an interrupt request for the "snChannel" channel.                          */
/* !Number      : 0x05                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/19.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidENABLE( \
\
   snChannel \
\
) \
   INTDRV_vidENABLE_I(snChannel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidDISABLE disables the interrupt request for the "snChannel" channel                        */
/* !Number      : 0x06                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/20.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidDISABLE( \
\
   snChannel \
\
) \
   INTDRV_vidDISABLE_I(snChannel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_bCHECK returns TRUE or FALSE according to whether an interrupt is pending or not on the      */
/*                "snChannel" channel.                                                                                */
/* !Number      : 0x07                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/21.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_bCHECK( \
\
   snChannel \
\
) \
   INTDRV_bCHECK_I(snChannel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidACKNOWLEDGE clears the interrupt pending flag of the "snChannel" channel                  */
/* !Number      : 0x08                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/22.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidACKNOWLEDGE( \
\
   snChannel \
\
) \
   INTDRV_vidACKNOWLEDGE_I(snChannel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidSuspendAll saves the actual microcontroller status (including CPU level) into             */
/*                "ps32ItLevel" and suspends all interrupts (begin of an uninterruptible sequence)                    */
/* !Number      : 0x09                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/23.01                                                                                     */
/* !Trace_To    : INTDRV/EA/23.02                                                                                     */
/* !Trace_To    : INTDRV/EA/11.02                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSuspendAll( \
\
   ps32ItLevel \
\
) \
   INTDRV_vidSuspendAll_I(ps32ItLevel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidResumeAll sets the microcontroller status (included the CPU level) to "s32ItLevel".       */
/* !Number      : 0x0A                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/24.01                                                                                     */
/* !Trace_To    : INTDRV/EA/24.02                                                                                     */
/* !Trace_To    : INTDRV/EA/11.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidResumeAll( \
\
   s32ItLevel \
\
) \
   INTDRV_vidResumeAll_I(s32ItLevel)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidTrap executes a trap to the vector number "s32VectNumber" in the current vector table.    */
/* !Number      : 0x0B                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/25.01                                                                                     */
/* !Trace_To    : INTDRV/EA/12.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidTrap( \
\
   s32VectNumber \
\
) \
   INTDRV_vidTrap_I(s32VectNumber)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_papfvidGetVectTableRef returns a pointer to the actual active vector table.                  */
/* !Number      : 0x0C                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/26.01                                                                                     */
/* !Trace_To    : INTDRV/EA/13.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_papfvidGetVectTableRef( \
\
\
) \
   INTDRV_papfvidGetVectTableRef_I()



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_vidSetVectTable selects "papfvidVectTabRef" as the new active vector table.                  */
/* !Number      : 0x0D                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/27.01                                                                                     */
/* !Trace_To    : INTDRV/EA/13.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSetVectTable( \
\
   pafpvidVectTabRef \
\
) \
   INTDRV_vidSetVectTable_I(pafpvidVectTabRef)



/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : INTDRV_bGET_ENABLE_BIT retrieve 1 or 0 whether the interrupt request is enabled or not.             */
/* !Number      : 0x0E                                                                                                */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/* !Trace_To    : INTDRV/EA/28.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_bGET_ENABLE_BIT( \
\
   snChannel \
\
) \
   INTDRV_bGET_ENABLE_BIT_I(snChannel)


#endif /* INTDRV_H */

/*--------------------------------------------------- end of file ----------------------------------------------------*/
