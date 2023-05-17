@echo off

call "setup_mingw.bat"

cd .

if "%1"=="" ("D:\PROGRA~1\MATLAB\R2021b\bin\win64\gmake"  -f tone_search_rtw.mk all) else ("D:\PROGRA~1\MATLAB\R2021b\bin\win64\gmake"  -f tone_search_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1