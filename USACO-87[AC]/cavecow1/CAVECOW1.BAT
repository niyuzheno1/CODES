@echo off
if "%1"=="" goto loop
copy cavecow1%1.in cavecow1.in >nul
echo Problem Test
echo Data %1
time<enter
cavecow1
time<enter
fc cavecow1.out cavecow1%1.out
del cavecow1.in
del cavecow1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
