#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ff fprintf
using namespace std;
const int maxn = 10100,inf = 0x7f7f7f7f;
FILE * d;int t,n,tot,ti,ti2,u[maxn],hd[maxn],to[maxn],fa[maxn],co[maxn];
struct lik{int v,n,c;};
lik lk[maxn];
struct sst{int st,si,cnt,num,ti;};
struct node
{
 int mv;
 int l,r;
};
struct zkw
{
 int n,d,k;
 node a[maxn*4];
 int too(int x){return x+k;}
 void upd(int x)
 {
  if(a[2*x+1].r == 0)
   a[x].mv = a[2*x].mv;
  if(a[2*x].l == 0)
   a[x].mv = a[2*x+1].mv;
  if(a[2*x].l != 0 && a[2*x+1].r != 0)
  a[x].mv = max(a[2*x].mv,a[2*x+1].mv);
 }
 void upda(int x)
 {
  x>>=1;
  while(x)
  {
   upd(x);
   x>>=1;
  }
 }
 void init(int x)
 {
  k = 1;
  n = x;
  while(k<=x)
   k<<=1;
  for(int i = 1;i<=n;i++){
   int v = too(i);
   a[v].mv = to[i];
   a[v].l = a[v].r = i;
  }
  for(int i = k;i>=1;i--){
   int l = 2*i,r = 2*i+1;
   if(a[l].l == 0)
   {
    a[i].l = a[r].l;
    a[i].r = a[r].r;
    a[i].mv = a[r].mv;
   }
   if(a[r].r == 0)
   {
    a[i].l = a[l].l;
    a[i].r = a[l].r;
    a[i].mv = a[l].mv;
   }
   if(a[l].l != 0 && a[r].r != 0)
   {
    a[i].l = a[l].l;
    a[i].r = a[r].r;
    a[i].mv = max(a[l].mv,a[r].mv);
   }
  }
 }
 void change(int x,int y)
 {
  int u = too(x);
  a[u].mv = y;
  upda(u);
 }
 int query(int l,int r)
 {
  l = too(l-1),r = too(r+1);
  int ans = -inf;
  while(l+1 < r)
  {
   if((l&1)==0)
    ans = max(ans,a[l^1].mv);
   if((r&1)==1)
    ans = max(ans,a[r^1].mv);
   l>>=1;r>>=1;
  }
  return ans;
 }
};
zkw tr;
sst st[maxn];
void add1(int x,int y,int z){tot++;lk[tot].n = st[x].st;lk[tot].v = y;lk[tot].c = z;st[x].st = tot;}
void add(int x,int y,int z){add1(x,y,z);add1(y,x,z);}
void dfs1(int x,int y)
{
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != y)
   dfs1(v,x);
 }
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != y)
   st[x].si += st[v].si;
 }
 st[x].si += st[x].cnt;
}
void dfs2(int x,int y,int nm)
{
 ti2++;u[ti2] = x;
 st[x].num = nm;st[x].ti = ti2;int ed;
 if(!hd[nm]){
  to[ti2] = -inf;
  hd[nm] = x;
 }
 int top = 0;
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != y && st[v].si > st[top].si)
   top = v,ed = lk[i].c;
 }
 if(top != 0){
 to[ti2+1] = ed;
 dfs2(top,x,nm);
 }
 for(int i = st[x].st;i!=0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != y && v != top){
   ti++;
   fa[v] = x;co[v] = lk[i].c;
   dfs2(v,x,ti);
  }
 }
}
void debugpri0()
{
 for(int i = 1;i<=n;i++)ff(d,"%d ",st[i].si);ff(d,"\n");
}
void debugpri1()
{
 for(int i = 1;i<=n;i++)ff(d,"%d ",st[i].ti);ff(d,"\n");
 for(int i = 1;i<=n;i++)ff(d,"%d ",st[i].num);ff(d,"\n");
 for(int i = 1;i<=ti2;i++)ff(d,"%d ",u[i]);ff(d,"\n");
 for(int i = 0;i<=ti;i++)ff(d,"%d ",hd[i]);ff(d,"\n");
 for(int i = 1;i<=ti2;i++)ff(d,"%d ",to[i]);ff(d,"\n");
 for(int i = 1;i<=n;i++)ff(d,"%d ",fa[i]);ff(d,"\n");
}
int main(int argc, char *argv[])
{
    freopen("spoj375.in","r",stdin);freopen("spoj375.out","w",stdout);d = fopen("debug.txt","w");
    scanf("%d",&t);
    while(t--)
    {
     scanf("%d",&n);
     for(int i = 1;i<=n;i++)
      st[i].cnt = 1;
     for(int i = 1;i<=n-1;i++){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
     }
     dfs1(1,-1);
     debugpri0();
     ti = 0;
     dfs2(1,-1,0);
     debugpri1();
     tr.init(ti2);
     while(true)
     {
      int x,y;
      scanf("%s%d%d",str,&x,&y);
      if(str[0] == 'D')
       break;
      if(str[0] == 'Q')
      {
       
      }
     }
    }
    fclose(d);fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
