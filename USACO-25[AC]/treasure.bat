@echo off
if "%1"=="" goto loop
copy treasure%1.in treasure.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc treasure.out treasure%1.out
del treasure.in
del treasure.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15) do call %0 %%i
:end
