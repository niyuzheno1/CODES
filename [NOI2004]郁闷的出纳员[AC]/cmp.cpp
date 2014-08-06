#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
int n;
char str[110];
int main(int argc, char *argv[])
{
    freopen("report.txt","w",stdout);
    n = 100;
    for(int i = 1;i<=n;i++)
    {
     system("data");
     sprintf(str,"cp splay2.in splay2.in%d",i);
     system(str);
    }
    for(int i = 1;i<=n;i++)
    {
     sprintf(str,"cp splay2.in%d splay2.in",i);
     system(str);
     system("ans");
     system("ans2");
     sprintf(str,"fc splay2.out splay2.ans");
     system(str);
     system("del splay2.in");
     system("del splay2.out");
     system("del splay2.ans");
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
