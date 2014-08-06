#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
const int MAXN = 100010;
int mod = 10301;
int a[MAXN],b[MAXN];
int n,m;
int main(int argc, char *argv[])
{
    freopen("tsinsenD5530.in","r",stdin);
    freopen("tsinsenD5530.ans","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
     scanf("%d%d",&a[i],&b[i]);
     a[i]%=10301;b[i]%=10301;
    }
    for(int i = 1;i<=m;i++){
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     if(x == 1)
      for(int j = y;j<=z;j++){
       a[j] += b[j];
       a[j] %= mod;
      }
     if(x == 2)
      for(int j = y;j<=z;j++){
       b[j] += a[j];
       b[j] %= mod;
      }
     if(x == 3){
      int ret = 0;
      for(int j = y;j<=z;j++){
       ret += a[j]*b[j];
       ret %= mod;
      }
      printf("%d\n",ret);
     }
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
