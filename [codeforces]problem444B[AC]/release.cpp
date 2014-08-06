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

#define MN 100010
#define BEEP for(int i=0;i<n;++i)
#undef pb
typedef long long LL;
int n,d,a[MN],b[MN],ans[MN]={0},s = 42;
int pa[MN],pb[MN];
LL x;
int get() {return x = (x*37+10007)%1000000007;}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, d = gi, x = gi;
    BEEP a[i]=i+1,b[i]=(i<d);
    BEEP swap(a[i],a[get()%(i+1)]);
    BEEP swap(b[i],b[get()%(i+1)]);
    BEEP {
         pa[a[i]] = i;
         if(b[i]) pb[++pb[0]] = i;
    }
    BEEP {
     for(int j = 0;j<s;++j)
      if(pa[n-j]<=i && b[i-pa[n-j]])
      {ans[i] = n-j;break;}
     if(!ans[i])
      for(int j = 1;j<=d&&pb[j]<=i;++j)
       ans[i] =max(ans[i],a[i-pb[j]]);
    }
    BEEP 
     printf("%d\n",ans[i]);
    closeIO();
    return EXIT_SUCCESS;
}
