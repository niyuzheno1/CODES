@echo off
if "%1"=="" goto loop
copy card%1.in card.in >nul
echo Problem Test
echo Data %1
time<enter
Ans
time<enter
fc card.out card%1.ans
del card.in
del card.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
