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
void setIO(string file = "sample")
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

//algorithm.h
template<class type,type Mod>
inline type & add(type & a,const type & b,const type & c)
{
    a = b+c;
    if(a>=Mod) a-= Mod;
    return a;
}

template<class type,type Mod>
inline type &sub(type & a,const type &b,const type & c)
{
   a= b-c;
   if(a<0) a+=Mod;
   return a;
}

template<class type,type Mod>
inline type &mut(type & a,const type & b,const type & c)
{
   a = ((b%Mod)*(c%Mod))%Mod;
   return a;
}
#ifdef DIVONMOD
template<class type,type Mod>
inline type &div(type & a,const type & b,const type & c)
{
   type u = 0,v = 0;
   type d = exgcd(a,Mod,u,v);
   a = ((b%Mod)*(d%Mod))%Mod;
   return a;
}
#endif
template<class type>
inline type & up(type & u, type v)
{
       if(v > u) u = v;
       return u;
}
template<class type>
inline type & dn(type & u, type v)
{
       if(v < u) u = v;
       return u;
}

#define MN 105
char str[MN];
int f[MN][MN];
int bit[4] = {0,100,10,1};

bool check(int l,int mid,int r){
 int lens,lent;
 if((lent = r-l+1)%(lens=mid-l+1) != 0) return 0;
 for(int i = l+lens;i<=r;i+=lens)
  for(int j = 0;j<=lens-1;++j)
   if(str[l+j-1] != str[i+j-1])
    return 0;
 return 1;
}

int calc(int num)
{
    for(int i = 1;i<=3;++i)
     if(num >= bit[i]) return 3-i+1;
    return 0;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    gets(str);int len = strlen(str);
    CLEAR(f,1);
    for(int i = 1;i<=len;f[i][i]=1,++i);
    for(int k = 1;k<=len;++k)
     for(int i = 1;i+k<=len;++i)
      for(int j = i,g=  0;j+1<=i+k;++j){
       dn(f[i][i+k],f[i][j]+f[j+1][i+k]);
       if(check(i,j,i+k))
        dn(f[i][i+k],min(calc((k+1)/(j-i+1))+2+f[i][j],k+1));
      }
    printf("%d",f[1][len]);
    closeIO();
    return EXIT_SUCCESS;
}
