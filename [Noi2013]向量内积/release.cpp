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

using namespace std;
const int MN = 100000+10,MD =100+10;
int n,d,k;
int a[MN][MD];
int b[MD][MN];
int x[MN];
int y[MN];
int ans1[MN],ans2[MN];
int main(int argc, char *argv[])
{
    setIO("meow");
    n = gi,d = gi,k = gi;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=d;++j){
      a[i][j] = b[j][i] = (gi)&1;
     }
    if(n == 2){
     printf("1 2\n");
     return 0;
    }
    int sumx1 = 0;
    for(int i = 1;i<=n;++i) x[i] = rand()%2,sumx1+=x[i];
    for(int i = 1;i<=n;++i) ans2[i] = (sumx1 - x[i])%2;
    for(int i = 1;i<=d;++i)
     for(int j = 1;j<=n;++j)
      y[i] = (y[i]+x[j]*a[j][i])%2;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=d;++j)
      ans1[i] = (ans1[i]+y[j]*b[j][i])%2;
    int flag = 0 ;
    for(int i = 1;i<=n;++i)
     if(ans1[i] != ans2[i])
      flag = i;
    if(!flag) printf("-1 -1\n");
    else{ 
     int another = 0;
     for(int i = 1;i<=n &&(~another);++i)
     if(i != flag){
      int res = 0;
      for(int j = 1;j<=d;++j)
       res += a[i][j]*a[flag][j];
      if(res%2 == 0)
       another = res;
     }
     if(flag > another)swap(flag,another);
     printf("%d %d\n",flag,another);
    }
    closeIO();
    return EXIT_SUCCESS;
}
