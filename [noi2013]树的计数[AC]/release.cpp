#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
const int INF =  0x7fffffff;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}
const int MN = 200010;
int n,dfs[MN],bfs[MN],Max[MN],Min[MN],rk[MN];
void build(int idx,int l,int r)
{
     if(l == r)
     {
      Min[idx] = dfs[l];
      return;
     }
     int mid = (l+r)>>1;
     build(idx*2,l,mid);
     build(idx*2+1,mid+1,r);
     Min[idx] = min(Min[idx*2],Min[idx*2+1]);
}
int getmin(int idx,int l,int r,int ll,int rr)
{
    if(ll<= l && r<=rr)
     return Min[idx];
    int ret = INF;
    int mid = (l+r)>>1;
    if(ll <= mid)
    ret = min(ret,getmin(idx*2,l,mid,ll,rr));
    if(rr > mid)
    ret = min(ret,getmin(idx*2+1,mid+1,r,ll,rr));
    return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i  = 1;i<=n;++i)
    {
     dfs[i] = gi;
     rk[dfs[i]]= i;
    }
    for(int i  =1;i<=n;++i)
    {
     bfs[i] = gi;
     dfs[rk[bfs[i]]]= i;
    }
    for(int i = 1;i<=n;++i)
     rk[dfs[i]]= i;
    for(int i = 1;i<=n;++i)
     Max[i] = max(Max[i-1],dfs[i]);
    build(1,1,n);
    int ans = 2,tmp = 0;
    for(int i = 1;i<n;++i)
    {
     if(i == 1 || rk[i+1]<rk[i]) ans += tmp+2,tmp = 0;
     else if(rk[i]+1 == rk[i+1] && Max[rk[i]]<i+1) ++tmp;
     else if(getmin(1,1,n,rk[i]+1,rk[i+1]-1)<i) tmp = 0; 
    }
    ans += tmp;
    printf("%.3f\n%.3f\n%.3f\n",ans/2.0-0.001,ans/2.0,ans/2.0+0.001);
    closeIO();
    return EXIT_SUCCESS;
}
