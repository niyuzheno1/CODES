#include <cstdlib>
#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

set<int> s;

int main(int argc, char *argv[])
{
    freopen("treap.in","r",stdin);
    freopen("treap.ans","w",stdout);
    while(true)
    {
     char str[8];
     if(scanf("%s",&str) == EOF)
      break;
     else{
      int x;
      scanf("%d",&x);
      if(str[0] == 'I')
       s.insert(x);
      if(str[0] == 'F')
       if(s.find(x) != s.end())
        printf("YES\n");
       else
        printf("NO\n");
     }
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
