#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#define X first
#define Y second
using namespace std;
typedef long long int64;
typedef pair<int,int> p;
int64 m,n,sx,sy,ex,ey;
int64 dx[9],dy[9],t;
int64 mp[32][32];
int64 f[31][31][31][31];
queue<p> q;
int64 d[31][31];
int64 s[31][31];
int main(int argc, char *argv[])
{
    freopen("lilypad.in","r",stdin);
    freopen("lilypad.out","w",stdout);
    memset(&d,0x7f,sizeof(d));
    t = 0;
    for(int64 i = -2;i<=2;i++)
     for(int64 j = -2;j<=2;j++)
      if(abs(i)+abs(j) == 3){
       t++;
       dx[t] = i,dy[t] = j;
      }
    scanf("%I64d%I64d",&m,&n);
    for(int64 i = 1;i<=m;i++)
     for(int64 j = 1;j<=n;j++){
      scanf("%I64d",&mp[i][j]);
      if(mp[i][j] == 3)
       sx = i,sy = j,mp[i][j] = 0;
      else if(mp[i][j] == 4)
       ex = i,ey = j,mp[i][j] = 0;
     }
    for(int64 i = 1;i<=m;i++)
     for(int64 j = 1;j<=n;j++)
      if(mp[i][j] == 0)
      {
       q.push(p(i,j));
       f[i][j][i][j] = 1;
       while(!q.empty())
       {
       int64 x = q.front().X;int64 y = q.front().Y; 
       q.pop();
       for(int64 k = 1;k<=8;k++)
        if(x+dx[k]<=m && x+dx[k]>=1 && y+dy[k]<=n&&y+dy[k] >= 1 && f[i][j][x+dx[k]][y+dy[k]] == 0 && mp[x+dx[k]][y+dy[k]] == 1)
        {
         f[i][j][x+dx[k]][y+dy[k]] = 1;
         q.push(p(x+dx[k],y+dy[k]));
        }
       }
       for(int64 x = 1;x<=m;x++)
        for(int64 y = 1;y<=n;y++)
         if(f[i][j][x][y] == 1)
         {
          for(int64 k = 1;k<=8;k++)
          if(x+dx[k]<=m && x+dx[k]>=1 && y+dy[k]<=n&&y+dy[k] >= 1 && f[i][j][x+dx[k]][y+dy[k]] == 0 && mp[x+dx[k]][y+dy[k]] == 0)
           f[i][j][x+dx[k]][y+dy[k]] =2 ;
         }
      }
     q.push(p(sx,sy));
     s[sx][sy] = 1;
     d[sx][sy] = 0;
     while(!q.empty())
     {
      int64 x = q.front().X;
      int64 y = q.front().Y;
      q.pop();
      for(int64 i = 1;i<=m;i++)
       for(int64 j = 1;j<=n;j++)
        if(f[x][y][i][j] == 2)
        {
         if(d[i][j] > d[x][y] + 1)
         {
          d[i][j] = d[x][y] + 1;
          s[i][j] = s[x][y];
          q.push(p(i,j));
         }
         else if(d[i][j] == d[x][y] + 1)
          s[i][j] += s[x][y];
        }
     }
    if(d[ex][ey] != d[0][0])
    printf("%I64d\n%I64d\n",d[ex][ey]-1,s[ex][ey]);
    else
    printf("-1\n");
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
