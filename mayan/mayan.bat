@echo off
if "%1"=="" goto loop
copy mayan%1.in mayan.in >nul
echo Problem Test
echo Data %1
time<enter
ans
time<enter
fc mayan.out mayan%1.ans
del mayan.in
del mayan.out
pause
goto end
:loop
for %%i in (  6 7 8 9 10) do call %0 %%i
:end