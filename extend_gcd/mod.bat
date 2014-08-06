@echo off
if "%1"=="" goto loop
copy mod%1.in mod.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc mod.out mod%1.ans
del mod.in
del mod.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end