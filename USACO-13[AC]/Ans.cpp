#include <cstdlib>
#include <iostream>

using namespace std;
int k,e,n;
struct p
{
 int c;
 int f;
 bool operator <(p x) const
 {
 if(c == x.c)
  return f < x.f;
 return c < x.c;
 }
};
p q[110];
int main(int argc, char *argv[])
{
    freopen("feed2.in","r",stdin);
    freopen("feed2.out","w",stdout);
    scanf("%d%d%d",&k,&e,&n);
    for(int i = 1;i<=n;i++)
    {
     int x,f,c;
     scanf("%d%d%d",&x,&f,&c);
     q[i].c = c+e-x;
     q[i].f = f;
    }
    int ans =0;
    sort(q+1,q+1+n);
    for(int i = 1;i<=n;i++)
     if(k == 0)
      break;
     else
     {
         int rc = min(q[i].f,k);
         k -= rc;
         ans += rc*q[i].c;
     }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    
    return EXIT_SUCCESS;
}
