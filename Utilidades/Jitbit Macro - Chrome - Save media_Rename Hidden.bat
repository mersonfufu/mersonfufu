:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 18:38 09/08/2024
::  */

@echo off

:: APARENCIA

:: SET
:: CALCULAR-DATA

:LOOP
:: DEFINE DATAHORA
setlocal ENABLEDELAYEDEXPANSION
for /f "skip=1 tokens=1-6" %%a in ('wmic path Win32_LocalTime Get Day^,Hour^,Minute^,Month^,Second^,Year /Format:table') do (
	if not "%%~f"=="" (
		:: FormattedDate
		set /A FormattedDate=10000 * %%f + 100 * %%d + %%a
		set FormattedDate=!FormattedDate:~0,4!-!FormattedDate:~4,2!-!FormattedDate:~6,2!
		:: FormattedTime
		set /A FormattedTime=10000 * %%b + 100 * %%c + %%e
		set FormattedTime=0000000!FormattedTime!
		set FormattedTime=!FormattedTime:~-6,2!-!FormattedTime:~-4,2!-!FormattedTime:~-2,2!
	)
)
endlocal & set DATAHORA="%FormattedDate%_%FormattedTime%"

:INICIO

:COMANDOS
ren "hidden.*" "hidden - %DATAHORA%.*"
timeout /t 1 /nobreak > nul
goto LOOP

:FIM