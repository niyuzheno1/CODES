@echo off
if "%1"=="" goto loop
copy bobsled%1.in bobsled.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc bobsled.out bobsled%1.out
del bobsled.in
del bobsled.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15) do call %0 %%i
:end
