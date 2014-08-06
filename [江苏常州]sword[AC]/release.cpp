#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
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

#define MN 22
#define MS 15555555
int a[MN],b[MN],c[MN],d[MN],pre[MN],pow[MN],f[MS];
int main(int argc, char *argv[])
{
    setIO("sample");
    int n , m , ans = 0;
    n = gi,m = gi;
    pow[0] = 1;
    for(int i = 0;i<n;++i)
     pow[i+1] = pow[i]*3,pre[i] = n;
    for(int i = 1;i<=m;++i){
     a[i] = gi;
     b[--a[i]] = i;
     if(i > 1)
      pre[a[i]] = a[i-1];
    }
    a[m+1] = n;
    f[0] = c[n] = 1;
    for(int i= 0;i<pow[n];++i)
     if(f[i]){
      int cnt = 0, k = 1,pos = 0 ;
      for(int j = d[0]=0,t=i;j<n;++j,t/=3)
       if(c[j] = t%3){
       ++cnt;
       if(b[j] > pos) pos = b[j];
       if(c[j] == 1 ) d[++d[0]] = j;
       }
       d[d[0]+1] = n;
       if(cnt == n) ans += f[i];
       for(int j = 0;j<n;++j)
        if(!c[j] && c[pre[j]]){
        bool t = true;
        for(;j>d[k];++k);
        for(int l = pos+1;t &&l<=m+1 && l <= k; ++l)
         if(a[l]> j) t = false;
        if(t) f[i+pow[j]+(k>d[0]?0:pow[d[k]])] += f[i];
        }
     }
    printf("%d",ans);
    closeIO();
    return EXIT_SUCCESS;
}
