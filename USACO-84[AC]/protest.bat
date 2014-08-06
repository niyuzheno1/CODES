@echo off
if "%1"=="" goto loop
copy %1.in running.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
time<enter
fc running.out %1.out
del running.in
del running.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15) do call %0 %%i
:end
