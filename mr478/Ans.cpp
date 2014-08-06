#include <cstdlib>
#include <iostream>
#include <vector>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n;
int a[10010],b;
vector<int> c[10010];

void p(int x)
{
  printf("%d",a[x]);
  if(c[x].size() != 0)
   p(c[x][0]);
}
char inf[100],ouf[100];
bool f(int x,int y)
{
     string a1,b1;
     string a2,b2;
     a1 += (a[x]+'0');b1 += (a[y]+'0');
     while(c[x].size() != 0)
     {
      x = c[x][0];
      a1 += (a[x]+'0');
     }
     while(c[y].size() != 0)
     {
      y = c[y][0];
      b1 += (a[y]+'0');
     }
     a2 = a1+b1;
     b2 = b1+a1;
     return a2 < b2;
}
bool cmp(int d,int e)
{
    /* if(a[d] == a[e])
      {
       if(c[d].size() != 0 && c[e].size() != 0)
        return cmp(c[d][0],c[e][0]);
       else if(c[d].size() != 0)
        return a[c[d][0]]<a[e];
       else if(c[e].size() != 0)
        return a[d]<a[c[e][0]];
       else
        return false;
      }*/
     return f(d,e);
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr478.in%d",cani);
    sprintf(ouf,"mr478.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)
    {
     scanf("%d",&b);
     c[b].push_back(i);
    }
    sort(c[0].begin(),c[0].end(),cmp);
   /* for(int i = 0;i<c[0].size()-1;i++)
    if(f(c[0][i],c[0][i+1])){
    int tmp = c[0][i];
    c[0][i] = c[0][i+1];
    c[0][i+1] = tmp;
    }*/
    for(int i = 0;i<c[0].size();i++)
    {
     printf("%d",a[c[0][i]]);
     if(c[c[0][i]].size() != 0)
     p(c[c[0][i]][0]);
    }
    memset(a,0,sizeof(a));
    for(int i = 0;i<=n;i++)
     c[i].clear();
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
