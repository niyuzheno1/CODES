@echo off
if "%1"=="" goto loop
copy binary%1.in binary.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc binary.out binary%1.out
del binary.in
del binary.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end