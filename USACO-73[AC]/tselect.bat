@echo off
if "%1"=="" goto loop
copy tselect%1.in tselect.in >nul
echo Problem Test
echo Data %1
time<enter
Ans3
time<enter
fc tselect.out tselect%1.out
del tselect.in
del tselect.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
