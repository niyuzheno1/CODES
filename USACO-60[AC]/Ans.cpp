#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
int n,m,b,tot;
struct pp
{
 int n,b,l;
};
pp e[100010*2];
int st[50010];
int dis[50010];
void add(int x,int y,int z)
{
     tot++;
     e[tot].n = st[x];
     e[tot].b = y;
     e[tot].l = z;
     st[x] = tot;
}
int main(int argc, char *argv[])
{
    freopen("cgiving.in","r",stdin);
    freopen("cgiving.out","w",stdout);
    scanf("%d%d%d",&n,&m,&b);
    for(int i = 1;i<=m;i++)
    {
     int r,s,l;
     scanf("%d%d%d",&r,&s,&l);
     add(r,s,l);
     add(s,r,l);
    }
    memset(dis,0x7f,sizeof(dis));
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
     int x = q.front();q.pop();
     for(int i = st[x];i != 0;i = e[i].n)
     if(dis[e[i].b] > dis[x] + e[i].l){
      dis[e[i].b] = dis[x] + e[i].l;
      q.push(e[i].b);
     }
    }
    for(int i = 1;i<=b;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     printf("%d\n",dis[x]+dis[y]);
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
