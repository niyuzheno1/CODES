@echo off
if "%1"=="" goto loop
copy solder%1.in solder.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
time<enter
fc solder.out solder%1.out
del solder.in
del solder.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19) do call %0 %%i
:end
