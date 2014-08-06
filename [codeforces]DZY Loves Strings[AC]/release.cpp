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

#define iter iterator
typedef vector<int> vi;
typedef pair<string,string> pss;
map<string,vi> occ;
map<pss,int> ans;
string s;
int main(int argc, char *argv[])
{
    setIO("sample");
    cin>>s;
    int l = s.length();
    for(int i = 0;i<l;++i){
     string tmp("");
     for(int j = 0;j<4 && i+j <l;++j){
     tmp += s[i+j];
     occ[tmp].pb(i);
     }
    }
    int q;
    cin>>q;
    while(q--){
     string a,b;
     cin>>a>>b;
     if(ans[MP(a,b)]) {
      cout<<ans[MP(a,b)]<<endl;
      continue;
     }
     vi va(occ[a]),vb(occ[b]);
     if(va.empty()||vb.empty()){
      ans[MP(a,b)]=-1;
      cout<<"-1"<<endl;
      continue;
     }
     int res = INF;
     vi::iter ia = va.begin(),ib = vb.begin();
     for(;ia!=va.end()&&ib!=vb.end();)
     {
      res = min(res,int(max(a.size()+*ia,b.size()+*ib)-min(*ia,*ib)));
      if(*ia < *ib)++ia;
      else ++ib;
     }
     cout<<res<<endl;
     ans[MP(a,b)] = res;
    }
    closeIO();
    return EXIT_SUCCESS;
}
