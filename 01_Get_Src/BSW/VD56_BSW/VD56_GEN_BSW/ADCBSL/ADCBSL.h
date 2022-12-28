/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ADCBSL                                                  */
/* !Description     : Analog digital converter                                */
/*                                                                            */
/* !File            : ADCBSL.h                                                */
/* !Description     :                                                         */
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
 * %PID: P2017_BSW:A17855.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef ADCBSL_H
#define ADCBSL_H

#include "Std_Types.h"
#include "ADCBSL_Cfg.h"
#include "IfxVadc_reg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define ADC_MODULE_GLOB                      (MODULE_VADC)

#define ADCBSL_u16CONVERTER_RESOL            4096

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : ADCBSL_u16Read                                              */
/* !Description : returns the result of the last conversion of the channel    */
/*                                                                            */
/* !LastAuthor  : TBOU                                                        */
/******************************************************************************/
#define ADCBSL_u16Read( \
\
   snChannel /* !Comment: Name of the ADCBSL channel                      */ \
\
) \
   M1_ADCBSL_u16Read(snChannel, \
                     ADCBSL_u16GET_CFG_DESIRED_RESOL(snChannel))

   /* Internal macros */
   #define M1_ADCBSL_u16Read(snChannel, u16DesiredResol) \
      M2_ADCBSL_u16Read(snChannel, \
                        u16DesiredResol, \
                        ADCBSL_u16GET_CFG_REAL_RESOL())

   #define M2_ADCBSL_u16Read(snChannel, u16DesiredResol, u16RealResol) \
      M3_ADCBSL_u16Read(snChannel, u16DesiredResol, u16RealResol)

   #define M3_ADCBSL_u16Read(snChannel, u16DesiredResol, u16RealResol) \
      (uint16)( ((u16RealResol) == (u16DesiredResol)) \
              ? (M4_ADCBSL_u16Read(snChannel)) \
              : ( ( ( (M4_ADCBSL_u16Read(snChannel)) \
                  * (u16DesiredResol)) \
                / (u16RealResol))))

   #define M4_ADCBSL_u16Read(snChannel) \
      (((uint32)snChannel##_RES)&0xFFF)


/******************************************************************************/
/* !FuncName    : ADCBSL_u16GET_CFG_DESIRED_RESOL                             */
/* !Description : Gets the desired resolution of the "snChannel"              */
/*                                                                            */
/* !LastAuthor  : TBOU                                                        */
/******************************************************************************/
#define ADCBSL_u16GET_CFG_DESIRED_RESOL( \
\
   snChannel   /* !Comment: Name of the ADCBSL channel                      */ \
) \
   M1_ADCBSL_u16GET_CFG_DESIRED_RESOL(snChannel)

   /* Internal macros */
   #define M1_ADCBSL_u16GET_CFG_DESIRED_RESOL(snChannel) \
      ADCBSL_u16##snChannel##_DESIRED_RESOL

/******************************************************************************/
/* !FuncName    : ADCBSL_u16GET_CFG_REAL_RESOL                                */
/* !Description : Gets the resolution of the hardware converter               */
/*                                                                            */
/* !LastAuthor  : TBOU                                                        */
/******************************************************************************/
#define ADCBSL_u16GET_CFG_REAL_RESOL() \
      ADCBSL_u16CONVERTER_RESOL


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define ADCBSL_START_SEC_CODE
#include "ADCBSL_MemMap.h"

void ADCBSL_vidInit(void);
void ADCBSL_vidWaitInitCompletion(void);

#define ADCBSL_STOP_SEC_CODE
#include "ADCBSL_MemMap.h"

#endif /* ADCBSL_H */

/*------------------------------ end of file ---------------------------------*/
