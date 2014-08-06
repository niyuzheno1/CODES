@echo off
if "%1"=="" goto loop
copy traffic%1.in traffic.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
traffic
time<enter
fc traffic.out traffic.ans
del traffic.in
del traffic.out
del traffic.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
