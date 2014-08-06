#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define X first
#define Y second

using namespace std;
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};
int n,m;
typedef pair<int,int> p;
typedef pair<p,int> p2;
queue<p2> q;
int ex,ey,sx,sy;
int f[310][310];
char mp[310][310];
vector<p> v[27];

int main(int argc, char *argv[])
{
    freopen("cornmaze.in","r",stdin);
    freopen("cornmaze.out","w",stdout);
    memset(&f,0x7f,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i = 0;i<=301;i++)
     for(int j = 0;j<=301;j++)
      mp[i][j] = '#';
    for(int i = 1;i<=n;i++)
      scanf("%s",&mp[i][1]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      if(mp[i][j] == '=')
      {
       mp[i][j] = '.';
       ex = i;ey = j;
      }
      else if(mp[i][j] == '@')
      {
       mp[i][j] = '.';
       sx = i;sy = j;
      }
      else if(mp[i][j] <= 'Z' && mp[i][j] >= 'A')
       v[mp[i][j]-'A'].push_back(p(i,j));
    f[sx][sy] = 0;
    q.push(p2(p(sx,sy),0));
    while(!q.empty())
    {
     p2 u = q.front();q.pop();
     
     f[u.X.X][u.X.Y] = min(f[u.X.X][u.X.Y],u.Y);
      for(int i = 1;i<=4;i++)
      {
       int xx = u.X.X+dx[i];int yy = u.X.Y+dy[i];
       if(mp[xx][yy] != '#')
       {
        bool flag = 0;
        if(mp[xx][yy] <= 'Z' && mp[xx][yy] >= 'A')
         for(int i = 0;i<v[mp[xx][yy]-'A'].size();i++)
         {
          p ux = v[mp[xx][yy]-'A'][i];
          if(!(ux.X == xx && ux.Y == yy))
           if(f[ux.X][ux.Y] > u.Y+1){
           f[ux.X][ux.Y] = u.Y+1;
           q.push(p2(p(ux.X,ux.Y),u.Y+1));
           }
         }
        else
          if(f[xx][yy] > u.Y +1){
          f[xx][yy] = u.Y +1;
          q.push(p2(p(xx,yy),u.Y+1));
          }
        
       }
      }
    }
    printf("%d\n",f[ex][ey]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
