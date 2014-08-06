#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#define X first
#define Y second
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef pair<int,int> mu;
const int dx[] = {0,0,0,1,-1};
const int dy[] = {0,1,-1,0,0};
int n,p,h;
int a[2510],m[60][60];
int st[2510];
int lk[6300100][3],tot;
int d[2510];
bool vi[2510];
priority_queue<mu,vector<mu>,greater<mu> > q;
void li(int x,int y)
{
 tot++;
 lk[tot][0] = y;
 lk[tot][1] = a[y];
 lk[tot][2] = st[x];
 st[x] = tot;
}

void dj(int x)
{
  memset(&d,0x7f,sizeof(d));
  memset(&vi,0,sizeof(vi));
  q.push(mu(0,0));
  d[x] = 0;
  
  /*int u = 0x7f7f7f7f,v = 0;
  for(int i = st[x];i!=0;i=lk[i][2]){
   d[lk[i][0]] = d[x]+lk[i][1];
   if(d[lk[i][0]] < u)
    u = d[lk[i][0]],v = lk[i][0];
  }*/
  while(!vi[p+1])
  {
   int v = q.top().Y;q.pop();

   if(vi[v] == true)
    continue;
   vi[v] = 1;
   for(int i = st[v];i!=0;i=lk[i][2])
   if(d[v]+lk[i][1] < d[lk[i][0]] && !vi[lk[i][0]])
   {
    d[lk[i][0]] = d[v]+lk[i][1];
    q.push(mu(d[lk[i][0]],lk[i][0]));
   }
  }
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    tot = 0;
    zero(a);
    zero(m);
    zero(st);
    zero(lk);
    zero(d);
    zero(vi);
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr409.in%d",cani);
    sprintf(ouf,"mr409.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(m,0xff,sizeof(m));
    scanf("%d%d%d",&n,&p,&h);
    for(int i = 1;i<=p;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      scanf("%d",&m[i][j]);
    for(int i = 1;i<=n;i++)
     m[0][i] = 0;
    for(int i = 1;i<=n;i++)
     m[n+1][i] = p+1;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      for(int k = 1;k<=4;k++)
       if(m[i+dx[k]][j+dy[k]] >= 0){
        li(m[i+dx[k]][j+dy[k]],m[i][j]);
        li(m[i][j],m[i+dx[k]][j+dy[k]]);
       }
    dj(0);
    if(h-d[p+1] < 0)
     printf("NO\n");
    else
     printf("%d\n",h-d[p+1]);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
