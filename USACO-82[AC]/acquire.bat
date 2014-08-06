@echo off
if "%1"=="" goto loop
copy acquire%1.in acquire.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc acquire.out acquire%1.out
del acquire.in
del acquire.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
