#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>

using namespace std;
int n;
struct pe
{
 int x,p;
 bool operator < (pe  x) const
 {
  return p < x.p;
 }
};
priority_queue<pe> q;
pe u[10010];
int to;
int solve(int up)
{
    to = n;
    int s = 0;
    int x = -1;
    while(!q.empty() && s < up)
    {
     s += q.top().p;q.pop();
     for(;to>=1 && u[to].x >= up-s;to--)
      q.push(u[to]);
     x++;
    }
    if(s >= up)
     return x;
    else
     return -1;
}
bool cmp(pe x,pe y)
{
     if(x.x == y.x)
      return x.p < y.p;
     else 
      return x.x < y.x;
}
int main(int argc, char *argv[])
{
    freopen("exp.in","r",stdin);
    freopen("exp.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&u[i].x,&u[i].p);
    sort(u+1,u+1+n,cmp);
    pe L;
    scanf("%d%d",&L.x,&L.p);
    q.push(L);
    printf("%d",solve(L.x));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
