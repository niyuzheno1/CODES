@echo off
if "%1"=="" goto loop
copy communicate%1.in communicate.in >nul
echo 评测批处理生成工具 CB(Check-Bat)
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

@Rem Stein 2007 10-17 由评测批处理生成工具 CB(Check-Bat)生成
@Rem QQ:383025560 Email:AdStein@126.com 宜昌市一中 刘佳奇