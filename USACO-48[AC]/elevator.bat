@echo off
if "%1"=="" goto loop
copy elevator%1.in elevator.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc elevator.out elevator%1.out
del elevator.in
del elevator.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
