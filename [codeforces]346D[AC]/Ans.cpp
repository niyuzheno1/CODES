#include "mode.h"
const int MN = 1000005;
int n,m,s,t,st[MN],nxt[MN],lk[MN],f[MN],q[MN*2],in[MN];
bool b[MN];
void add(int u,int v,int t)
{
 lk[t] = v,nxt[t] = st[u],st[u] = t;
}
void init()
{
     read(n);read(m);
     for(int i = 1,u,v;i<=m;++i)
      read(u),read(v),add(v,u,i),in[u]++;
     read(s);read(t);
}
void solve()
{
 memset(f,0x7f,sizeof(f)),f[t] = 0,q[n] = t;
 for(int l = n,r=n,u;l<=r;++l)
 {
  if(b[u=q[l]]) continue;
  b[u] = 1;
  for(int i = st[u],v;v=lk[i],i;i=nxt[i])
   if(!--in[v])
    if(f[u]<f[v])
     f[v] = f[u],q[l--] = v;
    else;
   else
    if(f[u]+1<f[v])
     f[v] = f[u]+1,q[++r]=v;
 }
 printf("%d\n",f[s]<INF?f[s]:-1);
}
int main(int argc, char *argv[])
{
    setIO("346D");
    init();solve();
    closeIO();
    return EXIT_SUCCESS;
}
