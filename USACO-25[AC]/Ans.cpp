#include <cstdlib>
#include <iostream>

using namespace std;
#define maxn  100010
#define pp  600000
#define pt   1000000003LL
#define pv   200003
#define fl 147804523
long long ca[maxn];
long long h1[maxn],h2[maxn],hs2[pv];
const int inf = 0x7f7f7f7f;
int f[maxn],st[maxn],s[maxn],p,tot,n,ha[pp+10],hs[pp+10],lihs[pp+10][6];
int add(int x,int y)
{
    long long c = x % pv;
    c = c * 47 % pv;
     while(hs2[c] != 0 && h1[hs2[c]] != x)
     {
      c++;
      c %= pv;if(x == 0) c = 1;
     }
     if(hs2[c] == 0)
     {
      hs2[c] = y;
      return -1;
     }else
     return hs2[c];
}
bool t1(int x,int y)
{
     for(int i = 1;i<=n;i++)
     {
      int u = (x+i)%n;int v = (y+i)%n;
      if(u == 0)
       u = n;
      if(v == 0)
       v = n;
      if(ca[u] != ca[v])
       return false;
     }
     return true;
}
struct v
{
      int ne;
      int to;
};
v lk[maxn*2];
void e(int x,int y)
{
     tot++;
     lk[tot].ne = st[x];
     lk[tot].to = y;
     st[x] = tot;
}

bool df;
void dfs(int u,int ff)
{
     if(df)
      return;
     if(f[u] != inf)
     {
       df = 1;int x = ff;
       while(true)
       {
        p++;
        s[p] = x;
        if(x == u)
         break;
        x = f[x];
       }
       return;
     }
     f[u] = ff;
     for(int i = st[u];i != -1;i=lk[i].ne)
      if(lk[i].to != ff)dfs(lk[i].to,u);
}
int ahash(long long x,int * y)
{
   
   while(hs[x] != 0)
   {
    bool flag = false;
    if(y[0] != lihs[x][0])
     flag = true;
    for(int i = 1;i<=max(y[0],lihs[x][0]);i++)
     if(y[i] != lihs[x][i]){
      flag = true;
      break;
     }
    if(!flag)
     break;
    x = x+1;
    x %= pp;if(x == 0) x = 1;
   }
   if(hs[x] == 0)
   {
    hs[x] = 1;
    lihs[x][0] = y[0];
    for(int i = 1;i<=max(y[0],lihs[x][0]);i++)
     lihs[x][i] = y[i];
   }
   return x;
}
int dfs2(int x)
{
     int lis[5];
     lis[0] = 0;
     if(!f[x])f[x] = 1;
     for(int i = st[x];i != -1;i=lk[i].ne)
      if(f[lk[i].to] == 0)
      {
       lis[0]++;lis[lis[0]] = dfs2(lk[i].to);
      }
     sort(lis+1,lis+1+lis[0]);
     long long p = 1;
     for(int i = 1;i<=lis[0];i++){
      p = lis[i]*p;
      p %= pp;
     }
     if(p != 1)
      p++;
     if(f[x] == 2)
      lis[++lis[0]] = inf;
     p = ahash(p%pp,lis);
     if(f[x] == 2)
     lis[0]--;
     int ans = 0;
     for(int i = 1;i<=lis[0];i++)
      if(lis[i] != inf &&(i == 1 || lis[i] != lis[i-1]))
       ans += ha[lis[i]];
     if((lis[0] <= 2 && f[x] != 2 )||(lis[0] <= 1))
      ans++;
     ha[p] = ans;
     return p;
}
void init()
{
     df = 0;
     memset(st,0xff,sizeof(st));memset(f,0x7f,sizeof(f));
     scanf("%d",&n);
     for(int i = 1;i<=n;i++)
     {
      int x,y;
      scanf("%d%d",&x,&y);
      e(x,y);e(y,x);
     }
     dfs(1,-1);
     /*for(int i = 0;i<=p-1;i++)
      printf("%d ",s[i]);*/
     memset(f,0,sizeof(f));
     for(int i = 1;i<=p;i++)
      f[s[i]] = 2;
     for(int i = 1;i<=p;i++)
      ca[i] = dfs2(s[i]);
     n = p;
}
void solve()
{
     h1[0] = 0;
    long long big = 1;
    for(int i = 1;i<=n;i++){
     h1[0] = (h1[0]*fl%pt+ca[i])%pt;
     big *= fl;
     big %= pt;
    }
    for(int i = 1;i<=n;i++){
     h1[i] = (h1[i-1]*fl%pt+ca[i])%pt;
     h1[i] = (h1[i]+pt-(ca[i]*big)%pt)%pt;
    }
    for(int i = n;i>=1;i--)
     h2[0] = (h2[0]*fl%pt+ca[i])%pt;
    for(int i = n;i>=1;i--){
     h2[i] = (h2[((i+1) == n+1)? 0 : i+1]*fl%pt+ca[i])%pt;
     h2[i] = (h2[i]+pt-(ca[i]*big)%pt)%pt;
    }
    long long a = 0,b = 0;
    for(int i = 1;a == 0 && i<=n;i++)
     if((b = add(h1[i],i))!= -1)
      if(t1(b,i))
       a = i-b;
    if(a == 0)
     a = n;
    b = 0;
    int c = 1;
    for(int i = 1;i<=n;i++){
     if(h1[i] == h2[i])
     {
      b |= 1;
      c = i;
     }
     if(h2[i] == h1[i+1 == n+1 ? 1:i+1] && ((b & 1) == 0))
     {
      b |= 2;
      c = ((i+1) == n+1) ? 1 : i+1;
     }
    }
   
    if(b & 1)
     a = a/2+1;
    else if(b & 2)
     a = a/2;
    long long ans = 0;
    for(int i = 0;i<a;i++)
     ans += ha[ca[(i+c)==n ? n :(i+c)%n]];
    printf("%I64d",ans);
}
int main(int argc, char *argv[])
{
    freopen("treasure.in", "r", stdin);
    freopen("treasure.out", "w", stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
