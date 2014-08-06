@echo off
if "%1"=="" goto loop
copy seq%1.in sample.in >nul
echo Problem Test
echo Data %1
time<enter
ans3
time<enter
fc sample.out seq%1.out
del sample.in 
del sample.out 
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
