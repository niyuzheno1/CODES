#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
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


#undef INF
#define MN 101
#define INF 0x7f7f7f7f
int q[MN],f[MN],map[MN][MN],temp[MN][MN];
int n,s1,e1,s2,e2,q1,q2,flow,tt,flag;
char c,enter;
int bfs()
{
     CLEAR(q,0);CLEAR(f,0xff);
     int h = 0,t = 1;f[0] = 1;
     while(h < t)
     {
      int now = q[++h];if(now == n) return 1;
      for(int i = 0;i<=n;++i)
       if(map[now][i] && f[i] == -1)
       {
        q[++t] = i;
        f[i] = f[now]+1;
       }
     }     
     return 0;
}
int dinic(int sta,int sum)
{
    if(sta == n) return sum;
    int os = sum;
    for(int i = 0;i<=n;++i)
     if(map[sta][i] && f[i] == f[sta]+1)
     {
      int Min = dinic(i,min(os,map[sta][i]));
      map[sta][i] -= Min;map[i][sta] += Min;os-=Min;
     }
    if(os == sum) f[sta] =-1;
    return sum-os;
}

int main()
{
    setIO("sample");
    while(~scanf("%d%d%d%d%d%d%d",&n,&s1,&e1,&q1,&s2,&e2,&q2))
    {
     ++s1,++e1,++s2,++e2;
     CLEAR(map,0);CLEAR(temp,0);
     for(int i = 1;i<=n;++i)
     {
     enter = getchar();
      for(int j = 1;j<=n;++j)
      {
       c = getchar();
       if(c == 'O')
        map[i][j] = temp[i][j] = 2;
       if(c == 'N')
        map[i][j] = temp[i][j] = INF;
      }
     }
     flag = 1;
     flow = 0;map[0][s1] = q1*2;map[0][s2] = q2*2;
     map[e1][++n] = q1*2;map[e2][n] = q2*2;
     while(bfs()){
      tt = dinic(0,INF);
      flow += tt;
      }
     if(flow < 2*(q1+q2)) flag =0;
     if(flag){
      CLEAR(map,0);
      for(int i = 1;i<n;++i)
       for(int j = 1;j<n;++j)
        map[i][j] = temp[i][j];
      map[0][s1] = q1*2;map[0][e2] = q2*2;map[e1][n] = q1*2;map[s2][n] = q2*2;flow = 0;
      while(bfs()){
      tt = dinic(0,INF);
      flow += tt;
      }
      if (flow<2*(q1+q2)) flag=0; 
     }
     if(flag) puts("Yes");else puts("No");
    }
    closeIO();
}
