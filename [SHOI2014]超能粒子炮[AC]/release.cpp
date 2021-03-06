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

typedef long long ll;
int n,m,a,b;
typedef pair<ll,ll> pll;
vector<pll> chains;

/*
  p0 -> the first of seq A
  p1 -> the len of seq A
  the same
  a -> the delta of seq A and B
  return the numbers of elements x,y of A and B that x<y and f(x) > f(y)
*/
ll cal(ll p0,ll l0,ll p1,ll l1,ll a){
 ll ret = 0;
 if (p0 < p1){
     ll cnt = min((p1-p0)/a+1,l0); //have inverse
     ret += cnt *l1;
     l0 -= cnt;
     p0 += cnt * a;
 }
 if(p0 >= p1 + a){
      long long cnt = (p0-p1)/a;//no inverse
      l1 -= cnt;
      p1 += cnt * a;
 }
 --l1,p1+=a;
 if(l0 > 0 && l1 > 0){
  long long l = min(l0,l1);
  ret += (l1+l1-l+1)*l/2;
 }
 return ret;
}
int rev(int a){
 return a==1?1:(ll)(m-m/a)*rev(m%a)%m;
}
#define MN 1005
ll cnt[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi,a = gi,b = gi;
    if(a <= rev(a)){
     int rb = b;
     b = (a+b)%m+1; //f(1)
     int go = 0;
     ll ans = 0;
     while(go < n)
     {
        int len = min(n-go,(m-b)/a+1);//ax+b>=m
        for(int i = 1;i<=a;++i)
         if(cnt[i])
          ans += cnt[i]*cal(b,len,i,(m-i)/a+1,a);
        for(int i = 0;i<chains.size();++i)
         ans += cal(b,len,chains[i].X,chains[i].Y,a);
        if(b <= a && len == (m-b)/a+1)
         ++cnt[b];
        else
         chains.pb(MP(b,len)); //to process the head and tail exception
        go += len;
        b = (rb+(ll)(go+1)*a)%m+1;//f(go+1)
     }
     cout<<ans<<endl;
    }else{
     int ra = rev(a);
     b = (ll)(m-b-1)*ra%m;
     int rb = b;
     b = (b+ra)%m;
     int go = 0;
     ll ans = 0;
     while(go < m){
      if(b<=n){
        int len = min(m-go,(n-b)/ra+1);
        for(int i = 1;i<=ra;++i)
         if(cnt[i])
          ans += cnt[i] * cal(b,len,i,(n-i)/ra+1,ra);
        for(int i =0;i<chains.size();++i) 
          ans += cal(b,len,chains[i].X,chains[i].Y,ra);
        if(b <= ra && len == (n-b)/ra+1)
         ++cnt[b];
        else
         chains.pb(MP(b,len));
      }
      go += min(m-go,(m-b)/ra+1);
      b = (rb+(ll)(go+1)*ra)%m;
      if(b ==0 )
      {
       b+=ra;
       ++go;
      }
     }
     cout<<ans<<endl;
    }
    closeIO();
    return EXIT_SUCCESS;
}
