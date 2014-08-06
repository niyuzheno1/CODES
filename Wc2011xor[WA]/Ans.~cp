#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 MAXN = 110000;
int64 d[MAXN],a[MAXN],g[MAXN],_w1[MAXN*3],_w2[MAXN*3],_v[MAXN*3],_u[MAXN*3];
int64 * w[3] = {0,&_w1[MAXN+10000],&_w2[MAXN+10000]};
int64 * v = &_v[MAXN+10000];
int64 * u = &_u[MAXN+10000];
int64 n,m,all,na,x,y;
int64 t,z,ans,tmp;
void con(int64 x,int64 y,int64 z)
{
 all++;
 w[1][all] = y;w[2][all] = g[x];
 v[all] = z;
 g[x] = all;
 w[1][-all] = x;w[2][-all] = g[y];
 v[-all] = z;
 g[y] = -all;
}
void dfs(int64 x,int64 h)
{
 if(d[x] == -1)
 {
  d[x] = h;
  int64 j = g[x];
  while(j != 0){
   if(!u[j]){
    u[j] = 1;u[-j] = 1;
    dfs(w[1][j],h^v[j]);
   }
   j = w[2][j];
  }
 }else
  if((h ^ d[x])>0){
   na++;
   a[na] = (h^d[x]);
  }
}
int main(int argc, char *argv[])
{
    //#ifndef ONLINE_JUDGE
    //freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
    //#endif
    scanf("%I64d%I64d",&n,&m);
    for(int64 i = 1;i<=m;i++)
    {
     scanf("%I64d%I64d%I64d",&x,&y,&z);
     con(x,y,z);
    }
    memset(u,0,sizeof(u));
    for(int64 i = 1;i<=n;i++)d[i] = -1;
    na = 0;
    dfs(1,0);
    t = 1<<31;
    t = t*t*2;
    ans = d[n];
    while(t != 0){
     tmp = 0;
     for(int64 i = 1;i<=na;i++)
      if((a[i] & t) != 0){
       tmp = a[i];
       break;
      }
     if(tmp != 0){
      for(int64 i = 1;i<=na;i++)
        if((a[i] & t) != 0)
         a[i] = a[i]^tmp;
      if( (ans & t) == 0)
       ans = ans ^ tmp;
     }
     t = t/2;
    }
    printf("%I64d",ans);
    //#ifndef ONLINE_JUDGE
    //fclose(stdin);fclose(stdout);
    //#endif
    return EXIT_SUCCESS;
}
