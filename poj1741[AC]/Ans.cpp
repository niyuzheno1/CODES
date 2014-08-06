#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ff fprintf
using namespace std;
const int inf = 0x7f7f7f7f;
const int maxn = 20100;
typedef vector<int> vi;
FILE * D;
int n,k,tot;
struct o
{
 int st;
 int s,ms,vis;
};
struct link
{
 int v,n,w;
};
link lk[maxn];
o st[maxn];
int a[maxn],ti;
void add1(int x,int y,int z)
{
 tot++;
 lk[tot].v = y;
 lk[tot].n = st[x].st;
 lk[tot].w = z;
 st[x].st = tot;
}
void add(int x,int y,int z)
{
 add1(x,y,z);add1(y,x,z);
}
int dfs(int x,int y)
{
 if(st[x].vis)
  return 0;
 ti++;a[ti] = x;
 st[x].s = 1,st[x].ms=0;
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {int v = lk[i].v;
  if(v != y){
   int q = dfs(v,x);
   st[x].ms = max(st[x].ms,q);
   st[x].s += q;
  }
 }
 return st[x].s;
}
int getG(int len)
{
 int maxva = inf,maxv =0;
 for(int i = 1;i<=ti;i++)
 {
  int x = a[i];
  x = max(st[x].ms,len-st[x].s);
  if(maxva > x)
   maxva = x,maxv = a[i];
 }
 return maxv;
}
void dfs2(int x,int y,vi & a,int z)
{
 if(st[x].vis)
  return;
 if(z > k)
  return;
 a.push_back(z);
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {int v = lk[i].v;
  if(v != y)
    dfs2(v,x,a,z+lk[i].w);
 }
}
int sum(vi a)
{
 sort(a.begin(),a.end());
 int ret = 0;
 int j = a.size();
 for(int i = 0;i<a.size();i++)
 {
  while(a[j-1]+a[i] > k && j>0)
   j--;
  ret += (j) - (((j)>i)?1:0);
 }
 return ret/2;
}
int ans = 0;
int sol(int x,int y)
{
 ti=0;
 dfs(x,0);
 x = getG(y);
 vi b;
 int ret=0;
 b.push_back(0);
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {
     int v = lk[i].v;
     vi a;
     dfs2(v,x,a,lk[i].w);
     ret -= sum(a);
     b.insert(b.end(),a.begin(),a.end());
 }
 ret += sum(b);
 st[x].vis = 1;
 ans += ret;
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(!st[v].vis)
   sol(v,st[v].s);
 }
}
int main(int argc, char *argv[])
{
    /*freopen("poj1741.in","r",stdin);
    freopen("poj1741.out","w",stdout);
    D = fopen("debug.txt","w");*/
    while(true){
    ans = 0;
    n = k = tot=ti=0;
    memset(lk,0,sizeof(lk));
    memset(st,0,sizeof(st));
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&k);
    if(n == 0 && k == 0)
     break;
    for(int i = 1;i<=n-1;i++)
     {
      int a,b,c;scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
     }
    sol(1,n);
    printf("%d\n",ans);
    }
    //fclose(stdin);fclose(stdout);fclose(D);
    return EXIT_SUCCESS;
}
