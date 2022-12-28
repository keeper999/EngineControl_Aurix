#ifndef KWP_TYP_H
#define KWP_TYP_H

#include "NOPROD.h"
/* DCM UDS */
#define KWP_SERV(fenuProcess) \
   FUNC(KWP_tenuServiceReturnType, KWP_APPL_CODE) fenuProcess(void)
#define KWP_TRANSMIT_CALLBACK(fvidCbk) \
   FUNC(void, KWP_APPL_CODE) fvidCbk(void)
#define KWP_RDBLID(fenuFunc) \
   FUNC(KWP_tenuServiceReturnType, KWP_APPL_CODE) fenuFunc(void) 
#define KWP_APPLIRIGHT_HOOK(fbFunc) \
   FUNC(boolean, KWP_APPL_CODE) fbFunc(void)
/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/
/* DCM for UDS */

typedef enum
{
   KWP_enuON,
   KWP_enuOFF

} KWP_tenuStatus;

typedef enum
{
   KWP_enuACK,
   KWP_enuACK_BUSY,
   KWP_enuNACK_11_UNSUPPORTED_SERVICE,
   KWP_enuNACK_12_UNSUPPORTED_SUB,
   KWP_enuNACK_12_INVALID_FORMAT,
   KWP_enuNACK_21_BUSY,
   KWP_enuNACK_22_INVALID_CONDITION,
   KWP_enuNACK_22_INVALID_SEQU_REQ,
   KWP_enuNACK_33_ECU_LOCKED,
   KWP_enuNACK_35_INVALID_KEY,
   KWP_enuNACK_78_BUSY_WITHOUT_STATUS,
   KWP_enuNACK_87_WRITE_DEFAULT

} KWP_tenuServiceReturnType;



#define KWP_vidEndofServiceExecution()

/* KWP_tenuServiceReturnType fenuProcess(void); */
/* void fvidCbk(void);*/
/* KWP_tenuServiceReturnType fenuFunc(void);*/
/* boolean fbFunc(void); */
#define Srv_bCarNotRolling() 0
#define Srv_bEngStpKeyOf()   0
#define Srv_bEcuUnlocked()   0
#define Srv_bEngStp()        0

#endif