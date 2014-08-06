#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n,m;
int a[210],b[210],p[210][210];
bool pow(int x)
{
     while(x != 0)
     {
      if(x%2 == 0)
       return false;
      x/=2;
     }
     return true;
}
bool check(int a,int b)
{
     int va[100],vb[100];
     memset(va,0,sizeof(va));
     memset(vb,0,sizeof(vb));
     while(a > 0)
     {
      va[0]++;
      va[va[0]] = a%2;
      a/=2;
     }
     while(b > 0)
     {
      vb[0]++;
      vb[vb[0]] = b%2;
      b/=2;
     }
     for(int i = max(va[0],vb[0]);i>=1;i--)
      if(va[i] == vb[i])
       return false;
     return true;
}
int c[210],v[210];
bool dfs(int x)
{
     if(x == 0)
      return true;
     bool flag = false;
     for(int i = 1;i<=m;i++)
      if(!v[i] && p[x][i])
      {
       v[i] = true;
       if(c[i] == 0 || dfs(c[i]))
       {
       c[i] = x;
       return true;
       
       }
      }
     return false;
}

char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    zero(a);
    zero(v);
    zero(b);
    zero(p);
    zero(c);
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr410.in%d",cani);
    sprintf(ouf,"mr410.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=m;i++)
     scanf("%d",&b[i]);
    for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       if(check(a[i],b[j]))
        p[i][j] = 1;
   //for(int i = 1;i<=n;i++){
    //  for(int j = 1;j<=m;j++)
    //   printf("%d ",p[i][j]);
    // printf("\n");
   // }
   // for(int i = 1;i<=n;i++){
   //   for(int j = 1;j<=m;j++)
   //    printf("%d ",p[i][j]);
   //  printf("\n");
   // }
    for(int i = 1;i<=n;i++){
    zero(v);
     if(dfs(i)){
     // printf("%d\n",i);
     ans++;
     }
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
