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

const int MN = 2010;
int test,n;
char s[MN];
int top[MN],temp[MN],sa[MN],rank[MN],height[MN];
void Make()
{
 CLEAR(top,0);
 int m = n<256?256:n;
 for(int i = 0;i<n;++i) ++top[rank[i]=s[i]&0xff];
 for(int i = 1;i<m;++i) top[i] += top[i-1];
 for(int i = 0;i<n;++i) sa[--top[rank[i]]] = i;
 for(int len = 1;len<n;len*=2)
 {
 int j;
  for(int i = 0;i<n;++i)
  {
  j = sa[i]-len;
  if(j < 0) j+= n;
  temp[top[rank[j]]++] = j;
  }
  sa[temp[top[0]=0]]=j=0;
  for(int i = 1;i<n;++i)
  {
   if(rank[temp[i]] != rank[temp[i-1]] || rank[temp[i]+len] != rank[temp[i-1]+len])
    top[++j] = i;
   sa[temp[i]] = j;
  }
  memcpy(rank,sa,sizeof(sa));
  memcpy(sa,temp,sizeof(sa));
  if(j>n-1) break;
 }
}

void Lcp()
{
 int i,k;
 for(int j = rank[height[i=k=0]];i<n-1;++i,++k)
  while(k >= 0 && s[i] != s[sa[j-1]+k])
   height[j] = k--,j=rank[sa[j]+1];
}

void Solve()
{
 int sum = n-sa[1]-1;
  for(int i = 2;i<n;++i)
   sum += n-sa[i]-1-height[i];
 printf("%d\n",sum);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int test = gi;
    while(test--)
    {
     scanf("%s",s);
     n = strlen(s);
     s[n++] = '$';
     Make();Lcp();Solve();
    }
    closeIO();
    return EXIT_SUCCESS;
}
