#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 500010,inf = 0x7f7f7f7f;
int n,tot;
int f[MAXN*3];
int son[MAXN*3][4];
int sz[MAXN*3],hz[MAXN*3],pre[MAXN*3],idx[MAXN*3];
int q[MAXN*3];
int a[MAXN*3],m,k;
int b[MAXN*4][5];
int c[MAXN*3];
FILE * d;
#define ER 2
#define ON 1
#define ZE 0
#define TR 3
#define DE 4
#define ff fprintf
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
void dfs(int s)
{
 int nxt = 0,x = s;
 while(true)
 {
  tot++;
  idx[x]=tot;
  pre[x]=s;
  if(hz[x] != -1)
   nxt = hz[x];
  else
   break;
  swap(nxt,x);
 }
}
void bd1()
{
 int l = 1,r=1;
 q[l] = 1;
 while(l<=r)
 {
  int x = q[l];l++;
  if(x == 0)
   continue;
  for(int i = 1;i<=3;i++)
   if(son[x][i] != 0 && son[x][i]<=n)
   {
    r++;
    q[r] = son[x][i];
   }
 }
 for(int i = 1;i<=n;i++)
  pre[i] = hz[i] = -1;
 for(int k = n;k>=1;k--){
  int i = q[k];
  sz[i] = 1;
  for(int j = 1;j<=3;j++)
   sz[i] += sz[son[i][j]];
  if(hz[f[i]] == -1 || sz[hz[f[i]]] < sz[i])
   hz[f[i]] = i;
 }
 for(int i = 1;i<=n;i++)
  if(pre[i] == -1)
  dfs(i);
}
int minval(int x,int y)
{
  return max(x,y);
}
int dn(int x,int y,int z)
{
 if(y-z<0 || y-z>3)
  return 0;
 return b[x][y-z];
}
void upd(int x)
{
 int l = x*2;
 int r = l+1;
 b[x][DE] = 0;
 b[x][ER] = minval(dn(l,ER,b[l][DE]),dn(r,ER,b[r][DE]));
 b[x][ON] = minval(dn(l,ON,b[l][DE]),dn(r,ON,b[r][DE]));
 b[x][ZE] = minval(dn(l,ZE,b[l][DE]),dn(r,ZE,b[r][DE]));
 b[x][TR] = minval(dn(l,TR,b[l][DE]),dn(r,TR,b[r][DE]));
}
void pdn(int x)
{
 int l = x*2;
 int r = l+1;
 b[l][DE] += b[x][DE];
 b[r][DE] += b[x][DE];
 b[x][DE] = 0;
}

void pd(int x)
{
 int u = x>>1,v=0;
 while(u)
 {
  v++; 
  u>>=1;
 }
 for(int i = v;i>=1;i--)
  pdn(x>>i);
}

void up(int x)
{
 x>>=1;
 while(x)
  upd(x),x>>=1;
}

void sm(int x)
{
 int p = k+x;
 for(int i = 0;i<=3;i++)
  b[p][i] = 0;
 b[p][a[x]+b[p][DE]] = x;
 up(p);
}

void add(int l,int r,int p)
{
 l = l+k-1;r = r+k+1;
 int ll = l,rr = r;
 pd(ll);pd(rr);
 int ans = inf;
 while((l^r) != 1)
 {
  if((l&1)==0)
   b[l^1][DE] += p;
  if((r&1)==1)
   b[r^1][DE] += p;
  l/=2;r/=2;
 }
 up(ll);up(rr);
}

int find(int l,int r,int p)
{
 l = l+k-1;r = r+k+1;
 int ll = l,rr = r;
 pd(ll);pd(rr);
 int ans = l-k;
 while((l^r) != 1)
 {
  if((l&1)==0)
   ans = minval(ans,dn(l^1,p,b[l^1][DE]));
  if((r&1)==1)
   ans = minval(ans,dn(r^1,p,b[r^1][DE]));
  l/=2;r/=2;
 }
 up(ll);up(rr);
 return ans;
}


void nup(int x,int y,int z)
{
 int nxtx = 0,nxty = 0;
 while(true)
 {
  if(x == 0)
   break;
  add(y,y,z);
  int u = b[y+k][DE]+a[x];
  int lbo = idx[pre[x]];
  if(z == -1)
  {
   if(u == 1)
   {
    int v = lbo;
    v = max(v,max(find(lbo,y-1,0)+1,find(lbo,y-1,3)));
    v = max(find(lbo,y-1,1)+1,v);
    if(v <= x-1)
     add(v,x-1,-1);
    if(v != lbo)
     break;
   }
   else
    break; 
  }
  if(z == 1)
  {
   if(u == 2)
   {
    int v = lbo;
    v = max(v,max(find(lbo,y-1,3)+1,find(lbo,y-1,0)));
    v = max(v,find(lbo,y-1,2)+1);
    if(v <= x-1)
     add(v,x-1,1);
    if(v != lbo)
     break;
   }
   else
    break;
  }
  nxtx = f[pre[x]];
  nxty = idx[nxtx];
  x = nxtx;y = nxty;
 }
}
int st(int x)
{
 int u = x+k;
 pd(u);
 for(int i = 0;i<=3;i++)
  if(dn(u,i,b[u][DE]))
   return i;
 return 0;
}

void init()
{
 for(int mac = n;mac>=1;mac--){
  int i = q[mac];
  int u = 0;
  for(int j = 1;j<=3;j++)
   if(a[son[i][j]]>=1)
    u++;
  a[i] = u;
 }
 k = 1;
 while(k<=n)
  k<<=1;
 for(int i = 1;i<=n;i++)
  sm(i);
}
void dpri()
{
 for(int i = 1;i<=k+n;i++)
  ff(d,"%d: two:%d one:%d zero:%d tir:%d delta:%d\n",i,b[i][ER],b[i][ON],b[i][ZE],b[i][TR],b[i][DE]);
}
int main(int argc, char *argv[])
{
    setIO("neuron");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=3;j++)
      scanf("%d",&son[i][j]),f[son[i][j]] = i;
    bd1();
    for(int i = 1;i<=2*n+1;i++)
    {
     int x;scanf("%d",&x);
     int u = i+n;
     a[u] = x;
     c[u] = x;
    }
    init();
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
    {
     int u;scanf("%d",&u);
     if(c[u] == 1)
      nup(f[u],idx[f[u]],-1);
     else
      nup(f[u],idx[f[u]],1);
     if(st(1)<=1)
      puts("0");
     else
      puts("1");
     if(i == 1)
      dpri();
     c[u]^=1;
    }
    closeIO();
    return EXIT_SUCCESS;
}
