@echo off
if "%1"=="" goto loop
copy stock%1.in stock.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc stock.out stock%1.out
del stock.in
del stock.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13) do call %0 %%i
:end
