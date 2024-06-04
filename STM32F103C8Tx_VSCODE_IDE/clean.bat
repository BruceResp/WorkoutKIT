@echo off  
setlocal  
  
REM 定义要删除的文件列表  
REM set "fileList=.\file.txt C:\path\to\your\second\file.log C:\another\path\to\a\third\file.dat"  
  
REM 定义要删除的文件夹路径  
set "folderPath=.\build"  

@REM REM 删除指定的文件  
@REM for %%f in (%fileList%) do (  
@REM     if exist "%%f" (  
@REM         echo 正在删除文件: %%f  
@REM         del /F /Q "%%f"  
@REM         if not errorlevel 1 echo 文件 %%f 已成功删除。  
@REM     ) else (  
@REM         echo 文件 %%f 不存在。  
@REM     )  
@REM )  
  
REM 删除指定的文件夹及其内容  
if exist "%folderPath%" (  
    echo Is Delting: %folderPath%  
    rd /S /Q "%folderPath%"  
    if not errorlevel 1 echo file %folderPath% deltes successed.  
) else (  
    echo file %folderPath% doesn't exit.  
)  

if not exist "%folderPath%" (  
    REM 如果文件夹不存在，则创建它  
    echo Is Creating: %folderPath%  
    md "%folderPath%" 
    @REM 一个空格导致的错误
    if exist "%folderPath%" (   
        echo %folderPath% creates successed
    ) else (
        echo %folderPath% creates failed
    )
) else (
    echo File already exists
)


endlocal  
exit 
