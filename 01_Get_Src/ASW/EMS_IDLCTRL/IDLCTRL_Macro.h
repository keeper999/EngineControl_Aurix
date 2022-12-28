/***************************************************************************
;**
;** FILE NAME      : IDLCTRL_MACRO.h
;**
;** FILE AUTHOR    : Mohamed.Bennasr
;**
;**************************************************************************/

#ifndef IDLCTRL_MACRO_H
#define IDLCTRL_MACRO_H

#include "STD_TYPES.h"
#include "SWFAIL.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define MaxSize 16

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define LIBPSA_u16SlidAverFilt(In, \
                               InitVal, \
                               Rst, \
                               Tab, \
                               TabSize, \
                               PtrIndex, \
                               SampleNbr, \
                               PtrRstCalc, \
                               PtrOutAverFilt) \
   M1_LIBPSA_u16SlidAverFilt(In, \
                             InitVal, \
                             Rst, \
                             Tab, \
                             TabSize, \
                             PtrIndex, \
                             SampleNbr, \
                             PtrRstCalc, \
                             PtrOutAverFilt)

   #define M1_LIBPSA_u16SlidAverFilt(In, \
                                     InitVal, \
                                     Rst, \
                                     Tab, \
                                     TabSize, \
                                     PtrIndex, \
                                     SampleNbr, \
                                     PtrRstCalc, \
                                     PtrOutAverFilt) \
      { \
         uint32 count; \
         uint8  pos; \
         uint32 sum; \
      \
         if (  (((uint32)(TabSize)) > (MaxSize)) \
            || (((uint32)(SampleNbr)) > (TabSize)) \
            || ((uint32)(SampleNbr) == 0) \
            || ((*(PtrIndex)) >= (TabSize))) \
         { \
           (*(PtrOutAverFilt)) = (In); \
           SWFAIL_vidSoftwareErrorHook(); \
         } \
         else \
         { \
           if ((*(PtrRstCalc)) == 0) \
           { \
             for (count = 0; count < TabSize; count++) \
             { \
               (Tab[count]) = (InitVal); \
             } \
             (*(PtrOutAverFilt)) = (InitVal); \
             (*(PtrIndex)) = 0; \
             (*(PtrRstCalc)) = 1; \
           } \
           else \
           { \
             if ((Rst) != 0) \
             { \
               for (count = 0; count < TabSize; count++) \
               { \
                  (Tab[count]) = (InitVal); \
               } \
               (*(PtrOutAverFilt)) = (InitVal); \
             } \
             else \
             { \
               (Tab[*(PtrIndex)]) = (In); \
               pos = (*(PtrIndex)); \
               sum = 0; \
               for (count = 0; count < ((uint32)(SampleNbr)); count++) \
               { \
                  sum = (sum + (Tab[pos])); \
                  if (pos == 0) \
                  { \
                    pos =((TabSize) - 1); \
                  } \
                  else \
                  { \
                    pos--; \
                  } \
               } \
               *(PtrOutAverFilt) = (sum / (SampleNbr)); \
               (*(PtrIndex))++; \
               if ((*(PtrIndex)) >= (TabSize)) \
               { \
                  (*(PtrIndex)) = 0; \
               } \
             } \
           } \
         } \
      }
#endif /* IDLCTRL_MACRO_H */ 

/*-------------------------------- end of file -------------------------------*/