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
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> _reserve_type_1;
typedef pair<int64,int64> pll;
#define pii _reserve_type_1
FILE * debug;
#define setIO _func_2_
void _func_2_(string file = "sample")
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

void endline()
{
     ff(debug,"\n");
}

#define MN 31000
#undef INF
const int INF = ~0U>>1;
struct Edge{
       int top,a[MN],loc[MN*2],next[MN*2];
       void init(){
       CLEAR(a,0);
       top = 0;
       }
       void add(int x,int y){
       int p = ++top;
       loc[p] = y;
       next[p] = a[x];
       a[x] = p;
       }
};
Edge a,child;
int value[MN],depth[MN],father[MN],blockroot[MN];
int size[MN],limit;
int VSum[MN],VMax[MN];
void buildblocks(int v,int f,int dep){
 depth[v] = dep;
 father[v] = f;
 int curBlock = blockroot[v];
 for(int p= a.a[v];p;p=a.next[p])
  if(a.loc[p] != f)
  {
   if(size[curBlock]+1 < limit){
    child.add(v,a.loc[p]);
    blockroot[a.loc[p]] = curBlock;
    ++size[curBlock];
   }
   buildblocks(a.loc[p],v,dep+1);
  }
}
void initData(int v,int sumValue,int maxValue){
sumValue += value[v];VSum[v] = sumValue;
maxValue = max(maxValue,value[v]);VMax[v] = maxValue;
for(int p = child.a[v];p;p=child.next[p])
 initData(child.loc[p],sumValue,maxValue);
}
void Change(int v,int Data)
{
      value[v] = Data;
      if(v == blockroot[v]) initData(v,0,-INF);
      else initData(v,VSum[father[v]],VMax[father[v]]);
}
pii Query(int a,int b){
 pii ans(0,-INF);
 while(a != b){
 if(depth[a] < depth[b]) swap(a,b);
  if(blockroot[a] == blockroot[b])
  {
   ans.X += value[a];
   ans.Y = max(ans.Y,value[a]);
   a = father[a];
  }
  else{
   if(depth[blockroot[a]] < depth[blockroot[b]])
    swap(a,b);
   ans.X += VSum[a];
   ans.Y = max(ans.Y,VMax[a]);
   a = father[blockroot[a]];
  }
 }
 ans.X += value[a];
 ans.Y = max(ans.Y ,value[a]);
 return ans;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi;
    limit = sqrt(n)+1;
    a.init();child.init();
    for(int i = 1;i<n;++i)
    {
     int x = gi,y = gi;
     a.add(x,y);a.add(y,x);
    }
    for(int i = 1;i<=n;++i)
    {
     value[i] = gi;
     blockroot[i] = i;
    }
    CLEAR(size,0);
    buildblocks(1,0,0);
    for(int i = 1;i<=n;++i)
     if(blockroot[i] == i)
      initData(i,0,-INF);
    int m = gi;
    char cmd[20];
    for(int i = 0;i<m;++i)
    {
     int x,y;
     scanf("%s%d%d",cmd,&x,&y);
     pii ans;
     switch(cmd[1])
     {
      case 'M':ans = Query(x,y);printf("%d\n",ans.Y); break;
      case 'S':ans = Query(x,y);printf("%d\n",ans.X); break;
      case 'H':Change(x,y); break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
