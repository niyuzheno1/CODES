@echo off
if "%1"=="" goto loop
copy Roads%1.in Roads.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc Roads.out Roads%1.out
del Roads.in
del Roads.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14) do call %0 %%i
:end
