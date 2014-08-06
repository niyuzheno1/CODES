#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
#define zero(a) memset(a,0,sizeof(a))
int n,m;
string str;
int g[101][101];
int f[256];
char inf[101],ouf[101];
int d1(string x)
{
    int pos = (x[0] == '-')?1:0;
    int m = 0;
    for(int i = pos;i<x.length();i++)
     if(x[i] <= '9' && x[i] >= '0'){
      m *= 10;
      m += x[i]-'0';
     }
     else
      return 0;
     
    return pos==1?-m:m;
}
int mx(string x)
{
    int ans = 0;
    memset(&f,0,sizeof(f));
    for(int i = 0;i<x.length();i++){
    f[i] = 1;
     for(int j = 0;j<i;j++)
      if(f[j] >= f[i] && x[j] < x[i])
      {
       f[i] = f[j]+1;
       ans = max(ans,f[i]);
      }
    }
    return ans;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
   
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr485.in%d",cani);
    sprintf(ouf,"mr485.ou%d",cani);
    ifstream cin(inf);
    ofstream cout(ouf);
    memset(&g,0x7f,sizeof(g));
    memset(&f,0,sizeof(f));
    str = "";
    cin>>n>>m;
    for(int i = 1;i<=m;i++)
    {
    int x,y;
    cin>>x>>y>>str;
     if(d1(str) != 0)
      g[y][x] = g[x][y] = d1(str);
     else if(str == "memory")
      g[y][x] = g[x][y] = 0;
     else if(str.find("memory") != -1)
      g[y][x] = g[x][y] = 1;
     else if(mx(str) > string("memory").length())
      g[y][x] = g[x][y] = 2;
     else
      g[y][x] = g[x][y] = str.length();
    }

    for(int k = 1;k<=n;k++)
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++)
      if(g[i][k] != 0x7f7f7f7f && g[k][j] != 0x7f7f7f7f){
       g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
       g[j][i] = g[i][j];
      }
    cout<<g[1][n];
   cin.close();cout.close();
}    
    return EXIT_SUCCESS;
}
