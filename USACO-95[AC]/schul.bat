@echo off
if "%1"=="" goto loop
copy schul%1.in schul.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc schul.out schul%1.out
del schul.in
del schul.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
