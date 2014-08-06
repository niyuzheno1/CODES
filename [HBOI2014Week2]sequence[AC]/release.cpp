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


#define MN 15010

int n,K,ans;
char str[MN];
int val[MN],fail[MN],ch[MN][30],nex[MN],tot,a[MN];

void ins(int & u,int v,int x)
{
     if(!ch[u][v]) ch[u][v]=++tot;
     nex[u] = ch[u][v],u = ch[u][v],val[u] = x;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    gets(str+1);
    n = strlen(str+1);K=gi;
    for(int i = 1;i<=n;++i)
    {
     CLEAR(nex,0);CLEAR(val,0);CLEAR(fail,0);CLEAR(ch,0);CLEAR(a,0x7f);
     int u = 0;tot = 0;
     if(i == n) break;
     for(int j = i+1;j<=n+1;++j){
      ins(u,j==n+1?29:str[j]-'a',j);
     }
     queue<int> q;
     q.push(1);fail[1] = 0;
     while(!q.empty())
     {
      int x = q.front();q.pop();
      if(x == 5) 
      x = 5;
      for(int u = 0;u<=29;++u)
       if(ch[x][u])
       {
        int p = ch[x][u];
        int f = fail[x];
        if(u == 29) {
         fail[p] = nex[fail[x]];
         break;
        }
        while(f && !ch[f][u]) f = fail[f];
        if(ch[f][u]) fail[p] = ch[f][u];
        else  fail[p] = 0;
        q.push(ch[x][u]);
       }
      if(val[fail[nex[x]]]-i >= K)
       a[nex[x]] = min(val[fail[nex[x]]],a[fail[nex[x]]]);
      else
       a[nex[x]] = a[fail[nex[x]]];
      if(a[nex[x]]-i >= K && val[x]-(a[nex[x]]-i)>=a[nex[x]])
       ++ans;
     }
    }
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
