@echo off
:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 14:05 04/06/2021
::  */

:: APARENCIA
color 0A
mode 80,15

:INICIO
echo Commit message...
set /p Commit=
git add -A
git commit -m "%Commit%"
git push

:FIM
exit