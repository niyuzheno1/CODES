@echo off
if "%1"=="" goto loop
copy cactus%1.in cactus.in >nul
echo �������������ɹ��� CB(Check-Bat)
echo Data %1
time<enter
ans2
ans
time<enter
fc cactus.ans1 cactus.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 ) do call %0 %%i
:end
del cactus.in 
del cactus.out 
del cactus.ans
@Rem Stein 2007 10-17 ���������������ɹ��� CB(Check-Bat)����
@Rem QQ:383025560 Email:AdStein@126.com �˲���һ�� ������