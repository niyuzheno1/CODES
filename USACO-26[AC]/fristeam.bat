@echo off
if "%1"=="" goto loop
copy fristeam%1.in fristeam.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc fristeam.out fristeam%1.out
del fristeam.in
del fristeam.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
