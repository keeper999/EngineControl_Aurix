
#if (COM_bRCV_SIG_GEN_ENABLE == STD_ON)
        
#include <SchM_Com.h>

#define COM_RECEIVE_SIGNAL_0( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[0]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal0
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_1( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[1]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal1
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_2( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[2]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal2
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_3( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[0]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal3
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_4( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[3]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal4
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_5( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[4]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal5
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_6( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[5]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal6
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_7( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[6]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal7
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_8( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[7]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal8
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_9( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 8 ; SignalLengthIndex < 16 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 8] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal9
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_10( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[1]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal10
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_11( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[16]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal11
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_12( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[17]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal12
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_13( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[2]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal13
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_14( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[18]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal14
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_15( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[3]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal15
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_16( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[19]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal16
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_17( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[4]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal17
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_18( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[5]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal18
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_19( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[6]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal19
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_20( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[7]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal20
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_21( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[8]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal21
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_22( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[20]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal22
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_23( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[9]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal23
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_24( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[10]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal24
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_25( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[21]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal25
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_26( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[11]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal26
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_27( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[22]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal27
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_28( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[23]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal28
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_29( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[24]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal29
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_30( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[12]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal30
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_31( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[13]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal31
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_32( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[25]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal32
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_33( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 26 ; SignalLengthIndex < 34 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 26] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal33
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_34( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[34]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal34
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_35( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[35]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal35
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_36( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[0]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal36
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_37( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[36]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal37
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_38( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[37]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal38
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_39( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[38]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal39
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_40( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 39 ; SignalLengthIndex < 47 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 39] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal40
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_41( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[47]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal41
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_42( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[48]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal42
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_43( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[14]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal43
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_44( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[15]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal44
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_45( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[49]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal45
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_46( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[50]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal46
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_47( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[1]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal47
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_48( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[16]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal48
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_49( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[51]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal49
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_50( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU32_0b(); \
        *(P2VAR(uint32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu32SignalObjectU32[0]; \
        SchM_Exit_Com_SigObjU32_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal50
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_51( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[52]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal51
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_52( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[53]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal52
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_53( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[54]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal53
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_54( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[55]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal54
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_55( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[56]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal55
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_56( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[57]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal56
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_57( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[58]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal57
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_58( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[59]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal58
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_59( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[17]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal59
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_60( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[60]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal60
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_61( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[61]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal61
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_62( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[62]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal62
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_63( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[63]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal63
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_64( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[18]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal64
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_65( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[64]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal65
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_66( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[19]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal66
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_67( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[20]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal67
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_68( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[21]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal68
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_69( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[22]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal69
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_70( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[23]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal70
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_71( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[24]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal71
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_72( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[25]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal72
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_73( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[26]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal73
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_74( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[65]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal74
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_75( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[66]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal75
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_76( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[27]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal76
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_77( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[67]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal77
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_78( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[68]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal78
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_79( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[28]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal79
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_80( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[69]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal80
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_81( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[70]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal81
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_82( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[71]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal82
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_83( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[29]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal83
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_84( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[72]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal84
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_85( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[73]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal85
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_86( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[74]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal86
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_87( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[75]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal87
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_88( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[76]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal88
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_89( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[30]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal89
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_90( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[31]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal90
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_91( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[77]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal91
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_92( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[78]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal92
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_93( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[79]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal93
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_94( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[32]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal94
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_95( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[33]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal95
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_96( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[80]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal96
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_97( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[81]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal97
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_98( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[34]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal98
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_99( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[82]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal99
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_100( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[35]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal100
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_101( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[36]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal101
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_102( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[83]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal102
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_103( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[84]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal103
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_104( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[37]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal104
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_105( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[38]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal105
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_106( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[39]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal106
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_107( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[40]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal107
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_108( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[41]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal108
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_109( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[85]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal109
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_110( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[86]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal110
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_111( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 87 ; SignalLengthIndex < 95 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 87] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal111
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_112( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[95]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal112
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_113( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[96]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal113
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_114( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[97]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal114
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_115( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[2]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal115
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_116( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[3]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal116
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_117( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[98]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal117
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_118( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[99]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal118
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_119( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[100]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal119
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_120( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[101]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal120
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_121( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[4]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal121
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_122( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[102]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal122
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_123( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[103]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal123
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_124( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[104]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal124
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_125( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[105]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal125
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_126( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[5]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal126
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_127( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[106]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal127
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_128( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 107 ; SignalLengthIndex < 115 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 107] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal128
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_129( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[115]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal129
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_130( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[116]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal130
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_131( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[117]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal131
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_132( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[118]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal132
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_133( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[119]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal133
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_134( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[120]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal134
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_135( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[121]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal135
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_136( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[122]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal136
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_137( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[123]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal137
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_138( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[124]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal138
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_139( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[42]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal139
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_140( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[43]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal140
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_141( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[44]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal141
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_142( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[125]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal142
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_143( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[45]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal143
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_144( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[126]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal144
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_145( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[127]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal145
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_146( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[128]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal146
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_147( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[129]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal147
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_148( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[130]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal148
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_149( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[131]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal149
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_150( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[132]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal150
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_151( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[46]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal151
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_152( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[47]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal152
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_153( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[48]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal153
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_154( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[133]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal154
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_155( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[134]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal155
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_156( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[135]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal156
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_157( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[49]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal157
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_158( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[136]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal158
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_159( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[50]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal159
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_160( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[51]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal160
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_161( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[137]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal161
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_162( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[138]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal162
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_163( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[139]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal163
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_164( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[140]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal164
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_165( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[52]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal165
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_166( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[6]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal166
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_167( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[7]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal167
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_168( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[8]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal168
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_169( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[141]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal169
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_170( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[9]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal170
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_171( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[53]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal171
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_172( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[54]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal172
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_173( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[142]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal173
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_174( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[143]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal174
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_175( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[144]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal175
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_176( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[55]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal176
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_177( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[145]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal177
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_178( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[56]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal178
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_179( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[146]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal179
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_180( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[57]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal180
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_181( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[58]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal181
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_182( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[147]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal182
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_183( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[148]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal183
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_184( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[149]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal184
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_185( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[150]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal185
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_186( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[151]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal186
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_187( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[152]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal187
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_188( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[59]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal188
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_189( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[153]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal189
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_190( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[60]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal190
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_191( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[61]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal191
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_192( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[154]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal192
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_193( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[62]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal193
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_194( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[63]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal194
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_195( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[155]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal195
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_196( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[64]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal196
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_197( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[156]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal197
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_198( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[157]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal198
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_199( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[158]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal199
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_200( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[65]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal200
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_201( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[66]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal201
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_202( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 159 ; SignalLengthIndex < 167 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 159] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal202
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_203( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[167]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal203
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_204( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[168]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal204
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_205( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[67]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal205
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_206( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[68]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal206
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_207( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[69]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal207
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_208( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[10]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal208
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_209( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[169]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal209
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_210( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[70]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal210
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_211( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[170]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal211
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_212( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[171]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal212
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_213( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[71]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal213
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_214( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[172]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal214
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_215( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[72]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal215
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_216( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[173]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal216
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_217( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[174]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal217
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_218( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[175]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal218
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_219( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[73]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal219
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_220( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[74]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal220
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_221( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[11]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal221
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_222( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[75]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal222
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_223( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[176]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal223
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_224( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[177]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal224
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_225( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[76]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal225
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_226( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[178]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal226
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_227( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[179]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal227
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_228( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[180]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal228
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_229( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[181]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal229
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_230( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[182]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal230
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_231( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[183]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal231
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_232( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[77]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal232
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_233( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[184]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal233
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_234( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[78]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal234
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_235( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[79]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal235
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_236( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[185]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal236
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_237( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[186]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal237
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_238( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[187]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal238
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_239( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[80]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal239
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_240( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[81]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal240
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_241( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[188]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal241
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_242( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[189]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal242
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_243( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[190]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal243
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_244( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[82]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal244
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_245( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[83]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal245
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_246( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[12]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal246
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_247( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[191]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal247
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_248( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[13]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal248
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_249( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[192]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal249
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_250( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[14]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal250
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_251( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[193]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal251
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_252( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[194]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal252
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_253( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[84]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal253
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_254( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[195]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal254
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_255( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[196]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal255
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_256( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[197]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal256
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_257( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[198]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal257
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_258( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[15]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal258
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_259( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[199]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal259
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_260( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[200]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal260
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_261( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[16]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal261
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_262( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[201]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal262
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_263( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[202]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal263
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_264( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[203]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal264
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_265( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[204]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal265
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_266( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[205]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal266
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_267( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[206]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal267
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_268( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[207]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal268
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_269( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[85]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal269
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_270( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[208]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal270
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_271( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[209]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal271
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_272( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[17]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal272
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_273( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[210]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal273
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_274( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[211]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal274
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_275( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[212]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal275
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_276( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[213]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal276
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_277( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[214]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal277
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_278( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[215]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal278
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_279( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[216]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal279
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_280( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[217]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal280
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_281( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[218]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal281
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_282( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[219]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal282
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_283( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[86]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal283
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_284( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[220]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal284
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_285( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[221]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal285
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_286( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[87]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal286
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_287( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[88]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal287
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_288( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[89]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal288
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_289( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[222]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal289
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_290( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[18]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal290
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_291( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[90]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal291
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_292( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[91]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal292
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_293( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[223]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal293
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_294( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[92]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal294
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_295( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[224]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal295
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_296( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[225]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal296
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_297( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[226]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal297
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_298( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[227]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal298
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_299( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[228]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal299
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_300( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[229]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal300
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_301( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[230]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal301
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_302( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[231]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal302
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_303( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[19]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal303
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_304( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[232]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal304
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_305( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[20]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal305
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_306( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[93]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal306
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_307( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[233]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal307
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_308( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[234]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal308
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_309( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[235]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal309
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_310( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[94]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal310
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_311( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[236]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal311
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_312( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[95]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal312
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_313( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[237]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal313
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_314( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[96]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal314
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_315( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[238]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal315
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_316( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[239]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal316
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_317( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[97]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal317
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_318( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[21]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal318
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_319( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[22]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal319
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_320( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[23]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal320
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_321( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[24]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal321
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_322( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[98]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal322
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_323( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[99]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal323
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_324( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[100]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal324
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_325( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[240]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal325
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_326( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[241]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal326
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_327( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[242]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal327
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_328( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[25]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal328
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_329( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[26]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal329
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_330( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[27]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal330
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_331( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[28]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal331
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_332( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[243]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal332
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_333( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[29]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal333
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_334( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[244]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal334
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_335( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[245]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal335
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_336( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU8U8N_0b(); \
        for(SignalLengthIndex = 246 ; SignalLengthIndex < 254 ; SignalLengthIndex++)\
        {\
        ((P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr)[SignalLengthIndex - 246] =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[SignalLengthIndex]; \
        }\
        SchM_Exit_Com_SigObjU8U8N_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal336
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_337( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[254]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal337
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_338( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[101]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal338
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_339( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[255]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal339
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_340( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[256]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal340
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_341( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[257]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal341
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_342( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[258]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal342
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_343( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[259]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal343
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_344( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[260]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal344
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_345( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[261]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal345
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_346( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[262]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal346
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_347( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[263]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal347
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_348( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[264]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal348
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_349( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[102]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal349
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_350( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[103]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal350
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_351( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[265]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal351
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_352( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[266]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal352
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_353( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[267]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal353
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_354( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[104]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal354
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_355( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[268]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal355
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_356( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[105]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal356
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_357( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[106]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal357
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_358( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[30]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal358
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_359( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[107]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal359
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_360( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[269]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal360
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_361( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[270]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal361
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_362( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[271]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal362
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_363( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[272]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal363
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_364( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[108]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal364
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_365( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[273]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal365
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_366( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[274]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal366
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_367( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[275]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal367
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_368( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[276]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal368
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_369( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[277]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal369
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_370( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[109]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal370
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_371( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[110]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal371
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_372( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[278]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal372
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_373( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[279]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal373
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_374( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[280]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal374
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_375( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[281]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal375
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_376( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[282]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal376
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_377( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[283]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal377
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_378( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[111]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal378
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_379( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[284]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal379
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_380( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[112]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal380
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_381( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[285]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal381
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_382( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[113]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal382
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_383( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[286]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal383
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_384( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[114]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal384
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_385( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[287]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal385
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_386( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[115]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal386
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_387( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[288]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal387
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_388( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[289]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal388
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_389( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[290]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal389
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_390( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[291]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal390
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_391( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[292]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal391
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_392( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[293]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal392
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_393( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[294]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal393
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_394( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[31]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal394
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_395( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[295]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal395
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_396( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[296]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal396
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_397( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[297]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal397
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_398( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[298]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal398
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_399( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[299]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal399
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_400( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[300]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal400
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_401( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[301]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal401
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_402( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[302]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal402
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_403( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[303]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal403
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_404( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[304]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal404
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_405( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[116]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal405
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_406( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[305]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal406
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_407( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[306]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal407
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_408( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[307]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal408
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_409( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU16_0b(); \
        *(P2VAR(uint16,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu16SignalObjectU16[32]; \
        SchM_Exit_Com_SigObjU16_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal409
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_410( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[117]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal410
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_411( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[308]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal411
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_412( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[118]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal412
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_413( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[119]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal413
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_414( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[309]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal414
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_415( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[120]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal415
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_416( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[121]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal416
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_417( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[122]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal417
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_418( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[123]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal418
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_419( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[124]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal419
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_420( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[125]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal420
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_421( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[126]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal421
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_422( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[127]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal422
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_423( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[128]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal423
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_424( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[310]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal424
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_425( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[129]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal425
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_426( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[130]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal426
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_427( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[311]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal427
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_428( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[312]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal428
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_429( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[313]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal429
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_430( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[131]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal430
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_431( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[314]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal431
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_432( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[315]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal432
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_433( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[316]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal433
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_434( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[132]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal434
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_435( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[133]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal435
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_436( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[317]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal436
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_437( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[318]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal437
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_438( SignalDataPtr ) \
   do { \
        SchM_Enter_Com_SigObjU32_0b(); \
        *(P2VAR(uint32,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu32SignalObjectU32[1]; \
        SchM_Exit_Com_SigObjU32_0b();\
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal438
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_439( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[319]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal439
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_440( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[320]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal440
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_441( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[321]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal441
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_442( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[322]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal442
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_443( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[323]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal443
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_444( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[324]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal444
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_445( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[325]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal445
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_446( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[326]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal446
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_447( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[327]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal447
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_448( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[328]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal448
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_449( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[329]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal449
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_450( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[330]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal450
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_451( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[331]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal451
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_452( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[332]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal452
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_453( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[333]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal453
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_454( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[334]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal454
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_455( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[335]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal455
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_456( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[336]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal456
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_457( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[337]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal457
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_458( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[338]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal458
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_459( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[339]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal459
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_460( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[134]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal460
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_461( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[135]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal461
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_462( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[136]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal462
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_463( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[340]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal463
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_464( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[341]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal464
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_465( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[137]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal465
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_466( SignalDataPtr ) \
   do { \
        *(P2VAR(boolean,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pbSignalObjectB[138]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal466
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_467( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[342]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal467
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

#define COM_RECEIVE_SIGNAL_468( SignalDataPtr ) \
   do { \
        *(P2VAR(uint8,AUTOMATIC,COM_APPL_DATA))SignalDataPtr =\
    Com_pkstreMainConfig->pu8SignalObjectU8U8N[343]; \
  } while( 0 )
   
 extern FUNC(uint8,COM_CODE) Com_ReceiveSignal468
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

        
#endif
      
