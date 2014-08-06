#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#define ff fprintf
#define X first
#define lc(y) (2*(y-1))
#define uc(y) (2*(y))
#define urc(y) (2*(y+1))
using namespace std;
typedef map<int,int> mpii;
typedef mpii::iterator it;
const string tab = "*()";
int n,m,ans;
FILE * d;
mpii f[13][13];
void undo(int & x,int y,int p,int q,int g)
{
  x ^=(p<<uc(y));x ^=(q<<lc(y));
  x ^=(g<<urc(y));
}
void resp(int x,int y,int z,int a)
{
 if(y == m){
   a<<=2;
   f[x+1][1][a] += f[x][y][z];
 }
 else
   f[x][y+1][a] += f[x][y][z];
}
char mp[13][13];
void decode(int x)
{
 for(int i = 0;i<=m;i++){
  int u = i;
  int v = (x>>(2*i))%4;
  ff(d,"%c",tab[v]);
 }
 ff(d,"\n");
}
void tran(int x,int y,int z)
{
 int p = (z>>uc(y))%4;
 int q = (z>>lc(y))%4;
 int g = (z>>urc(y))%4;
 int nw=0;
 if(mp[x][y] == '*' && p != 0 && q != 0)
  return;
 if(mp[x][y] == '*')
 {
  resp(x,y,z,z);
 }else{
 if(p == 0 && q == 0)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,2,1,g);
  resp(x,y,z,nw);
 }
 if(p == 0 && q == 2 && y != m)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,q,0,g);
  resp(x,y,z,nw);
 }
 if(p == 1 && q == 1)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,0,0,1);
  resp(x,y,z,nw);
 }
 if(q == 2 && p == 1)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,0,0,g);
  resp(x,y,z,nw);
 }
 if(q == 1&& p == 2)
 {
  if(x == n && y == m){
   int nw = z;
   undo(nw,y,p,q,0);
   if(nw == 0)
    ans += f[x][y][z];
  }
 }
 if((q == 0 && p != 0) || (p == 0&&q!=0))
 {
  nw = z;
  resp(x,y,z,nw);
 }
 }
}

int main(int argc, char *argv[])
{
    freopen("ural1519.in","r",stdin);
    freopen("ural1519.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%s",&mp[i][1]);
    f[1][1][0] = 1;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
     {
      for(it l = f[i][j].begin();l != f[i][j].end();l++)
      {
       int k = (*l).X;
       tran(i,j,k);
      }
     }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
     {
     ff(d,"i:%d j:%d :\n",i,j);
      for(it l = f[i][j].begin();l != f[i][j].end();l++)
      {
       int k = (*l).X;
       decode(k);
      }
     }
    printf("%d\n",ans);
    fclose(d);fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
