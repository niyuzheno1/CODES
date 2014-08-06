@echo off
if "%1"=="" goto loop
copy mqueue%1.in mqueue.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc mqueue.out mqueue%1.out
del mqueue.in
del mqueue.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
