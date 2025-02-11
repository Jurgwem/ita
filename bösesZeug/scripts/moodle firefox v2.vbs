Option Explicit
Dim objFSO, objShell, strUsername, strStartupPath, strScriptPath
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("WScript.Shell")
strUsername = objShell.ExpandEnvironmentStrings("%USERNAME%")
strStartupPath = objShell.ExpandEnvironmentStrings("C:\Users\" & strUsername & "\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\")
strScriptPath = WScript.ScriptFullName
If Not objFSO.FileExists(strStartupPath & WScript.ScriptName) Then
    objFSO.CopyFile strScriptPath, strStartupPath
End If
objShell.Run "firefox.exe https://bk-hilden.lms.schulon.org/login/index.php", 1, False
WScript.Sleep 1500
objShell.SendKeys "{TAB 5}{ENTER}"
WScript.Sleep 500
objShell.SendKeys "{ENTER}"
