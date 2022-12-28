@echo off
set XDM_INPUT_DIR=config
set TRESOS_OUTPUT_DIR=configOutput
set TRESOS_VERSION=14_2_0
set LOG_FILE_NAME=geneTresos.res
if not exist %TRESOS_PATH%\%TRESOS_VERSION%\bin\tresos_cmd.bat goto ERROR_TRESOS_LOCATION


echo.
echo ---------------------------------------------------------------------------
echo Update all plugins
echo ---------------------------------------------------------------------------
echo.
s:\util\choice /c:yn /n It will remove all existing plugins in %TRESOS_PATH%\%TRESOS_VERSION%\plugins - Continue anyway [Y]es [N]o ? 
if errorlevel 2 goto PRE_TRESOS


rem Remove all previous MCAL plugins
for /F %%i in ('dir /B %TRESOS_PATH%\%TRESOS_VERSION%\plugins\*_aurix') do (rd /s /q %TRESOS_PATH%\%TRESOS_VERSION%\plugins\%%i)

rem Unzip all plugins
for /F %%i in ('dir /B /S ..\..\..\..\02_TresosPlugin') do (
for /F %%j in ('dir /B /S %%i') do (
startenv unzip -y %%j -o%TRESOS_PATH%\%TRESOS_VERSION%\plugins
)
)

:PRE_TRESOS
if exist ..\tresos_workspace goto TRESOS
echo.
echo ---------------------------------------------------------------------------------------------------
echo Prepare tresos workspace folder with all xdm in ..\tresos_workspace folder
echo ---------------------------------------------------------------------------------------------------
echo.
if not exist ..\tresos_workspace\config md ..\tresos_workspace\config
if not exist ..\tresos_workspace\.prefs md ..\tresos_workspace\.prefs
if not exist ..\tresos_workspace\%TRESOS_OUTPUT_DIR% md ..\tresos_workspace\%TRESOS_OUTPUT_DIR%
if not exist %COMPILER_LOCAL_PATH% call set_env_inte
cd..
FOR /F "skip=2 delims== tokens=2*" %%i in ('find "COMPILER_VERSION" c:\env\env_proj.ini') do (
set LOCAL_COMPILER_VERSION=%%i
)

%COMPILER_LOCAL_PATH%\%LOCAL_COMPILER_VERSION%\bin\find ../../../.. -iname "*.xdm">temp
FOR /F %%a in (temp) do (
   %COMPILER_LOCAL_PATH%\%LOCAL_COMPILER_VERSION%\bin\cp %%a tresos_workspace/config
)
del temp
copy tresos_workspace\config\preferences.xdm tresos_workspace\.prefs\preferences.xdm
del tresos_workspace\config\preferences.xdm
copy 02_Tresos\.project tresos_workspace
attrib -R /S /D
cd 02_Tresos


:TRESOS
attrib -R /S /D
echo.
echo ---------------------------------------------------------------------------------------------------
echo All .xdm files are present in ..\tresos_workspace\%TRESOS_OUTPUT_DIR% folder
echo ---------------------------------------------------------------------------------------------------
echo.
rem s:\util\choice /c:yn /n Do you want to generate .c and .h file from .xdm files in ..\tresos_workspace\%TRESOS_OUTPUT_DIR% folder [Y]es [N]o ? 
rem if errorlevel 2 goto END

rem set VrTest=
rem for /f "delims=" %%i in ('type list_xdm') do set VrTt=%%i& call :treat
rem goto CMD

rem :treat
rem set VrTest=%VrTest% -g %VrTt%_AurixAS403 %VrTt%.xdm@xdm
rem goto :eof

rem :CMD
rem cd ..\tresos_workspace
rem call %TRESOS_PATH%\%TRESOS_VERSION%\bin\tresos_cmd.bat -Dwarning=true -DmergeConfigs=true -Dtarget=AURIX -Dderivate=TC277 legacy generate -c %XDM_INPUT_DIR% -o %TRESOS_OUTPUT_DIR% %VrTest% > %TRESOS_OUTPUT_DIR%\%LOG_FILE_NAME%
rem type %TRESOS_OUTPUT_DIR%\%LOG_FILE_NAME%
rem rd /S /Q %TRESOS_OUTPUT_DIR%\Demo_Aurix
rem cd ..\02_Tresos
echo.
echo ---------------------------------------------------------------------------------------------------
echo Carry over modifications done in ..\tresos_workspace\%TRESOS_OUTPUT_DIR% folder to 02_Tresos folder
echo Remove ..\tresos_workspace BEFORE compiling the software
echo ---------------------------------------------------------------------------------------------------
echo.
goto END

:ERROR_TRESOS_LOCATION
echo %TRESOS_PATH%\%TRESOS_VERSION%\bin\tresos_cmd.bat does not exist, please install TRESOS tool at this location.
goto END

:END
set XDM_INPUT_DIR=
set TRESOS_OUTPUT_DIR=
set TRESOS_VERSION=
set LOG_FILE_NAME=
set VrTest=
set VrTt=
set LOCAL_COMPILER_VERSION=
