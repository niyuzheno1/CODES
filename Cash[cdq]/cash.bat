@echo off
if "%1"=="" goto loop
copy cash%1.in cash.in >nul
echo Problem Test
echo Data %1
time<enter
splay
time<enter
fc cash.out cash%1.ans
del cash.in
del cash.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
