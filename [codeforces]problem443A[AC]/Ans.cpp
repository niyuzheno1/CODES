#include "mode.h"
#define MN 1100
char str[MN];
typedef map<string,int> mp;
mp f;
int main(int argc, char *argv[])
{
    setIO("sample");
    gets(str+1);
    int l= 1,r= strlen(str+1);
    for(;str[l]!='{';++l);
    for(;str[r]!='}';--r);
    string mem="";
    for(int i = l;i<=r;++i)
    {
     if(str[i]<='z' && str[i]>='a')
      mem+=str[i];
     else if(mem != "")
      f[mem]=1,mem="";
    }
    printf("%d",f.size());
    closeIO();
    return EXIT_SUCCESS;
}
