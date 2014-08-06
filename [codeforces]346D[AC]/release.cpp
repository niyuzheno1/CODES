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
void read(int & x)
{
 char tmp = 0; int flag = 1,ret = 0;
 while(tmp != '-' && !isdigit(tmp)) tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();
 while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}
void read(int64 & x)
{
 char tmp = 0; int64 flag = 1,ret = 0;
 while(tmp != '-' && !isdigit(tmp)) tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();
 while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

const int MN = 1000005;
int n,m,s,t,st[MN],nxt[MN],lk[MN],f[MN],q[MN*2],in[MN];
bool b[MN];
void add(int u,int v,int t)
{
 lk[t] = v,nxt[t] = st[u],st[u] = t;
}
void init()
{
     read(n);read(m);
     for(int i = 1,u,v;i<=m;++i)
      read(u),read(v),add(v,u,i),in[u]++;
     read(s);read(t);
}
void solve()
{
 memset(f,0x7f,sizeof(f)),f[t] = 0,q[n] = t;
 for(int l = n,r=n,u;l<=r;++l)
 {
  if(b[u=q[l]]) continue;
  b[u] = 1;
  for(int i = st[u],v;v=lk[i],i;i=nxt[i])
   if(!--in[v])
    if(f[u]<f[v])
     f[v] = f[u],q[l--] = v;
    else;
   else
    if(f[u]+1<f[v])
     f[v] = f[u]+1,q[++r]=v;
 }
 printf("%d\n",f[s]<INF?f[s]:-1);
}
int main(int argc, char *argv[])
{
    //setIO("346D");
    init();solve();
    //closeIO();
    return EXIT_SUCCESS;
}
