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

#define MN 13
int64 f[MN][MN][1<<(MN+1)],ans;
int a[MN][MN];
int U ;
inline void sh(int & x)
{
  x<<=1;x&=U;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int iCase = 0,T = gi;
    while(T--){
    printf("Case %d: ",++iCase);
    CLEAR(a,0);CLEAR(f,0);ans = 0;
    int n=gi,m=gi;
    f[0][m][0] = 1;
    for(int i = 1;i<=n;++i) for(int j = 1;j<=m;++j) a[i][j] = gi;
    U = (1<<(m+1))-1;
    for(int i = 0;i<=n;++i)
     for(int j = (i==0)?m:1;j<=m;++j)
     {
      for(int k = 0;k<=U;++k)
      {
       if(!f[i][j][k])continue;
       int now = k;
       int u1 = (now & (1<<j));
       int u2 = (now & (1<<(j-1)));
       if(a[i][j] == 0)
       {
        if(u1) now ^= (1<<j);
        if(u2)now ^= (1<<(j-1));
        if(j == m) sh(now),f[i+1][1][now] += f[i][j][k];
        else f[i][j+1][now] += f[i][j][k];
       }else{
        if(u1 && u2)
        {
         now ^= (1<<j),now ^= (1<<(j-1));
         if(j == m) sh(now),f[i+1][1][now] += f[i][j][k];
         else f[i][j+1][now] += f[i][j][k];
        }
        else if(u1 || u2)
        {
             if(u1) now ^= (1<<j);
             if(u2) now ^= (1<<(j-1));
             if(a[i][j+1])
             {
              int nowp = now^(1<<j);
              f[i][j+1][nowp] += f[i][j][k];
             }
             if(a[i+1][j])
             {
              int nowp = now^(1<<(j-1));
              if(j == m ) sh(nowp),f[i+1][1][nowp] += f[i][j][k];
              else f[i][j+1][nowp] += f[i][j][k];
             }
        }
        else
       {
           if(!u1) now ^= (1<<j);
           if(!u2) now ^= (1<<(j-1));
           if(a[i][j+1] && a[i+1][j])
           {
            f[i][j+1][now] += f[i][j][k];
           }
       }
       }
       
      }
     }
    for(int i = 0;i<=U;++i)
     ans += f[n+1][1][i];
    printf("There are %I64d ways to eat the trees.",ans);
    puts("");
    }
    closeIO();
    
    return EXIT_SUCCESS;
}
