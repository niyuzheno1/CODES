@echo off
if "%1"=="" goto loop
copy bcatch%1.in bcatch.in >nul
echo Problem Test
echo Data %1
time<enter
bcatch
time<enter
fc bcatch.out bcatch%1.out
del bcatch.in
del bcatch.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
