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

#define SSPLAY
#ifdef SPLAY
#define L C[0]
#define R C[1]
#define F C[2]
#endif
#ifdef SSPLAY
#define L 0
#define R 1
#define F 2
#endif
#ifdef SGT
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LEF(_t),_l,mid
#define RIGHT RIG(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}
#endif

const int N = 10100;
struct lct{
       int ch[N][3],sz[N],w[N];
       inline void update(int x)
       {
        sz[x] = sz[ch[x][L]]+sz[ch[x][R]]+w[x]+1;
       }
       inline bool isrt(int x){
        return (ch[x][F] == 0 || (ch[ch[x][F]][L]!=x&&ch[ch[x][F]][R]!=x));
       }
       void rotate(int x)
       {
        int y = ch[x][F],z = ch[y][F],d1 = (ch[y][0]==x),d2 = (ch[z][1] == y) ,d3 = isrt(y);
        ch[y][!d1] = ch[x][d1],ch[ch[y][!d1]][F]= y;
        ch[x][d1] = y;ch[y][F]=x;
        if(!d3) ch[z][d2]= x;
        ch[x][F]=z;
        update(y);update(x);
       }
       void splay(int x)
       {
        while(!isrt(x))
        {
         int y = ch[x][F];
         if(!isrt(y)){
         int z = ch[y][F];
         int d1 = ((ch[z][0]==y)==(ch[y][0]==x));
         if(d1) rotate(y);
         }
         rotate(x);
        }
        update(x);
       }
       void access(int rt){
        for(int x = rt,y = 0;x;x=ch[x][F]){
         splay(x);
         //modify
         ch[x][R]= y;
         update(y=x);
        }
       }
       void link(int x,int y)
       {
        access(y);
        splay(x);
        ch[x][F]=y;
        ch[y][R]=x;
        update(y);
       }
       void cut(int x,int y)
       {
        access(x);splay(x);splay(y);
        if(ch[y][L] == x) ch[y][L] = 0;
        else ch[y][R] = 0;
        ch[x][F] = 0;
        update(y);
       }
       int lmost(int x)
       {
        while(ch[x][L]) x=  ch[x][L];
        return x;
       }
       int upmost(int x)
       {
        while(ch[x][F]) x= ch[x][F];
        return x;
       }
       bool isconnect(int x,int y)
       {
        int u = upmost(x),v = upmost(y);
        if(u == v) return true;
        else return false;
       }
};
lct t;
int main(int argc, char *argv[])
{
    setIO("sample");
    int n , m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;++i)
    {
     char opt[5];scanf("%s",opt);
     int x,y;scanf("%d%d",&x,&y);
     if(opt[0] == 'Q')
      if(t.isconnect(x,y))
       printf("Yes\n");
      else
       printf("No\n");
     if(opt[0] == 'C')
      t.link(x,y);
     if(opt[0] == 'D')
      t.cut(x,y);
    }
    closeIO();
    return EXIT_SUCCESS;
}
