/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Gtm_Local.h $                                              **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-10-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Include Standard Types */
#include "Std_Types.h"
#include "IfxGtm_regdef.h"

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

extern void Gtm_lBrcConfig(void);
extern void Gtm_lAdcConnectionsConfig(void);
extern void Gtm_SelectBrcDest(uint8 SourceNo, uint32 SelDest);
extern void Gtm_lTomComplexConfig(void);
extern void Gtm_lAtomComplexConfig(void);
extern void Gtm_lAtomClockSetting(void);
extern void Gtm_lTomClockSetting(void);


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* BRC structures added to easier the acces to BStep registers*/
/** Destination Channels For Input Channel */
/* BRC structures added to easier the acces to BStep registers*/
/** Destination Channels For Input Channel */
  typedef struct
  {
    unsigned int EN_DEST0: 1;               /** \brief [0:0] Enable BRC 
                                                   destination address 0 (rw) */
    unsigned int EN_DEST1: 1;               /** \brief [1:1] Enable BRC 
                                                 destination address 1 (rw) */
    unsigned int EN_DEST2: 1;               /** \brief [2:2] Enable BRC 
                                                 destination address 2 (rw) */
    unsigned int EN_DEST3: 1;               /** \brief [3:3] Enable BRC 
                                                 destination address 3 (rw) */
    unsigned int EN_DEST4: 1;               /** \brief [4:4] Enable BRC 
                                                  destination address 4 (rw) */
    unsigned int EN_DEST5: 1;               /** \brief [5:5] Enable BRC 
                                                  destination address 5 (rw) */
    unsigned int EN_DEST6: 1;               /** \brief [6:6] Enable BRC 
                                               destination address 6 (rw) */
    unsigned int EN_DEST7: 1;               /** \brief [7:7] Enable BRC 
                                                   destination address 7 (rw) */
    unsigned int EN_DEST8: 1;               /** \brief [8:8] Enable BRC 
                                                   destination address 8 (rw) */
    unsigned int EN_DEST9: 1;               /** \brief [9:9] Enable BRC 
                                                   destination address 9 (rw) */
    unsigned int EN_DEST10: 1;              /** \brief [10:10] Enable BRC 
                                                  destination address 10 (rw) */
    unsigned int EN_DEST11: 1;              /** \brief [11:11] Enable BRC 
                                                  destination address 11 (rw) */
    unsigned int EN_DEST12: 1;              /** \brief [12:12] Enable BRC 
                                                destination address 12 (rw) */
    unsigned int EN_DEST13: 1;              /** \brief [13:13] Enable BRC 
                                                  destination address 13 (rw) */
    unsigned int EN_DEST14: 1;              /** \brief [14:14] Enable BRC 
                                                  destination address 14 (rw) */
    unsigned int EN_DEST15: 1;              /** \brief [15:15] Enable BRC 
                                                  destination address 15 (rw) */
    unsigned int EN_DEST16: 1;              /** \brief [16:16] Enable BRC 
                                                  destination address 16 (rw) */
    unsigned int EN_DEST17: 1;              /** \brief [17:17] Enable BRC 
                                                  destination address 17 (rw) */
    unsigned int EN_DEST18: 1;              /** \brief [18:18] Enable BRC 
                                                  destination address 18 (rw) */
    unsigned int EN_DEST19: 1;              /** \brief [19:19] Enable BRC 
                                                  destination address 19 (rw) */
    unsigned int EN_DEST20: 1;              /** \brief [20:20] Enable BRC 
                                                  destination address 20 (rw) */
    unsigned int EN_DEST21: 1;              /** \brief [21:21] Enable BRC 
                                                  destination address 21 (rw) */
    unsigned int EN_TRASHBIN: 1;      /** \brief [22:22] Control trash 
                                                       bin functionality (rw) */
    unsigned int reserved_23: 9;
  } Ifx_GTM_BRC_SRC_DEST_Bits;

/** Destination Channels For Input Channel */
  typedef union
  {
    unsigned int U;
    signed int I;
    Ifx_GTM_BRC_SRC_DEST_Bits B;
  } Ifx_GTM_BRC_SRC_DEST;

/** Read Address For Input Channel */
  typedef struct
  {
    unsigned int ADDR: 9;           /** \brief [8:0] Source ARU address (rw) */
    unsigned int reserved_9: 3;
    unsigned int BRC_MODE: 1;  /** \brief [12:12] BRC Operation 
                                                             mode select (rw) */
    unsigned int reserved_13: 19;
  } Ifx_GTM_BRC_SRC_ADDR_Bits;

  typedef union
  {
    unsigned int U;
    signed int I;
    Ifx_GTM_BRC_SRC_ADDR_Bits B;
  } Ifx_GTM_BRC_SRC_ADDR;

typedef volatile struct
{
    Ifx_GTM_BRC_SRC_ADDR SRC_ADDR; 
    Ifx_GTM_BRC_SRC_DEST SRC_DEST; 
   
  }Ifx_GTM_BRC_SRC_ADDRx;


  typedef volatile struct
  {
    Ifx_GTM_BRC_SRC_ADDRx SRC0;    /** \brief 0, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC1;    /** \brief 8, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC2;    /** \brief 10, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC3;    /** \brief 18, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC4;    /** \brief 20, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC5;    /** \brief 28, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC6;    /** \brief 30, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC7;    /** \brief 38, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC8;    /** \brief 40, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC9;    /** \brief 48, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC10;   /** \brief 50, BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx SRC11;   /** \brief 58, BRC input channel objects */
    Ifx_GTM_BRC_IRQ_NOTIFY IRQ_NOTIFY; /** \brief 60, BRC Interrupt 
                                                      Notification Register */
    Ifx_GTM_BRC_IRQ_EN IRQ_EN;    /** \brief 64, BRC Interrupt 
                                                            Enable Register */
    Ifx_GTM_BRC_IRQ_FORCINT IRQ_FORCINT;    /** \brief 68, 
                                    BRC_DEST_ERR Forcing Interrupt Register */
    Ifx_GTM_BRC_IRQ_MODE IRQ_MODE;    /** \brief 6C, BRC IRQ Mode 
                                                    Configuration Register */
    Ifx_GTM_BRC_RST RST;     /** \brief 70, BRC Software Reset Register */
    Ifx_GTM_BRC_EIRQ_EN EIRQ_EN;  /**< \brief 74, BRC Error Interrupt 
                                                            Enable Register */

  }Ifx_GTM_BRC_SRCx;

  typedef volatile union
  {
    /* For Accessing BRC source and destination registers */
    Ifx_GTM_BRC_SRCx BRC_SRC;
    /* For accessing all contents */                              
    Ifx_GTM_BRC BRC;
  } Ifx_GTM_BRCx;


  typedef volatile struct
  {
    /* BRC input channel objects */
    Ifx_GTM_BRC_SRC_ADDRx BrcSrc[GTM_NUMBER_OF_BRC_SOURCE];
    Ifx_GTM_BRC_IRQ_NOTIFY IRQ_NOTIFY;     /* Interrupt Notification Register */
    Ifx_GTM_BRC_IRQ_EN IRQ_EN;      /* Interrupt Enable Register */
    Ifx_GTM_BRC_IRQ_FORCINT IRQ_FORCINT;   /* Forcing Interrupt Register */
    Ifx_GTM_BRC_IRQ_MODE IRQ_MODE;         /* IRQ Mode Configuration Register */
    Ifx_GTM_BRC_RST RST;            /* Software Reset Register */
    Ifx_GTM_BRC_EIRQ_EN EIRQ_EN;     /**< \brief 74, 
                     BRC Error Interrupt Enable Register */
  } Gtm_BrcType;



/*BRC structures Ends */

