#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <queue>
#define sum(l,r) (l?v[r]-v[l-1]:v[r])
using namespace std;
const int MAXN = 500001;
int n,k,l,r,f[19][MAXN],v[MAXN],log[MAXN];
long long ans;
struct query{
 int i,l,r,n;
 query(int _i,int _l,int _r,int _n)
 :i(_i),l(_l),r(_r),n(_n)
 {
 }
};
struct comp{
 int operator()(query x,query y)
 {
  return sum(x.i,x.n)<sum(y.i,y.n);
 }
};
priority_queue<query,vector<query>,comp> q;
int max(int x,int y,int k)
{
 return v[f[k][x]]>v[f[k][y]]?f[k][x]:f[k][y];
}
void insert(int i,int l,int r)
{
 int k = log[r-l+1];
 q.push(query(i,l,r,max(l,r-(1<<k)+1,k)));
}
int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("piano.in","r",stdin);freopen("piano.out","w",stdout);
    #endif
    scanf("%d%d%d%d",&n,&k,&l,&r);
    for(int i = 0;i<n;i++)
     scanf("%d",&v[i]),i?v[i]+=v[i-1]:0,f[0][i] = i;
    log[1] = 0;
    for(int i = 2;i<=n;i++)
     log[i] = (1<<log[i-1]+1==i?1:0)+log[i-1];
    for(int i = 1;i<=log[n];i++)
     for(int j = 0;j<=n-(1<<i);j++)
      f[i][j] = max(j,j+(1<<i-1),i-1);
    for(int i = 0;i<=n-l;i++)
     insert(i,i+l-1,(i+r>n?n:i+r)-1);
    for(;k--;){
      query x = q.top();q.pop();
      ans += sum(x.i,x.n);
      if(x.n > x.l)
       insert(x.i,x.l,x.n-1);
      if(x.n < x.r)
       insert(x.i,x.n+1,x.r);
    }
    //#ifndef WINDOWS
    //printf("%I64d\n",ans);
    //#else
    printf("%lld\n",ans);
    //#endif
    #ifndef ONLINE_JUDGE
    fclose(stdin);fclose(stdout);
    #endif
    return EXIT_SUCCESS;
}
