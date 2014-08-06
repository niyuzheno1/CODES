#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define X first
#define Y second
using namespace std;
const int maxn = 13;
typedef map<int,int> mu;
typedef mu::iterator ite;
char mp[maxn][maxn];
mu f[maxn][maxn];
int n,m;
const string s = "#()";
int lc(int y,int z)
{
 if(y == 1)
  return 0;
 else
  return (z>>(2*(y-1)))%4;
}
int llc(int y)
{
 if(y == 1)
  return 0;
 else
  return 2*(y-1);
}
int uc(int y,int z)
{
 return (z>>(2*(y)))%4;
}
int uuc(int y)
{
 return (2*(y));
}
void undo(int & x,int y,int p,int q)
{
 x ^= (p<<llc(y));
 x ^= (q<<uuc(y));
}
int findpre(int y,int x)
{
 while(y>=0)
 {
  if((x & (1<<y)))
   break;
  y-=2;
 }
 return y;
}
int findne(int y,int x)
{
 while(y<=2*m)
 {
  int u = 2<<y;
  if((x&u))
   break;
  y+=2;
 }
 return y;
}
char str[13];
void decode(int x)
{
 for(int i = 0,u=0;i<=m;i++)
  u = (x>>(2*i))%4,str[i] = s[u];
}
void pri()
{
 for(int i = 0;i<=m;i++)
  printf("%c",str[i]);
 printf("\n");
}
int ans;
void tran(int x,int y,int z)
{
 int p = lc(y,z),q = uc(y,z);
 int nx =0,ny = 0;
 if(y == m)
  nx = x+1,ny = 1;
 else
  nx = x,ny = y+1;
 if(mp[x][y] == '*')
 {
  if(p == 0 && q == 0)
   f[nx][ny][z] += f[x][y][z];
  return;
 }
 if((p==1 && q == 2) && x == n && y == m)
 {
  ans += f[x][y][z];
 }
 if(p==2&&q==1)
 {
  int u = z;
  undo(u,y,p,q);
  f[nx][ny][u] += f[x][y][z];
 }
 if(p==0&&q==0)
 {
  int u = z;
  if(y == 1)
  {
   u ^= 1;
   u ^= (2<<2);
  }
  else
  undo(u,y,1,2);
  f[nx][ny][u] += f[x][y][z];
 }
 if((p == 0 && q != 0)||(p != 0 && q == 0))
 {
  int u = z;
  f[nx][ny][u] += f[x][y][z];
  if(y != 1){
  undo(u,y,p,q);
  undo(u,y,q,p);
  f[nx][ny][u] += f[x][y][z];
  }
 }
 if(p == 2 && q == 2)
 {
  int u = z;
  undo(u,y,p,q);
  int v = findpre(2*(y-1),u);
  if(v < 0)
   return;
  u ^= (1<<v);
  u ^= (2<<v);
  f[nx][ny][u] += f[x][y][z];
 }
 if(p == 1 && q == 1)
 {
  int u = z;
  undo(u,y,p,q);
  int v = findne(2*(y+1),u);
  if(v > 2*m)
   return;
  u ^= (2<<v);
  u ^= (1<<v);
  f[nx][ny][u] += f[x][y][z];
 }
}
int main(int argc, char *argv[])
{
    freopen("ural1519.in","r",stdin);
    freopen("ural1519.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%s",&mp[i][1]);
    f[1][1][0] = 1;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      for(ite k = f[i][j].begin();k != f[i][j].end();k++)
      {
      int u = (*k).X;
      tran(i,j,u);
      }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++){
      printf("(%d,%d):\n",i,j);
      for(ite k = f[i][j].begin();k != f[i][j].end();k++)
      {
       decode((*k).X);
       pri();
      }
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
