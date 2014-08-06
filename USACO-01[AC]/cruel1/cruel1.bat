@echo off
if "%1"=="" goto loop
copy cruel1%1.in cruel1.in >nul
echo Problem Test
echo Data %1
time<enter
cruel1
time<enter
fc cruel1.out cruel1%1.out
del cruel1.in
del cruel1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14) do call %0 %%i
:end
