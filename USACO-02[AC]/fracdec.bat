@echo off
if "%1"=="" goto loop
copy fracdec%1.in fracdec.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc fracdec.out fracdec%1.out
del fracdec.in
del fracdec.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 ) do call %0 %%i
:end
