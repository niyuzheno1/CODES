@echo off
if "%1"=="" goto loop
copy input%1.txt cryptcow.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc cryptcow.out output%1.txt
del cryptcow.in
del cryptcow.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
