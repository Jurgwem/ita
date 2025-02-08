@echo off
taskkill /f /im KILLV1.exe
start C:\Windows\explorer.exe
del /Q C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\payload.bat
::
::if you can read this, 'steam.exe' has had this user infected at some point!
::(for clarification it's not malware)
::  -=-=- S#itty code by Jurgwem -=-=-
::
del /Q C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\debug.bat
del /Q C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\KILLV1.exe
exit