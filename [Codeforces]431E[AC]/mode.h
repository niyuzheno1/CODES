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
