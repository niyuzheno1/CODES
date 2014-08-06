#include <cstdlib>
#include <iostream>

using namespace std;
int n;

typedef  int e[14*2+2];
e a,b,c,d;
int ca(int x,int y){ return x;}
int cb(int x,int y){ return y;}
int cc(int x,int y){ return x+y;}
int cd(int x,int y){ return n-x+y;}
class re
{
public:
 e x;
 bool operator < (re y) const 
 {
  for(int i = 1;i<=n;i++)
   if(x[i] < y.x[i])
    return true;
   else if(x[i] > y.x[i])
    return false;
  return false;
 }
};
re p[5];
re now;
int ans = 0;
void dfs(int de)
{
     if(de> n)
     {
     ans++;
     memcpy(&p[4],&now,sizeof(re));
     sort(p+1,p+5);
     return;
     }
     for(int i = 1;i<=n;i++)
     {
       int x = de,y =i;
       if(a[ca(x,y)] == 0 && b[cb(x,y)] == 0 && c[cc(x,y)] == 0 && d[cd(x,y)] == 0)
       {
       now.x[de] = i;
       a[ca(x,y)] = b[cb(x,y)] = c[cc(x,y)] = d[cd(x,y)] = 1;
       dfs(de+1);
       a[ca(x,y)] = b[cb(x,y)] = c[cc(x,y)] = d[cd(x,y)] = 0;
       }
     }
}
int main(int argc, char *argv[])
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=5;i++)
     memset(p[i].x,0x7f,sizeof(p[i].x));
    dfs(1);
    for(int i = 1;i<=3;i++){
     for(int j = 1;j<=n-1;j++)
      printf("%d ",p[i].x[j]);
     printf("%d\n",p[i].x[n]);
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
