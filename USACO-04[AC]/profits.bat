@echo off
if "%1"=="" goto loop
copy profits%1.in profits.in >nul
echo Problem Test
echo Data %1
time<enter
profits
time<enter
fc profits.out profits%1.out
del profits.in
del profits.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
