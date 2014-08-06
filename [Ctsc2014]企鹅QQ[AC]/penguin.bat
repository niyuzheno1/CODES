@echo off
if "%1"=="" goto loop
copy penguin%1.in penguin.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc penguin.out penguin%1.ans
del penguin.in
del penguin.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
