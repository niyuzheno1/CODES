#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN  = 500010;
typedef double db;
void setIO(string str)
{
 #ifndef ONLINE_JUDGE
 string input = str+".in";string output = str+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
int st[MAXN];
int q[MAXN];
db qi[MAXN];
db l[MAXN];
int f[MAXN],n;
db dp[MAXN][2];
int tot,ti,tl;
struct edge
{db w;int v;int n;
};
edge lk[MAXN*2];
void add1(int x,int y,db z)
{
 ti++;
 lk[ti].v = y;
 lk[ti].w = z;
 lk[ti].n = st[x];
 st[x] = ti;
}
void add(int x,int y,db z)
{
 add1(x,y,z);add1(y,x,z);
}
int main(int argc, char *argv[])
{
    setIO("charger");
    scanf("%d",&n);
    for(int i = 1;i<=n-1;i++)
    {
     int x,y;db z;
     scanf("%d%d%lf",&x,&y,&z);z/=100;
     add(x,y,z);
    }
    tot++;
    q[tot] = 1;
    tl = 2;
    while(q[tot] != 0)
    {
     int u = q[tot];tot++;
     for(int i = st[u];i;i=lk[i].n)
     if(lk[i].v != f[u]){
      int v = lk[i].v;
      q[tl] = v;
      tl++;
      f[v] = u;
      l[v] = lk[i].w;
     }
    }
    for(int i = 1;i<=n;i++){
     scanf("%lf",&qi[i]);
     qi[i]/=100;
    }
    double ans = 0;
    for(int i = n;i>=1;i--)
    {
     int x = q[i];
     dp[x][0] = 1-qi[x];
     for(int j = st[x];j;j=lk[j].n)
     if(lk[j].v != f[x]){
      int v = lk[j].v;
      db t = lk[j].w;
      dp[x][0] *=(dp[v][0]+(1-t)*(1-dp[v][0]));
     }
    }
    dp[1][1] = 1;
    ans = 1-dp[1][0];
    for(int i = 2;i<=n;i++){
     int x = q[i];
     db t;
     if(dp[x][0]+(1-l[x])*(1-dp[x][0])==0)
      t = 0;
     else{
      t = dp[f[x]][0]/(dp[x][0]+(1-l[x])*(1-dp[x][0]));
      t *= dp[f[x]][1];
     }
     dp[x][1] = t+(1-t)*(1-l[x]);
     ans += 1-dp[x][0]*dp[x][1];
    }
    printf("%.6f",ans);
    return EXIT_SUCCESS;
}
