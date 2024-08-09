;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Default

; Recommended for performance and compatibility with future AutoHotkey releases.
#NoEnv

; Enable warnings to assist with detecting common errors.
; #Warn

; Recommended for new scripts due to its superior speed and reliability.
SendMode Input

; Ensures a consistent starting directory.
SetWorkingDir %A_ScriptDir%

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Etc

; /**
;  * mersonfufu@gmail.com
;  * ultima update em 15:00 12/09/2020
;  */

; Pastas do StartUp
; "%ProgramData%\Microsoft\Windows\Start Menu\Programs\Startup\" ; PC
; "%AppData%\Microsoft\Windows\Start Menu\Programs\Startup\" ; User

; Instância única
#SingleInstance force

; Capturador de teclas
; #InstallKeybdHook

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Comandos


; CTRL + ; = ?
^;::
 Send, ?
Return

; CTRL + / = /
^/::
 Send, /
Return

; CTRL + \ = \
^\::
 Send, \
Return

F1::F2              ; F1 = F2

Home::PgUp          ; Home = PgUp
End::PgDn           ; End = PgDn

PgDn::End           ; PgDn = End
PgUp::Home          ; PgUp = Home

RAlt::#PrintScreen  ; RAlt = Win + Print Screen
RCtrl::AppsKey      ; RCTRL = Apps

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Mega Man X Legacy
;j::x               ; Shot
;k::z               ; Jump
;l::a               ; Dash
;e::d               ; Left weapon
;u::c               ; Right weapon
;w::Up              ; Up
;s::Down            ; Down
;a::Left            ; Left
;d::Right           ; Right
;f::s               ; Save