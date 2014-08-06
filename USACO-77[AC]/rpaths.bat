@echo off
if "%1"=="" goto loop
copy rpaths%1.in rpaths.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc rpaths.out rpaths%1.out
del rpaths.in
del rpaths.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
