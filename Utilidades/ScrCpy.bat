:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 19:36 14/03/2024
::  */

@echo off

:: APARENCIA

:SET
set Path=

:INICIO

:: COMANDOS
for /f "tokens=*" %%d in ('dir /ad/b') do (set "Path=%%d")
cd %Path%
scrcpy -f --lock-video-orientation=270 --record=Video_e0001.mp4

:FIM
taskkill /f /im adb*