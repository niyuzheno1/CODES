#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 0x7f7f7f7f;
int n,m;
int f[17][17];
int u[17][17];
int ans[17][17],sp[17][17];
int d;
void c(int x,int y)
{
   u[x][y] = !u[x][y];
   u[x+1][y] = !u[x+1][y];
   u[x-1][y] = !u[x-1][y];
   u[x][y+1] = !u[x][y+1];
   u[x][y-1] = !u[x][y-1];
}
bool cl()
{
     bool ret = true;
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       if(u[i][j])
        ret= false;
     return ret;
}
int a()
{
    int ret = 0;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
     ret += sp[i][j];
    return ret;
}
void so()
{
     memcpy(u,f,sizeof(u));
     
     for(int i = 1;i<=n;i++)
      if(sp[i][1])
       c(i,1);
     for(int i = 2;i<=m;i++)
      for(int j = 1;j<=n;j++)
       if(u[j][i-1]){
        sp[j][i] = 1;
        c(j,i);
       }else
        sp[j][i] = 0;
     int cle = cl();
     if(cle)
     {
      int de = a();
      if(de < d){
       d = de;
       memcpy(ans,sp,sizeof(ans));
      }
     }
}
int main(int argc, char *argv[])
{
    freopen("fliptile.in","r",stdin);
    freopen("fliptile.out","w",stdout);
    d = inf;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&f[i][j]);
    
    while(true)
    {
     sp[n][1]++;
     for(int i = n;i>=1;i--)
      if(sp[i][1] > 1)
       sp[i][1]-=2,sp[i-1][1]+=1;
     so();
     if(sp[0][1] > 0)
      break;
    }
    
    if(d != inf)
    {
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       printf("%d%c",ans[i][j],(j==m)? '\n' : ' ' );
    }
    else
     printf("IMPOSSIBLE\n");
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
