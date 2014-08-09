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
typedef pair<int,int> _reserve_type_1;
typedef pair<int64,int64> pll;
#define pii _reserve_type_1
FILE * debug;
#define setIO _func_2_
void _func_2_(string file = "sample")
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

#define ERROR_FILE_END -1
#define FILEOF(X) func_1_(X)
int func_1_(FILE * X)
{
 int cur = ftell(X);
 fseek(X,0L,SEEK_END);
 int ret  = ftell(X);
 fseek(X,cur,SEEK_SET);
 return ret;
}
class iomgr{
 FILE * A;
 char * rb, * endb;
 int fl;
public:
 void setting(FILE * _A){
	 A = _A;fl = FILEOF(stdin);rb = new char[fl+3];fread(rb,1,fl,stdin);rb[fl] = -1;endb = rb+fl;
 }
 char exgetchar(){
	char ret = *rb; ++rb;
	return ret;
 }
 template <class T>
 void exread(T & x)
 {
  if(rb >= endb) return;
  char tmp = 0; T flag = 1,ret = 0;while(tmp != -1 && tmp != '-' && !isdigit(tmp)) tmp = exgetchar();
  if(tmp == -1) return;
  if(tmp == '-') flag = -1,tmp=exgetchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = exgetchar();
  x = flag *ret;
 }
 int64 exgetint()
 {
	int64 ret = ERROR_FILE_END;exread(ret);return ret;
 }
};
iomgr _global_reader_;
#undef setIO
void _func_3_(string file = "sample"){
 _func_2_(file);
 _global_reader_.setting(stdin);
}
#define setIO _func_3_
#undef gi
#define gi _global_reader_.exgetint()

int x,y,a,b;
int main(int argc, char *argv[])
{
    setIO("sample");
    x = gi,y = gi,a = gi,b = gi;
    int lcm = x;
    while(lcm % y) lcm += x;
    printf("%d",b/lcm - (a-1)/lcm);
    closeIO();
    return EXIT_SUCCESS;
}
