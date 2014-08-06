@echo off
if "%1"=="" goto loop
copy %1.in restack.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc restack.out %1.out
del restack.in
del restack.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 ) do call %0 %%i
:end
