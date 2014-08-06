@echo off
if "%1"=="" goto loop
copy cornfld%1.in cornfld.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
time<enter
fc cornfld.out cornfld%1.out
del cornfld.in
del cornfld.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
