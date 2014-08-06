#include <cstdlib>
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const int maxn = 1010,maxm = 64;
int mp[maxn][4];
int g[maxn][maxm];
int f[maxn][maxn][maxm];
int n,k;
vector<int> v;
int lb(int x)
{
 return (x&(-x));
}
int h(int x)
{
 int ret = 0;
 while(x > 0)
 {
  ret++;
  x-= lb(x);
 }
 return ret;
}
bool l(int x)
{
 bool tan[2][4]={0};
 for(int i = 0;i<6;i++)
  if((x & (1<<i)))
   tan[i/3][i%3+1] = 1;
 for(int i = 0;i<=1;i++)
  for(int j = 1;j<=3;j++)
   if(tan[i][j] == 1)
   {
    bool tp = true;
    if(j+1 <= 3 && tan[i][j+1])
     tp = false;
    if(j-1 >= 1 && tan[i][j-1])
     tp = false;
    if(i+1 <= 1 && tan[i+1][j])
     tp = false;
    if(i-1 >= 0 && tan[i-1][j])
     tp = false;
    if(tp)
     return false;
   }
  return true;
}
int main(int argc, char *argv[])
{
    freopen("domine.in","r",stdin);
    freopen("domine.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=3;j++)
      scanf("%d",&mp[i][j]);
    for(int i = 0;i<maxm;i++)
     if(h(i) == 2 && l(i)==1)
      v.pb(i);
    for(int i = 1;i<=n;i++)
     for(int j = 0;j<v.size();j++)
     {
      int x = v[j];
      for(int k = 0;k<6;k++)
       if((x & (1<<k))){
       g[i][x] += mp[i+k/3][k%3+1];
       if(i+k/3 > n){g[i][x] = 0;break;}
       }
     }
    for(int i = 1;i<=n;i++)
     for(int j = 0;j<=k;j++)
      for(int p = 0;p<maxm;p++){
       for(int o = 0;o<v.size();o++)
        if((v[o]&p) == 0)
         f[i][j+1][p|v[o]] = max(f[i][j][p]+g[i][v[o]],f[i][j+1][p|v[o]]);
     f[i+1][j][p>>3] = max(f[i+1][j][p>>3],f[i][j][p]);
     }
    int ans = 0;
    for(int i = 0;i<=maxm;i++)
     ans = max(f[n][k][i],ans);
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
