@echo off
if "%1"=="" goto loop
copy ontherun%1.in ontherun.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc ontherun.out ontherun%1.out
del ontherun.in
del ontherun.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
