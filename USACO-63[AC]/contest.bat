@echo off
if "%1"=="" goto loop
copy contest%1.in contest.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc contest.out contest%1.out
del contest.in
del contest.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
