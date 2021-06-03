@echo off
:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 14:37 31/05/2021
::  */

:: APARENCIA
color 0A
mode 60,15

:INICIO
set ext=*

:MENU
cls
echo.
echo  /----------------------------\
echo  .         SELECIONE          .
echo  .----------------------------.
echo  . [1 OU A] CRYPT             .
echo  . [2 OU S] DECRYPT           .
echo  \----------------------------/
echo.
echo  EXT selecionada = %ext%
echo.
set /p opcao=Opssaum: 
if %Opcao% EQU 1 set /a Opcao=1 & goto VALIDA
if %Opcao%==a set /a Opcao=1 & goto VALIDA
if %Opcao%==A set /a Opcao=1 & goto VALIDA
if %Opcao% EQU 2 set /a Opcao=2 & goto VALIDA
if %Opcao%==s set /a Opcao=2 & goto VALIDA
if %Opcao%==S set /a Opcao=2 & goto VALIDA
:INVALIDA
echo.
echo Opssaum invalida!
echo.
pause
goto MENU
:VALIDA

:COMANDOS
echo Password...
set /p Password=
if %Opcao% EQU 1 set Texto=Criptografando
if %Opcao% EQU 1 set Parametro=e
if %Opcao% EQU 1 move "Utilidades [SMx32]"\*.aes %cd%
if %Opcao% EQU 2 set Texto=Descriptografando
if %Opcao% EQU 2 set Parametro=d
if %Opcao% EQU 2 set ext=aes
for /f "tokens=*" %%a in ('dir/a-d/b "Utilidades [SMx32]"\*.%ext%') do (
	echo %Texto% "Utilidades [SMx32]\%%a"
	0AESCrypt64.exe -%Parametro% -p %Password% "Utilidades [SMx32]\%%a"
	if %Opcao%==1 if exist "Utilidades [SMx32]\%%a.aes" del "Utilidades [SMx32]\%%a"
	if %Opcao%==2 if exist "Utilidades [SMx32]\%%~na" del "Utilidades [SMx32]\%%a"
)
move *.aes "Utilidades [SMx32]"
goto FIM

:FIM