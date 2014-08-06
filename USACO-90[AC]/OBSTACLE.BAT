@echo off
if "%1"=="" goto loop
copy obstacle%1.in obstacle.in >nul
echo Problem Test
echo Data %1
time<enter
Ans1
time<enter
fc obstacle.out obstacle%1.out
del obstacle.in
del obstacle.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
