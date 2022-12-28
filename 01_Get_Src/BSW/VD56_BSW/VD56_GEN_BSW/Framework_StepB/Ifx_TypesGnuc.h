/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : IFX_CFG                                                 */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFX_TYPESGNUC.h                                         */
/* !Description     : GNU Types definition used in framework software         */
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
 * %PID: P2017_BSW:0A111563.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFX_TYPESGNUC_H_
#define IFX_TYPESGNUC_H_
/******************************************************************************/
#define FRACT_MAX 0x7fffffff

#define __interrupt(intno)

typedef long                fract;
typedef short               sfract;
typedef long long           laccum;
typedef long                __packb; //MSMRK should be struct of four chars
typedef unsigned long       __upackb;//MSMRK should be struct of four unsigned chars
typedef long                __packhw; //MSMRK should be struct of two shorts
typedef unsigned long       __upackhw;//MSMRK should be struct of two unsigned shorts
/******************************************************************************/

#endif /* IFX_TYPESGNUC_H_ */

/*-------------------------------- end of file -------------------------------*/
