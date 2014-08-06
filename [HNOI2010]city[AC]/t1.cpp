#include "mode.h"

using namespace std;
struct e{int u,v,w;bool operator<(e ux) const {return w<ux.w;}};
e a[101],b[101];
int c[101],n,m,q,tot,tot2;
bool cmp(int x,int y)
{
 return a[x]<a[y];
}
void add(int x,int y,int z)
{
 a[tot].u = x;a[tot].v = y;a[tot].w = z;tot++;
}
void add2(int x,int y)
{
 tot2++;b[tot2].u = x;b[tot2].v = y;
}
void change(e*u,int l,int r,int x,int y,int v)
{
 for(int i = x;i<=y;++i){
 
  for(int j = l;j<=r;++j)
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi,q = gi;
    for(int i = 1;i<=m;i++){
     int u=gi,v=gi,w=gi;
     add(u,v,w),add(v,u,w);
    }
    for(int i = 0;i<tot;i++)
     c[i] = i;
    sort(c,c+tot-1,cmp);
    for(int i = 1;i<=q;i++){
     int u=gi,v=gi;
     add2(u,v);
    }
    closeIO();
    return EXIT_SUCCESS;
}
