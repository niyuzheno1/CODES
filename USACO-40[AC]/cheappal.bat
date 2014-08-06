@echo off
if "%1"=="" goto loop
copy cheappal%1.in cheappal.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc cheappal.out cheappal%1.out
del cheappal.in
del cheappal.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
