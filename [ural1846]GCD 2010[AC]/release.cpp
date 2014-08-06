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
#define MP make_pair
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

template <class T>
bool isprime(T x)
{
     if(x == 1) return false;
     for(T i = 2;i*i<=x;i++) if(x % i == 0) return false;
     return true;
}

template <class T>
T gcd(T a,T b)
{
       if(b == 0) return a;
       return gcd(b,a%b);
}

const int MAXN  = 100010;
int gc(int x,int y)
{ return gcd<int>(x,y); }
int a[4*MAXN],n,m,tot;
typedef map<int,vector<int> > mp;
typedef mp::iterator itor;
mp hash;
char getstr()
{
 char c = ' ';
 while(c == ' ' || c == '\n') c = getchar();
 return c;
}
void update(int x)
{
 for(x>>=1;x;x>>=1)
 {
  a[x] = 0;
  if(a[2*x] != 0)
   a[x] = gc(a[x],a[2*x]);
  if(a[2*x+1] != 0)
   a[x] = gc(a[x],a[2*x+1]);
 }
}
void inc(int x)
{
 tot++;
 hash[x].push_back(tot);
 a[m+tot] = x;
 update(m+tot);
}
void dec(int x)
{
 int u = (*hash[x].begin());
 hash[x].erase(hash[x].begin());
 a[m+u] = 0;
 update(m+u);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    m = 1;
    while(m <= n) m*=2;
    for(int i = 1;i<=n;++i)
    {
     char op;
     op = getstr();
     int x = gi;
     if(op == '+')
      inc(x);
     else
      dec(x);
     printf("%d\n",a[1]==0?1:a[1]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
