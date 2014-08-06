#include <cstdlib>
#include <iostream>

using namespace std;
int c[10],tot;
int b[10];
int now[10];
int f[310];
struct px
{
 int x,y,z;
 bool operator < (px a) const
 {
  if(x == a.x)
  {
   if(y == a.y)
    return z > a.z;
   return y > a.y;
  }
  return x > a.x;
 }
}p[300];
void dfs(int x)
{
 if(x == 4)
 {
  tot++;
  p[tot].x = now[b[1]];
  p[tot].y = now[b[2]];
  p[tot].z = now[b[3]];
  return;
 }
 for(int i = 1;i<=3;i++)
 if(!c[i]){
  c[i] = 1;
  b[x] = i;
  dfs(x+1);
  b[x] = 0;
  c[i] = 0;
 }
}
int n,ca;
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
    for(int cani = 0;cani<=4;cani++){
    ca = 0;
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr431.in%d",cani);
    sprintf(ouf,"mr431.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout); 
    while(true)
    {
     ca++;
     scanf("%d",&n);
     if(n==0)
      break;
     tot = 0;
     for(int i = 1;i<=n;i++)
     {
      for(int j = 1;j<=3;j++)
       scanf("%d",&now[j]);
      dfs(1);
     }
     sort(p+1,p+1+tot);
     int ans = 0;
     for(int i = 1;i<=tot;i++)
      f[i] = p[i].z;
     for(int i = 1;i<=tot;i++){
      for(int j = 1;j<i;j++)
       if(p[i].x < p[j].x && p[i].y < p[j].y)
       f[i] = max(f[i],f[j]+p[i].z);
      ans = max(ans,f[i]);
     }
     printf("Case %d:maximum height=%d\n",ca,ans);
    }
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
