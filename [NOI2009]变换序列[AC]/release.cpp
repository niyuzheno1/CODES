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

const int MN =  20001,MM = MN *4 ;
struct edge{
       edge * next;
       int t;
}* V[MN],ES[MM];
int n,EC;
int S[MN][2],mat[MN];
bool vis[MN];
inline void addedge(int a,int b)
{
       ES[++EC].next = V[a];V[a] = ES+EC;V[a]->t = b;
}

void init()
{
     scanf("%d",&n);
     for(int i = 1,d,t1,t2;i<=n;++i)
     {
      scanf("%d",&d);
      t1 = i+d;
      if(t1 > n) t1 -= n;
      t2 = i-d; 
      if(t2 < 1) t2 += n;
      if(t1 < t2)
       S[i][0] = t1,S[i][1] = t2;
      else
       S[i][0] = t2,S[i][1] = t1;
      addedge(i,S[i][1]+=n);
      addedge(i,S[i][0]+=n);
     }
}
bool augment(int i)
{
 for(edge * e = V[i];e;e = e->next){
   int j = e->t;
   if(!vis[j]){
    vis[j] = 1;
    if(!mat[j] || augment(mat[j]))
    {
     mat[j] = i;
     mat[i] = j;
     return 1;
    }
   }
 }    
 return false;
}

void solve()
{
 int cnt = 0;
 for(int i = n;i>=1;--i)
 CLEAR(vis,0),augment(i) ? ++cnt : 0;
 if(cnt < n)
 {
  printf("No Answer\n");
  exit(0);
 }
}
void print()
{
 for(int i = 1;i<=n;++i,printf("%c",i==n+1?'\n':' '))
  printf("%d",mat[i]-n-1);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();solve();print();
    closeIO();
    return EXIT_SUCCESS;
}
