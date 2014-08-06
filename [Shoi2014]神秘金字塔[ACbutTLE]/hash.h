int stu = 0;
namespace nyz{
struct hash
{
       int st[MH],ch[MH],time,ne[MS],size,f[MS];
       LL state[MS];
       void init(int _time){
		   size = 0;time = _time;}
       void push(LL sta,LL ans)
       {
         LL h = sta%int64(MH);
         if(ch[h] != time)
          st[h] = -1,ch[h] = time;
         for(int i = st[h];~i;i=ne[i])
          if(sta == state[i])
          {
			 LL res = 0;
           addmod(res,f[i],ans);
           f[i] = res;return;
		  }
         f[size]=ans%modd;
         state[size]=sta;
         ne[size] = st[h];st[h] = size;
         ++size;
		 stu = max(size,stu);
       }
};
};
