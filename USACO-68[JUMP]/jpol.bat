@echo off
if "%1"=="" goto loop
copy jpol%1.in jpol.in >nul
echo Problem Test
echo Data %1
time<enter
jpol
time<enter
checkj
type check.txt
del check.txt
del jpol.in
del jpol.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16) do call %0 %%i
:end
