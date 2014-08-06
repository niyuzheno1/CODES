var
    n, m                :longint;
    pre, other          :array[0..50010] of longint;
    last                :array[0..10010] of longint;
    flag                :array[0..50010] of boolean;
    tot                 :longint;
    ans                 :array[0..10010] of longint;
    i                   :longint;
    l                   :longint;

procedure connect(x,y:longint);
begin
    inc(l);
    pre[l]:=last[x];
    last[x]:=l;
    other[l]:=y;
end;

procedure init;
var
    i                   :longint;
    x, y                :longint;
begin
    read(n,m);
    for i:=1 to m do
    begin
        read(x,y);
        connect(x,y);
        connect(y,x);
    end;
end;

procedure dfs(x:longint);
var
    p, q                :longint;
begin
    q:=last[x];
    while q<>0 do
    begin
        p:=other[q];
        if not flag[q] then
        begin
            flag[q]:=true;
            dfs(p);
        end;
        q:=pre[q];
    end;
    inc(tot);
    ans[tot]:=x;
end;

begin
    assign(input,'watch.in'); reset(input);
    assign(output,'watch.out'); rewrite(output);
    init;
    dfs(1);
    for i:=tot downto 1 do writeln(ans[i]);
    close(input); close(output);
end.