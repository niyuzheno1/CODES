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
const int INF =  1000000010;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
FILE * d;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);d = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(d);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
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
uint64 n;
int main(int argc, char *argv[])
{
    setIO("sample");
    int t;read<int>(t);
    while(t--)
    {
     read<uint64>(n);
     uint64 p = n;
     uint64 e = n+1;
     while(!isprime<uint64>(p))
      p--;
     while(!isprime<uint64>(e))
      e++;
     uint64 ans1 = p*e-2*e+2*(n-p+1),ans2 = 2*p*e;
     uint64 tmp = gcd<uint64>(ans1,ans2);
     ans1/=tmp;ans2/=tmp;
     printf("%I64d/%I64d\n",ans1,ans2);
    }
    closeIO();
    return EXIT_SUCCESS;
}

