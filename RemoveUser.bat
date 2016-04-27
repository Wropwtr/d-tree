FORFILES /M *.user /S /C "cmd /c del /q /f @file"
FORFILES /M *.sdf /S /C "cmd /c del /q /f @file"
FORFILES /S /C "cmd /c rmdir /s/q Debug"