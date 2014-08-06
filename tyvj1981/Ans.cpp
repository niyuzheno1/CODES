#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef long long int64;
int64 n,p,k;
int64 st[1010];
int64 d[1010],vi[1010];
typedef pair<int64,int64> pi;
struct
{
int64 w,v,ne;
}lk[1010*1010*4];
int64 tot;
void li(int64 x,int64 y ,int64 z)
{
     tot++;
     lk[tot].ne = st[x];
     lk[tot].v = y;
     lk[tot].w = z;
     st[x] = tot;
}
int64 dj(int64 s,int64 t)
{
 memset(d,0x7f,sizeof(d));
 memset(vi,0,sizeof(vi));
 d[s] = 0;
 priority_queue<pi,vector<pi>,greater<pi> > q;
 q.push(pi(0,s));
 while(!q.empty())
 {
  int64 x = q.top().Y;
  q.pop();
  if(vi[x])
   continue;
  vi[x] = 1;
  for(int64 i = st[x];i != 0;i=lk[i].ne)
   if(d[lk[i].v] > d[x] + ((lk[i].w) <=t? 0 : 1)){
   d[lk[i].v] = d[x] + ((lk[i].w) <=t? 0 : 1);
   q.push(pi(d[lk[i].v],lk[i].v));
   }
 }
 return d[n];
}
int main(int argc, char *argv[])
{
    scanf("%lld%lld%lld",&n,&p,&k);
    int64 l,r;
    l = r = 0;
    int64 flag;
    for(int64 i = 1;i<= p;i++)
    {
     int64 x,y,z;
     scanf("%lld%lld%lld",&x,&y,&z);
     li(x,y,z);
     li(y,x,z);
     r = max(z,r);
    }
    r = r+1;
    flag = r;
    while(l<r)
    {
     int64 mid = (l+r)/2;
     int64 c = dj(1,mid);

	 if(c<k)
      r = mid-1;
     else if(c>k)
      l = mid+1;
	 else if(c == k)
	  r = mid;
    }
    if((l+r)/2 == flag)
    printf("-1");
    else
    printf("%lld",(l+r)/2);
    
    return EXIT_SUCCESS;
}
