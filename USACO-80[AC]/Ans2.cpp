#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef long long int64;
struct pp
{
 int64 p,v;
 pp(int64 x,int64 y)
 {
  this->p = x;
  v = y;
 }
 pp()
 {
  this->p  = this->v = 0;
 }
};
int64 k,e,n;

struct ex
{
 int64 x,f,c;
 bool operator<(ex o) const
 {
  return x<o.x;
 }
};
ex u[10010];
int64 best[10010],pre[10010];
int main(int argc, char *argv[])
{
    freopen("feed.in","r",stdin);
    freopen("feed.out","w",stdout);
    scanf("%I64d%I64d%I64d",&k,&e,&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d%I64d",&u[i].x,&u[i].f,&u[i].c);
    sort(u+1,u+1+n);
    for(int64 i = 1;i<=k;i++)
     pre[i] = -1;
    for(int64 i = 1;i<=n;i++)
    {
     deque<pp> q;
     for(int64 j = 0;j<=k;j++)
     {
     if(pre[j] != -1){
      int64 bp = (pre[j]+(u[i].x-u[i-1].x)*j*j)-j*u[i].c;
      int64 va = j + u[i].f;
      while(!q.empty() && q.back().p > bp)
       q.pop_back();
      q.push_back(pp(bp,va));
     }
     while(!q.empty() && q.front().v < j)
      q.pop_front();
     if(!q.empty())
      best[j] = q.front().p+j*u[i].c;
     }
    memcpy(pre,best,sizeof(best));
    }
    printf("%I64d",pre[k]+k*k*(e-u[n].x));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
