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
const int INF =  1000000010;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
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

const int u = 4010;
struct rec{int x,l,r;}a[u];
int f[u][u],d[u][u],v[u][u],b[u],n,m;
vector<int> c[u];
int dp(int l,int r)
{
    if(l>r) return 0;
    if(f[l][r] != -1) return f[l][r];
    f[l][r] = dp(l+1,r);
    for(int i = 0,j;i<c[l].size();i++)
     if(a[j=c[l][i]].r < r && dp(l,a[j].r)+dp(a[j].r,r) > f[l][r])
      f[l][r] = dp(l,a[j].r)+dp(a[j].r,r),d[l][r] = j;
    return f[l][r]+=(v[l][r]>0);  
}
void print(int l,int r)
{
     if(l>r) return;
     if(v[l][r]) printf("%d ",v[l][r]);
     if(d[l][r]) print(l,a[d[l][r]].r),print(a[d[l][r]].r,r);
     else return print(l+1,r);
}
int main(int argc, char *argv[])
{
    //setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i)
    {
     a[i].x = gi,a[i].r = gi;
     a[i].l = a[i].x-a[i].r;a[i].r += a[i].x;
     b[++m] = a[i].l,b[++m] = a[i].r;
    }
    sort(b+1,b+1+m);
    m = unique(b+1,b+1+m)-b-1;
    for(int i = 1;i<=n;i++)
    {
     a[i].l = lower_bound(b+1,b+1+m,a[i].l)-b;
     a[i].r = lower_bound(b+1,b+1+m,a[i].r)-b;
     c[a[i].l].push_back(i);
     v[a[i].l][a[i].r] = i;
    }
    CLEAR(f,0xff);
    printf("%d\n",dp(1,m));
    print(1,m);
    //closeIO();
    return EXIT_SUCCESS;
}
