#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define ff fprintf 
using namespace std;
const int maxn = 10100,inf = 0x7f7f7f7f;
FILE * D;
struct lik
{
 int n,v,c;
};
struct sta
{
 int st,si,d,ac,cost,fa,son,ti;
 void print()
 {
  ff(D,"st:%d\n",st);ff(D,"si:%d\n",si);ff(D,"d:%d\n",d);ff(D,"ac:%d\n",ac);ff(D,"cost:%d\n",cost);ff(D,"fa:%d\n",fa);ff(D,"son:%d\n",son);ff(D,"ti:%d\n",ti);
 }
};
lik lk[maxn*2];
sta st[maxn];
int tot,ti,b[maxn],n;
void dpri()
{
 for(int i = 1;i<=n;i++){
  ff(D,"%d:\n",i);
  st[i].print();
 }
 for(int i = 1;i<=ti;i++)
  ff(D,"%d ",b[i]);
}
void add1(int x,int y,int z)
{
 tot++;lk[tot].v = y;lk[tot].c = z;lk[tot].n = st[x].st;st[x].st = tot;
}
void add(int x,int y,int z)
{
  add1(x,y,z);add1(y,x,z);
}
int readint()
{
  char c = 0;int ret = 0;
  while(!isdigit(c)) c=getchar();
  while(isdigit(c)){ret *= 10;ret+=c-'0';c=getchar();}
  return ret; 
}
char gete()
{
 char c = 0;
 while(c <'A' || c >'Z')
  c = getchar();
 return c;
}
void dfs1(int x,int y,int z)
{
 int mx = 0;
 st[x].son = 0;st[x].fa = y;st[x].d = z;st[x].si = 1;
 for(int i = st[x].st;i != 0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != y){
   st[v].cost = lk[i].c;
   dfs1(v,x,z+1);
   st[x].si += st[v].si;
   if(st[v].si > mx)
    st[x].son = v;
  }
 }
}
void dfs2(int x,int y)
{
 ti++;b[ti] = st[x].cost;st[x].ti =  ti;st[x].ac = y;
 if(st[x].son) dfs2(st[x].son,y);
 for(int i = st[x].st;i != 0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != st[x].son && v != st[x].fa)
   dfs2(v,v);
 }
}
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
  if(a[2*x].l == 0)
   a[x].mv = a[2*x+1].mv;
  if(a[2*x+1].r == 0)
   a[x].mv = a[2*x].mv;
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
  memset(a,0,sizeof(a));
  k = 1;
  n = x;
  while(k<=x)
   k<<=1;
  for(int i = 1;i<=n;i++){
   int v = too(i);
   a[v].mv = b[i];
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
int query(int x,int y)
{
 int ret = 0;
 while(st[x].ac != st[y].ac){
  if(st[st[x].ac].d < st[st[y].ac].d)
   swap(x,y);
  ret = max(ret,tr.query(st[st[x].ac].ti,st[x].ti));
  x = st[st[x].ac].fa;
 }
 if(st[x].d > st[y].d)
  swap(x,y);
 ret = max(ret,tr.query(st[x].ti+1,st[y].ti));
 return ret;
}
void init()
{
 n = readint();
 for(int i = 1;i<=n-1;i++)
 {
  int a,b,c;a = readint();b = readint();c = readint();
  add(a,b,c);
 }
 dfs1(1,0,1);
 dfs2(1,1);
 tr.init(ti);
 //dpri();
}
void solve()
{
  while(true)
  {
   char c = gete();
   if(c == 'D')
    break;
   int x,y;x = readint();y = readint();
   if(c == 'C')
   {
    int a = lk[2*x-1].v,b=lk[2*x].v;
    if(st[a].d < st[b].d)
     swap(a,b);
    tr.change(a,y);
   }
   if(c == 'Q')
   {
    
    printf("%d\n",query(x,y));
   }
  }
}
void clear()
{
    tot=0;
    ti = 0;
    /*for(int i = 1;i<=n;i++){
     b[i] = 0;
     memset(&st[i],0,sizeof(st[i]));
    }*/
}
int main(int argc, char *argv[])
{
    //freopen("spoj375.in","r",stdin);freopen("spoj375.out","w",stdout);//D = fopen("debug.txt","w");
    int T;
    T = readint();
    while(T--)
    {
     init();
     solve();
     clear();
    }
    /*fclose(D);*///fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
