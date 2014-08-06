#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define X first
#define Y second
#define dprint(a,b) fprintf(debug,a,b);
using namespace std;
FILE * debug;
const int maxn = 200010,maxlog=18;
int n;
map<int,int> a1,a2;
typedef map<int,int>::iterator mi;
struct tab
{
 int l,r;
 bool operator < (tab x) const
 {
      if(r == x.r)
       return l > x.l;
      else
       return r<x.r;
 }
};
struct pro{ int x,y;bool operator < (pro g) const{return x<g.x;}};
tab a[maxn],b[maxn],d[maxn];
pro c[maxn];
int f[maxn][maxlog],g[maxn][maxlog];
int v,u,e;
int bin(int x)
{
    int l = 0,r=v;
    while(l<r)
    {
     int mid = (l+r)/2;
     if(d[mid].r >= x)
      r = mid-1;
     else if(d[mid].r < x && d[mid+1].r<x)
      l = mid+1;
     else if(d[mid].r < x)
      l = mid,r=mid;
    }
    return (l+r)/2;
}
void processa()
{
    sort(b+1,b+1+n);
    v = 1;
    for(int i = 1;i<=n;i++)
     if(b[i].r > b[i-1].r || (b[i].l==b[i-1].l&&b[i].r == b[i-1].r))
      d[v] = b[i],v++;
    v--;
    int ans1=0, r = 0;
    for(int i = 1;i<=v;i++)
     if(b[i].l > r)
      ans1++,r=b[i].r;
    printf("%d\n",ans1);
    g[v+1][0] = v+1;
    f[v+1][0] = u;
    g[v+1][1] = v+1;
    f[v+1][1] = u;
    for(int i = 1;i<=v;i++)
    {
     g[i][0] = i;
     f[i][0] = b[i].r;
     g[i][1] = v+1;
     f[i][1] = u;
     int u = bin(b[i].l);
     if(b[u].r == 0)
      continue;
     g[u][1] = i;
     f[u][1] = b[i].r;
    }
    for(int j = 2;j<maxlog;j++)
     for(int i = v+1;i>=1;i--){
      f[i][j] = f[g[i][j-1]][j-1];
      g[i][j] = g[g[i][j-1]][j-1];
     }
    for(int i = 0;i<maxlog;i++)
    {
     for(int j = 1;j<=v;j++)
      dprint("%d ",f[j][i]);
     dprint("\n",0);
    }
}
void init()
{
     
}
bool fred(int l,int r)
{
     bool flag = false;
     return flag;
}
int p(int x,int y)
{
    
}
void insert(int l,int r)
{
     
}
void processb()
{
     init();
     for(int i = 1;i<=n;i++)
     {
      bool flag = fred(a[i].l,a[i].r);
      if(!flag)
      {
       mi l = a1.lower_bound(a[i].l);
       mi r = a2.upper_bound(a[i].r);
       if(p((*l).X,(*r).X) == p((*l).X,a[i].l)+p(a[i].r,(*r).X)+1)
       {
        a1[a[i].r] = 1;
        a2[a[i].l] = 1;
        insert(a[i].l,a[i].r);
       }
      }
     }
}
int main(int argc, char *argv[])
{
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    debug = fopen("debug.txt","w");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%d%d",&a[i].l,&a[i].r);
     c[2*i].x = a[i].l;
     c[2*i].y = 2*i;
     c[2*i+1].x = a[i].r;
     c[2*i+1].y = 2*i+1;
    }
    sort(c+2,c+2*n+2);
     u = 0;
    for(int i = 2;i<=2*n+1;i++){
     if(c[i].x != c[i-1].x)
      u++;
     if(c[i].y%2 == 0)
      a[c[i].y/2].l = u; 
     else if(c[i].y % 2 == 1)
      a[c[i].y/2].r = u;
    }
    u++;
    for(int i = 1;i<=n;i++)
     b[i] = a[i];
    processa();
    fclose(debug);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
