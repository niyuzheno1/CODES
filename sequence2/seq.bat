@echo off
if "%1"=="" goto loop
copy seq%1.in seq.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc seq.out seq%1.out
del seq.in
del seq.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end