@echo off
if "%1"=="" goto loop
copy frame%1.in frame.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc frame.out frame%1.ans
del frame.in
del frame.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
