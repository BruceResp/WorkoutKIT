@echo off  
setlocal  
  
REM 定义要删除的文件列表  
REM set "fileList=.\file.txt C:\path\to\your\second\file.log C:\another\path\to\a\third\file.dat"  

set "Makefile=Makefile"

if exist ".\build\%Makefile%" (  
    cd build
    echo Found Makefile in .\build
    make -j
    if %errorlevel% neq 0 (  
        echo Error with make -j  
    )
    cd ..
) else (
    echo Makefile not exists in Current Address.you should make sure Makefile exist.
)

exit /b 0
endlocal  
 
