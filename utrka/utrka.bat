@echo off
if "%1"=="" goto loop
copy utrka.in.%1 utrka.in >nul
echo Problem Test
echo Data %1
time<enter
utrka
time<enter
fc utrka.out utrka.out.%1
del utrka.in
del utrka.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
