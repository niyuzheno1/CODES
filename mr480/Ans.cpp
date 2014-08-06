#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define X first
#define Y second
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int p[265];
char s[265][265];
typedef pair<int,int> pi;
map<pi,int> a;
vector<pi> d;
queue<pi> m;
pi operator +(pi x,pi y)
{
 return pi(x.X+y.X,x.Y+y.Y);
}
pi b;
int t,x,y;
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr480.in%d",cani);
    sprintf(ouf,"mr480.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    
    zero(p);
    zero(s);
    a.clear();
    d.clear();
   
    t = x = y;
    memset(p,0x4f,sizeof(p));
    p['m'] = 1;
    p['.'] = 1;
    p['#'] = 2;
    
    d.push_back(pi(1,0));d.push_back(pi(-1,0));
    d.push_back(pi(0,1));d.push_back(pi(0,-1));
    scanf("%d%d%d",&t,&y,&x);
    for(int i = 1;i<=x;i++){
     scanf("%s",&s[i][1]);
     for(int j = 1;j<=y;j++)
      if(s[i][j] == 's')
       m.push(pi(i,j));
      else if(s[i][j] == 'm')
       b = pi(i,j);
    }
    for(int i = 1;i<=x;i++)
     for(int j = 1;j<=y;j++)
      a[pi(i,j)] = 62501;
    a[m.front()] = 0;
    while(!m.empty())
    {
    pi v = m.front();m.pop();
       for(int i = 0;i<=3;i++)
       {
          pi mp = v+d[i];
          if(a[mp] > a[v]+p[s[mp.X][mp.Y]])
          {
          a[mp] = a[v]+p[s[mp.X][mp.Y]];
          m.push(mp);
          }
       }
    }
    if(a[b] == 62501)
     printf("Impossible\n");
    else if(a[b] > t)
     printf("55555\n");
    else
     printf("%d\n",a[b]);
    fclose(stdin);fclose(stdout);
}    return EXIT_SUCCESS;
}
