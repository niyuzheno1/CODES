@echo off
if "%1"=="" goto loop
copy seven%1.in seven.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc seven.out seven%1.out
del seven.in
del seven.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end