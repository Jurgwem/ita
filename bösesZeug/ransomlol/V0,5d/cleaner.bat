@echo off
taskkill /f /im KILLV1.exe
start C:\Windows\explorer.exe
reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System /v DisableTaskMgr /t REG_DWORD /d 0 /f
del /Q C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\payload.bat
::
::     S#itty RansomWare, awesome
::  -=-=- S#itty code by Jurgwem -=-=-
::
del /Q C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\debug.bat
del /Q C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\KILLV1.exe
exit