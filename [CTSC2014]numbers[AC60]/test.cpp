#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
FILE * r,*t;
int main(int argc, char *argv[])
{
    freopen("report.txt","w",stdout);
    r = fopen("numbers1.out","r");
    t = fopen("numbers1.ans","r");
    int n = 0;
    fscanf(r,"%d",&n);
    fscanf(t,"%d",&n);
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
     int u,v;
     fscanf(r,"%d",&u);
     fscanf(t,"%d",&v);
     if(u == v)
      ans++;
    }
    printf("%d\n",ans);
    fclose(stdout);
    return EXIT_SUCCESS;
}
