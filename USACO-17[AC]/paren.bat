@echo off
if "%1"=="" goto loop
copy paren%1.in paren.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc paren.out paren%1.out
del paren.in
del paren.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
