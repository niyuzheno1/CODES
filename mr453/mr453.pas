program box;
var a:array[1..500000] of longint;
    n,m,k,nn,ans:int64;
procedure init;
begin
  assign(input,'mr453.in2'); reset(input);
  assign(output,'mr453.ans2'); rewrite(output);
end;
procedure terminate;
begin
  close(input); close(output);
  halt;
end;
procedure qsort(s,t:longint);
var i,j,x,y,m:longint;
begin
  m:=(s+t) shr 1;
  x:=a[m]; a[m]:=a[s]; a[s]:=x;
  i:=s; j:=t; x:=a[i];
  repeat
    while (i<j) and (a[j]<x) do dec(j);
      if i<j then begin a[i]:=a[j]; inc(i); end;
    while (i<j) and (a[i]>x) do inc(i);
      if i<j then begin a[j]:=a[i]; dec(j); end;
  until i=j;
  a[i]:=x;
  inc(i); dec(j);
  if i<t then qsort(i,t);
  if s<j then qsort(s,j);
end;
procedure main;
var i,x,y,min:longint;
begin
  readln(n,k,m);
  nn:=0; min:=0; //nn统计拿箱子的人数，min统计离顶部最近的没有拿箱子的人的位置
  for i:=1 to k do begin
    readln(x,y);
    if y=0 then begin
      inc(nn);
      a[nn]:=x;
    end
    else if min<x then min:=x;
  end;
  qsort(1,nn);
  m:=m+nn;
  y:=m div k;
  ans:=2*(n-1)*y;
  x:=m mod k;
  if x=0 then begin
    ans:=ans-(n-min);
  end
  else if x>0 then begin
    ans:=ans+n-a[x];
  end;
  writeln(ans);
end;
begin
  init;
  main;
  terminate;
end.
