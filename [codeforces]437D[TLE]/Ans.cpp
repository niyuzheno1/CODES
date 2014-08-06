#include "mode.h"
/*
template<class T,class OP>
struct dset
{
 int * f;T * st;
 void init(int n)
 {
  f = new int[n+10];
  st = new T[n+10];
  for(int i = 0;i<=n+1;i++)
   f[i] = i;
  for(int i = 0;i<=n+1;i++)
   memset(st+i,0,sizeof(T));
 }
 OP func;
 int find(int x)
 {
  if(f[x] == x) return x;return find(f[x]);
 }
 void merge(int u,int v){
  f[u] = f[v];
  func(st[f[v]],st[u]);
 }
};

struct node{
 int size;
};*/
int n,m;
const int N = 100005;
vector<int> edge[N];
int a[N],ord[N],appear[N],f[N],si[N];
void init(int n)
{
  for(int i = 0;i<=n+1;i++)
   f[i] = i;
}
int find(int x)
{
  if(f[x] == x) return x;return find(f[x]);
}
void merge(int u,int v){
  f[u] = f[v];
  si[f[v]]+=si[u];
}
bool cmp(int  x,int y)
{
     return a[x]>a[y];
}
/*
struct OP{
 void operator()(node & x,node & y) const
 {
  x.size += y.size;
 }
};*/
//dset<node,OP> s;
vector<int> p;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    for(int i = 0;i<n;++i){
     a[i] = gi;
     ord[i] = i;
    }
    sort(ord,ord+n,cmp);
    for(int i = 0,u,v;i<m;++i){
     u = gi;v = gi;
     --u;--v;
     edge[u].push_back(v);
     edge[v].push_back(u);
    } 
    init(n);
    for(int i = 0;i<n;++i)
     si[i] = 1;
    ld ans = 0;
    for(int i = 0,u;i<n;++i){
     u = ord[i];
     appear[u] = 1;
     vector<int> block;
     block.push_back(1);
     for(int j = 0,v;j<(int)edge[u].size();++j){
      v = edge[u][j];
      if(!appear[v]) continue;
      if(find(u) != find(v)){
      block.push_back(si[find(v)]);
      merge(find(u),find(v));
      }
     }
     for(int i = 0;i<(int)block.size();++i)
      ans += (ld)(si[find(u)]-block[i])*block[i]*a[u];
    }
    
    printf("%.12f\n",(double)(ans/n/(n-1)));
    closeIO();
    return EXIT_SUCCESS;
}
