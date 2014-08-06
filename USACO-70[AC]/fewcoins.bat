@echo off
if "%1"=="" goto loop
copy fewcoins%1.in fewcoins.in >nul
echo Problem Test
echo Data %1
time<enter
fewcoins
time<enter
fc fewcoins.out fewcoins%1.out
del fewcoins.in
del fewcoins.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
