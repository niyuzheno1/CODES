@echo off
if "%1"=="" goto loop
copy protest%1.in protest.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc protest.out protest%1.out
del protest.in
del protest.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
