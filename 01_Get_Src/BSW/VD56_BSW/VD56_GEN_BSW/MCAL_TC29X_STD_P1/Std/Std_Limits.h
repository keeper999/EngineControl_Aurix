/**********************************************************************************************************************/
/* !Layer           : SRV                                                                                             */
/* !Component       : STD                                                                                             */
/* !Description     : Standard header files for compiler abstraction                                                  */
/*                                                                                                                    */
/* !File            : Std_Limits.h                                                                                    */
/* !Description     : Limits value of standard types                                                                  */
/*                                                                                                                    */
/* !Reference       : V01 INS 07 00014 #01                                                                            */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: COTS_17:0A949.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef STD_LIMITS_H
#define STD_LIMITS_H


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* !Comment: Minimum value of a data of type uint8 or uint8_least                                                     */
#define UINT8_MIN 0
/* !Comment: Maximum value of a data of type uint8 or uint8_least                                                     */
#define UINT8_MAX 255

/* !Comment: Minimum value of a data of type sint8 or sint8_least                                                     */
#define SINT8_MIN -128
/* !Comment: Maximum value of a data of type sint8 or sint8_least                                                     */
#define SINT8_MAX 127

/* !Comment: Minimum value of a data of type uint16 or uint16_least                                                   */
#define UINT16_MIN 0
/* !Comment: Maximum value of a data of type uint16 or uint16_least                                                   */
#define UINT16_MAX 65535u

/* !Comment: Minimum value of a data of type sint16 or sint16_least                                                   */
#define SINT16_MIN (-32767 - 1)
/* !Comment: Maximum value of a data of type sint16 or sint16_least                                                   */
#define SINT16_MAX 32767

/* !Comment: Minimum value of a data of type uint32                                                                   */
#define UINT32_MIN 0
/* !Comment: Maximum value of a data of type uint32                                                                   */
#define UINT32_MAX 4294967295ul

/* !Comment: Minimum value of a data of type sint32                                                                   */
#define SINT32_MIN (-2147483647l - 1)
/* !Comment: Maximum value of a data of type sint32                                                                   */
#define SINT32_MAX 2147483647l

/* !Comment: Minimum value of a data of type float32                                                                  */
#define FLOAT32_MIN -3.4028234663852886e+38f
/* !Comment: Maximum value of a data of type float32                                                                  */
#define FLOAT32_MAX 3.4028234663852886e+38f

/* !Comment: Minimum value of a data of type float64                                                                  */
#define FLOAT64_MIN -1.7976931348623158e+308
//#define FLOAT64_MIN -1.7976931348623158e+308
/* !Comment: Maximum value of a data of type float64                                                                  */
#define FLOAT64_MAX 1.7976931348623158e+308


#endif /* STD_LIMITS_H */

/*--------------------------------------------------- end of file ----------------------------------------------------*/
