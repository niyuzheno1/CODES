#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;
int maxn = 10010;
int n,m;
char str[10];
set<int> s;
int x;
int main(int argc, char *argv[])
{
    freopen("splay2.in","r",stdin);
    freopen("splay2.ans","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
     int d = 0;
     scanf("%s%d",str,&d);
     if(str[0] == 'I')
      s.insert(d);
     else if(str[0] == 'S')
      x -= d;
     else if(str[0] == 'A')
      x += d;
     else if(str[0] == 'F')
     {
      if(d> s.size())
       printf("-1\n");
      else
      {
       int u = s.size()-d;
       for(set<int>::iterator it = s.begin();it != s.end();it++)
       {
        if(u == 0)
         printf("%d\n",*it);
        u--;
       }
      }
     }
     while(s.size()&&*s.begin() < (m-x))
      s.erase(s.begin());
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
