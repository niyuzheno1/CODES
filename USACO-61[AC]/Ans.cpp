#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
int n,m,k,tot;
int dis[21][10010];
int st[10010];
int flag[10010];
struct p
{
 int n,v,l;
};
p pe[50010*2];
void add(int x,int y,int z)
{
     tot++;
     pe[tot].n = st[x];
     pe[tot].v = y;
     pe[tot].l = z;
     st[x] = tot;
}
void bfs(int d,int x)
{
     flag[x] = 1;
     queue<int> q;
     q.push(x);
     while(!q.empty())
     {
      x = q.front();q.pop();
      flag[x]--;
      for(int i = st[x];i!=0;i=pe[i].n)
      {
       int v = pe[i].v;
       if(dis[d][v] > dis[d][x]+pe[i].l)
       {
        dis[d][v] = dis[d][x]+pe[i].l;
        if(!flag[v]){
        flag[v]++;
        q.push(v);
        }
       }
      }
     }
}
void up(int d,int x)
{
     for(int i = st[x];i!=0;i=pe[i].n)
      if(dis[d+1][pe[i].v] > dis[d][x])
       dis[d+1][pe[i].v] = dis[d][x];
}
int main(int argc, char *argv[])
{
    freopen("revamp.in","r",stdin);
    freopen("revamp.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int j = 0;j<=n;j++)
      dis[0][j] = 0x7f7f7f7f;
    for(int i = 0;i<=k;i++)
     dis[i][1] = 0;
    for(int i = 1;i<=m;i++)
    {
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     add(x,y,z);add(y,x,z);
    }
    for(int i = 0;i<=k;i++){
     for(int j = 1;j<=n;j++)
      bfs(i,j);
     for(int j = 1;j<=n;j++)
      dis[i+1][j] = dis[i][j];
     if(i+1<=k)
     for(int j = 1;j<=n;j++)
      up(i,j);
    }
    printf("%d",dis[k][n]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
