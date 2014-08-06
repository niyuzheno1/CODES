#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> o;
int n,p,c,m;
vector<int> a[1010];
map<int,int> b;
queue<o> q;
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
  for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr459.in%d",cani);
    sprintf(ouf,"mr459.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);   
    n = p = c = m = 0;
    for(int i = 0;i<=1000;i++)
     a[i].clear();
    b.clear();
    scanf("%d%d%d",&n,&p,&c);
    scanf("%d",&m);
    for(int i = 1;i<=p;i++)
    {
            int l,k;
            scanf("%d%d",&l,&k);
            a[l].push_back(k);
            a[k].push_back(l);
    }
    q.push(o(c,1));
    b[c] = 1;
    int ans = 0;
    while(!q.empty())
    {
     o u = q.front();q.pop();
     ans = max(ans,u.Y);
     for(int i = 0;i<a[u.X].size();i++)
      if(!b[a[u.X][i]])
      {
       b[a[u.X][i]] = 1;
       q.push(o(a[u.X][i],u.Y+1));
      }
    }
    printf("%d\n",ans+m);
	fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
