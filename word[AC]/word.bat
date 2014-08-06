@echo off
if "%1"=="" goto loop
copy word%1.in word.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc word.out word%1.out
del word.in
del word.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
