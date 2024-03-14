@echo off
rem /**
rem  * mersonfufu@gmail.com
rem  * ultima update em 12:06 2018-01-27
rem  */

:INICIO
set Folder="%AppData%\Notepad++\"

rem COMANDOS
copy /y "NotepadPP - Configs.xml" %Folder%\config.xml
copy /y "NotepadPP - ContextMenu.xml" %Folder%\contextMenu.xml

:FIM