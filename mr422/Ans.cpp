#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n;
int u[210][210];
struct fg
{
 int c;
 int h[210];
 void a()
 {
  c=0;
  for(int i = 1;i<=n;i++)
   if(h[i] == 1)
    c++;
 }
 bool operator < (fg x) const
 {
 return c > x.c;
 }
};
fg o[210];
bool cover[210];
char inf[100],ouf[100];
int t = 0;
void dfs(int x,int y)
{
    if(o[y].h[x])
     return;
    o[y].h[x] = 1;
    for(int i = 1;i<=u[x][0];i++)
     dfs(u[x][i],y);
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    n = 0;
zero(u);
zero(o);
zero(cover);
t =0 ;
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr422.in%d",cani);
    sprintf(ouf,"mr422.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int x = 0;
     while(true)
     {
      scanf("%d",&x);
      if(x == 0)
       break;
      u[i][0]++;
      u[i][u[i][0]] = x;
     }
    }
    for(int i = 1;i<=n;i++){
     dfs(i,i);
     o[i].a();
    }
    sort(o+1,o+1+n);
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
     t += o[i].c;
     ans = i;
     if(t == n)
      break;
     for(int j = i+1;j<=n;j++){
      for(int k = 1;k<=n;k++)
       if(o[j].h[k] == o[i].h[k])
        o[j].h[k] = 0;
       o[j].a();
     }
     sort(o+i+1,o+1+n);
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
