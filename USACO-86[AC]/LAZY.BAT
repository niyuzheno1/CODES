@echo off
if "%1"=="" goto loop
copy lazy%1.in lazy.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc lazy.out lazy%1.out
del lazy.in
del lazy.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
