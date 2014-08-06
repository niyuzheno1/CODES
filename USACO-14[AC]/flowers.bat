@echo off
if "%1"=="" goto loop
copy flowers%1.in flowers.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc flowers.out flowers%1.out
del flowers.in
del flowers.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
