#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef  long long int64;
const int64 y[] =
{ 6,2,5,5,4,5,6,3,7,5};
int64 n;
char c[100];
int64 get(int64 x)
{
 int64 m = 0,ret = 0;
 
 while(x != 0)
 {
 m++;
 int u = x%10;
 ret += y[u];
 x/=10;
 }
 ret += y[0]*(n-m);
 return ret;
}

int64 pow(int64 x)
{
      int64 ret = 1;
      for(int i = 1;i<=x;i++)
       ret*=10;
      return ret;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
//for(int cani = 0;cani<=9;cani++){
    
   // zero(inf);
   // zero(ouf);
    sprintf(inf,"mr408.in");
    sprintf(ouf,"mr408.ou");
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d\n",&n);
    int64 p = 0;
    scanf("%s",&c[1]);
    for(int64 i = 1;i<=n;i++)
     p*=10,p+=(c[i]-'0');
    int64 ans = 0;
    int64 m = get(p);
    int64 o = pow(n);
    for(ans = 1;ans<=o;ans++)
     if(m == get((p+ans)%o))
      break;
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
//}
    return EXIT_SUCCESS;
}
