#include <cstdlib>
#include <iostream>
#define rep(i,f,n) for(int i = f;i<=n;i++)
using namespace std;
bool up[101][101],down[101][101];
int lup[101][101],ldown[101][101];
int n,m,a,b,maxx;
void get_len()
{
     memset(lup,0,sizeof(lup));
     memset(ldown,0,sizeof(ldown));
     rep(i,1,n)
      if(up[n][i])
       lup[n][i] = 1;
      else
       lup[n][i] = 0;
     for(int i = n-1;i>=1;i--)
      rep(j,1,i)
      {
       if(up[i][j] && down[i+1][j])
        lup[i][j] = min(lup[i+1][j],lup[i+1][j+1])+1;
       else
        if(up[i][j])
         lup[i][j] = 1;
       if((j == 1 || j == i-1)&&down[i][j])
        ldown[i][j] = 1;
      }
      rep(i,2,3)
       rep(j,1,2)
        if(down[i][j])
         ldown[i][j] = 1;
      rep(i,4,n)
       rep(j,2,n-2)
       {
        if(down[i][j] && up[i-1][j])
         ldown[i][j] = min(ldown[i-1][j],ldown[i-1][j-1])+1;
        else
         if(down[i][j]) 
          ldown[i][j] = 1;
       }
}
void maina()
{
     rep(i,1,n-1)
     {
      int x = 0,y=0;
      rep(j,1,i)
       rep(k,1,j)
       {
       if(min(lup[j][k],i-j)>x)
       x = min(lup[j][k],i-j);
       if(j != k && ldown[j][k] > x)
        x= ldown[j][k];
       }
      if(x == 0)continue;
      rep(j,i+1,n)
       rep(k,1,j)
       {
        if(lup[j][k] > y)
         y = lup[j][k];
        if(min(j-i,ldown[j][k])>y)
         y = min(j-i,ldown[j][k]);
       }
      if(y == 0)continue;
      if(x*x+y*y > maxx)
       maxx = x*x+y*y;
     }
}
void trun()
{
     int up0[101][101],down0[101][101];
     memcpy(up0,up,sizeof(up0));
     memcpy(down0,down,sizeof(down0));
     memset(up,1,sizeof(up));
     memset(down,1,sizeof(down));
     for(int x = 1;x<=n;x++)
      for(int y = 1;y<=x;y++)
      {
      int xx = n-y+1,yy=x-(n-xx);
      up[xx][yy] = up0[x][y];
      if(y != x){
       yy = yy-1;
       down[xx][yy]=down0[x][y];
       }
      }
}
int main()
{
    memset(up,1,sizeof(up));
    scanf("%d%d",&m,&n);
    memset(down,1,sizeof(down));
    rep(i,1,n)
    {
     scanf("%d%d",&a,&b);
     if(b % 2 == 1)
      up[a][(b+1)/2] = false;
     else
      down[a][b/2] = false;
    }
    swap(m,n);
    rep(i,1,2)
    {
     get_len();
     maina();
     trun();
    }
    get_len();
    maina();
    printf("%d",maxx);
    return 0;
}
