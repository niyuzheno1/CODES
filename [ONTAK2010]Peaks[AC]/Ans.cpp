#include "mode.h"
int n,m,Q;
const int MN = 100000+9;
struct node
{
 int C[3];
};
struct edge
{
 int C[4];
 bool operator < (edge x)const
 {
  return C[2]<x.C[2];
 }
};
edge b[MN*5],c[MN*5];
node a[MN];
int sz[MN],val[MN],q[MN],f[MN],ans[MN*5];
void update(int x)
{
 if(x != 0) sz[x] = sz[a[x].L]+sz[a[x].R]+1;
}
int gf(int x)
{
 if(f[x] == x) return x;
 return(f[x] = gf(f[x]));
}
void rotate(int x)
{
 int y = a[x].F;
 int z = a[y].F;
 int d1 = (a[y].L==x);
 int d2 = (a[z].R==y);
 a[y].C[!d1] = a[x].C[d1];a[a[y].C[!d1]].F = y;
 a[x].C[d1] = y;a[y].F = x;
 if(z != 0) a[z].C[d2] = x;
 a[x].F = z;
 update(y);update(x);
}
void splay(int x)
{
 while(a[x].F != 0)
 {
  int y = a[x].F,z = a[y].F;
  if(z != 0 && (a[y].L == x)==(a[z].L == y)) rotate(y);
  rotate(x);
 }
}
void ins(int x,int y)
{
 a[x].L = a[x].R = a[x].F = 0;sz[x] = 1;
 for(int z = y;1;)
 {
  int d1 = val[z]>val[x];
  if(a[z].C[d1] == 0)
  {
   a[z].C[d1] = x;a[x].F = z;splay(x);break;
  }
  z = a[z].C[d1];
 }
}
void merge(int x,int y)
{
 splay(x);splay(y);
 if(sz[x] < sz[y]) swap(x,y);
 int r=1;q[1] = y;
 for(int i = 1;i<=r;++i)
 {
  int u = q[i];
  if(a[u].C[0])
  { r++;q[r] = a[u].C[0];}
  if(a[u].C[1])
  { r++;q[r] = a[u].C[1];}
  ins(q[i],x);x = q[i];
 }
}
void Union(int x,int y)
{
     x = gf(x); y = gf(y);
     f[x] = f[y];
     merge(x,y);
}
int fkt(int x,int y)
{
 if(x == 0 && y != 0)
  return -1;
 if(y <= sz[a[x].L])
  return fkt(a[x].L,y);
 else if(y == sz[a[x].L]+1)
  return val[x];
 else if(y > sz[a[x].L]+1)
  return fkt(a[x].R,y-1-sz[a[x].L]);
}

int main(int argc, char *argv[])
{
   
    setIO("Peak");
    read(n);read(m);read(Q);
    for(int i = 1;i<=n;i++)
     read(val[i]),sz[i] = 1,f[i] = i;
    for(int i = 1;i<=m;i++)
     read(b[i].C[0]),read(b[i].C[1]),read(b[i].C[2]);
    sort(b+1,b+1+m);
    for(int i = 1;i<=Q;i++)
     read(c[i].C[0]),read(c[i].C[2]),read(c[i].C[1]),c[i].C[3]=i;
    sort(c+1,c+1+Q);
    int l = 1;
    for(int i = 1;i<=Q;i++)
    {
     while(l <= m && b[l].C[2] <= c[i].C[2])
     {
     
      int x = b[l].C[0],y = b[l].C[1];
      if(gf(x) != gf(y))
       Union(x,y);
      l++;
     }
     splay(c[i].C[0]);
     
     ans[c[i].C[3]] = fkt(c[i].C[0],c[i].C[1]);
    }
    for(int i = 1;i<=Q;i++)
     printf("%d\n",ans[i]);
    closeIO();
    return EXIT_SUCCESS;
}
