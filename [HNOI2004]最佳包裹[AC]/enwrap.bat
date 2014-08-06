@echo off
if "%1"=="" goto loop
copy enwrap%1.in enwrap.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc enwrap.out enwrap%1.out
del enwrap.in
del enwrap.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
