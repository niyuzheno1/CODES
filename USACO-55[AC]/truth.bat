@echo off
if "%1"=="" goto loop
copy %1.in truth.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc truth.out %1.out
del truth.in
del truth.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
