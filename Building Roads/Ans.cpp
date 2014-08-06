#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
const double eps = 10e-6;
double dblcmp(double x)
{
 if(abs(x) <= eps)
  return 0;
 else
  return x;
}
const int maxn = 1010;
struct Ed { int from,to;double dis;
 bool operator <(Ed x) const
 {
  return (dblcmp(dis-x.dis) < 0);
 }
};
struct Disset
{
 int f[maxn];
 void init(int n )
 {
     for(int i = 1;i<=n;i++)
      f[i] = i; 
 }
 int find(int x)
 {
  if(f[x] != x)
   return (f[x]=find(f[x]));
  return x;
 }
 void unions(int x,int y)
 {
  f[find(x)] = f[find(y)];
  find(f[x]);
  find(f[y]);
 }
};
struct Kruscal
{
 Ed ED[maxn*2];
 int tot;
 Disset se;
 double ans;
 void addEdge(int from,int to,double dis)
 {
  tot++;
  ED[tot].from = from;
  ED[tot].to = to;
  ED[tot].dis = dis;
 }
 double sortandpro()
 {
      sort(ED+1,ED+tot+1);
      for(int i = 1;i<=tot;i++){
       Ed & e = ED[i];
       if(se.find(e.from)  != se.find(e.to) )
       {
        ans += e.dis;
        se.unions(e.from,e.to);     
       }
      }
      return ans;
 }
 
};
Kruscal kru;
int N,M;
double pos[maxn][2];
double dis(int x,int y)
{
       double ret = 0;
       for(int i = 0;i<=1;i++)
        ret += (pos[x][i]-pos[y][i])*(pos[x][i]-pos[y][i]);
       return sqrt(ret);
}
int main(int argc, char *argv[])
{
    scanf("%d%d",&N,&M);
    for(int i  = 1;i<=N;i++)
     scanf("%lf %lf",&pos[i][0],&pos[i][1]);
    for(int i = 1;i<=N;i++)
     for(int j = 1;j<=N;j++)
      kru.addEdge(i,j,dis(i,j));
    kru.se.init(N);
    for(int i = 1;i<=M;i++)
    {
     int x,y;
     scanf("%d %d",&x,&y);
     kru.se.unions(x,y);
    }
    printf("%.2f",kru.sortandpro());
    system("PAUSE");
    return EXIT_SUCCESS;
}
