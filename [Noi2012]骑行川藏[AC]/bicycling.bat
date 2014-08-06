@echo off
if "%1"=="" goto loop
copy bicycling%1.in bicycling.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc bicycling.out bicycling%1.ans
del bicycling.in
del bicycling.out
pause
goto end
:loop
for %%i in (17 19 20) do call %0 %%i
:end
