
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int n,m,tot;
int a[50010],c[50010],up[50010],fi[50010],ct[50010],st[50010],f[50010][16];
int w[50010];
struct 
{
 int v;
 int w;
 int ne;
}lk[50010*4];
void li(int x,int y,int w)
{
 tot++;
 lk[tot].v = y;
 lk[tot].w = w;
 lk[tot].ne = st[x];
 st[x] = tot;
 ct[x]++;
}
bool vi[50010];
int dfsn[50010];
void dfs(int v,int dis,int o)
{
 if(vi[v]) return;
 if(v != 1) fi[v] = o;
 dfsn[0]++;
 dfsn[dfsn[0]] = v;
 vi[v] = 1;
 up[v] = dis;
 for(int i = st[v];i!=0;i=lk[i].ne)
 if(!vi[lk[i].v]){
  f[lk[i].v][0] = v;
  dfs(lk[i].v,dis+lk[i].w,v == 1? lk[i].v : o);
 }
}
void merge()
{
for(int j = 1;j<=(log(double(n))/log(double(2)))+1;j++)
 for(int i = 1;i<=dfsn[0];i++)
  f[dfsn[i]][j] = f[f[dfsn[i]][j-1]][j-1];
}
int d(int x,int t)
{
 while(true)
 {
  int l = 0,r = int(log(double(n))/log(double(2)))+1;
  while(l<r)
  {
   int mid = (l+r)/2;
   if(up[x]-up[f[x][mid]] > t)
    r = mid-1;
   else if(up[x]-up[f[x][mid]] < t)
    l = mid+1;
   else
    l = mid,r=mid;
  }
  if((l == 0 && r == 0 && !(up[x]-up[f[x][l]] <= t))||(r<l))
   return x;
  t -= (up[x]-up[f[x][l]]);
  x = f[x][l];
 }
}
int A[50010],B[50010];
bool cmp1(int  a,int  b)
{
 return up[a]>up[b];
}
bool cmp2(int  a,int  b)
{
 return up[a]<up[b];
}
bool ok(int t)
{
 memset(A,0,sizeof(A));
 memset(B,0,sizeof(B));
 memset(w,0,sizeof(w));
 for(int i = 1;i<=m;i++)
  if(up[c[i]] > t)
  {
   int m = d(c[i],t);
   w[m] = 1;
  }
 for(int i = 1;i<=m;i++)
  if(up[c[i]] <= t)
   A[++A[0]] =  c[i];
 for(int i = st[1];i!=0;i=lk[i].ne)
  if(!w[lk[i].v])
   B[++B[0]] =  lk[i].v;
 sort(A+1,A+1+A[0],cmp1);
 sort(B+1,B+1+B[0],cmp2);
 int j = 1;
 for(int i = 1;i<=A[0];i++)
 {
  if(w[fi[A[i]]] == 0)
   w[fi[A[i]]] = 1;
  else if(up[B[j]]+up[A[i]] <= t)
   w[B[j]] = 1;
  while(w[B[j]] == 1 && j <= B[0])
   j++;
  if(j > B[0])
   return true;
 }
 return false;
}
int main(int argc, char *argv[])
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    up[0] = -0x7f7f7f7f;
    int l = 1,r = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n-1;i++)
    {
     int a,b,c;
     scanf("%d%d%d",&a,&b,&c);
     li(a,b,c);
     li(b,a,c);
     r += c;
    }
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
    {
     int b;
     scanf("%d",&b);
     a[b]++;
     c[i] = b;
    }
    dfs(1,0,0);
    merge();
    
    
    while(l+1 < r)
    {
      int mid = (l+r)/2;
      if(ok(mid))
       r = mid;
      else
       l = mid+1;
    }
    printf("%d\n",(l+r)/2);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
