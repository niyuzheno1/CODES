@echo off
if "%1"=="" goto loop
copy jail%1.in jail.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc jail.out jail%1.out
del jail.in
del jail.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5  6 7 8 9 10) do call %0 %%i
:end