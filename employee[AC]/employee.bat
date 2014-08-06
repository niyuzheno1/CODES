@echo off
if "%1"=="" goto loop
copy employee%1.in employee.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc employee.out employee%1.ans
del employee.in
del employee.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
