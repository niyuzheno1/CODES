#include <cstdlib>
#include <iostream>

using namespace std;
struct s
{
 int tx,ty,sx,sy;
};
struct p
{
int x,y;
};
int n,k,ans;
p d[51];
s m[5];
void dfs(int x)
{
  int S = 0;
  for(int i = 1;i<=k;i++)
  if(m[i].tx != -1){
   S = S + (m[i].tx-m[i].sx)*(m[i].ty-m[i].sy);
   for(int j = i+1;j<=k;j++)
    if(m[j].tx != -1)
     if(m[j].sx <= m[i].tx && m[i].sx<= m[j].tx && m[j].sy <= m[i].ty && m[i].sy <= m[j].ty)
      return;
  }
  if(S > ans)
   return;
  if(x > n)
   {
   ans = min(ans,S);
   return;
   }
  for(int i = 1;i<=k;i++)
  {
   s t;
   t = m[i];
   m[i].sx = min(m[i].sx,d[x].x);
   m[i].sy = min(m[i].sy,d[x].y);
   m[i].tx = max(m[i].tx,d[x].x);
   m[i].ty = max(m[i].ty,d[x].y);
   dfs(x+1);
   m[i] = t;
   if(m[i].tx<0)
    break;
  }
}
char inf[10],ouf[10];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr403.in%d",cani);
    sprintf(ouf,"mr403.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(d,0,sizeof(d));
    memset(m,0,sizeof(m));
    n = k = ans = 0;
    ans = 10000000;
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d %d",&d[i].x,&d[i].y);
    for(int i = 1;i<=k;i++)
     m[i].tx = m[i].ty = -1,m[i].sx = m[i].sy = 501; 
    dfs(1);
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
}

    return EXIT_SUCCESS;
}
