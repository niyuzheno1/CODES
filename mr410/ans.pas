var
f:array[1..400,1..400]of boolean;
match:array[1..400]of longint;
vis:array[1..400]of boolean;
a,b:array[1..400]of int64;
ans,i,j,k,l,n,m:longint;
function max(a,b:int64):int64;
begin
   if a>b then exit(a)
    else exit(b);
end;
function ok(v:longint):boolean;
var i,j:longint;
begin
    for i:=1 to max(n,m) do
      if (not vis[i])and(f[v,i])then
       begin
          vis[i]:=true;
        if (match[i]=0)or(ok(match[i]))then
         begin
           match[i]:=v;
           exit(true);
         end;
       end;
    exit(false);
end;
function check(a,b:longint):boolean;
var l,k,i:longint;
     c,d:array[1..40]of integer;
begin
    fillchar(c,sizeof(c),0);
    fillchar(d,sizeof(d),0);
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
for i:=1 to k do
   if c[i]=d[i] then exit(false);
exit(true);
end;
procedure init;
begin
assign(input,'nobody.in');reset(input);
assign(output,'nobody.out');rewrite(output);
readln(n,m);
for i:=1 to n do
read(a[i]);
for i:=1 to m do
read(b[i]);
end;
begin
init;
fillchar(f,sizeof(f),0);
fillchar(match,sizeof(match),0);
for i:=1 to n do
   for j:=1 to m do
    if check(a[i],b[j]) then
     f[i,j]:=true;
    ans:=0;
for i:=1 to n do
begin
   fillchar(vis,sizeof(vis),0);
   if ok(i) then inc(ans);
end;
writeln(ans);
close(output);
end.
