#include <cstdlib>
#include <iostream>

using namespace std;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int n;
struct pp
{
 int x,y;
};
pp p[101];
int f[101];
pp po[101][5];
int gf(int x)
{
    if(f[x] == x)
     return x;
    return f[x]=gf(f[x]);
}
void un(int x,int y)
{
     f[gf(x)] = f[gf(y)];
}
bool u(int x,int y,int t)
{
     if(abs(p[x].x-p[y].x)+abs(p[x].y-p[y].y) <= 2 * t)
      return true;
     
     return false;
}
bool ok(int x)
{
 for(int i = 1;i<=n;i++)
  f[i] = i;
 memset(&po,0,sizeof(po));
 for(int i = 1;i<=n;i++)
  for(int j = 0;j<=3;j++){
   po[i][j].x = dx[j]*x+p[i].x;
   po[i][j].y = dy[j]*x+p[i].y;
  }
 for(int i = 1;i<=n;i++)
  for(int j = i+1;j<=n;j++){
   bool flag = false;
     if(u(i,j,x))
      flag = true;
   if(flag)
    un(i,j);
  }
  for(int i = 1;i<=n;i++)
   if(gf(i) != gf(1))
    return false;
  return true;
}
int main(int argc, char *argv[])
{
    freopen("ppg1.in","r",stdin);
    freopen("ppg1.out","w",stdout);
    
    int l = 0,r = 100;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%d%d",&p[i].x,&p[i].y);
     r = max(r,p[i].y);
    }
    while(l<r)
    {
     int mid = (l+r)/2;
     if(ok(mid))
      r = mid;
     else
      l = mid+1;
    }
    printf("%d",(l+r)/2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
