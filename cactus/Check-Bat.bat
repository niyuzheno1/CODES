@echo off
if "%1"=="" goto loop
copy cactus%1.in cactus.in >nul
echo 评测批处理生成工具 CB(Check-Bat)
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
@Rem Stein 2007 10-17 由评测批处理生成工具 CB(Check-Bat)生成
@Rem QQ:383025560 Email:AdStein@126.com 宜昌市一中 刘佳奇