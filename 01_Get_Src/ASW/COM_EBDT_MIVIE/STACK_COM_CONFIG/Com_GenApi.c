
#include <Com_Cfg.h>
#if (COM_bRCV_SIG_GEN_ENABLE == STD_ON)
#include <Com_LCfg.h>
#include <Com_GenApi.h>
#include <Com_PBCfg.h>
uint8 SignalLengthIndex;

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_0( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal0 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_0( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_0( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_1( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal1 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_1( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_1( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_2( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal2 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_2( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_2( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_3( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal3 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_3( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_3( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_4( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal4 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_4( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_4( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_5( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal5 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_5( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_5( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 0*/
#define COM_CHECK_STATUS_6( retval ) \
   do { \
          if ((Com_audteIPduStatus[0] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal6 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_6( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_6( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 28*/
#define COM_CHECK_STATUS_7( retval ) \
   do { \
          if ((Com_audteIPduStatus[28] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal7 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_7( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_7( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 28*/
#define COM_CHECK_STATUS_8( retval ) \
   do { \
          if ((Com_audteIPduStatus[28] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal8 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_8( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_8( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 61*/
#define COM_CHECK_STATUS_9( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[61] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal9 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_9( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_9( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_10( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal10 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_10( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_10( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_11( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal11 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_11( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_11( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_12( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal12 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_12( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_12( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_13( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal13 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_13( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_13( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_14( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal14 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_14( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_14( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_15( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal15 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_15( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_15( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_16( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal16 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_16( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_16( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_17( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal17 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_17( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_17( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_18( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal18 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_18( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_18( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_19( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal19 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_19( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_19( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_20( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal20 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_20( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_20( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_21( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal21 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_21( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_21( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_22( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal22 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_22( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_22( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_23( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal23 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_23( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_23( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_24( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal24 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_24( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_24( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_25( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal25 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_25( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_25( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_26( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal26 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_26( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_26( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_27( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal27 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_27( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_27( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_28( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal28 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_28( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_28( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_29( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal29 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_29( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_29( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_30( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal30 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_30( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_30( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_31( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal31 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_31( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_31( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 1*/
#define COM_CHECK_STATUS_32( retval ) \
   do { \
          if ((Com_audteIPduStatus[1] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal32 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_32( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_32( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 44*/
#define COM_CHECK_STATUS_33( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[44] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal33 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_33( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_33( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_34( retval ) \
   do { \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal34 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_34( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_34( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_35( retval ) \
   do { \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal35 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_35( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_35( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_36( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal36 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_36( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_36( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_37( retval ) \
   do { \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal37 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_37( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_37( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_38( retval ) \
   do { \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal38 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_38( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_38( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_39( retval ) \
   do { \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal39 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_39( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_39( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 42*/
#define COM_CHECK_STATUS_40( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[42] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal40 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_40( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_40( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 4*/
#define COM_CHECK_STATUS_41( retval ) \
   do { \
          if ((Com_audteIPduStatus[4] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal41 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_41( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_41( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 4*/
#define COM_CHECK_STATUS_42( retval ) \
   do { \
          if ((Com_audteIPduStatus[4] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal42 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_42( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_42( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 4*/
#define COM_CHECK_STATUS_43( retval ) \
   do { \
          if ((Com_audteIPduStatus[4] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal43 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_43( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_43( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 4*/
#define COM_CHECK_STATUS_44( retval ) \
   do { \
          if ((Com_audteIPduStatus[4] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal44 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_44( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_44( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_45( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal45 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_45( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_45( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 5*/
#define COM_CHECK_STATUS_46( retval ) \
   do { \
          if ((Com_audteIPduStatus[5] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal46 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_46( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_46( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 5*/
#define COM_CHECK_STATUS_47( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[5] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal47 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_47( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_47( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_48( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal48 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_48( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_48( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 5*/
#define COM_CHECK_STATUS_49( retval ) \
   do { \
          if ((Com_audteIPduStatus[5] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal49 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_49( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_49( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 5*/
#define COM_CHECK_STATUS_50( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[5] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal50 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_50( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_50( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_51( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal51 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_51( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_51( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_52( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal52 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_52( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_52( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_53( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal53 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_53( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_53( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_54( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal54 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_54( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_54( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_55( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal55 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_55( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_55( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_56( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal56 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_56( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_56( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_57( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal57 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_57( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_57( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 6*/
#define COM_CHECK_STATUS_58( retval ) \
   do { \
          if ((Com_audteIPduStatus[6] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal58 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_58( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_58( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_59( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal59 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_59( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_59( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_60( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal60 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_60( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_60( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_61( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal61 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_61( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_61( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_62( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal62 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_62( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_62( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_63( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal63 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_63( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_63( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_64( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal64 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_64( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_64( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_65( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal65 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_65( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_65( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_66( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal66 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_66( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_66( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_67( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal67 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_67( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_67( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_68( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal68 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_68( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_68( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_69( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal69 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_69( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_69( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_70( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal70 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_70( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_70( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_71( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal71 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_71( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_71( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_72( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal72 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_72( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_72( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_73( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal73 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_73( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_73( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_74( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal74 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_74( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_74( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_75( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal75 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_75( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_75( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_76( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal76 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_76( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_76( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_77( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal77 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_77( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_77( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_78( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal78 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_78( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_78( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_79( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal79 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_79( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_79( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_80( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal80 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_80( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_80( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_81( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal81 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_81( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_81( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_82( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal82 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_82( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_82( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_83( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal83 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_83( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_83( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 8*/
#define COM_CHECK_STATUS_84( retval ) \
   do { \
          if ((Com_audteIPduStatus[8] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal84 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_84( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_84( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 8*/
#define COM_CHECK_STATUS_85( retval ) \
   do { \
          if ((Com_audteIPduStatus[8] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal85 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_85( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_85( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 8*/
#define COM_CHECK_STATUS_86( retval ) \
   do { \
          if ((Com_audteIPduStatus[8] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal86 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_86( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_86( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 8*/
#define COM_CHECK_STATUS_87( retval ) \
   do { \
          if ((Com_audteIPduStatus[8] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal87 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_87( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_87( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_88( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal88 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_88( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_88( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_89( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal89 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_89( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_89( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_90( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal90 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_90( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_90( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_91( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal91 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_91( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_91( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_92( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal92 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_92( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_92( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_93( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal93 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_93( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_93( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_94( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal94 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_94( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_94( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_95( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal95 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_95( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_95( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_96( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal96 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_96( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_96( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_97( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal97 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_97( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_97( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_98( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal98 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_98( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_98( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_99( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal99 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_99( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_99( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_100( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal100 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_100( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_100( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_101( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal101 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_101( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_101( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_102( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal102 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_102( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_102( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_103( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal103 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_103( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_103( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_104( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal104 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_104( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_104( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_105( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal105 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_105( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_105( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_106( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal106 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_106( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_106( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_107( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal107 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_107( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_107( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 9*/
#define COM_CHECK_STATUS_108( retval ) \
   do { \
          if ((Com_audteIPduStatus[9] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal108 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_108( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_108( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 10*/
#define COM_CHECK_STATUS_109( retval ) \
   do { \
          if ((Com_audteIPduStatus[10] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal109 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_109( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_109( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 10*/
#define COM_CHECK_STATUS_110( retval ) \
   do { \
          if ((Com_audteIPduStatus[10] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal110 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_110( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_110( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 11*/
#define COM_CHECK_STATUS_111( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[11] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal111 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_111( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_111( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 10*/
#define COM_CHECK_STATUS_112( retval ) \
   do { \
          if ((Com_audteIPduStatus[10] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal112 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_112( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_112( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 8*/
#define COM_CHECK_STATUS_113( retval ) \
   do { \
          if ((Com_audteIPduStatus[8] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal113 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_113( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_113( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 7*/
#define COM_CHECK_STATUS_114( retval ) \
   do { \
          if ((Com_audteIPduStatus[7] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal114 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_114( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_114( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_115( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal115 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_115( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_115( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_116( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal116 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_116( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_116( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_117( retval ) \
   do { \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal117 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_117( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_117( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_118( retval ) \
   do { \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal118 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_118( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_118( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_119( retval ) \
   do { \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal119 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_119( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_119( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_120( retval ) \
   do { \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal120 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_120( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_120( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_121( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal121 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_121( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_121( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 12*/
#define COM_CHECK_STATUS_122( retval ) \
   do { \
          if ((Com_audteIPduStatus[12] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal122 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_122( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_122( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 5*/
#define COM_CHECK_STATUS_123( retval ) \
   do { \
          if ((Com_audteIPduStatus[5] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal123 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_123( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_123( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 13*/
#define COM_CHECK_STATUS_124( retval ) \
   do { \
          if ((Com_audteIPduStatus[13] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal124 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_124( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_124( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 13*/
#define COM_CHECK_STATUS_125( retval ) \
   do { \
          if ((Com_audteIPduStatus[13] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal125 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_125( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_125( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 4*/
#define COM_CHECK_STATUS_126( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[4] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal126 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_126( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_126( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 13*/
#define COM_CHECK_STATUS_127( retval ) \
   do { \
          if ((Com_audteIPduStatus[13] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal127 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_127( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_127( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 14*/
#define COM_CHECK_STATUS_128( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[14] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal128 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_128( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_128( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 15*/
#define COM_CHECK_STATUS_129( retval ) \
   do { \
          if ((Com_audteIPduStatus[15] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal129 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_129( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_129( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 15*/
#define COM_CHECK_STATUS_130( retval ) \
   do { \
          if ((Com_audteIPduStatus[15] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal130 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_130( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_130( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 15*/
#define COM_CHECK_STATUS_131( retval ) \
   do { \
          if ((Com_audteIPduStatus[15] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal131 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_131( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_131( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 15*/
#define COM_CHECK_STATUS_132( retval ) \
   do { \
          if ((Com_audteIPduStatus[15] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal132 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_132( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_132( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 15*/
#define COM_CHECK_STATUS_133( retval ) \
   do { \
          if ((Com_audteIPduStatus[15] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal133 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_133( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_133( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_134( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal134 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_134( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_134( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_135( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal135 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_135( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_135( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_136( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal136 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_136( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_136( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_137( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal137 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_137( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_137( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_138( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal138 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_138( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_138( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_139( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal139 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_139( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_139( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_140( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal140 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_140( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_140( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_141( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal141 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_141( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_141( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_142( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal142 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_142( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_142( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_143( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal143 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_143( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_143( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_144( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal144 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_144( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_144( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_145( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal145 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_145( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_145( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_146( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal146 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_146( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_146( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_147( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal147 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_147( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_147( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 16*/
#define COM_CHECK_STATUS_148( retval ) \
   do { \
          if ((Com_audteIPduStatus[16] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal148 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_148( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_148( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_149( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal149 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_149( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_149( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_150( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal150 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_150( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_150( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_151( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal151 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_151( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_151( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_152( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal152 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_152( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_152( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_153( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal153 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_153( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_153( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_154( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal154 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_154( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_154( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_155( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal155 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_155( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_155( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_156( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal156 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_156( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_156( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_157( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal157 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_157( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_157( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_158( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal158 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_158( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_158( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_159( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal159 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_159( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_159( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_160( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal160 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_160( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_160( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_161( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal161 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_161( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_161( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_162( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal162 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_162( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_162( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_163( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal163 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_163( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_163( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_164( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal164 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_164( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_164( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_165( retval ) \
   do { \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal165 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_165( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_165( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 17*/
#define COM_CHECK_STATUS_166( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[17] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal166 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_166( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_166( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 18*/
#define COM_CHECK_STATUS_167( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[18] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal167 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_167( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_167( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 18*/
#define COM_CHECK_STATUS_168( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[18] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal168 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_168( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_168( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 18*/
#define COM_CHECK_STATUS_169( retval ) \
   do { \
          if ((Com_audteIPduStatus[18] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal169 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_169( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_169( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 18*/
#define COM_CHECK_STATUS_170( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[18] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal170 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_170( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_170( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_171( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal171 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_171( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_171( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_172( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal172 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_172( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_172( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_173( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal173 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_173( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_173( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_174( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal174 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_174( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_174( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_175( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal175 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_175( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_175( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_176( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal176 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_176( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_176( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_177( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal177 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_177( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_177( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_178( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal178 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_178( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_178( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_179( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal179 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_179( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_179( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_180( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal180 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_180( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_180( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_181( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal181 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_181( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_181( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_182( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal182 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_182( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_182( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_183( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal183 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_183( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_183( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_184( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal184 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_184( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_184( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_185( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal185 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_185( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_185( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_186( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal186 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_186( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_186( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 3*/
#define COM_CHECK_STATUS_187( retval ) \
   do { \
          if ((Com_audteIPduStatus[3] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal187 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_187( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_187( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_188( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal188 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_188( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_188( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_189( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal189 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_189( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_189( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_190( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal190 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_190( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_190( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_191( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal191 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_191( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_191( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 28*/
#define COM_CHECK_STATUS_192( retval ) \
   do { \
          if ((Com_audteIPduStatus[28] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal192 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_192( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_192( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_193( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal193 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_193( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_193( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_194( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal194 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_194( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_194( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_195( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal195 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_195( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_195( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_196( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal196 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_196( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_196( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_197( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal197 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_197( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_197( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_198( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal198 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_198( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_198( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_199( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal199 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_199( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_199( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_200( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal200 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_200( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_200( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 19*/
#define COM_CHECK_STATUS_201( retval ) \
   do { \
          if ((Com_audteIPduStatus[19] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal201 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_201( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_201( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 20*/
#define COM_CHECK_STATUS_202( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[20] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal202 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_202( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_202( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_203( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal203 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_203( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_203( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_204( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal204 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_204( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_204( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_205( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal205 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_205( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_205( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_206( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal206 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_206( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_206( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_207( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal207 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_207( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_207( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_208( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal208 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_208( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_208( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_209( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal209 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_209( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_209( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_210( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal210 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_210( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_210( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_211( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal211 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_211( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_211( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_212( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal212 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_212( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_212( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_213( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal213 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_213( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_213( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_214( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal214 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_214( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_214( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 21*/
#define COM_CHECK_STATUS_215( retval ) \
   do { \
          if ((Com_audteIPduStatus[21] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal215 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_215( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_215( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_216( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal216 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_216( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_216( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_217( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal217 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_217( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_217( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_218( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal218 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_218( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_218( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_219( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal219 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_219( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_219( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_220( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal220 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_220( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_220( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_221( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal221 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_221( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_221( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_222( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal222 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_222( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_222( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_223( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal223 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_223( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_223( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_224( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal224 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_224( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_224( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 22*/
#define COM_CHECK_STATUS_225( retval ) \
   do { \
          if ((Com_audteIPduStatus[22] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal225 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_225( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_225( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_226( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal226 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_226( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_226( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_227( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal227 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_227( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_227( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_228( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal228 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_228( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_228( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_229( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal229 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_229( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_229( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_230( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal230 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_230( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_230( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_231( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal231 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_231( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_231( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_232( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal232 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_232( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_232( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_233( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal233 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_233( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_233( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_234( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal234 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_234( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_234( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_235( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal235 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_235( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_235( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_236( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal236 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_236( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_236( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_237( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal237 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_237( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_237( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_238( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal238 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_238( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_238( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_239( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal239 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_239( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_239( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 23*/
#define COM_CHECK_STATUS_240( retval ) \
   do { \
          if ((Com_audteIPduStatus[23] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal240 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_240( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_240( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_241( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal241 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_241( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_241( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_242( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal242 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_242( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_242( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_243( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal243 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_243( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_243( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 25*/
#define COM_CHECK_STATUS_244( retval ) \
   do { \
          if ((Com_audteIPduStatus[25] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal244 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_244( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_244( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 25*/
#define COM_CHECK_STATUS_245( retval ) \
   do { \
          if ((Com_audteIPduStatus[25] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal245 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_245( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_245( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_246( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal246 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_246( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_246( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_247( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal247 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_247( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_247( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_248( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal248 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_248( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_248( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_249( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal249 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_249( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_249( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_250( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal250 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_250( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_250( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_251( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal251 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_251( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_251( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_252( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal252 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_252( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_252( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_253( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal253 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_253( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_253( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_254( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal254 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_254( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_254( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_255( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal255 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_255( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_255( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 26*/
#define COM_CHECK_STATUS_256( retval ) \
   do { \
          if ((Com_audteIPduStatus[26] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal256 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_256( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_256( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_257( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal257 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_257( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_257( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_258( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal258 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_258( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_258( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_259( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal259 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_259( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_259( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_260( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal260 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_260( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_260( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_261( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal261 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_261( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_261( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_262( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal262 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_262( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_262( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_263( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal263 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_263( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_263( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_264( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal264 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_264( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_264( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_265( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal265 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_265( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_265( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 27*/
#define COM_CHECK_STATUS_266( retval ) \
   do { \
          if ((Com_audteIPduStatus[27] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal266 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_266( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_266( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 28*/
#define COM_CHECK_STATUS_267( retval ) \
   do { \
          if ((Com_audteIPduStatus[28] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal267 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_267( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_267( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 28*/
#define COM_CHECK_STATUS_268( retval ) \
   do { \
          if ((Com_audteIPduStatus[28] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal268 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_268( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_268( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 29*/
#define COM_CHECK_STATUS_269( retval ) \
   do { \
          if ((Com_audteIPduStatus[29] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal269 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_269( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_269( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_270( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal270 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_270( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_270( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 30*/
#define COM_CHECK_STATUS_271( retval ) \
   do { \
          if ((Com_audteIPduStatus[30] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal271 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_271( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_271( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 30*/
#define COM_CHECK_STATUS_272( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[30] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal272 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_272( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_272( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 30*/
#define COM_CHECK_STATUS_273( retval ) \
   do { \
          if ((Com_audteIPduStatus[30] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal273 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_273( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_273( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 31*/
#define COM_CHECK_STATUS_274( retval ) \
   do { \
          if ((Com_audteIPduStatus[31] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal274 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_274( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_274( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 32*/
#define COM_CHECK_STATUS_275( retval ) \
   do { \
          if ((Com_audteIPduStatus[32] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal275 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_275( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_275( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 32*/
#define COM_CHECK_STATUS_276( retval ) \
   do { \
          if ((Com_audteIPduStatus[32] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal276 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_276( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_276( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 32*/
#define COM_CHECK_STATUS_277( retval ) \
   do { \
          if ((Com_audteIPduStatus[32] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal277 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_277( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_277( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 32*/
#define COM_CHECK_STATUS_278( retval ) \
   do { \
          if ((Com_audteIPduStatus[32] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal278 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_278( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_278( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 32*/
#define COM_CHECK_STATUS_279( retval ) \
   do { \
          if ((Com_audteIPduStatus[32] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal279 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_279( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_279( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 32*/
#define COM_CHECK_STATUS_280( retval ) \
   do { \
          if ((Com_audteIPduStatus[32] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal280 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_280( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_280( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_281( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal281 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_281( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_281( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_282( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal282 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_282( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_282( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_283( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal283 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_283( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_283( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_284( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal284 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_284( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_284( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_285( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal285 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_285( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_285( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_286( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal286 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_286( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_286( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_287( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal287 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_287( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_287( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_288( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal288 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_288( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_288( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_289( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal289 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_289( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_289( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_290( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal290 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_290( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_290( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_291( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal291 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_291( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_291( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 33*/
#define COM_CHECK_STATUS_292( retval ) \
   do { \
          if ((Com_audteIPduStatus[33] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal292 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_292( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_292( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 35*/
#define COM_CHECK_STATUS_293( retval ) \
   do { \
          if ((Com_audteIPduStatus[35] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal293 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_293( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_293( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 35*/
#define COM_CHECK_STATUS_294( retval ) \
   do { \
          if ((Com_audteIPduStatus[35] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal294 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_294( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_294( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 35*/
#define COM_CHECK_STATUS_295( retval ) \
   do { \
          if ((Com_audteIPduStatus[35] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal295 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_295( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_295( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 35*/
#define COM_CHECK_STATUS_296( retval ) \
   do { \
          if ((Com_audteIPduStatus[35] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal296 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_296( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_296( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 36*/
#define COM_CHECK_STATUS_297( retval ) \
   do { \
          if ((Com_audteIPduStatus[36] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal297 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_297( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_297( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 36*/
#define COM_CHECK_STATUS_298( retval ) \
   do { \
          if ((Com_audteIPduStatus[36] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal298 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_298( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_298( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_299( retval ) \
   do { \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal299 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_299( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_299( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_300( retval ) \
   do { \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal300 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_300( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_300( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_301( retval ) \
   do { \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal301 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_301( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_301( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_302( retval ) \
   do { \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal302 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_302( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_302( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_303( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal303 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_303( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_303( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_304( retval ) \
   do { \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal304 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_304( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_304( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 37*/
#define COM_CHECK_STATUS_305( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[37] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal305 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_305( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_305( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_306( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal306 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_306( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_306( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_307( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal307 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_307( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_307( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_308( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal308 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_308( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_308( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_309( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal309 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_309( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_309( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_310( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal310 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_310( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_310( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_311( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal311 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_311( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_311( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_312( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal312 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_312( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_312( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_313( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal313 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_313( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_313( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_314( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal314 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_314( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_314( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_315( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal315 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_315( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_315( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 38*/
#define COM_CHECK_STATUS_316( retval ) \
   do { \
          if ((Com_audteIPduStatus[38] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal316 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_316( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_316( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 39*/
#define COM_CHECK_STATUS_317( retval ) \
   do { \
          if ((Com_audteIPduStatus[39] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal317 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_317( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_317( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 40*/
#define COM_CHECK_STATUS_318( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[40] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal318 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_318( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_318( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 40*/
#define COM_CHECK_STATUS_319( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[40] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal319 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_319( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_319( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 40*/
#define COM_CHECK_STATUS_320( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[40] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal320 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_320( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_320( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 40*/
#define COM_CHECK_STATUS_321( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[40] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal321 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_321( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_321( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 41*/
#define COM_CHECK_STATUS_322( retval ) \
   do { \
          if ((Com_audteIPduStatus[41] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal322 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_322( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_322( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 41*/
#define COM_CHECK_STATUS_323( retval ) \
   do { \
          if ((Com_audteIPduStatus[41] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal323 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_323( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_323( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 41*/
#define COM_CHECK_STATUS_324( retval ) \
   do { \
          if ((Com_audteIPduStatus[41] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal324 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_324( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_324( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_325( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal325 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_325( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_325( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 2*/
#define COM_CHECK_STATUS_326( retval ) \
   do { \
          if ((Com_audteIPduStatus[2] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal326 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_326( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_326( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_327( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal327 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_327( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_327( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 45*/
#define COM_CHECK_STATUS_328( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[45] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal328 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_328( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_328( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 45*/
#define COM_CHECK_STATUS_329( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[45] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal329 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_329( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_329( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 45*/
#define COM_CHECK_STATUS_330( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[45] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal330 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_330( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_330( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 45*/
#define COM_CHECK_STATUS_331( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[45] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal331 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_331( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_331( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 46*/
#define COM_CHECK_STATUS_332( retval ) \
   do { \
          if ((Com_audteIPduStatus[46] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal332 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_332( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_332( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 46*/
#define COM_CHECK_STATUS_333( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[46] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal333 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_333( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_333( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 46*/
#define COM_CHECK_STATUS_334( retval ) \
   do { \
          if ((Com_audteIPduStatus[46] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal334 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_334( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_334( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 46*/
#define COM_CHECK_STATUS_335( retval ) \
   do { \
          if ((Com_audteIPduStatus[46] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal335 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_335( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_335( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 47*/
#define COM_CHECK_STATUS_336( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[47] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal336 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_336( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_336( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_337( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal337 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_337( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_337( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_338( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal338 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_338( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_338( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 48*/
#define COM_CHECK_STATUS_339( retval ) \
   do { \
          if ((Com_audteIPduStatus[48] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal339 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_339( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_339( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 48*/
#define COM_CHECK_STATUS_340( retval ) \
   do { \
          if ((Com_audteIPduStatus[48] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal340 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_340( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_340( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 48*/
#define COM_CHECK_STATUS_341( retval ) \
   do { \
          if ((Com_audteIPduStatus[48] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal341 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_341( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_341( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 48*/
#define COM_CHECK_STATUS_342( retval ) \
   do { \
          if ((Com_audteIPduStatus[48] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal342 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_342( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_342( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 48*/
#define COM_CHECK_STATUS_343( retval ) \
   do { \
          if ((Com_audteIPduStatus[48] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal343 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_343( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_343( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 49*/
#define COM_CHECK_STATUS_344( retval ) \
   do { \
          if ((Com_audteIPduStatus[49] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal344 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_344( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_344( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 49*/
#define COM_CHECK_STATUS_345( retval ) \
   do { \
          if ((Com_audteIPduStatus[49] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal345 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_345( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_345( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 49*/
#define COM_CHECK_STATUS_346( retval ) \
   do { \
          if ((Com_audteIPduStatus[49] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal346 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_346( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_346( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 49*/
#define COM_CHECK_STATUS_347( retval ) \
   do { \
          if ((Com_audteIPduStatus[49] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal347 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_347( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_347( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 49*/
#define COM_CHECK_STATUS_348( retval ) \
   do { \
          if ((Com_audteIPduStatus[49] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal348 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_348( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_348( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_349( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal349 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_349( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_349( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_350( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal350 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_350( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_350( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_351( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal351 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_351( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_351( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_352( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal352 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_352( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_352( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_353( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal353 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_353( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_353( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_354( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal354 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_354( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_354( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_355( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal355 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_355( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_355( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 50*/
#define COM_CHECK_STATUS_356( retval ) \
   do { \
          if ((Com_audteIPduStatus[50] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal356 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_356( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_356( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 51*/
#define COM_CHECK_STATUS_357( retval ) \
   do { \
          if ((Com_audteIPduStatus[51] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal357 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_357( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_357( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 51*/
#define COM_CHECK_STATUS_358( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[51] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal358 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_358( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_358( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 51*/
#define COM_CHECK_STATUS_359( retval ) \
   do { \
          if ((Com_audteIPduStatus[51] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal359 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_359( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_359( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 51*/
#define COM_CHECK_STATUS_360( retval ) \
   do { \
          if ((Com_audteIPduStatus[51] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal360 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_360( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_360( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 51*/
#define COM_CHECK_STATUS_361( retval ) \
   do { \
          if ((Com_audteIPduStatus[51] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal361 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_361( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_361( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 51*/
#define COM_CHECK_STATUS_362( retval ) \
   do { \
          if ((Com_audteIPduStatus[51] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal362 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_362( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_362( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 52*/
#define COM_CHECK_STATUS_363( retval ) \
   do { \
          if ((Com_audteIPduStatus[52] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal363 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_363( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_363( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_364( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal364 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_364( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_364( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_365( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal365 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_365( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_365( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_366( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal366 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_366( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_366( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_367( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal367 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_367( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_367( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_368( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal368 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_368( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_368( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_369( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal369 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_369( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_369( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_370( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal370 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_370( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_370( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_371( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal371 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_371( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_371( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_372( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal372 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_372( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_372( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_373( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal373 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_373( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_373( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_374( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal374 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_374( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_374( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_375( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal375 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_375( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_375( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_376( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal376 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_376( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_376( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_377( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal377 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_377( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_377( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_378( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal378 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_378( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_378( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_379( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal379 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_379( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_379( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_380( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal380 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_380( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_380( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_381( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal381 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_381( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_381( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 53*/
#define COM_CHECK_STATUS_382( retval ) \
   do { \
          if ((Com_audteIPduStatus[53] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal382 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_382( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_382( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_383( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal383 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_383( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_383( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 54*/
#define COM_CHECK_STATUS_384( retval ) \
   do { \
          if ((Com_audteIPduStatus[54] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal384 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_384( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_384( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 54*/
#define COM_CHECK_STATUS_385( retval ) \
   do { \
          if ((Com_audteIPduStatus[54] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal385 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_385( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_385( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 54*/
#define COM_CHECK_STATUS_386( retval ) \
   do { \
          if ((Com_audteIPduStatus[54] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal386 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_386( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_386( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 54*/
#define COM_CHECK_STATUS_387( retval ) \
   do { \
          if ((Com_audteIPduStatus[54] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal387 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_387( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_387( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 54*/
#define COM_CHECK_STATUS_388( retval ) \
   do { \
          if ((Com_audteIPduStatus[54] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal388 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_388( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_388( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 56*/
#define COM_CHECK_STATUS_389( retval ) \
   do { \
          if ((Com_audteIPduStatus[56] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal389 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_389( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_389( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 56*/
#define COM_CHECK_STATUS_390( retval ) \
   do { \
          if ((Com_audteIPduStatus[56] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal390 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_390( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_390( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 56*/
#define COM_CHECK_STATUS_391( retval ) \
   do { \
          if ((Com_audteIPduStatus[56] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal391 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_391( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_391( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 57*/
#define COM_CHECK_STATUS_392( retval ) \
   do { \
          if ((Com_audteIPduStatus[57] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal392 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_392( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_392( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 58*/
#define COM_CHECK_STATUS_393( retval ) \
   do { \
          if ((Com_audteIPduStatus[58] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal393 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_393( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_393( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 58*/
#define COM_CHECK_STATUS_394( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[58] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal394 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_394( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_394( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 58*/
#define COM_CHECK_STATUS_395( retval ) \
   do { \
          if ((Com_audteIPduStatus[58] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal395 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_395( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_395( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 58*/
#define COM_CHECK_STATUS_396( retval ) \
   do { \
          if ((Com_audteIPduStatus[58] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal396 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_396( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_396( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_397( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal397 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_397( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_397( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_398( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal398 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_398( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_398( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_399( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal399 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_399( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_399( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_400( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal400 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_400( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_400( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_401( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal401 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_401( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_401( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_402( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal402 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_402( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_402( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_403( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal403 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_403( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_403( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 59*/
#define COM_CHECK_STATUS_404( retval ) \
   do { \
          if ((Com_audteIPduStatus[59] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal404 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_404( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_404( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 60*/
#define COM_CHECK_STATUS_405( retval ) \
   do { \
          if ((Com_audteIPduStatus[60] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal405 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_405( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_405( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 60*/
#define COM_CHECK_STATUS_406( retval ) \
   do { \
          if ((Com_audteIPduStatus[60] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal406 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_406( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_406( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 60*/
#define COM_CHECK_STATUS_407( retval ) \
   do { \
          if ((Com_audteIPduStatus[60] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal407 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_407( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_407( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 60*/
#define COM_CHECK_STATUS_408( retval ) \
   do { \
          if ((Com_audteIPduStatus[60] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal408 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_408( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_408( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 60*/
#define COM_CHECK_STATUS_409( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[60] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal409 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_409( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_409( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_410( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal410 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_410( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_410( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_411( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal411 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_411( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_411( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_412( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal412 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_412( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_412( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_413( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal413 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_413( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_413( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_414( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal414 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_414( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_414( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_415( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal415 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_415( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_415( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_416( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal416 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_416( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_416( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_417( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal417 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_417( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_417( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_418( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal418 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_418( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_418( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_419( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal419 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_419( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_419( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_420( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal420 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_420( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_420( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 62*/
#define COM_CHECK_STATUS_421( retval ) \
   do { \
          if ((Com_audteIPduStatus[62] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal421 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_421( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_421( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_422( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal422 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_422( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_422( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_423( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal423 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_423( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_423( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_424( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal424 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_424( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_424( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_425( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal425 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_425( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_425( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_426( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal426 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_426( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_426( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_427( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal427 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_427( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_427( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_428( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal428 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_428( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_428( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_429( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal429 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_429( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_429( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_430( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal430 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_430( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_430( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_431( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal431 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_431( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_431( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_432( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal432 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_432( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_432( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_433( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal433 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_433( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_433( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_434( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal434 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_434( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_434( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 63*/
#define COM_CHECK_STATUS_435( retval ) \
   do { \
          if ((Com_audteIPduStatus[63] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal435 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_435( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_435( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_436( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal436 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_436( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_436( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_437( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal437 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_437( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_437( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_438( retval ) \
   do { \
  SchM_Enter_Com_IPduStatus_0B(); \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
       SchM_Exit_Com_IPduStatus_0B(); \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal438 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_438( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_438( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 34*/
#define COM_CHECK_STATUS_439( retval ) \
   do { \
          if ((Com_audteIPduStatus[34] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal439 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_439( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_439( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 55*/
#define COM_CHECK_STATUS_440( retval ) \
   do { \
          if ((Com_audteIPduStatus[55] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal440 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_440( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_440( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 55*/
#define COM_CHECK_STATUS_441( retval ) \
   do { \
          if ((Com_audteIPduStatus[55] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal441 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_441( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_441( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 55*/
#define COM_CHECK_STATUS_442( retval ) \
   do { \
          if ((Com_audteIPduStatus[55] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal442 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_442( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_442( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 55*/
#define COM_CHECK_STATUS_443( retval ) \
   do { \
          if ((Com_audteIPduStatus[55] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal443 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_443( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_443( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 43*/
#define COM_CHECK_STATUS_444( retval ) \
   do { \
          if ((Com_audteIPduStatus[43] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal444 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_444( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_444( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 43*/
#define COM_CHECK_STATUS_445( retval ) \
   do { \
          if ((Com_audteIPduStatus[43] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal445 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_445( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_445( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 43*/
#define COM_CHECK_STATUS_446( retval ) \
   do { \
          if ((Com_audteIPduStatus[43] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal446 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_446( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_446( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 43*/
#define COM_CHECK_STATUS_447( retval ) \
   do { \
          if ((Com_audteIPduStatus[43] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal447 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_447( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_447( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 43*/
#define COM_CHECK_STATUS_448( retval ) \
   do { \
          if ((Com_audteIPduStatus[43] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal448 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_448( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_448( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_449( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal449 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_449( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_449( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_450( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal450 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_450( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_450( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 24*/
#define COM_CHECK_STATUS_451( retval ) \
   do { \
          if ((Com_audteIPduStatus[24] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal451 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_451( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_451( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 55*/
#define COM_CHECK_STATUS_452( retval ) \
   do { \
          if ((Com_audteIPduStatus[55] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal452 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_452( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_452( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_453( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal453 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_453( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_453( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_454( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal454 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_454( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_454( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_455( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal455 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_455( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_455( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_456( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal456 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_456( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_456( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_457( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal457 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_457( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_457( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_458( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal458 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_458( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_458( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 64*/
#define COM_CHECK_STATUS_459( retval ) \
   do { \
          if ((Com_audteIPduStatus[64] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal459 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_459( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_459( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_460( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal460 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_460( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_460( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_461( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal461 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_461( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_461( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_462( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal462 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_462( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_462( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_463( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal463 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_463( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_463( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_464( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal464 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_464( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_464( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_465( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal465 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_465( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_465( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 65*/
#define COM_CHECK_STATUS_466( retval ) \
   do { \
          if ((Com_audteIPduStatus[65] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal466 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_466( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_466( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 66*/
#define COM_CHECK_STATUS_467( retval ) \
   do { \
          if ((Com_audteIPduStatus[66] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal467 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_467( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_467( SignalDataPtr );
   }
   }
   return retval;
}

 /*signal belongs to IPdu with ID 66*/
#define COM_CHECK_STATUS_468( retval ) \
   do { \
          if ((Com_audteIPduStatus[66] & (Com_u8ACTIVE_MASK) ) == FALSE)\
          { retval = COM_SERVICE_NOT_AVAILABLE;} \
   } while( 0 )
   
FUNC(uint8,COM_CODE) Com_ReceiveSignal468 
(
   P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
uint8 retval = E_OK;
#if (COM_DEV_ERROR_DETECT == STD_ON)
if (Com_enueStatus == COM_UNINIT)
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_UNINIT);
retval = COM_SERVICE_NOT_AVAILABLE;
}
else if ( SignalDataPtr ==  NULL_PTR )
{
(void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
retval = COM_SERVICE_NOT_AVAILABLE;
}
  else
#endif
   {
   COM_CHECK_STATUS_468( retval );
   if (retval == E_OK)
   {
       COM_RECEIVE_SIGNAL_468( SignalDataPtr );
   }
   }
   return retval;
}

#endif
      
