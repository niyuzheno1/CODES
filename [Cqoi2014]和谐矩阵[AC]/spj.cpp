#include "mode.h"

#define MN 43
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};

int a[MN][MN];

bool allzero = 0;

int main(int argc, char *argv[])
{
    FILE * in = fopen("sample.in","r");
    FILE * out = fopen("sample.out","r");
    int n,m;fscanf(in,"%d",&n);fscanf(in,"%d",&m);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j)
      fscanf(out,"%d",&a[i][j]);
    allzero  = 1;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j){
      if(a[i][j] == 1) allzero = 0;
      if(a[i][j] != 0 && a[i][j] != 1) {allzero = 1;break;} 
     }
    if(allzero) 
     return 1;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j){
      int f=  0;
      for(int k = 0;k<=4;++k)
       f^= a[i+dx[k]][j+dy[k]];
      if(f == 1) 
       return 1;
     }
    return EXIT_SUCCESS;
}
