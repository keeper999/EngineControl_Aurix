
/******************************************************************************/
/*                                                                            */
/* !Layer           :  Services Layer                                         */
/*                                                                            */
/* !Component       :  NvM                                                    */
/* !Description     :  Non Volatile RAM Manager                               */
/*                                                                            */
/* !Module          :  NvM                                                    */
/* !Description     :  Non Volatile RAM Manager                               */
/*                                                                            */
/* !File            :  NvM_Cfg.h                                              */
/*                                                                            */
/* !Scope           :  Public                                                 */
/*                                                                            */
/* !Target          :  Any                                                    */
/*                                                                            */
/* !Vendor          :  Valeo                                                  */
/*                                                                            */
/* Coding language  :  C                                                      */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* all rights reserved                                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/*                                                                            */
/* $Header:   P:/EBx_V46/LDA/REF/modules/NVRAM/Nvm_Cfg.h_v   1.1   19 Sep 2014 17:10:28   wbouach  $/Data/pvcs65/CEE-SW/B01H01067-GroupSwStdDev/archives/02-R&D/02-Project/01-Modules/02-Services/04-NvM/02-Dev/01-SRC_NvM/NvM_Cfg.h-arc   1.7   Aug 11 2008 22:25:40   abazaraa  $
                                                                              */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/*       THIS FILE IS CREATED AUTOMATICALY BY CONFIGURATION TOOLS             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.0    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 26/06/11    */
/* Description: - Initial Revision                                            */
/******************************************************************************/

#ifndef NVM_CFG_H
#define NVM_CFG_H

/*============================================================================*/
/*=== Configuration version information ======================================*/
/*============================================================================*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0032                                  */
/* !Comment : Major version number of the module's configuration.            
              The numbering is vendor specific.                               */
#define NVM_CFG_MAJOR_VERSION               (1U)

/* !Comment : Minor version number of the module's configuration.            
              The numbering is vendor specific.                               */
#define NVM_CFG_MINOR_VERSION               (1U)

/*============================================================================*/
/*=== AUTOSAR Configuration attributes =======================================*/
/*============================================================================*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0067                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0420                                 */


/* !Trace_To        : GSCSW-NVM-SDD-001-0238                                  */
/* !MComment: NVRAM block identifier. It is not used by the NvM source code, 
              it is only used by NvM user                   */

#define NvM_Block_ConfigID ((NvM_BlockIdType)1)

#define NvM_TEST_EEPROM_1 ((NvM_BlockIdType)2)

#define NvM_TEST_EEPROM_2 ((NvM_BlockIdType)3)

#define NvM_SPI_REREAD_FRAMES ((NvM_BlockIdType)4)

#define NvM_EPMSRV ((NvM_BlockIdType)5)

#define NvM_DOWNLOAD ((NvM_BlockIdType)6)

#define NvM_ECRITURES_EEPROM ((NvM_BlockIdType)7)

#define NvM_RESET ((NvM_BlockIdType)8)

#define NvM_EXCEPTION_REGS ((NvM_BlockIdType)9)

#define NvM_TEST_EEPROM_3 ((NvM_BlockIdType)10)

#define NvM_REDPROD_1 ((NvM_BlockIdType)11)

#define NvM_REDPROD_2 ((NvM_BlockIdType)12)

#define NvM_REDPROD_5 ((NvM_BlockIdType)13)

#define NvM_REDPROD_8 ((NvM_BlockIdType)14)

#define NvM_PROD_1_VALEOIDENT ((NvM_BlockIdType)15)

#define NvM_PROD_2_PSAIDENT ((NvM_BlockIdType)16)

#define NvM_PROD_5_CIENUM ((NvM_BlockIdType)17)

#define NvM_PROD_8_TRIMS ((NvM_BlockIdType)18)

#define NvM_EEPROM_VERSION ((NvM_BlockIdType)19)

#define NvM_KNKADPCOR ((NvM_BlockIdType)20)

#define NvM_POSTEQUSRV ((NvM_BlockIdType)21)

#define NvM_SAIMMO_CODE ((NvM_BlockIdType)22)

#define NvM_SAIMMO_ETAT ((NvM_BlockIdType)23)

#define NvM_TELECODAGE ((NvM_BlockIdType)24)

#define NvM_ACCPEM ((NvM_BlockIdType)25)

#define NvM_ACCPLRNPOS ((NvM_BlockIdType)26)

#define NvM_ACQCOT ((NvM_BlockIdType)27)

#define NvM_AFAMGTT_NVRAM_INT8_CONST ((NvM_BlockIdType)28)

#define NvM_AFAT_NVRAM_INT16_CALIB ((NvM_BlockIdType)29)

#define NvM_AFAT_NVRAM_INT32_CALIB ((NvM_BlockIdType)30)

#define NvM_AFAT_NVRAM_INT8_CALIB ((NvM_BlockIdType)31)

#define NvM_AFAT_NVRAM_BOOLEAN_CALIB ((NvM_BlockIdType)32)

#define NvM_AFAT_NVRAM_INT16_CONST ((NvM_BlockIdType)33)

#define NvM_AFAT_NVRAM_INT8_CONST ((NvM_BlockIdType)34)

#define NvM_AFAT_NVRAM_BOOLEAN_CONST ((NvM_BlockIdType)35)

#define NvM_CLCNFISAGAIN ((NvM_BlockIdType)36)

#define NvM_CLUPEDPOSNDIAG ((NvM_BlockIdType)37)

#define NvM_CLUSWTDIAG ((NvM_BlockIdType)38)

#define NvM_COEMSTT_NVRAM_INT16_CONST_1 ((NvM_BlockIdType)39)

#define NvM_COEMSTT_NVRAM_INT32_CONST_1 ((NvM_BlockIdType)40)

#define NvM_COEMSTT_NVRAM_INT8_CONST_1 ((NvM_BlockIdType)41)

#define NvM_COFANCMDDIAG ((NvM_BlockIdType)42)

#define NvM_FHCANF552 ((NvM_BlockIdType)43)

#define NvM_COSTOPSTART_NVRAM_INT16_CONST_1 ((NvM_BlockIdType)44)

#define NvM_COSTOPSTART_NVRAM_INT8_CONST_1 ((NvM_BlockIdType)45)

#define NvM_COSTOPSTART_NVRAM_INT8_CONST_2 ((NvM_BlockIdType)46)

#define NvM_COSTOPSTART_NVRAM_INT8_CONST_3 ((NvM_BlockIdType)47)

#define NvM_COSTOPSTART_NVRAM_BOOLEAN_CONST_1 ((NvM_BlockIdType)48)

#define NvM_COSTOPSTART_NVRAM_BOOLEAN_CONST_2 ((NvM_BlockIdType)49)

#define NvM_CSTRFUCONCESTIM ((NvM_BlockIdType)50)

#define NvM_DCM_MANU ((NvM_BlockIdType)51)

#define NvM_DFWCTL_NVRAM_INT16_CONST ((NvM_BlockIdType)52)

#define NvM_DIAGAIREXTPRES ((NvM_BlockIdType)53)

#define NvM_DSO2SEN ((NvM_BlockIdType)54)

#define NvM_ECUMNG ((NvM_BlockIdType)55)

#define NvM_ENGRUNST ((NvM_BlockIdType)56)

#define NvM_DIVERS_EEP_FIXE ((NvM_BlockIdType)57)

#define NvM_EOMGSL_NVRAM_INT32_CONST ((NvM_BlockIdType)58)

#define NvM_EXMGSLT2_NVRAM_INT16_CONST ((NvM_BlockIdType)59)

#define NvM_FISARFUDET ((NvM_BlockIdType)60)

#define NvM_FISA_NVRAM_INT8_CONST_1 ((NvM_BlockIdType)61)

#define NvM_FLOWMNG ((NvM_BlockIdType)62)

#define NvM_FTPCTL ((NvM_BlockIdType)63)

#define NvM_FUCNS ((NvM_BlockIdType)64)

#define NvM_FULVL ((NvM_BlockIdType)65)

#define NvM_WUC ((NvM_BlockIdType)66)

#define NvM_STATUSOFDTC ((NvM_BlockIdType)67)

#define NvM_INDICOBD ((NvM_BlockIdType)68)

#define NvM_IUPRGENDEN ((NvM_BlockIdType)69)

#define NvM_RC01 ((NvM_BlockIdType)70)

#define NvM_GOBD ((NvM_BlockIdType)71)

#define NvM_IUPRRATIO ((NvM_BlockIdType)72)

#define NvM_MEM1 ((NvM_BlockIdType)73)

#define NvM_MEM2 ((NvM_BlockIdType)74)

#define NvM_MEM3 ((NvM_BlockIdType)75)

#define NvM_MEM4 ((NvM_BlockIdType)76)

#define NvM_MEM5 ((NvM_BlockIdType)77)

#define NvM_MEM6 ((NvM_BlockIdType)78)

#define NvM_MEM7 ((NvM_BlockIdType)79)

#define NvM_MEM8 ((NvM_BlockIdType)80)

#define NvM_MEM9 ((NvM_BlockIdType)81)

#define NvM_MEM10 ((NvM_BlockIdType)82)

#define NvM_MEM11 ((NvM_BlockIdType)83)

#define NvM_MEM12 ((NvM_BlockIdType)84)

#define NvM_MEM13 ((NvM_BlockIdType)85)

#define NvM_MEM14 ((NvM_BlockIdType)86)

#define NvM_MEM15 ((NvM_BlockIdType)87)

#define NvM_MEM16 ((NvM_BlockIdType)88)

#define NvM_MEM17 ((NvM_BlockIdType)89)

#define NvM_MEM18 ((NvM_BlockIdType)90)

#define NvM_MEM19 ((NvM_BlockIdType)91)

#define NvM_MEM20 ((NvM_BlockIdType)92)

#define NvM_MEM21 ((NvM_BlockIdType)93)

#define NvM_MEM22 ((NvM_BlockIdType)94)

#define NvM_MEM23 ((NvM_BlockIdType)95)

#define NvM_MEM24 ((NvM_BlockIdType)96)

#define NvM_MEM25 ((NvM_BlockIdType)97)

#define NvM_MEM26 ((NvM_BlockIdType)98)

#define NvM_MEM27 ((NvM_BlockIdType)99)

#define NvM_MEM28 ((NvM_BlockIdType)100)

#define NvM_MEM29 ((NvM_BlockIdType)101)

#define NvM_MEM30 ((NvM_BlockIdType)102)

#define NvM_MEM31 ((NvM_BlockIdType)103)

#define NvM_MEM32 ((NvM_BlockIdType)104)

#define NvM_MEM33 ((NvM_BlockIdType)105)

#define NvM_MEM34 ((NvM_BlockIdType)106)

#define NvM_MEM35 ((NvM_BlockIdType)107)

#define NvM_MEM36 ((NvM_BlockIdType)108)

#define NvM_MEM37 ((NvM_BlockIdType)109)

#define NvM_MEM38 ((NvM_BlockIdType)110)

#define NvM_MEM39 ((NvM_BlockIdType)111)

#define NvM_MEM40 ((NvM_BlockIdType)112)

#define NvM_GMIL ((NvM_BlockIdType)113)

#define NvM_AASTART_BIDON ((NvM_BlockIdType)114)

#define NvM_COH_PED ((NvM_BlockIdType)115)

#define NvM_SCPOC_PED2 ((NvM_BlockIdType)116)

#define NvM_SCG_PED2 ((NvM_BlockIdType)117)

#define NvM_SCPOC_PED1 ((NvM_BlockIdType)118)

#define NvM_SCG_PED1 ((NvM_BlockIdType)119)

#define NvM_STUCKACCP ((NvM_BlockIdType)120)

#define NvM_SCPACCPSWT ((NvM_BlockIdType)121)

#define NvM_STUCKACCPSWT ((NvM_BlockIdType)122)

#define NvM_SCGACCPSWT ((NvM_BlockIdType)123)

#define NvM_COHACCPSWT ((NvM_BlockIdType)124)

#define NvM_COH_RACCP ((NvM_BlockIdType)125)

#define NvM_GRD_PACMES ((NvM_BlockIdType)126)

#define NvM_HI_PACMES ((NvM_BlockIdType)127)

#define NvM_LO_PACMES ((NvM_BlockIdType)128)

#define NvM_GRD_TCOMES ((NvM_BlockIdType)129)

#define NvM_OC_TCOMES ((NvM_BlockIdType)130)

#define NvM_SCG_TCOMES ((NvM_BlockIdType)131)

#define NvM_SCP_TCOMES ((NvM_BlockIdType)132)

#define NvM_SCG_AIREXTPRESACQ ((NvM_BlockIdType)133)

#define NvM_SCP_AIREXTPRESACQ ((NvM_BlockIdType)134)

#define NvM_SCP_PDSTHRMES ((NvM_BlockIdType)135)

#define NvM_SCG_PDSTHRMES ((NvM_BlockIdType)136)

#define NvM_SCP_PBRKASI ((NvM_BlockIdType)137)

#define NvM_SCG_PBRKASI ((NvM_BlockIdType)138)

#define NvM_GRD_PBRKASI ((NvM_BlockIdType)139)

#define NvM_STALLCOH_PDSTHR ((NvM_BlockIdType)140)

#define NvM_CRKCOH_PDSTHR ((NvM_BlockIdType)141)

#define NvM_STABCOH_PDSTHR ((NvM_BlockIdType)142)

#define NvM_THRCOH_PDSTHR ((NvM_BlockIdType)143)

#define NvM_ORNG_PDSTHR ((NvM_BlockIdType)144)

#define NvM_FLDCOH_PDSTHR ((NvM_BlockIdType)145)

#define NvM_GRD_PDSTHR ((NvM_BlockIdType)146)

#define NvM_MAX_PAIREXT ((NvM_BlockIdType)147)

#define NvM_MIN_PAIREXT ((NvM_BlockIdType)148)

#define NvM_GRD_PAIREXT ((NvM_BlockIdType)149)

#define NvM_GRD_PAIREXTOLD ((NvM_BlockIdType)150)

#define NvM_COH_PBRKASI ((NvM_BlockIdType)151)

#define NvM_SCP_PRELBRKASI ((NvM_BlockIdType)152)

#define NvM_SCG_PRELBRKASI ((NvM_BlockIdType)153)

#define NvM_GRD_PRELBRKASI ((NvM_BlockIdType)154)

#define NvM_BOOST1_PDSTHR ((NvM_BlockIdType)155)

#define NvM_BOOST2_PDSTHR ((NvM_BlockIdType)156)

#define NvM_BOOST3_PDSTHR ((NvM_BlockIdType)157)

#define NvM_BOOST4_PDSTHR ((NvM_BlockIdType)158)

#define NvM_OC_TAIRMES ((NvM_BlockIdType)159)

#define NvM_SCG_TAIRMES ((NvM_BlockIdType)160)

#define NvM_SCP_TAIRMES ((NvM_BlockIdType)161)

#define NvM_GRD_TAIRMES ((NvM_BlockIdType)162)

#define NvM_NEGOFS_TAIRMES ((NvM_BlockIdType)163)

#define NvM_ORNG_TAIRMES ((NvM_BlockIdType)164)

#define NvM_POSOFS_TAIRMES ((NvM_BlockIdType)165)

#define NvM_STALLCOH_TAIRMES ((NvM_BlockIdType)166)

#define NvM_DECELCOH_BRKPED ((NvM_BlockIdType)167)

#define NvM_ACCELCOH_BRKPED ((NvM_BlockIdType)168)

#define NvM_INVCOH_BRKPED ((NvM_BlockIdType)169)

#define NvM_DECELCOH_BRKPEDBVH2P ((NvM_BlockIdType)170)

#define NvM_ACCELCOH_BRKPEDBVH2P ((NvM_BlockIdType)171)

#define NvM_COHBIT7_STDFTOBD ((NvM_BlockIdType)172)

#define NvM_COHBIT4_STDFTOBD ((NvM_BlockIdType)173)

#define NvM_COHBIT3_STDFTOBD ((NvM_BlockIdType)174)

#define NvM_COHBIT2_STDFTOBD ((NvM_BlockIdType)175)

#define NvM_CHKBATTSYS_IBATTMES ((NvM_BlockIdType)176)

#define NvM_CHKBATTSYS_TBATTMES ((NvM_BlockIdType)177)

#define NvM_CHKBATTSYS_UBATTCLC ((NvM_BlockIdType)178)

#define NvM_STFULVLDFT ((NvM_BlockIdType)179)

#define NvM_COH_BMODSPTREQ ((NvM_BlockIdType)180)

#define NvM_COH_STCLUAC ((NvM_BlockIdType)181)

#define NvM_COH_STPWRAC ((NvM_BlockIdType)182)

#define NvM_SCP_UDSLS ((NvM_BlockIdType)183)

#define NvM_OC_UDSLS ((NvM_BlockIdType)184)

#define NvM_SCG_UDSLS ((NvM_BlockIdType)185)

#define NvM_ORNG_SIGGRDDIAG ((NvM_BlockIdType)186)

#define NvM_ORNG_DSPLAUSFLD ((NvM_BlockIdType)187)

#define NvM_ORNG_DSPLAUSFCO ((NvM_BlockIdType)188)

#define NvM_OC_UUPLS ((NvM_BlockIdType)189)

#define NvM_SCG_UUPLS ((NvM_BlockIdType)190)

#define NvM_SCP_UUPLS ((NvM_BlockIdType)191)

#define NvM_ORNG_OXYSENSPERD ((NvM_BlockIdType)192)

#define NvM_ORNG_OXYAPVPERD ((NvM_BlockIdType)193)

#define NvM_ORNG_USPLAUSFLD ((NvM_BlockIdType)194)

#define NvM_ORNG_USPLAUSFCO ((NvM_BlockIdType)195)

#define NvM_COH_CLUST ((NvM_BlockIdType)196)

#define NvM_STUCK_CLUST ((NvM_BlockIdType)197)

#define NvM_SCP_RCLUPEDPRSSMES ((NvM_BlockIdType)198)

#define NvM_SCG_RCLUPEDPRSSMES ((NvM_BlockIdType)199)

#define NvM_ORNG_RCLUPEDPRSSMES ((NvM_BlockIdType)200)

#define NvM_GRD_RCLUPEDPRSSMES ((NvM_BlockIdType)201)

#define NvM_FCTCLUP ((NvM_BlockIdType)202)

#define NvM_OC_DRVRFAN1 ((NvM_BlockIdType)203)

#define NvM_LO_DRVRFAN1 ((NvM_BlockIdType)204)

#define NvM_HI_DRVRFAN1 ((NvM_BlockIdType)205)

#define NvM_OC_DRVRFAN2 ((NvM_BlockIdType)206)

#define NvM_LO_DRVRFAN2 ((NvM_BlockIdType)207)

#define NvM_HI_DRVRFAN2 ((NvM_BlockIdType)208)

#define NvM_COH_STFANB1 ((NvM_BlockIdType)209)

#define NvM_COH_STFANB2LOSPD ((NvM_BlockIdType)210)

#define NvM_COH_STFANB2HISPD ((NvM_BlockIdType)211)

#define NvM_COH_STFANB2NOSPD ((NvM_BlockIdType)212)

#define NvM_CLSDRLY_STFANC ((NvM_BlockIdType)213)

#define NvM_EL_STFANC ((NvM_BlockIdType)214)

#define NvM_UNVLD_STFANC ((NvM_BlockIdType)215)

#define NvM_CRITSC_STFANC ((NvM_BlockIdType)216)

#define NvM_ECI_STFANC ((NvM_BlockIdType)217)

#define NvM_SCP_ECTREQ ((NvM_BlockIdType)218)

#define NvM_SCG_ECTREQ ((NvM_BlockIdType)219)

#define NvM_OC_ECTREQ ((NvM_BlockIdType)220)

#define NvM_LINBLOCKEDBUS ((NvM_BlockIdType)221)

#define NvM_ALTABSENTECU ((NvM_BlockIdType)222)

#define NvM_ETAT_ALT1 ((NvM_BlockIdType)223)

#define NvM_ETAT_ALT2 ((NvM_BlockIdType)224)

#define NvM_TRCK_TCOMES ((NvM_BlockIdType)225)

#define NvM_WUP_TCOMES ((NvM_BlockIdType)226)

#define NvM_LOCSTRDRV ((NvM_BlockIdType)227)

#define NvM_HICSTRDRV ((NvM_BlockIdType)228)

#define NvM_ELINFBSIDFT ((NvM_BlockIdType)229)

#define NvM_ELCPTTRABSIDFT ((NvM_BlockIdType)230)

#define NvM_ELCHKCONSDFT ((NvM_BlockIdType)231)

#define NvM_ELCONSDEFDFTVSLIM ((NvM_BlockIdType)232)

#define NvM_ELCONSVARDFTVSLIM ((NvM_BlockIdType)233)

#define NvM_ELCONSDEFDFTVSREG ((NvM_BlockIdType)234)

#define NvM_ELCONSVARDFTVSREG ((NvM_BlockIdType)235)

#define NvM_ELCONSINITDFTVSREG ((NvM_BlockIdType)236)

#define NvM_ELDFTCRSCTL ((NvM_BlockIdType)237)

#define NvM_ZEROFRAMECNTDFT ((NvM_BlockIdType)238)

#define NvM_EVENFRAMECNTDFT ((NvM_BlockIdType)239)

#define NvM_ELFRAMECNTINCDFT ((NvM_BlockIdType)240)

#define NvM_ELCONSCOHVSMAXP ((NvM_BlockIdType)241)

#define NvM_ELCONSDEFDFTVSMAXP ((NvM_BlockIdType)242)

#define NvM_CRSCTLDFT ((NvM_BlockIdType)243)

#define NvM_F432LOST ((NvM_BlockIdType)244)

#define NvM_DFTEEPROM ((NvM_BlockIdType)245)

#define NvM_FLASHCHK ((NvM_BlockIdType)246)

#define NvM_SCP_BINHCRKALTHW ((NvM_BlockIdType)247)

#define NvM_SCG_BINHCRKALTHW ((NvM_BlockIdType)248)

#define NvM_SCP_UDFTSTACMD ((NvM_BlockIdType)249)

#define NvM_SCG_UDFTSTACMD ((NvM_BlockIdType)250)

#define NvM_INVLD_UDFTSTACMD ((NvM_BlockIdType)251)

#define NvM_SCP_ENGSTOUTIDC ((NvM_BlockIdType)252)

#define NvM_SCG_ENGSTOUTIDC ((NvM_BlockIdType)253)

#define NvM_OC_ENGSTOUTIDC ((NvM_BlockIdType)254)

#define NvM_ORNGPFUENGST ((NvM_BlockIdType)255)

#define NvM_ORNGUNLOCKENGST ((NvM_BlockIdType)256)

#define NvM_ORNGSYNCENGST ((NvM_BlockIdType)257)

#define NvM_ORNGSTRTENGST ((NvM_BlockIdType)258)

#define NvM_SCP_DML ((NvM_BlockIdType)259)

#define NvM_OC_DML ((NvM_BlockIdType)260)

#define NvM_SCG_DML ((NvM_BlockIdType)261)

#define NvM_BLOCK_STRTR ((NvM_BlockIdType)262)

#define NvM_REDESLIM ((NvM_BlockIdType)263)

#define NvM_ORNG_FUGAUGELVL ((NvM_BlockIdType)264)

#define NvM_LOFULVL ((NvM_BlockIdType)265)

#define NvM_OC_FUGAUGE ((NvM_BlockIdType)266)

#define NvM_ORNG_FUGAUGE ((NvM_BlockIdType)267)

#define NvM_SCG_FUGAUGE ((NvM_BlockIdType)268)

#define NvM_SCG_PROPFUPMP ((NvM_BlockIdType)269)

#define NvM_SCP_PROPFUPMP ((NvM_BlockIdType)270)

#define NvM_OC_PROPFUPMP ((NvM_BlockIdType)271)

#define NvM_MAP_PROPFUPMP ((NvM_BlockIdType)272)

#define NvM_GRAVSCP_PROPFUPMP ((NvM_BlockIdType)273)

#define NvM_FRQ_PROPFUPMP ((NvM_BlockIdType)274)

#define NvM_RVSGEAR ((NvM_BlockIdType)275)

#define NvM_SCP_BNEUT ((NvM_BlockIdType)276)

#define NvM_SCG_BNEUT ((NvM_BlockIdType)277)

#define NvM_ORNG_BNEUT ((NvM_BlockIdType)278)

#define NvM_COH_STRTLOCK ((NvM_BlockIdType)279)

#define NvM_HI_DRVRSENO2DS ((NvM_BlockIdType)280)

#define NvM_LO_DRVRSENO2DS ((NvM_BlockIdType)281)

#define NvM_HI_DRVRSENO2US ((NvM_BlockIdType)282)

#define NvM_LO_DRVRSENO2US ((NvM_BlockIdType)283)

#define NvM_ORNG_USHEAT ((NvM_BlockIdType)284)

#define NvM_ORNG_DSHEAT ((NvM_BlockIdType)285)

#define NvM_OC_IGCOIL1CMD ((NvM_BlockIdType)286)

#define NvM_SCP_IGCOIL1CMD ((NvM_BlockIdType)287)

#define NvM_OC_IGCOIL2CMD ((NvM_BlockIdType)288)

#define NvM_SCP_IGCOIL2CMD ((NvM_BlockIdType)289)

#define NvM_OC_IGCOIL3CMD ((NvM_BlockIdType)290)

#define NvM_SCP_IGCOIL3CMD ((NvM_BlockIdType)291)

#define NvM_OC_IGCOIL4CMD ((NvM_BlockIdType)292)

#define NvM_SCP_IGCOIL4CMD ((NvM_BlockIdType)293)

#define NvM_CMMABSENT ((NvM_BlockIdType)294)

#define NvM_CAPT_VOLABSENT ((NvM_BlockIdType)295)

#define NvM_MISSF305 ((NvM_BlockIdType)296)

#define NvM_SHOF305 ((NvM_BlockIdType)297)

#define NvM_CHKF305 ((NvM_BlockIdType)298)

#define NvM_CNTF305 ((NvM_BlockIdType)299)

#define NvM_INVLDF305P537 ((NvM_BlockIdType)300)

#define NvM_INVLDF305P538 ((NvM_BlockIdType)301)

#define NvM_FRBDF305P537 ((NvM_BlockIdType)302)

#define NvM_MISSF30D ((NvM_BlockIdType)303)

#define NvM_SHOF30D ((NvM_BlockIdType)304)

#define NvM_INVLDF30DP263 ((NvM_BlockIdType)305)

#define NvM_INVLDF30DP264 ((NvM_BlockIdType)306)

#define NvM_INVLDF30DP265 ((NvM_BlockIdType)307)

#define NvM_INVLDF30DP266 ((NvM_BlockIdType)308)

#define NvM_MISSF329 ((NvM_BlockIdType)309)

#define NvM_SHOF329 ((NvM_BlockIdType)310)

#define NvM_CHKF329 ((NvM_BlockIdType)311)

#define NvM_CNTF329 ((NvM_BlockIdType)312)

#define NvM_INVLDF329P445 ((NvM_BlockIdType)313)

#define NvM_FRBDF329P445 ((NvM_BlockIdType)314)

#define NvM_FRBDF329P397 ((NvM_BlockIdType)315)

#define NvM_MISSF349 ((NvM_BlockIdType)316)

#define NvM_SHOF349 ((NvM_BlockIdType)317)

#define NvM_CHKF349 ((NvM_BlockIdType)318)

#define NvM_CNTF349 ((NvM_BlockIdType)319)

#define NvM_INVLDF349P007 ((NvM_BlockIdType)320)

#define NvM_INVLDF349P055 ((NvM_BlockIdType)321)

#define NvM_FRBDF349P360 ((NvM_BlockIdType)322)

#define NvM_FRBDF349P057 ((NvM_BlockIdType)323)

#define NvM_FRBDF349P008 ((NvM_BlockIdType)324)

#define NvM_FRBDF349P007 ((NvM_BlockIdType)325)

#define NvM_FRBDF349P287 ((NvM_BlockIdType)326)

#define NvM_FRBDF349PM1434 ((NvM_BlockIdType)327)

#define NvM_FRBDF349P166 ((NvM_BlockIdType)328)

#define NvM_MISSF34D ((NvM_BlockIdType)329)

#define NvM_SHOF34D ((NvM_BlockIdType)330)

#define NvM_CNTF34D ((NvM_BlockIdType)331)

#define NvM_INVLDF34DFP0593 ((NvM_BlockIdType)332)

#define NvM_INVLDF34DPM1413 ((NvM_BlockIdType)333)

#define NvM_FRBDF34DP047 ((NvM_BlockIdType)334)

#define NvM_FRBDF34DP043 ((NvM_BlockIdType)335)

#define NvM_FRBDF34DP044 ((NvM_BlockIdType)336)

#define NvM_FRBDF34DP045 ((NvM_BlockIdType)337)

#define NvM_FRBDF34DFP0593 ((NvM_BlockIdType)338)

#define NvM_FRBDF34DPM1413 ((NvM_BlockIdType)339)

#define NvM_UC_FREINABSENT ((NvM_BlockIdType)340)

#define NvM_MISSF38D ((NvM_BlockIdType)341)

#define NvM_SHOF38D ((NvM_BlockIdType)342)

#define NvM_CHKF38D ((NvM_BlockIdType)343)

#define NvM_CNTF38D ((NvM_BlockIdType)344)

#define NvM_INVLDF38DP010 ((NvM_BlockIdType)345)

#define NvM_INVLDF38DP052 ((NvM_BlockIdType)346)

#define NvM_MISSF3AD ((NvM_BlockIdType)347)

#define NvM_SHOF3AD ((NvM_BlockIdType)348)

#define NvM_CHKF3AD ((NvM_BlockIdType)349)

#define NvM_CNTF3AD ((NvM_BlockIdType)350)

#define NvM_FRBDF3ADP337 ((NvM_BlockIdType)351)

#define NvM_MISSF3C9 ((NvM_BlockIdType)352)

#define NvM_SHOF3C9 ((NvM_BlockIdType)353)

#define NvM_CHKF3C9 ((NvM_BlockIdType)354)

#define NvM_CNTF3C9 ((NvM_BlockIdType)355)

#define NvM_INVLDF3C9P363 ((NvM_BlockIdType)356)

#define NvM_INVLDF3C9P364 ((NvM_BlockIdType)357)

#define NvM_INVLDF3C9P482 ((NvM_BlockIdType)358)

#define NvM_INVLDF3C9P483 ((NvM_BlockIdType)359)

#define NvM_FRBDF3C9P481 ((NvM_BlockIdType)360)

#define NvM_FRBDF3C9P364 ((NvM_BlockIdType)361)

#define NvM_FRBDF3C9P482 ((NvM_BlockIdType)362)

#define NvM_FRBDF3C9P483 ((NvM_BlockIdType)363)

#define NvM_MISSF3CD ((NvM_BlockIdType)364)

#define NvM_SHOF3CD ((NvM_BlockIdType)365)

#define NvM_INVLDF3CDP225 ((NvM_BlockIdType)366)

#define NvM_INVLDF3CDP515 ((NvM_BlockIdType)367)

#define NvM_INVLDF3CDP319 ((NvM_BlockIdType)368)

#define NvM_FRBDF3CDPM1387 ((NvM_BlockIdType)369)

#define NvM_FRBDF3CDP319 ((NvM_BlockIdType)370)

#define NvM_MISSF412 ((NvM_BlockIdType)371)

#define NvM_SHOF412 ((NvM_BlockIdType)372)

#define NvM_INVLDF412P040 ((NvM_BlockIdType)373)

#define NvM_MISSF432 ((NvM_BlockIdType)374)

#define NvM_SHOF432 ((NvM_BlockIdType)375)

#define NvM_INVLDF432P214 ((NvM_BlockIdType)376)

#define NvM_FRBDF432P249 ((NvM_BlockIdType)377)

#define NvM_FRBDF432P251 ((NvM_BlockIdType)378)

#define NvM_FRBDF432P402 ((NvM_BlockIdType)379)

#define NvM_FRBDF432P368 ((NvM_BlockIdType)380)

#define NvM_FRBDF432P369 ((NvM_BlockIdType)381)

#define NvM_FRBDF432PM1424 ((NvM_BlockIdType)382)

#define NvM_MISSF44D ((NvM_BlockIdType)383)

#define NvM_SHOF44D ((NvM_BlockIdType)384)

#define NvM_INVLDF44DFP0535 ((NvM_BlockIdType)385)

#define NvM_INVLDF44DP330 ((NvM_BlockIdType)386)

#define NvM_INVLDF44DP331 ((NvM_BlockIdType)387)

#define NvM_INVLDF44DP354 ((NvM_BlockIdType)388)

#define NvM_FRBDF44DP354 ((NvM_BlockIdType)389)

#define NvM_BVABSENT ((NvM_BlockIdType)390)

#define NvM_MISSF489 ((NvM_BlockIdType)391)

#define NvM_SHOF489 ((NvM_BlockIdType)392)

#define NvM_INVLDF489P102 ((NvM_BlockIdType)393)

#define NvM_INVLDF489P254 ((NvM_BlockIdType)394)

#define NvM_INVLDF489P218 ((NvM_BlockIdType)395)

#define NvM_FRBDF489P254 ((NvM_BlockIdType)396)

#define NvM_FRBDF489P218 ((NvM_BlockIdType)397)

#define NvM_MISSF492 ((NvM_BlockIdType)398)

#define NvM_SHOF492 ((NvM_BlockIdType)399)

#define NvM_MISSF495 ((NvM_BlockIdType)400)

#define NvM_SHOF495 ((NvM_BlockIdType)401)

#define NvM_MISSF4B2 ((NvM_BlockIdType)402)

#define NvM_SHOF4B2 ((NvM_BlockIdType)403)

#define NvM_MISSF4D2 ((NvM_BlockIdType)404)

#define NvM_SHOF4D2 ((NvM_BlockIdType)405)

#define NvM_MISSF4F2 ((NvM_BlockIdType)406)

#define NvM_SHOF4F2 ((NvM_BlockIdType)407)

#define NvM_INVLDF4F2P434 ((NvM_BlockIdType)408)

#define NvM_INVLDF4F2P438 ((NvM_BlockIdType)409)

#define NvM_INVLDF4F2P429 ((NvM_BlockIdType)410)

#define NvM_INVLDF4F2P437 ((NvM_BlockIdType)411)

#define NvM_INVLDF4F2P490 ((NvM_BlockIdType)412)

#define NvM_INVLDF4F2P491 ((NvM_BlockIdType)413)

#define NvM_INVLDF4F2P492 ((NvM_BlockIdType)414)

#define NvM_FRBDF4F2P434 ((NvM_BlockIdType)415)

#define NvM_FRBDF4F2P438 ((NvM_BlockIdType)416)

#define NvM_FRBDF4F2P437 ((NvM_BlockIdType)417)

#define NvM_FRBDF4F2P490 ((NvM_BlockIdType)418)

#define NvM_FRBDF4F2P493 ((NvM_BlockIdType)419)

#define NvM_FRBDF4F2P491 ((NvM_BlockIdType)420)

#define NvM_FRBDF4F2P494 ((NvM_BlockIdType)421)

#define NvM_FRBDF4F2P492 ((NvM_BlockIdType)422)

#define NvM_MISSF50D ((NvM_BlockIdType)423)

#define NvM_SHOF50D ((NvM_BlockIdType)424)

#define NvM_CHKF50D ((NvM_BlockIdType)425)

#define NvM_CNTF50D ((NvM_BlockIdType)426)

#define NvM_BSIABSENT ((NvM_BlockIdType)427)

#define NvM_MISSF50E ((NvM_BlockIdType)428)

#define NvM_SHOF50E ((NvM_BlockIdType)429)

#define NvM_INVLDF50EPM1386 ((NvM_BlockIdType)430)

#define NvM_INVLDF50EP046 ((NvM_BlockIdType)431)

#define NvM_INVLDF50EP210 ((NvM_BlockIdType)432)

#define NvM_FRBDF50EP046 ((NvM_BlockIdType)433)

#define NvM_FRBDF50EP417 ((NvM_BlockIdType)434)

#define NvM_FRBDF50EP208 ((NvM_BlockIdType)435)

#define NvM_MISSF532 ((NvM_BlockIdType)436)

#define NvM_SHOF532 ((NvM_BlockIdType)437)

#define NvM_INVLDF532PM1414 ((NvM_BlockIdType)438)

#define NvM_INVLDF532PM1415 ((NvM_BlockIdType)439)

#define NvM_INVLDF532PM1416 ((NvM_BlockIdType)440)

#define NvM_FRBDF532PM1414 ((NvM_BlockIdType)441)

#define NvM_FRBDF532PM1415 ((NvM_BlockIdType)442)

#define NvM_FRBDF532PM1416 ((NvM_BlockIdType)443)

#define NvM_MISSF552 ((NvM_BlockIdType)444)

#define NvM_SHOF552 ((NvM_BlockIdType)445)

#define NvM_INVLDF552P255 ((NvM_BlockIdType)446)

#define NvM_INVLDF552P256 ((NvM_BlockIdType)447)

#define NvM_INVLDF552P257 ((NvM_BlockIdType)448)

#define NvM_INVLDF552P325 ((NvM_BlockIdType)449)

#define NvM_INVLDF552P015 ((NvM_BlockIdType)450)

#define NvM_INVLDF552P326 ((NvM_BlockIdType)451)

#define NvM_FRBDF552P255 ((NvM_BlockIdType)452)

#define NvM_FRBDF552P256 ((NvM_BlockIdType)453)

#define NvM_FRBDF552P257 ((NvM_BlockIdType)454)

#define NvM_MISSF572 ((NvM_BlockIdType)455)

#define NvM_SHOF572 ((NvM_BlockIdType)456)

#define NvM_INVLDF572PM1360 ((NvM_BlockIdType)457)

#define NvM_FRBDF572PM1360 ((NvM_BlockIdType)458)

#define NvM_DMTRABSENT ((NvM_BlockIdType)459)

#define NvM_MISSF57C ((NvM_BlockIdType)460)

#define NvM_SHOF57C ((NvM_BlockIdType)461)

#define NvM_INVLDF57CPM1418 ((NvM_BlockIdType)462)

#define NvM_MISSF592 ((NvM_BlockIdType)463)

#define NvM_SHOF592 ((NvM_BlockIdType)464)

#define NvM_LIDF592 ((NvM_BlockIdType)465)

#define NvM_INVLDF592P272 ((NvM_BlockIdType)466)

#define NvM_INVLDF592P273 ((NvM_BlockIdType)467)

#define NvM_INVLDF592P349 ((NvM_BlockIdType)468)

#define NvM_INVLDF592P418 ((NvM_BlockIdType)469)

#define NvM_INVLDF592P419 ((NvM_BlockIdType)470)

#define NvM_INVLDF592P420 ((NvM_BlockIdType)471)

#define NvM_INVLDF592P421_1 ((NvM_BlockIdType)472)

#define NvM_INVLDF592P421_2 ((NvM_BlockIdType)473)

#define NvM_INVLDF592P421_3 ((NvM_BlockIdType)474)

#define NvM_FRBDF592P272 ((NvM_BlockIdType)475)

#define NvM_FRBDF592P273 ((NvM_BlockIdType)476)

#define NvM_FRBDF592P349 ((NvM_BlockIdType)477)

#define NvM_FRBDF592P418 ((NvM_BlockIdType)478)

#define NvM_FRBDF592P419 ((NvM_BlockIdType)479)

#define NvM_FRBDF592P421_1 ((NvM_BlockIdType)480)

#define NvM_FRBDF592P421_2 ((NvM_BlockIdType)481)

#define NvM_FRBDF592P421_3 ((NvM_BlockIdType)482)

#define NvM_MISSF5B2 ((NvM_BlockIdType)483)

#define NvM_SHOF5B2 ((NvM_BlockIdType)484)

#define NvM_INVLDF5B2P146 ((NvM_BlockIdType)485)

#define NvM_FRBDF5B2P146 ((NvM_BlockIdType)486)

#define NvM_MISSF612 ((NvM_BlockIdType)487)

#define NvM_SHOF612 ((NvM_BlockIdType)488)

#define NvM_INVLDF612P260 ((NvM_BlockIdType)489)

#define NvM_INVLDF612P436 ((NvM_BlockIdType)490)

#define NvM_INVLDF612P705 ((NvM_BlockIdType)491)

#define NvM_FRBDF612P927 ((NvM_BlockIdType)492)

#define NvM_FRBDF612P436 ((NvM_BlockIdType)493)

#define NvM_MISSF792 ((NvM_BlockIdType)494)

#define NvM_SHOF792 ((NvM_BlockIdType)495)

#define NvM_MISSF7F2 ((NvM_BlockIdType)496)

#define NvM_SHOF7F2 ((NvM_BlockIdType)497)

#define NvM_LIDF7F2 ((NvM_BlockIdType)498)

#define NvM_INVLDF7F2P146 ((NvM_BlockIdType)499)

#define NvM_INVLDF7F2P015 ((NvM_BlockIdType)500)

#define NvM_FRBDF7F2P849 ((NvM_BlockIdType)501)

#define NvM_FRBDF7F2P146 ((NvM_BlockIdType)502)

#define NvM_SCP_INJ1CMD ((NvM_BlockIdType)503)

#define NvM_OC_INJ1CMD ((NvM_BlockIdType)504)

#define NvM_SCP_INJ2CMD ((NvM_BlockIdType)505)

#define NvM_OC_INJ2CMD ((NvM_BlockIdType)506)

#define NvM_SCP_INJ3CMD ((NvM_BlockIdType)507)

#define NvM_OC_INJ3CMD ((NvM_BlockIdType)508)

#define NvM_SCP_INJ4CMD ((NvM_BlockIdType)509)

#define NvM_OC_INJ4CMD ((NvM_BlockIdType)510)

#define NvM_ORNGLFBK_AFL ((NvM_BlockIdType)511)

#define NvM_DFTFU_AFL ((NvM_BlockIdType)512)

#define NvM_DFTSENO2_AFL ((NvM_BlockIdType)513)

#define NvM_ORNGLFBKGAS_AFL ((NvM_BlockIdType)514)

#define NvM_DFTFUGAS_AFL ((NvM_BlockIdType)515)

#define NvM_DFTSENO2GAS_AFL ((NvM_BlockIdType)516)

#define NvM_ORNGLFBK_AFR ((NvM_BlockIdType)517)

#define NvM_DFTFU_AFR ((NvM_BlockIdType)518)

#define NvM_DFTSENO2_AFR ((NvM_BlockIdType)519)

#define NvM_ORNGLFBKGAS_AFR ((NvM_BlockIdType)520)

#define NvM_DFTFUGAS_AFR ((NvM_BlockIdType)521)

#define NvM_DFTSENO2GAS_AFR ((NvM_BlockIdType)522)

#define NvM_HITALT_ALTCTL ((NvM_BlockIdType)523)

#define NvM_MECAALT_ALTCTL ((NvM_BlockIdType)524)

#define NvM_ELECALT_ALTCTL ((NvM_BlockIdType)525)

#define NvM_COMALT_ALTCTL ((NvM_BlockIdType)526)

#define NvM_ORNG_KNKDIAG ((NvM_BlockIdType)527)

#define NvM_HHIT_NOISEADP ((NvM_BlockIdType)528)

#define NvM_LHIT_NOISEADP ((NvM_BlockIdType)529)

#define NvM_HSLD_NOISEADP ((NvM_BlockIdType)530)

#define NvM_LSLD_NOISEADP ((NvM_BlockIdType)531)

#define NvM_ORNG_SHRTWINLRN ((NvM_BlockIdType)532)

#define NvM_ORNG_LONGWINLRN ((NvM_BlockIdType)533)

#define NvM_ORNG_SHRTWINLRNMAX ((NvM_BlockIdType)534)

#define NvM_ORNG_LONGWINLRNMAX ((NvM_BlockIdType)535)

#define NvM_LOSTMISFROUGHNSROAD ((NvM_BlockIdType)536)

#define NvM_ORNGDMGCATMD1 ((NvM_BlockIdType)537)

#define NvM_ORNGDMGCATMD2 ((NvM_BlockIdType)538)

#define NvM_ORNGDMGCATMD3 ((NvM_BlockIdType)539)

#define NvM_ORNGDMGCATMD4 ((NvM_BlockIdType)540)

#define NvM_ORNGDMGCATMDALL ((NvM_BlockIdType)541)

#define NvM_ORNGDMGCATDTC1 ((NvM_BlockIdType)542)

#define NvM_ORNGDMGCATDTC2 ((NvM_BlockIdType)543)

#define NvM_ORNGDMGCATDTC3 ((NvM_BlockIdType)544)

#define NvM_ORNGDMGCATDTC4 ((NvM_BlockIdType)545)

#define NvM_ORNGDMGCATDTCALL ((NvM_BlockIdType)546)

#define NvM_ORNGMISFEMI1 ((NvM_BlockIdType)547)

#define NvM_ORNGMISFEMI2 ((NvM_BlockIdType)548)

#define NvM_ORNGMISFEMI3 ((NvM_BlockIdType)549)

#define NvM_ORNGMISFEMI4 ((NvM_BlockIdType)550)

#define NvM_ORNGMISFEMIALL ((NvM_BlockIdType)551)

#define NvM_ORNGDMGCATMDGAZ1 ((NvM_BlockIdType)552)

#define NvM_ORNGDMGCATMDGAZ2 ((NvM_BlockIdType)553)

#define NvM_ORNGDMGCATMDGAZ3 ((NvM_BlockIdType)554)

#define NvM_ORNGDMGCATMDGAZ4 ((NvM_BlockIdType)555)

#define NvM_ORNGDMGCATMDGAZALL ((NvM_BlockIdType)556)

#define NvM_ORNGDMGCATDTCGAZ1 ((NvM_BlockIdType)557)

#define NvM_ORNGDMGCATDTCGAZ2 ((NvM_BlockIdType)558)

#define NvM_ORNGDMGCATDTCGAZ3 ((NvM_BlockIdType)559)

#define NvM_ORNGDMGCATDTCGAZ4 ((NvM_BlockIdType)560)

#define NvM_ORNGDMGCATDTCGAZALL ((NvM_BlockIdType)561)

#define NvM_ORNGMISFEMIGAZ1 ((NvM_BlockIdType)562)

#define NvM_ORNGMISFEMIGAZ2 ((NvM_BlockIdType)563)

#define NvM_ORNGMISFEMIGAZ3 ((NvM_BlockIdType)564)

#define NvM_ORNGMISFEMIGAZ4 ((NvM_BlockIdType)565)

#define NvM_ORNGMISFEMIGAZALL ((NvM_BlockIdType)566)

#define NvM_DFTSENR_ACCP ((NvM_BlockIdType)567)

#define NvM_OC_BINHCRKALTHW ((NvM_BlockIdType)568)

#define NvM_LO_UBATTSPC ((NvM_BlockIdType)569)

#define NvM_ORNG_VMES4 ((NvM_BlockIdType)570)

#define NvM_ORNG_VMES4_SFTY ((NvM_BlockIdType)571)

#define NvM_ALTABSENT ((NvM_BlockIdType)572)

#define NvM_BUSOFF ((NvM_BlockIdType)573)

#define NvM_LINBLOCKED ((NvM_BlockIdType)574)

#define NvM_ORNG_CAT ((NvM_BlockIdType)575)

#define NvM_ORNG_CATAPV ((NvM_BlockIdType)576)

#define NvM_ABSESPMUTE ((NvM_BlockIdType)577)

#define NvM_BSIMUTE ((NvM_BlockIdType)578)

#define NvM_BVAMUTE ((NvM_BlockIdType)579)

#define NvM_ECMMUTE ((NvM_BlockIdType)580)

#define NvM_DIRAMUTE ((NvM_BlockIdType)581)

#define NvM_CAVMUTE ((NvM_BlockIdType)582)

#define NvM_DMTRMUTE ((NvM_BlockIdType)583)

#define NvM_F552BISP325INVLD ((NvM_BlockIdType)584)

#define NvM_F552P255INVLD ((NvM_BlockIdType)585)

#define NvM_F552P256INVLD ((NvM_BlockIdType)586)

#define NvM_F552P257INVLD ((NvM_BlockIdType)587)

#define NvM_HI_DMPVLVCMD ((NvM_BlockIdType)588)

#define NvM_LO_DMPVLVCMD ((NvM_BlockIdType)589)

#define NvM_HI_WGCCMD ((NvM_BlockIdType)590)

#define NvM_LO_WGCCMD ((NvM_BlockIdType)591)

#define NvM_OC_CTLPMPREQ ((NvM_BlockIdType)592)

#define NvM_OC_CTP1 ((NvM_BlockIdType)593)

#define NvM_OC_CTP2 ((NvM_BlockIdType)594)

#define NvM_OC_TRBWAPMP ((NvM_BlockIdType)595)

#define NvM_SCG_CTLPMPREQ ((NvM_BlockIdType)596)

#define NvM_SCG_CTP1 ((NvM_BlockIdType)597)

#define NvM_SCP_CTP1 ((NvM_BlockIdType)598)

#define NvM_SCG_CTP2 ((NvM_BlockIdType)599)

#define NvM_SCP_CTP2 ((NvM_BlockIdType)600)

#define NvM_SCG_TRBWAPMP ((NvM_BlockIdType)601)

#define NvM_SCP_CTLPMPREQ ((NvM_BlockIdType)602)

#define NvM_SCP_TRBWAPMP ((NvM_BlockIdType)603)

#define NvM_SCG_BLOWBY1 ((NvM_BlockIdType)604)

#define NvM_SCG_BLOWBY2 ((NvM_BlockIdType)605)

#define NvM_SCP_BLOWBY1 ((NvM_BlockIdType)606)

#define NvM_SCP_BLOWBY2 ((NvM_BlockIdType)607)

#define NvM_OC_BLOWBY1 ((NvM_BlockIdType)608)

#define NvM_OC_BLOWBY2 ((NvM_BlockIdType)609)

#define NvM_ORNGHITOILESTIM ((NvM_BlockIdType)610)

#define NvM_PWRLMRK ((NvM_BlockIdType)611)

#define NvM_SCP_VSSNWACVREQ ((NvM_BlockIdType)612)

#define NvM_SCG_VSSNWACVREQ ((NvM_BlockIdType)613)

#define NvM_HI_UBATTMES ((NvM_BlockIdType)614)

#define NvM_LO_UBATTMES ((NvM_BlockIdType)615)

#define NvM_ORNG_VMES1 ((NvM_BlockIdType)616)

#define NvM_ORNG_VMES1_SFTY ((NvM_BlockIdType)617)

#define NvM_ORNG_VMES2 ((NvM_BlockIdType)618)

#define NvM_ORNG_VMES2_SFTY ((NvM_BlockIdType)619)

#define NvM_ORNG_VMES3 ((NvM_BlockIdType)620)

#define NvM_ORNG_VMES3_SFTY ((NvM_BlockIdType)621)

#define NvM_INV_CALID ((NvM_BlockIdType)622)

#define NvM_STUCK_MAINRLY ((NvM_BlockIdType)623)

#define NvM_STUCK_PWRRLY ((NvM_BlockIdType)624)

#define NvM_SCP_PWRRLY ((NvM_BlockIdType)625)

#define NvM_OC_PWRRLY ((NvM_BlockIdType)626)

#define NvM_SCG_PWRRLY ((NvM_BlockIdType)627)

#define NvM_DFT_INFO_CRASH ((NvM_BlockIdType)628)

#define NvM_AFA_ADPAREFFEGRVLVLIM ((NvM_BlockIdType)629)

#define NvM_AFA_ADPAREFFTHROFS1LIM ((NvM_BlockIdType)630)

#define NvM_AFA_ADPAREFFTHROFS2LIM ((NvM_BlockIdType)631)

#define NvM_AFA_ADPAREFFTHROFS3LIM ((NvM_BlockIdType)632)

#define NvM_AFA_ADPAREFFTHROFSLIM ((NvM_BlockIdType)633)

#define NvM_AFA_ADPCLSEXOFSLIM ((NvM_BlockIdType)634)

#define NvM_AFA_ADPINJOFSLIM ((NvM_BlockIdType)635)

#define NvM_AFA_ADPIVSINJCONLIM ((NvM_BlockIdType)636)

#define NvM_AFA_ADPOPINOFSLIM ((NvM_BlockIdType)637)

#define NvM_AFA_ADPSLOPINJCONLIM ((NvM_BlockIdType)638)

#define NvM_ANTIBOIL ((NvM_BlockIdType)639)

#define NvM_BLT ((NvM_BlockIdType)640)

#define NvM_CAT ((NvM_BlockIdType)641)

#define NvM_CATAPV ((NvM_BlockIdType)642)

#define NvM_CKSIG ((NvM_BlockIdType)643)

#define NvM_COSYSDFCT ((NvM_BlockIdType)644)

#define NvM_CORLOSS ((NvM_BlockIdType)645)

#define NvM_CORSPCUR ((NvM_BlockIdType)646)

#define NvM_CUTREQ ((NvM_BlockIdType)647)

#define NvM_FSFBLOCKCLS ((NvM_BlockIdType)648)

#define NvM_FSFBLOCKOP ((NvM_BlockIdType)649)

#define NvM_IRVENGSTOP ((NvM_BlockIdType)650)

#define NvM_LGENGRSTRTINH ((NvM_BlockIdType)651)

#define NvM_MAINWKUDISRD ((NvM_BlockIdType)652)

#define NvM_MAINWKUINCST ((NvM_BlockIdType)653)

#define NvM_ORNGCUTOFFREQ ((NvM_BlockIdType)654)

#define NvM_ORNGGCCLU ((NvM_BlockIdType)655)

#define NvM_ORNGGCMINCLU ((NvM_BlockIdType)656)

#define NvM_ORNGGCNEUT ((NvM_BlockIdType)657)

#define NvM_ORNGGEARENACLU ((NvM_BlockIdType)658)

#define NvM_ORNGGEARMINCLU ((NvM_BlockIdType)659)

#define NvM_ORNGGEARNEUT ((NvM_BlockIdType)660)

#define NvM_ORNGHIDRAGRED ((NvM_BlockIdType)661)

#define NvM_ORNGHINEUT ((NvM_BlockIdType)662)

#define NvM_ORNGLODRAGRED ((NvM_BlockIdType)663)

#define NvM_ORNGLONEUT ((NvM_BlockIdType)664)

#define NvM_ORNGMPLREQ ((NvM_BlockIdType)665)

#define NvM_ORNGSTOPREQ ((NvM_BlockIdType)666)

#define NvM_OBSADP ((NvM_BlockIdType)667)

#define NvM_PROTADP ((NvM_BlockIdType)668)

#define NvM_RCDLINESCG ((NvM_BlockIdType)669)

#define NvM_RATCONVTRACLC ((NvM_BlockIdType)670)

#define NvM_SFTYORNGAMT ((NvM_BlockIdType)671)

#define NvM_SFTYORNGAT ((NvM_BlockIdType)672)

#define NvM_SPDVEHCLC ((NvM_BlockIdType)673)

#define NvM_STAACVTHD1 ((NvM_BlockIdType)674)

#define NvM_STAACVTHD2 ((NvM_BlockIdType)675)

#define NvM_STACMD ((NvM_BlockIdType)676)

#define NvM_STACMDINFO ((NvM_BlockIdType)677)

#define NvM_STAELCMD ((NvM_BlockIdType)678)

#define NvM_STUCKMEC ((NvM_BlockIdType)679)

#define NvM_TCOBLOCK ((NvM_BlockIdType)680)

#define NvM_TCOOVERESTIM ((NvM_BlockIdType)681)

#define NvM_TCOSLOWRISE ((NvM_BlockIdType)682)

#define NvM_TCOUNDESTIM ((NvM_BlockIdType)683)

#define NvM_TCOWARN ((NvM_BlockIdType)684)

#define NvM_THERMOSTUCKCLS ((NvM_BlockIdType)685)

#define NvM_THERMOSTUCKOP ((NvM_BlockIdType)686)

#define NvM_TQALT ((NvM_BlockIdType)687)

#define NvM_VSLIM ((NvM_BlockIdType)688)

#define NvM_VSLIMBODY ((NvM_BlockIdType)689)

#define NvM_VSMAX ((NvM_BlockIdType)690)

#define NvM_VSMAXP ((NvM_BlockIdType)691)

#define NvM_VSREG ((NvM_BlockIdType)692)

#define NvM_VSREGBODY ((NvM_BlockIdType)693)

#define NvM_VSREGVEH ((NvM_BlockIdType)694)

#define NvM_IBATTMAXCKG ((NvM_BlockIdType)695)

#define NvM_IBATTMES ((NvM_BlockIdType)696)

#define NvM_RBATTSOC ((NvM_BlockIdType)697)

#define NvM_RESBATTIT ((NvM_BlockIdType)698)

#define NvM_TBATTMES ((NvM_BlockIdType)699)

#define NvM_TQALTRV ((NvM_BlockIdType)700)

#define NvM_UBATTMES ((NvM_BlockIdType)701)

#define NvM_UBATTMINCKG ((NvM_BlockIdType)702)

#define NvM_UBATTOC ((NvM_BlockIdType)703)

#define NvM_UBATTRSTRT ((NvM_BlockIdType)704)

#define NvM_UBATTSTRT ((NvM_BlockIdType)705)

#define NvM_NOANSWCTLUNIT ((NvM_BlockIdType)706)

#define NvM_WRGANSWCTLUNIT ((NvM_BlockIdType)707)

#define NvM_IMMOCODNOTREAD ((NvM_BlockIdType)708)

#define NvM_NOGAP_CKSTS ((NvM_BlockIdType)709)

#define NvM_TOOTHCOH_CKSTS ((NvM_BlockIdType)710)

#define NvM_HITOOTHCOH_CKSTS ((NvM_BlockIdType)711)

#define NvM_IUPRSYNT1 ((NvM_BlockIdType)712)

#define NvM_IUPRSYNT2 ((NvM_BlockIdType)713)

#define NvM_IUPRSYNT3 ((NvM_BlockIdType)714)

#define NvM_SFTYCHKPT_PFCMNG ((NvM_BlockIdType)715)

#define NvM_IRVSTT ((NvM_BlockIdType)716)

#define NvM_RVLIH ((NvM_BlockIdType)717)

#define NvM_IRVVSCTL ((NvM_BlockIdType)718)

#define NvM_INHCHKINITSFTY ((NvM_BlockIdType)719)

#define NvM_DRVTRA ((NvM_BlockIdType)720)

#define NvM_INHENGSTOPSTT ((NvM_BlockIdType)721)

#define NvM_IRVECU ((NvM_BlockIdType)722)

#define NvM_IRVEM ((NvM_BlockIdType)723)

#define NvM_COMSPI_CPU ((NvM_BlockIdType)724)

#define NvM_COMTOUT_CPU ((NvM_BlockIdType)725)

#define NvM_SYNCMON_CPU ((NvM_BlockIdType)726)

#define NvM_ACCP_CPU ((NvM_BlockIdType)727)

#define NvM_THR_CPU ((NvM_BlockIdType)728)

#define NvM_CLK_CPU ((NvM_BlockIdType)729)

#define NvM_ALGO_CPU ((NvM_BlockIdType)730)

#define NvM_COMSPI_CPUSFTY ((NvM_BlockIdType)731)

#define NvM_COMTOUT_CPUSFTY ((NvM_BlockIdType)732)

#define NvM_SYNCMON_CPUSFTY ((NvM_BlockIdType)733)

#define NvM_CLK_CPUSFTY ((NvM_BlockIdType)734)

#define NvM_ALGO_CPUSFTY ((NvM_BlockIdType)735)

#define NvM_CKSROM_CPUSFTY ((NvM_BlockIdType)736)

#define NvM_DEGMOD_CPUSFTY ((NvM_BlockIdType)737)

#define NvM_HI_AENG ((NvM_BlockIdType)738)

#define NvM_HI_NENG ((NvM_BlockIdType)739)

#define NvM_DISTSIG ((NvM_BlockIdType)740)

#define NvM_COH_INCM ((NvM_BlockIdType)741)

#define NvM_COH_EXCM ((NvM_BlockIdType)742)

#define NvM_ENGSPDCOHCK ((NvM_BlockIdType)743)

#define NvM_ENGSPDCOHINCM ((NvM_BlockIdType)744)

#define NvM_ENGSPDCOHEXCM ((NvM_BlockIdType)745)

#define NvM_NOSIGCK ((NvM_BlockIdType)746)

#define NvM_SIGLOSSCK ((NvM_BlockIdType)747)

#define NvM_NOSIGINCM ((NvM_BlockIdType)748)

#define NvM_SIGLOSSINCM ((NvM_BlockIdType)749)

#define NvM_NOSIGEXCM ((NvM_BlockIdType)750)

#define NvM_SIGLOSSEXCM ((NvM_BlockIdType)751)

#define NvM_ORNG_TIENGSTOP ((NvM_BlockIdType)752)

#define NvM_COH_TIENGSTOP ((NvM_BlockIdType)753)

#define NvM_INV_VARCOD ((NvM_BlockIdType)754)

#define NvM_ORNGSERVO ((NvM_BlockIdType)755)

#define NvM_ORNGSERVODIFPOS ((NvM_BlockIdType)756)

#define NvM_ORNGSERVODIFNEG ((NvM_BlockIdType)757)

#define NvM_ENDSTOPREQ1 ((NvM_BlockIdType)758)

#define NvM_ENDSTOPREQ2 ((NvM_BlockIdType)759)

#define NvM_CLSIDLCTL ((NvM_BlockIdType)760)

#define NvM_LIHREQ1 ((NvM_BlockIdType)761)

#define NvM_LIHREQ2 ((NvM_BlockIdType)762)

#define NvM_COHPOSNSNSR ((NvM_BlockIdType)763)

#define NvM_SCPPOSNSNSR1 ((NvM_BlockIdType)764)

#define NvM_SCGPOSNSNSR1 ((NvM_BlockIdType)765)

#define NvM_SCPPOSNSNSR2 ((NvM_BlockIdType)766)

#define NvM_SCGPOSNSNSR2 ((NvM_BlockIdType)767)

#define NvM_DFTSENR_THR ((NvM_BlockIdType)768)

#define NvM_OVLD_THRCMD ((NvM_BlockIdType)769)

#define NvM_CPT_THRCMD ((NvM_BlockIdType)770)

#define NvM_READPININHTHR_CPU ((NvM_BlockIdType)771)

#define NvM_INHTHR_CPUSFTY ((NvM_BlockIdType)772)

#define NvM_OVLDTHERMOTHR ((NvM_BlockIdType)773)

#define NvM_ORNGSFTYDFTLIH ((NvM_BlockIdType)774)

#define NvM_ELDIAGINHPIN0_CPU ((NvM_BlockIdType)775)

#define NvM_ELDIAGINHPIN1_CPU ((NvM_BlockIdType)776)

#define NvM_MCPRAMTEST_CPU ((NvM_BlockIdType)777)

#define NvM_MCPFLASHCKS_CPU ((NvM_BlockIdType)778)

#define NvM_MCWCKSCALC_CPU ((NvM_BlockIdType)779)

#define NvM_MCWINITSFTYRSLT_CPU ((NvM_BlockIdType)780)

#define NvM_MCWFCTTEST_CPU ((NvM_BlockIdType)781)

#define NvM_CLUDMGAFTS ((NvM_BlockIdType)782)

#define NvM_COH_SPDVEH ((NvM_BlockIdType)783)

#define NvM_ORNG_SPDVEH ((NvM_BlockIdType)784)

#define NvM_SERVOERRVLVACTEX ((NvM_BlockIdType)785)

#define NvM_IMAXVLVACTEX ((NvM_BlockIdType)786)

#define NvM_ORNGSPDVLVACTEX ((NvM_BlockIdType)787)

#define NvM_ORNGSHIFTVLVACTEX ((NvM_BlockIdType)788)

#define NvM_MISSTOOTHVLVACTEX ((NvM_BlockIdType)789)

#define NvM_TDCDIAGVLVACTEX ((NvM_BlockIdType)790)

#define NvM_CLNERRVLVACTEX ((NvM_BlockIdType)791)

#define NvM_LRNENDSTOPVLVACTEX ((NvM_BlockIdType)792)

#define NvM_ENDSTOPOLDVLVACTEX ((NvM_BlockIdType)793)

#define NvM_LRNFAILIMVLVACTEX ((NvM_BlockIdType)794)

#define NvM_OLDLRNVLVACTEX ((NvM_BlockIdType)795)

#define NvM_LOVLVACTEXDRV ((NvM_BlockIdType)796)

#define NvM_HIVLVACTEXDRV ((NvM_BlockIdType)797)

#define NvM_DFTCVLVACTEX ((NvM_BlockIdType)798)

#define NvM_ORNGCVLVACTEX ((NvM_BlockIdType)799)

#define NvM_CMDCVLVACTEX ((NvM_BlockIdType)800)

#define NvM_SLOWC1VLVACTEX ((NvM_BlockIdType)801)

#define NvM_SLOWC2VLVACTEX ((NvM_BlockIdType)802)

#define NvM_DFTHVLVACTEX ((NvM_BlockIdType)803)

#define NvM_ORNGHVLVACTEX ((NvM_BlockIdType)804)

#define NvM_CMDHVLVACTEX ((NvM_BlockIdType)805)

#define NvM_STUCKHVLVACTEX ((NvM_BlockIdType)806)

#define NvM_SLOWH1VLVACTEX ((NvM_BlockIdType)807)

#define NvM_STUCKH1VLVACTEX ((NvM_BlockIdType)808)

#define NvM_SLOWH2VLVACTEX ((NvM_BlockIdType)809)

#define NvM_STUCKH2VLVACTEX ((NvM_BlockIdType)810)

#define NvM_STUCKH3VLVACTEX ((NvM_BlockIdType)811)

#define NvM_DIFPOS1VLVACTEX ((NvM_BlockIdType)812)

#define NvM_DIFPOS2VLVACTEX ((NvM_BlockIdType)813)

#define NvM_DIFNEG1VLVACTEX ((NvM_BlockIdType)814)

#define NvM_DIFNEG2VLVACTEX ((NvM_BlockIdType)815)

#define NvM_SERVOERRVLVACTIN ((NvM_BlockIdType)816)

#define NvM_IMAXVLVACTIN ((NvM_BlockIdType)817)

#define NvM_ORNGSPDVLVACTIN ((NvM_BlockIdType)818)

#define NvM_ORNGSHIFTVLVACTIN ((NvM_BlockIdType)819)

#define NvM_MISSTOOTHVLVACTIN ((NvM_BlockIdType)820)

#define NvM_TDCDIAGVLVACTIN ((NvM_BlockIdType)821)

#define NvM_CLNERRVLVACTIN ((NvM_BlockIdType)822)

#define NvM_LRNENDSTOPVLVACTIN ((NvM_BlockIdType)823)

#define NvM_ENDSTOPOLDVLVACTIN ((NvM_BlockIdType)824)

#define NvM_LRNFAILIMVLVACTIN ((NvM_BlockIdType)825)

#define NvM_OLDLRNVLVACTIN ((NvM_BlockIdType)826)

#define NvM_LOVLVACTINDRV ((NvM_BlockIdType)827)

#define NvM_HIVLVACTINDRV ((NvM_BlockIdType)828)

#define NvM_DFTCVLVACTIN ((NvM_BlockIdType)829)

#define NvM_ORNGCVLVACTIN ((NvM_BlockIdType)830)

#define NvM_CMDCVLVACTIN ((NvM_BlockIdType)831)

#define NvM_SLOWC1VLVACTIN ((NvM_BlockIdType)832)

#define NvM_SLOWC2VLVACTIN ((NvM_BlockIdType)833)

#define NvM_DFTHVLVACTIN ((NvM_BlockIdType)834)

#define NvM_ORNGHVLVACTIN ((NvM_BlockIdType)835)

#define NvM_CMDHVLVACTIN ((NvM_BlockIdType)836)

#define NvM_STUCKHVLVACTIN ((NvM_BlockIdType)837)

#define NvM_SLOWH1VLVACTIN ((NvM_BlockIdType)838)

#define NvM_STUCKH1VLVACTIN ((NvM_BlockIdType)839)

#define NvM_SLOWH2VLVACTIN ((NvM_BlockIdType)840)

#define NvM_STUCKH2VLVACTIN ((NvM_BlockIdType)841)

#define NvM_STUCKH3VLVACTIN ((NvM_BlockIdType)842)

#define NvM_DIFPOS1VLVACTIN ((NvM_BlockIdType)843)

#define NvM_DIFPOS2VLVACTIN ((NvM_BlockIdType)844)

#define NvM_DIFNEG1VLVACTIN ((NvM_BlockIdType)845)

#define NvM_DIFNEG2VLVACTIN ((NvM_BlockIdType)846)

#define NvM_ZZEND_BIDON ((NvM_BlockIdType)847)

#define NvM_HEATSENO2DSDERIDIAG ((NvM_BlockIdType)848)

#define NvM_HEATSENO2DS ((NvM_BlockIdType)849)

#define NvM_HEATSENO2US ((NvM_BlockIdType)850)

#define NvM_IFAIRSYSIGSYS ((NvM_BlockIdType)851)

#define NvM_INJFARCTLDSCTL ((NvM_BlockIdType)852)

#define NvM_MISFDFTLRN ((NvM_BlockIdType)853)

#define NvM_MPM_NVRAM_INT16_CONST ((NvM_BlockIdType)854)

#define NvM_MPM_NVRAM_INT32_CONST ((NvM_BlockIdType)855)

#define NvM_MPM_NVRAM_INT32_CONST_1 ((NvM_BlockIdType)856)

#define NvM_MPM_NVRAM_INT32_CONST_2 ((NvM_BlockIdType)857)

#define NvM_INJRCHRN ((NvM_BlockIdType)858)

#define NvM_OBDSRV06 ((NvM_BlockIdType)859)

#define NvM_POSTEQUSRV_BANTISCANNING ((NvM_BlockIdType)860)

#define NvM_PREDES ((NvM_BlockIdType)861)

#define NvM_PRODELEM_NVRAM_INT16_CONST_1 ((NvM_BlockIdType)862)

#define NvM_PRODELEM_NVRAM_INT16_CONST_2 ((NvM_BlockIdType)863)

#define NvM_PRODELEM_NVRAM_INT32_CONST_1 ((NvM_BlockIdType)864)

#define NvM_PRODELEM_NVRAM_INT32_CONST_2 ((NvM_BlockIdType)865)

#define NvM_PRODELEM_NVRAM_INT32_CONST_3 ((NvM_BlockIdType)866)

#define NvM_PRODELEM_NVRAM_INT8_CONST_1 ((NvM_BlockIdType)867)

#define NvM_PRODELEM_NVRAM_INT8_CONST_2 ((NvM_BlockIdType)868)

#define NvM_PRODELEM_NVRAM_BOOLEAN_CONST_1 ((NvM_BlockIdType)869)

#define NvM_PRODELEM_NVRAM_BOOLEAN_CONST_2 ((NvM_BlockIdType)870)

#define NvM_PRODELENG_NVRAM_INT32_CONST_1 ((NvM_BlockIdType)871)

#define NvM_PROTMANCLU ((NvM_BlockIdType)872)

#define NvM_ECUSTSRVPWRLST ((NvM_BlockIdType)873)

#define NvM_REFIDETA ((NvM_BlockIdType)874)

#define NvM_RANDOM ((NvM_BlockIdType)875)

#define NvM_SFTYMNGR ((NvM_BlockIdType)876)

#define NvM_SPYEMSTT ((NvM_BlockIdType)877)

#define NvM_SPYSTT ((NvM_BlockIdType)878)

#define NvM_STOPSTRTEM_NVRAM_INT16_CONST_3 ((NvM_BlockIdType)879)

#define NvM_STOPSTRTEM_NVRAM_INT32_CONST_1 ((NvM_BlockIdType)880)

#define NvM_STOPSTRTEM_NVRAM_INT32_CONST_2 ((NvM_BlockIdType)881)

#define NvM_SYNCENGCLC ((NvM_BlockIdType)882)

#define NvM_TELE_BANTISCANNING ((NvM_BlockIdType)883)

#define NvM_THMGT_NVRAM_INT8_CONST ((NvM_BlockIdType)884)

#define NvM_THMGT_NVRAM_BOOLEAN_CONST ((NvM_BlockIdType)885)

#define NvM_THRSPT_NVRAM_INT32_CONST ((NvM_BlockIdType)886)

#define NvM_PAP_MOT ((NvM_BlockIdType)887)

#define NvM_TIENGSTOP ((NvM_BlockIdType)888)

#define NvM_TOILEST ((NvM_BlockIdType)889)

#define NvM_TPM_NVRAM_INT16_CONST ((NvM_BlockIdType)890)

#define NvM_TQADPCMP_NVRAM_INT16_CONST ((NvM_BlockIdType)891)

#define NvM_TQADPCMP_NVRAM_INT32_CONST ((NvM_BlockIdType)892)

#define NvM_TQADPCMP_NVRAM_INT8_CONST ((NvM_BlockIdType)893)

#define NvM_TWCMGT ((NvM_BlockIdType)894)

#define NvM_UPLSACQ ((NvM_BlockIdType)895)

#define NvM_USTHRMT_NVRAM_INT16_CALIB ((NvM_BlockIdType)896)

#define NvM_VLVACTEXENDSTOP ((NvM_BlockIdType)897)

#define NvM_VLVACTINENDSTOP ((NvM_BlockIdType)898)

#define NvM_VSC ((NvM_BlockIdType)899)

#define NvM_BSW_BLOCK_RESET ((NvM_BlockIdType)900)

#define NvM_BSW_BLOCK_EXCEPTIONS ((NvM_BlockIdType)901)

#define NvM_BSW_BLOCK_MEAS ((NvM_BlockIdType)902)

/* !Trace_To        : GSCSW-NVM-SDD-001-0205                                  */
/* !Parameter: Switch to enable the development error detection.         */
/* !Range: [STD_ON, STD_OFF]                           */
#define NVM_DEV_ERROR_DETECT STD_ON

/* !Trace_To        : GSCSW-NVM-SDD-001-0206                                  */
/* !Parameter: Switch to enable job prioritization handling. If disabled all 
               jobs shall be treated in FCFS order and immediate jobs won't  
   be supported                                                         */
/* !Range: [STD_ON, STD_OFF]                           */
#define NVM_JOB_PRIORITIZATION STD_OFF

/* !Trace_To        : GSCSW-NVM-SDD-001-0207                                  */
/* !Parameter: Switch to enable the dynamic configuration management handling
               by the NvM_ReadAll request incase of configuration ID mismatch */
/* !Range: [STD_ON, STD_OFF]                                                  */
#define NVM_DYNAMIC_CONFIGURATION STD_OFF

/* !Trace_To        : GSCSW-NVM-SDD-001-0208                                  */
/* !Parameter: Switch to enable switching memory drivers to fast mode during 
               performing NvM_ReadAll and NvM_WriteAll                        */
/* !Range: [STD_ON, STD_OFF]                           */
#define NVM_DRV_MODE_SWITCH STD_ON

/* !Trace_To        : GSCSW-NVM-SDD-001-0209                                  */
/* !Parameter: Switch to enable the version info API               */
/* !Range: [STD_ON, STD_OFF]                           */
#define NVM_VERSION_INFO_API STD_OFF

/* !Trace_To        : GSCSW-NVM-SDD-001-0210                                  */
/* !Parameter: Switch to enable the API NvM_SetRamBlockStatus         */
/* !Range: [STD_ON, STD_OFF]                           */
#define NVM_SET_RAM_BLOCK_STATUS_API STD_ON

/* !Trace_To        : GSCSW-NVM-SDD-001-0211                                  */
/* !Parameter: Switch to enable the polling mode in the NVRAM Manager and at 
   the same time disable the callback functions useable by lower 
   layers or vice versa                                                 */
/* !Range: [STD_ON, STD_OFF]                                                  */
#define NVM_POLLING_MODE STD_OFF
/* !Trace_To        : GSCSW-NVM-SDD-001-0383                                  */
/* !Parameter: This parameter is used to enable/disable using CRC8. Note that
               this parameter depends on the CRC component configuration      */
/* !Range: [STD_ON, STD_OFF] */
#define NVM_USE_CRC8 STD_OFF

/* !Trace_To        : GSCSW-NVM-SDD-001-0239                                  */
/* !Parameter: This parameter is used to enable/disable using CRC16. Note
               that this parameter depends on the CRC component configuration */
/* !Range: [STD_ON, STD_OFF]                           */
#define NVM_USE_CRC16 STD_ON

/* !Trace_To        : GSCSW-NVM-SDD-001-0240                                  */
/* !Parameter: This parameter is used to enable/disable using CRC32. Note    
               that this parameter depends on the CRC component configuration */
/* !Range: [STD_ON, STD_OFF]                                                  */
#define NVM_USE_CRC32 STD_OFF
/* !Trace_To        : GSCSW-NVM-SDD-001-0379                                  */
/* !Parameter: Defines the numberof retries to let the application copy data
               to or from the NvM module's mirror before postponing the
               current job.                                                   */
/* !Range: [0..7] */

#define NVM_REPEAT_MIRROR_OPERATIONS (0U)



/* !Trace_To        : GSCSW-NVM-SDD-001-0213                                */
/* !Parameter: Defines number of queue entries for the immediate priority job
queue. If NVM_JOB_PRIORITIZATION is switched OFF this
parameter will be out of scope.                                             */
/* !Range: [0..255]                             */
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE ((uint8)0)


/* !Trace_To        : GSCSW-NVM-SDD-001-0214                                  */
/* !Parameter: Defines number of queue entries for the standard priority job 
               queue.                                                         */
/* !Range: [1..255]                                                           */
#define NVM_SIZE_STANDARD_JOB_QUEUE ((uint8)70)


/* !Trace_To        : GSCSW-NVM-SDD-001-0215                                  */
/* !Parameter: Switch to enable some API calls which are related to NVM API  
               configuration classes.                                         */
/* !Range: [NVM_API_CONFIG_CLASS_1, NVM_API_CONFIG_CLASS_2 ,                 
           NVM_API_CONFIG_CLASS_3]                                            */
#define NVM_API_CONFIG_CLASS NVM_API_CONFIG_CLASS_3

/* !Trace_To        : GSCSW-NVM-SDD-001-0216                                  */
/* !Parameter: If CRC is configured for at least one NVRAM block, this       
               parameter defines the maximum number of bytes which shall be  
               processed within one cycle of job processing.                  */
/* !Range: [1..65535]                                                         */
#define NVM_CRC_NUM_OF_BYTES ((uint16)65535)


/* !Trace_To        : GSCSW-NVM-SDD-001-0217                                  */
/* !Parameter: Configuration ID regarding the NV memory layout. This         
               configuration ID shall be published so a SW-C shall have the  
               possibility to write it to NV memory. Used by NvM_ReadAll to  
               compare with the stored Configuration ID.                      */
/* !Range: [0..65535]                                                         */
#define NVM_COMPILED_CONFIG_ID ((uint16)1)


/* !Trace_To        : GSCSW-NVM-SDD-001-0218                                  */
/* !Parameter: Defines the number of least significant bits which shall be   
               used to address a certain dataset of a NVRAM block within the 
               interface to the memory hardware abstraction. This parameter  
               affects the range of NVM_udtNUM_OF_NVRAM_BLOCKS parameter. If 
               this parameter is set to 0 then there shouldn't be any block  
               configured as NVM_BLOCK_DATASET.                               */
/* !Range: [1..8]                                                             */
#define NVM_DATASET_SELECTION_BITS (1U)

/* !Trace_To        : GSCSW-NVM-SDD-001-0380                                  */
/* !Parameter: This parameter defines the cycle time in seconds of the 
               periodic calling of NvM main function.                         */
/* !Range: [0..0.1] */
#define NVM_MAIN_FUNCTION_CYCLE_TIME 0.01

/* !Trace_To        : GSCSW-NVM-SDD-001-0127                                  */
/* !Parameter: Defines the number of queue entries for the background CRC    
               recalculations initiated through NvM_SetRamBlockStatus API. If
               NVM_SET_RAM_BLOCK_STATUS_API is switched OFF, this parameter  
               shall be out of scope.                                         */
/* !Range: [0..255]                                                           */
#define NVM_u8SIZE_BCKGND_CRC_QUEUE (0U)

/* !Trace_To        : GSCSW-NVM-SDD-001-0219                                  */
/* !Parameter: This parameter shall publish the total number of configured
               NVRAM blocks to offer the possibility to do an over-all block
               handling, e.g. during start-up by a single SW-C. It's also
               used by the NVM to allocate the required resources (ex. RAM)
               to handle these blocks. Take care that the reserved block ID 1
               should be taken into account while setting this value
              (ie.added). Reserved block ID 0 won't be added.                 */
/* !Range: [2..((2^(16-NVM_DATASET_SELECTION_BITS))-1)]                       */
#define NVM_udtNUM_OF_NVRAM_BLOCKS (902U)
  
/* !Trace_To        :  GSCSW-NVM-SDD-001-0382                                 */
/* !Parameter: This parameter shall publish the size of the buffer used
               for RAM mirror operations. Its value is Automatically calculated
               by the configuration tool as follows:
                  - Search All blocks configured with attribute
                  NvMBlockUseSyncMechanism = TRUE
                  - Assign the highest NvmNvBlockLength of those block to this
                  parameter
               Note: The value of this parameter will be set to zero if there
               are no blocks configrued with
               NvMBlockUseSyncMechanism = TRUE                                */
/* !Range: [0..65535] */

#define NVM_u16RAM_MIRROR_BUF_SIZE (0U)
    
/* !Trace_To        :  GSCSW-NVM-SDD-001-0381                                 */
/* !Parameter: This parameter shall publish the size Internal RAM Mirror
                 which is passed to the underlying layer in all read and write.
                 operations Its value is Automatically calculated by the
                 configuration tool . It is calculated as follows:
                 (Maximum NvMBlockLength) +
                 (Number of Bytes for Block ID Header  "if configured") +
                 (CRC bytes"1,2 or 4 bytes based on the type of Configured CRC")*/

/* !Range: [3..65535] */
#define NVM_u16INTERNAL_RAM_BUF_SIZE ((uint16)2938)


/* !Trace_To        : GSCSW-NVM-SDD-001-0429                                  */
/* !Parameter: This parameter shall publish the size of the verification
               Buffer. Its value is Automatically calculated by the
               configuration tool . It is calculated as follows:
               Search All blocks that use NvMWriteVerification and obtain the
               largest value of NvMWriteVerificationDataSize.
               Note: The value of this parameter will be set to zero if there
                     are no blocks configrued with NvMWriteVerification = TRUE*/
/* !Range: [0..65535]                                                         */
  
#define NVM_u16VERIFY_BUFFER_SIZE (0U)

#define NvM_bRTE_USED STD_OFF
#endif


