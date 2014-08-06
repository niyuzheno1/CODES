#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define pb push_back
#define X first
#define Y second
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef pair<int,int> p;
vector<p> d;
map<p,int> m,t;
int r,c;
char g[110];
int w,o;
void init()
{
  m.clear();t.clear();
  w = o = 0;
}
int e(p & m,p u)
{
  if(m.X < u.X || (m.X == u.X && m.Y < u.Y))
   m = u;
}
int a(p & m,p u)
{
  if(m.X < u.X || (m.X == u.X && m.Y > u.Y))
   m = u;
}
int k(p & m,p u)
{
  if(m.X > u.X || (m.X == u.X && m.Y > u.Y))
   m = u;
}
int l(p & m,p u)
{
  if(m.X > u.X || (m.X == u.X && m.Y < u.Y))
   m = u;
}
p operator + (p x,p y)
{
 return p(x.X+y.X,x.Y+y.Y);
}
bool ff(p x)
{
     t[x] = 1;
     queue<p> q;
     q.push(x);
     p v,h,y,f;
     v = h = y = f = x;
     while(!q.empty())
     {
      p tmp = q.front();
      q.pop();
      for(int i = 0;i<d.size();i++)
      {
       p nt = tmp + d[i];
       if(m[nt] == 1 && t[nt] == 0){
        t[nt] = 1;
        q.push(nt);
        k(v,nt);l(h,nt);a(y,nt);e(f,nt);
       }
      }
     }
     for(int i = min(v.X,h.X);i<=max(y.X,f.X);i++)
      for(int j = min(v.Y,y.Y);j<=max(h.Y,f.Y);j++)
       if(m[p(i,j)] == 0)
        return false;
     return true;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
    d.pb(p(1,0));
    d.pb(p(0,1));
    d.pb(p(-1,0));
    d.pb(p(0,-1));
for(int cani = 0;cani<=4;cani++){
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr407.in%d",cani);
    sprintf(ouf,"mr407.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);

    init();
    
    scanf("%d%d",&r,&c);
    for(int i = 1;i<=r;i++)
    {
     scanf("%s",&g[1]);
     for(int j = 1;j<=c;j++)
      if(g[j] == '#')
       m[p(i,j)] = 1;
    }
    for(int i = 1;i<=r;i++)
     for(int j = 1;j<=c;j++)
      if(m[p(i,j)]==1 && t[p(i,j)] == 0)
       if(ff(p(i,j)))
        w++;
       else
        o++;
    printf("%d\n",w);
    printf("%d\n",o);
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
