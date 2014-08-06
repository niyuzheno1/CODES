@echo off
if "%1"=="" goto loop
copy dream%1.in dream.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc dream.out dream%1.out
del dream.in
del dream.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
