#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
const double inf = 10e7;
const double p = 10e-7;
const int iinf = 0x7f7f7f7f;
int n,m;
int f[5010];
struct e
{
 int s,t,l;
};
e ed[5010];
int st[1010];
double dis[1010];
int visit[1010];
int flag[1010];
struct t
{
 int n,p;
 double len;
};
t ee[5010*2];
int tot;
void add(int x,int y,double z)
{
     tot++;
     ee[tot].p = y;
     ee[tot].len = z;
     ee[tot].n = st[x];
     st[x] = tot;
}
bool sp()
{
     for(int i = 1;i<=n;i++)
      dis[i] = inf;
     memset(flag,0,sizeof(flag));
     memset(visit,0,sizeof(visit));
     dis[1] = 0;
     flag[1] = 1;
     visit[1] = 1;
     queue<int> s;
     s.push(1);
     
     while(!s.empty())
     {
      int x = s.front();s.pop();
      visit[x] = 0;
      for(int i = st[x];i != 0;i = ee[i].n)
       if(dis[ee[i].p] > dis[x] + ee[i].len){
        dis[ee[i].p] = dis[x] + ee[i].len;
        if(!visit[ee[i].p]){
        flag[ee[i].p]++;
        if(flag[ee[i].p] > n)
         return true;
        s.push(ee[i].p);
        visit[ee[i].p] = 1;
        }
       }
     }
     return false;
}
int main(int argc, char *argv[])
{
    freopen("sightsee.in","r",stdin);
    freopen("sightsee.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&f[i]);
    for(int i = 1;i<=m;i++)
     scanf("%d%d%d",&ed[i].s,&ed[i].t,&ed[i].l);
    double l = 0,r = 100;
    while(l<r)
    {
     double mid = (l+r)/2;
     memset(st,0,sizeof(st));
     tot = 0;
     for(int i = 1;i<=m;i++)
      add(ed[i].s,ed[i].t,mid*double(ed[i].l)-double(f[ed[i].t]));
     if(sp())
      l = mid+p;
     else
      r = mid-p;
    }
    printf("%.2lf",(l+r)/2);
    fclose(stdin);
    fclose(stdout); 
    return EXIT_SUCCESS;
}
