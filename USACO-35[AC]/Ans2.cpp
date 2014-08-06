#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
vector<p> v[265];
int r,c;
bool us[110];
char as[11][11][5];
char s[11][11][5];
char u[110][5];
int g1(int x)
{return (x+1)%4 == 0 ? 4 : (x+1)%4;}
int g2(int x)
{return (x+2)%4 == 0 ? 4 : (x+2)%4;}
int g3(int x)
{return (x+3)%4 == 0 ? 4 : (x+3)%4;}
void dfs(int x,int y)
{
    if(x > r)
    {
     for(int i = 1;i<=r;i++)
      for(int j = 1;j<=c;j++)
       if(as[i][j][0] < s[i][j][0])
        return;
       else if(as[i][j][0] > s[i][j][0])
        break;
     for(int i = 1;i<=r;i++)
      for(int j = 1;j<=c;j++)
       for(int k = 0;k<=4;k++)
       as[i][j][k] = s[i][j][k];
     return;
    }
    if(y > c)
    {
     dfs(x+1,1);
     return;
    }
    int pm = s[x][y-1][2];
    for(int i = 0;i<v[pm].size();i++)
    if(!us[v[pm][i].X])
    {
     if(s[x-1][y][3] == u[v[pm][i].X][g1(v[pm][i].Y)])
     {
       if(y == c && u[v[pm][i].X][g2(v[pm][i].Y)] != '0')
        continue;
       if(x == r && u[v[pm][i].X][g3(v[pm][i].Y)] != '0')
        continue;
       us[v[pm][i].X] = 1;
       s[x][y][0] = v[pm][i].X;
       s[x][y][1] = u[v[pm][i].X][g1(v[pm][i].Y)];
       s[x][y][2] = u[v[pm][i].X][g2(v[pm][i].Y)];
       s[x][y][3] = u[v[pm][i].X][g3(v[pm][i].Y)];
       s[x][y][4] = u[v[pm][i].X][(v[pm][i].Y)];
       dfs(x,y+1);
       s[x][y][0] = s[x][y][1] = s[x][y][2] = s[x][y][3] =s[x][y][4] = 0;
       us[v[pm][i].X] = 0;
     }
    }
}
int main(int argc, char *argv[])
{
    freopen("jigsaw.in","r",stdin);
    freopen("jigsaw.out","w",stdout);
    for(int i = 0;i<=10;i++)
     for(int j = 0;j<=10;j++)
      as[i][j][0] = 110;
    scanf("%d%d",&r,&c);
    for(int i = 1;i<=r*c;i++)
    {
     int id;
     scanf("%d",&id);
     for(int j = 1;j<=4;j++){
     char x[10];
     scanf("%s",&x);
     u[id][j] = x[0];
     v[u[id][j]].push_back(p(id,j));
     }
    }
    for(int i = 0;i<=r;i++)
     s[i][0][2] = '0';
    for(int i = 0;i<=c;i++)
     s[0][i][3] = '0';
    dfs(1,1);
    for(int i = 1;i<=r;i++){
     for(int j = 1;j<=c;j++){
      printf("%d ",int(as[i][j][0]));
     for(int k = 1;k<=3;k++)
      printf("%c ",as[i][j][k]);
     printf("%c",as[i][j][4]);
     printf("\n");
     }
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
