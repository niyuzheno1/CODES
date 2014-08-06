@echo off
if "%1"=="" goto loop
copy cornmaze%1.in cornmaze.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc cornmaze.out cornmaze%1.out
del cornmaze.in
del cornmaze.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16) do call %0 %%i
:end
