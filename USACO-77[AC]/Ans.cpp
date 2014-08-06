#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#define MP(x,y) make_pair(x,y)
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
const int inf = 0x7f7f7f7f;
int n,m;
vector<p> q[5010];
struct
{
 int d,t,p,bcc;
}c[5010];
void readin()
{
     scanf("%d%d",&n,&m);
     for(int i = 1;i<=m;i++)
     {
      int x,y;
      scanf("%d%d",&x,&y);
      q[x].push_back(MP(y,int(q[y].size())));
      q[y].push_back(MP(x,int(q[x].size())-1));
     }
}
int de = 1;
stack<int> bc;
int recurse(int x,int y)
{
    int leaves = 0;
    c[x].d = de++;
    c[x].t = x;
    bc.push(x);
    for(int i = 0;i<q[x].size();i++)
    {
     int nxt = q[x][i].X;
     if(i == y)
      continue;
     if(c[nxt].d == 0){
      c[nxt].p = x;
      leaves += recurse(nxt,q[x][i].Y);
     }
     if(c[c[nxt].t].d < c[c[x].t].d)
      c[x].t = c[nxt].t;
    }
    if(c[x].t == x){
     while(bc.top() != x)
     {
      c[bc.top()].bcc = x;
      bc.pop();               
     }
     c[x].bcc = x;
     bc.pop();
     if(leaves == 0)
      return 1;
    }
    return leaves;
}
int solve()
{
    int leaves = recurse(1,-1);
    int rc = 0;
    for(int i = 2;i<=n;i++){
     int p = c[i].p;
     if(c[i].t == i && c[p].bcc == 1)
      rc++;
    }
    if(rc == 0)
     return 0;
    else if(rc == 1)
     leaves++;
    return (leaves+1)/2;
}
int main()
{
    freopen("rpaths.in","r",stdin);
    freopen("rpaths.out","w",stdout);
    readin();
    printf("%d",solve());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
