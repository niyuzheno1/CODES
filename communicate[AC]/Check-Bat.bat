@echo off
if "%1"=="" goto loop
copy communicate%1.in communicate.in >nul
echo �������������ɹ��� CB(Check-Bat)
echo Data %1
time<enter
ans
time<enter
fc communicate.out communicate%1.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) do call %0 %%i
:end
del communicate.in
del communicate.out

@Rem Stein 2007 10-17 ���������������ɹ��� CB(Check-Bat)����
@Rem QQ:383025560 Email:AdStein@126.com �˲���һ�� ������