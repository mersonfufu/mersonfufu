@echo off
:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 17:44 10/01/2022
::  */

:: APARENCIA
color 0A
mode 60,15

:INICIO
set ext=*
set Pasta=Utilidades [SMVMTx2]

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
if %Opcao% EQU 1 move "%Pasta%"\*.aes %cd%
if %Opcao% EQU 2 set Texto=Descriptografando
if %Opcao% EQU 2 set Parametro=d
if %Opcao% EQU 2 set ext=aes
for /f "tokens=*" %%a in ('dir/a-d/b "%Pasta%"\*.%ext%') do (
	echo %Texto% "%Pasta%\%%a"
	AESCrypt64.exe -%Parametro% -p %Password% "%Pasta%\%%a"
	if %Opcao%==1 if exist "%Pasta%\%%a.aes" del "%Pasta%\%%a"
	if %Opcao%==2 if exist "%Pasta%\%%~na" del "%Pasta%\%%a"
)
move *.aes "%Pasta%"
goto FIM

:FIM