struct hash
{
       int st[MH],ch[MH],time,ne[MS],size,f[MS];
       pii state[MS];
       void init(int _time){
		   size = 0;time = _time;}
       void push(pii sta,int ans)
       {
         int h = sta.X%MH;
         if(ch[h] != time)
          st[h] = -1,ch[h] = time;
         for(int i = st[h];~i;i=ne[i])
          if(sta == state[i])
			 return;
         f[size]=ans;
         state[size]=sta;
         ne[size] = st[h];st[h] = size;
         ++size;
       }
       int find(pii sta)
       {
         int h = sta.X%MH;
         if(ch[h] != time)
          st[h] = -1,ch[h] = time;
         for(int i = st[h];~i;i=ne[i])
          if(sta == state[i])
			 return i;
         return -1;
       }
};
