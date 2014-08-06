@echo off
if "%1"=="" goto loop
copy fliptile%1.in fliptile.in >nul
echo Problem Test
echo Data %1
time<enter
Ans2
time<enter
fc fliptile.out fliptile%1.out
del fliptile.in
del fliptile.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13) do call %0 %%i
:end
