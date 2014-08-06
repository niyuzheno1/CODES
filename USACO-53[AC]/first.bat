@echo off
if "%1"=="" goto loop
copy %1.in first.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc first.out %1.out
del first.in
del first.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
