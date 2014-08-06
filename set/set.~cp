#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define pb push_back
using namespace std;
bool m[100010];
bool n[100010];
int a,b,p;
vector<int> k[100010];
void link(int x,int y)
{
   k[y].pb(x);
   k[x].pb(y);
}
void floodfill(int x)
{
  for(int i = 0;i<k[x].size();i++)
  if(k[x][i] >= p)
  if(!m[k[x][i]] ){
   m[k[x][i]] = 1;
   floodfill(k[x][i]);
  }
}
int ans  = 0;
int main(int argc, char *argv[])
{
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    scanf("%d%d%d",&a,&b,&p);
    n[1] = 1;
    for(int i = 2;i<=b;i++)
     if(n[i] == 0)
      for(int j = 2;j<=b/i;j++)
      {
       n[i*j] = 1;
       if(i*j <= b && i*j >= a)
        link(i,i*j);
      }
    for(int i = a;i<=b;i++)
     if(!m[i]){
      m[i] = 1;
      floodfill(i),ans++;
     }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
