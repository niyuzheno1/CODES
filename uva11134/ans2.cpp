#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>


#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int n;
struct l
{
  int a,b,c; 
  bool operator < (l a) const
  {
   return b > a.b;
  }
};
l a[5010];
l b[5010];
int ans[5010][3];
bool cmp(l a, l b)
{
     return a.a < b.a;
}
bool check(l * a,int b)
{
     priority_queue<l> q; 
     int j = 0;
     rep(i,n)
     {
       int p = i+1;
       for(;a[j].a <= p && j< n;j++)
        q.push(a[j]);
       if(q.empty())
        return false;
       if(q.top().b < p)
        return false;
       ans[q.top().c][b] = p;
       q.pop();
     }
     return true;
}
int main(int argc, char *argv[])
{
    while(true){
    scanf("%d",&n);
    if(n == 0)
     break;
    rep(i,n)
    {
     scanf("%d%d%d%d",&a[i].a,&b[i].a,&a[i].b,&b[i].b);
     a[i].c = b[i].c = i;
    }
    sort(a,a+n,cmp);
    sort(b,b+n,cmp);
    bool flag = true;
    flag = flag && check(a,1);
    flag = flag && check(b,2);
    if(flag)
     rep(i,n)
      printf("%d %d\n",ans[i][1],ans[i][2]);
    else
     puts("IMPOSSIBLE");
    }
    
    return EXIT_SUCCESS;
}
