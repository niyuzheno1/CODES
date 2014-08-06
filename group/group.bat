@echo off
if "%1"=="" goto loop
copy group%1.in group.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc group.out group%1.out
del group.in
del group.out
pause
goto end
:loop
for %%i in ( 1 2 3 4 5  6 7 8 9 10) do call %0 %%i
:end