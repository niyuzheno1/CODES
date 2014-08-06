#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 MAXN = 100000+1000;
int64 n,m;
int64 begin[MAXN],next[MAXN],t[MAXN],root,tot;
int64 power[MAXN],w[MAXN],answer;
void addedge(int64 x,int64 v)
{
 tot++;
 t[tot] = v;
 next[tot] = begin[x];
 begin[x] = tot;
}
struct node
{
 int64 lc,rc,w;
 int64 size,sum,dist;
 node()
 {
  lc = rc = w = size = sum = dist = 0;
 }
};
node tree[MAXN];
int64 cnt;
void updata(int64 u)
{
 tree[u].sum = tree[u].w+tree[tree[u].lc].sum+tree[tree[u].rc].sum;
 tree[u].size = 1+tree[tree[u].lc].size+tree[tree[u].rc].size;
}

int64 merge(int64 u,int64 v)
{
 if(!u) return v;
 if(!v) return u;
 if(tree[u].w < tree[v].w) 
  swap(u,v);
 tree[u].rc =  merge(tree[u].rc,v);
 if(tree[tree[u].rc].dist > tree[tree[u].lc].dist)
  swap(tree[u].rc,tree[u].lc);
 if(!tree[u].rc)
  tree[u].dist = 0;
 else
  tree[u].dist = tree[tree[u].rc].dist+1;
 updata(u);
 return u;
}
int64 dfs(int64 u)
{
 int64 v,p=0;
 for(int64 i = begin[u];i;i=next[i])
 {
  v=t[i];
  p = merge(p,dfs(v));
 }
 int64 me = ++cnt;
 tree[me].size = 1;tree[me].w = w[u];tree[me].sum = w[u];
 p = merge(me,p);
 while(tree[p].sum > m)
  p = merge(tree[p].lc,tree[p].rc);
 if(power[u]*tree[p].size > answer)
  answer = power[u]*tree[p].size;
 return p;
}
int main(int argc, char *argv[])
{
    
    int64 fa;
    scanf("%lld%lld",&n,&m);
    for(int64 i = 1;i<=n;i++)
    {
     scanf("%lld%lld%lld",&fa,&w[i],&power[i]);
     if(fa)
      addedge(fa,i);
     else
      root = i;
    }
    dfs(root);
    printf("%lld\n",answer);
    
    return EXIT_SUCCESS;
}
