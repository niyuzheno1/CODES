#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#define X first
#define Y second
#define ff fprintf
using namespace std;
const int maxn = 110,maxm = 11;
typedef pair<int,int> pii;
typedef map<int,int> mpii;
typedef mpii::iterator ite;
mpii f[maxn][maxm];
FILE * d;
char s[maxn][maxm];
int mod,n,m;
int ans = 0;
pii nxt(int x,int y)
{
 if(y == m)
  return pii(x+1,1);
 else
  return pii(x,y+1);
}
void tran(int x,int y,int z)
{
 int flag = 0,nw = z;
 pii v = nxt(x,y);
 if(v.Y > 1 && (z&1))
  flag = 1;
 if(v.Y > 2 && (z&2))
  flag = 1;
 if((z & (1<<(m-1))))
  flag = 1;
 if((z & (1<<(2*m-1))))
  flag = 1;
 if(s[v.X][v.Y] == 'H')
  flag = 1;
 if(!flag)
 {
  nw = z;nw<<=1;nw%=mod;
  nw|=1;
  //ff(d,"%d\n",nw);
  f[v.X][v.Y][nw] = max(f[v.X][v.Y][nw],f[x][y][z]+1);
  if(v.X == n && v.Y == m)
  ans = max(f[v.X][v.Y][nw],ans);
 }
 nw = z;nw<<=1;nw%=mod;
 //ff(d,"%d\n",nw);
 f[v.X][v.Y][nw] = max(f[v.X][v.Y][nw],f[x][y][z]);
 if(v.X == n && v.Y == m)
  ans = max(f[v.X][v.Y][nw],ans);
}
int q[maxn][maxm];
pii pre(int x,int y)
{
  if(y == 1)
   return pii(x-1,m);
  else
   return pii(x,y-1);
}
void decode(int x,int y,int z)
{
  for(pii i = pii(x,y);i != pre(x-2,y);i = pre(i.X,i.Y))
  {
   
   q[i.X][i.Y] = (z&1);
   z>>=1;
   if(i.X == 1 && i.Y == 1)
    break;
  }
  ff(d,"from:(%d,%d) to:(%d,%d)\n",x-2,1,x,m);
  for(int i = x-2;i<=x;i++){
   for(int j = 1;j<=m;j++)
    if(i < 0)
    ff(d,"0 ");
    else
    ff(d,"%d ",q[i][j]);
   ff(d,"\n");
  }
}
int main(int argc, char *argv[])
{
    freopen("cannon.in","r",stdin);
    freopen("cannon.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%d%d",&n,&m);
    mod = (1<<(2*m+1));
    for(int i = 1;i<=n;i++)
     scanf("%s",&s[i][1]);
    tran(0,m,0);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      for(ite e=f[i][j].begin();e != f[i][j].end();e++)
      {
       int u = (*e).X;
       tran(i,j,u);
      }
    
    printf("%d\n",ans);
    fclose(d);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
