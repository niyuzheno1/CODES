#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;
map<string,int> m;
int N;
char tmp[1010];
int main(int argc, char *argv[])
{
    scanf("%d",&N);
    int x = 0;
    m["0"]=1;
    while(x <= 1<<N)
    {
     string tp,ne;
     int u = 0;
     for(int i = 1;i<= 1<<(N-1); i<<=1 )
     {
     int y = x;
     y ^= i;
     itoa(y,tmp,2);
     tp = tmp;
     if((tp.length() < ne.length() || (tp < ne &&tp.length() == ne.length())||  ne == "" )&&m[tp] == 0)
      ne = tp,u=y;
     }
     printf("%s\n",ne.c_str());
     x = u;
     if(ne == "")
      break;
     m[ne] = 1;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
