@echo off
if "%1"=="" goto loop
copy toll%1.in toll.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc toll.out toll%1.out
del toll.in
del toll.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
