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
const int INF =  1000000010;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
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

const int N  = 100100;
bool a[N*2+1],aa[N+1];
int b[N*2+1],c[N*2+1],h[N+1],n,m,i,x,y;
int go(int k)
{
 aa[k] = 1;
 int x = 0;
 for(int i=h[k],t;i;i=b[i])
  if(!a[i])
  {
   a[i>m ? i-m:i+m] = 1;
   if(t = (aa[c[i]] ? 0 : go(c[i])))
    printf("%d %d %d\n",k,c[i],t);
   else
    if(x)
     printf("%d %d %d\n",x,k,c[i]),x = 0;
    else
     x = c[i];
  }
 return x;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    if(m&1)
    {
     puts("No solution");
     return 0;
    }
    for(int i = 1;i<=m;++i)
    {
     x = gi,y=gi;
     b[i] = h[x];c[i] = y;h[x] = i;
     b[i+m] = h[y];c[i+m] = x;h[y] = i+m;
    }
    go(1);
    closeIO();
    return EXIT_SUCCESS;
}