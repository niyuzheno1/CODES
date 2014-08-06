@echo off
if "%1"=="" goto loop
copy roads%1.in roads.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc roads.out roads%1.out
del roads.in
del roads.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
