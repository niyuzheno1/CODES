#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#define ff fprintf
using namespace std;
const int MAXN = 1010,inf = 0x7f7f7f7f;
int a[MAXN],n,m,k;
int b[MAXN*4][5];
FILE * d;
#define ER 2
#define ON 1
#define ZE 0
#define TR 3
#define DE 4
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
 int ans = 0;
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

void init()
{
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
    setIO("cha");
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    init();
    for(int i = 1;i<=m;i++)
    {
     int opr,x,y;
     scanf("%d%d",&opr,&x);
     
     if(opr == 0)
     {
      add(x,x,-1);
      int u = b[x+k][DE]+a[x];
      if(u == 1)
      {
       int v = max(find(1,x-1,0)+1,find(1,x-1,3));
       v = max(find(1,x-1,1)+1,v);
       if(v <= x-1)
       add(v,x-1,-1);
      }
     }
     else
     {
      add(x,x,1);
      int u = b[x+k][DE]+a[x];
      if(u == 2)
      {
       int v = max(find(1,x-1,3)+1,find(1,x-1,0));
       v = max(find(1,x-1,2)+1,v);
       if(v <= x-1)
       add(v,x-1,1);
      }
     } 
    
    }
      dpri();
    closeIO();
    return EXIT_SUCCESS;
}
