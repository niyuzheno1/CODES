@echo off
if "%1"=="" goto loop
copy osmrtfun%1.in smrtfun.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc smrtfun.out osmrtfun%1.out
del smrtfun.in
del smrtfun.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
