@echo off
if "%1"=="" goto loop
copy job.%1.in job.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc job.out job.%1.out
del job.in
del job.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
