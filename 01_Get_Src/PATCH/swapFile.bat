@echo off

echo ---------------------------------------------------------------------------
echo  ATTENTION --- Patch des fichiers ASW
echo ---------------------------------------------------------------------------

echo Renommage EEPMNG_NVMSRV.oil EEPMNG_NVMSRV.oil.old dans EEPMNG
ren ..\ASW\EEPMNG\EEPMNG_NVMSRV.oil EEPMNG_NVMSRV.oil.old
echo Renommage frm_api.h en frm_api.h.old
ren ..\ASW\FRM\frm_api.h frm_api.h.old
echo Renommage STUB_DGOHAL.OIL en STUB_DGOHAL.OIL.old
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\STUB\02_Config\01_Genecode\STUB_DGOHAL.OIL STUB_DGOHAL.OIL.old

rem Pb CAT1
echo Renommage OBDSRV_MODE9Auto_API1.c en OBDSRV_MODE9Auto_API1.c.old
ren ..\ASW\OBDSRV\OBDSRV_MODE9Auto_API1.c OBDSRV_MODE9Auto_API1.c.old
echo IUPRRATIO renommage donnee.txt en donnee.txt.old
ren ..\ASW\GDGAR\GD\IUPRRATIO\donnee.txt donnee.txt.old

rem Pb List_std Moisi
echo Renommage COM_MIVIE_im.h en COM_MIVIE_im.h.old
ren ..\ASW\COM_EBDT_MIVIE\COM_MIVIE_im.h COM_MIVIE_im.h.old

rem Pb KNKACQFILT
echo Renommage KNKACQFILT_FCT2.c en KNKACQFILT_FCT2.c.old
ren ..\ASW\KNKACQFILT\KNKACQFILT_FCT2.c KNKACQFILT_FCT2.c.old

rem *******************************************************************************
rem Patch du CODE_RTE
rem *******************************************************************************
echo Renommage CatAcvDiagT_Version.c en CatAcvDiagT_Version.c.old
ren ..\ASW\CODE_RTE\PSA_CATACVDIAGT_3_1\CatAcvDiagT_Version.c CatAcvDiagT_Version.c.old
echo Renommage CatPasDiagT_Version.c en  CatPasDiagT_Version.c.old
ren ..\ASW\CODE_RTE\PSA_CATPASDIAGT_3_1\CatPasDiagT_Version.c CatPasDiagT_Version.c.old
echo Renommage rte_dcm_type.h en rte_dcm_type.h.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\rte_dcm_type.h rte_dcm_type.h.old
echo Renommage DCM_MANU_FCT2.c en DCM_MANU_FCT2.c.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\DCM_MANU_FCT2.c DCM_MANU_FCT2.c.old
echo Renommage DCM_MANU_Fix.h en DCM_MANU_Fix.h.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\DCM_MANU_Fix.h DCM_MANU_Fix.h.old
echo Renommage Nvm.h en Nvm.h.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\Nvm.h Nvm.h.old

echo Renommage Rte_VirtualComponent_Type.h en Rte_VirtualComponent_Type.h.old
ren ..\ASW\CODE_RTE\Rte_VirtualComponent_Type.h Rte_VirtualComponent_Type.h.old
echo Renommage Dlt_ReadDataADPT_API1.c en Dlt_ReadDataADPT_API1.c.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\Dlt_ReadDataADPT_API1.c Dlt_ReadDataADPT_API1.c.old
echo Renommage Dlt_ReadDataADPT_API2.c en Dlt_ReadDataADPT_API2.c.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\Dlt_ReadDataADPT_API2.c Dlt_ReadDataADPT_API2.c.old
echo Renommage Dlt_WriteDataADPT_API1.c en Dlt_WriteDataADPT_API1.c.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\Dlt_WriteDataADPT_API1.c Dlt_WriteDataADPT_API1.c.old
echo Renommage Dlt_WriteDataADPT_API2.c en Dlt_WriteDataADPT_API2.c.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\Dlt_WriteDataADPT_API2.c Dlt_WriteDataADPT_API2.c.old

rem Inte MacroModule
echo Renommage Compiler.h en Compiler.h.old
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\MCAL_TC29X_STD_P1\Std\Compiler.h Compiler.h.old
call l:\perl\bin\perl ..\..\..\Makefile\Tools\A2L\Split_Projet_A2l.pl ..\ASW\CODE_RTE\PSA_MM\a2l_global\EPR_EB2ADT.a2l
echo Renommage EPR_EB2ADT.a2l en EPR_EB2ADT.a2l.old
ren ..\ASW\CODE_RTE\PSA_MM\a2l_global\EPR_EB2ADT.a2l EPR_EB2ADT.a2l.old

rem Inte ComStack
echo Renommage tsautosar.h en tsautosar.h.old
ren ..\BSW\BASE_AS40\include\tsautosar.h tsautosar.h.old
echo Renommage tsmem.h en tsmem.h.old
ren ..\BSW\BASE_AS40\include\tsmem.h tsmem.h.old
echo Renommage ComM_Dcm.h en ComM_Dcm.h.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\ComM_Dcm.h ComM_Dcm.h.old
echo Renommage Crc.h en Crc_.h
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\MCAL_TC29X_CRC_P1\Crc\Crc.h Crc_.h
echo Renommage Crc.c en Crc.c.old
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\MCAL_TC29X_CRC_P1\Crc\Crc.c Crc.c.old
echo Renommage EcuM_PBCfg.c en EcuM_PBCfg.c.old
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\02_Config\02_Tresos\configOutput\src\EcuM_PBCfg.c EcuM_PBCfg.c.old
echo Renommage IfxGtm_regdef.h en IfxGtm_regdef.h.old
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\MCAL_TC29X_DRV_P1\Drv\IfxGtm_regdef.h IfxGtm_regdef.h.old

rem Inte NVRAM
echo Renommage Initeep_GDGAR.tpl en Initeep_GDGAR.tpl.old
ren ..\ASW\GDGAR\Initeep_GDGAR.tpl Initeep_GDGAR.tpl.old
echo Renommage NvM.c en NvM.c.old
ren ..\BSW\VD56_BSW\VD56_GEN_BSW\NVM_AS402\src\NvM.c NvM.c.old
echo Renommage dem.h en dem.h.old
ren ..\ASW\CODE_RTE\DCM_CONFIG\DCM_MANU\dem.h dem.h.old

rem Inte STACK_COM_CONFIG
echo Renommage Com_Cbk.c en Com_Cbk.c.old
ren ..\ASW\COM_EBDT_MIVIE\STACK_COM_CONFIG\Com_Cbk.c Com_Cbk.c.old

rem Inte ACQCMDDIO
echo Renommage ACQCMDDIO_GATEWAY.h en ACQCMDDIO_GATEWAY.h.old
ren ..\ASW\CODE_RTE\ACQCMDDIO\ACQCMDDIO_GATEWAY.h ACQCMDDIO_GATEWAY.h.old

