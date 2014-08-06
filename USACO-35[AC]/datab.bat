@echo off
if "%1"=="" goto loop
copy jigsaw%1.in jigsaw.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter

copy jigsaw.out jigsaw%1.out  >nul
del jigsaw.in
del jigsaw.out
pause
goto end
:loop
for %%i in ( 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26) do call %0 %%i
:end
