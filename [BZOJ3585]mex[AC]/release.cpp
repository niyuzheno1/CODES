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
const int INF =  1000000010;
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
int mex[MN],a[MN],next[MN];
map<int,int> mp;
int n , m;
void pre(){
 for(int i = 1;i<=n;mp[a[i]]=i,++i)
  if(mp.count(a[i]))
   next[mp[a[i]]] = i-1;
  else
   next[mp[a[i]]] = n;
 mp.clear();     
 int minn = 0;
 if(a[1] == 0)++minn;
 mex[1] = minn,mp[a[1]] = 1;
 for(int i =2;i<=n;++i) {
  mp[a[i]] = 1;
  while(mp[minn])++minn;
  mex[i] = minn;
 }
}
void change(int x){
 int val = a[x];
 mex[x] = 0;
 int end = next[x];
 if(end == 0)end = n;
 for(int i = end;i>x;--i)
  if(mex[i] > val)
   mex[i] = val;
  else
   break;
}
struct qes{
 int ind,l,r;
 bool operator < (const qes & a)const{
  return l < a.l|| (l == a.l && r<a.r);
 }
};
qes q[MN];
int anss[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    for(int i = 1;i<=n;++i)a[i] =gi;
    pre();
    for(int i = 1;i<=m;++i)
     q[i].ind = i,q[i].l = gi,q[i].r = gi;
    sort(q+1,q+1+m);
    int last = 1;
    for(int i = 1;i<=m;++i)
    {
     if(q[i].l == last)
      anss[q[i].ind] = mex[q[i].r];
     else
     {
      for(int j = last;j<q[i].l;++j)
       change(j);
      anss[q[i].ind] = mex[q[i].r];
     }
     last = q[i].l;
    }
    for(int i = 1;i<=m;++i)
     printf("%d\n",anss[i]);
    closeIO();
    return EXIT_SUCCESS;
}
