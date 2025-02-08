@echo off
reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System /v DisableTaskMgr /t REG_DWORD /d 1 /f
exit
reg delete HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System DisableTaskMgr