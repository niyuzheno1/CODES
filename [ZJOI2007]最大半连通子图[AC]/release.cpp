#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define rep(x,y) for(int i = 0;i<n;++i)
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

#undef INF
#define INF ~0U>>1
#define MN  100000
int n,m,mod;
vector<int> E[MN];
typedef vector<int>::iterator it;
int ord[MN]={0},low[MN],stack[MN],top=0,cnt=0,id[MN],snt = 0;
bool inStack[MN] = {0};
void dfs(int x){
 ord[x] = low[x] = ++cnt;
 stack[top++]=x;inStack[x] = true;
 for(it i = E[x].begin();i!=E[x].end();++i)
   if(!ord[*i])
    dfs(*i),low[x] = min(low[x],low[*i]);
   else if(inStack[*i])
    low[x] = min(low[x],ord[*i]);
 if(low[x]==ord[x]){
  int u;do{u=stack[--top];id[u]=snt;inStack[u]=false;}while(u != x);
  ++snt;
 }
}
struct State{
 int Ans,Num;
 State():Ans(0),Num(1){}
 void Renew(const State & o){
  if(o.Ans < Ans) return ;
  if(o.Ans > Ans) {*this = o;return;}
  Num += o.Num;Num%=mod;
 }
};
State Dp[MN];
set<int> Edge[MN];
typedef set<int>::iterator sit;
int In[MN]={0},Num[MN]={0};
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi,mod = gi;
    int s,t;
    while(m--)s=gi,t=gi,E[s-1].pb(t-1);
    rep(i,n) if(!ord[i]) dfs(i);
    rep(i,n){
     int own = id[i];++Num[own];
     for(it e = E[i].begin();e != E[i].end();++e) if(id[*e] != own) Edge[own].insert(id[*e]);
    }
    rep(i,snt) 
     for(sit e = Edge[i].begin();e!=Edge[i].end();++e) In[*e]++;
    queue<int> Q;vector<int> S;
    rep(i,snt) if(!In[i]) Q.push(i);
    while(Q.size()){
     int t = Q.front();Q.pop();
     S.pb(t);
     for(sit i = Edge[t].begin();i != Edge[t].end();++i)
      if(!--In[*i]) Q.push(*i);
    }
    for(vector<int>::reverse_iterator i = S.rbegin();i!=S.rend();++i)
    {
     for(sit e = Edge[*i].begin();e!=Edge[*i].end();++e)
      Dp[*i].Renew(Dp[*e]);
     Dp[*i].Ans += Num[*i];
    }
    State Ans;
    rep(i,snt) Ans.Renew(Dp[i]);
    printf("%d\n",Ans.Ans);
    printf("%d\n",Ans.Num);
    closeIO();
    return EXIT_SUCCESS;
}
