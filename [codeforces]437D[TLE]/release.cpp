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
typedef long double ld;
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

template<class T,class OP>
class dset
{
 public:
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

class node{
public:
 int size;
};
int n,m;
const int N = 100005;
vector<int> edge[N];
int a[N],ord[N],appear[N];
bool cmp(int  x,int y)
{
     return a[x]>a[y];
}

class OP{ 
 public:
 void operator()(node & x,node & y) const
 {
  x.size += y.size;
 }
};
dset<node,OP> s;
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
    s.init(n);
    for(int i = 0;i<n;++i)
     s.st[i].size = 1;
    ld ans = 0;
    for(int i = 0,u;i<n;++i){
     u = ord[i];
     appear[u] = 1;
     vector<int> block;
     block.push_back(1);
     for(int j = 0,v;j<(int)edge[u].size();++j){
      v = edge[u][j];
      if(!appear[v]) continue;
      if(s.find(u) != s.find(v)){
      block.push_back(s.st[s.find(v)].size);
      s.merge(s.find(u),s.find(v));
      }
     }
     for(int i = 0;i<(int)block.size();++i)
      ans += (ld)(s.st[s.find(u)].size-block[i])*block[i]*a[u];
    }
    
    printf("%.12f\n",(double)(ans/n/(n-1)));
    closeIO();
    return EXIT_SUCCESS;
}
