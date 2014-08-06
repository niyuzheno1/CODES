@echo off
if "%1"=="" goto loop
copy ball%1.in ball.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc ball.out ball%1.ans
del ball.in
del ball.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end