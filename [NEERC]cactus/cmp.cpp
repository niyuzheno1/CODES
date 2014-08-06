#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
char str[1101];
char f(int x)
{
 return (x/10)+'0';
}
char g(int x)
{
 return x%10+'0';
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=44;i++)
    {
     sprintf(str,"cp data\\%c%c cactus.in",f(i),g(i));
     system(str);
     system("ans");
     sprintf(str,"fc cactus.out data\\%c%c.a",f(i),g(i));
     system(str);
     system("pause");
    }
    return EXIT_SUCCESS;
}
