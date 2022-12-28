 /***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DC                                                      */
/* !Description     : DC Component                                            */
/*                                                                            */
/* !Module          : DC                                                      */
/* !Description     : DRIVING CYCLE                                           */
/*                                                                            */
/* !File            : DC_API.c                                                */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DC_vidMngEveCDThd                                                    */
/*   2 / DC_vidMngEveKeyODB                                                   */
/*                                                                            */
/* !Reference   : V02 NT 10 04662 / 1                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "DC.h"
#include "DC_im.h"

#ifndef DC_CALLBACK_H
#define DC_CALLBACK_H

/* Macro for optimization */
/* Replace the function DC_vidF02_F01_ValDC */
#define DC_vidF02_F01_ValDC_opt(LocalDivision,LocalMask)\
{\
   boolean  blocal;\
\
   blocal = TRUE;\
   GD_vidBitWrite_opt_mask(DC_au8DC_EEPROM[LocalDivision],LocalMask,blocal)\
}

/* Macro for optimization */
/* Replace the function DC_vidMngEveCDThd */
#define DC_vidMngEveCDThd_opt(LocalDivision,LocalMask)\
{\
   if(DC_u8Inhib != 0x5A)\
   {\
      DC_vidF02_F01_ValDC_opt(LocalDivision,LocalMask);\
   }\
}



#endif /* DC_CALLBACK_H */