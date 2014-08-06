var
f:array[0..200,0..200]of longint;
a,b:array[1..200]of longint;
i,j,k,l,n,m:longint;
function check(a,b:longint):boolean;
var l,k,i:longint;
     c,d:array[1..32]of integer;
begin
     l:=0;
     while a<>0 do
      begin
       inc(l);
       c[l]:=a mod 2;
       a:=a div 2;
      end;
     k:=0;
     while b<>0 do
      begin
       inc(k);
       d[k]:= b mod 2;
       b:=b div 2;
      end;
    if k<l then k:=l;
for i:=1 to l do
   if c[i]=d[i] then exit(false);
exit(true);
end;
function max(a,b:longint):longint;
begin
max:=a;
if b>max then max:=b;
end;
procedure init;
begin
readln(n,m);
for i:=1 to n do
read(a[i]);
for i:=1 to m do
read(b[i]);
end;
begin
init;
for i:=1 to n do
   for j:=1 to m do
    if check(a[i],b[j]) then f[i,j]:=max(f[i,j],f[i-1,j-1])+1
    else f[i,j]:=max(f[i-1,j],f[i,j-1]);
writeln(f[n,m]);
end.