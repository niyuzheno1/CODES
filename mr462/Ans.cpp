#include <cstdlib>
#include <iostream>

using namespace std;
int n;
int p[102];
int a[51];
int b[51];
bool m;
char inf[101],ouf[101];
void pa()
{
     for(int i = 1;i<=n-1;i++)
      printf("%d ",b[i]);
     printf("%d\n",b[n]);
     m = true;
}
void dfs(int x)
{
    if(x == n+1 )
    {
     if(p[b[n]+b[1]])
      pa();
     return;
    }
    for(int i = 1;i<=n;i++)
     if(a[i] == 0 && (p[b[x-1]+i]==1 || x-1==0))
     {
      a[i] = 1;
      b[x] = i;
      dfs(x+1);
      if(m)
       break;
      a[i] = 0;
     }
     return;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    n=m=0;
    memset(p,0,sizeof(p));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr462.in%d",cani);
    sprintf(ouf,"mr462.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);   
    scanf("%d",&n);
    if(n%2 == 1)
    printf("NONE");
    else{
    for(int i = 2;i<=2*n-1;i++)
     p[i] = 1;
    for(int i = 2;i<=2*n-1;i++)
     if(p[i])
     {
      for(int j = 2;j<=2*n-1;j++)
       if(i*j <= 2*n-1)
           p[i*j] = 0;
       else
           break;
     }
     dfs(1);
     }
    fclose(stdin);fclose(stdout);
}
system("PAUSE");
    
    return EXIT_SUCCESS;
}
