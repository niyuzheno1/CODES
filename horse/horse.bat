@echo off
if "%1"=="" goto loop
copy horse%1.in horse.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc horse.out horse%1.out
del horse.in
del horse.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5  6 7 8 9 10) do call %0 %%i
:end