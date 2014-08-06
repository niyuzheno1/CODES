@echo off
if "%1"=="" goto loop
copy ttravel%1.in ttravel.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc ttravel.out ttravel%1.out
del ttravel.in
del ttravel.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
