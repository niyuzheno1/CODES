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
const int INF =  1000000010;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
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

const char ans[] = {'A','B','C','D'};
string str[4];
int main(int argc, char *argv[])
{
    setIO("sample");
    cin>>str[0]>>str[1]>>str[2]>>str[3];
    for(int i = 0;i<=3;i++)
    {
     int len1 = str[i].length()-2;
     int a1 = 1,a2 = 1;
     for(int j = 0;j<=3;j++)
      if(i != j)
      {
       int len2 = str[j].length()-2;
       if(len2 >= len1 *2)
        a2 = 0;
       else if(len2*2 <= len1)
        a1 = 0;
       else
        a1 = 0,a2 = 0;
      }
     if(a1 || a2)
     {
      printf("%c\n",ans[i]);
      return 0;
     }
    }
    printf("C\n");
    closeIO();
    return EXIT_SUCCESS;
}
