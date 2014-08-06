#include <cstdlib>
#include <iostream>
#include <set>
#define iter iterator
using namespace std;
typedef long long int64;
set<int64> s;
int64 d[101];
int k,n;
int main(int argc, char *argv[])
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    
    scanf("%d%d",&k,&n);
    for(int i = 1;i<=k;i++)
     scanf("%d",&d[i]),s.insert(d[i]);;
    for(int i = 1;i<=k;i++)
    {
     
     set<int64>::iter it = s.begin();
     while(true)
     {
      if(it == s.end())
       break;
      int nw = 0;
      nw = d[i]*(*it);
      
      if(nw < 0)
       break;
      if(s.size() > n)
       s.erase(*(--s.end()));
      s.insert(nw);
      it++;
     }
    }
    while(s.size() > n)
     s.erase(*(--s.end()));
    printf("%d",*(--s.end()));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
