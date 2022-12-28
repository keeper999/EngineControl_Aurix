/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Adc_Isr.c                                               */
/* !Description     : ISR definition of Adc component                         */
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
 * %PID: P2017_BSW:0A192585.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/******************************************************************************/
/* !Comment: ISR are not defined for following SRCs:                          */
/*           SRC_VADC_CG0_SRx (x = 1..3), SRC_VADC_CG1_SRy (y = 0..3),        */
/*           SRC_VADC_Gz_SR3 (z = 0..7)                                       */
/******************************************************************************/
/* !Comment: To manage ADC EMUX transfers using DMA, DMAMEx_CHy_SR            */
/*           shall be configured                                              */
/******************************************************************************/

#include "Std_Types.h"
#include "Isr_Cfg.h"
#include "Os.h"

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G0_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G0_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G0_SR0_USED == STD_ON)
INT(SRC_VADC_G0_SR0_ISR)
{
/* ADC0 SRN0 is used by request source 0 of ADC0 */
#if (ADC0_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC0);
#endif
}
#endif /* if (SRC_VADC_G0_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G0_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G0_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G0_SR1_USED == STD_ON)
INT(SRC_VADC_G0_SR1_ISR)
{
/* ADC0 SRN1 is used by request source 1 of ADC0 */
#if (ADC0_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC0);
#endif
}
#endif /* if (SRC_VADC_G0_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G1_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G1_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G1_SR0_USED == STD_ON)
INT(SRC_VADC_G1_SR0_ISR)
{
/* ADC0 SRN0 is used by request source 0 of ADC1 */
#if (ADC1_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC1);
#endif
}
#endif /* if (SRC_VADC_G1_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G1_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G1_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G1_SR1_USED == STD_ON)
INT(SRC_VADC_G1_SR1_ISR)
{
/* ADC1 SRN1 is used by request source 1 of ADC1 */
#if (ADC1_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC1);
#endif
}
#endif /* if (SRC_VADC_G1_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G2_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G2_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G2_SR0_USED == STD_ON)
INT(SRC_VADC_G2_SR0_ISR)
{
/* ADC2 SRN0 is used by request source 0 of ADC2 */
#if (ADC2_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC2);
#endif
}
#endif /* if (SRC_VADC_G2_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G2_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G2_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G2_SR1_USED == STD_ON)
INT(SRC_VADC_G2_SR1_ISR)
{
/* ADC2 SRN1 is used by request source 1 of ADC2 */
#if (ADC2_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC2);
#endif
}
#endif /* if (SRC_VADC_G2_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G3_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G3_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G3_SR0_USED == STD_ON)
INT(SRC_VADC_G3_SR0_ISR)
{
/* ADC3 SRN0 is used by request source 0 of ADC3 */
#if (ADC3_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC3);
#endif
}
#endif /* if (SRC_VADC_G3_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G3_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G3_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G3_SR1_USED == STD_ON)
INT(SRC_VADC_G3_SR1_ISR)
{
/* ADC3 SRN1 is used by request source 1 of ADC3 */
#if (ADC3_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC3);
#endif
}
#endif /* if (SRC_VADC_G3_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G4_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G4_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G4_SR0_USED == STD_ON)
INT(SRC_VADC_G4_SR0_ISR)
{
/* ADC4 SRN0 is used by request source 0 of ADC4 */
#if (ADC4_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC4);
#endif
}
#endif /* if (SRC_VADC_G0_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G4_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G4_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G4_SR1_USED == STD_ON)
INT(SRC_VADC_G4_SR1_ISR)
{
/* ADC4 SRN1 is used by request source 1 of ADC4 */
#if (ADC4_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC4);
#endif
}
#endif /* if (SRC_VADC_G4_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G5_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G5_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G5_SR0_USED == STD_ON)
INT(SRC_VADC_G5_SR0_ISR)
{
/* ADC5 SRN0 is used by request source 0 of ADC5 */
#if (ADC5_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC5);
#endif
}
#endif /* if (SRC_VADC_G5_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G5_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G5_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G5_SR1_USED == STD_ON)
INT(SRC_VADC_G5_SR1_ISR)
{
/* ADC5 SRN1 is used by request source 1 of ADC5 */
#if (ADC5_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC5);
#endif
}
#endif /* if (SRC_VADC_G5_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G6_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G6_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G6_SR0_USED == STD_ON)
INT(SRC_VADC_G6_SR0_ISR)
{
/* ADC6 SRN0 is used by request source 0 of ADC6 */
#if (ADC6_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC6);
#endif
}
#endif /* if (SRC_VADC_G6_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G6_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G6_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G6_SR1_USED == STD_ON)
INT(SRC_VADC_G6_SR1_ISR)
{
/* ADC6 SRN1 is used by request source 1 of ADC6 */
#if (ADC6_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC6);
#endif
}
#endif /* if (SRC_VADC_G6_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G7_SR0_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G7_SR0                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G7_SR0_USED == STD_ON)
INT(SRC_VADC_G7_SR0_ISR)
{
/* ADC7 SRN0 is used by request source 0 of ADC7 */
#if (ADC7_REQSRC0 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC7);
#endif
}
#endif /* if (SRC_VADC_G7_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G7_SR1_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G7_SR1                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G7_SR1_USED == STD_ON)
INT(SRC_VADC_G7_SR1_ISR)
{
/* ADC7 SRN1 is used by request source 1 of ADC7 */
#if (ADC7_REQSRC1 == ADC_REQSRC_USED)
   /* Call Adc Interrupt function*/
   Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC7);
#endif
}
#endif /* if (SRC_VADC_G7_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_CG0_SR2_ISR)                                   */
/* !Description : INT linked to SRC_VADC_CG0_SR2 managing the interrupts from */
/*                Group that uses Request Source 2 of all ADC kernels         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_CG0_SR2_USED == STD_ON)
INT(SRC_VADC_CG0_SR2_ISR)
{
/* ADC SRN2 is used by request source 2 of All ADC kernels */
#if ( (ADC0_REQSRC2 == ADC_REQSRC_USED) || (ADC1_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC2_REQSRC2 == ADC_REQSRC_USED) || (ADC3_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC4_REQSRC2 == ADC_REQSRC_USED) || (ADC5_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC6_REQSRC2 == ADC_REQSRC_USED) || (ADC7_REQSRC2 == ADC_REQSRC_USED) )
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2CG0AdcRS2();
#endif
}
#endif /* if (SRC_VADC_CG0_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G0_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G0_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G0_SR2_USED == STD_ON)
INT(SRC_VADC_G0_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC0 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC0);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G0_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G1_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G1_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G1_SR2_USED == STD_ON)
INT(SRC_VADC_G1_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC1 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC1);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G1_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G2_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G2_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G2_SR2_USED == STD_ON)
INT(SRC_VADC_G2_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC2 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC2);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G2_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G3_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G3_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G3_SR2_USED == STD_ON)
INT(SRC_VADC_G3_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC3 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC3);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G3_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G4_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G4_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G4_SR2_USED == STD_ON)
INT(SRC_VADC_G4_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC4 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC4);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G4_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G5_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G5_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G5_SR2_USED == STD_ON)
INT(SRC_VADC_G5_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC5 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC5);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G5_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G6_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G6_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G6_SR2_USED == STD_ON)
INT(SRC_VADC_G6_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC6 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC6);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G6_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_VADC_G7_SR2_ISR)                                    */
/* !Description : INT managing ADC Request source conversion completed linked */
/*                to SRC_VADC_G7_SR2                                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_VADC_G7_SR2_USED == STD_ON)
INT(SRC_VADC_G7_SR2_ISR)
{
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC7 SRN2 is used by Channel Event for Limit check */
   /* Call Adc Interrupt function*/
   Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC7);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* if (SRC_VADC_G7_SR2_USED == STD_ON) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/

