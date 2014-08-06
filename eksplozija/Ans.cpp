#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
char str[1000010];
int ne[1000010];
char e[37];
string ans;
int main(int argc, char *argv[])
{
    freopen("eksplozija.in","r",stdin);
    freopen("eksplozija.out","w",stdout);
    scanf("%s",&str);
    scanf("%s",&e);
    int next = strlen(str)-1;
    ne[next] = strlen(str);
    int st = 0;
    for(int i = next;i>=0;i--)
    {
     int nx = i;
     bool test = true;
     for(int j = 0;j<strlen(e);j++)
      if(nx > next)
      { test = false;break;}
      else if(str[nx] != e[j])
      { test = false;break;}
      else if(str[nx] == e[j])
       nx = ne[nx];
     
     if(test)
     {
      if(i-1 < 0)
      st = nx;
      else
      ne[i-1] = nx;
     }
     else{
     if(i-1 < 0)
      st = i;
     else
     ne[i-1] = i;
     }
    }
    while(st < next)
    {
     ans += str[st];
     st = ne[st];
    }
    if(ans == "")
     printf("FRULA");
    else
     printf("%s",ans.c_str());
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
