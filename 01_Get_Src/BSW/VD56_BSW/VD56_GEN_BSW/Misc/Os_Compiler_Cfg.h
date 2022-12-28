/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Os                                                      */
/* !Description     : Kernel                                                  */
/*                                                                            */
/* !File            : Os_Compiler_Cfg.h                                       */
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
 * %PID: P2017_BSW:0A192463.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef OS_COMPILER_CFG_H
#define OS_COMPILER_CFG_H
        
/* memclass and ptrclass macros */
#define OS_CODE               /* not required */ /* Code */
#define OS_CONST              /* not required */ /* Global or static constants. */
#define OS_APPL_DATA          /* not required */ /* References on application data (expected to be in RAM or ROM) passed via API. */
#define OS_APPL_CONST         /* not required */ /* References on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API */
#define OS_APPL_CODE          /* not required */ /* References on application functions. (e.g. call back function pointers) */
#define OS_VAR_NOINIT         /* not required */ /* Globals or statics which are never initialized. */
#define OS_VAR_POWER_ON_INIT  /* not required */ /* Globals or statics which are initialized after PO reset. */
#define OS_VAR_FAST           /* not required */ /* Globals or statics which require fast or bitwise access. */
#define OS_VAR                /* not required */ /* Globals or statics which are initialized after every reset. */

#endif /* OS_COMPILER_CFG_H */

/*-------------------------------- end of file -------------------------------*/
