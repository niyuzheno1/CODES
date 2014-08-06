@echo off
if "%1"=="" goto loop
copy toy%1.in toy.in >nul
echo Problem Test
echo Data %1
time<enter
toy
time<enter
fc toy.out toy%1.out
del toy.in
del toy.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) do call %0 %%i
:end
