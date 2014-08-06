#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
const int N = 100100,inf = 0x7f7f7f7f;
int k,n,Q,ec,id;
int st[N],lk[N*2],ve[N*2],sz[N],q[N],fa[N],hz[N],idx[N],pf[N],dep[N];
int a[N*4],b[N];
FILE * d;
void ae(int x,int y)
{
 ++ec;
 lk[ec] = st[x];ve[ec] = y;st[x] = ec;
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);d = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(d);
 #endif
}
int query(int l,int r)
{
 l = l+k-1;r = r+k+1;
 int lans = 0,rans = 0;
 while((l^r) != 1)
 {
  if(!(l&1))
   if(dep[lans] > dep[a[l^1]])
    lans = a[l^1];
  if(lans != 0)
   return lans;
  if((r&1))
   if(dep[rans] > dep[a[r^1]])
    rans = a[r^1];
  l/=2;r/=2;
 }
 if(lans == 0) return rans;
 return lans;
}
int main(int argc, char *argv[])
{
    setIO("Qtree3");
    scanf("%d%d",&n,&Q);
    for(int i = 1;i<=n-1;++i)
    {
     int x,y;scanf("%d%d",&x,&y);
     ae(x,y);ae(y,x);
    }
    int r = 1;q[1] = 1;dep[0] = inf;dep[1] = 1;
    k = 1;
    while(k <= n) k<<=1;
    for(int i = 1;i<=r;++i)
    {
     int x = q[i];
     for(int j = st[x];j;j=lk[j])
     {
      int v = ve[j];
      if(v != fa[x]){
       fa[v] = x,++r,q[r] = v;
       dep[v] = dep[x]+1;
       }
     }
    }
    for(int j = r;j>=1;--j)
    {
     int i = q[j];
     ++sz[i];
     if(hz[fa[i]] == 0 || sz[hz[fa[i]]] < sz[i])
      hz[fa[i]] = i;
     sz[fa[i]] += sz[i];
    }
    id = 0;hz[0] = 0;
    for(int j = r;j>=1;--j)
    {
     int i = q[j];
     if(hz[i] == 0)
     {
      int p = i;
      for(;hz[fa[p]] == p;p = fa[p]);
      for(int k = p;k!=0;k = hz[k])
       id++,pf[k] = p,idx[k] = id;
     }
    }
    for(int i = 1;i<=Q;++i)
    {
     int opr,x;scanf("%d%d",&opr,&x);
     if(!opr)
     {
      int y = idx[x];
      a[y+k] = b[x]?0:x;
      for(int j = (y+k)/2;j>=1;j/=2)
       a[j] = dep[a[2*j]]<dep[a[2*j+1]]?a[2*j]:a[2*j+1];
      b[x] ^= 1;
     }
     else
     {
      int ans = 0;
      for(int j = x;j;j=fa[pf[j]])
      {
       int qans = query(idx[pf[j]],idx[j]);
       ans = dep[ans]<dep[qans]?ans:qans;
      }
      if(ans == 0)
       puts("-1");
      else
       printf("%d\n",ans);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
