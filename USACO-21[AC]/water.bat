@echo off
if "%1"=="" goto loop
copy water%1.in water.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc water.out water%1.out
del water.in
del water.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
