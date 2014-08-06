@echo off
if "%1"=="" goto loop
copy pet%1.in pet.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc pet.out pet%1.out
del pet.in
del pet.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
