#include <cstdlib>
#include <iostream>

using namespace std;
char cmd[100];
int n = 1000;
int main(int argc, char *argv[])
{
    freopen("report.txt","w",stdout);
    for(int i = 1;i<=n;i++)
    {
     system("data");
     sprintf(cmd,"cp splay1.in splay1.in%d",i);
     system(cmd);
    }
    for(int i =1;i<=n;i++)
    {
     printf("test:%d\n",i);
     sprintf(cmd,"cp splay1.in%d splay1.in",i);
     system(cmd);
     system("ans");
     system("ans2");
     system("fc splay1.ans splay1.out");
     system("del splay1.ans");
     system("del splay1.out");
     system("del splay1.in");
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
