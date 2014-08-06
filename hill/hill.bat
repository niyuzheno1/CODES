@echo off
if "%1"=="" goto loop
copy hill%1.in hill.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc hill.out hill%1.out
del hill.in
del hill.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end