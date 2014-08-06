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
#define INF  1000000010;
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

int N;
const int MN = 152;
const int dx[] = {0,0,1,0,-1};
const int dy[] = {0,1,0,-1,0};
int f[MN][MN];
bool check(pii u)
{
     for(int i = 1;i<=4;++i)
      if(!f[u.X+dx[i]][u.Y+dy[i]])
       return true;
     return false;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    N = gi;
    N+=2;
    for(int i = 1;i<=N;++i)f[i][N] = 1,f[i][1] = 1;
    for(int i = 1;i<=N;++i)f[N][i] = 1,f[1][i] = 1;
    pii d = MP(2,2);
    int cnt = 1,k = 1;f[2][2] = 1;
    while(check(d))
    {
     int nx = d.X+dx[k];
     int ny = d.Y+dy[k];
     while(f[nx][ny]){
      k++,k%=5,k=k?k:1;
      nx = d.X+dx[k],ny = d.Y+dy[k];
     }
     ++cnt;f[nx][ny] = cnt;d = MP(nx,ny);
    }
    for(int i =2;i<=N-1;printf("\n"),++i)
     for(int j = 2;j<=N-1;++j)
      printf("%6d",f[i][j]);
    closeIO();
    return EXIT_SUCCESS;
}
