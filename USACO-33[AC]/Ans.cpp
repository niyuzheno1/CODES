#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;
typedef long long int64;
int64 n;
struct p
{
 int64 a,b,h,n;
 bool operator < (p x) const
 {
 return h < x.h; 
 }
};
bool cmp(p x,p y)
{
     return x.a < y.a;
}
bool del[40010];
p a[40010],b[40010*2];
priority_queue<p> q;
int64 tot;
void add(int64 x,int64 y,int64 z,int64 k)
{
     tot++;
     b[tot].a = x;b[tot].b = y;b[tot].h = z;b[tot].n = k;
}
int main(int argc, char *argv[])
{
    freopen("horizon.in","r",stdin);
    freopen("horizon.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d%I64d",&a[i].a,&a[i].b,&a[i].h);
    for(int64 i = 1;i<=n;i++)
    {
     add(a[i].a,0,a[i].h,i);
     add(a[i].b,1,a[i].h,i);
    }
    int64 ans = 0;
    sort(b+1,b+1+tot,cmp);
    for(int64 i = 1;i<=tot;i++)
    {
     while(!q.empty() && del[q.top().n])
      q.pop();
     if(!q.empty())
     ans += q.top().h*(b[i].a-b[i-1].a);
     if(b[i].b == 0)
      q.push(b[i]);
     else
      del[b[i].n] = 1;
     
    }
    printf("%I64d",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
