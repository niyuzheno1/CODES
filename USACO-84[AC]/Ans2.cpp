#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 n,l,c,mr;
struct pt
{
 int64 v,m,r;
 bool operator <(pt x)const
 {
  return v < x.v;
 }
};
pt w[100010];
int64 lb(int64 x)
{
    return x&(-x);
}
int64 s[100010];
int64 sum(int64 x)
{
    int64 ans = 0;
    while(x > 0)
    {
     ans += s[x];
     x-=lb(x);
    }
    return ans;
}
void add(int64 x)
{
     while(x <= mr)
     {
      s[x]++;
      x+= lb(x);
     }
}

bool cmp(pt a,pt b)
{
     return a.m<b.m;
}
int main(int argc, char *argv[])
{
    freopen("running.in","r",stdin);
    freopen("running.out","w",stdout);
    scanf("%I64d%I64d%I64d",&n,&l,&c);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d",&w[i].v);
    sort(w+1,w+1+n);
    int64 mv = w[n].v;
    for(int64 i = 1;i<=n;i++)
     w[i].m = (l*c*w[i].v)%(mv*c);
    sort(w+1,w+1+n,cmp);
    int64 rank = 1;
    for(int64 i = 1;i<=n;i++)
    {
     w[i].r = rank;
     if(w[i].m == w[i+1].m)
      rank--;
     rank++;
    }
    mr = rank;
    sort(w+1,w+1+n);
    int64 sf = 0,ans = 0;
    for(int64 i = 1;i<=n;i++)
    {
     int64 cf = (w[i].v*l)/(w[n].v);
     ans += (cf-1)*(i-1)-sf+sum(w[i].r);
     sf+=cf;
     add(w[i].r);
    }
    printf("%I64d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}

