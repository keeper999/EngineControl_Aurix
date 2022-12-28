/***************************************************************************
;**
;** FILE NAME      : FRM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FRM_L_H
#define FRM_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FRM_Macro.h"
#include "GD.h"
#include "GD_api.h"
#include "GDFRM.h"
#include "GDFRMDEF.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define FRM_ABAUTHTYPCC_NAMEVAR_C_LNS         ( 739 )
#define FRM_ABDFTTYPCC_NAMEVAR_LNS            ( 739 )
#define FRM_ABRAWTYPACVOPTRVCCDD_LNS          ( 1229 )
#define FRM_ABTYPACVOPTRVCCDD_LNS             ( 1229 )
#define FRM_AU16FRM_TO_LD_NBLD_C_LNS          ( 1229 )
#define FRM_AU16FRM_TO_LD_NBLD_VISU_1_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_NBLD_VISU_2_C_LNS   ( 229 )
#define FRM_AU16FRM_TO_LD_POSDEB_C_LNS        ( 1229 )
#define FRM_AU16FRM_TO_LD_POSDEB_VISU_1_C_LNS  ( 1000 )
#define FRM_AU16FRM_TO_LD_POSDEB_VISU_2_C_LNS  ( 229 )
#define FRM_AU16FRM_TO_LD_TAB_C_LNS           ( 17206 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_1_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_10_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_11_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_12_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_13_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_14_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_15_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_16_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_17_C_LNS   ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_18_C_LNS   ( 206 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_2_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_3_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_4_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_5_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_6_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_7_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_8_C_LNS    ( 1000 )
#define FRM_AU16FRM_TO_LD_TAB_VISU_9_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_NBFRM_C_LNS         ( 739 )
#define FRM_AU16LD_TO_FRM_NBFRM_VISU_1_C_LNS  ( 739 )
#define FRM_AU16LD_TO_FRM_POSDEB_C_LNS        ( 739 )
#define FRM_AU16LD_TO_FRM_POSDEB_VISU_1_C_LNS  ( 739 )
#define FRM_AU16LD_TO_FRM_TAB_C_LNS           ( 17206 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_1_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_10_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_11_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_12_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_13_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_14_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_15_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_16_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_17_C_LNS   ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_18_C_LNS   ( 206 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_2_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_3_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_4_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_5_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_6_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_7_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_8_C_LNS    ( 1000 )
#define FRM_AU16LD_TO_FRM_TAB_VISU_9_C_LNS    ( 1000 )
#define FRM_AU8DU_LNS                         ( 972 )
#define FRM_AU8ENATYPACVOPTRVCCDD_C_LNS       ( 1229 )
#define FRM_FRM_NB                        1229
#define FRM_LD__IBATTMAXCKG               1
#define FRM_LD__IBATTMES                  2
#define FRM_LD__RBATTSOC                  3
#define FRM_LD__RESBATTIT                 4
#define FRM_LD__TBATTMES                  5
#define FRM_LD__UBATTMES                  6
#define FRM_LD__UBATTMINCKG               7
#define FRM_LD__UBATTOC                   8
#define FRM_LD__UBATTRSTRT                9
#define FRM_LD__UBATTSTRT                 10
#define FRM_LD_AASTART_BIDON              0
#define FRM_LD_ABSESPMUTE                 11
#define FRM_LD_ACCELCOH_BRKPED            12
#define FRM_LD_ACCELCOH_BRKPEDBVH2P       13
#define FRM_LD_ACCP_CPU                   14
#define FRM_LD_ADPAREFFEGRVLVLIM          15
#define FRM_LD_ADPAREFFTHROFS1LIM         16
#define FRM_LD_ADPAREFFTHROFS2LIM         17
#define FRM_LD_ADPAREFFTHROFS3LIM         18
#define FRM_LD_ADPAREFFTHROFSLIM          19
#define FRM_LD_ADPCLSEXOFSLIM             20
#define FRM_LD_ADPINJOFSLIM               21
#define FRM_LD_ADPIVSINJCONLIM            22
#define FRM_LD_ADPOPINOFSLIM              23
#define FRM_LD_ADPSLOPINJCONLIM           24
#define FRM_LD_AIRPRSSEXTSDWN             25
#define FRM_LD_AIRPRSSEXTSUP              26
#define FRM_LD_ALGO_CPU                   27
#define FRM_LD_ALGO_CPUSFTY               28
#define FRM_LD_ALTABSENTECU               29
#define FRM_LD_ANTIBOIL                   30
#define FRM_LD_ARDELTACORLIM              31
#define FRM_LD_ASICGDIFAILURE             32
#define FRM_LD_BLOCK_STRTR                33
#define FRM_LD_BLT                        34
#define FRM_LD_BOOST1_PDSTHR              35
#define FRM_LD_BOOST2_PDSTHR              36
#define FRM_LD_BOOST3_PDSTHR              37
#define FRM_LD_BOOST4_PDSTHR              38
#define FRM_LD_BSIMUTE                    39
#define FRM_LD_BUSOFF                     40
#define FRM_LD_BVAMUTE                    41
#define FRM_LD_CAVMUTE                    42
#define FRM_LD_CHKBATTSYS_IBATTMES        43
#define FRM_LD_CHKBATTSYS_TBATTMES        44
#define FRM_LD_CHKBATTSYS_UBATTCLC        45
#define FRM_LD_CKSROM_CPUSFTY             46
#define FRM_LD_CLK_CPU                    47
#define FRM_LD_CLK_CPUSFTY                48
#define FRM_LD_CLNERRVLVACTEX             49
#define FRM_LD_CLNERRVLVACTIN             50
#define FRM_LD_CLSDRLY_STFANC             51
#define FRM_LD_CLSIDLCTL                  52
#define FRM_LD_CLUDMGAFTS                 53
#define FRM_LD_CMDCVLVACTEX               54
#define FRM_LD_CMDCVLVACTIN               55
#define FRM_LD_CMDHVLVACTEX               56
#define FRM_LD_CMDHVLVACTIN               57
#define FRM_LD_COH_BMODSPTREQ             58
#define FRM_LD_COH_CLUST                  59
#define FRM_LD_COH_EEPPWRL                60
#define FRM_LD_COH_EEPREINIT              61
#define FRM_LD_COH_EXCM                   62
#define FRM_LD_COH_HPSENS                 63
#define FRM_LD_COH_INCM                   64
#define FRM_LD_COH_PBRKASI                65
#define FRM_LD_COH_PED                    66
#define FRM_LD_COH_PFUACQ                 67
#define FRM_LD_COH_RACCP                  68
#define FRM_LD_COH_SPDVEH                 69
#define FRM_LD_COH_STCLUAC                70
#define FRM_LD_COH_STFANB1                71
#define FRM_LD_COH_STFANB2HISPD           72
#define FRM_LD_COH_STFANB2LOSPD           73
#define FRM_LD_COH_STFANB2NOSPD           74
#define FRM_LD_COH_STPWRAC                75
#define FRM_LD_COH_STRTLOCK               76
#define FRM_LD_COH_TIENGSTOP              77
#define FRM_LD_COHACCPSWT                 78
#define FRM_LD_COHBIT2_STDFTOBD           79
#define FRM_LD_COHBIT3_STDFTOBD           80
#define FRM_LD_COHBIT4_STDFTOBD           81
#define FRM_LD_COHBIT7_STDFTOBD           82
#define FRM_LD_COHPOSNSNSR                83
#define FRM_LD_COMALT_ALTCTL              84
#define FRM_LD_COMSPI_CPU                 85
#define FRM_LD_COMSPI_CPUSFTY             86
#define FRM_LD_COMTOUT_CPU                87
#define FRM_LD_COMTOUT_CPUSFTY            88
#define FRM_LD_CORLOSS                    89
#define FRM_LD_CORSPCUR                   90
#define FRM_LD_COSYSDFCT                  91
#define FRM_LD_CPT_THRCMD                 92
#define FRM_LD_CRITSC_STFANC              93
#define FRM_LD_CRKCOH_PDSTHR              94
#define FRM_LD_CRSCTLDFT                  95
#define FRM_LD_CUTREQ                     96
#define FRM_LD_DECELCOH_BRKPED            97
#define FRM_LD_DECELCOH_BRKPEDBVH2P       98
#define FRM_LD_DEGMOD_CPUSFTY             99
#define FRM_LD_DFT_INFO_CRASH             100
#define FRM_LD_DFTCVLVACTEX               101
#define FRM_LD_DFTCVLVACTIN               102
#define FRM_LD_DFTEEPROM                  103
#define FRM_LD_DFTFU_AFL                  104
#define FRM_LD_DFTFU_AFR                  105
#define FRM_LD_DFTFUGAS_AFL               106
#define FRM_LD_DFTFUGAS_AFR               107
#define FRM_LD_DFTHVLVACTEX               108
#define FRM_LD_DFTHVLVACTIN               109
#define FRM_LD_DFTOBJEEP                  110
#define FRM_LD_DFTONOFFHI                 111
#define FRM_LD_DFTONOFFLO                 112
#define FRM_LD_DFTOSCCFM                  113
#define FRM_LD_DFTREGHI                   114
#define FRM_LD_DFTREGHICFM                115
#define FRM_LD_DFTREGLO                   116
#define FRM_LD_DFTREGLOCFM                117
#define FRM_LD_DFTSENO2_AFL               118
#define FRM_LD_DFTSENO2_AFR               119
#define FRM_LD_DFTSENO2GAS_AFL            120
#define FRM_LD_DFTSENO2GAS_AFR            121
#define FRM_LD_DFTSENR_ACCP               122
#define FRM_LD_DFTSENR_THR                123
#define FRM_LD_DIFNEG1VLVACTEX            124
#define FRM_LD_DIFNEG1VLVACTIN            125
#define FRM_LD_DIFNEG2VLVACTEX            126
#define FRM_LD_DIFNEG2VLVACTIN            127
#define FRM_LD_DIFPOS1VLVACTEX            128
#define FRM_LD_DIFPOS1VLVACTIN            129
#define FRM_LD_DIFPOS2VLVACTEX            130
#define FRM_LD_DIFPOS2VLVACTIN            131
#define FRM_LD_DIRAMUTE                   132
#define FRM_LD_DISTSIG                    133
#define FRM_LD_DMTRMUTE                   134
#define FRM_LD_DRVTRA                     135
#define FRM_LD_ECI_STFANC                 136
#define FRM_LD_ECMMUTE                    137
#define FRM_LD_EL_STFANC                  138
#define FRM_LD_ELCHKCONSDFT               139
#define FRM_LD_ELCONSCOHVSMAXP            140
#define FRM_LD_ELCONSDEFDFTVSLIM          141
#define FRM_LD_ELCONSDEFDFTVSMAXP         142
#define FRM_LD_ELCONSDEFDFTVSREG          143
#define FRM_LD_ELCONSINITDFTVSREG         144
#define FRM_LD_ELCONSVARDFTVSLIM          145
#define FRM_LD_ELCONSVARDFTVSREG          146
#define FRM_LD_ELCPTTRABSIDFT             147
#define FRM_LD_ELDFTCRSCTL                148
#define FRM_LD_ELDIAGINHPIN0_CPU          149
#define FRM_LD_ELDIAGINHPIN1_CPU          150
#define FRM_LD_ELECALT_ALTCTL             151
#define FRM_LD_ELFRAMECNTINCDFT           152
#define FRM_LD_ELINFBSIDFT                153
#define FRM_LD_ENDSTOPOLDVLVACTEX         154
#define FRM_LD_ENDSTOPOLDVLVACTIN         155
#define FRM_LD_ENDSTOPREQ1                156
#define FRM_LD_ENDSTOPREQ2                157
#define FRM_LD_ENGOILOVERHEAT             158
#define FRM_LD_ENGSPDCOHCK                159
#define FRM_LD_ENGSPDCOHEXCM              160
#define FRM_LD_ENGSPDCOHINCM              161
#define FRM_LD_ETAT_ALT1                  162
#define FRM_LD_ETAT_ALT2                  163
#define FRM_LD_EVENFRAMECNTDFT            164
#define FRM_LD_EXTLEAK_FUSYS              165
#define FRM_LD_F305COH                    166
#define FRM_LD_F305LENGTH                 167
#define FRM_LD_F305LOST                   168
#define FRM_LD_F305P537INVLD              169
#define FRM_LD_F305P538INVLD              170
#define FRM_LD_F30DLENGTH                 171
#define FRM_LD_F30DLOST                   172
#define FRM_LD_F30DP263INVLD              173
#define FRM_LD_F30DP264INVLD              174
#define FRM_LD_F30DP265INVLD              175
#define FRM_LD_F30DP266INVLD              176
#define FRM_LD_F329COH                    177
#define FRM_LD_F329LENGTH                 178
#define FRM_LD_F329LOST                   179
#define FRM_LD_F329P445INVLD              180
#define FRM_LD_F329PROCFAILED             181
#define FRM_LD_F349COH                    182
#define FRM_LD_F349INVLD                  183
#define FRM_LD_F349LENGTH                 184
#define FRM_LD_F349LOST                   185
#define FRM_LD_F349P007INVLD              186
#define FRM_LD_F349P055INVLD              187
#define FRM_LD_F349P440INVLD              188
#define FRM_LD_F349PROCFAILED             189
#define FRM_LD_F34DCOH                    190
#define FRM_LD_F34DLENGTH                 191
#define FRM_LD_F34DLOST                   192
#define FRM_LD_F34DPM1413INVLD            193
#define FRM_LD_F34DPROCFAILED             194
#define FRM_LD_F38DCOH                    195
#define FRM_LD_F38DLENGTH                 196
#define FRM_LD_F38DLOST                   197
#define FRM_LD_F38DP010INVLD              198
#define FRM_LD_F38DP052INVLD              199
#define FRM_LD_F38DPROCFAILED             200
#define FRM_LD_F3ADCOH                    201
#define FRM_LD_F3ADLENGTH                 202
#define FRM_LD_F3ADLOST                   203
#define FRM_LD_F3C9COH                    204
#define FRM_LD_F3C9LENGTH                 205
#define FRM_LD_F3C9LOST                   206
#define FRM_LD_F3C9P291INVLD              207
#define FRM_LD_F3C9P363INVLD              208
#define FRM_LD_F3C9P364INVLD              209
#define FRM_LD_F3C9P482INVLD              210
#define FRM_LD_F3C9P483INVLD              211
#define FRM_LD_F3C9PROCFAILED             212
#define FRM_LD_F3CDCOH                    213
#define FRM_LD_F3CDLENGTH                 214
#define FRM_LD_F3CDLOST                   215
#define FRM_LD_F3CDP225INVLD              216
#define FRM_LD_F3CDP319INVLD              217
#define FRM_LD_F3CDP515INVLD              218
#define FRM_LD_F412LENGTH                 219
#define FRM_LD_F412LOST                   220
#define FRM_LD_F412P040INVLD              221
#define FRM_LD_F432COH                    222
#define FRM_LD_F432INVLD                  223
#define FRM_LD_F432LENGTH                 224
#define FRM_LD_F432LOST                   225
#define FRM_LD_F44DCOH                    226
#define FRM_LD_F44DFP0535INVLD            227
#define FRM_LD_F44DLENGTH                 228
#define FRM_LD_F44DLOST                   229
#define FRM_LD_F44DP330INVLD              230
#define FRM_LD_F44DP331INVLD              231
#define FRM_LD_F44DP354INVLD              232
#define FRM_LD_F489COH                    233
#define FRM_LD_F489LENGTH                 234
#define FRM_LD_F489LOST                   235
#define FRM_LD_F489P102INVLD              236
#define FRM_LD_F489P218INVLD              237
#define FRM_LD_F489P254INVLD              238
#define FRM_LD_F492LENGTH                 239
#define FRM_LD_F492LOST                   240
#define FRM_LD_F495LENGTH                 241
#define FRM_LD_F495LOST                   242
#define FRM_LD_F4B2LENGTH                 243
#define FRM_LD_F4B2LOST                   244
#define FRM_LD_F4D2LENGTH                 245
#define FRM_LD_F4D2LOST                   246
#define FRM_LD_F4F2COH                    247
#define FRM_LD_F4F2LENGTH                 248
#define FRM_LD_F4F2LOST                   249
#define FRM_LD_F4F2P429INVLD              250
#define FRM_LD_F4F2P434INVLD              251
#define FRM_LD_F4F2P437INVLD              252
#define FRM_LD_F4F2P438INVLD              253
#define FRM_LD_F4F2P490INVLD              254
#define FRM_LD_F4F2P491INVLD              255
#define FRM_LD_F4F2P492INVLD              256
#define FRM_LD_F50DLENGTH                 257
#define FRM_LD_F50DLOST                   258
#define FRM_LD_F50ECOH1                   259
#define FRM_LD_F50ECOH2                   260
#define FRM_LD_F50ECOH3                   261
#define FRM_LD_F50ELENGTH                 262
#define FRM_LD_F50ELOST                   263
#define FRM_LD_F50EP046INVLD              264
#define FRM_LD_F50EP210INVLD              265
#define FRM_LD_F50EPM1386INVLD            266
#define FRM_LD_F532COH                    267
#define FRM_LD_F532LENGTH                 268
#define FRM_LD_F532LOST                   269
#define FRM_LD_F532PM1414INVLD            270
#define FRM_LD_F532PM1415INVLD            271
#define FRM_LD_F532PM1416INVLD            272
#define FRM_LD_F552BISP015INVLD           273
#define FRM_LD_F552BISP325INVLD           274
#define FRM_LD_F552BISP326INVLD           275
#define FRM_LD_F552COH                    276
#define FRM_LD_F552LENGTH                 277
#define FRM_LD_F552LOST                   278
#define FRM_LD_F552P255INVLD              279
#define FRM_LD_F552P256INVLD              280
#define FRM_LD_F552P257INVLD              281
#define FRM_LD_F572COH                    282
#define FRM_LD_F572LENGTH                 283
#define FRM_LD_F572LOST                   284
#define FRM_LD_F572PM1360INVLD            285
#define FRM_LD_F57CCOH                    286
#define FRM_LD_F57CLENGTH                 287
#define FRM_LD_F57CLOST                   288
#define FRM_LD_F57CPM1418INVLD            289
#define FRM_LD_F592COH                    290
#define FRM_LD_F592LENGTH                 291
#define FRM_LD_F592LOST                   292
#define FRM_LD_F592P272INVLD              293
#define FRM_LD_F592P273INVLD              294
#define FRM_LD_F592P349INVLD              295
#define FRM_LD_F592P418INVLD              296
#define FRM_LD_F592P419INVLD              297
#define FRM_LD_F592P420INVLD              298
#define FRM_LD_F592P421INVLD              299
#define FRM_LD_F5B2COH                    300
#define FRM_LD_F5B2LENGTH                 301
#define FRM_LD_F5B2LOST                   302
#define FRM_LD_F5B2P146INVLD              303
#define FRM_LD_F612COH                    304
#define FRM_LD_F612LENGTH                 305
#define FRM_LD_F612LOST                   306
#define FRM_LD_F612P260INVLD              307
#define FRM_LD_F612P436INVLD              308
#define FRM_LD_F612P705INVLD              309
#define FRM_LD_F7F2COH                    310
#define FRM_LD_F7F2LENGTH                 311
#define FRM_LD_F7F2LOST                   312
#define FRM_LD_F7F2P015BISINVLD           313
#define FRM_LD_F7F2P146BISINVLD           314
#define FRM_LD_FCTCLUP                    315
#define FRM_LD_FLASHCHK                   316
#define FRM_LD_FLDCOH_PDSTHR              317
#define FRM_LD_FRQ_PROPFUPMP              318
#define FRM_LD_FSFBLOCKCLS                319
#define FRM_LD_FSFBLOCKOP                 320
#define FRM_LD_GRAVSCP_PROPFUPMP          321
#define FRM_LD_GRD_OILLVLACQ              322
#define FRM_LD_GRD_PACMES                 323
#define FRM_LD_GRD_PAIREXT                324
#define FRM_LD_GRD_PAIREXTOLD             325
#define FRM_LD_GRD_PBRKASI                326
#define FRM_LD_GRD_PDSTHR                 327
#define FRM_LD_GRD_PRELBRKASI             328
#define FRM_LD_GRD_RCLUPEDPRSSMES         329
#define FRM_LD_GRD_TAIRMES                330
#define FRM_LD_GRD_TCOMES                 331
#define FRM_LD_HHIT_NOISEADP              332
#define FRM_LD_HI_AENG                    333
#define FRM_LD_HI_DMPVLVCMD               334
#define FRM_LD_HI_DRVRFAN1                335
#define FRM_LD_HI_DRVRFAN2                336
#define FRM_LD_HI_DRVRSENO2DS             337
#define FRM_LD_HI_DRVRSENO2US             338
#define FRM_LD_HI_NENG                    339
#define FRM_LD_HI_PACMES                  340
#define FRM_LD_HI_UBATTMES                341
#define FRM_LD_HI_WGCCMD                  342
#define FRM_LD_HICSTRDRV                  343
#define FRM_LD_HITALT_ALTCTL              344
#define FRM_LD_HITOOTHCOH_CKSTS           345
#define FRM_LD_HIVLVACTEXDRV              346
#define FRM_LD_HIVLVACTINDRV              347
#define FRM_LD_HSLD_NOISEADP              348
#define FRM_LD_IDCBLBYCND                 349
#define FRM_LD_IMAXVLVACTEX               350
#define FRM_LD_IMAXVLVACTIN               351
#define FRM_LD_IMMOCODNOTREAD             352
#define FRM_LD_INHCHKINITSFTY             353
#define FRM_LD_INHENGSTOPSTT              354
#define FRM_LD_INHTHR_CPUSFTY             355
#define FRM_LD_INV_CALID                  356
#define FRM_LD_INV_VARCOD                 357
#define FRM_LD_INVCOH_BRKPED              358
#define FRM_LD_INVLD_UDFTSTACMD           359
#define FRM_LD_IRVECU                     360
#define FRM_LD_IRVEM                      361
#define FRM_LD_IRVSTT                     362
#define FRM_LD_IRVVSCTL                   363
#define FRM_LD_IUPRSYNT1                  364
#define FRM_LD_IUPRSYNT2                  365
#define FRM_LD_IUPRSYNT3                  366
#define FRM_LD_LGENGRSTRTINH              367
#define FRM_LD_LHIT_NOISEADP              368
#define FRM_LD_LIHREQ1                    369
#define FRM_LD_LIHREQ2                    370
#define FRM_LD_LINBLOCKEDBUS              371
#define FRM_LD_LO_DMPVLVCMD               372
#define FRM_LD_LO_DRVRFAN1                373
#define FRM_LD_LO_DRVRFAN2                374
#define FRM_LD_LO_DRVRSENO2DS             375
#define FRM_LD_LO_DRVRSENO2US             376
#define FRM_LD_LO_PACMES                  377
#define FRM_LD_LO_UBATTMES                378
#define FRM_LD_LO_UBATTSPC                379
#define FRM_LD_LO_WGCCMD                  380
#define FRM_LD_LOCSTRDRV                  381
#define FRM_LD_LOFULVL                    382
#define FRM_LD_LOSTMISFROUGHNSROAD        383
#define FRM_LD_LOVLVACTEXDRV              384
#define FRM_LD_LOVLVACTINDRV              385
#define FRM_LD_LRNENDSTOPVLVACTEX         386
#define FRM_LD_LRNENDSTOPVLVACTIN         387
#define FRM_LD_LRNFAILIMVLVACTEX          388
#define FRM_LD_LRNFAILIMVLVACTIN          389
#define FRM_LD_LSLD_NOISEADP              390
#define FRM_LD_MAINWKUDISRD               391
#define FRM_LD_MAINWKUINCST               392
#define FRM_LD_MAP_PROPFUPMP              393
#define FRM_LD_MAX_PAIREXT                394
#define FRM_LD_MAXABS_PUSTHR              395
#define FRM_LD_MCPFLASHCKS_CPU            396
#define FRM_LD_MCPRAMTEST_CPU             397
#define FRM_LD_MCWCKSCALC_CPU             398
#define FRM_LD_MCWFCTTEST_CPU             399
#define FRM_LD_MCWINITSFTYRSLT_CPU        400
#define FRM_LD_MECAALT_ALTCTL             401
#define FRM_LD_MIN_PAIREXT                402
#define FRM_LD_MISSTOOTHVLVACTEX          403
#define FRM_LD_MISSTOOTHVLVACTIN          404
#define FRM_LD_NB                         739
#define FRM_LD_NEGDIF_PUSTHRSEN           405
#define FRM_LD_NEGDIF1_PUSTHR             406
#define FRM_LD_NEGDIF2_PUSTHR             407
#define FRM_LD_NEGOFS_TAIRMES             408
#define FRM_LD_NOANSWCTLUNIT              409
#define FRM_LD_NOGAP_CKSTS                410
#define FRM_LD_NOSIGCK                    411
#define FRM_LD_NOSIGEXCM                  412
#define FRM_LD_NOSIGINCM                  413
#define FRM_LD_OBSADP                     414
#define FRM_LD_OC_BINHCRKALTHW            415
#define FRM_LD_OC_BLOWBY1                 416
#define FRM_LD_OC_BLOWBY2                 417
#define FRM_LD_OC_CTLPMPREQ               418
#define FRM_LD_OC_CTP1                    419
#define FRM_LD_OC_CTP2                    420
#define FRM_LD_OC_DML                     421
#define FRM_LD_OC_DRVRFAN1                422
#define FRM_LD_OC_DRVRFAN2                423
#define FRM_LD_OC_ECTREQ                  424
#define FRM_LD_OC_ENGSTOUTIDC             425
#define FRM_LD_OC_FUGAUGE                 426
#define FRM_LD_OC_HPPMPACTCMD             427
#define FRM_LD_OC_IGCOIL1CMD              428
#define FRM_LD_OC_IGCOIL2CMD              429
#define FRM_LD_OC_IGCOIL3CMD              430
#define FRM_LD_OC_IGCOIL4CMD              431
#define FRM_LD_OC_INJ1CMD                 432
#define FRM_LD_OC_INJ2CMD                 433
#define FRM_LD_OC_INJ3CMD                 434
#define FRM_LD_OC_INJ4CMD                 435
#define FRM_LD_OC_PROPFUPMP               436
#define FRM_LD_OC_PWRRLY                  437
#define FRM_LD_OC_TAIRMES                 438
#define FRM_LD_OC_TCOMES                  439
#define FRM_LD_OC_TRBWAPMP                440
#define FRM_LD_OC_UDSLS                   441
#define FRM_LD_OC_UUPLS                   442
#define FRM_LD_OILPRSSSDWNORNG            443
#define FRM_LD_OILPRSSSUPORNG             444
#define FRM_LD_OLDLRNVLVACTEX             445
#define FRM_LD_OLDLRNVLVACTIN             446
#define FRM_LD_ORNG_BNEUT                 447
#define FRM_LD_ORNG_CAT                   448
#define FRM_LD_ORNG_CATAPV                449
#define FRM_LD_ORNG_DSHEAT                450
#define FRM_LD_ORNG_DSPLAUSFCO            451
#define FRM_LD_ORNG_DSPLAUSFLD            452
#define FRM_LD_ORNG_FUGAUGE               453
#define FRM_LD_ORNG_FUGAUGELVL            454
#define FRM_LD_ORNG_KNKDIAG               455
#define FRM_LD_ORNG_LONGWINLRN            456
#define FRM_LD_ORNG_LONGWINLRNMAX         457
#define FRM_LD_ORNG_OXYAPVPERD            458
#define FRM_LD_ORNG_OXYSENSPERD           459
#define FRM_LD_ORNG_PDSTHR                460
#define FRM_LD_ORNG_RBLIRVLDLIM           461
#define FRM_LD_ORNG_RBLTMPLDLIM           462
#define FRM_LD_ORNG_RBLVLVPOSN            463
#define FRM_LD_ORNG_RCLUPEDPRSSMES        464
#define FRM_LD_ORNG_SHRTWINLRN            465
#define FRM_LD_ORNG_SHRTWINLRNMAX         466
#define FRM_LD_ORNG_SIGGRDDIAG            467
#define FRM_LD_ORNG_SPDVEH                468
#define FRM_LD_ORNG_TAIRMES               469
#define FRM_LD_ORNG_TIENGSTOP             470
#define FRM_LD_ORNG_USHEAT                471
#define FRM_LD_ORNG_USPLAUSFCO            472
#define FRM_LD_ORNG_USPLAUSFLD            473
#define FRM_LD_ORNG_VMES1                 474
#define FRM_LD_ORNG_VMES1_SFTY            475
#define FRM_LD_ORNG_VMES2                 476
#define FRM_LD_ORNG_VMES2_SFTY            477
#define FRM_LD_ORNG_VMES3                 478
#define FRM_LD_ORNG_VMES3_SFTY            479
#define FRM_LD_ORNG_VMES4                 480
#define FRM_LD_ORNG_VMES4_SFTY            481
#define FRM_LD_ORNGCUTOFFREQ              482
#define FRM_LD_ORNGCVLVACTEX              483
#define FRM_LD_ORNGCVLVACTIN              484
#define FRM_LD_ORNGDMGCATDTC1             485
#define FRM_LD_ORNGDMGCATDTC2             486
#define FRM_LD_ORNGDMGCATDTC3             487
#define FRM_LD_ORNGDMGCATDTC4             488
#define FRM_LD_ORNGDMGCATDTCALL           489
#define FRM_LD_ORNGDMGCATDTCGAZ1          490
#define FRM_LD_ORNGDMGCATDTCGAZ2          491
#define FRM_LD_ORNGDMGCATDTCGAZ3          492
#define FRM_LD_ORNGDMGCATDTCGAZ4          493
#define FRM_LD_ORNGDMGCATDTCGAZALL        494
#define FRM_LD_ORNGDMGCATMD1              495
#define FRM_LD_ORNGDMGCATMD2              496
#define FRM_LD_ORNGDMGCATMD3              497
#define FRM_LD_ORNGDMGCATMD4              498
#define FRM_LD_ORNGDMGCATMDALL            499
#define FRM_LD_ORNGDMGCATMDGAZ1           500
#define FRM_LD_ORNGDMGCATMDGAZ2           501
#define FRM_LD_ORNGDMGCATMDGAZ3           502
#define FRM_LD_ORNGDMGCATMDGAZ4           503
#define FRM_LD_ORNGDMGCATMDGAZALL         504
#define FRM_LD_ORNGGCCLU                  505
#define FRM_LD_ORNGGCMINCLU               506
#define FRM_LD_ORNGGCNEUT                 507
#define FRM_LD_ORNGGEARENACLU             508
#define FRM_LD_ORNGGEARMINCLU             509
#define FRM_LD_ORNGGEARNEUT               510
#define FRM_LD_ORNGHIDRAGRED              511
#define FRM_LD_ORNGHINEUT                 512
#define FRM_LD_ORNGHITOILESTIM            513
#define FRM_LD_ORNGHVLVACTEX              514
#define FRM_LD_ORNGHVLVACTIN              515
#define FRM_LD_ORNGIFRZ_PFUCTL            516
#define FRM_LD_ORNGINTR                   517
#define FRM_LD_ORNGLFBK_AFL               518
#define FRM_LD_ORNGLFBK_AFR               519
#define FRM_LD_ORNGLFBKGAS_AFL            520
#define FRM_LD_ORNGLFBKGAS_AFR            521
#define FRM_LD_ORNGLODRAGRED              522
#define FRM_LD_ORNGLONEUT                 523
#define FRM_LD_ORNGMAX_PFUCTL             524
#define FRM_LD_ORNGMISFEMI1               525
#define FRM_LD_ORNGMISFEMI2               526
#define FRM_LD_ORNGMISFEMI3               527
#define FRM_LD_ORNGMISFEMI4               528
#define FRM_LD_ORNGMISFEMIALL             529
#define FRM_LD_ORNGMISFEMIGAZ1            530
#define FRM_LD_ORNGMISFEMIGAZ2            531
#define FRM_LD_ORNGMISFEMIGAZ3            532
#define FRM_LD_ORNGMISFEMIGAZ4            533
#define FRM_LD_ORNGMISFEMIGAZALL          534
#define FRM_LD_ORNGMPLREQ                 535
#define FRM_LD_ORNGNEG_PFUCTL             536
#define FRM_LD_ORNGNEGDIFI_PFUCTL         537
#define FRM_LD_ORNGPFUENGST               538
#define FRM_LD_ORNGPOS_PFUCTL             539
#define FRM_LD_ORNGPOSDIFI_PFUCTL         540
#define FRM_LD_ORNGSERVO                  541
#define FRM_LD_ORNGSERVODIFNEG            542
#define FRM_LD_ORNGSERVODIFPOS            543
#define FRM_LD_ORNGSFTYDFTLIH             544
#define FRM_LD_ORNGSHIFTVLVACTEX          545
#define FRM_LD_ORNGSHIFTVLVACTIN          546
#define FRM_LD_ORNGSPDVLVACTEX            547
#define FRM_LD_ORNGSPDVLVACTIN            548
#define FRM_LD_ORNGSTOPREQ                549
#define FRM_LD_ORNGSTRTENGST              550
#define FRM_LD_ORNGSYNCENGST              551
#define FRM_LD_ORNGUNLOCKENGST            552
#define FRM_LD_OVLD_HPPMPACTCMD           553
#define FRM_LD_OVLD_INJ1CMD               554
#define FRM_LD_OVLD_INJ2CMD               555
#define FRM_LD_OVLD_INJ3CMD               556
#define FRM_LD_OVLD_INJ4CMD               557
#define FRM_LD_OVLD_THRCMD                558
#define FRM_LD_OVLDTHERMOTHR              559
#define FRM_LD_PLAUS_PUSTHRBOOST          560
#define FRM_LD_PLAUS_PUSTHRIDL            561
#define FRM_LD_POSDIF_PUSTHRSEN           562
#define FRM_LD_POSDIF1_PUSTHR             563
#define FRM_LD_POSDIF2_PUSTHR             564
#define FRM_LD_POSOFS_TAIRMES             565
#define FRM_LD_PRESMESFRZ                 566
#define FRM_LD_PRESTOHI                   567
#define FRM_LD_PRESTOLO                   568
#define FRM_LD_PROTADP                    569
#define FRM_LD_PWRLMRK                    570
#define FRM_LD_RATCONVTRACLC              571
#define FRM_LD_RCDLINESCG                 572
#define FRM_LD_READPININHTHR_CPU          573
#define FRM_LD_REDESLIM                   574
#define FRM_LD_RVLIH                      575
#define FRM_LD_RVSGEAR                    576
#define FRM_LD_SCG_AIREXTPRESACQ          577
#define FRM_LD_SCG_BINHCRKALTHW           578
#define FRM_LD_SCG_BLOWBY1                579
#define FRM_LD_SCG_BLOWBY2                580
#define FRM_LD_SCG_BNEUT                  581
#define FRM_LD_SCG_CTLPMPREQ              582
#define FRM_LD_SCG_CTP1                   583
#define FRM_LD_SCG_CTP2                   584
#define FRM_LD_SCG_DML                    585
#define FRM_LD_SCG_ECTREQ                 586
#define FRM_LD_SCG_ENGSTOUTIDC            587
#define FRM_LD_SCG_FUGAUGE                588
#define FRM_LD_SCG_INJ1CMD                589
#define FRM_LD_SCG_INJ2CMD                590
#define FRM_LD_SCG_INJ3CMD                591
#define FRM_LD_SCG_INJ4CMD                592
#define FRM_LD_SCG_OILLVLACQ              593
#define FRM_LD_SCG_PBRKASI                594
#define FRM_LD_SCG_PDSTHRMES              595
#define FRM_LD_SCG_PED1                   596
#define FRM_LD_SCG_PED2                   597
#define FRM_LD_SCG_PFUACQ                 598
#define FRM_LD_SCG_POILMES                599
#define FRM_LD_SCG_PRELBRKASI             600
#define FRM_LD_SCG_PROPFUPMP              601
#define FRM_LD_SCG_PSPGPRES               602
#define FRM_LD_SCG_PWRRLY                 603
#define FRM_LD_SCG_RCLUPEDPRSSMES         604
#define FRM_LD_SCG_TAIRMES                605
#define FRM_LD_SCG_TCOMES                 606
#define FRM_LD_SCG_TECUACQ                607
#define FRM_LD_SCG_TRBWAPMP               608
#define FRM_LD_SCG_UDFTSTACMD             609
#define FRM_LD_SCG_UDSLS                  610
#define FRM_LD_SCG_UUPLS                  611
#define FRM_LD_SCG_VSSNWACVREQ            612
#define FRM_LD_SCGACCPSWT                 613
#define FRM_LD_SCGPOSNSNSR1               614
#define FRM_LD_SCGPOSNSNSR2               615
#define FRM_LD_SCP_AIREXTPRESACQ          616
#define FRM_LD_SCP_BINHCRKALTHW           617
#define FRM_LD_SCP_BLOWBY1                618
#define FRM_LD_SCP_BLOWBY2                619
#define FRM_LD_SCP_BNEUT                  620
#define FRM_LD_SCP_CTLPMPREQ              621
#define FRM_LD_SCP_CTP1                   622
#define FRM_LD_SCP_CTP2                   623
#define FRM_LD_SCP_DML                    624
#define FRM_LD_SCP_ECTREQ                 625
#define FRM_LD_SCP_ENGSTOUTIDC            626
#define FRM_LD_SCP_HPPMPACTCMD            627
#define FRM_LD_SCP_IGCOIL1CMD             628
#define FRM_LD_SCP_IGCOIL2CMD             629
#define FRM_LD_SCP_IGCOIL3CMD             630
#define FRM_LD_SCP_IGCOIL4CMD             631
#define FRM_LD_SCP_INJ1CMD                632
#define FRM_LD_SCP_INJ2CMD                633
#define FRM_LD_SCP_INJ3CMD                634
#define FRM_LD_SCP_INJ4CMD                635
#define FRM_LD_SCP_OILLVLACQ              636
#define FRM_LD_SCP_PBRKASI                637
#define FRM_LD_SCP_PDSTHRMES              638
#define FRM_LD_SCP_PFUACQ                 639
#define FRM_LD_SCP_POILMES                640
#define FRM_LD_SCP_PRELBRKASI             641
#define FRM_LD_SCP_PROPFUPMP              642
#define FRM_LD_SCP_PSPGPRES               643
#define FRM_LD_SCP_PWRRLY                 644
#define FRM_LD_SCP_RCLUPEDPRSSMES         645
#define FRM_LD_SCP_TAIRMES                646
#define FRM_LD_SCP_TCOMES                 647
#define FRM_LD_SCP_TECUACQ                648
#define FRM_LD_SCP_TRBWAPMP               649
#define FRM_LD_SCP_UDFTSTACMD             650
#define FRM_LD_SCP_UDSLS                  651
#define FRM_LD_SCP_UUPLS                  652
#define FRM_LD_SCP_VSSNWACVREQ            653
#define FRM_LD_SCPACCPSWT                 654
#define FRM_LD_SCPOC_PED1                 655
#define FRM_LD_SCPOC_PED2                 656
#define FRM_LD_SCPPOSNSNSR1               657
#define FRM_LD_SCPPOSNSNSR2               658
#define FRM_LD_SERVOERRVLVACTEX           659
#define FRM_LD_SERVOERRVLVACTIN           660
#define FRM_LD_SFTYCHKPT_PFCMNG           661
#define FRM_LD_SFTYORNGAMT                662
#define FRM_LD_SFTYORNGAT                 663
#define FRM_LD_SIGLOSSCK                  664
#define FRM_LD_SIGLOSSEXCM                665
#define FRM_LD_SIGLOSSINCM                666
#define FRM_LD_SLOWC1VLVACTEX             667
#define FRM_LD_SLOWC1VLVACTIN             668
#define FRM_LD_SLOWC2VLVACTEX             669
#define FRM_LD_SLOWC2VLVACTIN             670
#define FRM_LD_SLOWH1VLVACTEX             671
#define FRM_LD_SLOWH1VLVACTIN             672
#define FRM_LD_SLOWH2VLVACTEX             673
#define FRM_LD_SLOWH2VLVACTIN             674
#define FRM_LD_SPDVEHCLC                  675
#define FRM_LD_STAACVTHD1                 676
#define FRM_LD_STAACVTHD2                 677
#define FRM_LD_STABCOH_PDSTHR             678
#define FRM_LD_STACMD                     679
#define FRM_LD_STACMDINFO                 680
#define FRM_LD_STAELCMD                   681
#define FRM_LD_STALLCOH_PDSTHR            682
#define FRM_LD_STALLCOH_TAIRMES           683
#define FRM_LD_STFULVLDFT                 684
#define FRM_LD_STUCK_CLUST                685
#define FRM_LD_STUCK_HPSENS               686
#define FRM_LD_STUCK_MAINRLY              687
#define FRM_LD_STUCK_PWRRLY               688
#define FRM_LD_STUCKACCP                  689
#define FRM_LD_STUCKACCPSWT               690
#define FRM_LD_STUCKCLS_DMPVLV            691
#define FRM_LD_STUCKCLS_PTRBACT           692
#define FRM_LD_STUCKH1VLVACTEX            693
#define FRM_LD_STUCKH1VLVACTIN            694
#define FRM_LD_STUCKH2VLVACTEX            695
#define FRM_LD_STUCKH2VLVACTIN            696
#define FRM_LD_STUCKH3VLVACTEX            697
#define FRM_LD_STUCKH3VLVACTIN            698
#define FRM_LD_STUCKHVLVACTEX             699
#define FRM_LD_STUCKHVLVACTIN             700
#define FRM_LD_STUCKMEC                   701
#define FRM_LD_STUCKOP_DMPVLV             702
#define FRM_LD_STUCKOP_INJRCYL1           703
#define FRM_LD_STUCKOP_INJRCYL2           704
#define FRM_LD_STUCKOP_INJRCYL3           705
#define FRM_LD_STUCKOP_INJRCYL4           706
#define FRM_LD_STUCKOP_PTRBACT            707
#define FRM_LD_SYNCMON_CPU                708
#define FRM_LD_SYNCMON_CPUSFTY            709
#define FRM_LD_TCOBLOCK                   710
#define FRM_LD_TCOOVERESTIM               711
#define FRM_LD_TCOSLOWRISE                712
#define FRM_LD_TCOUNDESTIM                713
#define FRM_LD_TCOWARN                    714
#define FRM_LD_TDCDIAGVLVACTEX            715
#define FRM_LD_TDCDIAGVLVACTIN            716
#define FRM_LD_THERMOSTUCKCLS             717
#define FRM_LD_THERMOSTUCKOP              718
#define FRM_LD_THR_CPU                    719
#define FRM_LD_THRCOH_PDSTHR              720
#define FRM_LD_TOOTHCOH_CKSTS             721
#define FRM_LD_TQALT                      722
#define FRM_LD_TQALTRV                    723
#define FRM_LD_TRCK_TCOMES                724
#define FRM_LD_UNVLD_STFANC               725
#define FRM_LD_USTHRPRSSSDOWN             726
#define FRM_LD_USTHRPRSSSUP               727
#define FRM_LD_VSLIM                      728
#define FRM_LD_VSLIMBODY                  729
#define FRM_LD_VSMAX                      730
#define FRM_LD_VSMAXP                     731
#define FRM_LD_VSREG                      732
#define FRM_LD_VSREGBODY                  733
#define FRM_LD_VSREGVEH                   734
#define FRM_LD_WRGANSWCTLUNIT             735
#define FRM_LD_WUP_TCOMES                 736
#define FRM_LD_ZEROFRAMECNTDFT            737
#define FRM_LD_ZZEND_BIDON                738
#define FRM_NB_EVOL_STDGO_AUTORISED       50
#define FRM_NB_MAX_LD_TO_FRM_TAB          17206
#define FRM_u8ENA_TYP_ACV_FORCE_FALSE     1
#define FRM_u8ENA_TYP_ACV_FORCE_TRUE      2
#define FRM_u8ENA_TYP_ACV_LIBRE           0
#define FRM_u8OBD_DFT_FALSE               0
#define FRM_u8OBD_DFT_TRUE                16
#define FRM_u8SNG_DFT_FALSE               0
#define FRM_u8SNG_DFT_TRUE                1

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  FRM_abAuthTypCc_NameVar_C[FRM_ABAUTHTYPCC_NAMEVAR_C_LNS];
extern const boolean  FRM_bEnaFid_C;
extern const uint8  FRM_au8EnaTypAcvOptRvCcDd_C[FRM_AU8ENATYPACVOPTRVCCDD_C_LNS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean FRM_abDftTypCc_NameVar[FRM_ABDFTTYPCC_NAMEVAR_LNS];
extern boolean FRM_abRawTypAcvOptRvCcDd[FRM_ABRAWTYPACVOPTRVCCDD_LNS];
extern boolean FRM_abTypAcvOptRvCcDd[FRM_ABTYPACVOPTRVCCDD_LNS];
extern uint8 FRM_au8DU[FRM_AU8DU_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FRM_vidDemInit(void);
void FRM_vidF01_PrmDft_Init(uint16 u16Index, uint8 u8StatusOld, uint8 u8Status);
void FRM_vidF02_FidMng_F01_FRM_RawDft__iBattMaxCkg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__iBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__rBattSoC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__resBattIt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__tBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattMinCkg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattOc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattRstrt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft__uBattStrt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AaStart_Bidon(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AbsEspMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AccelCoh_BrkPed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AccelCoh_BrkPedBVH2p(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AccP_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffEGRVlvLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs1Lim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs2Lim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfs3Lim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpArEffThrOfsLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpClsExOfsLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpInjOfsLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpIvsInjConLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpOpInOfsLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AdpSlopInjConLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AirPrssExtSdwn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AirPrssExtSup(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Algo_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Algo_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AltAbsentEcu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AntiBoil(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ArDeltaCorLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_AsicGdiFailure(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Block_Strtr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Blt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost1_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost2_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost3_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Boost4_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_BsiMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_BusOff(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_BvaMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CAVMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_iBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_tBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ChkBattSys_uBattClc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CksRom_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Clk_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Clk_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ClnErrVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ClnErrVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ClsdRly_StFanC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ClsIdlCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CluDmgAfts(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdCVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdCVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdHVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CmdHVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_bModSptReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_CluSt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_EepPwrl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_EepReinit(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_ExCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_HPSens(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_InCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_pBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_Ped(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_PFuAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_rAccP(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_spdVeh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_stCluAC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2HiSpd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2LoSpd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StFanB2NoSpd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_stPwrAC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_StrtLock(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Coh_tiEngStop(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CohAccPSwt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit2_stDftOBD(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit3_stDftOBD(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit4_stDftOBD(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CohBit7_stDftOBD(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CohPosnSnsr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ComAlt_AltCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ComSpi_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ComSpi_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ComTout_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ComTout_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CorLoss(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CorSpCur(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CoSysDfct(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Cpt_ThrCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CritSc_StFanC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CrkCoh_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CrsCtlDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_CutReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DecelCoh_BrkPed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DecelCoh_BrkPedBVH2p(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DegMod_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Dft_Info_Crash(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftCVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftCVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftEeprom(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFu_Afl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFu_Afr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFuGas_Afl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftFuGas_Afr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftHVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftHVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftObjEep(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftOnOffHi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftOnOffLo(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftOscCfm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegHi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegHiCfm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegLo(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftRegLoCfm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2_Afl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2_Afr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2Gas_Afl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenO2Gas_Afr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenr_AccP(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DftSenr_Thr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg1VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg1VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg2VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifNeg2VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos1VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos1VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos2VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DifPos2VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DiraMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DistSig(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DmtrMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_DrvTra(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ECI_StFanC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EcmMute(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_El_StFanC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElChkConsDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsCohVSMaxp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSMaxp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsDefDftVSReg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsInitDftVSReg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsVarDftVSLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElConsVarDftVSReg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElCptTraBsiDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElDftCrsCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElDiagInhPin0_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElDiagInhPin1_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElecAlt_AltCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElFrameCntIncDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ElInfBsiDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopOldVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopOldVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopReq1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EndStopReq2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EngOilOverHeat(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohCk(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohExCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EngSpdCohInCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Etat_Alt1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Etat_Alt2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_EvenFrameCntDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ExtLeak_FuSys(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F305Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F305Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F305Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F305P537Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F305P538Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP263Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP264Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP265Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F30DP266Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F329Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F329Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F329Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F329P445Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F329ProcFailed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349P007Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349P055Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349P440Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F349ProcFailed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DCoh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DPM1413Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F34DProcFailed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DCoh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DP010Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DP052Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F38DProcFailed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADCoh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3ADLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P291Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P363Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P364Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P482Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9P483Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3C9ProcFailed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDCoh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP225Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP319Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F3CDP515Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F412Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F412Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F412P040Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F432Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DCoh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DFP0535Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP330Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP331Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F44DP354Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F489Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F489Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F489Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F489P102Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F489P218Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F489P254Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F492Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F492Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F495Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F495Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4B2Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4B2Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4D2Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4D2Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P429Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P434Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P437Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P438Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P490Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P491Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F4F2P492Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50DLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50DLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ECoh3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ELength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50ELost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50EP046Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50EP210Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F50EPM1386Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F532Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F532Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F532Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1414Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1415Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F532PM1416Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP015Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP325Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552bisP326Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552P255Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552P256Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F552P257Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F572Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F572Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F572Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F572PM1360Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CCoh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CLength(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CLost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F57CPM1418Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P272Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P273Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P349Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P418Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P419Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P420Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F592P421Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F5B2P146Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F612Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F612Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F612Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F612P260Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F612P436Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F612P705Invld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Coh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Length(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2Lost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2P015bisInvld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_F7F2P146bisInvld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_FctCluP(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_FlashChk(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_FldCoh_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Frq_PropFuPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_FSFBlockCls(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_FSFBlockOp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_GravScp_PropFuPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_OilLvlAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pACMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pAirExt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pAirExtOld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_pRelBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_rCluPedPrssMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Grd_tCoMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HHit_NoiseAdp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_aEng(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DmpVlvCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrFan1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrFan2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrSenO2Ds(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_DrvrSenO2Us(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_nEng(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_pACMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_uBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Hi_WgcCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HiCstrDrv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HiTAlt_AltCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HiToothCoh_CkSts(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HiVlvActExDrv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HiVlvActInDrv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_HSld_NoiseAdp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IdcBlbyCnd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IMaxVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IMaxVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ImmoCodNotRead(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_InhChkInitSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_InhEngStopSTT(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_InhThr_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Inv_CalId(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Inv_VarCod(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_InvCoh_BrkPed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Invld_uDftStaCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvECU(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvEM(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvSTT(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IrvVSCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_IUPRSynt3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LgEngRStrtInh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LHit_NoiseAdp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LihReq1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LihReq2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LinBlockedBus(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DmpVlvCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrFan1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrFan2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrSenO2Ds(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_DrvrSenO2Us(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_pACMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_uBattMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_uBattSpc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Lo_WgcCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LoCstrDrv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LoFuLvl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LostMisfRoughnsRoad(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LoVlvActExDrv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LoVlvActInDrv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnEndStopVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnEndStopVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnFaiLimVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LrnFaiLimVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_LSld_NoiseAdp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_MainWkuDisrd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_MainWkuIncst(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Map_PropFuPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Max_pAirExt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_MaxAbs_pUsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_McpFlashCks_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_McpRAMTest_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_McwCksCalc_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_McwFctTest_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_McwInitSftyRslt_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_MecaAlt_AltCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Min_pAirExt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_MissToothVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_MissToothVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif_pUsThrSen(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif1_pUsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NegDif2_pUsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NegOfs_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NoAnswCtlUnit(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NoGap_CkSts(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigCk(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigExCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_NoSigInCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ObsAdp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_bInhCrkAltHw(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_BlowBy1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_BlowBy2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CtlPmpReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CTP1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_CTP2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Dml(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_DrvrFan1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_DrvrFan2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_ECTReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_EngStOutIdc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_FuGauge(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_HPPmpActCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil1Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil2Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil3Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_IgCoil4Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj1Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj2Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj3Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_Inj4Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_PropFuPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_PwrRly(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_tCoMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_TrbWaPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_uDsLs(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Oc_uUpLs(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_OilPrssSdwnORng(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_OilPrssSupORng(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_OldLrnVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_OldLrnVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_bNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_Cat(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_CatApv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsHeat(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsPlausFco(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_DsPlausFld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_FuGauge(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_FuGaugeLvl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_KnkDiag(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_LongWinLrn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_LongWinLrnMax(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_OxyApvPerd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_OxySensPerd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblIrvLdLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblTmpLdLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_RblVlvPosn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_rCluPedPrssMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_ShrtWinLrn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_ShrtWinLrnMax(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_SigGrdDiag(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_spdVeh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_tiEngStop(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsHeat(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsPlausFco(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_UsPlausFld(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes1_Sfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes2_Sfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes3_Sfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORng_vMes4_Sfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCutOffReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngCVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTC4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCAll(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGaz4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatDTCGazAll(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMD4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDAll(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGaz4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngDmgCatMDGazAll(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcClu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcMinClu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGcNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearEnaClu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearMinClu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngGearNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiDragRed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHiTOilEstim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngHVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngIFrz_PFuCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngIntr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbk_Afl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbk_Afr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbkGas_Afl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLfbkGas_Afr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLoDragRed(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngLoNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMax_PFuCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmi4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiAll(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGaz4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMisfEmiGazAll(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngMplReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngNeg_PFuCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngNegDifI_PFuCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPFuEngSt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPos_PFuCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngPosDifI_PFuCtl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServo(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServoDifNeg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngServoDifPos(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSftyDftLih(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngShiftVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngShiftVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSpdVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSpdVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngStopReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngStrtEngSt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngSyncEngSt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ORngUnlockEngSt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_HPPmpActCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj1Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj2Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj3Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_Inj4Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Ovld_ThrCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_OvldThermoThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Plaus_pUsThrBoost(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Plaus_pUsThrIdl(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif_pUsThrSen(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif1_pUsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PosDif2_pUsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PosOfs_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PresMesFrz(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PresToHi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PresToLo(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ProtAdp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_PwrlMrk(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_RatConvTraClc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_RCDLineScg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ReadPinInhThr_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_RedESLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_RvLih(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_RvsGear(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_AirExtPresAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_bInhCrkAltHw(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_BlowBy1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_BlowBy2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_bNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CtlPmpReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CTP1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_CTP2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Dml(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_ECTReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_EngStOutIdc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_FuGauge(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj1Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj2Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj3Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Inj4Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_OilLvlAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pDsThrMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Ped1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_Ped2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PFuAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pOilMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pRelBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PropFuPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_pSpgPres(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_PwrRly(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_rCluPedPrssMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tCoMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_tECUAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_TrbWaPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uDftStaCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uDsLs(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_uUpLs(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scg_VSSNwAcvReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScgAccPSwt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScgPosnSnsr1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScgPosnSnsr2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_AirExtPresAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_bInhCrkAltHw(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_BlowBy1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_BlowBy2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_bNeut(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CtlPmpReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CTP1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_CTP2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Dml(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_ECTReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_EngStOutIdc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_HPPmpActCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil1Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil2Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil3Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_IgCoil4Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj1Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj2Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj3Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_Inj4Cmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_OilLvlAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pDsThrMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PFuAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pOilMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pRelBrkAsi(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PropFuPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_pSpgPres(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_PwrRly(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_rCluPedPrssMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tCoMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_tECUAcq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_TrbWaPmp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uDftStaCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uDsLs(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_uUpLs(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Scp_VSSNwAcvReq(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpAccPSwt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpOc_Ped1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpOc_Ped2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpPosnSnsr1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ScpPosnSnsr2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ServoErrVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ServoErrVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SftyChkPt_PfcMng(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SftyORngAMT(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SftyORngAT(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossCk(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossExCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SigLossInCm(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC1VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC1VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC2VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowC2VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH1VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH1VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH2VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SlowH2VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SpdVehClc(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StaAcvThd1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StaAcvThd2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StabCoh_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StaCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StaCmdInfo(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StaElCmd(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StallCoh_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StallCoh_tAirMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StFuLvlDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_CluSt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_HPSens(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_MainRly(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Stuck_PwrRly(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckAccP(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckAccPSwt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckCls_DmpVlv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckCls_pTrbAct(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH1VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH1VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH2VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH2VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH3VlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckH3VlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckHVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckHVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckMec(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_DmpVlv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl1(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl2(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl3(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_InjrCyl4(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_StuckOp_pTrbAct(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SyncMon_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_SyncMon_CpuSfty(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoBlock(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoOverEstim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoSlowRise(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoUndEstim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TCoWarn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TDCDiagVlvActEx(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TDCDiagVlvActIn(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ThermoStuckCls(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ThermoStuckOp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Thr_Cpu(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ThrCoh_pDsThr(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ToothCoh_CkSts(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_TqAlt(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_tqAltRv(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Trck_tCoMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_UnVld_StFanC(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_UsThrPrssSdown(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_UsThrPrssSup(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSLim(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSLimBody(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSMax(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSMaxp(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSReg(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSRegBody(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_VSRegVeh(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_WrgAnswCtlUnit(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_Wup_tCoMes(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ZeroFrameCntDft(void);
void FRM_vidF02_FidMng_F01_FRM_RawDft_ZzEnd_Bidon(void);
void FRM_vidF02_FidMng_F02_AcvTable(uint16 u16LDIndex);
void FRM_vidInit(void);
Std_ReturnType FRM_vidF03_EnaFid_Idx_Switch(uint16 u16FRMIndex, boolean  *bPermission);


#endif /* FRM_L_H */

/*-------------------------------- end of file -------------------------------*/
