
@echo off

set RepGCC=c:\GCC\bin\
set Out=GeneFRM.exe

del *.o %Out%

for %%I in (*.cpp) do (
echo Compilation de %%I
%RepGCC%\g++ -W -Wall -pedantic -O3 -o %%I.o -c %%I
)

echo Linkage de GeneFRM.exe
%RepGCC%\g++ -o %Out% *.o

del *.o

PAUSE
