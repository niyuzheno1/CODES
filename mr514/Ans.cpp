#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
priority_queue<int, vector<int>, greater<int> >  Q;
vector<int> v[10010];
int b[10010];
int c[10010];
char inf[101],ouf[101];
int t,n;
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr514.in%d",cani);
    sprintf(ouf,"mr514.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    zero(b);
    zero(c);
    for(int i = 0;i<=10000;i++)
     v[i].clear();
    while(!Q.empty())
     Q.pop();
    t = 0;
    int x;
    x = 1;
    while(scanf("%d",&x) != EOF)
    {
    
     t++;
     c[t] = x;
     b[x] ++;
     n = max(n,x);
    }
    t--;
    for(int i = 1;i<=n;i++)
     if(b[i] == 0)
      Q.push(i);
    for(int i = 1;i<=t;i++)
    {
     v[c[i]].push_back(Q.top());
     v[Q.top()].push_back(c[i]);
     Q.pop();
     b[c[i]]--;
     if(b[c[i]] == 0)
      Q.push(c[i]);
    }
    for(int i = 1;i<=n;i++){
     sort(v[i].begin(),v[i].end());
     printf("%d:",i);
     for(int j = 0;j<v[i].size();j++)
      printf(" %d",v[i][j]);
     printf("\n");
    }
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
