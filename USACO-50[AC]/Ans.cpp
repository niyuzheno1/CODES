#include <cstdlib>
#include <iostream>

using namespace std;
int s,d,m;
int P[12][52];
int h[5000005];
int main(int argc, char *argv[])
{
    freopen("stock.in","r",stdin);
    freopen("stock.out","w",stdout);
    scanf("%d%d%d",&s,&d,&m);
    for(int i = 1;i<=s;i++){
     for(int j = 1;j<=d;j++){
      scanf("%d",&P[j][i]);
      }
     }
    int o = 2;
    while(o<=d)
    {
     for(int u = 0;u<=m;u++)
      h[u] = u;
     for(int v = 1;v<=s;v++)
     {
      int pre = P[o-1][v];
      int nex = P[o][v];
      for(int k = pre;k<=m;k++)
      {
	   
       h[k] = max(h[k],h[k-pre]+nex);
      }
     }
     m = h[m];o++;
    }
    printf("%d\n",m);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
