@echo off
if "%1"=="" goto loop
copy tower.%1.in tower.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc tower.out tower.%1.out
del tower.in
del tower.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17) do call %0 %%i
:end
