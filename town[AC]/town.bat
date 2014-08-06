@echo off
if "%1"=="" goto loop
copy town%1.in town.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc town.out town%1.out
del town.in
del town.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
