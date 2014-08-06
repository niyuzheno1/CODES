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
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
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

#define pb push_back
const double eps = 10e-5;
int dblcmp(double x){
 if(abs(x) < eps) return 0;
 if(x > 0) return 1;
 else return -1;
}
int n;
const int MN = 10010;
typedef double ld;
typedef pair<ld,ld> pdd;
pdd a[MN];
int stk[MN],top,sou[MN];
vector<int> ans;
bool cmp1(pdd x,pdd y)
{
     if(dblcmp(x.X-y.X) == 0) return dblcmp(x.Y-y.Y) > 0;
     return  dblcmp(x.X-y.X) < 0;
}
bool cmp2(int x,int y)
{
     return cmp1(a[x],a[y]);
}

double getv(int li,ld x)
{
 return a[li].X*x+a[li].Y;
}
pdd inser(int li1,int li2)
{
  double dk = a[li1].X-a[li2].X;
  double db = a[li2].Y-a[li1].Y;
  double x = db/dk; 
  return MP(x,getv(li1,x));
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i) a[i].Y = gi,sou[i] = i;
    for(int i = 1;i<=n;++i) a[i].X = gi;
    sort(sou+1,sou+1+n,cmp2);
    sort(a+1,a+n+1,cmp1);
    stk[++top] = 1;
    for(int i = 2;i<=n;++i)
    {
      if(dblcmp(a[stk[top]].X-a[i].X) == 0) continue;
      while(top)
      {
       pdd pu = inser(stk[top],i);
       if(pu.X<0) --top;
       else if(top >= 2 && pu.Y<getv(stk[top-1],pu.X)) --top;
       else break;
      }
      stk[++top] = i;
    }
    for(int i = 1;i<=top;++i)
    {
     int x = stk[i];
     for(int j = x;j<=n;++j)
      if(dblcmp(a[j].X - a[x].X) != 0 || dblcmp(a[j].Y - a[x].Y) != 0)
       break;
      else
       ans.pb(sou[j]);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i = 0;i<ans.size()-1;++i)
     printf("%d ",ans[i]);
    printf("%d\n",ans[ans.size()-1]);
    closeIO();
    return EXIT_SUCCESS;
}
