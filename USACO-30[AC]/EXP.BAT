@echo off
if "%1"=="" goto loop
copy exp%1.in exp.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc exp.out exp%1.out
del exp.in
del exp.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
