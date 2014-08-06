#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef map<int,int> mp;
int n,sumb = 0;
struct pp
{
 int b,c;
 bool operator < (pp x) const
 {
  return b > x.b;
 }
};
pp a[61*3];
mp f[61*2][61*2];
mp g[61*2][61*2];
vector<int> va,vb;
FILE * ferr;
void dfs(int x,int y,int z)
{
 if(x == 0)
 {
  for(int i = 0;i<va.size();i++)
   printf("%d\n",va[i]);
  for(int i = 0;i<vb.size();i++)
   printf("%d\n",vb[i]);
  return;
 }
 fprintf(ferr,"%d\n",z);
 if(f[x-1][y][z] == 1)
 {
  va.push_back(a[x].c);
  dfs(x-1,y,z);
 }
 else
 {
  vb.push_back(a[x].c);
  dfs(x-1,y-1,z-a[x].b);
 }
 
}
int main(int argc, char *argv[])
{
    ferr = fopen("err2.out","w");
    freopen("jpol.in","r",stdin);
    freopen("jpol.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=3*n;i++)
     scanf("%d",&a[i].b),a[i].c = i;
    sort(a+1,a+1+3*n);
    for(int i = 2*n+1;i<=3*n;i++)
     printf("%d\n",a[i].c);
    for(int i = 1;i<=2*n;i++)
     sumb += a[i].b;
    f[0][0][0] = 1;
    for(int i = 0;i<=2*n-1;i++)
     for(int j = 0;j<=n;j++)
      for(mp::iterator it = f[i][j].begin();it != f[i][j].end();it++)
      {
      int u = (*it).X;
      f[i+1][j][u] = 1;
      f[i+1][j+1][u+a[i+1].b] = 1;
      g[i+1][j+1][u+a[i+1].b] = 1;
      }
    fprintf(ferr,"%d",f[23][8][5285]);
    for(mp::iterator it = f[2*n][n].begin();it != f[2*n][n].end();it++)
    {
    int u = (*it).X;
    if(sumb-u > 500*n && u > 500*n){
     dfs(2*n,n,u);
     break;
     }
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
