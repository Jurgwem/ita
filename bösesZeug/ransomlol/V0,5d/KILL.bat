@echo off
title KILL
::actual version: V3.1 
::build date: 19.09.
::to-do: taskkill system processes? settings, etc.

::nofly list
:1 
taskkill /f /im explorer.exe
taskkill /f /im chrome.exe
taskkill /f /im firefox.exe
taskkill /f /im msedge.exe
taskkill /f /im notepad.exe
taskkill /f /im code.exe
taskkill /f /im EXCEL.exe
taskkill /f /im POWERPNT.exe
taskkill /f /im WINWORD.exe
taskkill /f /im opera.exe
taskkill /f /im calc.exe
taskkill /f /im steam.exe


::self.destruct function, scans tasklist for KILL, kills itself if it cant find itself
timeout /T 2 /nobreak
tasklist /fi "ImageName eq KILL.exe" /fo csv 2>NUL | find /I "KILL.exe">NUL
if "%ERRORLEVEL%"=="0" goto :1
exit