/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MATHSRV                                                 */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !File            : MATHSRV_PORTABILITY.h                                   */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !Reference       : PTS_DOC_5405229                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MATHSRV PORTABILITY H-99055194X4420X362.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MATHSRV_PORTABILITY_H
#define MATHSRV_PORTABILITY_H

/******************************************************************************/
/* MACRO CONSTANTS                                                            */
/******************************************************************************/


#define  abs(a)         MATHSRV_udtABS(a)
#define  min(a, b)      MATHSRV_udtMIN(a, b)
#define  max(a, b)      MATHSRV_udtMAX(a, b)
#define  clamp(a, b, c) MATHSRV_udtCLAMP(a, b, c)

#define interp_1d_1b         MATHSRV_u8Interp1d
#define interp_1d_1b_09_pts  MATHSRV_u8Interp1d09Pts
#define interp_1d_1b_11_pts  MATHSRV_u8Interp1d11Pts
#define interp_1d_1b_17_pts  MATHSRV_u8Interp1d17Pts
#define interp_2d_1b         MATHSRV_u8Interp2d
#define interp_1d_2b         MATHSRV_u16Interp1d
#define interp_1d_2b_09_pts  MATHSRV_u16Interp1d09Pts
#define interp_1d_2b_11_pts  MATHSRV_u16Interp1d11Pts
#define interp_1d_2b_17_pts  MATHSRV_u16Interp1d17Pts
#define interp_2d_2b         MATHSRV_u16Interp2d
#define calc_para_1b_inc_tab MATHSRV_u16CalcParaIncAryU8Loc
#define calc_para_2b_inc_tab MATHSRV_u16CalcParaIncAryU16Loc
#define filtre_uw_coefub_mem MATHSRV_u16FirstOrderFilterGu8
#define filtre_uw_coefuw_mem MATHSRV_u16FirstOrderFilterGu16
#define general_threshold    MATHSRV_vidSchmittTriggerU16


#endif /* MATHSRV_PORTABILITY_H */

/*----------------------------- fin de fichier -------------------------------*/
