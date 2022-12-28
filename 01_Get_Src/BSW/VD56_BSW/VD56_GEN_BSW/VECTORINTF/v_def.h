/* STARTSINGLE_OF_MULTIPLE */
/*****************************************************************************
| Project Name: V E C T O R   -  Common module type definition header
|    File Name: v_def.h
|
|  Description: Declares types and definitions common to all 
|               VECTOR CANbedded modules.
| 
|               Note:
|               =====
|               that some hardware dependent settings are included in this file.
|               Never mix up files with same namings but intended for 
|               other hardware platforms.
|
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2013 by Vector Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary 
| to Vector Informatik GmbH. Vector Informatik GmbH 
| grants to you only those rights as set out in the 
| license conditions. All other rights remain with 
| Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
|   Hp         Armin Happel              Vector Informatik GmbH
|   Ht         Heike Honert              Vector Informatik GmbH
|   dH         Gunnar de Haan            Vector Informatik GmbH
|   Et         Thomas Ebert              Vector Informatik GmbH
|   Wr         Hans Waaser               Vector Informatik GmbH
|   Vg         Frank Voorburg            Vector CANtech, Inc.
|   Ds         Hussain Darwish           Vector CANtech, Inc.
|   RAP        Rebecca Pipkorn           Vector CANtech, Inc.
|   BWR        Brandon Root              Vector CANtech, Inc.
|   Ml         Patrick Markl             Vector Informatik GmbH
|   Pl         Georg Pfluegel            Vector Informatik GmbH
|   LS         Konrad Lazarus            Vector Informatik GmbH
|   Zw         Werner Ziegler            Vector Informatik GmbH
|   Bs         Thomas Balster            Vector Informatik GmbH
|   Stu        Bernd Stumpf              Vector Informatik GmbH
|   Pet        Thomas Petrus             Vector Informatik GmbH
|   To         Torsten Schmidt           Vector Informatik GmbH
|   Ap         Andreas Pick              Vector Informatik GmbH
|   Tri        Frank Triem               Vector Informatik GmbH
|   WM         Marco Wierer              Vector Informatik GmbH
|   Bir        Holger Birke              Vector Informatik GmbH
|   Ces        Senol Cendere             Vector Informatik GmbH
|   Ms         Gunnar Meiss              Vector Informatik GmbH
|   Ths        Thomas Sommer             Vector Informatik GmbH
|   Krt        Kerstin Thim              Vector Informatik GmbH
|   Fn         Matthias Fleischmann      Vector Informatik GmbH
|   Svh        Sven Hesselmann           Vector Informatik GmbH
|   Ard        Thomas Arnold             Vector Informatik GmbH
|   Her        Peter Herrmann            Vector Informatik GmbH
|   swk        Slawomir Wilk             Vector Informatik GmbH
|   Ou         Mihai Olariu              Vector Informatik GmbH
|   Tvi        Timo Vanoni               Vector Informatik GmbH
|   Kk         Karol Kostolny            Vector Informatik GmbH
|   Aj         Arthur Jendrusch          Vector Informatik GmbH
|   vadaba     Abir Bazzi                Vector CANtech, Inc
|   Rna        Ruediger Naas             Vector Informatik GmbH
|   Eta        Edgar Tongoona            Vector Informatik GmbH
|   Rse        Robert Schelkle           Vector Informatik GmbH
|   Seu        Eugen Stripling           Vector Informatik GmbH
|   Was        Andreas Weinrauch         Vector Informatik GmbH
|   QPs        Quetty Palacios           Vector Informatik GmbH
|   Tkr        Torsten Kercher           Vector Informatik GmbH
|   Bmo        Bastian Molkenthin        Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver    Author  Description
| ---------  ----   ------  --------------------------------------------------
| 13-Mar-01  1.00    Hp     Creation
| 04-Apr-01  1.01    Ht     general rework 
| 05-Apr-01  1.02    dH     added Fujitsu FFMC16LX
| 05-Apr-01  1.03    HH     added COMP_GHS_V85X
| 11-Apr-01  1.04    Et     added LIN components
| 23-Apr-01  1.05    Si     corrections for C_COMP_IAR_78K0
|                           lint comments added
| 29-Mai-01  1.06    Pl     added ARM7 STMICRO
| 22-Jun-01  1.07    Ht     added ANSI CANoe
| 03-Jul-01          Wr     added C_COMP_OKI_CC665S
| 12-Jul-01          Et     support combination of "old" CAN driver and "new" LIN driver
| 13-Jul-01  1.08    Ht     error check for supported systems and switches added
| 16-Jul-01          dH     added C_COMP_HEW_SH7055 / C_COMP_HEW_H8S
| 17-Aug-01  1.09    Et     deleted keywords __near and __far for C_COMP_FUJITSU_8L
| 21-Aug-01  1.10    Ht/Vg  added C_COMP_DIABDATA_PPC
| 25-Aug-01  1.11    Ml     added #pragma MESSAGE DISABLE C1106 for Hiware HC08 compiler
| 06-Sep-01  1.12    Ht/Vg  added C_COMP_GNU_ST9
| 11-Sep-01  1.13    Fr     added C_COMP_ANSI_TMS_470
| 21-Sep-01  1.14    Pl     added C_COMP_MCP18_PIC_INT
| 25-Sep-01  1.15    Vg     added C_COMP_MICROTEC_MC376 and C_COMP_TASKING_MC376
| 28-Sep-01  1.16    Hp     added C_COMP_GHS_TX39 and C_COMP_TOSHIBA_TLC900
| 23-Oct-01  1.17    Js     added C_COMP_DIABDATA_MCORE
| 23-Oct-01  1.18    dH     changed ..._SH705X to ..._SH705X
| 05-Nov-01  1.19    dH     added M32R
| 19-Nov-01  1.20    Ht     added C_COMP_xxx_XC16X
| 22-Nov-01  1.21    dH     added C_COMP_IAR_H8S
| 11-Nov-01  1.22    Fz     added C_COMP_MITSUBISHI_M32C/C_COMP_NEC_V85X
| 19-Dec-01  1.23    dH     changed Fujitsu FFMC16LX
| 28-Jan-02  1.24    Ml     ESCAN00002160: added paging keywords for HC12
| 31-Jan-02  1.25    Pl     added C_COMP_KEIL_T89C51C
| 07-Mar-02  1.26    Vg/Rn  added C_COMP_METROWERKS_PPC
| 27-Mar-02  1.27    Fz     added C_COMP_IAR_V85X
| 09-Apr-02  1.28    Ht     addaption to LI 1.3
| 02-Apr-02  1.29    Ml     added C_COMP_METROWERKS_MGT5100
|                           added C_COMP_METROWERKS_DSP56F80X
| 13-May-02  1.30    LS     MEMORY_HUGE added for C_COMP_TASKING_C16X
| 21-May-02  1.31    Ml     canbittype for HC12 is now unsigned short
| 10-Jul-02  1.32    Ml     canbittype for HC12 changed to unsigned char
| 16-Jul-02  1.33a   Fz     canbittype for V850 changed to unsigend int
|                           _c_bits32 added  
| 31-Jul-02          Ts     added C_COMP_HEW_SH70XX_HCAN2
| 31-Jul-02  1.33    Ht     _c_bits16 added for C_CPUTYPE_BITORDER_MSB2LSB
| 31-Jul-02  1.34    Si     pc-lint comments for 78K0 changed
| 02-Aug-02  1.33    Sf     ESCAN00003192  Memory qualifier for M16C changed
| 08-Aug-02  1.34    Zw     ESCAN00003456  added STmicro ST7 (beCAN) / Hiware
| 18-Aug-02          Pet    ESCAN00003530  delete keyword near for HC08
| 06-Sep-02  1.35    Zw     ESCAN00003688: MEMORY_NEAR defined to nothing for ST7_beCAN
| 09-Sep-02  1.36    Bs     controller OKI MSM9225B (C_COMP_GHS_ARM7TM) added (needed for FBL)
| 10-Sep-02  1.37    Ds     added C_COMP_COSMIC_ST7_BECAN
|                           and   C_COMP_HIWARE_ST7_BECAN
| 13-Sep-02  1.38    Ht     rework the module
| 17-Sep-02  1.39    Stu    add the C_COMP_NEC_78K0
| 17-Sep-02  1.40    Vg     ESCAN00003614 added __declspec() to place const 
|                           variables into ROM for Metrowerks
| 18-Sep-02  1.41    Stu    added C_COMP_NEC_78K0
| 07-Oct-02  1.42    dH     added C_COMP_GAIO_SH705X
| 11-Oct-02  1.43    dH     added C_COMP_FUJITSU_16LX_HL
| 14-Oct-02  1.44    Ml     changed vbittype for MGT5100 into unsigned short
| 14-Oct-02  1.45    Stu    changed vbittype for 78k0 into unsigned char
| 18-Oct-02  1.46    Pl     added C_COMP_TASKING_ST10_CCAN 
|                           added C_COMP_ARM_ST30_CCAN 
| 30-Oct-02  1.47    Ml     added C_COMP_ARM_470 and C_COMP_TI_470
| 06-Nov-02  1.48    Wr     added C_COMP_NATIONAL_CR16 
| 07-Nov-02  1.49    RAP    added C_COMP_DIABDATA_MPC823
|                    RAP    added C_COMP_GHS_STARFISH
| 14-Nov-02  1.50    An     corrected the banking defines for Cosmic and Hiware
| 27-Nov-02  1.50    Pl     added C_COMP_FUJITSU_FR50
| 02-Dec-02  1.51    Si     MEMORY_NEAR changed for C_COMP_NEC_78K0
| 11-Dec-02          Pet    added C_COMP_IAR_CEVF
| 18-Dec-02  1.52    Si     added C_COMP_NEC_78K0
| 04-Jan-03          Et     added memory qualifier for C_COMP_IAR_CEVF
| 22-Jan-03          Ap     added C_COMP_ARM_EASYCAN
| 28-Jan-03  1.53    Pl     added C_COMP_KEIL_ST10_CCAN
|                           delete C_COMP_ARM_ARM7STM
| 03-Apr-04  1.54    To     added C_COMP_METROWERKS_DSP5683X
|                    ZW     canbittype for CEVG is now unsigned char
|                    Hp     Add MEMORY_HUGE for XC16x
|                    Fz     added  C_COMP_IAR_CR16 and C_COMP_NATIONAL_CR16 changed
|                    Ml     added  C_COMP_TI_TMS320
| 2003-05-13 1.60    Ht     support V_MEMROM0
| 2003-05-14 1.61    Tri    added V_MEMROM0 definition for MGT5100
| 2003-05-15 1.62    Pl     added C_COMP_FUJITSU_FR60_CCAN
| 2003-05-20 1.63    WM     added near/far memory defines for C_COMP_HIWARE_12
| 2003-06-11 1.64    CB     MEMORY_HUGE added for C_COMP_TASKING_ST10_CCAN    
| 2003-06-18 1.65    Bir    added C_COMP_MICROCHIP_DSPIC30
| 2003-07-08 1.66    Bir    no local lint command
| 2003-08-15 1.67    Rr     changed MEMORY_FAR for M32C
| 2003-08-18 1.68    BWR    added support for MAC710X
| 2003-09-02 1.69    BWR    added support for MC332 with external Intel 82527 
| 2003-09-09 1.70    Bir    added C_COMP_TASKING_TRICORE_MULTICAN & C_COMP_GNU_TRICORE_MULTICAN
| 2003-10-30 1.71    RAP    added C_COMP_MICROCHIP_PIC18
| 2003-11-13 2.00    Ht     memory qualifier changed to new definition
| 2004-01-08 2.01    BWR    added support for MPC55XX 
| 2004-01-16 2.02    Ml     added cast macros
| 2004-01-22 2.03    dH     added C_COMP_HEW_SH2_HCAN1 and C_COMP_HEW_H8S_HCAN1
| 2004-02-13 2.04    WM     Added banking support for C_COMP_IAR_12
| 2004-02-18 2.05    RAP    Update for C_COMP_MICROCHIP_PIC18
| 2004-03-12 2.06    Ml     changed canbittype for TMS470
| 2004-03-13 2.07    dH     added C_COMP_HEW_H8TINY
| 2004-04-20 2.08    dH     added C_COMP_HEW_H8SX_HCAN1
| 2004-04-08 2.09    Rna    Memoryclassifier V_MEMROM0 and MEMORY_ROM for Metrowerks PPC changed
| 2004-05-14 2.10    Ms     added Release Version define
|                           added include for vstdlib.h
| 2004-05-18 2.11    Ml     changed plattform check to work in any case (NO_ELSE)
|                    Ml     added V_NULL
| 2004-06-17 2.12    Ms     changed C_COMP_SUPPORTED_PLATTFORM -> V_COMP_SUPPORTED_PLATTFORM
| 2004-06-26 2.13    RAP    added C_COMP_GHS_SJA2020
| 2004-06-30 2.14    Ml     added C_COMP_COSMIC_MCS12X_MSCAN12
| 2004-08-17 2.15    Pl     Memoryclassifier V_MEMROM0/1/2 for the C_COMP_TOSHIBA_TLC900 changed
| 2004-08-31 2.16    Ml     changed bitfieldtype for MCS12X
| 2004-09-08 2.17    RAP    changed vbittype for C_COMP_GHS_SJA2020
| 2004-09-12 2.18    BWR    added C_COMP_GHS_PPC
| 2004-09-20 2.19    Ces    added C_COMP_GHS_ST30_CCAN
| 2004-09-27 2.20    Ms     -ESCAN00009636: Naming Conventions
| 2004-09-28 2.21    Bir    changed bitfieldtype for TriCore MultiCAN
| 2004-09-30 2.22    Ht     Review
| 2004-10-06 2.23    Ml     Added C_COMP_MTRWRKS_MCS12X_MSCAN12  
| 2004-10-27 2.24    Ml     changed V_ENABLE_VSTDLIB -> VGEN_ENABLE_VSTDLIB
| 2004-10-29 2.25    Pl     Added C_COMP_GHS_TX19
| 2004-11-05 2.26    Ml     Added C_COMP_COSMIC_MCS12X_MSCAN12 and C_COMP_COSMIC_MCS12_MSCAN12
| 2004-11-08 2.27    Et     support compiler option -fNP (C_COMP_MITSUBISHI_M32C)
| 2004-11-10 2.28    Ml     Added compatibility for VStdLib
| 2004-11-15 2.29    dH     new memoryclassifier for C_COMP_FUJITSU_16LX/C_COMP_FUJITSU_16LX_HL
| 2004-11-15 2.30    Ms     ESCAN00010228: Support C_COMP specific V_NULL definition
| 2004-11-19 2.31    Ml     bitfields for TMS470 are now int
|                    Ths    ESCAN00010435: Due to compatibility V_DEF_VERSION added
| 2005-01-31 2.32    Ml     Added C_COMP_IAR_TMS430_SCCHECC
| 2005-02-09 2.33    Ht     support V_NULL for C_COMP_KEIL_C5X5C
| 2005-03-10 2.34    Ces    Memory qualifier MEMORY_SADDR and MEMORY_NEAR for IAR 78K0 compiler
| 2005-03-22 2.35    Pl     support V_NULL for C_COMP_TASKING_ST10_CCAN
| 2005-03-22 2.36    Ces    support C_COMP_IAR_78K0_AFCAN
|                           support V_NULL for Tasking C16x/ST10, Mitsubishi M16C, IAR 78K0,
|                           Metrowerks DSP5683x and GreenHills ST30
| 2005-03-24 2.37    Krt    Set cast macros for M32C controller, to avoid compiler warnings
|                    Bir    support V_NULL for C_COMP_TASKING_C16X, C_COMP_TASKING_XC16X, C_COMP_GNU_TRICORE_MULTICAN
|                    Ces    MEMORY_NEAR corrections for IAR 78K0 AFCAN
| 2005-06-17 2.38    Ht     remove duplicated compiler switch
|                    dH     added C_COMP_HEW_SH2_RCAN
|                    Pl     added C_COMP_GNU_ST10_CCAN
|                    Ds     Added support for ADI Blackfin (BF5xx)
|                    Ml     Added QNX platforms
|                    Fz     MEMORY_HUGE changed for V85X IAR compiler in case tiny memory model
|                    Ht     default definition of NULL
| 2005-06-20 2.39    BWR    Added support for MAC7100 IAR compiler
|                    dH     changed bittype for C_COMP_HEW_SH2_RCAN to unsigned char
| 2005-08-24 2.40    Rna    position for NULL definitions moved to prevent redefinitions for HC12 cosmic (string.h)
| 2005-10-05 2.41    Ces    adaptions for IAR compiler M16C
| 2005-10-14 2.42    Fn     added C_COMP_IAR_AVR_CANARY
|                    Ces    corrections for C_COMP_IAR_M16C
|                    Ces    added C_COMP_IAR_M32C
|                    Ces    added V_MEMROM3 for C_COMP_MITSUBISHI_M16C
| 2005-10-25 2.43    Ces    IAR M32C: MEMORY_ROM is always far const
| 2005-12-02 2.44    dH     added C_COMP_HEW_H8S_RCAN
|                    Fn     added C_COMP_MICROCHIP_PIC18 for V_NULL
|                    Ht     V_COMP_SUPPORTED_PLATTFORM changed to V_DEF_SUPPORTED_PLATFORM 
|                    Pl     added C_COMP_MATSUSHITA_MN103S_CCAN
|                    Svh    added C_COMP_TOSHIBA_TLCS870
|                    Ces    changed compiler version check of IAR M16C and IAR M32C
| 2005-12-20 2.45    Ml     Added C_COMP_METROWERKS_MGT5X00
|                    Ces    changed MEMORY_NORMAL for IAR M16C and IAR M32C
| 2006-01-27 2.46    Ml     ESCAN00014816: Added cast defines for MCS12x with comsic
|                    Ml     ESCAN00015045: Added support for constants in global pages
|                    Ml     Added C_COMP_MTRWRKS_MPC5X00
|                    Svh    Added C_COMP_ARM_ADUC703X
| 2006-02-08 2.47    Pl     Added C_COMP_IAR_ML67Q25XX_CCAN
| 2006-02-09         Ml     Changed check for XGate compiler
| 2006-02-10 2.48    Ces    Added #define V_NULL for MITSUBISHI M32C and MITSUBISHI M32R
| 2006-02-20 2.49    Ml     Changes for dependency builder to accept XGate compiler specific preprocessor
| 2006-03-28 2.50    Ard    Added C_COMP_ARM_OMAP
|                    Pl     Added C_COMP_TOSHIBA_TLCS900
|                    Svh    Added C_COMP_HPINFOTECH_AVR_CANARY
| 2006-04-27 2.51    dH     added C_COMP_MATSUSHITA_MN101E_CCAN
|                    Ap     added C_COMP_HITECH_PIC18
|                    Fn     modifications for C_COMP_MICROCHIP_PIC18
|                    Ces    Added C_COMP_GHS_TX49 and C_COMP_NEC_78K0_AFCAN
| 2006-05-02 2.52    Ces    Change MEMORY_NEAR and MEMORY_SADDR for C_COMP_NEC_78K0_AFCAN
|                    Svh    Added C_COMP_IAR_ADUC703X
| 2006-05-19 2.53    Ces    Change MEMORY_NEAR for C_COMP_NEC_78K0_AFCAN
|                    Ces    Change define V_NULL for C_COMP_MITSUBISHI_M32R
| 2006-08-03 2.54    Her    Added type cast for C_COMP_: COSMIC_08/NEC_78K0_AFCAN/COSMIC_MCS12X_MSCAN12
|                    Fn     Added C_COMP_MICROCHIP_DSPIC33
|                    Ap     Added C_COMP_MTRWRKS_MCS08_MSCAN and C_COMP_COSMIC_MCS08_MSCAN
|                    BWR    Added C_COMP_GAIO_MPC55XX 
|                    Pl     Added C_COMP_FUJITSU_16FX_CCAN
| 2006-08-04 2.55    Ces    Added C_COMP_GHS_LPC2XXX
| 2006-08-09 2.56    Svh    Added V_MEMRAM1_NEAR for C_COMP_NEC_78K0
| 2006-08-13 2.57    Ml     Changed bitfield type for C_COMP_COSMIC_MCS08_MSCAN
|                    Pl     Added C_COMP_ARM_AVCCORE1_CCAN  
| 2006-08-30 2.58    Wr     Added C_COMP_GNU_VR55XX_AFCAN
|            2.58    Ml     Added C_COMP_DIABDATA_MPC5X00_MSCAN
| 2006-09-22 2.59    swk    Added C_COMP_KEIL_ST10_CCAN
|                    Ml     Changed bitfield type for C_COMP_COSMIC_MCS08_MSCAN back to vuint8
| 2006-10-23 2.60    BWR    Added C_COMP_GNU_MICROBLAZE_LOGICORECAN
|                    Ard    Added C_COMP_GHS_MAC710X
| 2006-10-23 2.61    Bir    Added C_COMP_TASKING_XC2000_MULTICAN
| 2006-11-14         Ml     Added function near/far qualifier for platform MCS12X
| 2006-11-20         BWR    Added C_COMP_METROWERKS_MPC55XX_FLEXCAN
|                           Added C_COMP_DIABDATA_MCORE_FLEXCAN
| 2006-11-20         Bir    changes for C_COMP_TASKING_XC2000_MULTICAN
| 2006-12-14         Pl     Added C_COMP_TI_TMS470_DCAN
| 2007-01-10         Bir    changes for C_COMP_TASKING_XC2000_MULTICAN
| 2007-01-11         Ces    Added C_COMP_IAR_MCS12_MSCAN12
| 2007-02-01 2.62    Svh    Added C_COMP_FUJITSU_8FX
| 2007-02-19 2.63    Ces    Added C_COMP_GHS_SAF7780_PELICAN
|                    Ces    Changed MEMORY_NORMAL for C_COMP_MITSUBISHI_M32C
| 2007-06-21 2.64    Ces    Changed MEMORY_NORMAL for C_COMP_MITSUBISHI_M16C
|                    Fn     Added C_COMP_IAR_R32C
|                    BWR    Added C_COMP_DIABDATA_MCF_FLEXCAN
|                    Awh    Added C_COMP_KEIL_XC16X 
|                    Ou     Changed vbittype for C_COMP_MTRWRKS_MCS12X_MSCAN12 to unsigned char, additionally disabled warning C1106 for this compiler (see #pragma MESSAGE DISABLE C1106)
| 2007-09-07 2.65    Ou     Changed back vbittype for C_COMP_MTRWRKS_MCS12X_MSCAN12 to unsigned int
|                    Ard    Added C_COMP_GHS_TMS470
| 2007-09-28 2.66    Fn     Added C_COMP_COSMIC_ST79_BECAN3
|                    Ces    Added V_MEMROMx_NEAR and V_MEMROMx_FAR for C_COMP_IAR_M16C
|                           Added V_MEMROMx_NEAR and V_MEMROMx_FAR for C_COMP_IAR_M32C
|                           Use predefined compiler macros __VX__ and _C166 for C_COMP_TASKING_XC2000_MULTICAN
| 2007-10-24 2.67    Fn     Changed C_COMP_COSMIC_ST79_BECAN3 to C_COMP_COSMIC_STM8A_BECAN3
|                    Fn     Added C_COMP_RENESAS_R32C
| 2007-11-09 2.68    Wr     Added C_COMP_KEIL_SLC8051
| 2007-11-14 2.69    Svh    Added C_COMP_KEIL_ADUC703X
| 2007-11-27 2.70    Fn     Adapted rom qualifier for: C_COMP_RENESAS_R32C, C_COMP_IAR_R32C and C_COMP_MICROCHIP_DSPIC33
|                    Ml     Added memory mapping defines for C_COMP_MTRWRKS_MCS12X_MSCAN12
| 2007-12-03 2.71    Ard    Added C_COMP_MICROSOFT_TMS320ARM
| 2008-01-14 2.72    Ou     Added memory mapping defines for C_COMP_MTRWRKS_MCS08_MSCAN and C_COMP_COSMIC_MCS08_MSCAN
|                    Ces    Added C_COMP_GHS_MPC55XX and C_COMP_GHS_MPC55XX_FLEXCAN2
|                           Added C_COMP_GAIO_MPC55XX_FLEXCAN2
|                           Added C_COMP_DIABDATA_MPC55XX_FLEXCAN2
|                           Changed memory qualifier for IAR M16C and IAR M32C
| 2008-02-19 2.73    Ces    Corrected V_NULL for DIABDATA_MPC55XX
| 2008-03-05 2.74    Pl     Added C_COMP_GNU_NIOS_DCAN
| 2008-03-12         Fn     Added V_MEMROM2_FAR and V_MEMROM2_NEAR for C_COMP_IAR_AVR_CANARY
| 2008-04-18         Ap     Added C_COMP_GNU_AVR_CANARY
| 2008-05-05 2.75    Bir    Possibility to change V_MEMROM2 for XC2000 (user config)
| 2008-05-05 2.76    Ou     Change the behavior for V_MEMROM3 on MCS12X (relevant just for Cosmic compiler, global constants feature)
| 2008-05-06 2.77    Ces    Changed V_MEMRAM2_FAR for IAR compiler M16C/R8C
|                           Added P_MEM_ROM for IAR compiler M16C
|                    Ap     Added C_COMP_IAR_78K0R
| 2008-07-24 2.78    Ht     Memory qualifier for C_COMP_COSMIC_STM8A_BECAN3 added
| 2008-08-27 2.79    Ces    Adapt memory qualifier for C_COMP_MITSUBISHI_M16C and C_COMP_MITSUBISHI_M32C
| 2008-09-18 2.80    Ard    Added C_COMP_QCC_TMS320ARM
| 2008-10-15 2.81    Bir    Added C_COMP_GHS_TRICORE_MULTICAN
|                    BWR    Adapt memory qualifier for C_COMP_GNU_MPC5X00_MSCAN
| 2008-11-14 2.82    Pl     Added C_COMP_GNU_MB86R0X_CCAN
|                    Ou     V_MEMROMx have the default behavior for C_COMP_MICROCHIP_DSPIC33
| 2008-11-21 2.83    Ces    Added C_COMP_GNU_IMX_FLEXCAN2
|                           Added V_MEMROM2 for C_COMP_MITSUBISHI_M32C
| 2009-01-19 2.84    Ou     Change the behavior of data pointer buffers in order to meet the global data expectations in case of C_COMP_COSMIC_MCS12X_MSCAN12
|                           Change the default behavior for V_MEMRAM1_FAR and V_MEMRAM3_FAR in case of C_COMP_COSMIC_MCS12X_MSCAN12
|                    Tvi    Added C_COMP_IAR_M16C_RCAN2 and C_COMP_RENESAS_M16C_RCAN2
| 2009-01-23 2.85    Ou     Adjust the behavior of V_MEMRAM1_FAR and V_MEMRAM3_FAR in case of C_COMP_COSMIC_MCS12X_MSCAN12 in order to have an unified behavior
| 2009-01-29 2.86    Pl     For the TI_TMS470_DCAN changed vuint32 from unsigned long to unsigned int and vsint32 int from signed long to signed int
|                           Added C_COMP_GNU_ST30_CCAN
| 2009-02-18         Ou     Added C_COMP_MTRWRKS_MPC5X00_MSCAN
| 2009-03-19 2.87    Kk     Added C_COMP_GAIO_SH2_RCAN
|                    Pl     Some V_MEMROM and V_MEMRAM defines for the C_COMP_FUJITSU_16FX_CCAN added ( only in the case VGEN_ENABLE_CANFBL is defined )
| 2009-03-25 2.88    Aj     Added C_COMP_ARM_TCC800X_CCAN
| 2009-07-08 2.89    Bir    Added Compiler abstraction like ASR
|                    Ou     Added C_COMP_KEIL_PSOC3_CANMODULE3
|                    Ces    Added C_COMP_METROWERKS_MPC55XX and C_COMP_METROWERKS_MPC55XX_FLEXCAN2
|                    Pl     For the TI_TMS470_DCAN changed back vuint32 from unsigned int to unsigned long and vsint32 from signed int to signed long
|                           Reason is to be compatible with TI_TMS470 and with Platform_Types.h
| 2009-07-08 2.90    Bir    change Compiler abstraction "V_DEF_P2SFR_CAN"
|                    Ou     Rework the V_MEMROMx and V_MEMRAMx for C_COMP_KEIL_PSOC3_CANMODULE3
|                    Seg    Added C_COMP_ARM_TMS470_DCAN
|                    Ou     Added C_COMP_QCC_MPC5X00_MSCAN
| 2009-09-03 2.91    Bir    Added C_COMP_IAR_AVR32_CANIF
|                    Kk     Added C_COMP_RENESAS_SH4_RCAN
| 2009-09-04 2.92    Tvi    Added C_COMP_GHS_V85X_FCN
| 2009-10-06 2.93    Tvi    Added C_COMP_GHS_SH4_RCAN2
| 2009-10-16 2.94    Ou,Ht  Fixed V_NULL for C_COMP_KEIL_PSOC3_CANMODULE3, C_COMP_KEIL_C5X5C and
|                           C_COMP_KEIL_SLC8051
| 2009-10-27 2.95    Ou     Map the reentrant keyword to C_API_3 in case of C_COMP_KEIL_PSOC3_CANMODULE3
| 2009-10-30 2.96    Rna    Support C_COMP_ARM_STM32_BXCAN
| 2009-11-10 2.97    Ht     ESCAN00039030: Support V_MEMRAM2_FAR for XC2000 Tasking
|                    Seg    Support C_COMP_GNU_TX49
| 2009-11-20 2.98    Tvi    ESCAN00039020: Renesas: support "-fansi" option
|                    Ou     Fixed the standard memory qualifier definitions (vuintx/ vsintx) in combination with CAN-Driver for ASR
| 2009-11-23 2.98.01 Ht     correct COMMON_VDEF_RELEASE_VERSION 
| 2010-02-03 2.99    Tvi    ESCAN00039371: [M16C/R8C with RENESAS]: Warnings about incompatible pointer types for Compiler versions >= V5.45
|                    Ht     Support C_COMP_KEIL_SJA2020
| 2010-02-03 3.00.00 Ht     change version number 
| 2010-03-02 3.01.00 Ou     Rework the V_MEMROMx and V_MEMRAMx for C_COMP_IAR_78K0R
|                    vadaba Added V_MEMROM0 to place const variables into ROM for C_COMP_METROWERKS_MPC55XX_FLEXCAN2
| 2010-03-10 3.02.00 Tvi    ESCAN00041468: [SH4Rcan2 w. GHS] "-Ospace" leads to a runtime exception due to incorrect bitfield access
|                    Kk     Added C_COMP_QCC_SH4_RCAN
|                    Kk     Added C_COMP_IAR_SH2_RCAN
| 2010-05-12 3.03.00 Pl     Added C_COMP_QCC_MB86R0X_CCAN
|                    Ces    Support C_COMP_GNU_MPC55XX and C_COMP_GNU_MPC55XX_FLEXCAN2 
| 2010-06-09 3.04.00 Tvi    Added C_COMP_NEC_78K0R
| 2010-07-01 3.05.00 Ht     Added support of MEMORY_HUGE for C_COMP_KEIL_C16X
| 2010-07-12 3.06.00 Ces    Support C_COMP_GHS_IMX_FLEXCAN2
|                    Tvi    ESCAN00044064: [R32C with RENESAS]: Warnings about incompatible pointer types for Compiler versions >= V1.02 r00
| 2010-09-06 3.07.00 Ces    ESCAN00044378: added check for V_NULL definiton if default is not used
|                    Tvi    Misra warning due to wrong characters in history removed
|                    Kk     Added C_COMP_ARM_TRITON_AFCAN
|                    Ap     Added C_PROCESSOR_R8C_XX to distinguish different derivatives 
| 2010-10-01 3.08.00 Tvi    Added C_COMP_RENESAS_V85X_FCN
| 2010-10-17 3.09.00 Bir    Added C_COMP_KEIL_XC800
| 2010-12-13 3.10.00 Tvi    Added C_COMP_RENESAS_78K0R
| 2011-01-28 3.11.00 Ht     M16C Compiler switch for Organi added
|                           Added C_COMP_GHS_SH2_RCAN
|                    Tvi    Changed V_MEMROM1 for C_COMP_RENESAS_78K0R when memory model MEDIUM is used
|                    Rna    Support TMS320(canbedded) with Geny
| 2011-02-25 3.12.00 Ces    Added C_COMP_ARM_TX03_TXCAN
|                    Pl     Added C_COMP_FUJITSU_FR81_CCAN
|                    Tkr    Added C_COMP_GHS_SH2_RCAN2A
| 2011-04-08 3.13.00 Ou     Added C_COMP_IAR_MCS12X_MSCAN12
|                    Tvi    Support C_PROCESSOR_R8C again (removed in 3.07.00)
|                    Aj     Added C_COMP_RENESAS_V85X_AFCAN
| 2011-05-20 3.14.00 Tvi    Added C_COMP_IAR_V85X_FCN
|                    Was    Added C_COMP_TI_TMS320C64X_HECCSCC
| 2011-05-31 3.15.00 Aj     Added C_COMP_GNU_SH2_RCAN
| 2011-07-11 3.16.00 Ht     replace V_NONE with V_STORAGE_NONE in case of V_CPU_TMS320ARM
| 2011-08-08 3.17.00 Pl     Added C_COMP_GHS_FCR4_CCAN
|                    Eta    Added C_COMP_IAR_ADUCM33X
| 2011-09-26 3.18.00 Aj     Added C_COMP_HEW_SH2_RCAN2
| 2011-11-24 3.19.00 Aj     Added C_COMP_ARM_AVNA_CCAN
| 2012-01-12 3.20.00 Rse    Added C_COMP_QCC_IMX_FLEXCAN2, C_COMP_GNU_IMX_FLEXCAN3, C_COMP_QCC_IMX_FLEXCAN3, C_COMP_GHS_IMX_FLEXCAN3
| 2012-02-15 3.21.00 Aj     Added C_COMP_KEIL_FM3_CCAN
|                    Ht     Header changed
|                           remove C_COMP_MCP18_PIC_INT (old driver version)
|                    Tvi    Added C_COMP_RENESAS_SH4_RCAN2
| 2012-02-24 3.22.00 Tvi    Change VEMROM2_NEAR to __near for C_COMP_IAR_78K0R
| 2012-03-23 3.23.00 Ht     Add C_COMP_IAR_RL78_AFCAN
| 2012-03-30 3.24.00 bir    Add CAN_STATIC define for AutoSar4 compatible LL
| 2012-04-18 3.25.00 Seu    Added C_COMP_TASKING_XC800_MULTICAN
| 2012-06-18 3.26.00 Aj     Set vbittype=char for Sh4/Rcan2 in order to support littleendian
| 2012-08-01 3.27.00 Was    Added C_COMP_KEIL_XC2000_MULTICAN
| 2012-08-22 3.28.00 Pl     Added C_COMP_KEIL_SLC8051_CCAN, integration of C_COMP_KEIL_ switches
|                    QPs    Added C_COMP_RENESAS_RL78_AFCAN
| 2012-09-20 3.29.00 Rse    Added C_COMP_GNU_MPC5700_MCAN
| 2012-09-24 3.30.00 Tkr    Added C_COMP_GHS_RH850_RSCAN, C_COMP_HEW_SH2_RSCAN and C_COMP_GHS_SH2_RSCAN
| 2012-10-08 3.30.01 Was    ESCAN00061961: Compiler error: Using of V_MEMROM2_FAR and V_MEMROM2_NEAR leads to an compile error (Keil compiler/ XC2000)
| 2012-11-06 3.31.00 Ht     ESCAN00062762: Remove function memory qualifier for 78K0R and RL78
| 2012-11-08 3.32.00 Pl     Added C_COMP_TI_TMS320ARM_DCAN
| 2012-12-12 3.33.00 Pl     Added C_COMP_QCC_TMS320ARM_DCAN
| 2012-12-18 3.34.00 Rna    Added C_COMP_IAR_STM32_BXCAN
|                    Bmo    Added C_COMP_KEIL_TLE986X
| 2013-03-06 3.35.00 Rse    Added C_COMP_GHS_MPC5700_FLEXCAN3, C_COMP_DIABDATA_MPC5700_FLEXCAN3
|                    Rna    VUINTx_CAST for STM8A with Cosmic added
| 2013-03-26 3.36.00 Tkr    Added C_COMP_RENESAS_RL78_RSCAN
|                    Ht     improve RL78 and 78K0R
| 2013-04-02 3.37.00 Was    Added V_COMP_COSMIC_MCS12Z
| 2013-06-11 3.38.00 Ht     Replace C_COMP_xxx_MPC5700_yyy with V_COMP_xxx_MPC5700
|                           Replace C_COMP_xxx_IMX_yyyy with V_COMP_xxx_IMX
|                           Replace C_COMP_GHS_RH850_RSCAN with V_COMP_GHS_RH850
|                           Replace canbittype by vbittype in this file -> no change of API
|                    Was    Support IAR HCS12 Compiler Version 3.x
| 2013-06-21 3.38.01 Ht     Remove comment
| 2013-07-02 3.39.00 Tkr    Replace C_COMP_IAR_RL78_AFCAN with V_COMP_IAR_RL78
|                    Tkr    merge and adapt RL78 and 78K0R memory qualifier definitions for IAR compiler
|                           Replace C_COMP_RENESAS_RL78_xxx with V_COMP_RENESAS_RL78
| 2013-08-20 3.40.00 Pl     Added V_COMP_ARM_STA8088
|                    Tkr    Added V_COMP_DIABDATA_RH850
|                    Rse    Added V_COMP_GNU_VYBRID
| 2014-04-11 3.41.00 Rse    Added V_COMP_GHS_VYBRID
|                    Was    Added V_COMP_ARM_ZYNQ7000
|                    Rse    Added V_COMP_MICROSOFT_IMX
|                    Rse    Added V_COMP_GHS_IMX
|                    Rse    Added V_COMP_ARM_VYBRID
|                    QPs    Added C_COMP_GNU_STM32_BXCAN
|                    Rna    Added V_COMP_DIAB_TRICORE
|****************************************************************************/



#ifndef  V_DEF_H
#define  V_DEF_H

/***************************************************************************/
/* Version                  (abcd: Main version=ab, Sub Version=cd )       */
/***************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Common_Vdef CQComponent : Implementation */
#define COMMON_VDEF_VERSION            0x0341
#define COMMON_VDEF_RELEASE_VERSION    0x00

/* compatibility for IL versions < 3.52 */
#define V_DEF_VERSION                  COMMON_VDEF_VERSION


/***************************************************************************/
/* Supported Systems                                                       */
/***************************************************************************/
#if defined( C_COMP_GNU_TRICORE_MULTICAN )      
    
# define V_DEF_SUPPORTED_PLATFORM
#endif


#if !defined V_DEF_SUPPORTED_PLATFORM
# error "driver not supported or C_COMP_xxx_yyy not defined"
#endif




/***************************************************************************/
/***************************************************************************/
/****  Hardware independent settings  **************************************/
/***************************************************************************/
/***************************************************************************/
/*--- standard memory qualifier definition --------------------------------*/

/* 8-Bit qualifier */
#if !defined( vuint8 ) /* ASR compatibility */
typedef unsigned char  vuint8;
#endif
#define canuint8 vuint8

#if !defined( vsint8 ) /* ASR compatibility */
typedef signed char    vsint8;
#endif
#define cansint8 vsint8

/* 16-Bit qualifier */
#if !defined( vuint16 ) /* ASR compatibility */
typedef unsigned short vuint16;
#endif
#define canuint16 vuint16

#if !defined( vsint16 ) /* ASR compatibility */
typedef signed short   vsint16;
#endif
#define cansint16 vsint16


/* 32-Bit qualifier */
#if !defined( vuint32 ) /* ASR compatibility */
typedef unsigned long  vuint32;
#endif
#define canuint32 vuint32

#if !defined( vsint32 ) /* ASR compatibility */
typedef signed long    vsint32;
#endif
#define cansint32 vsint32



typedef unsigned char *TxDataPtr;              /* ptr to transmission data buffer */
typedef unsigned char *RxDataPtr;              /* ptr to receiving data buffer    */

/***************************************************************************/
/*  Defines                                                                */
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
/****  Hardware/Compiler dependent settings   ******************************/
/***************************************************************************/
/***************************************************************************/

/*  data type according to the CPU type */
#if defined( C_CPUTYPE_8BIT )
/* 8-Bit qualifier */
# ifndef vuintx
#  define vuintx vuint8
# endif
# ifndef vsintx
#  define vsintx vsint8
# endif
#else
# if defined( C_CPUTYPE_16BIT )
/* 16-Bit qualifier */
#  ifndef vuintx
#   define vuintx vuint16
#  endif
#  ifndef vsintx
#   define vsintx vsint16
#  endif
# else
#  if defined( C_CPUTYPE_32BIT )
/* 32-Bit qualifier */
#   ifndef vuintx
#    define vuintx vuint32
#   endif
#   ifndef vsintx
#    define vsintx vsint32
#   endif
#  endif
# endif
#endif


/* qualifier for bitfield definition */

typedef unsigned int     vbittype;
#define canbittype       vbittype



#if defined( C_SUPPORT_MIXED_CAN_LIN )
  /* support combination of "old" CAN driver and "new" LIN driver */
#else
/* Structure for bit accessed memory.           */
/* The bit-order is hardware/compiler dependent */
#  if defined( C_CPUTYPE_BITORDER_LSB2MSB )
struct _c_bits8
{
  vbittype  b0:1;  /* LSB-Bits (lower adr!) */
  vbittype  b1:1;
  vbittype  b2:1;
  vbittype  b3:1;
  vbittype  b4:1;
  vbittype  b5:1;
  vbittype  b6:1;
  vbittype  b7:1;  /* MSB-Bits (higher address) unused */
 };

struct _c_bits16 
{
  vbittype  b0:1;  /* lower adr */
  vbittype  b1:1;
  vbittype  b2:1;
  vbittype  b3:1;
  vbittype  b4:1;
  vbittype  b5:1;
  vbittype  b6:1;
  vbittype  b7:1;

  vbittype  b10:1; /* higher adr */
  vbittype  b11:1;
  vbittype  b12:1;
  vbittype  b13:1;
  vbittype  b14:1;
  vbittype  b15:1;
  vbittype  b16:1;
  vbittype  b17:1;
};

struct _c_bits32 
{
  vbittype  b0:1;  /* lower adr */
  vbittype  b1:1;
  vbittype  b2:1;
  vbittype  b3:1;
  vbittype  b4:1;
  vbittype  b5:1;
  vbittype  b6:1;
  vbittype  b7:1;

  vbittype  b10:1; /* mid low adr */
  vbittype  b11:1;
  vbittype  b12:1;
  vbittype  b13:1;
  vbittype  b14:1;
  vbittype  b15:1;
  vbittype  b16:1;
  vbittype  b17:1;

  vbittype  b20:1; /* mid high adr */
  vbittype  b21:1;
  vbittype  b22:1;
  vbittype  b23:1;
  vbittype  b24:1;
  vbittype  b25:1;
  vbittype  b26:1;
  vbittype  b27:1;

  vbittype  b30:1; /* higher adr */
  vbittype  b31:1;
  vbittype  b32:1;
  vbittype  b33:1;
  vbittype  b34:1;
  vbittype  b35:1;
  vbittype  b36:1;
  vbittype  b37:1;
};

# else /* MSB2LSB */
#  if defined( C_CPUTYPE_BITORDER_MSB2LSB )
struct _c_bits8         
{
  vbittype  b7:1;  /* MSB-Bits (Higher addr!) */
  vbittype  b6:1;
  vbittype  b5:1;
  vbittype  b4:1;
  vbittype  b3:1;
  vbittype  b2:1;
  vbittype  b1:1;
  vbittype  b0:1;  /* LSB-Bits (higher address) unused */
};

struct _c_bits16 
{
  vbittype  b7:1;   /* lower adr */
  vbittype  b6:1;
  vbittype  b5:1;
  vbittype  b4:1;
  vbittype  b3:1;
  vbittype  b2:1;
  vbittype  b1:1;
  vbittype  b0:1;

  vbittype  b17:1;  /* higher adr */
  vbittype  b16:1;
  vbittype  b15:1;
  vbittype  b14:1;
  vbittype  b13:1;
  vbittype  b12:1;
  vbittype  b11:1;
  vbittype  b10:1;
};


struct _c_bits32 
{
  vbittype  b7:1;   /* lower adr */
  vbittype  b6:1;
  vbittype  b5:1;
  vbittype  b4:1;
  vbittype  b3:1;
  vbittype  b2:1;
  vbittype  b1:1;
  vbittype  b0:1;

  vbittype  b17:1;  /* mid low adr */
  vbittype  b16:1;
  vbittype  b15:1;
  vbittype  b14:1;
  vbittype  b13:1;
  vbittype  b12:1;
  vbittype  b11:1;
  vbittype  b10:1;

  vbittype  b27:1;  /* mid high adr */
  vbittype  b26:1;
  vbittype  b25:1;
  vbittype  b24:1;
  vbittype  b23:1;
  vbittype  b22:1;
  vbittype  b21:1;
  vbittype  b20:1;

  vbittype  b37:1;  /* higher adr */
  vbittype  b36:1;
  vbittype  b35:1;
  vbittype  b34:1;
  vbittype  b33:1;
  vbittype  b32:1;
  vbittype  b31:1;
  vbittype  b30:1;
};
#  else
#  error "Bitorder unknown: C_CPUTYPE_BITORDER_MSB2LSB or C_CPUTYPE_BITORDER_LSB2MSB has to be defined"
#  endif /* C_CPUTYPE_BITORDER_MSB2LSB */
# endif  /* C_CPUTYPE_BITORDER_LSB2MSB */
#endif




/***************************************************************************/
/* Memory qualifier                                                        */
/***************************************************************************/










#if defined ( VGEN_ENABLE_CANFBL ) 
#endif

























#ifndef MEMORY_HUGE
#  define MEMORY_HUGE               /* no entry                         */
#endif








/* *********************** default defines - used to store permanent data **************************************** */
#ifndef V_MEMROM0
# define V_MEMROM0                  /* addition qualifier data access in ROM  */
#endif

#ifndef V_MEMROM1_NEAR
# define V_MEMROM1_NEAR             /* fast data access in ROM */
#endif

#ifndef V_MEMROM1
# define V_MEMROM1                 /* fast data access in ROM */
#endif

#ifndef V_MEMROM1_FAR
# define V_MEMROM1_FAR             /* slow addressing mode in ROM */
#endif


#ifndef MEMORY_ROM_NEAR
# ifndef V_MEMROM2_NEAR
#  define V_MEMROM2_NEAR   const    /* fast data access in ROM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM_NEAR   V_MEMROM2_NEAR
#else
# define V_MEMROM2_NEAR    MEMORY_ROM_NEAR
#endif

#ifndef MEMORY_ROM
# ifndef V_MEMROM2
#  define V_MEMROM2        const    /* fast data access in ROM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM        V_MEMROM2       
#else
# define V_MEMROM2         MEMORY_ROM
#endif

#ifndef MEMORY_ROM_FAR
# ifndef V_MEMROM2_FAR
#  define V_MEMROM2_FAR    const    /* slow addressing mode in ROM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM_FAR    V_MEMROM2_FAR
#else
# define V_MEMROM2_FAR     MEMORY_ROM_FAR
#endif

#ifndef V_MEMROM3
# define V_MEMROM3        
#endif


/* *********************** default defines - used to store volatile data **************************************** */
#ifndef V_MEMRAM0
# define V_MEMRAM0                  /* addition qualifier data access in RAM  */
#endif

#ifndef V_MEMRAM1_NEAR
# define V_MEMRAM1_NEAR             /* fast data access in RAM */
#endif

#ifndef V_MEMRAM1
# define V_MEMRAM1                 /* fast data access in RAM */
#endif

#ifndef V_MEMRAM1_FAR
# define V_MEMRAM1_FAR             /* slow addressing mode in RAM */
#endif


#ifndef MEMORY_NEAR
# ifndef V_MEMRAM2_NEAR
#  define V_MEMRAM2_NEAR           /* fast data access in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_NEAR   V_MEMRAM2_NEAR
#else
# define V_MEMRAM2_NEAR    MEMORY_NEAR
#endif

#ifndef MEMORY_NORMAL
# ifndef V_MEMRAM2
#  define V_MEMRAM2                 /* fast data access in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_NORMAL   V_MEMRAM2       
#else
# define V_MEMRAM2           MEMORY_NORMAL
#endif

#ifndef MEMORY_FAR
# ifndef V_MEMRAM2_FAR
#  define V_MEMRAM2_FAR            /* slow addressing mode in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_FAR    V_MEMRAM2_FAR
#else
# define V_MEMRAM2_FAR     MEMORY_FAR
#endif

#ifndef V_MEMRAM3_NEAR
# define V_MEMRAM3_NEAR             /* fast data access in RAM */
#endif

#ifndef V_MEMRAM3
# define V_MEMRAM3                 /* fast data access in RAM */
#endif

#ifndef V_MEMRAM3_FAR
# define V_MEMRAM3_FAR             /* slow addressing mode in RAM */
#endif


/* *********************** default defines - to cast results **************************************************** */
#if !defined(VUINT8_CAST)
# define VUINT8_CAST
#endif 
#if !defined(VSINT8_CAST)
# define VSINT8_CAST
#endif
#if !defined(VUINT16_CAST)
# define VUINT16_CAST
#endif
# if !defined(VSINT16_CAST)
# define VSINT16_CAST
#endif
#if !defined(CANBITTYPE_CAST)
# define CANBITTYPE_CAST
#endif
#if !defined(CANSINTCPUTYPE_CAST)
# define CANSINTCPUTYPE_CAST
#endif
#if !defined(CANUINTCPUTYPE_CAST)
# define CANUINTCPUTYPE_CAST
#endif

/* ************************************************************************* */
/*  Common_VStdLib                                                           */
/* ************************************************************************* */
# if defined (VGEN_ENABLE_VSTDLIB) || defined (V_ENABLE_VSTDLIB)
#  include "vstdlib.h"
# endif

/* ************************************************************************* */
/*  V_NULL Definition                                                        */
/* ************************************************************************* */

#if defined( C_COMP_GNU_TRICORE_MULTICAN )        
# if !defined(V_NULL)    
#  define V_NULL 0
# endif
#endif


#if !defined(V_NULL)
# define V_NULL ((void*)0)
#endif


#ifndef NULL
# define NULL V_NULL
#endif


/*-----------------------------------------------------------------------------------------------*/
#if !defined(V_ENABLE_CAN_ASR_ABSTRACTION) && !defined(V_ENABLE_VSTDLIB_ASR_ABSTRACTION)
# define V_ENABLE_CBD_ABSTRACTION
# define STATIC                                          static /* MSR3 */
# define CAN_STATIC                                      static /* MSR4 */
# define AUTOMATIC
# if !defined(NULL_PTR)
#  define NULL_PTR                                        V_NULL
# endif

#  define V_NONE              /* empty storage used instead of extern, static, volatile... */
#  define V_STORAGE_NONE      /* empty storage used instead of extern, static, volatile... */

# if !defined( C_CALLBACK_1 )
#  define C_CALLBACK_1
# endif
# if !defined( C_CALLBACK_2 )
#  define C_CALLBACK_2
# endif
# if !defined( C_API_1 )
#  define C_API_1
# endif
# if !defined( C_API_2 )
#  define C_API_2
# endif
# if !defined( C_API_3 )
#  define C_API_3
# endif
# define V_DEF_VAR(storage, vartype, memclass)                    V_MEMRAM0 storage V_MEMRAM1 vartype V_MEMRAM2
# define V_DEF_VAR_NEAR(storage, vartype)                         V_MEMRAM0 storage V_MEMRAM1_NEAR vartype V_MEMRAM2_NEAR
# define V_DEF_VAR_FAR(storage, vartype)                          V_MEMRAM0 storage V_MEMRAM1_FAR vartype V_MEMRAM2_FAR
# define V_DEF_VAR_TYPE(storage, vartype)                         typedef storage V_MEMRAM1 vartype V_MEMRAM2
# define V_DEF_P2VAR(storage, ptrtype, memclass, ptrclass)        V_MEMRAM0 storage V_MEMRAM1 ptrtype V_MEMRAM2 *
# define V_DEF_P2VAR_PARA(storage, ptrtype, memclass, ptrclass)   storage V_MEMRAM1 ptrtype V_MEMRAM2 *
# define V_DEF_P2VAR_TYPE(storage, ptrtype, ptrclass)             typedef storage V_MEMRAM1 ptrtype V_MEMRAM2 *
/* platform specific order may be needed for MEMORY_CAN (position RAM1 or RAM2) */
# define V_DEF_P2SFR_CAN(storage, ptrtype, memclass)              V_MEMRAM0 storage V_MEMRAM1 ptrtype MEMORY_CAN *
# define V_DEF_P2SFR_CAN_TYPE(storage, ptrtype)                   typedef storage V_MEMRAM1 ptrtype MEMORY_CAN *
/* --- */
# define V_DEF_CONSTP2VAR(storage, ptrtype, memclass, ptrclass)   V_MEMROM0 storage V_MEMRAM1 ptrtype V_MEMRAM2 V_MEMRAM3 * V_MEMROM1 V_MEMROM2
# define V_DEF_CONST(storage, type, memclass)                     V_MEMROM0 storage V_MEMROM1 type V_MEMROM2
# define V_DEF_CONST_NEAR(storage, type)                          V_MEMROM0 storage V_MEMROM1_NEAR type V_MEMROM2_NEAR
# define V_DEF_CONST_FAR(storage, type)                           V_MEMROM0 storage V_MEMROM1_FAR type V_MEMROM2_FAR
# define V_DEF_CONST_TYPE(storage, type, memclass)                typedef storage V_MEMROM1 type V_MEMROM2
# define V_DEF_P2CONST(storage, ptrtype, memclass, ptrclass)      V_MEMRAM0 storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2
# define V_DEF_P2CONST_PARA(storage, ptrtype, memclass, ptrclass) storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2
# define V_DEF_P2CONST_TYPE(storage, ptrtype, ptrclass)           typedef storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 *
# define V_DEF_CONSTP2CONST(storage, ptrtype, memclass, ptrclass) V_MEMROM0 storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 * V_MEMROM1 V_MEMROM2
# define V_DEF_FUNC(storage, rettype, memclass)                   storage rettype
# define V_DEF_FUNC_API(storage, rettype, memclass)               storage C_API_1 rettype C_API_2
# define V_DEF_FUNC_CBK(storage, rettype, memclass)               storage C_CALLBACK_1 rettype C_CALLBACK_2
# define V_DEF_P2FUNC(storage, rettype, ptrclass, fctname)        storage C_CALLBACK_1 rettype (C_CALLBACK_2 *fctname)
#endif
/*-----------------------------------------------------------------------------------------------*/

#endif /* V_DEF_H */


/* STOPSINGLE_OF_MULTIPLE */
