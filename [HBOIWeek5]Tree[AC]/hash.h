struct hash
{
       int st[MH],ne[MS],state[MS],size;
       long long f[MS];
       void init(){size = 0;CLEAR(st,0xff);}
       void push(int sta,long long ans)
       {
         int h = sta%MH;
         for(int i = st[h];~i;i=ne[i])
          if(sta == state[i])
          {
           f[i] += ans;return;
          }
         f[size]=ans;
         state[size]=sta;
         ne[size] = st[h];
         ++size;
       }
};
