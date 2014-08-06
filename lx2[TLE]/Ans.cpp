#include <cstdlib>
#include <iostream>
using namespace std;
int n,m;
const int L[] = {0,1,2,4,4};
const int R[] = {0,1,2,2,2};
const int U[] = {0,1,1,1,1};
const int D[] = {0,1,1,3,3};
const int* P[5],*T[5];
const int dx[] = {0,-1,1,0,0};
const int dy[] = {0,0,0,-1,1};
int g(int x,int y,int z)
{
    if(x < 1 || x > n)
     return 0;
    if(y < 1 || y > m)
     return 0;
    if(z == 0)
     return 0;
    return (x-1)*m*5+(y-1)*5+z;
}
int st[100*100*6];
int vis[100*100*6],c[100*100*6];
int tota;
struct lb
{
 int n,v;
};
lb lk[100*100*6*8];
int tot;
void ae(int x,int y)
{
     //printf("%d %d\n",x,y);
     tot++;
     
     lk[tot].n = st[x];
     lk[tot].v = y;
     st[x] = tot;
}
int rec[100*100*5];
int map[100][100];
void init()
{
    P[1] = U;P[2] = D;P[3] = L;P[4] = R;
    T[1] = D;T[2] = U;T[3] = R;T[4] = L;
    scanf("%d%d",&n,&m); 
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&map[i][j]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
     {
      if( (i+j) % 2 == 0)
       for(int k = 1;k<=4;k++)
       {
        int x = g(i,j,P[k][map[i][j]]);
        int y = g(i+dx[k],j+dy[k],T[k][map[i+dx[k]][j+dy[k]]]);
        if(x != 0)
         if(!rec[x]){
          tota++;
          rec[x] = 1;
         }
        if(x != 0 && y != 0)
         ae(x,y);
       }
      if(map[i][j] == 3){
       if((i+j)%2 == 0)
        for(int k = 1;k<=4;k++)
         ae(g(i,j,k),g(i,j,5));
       else{
        for(int k = 1;k<=4;k++)
         ae(g(i,j,5),g(i,j,k));
        if(!rec[g(i,j,5)]){
         tota++;
         rec[g(i,j,5)] = 1;
         }
        }
      }
     }
     
     //printf("%d %d\n",tot,tota);
}
bool ok(int x)
{
     if(x == 0)
      return true;
     for(int i = st[x];i!= 0;i = lk[i].n)
     if(!vis[lk[i].v]){
      vis[lk[i].v] = 1;
      if(ok(c[lk[i].v]))
      {
       c[lk[i].v] = x;
       c[x] = lk[i].v;
       return true;
      }
     }
     return false;
}
bool solve()
{
     int ans = 0;
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       for(int k = 1;k<=5;k++){
         memset(vis,0,sizeof(vis));
         if(ok(g(i,j,k)))
          ans++;
       }
     if(ans == tota)
      return true;
     else
      return false;
}
char buffer[100*3][100*3];
void print()
{
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       if(map[i][j] > 0)
       {
       int cx,cy;
       cx = (i-1)*3+2;
       cy = (j-1)*3+2;
       buffer[cx][cy] = 'O';
       for(int k = 1;k<=4;k++){
        int x = g(i,j,P[k][map[i][j]]);
        int y = g(i+dx[k],j+dy[k],T[k][map[i+dx[k]][j+dy[k]]]);
        if(c[x] == y)
         buffer[cx+dx[k]][cy+dy[k]] = 'X';
        }
       }
     for(int i = 1;i<=3*n;i++){
      for(int j = 1;j<=3*m;j++)
       if(buffer[i][j] == 0)
        printf(".");
       else
        printf("%c",buffer[i][j]); 
      printf("\n");
     }
}
int main(int argc, char *argv[])
{
    freopen("alliances.in","r",stdin);
    freopen("alliances.out","w",stdout);
    init();
    if(solve())
     print();
    else
     printf("Impossible!\n");
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
