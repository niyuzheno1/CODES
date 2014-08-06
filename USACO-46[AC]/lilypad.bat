@echo off
if "%1"=="" goto loop
copy lilypad%1.in lilypad.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc lilypad.out lilypad%1.out
del lilypad.in
del lilypad.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16) do call %0 %%i
:end
