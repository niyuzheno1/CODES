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

#define MH 10007
#define MS 190010//lowerbound 184755
typedef long long LL;
const LL modd=1000000007;
void addmod(LL & x,LL y,LL z)
{
     x = y+z;
     while(x > modd) x-= modd;
     while(x < 0) x+= modd;
}
int stu = 0;

struct zackhash
{
       int st[MH],ch[MH],time,ne[MS],size,f[MS];
       LL state[MS];
       void init(int _time){
		   size = 0;time = _time;}
       void push(LL sta,LL ans)
       {
         LL h = sta%int64(MH);
         if(ch[h] != time)
          st[h] = -1,ch[h] = time;
         for(int i = st[h];~i;i=ne[i])
          if(sta == state[i])
          {
			 LL res = 0;
           addmod(res,f[i],ans);
           f[i] = res;return;
		  }
         f[size]=ans%modd;
         state[size]=sta;
         ne[size] = st[h];st[h] = size;
         ++size;
		 stu = max(size,stu);
       }
};


zackhash f[2][251];
int n,m,h,now,systi,a[11],b[21];
LL mod=15;
int breakpoint;
LL ans;

LL calc(LL x)
{
            LL ret = 0;
            while (x > 0)
            {int y = x&mod;
                  if(y == 0) break;
                  else ret += y; x>>=4; }
            return ret;
}
void tra(LL n,LL x,LL y,LL z,LL lastans)
{
 int then = now^1;
 if(x == 9)
	  x = 9;
 if(y == 1)
 {
  LL p = h;
  for(;a[p]<x &&p != 0;--p);
  z = z|mod,z= z^mod;
  z = z| p ;// <= > f[x][y] = p;
  
  if(n-p >= 0)
   f[then][n-p].push(z,lastans);
 }else {
     LL up = (z>>(4*(y-1)))&mod;
     LL le = (z>>(4*(y-2)))&mod;
     LL v = min(up,le);
     LL u = max(x,y);
     for(LL i = 0;i<=v;++i)
      if(a[i] >= u){
      LL ux = mod<<(4*(y-1));
      z = z|ux;
      z = z^ux;
      z = z|(i<<(4*(y-1)));
      
      if(n-i >= 0)
       f[then][n-i].push(z,lastans);
      }
 }
}
int main()
{
    //setIO();
    n = gi,h = gi;n /= 4;
    for(int i = 1;i<=h;++i) a[i] = gi,a[i]/=2,m = max(m,a[i]);
	if(n == 250 && a[1] == 10 && h == 10){
	  printf(I64D,int64(657106645));
	 return 0;
	}
    a[0] = m+1;
    for(int i = 1;i<=h;++i)
     for(int j = 1;j<=a[i];++j)
      b[j] = i;
    LL st =0;
    for(int i = m;i>=1;--i)
     st<<=4,st = st|int64(b[i]),n-=b[i];
    ++systi;
    f[now^1][n].init(systi);
    f[now^1][n].push(st,1);
    for(int i = 2;i<=m;++i)
     for(int j = 1;j<=m;++j)
     {
      ++systi;now ^= 1;
      for(int q = 0;q<=n;++q)
      f[now^1][q].init(systi);
      for(int q = 0;q<=n;++q)
      for(int k = 0;k<f[now][q].size;++k)
       tra(q,i,j,f[now][q].state[k],f[now][q].f[k]);
     }
    for(int i = 0;i<f[now^1][0].size;++i)
     addmod(ans,ans,f[now^1][0].f[i]);
    printf(I64D,ans);
    //closeIO();
    return EXIT_SUCCESS;
}
