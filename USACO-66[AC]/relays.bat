@echo off
if "%1"=="" goto loop
copy relays%1.in relays.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc relays.out relays%1.out
del relays.in
del relays.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
