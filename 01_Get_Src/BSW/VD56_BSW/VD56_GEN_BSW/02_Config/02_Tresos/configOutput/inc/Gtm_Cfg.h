
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2011)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_Cfg.h                                                    **
**                                                                            **
**  VERSION   : 0.0.6                                                         **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:17                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver                                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef GTMCFG_H
#define GTMCFG_H
#define MCU_INITCHECK_API (STD_ON)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*****************************************************************************
**                                 GPT                                      **
******************************************************************************/

#define  GTM_GPT_MODULE_USED                        (STD_ON)
/*****************************************************************************
**                                 ICU                                      **
******************************************************************************/
#define GTM_ICU_MODULE_USED                          (STD_ON)
/*****************************************************************************
**                                 PWM                                      **
******************************************************************************/
#define GTM_PWM_MODULE_USED                          (STD_ON)

/* TIM, TOM and ATOM usage */
#define GTM_TOM_USED_BY_OTHER_DRIVERS    (STD_ON)
#define GTM_ATOM_USED_BY_OTHER_DRIVERS   (STD_ON)
#define GTM_TIM_USED_BY_OTHER_DRIVERS    (STD_ON)



/* Resource Availability  */
#define GTM_TIM_MODULE  (0U)
#define GTM_NO_OF_TIM_MODULES   (6U)
#define GTM_CHANNELS_PER_TIM_MODULE    (8U)
#define GTM_MAX_TIM_CHANNELS                                                  \
                          (GTM_NO_OF_TIM_MODULES * GTM_CHANNELS_PER_TIM_MODULE)

#define GTM_TOM_MODULE  (1U)
#define GTM_NO_OF_TOM_MODULES   (5U)
#define GTM_NO_OF_TGC_PER_MODULE  (2U)
#define GTM_CHANNELS_PER_TOM_MODULE    (16U)
#define GTM_TOM_CHANNELS_PER_TGC   (8U)
#define GTM_MAX_TOM_CHANNELS                                                   \
                          (GTM_NO_OF_TOM_MODULES *  GTM_CHANNELS_PER_TOM_MODULE)

 
#define GTM_ATOM_MODULE  (2U)
#define GTM_NO_OF_ATOM_MODULES   (9U)
#define GTM_NO_OF_AGC_PER_MODULE  (1U)
#define GTM_CHANNELS_PER_ATOM_MODULE    (8U)
#define GTM_ATOM_CHANNELS_PER_AGC   (8U)
#define GTM_MAX_ATOM_CHANNELS                                                  \
                        (GTM_NO_OF_ATOM_MODULES *  GTM_CHANNELS_PER_ATOM_MODULE)


#define GTM_NO_OF_TBU_CHANNELS  (3U)
#define GTM_NUMBER_OF_BRC_SOURCE (12U)
#define GTM_NO_OF_AFD_CHANNELS (8U)
#define GTM_NO_OF_FIFO_CHANNELS (8U)
#define GTM_NO_OF_F2A_CHANNELS (GTM_NO_OF_FIFO_CHANNELS)
#define GTM_DPLL_NO_OF_ACTIONS (24U)
#define GTM_NO_OF_MCS_CHANNELS  (8U)
#define GTM_NO_OF_MCS_MODULES  (6U)
#define GTM_NO_OF_TOUTSEL_REGISTERS  (17U)
#define GTM_NO_SPE_MODULES (4U)
#define GTM_NO_OF_SPE_PATTERNS (8U)
#define GTM_NO_OF_MSC_SETS (6U)
#define GTM_NO_MSC_CONTROLS_PER_SET (4U)
#define GTM_NO_OF_MSC_MODULES (3U)  /* Please note, this is MSC and not MCS */
#define GTM_NO_OF_ADC_MODULES (12U)
#define GTM_ADC_CONN_PER_REGISTER (8U)
#define GTM_NO_OF_TTCAN_TRIGGERS (8U)


  /*Number of TOM, ATOM and TIM channels configured for notifications*/
#define GTM_NO_OF_TOM_CH_CONF_NOTIF (3U)
#define GTM_NO_OF_ATOM_CH_CONF_NOTIF (18U)
#define GTM_NO_OF_TIM_CH_CONF_NOTIF (2U)

/* Generating defines for Global Channel Numbers */
#define GTM_TIM0_CHANNEL0   (0U)
#define GTM_TIM0_CHANNEL1   (1U)
#define GTM_TIM0_CHANNEL2   (2U)
#define GTM_TIM0_CHANNEL3   (3U)
#define GTM_TIM0_CHANNEL4   (4U)
#define GTM_TIM0_CHANNEL5   (5U)
#define GTM_TIM0_CHANNEL6   (6U)
#define GTM_TIM0_CHANNEL7   (7U)
#define GTM_TIM1_CHANNEL0   (8U)
#define GTM_TIM1_CHANNEL1   (9U)
#define GTM_TIM1_CHANNEL2   (10U)
#define GTM_TIM1_CHANNEL3   (11U)
#define GTM_TIM1_CHANNEL4   (12U)
#define GTM_TIM1_CHANNEL5   (13U)
#define GTM_TIM1_CHANNEL6   (14U)
#define GTM_TIM1_CHANNEL7   (15U)
#define GTM_TIM2_CHANNEL0   (16U)
#define GTM_TIM2_CHANNEL1   (17U)
#define GTM_TIM2_CHANNEL2   (18U)
#define GTM_TIM2_CHANNEL3   (19U)
#define GTM_TIM2_CHANNEL4   (20U)
#define GTM_TIM2_CHANNEL5   (21U)
#define GTM_TIM2_CHANNEL6   (22U)
#define GTM_TIM2_CHANNEL7   (23U)
#define GTM_TIM3_CHANNEL0   (24U)
#define GTM_TIM3_CHANNEL1   (25U)
#define GTM_TIM3_CHANNEL2   (26U)
#define GTM_TIM3_CHANNEL3   (27U)
#define GTM_TIM3_CHANNEL4   (28U)
#define GTM_TIM3_CHANNEL5   (29U)
#define GTM_TIM3_CHANNEL6   (30U)
#define GTM_TIM3_CHANNEL7   (31U)
#define GTM_TIM4_CHANNEL0   (32U)
#define GTM_TIM4_CHANNEL1   (33U)
#define GTM_TIM4_CHANNEL2   (34U)
#define GTM_TIM4_CHANNEL3   (35U)
#define GTM_TIM4_CHANNEL4   (36U)
#define GTM_TIM4_CHANNEL5   (37U)
#define GTM_TIM4_CHANNEL6   (38U)
#define GTM_TIM4_CHANNEL7   (39U)
#define GTM_TIM5_CHANNEL0   (40U)
#define GTM_TIM5_CHANNEL1   (41U)
#define GTM_TIM5_CHANNEL2   (42U)
#define GTM_TIM5_CHANNEL3   (43U)
#define GTM_TIM5_CHANNEL4   (44U)
#define GTM_TIM5_CHANNEL5   (45U)
#define GTM_TIM5_CHANNEL6   (46U)
#define GTM_TIM5_CHANNEL7   (47U)
#define GTM_TOM0_CHANNEL0   (48U)
#define GTM_TOM0_CHANNEL1   (49U)
#define GTM_TOM0_CHANNEL2   (50U)
#define GTM_TOM0_CHANNEL3   (51U)
#define GTM_TOM0_CHANNEL4   (52U)
#define GTM_TOM0_CHANNEL5   (53U)
#define GTM_TOM0_CHANNEL6   (54U)
#define GTM_TOM0_CHANNEL7   (55U)
#define GTM_TOM0_CHANNEL8   (56U)
#define GTM_TOM0_CHANNEL9   (57U)
#define GTM_TOM0_CHANNEL10   (58U)
#define GTM_TOM0_CHANNEL11   (59U)
#define GTM_TOM0_CHANNEL12   (60U)
#define GTM_TOM0_CHANNEL13   (61U)
#define GTM_TOM0_CHANNEL14   (62U)
#define GTM_TOM0_CHANNEL15   (63U)
#define GTM_TOM1_CHANNEL0   (64U)
#define GTM_TOM1_CHANNEL1   (65U)
#define GTM_TOM1_CHANNEL2   (66U)
#define GTM_TOM1_CHANNEL3   (67U)
#define GTM_TOM1_CHANNEL4   (68U)
#define GTM_TOM1_CHANNEL5   (69U)
#define GTM_TOM1_CHANNEL6   (70U)
#define GTM_TOM1_CHANNEL7   (71U)
#define GTM_TOM1_CHANNEL8   (72U)
#define GTM_TOM1_CHANNEL9   (73U)
#define GTM_TOM1_CHANNEL10   (74U)
#define GTM_TOM1_CHANNEL11   (75U)
#define GTM_TOM1_CHANNEL12   (76U)
#define GTM_TOM1_CHANNEL13   (77U)
#define GTM_TOM1_CHANNEL14   (78U)
#define GTM_TOM1_CHANNEL15   (79U)
#define GTM_TOM2_CHANNEL0   (80U)
#define GTM_TOM2_CHANNEL1   (81U)
#define GTM_TOM2_CHANNEL2   (82U)
#define GTM_TOM2_CHANNEL3   (83U)
#define GTM_TOM2_CHANNEL4   (84U)
#define GTM_TOM2_CHANNEL5   (85U)
#define GTM_TOM2_CHANNEL6   (86U)
#define GTM_TOM2_CHANNEL7   (87U)
#define GTM_TOM2_CHANNEL8   (88U)
#define GTM_TOM2_CHANNEL9   (89U)
#define GTM_TOM2_CHANNEL10   (90U)
#define GTM_TOM2_CHANNEL11   (91U)
#define GTM_TOM2_CHANNEL12   (92U)
#define GTM_TOM2_CHANNEL13   (93U)
#define GTM_TOM2_CHANNEL14   (94U)
#define GTM_TOM2_CHANNEL15   (95U)
#define GTM_TOM3_CHANNEL0   (96U)
#define GTM_TOM3_CHANNEL1   (97U)
#define GTM_TOM3_CHANNEL2   (98U)
#define GTM_TOM3_CHANNEL3   (99U)
#define GTM_TOM3_CHANNEL4   (100U)
#define GTM_TOM3_CHANNEL5   (101U)
#define GTM_TOM3_CHANNEL6   (102U)
#define GTM_TOM3_CHANNEL7   (103U)
#define GTM_TOM3_CHANNEL8   (104U)
#define GTM_TOM3_CHANNEL9   (105U)
#define GTM_TOM3_CHANNEL10   (106U)
#define GTM_TOM3_CHANNEL11   (107U)
#define GTM_TOM3_CHANNEL12   (108U)
#define GTM_TOM3_CHANNEL13   (109U)
#define GTM_TOM3_CHANNEL14   (110U)
#define GTM_TOM3_CHANNEL15   (111U)
#define GTM_TOM4_CHANNEL0   (112U)
#define GTM_TOM4_CHANNEL1   (113U)
#define GTM_TOM4_CHANNEL2   (114U)
#define GTM_TOM4_CHANNEL3   (115U)
#define GTM_TOM4_CHANNEL4   (116U)
#define GTM_TOM4_CHANNEL5   (117U)
#define GTM_TOM4_CHANNEL6   (118U)
#define GTM_TOM4_CHANNEL7   (119U)
#define GTM_TOM4_CHANNEL8   (120U)
#define GTM_TOM4_CHANNEL9   (121U)
#define GTM_TOM4_CHANNEL10   (122U)
#define GTM_TOM4_CHANNEL11   (123U)
#define GTM_TOM4_CHANNEL12   (124U)
#define GTM_TOM4_CHANNEL13   (125U)
#define GTM_TOM4_CHANNEL14   (126U)
#define GTM_TOM4_CHANNEL15   (127U)
#define GTM_ATOM0_CHANNEL0   (128U)
#define GTM_ATOM0_CHANNEL1   (129U)
#define GTM_ATOM0_CHANNEL2   (130U)
#define GTM_ATOM0_CHANNEL3   (131U)
#define GTM_ATOM0_CHANNEL4   (132U)
#define GTM_ATOM0_CHANNEL5   (133U)
#define GTM_ATOM0_CHANNEL6   (134U)
#define GTM_ATOM0_CHANNEL7   (135U)
#define GTM_ATOM1_CHANNEL0   (136U)
#define GTM_ATOM1_CHANNEL1   (137U)
#define GTM_ATOM1_CHANNEL2   (138U)
#define GTM_ATOM1_CHANNEL3   (139U)
#define GTM_ATOM1_CHANNEL4   (140U)
#define GTM_ATOM1_CHANNEL5   (141U)
#define GTM_ATOM1_CHANNEL6   (142U)
#define GTM_ATOM1_CHANNEL7   (143U)
#define GTM_ATOM2_CHANNEL0   (144U)
#define GTM_ATOM2_CHANNEL1   (145U)
#define GTM_ATOM2_CHANNEL2   (146U)
#define GTM_ATOM2_CHANNEL3   (147U)
#define GTM_ATOM2_CHANNEL4   (148U)
#define GTM_ATOM2_CHANNEL5   (149U)
#define GTM_ATOM2_CHANNEL6   (150U)
#define GTM_ATOM2_CHANNEL7   (151U)
#define GTM_ATOM3_CHANNEL0   (152U)
#define GTM_ATOM3_CHANNEL1   (153U)
#define GTM_ATOM3_CHANNEL2   (154U)
#define GTM_ATOM3_CHANNEL3   (155U)
#define GTM_ATOM3_CHANNEL4   (156U)
#define GTM_ATOM3_CHANNEL5   (157U)
#define GTM_ATOM3_CHANNEL6   (158U)
#define GTM_ATOM3_CHANNEL7   (159U)
#define GTM_ATOM4_CHANNEL0   (160U)
#define GTM_ATOM4_CHANNEL1   (161U)
#define GTM_ATOM4_CHANNEL2   (162U)
#define GTM_ATOM4_CHANNEL3   (163U)
#define GTM_ATOM4_CHANNEL4   (164U)
#define GTM_ATOM4_CHANNEL5   (165U)
#define GTM_ATOM4_CHANNEL6   (166U)
#define GTM_ATOM4_CHANNEL7   (167U)
#define GTM_ATOM5_CHANNEL0   (168U)
#define GTM_ATOM5_CHANNEL1   (169U)
#define GTM_ATOM5_CHANNEL2   (170U)
#define GTM_ATOM5_CHANNEL3   (171U)
#define GTM_ATOM5_CHANNEL4   (172U)
#define GTM_ATOM5_CHANNEL5   (173U)
#define GTM_ATOM5_CHANNEL6   (174U)
#define GTM_ATOM5_CHANNEL7   (175U)
#define GTM_ATOM6_CHANNEL0   (176U)
#define GTM_ATOM6_CHANNEL1   (177U)
#define GTM_ATOM6_CHANNEL2   (178U)
#define GTM_ATOM6_CHANNEL3   (179U)
#define GTM_ATOM6_CHANNEL4   (180U)
#define GTM_ATOM6_CHANNEL5   (181U)
#define GTM_ATOM6_CHANNEL6   (182U)
#define GTM_ATOM6_CHANNEL7   (183U)
#define GTM_ATOM7_CHANNEL0   (184U)
#define GTM_ATOM7_CHANNEL1   (185U)
#define GTM_ATOM7_CHANNEL2   (186U)
#define GTM_ATOM7_CHANNEL3   (187U)
#define GTM_ATOM7_CHANNEL4   (188U)
#define GTM_ATOM7_CHANNEL5   (189U)
#define GTM_ATOM7_CHANNEL6   (190U)
#define GTM_ATOM7_CHANNEL7   (191U)
#define GTM_ATOM8_CHANNEL0   (192U)
#define GTM_ATOM8_CHANNEL1   (193U)
#define GTM_ATOM8_CHANNEL2   (194U)
#define GTM_ATOM8_CHANNEL3   (195U)
#define GTM_ATOM8_CHANNEL4   (196U)
#define GTM_ATOM8_CHANNEL5   (197U)
#define GTM_ATOM8_CHANNEL6   (198U)
#define GTM_ATOM8_CHANNEL7   (199U)


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#endif
