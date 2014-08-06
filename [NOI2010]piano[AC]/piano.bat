@echo off
if "%1"=="" goto loop
copy piano%1.in piano.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc piano.out piano%1.ans
del piano.in
del piano.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
