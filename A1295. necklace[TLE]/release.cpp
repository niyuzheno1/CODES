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
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\





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
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
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

void endline()
{
     ff(debug,"\n");
}

typedef double ld;
const int MN = 1010,MM = 11;
typedef pair<pii,int> piii;
typedef map<piii,ld> nmap;
typedef nmap::iterator itor;
nmap f[2];
ld a[MN][MM];
int n,m;
int main(int argc, char *argv[])
{
    setIO("sample");
    for(int i = 0;i<2;++i) f[i].clear();
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j)
      scanf("%lf",&a[i][j]);
    f[0][MP(MP(0,0),1)] = 1;
    for(int i = 1;i<=n;++i)
    {
     int now = i&1,last = now^1;
     f[now].clear();
     for(itor it = f[last].begin();it != f[last].end();++it)
     {
      int col = (*it).X.X.X,len = (*it).X.X.Y,len1 = (*it).X.Y;
      double pp = (*it).Y;
      for(int j = 1;j<=m;++j)
      {
       if(j != col)
       f[now][MP(MP(j,1),len1)] += pp*a[i][j];
       else
       f[now][MP(MP(j,len+1),max(len1,len+1))] += pp*a[i][j];
      }
     }
    }
    double ans = 0;
    int ECase = 0;
    for(itor it = f[(n)&1].begin();it != f[(n)&1].end();++it)
    {
     ++ECase;
     ff(debug,"number %d : col:%d len:%d len1:%d P:%.5f\n",ECase,(*it).X.X.X,(*it).X.X.Y,(*it).X.Y,(*it).Y);
     ans += (*it).Y*double((*it).X.Y);
    }
    printf("%.6f\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
