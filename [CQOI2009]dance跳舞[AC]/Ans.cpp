#include "mode.h"
const int MN=205,MM =10005; 
int st[MN],next[MM],aim[MM],c[MM];
int lev[MN],now[MN],q[MN];
int n,k,tot,S,T;
int mp[53][53];
inline void add(int x,int y,int z)
{
 next[++tot] = st[x];aim[tot] = y;c[tot] = z;st[x] = tot;
 next[++tot] = st[y];aim[tot] = x;c[tot] = 0;st[y] = tot;
}
inline void Init()
{
  char s[65];
  n = gi,k=  gi;
  for(int i = 1;i<=n;++i)
  {
   scanf("%s",s+1);
   for(int j = 1;j<=n;++j)
    mp[i][j] = (s[j]=='Y'?1:0);
  }
  S = 0, T = 4*n+1;
}
inline bool bfs()
{
 CLEAR(lev,0);
 int h = 0,t = 1;q[1]=S;lev[S] = 1;
 while(h != t){
         ++h;
         now[q[h]] = st[q[h]];
         for(int i = st[q[h]];i;i=next[i])
          if(c[i] > 0 && !lev[aim[i]])
          {
           lev[aim[i]] = lev[q[h]]+1;
           q[++t] = aim[i];
          }
 }
 return lev[T];
}
int Dinic(int t,int f)
{
 if(t == T) return f;
 int l = f,tmp;
 int i;
 for( i = now[t];i;i=next[i])
  if(c[i] > 0&& lev[aim[i]] ==lev[t]+1)
  {
   tmp = Dinic(aim[i],min(l,c[i]));
   l -= tmp;c[i] -= tmp;c[i^1]+=tmp;
   if(!l) break;
  }
 now[t] = i;
 if(l == f) lev[t] = -1;
 return f-l;
}
bool Okay(int p)
{
     tot = 1;CLEAR(st,0);
     int s = 0;
     for(int i = 1;i<=n;++i)
     {
      add(S,i,p);
      add(i,i+2*n,k);
      add(i+n,T,p);
      add(i+3*n,i+n,k);
      for(int j = 1;j<=n;++j)
       if(mp[i][j]) add(i,j+n,1); else add(i+2*n,j+3*n,1);
     }
     while(bfs())
      s+=Dinic(S,INF);
     return s == n*p;
}
void work()
{
 int l = 1,r = n,mid;
 while(l <= r)
 {
  mid = (l+r)>>1;
  if(Okay(mid)) l = mid+1;
  else r = mid-1;
 }
 printf("%d\n",l-1);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    Init();work();
    closeIO();
    return EXIT_SUCCESS;
}
