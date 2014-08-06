program aggr_ran;
var
        i,n,x,v:longint;
        cow:array[1..200] of longint;
        sum:longint;
        hash:array[1..200] of boolean;
begin
        assign(output,'check.txt');
        rewrite(output);
        writeln('Error!');
        close(output);
        assign(input,'jpol.in');
        reset(input);
        readln(n);
        for i:=1 to n*3 do readln(cow[i]);
        close(input);

        assign(input,'jpol.out');
        reset(input);

        fillchar(hash,sizeof(hash),false);

        sum:=0; v:=0;
        for i:=1 to n do
        begin
                readln(x);
                inc(sum, cow[x]);
                if (hash[x]) then halt;
                hash[x] := true;
        end;
        if sum>500*n then inc(v);

        sum:=0;
        for i:=1 to n do
        begin
                readln(x);
                inc(sum, cow[x]);
                if (hash[x]) then halt;
                hash[x] := true;
        end;
        if sum>500*n then inc(v);

        sum:=0;
        for i:=1 to n do
        begin
                readln(x);
                inc(sum, cow[x]);
                if (hash[x]) then halt;
                hash[x] := true;
        end;
        close(input);
        if sum>500*n then inc(v);

        if v>=2 then
           begin
                rewrite(output);
                writeln('FC: Right!');
                close(output);
           end;
end.


