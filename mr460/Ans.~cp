#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int,vi> p;
typedef map<p,int> N;
int n,ans = 0,mx = 0;
int H[410],A[410],C[410];
N m;
map<int,int> c,v;
vi b;
char inf[101],ouf[101];
void dfs(int x,int z,vi y)
{
    if(c[x] < z && c[x] != 0)
     return;
    if(v[z] > x && v[z] != 0)
     return;
    c[x] = z;
    v[z] = x;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=C[i]-y[i-1];j++)
            if(x+H[i]*j<=A[i] && y[i-1]+j <= C[i])
            {
            vi e  = y;
            e[i-1]+=j;
            dfs(x+H[i]*j,z+j,e);
            }
    return;
}


int main(int argc, char *argv[])
{
  for(int cani = 0;cani<=9;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr460.in%d",cani);
    sprintf(ouf,"mr460.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);   
    n = ans = mx = 0;
    memset(H,0,sizeof(H));
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    v.clear();
    m.clear();
    c.clear();
    b.clear();
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
    scanf("%d%d%d",&H[i],&A[i],&C[i]);
    mx = max(mx,A[i]);
    b.push_back(0);
    }
    dfs(0,0,b);
    for(int i = 1;i<=mx;i++)
     if(c[i] != 0)
     ans = max(ans,i);
    printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
