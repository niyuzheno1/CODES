@echo off
if "%1"=="" goto loop
copy navigate%1.in navigate.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc navigate.out navigate%1.out
del navigate.in
del navigate.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
