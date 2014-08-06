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


#define MN 1010
struct ele
{
       int i,p;
};
struct minmonoqueue{
 ele Q[MN];
 int Width,head,tail;
 void ins(int i ,int p)
 {
       while(tail >= head && (i-Q[tail].i>=Width || p <= Q[tail].p ))
        --tail;
       Q[++tail].p = p;
       Q[tail].i = i;
 }
 int get(int i)
 {
     while(i-Q[head].i>=Width)++head;
     return Q[head].p;
 }
 void init(int W)
 {
  Width = W;
  head = 0;tail = -1;
 }
}MinQ; 
struct maxmonoqueue {
 ele Q[MN];
 int Width,head,tail;
 void ins(int i ,int p)
 {
       while(tail >= head && (i-Q[tail].i>=Width || p >= Q[tail].p ))
        --tail;
       Q[++tail].p = p;
       Q[tail].i = i;
 }
 int get(int i)
 {
     while(i-Q[head].i>=Width)++head;
     return Q[head].p;
 }
 void init(int W)
 {
  Width = W;
  head = 0;tail = -1;
 }
}MaxQ;
int N,M,P,Ans;
int A[MN][MN],B[MN][MN],C[MN][MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    N = gi,M = gi,P = gi;
    for(int i = 1;i<=N;++i)
     for(int j = 1;j<=M;++j) A[i][j] = gi;
    Ans = INF;
    int Amin=0,Amax=0;
    for(int j = 1;j<=M;++j)
    {
     MinQ.init(P);
     MaxQ.init(P);
     for(int i = 1;i<P;++i)
      MinQ.ins(i,A[i][j]),MaxQ.ins(i,A[i][j]);
     for(int i = P;i<=N;++i)
     {
      MinQ.ins(i,A[i][j]),MaxQ.ins(i,A[i][j]);
      int k = i-P+1;
      B[k][j] = MinQ.get(i);
      C[k][j] = MaxQ.get(i);
     }
    }
    for(int i = 1;i+P-1<=N;++i)
    {
     MinQ.init(P);MaxQ.init(P);
     for(int j = 1;j<P;++j) MinQ.ins(j,B[i][j]),MaxQ.ins(j,C[i][j]);
     for(int j = P;j<=M;++j)
     {
     MinQ.ins(j,B[i][j]),MaxQ.ins(j,C[i][j]);
     Amin = MinQ.get(j);
     Amax = MaxQ.get(j);
      Ans = min(Ans,Amax-Amin);
     }
    }
    printf("%d",Ans);
    closeIO();
    return EXIT_SUCCESS;
}
