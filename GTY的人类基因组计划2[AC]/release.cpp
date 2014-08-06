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
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


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
const int INF =  1000000010;
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

const int MN =  1e5+10,p = 13131,pp = 21313,ppp=756753,pppp=10007;
typedef unsigned long long lld;
set<lld> hash;set<int> s;
typedef set<int>::iterator iter;
lld mp[MN],room[MN];
int size[MN],bel[MN];
int n , m ,  q ; 

void Change(int i,int j)
{
 room[bel[i]] ^= mp[i];
 size[bel[i]]--;
 if(!hash.count(room[bel[i]])) s.insert(bel[i]);else s.erase(bel[i]);
 room[(bel[i] = j)] ^= mp[i];
 ++size[bel[i]];
 if(!hash.count(room[bel[i]]))s.insert(bel[i]); else s.erase(bel[i]);
}

int Qsum(int l,int r)
{
    int ans = 0;
    for(;;){
     iter it = s.lower_bound(l);
     if(it == s.end() || *it>r) break;
     int deb = *it;
     ans += size[*it];
     hash.insert(room[*it]);
     s.erase(it);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    srand(112);
    setIO("sample");
    n = gi; m = gi; q = gi;
    for(int i = 1;i<=n;++i) mp[i] = ((rand())*p+pp*(rand()+ppp))*pppp;
    size[1] = n;
    for(int i = 1;i<=n;++i) room[1] ^= mp[i],bel[i] = 1;
    s.insert(1);
    while(q--)
    {
     char opt[3];scanf("%s",opt);
     if(opt[0] == 'C'){
      int i = gi,j= gi;
      Change(i,j);
     }else {
      int l = gi,r = gi;
      printf("%d\n",Qsum(l,r));
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
