Option Explicit
Dim objFSO, objShell, strUsername, strSourcePath, strDestPath
Dim objRandom, intRandom
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("WScript.Shell")
strUsername = objShell.ExpandEnvironmentStrings("%USERNAME%")
strSourcePath = WScript.ScriptFullName
strDestPath = objShell.ExpandEnvironmentStrings("C:\Users\" & strUsername & "\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\")
If objFSO.FileExists(strDestPath & WScript.ScriptName) Then
Else
objFSO.CopyFile strSourcePath, strDestPath
End If
objShell.Run("""C:\Program Files\SafeExamBrowser\Application\SafeExamBrowser.exe""")
WScript.Sleep 1000
objShell.AppActivate "SafeExamBrowser"