@echo off
set OUTPUT_FILE=merged_code.txt

:: Delete the old merged file if it exists
if exist %OUTPUT_FILE% del %OUTPUT_FILE%

echo --- MERGED CODE START --- > %OUTPUT_FILE%

:: Loop through all .h and .cpp files
for %%f in (*.h *.cpp) do (
    echo. >> %OUTPUT_FILE%
    echo ======================================== >> %OUTPUT_FILE%
    echo FILE: %%f >> %OUTPUT_FILE%
    echo ======================================== >> %OUTPUT_FILE%
    type "%%f" >> %OUTPUT_FILE%
    echo. >> %OUTPUT_FILE%
)

echo Done! Created %OUTPUT_FILE%
pause