@echo off
if "%1"=="" goto loop
copy cleanup%1.in cleanup.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
time<enter
fc cleanup.out cleanup%1.out
del cleanup.in
del cleanup.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
