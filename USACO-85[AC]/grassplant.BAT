@echo off
if "%1"=="" goto loop
copy I.%1 grassplant.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc grassplant.out O.%1 
del grassplant.in
del grassplant.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13) do call %0 %%i
:end
