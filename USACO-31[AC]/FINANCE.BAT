@echo off
if "%1"=="" goto loop
copy finance%1.in finance.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc finance.out finance%1.out
del finance.in
del finance.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
