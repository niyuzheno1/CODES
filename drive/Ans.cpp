#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;
typedef  long long int64;
typedef pair<int64,int64> p;
int64 N,M;
int64 H[100010];
vector<int64> R[100010];
int64 x[10010],s[10010];
int64 u = 0;
void run(int64 x,int64 y,int64 z,int64 dis)
{
    if(dis > u)
     return;
    if(z == 1)
    {
    p m = p(0x7f7f7f7f,0);
    int c = 0;
    for(int i = y+1;i<=N;i++)
      if(p(abs(H[y]-H[i]),H[i]) < m)
       m = p(abs(H[y]-H[i]),H[i]),c = i;
    if(c == 0)
     return;
    R[x].pb(abs(H[y]-H[c]));
    run(x,c,2,dis+abs(H[y]-H[c]));
    
    }
    else if(z == 2)
    {
    p m = p(0x7f7f7f7f,0);
    int c,d;
    c = d = 0;
    p k = p(0x7f7f7f7f,0);
    for(int i = y+1;i<=N;i++)
      if(p(abs(H[y]-H[i]),H[i]) < m){
       d = c;k = m;
       m = p(abs(H[y]-H[i]),H[i]),c = i;
      }
      else if(p(abs(H[y]-H[i]),H[i]) < k){
       k = p(abs(H[y]-H[i]),H[i]);
       d = i;
      }
    if(d == 0)
     return;
    
    R[x].pb(abs(H[y]-H[d]));
    run(x,d,1,dis+abs(H[y]-H[d]));
    
    }
}

int main(int argc, char *argv[])
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    int64 ans1x=0,ans1y=0,ans1=0;
    scanf("%I64d",&N);
    for(int i = 1;i<=N;i++)
     scanf("%I64d",&H[i]);
    H[0] = -0x7f7f7f7f;
    scanf("%d",&x[0]);
    u = x[0];
    scanf("%I64d",&M);
    for(int i = 1;i<=M;i++){
     scanf("%I64d%I64d",&s[i],&x[i]);
     u = max(u,x[i]);
    }
    for(int i = 1;i<=N;i++)
     run(i,i,2,0);
    for(int i = 1;i<=N;i++)
    {
     int cx,cy;
     cx = cy = 0;
     for(int j = 0;j<R[i].size();j++)
     if(cy+cx+R[i][j] <= x[0])
     {
      if(j % 2==0)
       cx += R[i][j];
      else 
       cy += R[i][j];
     }
     else
      break;
     if((ans1x*cy > ans1y*cx ) || ((ans1x*cy == ans1y*cx)&&cx != 0 && cy != 0 &&H[ans1]<H[i]) || ( ans1y == 0 && H[ans1]<H[i]))
     {
      ans1x = cx;
      ans1y = cy;
      ans1 = i;
     }
    }
    printf("%d\n",ans1);
    for(int i = 1;i<=M;i++)
    {
     int cx,cy;
     cx = cy = 0;
     for(int j = 0;j<R[s[i]].size();j++)
     if(cy+cx+R[s[i]][j] <= x[i])
     {
      if(j % 2==0)
       cx += R[s[i]][j];
      else 
       cy += R[s[i]][j];
     }
     else
      break;
     printf("%d %d\n",cx,cy);
    }
    fclose(stdin);
    fclose(stdout);
    
    return EXIT_SUCCESS;
}
