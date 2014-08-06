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

#define MN 510
char str[MN];
int k;
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%s",str+1);
    k = gi;
    int len = strlen(str+1),ans = 0;
    for(int i=1;i<=len-k+1;++i)
    {
     int l = len+1;
     for(int j = i;j<=i+k-1;++j) str[l] = str[j],++l;
     --l;
     for(int j = 1;j<=l;++j)
      for(int o = 1;o<=l;++o)
       if(j+o <= l)
       {
        int q = j+o;
        int flag= 1;
        for(int p = j;p<=j+o-1;++q,++p)
         if(str[p] != str[q])
          flag = 0;
        if(flag)
         ans =max(ans,o*2);
       }
    }
     if(len-k+1<=0) ans = ((len+k)/2)*2;
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
