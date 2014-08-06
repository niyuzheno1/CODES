program checker;
var
    n,total,upright,biasl,biasr,finish:longint;
a:array[1..14] of integer;
b,c,d:array[-13..26] of boolean;
procedure init;
begin
    assign(input,'checker.in');reset(input);
    readln(n);
    finish:=(1 shl n) -1;
    fillchar(b,sizeof(a),true);
    fillchar(c,sizeof(b),true);
    fillchar(d,sizeof(b),true);
    total:=0;
    close(input);
end;
procedure dfs(t:integer);
var
    j,i:integer;
begin
for j:=1 to n do
   if b[j]and c[t+j] and d[t-j] then
      begin
       a[t]:=j;
       b[j]:=false;
       c[t+j]:=false;
       d[t-j]:=false;
       if t=n then
        begin
                           inc(total);
            for i:=1 to n-1 do
            write(a[i],' ');
                           writeln(a[n]);
                           if total=3 then exit;
        end
        else dfs(t+1);
       b[j]:=true;
       c[t+j]:=true;
       d[t-j]:=true;
      end;
end;
procedure dfsn(upright,biasl,biasr:longint);
var
    pos,p,i:longint;
begin
    pos:=finish and not(upright or biasl or biasr);
    while pos <>0 do
        begin
            p:=pos and (pos xor (pos-1));
            dec(pos,p);
            if upright+p=finish then inc(total)
            else dfsn(upright+p,(biasl+p)shl 1,(biasr+p)shr 1);
        end;
end;
begin
    init;
    assign(output,'checker.out');rewrite(output);
    dfs(1);
    total:=0;
    dfsn(0,0,0);
    writeln(total);
    close(output);
end.