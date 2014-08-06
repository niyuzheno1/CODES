@echo off
if "%1"=="" goto loop
copy monkey%1.in monkey.in >nul
echo Problem Test
echo Data %1
time<enter
ans2
time<enter
fc monkey.out monkey%1.out
del monkey.in
del monkey.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end