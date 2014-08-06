@echo off
if "%1"=="" goto loop
copy majesty\majesty%1.in majesty.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc majesty.out majesty\majesty%1.out
del majesty.in
del majesty.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7) do call %0 %%i
:end
