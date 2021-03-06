#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define X first
#define Y second

using namespace std;
typedef pair<int,int> p;
typedef pair<p,int> p2;
int h,n;
int x[10010],y[10010];
int f[10010];
vector<p> t;
queue<p2> q;
int main(int argc, char *argv[])
{
    freopen("wall.in","r",stdin);
    freopen("wall.out","w",stdout);
    memset(&f,0x7f,sizeof(f));
    scanf("%d%d",&h,&n);
    for(int i = 1;i<=n;i++){
     scanf("%d%d",&x[i],&y[i]);
     t.push_back(p(y[i],i));
     if(y[i] <= 1000)
      q.push(p2(p(x[i],y[i]),i)),f[i] = 1;
    }
    sort(t.begin(),t.end());
    int ans = 0x7f7f7f7f;
    while(!q.empty())
    {
     int xx = q.front().X.X;
     int yy = q.front().X.Y;
     int z = q.front().Y;
     q.pop();
     if(yy >= h -1000)
      ans = min(ans,f[z]);
     vector<p>::iterator lo = lower_bound(t.begin(),t.end(),make_pair(yy-1000,INT_MIN));
     vector<p>::iterator hi = upper_bound(t.begin(),t.end(),make_pair(yy+1000,INT_MAX));
     for(vector<p>::iterator i = lo;i<hi;i++)
     {
      int nx = i->Y;
      int px = x[nx],py = y[nx];
      if((xx-px)*(xx-px)+(yy-py)*(yy-py) <= 1000*1000 && f[nx] > f[z] + 1)
      {
       f[nx] = f[z] + 1;
       q.push(p2(p(px,py),nx));
      }
     }
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
