@echo off
if "%1"=="" goto loop
copy watchcow%1.in watchcow.in
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc watchcow.out watchcow%1.out
del watchcow.in
del watchcow.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
