@echo off
if "%1"=="" goto loop
copy lights%1.in lights.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
time<enter
fc lights.out lights%1.out
del lights.in
del lights.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17) do call %0 %%i
:end
