@echo off
if "%1"=="" goto loop
copy neg2%1.in neg2.in >nul
echo Problem Test
echo Data %1
time<enter
neg2
time<enter
fc neg2.out neg2%1.out
del neg2.in
del neg2.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13) do call %0 %%i
:end
