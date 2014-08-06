@echo off
if "%1"=="" goto loop
copy dining%1.in dining.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc dining.out dining%1.out
del dining.in
del dining.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
