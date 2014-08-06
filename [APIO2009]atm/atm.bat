@echo off
if "%1"=="" goto loop
copy atm.in%1 atm.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc atm.out atm.out%1
del atm.in
del atm.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8) do call %0 %%i
:end
