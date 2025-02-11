Option Explicit
Dim objFSO, objShell, strUsername, strSourcePath, strDestPath
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("WScript.Shell")
strUsername = objShell.ExpandEnvironmentStrings("%USERNAME%")
strSourcePath = WScript.ScriptFullName
strDestPath = objShell.ExpandEnvironmentStrings("C:\Users\" & strUsername & "\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\")
If objFSO.FileExists(strDestPath & WScript.ScriptName) Then
objFSO.CopyFile strSourcePath, strDestPath
End If
objShell.run "firefox.exe https://bk-hilden.lms.schulon.org/login/index.php"
WScript.Sleep 1500
objShell.SendKeys "{TAB}"
objShell.SendKeys "{TAB}"
objShell.SendKeys "{TAB}"
objShell.SendKeys "{TAB}"
objShell.SendKeys "{TAB}"
objShell.SendKeys "{Enter}"
WScript.Sleep 500
objShell.SendKeys "{Enter}"