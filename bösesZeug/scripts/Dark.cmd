REM **For Windows 10**
powershell.exe Set-ItemProperty -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize -Name AppsUseLightTheme -Value 0
powershell.exe Set-ItemProperty -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize -Name SystemUsesLightTheme -Value 0
REM **For Office 2016**

powershell.exe Set-ItemProperty -Path HKCU:\Software\Microsoft\Office\16.0\Common -Name 'UI Theme' -Value 4
powershell.exe Set-ItemProperty -Path 'HKCU:\Software\Microsoft\Office\16.0\Common\Roaming\Identities\<<MODIFY_USERNAME_HERE>>\Settings\1186\{00000000-0000-0000-0000-000000000000}\PendingChanges' -Name 'Data' -Value ([byte[]](4, 0, 0, 0)) -Type Binary
REM ref: https://www.cloudappie.nl/change-theme-officeproplus-powershell/ for Office 2016
pause