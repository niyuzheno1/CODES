@echo off
if "%1"=="" goto loop
copy ppg%1.in ppg.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc ppg.out ppg%1.ans
del ppg.in
del ppg.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end