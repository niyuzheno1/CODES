@echo off
if "%1"=="" goto loop
copy I.%1 photo.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc photo.out O.%1
del photo.in
del photo.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 ) do call %0 %%i
:end
