#include <cstdlib>
#include <iostream>

using namespace std;
int n,t;
int v[110];
int c[110][110];
int f[20010];
const int bound = 20000;
void a(int x,int y)
{
 int u = 1;
 while(x > u)
 {
  c[y][0]++;
  c[y][c[y][0]] = u;
  x -= u;
  u<<=1;
 }
 if(x == 0)
  return;
 c[y][0]++;
 c[y][c[y][0]] = x;
}
int main(int argc, char *argv[])
{
    freopen("fewcoins.in","r",stdin);
    freopen("fewcoins.out","w",stdout);
    scanf("%d%d",&n,&t);
    for(int i = 1;i<=n;i++)
     scanf("%d",&v[i]);
    for(int i = 1;i<=n;i++)
    {
     int x;
     scanf("%d",&x);
     a(x,i);
    }
    memset(f,0x7f,sizeof(f));
    f[0] = 0;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=c[i][0];j++)
      for(int o = bound-v[i]*c[i][j];o>=0;o--)
       f[o+v[i]*c[i][j]] = min(f[o+v[i]*c[i][j]],f[o]+c[i][j]);
    for(int i = 1;i<=n;i++)
     for(int o = bound-v[i];o>=0;o--)
      f[o] = min(f[o],f[o+v[i]]+1);
    printf("%d\n",f[t]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
