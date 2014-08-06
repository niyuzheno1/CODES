@echo off
if "%1"=="" goto loop
copy damage2%1.in damage2.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc damage2.out damage2%1.out
del damage2.in
del damage2.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15) do call %0 %%i
:end
