#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef long long int64;
const int64 inf = 0x7f7f7f7f;
int64 t,r,p,s,tot;

struct pp
{
 int64 n,v,l;
 bool x;
};
pp lk[50010*4];
int64 st[25010*2];
void add(int64 x,int64 y,int64 z,bool a)
{
     tot++;
     lk[tot].n = st[x];
     st[x] = tot;
     lk[tot].v = y;
     lk[tot].l = z;
     lk[tot].x = a;
}
int64 dis[25010];
struct no
{
 //map<int,int> mp;
 int64 v;
};
no ss;
int64 flag[25010*2];
int main(int argc, char *argv[])
{
    freopen("roadplane.in","r",stdin);
    freopen("roadplane.out","w",stdout);
    deque<no> q;
    memset(dis,0x7f,sizeof(dis));
    scanf("%I64d%I64d%I64d%I64d",&t,&r,&p,&s);
    dis[s] = 0;
  
    ss.v = s;
    flag[s]++;
    q.push_front(ss);
    for(int64 i = 1;i<=r;i++)
    {
     int64 a,b,c;
     scanf("%I64d%I64d%I64d",&a,&b,&c);
     add(a,b,c,0);
     add(b,a,c,0);
    }
    for(int64 i = 1;i<=p;i++)
    {
     int64 a,b,c;
     scanf("%I64d%I64d%I64d",&a,&b,&c);
     add(a,b,c,1);
    }
    while(!q.empty())
    {
     no top = q.front();q.pop_front();
     int64 v = top.v;
     flag[v]--;
     for(int64 i = st[v];i!=0;i=lk[i].n)
      if(dis[lk[i].v] > dis[v]+lk[i].l)
      {
      no nextop = top;
      dis[lk[i].v] = dis[v]+lk[i].l;
      nextop.v = lk[i].v;
      if(!flag[lk[i].v]){
       flag[lk[i].v]++;
       if(q.empty())
        q.push_back(nextop);
       else if(dis[q.front().v] < dis[lk[i].v])
        q.push_back(nextop);
       else
        q.push_front(nextop);
      }
      
      }
    }
    for(int64 i = 1;i<=t;i++)
     if(dis[i] > inf)
      printf("NO PATH\n");
     else
      printf("%I64d\n",dis[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
