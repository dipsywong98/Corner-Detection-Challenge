::param 1 is timeout seconds, param 2 is executable
echo "running %2 with timeout %1, with additional params"
start /b %2 %3
set time=0

:check
tasklist /FI "IMAGENAME eq %2" 2>NUL | find /I /N "%2">NUL
::time limit exceed
if "%time%"=="%1" goto kill
::program is running
if "%ERRORLEVEL%"=="0" ( ping 127.0.0.1 -n 2 >nul & set /a time=%time%+1 & goto check) else ( goto end)

:kill
echo "terminate"
taskkill /im %2 /f

:end
echo "end with errorlevel %ERRORLEVEL%"