@echo off
if "%1"=="" goto loop
copy asteroid%1.in asteroid.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc asteroid.out asteroid%1.out
del asteroid.in
del asteroid.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
