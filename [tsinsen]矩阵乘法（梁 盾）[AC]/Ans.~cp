#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define gi getint()
#define ff fprintf
#define lb(x) ((x)&(-x))
#define SIZE(x) x[0].y
using namespace std;
const int MAXQ = 60100,MAXN = 510,UB = 510*510;
FILE * d;
int n,q;
int bi[MAXN];
int sum(int x)
{
 int ret = 0;
 for(;x;x-=lb(x))
  ret += bi[x];
 return ret;
}
int add(int x,int y)
{
 for(;x<=n;x+=lb(x))
  bi[x] += y;
}
struct s
{
 int v;
 int x,y;
 bool operator < (s u) const
 {
  return x<u.x;
 }
};
bool cmp1(s a1,s a2)
{
 return a1.v < a2.v;
}
s a[MAXN*MAXN],t1[MAXN*MAXN],t2[MAXN*MAXN];
int c[UB];
struct qu
{
 int x,y,z;
 int c,d;
 bool operator < (qu u)const 
 {
  return x<u.x;
 }
};
int cur[MAXQ],now[MAXQ],up[MAXQ],ans[MAXQ];
qu b[MAXQ*2],t3[MAXQ*2],t4[MAXQ*2];
int tot;
void addq(int x,int y,int z,int u,int v)
{
 tot++;
 b[tot].x = x;b[tot].y = y;b[tot].z = z;b[tot].c = u;b[tot].d = v;
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
int getint()
{
 char c = 0;int ret = 0;
 while(!isdigit(c))c = getchar();while(isdigit(c)){ret *= 10;ret += (c-'0');c = getchar();}
 return ret;
}
void solve(int l,int r,int al,int ar,int bl,int br)
{
 if(l == r)
 {
  for(int i = bl;i<=br;i++)
   ans[b[i].d] = l;
  return;
 }
 SIZE(t1) = SIZE(t2) = SIZE(t3) = SIZE(t4) = 0;
 int mid = (l+r)/2;
 int p = al;
 for(int i = bl;i<=br;i++)
 {
  while(p <= ar && a[p].x <= b[i].x)
  {
   if(a[p].v <= mid)
    add(a[p].y,1);
   p++;
  }
  int x = sum(b[i].z)-sum(b[i].y-1),y = b[i].d,z = b[i].c;
  if(z < 0)
   now[y] = -x;
  else
   now[y] += x;
 }
 p--;
 for(int i = p;i>=al;i--)
 {
  if(a[i].v <= mid)
   add(a[i].y,-1);
 }
 int amid = 0,bmid = 0;
 for(int i = bl;i<=br;i++)
 {
  int u = b[i].d;
  if(cur[u] + now[u] >= up[u])
  {
   SIZE(t3)++;
   t3[SIZE(t3)] = b[i];
  }
  else
  {
   cur[u] += now[u];now[u] = 0;
   SIZE(t4)++;
   t4[SIZE(t4)] = b[i];
  }
 }
 for(int i = al;i <= ar; i++)
 {
  if(a[i].v <= mid)
  {
  SIZE(t1)++;
  t1[SIZE(t1)] = a[i];
  }else{
  SIZE(t2)++;
  t2[SIZE(t2)] = a[i];
  }
 }
 int ax1=al-1,bx1=bl-1;
 for(int i = 1;i<=SIZE(t3);i++)
  bx1++,b[bx1] = t3[i];
 bmid = bx1;
 for(int i = 1;i<=SIZE(t4);i++)
  bx1++,b[bx1] = t4[i];
 for(int i = 1;i<=SIZE(t1);i++)
  ax1++,a[ax1] = t1[i];
 amid = ax1;
 for(int i = 1;i<=SIZE(t2);i++)
  ax1++,a[ax1] = t2[i];
 solve(l,mid,al,amid,bl,bmid);
 solve(mid+1,r,amid+1,ar,bmid+1,br);
 return;
}
int main(int argc, char *argv[])
{
    setIO("product");
    n = gi;q = gi;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
     {
      int x = gi;
      a[(i-1)*n+j].v = x;a[(i-1)*n+j].x = i;a[(i-1)*n+j].y = j;
     }
    tot = 0;
    sort(a+1,a+1+n*n,cmp1);
    a[0].v = -100;
    for(int i = 1;i<=n*n;i++) 
     if(a[i].v != a[i-1].v)
     {
      tot++;
      c[tot] = a[i].v;
      a[i].v = tot;
     }else
      a[i].v = tot;
    a[0].v = 0;
    tot = 0;
    for(int i = 1;i<=q;i++)
    {
     int x1=gi,y1=gi,x2=gi,y2=gi,k=gi;
     up[i] = k;
     addq(x1-1,y1,y2,-1,i);
     addq(x2,y1,y2,1,i);
    }
    sort(a+1,a+1+n*n);
    sort(b+1,b+1+tot);
    solve(1,UB,1,n*n,1,tot);
    for(int i = 1;i<=q;i++)
     printf("%d\n",c[ans[i]]);
    closeIO();
    return EXIT_SUCCESS;
}
