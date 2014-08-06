@echo off
if "%1"=="" goto loop
copy input%1.txt bounce.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc bounce.out output%1.txt
del bounce.in
del bounce.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
