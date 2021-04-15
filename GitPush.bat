@echo off
:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 14:05 04/06/2021
::  */

:: APARENCIA
:: color 0A
:: mode 80,15

:INICIO
echo Commit message...
set /p Commit=
git add -A
echo.
git commit -m "%Commit%"
echo.
git push
echo.
pause

:FIM
copy GitClone.bat ..