@echo off
if "%1"=="" goto loop
copy sightsee%1.in sightsee.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc sightsee.out sightsee%1.out
del sightsee.in
del sightsee.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end