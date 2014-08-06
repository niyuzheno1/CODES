@echo off
if "%1"=="" goto loop
copy horizon%1.in horizon.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc horizon.out horizon%1.out
del horizon.in
del horizon.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
