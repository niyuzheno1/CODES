#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#define rep(o,x) for(int o = 1;o<=x;o++)
#define tra(o,x) for(int o = st[x].st;o;o=lk[o].n)
#define gi getint()
using namespace std;
const int MAXN = 20100,INF = 0x7f7f7f7f;
int n,tot;
int inter[MAXN];
struct edge
{
 int n,v,w;
};
struct po
{
 int st,del,s,son;
};
edge lk[MAXN*2];
po st[MAXN];
void add1(int x,int y,int z)
{
 tot++;lk[tot].n = st[x].st;lk[tot].v = y;lk[tot].w = z;st[x].st = tot;
}
void add(int x,int y,int z)
{
 add1(x,y,z);add1(y,x,z);
}
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
void dfs1(int x,int y)
{
 tot++;
 inter[tot] = x;
 st[x].s = 1;
 tra(e,x)
  if(y != lk[e].v && !st[lk[e].v].del){
   dfs1(lk[e].v,x);
   st[x].s += st[lk[e].v].s;
   st[x].son = max(st[x].son,st[lk[e].v].s);
  }
}
int getG(int x)
{
 tot = 0;
 dfs1(x,0);
 int p = 0,l = INF;
 int si = st[x].s;
 rep(i,tot)
 {
  int x = inter[i];
  int y = max(si-st[x].s,st[x].son);
  if(y < l)
    p = x,l = y;
 }
 return p;
}
void dfs2(int x,int y,int z)
{
 st[x].s = z%3;
 tra(e,x)
  if(lk[e].v != y && !st[lk[e].v].del)
   dfs2(lk[e].v,x,(z+lk[e].w)%3);
}
void dfs3(int x,int y)
{
 tot++;inter[tot] = x;
 tra(e,x)
  if(lk[e].v != y && !st[lk[e].v].del)
   dfs3(lk[e].v,x);
}
int ans[3];
int getA(int x)
{
 int p = getG(x);
 dfs2(p,0,0);
 memset(ans,0,sizeof(ans));
 int ret = 1;
 ans[0]++;
 tra(e,p)
  if(!st[lk[e].v].del)
  {
   tot = 0;
   dfs3(lk[e].v,p);
   rep(i,tot)
   {
    int t = st[inter[i]].s;
    ret += (ans[(3-t)%3]*2);
   }
   rep(i,tot)
    ans[st[inter[i]].s]++;
  }
 st[p].del = 1;
 tra(e,p)
  if(!st[lk[e].v].del)
   ret += getA(lk[e].v);
 return ret;
}
int gcd(int x,int y)
{
    if ( x < y ) swap( x , y ) ;
    for ( ; y ; ) {
        int k = y ; 
        y = x % y ;
        x = k ;
    }
    return x;
}
int o [ 20 ];
void putint( int t ) {
    if ( t ) {
        o[ 0 ] = 0 ;
        for ( ; t ; t /= 10 ) o[ ++ o[ 0 ] ] = t % 10 ;
        while ( o[ 0 ] -- ) putchar( '0' + o[ o[ 0 ] + 1 ] ) ;
    } else putchar( '0' ) ;
}
int main(int argc, char *argv[])
{
    setIO("clever");
    n = gi;
    rep(i,n-1)
    {
     int x=gi,y=gi,w=gi;
     add(x,y,w);
    }
    int ans1 = getA(1);
    int ans2 = n*n;
    int d = gcd(ans1,ans2);
    ans1 /= d; ans2 /= d;
    putint(ans1);
    putchar('/');
    putint(ans2);
    closeIO();
    return EXIT_SUCCESS;
}
