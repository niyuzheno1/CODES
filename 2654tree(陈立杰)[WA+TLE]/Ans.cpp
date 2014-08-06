#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define gi getint()
#define rep(o,x) for(int o = 1;o<=x;o++)
#define tra(o,x) for(int o = st[x];o!=-1;o=lk[o].n)
using namespace std;
const int MAXN = 50100,MAXM = 110000*2;
int getint()
{
 char c = 0;int ret = 0;
 while(!isdigit(c))c = getchar();
 while(isdigit(c)){ret *= 10;ret += (c-'0');c = getchar();}
 return ret;
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);
 #endif
}
struct edge
{
 int f,n,v,w,c;
};
edge lk[MAXM];
int v,e,need,st[MAXN],tot,delta,a[MAXN],f[MAXN];
void add1(int x,int y,int z,int a)
{
 tot++;lk[tot].f = x;lk[tot].n = st[x];lk[tot].v = y;lk[tot].w = z;lk[tot].c = a;st[x] = tot;
}
void add(int x,int y,int z,int a)
{
 add1(x,y,z,a);add1(y,x,z,a);
}
int gf(int x)
{
    if(x == f[x])
     return x;
    else
     return (f[x]=gf(f[x]));
}
bool cmp1(int x,int y)
{
 int u = (lk[x].c == 0)?lk[x].w+delta:lk[x].w;
 int v = (lk[y].c == 0)?lk[y].w+delta:lk[y].w;
 if(u != v)
  return u < v;
 else
  return lk[x].c > lk[y].c;
}
bool cmp2(int x,int y)
{
 int u = (lk[x].c == 0)?lk[x].w+delta:lk[x].w;
 int v = (lk[y].c == 0)?lk[y].w+delta:lk[y].w;
 if(u != v)
  return u<v;
 else
  return lk[x].c < lk[y].c; 
}
int sta(int & mins)
{
 int ret =0 ;
 rep(i,v)
  f[i] = i;
 rep(i,tot)
 {
  int x = lk[a[i]].f;
  int y = lk[a[i]].v;
  
  x = gf(x);y = gf(y);
  if(x != y)
  {
  ret += lk[a[i]].w;
  f[f[x]] = f[y];
  if(lk[a[i]].c == 0)
   mins++;
  }
 }
 return ret;
}
bool check(int x)
{
 int mins = 0,maxs = 0;
 delta = x;
 sort(a+1,a+1+tot,cmp1);
 sta(mins);
 sort(a+1,a+1+tot,cmp2);
 sta(maxs);
 if(need <= maxs && need >= mins)
  return 1;
 else
  return 0;
}
int main(int argc, char *argv[])
{
    //setIO("tree");
    v = gi,e = gi,need = gi;
    rep(i,e)
    {
     int x=gi,y=gi,z=gi,c=gi;
     x++,y++;
     add(x,y,z,c);
    }
    rep(i,tot)
     a[i] = i;
    int l = -100,r = 100;
    rep(i,100)
    {
     int mid = (l+r)/2;
     if(check(mid))
      l = mid+1;
     else
      r = mid;
    }
    delta = l;
    int p = 0,q = 0;
    sort(a+1,a+1+tot,cmp2);
    q = sta(p);
    printf("%d\n",q);
    //closeIO();
    return EXIT_SUCCESS;
}
