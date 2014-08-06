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
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file = "sample")
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

#define MN 100005
int t,f,sg[MN],vis[MN];
void initsg()
{
     for(int i = 0;i<f;sg[i] = 0,++i);
     for(int i = f;i<=MN-5;++i){
      for(int l = 2,last=  0;l<=i;l=last+1){
       last = i/(i/l);
       int p = i/l,q = i%l,isq=l-q;
       vis[sg[(q&1)*(p+1)]^sg[(isq&1)*p]] = i;
       if(q >= p && l+p+1-q>=0)
        vis[sg[((q-p)&1)*(p+1)]^sg[((l+p+1-q)&1)*p]] = i;
      }
      int j = 0;
      for(;;++j) if(vis[j] != i) break;
      sg[i] = j;
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    t = gi, f = gi;
    initsg();
    for(int j = 1;j<=t;++j){
     int n = gi,res = 0;
     for(int i = 1;i<=n;res^=sg[gi],++i);
     printf(j == 1 ? "%d" : " %d" ,res!=0);
    }
    closeIO();
    return EXIT_SUCCESS;
}
